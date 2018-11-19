#include "tcpmodbus.h"
#include "../common.h"

TcpModbus::TcpModbus(QString _ip, int _port, int _id, bool _haveB, QObject *parent) :
    QThread(parent),
    master(nullptr),
    ip(_ip),
    port(_port),
    id(_id),
    haveB(_haveB),
    readA(-2),
    readB(-2),
    writeA(-2),
    writeB(-2),
    updateA(false),
    updateB(false),
    quit(false),
    agv_turn(false)
{
    store_no_a = QString("A%1").arg(id);
    store_no_b = QString("B%1").arg(id);
    haveB = (id != 3);
}

TcpModbus::~TcpModbus()
{
    quit = true;
}

void TcpModbus::writeValue(bool AOrB)
{
    static int write_id = 256;
    if(write_id>511)write_id = 256;
    if(AOrB && updateA){
        QByteArray qba(2,'\0');

        qba[0] = (char)((writeA>>8) & 0xFF);
        qba[1] = (char)(writeA & 0xFF);
        qDebug()<<"write A"<<id<<"============="<<writeA;
        if(master->WriteSingleRegister(++write_id,ADD_WRITE_A,qba)){
            updateA = false;
        }
    }
    else if(!AOrB && updateB){
        QByteArray qba;

        qba[0] = (char)((writeB>>8) & 0xFF);
        qba[1] = (char)(writeB & 0xFF);
        qDebug()<<"write B"<<id<<"============="<<writeB;
        if(master->WriteSingleRegister(++write_id,ADD_WRITE_B,qba)){
            updateB = false;
        }
    }
}

void TcpModbus::readAgv()
{
    static int read_id = 0;
    if(read_id>255)read_id = 0;
    QByteArray qba;
    int add = ADD_READ_AGV;
    if(master->ReadDiscreteInputs(++read_id,add,1,qba))
    {
        bool agv_turn_temp = ((char)qba[0]>0);
        if(agv_turn_temp!=agv_turn){
            agv_turn = agv_turn_temp;
            qDebug()<<"read AGV"<<id<<"============="<<agv_turn;
        }
    }
}

void TcpModbus::readValue(bool AOrB)
{
    static int read_id = 0;
    if(read_id>255)read_id = 0;
    QByteArray qba;
    int add = ADD_READ_A;
    if(!AOrB)add = ADD_READ_B;
    if(master->ReadInputRegister(++read_id,add,1,qba))
    {
        int high = (char)qba[0];
        high = (high&0xff)<<8;
        int low = (char)qba[1];
        low = low&0xFF;
        int new_read  = high+low;

        if(AOrB){
            if(new_read != readA){
                qDebug()<<"read A"<<id<<"============="<<new_read;

                if(new_read != readA+1){
                    readA = new_read;
                    writeA = new_read;
                    updateA = true;
                }else{
                    readA = new_read;
                    writeA = new_read;
                    if(agv_turn){
                        updateA = false;
                        emit sig_readOpcMsg(store_no_a, new_read, ip, port);
                    }else{
                        updateA = true;
                    }
                }
            }
        }else{
            if(new_read != readB){
                qDebug()<<"read B"<<id<<"============="<<new_read;
                if(new_read != readB+1){
                    readB = new_read;
                    writeB = new_read;
                    updateB = true;
                }else{
                    readB = new_read;
                    writeB = new_read;
                    if(agv_turn){
                        updateB = false;
                        emit sig_readOpcMsg(store_no_b, new_read, ip, port);
                    }else{
                        updateA = true;
                    }
                }
            }
        }
    }
}

void TcpModbus::run()
{
    master = new Master;
    master->connectToHost(ip,port);

    while(!quit)
    {
        readAgv();

        //read a;
        readValue(true);

        //read b;
        if(haveB){
            readValue(false);
        }

        //write a;
        writeValue(true);

        //write b;
        if(haveB){
            writeValue(false);
        }

        QyhSleep(1000);
    }
}

void TcpModbus::slot_writeOpcMsg(QString storage_no, bool b)
{
    if(!b)return ;
    if(storage_no == store_no_a){
        updateA = true;
    }else if(storage_no == store_no_b){
        updateB = true;
    }
}
