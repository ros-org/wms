#ifndef TCPMODBUS_H
#define TCPMODBUS_H

#include <QObject>
#include <QThread>
#include "../TcpModbus/master.h"

#define ADD_READ_AGV  0
#define ADD_READ_A  8192
#define ADD_READ_B  8194
#define ADD_WRITE_A    24576
#define ADD_WRITE_B    24578

class TcpModbus : public QThread
{
    Q_OBJECT
public:
    explicit TcpModbus(QString _ip, int _port, int _id, bool _haveB, QObject *parent = nullptr);
    ~TcpModbus();
    void run() override;
signals:
    void sig_readOpcMsg(QString, int, QString, int);

public slots:
    void slot_writeOpcMsg(QString storage_no, bool b);
private:    

    void readAgv();

    void readValue(bool AOrB);

    void writeValue(bool AOrB);

    Master *master;

    QString ip;
    int port;
    int id;

    bool haveB;

    int readA;
    int writeA;
    bool updateA;

    int readB;
    int writeB;
    bool updateB;

    QString store_no_a;
    QString store_no_b;

    bool quit;

    bool agv_turn;
};

#endif // TCPMODBUS_H
