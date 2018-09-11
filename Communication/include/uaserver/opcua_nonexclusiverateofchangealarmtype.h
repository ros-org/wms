/******************************************************************************
** opcua_nonexclusiverateofchangealarmtype.h
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

#ifndef __OPCUA_NONEXCLUSIVERATEOFCHANGEALARMTYPE_H__
#define __OPCUA_NONEXCLUSIVERATEOFCHANGEALARMTYPE_H__

#include "opcua_nonexclusivelimitalarmtype.h"
#include "opcua_identifiers.h"
#include "basenodes.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class NonExclusiveRateOfChangeAlarmType;

/** Generated event data class for a NonExclusiveRateOfChangeAlarmType.
 *
 *  This class contains the auto generated code for the object type NonExclusiveRateOfChangeAlarmType
 *  providing UaEventData interface for the access to event data containing the current state of the
 *  condition for events sent to the client. The class is used for condition events if the condition has
 *  no nodes in the address space or for condition branches created as snapshot of the main branch.

 *  A special level Alarm utilized with one or more non-exclusive states.
 *
 *  If for example both the High and HighHigh states need to be maintained as
 *  active at the same time this AlarmType should be used.
 *
 *  A Rate of Change Alarm is commonly used to report an unusual change or lack of
 *  change in a measured value related to the speed at which the value has changed.
 *  The Rate of Change Alarm becomes active when the rate at which the value
 *  changes exceeds or drops below a defined limit.
 *
 *  A Rate of Change is measured in some time unit, such as seconds or minutes and
 *  some unit of measure such as percent or meter. For example a tank may have a
 *  High limit for the Rate of Change of its level (measured in meters) which would
 *  be 4 meters per minute. If the tank level changes at a rate that is greater
 *  than 4 meters per minute then the High sub state is entered.
 *
 *  The NonExclusiveRateOfChangeAlarmType is based on the
 *  NonExclusiveLimitAlarmType.
 *
 *  See also \ref Doc_OpcUa_NonExclusiveRateOfChangeAlarmType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT NonExclusiveRateOfChangeAlarmTypeData:
    public OpcUa::NonExclusiveLimitAlarmTypeData
{
    UA_DISABLE_COPY(NonExclusiveRateOfChangeAlarmTypeData);
protected:
    virtual ~NonExclusiveRateOfChangeAlarmTypeData();
public:
    NonExclusiveRateOfChangeAlarmTypeData();
    void initializeAsBranch(NonExclusiveRateOfChangeAlarmType* pCondition);
    void initializeAsBranch(NonExclusiveRateOfChangeAlarmTypeData* pConditionData);
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

private:
    void initialize();

private:
    UaObjectPointerArray<UaVariant> m_FieldValues;
};


/** @brief Class implementing the UaObject interface for the NonExclusiveRateOfChangeAlarmType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  A special level Alarm utilized with one or more non-exclusive states.
 *
 *  If for example both the High and HighHigh states need to be maintained as
 *  active at the same time this AlarmType should be used.
 *
 *  A Rate of Change Alarm is commonly used to report an unusual change or lack of
 *  change in a measured value related to the speed at which the value has changed.
 *  The Rate of Change Alarm becomes active when the rate at which the value
 *  changes exceeds or drops below a defined limit.
 *
 *  A Rate of Change is measured in some time unit, such as seconds or minutes and
 *  some unit of measure such as percent or meter. For example a tank may have a
 *  High limit for the Rate of Change of its level (measured in meters) which would
 *  be 4 meters per minute. If the tank level changes at a rate that is greater
 *  than 4 meters per minute then the High sub state is entered.
 *
 *  The NonExclusiveRateOfChangeAlarmType is based on the
 *  NonExclusiveLimitAlarmType.
 *
 *  See also \ref Doc_OpcUa_NonExclusiveRateOfChangeAlarmType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT NonExclusiveRateOfChangeAlarmType:
    public OpcUa::NonExclusiveLimitAlarmType
{
    friend class NonExclusiveRateOfChangeAlarmTypeData;
    UA_DISABLE_COPY(NonExclusiveRateOfChangeAlarmType);
protected:
    // destruction
    virtual ~NonExclusiveRateOfChangeAlarmType();
public:
    // construction
    NonExclusiveRateOfChangeAlarmType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    NonExclusiveRateOfChangeAlarmType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    NonExclusiveRateOfChangeAlarmType(
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
    void useAccessInfoFromInstance(NonExclusiveRateOfChangeAlarmType *pInstance);

    virtual UaStatus triggerEvent(
        const UaDateTime&   time,
        const UaDateTime&   receiveTime,
        const UaByteString& eventId);

    virtual void getNonExclusiveRateOfChangeAlarmTypeOptionalFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

private:
    void initialize();
    void createChildren();

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_NonExclusiveRateOfChangeAlarmTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUANONEXCLUSIVERATEOFCHANGEALARMTYPE_H__

