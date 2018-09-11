#include "api_thread.h"
#include <QJsonDocument>
/********************************************************************************************************
 * Function Name :                  prase_request
 * Function Main Usage:             解析请求报文
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/
void APIThread::prase_request(QString msg, QWebSocket* client)
{
    QJsonDocument jsonDoc =  QJsonDocument::fromJson(msg.toLatin1());
    QJsonObject jsonRequest = jsonDoc.object();
    if(jsonRequest.contains("todo"))
    {
        prase_json_request(jsonRequest, client);
        qDebug()<<jsonRequest.value("todo");
        return;
    }
    //TODO 报文解析
    QString response;
    QStringList request = msg.split(",");
    QString time_stamp = request.at(0);
    request.pop_front();
    QString msg_type = request.at(0);

    if("PREASSIGN" == msg_type)
    {
        //eg:PREASSIGN,A1,1,0
        if(request.size() != 4)
        {
            response = STR(RET_PARAMS_NUM_ERROR);
        }
        else
        {
            //校验参数
            int type = request.at(3).toInt();

            if(IN_STOCK != type && OUT_STOCK != type)
            {
                response = STR(RET_PARAMS_ERROR);
            }
            else
            {
                //预分配
                QString storage_no;
                RET_CODE ret = inter_wms->db_preAssign(request.at(1), request.at(2).toInt(), request.at(3).toInt(), storage_no);
                response = STR(ret);
                if(RET_OK == ret)
                {
                    response.append(",").append(storage_no);
                }
            }
        }
    }
    else if("CANCEL_PREASSIGN" == msg_type)
    {
        //eg:CANCEL_PREASSIGN,A1,1,0
        if(request.size() != 4)
        {
            response = STR(RET_PARAMS_NUM_ERROR);
        }
        else
        {
            //校验参数
            int type = request.at(3).toInt();

            if(IN_STOCK != type && OUT_STOCK != type)
            {
                response = STR(RET_PARAMS_ERROR);
            }
            else
            {
                //取消预分配
                RET_CODE ret = inter_wms->db_cancelPreAssign(request.at(1), request.at(2).toInt(), request.at(3).toInt());
                response = STR(ret);
            }
        }
    }
    else if("IN_STOCK" == msg_type)
    {
        //eg:IN_STOCK,A1,01,1,MOTOR
        if(request.size() != 5)
        {
            response = STR(RET_PARAMS_NUM_ERROR);
        }
        else
        {
            //入库
            RET_CODE ret = inter_wms->db_inStock(request.at(1), request.at(2), request.at(3).toInt(), request.at(4));
            response = STR(ret);
        }
    }
    else if("OUT_STOCK" == msg_type)
    {
        //eg:OUT_STOCK,A1,01,1
        if(request.size() != 4)
        {
            response = STR(RET_PARAMS_NUM_ERROR);
        }
        else
        {
            //出库
            RET_CODE ret = inter_wms->db_outStock(request.at(1), request.at(2), request.at(3).toInt());
            response = STR(ret);
        }
    }
    else if("NEWSTORE" == msg_type)
    {
        //eg:NEWSTORE,A11,websocket测试库别,H2
        if(request.size() != 4)
        {
            response = STR(RET_PARAMS_NUM_ERROR);
        }
        else
        {
            //新建库别
            RET_CODE ret = inter_wms->db_newStore(request.at(1), request.at(2), request.at(3));
            response = STR(ret);
        }
    }
    else if("NEWSTORAGE" == msg_type)
    {
        //eg:NEWSTORAGE,A11,07,H2
        if(request.size() != 4)
        {
            response = STR(RET_PARAMS_NUM_ERROR);
        }
        else
        {
            //新建储位
            RET_CODE ret = inter_wms->db_newStorage(request.at(1), request.at(2), request.at(3));
            response = STR(ret);
        }
    }
    else if("TASK_MATERIAL" == msg_type)
    {
        //eg:TASK_MATERIAL,F1_MATERIAL,01,RAW,1,TEST_USER
        //UPDATE STORAGE
        if(request.size() != 6)
        {
            response = STR(RET_PARAMS_NUM_ERROR);
        }
        else
        {
            RET_CODE ret = inter_wms->db_updateStorage(request.at(1), request.at(2), request.at(3), request.at(4).toInt(), request.at(5));
            response = STR(ret);

            if(RET_OK == ret)
            {
                generate_task(msg_type, request.at(1), request.at(2), request.at(3));
            }
        }
    }
    else
    {
        response = RET_MSG_ERROR;
    }

    //发送应答
    emit sig_response(time_stamp+","+response, client);
}

/********************************************************************************************************
         * Function Name :                  slot_receivemsg
         * Function Main Usage:             接收消息
         *
         * Author/Date:
         * Modefy/Date:
        ********************************************************************************************************/

void APIThread::slot_receivemsg(QString msg, QWebSocket* client)
{
    websocketMsgLock.lock();
    receive_buff.push_back(std::make_pair(msg, client));
    websocketMsgLock.unlock();
}
