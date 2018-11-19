#ifndef MASTER_H
#define MASTER_H

#include <QObject>
#include <QTcpSocket>
#include <QMutex>
#include <QTimer>

/*
 * 东药项目 产线对接 tcp - modbus
 * 该项目只用到了 读单个输入寄存器 和 写单个保持寄存器
 * 分别对应 ReadInputReigster 和 WriteSingleRegister
 * 测试函数 test
 * last modify：2018-10-15
 * author:qinyinghao
 * */
class Master : public QObject
{
    Q_OBJECT
public:
    Master(QObject *parent = nullptr);

    bool getIsConnected(){return isConnected;}

    void connectToHost(QString _ip,int _port = 502);

    bool WriteSingleRegister(int id, int startAddress, const QByteArray &values);
    bool ReadInputRegister(int id, int startAddress, int numInputs,QByteArray &result);

    bool ReadDiscreteInputs(int id, int startAddress, int numInputs, QByteArray &result);

    void test();

    void startQuery();
    void startWrite();
public slots:
    void slotStateChanged(QAbstractSocket::SocketState s);
    void slotReadyRead();
    void slotTimeToQuery();
    void slotTimeToWrite();
private:
    bool isConnected;

    QString ip;
    int port;

    QTcpSocket *socket;
    QTimer *timer_read;
    QTimer *time_write;

    int lastSendId;
    int lastFunction;
    int lastRequstNumber;
    bool getResponse;
    QByteArray response;

    QByteArray CreateReadHeader(int id, int startAddress, int length, int function);
    QByteArray CreateWriteHeader(int id, int startAddress, int numData, int numBytes, int function);
    bool WriteData(const QByteArray &data, int id, int function, QByteArray &result);

public:
    const int excIllegalFunction = 1;
    const int excIllegalDataAdr = 2;
    const int excIllegalDataVal = 3;
    const int excSlaveDeviceFailure = 4;
    const int excAck = 5;
    const int excMemParityErr = 6;
    const int excGatePathUnavailable = 10;
    const int excExceptionNotConnected = 253;
    const int excExceptionConnectionLost = 254;
    const int excExceptionTimeout = 255;
    const int timeout = 500;

private:
    const int fctReadCoil = 1;
    const int fctReadDiscreteInputs = 2;
    const int fctReadHoldingRegister = 3;
    const int fctReadInputRegister = 4;
    const int fctWriteSingleCoil = 5;
    const int fctWriteSingleRegister = 6;
    const int fctWriteMultipleCoils = 15;
    const int fctWriteMultipleRegister = 16;
    const int fctExceptionOffset = 128;

};

#endif // MASTER_H
