/******************************************************************************
** nodemanagerns1.h
**
** Copyright (c) 2006-2016 Unified Automation GmbH. All rights reserved.
**
** Software License Agreement ("SLA") Version 2.5
**
** Unless explicitly acquired and licensed from Licensor under another
** license, the contents of this file are subject to the Software License
** Agreement ("SLA") Version 2.5, or subsequent versions
** as allowed by the SLA, and You may not copy or use this file in either
** source code or executable form, except in compliance with the terms and
** conditions of the SLA.
**
** All software distributed under the SLA is provided strictly on an
** "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
** AND LICENSOR HEREBY DISCLAIMS ALL SUCH WARRANTIES, INCLUDING WITHOUT
** LIMITATION, ANY WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
** PURPOSE, QUIET ENJOYMENT, OR NON-INFRINGEMENT. See the SLA for specific
** language governing rights and limitations under the SLA.
**
** The complete license agreement can be found here:
** http://unifiedautomation.com/License/SLA/2.5/
**
** Project: C++ OPC Server SDK core module
**
** Description: NodeManager for namespace 1.
**
******************************************************************************/
#ifndef __NODEMANAGERNS1_H__
#define __NODEMANAGERNS1_H__

#include "nodemanager.h"
#include "uamutex.h"
#include "uathread.h"
#include "uabasenodes.h"
#include "nodemanagerbase.h"
#include "uaobjecttypes.h"
#include "userdatabase.h"


/** NodeManager implementation for namespace 1.
 *
 *  This NodeManager implements the local server namespace using the ServerUri as namespace URI. This NodeManager
 *  contains all status, diagnostic and configuraiton nodes specific for this OPC UA server instance.
 */
class SERVER_CORE_EXPORT NodeManagerNS1 :
    public NodeManagerBase
{
    UA_DISABLE_COPY(NodeManagerNS1);
public:
    NodeManagerNS1(const UaString& sNamespaceUri, OpcUa_Boolean firesEvents = OpcUa_False, OpcUa_Int32 nHashTableSize = 10007);
    virtual ~NodeManagerNS1();

    //- Interface NodeManager -------------------------------------------------------------
    virtual UaStatus startUp(ServerManager* pServerManager);
    virtual HistoryVariableHandle* getHistoryVariableHandle(Session*, HistoryVariableHandle::ServiceType, OpcUa_NodeId*, UaStatus&) const;
    //- Interface NodeManager -------------------------------------------------------------

    //- Interface NodeManagerUaNode -------------------------------------------------------
    virtual UaStatus   afterStartUp();
    virtual UaStatus   beforeShutDown();
    //- Interface NodeManagerUaNode -------------------------------------------------------

    //- Interface IOManagerUaNode ---------------------------------------------------------
    // Handle reads of status variables
    virtual UaStatus readValues(const UaVariableArray&, UaDataValueArray& arrDataValues);
    //- Interface IOManagerUaNode ---------------------------------------------------------

private:
};

/** Specialized UserData class for UaVariable in namespace 1 where the UserData class provides access to a int counter.
 *
 * This class is used for instances of the UaVariable where polling access through
 * NodeManagerUaNode::readValues is used for variables in namespace 1.
 *
 * This class can be used to provide the value of the variable through the UserData. This option can be used for an int
 * value in memory where the update of the data is not reported through internal events and the data needs to be polled.
 *
 * The access to the int value is not synchronized. Therefore the int value must be incremented and decremented using
 * the atomic functions ua_atomic_increment and ua_atomic_decrement.
 */
class SERVER_CORE_EXPORT UaVariableNs1UserDataGetCounter : public UserDataVariableGetValue
{
    UA_DISABLE_COPY(UaVariableNs1UserDataGetCounter);
    UaVariableNs1UserDataGetCounter();
public:
    UaVariableNs1UserDataGetCounter(int* pData);
    virtual ~UaVariableNs1UserDataGetCounter(){}

    virtual void setInvalid();

    virtual OpcUa_StatusCode getValue(UaVariant& value) const;
    virtual void getDataValue(UaDataValue& dataValue) const;
private:
    int* m_pData;
};


/** Specialized UserData class for UaVariable where the UserData class provides access to an UInt32 value.
 *
 * This class is used for instances of the UaVariable where polling access through
 * NodeManagerUaNode::readValues is used. This feature is supported by the node manager for namespace 1 by default.
 *
 * This class can be used to provide the value of the variable through the UserData. This class can be used for a UInt32
 * value in memory where the update of the data is not reported through internal events and the data needs to be polled.
 *
 * The access to the OpcUa_UInt32 variable memory is synchronized by using the shared mutex passed to this class. Therefore
 * the same mutex must be locked when changing the OpcUa_UInt32 variable in memory.
 */
class SERVER_CORE_EXPORT UserDataGetCounterUInt32 : public UserDataVariableGetValue
{
    UA_DISABLE_COPY(UserDataGetCounterUInt32);
    UserDataGetCounterUInt32();
public:
    UserDataGetCounterUInt32(OpcUa_UInt32* pData, UaMutexRefCounted* pShareMutex);
    virtual ~UserDataGetCounterUInt32();

    virtual void setInvalid();

    virtual OpcUa_StatusCode getValue(UaVariant& value) const;
    virtual void getDataValue(UaDataValue& dataValue) const;
private:
    OpcUa_UInt32*      m_pData;
    UaMutexRefCounted* m_pShareMutex;
};


/** Specialized UserData class for UaVariable where the UserData class provides access to an Byte value.
 *
 * This class is used for instances of the UaVariable where polling access through
 * NodeManagerUaNode::readValues is used. This feature is supported by the node manager for namespace 1 by default.
 *
 * This class can be used to provide the value of the variable through the UserData. This class can be used for a Byte
 * value in memory where the update of the data is not reported through internal events and the data needs to be polled.
 *
 * The access to the OpcUa_Byte variable memory is synchronized by using the shared mutex passed to this class. Therefore
 * the same mutex must be locked when changing the OpcUa_Byte variable in memory.
 */
class SERVER_CORE_EXPORT UserDataGetCounterByte : public UserDataVariableGetValue
{
    UA_DISABLE_COPY(UserDataGetCounterByte);
    UserDataGetCounterByte();
public:
    UserDataGetCounterByte(OpcUa_Byte* pData, UaMutexRefCounted* pShareMutex);
    virtual ~UserDataGetCounterByte();

    virtual void setInvalid();

    virtual OpcUa_StatusCode getValue(UaVariant& value) const;
    virtual void getDataValue(UaDataValue& dataValue) const;
private:
    OpcUa_Byte*      m_pData;
    UaMutexRefCounted* m_pShareMutex;
};


/** Specialized UserData class for UaVariable where the UserData class provides access to an Double value.
 *
 * This class is used for instances of the UaVariable where polling access through
 * NodeManagerUaNode::readValues is used. This feature is supported by the node manager for namespace 1 by default.
 *
 * This class can be used to provide the value of the variable through the UserData. This class can be used for a Double
 * value in memory where the update of the data is not reported through internal events and the data needs to be polled.
 *
 * The access to the OpcUa_Double variable memory is synchronized by using the shared mutex passed to this class. Therefore
 * the same mutex must be locked when changing the OpcUa_Double variable in memory.
 */
class SERVER_CORE_EXPORT UserDataGetCounterDouble : public UserDataVariableGetValue
{
    UA_DISABLE_COPY(UserDataGetCounterDouble);
    UserDataGetCounterDouble();
public:
    UserDataGetCounterDouble(OpcUa_Double* pData, UaMutexRefCounted* pShareMutex);
    virtual ~UserDataGetCounterDouble();

    virtual void setInvalid();

    virtual OpcUa_StatusCode getValue(UaVariant& value) const;
    virtual void getDataValue(UaDataValue& dataValue) const;
private:
    OpcUa_Double*      m_pData;
    UaMutexRefCounted* m_pShareMutex;
};


/** Specialized UserData class for UaVariable where the UserData class provides access to an Boolean value.
 *
 * This class is used for instances of the UaVariable where polling access through
 * NodeManagerUaNode::readValues is used. This feature is supported by the node manager for namespace 1 by default.
 *
 * This class can be used to provide the value of the variable through the UserData. This class can be used for a Boolean
 * value in memory where the update of the data is not reported through internal events and the data needs to be polled.
 *
 * The access to the OpcUa_Boolean variable memory is synchronized by using the shared mutex passed to this class. Therefore
 * the same mutex must be locked when changing the OpcUa_Boolean variable in memory.
 */
class SERVER_CORE_EXPORT UserDataGetCounterBoolean : public UserDataVariableGetValue
{
    UA_DISABLE_COPY(UserDataGetCounterBoolean);
    UserDataGetCounterBoolean();
public:
    UserDataGetCounterBoolean(OpcUa_Boolean* pData, UaMutexRefCounted* pShareMutex);
    virtual ~UserDataGetCounterBoolean();

    virtual void setInvalid();

    virtual OpcUa_StatusCode getValue(UaVariant& value) const;
    virtual void getDataValue(UaDataValue& dataValue) const;
private:
    OpcUa_Boolean*      m_pData;
    UaMutexRefCounted* m_pShareMutex;
};


/** Specialized UserData class for UaVariable where the UserData class provides access to an NodeId value.
 *
 * This class is used for instances of the UaVariable where polling access through
 * NodeManagerUaNode::readValues is used. This feature is supported by the node manager for namespace 1 by default.
 *
 * This class can be used to provide the value of the variable through the UserData. This class can be used for a NodeId
 * value in memory where the update of the data is not reported through internal events and the data needs to be polled.
 *
 * The access to the OpcUa_NodeId variable memory is synchronized by using the shared mutex passed to this class. Therefore
 * the same mutex must be locked when changing the OpcUa_NodeId variable in memory.
 */
class SERVER_CORE_EXPORT UserDataGetCounterNodeId : public UserDataVariableGetValue
{
    UA_DISABLE_COPY(UserDataGetCounterNodeId);
    UserDataGetCounterNodeId();
public:
    UserDataGetCounterNodeId(OpcUa_NodeId* pData, UaMutexRefCounted* pShareMutex);
    virtual ~UserDataGetCounterNodeId();

    virtual void setInvalid();

    virtual OpcUa_StatusCode getValue(UaVariant& value) const;
    virtual void getDataValue(UaDataValue& dataValue) const;
private:
    OpcUa_NodeId*      m_pData;
    UaMutexRefCounted* m_pShareMutex;
};


/** Specialized UserData class for UaVariable where the UserData class provides access to an String value.
*
* This class is used for instances of the UaVariable where polling access through
* NodeManagerUaNode::readValues is used. This feature is supported by the node manager for namespace 1 by default.
*
* This class can be used to provide the value of the variable through the UserData. This class can be used for a String
* value in memory where the update of the data is not reported through internal events and the data needs to be polled.
*
* The access to the OpcUa_String variable memory is synchronized by using the shared mutex passed to this class. Therefore
* the same mutex must be locked when changing the OpcUa_String variable in memory.
*/
class SERVER_CORE_EXPORT UserDataGetString : public UserDataVariableGetValue
{
    UA_DISABLE_COPY(UserDataGetString);
    UserDataGetString();
public:
    UserDataGetString(OpcUa_String* pData, UaMutexRefCounted* pShareMutex);
    virtual ~UserDataGetString();

    virtual void setInvalid();

    virtual OpcUa_StatusCode getValue(UaVariant& value) const;
    virtual void getDataValue(UaDataValue& dataValue) const;
private:
    OpcUa_String*      m_pData;
    UaMutexRefCounted* m_pShareMutex;
};


/** Specialized UserData class for UaVariable where the UserData class provides access to an DateTime value.
*
* This class is used for instances of the UaVariable where polling access through
* NodeManagerUaNode::readValues is used. This feature is supported by the node manager for namespace 1 by default.
*
* This class can be used to provide the value of the variable through the UserData. This class can be used for a DateTime
* value in memory where the update of the data is not reported through internal events and the data needs to be polled.
*
* The access to the OpcUa_DateTime variable memory is synchronized by using the shared mutex passed to this class. Therefore
* the same mutex must be locked when changing the OpcUa_DateTime variable in memory.
*/
class SERVER_CORE_EXPORT UserDataGetDateTime : public UserDataVariableGetValue
{
    UA_DISABLE_COPY(UserDataGetDateTime);
    UserDataGetDateTime();
public:
    UserDataGetDateTime(OpcUa_DateTime* pData, UaMutexRefCounted* pShareMutex);
    virtual ~UserDataGetDateTime();

    virtual void setInvalid();

    virtual OpcUa_StatusCode getValue(UaVariant& value) const;
    virtual void getDataValue(UaDataValue& dataValue) const;
private:
    OpcUa_DateTime*    m_pData;
    UaMutexRefCounted* m_pShareMutex;
};

#endif // #ifndef __NODEMANAGERNS1_H__
