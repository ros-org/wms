/******************************************************************************
** opcua_systemoffnormalalarmtype.h
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

#ifndef __OPCUA_SYSTEMOFFNORMALALARMTYPE_H__
#define __OPCUA_SYSTEMOFFNORMALALARMTYPE_H__

#include "opcua_offnormalalarmtype.h"
#include "opcua_identifiers.h"
#include "basenodes.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class SystemOffNormalAlarmType;

/** Generated event data class for a SystemOffNormalAlarmType.
 *
 *  This class contains the auto generated code for the object type SystemOffNormalAlarmType
 *  providing UaEventData interface for the access to event data containing the current state of the
 *  condition for events sent to the client. The class is used for condition events if the condition has
 *  no nodes in the address space or for condition branches created as snapshot of the main branch.

 *  Used by a Server to indicate that an underlying system that is providing Alarm
 *  information is having a communication problem and that the Server may have
 *  invalid or incomplete Condition state in the Subscription.
 *
 *  See also \ref Doc_OpcUa_SystemOffNormalAlarmType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT SystemOffNormalAlarmTypeData:
    public OpcUa::OffNormalAlarmTypeData
{
    UA_DISABLE_COPY(SystemOffNormalAlarmTypeData);
protected:
    virtual ~SystemOffNormalAlarmTypeData();
public:
    SystemOffNormalAlarmTypeData();
    void initializeAsBranch(SystemOffNormalAlarmType* pCondition);
    void initializeAsBranch(SystemOffNormalAlarmTypeData* pConditionData);
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

private:
    void initialize();

private:
    UaObjectPointerArray<UaVariant> m_FieldValues;
};


/** @brief Class implementing the UaObject interface for the SystemOffNormalAlarmType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  Used by a Server to indicate that an underlying system that is providing Alarm
 *  information is having a communication problem and that the Server may have
 *  invalid or incomplete Condition state in the Subscription.
 *
 *  See also \ref Doc_OpcUa_SystemOffNormalAlarmType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT SystemOffNormalAlarmType:
    public OpcUa::OffNormalAlarmType
{
    friend class SystemOffNormalAlarmTypeData;
    UA_DISABLE_COPY(SystemOffNormalAlarmType);
protected:
    // destruction
    virtual ~SystemOffNormalAlarmType();
public:
    // construction
    SystemOffNormalAlarmType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    SystemOffNormalAlarmType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    SystemOffNormalAlarmType(
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
    void useAccessInfoFromInstance(SystemOffNormalAlarmType *pInstance);

    virtual UaStatus triggerEvent(
        const UaDateTime&   time,
        const UaDateTime&   receiveTime,
        const UaByteString& eventId);

    virtual void getSystemOffNormalAlarmTypeOptionalFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

private:
    void initialize();
    void createChildren();

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_SystemOffNormalAlarmTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUASYSTEMOFFNORMALALARMTYPE_H__

