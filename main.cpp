#include <QCoreApplication>
#include "Interface/interface_wms.h"
#include "Communication/websocketserver.h"
#include "Communication/fortuneserver.h"
#include "API/api_thread.h"
#include "TcpModbus/master.h"
#include "Communication/tcpmodbus.h"
#include "common.h"

#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <QDir>

QMap<QString, STATION_INFO> mapping_table;
QFile logFile;
//重定义qDebug等输出至文件
void customMessageHandler(QtMsgType type, const QMessageLogContext& Context, const QString& msg)
{
    Q_UNUSED(Context);
    //static QMutex mutex;

    //mutex.lock();
    QString txt;
    switch (type)
    {
    case QtDebugMsg:
        txt = QString(" %1").arg(msg);
        break;
    case QtInfoMsg:
        txt = QString("[Info] %1").arg(msg);
        break;
    case QtWarningMsg:
        txt = QString("[Warning] %1").arg(msg);
        break;
    case QtCriticalMsg:
        txt = QString("[Critical] %1").arg(msg);
        break;
    case QtFatalMsg:
        txt = QString("[Fatal] %1").arg(msg);
        abort();
    }

    QString log;
    log += QDateTime::currentDateTime().toLocalTime().toString("[hh:mm:ss.zzz]" ) + QString(" : %1\n").arg(txt);
    QByteArray temp = log.toLocal8Bit();
    logFile.write(temp);
    logFile.flush();

    // mutex.unlock();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //    QDir dir;
    //    if(!dir.exists("logs"))
    //    {
    //        dir.mkdir("logs");
    //    }
    //    logFile.setFileName("logs/wms_debuglog_"+QDate::currentDate().toString("yyyyMMdd")+"_"+QTime::currentTime().toString("hhmmss")+".txt");
    //    logFile.open(QIODevice::WriteOnly | QIODevice::Append);

    //    qInstallMessageHandler(customMessageHandler);


    /*
    //直接接口调用的方式
    InterfaceWMS* interface_wms = new InterfaceWMS();
    interface_wms->db_connect("wms.db");
    //入库
    QString storage_no;
    interface_wms->db_preAssign("A1", 2, 0, storage_no);
    interface_wms->db_inStock("A1", storage_no, 2, "INSTOCKTEST");

    //出库
    interface_wms->db_preAssign("A1", 3, 1, storage_no);
    interface_wms->db_outStock("A1", storage_no, 3);

    //新增库别
    interface_wms->db_newStore("A1","唯一性测试", "H2");
    interface_wms->db_newStore("A3","新增库别测试", "H2");

    //新增储位
    interface_wms->db_newStorage("A3", "07", "H2");

*/
    APIThread* api_thread = new APIThread();
    api_thread->start();

    //调度同WMS为TCP连接，外界发送任务WEBSOCKET连接
    //websocket服务
    WebSocketServer *server = new WebSocketServer(1234, true);
    QObject::connect(server, &WebSocketServer::closed, &a, &QCoreApplication::quit);
    QObject::connect(server, SIGNAL(sig_websocket_msg(QString,QWebSocket*)), api_thread, SLOT(slot_receivemsg(QString,QWebSocket*)));
    QObject::connect(api_thread, SIGNAL(sig_response(QString,QWebSocket*)), server, SLOT(slot_sendResponse(QString,QWebSocket*)));
    QObject::connect(api_thread, SIGNAL(sig_notifyAll(QString)), server, SLOT(slot_notifyAll(QString)));

    //tcpip服务
    FortuneServer* tcp_server = new FortuneServer();
    QObject::connect(tcp_server, SIGNAL(sig_tcpip_msg(QByteArray,QString,QString,int)), api_thread, SLOT(slot_receivemsg(QByteArray,QString,QString,int)));
    QObject::connect(api_thread, SIGNAL(sig_response(QString,QByteArray,int)), tcp_server, SLOT(slot_PushDownlinkMsg(QString,QByteArray,int)));
    tcp_server->init();
    QHostAddress serverAddress = QHostAddress("127.0.0.1");
    if (!tcp_server->listen(serverAddress,12345))
    {
        qDebug()<<"Unable to start the server:"<<tcp_server->errorString();
    }
    else
    {
        qDebug()<<"The server is running on IP:"<<serverAddress.toString()<<"port:"<<tcp_server->serverPort();
    }


    TcpModbus *tm1 = new TcpModbus("10.20.2.61",502,1,"F3_MD");

    TcpModbus *tm2 = new TcpModbus("10.20.2.62",502,2,"F3_MD");

    TcpModbus *tm3 = new TcpModbus("10.20.2.63",502,3,"F3_MD");


    QObject::connect(tm1, SIGNAL(sig_readOpcMsg(QString,int,QString,int)), api_thread, SLOT(slot_readOpcMsg(QString,int,QString,int)));
    QObject::connect(api_thread, SIGNAL(sig_writeOpcMsg(QString, bool)), tm1, SLOT(slot_writeOpcMsg(QString,bool)));

    QObject::connect(tm2, SIGNAL(sig_readOpcMsg(QString,int,QString,int)), api_thread, SLOT(slot_readOpcMsg(QString,int,QString,int)));
    QObject::connect(api_thread, SIGNAL(sig_writeOpcMsg(QString, bool)), tm2, SLOT(slot_writeOpcMsg(QString,bool)));

    QObject::connect(tm3, SIGNAL(sig_readOpcMsg(QString,int,QString,int)), api_thread, SLOT(slot_readOpcMsg(QString,int,QString,int)));
    QObject::connect(api_thread, SIGNAL(sig_writeOpcMsg(QString, bool)), tm3, SLOT(slot_writeOpcMsg(QString,bool)));

    tm1->start();

    tm2->start();

    tm3->start();

    return a.exec();
}

