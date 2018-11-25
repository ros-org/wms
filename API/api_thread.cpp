#include "api_thread.h"


/********************************************************************************************************
 * Function Name :                  APIThread
 * Function Main Usage:             构造函数
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/

APIThread::APIThread(QObject *parent)
{
    Q_UNUSED(parent);
    quit_flag = false;
}


/********************************************************************************************************
 * Function Name :                  run
 * Function Main Usage:
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/

void APIThread::run()
{
    inter_wms = new InterfaceWMS();
    //连接数据库
    inter_wms->db_connect("wms.db");
    sendQueueNumber = 0;
    init_map();
    init_taskinfo();
    while(!quit_flag)
    {
        msleep(50);
        if(!receive_buff.isEmpty())
        {
            websocketMsgLock.lock();
            std::pair<QString, QWebSocket*> msg = receive_buff.front();
            receive_buff.pop_front();
            websocketMsgLock.unlock();
            prase_request(msg.first, msg.second);
        }
        if(!receive_tcpbuff.isEmpty())
        {
            tcpMsgLock.lock();
            std::pair<QByteArray, QString> msg = receive_tcpbuff.front();
            receive_tcpbuff.pop_front();
            tcpMsgLock.unlock();
            prase_request(msg.first, msg.second);
        }
        if(!receive_opcbuff.isEmpty())
        {
            opcMsgLock.lock();
            std::pair<QString, int> msg = receive_opcbuff.front();
            receive_opcbuff.pop_front();
            opcMsgLock.unlock();
            praseOpcMsg(msg.first, msg.second);
        }
        if(!receive_opcreadybuff.isEmpty())
        {
            opcReadyMsgLock.lock();
            std::pair<QString, bool> msg = receive_opcreadybuff.front();
            receive_opcreadybuff.pop_front();
            opcReadyMsgLock.unlock();
            praseOpcReadyMsg(msg.first, msg.second);
        }
        auto_generate_task();
    }
}

/********************************************************************************************************
 * Function Name :                  close
 * Function Main Usage:             关闭线程
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/
void APIThread::close()
{
    quit_flag = false;
}


