#include "interface_wms.h"
#include "Database/db.h"
#include <QDebug>
#include <QVector>
DB* InterfaceWMS::m_pDB;

/********************************************************************************************************
 * Function Name :                  InterfaceWMS
 * Function Main Usage:             构造函数
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/

InterfaceWMS::InterfaceWMS()
{
    if (m_pDB == NULL)
    {
        //lock();
        if (m_pDB == NULL)
        {
            m_pDB = new DB();
        }
        //unlock();
    }
}

/********************************************************************************************************
 * Function Name :                  db_connect
 * Function Main Usage:             数据库连接
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/
void InterfaceWMS::db_connect(QString dbName)
{
    m_pDB->DBconnect(dbName);
}

/********************************************************************************************************
 * Function Name :                  db_disconnect
 * Function Main Usage:             数据库断开连接
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/
void InterfaceWMS::db_disconnect()
{
    m_pDB->DBdisconnect();
}

/********************************************************************************************************
 * Function Name :                  db_counter_preAssign
 * Function Main Usage:             自动计数类预分配
 *
 * Author/Date:
 * Modefy/Date:
 * modify: 自动展板机不记录数量，只记录是否可用，可用情况下，轮流使用
 *          count > 0 可用  count<=0 不可用
 * 除了展板机也不会有其他count类型的 ，key part no 略去不用
 * 取消 展板机预分配模式
********************************************************************************************************/
RET_CODE InterfaceWMS::db_counter_preAssign(QString store_no, int agv_id, QString &storage_no, QString key_part_no)
{
    int rownum, colnum;
    static int use_index = 0;
    QVector< QStringList > res;
    QString err_msg;
    //预分配查询:（取其中一笔）
    QString query_sql;

    //task preassign
    query_sql = QString("SELECT STORAGE_NO FROM R_STORE_STATUS_T WHERE STORE_NO='%1' AND count >0 ").arg(store_no);
    //    query_sql = QString("SELECT STORAGE_NO, MAX(COUNT) FROM R_STORE_STATUS_T WHERE STORE_NO='%1' ORDER BY STATUS DESC, STORAGE_NO ASC limit 1")
    //            .arg(store_no);
    bool ret = m_pDB->DBQuery(query_sql, rownum, colnum, res, err_msg);
    //    qDebug()<<rownum;

    if(!ret)
    {
        return RET_DB_ERROR;
    }

    if(rownum <= 0)
    {
        return RET_NOT_AVAILABLE;
    }
    else
    {
        storage_no = res.at(++use_index%rownum).at(0);
        //        //预分配更新:
        //        QString update_sql = QString("UPDATE R_STORE_STATUS_T SET STATUS='2',AGV_ID=%1,WORK_TIME= datetime('now', 'localtime') WHERE STORE_NO='%2' AND STORAGE_NO='%3'").arg(agv_id).arg(store_no).arg(storage_no);
        //        ret = m_pDB->DBUpdate(update_sql, err_msg);
        //        if(ret){
        //            ++use_index;
        //        }
        //        return ret ? RET_OK : RET_DB_ERROR;
    }

    return RET_OK;
}

/********************************************************************************************************
 * Function Name :                  db_out_preAssign
 * Function Main Usage:             出库预分配
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/
RET_CODE InterfaceWMS::db_out_preAssign(QString store_no, int agv_id, QString &storage_no, QString key_part_no)
{
    int rownum, colnum;
    QVector< QStringList > res;
    QString err_msg;
    //预分配查询:（取其中一笔）
    QString query_sql;
    if(agv_id == 0)
    {
        //task preassign
        query_sql = QString("SELECT * FROM R_STORE_STATUS_T WHERE (STATUS='1' AND STORE_NO='%1' AND KEY_PART_NO = '%2' AND TASK_STATUS = '2') ORDER BY STATUS DESC, STORAGE_NO ASC limit 1")\
                .arg(store_no).arg(key_part_no);
    }
    else
    {
        query_sql = QString("SELECT * FROM R_STORE_STATUS_T WHERE ((STATUS='1' AND STORE_NO='%1') OR (STATUS='2' AND STORE_NO='%1' AND (AGV_ID='%2'||AGV_ID='0')) AND KEY_PART_NO = '%3' AND TASK_STATUS = '2') ORDER BY STATUS DESC, STORAGE_NO ASC limit 1")\
                .arg(store_no).arg(agv_id).arg(key_part_no);
    }
    bool ret = m_pDB->DBQuery(query_sql, rownum, colnum, res, err_msg);
    //    qDebug()<<rownum;

    if(!ret)
    {
        return RET_DB_ERROR;
    }

    if(rownum == 0)
    {
        return RET_NOT_AVAILABLE;
    }
    else
    {
        storage_no = res.at(0).at(1);
        //        key_part_no = res.at(0).at(2);
        qDebug()<<"预分配的储位:"<<storage_no<<"Material:"<<res.at(0).at(2);
        //预分配更新:
        QString update_sql = QString("UPDATE R_STORE_STATUS_T SET STATUS='2',AGV_ID=%1,WORK_TIME= datetime('now', 'localtime'), TASK_STATUS='0' WHERE STORE_NO='%2' AND STORAGE_NO='%3'").arg(agv_id).arg(store_no).arg(storage_no);
        ret = m_pDB->DBUpdate(update_sql, err_msg);

        return ret ? RET_OK : RET_DB_ERROR;
    }
}

/********************************************************************************************************
 * Function Name :                  db_updateTaskStatus
 * Function Main Usage:             更新任务信息
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/
RET_CODE InterfaceWMS::db_updateTaskStatus(QString from_store, int status, QString to_store,int store_type)
{
    QString err_msg;
    //qDebug()<<"库区:"<<store_no<<"任务置为:"<<status<<",目标库区:"<<to_store;
    //更新任务状态:
    QString update_sql;
    if(status == 1)
    {
        update_sql= QString("UPDATE R_STORE_STATUS_T SET TASK_STATUS='%3', TASK_DEST = '%2', WORK_TIME= datetime('now', 'localtime') WHERE STORE_NO='%1' AND STATUS='1' AND TASK_STATUS = '0'").arg(from_store).arg(to_store).arg(status);
        if(store_type!=-1)
        {
            update_sql.append(QString(" AND KEY_PART_NO = '%1' ").arg(store_type));
        }
    }
    else if(status == 2)
    {
        update_sql= QString(" UPDATE R_STORE_STATUS_T SET TASK_STATUS = '2' WHERE ( (STORE_NO||STORAGE_NO IN (SELECT STORE_NO||MIN(STORAGE_NO) FROM R_STORE_STATUS_T WHERE (STATUS='1' OR STATUS='2') GROUP BY(STORE_NO))  OR (STORE_NO||TASK_DEST NOT IN (SELECT FROM_STORE_NO||TO_STORE_NO FROM C_TASK_DEF_T )))) AND  TASK_STATUS = '1' ");
    }
    int ret = m_pDB->DBUpdate(update_sql, err_msg);

    return ret ? RET_OK : RET_DB_ERROR;
}


/********************************************************************************************************
 * Function Name :                  db_queryTaskAvailable
 * Function Main Usage:             查询可用任务信息
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/

RET_CODE InterfaceWMS::db_queryTaskAvailable(QVector< QStringList > &res)
{
    int rownum, colnum;
    QString err_msg;
    QString query_sql = QString("SELECT STORE_NO||'|'||STORAGE_NO||'|'||(case ifnull(KEY_PART_NO,'') when '' then 0  when 'RAW' then 1 when 'PACK' then 2 when 'TRAY' then 3 when 'TRASH' then 4 when 'PRODUCT' then 5 ELSE KEY_PART_NO END )|| '|' ||TASK_DEST  FROM R_STORE_STATUS_T WHERE TASK_STATUS = '2'");

    bool ret = m_pDB->DBQuery(query_sql, rownum, colnum, res, err_msg);

    if(!ret)
    {
        return RET_DB_ERROR;
    }
    return RET_OK;
}

/********************************************************************************************************
 * Function Name :                  db_preAssign
 * Function Main Usage:             预分配(type:1-出库 0-入库)
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/
RET_CODE InterfaceWMS::db_preAssign(QString store_no, int agv_id, int type, QString &storage_no)
{
    int rownum, colnum;
    QVector< QStringList > res;
    QString err_msg;
    //预分配查询:（取其中一笔）
    QString query_sql;
    if(agv_id == 0)
    {
        //task preassign
        query_sql = QString("SELECT * FROM R_STORE_STATUS_T WHERE (STATUS='%2' AND STORE_NO='%1') ORDER BY STATUS DESC, STORAGE_NO ASC limit 1")\
                .arg(store_no).arg(type);
    }
    else
    {
        query_sql = QString("SELECT * FROM R_STORE_STATUS_T WHERE (STATUS='%3' AND STORE_NO='%1') OR (STATUS='2' AND STORE_NO='%1' AND (AGV_ID='%2'||AGV_ID='0')) ORDER BY STATUS DESC, STORAGE_NO ASC limit 1")\
                .arg(store_no).arg(agv_id).arg(type);
    }
    bool ret = m_pDB->DBQuery(query_sql, rownum, colnum, res, err_msg);
    //    qDebug()<<rownum;

    if(!ret)
    {
        return RET_DB_ERROR;
    }

    if(rownum == 0)
    {
        return RET_NOT_AVAILABLE;
    }
    else
    {
        storage_no = res.at(0).at(1);
        //qDebug()<<"预分配的储位:"<<storage_no;
        //预分配更新:
        QString update_sql = QString("UPDATE R_STORE_STATUS_T SET STATUS='2',AGV_ID='%1',WORK_TIME= datetime('now', 'localtime') WHERE STORE_NO='%2' AND STORAGE_NO='%3'").arg(agv_id).arg(store_no).arg(storage_no);
        ret = m_pDB->DBUpdate(update_sql, err_msg);

        return ret ? RET_OK : RET_DB_ERROR;
    }
}

/********************************************************************************************************
 * Function Name :                  db_preAssignByDis
 * Function Main Usage:             预分配(type:1-出库 0-入库)
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/
RET_CODE InterfaceWMS::db_preAssignByDis(QString store_no, int agv_id, int type, QString current_station_key, QString &storage_no)
{
    int rownum, colnum;
    QVector< QStringList > res;
    QString err_msg;
    //预分配查询:（取所有）
    QString query_sql;
    if(agv_id == 0)
    {
        //task preassign
        query_sql = QString("SELECT * FROM R_STORE_STATUS_T WHERE (STATUS='%2' AND STORE_NO='%1') ORDER BY STATUS DESC, STORAGE_NO ASC")\
                .arg(store_no).arg(type);
    }
    else
    {
        query_sql = QString("SELECT * FROM R_STORE_STATUS_T WHERE (STATUS='%3' AND STORE_NO='%1') OR (STATUS='2' AND STORE_NO='%1' AND (AGV_ID='%2'||AGV_ID='0')) ORDER BY STATUS DESC, STORAGE_NO ASC")\
                .arg(store_no).arg(agv_id).arg(type);
    }
    bool ret = m_pDB->DBQuery(query_sql, rownum, colnum, res, err_msg);
    //    qDebug()<<rownum;

    if(!ret)
    {
        return RET_DB_ERROR;
    }

    if(rownum == 0)
    {
        return RET_NOT_AVAILABLE;
    }
    else
    {
        int min_dis = INT_MAX;//用直线距离计算
        QString min_storage_no;
        STATION_INFO current_station = mapping_table.value(current_station_key);

        for(int k = 0; k < rownum; k++)
        {
            QString temp_storage_no = res.at(k).at(1);
            QString temp_key;
            temp_key.append(store_no).append("_").append(temp_storage_no);
            STATION_INFO temp_station = mapping_table.value(temp_key);
            int dis = abs(temp_station.pos_x-current_station.pos_x)+abs(temp_station.pos_y-current_station.pos_y);
            if(dis < min_dis)
            {
                min_dis = dis;
                min_storage_no = temp_storage_no;
            }
        }
        storage_no = min_storage_no;
        //qDebug()<<"预分配的储位:"<<storage_no;
        //预分配更新:
        QString update_sql = QString("UPDATE R_STORE_STATUS_T SET STATUS='2',AGV_ID='%1',WORK_TIME= datetime('now', 'localtime') WHERE STORE_NO='%2' AND STORAGE_NO='%3'").arg(agv_id).arg(store_no).arg(storage_no);
        ret = m_pDB->DBUpdate(update_sql, err_msg);

        return ret ? RET_OK : RET_DB_ERROR;
    }
}
/********************************************************************************************************
 * Function Name :                  db_cancelPreAssign
 * Function Main Usage:             取消预分配
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/
RET_CODE InterfaceWMS::db_cancelPreAssign(QString store_no, QString storage_no, QString &material_id)
{
    QString err_msg;
    int count,column;
    QVector< QStringList > res;
    QString query_sql = QString("SELECT KEY_PART_NO FROM R_STORE_STATUS_T WHERE storage_no='%2' AND STORE_NO='%1'")\
            .arg(store_no).arg(storage_no);

    bool ret = m_pDB->DBQuery(query_sql, count, column, res, err_msg);
    if(!ret)return RET_DB_ERROR;
    material_id = "";
    if(column > 0)
    {
        material_id = res.at(0).at(0);
    }
    //取消预分配:
    QString update_sql = QString("UPDATE R_STORE_STATUS_T SET STATUS='0',TASK_STATUS='0',AGV_ID='',WORK_TIME= datetime('now', 'localtime') WHERE storage_no = '%1' AND STORE_NO='%2' ").arg(storage_no).arg(store_no);
    ret = m_pDB->DBUpdate(update_sql, err_msg);
    return ret ? RET_OK : RET_DB_ERROR;
}

RET_CODE InterfaceWMS::db_autoTrayEnable(QString store_no, QString storage_no, bool enable)
{
    QString err_msg;
    int count = enable?1:0;
    QString update_sql = QString("UPDATE R_STORE_STATUS_T SET count='%3' WHERE storage_no = '%1' AND STORE_NO='%2' ").arg(storage_no).arg(store_no).arg(count);
    bool ret = m_pDB->DBUpdate(update_sql, err_msg);
    return ret ? RET_OK : RET_DB_ERROR;
}

/********************************************************************************************************
 * Function Name :                  db_cancelPreAssign
 * Function Main Usage:             取消预分配(type:1-出库 0-入库)
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/
RET_CODE InterfaceWMS::db_cancelPreAssign(QString store_no, int agv_id, int type)
{
    int rownum, colnum;
    QVector< QStringList > res;
    QString err_msg;
    //预分配查询:（取其中一笔）
    QString query_sql = QString("SELECT * FROM R_STORE_STATUS_T WHERE STATUS='2' AND STORE_NO='%1' AND AGV_ID='%2' ")\
            .arg(store_no).arg(agv_id);
    bool ret = m_pDB->DBQuery(query_sql, rownum, colnum, res, err_msg);
    //    qDebug()<<rownum;
    if(!ret)
    {
        return RET_DB_ERROR;
    }

    if(rownum == 0)
    {
        qDebug()<<"该小车尚未预分配任务";
        return RET_PRERECORD_NOT_FOUND;
    }
    else
    {
        //取消预分配:
        QString update_sql = QString("UPDATE R_STORE_STATUS_T SET STATUS='%1',AGV_ID='',WORK_TIME= datetime('now', 'localtime') WHERE STATUS = '2' AND STORE_NO='%2' AND AGV_ID='%3'").arg(type).arg(store_no).arg(agv_id);
        ret = m_pDB->DBUpdate(update_sql, err_msg);
        return ret ? RET_OK : RET_DB_ERROR;
    }
}


/********************************************************************************************************
 * Function Name :                  db_inStock
 * Function Main Usage:             入库
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/

RET_CODE InterfaceWMS::db_inStock(QString store_no, QString storage_no, int agv_id, QString key_part_no)
{
    int rownum, colnum;
    QVector< QStringList > res;
    QString err_msg;

    //查询是否已预分配
    QString query_sql = QString("SELECT * FROM R_STORE_STATUS_T WHERE STATUS='2' AND STORE_NO='%1' AND (AGV_ID='%2' OR AGV_ID='0') AND STORAGE_NO='%3'")\
            .arg(store_no).arg(agv_id).arg(storage_no);
    bool ret = m_pDB->DBQuery(query_sql, rownum, colnum, res, err_msg);
    //    qDebug()<<rownum;
    if(!ret)
    {
        return RET_DB_ERROR;
    }

    if(rownum == 0)
    {
        qDebug()<<"该小车尚未预分配任务";
        return RET_PRERECORD_NOT_FOUND;
    }
    //入库更新
    QString update_sql = QString("UPDATE R_STORE_STATUS_T SET AGV_ID = '%4', STATUS='1',KEY_PART_NO='%1',WORK_TIME= datetime('now', 'localtime') WHERE STATUS = '2' AND STORE_NO='%2' AND STORAGE_NO='%3' AND (AGV_ID = '%4' OR AGV_ID='0');")\
            .arg(key_part_no).arg(store_no).arg(storage_no).arg(agv_id);

    ret = m_pDB->DBUpdate(update_sql, err_msg);
    if(ret)
    {
        qDebug()<<"入库完成";
        //记日志
        ret = db_log(store_no, storage_no, "AGV"+QString::number(agv_id), 0, key_part_no);
    }
    return ret ? RET_OK : RET_DB_ERROR;
}

/********************************************************************************************************
 * Function Name :                  db_outStock
 * Function Main Usage:             出库
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/

RET_CODE InterfaceWMS::db_outStock(QString store_no, QString storage_no, int agv_id)
{
    int rownum, colnum;
    QVector< QStringList > res;
    QString err_msg;

    //查询是否已预分配
    QString query_sql = QString("SELECT * FROM R_STORE_STATUS_T WHERE STATUS='2' AND STORE_NO='%1' AND (AGV_ID='%2' OR AGV_ID='0') AND STORAGE_NO='%3'")\
            .arg(store_no).arg(agv_id).arg(storage_no);
    bool ret = m_pDB->DBQuery(query_sql, rownum, colnum, res, err_msg);
    //    qDebug()<<rownum;

    if(rownum == 0)
    {
        qDebug()<<"该小车尚未预分配任务";
        return RET_PRERECORD_NOT_FOUND;
    }
    //出库更新
    QString update_sql = QString("UPDATE R_STORE_STATUS_T SET AGV_ID = '%3', STATUS='0',KEY_PART_NO='',WORK_TIME=datetime('now', 'localtime') WHERE STATUS = '2' AND STORE_NO='%1' AND STORAGE_NO='%2' AND (AGV_ID = '%3' OR AGV_ID='0');").arg(store_no).arg(storage_no).arg(agv_id);
    ret =  m_pDB->DBUpdate(update_sql, err_msg);

    if(ret)
    {
        qDebug()<<"出库完成";
        //记日志
        ret = db_log(store_no, storage_no, "AGV"+QString::number(agv_id), 1, "");
    }
    return ret ? RET_OK : RET_DB_ERROR;
}


/********************************************************************************************************
 * Function Name :                  db_queryAvailable
 * Function Main Usage:             查询可用
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/

RET_CODE InterfaceWMS::db_queryAvailable(QString store_no, int status, int& count, int key_part_no)
{
    int colnum;
    QVector< QStringList > res;
    QString err_msg;

    //查询是否已预分配
    QString query_sql = QString("SELECT * FROM R_STORE_STATUS_T WHERE STATUS='%2' AND STORE_NO='%1'")\
            .arg(store_no).arg(status);

    if(key_part_no != -1)
    {
        query_sql.append(" AND KEY_PART_NO = '").append(QString::number(key_part_no)).append("'");
    }
    bool ret = m_pDB->DBQuery(query_sql, count, colnum, res, err_msg);
    return ret ? RET_OK : RET_DB_ERROR;
}

/********************************************************************************************************
 * Function Name :                  db_log
 * Function Main Usage:             写日志
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/

bool InterfaceWMS::db_log(QString store_no, QString storage_no, QString user_id, int type,  QString key_part_no)
{
    QString err_msg;

    QString insert_sql = QString("INSERT INTO R_STORE_LOG_T(STORE_NO, STORAGE_NO, KEY_PART_NO, MOTION_TYPE, USER_ID) VALUES('%1', '%2', '%3', '%4', '%5');")\
            .arg(store_no).arg(storage_no).arg(key_part_no).arg(type).arg(user_id);
    return m_pDB->DBInsert(insert_sql, err_msg);
}


/********************************************************************************************************
 * Function Name :                  db_newStore
 * Function Main Usage:             新建库别
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/

RET_CODE InterfaceWMS::db_newStore(QString store_no, QString store_name, QString user)
{
    int rownum, colnum;
    QVector< QStringList > res;
    QString err_msg;

    //查询是否已存在
    QString query_sql = QString("SELECT * FROM C_STORE_DEF_T WHERE STORE_NO='%1'")\
            .arg(store_no);
    bool ret = m_pDB->DBQuery(query_sql, rownum, colnum, res, err_msg);

    if(!ret)
    {
        return RET_DB_ERROR;
    }

    if(rownum != 0)
    {
        qDebug("该库别%s已存在",qPrintable(store_no));
        return RET_RECORD_ALREADY_EXIST;
    }

    //新建库别
    QString insert_sql = QString("INSERT INTO C_STORE_DEF_T(STORE_NO, STORE_NAME, STRATEGY, CREATE_USER, CREATE_TIME) VALUES('%1', '%2', 1, '%3', datetime('now', 'localtime'));")\
            .arg(store_no).arg(store_name).arg(user);
    ret =  m_pDB->DBInsert(insert_sql, err_msg);
    return ret ? RET_OK : RET_DB_ERROR;
}


/********************************************************************************************************
 * Function Name :                  db_newStorage
 * Function Main Usage:             新建储位
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/

RET_CODE InterfaceWMS::db_newStorage(QString store_no, QString storage_no, QString user)
{
    int rownum, colnum;
    QVector< QStringList > res;
    QString err_msg;

    //查询是否已存在
    QString query_sql = QString("SELECT * FROM C_STORAGE_DEF_T WHERE STORE_NO='%1' AND STORAGE_NO='%2'")\
            .arg(store_no).arg(storage_no);
    bool ret = m_pDB->DBQuery(query_sql, rownum, colnum, res, err_msg);

    if(!ret)
    {
        return RET_DB_ERROR;
    }

    if(rownum != 0)
    {
        qDebug("该储位%s-%s已存在",qPrintable(store_no), qPrintable(storage_no));
        return RET_RECORD_ALREADY_EXIST;
    }

    //新建储位
    QString insert_sql = QString("INSERT INTO C_STORAGE_DEF_T(STORE_NO, STORAGE_NO, CREATE_USER, CREATE_TIME) VALUES('%1', '%2', '%3', datetime('now', 'localtime'));")\
            .arg(store_no).arg(storage_no).arg(user);
    ret = m_pDB->DBInsert(insert_sql, err_msg);

    if(!ret)
    {
        return RET_DB_ERROR;
    }
    //同时更新库存
    insert_sql = QString("INSERT INTO R_STORE_STATUS_T(STORE_NO, STORAGE_NO, STATUS) VALUES('%1', '%2', '0');")\
            .arg(store_no).arg(storage_no);
    ret = m_pDB->DBInsert(insert_sql, err_msg);

    return ret ? RET_OK : RET_DB_ERROR;
}


/********************************************************************************************************
 * Function Name :                  db_updateStorage
 * Function Main Usage:             update储位
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/

RET_CODE InterfaceWMS::db_updateStorage(QString store_no, QString storage_no, QString key_part_no, int status, QString user)
{
    int rownum, colnum;
    QVector< QStringList > res;
    QString err_msg;

    //查询是否存在
    QString query_sql = QString("SELECT * FROM R_STORE_STATUS_T WHERE STORE_NO='%1' AND STORAGE_NO='%2' AND STATUS != 2")\
            .arg(store_no).arg(storage_no);
    bool ret = m_pDB->DBQuery(query_sql, rownum, colnum, res, err_msg);

    if(!ret)
    {
        return RET_DB_ERROR;
    }

    if(rownum == 0)
    {
        qDebug()<<QString::fromLocal8Bit("该储位%1-%2不存在/已被任务预分配,无法更新库存").arg(store_no).arg(storage_no);
        return RET_NOT_AVAILABLE;
    }

    //更新库存
    QString update_sql = QString("UPDATE R_STORE_STATUS_T SET STATUS='%1',KEY_PART_NO='%2',WORK_TIME=datetime('now', 'localtime'), MODIFY_USER='%3',AGV_ID='0' WHERE STORE_NO='%4' AND STORAGE_NO='%5';").arg(status).arg(key_part_no).arg(user).arg(store_no).arg(storage_no);
    ret =  m_pDB->DBUpdate(update_sql, err_msg);

    if(ret)
    {
        qDebug()<<"update完成";
        //记日志
        ret = db_log(store_no, storage_no, user, 2, key_part_no);
    }
    return ret ? RET_OK : RET_DB_ERROR;

}

/********************************************************************************************************
 * Function Name :                  db_updateStorage
 * Function Main Usage:             update储位
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/

RET_CODE InterfaceWMS::db_updateStorage(QString store_no, QString storage_no, QString key_part_no, int status, QString user, int count)
{
    int rownum, colnum;
    QVector< QStringList > res;
    QString err_msg;

    //查询是否存在
    QString query_sql = QString("SELECT * FROM R_STORE_STATUS_T WHERE STORE_NO='%1' AND STORAGE_NO='%2' AND STATUS != 2")\
            .arg(store_no).arg(storage_no);
    bool ret = m_pDB->DBQuery(query_sql, rownum, colnum, res, err_msg);

    if(!ret)
    {
        return RET_DB_ERROR;
    }

    if(rownum == 0)
    {
        qDebug()<<QString::fromLocal8Bit("该储位%1-%2不存在/已被任务预分配,无法更新库存").arg(store_no).arg(storage_no);
        return RET_NOT_AVAILABLE;
    }

    //更新库存
    QString update_sql = QString("UPDATE R_STORE_STATUS_T SET STATUS='%1',KEY_PART_NO='%2',WORK_TIME=datetime('now', 'localtime'), MODIFY_USER='%3',AGV_ID='0', COUNT='%6' WHERE STORE_NO='%4' AND STORAGE_NO='%5';").arg(status).arg(key_part_no).arg(user).arg(store_no).arg(storage_no).arg(count);
    ret =  m_pDB->DBUpdate(update_sql, err_msg);

    if(ret)
    {
        qDebug()<<"update完成";
        //记日志
        ret = db_log(store_no, storage_no, user, 2, key_part_no);
    }
    return ret ? RET_OK : RET_DB_ERROR;

}

/********************************************************************************************************
 * Function Name :                  db_queryStorageMap
 * Function Main Usage:             查询地图映射表
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/

RET_CODE InterfaceWMS::db_queryStorageMap(QMap<QString, STATION_INFO> & mapping_table)
{
    mapping_table.clear();
    int rownum, colnum;
    QVector< QStringList > res;
    QString err_msg;
    QString query_sql = QString("SELECT T1.STORE_NO, T1.STORAGE_NO, T1.MAP_STATION_ID, REALX, REALY, READY_STATION_ID, T3.COUNT FROM C_STORAGE_DEF_T AS T1, agv_station AS T2 , R_STORE_STATUS_T AS T3 WHERE T1.MAP_STATION_ID = ID AND T1.STORE_NO = T3.STORE_NO AND T1.STORAGE_NO = T3.STORAGE_NO;");
    bool ret = m_pDB->DBQuery(query_sql, rownum, colnum, res, err_msg);

    if(!ret || (colnum != 7))
    {
        return RET_DB_ERROR;
    }

    for(int i = 0; i < rownum; i++)
    {
        QString key;
        STATION_INFO station_info;
        station_info.map_id = res.at(i).at(2).toInt();
        station_info.pos_x = res.at(i).at(3).toInt();
        station_info.pos_y = res.at(i).at(4).toInt();
        station_info.map_readyid = res.at(i).at(5).toInt();
        station_info.times = res.at(i).at(6).toInt();
        key.append(res.at(i).at(0)).append("_").append(res.at(i).at(1));
        mapping_table.insert(key, station_info);
    }
    return RET_OK;
}


RET_CODE InterfaceWMS::db_queryTaskInfo(QMap<std::pair<QString, QString>, TASK_INFO> & mapping_task)
{
    mapping_task.clear();
    int rownum, colnum;
    QVector< QStringList > res;
    QString err_msg;
    QString query_sql = QString("SELECT FROM_STORE_NO, TO_STORE_NO, PRIORITY, STRATEGY FROM C_TASK_DEF_T");
    bool ret = m_pDB->DBQuery(query_sql, rownum, colnum, res, err_msg);

    if(!ret || (colnum != 4))
    {
        return RET_DB_ERROR;
    }

    for(int i = 0; i < rownum; i++)
    {
        TASK_INFO taskinfo;
        taskinfo.from_store = res.at(i).at(0);
        taskinfo.to_store = res.at(i).at(1);
        taskinfo.priority = res.at(i).at(2).toInt();
        taskinfo.strategy = res.at(i).at(3).toInt();
        mapping_task.insert(std::make_pair(res.at(i).at(0), res.at(i).at(1)), taskinfo);
    }
    return RET_OK;
}

/********************************************************************************************************
 * Function Name :                  db_queryStorage
 * Function Main Usage:             查询库存
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/

RET_CODE InterfaceWMS::db_queryStorage(QString store_no, QVector< QStringList > &res)
{
    int rownum, colnum;
    QString err_msg;
    QString query_sql = QString("SELECT STORE_NO||'|'||STORAGE_NO||'|'||ifnull(STATUS,0)||'|'||(case ifnull(KEY_PART_NO,'') when '' then 0  when 'RAW' then 1 when 'PACK' then 2 when 'TRAY' then 3 when 'TRASH' then 4 when 'PRODUCT' then 5	ELSE    KEY_PART_NO END )  FROM R_STORE_STATUS_T");

    if(store_no.trimmed() != "ALL")
        query_sql.append(" WHERE STORE_NO = '").append(store_no).append("'");
    bool ret = m_pDB->DBQuery(query_sql, rownum, colnum, res, err_msg);

    if(!ret)
    {
        return RET_DB_ERROR;
    }
    return RET_OK;
}

RET_CODE InterfaceWMS::db_queryAutotrayEnable(QString store_no, QVector<bool> &res)
{
    int rownum, colnum;
    QString err_msg;
    QVector< QStringList > ress;
    QString query_sql = QString("SELECT COUNT FROM R_STORE_STATUS_T WHERE store_no = '%1';").arg(store_no);

    bool ret = m_pDB->DBQuery(query_sql, rownum, colnum, ress, err_msg);

    if(!ret)
    {
        return RET_DB_ERROR;
    }

    if(colnum<=0)return RET_OK;

    for(int i=0;i<rownum;++i){
        res.append(ress.at(i).at(0).toInt()>0);
    }

    return RET_OK;
}

/********************************************************************************************************
 * Function Name :                  db_queryStorage
 * Function Main Usage:             查询库存
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/

RET_CODE InterfaceWMS::db_queryStorageStatus(QString store_no, QString storage_no, QString & key_part_no, int & status)
{
    int rownum, colnum;
    QString err_msg;
    QVector< QStringList > res;
    QString query_sql = QString("SELECT ifnull(STATUS,0), ifnull(KEY_PART_NO,'') FROM R_STORE_STATUS_T");

    if(store_no.trimmed() != "ALL")
        query_sql.append(" WHERE STORE_NO = '").append(store_no).append("' AND STORAGE_NO='").append(storage_no).append("'");
    bool ret = m_pDB->DBQuery(query_sql, rownum, colnum, res, err_msg);

    if(!ret)
    {
        return RET_DB_ERROR;
    }
    if(rownum == 1 && colnum == 2)
    {
        key_part_no = res.at(0).at(1);
        status = res.at(0).at(0).toInt();
    }
    return RET_OK;
}
