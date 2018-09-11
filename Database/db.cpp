#include "db.h"
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>

DB::DB()
{
    conSucc = false;
}

/********************************************************************************************************
 * Function Name :                  DBconnect
 * Function Main Usage:             数据库连接
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/
bool DB::DBconnect(QString dbName)
{
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        //QSQLITE
        db = QSqlDatabase::addDatabase("QSQLITE");
        //db = QSqlDatabase::addDatabase("SQLITECIPHER");
    }
    db.setDatabaseName(dbName);

    if (!db.open()) {
        qDebug() << "Database Error!"<< db.lastError().driverText();
        conSucc = false;
        return false;
    }
    else
    {
        qDebug() << "Open Database successful";
        conSucc = true;
    }
    return true;
}

/********************************************************************************************************
 * Function Name :                  DBdisconnect
 * Function Main Usage:             数据库断开连接
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/
bool DB::DBdisconnect()
{
    if(conSucc)
    {
        db.close();
        conSucc = false;
    }
    else
    {
        qDebug() << "Database is already closed";
    }
    return true;
}

/********************************************************************************************************
 * Function Name :                  DBInsert
 * Function Main Usage:             单条插入数据库记录
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/
bool DB::DBInsert(QString insert_sql, QString &err_msg)
{
    err_msg = "insert ok";
    if(conSucc)
    {
        QSqlQuery query;
        if (!query.exec(insert_sql)) {
            err_msg = query.lastError().text();
            qDebug() << "DB-INSERT:"<<insert_sql<<" Failed!"<<err_msg;
            return false;
        }
        query.finish();
        qDebug() << "DB-INSERT:"<<insert_sql<<" Success!";
        return true;
    }
    else
    {
        err_msg = "database is not open";
        qDebug() << err_msg;
        return false;
    }
}

/********************************************************************************************************
 * Function Name :                  DBUpdate
 * Function Main Usage:             更新数据
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/
bool DB::DBUpdate(QString update_sql, QString &err_msg)
{
    err_msg = "update ok";

    if(conSucc)
    {
        QSqlQuery query;
        if (!query.exec(update_sql)) {
            err_msg = query.lastError().text();
            qDebug() << "DB-UPDATE:"<<update_sql<<" Failed!"<<err_msg;
            return false;
        }
        query.finish();
        if(query.numRowsAffected() != -1)
        qDebug() << "DB-UPDATE:"<<update_sql<<" Success!";
        return true;
    }
    else
    {
        err_msg = "database is not open";
        qDebug() << err_msg;
        return false;
    }
}

/********************************************************************************************************
 * Function Name :                  DBDelete
 * Function Main Usage:             删除数据
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/
bool DB::DBDelete(QString delete_sql, QString &err_msg)
{
    err_msg = "delete ok";

    if(conSucc)
    {
        QSqlQuery query;
        if (!query.exec(delete_sql)) {
            err_msg = query.lastError().text();
            qDebug() << "DB-DELETE:"<<delete_sql<<" Failed!"<<err_msg;
            return false;
        }
        query.finish();
        qDebug() << "DB-DELETE:"<<delete_sql<<" Success!";
        return true;
    }
    else
    {
        err_msg = "database is not open";
        qDebug() << err_msg;
        return false;
    }
}

/********************************************************************************************************
 * Function Name :                  DBQuery
 * Function Main Usage:             数据查询
 *
 * Author/Date:
 * Modefy/Date:
********************************************************************************************************/
bool DB::DBQuery(QString query_sql, int & rownum, int & colnum, QVector< QVector<QString> >& res, QString &err_msg)
{
    rownum = 0;
    colnum = 0;

    if(conSucc)
    {
        QSqlQuery query;
        if (!query.exec(query_sql)) {
            err_msg = query.lastError().text();
            qDebug() << "DB-QUERY:"<<query_sql<<" Failed!"<<err_msg;
            return false;
        }
        while (query.next()) {
            if(rownum == 0)
            {
                QSqlRecord record = query.record();
                colnum = record.count();
            }
            QVector<QString> res_line;
            for(int i = 0; i < colnum; i++)
            {
                res_line.push_back(query.value(i).toString());
            }
            res.push_back(res_line);
            rownum++;
        }
//        qDebug() << "DB-QUERY:"<<query_sql<<" Success!";
        query.clear();

        return true;
    }
    else
    {
        err_msg = "database is not open";
        qDebug() << err_msg;
        return false;
    }
}
