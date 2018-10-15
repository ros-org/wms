#ifndef TCPMODBUS_H
#define TCPMODBUS_H

#include <QObject>
#include <QThread>
#include "../TcpModbus/master.h"

#define ADD_READ_A   24576
#define ADD_READ_B   24578
#define ADD_WRITE_A   8192
#define ADD_WRITE_B   8194

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

    void readValue(bool AOrB);

    void writeValue(bool AOrB);

    int __id;

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
};

#endif // TCPMODBUS_H
