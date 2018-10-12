#include "opcua.h"
#include <QDebug>
opcua::opcua(UaString serverip, int serverport, UaString _username, UaString _password, int _id, QString _store_no, QMap<QString, STATION_INFO> _mapping_table, QObject *parent)
    : QThread(parent)
{
    ip = serverip;
    port = serverport;
    id = _id;
    username = _username;
    password = _password;

    //初始状态为未更新，已执行任务数为数据库中保存的
#ifndef TEST
    ostringstream ssa_start, ssa_end, ssa_ready, ssa;
    ssa_start<<"::AsGlobalPV:AGV_A"<<_id<<"_AGV";
    opcnode node;
    node.index = 6;
    node.nodeid = ssa_start.str();
    node.updateFlag = false;
    ssa<<"A"<<_id;
    node.storage_no = ssa.str();
    node.value = -2;
    //    QString key = _store_no;
    //    key.append("_").append(QString::fromStdString(ssa.str()));
    //    node.value = _mapping_table.value(key).times;
    vec_writenodes.push_back(node);

    ssa_end<<"::AsGlobalPV:AGV_A"<<_id<<"_ROBOT";
    node.nodeid = ssa_end.str();
    node.value = -2;
    node.updateFlag = false;
    node.storage_no = ssa.str();
    vec_readnodes.push_back(node);

    //    ssa_ready<<"::AsGlobalPV:AGV_A"<<_id<<"_ready";
    //    node.nodeid = ssa_ready.str();
    //    node.value = 0;
    //    node.updateFlag = false;
    //    node.storage_no = ssa.str();
    //    // vec_readynodes.push_back(node);

    ostringstream ssb_start, ssb_end, ssb_ready, ssb;
    ssb_start<<"::AsGlobalPV:AGV_B"<<_id<<"_AGV";
    node.nodeid = ssb_start.str();
    node.updateFlag = false;
    ssb<<"B"<<_id;
    node.storage_no = ssb.str();
    node.value = -2;
    //    key = _store_no;
    //    key.append("_").append(QString::fromStdString(ssb.str()));
    //    node.value = _mapping_table.value(key).times;
    vec_writenodes.push_back(node);

    ssb_end<<"::AsGlobalPV:AGV_B"<<_id<<"_ROBOT";
    node.nodeid = ssb_end.str();
    node.value = -2;
    node.updateFlag = false;
    node.storage_no = ssb.str();
    vec_readnodes.push_back(node);

    //    ssb_ready<<"::AsGlobalPV:AGV_B"<<_id<<"_ready";
    //    node.nodeid = ssb_ready.str();
    //    node.value = 0;
    //    node.updateFlag = false;
    //    node.storage_no = ssb.str();
    //    //vec_readynodes.push_back(node);
#else
    opcnode node;
    ostringstream ssa_test;
    ssa_test<<"Demo.AccessRights.Access_All.All_RW";
    node.index = 2;
    node.nodeid = ssa_test.str();
    node.value = 1;
    node.storage_no = "A2";
    node.updateFlag = false;
    vec_readnodes.push_back(node);
    node.value = 0;
    vec_writenodes.push_back(node);
#endif
}

bool opcua::readNode(int index){
    UaString idstring(vec_readnodes[index].nodeid.c_str());
    UaNodeId node(idstring,vec_readnodes[index].index);

    OpcUa_UInt32      count = 1;
    UaReadValueIds    nodesToRead;
    UaDataValues      values;
    ServiceSettings   serviceSettings;
    UaDiagnosticInfos diagnosticInfos;

    nodesToRead.create(count);

    for (int i=0; i<count; i++ )
    {
        node.copyTo(&nodesToRead[i].NodeId);
        nodesToRead[i].AttributeId = OpcUa_Attributes_Value;
    }

    UaStatus status;
    status = g_pUaSession->read(
                serviceSettings,                // Use default settings
                0,                              // Max age
                OpcUa_TimestampsToReturn_Both,  // Time stamps to return
                nodesToRead,                    // Array of nodes to read
                values,                         // Returns an array of values
                diagnosticInfos);               // Returns an array of diagnostic info
    if ( status.isBad() )
    {
        qDebug()<<"** Error: UaSession::read failed [ret="<<status.toString().toUtf8()<<"] **\n";
        return false;
    }else{
        //qDebug()<<"** UaSession::read result **************************************\n";
        for (int i=0; i<count; i++ )
        {
            UaNodeId node(nodesToRead[i].NodeId);
            if ( OpcUa_IsGood(values[i].StatusCode) )
            {
                UaVariant tempValue = values[i].Value;
                if (tempValue.type() == OpcUaType_ExtensionObject)
                {
                    qDebug()<<"  Variable "<<node.toString().toUtf8()<<" is an ExtensionObject\n";
                    //printExtensionObjects(tempValue, UaString("Variable %1").arg(node.toString()));
                }
                else
                {
                    OpcUa_Int16 status;
                    tempValue.toInt16(status);
                    int readvalue = status;

                    if(readvalue != vec_readnodes[index].value){
                        //diff value from last time
                        if(readvalue != vec_readnodes[index].value+1){
                            //init read or clear to zero
                            vec_readnodes[index].value = readvalue;
                            vec_readnodes[index].updateFlag = false;
                            writenode_mutex.lock();
                            vec_writenodes[index].value = readvalue;
                            vec_writenodes[index].updateFlag = true;
                            writenode_mutex.unlock();
                        }else{
                            //readvalue == vec_readnodes[index].value +1
                            vec_readnodes[index].value = readvalue;
                            vec_readnodes[index].updateFlag = true;
                            writenode_mutex.lock();
                            vec_writenodes[index].value = readvalue;
                            vec_writenodes[index].updateFlag = false;
                            writenode_mutex.unlock();
                        }
                        qDebug()<<"  Variable "<<node.toString().toUtf8()<<" value = "<<tempValue.toString().toUtf8();
                    }


                }
            }
            else
            {
                //qDebug()<<"  Variable "<<node.toString().toUtf8()<<" failed with error "<<UaStatus(values[i].StatusCode).toString().toUtf8();
            }
        }
        //qDebug()<<"****************************************************************\n";
    }

    return true;
}

void opcua::slot_writeOpcMsg(QString storage_no, bool flag)
{
    if(!flag)
        return;
    for(int i = 0; i <vec_writenodes.size(); i++)
    {
        opcnode node = vec_writenodes.at(i);
        if(node.storage_no == storage_no.toStdString())
        {
            writenode_mutex.lock();
            node.updateFlag = true;
            vec_writenodes.at(i) = node;
            writenode_mutex.unlock();
        }
    }
}

/*============================================================================
 * registerNodes - RegisterNodes for frequently use in read or write
 *===========================================================================*/
void  opcua::registerNodes(vector<opcnode> nodes)
{
    printf("\n\n****************************************************************\n");
    printf("** Try to call registerNodes for configured node ids\n");
    if ( g_pUaSession == NULL )
    {
        printf("** Error: Server not connected\n");
        printf("****************************************************************\n");
        return;
    }

    OpcUa_UInt32      i;
    OpcUa_UInt32      count;
    UaStatus          status;
    UaNodeIdArray     nodesToRegister;
    UaNodeIdArray     registeredNodes;
    ServiceSettings   serviceSettings;

    // Initialize IN parameter nodesToRegister
    count = nodes.size();
    nodesToRegister.create(count);
    for ( i=0; i<count; i++ )
    {
        UaNodeId node(nodes[i].nodeid.c_str(), nodes[i].index);

        node.copyTo(&nodesToRegister[i]);
    }

    /*********************************************************************
     Call registerNodes service
    **********************************************************************/
    status = g_pUaSession->registerNodes(
                serviceSettings,     // Use default settings
                nodesToRegister,     // Array of nodeIds to register
                registeredNodes);    // Returns an array of registered nodeIds
    /*********************************************************************/
    if ( status.isBad() )
    {
        printf("** Error: UaSession::registerNodes failed [ret=%s] **\n", status.toString().toUtf8());
    }
    else
    {
        printf("** UaSession::registerNodes succeeded\n");
        for ( i=0; i<count; i++ )
        {
            // Copy back returned NodeIds
            //g_VariableNodeIds[i] = registeredNodes[i];
        }
        printf("****************************************************************\n");
    }
}

bool opcua::writeNode(opcnode &writenode){

    UaString idstring(writenode.nodeid.c_str());
    UaNodeId node(idstring, writenode.index);

    OpcUa_UInt32      count = 1;
    UaStatus          status;
    UaVariant         tempValue;
    UaWriteValues     nodesToWrite;
    UaStatusCodeArray results;
    UaDiagnosticInfos diagnosticInfos;
    ServiceSettings   serviceSettings;

    nodesToWrite.create(count);
    for (int i=0; i<count; i++ )
    {
        node.copyTo(&nodesToWrite[i].NodeId);
        nodesToWrite[i].AttributeId = OpcUa_Attributes_Value;

#ifndef TEST
        std::stringstream ss;
        int num;
        ss<<writenode.value;
        ss>>num;
        tempValue.setInt16(num);
#else
        std::stringstream ss;
        double num;
        ss<<writenode.value;
        ss>>num;
        tempValue.setDouble(num);
#endif
        tempValue.copyTo(&nodesToWrite[i].Value.Value);
    }

    /*********************************************************************
         Call write service
        **********************************************************************/
    status = g_pUaSession->write(
                serviceSettings,                // Use default settings
                nodesToWrite,                   // Array of nodes to write
                results,                        // Returns an array of status codes
                diagnosticInfos);               // Returns an array of diagnostic info
    /*********************************************************************/
    if ( status.isBad() )
    {
        qDebug()<<"** Error: UaSession::write failed [ret="<<status.toString().toUtf8()<<"] **\n";
    }
    else
    {
        qDebug()<<"** UaSession::write result **************************************\n";
        for (int i=0; i<count; i++ )
        {
            UaNodeId node(nodesToWrite[i].NodeId);
            if ( OpcUa_IsGood(results[i]) )
            {
                qDebug()<<"** Variable "<<node.toString().toUtf8()<<" value = "<<tempValue.toString().toUtf8()<<" succeeded!\n";
            }
            else
            {
                qDebug()<<"** Variable "<<node.toString().toUtf8()<<" failed with error "<<UaStatus(results[i]).toString().toUtf8();
            }
        }
        qDebug()<<"****************************************************************\n";
    }

    return true;
}
void opcua::run()
{
    while(true)
    {
        int ret = UaPlatformLayer::init();
        if(ret !=0){
            std::cerr<<"!!!!!!!!!!UaPlatformLayer init fail!!!!!!!!"<<std::endl;
            //严重错误，直接退出
            return ;
        }

        SessionSecurityInfo sessionSecurityInfo;
        sessionSecurityInfo.setUserPasswordUserIdentity(username, password);

        UaStatus status;
        SessionConnectInfo sessionConnectInfo;
        sessionConnectInfo.sApplicationName = "";
        sessionConnectInfo.sApplicationUri  = "";
        sessionConnectInfo.sProductUri      = "";
        sessionConnectInfo.sSessionName     = UaString("Client_Cpp_SDK@%1").arg("123");
        sessionConnectInfo.bAutomaticReconnect = OpcUa_True;

        UaString serveraddress=UaString("opc.tcp://%1:%2").arg(ip).arg(port);

        g_pUaSession = new UaSession();
        int kk = 0;
        do
        {
            status = g_pUaSession->connect(
                        serveraddress,
                        sessionConnectInfo,
                        sessionSecurityInfo,
                        NULL);        // Callback interface
            qDebug()<<"try to connect...";
            sleep(5);
        }while (!status.isGood() && ++kk<4);

        //多次重连还是失败的话，重新初始化
        if(!status.isGood())continue;

        qDebug()<<"connect is ok";

        registerNodes(vec_readnodes);
        registerNodes(vec_writenodes);

        while(true)
        {
            int ret = 0;
            for(int i = 0; i < vec_readnodes.size(); i++)
            {
                ret += readNode(i);
                opcnode node = vec_readnodes.at(i);
                if(node.updateFlag)
                {
                    //TODO 若机械臂码完一盘货，则通知wms更新库存
                    qDebug()<<"**  "<<QString::fromStdString(node.storage_no)<<" is full, update wms!\n";
                    emit sig_readOpcMsg(QString::fromStdString(node.storage_no), node.value, QString::fromStdString(ip.toUtf8()), port);
                    vec_readnodes.at(i).updateFlag = false;
                }
            }

            if(ret == 0)
            {
                //可能是断线 重新连接
                if ( g_pUaSession )
                {
                    delete g_pUaSession;
                    g_pUaSession = NULL;
                    qDebug() <<"** Error: UaSession::disconnect\n";
                }
                break;
            }
            writenode_mutex.lock();

            for(unsigned int i = 0; i < vec_writenodes.size(); i++)
            {
                opcnode node = vec_writenodes.at(i);
                if(node.updateFlag)
                {
                    sleep(15);
                    //TODO 更新是否有托盘
                    writeNode(node);
                    node.updateFlag = false;
                    vec_writenodes.at(i) = node;
                }
            }
            writenode_mutex.unlock();

            sleep(1);//每隔1秒进行一次查询和写入
        }

        sleep(3);
    }

    return;
}
