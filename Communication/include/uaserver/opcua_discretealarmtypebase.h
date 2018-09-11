/******************************************************************************
** opcua_discretealarmtypebase.h
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
** Project: C++ OPC Server SDK information model for namespace http://opcfoundation.org/UA/
**
** Description: OPC Unified Architecture Software Development Kit.
**
******************************************************************************/

#ifndef __OPCUA_DISCRETEALARMTYPEBASE_H__
#define __OPCUA_DISCRETEALARMTYPEBASE_H__

#include "opcua_alarmconditiontype.h"
#include "basenodes.h"
#include "opcua_identifiers.h"
#include "opcua_propertytype.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class DiscreteAlarmTypeBase;

/** Generated event data class for a DiscreteAlarmType.
 *
 *  This class contains the auto generated code for the object type DiscreteAlarmType
 *  providing UaEventData interface for the access to event data containing the current state of the
 *  condition for events sent to the client. The class is used for condition events if the condition has
 *  no nodes in the address space or for condition branches created as snapshot of the main branch.

 *  Used to classify Types into Alarm Conditions where the input for the Alarm may
 *  take on only a certain number of possible values (e.g. true/false,
 *  running/stopped/terminating).
 *
 *  See also \ref Doc_OpcUa_DiscreteAlarmType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT DiscreteAlarmTypeData:
    public OpcUa::AlarmConditionTypeData
{
    UA_DISABLE_COPY(DiscreteAlarmTypeData);
protected:
    virtual ~DiscreteAlarmTypeData();
public:
    DiscreteAlarmTypeData();
    void initializeAsBranch(DiscreteAlarmTypeBase* pCondition);
    void initializeAsBranch(DiscreteAlarmTypeData* pConditionData);
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);


private:
    void initialize();

private:
    UaObjectPointerArray<UaVariant> m_FieldValues;
};


/** Generated base class for a DiscreteAlarmType.
 *
 *  This class contains the auto generated code for the object type DiscreteAlarmType
 *  representing an OPC UA condition type. This class is used to create the condition type and to
 *  create and represent the condition object in the server address space. It provides also the UaEventData
 *  interface for the access to event data containing the current state of the condition for events sent to
 *  the client.
 *
 *
 *  Used to classify Types into Alarm Conditions where the input for the Alarm may
 *  take on only a certain number of possible values (e.g. true/false,
 *  running/stopped/terminating).
 *
 *  See also \ref Doc_OpcUa_DiscreteAlarmType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT DiscreteAlarmTypeBase:
    public OpcUa::AlarmConditionType
{
    friend class DiscreteAlarmTypeData;
    UA_DISABLE_COPY(DiscreteAlarmTypeBase);
protected:
    // destruction
    virtual ~DiscreteAlarmTypeBase();
public:
    // construction
    DiscreteAlarmTypeBase(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    DiscreteAlarmTypeBase(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    DiscreteAlarmTypeBase(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    static void createTypes();
    static void clearStaticMembers();
    virtual UaNodeId typeDefinitionId() const;
    static void registerEventFields();
    static OpcUa_UInt32 registerOptionalEventFields(const UaString& fieldName);
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    void clearFieldData();
    UaNodeId createBranch();


    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(DiscreteAlarmTypeBase *pInstance);

    virtual UaStatus triggerEvent(
        const UaDateTime&   time,
        const UaDateTime&   receiveTime,
        const UaByteString& eventId);

    virtual void getDiscreteAlarmTypeOptionalFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

protected:


private:
    void initialize();
    void createChildren();

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_DiscreteAlarmTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUADISCRETEALARMTYPEBASE_H__

