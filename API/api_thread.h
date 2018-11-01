#ifndef APITHREAD_H
#define APITHREAD_H
#include <QThread>
#include <QQueue>
#include <QWebSocket>
#include <QJsonObject>
#include <QMutex>
#include "api_common.h"
#include "Interface/interface_wms.h"


class APIThread : public QThread
{
    Q_OBJECT

public:
    APIThread(QObject *parent = 0);
    void close();

public slots:
    //接收消息
    void slot_receivemsg(QString msg, QWebSocket* client);
    void slot_receivemsg(QByteArray msg, QString clientIP, QString port, int threadNo);
    void slot_readOpcMsg(QString storage_no, int times, QString ip, int port);
    void slot_readyOpcMsg(QString storage_no, bool flag, QString ip, int port);
signals:
    //发送消息
    void sig_response(QString msg, QWebSocket* client);
    void sig_notifyAll(QString msg);
    void sig_response(QString IPAddr, QByteArray Msg, int maxRepeatcount);
    void sig_responseAll(QString msg);
    void sig_writeOpcMsg(const QString, const bool);
protected:
    void run();
private:
    //解析消息
    void prase_request(QString msg, QWebSocket* client);
    void prase_request(QByteArray msg, QString clientIP);
    void praseOpcMsg(QString storage_no, int times);
    void praseOpcReadyMsg(QString storage_no, bool flag);

    //任务解析与发送
    void prase_json_request(QJsonObject request, QWebSocket *client);
    void generate_task(QString tasktype, QString store_no, QString storage_no, QString key_part_no);

    //自动生成任务
    void auto_generate_task();

    //保存储位和地图ID的映射关系
    void init_map();
    void init_taskinfo();

    //更新客户端储位信息
    void updateClientStorage(QString _store_no, QString _storage_no,  QString _key_part_no, int _status);
    void updateClientAutoTrayEnable(QString _store_no, QString _storage_no, bool enable);
    int sendQueueNumber;
    //消息缓存
    QQueue<std::pair<QString, QWebSocket*> > receive_buff;
    QQueue<std::pair<QByteArray, QString> > receive_tcpbuff;
    QQueue<std::pair<QString, int> > receive_opcbuff;
    QQueue<std::pair<QString, bool> > receive_opcreadybuff;
    bool quit_flag;
    QMap<std::pair<QString, QString>, TASK_INFO> mapping_task;
    //WMS接口
    InterfaceWMS* inter_wms;

    QMutex tcpMsgLock;
    QMutex websocketMsgLock;
    QMutex opcMsgLock;
    QMutex opcReadyMsgLock;

};

#endif // APITHREAD_H
