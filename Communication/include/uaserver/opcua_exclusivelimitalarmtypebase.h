/******************************************************************************
** opcua_exclusivelimitalarmtypebase.h
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

#ifndef __OPCUA_EXCLUSIVELIMITALARMTYPEBASE_H__
#define __OPCUA_EXCLUSIVELIMITALARMTYPEBASE_H__

#include "opcua_limitalarmtype.h"
#include "basenodes.h"
#include "opcua_finitetransitionvariabletype.h"
#include "opcua_identifiers.h"
#include "opcua_twostatevariabletype.h"
#include "opcua_exclusivelimitstatemachinetype.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class ExclusiveLimitAlarmTypeBase;
class ExclusiveLimitStateMachineType;
class FiniteStateVariableType;
class FiniteTransitionVariableType;

/** Generated event data class for a ExclusiveLimitAlarmType.
 *
 *  This class contains the auto generated code for the object type ExclusiveLimitAlarmType
 *  providing UaEventData interface for the access to event data containing the current state of the
 *  condition for events sent to the client. The class is used for condition events if the condition has
 *  no nodes in the address space or for condition branches created as snapshot of the main branch.

 *  Used to specify the common behaviour for Alarm Types with multiple mutually
 *  exclusive limits.
 *
 *  The LimitState is a Substate of the ActiveState and has a IsTrueSubstate
 *  reference to the ActiveState.
 *
 *  See also \ref Doc_OpcUa_ExclusiveLimitAlarmType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT ExclusiveLimitAlarmTypeData:
    public OpcUa::LimitAlarmTypeData
{
    UA_DISABLE_COPY(ExclusiveLimitAlarmTypeData);
protected:
    virtual ~ExclusiveLimitAlarmTypeData();
public:
    ExclusiveLimitAlarmTypeData();
    void initializeAsBranch(ExclusiveLimitAlarmTypeBase* pCondition);
    void initializeAsBranch(ExclusiveLimitAlarmTypeData* pConditionData);
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // ActiveState already defined by base class
// Addition to generated code begin (Added and removed methods)
    void setExclusiveState(ExclusiveLimitStateMachineType::ExclusiveState state);
    ExclusiveLimitStateMachineType::ExclusiveState getExclusiveState();
    // LimitState
    UaLocalizedText getLimitState_CurrentState();
    virtual void getLimitState_CurrentStateValue(Session* pSession, OpcUa_Variant& value);
    UaNodeId getLimitState_CurrentState_Id();
    virtual void getLimitState_CurrentState_IdValue(Session* pSession, OpcUa_Variant& value);
    UaLocalizedText getLimitState_LastTransition();
    virtual void getLimitState_LastTransitionValue(Session* pSession, OpcUa_Variant& value);
    UaNodeId getLimitState_LastTransition_Id();
    virtual void getLimitState_LastTransition_IdValue(Session* pSession, OpcUa_Variant& value);
    UaDateTime getLimitState_LastTransition_TransitionTime();
    virtual void getLimitState_LastTransition_TransitionTimeValue(Session* pSession, OpcUa_Variant& value);
// Addition to generated code end


private:
    void initialize();

private:
    UaObjectPointerArray<UaVariant> m_FieldValues;
// Addition to generated code begin
    ExclusiveLimitStateMachineType::ExclusiveState m_state;
// Addition to generated code end
};


/** Generated base class for a ExclusiveLimitAlarmType.
 *
 *  This class contains the auto generated code for the object type ExclusiveLimitAlarmType
 *  representing an OPC UA condition type. This class is used to create the condition type and to
 *  create and represent the condition object in the server address space. It provides also the UaEventData
 *  interface for the access to event data containing the current state of the condition for events sent to
 *  the client.
 *
 *  **Object members of the ExclusiveLimitAlarmType:**
 *
 *  Browse Name | TypeDefinition                 | Modelling Rule | See Also
 *  ------------|--------------------------------|----------------|-------------------
 *  LimitState  | ExclusiveLimitStateMachineType | Mandatory      | \ref getLimitState
 *
 *
 *  Used to specify the common behaviour for Alarm Types with multiple mutually
 *  exclusive limits.
 *
 *  The LimitState is a Substate of the ActiveState and has a IsTrueSubstate
 *  reference to the ActiveState.
 *
 *  See also \ref Doc_OpcUa_ExclusiveLimitAlarmType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT ExclusiveLimitAlarmTypeBase:
    public OpcUa::LimitAlarmType
{
    friend class ExclusiveLimitAlarmTypeData;
    UA_DISABLE_COPY(ExclusiveLimitAlarmTypeBase);
protected:
    // destruction
    virtual ~ExclusiveLimitAlarmTypeBase();
public:
    // construction
    ExclusiveLimitAlarmTypeBase(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    ExclusiveLimitAlarmTypeBase(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    ExclusiveLimitAlarmTypeBase(
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


    // ActiveState
    // Already defined by base class

    virtual OpcUa::ExclusiveLimitStateMachineType* getLimitState();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(ExclusiveLimitAlarmTypeBase *pInstance);

    virtual UaStatus triggerEvent(
        const UaDateTime&   time,
        const UaDateTime&   receiveTime,
        const UaByteString& eventId);

    virtual void getExclusiveLimitAlarmTypeOptionalFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

protected:
    // Object nodes
    // Object LimitState
    static OpcUa::ExclusiveLimitStateMachineType*  s_pLimitState;
    OpcUa::ExclusiveLimitStateMachineType*  m_pLimitState;

    // Variable nodes
    // Variable ActiveState
    static OpcUa::TwoStateVariableType*  s_pActiveState;
    // ActiveState defined by base type



private:
    void initialize();
    void createChildren();

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_ExclusiveLimitAlarmTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUAEXCLUSIVELIMITALARMTYPEBASE_H__

