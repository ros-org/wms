#ifndef INTERFACE_WMS_H
#define INTERFACE_WMS_H
#include <QString>
#include <QMap>
#include "API/api_common.h"

class DB;


class InterfaceWMS
{
public:
    InterfaceWMS();
    //连接数据库
    void db_connect(QString dbName);
    //断开数据库连接
    void db_disconnect();
    //入库
    RET_CODE db_inStock(QString store_no, QString storage_no, int agv_id, QString key_part_no);
    //出库
    RET_CODE db_outStock(QString store_no, QString storage_no, int agv_id);
    //预分配
    RET_CODE db_preAssign(QString store_no, int agv_id, int type, QString &storage_no);
    //出库预分配
    RET_CODE db_out_preAssign(QString store_no, int agv_id, QString &storage_no, QString key_part_no);
    //取消预分配
    RET_CODE db_cancelPreAssign(QString store_no, int agv_id, int type);
    //取消预分配
    RET_CODE db_cancelPreAssign(QString store_no, QString storage_no, QString &material_id);
    //enable auto tray
    RET_CODE db_autoTrayEnable(QString store_no, QString storage_no, bool enable);
    //记日志
    bool db_log(QString store_no, QString storage_no, QString user_id, int type,  QString key_part_no);
    //新增库别
    RET_CODE db_newStore(QString store_no, QString store_name, QString user);
    //新增储位
    RET_CODE db_newStorage(QString store_no, QString storage_no, QString user);
    //更新储位
    RET_CODE db_updateStorage(QString store_no, QString storage_no, QString key_part_no, int status, QString user);
    //更新储位&count信息
    RET_CODE db_updateStorage(QString store_no, QString storage_no, QString key_part_no, int status, QString user, int count);
    //查询地图映射表
    RET_CODE db_queryStorageMap(QMap<QString, STATION_INFO> &mapping_table);
    //查询库存
    RET_CODE db_queryStorage(QString store_no, QVector< QStringList > &res);
    //
    RET_CODE db_queryAutotrayEnable(QString store_no, QVector<bool> &res);
    //
    RET_CODE db_queryTaskCount(int &res);
    //查询库位信息
    RET_CODE db_queryStorageStatus(QString store_no, QString storage_no, QString & key_part_no, int & status);
    //查询可用储位数量
    RET_CODE db_queryAvailable(QString store_no, int status, int& count, int key_part_no);
    //更新任务信息
    RET_CODE db_updateTaskStatus(QString from_store, int status, QString to_store, int store_type);
    //查询目前可以执行的任务
    RET_CODE db_queryTaskAvailable(QVector< QStringList > &res);
    //计数类储位预分配
    RET_CODE db_counter_preAssign(QString store_no, int agv_id, QString &storage_no, QString key_part_no);
    //查询任务信息
    RET_CODE db_queryTaskInfo(QMap<std::pair<QString, QString>, TASK_INFO> & mapping_task);
    //按距离预分配
    RET_CODE db_preAssignByDis(QString store_no, int agv_id, int type, QString current_station_key, QString &storage_no);
private:
    //  声明一个类的指针，不需要知道类的定义
    static DB *m_pDB;
};


#endif // INTERFACE_WMS_H
