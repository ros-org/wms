#ifndef DB_H
#define DB_H
#include <QSqlDatabase>
#include <QSqlError>
class DB
{
public:
    DB();
    //数据库连接
    bool DBconnect(QString dbName);
    //断开数据库连接
    bool DBdisconnect();
    //数据库插入
    bool DBInsert(QString insert_sql, QString &err_msg);
    //数据库更新
    bool DBUpdate(QString update_sql, QString &err_msg);
    //数据库删除
    bool DBDelete(QString delete_sql, QString &err_msg);
    //数据库查询
    bool DBQuery(QString query_sql, int & rownum, int & colnum, QVector<QVector<QString> >& res, QString &err_msg);
private:
    QSqlDatabase db;
    bool conSucc;
};

#endif // DB_H
