#ifndef OPCUA_H
#define OPCUA_H
#include <QThread>
#include <iostream>
#include <sstream>
#include <stdio.h>
/* base */
#include <opcua_platformdefs.h>
#include <uaplatformlayer.h>
#include <opcua_statuscodes.h>
#include <opcua_errorhandling.h>
#include <uaclientsdk.h>

/* core */
#include <opcua_memory.h>
#include <opcua_string.h>
#include <opcua_guid.h>

/* stack */
#include <opcua_encoder.h>
#include <opcua_decoder.h>

/* types */
#include <opcua_identifiers.h>
#include <uasession.h>
#include "API/api_common.h"


#include <QMutex>
using namespace std;

using namespace UaClientSdk;
class opcnode
{
  public:
    int index;
    std::string nodeid;
    std::string storage_no;
    int value;
    bool updateFlag;
};


class opcua: public QThread
{
    Q_OBJECT

public:
    UaSession *g_pUaSession = NULL;
    opcua(UaString serverip, int serverport, UaString _username, UaString _password, int _id, QString _store_no, QMap<QString, STATION_INFO> mapping_table, QObject *parent = 0);
    void run();
    bool readNode(int index);
    bool writeNode(opcnode &writenode);
    void registerNodes(vector<opcnode> nodes);
public slots:
    void slot_writeOpcMsg(QString storage_no, bool);
signals:
    void sig_readOpcMsg(QString, int, QString, int);
    void sig_readyOpcMsg(QString, bool, QString, int);
private:
    UaString ip;
    int port;
    int id;
    UaString username;
    UaString password;
    vector<opcnode> vec_readnodes;
    vector<opcnode> vec_writenodes;
    vector<opcnode> vec_readynodes;
    QMutex writenode_mutex;
};

#endif // OPCUA_H
