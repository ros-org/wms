/******************************************************************************
** opcua_exclusivedeviationalarmtype.h
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

#ifndef __OPCUA_EXCLUSIVEDEVIATIONALARMTYPE_H__
#define __OPCUA_EXCLUSIVEDEVIATIONALARMTYPE_H__

#include "opcua_exclusivelimitalarmtype.h"
#include "opcua_identifiers.h"
#include "basenodes.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class ExclusiveDeviationAlarmType;
class PropertyType;

/** Generated event data class for a ExclusiveDeviationAlarmType.
 *
 *  This class contains the auto generated code for the object type ExclusiveDeviationAlarmType
 *  providing UaEventData interface for the access to event data containing the current state of the
 *  condition for events sent to the client. The class is used for condition events if the condition has
 *  no nodes in the address space or for condition branches created as snapshot of the main branch.
 *
 *  **Event Fields of the ExclusiveDeviationAlarmType:**
 *
 *  Browse Name  | DataType | TypeDefinition | Modelling Rule | See Also
 *  -------------|----------|----------------|----------------|-------------------------------------------
 *  SetpointNode | NodeId   | PropertyType   | Mandatory      | \ref getSetpointNode, \ref setSetpointNode

 *  A special deviation alarm utilized with multiple mutually exclusive limits.
 *
 *  A deviation Alarm is commonly used to report an excess deviation between a
 *  desired set point level of a process value and an actual measurement of that
 *  value. The deviation Alarm becomes active when the deviation exceeds or drops
 *  below a defined limit.
 *
 *  For example if a set point had a value of 10 and the high deviation Alarm limit
 *  were set for 2 and the low deviation Alarm limit had a value of -1 then the low
 *  sub state is entered if the process value dropped to below 9; the high sub
 *  state is entered if the process value became larger than 12. If the set point
 *  were changed to 11 then the new deviation values would be 10 and 13
 *  respectively.
 *
 *  See also \ref Doc_OpcUa_ExclusiveDeviationAlarmType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT ExclusiveDeviationAlarmTypeData:
    public OpcUa::ExclusiveLimitAlarmTypeData
{
    UA_DISABLE_COPY(ExclusiveDeviationAlarmTypeData);
protected:
    virtual ~ExclusiveDeviationAlarmTypeData();
public:
    ExclusiveDeviationAlarmTypeData();
    void initializeAsBranch(ExclusiveDeviationAlarmType* pCondition);
    void initializeAsBranch(ExclusiveDeviationAlarmTypeData* pConditionData);
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // SetpointNode
    void setSetpointNode(const UaNodeId& SetpointNode);
    void setSetpointNodeStatus(OpcUa_StatusCode status);
    UaNodeId getSetpointNode();
    virtual void getSetpointNodeValue(Session* pSession, OpcUa_Variant& value);

private:
    void initialize();

private:
    UaObjectPointerArray<UaVariant> m_FieldValues;
};


/** @brief Class implementing the UaObject interface for the ExclusiveDeviationAlarmType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Variable members of the ExclusiveDeviationAlarmType:**
 *
 *  Browse Name  | DataType | TypeDefinition | Modelling Rule | See Also
 *  -------------|----------|----------------|----------------|-------------------------------------------------------------------------------------------------------------------------------------------------
 *  SetpointNode | NodeId   | PropertyType   | Mandatory      | \ref getSetpointNode, \ref setSetpointNode
 *
 *  A special deviation alarm utilized with multiple mutually exclusive limits.
 *
 *  A deviation Alarm is commonly used to report an excess deviation between a
 *  desired set point level of a process value and an actual measurement of that
 *  value. The deviation Alarm becomes active when the deviation exceeds or drops
 *  below a defined limit.
 *
 *  For example if a set point had a value of 10 and the high deviation Alarm limit
 *  were set for 2 and the low deviation Alarm limit had a value of -1 then the low
 *  sub state is entered if the process value dropped to below 9; the high sub
 *  state is entered if the process value became larger than 12. If the set point
 *  were changed to 11 then the new deviation values would be 10 and 13
 *  respectively.
 *
 *  See also \ref Doc_OpcUa_ExclusiveDeviationAlarmType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT ExclusiveDeviationAlarmType:
    public OpcUa::ExclusiveLimitAlarmType
{
    friend class ExclusiveDeviationAlarmTypeData;
    UA_DISABLE_COPY(ExclusiveDeviationAlarmType);
protected:
    // destruction
    virtual ~ExclusiveDeviationAlarmType();
public:
    // construction
    ExclusiveDeviationAlarmType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    ExclusiveDeviationAlarmType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    ExclusiveDeviationAlarmType(
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

    // SetpointNode
    virtual void setSetpointNode(const UaNodeId& SetpointNode);
    virtual UaNodeId getSetpointNode() const;
    virtual void setSetpointNodeStatus(OpcUa_StatusCode status);
    virtual void getSetpointNodeValue(Session* pSession, UaVariant& value);

    virtual OpcUa::PropertyType* getSetpointNodeNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(ExclusiveDeviationAlarmType *pInstance);

    virtual UaStatus triggerEvent(
        const UaDateTime&   time,
        const UaDateTime&   receiveTime,
        const UaByteString& eventId);

    virtual void getExclusiveDeviationAlarmTypeOptionalFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

protected:
    // Variable nodes
    // Variable SetpointNode
    static OpcUa::PropertyType*  s_pSetpointNode;
    OpcUa::PropertyType*  m_pSetpointNode;

private:
    void initialize();
    void createChildren();

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_ExclusiveDeviationAlarmTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUAEXCLUSIVEDEVIATIONALARMTYPE_H__

