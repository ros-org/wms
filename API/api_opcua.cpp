#include "api_thread.h"


void APIThread::slot_readOpcMsg(QString storage_no, int times, QString ip, int port)
{  
    opcMsgLock.lock();
    receive_opcbuff.push_back(std::make_pair(storage_no, times));
    opcMsgLock.unlock();
    qDebug("[%s:%d]opcmsg: %s %d", ip.toStdString().data(), port, storage_no.toStdString().data(), times);
}


void APIThread::slot_readyOpcMsg(QString storage_no, bool flag, QString ip, int port)
{
    opcReadyMsgLock.lock();
    receive_opcreadybuff.push_back(std::make_pair(storage_no, flag));
    opcReadyMsgLock.unlock();
    qDebug("[%s:%d]opcmsg: %s %d", ip.toStdString().data(), port, storage_no.toStdString().data(), flag);
}

void APIThread::praseOpcMsg(QString storage_no, int times)
{
    QString store_no_out = "F3_MD";
    QString store_no_in = "F3_XB";
    QString key_part_no = QString::number(PRODUCT);

    qDebug()<<"times ========"<<times;
    if(times >= 0)
    {
        int count;
        inter_wms->db_queryAvailable(store_no_in, 0, count, -1);
        qDebug()<<"count ========"<<count;
        if(count > 0)
        {
            //如果有空余库位
            RET_CODE ret = inter_wms->db_updateStorage(store_no_out, storage_no, key_part_no, 2, "OPC", times);
            qDebug("opcupdate: %s %d, ret=%d", storage_no.toStdString().data(), 2, ret);
            qDebug()<<"query xian bian ku ========"<<ret;
            if(RET_OK != ret)
            {
                qDebug()<<"no xianbian ku!!!!!!!!!!!1";
                return;
            }
            QString storage_no_in;
            QString current_station_key;
            current_station_key.append(store_no_out).append("_").append(storage_no);
            //选距离最近的线边库入库
            RET_CODE ret_in = inter_wms->db_preAssignByDis(store_no_in, 0, 0, current_station_key, storage_no_in);
            QString key_out = store_no_out+"_"+storage_no;
            QString key_in = store_no_in+"_"+storage_no_in;
            QString task;
            qDebug()<<"nearest xian bian ku ========"<<ret_in;
            if(RET_OK == ret_in)
            {
                //查询可用的自动托盘机
                QString store_emptytray = "F3_AUTOTRAY";
                QString storage_no_tray;

                RET_CODE ret_empty = inter_wms->db_counter_preAssign(store_emptytray, 0, storage_no_tray, QString::number(TRAY));
                QString key_tray_out = store_emptytray+"_"+storage_no_tray;
                QString key_tray_in = store_no_out+"_"+storage_no;
                //TODO:test
                //ret_empty = RET_OK;
                qDebug()<<"query tray  ========"<<ret_empty;
                if(RET_OK == ret_empty)
                {
                    //[agvid] [优先级] [do] [where] [do] [where]
                    //码垛相关任务优先级最高
                    //TODO 指定x号车
                    task.append("0 2 pick ").append(QString::number(mapping_table.value(key_out).map_id)).append(" ").append(store_no_out).append(" ").append(storage_no).append(" ").append(key_part_no)\
                            .append(" put ").append(QString::number(mapping_table.value(key_in).map_id)).append(" ").append(store_no_in).append(" ").append(storage_no_in).append(" ").append(key_part_no)\
                            .append(" pick ").append(QString::number(mapping_table.value(key_tray_out).map_id)).append(" ").append(store_emptytray).append(" ").append(storage_no_tray).append(" ").append(QString::number(TRAY))\
                            .append(" put ").append(QString::number(mapping_table.value(key_tray_in).map_id)).append(" ").append(store_no_out).append(" ").append(storage_no).append(" ").append(QString::number(TRAY));

                    //回停车位等待，由调度执行决定去哪个等待位置
                    task.append(" wait 0");


//                    //查询可用的小车停车区
//                    QString store_wait = "F3_WAIT";
//                    //暂时任务完成后都返回1号停车位
//                    QString storage_no_wait = "01";

//                    //                    RET_CODE ret_wait = inter_wms->db_preAssign(store_wait, 0, 0, storage_no_wait);
//                    QString key_wait = store_wait+"_"+storage_no_wait;

//                    //                    if(RET_OK == ret_wait)
//                    //                    {
//                    task.append(" move ").append(QString::number(mapping_table.value(key_wait).map_id));
//                    //                    }

                    QString msg_len = QString::number(task.length()+4).rightJustified(4, '0');
                    QString send_task;
                    send_task.append("*").append(msg_len).append(task).append("#");

                    qDebug()<<"wms send task:"<<send_task;
                    //send to agv_dispatch
                    qDebug()<<"send_task  ========"<<send_task;
                    emit sig_response("127.0.0.1", send_task.toLatin1(),1);
                }
            }
        }
        else
        {
            //如果暂时没有空余线边库 则更新库存和任务信息 待有空线边库时再执行
            //inter_wms->db_updateStorage(store_no_out, storage_no, "5", 1, "OPC", times);
            //inter_wms->db_updateTaskStatus(store_no_in,1,store_no_in);
            qDebug("暂时无空闲线边库 opcupdate: %s %d", storage_no.toStdString().data(), 1);
        }
    }
}

void APIThread::praseOpcReadyMsg(QString storage_no, bool flag)
{
    if(flag)
    {
        QString store_no = "F3_MD";

        QString station_key;
        station_key.append(store_no).append("_").append(storage_no);

        QString task;
        //准备码垛
        task.append("1 2 move ").append(QString::number(mapping_table.value(station_key).map_readyid));

        QString msg_len = QString::number(task.length()+4).rightJustified(4, '0');
        QString send_task;
        send_task.append("*").append(msg_len).append(task).append("#");

        qDebug()<<"wms send readytask:"<<send_task;
        //send to agv_dispatch
        emit sig_response("127.0.0.1", send_task.toLatin1(),1);
    }
}
