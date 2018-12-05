#include "api_thread.h"

/********************************************************************************************************
 * Function Name :                  slot_receivemsg
 * Function Main Usage:             接收请求信息
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/
void APIThread::slot_receivemsg(QByteArray msg, QString clientIP, QString port, int threadNo)
{
    tcpMsgLock.lock();
    receive_tcpbuff.push_back(std::make_pair(msg, clientIP));
    tcpMsgLock.unlock();

    qDebug("[%d][%s:%s]receivemsg: %s", threadNo, qPrintable(clientIP), qPrintable(port), qPrintable(msg));
}

/********************************************************************************************************
 * Function Name :                  prase_request
 * Function Main Usage:             解析请求信息
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/
void APIThread::prase_request(QByteArray msg, QString clientIP)
{
    int main_msg = msg.mid(10,2).toInt();
    QString response;
    QString str_params = msg.mid(12);
    QStringList params = str_params.split('|');

    switch(main_msg)
    {
    case 70:        //预分配申请
    {
        //eg:*123456001870A1|1|0#
        if(params.size() != 3)
        {
            response = STR(RET_PARAMS_NUM_ERROR);
        }
        else
        {
            //校验参数
            int type = params.at(2).toInt();

            if(IN_STOCK != type && OUT_STOCK != type)
            {
                response = STR(RET_PARAMS_ERROR);
            }
            else
            {
                //预分配
                QString storage_no;
                RET_CODE ret = inter_wms->db_preAssign(params.at(0), params.at(1).toInt(), params.at(2).toInt(), storage_no);
                response = STR(ret);
                if(RET_OK == ret)
                {
                    response.append("|").append(storage_no);
                }
            }
        }
        break;
    }
    case 71:        //取消预分配
    {
        //eg:*123456001871A1|1|0#
        if(params.size() != 3)
        {
            response = STR(RET_PARAMS_NUM_ERROR);
        }
        else
        {
            //校验参数
            int type = params.at(2).toInt();

            if(IN_STOCK != type && OUT_STOCK != type)
            {
                response = STR(RET_PARAMS_ERROR);
            }
            else
            {
                //取消预分配
                RET_CODE ret = inter_wms->db_cancelPreAssign(params.at(0), params.at(1).toInt(), params.at(2).toInt());
                response = STR(ret);
            }
        }
        break;
    }
    case 72:        //入库
    {
        //eg:*123456002572A1|01|1|MOTOR#
        if(params.size() != 4)
        {
            response = STR(RET_PARAMS_NUM_ERROR);
        }
        else
        {
            //入库
            RET_CODE ret = inter_wms->db_inStock(params.at(0), params.at(1), params.at(2).toInt(), params.at(3));
            response = STR(ret);
            if(!ret)
            {
                updateClientStorage(params.at(0), params.at(1),  params.at(3), 1);
//                if(params.at(0) == "F3_MD")
//                {
//                    //如果是码垛处托盘放好，需通知OPC
//                    emit sig_writeOpcMsg(params.at(1), true);
//                }
            }
        }
        break;
    }
    case 73:        //出库
    {
        //eg:*123456001973A1|01|0#
        if(params.size() != 3)
        {
            response = STR(RET_PARAMS_NUM_ERROR);
        }
        else
        {
            //出库
            RET_CODE ret = inter_wms->db_outStock(params.at(0), params.at(1), params.at(2).toInt());
            response = STR(ret);
            if(!ret)
            {
                if(params.at(0) == "F3_MD")
                {
                    //如果是码垛处托盘被拖走，需通知OPC(20180829成品拖走无需告诉机械臂)
                    //emit sig_writeOpcMsg(params.at(1), false);
                    //此处修改为空托盘预分配状态
                    inter_wms->db_updateStorage(params.at(0), params.at(1), "3", 2, "OPC");

                    emit sig_writeOpcMsg(params.at(1), true);
                }
                updateClientStorage(params.at(0), params.at(1),  "", 0);
            }
        }
        break;
    }
    case 74://新建库别
    {
        //eg:*123456002674A12|tcptest|H2#
        if(params.size() != 3)
        {
            response = STR(RET_PARAMS_NUM_ERROR);
        }
        else
        {
            //新建库别
            RET_CODE ret = inter_wms->db_newStore(params.at(0), params.at(1), params.at(2));
            response = STR(ret);
        }
        break;
    }
    case 75://新建储位
    {
        //*123456002175A12|07|H2#
        if(params.size() != 3)
        {
            response = STR(RET_PARAMS_NUM_ERROR);
        }
        else
        {
            //新建储位
            RET_CODE ret = inter_wms->db_newStorage(params.at(0), params.at(1), params.at(2));
            response = STR(ret);
        }
        break;
    }
    default:        //其他信息
    {
        qDebug()<<"unknown msg-type";
        response = RET_MSG_ERROR;
        break;
    }
    }
    //发送应答
    QString msg_len = QString::number(response.length()+12).rightJustified(4, '0');
    QString send_msg = "*"+msg.mid(0,6)+msg_len+msg.mid(10,2)+response+"#";
    emit sig_response(clientIP, send_msg.toLocal8Bit(), 1);
}
