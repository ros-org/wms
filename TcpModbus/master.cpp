#include "master.h"
#include <thread>
#include <iostream>
#include <QMutexLocker>
#include "../common.h"

/*
 * tcp modbus 协议。组成部分三部分
 * mbap + 功能代码 + 数据
 *
 * mbap组成部分四部分
 * mbap【1】  2Byte  传输标志：客户端随机生成，服务器返回一样的
 * mbap【2】  2Byte  传输协议： 0-modbus  1-UNI-TE  ;这里固定0
 * mbap【3】  2Byte  长度：后续字节数。 出去前面的 传输标志、传输协议、长度。所以  length = 总长度 - 6
 * mbap【4】  1Byte  单元标志：客户端生成，服务器返回一样的。
 *
 * 功能码：
 * 01 读线圈
 * 02 读输入点
 * 03 读多个寄存器
 * 04 读输入寄存器
 * 05 读单个先去
 * 06 写多个寄存器
 * 15 写多个线圈
 * 16 写多个寄存器
 * 20 读文件记录
 * 21 写文件记录
 * 22 屏蔽写寄存器
 * 23 读写多个寄存器
 * 43 读设备表示
 *
 *  例如读寄存器
 *
 * 请求：
 *  请求功能码   1Byte 03
 *  起始地址    2Byte  0x0000到0xffff
 *  寄存器数量   2Byte  N
 *
 * 响应：
 *  应答功能码   1Byte  03
 *  字节数      1Byte  2*N
 *  寄存器的值   2Byte * N个
 *
 * */

Master::Master(QObject *parent) : QObject(parent),
    isConnected(false),
    socket(nullptr),
    timer_read(nullptr),
    time_write(nullptr)
{

}

void Master::connectToHost(QString _ip, int _port)
{
    qDebug()<<" connect to ip:"<<_ip<<" port:"<<_port;
    if(isConnected && ip == _ip && port == _port)return ;

    if(socket){
        socket->close();
        delete socket;
    }
    ip = _ip;
    port = _port;
    socket = new QTcpSocket;

    connect(socket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(slotStateChanged(QAbstractSocket::SocketState)));
    connect(socket,SIGNAL(readyRead()),this,SLOT(slotReadyRead()));
    socket->connectToHost(ip,port);
}

bool Master::WriteSingleRegister(int id, int startAddress, const QByteArray &values)
{
    QByteArray data;
    data = CreateWriteHeader(id, startAddress, 1, 1, fctWriteSingleRegister);
    data[10] = values[0];
    data[11] = values[1];
    QByteArray result;
    return WriteData(data, id,fctWriteSingleRegister,result);
}

bool Master::ReadInputRegister(int id, int startAddress, int numInputs, QByteArray &result)
{
    lastRequstNumber = numInputs;
    return WriteData(CreateReadHeader(id, startAddress, numInputs, fctReadInputRegister), id,fctReadInputRegister,result);
}

bool Master::ReadDiscreteInputs(int id,int startAddress,int numInputs,QByteArray &result)
{
    lastRequstNumber = numInputs;
    return WriteData(CreateReadHeader(id, startAddress, numInputs, fctReadDiscreteInputs), id,fctReadDiscreteInputs,result);
}

void Master::slotStateChanged(QAbstractSocket::SocketState s)
{
    //qDebug()<<"socket state = "<<s;
    if(s == QAbstractSocket::ConnectedState){
        isConnected = true;
    }else{
        isConnected = false;
    }

    if(s == QAbstractSocket::UnconnectedState){
        QyhSleep(5000);
        socket->connectToHost(ip,port);
    }
}

void Master::slotTimeToQuery()
{
    static int id_read = 0;
    if(id_read>=255)id_read = 0;
    QByteArray qba;

    if(!ReadInputRegister(++id_read,8192,1,qba)){
        qDebug()<<"read fail";
    }else{
        qDebug()<<"read :"<<qba;
        for(int i=0;i<1;++i){
            int high = (char)qba[2*i];
            high = (high&0xff)<<8;
            int low = (char)qba[2*i+1];
            low = low&0xFF;
            int k  = high+low;
            qDebug()<<" ii["<<i<<"] = "<<k;
        }
    }
}

void Master::slotTimeToWrite()
{
    static int id_write = 256;
    if(id_write>=512)id_write = 256;

    static int write_value = 1;
    ++write_value;

    QByteArray qba(2,0);

    qba[0] = (write_value>>8)&0xff;
    qba[1] = write_value&0xff;

    if(!WriteSingleRegister(++id_write,24578,qba)){
        qDebug()<<"write fail";
    }else{
        qDebug()<<"write ok";
    }

}

void Master::slotReadyRead()
{
    QByteArray qba = socket->readAll();

    if(qba.length()>7)
    {
        if(qba[0] == (char)((lastSendId>>8)&0xFF) && qba[1] == (char)(lastSendId&0xFF) ){
            if(lastFunction == fctWriteSingleRegister){
                response.clear();
                getResponse = true;
            }
            //// 9 = mbap 7Byte + 功能码 1Byte + 长度 1Byte
            else if(lastFunction == fctReadInputRegister && qba[7] == (char)lastFunction && qba.length()>=9+2*lastRequstNumber)
            {
                response = qba.mid(9,2*lastRequstNumber);
                getResponse = true;
            }

            else if(lastFunction == fctReadDiscreteInputs && qba[7] == (char)lastFunction && qba.length()>=9+1*lastRequstNumber)
            {
                response = qba.mid(9,1*lastRequstNumber);
                getResponse = true;
            }
        }
    }
}

// Create modbus header for read action
QByteArray Master::CreateReadHeader(int id, int startAddress, int length, int function)
{
    QByteArray data(12,'\0');

    data[0] = (id>>8) &0xff;
    data[1] = id&0xff;
    data[5] = 6;                    //后续长度固定为6
    data[6] = 1;
    data[7] = function;
    data[8] = (startAddress>>8)&0xFF;
    data[9] = startAddress&0xFF;
    data[11] = length;
    return data;
}

// Create modbus header for write action
QByteArray Master::CreateWriteHeader(int id, int startAddress, int numData, int numBytes, int function)
{
    QByteArray data(numBytes + 11,'\0');

    data[0] = (id>>8) &0xff;
    data[1] = id&0xff;

    short n = 5+numBytes;
    data[4] = (n>>8)&0xFF;
    data[5] = n&0xFF;
    data[6] = 1;
    data[7] = function;
    data[8] = (startAddress>>8)&0xFF;
    data[9] = startAddress&0xFF;

    if (function >= fctWriteMultipleCoils)
    {
        data[10] = (numData>>8)&0xFF;
        data[11] = numData&0xFF;
        data[12] = (numBytes - 2);
    }


    return data;
}

bool Master::WriteData(const QByteArray &data,int id,int function,QByteArray &result)
{
    if(!isConnected)return false;
    if(socket==nullptr)return false;

    getResponse = false;
    lastSendId = id;
    lastFunction = function;
    result.clear();
    if(!data.length() == socket->write(data))return false;

    int kk = 0;
    while(true){
        if(kk >= timeout)return false;
        if(getResponse){
            result = response;
            return true;
        }
        kk+=10;
        QyhSleep(10);
    }

    return true;
}

void Master::startQuery()
{
    if(timer_read == nullptr){
        timer_read = new QTimer;
    }

    timer_read->setInterval(1000);
    connect(timer_read,SIGNAL(timeout()),this,SLOT(slotTimeToQuery()));

    timer_read->start();
}

void Master::startWrite()
{
    if(time_write == nullptr){
        time_write = new QTimer;
    }

    time_write->setInterval(1000);
    connect(time_write,SIGNAL(timeout()),this,SLOT(slotTimeToWrite()));
    time_write->start();

}

void Master::test()
{
    connectToHost(QString("10.20.2.61"));

    startQuery();
    //startWrite();
}
