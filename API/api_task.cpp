#include "api_thread.h"
#include <QJsonDocument>
#include <QJsonArray>

#define TODO_REQUEST_STORAGE    1
#define TODO_UPDATE_STORAGE     2
#define TODO_SEND_TASK          3

#define MSG_TYPE_REQUEST        0
#define MSG_TYPE_RESPONSE       1


enum STORAGE_TYPE{
    STORAGE_TYPE_NULL = 0,
    STORAGE_TYPE_MATERIAL = 1,
    STORAGE_TYPE_PACKING = 2,
    STORAGE_TYPE_TRAY = 3,
    STORAGE_TYPE_GARBAGE = 4,
    STORAGE_TYPE_PRODUCT = 5,
};

void APIThread::init_map()
{
    inter_wms->db_queryStorageMap(mapping_table);

}

void APIThread::init_taskinfo()
{
    inter_wms->db_queryTaskInfo(mapping_task);

}
/********************************************************************************************************
 * Function Name :                  prase_json_request
 * Function Main Usage:
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/

void APIThread::prase_json_request(QJsonObject request, QWebSocket* client)
{
    QJsonObject response;

    if(!request.contains("todo") || !request.contains("type") || !request.contains("queuenumber"))
    {
        response.insert("queuenum", 1);
        response.insert("type", MSG_TYPE_RESPONSE);
        response.insert("retcode", "-1");
        response.insert("retmsg", "消息格式错误");

    }
    else
    {
        response.insert("type", MSG_TYPE_RESPONSE);
        response.insert("todo", request.value("todo").toInt());
        response.insert("queuenumber", request.value("queuenumber").toInt());

        int msgType = request.value("todo").toInt();
        switch (msgType) {
        case 1:
        {
            //{ "todo":1, "type":0, "queuenumber":1, "store_no" : "F1_MATERIAL" }
            if(!request.contains("store_no"))
            {
                response.insert("retcode", "-1");
                response.insert("retmsg", "消息格式错误");
                break;
            }
            QString store_no = request.take("store_no").toString();
            QVector< QStringList > res;
            RET_CODE ret = inter_wms->db_queryStorage(store_no, res);
            response.insert("retcode", ret);
            if(RET_OK == ret)
            {
                int item_count = res.size();
                response.insert("storage_count", item_count);
                response.insert("retmsg", "查询库位信息成功");

                QJsonArray storage_info;

                for(int i = 0; i < item_count; i++)
                {
                    QJsonObject json_object;
                    QStringList info = res.at(i).at(0).split("|");
                    json_object.insert("store_no", info.at(0));
                    json_object.insert("storage_no", info.at(1));
                    json_object.insert("status", info.at(2).toInt());
                    json_object.insert("material", info.at(3));
                    storage_info.insert(i, json_object);
                }
                response.insert("storage_info", storage_info);
            }
            else {
                response.insert("retmsg", "查询库位信息失败");
            }
            break;
        }
        case 2:
        {
            if(!request.contains("store_no") || !request.contains("storage_no") || !request.contains("status") || !request.contains("material"))
            {
                response.insert("retcode", "-1");
                response.insert("retmsg", "消息格式错误");
                break;
            }
            QString store_no = request.value("store_no").toString();
            QString storage_no = request.value("storage_no").toString();
            int status = request.value("status").toInt();
            QString material_id = QString::number(request.value("material").toInt());
            RET_CODE ret = inter_wms->db_updateStorage(store_no, storage_no, material_id, status, QString::number(client->peerPort()));
            response.insert("retcode", ret);
            if(RET_OK == ret)
            {
                response.insert("retmsg", "储位信息更新成功");
                updateClientStorage(store_no, storage_no, material_id, status);
            }
            else
            {
                RET_CODE ret = inter_wms->db_queryStorageStatus(store_no, storage_no, material_id, status);
                if(RET_OK == ret && status == 2)
                {
                    status = (material_id.size()) ? 1: 0;
                    //恢复为之前的状态
                    updateClientStorage(store_no, storage_no, material_id, status);
                }
                response.insert("retmsg", "储位信息更新失败");
            }
            break;
        }
        case 3:
        {
            //
            QString store_no_out = request.value("from_store_no").toString();
            QString store_no_in = request.value("to_store_no").toString();
            int store_type = request.value("store_type").toInt();
            int from_available, to_available, tasknum;
            inter_wms->db_queryAvailable(store_no_out, 1, from_available, store_type);
            inter_wms->db_queryAvailable(store_no_in, 0, to_available, -1);
            tasknum = std::min(from_available, to_available);
            inter_wms->db_updateTaskStatus(store_no_out, 1, store_no_in);
            //            for(int i = 0; i < tasknum; i++)
            //            {
            //                QString storage_no_out, storage_no_in;
            //                QString key_part_no = QString::number(store_type);
            //                RET_CODE ret_out = inter_wms->db_out_preAssign(store_no_out, 0, storage_no_out, key_part_no);
            //                RET_CODE ret_in = inter_wms->db_preAssign(store_no_in, 0, 0, storage_no_in);
            //                QString key_out = store_no_out+"_"+storage_no_out;
            //                QString key_in = store_no_in+"_"+storage_no_in;
            //                QString task;

            //                if(RET_OK == ret_out && RET_OK == ret_in)
            //                {
            //                    //[agvid] [优先级] [do] [where] [do] [where]
            //                    task.append("0 1 pick ").append(mapping_table.value(key_out)).append(" ").append(store_no_out).append(" ").append(storage_no_out).append(" ").append(key_part_no)
            //                            .append(" put ").append(mapping_table.value(key_in)).append(" ").append(store_no_in).append(" ").append(storage_no_in).append(" ").append(key_part_no);
            //                    qDebug()<<"wms receive task:"<<task;
            //                    //send to agv_dispatch
            //                    emit sig_response("127.0.0.1", task.toLatin1(),1);
            //                }
            //            }
            if(tasknum)
            {
                response.insert("retmsg", "任务已成功发送");
                response.insert("retcode", RET_OK);
            }
            else
            {
                response.insert("retmsg", "任务发送失败,无可用库位");
                response.insert("retcode", RET_NOT_AVAILABLE);
            }
            break;
        }
        case 4:{
            //取消预分配
            QString store_no = request.value("store_no").toString();
            QString storage_no = request.value("storage_no").toString();
            RET_CODE ret = inter_wms->db_cancelPreAssign(store_no, storage_no);
            response.insert("retcode", ret);
            if(RET_OK == ret)
            {
                response.insert("retmsg", "储位信息更新成功");
                updateClientStorage(store_no, storage_no, material_id, status);
            }
            else
            {
                response.insert("retmsg", "储位信息更新失败");
            }

            break;
        }
        default:
            break;
        }
    }
    emit sig_response(QString(QJsonDocument(response).toJson()), client);
    return;
    //inter_wms->db_queryStorageMap(mapping_table);

}

void APIThread::generate_task(QString tasktype, QString in_store_no, QString in_storage_no, QString key_part_no)
{
    if("TASK_MATERIAL" == tasktype)
    {
        QString to_store = ("RAW" == key_part_no) ? "F3_WQ":"F3_WB";
        QString storage_no;
        RET_CODE ret = inter_wms->db_preAssign(in_store_no, 0, 1, in_storage_no);
        if(RET_OK != ret)
            return;
        ret = inter_wms->db_preAssign(to_store, 0, 0, storage_no);
        QString task;
        QString key_out = in_store_no+"_"+in_storage_no;
        QString key_in = to_store+"_"+storage_no;
        if(RET_OK == ret)
        {
            //[agvid] [优先级] [do] [where] [do] [where]
            task.append("0 1 get_good ").append(QString::number(mapping_table.value(key_out).map_id)).append(" ").append(in_store_no).append(" ").append(in_storage_no).append(" ").append(key_part_no)\
                    .append(" put_good ").append(QString::number(mapping_table.value(key_in).map_id)).append(" ").append(to_store).append(" ").append(storage_no).append(" ").append(key_part_no);
            qDebug()<<"wms receive task:"<<task;
            QString msg_len = QString::number(task.length()+4).rightJustified(4, '0');
            QString send_task;
            send_task.append("*").append(msg_len).append(task).append("#");
            //send to agv_dispatch
            emit sig_response("127.0.0.1", send_task.toLatin1(),1);
        }
    }
}

void APIThread::updateClientStorage(QString _store_no, QString _storage_no,  QString _key_part_no, int _status)
{
    QJsonObject obj;
    int queuenumber = sendQueueNumber++;
    if(queuenumber>255)queuenumber = 1;

    obj["todo"] = TODO_UPDATE_STORAGE;
    obj["type"] = MSG_TYPE_REQUEST;
    obj["queuenumber"] = queuenumber;
    obj["store_no"] = _store_no;
    obj["storage_no"] = _storage_no;
    obj["status"] = _status;
    obj["material"] = _status? _key_part_no :"";

    QJsonDocument doc(obj);
    QString request(doc.toJson(QJsonDocument::Compact));
    //通知所有连上的平板客户端
    emit sig_notifyAll(request);
}

void APIThread::auto_generate_task()
{
    //查询目前可以执行的任务
    inter_wms->db_updateTaskStatus("", 2, "");

    //生成任务
    QVector< QStringList > res;
    inter_wms->db_queryTaskAvailable(res);

    for(int i = 0; i < res.size(); i++)
    {
        QStringList query_res = res.at(i).at(0).split("|");
        QString store_no_out, store_no_in, key_part_no;
        store_no_out = query_res.at(0);
        store_no_in = query_res.at(3);
        key_part_no = query_res.at(2);
        QString storage_no_out, storage_no_in;
        RET_CODE ret_out = inter_wms->db_out_preAssign(store_no_out, 0, storage_no_out, key_part_no);
        RET_CODE ret_in = inter_wms->db_preAssign(store_no_in, 0, 0, storage_no_in);
        QString key_out = store_no_out+"_"+storage_no_out;
        QString key_in = store_no_in+"_"+storage_no_in;
        QString task;
        int priority = 1;

        if(mapping_task.contains(std::make_pair(store_no_out, store_no_in)))
        {
            priority = mapping_task.value(std::make_pair(store_no_out, store_no_in)).priority;
        }
        if(RET_OK == ret_out && RET_OK == ret_in)
        {
            //[agvid] [优先级] [do] [where] [do] [where]
            task.append("0 ").append(priority).append(" pick ").append(QString::number(mapping_table.value(key_out).map_id)).append(" ").append(store_no_out).append(" ").append(storage_no_out).append(" ").append(key_part_no)\
                    .append(" put ").append(QString::number(mapping_table.value(key_in).map_id)).append(" ").append(store_no_in).append(" ").append(storage_no_in).append(" ").append(key_part_no);
            QString msg_len = QString::number(task.length()+4).rightJustified(4, '0');
            QString send_task;
            send_task.append("*").append(msg_len).append(task).append("#");

            qDebug()<<"wms receive task:"<<send_task;
            //send to agv_dispatch
            emit sig_response("127.0.0.1", send_task.toLatin1(),1);
        }
    }
}
