/******************************************************************************
** opcua_exclusivelevelalarmtype.h
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

#ifndef __OPCUA_EXCLUSIVELEVELALARMTYPE_H__
#define __OPCUA_EXCLUSIVELEVELALARMTYPE_H__

#include "opcua_exclusivelimitalarmtype.h"
#include "opcua_identifiers.h"
#include "basenodes.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class ExclusiveLevelAlarmType;


/** Generated event data class for a ExclusiveLevelAlarmType.
 *
 *  This class contains the auto generated code for the object type ExclusiveLevelAlarmType
 *  providing UaEventData interface for the access to event data containing the current state of the
 *  condition for events sent to the client. The class is used for condition events if the condition has
 *  no nodes in the address space or for condition branches created as snapshot of the main branch.

 *  The ExclusiveLevelAlarmType is a special level Alarm utilized with multiple
 *  mutually exclusive limits.
 *
 *  A level Alarm is commonly used to report when a limit is exceeded. It typically
 *  relates to an instrument – e.g. a temperature meter. The level Alarm becomes
 *  active when the observed value is above a high limit or below a low limit.
 *
 *  See also \ref Doc_OpcUa_ExclusiveLevelAlarmType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT ExclusiveLevelAlarmTypeData:
    public OpcUa::ExclusiveLimitAlarmTypeData
{
    UA_DISABLE_COPY(ExclusiveLevelAlarmTypeData);
protected:
    virtual ~ExclusiveLevelAlarmTypeData();
public:
    ExclusiveLevelAlarmTypeData();
    void initializeAsBranch(ExclusiveLevelAlarmType* pCondition);
    void initializeAsBranch(ExclusiveLevelAlarmTypeData* pConditionData);
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

private:
    void initialize();

private:
    UaObjectPointerArray<UaVariant> m_FieldValues;
};


/** @brief Class implementing the UaObject interface for the ExclusiveLevelAlarmType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  The ExclusiveLevelAlarmType is a special level Alarm utilized with multiple
 *  mutually exclusive limits.
 *
 *  A level Alarm is commonly used to report when a limit is exceeded. It typically
 *  relates to an instrument – e.g. a temperature meter. The level Alarm becomes
 *  active when the observed value is above a high limit or below a low limit.
 *
 *  See also \ref Doc_OpcUa_ExclusiveLevelAlarmType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT ExclusiveLevelAlarmType:
    public OpcUa::ExclusiveLimitAlarmType
{
    friend class ExclusiveLevelAlarmTypeData;
    UA_DISABLE_COPY(ExclusiveLevelAlarmType);
protected:
    // destruction
    virtual ~ExclusiveLevelAlarmType();
public:
    // construction
    ExclusiveLevelAlarmType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    ExclusiveLevelAlarmType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    ExclusiveLevelAlarmType(
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
    void useAccessInfoFromInstance(ExclusiveLevelAlarmType *pInstance);

    virtual UaStatus triggerEvent(
        const UaDateTime&   time,
        const UaDateTime&   receiveTime,
        const UaByteString& eventId);

    virtual void getExclusiveLevelAlarmTypeOptionalFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

private:
    void initialize();
    void createChildren();

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_ExclusiveLevelAlarmTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUAEXCLUSIVELEVELALARMTYPE_H__

