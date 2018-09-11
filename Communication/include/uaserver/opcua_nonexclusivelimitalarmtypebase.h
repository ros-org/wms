/******************************************************************************
** opcua_nonexclusivelimitalarmtypebase.h
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

#ifndef __OPCUA_NONEXCLUSIVELIMITALARMTYPEBASE_H__
#define __OPCUA_NONEXCLUSIVELIMITALARMTYPEBASE_H__

#include "opcua_limitalarmtype.h"
#include "basenodes.h"
#include "opcua_identifiers.h"
#include "opcua_twostatevariabletype.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class NonExclusiveLimitAlarmTypeBase;
class TwoStateVariableType;

/** Generated event data class for a NonExclusiveLimitAlarmType.
 *
 *  This class contains the auto generated code for the object type NonExclusiveLimitAlarmType
 *  providing UaEventData interface for the access to event data containing the current state of the
 *  condition for events sent to the client. The class is used for condition events if the condition has
 *  no nodes in the address space or for condition branches created as snapshot of the main branch.
 *
 *  **Event Fields of the NonExclusiveLimitAlarmType:**
 *
 *  Browse Name   | DataType      | TypeDefinition       | Modelling Rule | See Also
 *  --------------|---------------|----------------------|----------------|---------------------------------------------
 *  HighHighState | LocalizedText | TwoStateVariableType | Optional       | \ref getHighHighState, \ref setHighHighState
 *  HighState     | LocalizedText | TwoStateVariableType | Optional       | \ref getHighState, \ref setHighState
 *  LowLowState   | LocalizedText | TwoStateVariableType | Optional       | \ref getLowLowState, \ref setLowLowState
 *  LowState      | LocalizedText | TwoStateVariableType | Optional       | \ref getLowState, \ref setLowState

 *  Used to specify the common behaviour for Alarm Types with multiple
 *  non-exclusive limits
 *
 *  HighHighState, HighState, LowState, and LowLowState represent the non-exclusive
 *  states. As an example, it is possible that both HighState and HighHighState are
 *  in their TRUE state. Vendors may choose to support any subset of these states.
 *
 *  Four optional limits are defined that configure these states. At least the
 *  HighState or the LowState shall be provided even though all states are
 *  optional. It is implied by the definition of a HighState and a LowState, that
 *  these groupings are mutually exclusive. A value cannot exceed both a HighState
 *  value and a LowState value simultaneously.
 *
 *  See also \ref Doc_OpcUa_NonExclusiveLimitAlarmType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT NonExclusiveLimitAlarmTypeData:
    public OpcUa::LimitAlarmTypeData
{
    UA_DISABLE_COPY(NonExclusiveLimitAlarmTypeData);
protected:
    virtual ~NonExclusiveLimitAlarmTypeData();
public:
    NonExclusiveLimitAlarmTypeData();
    void initializeAsBranch(NonExclusiveLimitAlarmTypeBase* pCondition);
    void initializeAsBranch(NonExclusiveLimitAlarmTypeData* pConditionData);
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // ActiveState already defined by base class
    // HighHighState
    virtual void getHighHighStateValue(Session* pSession, OpcUa_Variant& value);
    void setHighHighState(OpcUa_Boolean highHighState);
    void setHighHighStateStatus(OpcUa_StatusCode status);
    OpcUa_Boolean getHighHighState();
    virtual void getHighHighState_IdValue(Session* pSession, OpcUa_Variant& value);
    void setHighHighState_TransitionTime(const UaDateTime& TransitionTime);
    void setHighHighState_TransitionTimeStatus(OpcUa_StatusCode status);
    UaDateTime getHighHighState_TransitionTime();
    virtual void getHighHighState_TransitionTimeValue(Session* pSession, OpcUa_Variant& value);
    // HighState
    virtual void getHighStateValue(Session* pSession, OpcUa_Variant& value);
    void setHighState(OpcUa_Boolean highState);
    void setHighStateStatus(OpcUa_StatusCode status);
    OpcUa_Boolean getHighState();
    virtual void getHighState_IdValue(Session* pSession, OpcUa_Variant& value);
    void setHighState_TransitionTime(const UaDateTime& TransitionTime);
    void setHighState_TransitionTimeStatus(OpcUa_StatusCode status);
    UaDateTime getHighState_TransitionTime();
    virtual void getHighState_TransitionTimeValue(Session* pSession, OpcUa_Variant& value);
    // LowLowState
    virtual void getLowLowStateValue(Session* pSession, OpcUa_Variant& value);
    void setLowLowState(OpcUa_Boolean lowLowState);
    void setLowLowStateStatus(OpcUa_StatusCode status);
    OpcUa_Boolean getLowLowState();
    virtual void getLowLowState_IdValue(Session* pSession, OpcUa_Variant& value);
    void setLowLowState_TransitionTime(const UaDateTime& TransitionTime);
    void setLowLowState_TransitionTimeStatus(OpcUa_StatusCode status);
    UaDateTime getLowLowState_TransitionTime();
    virtual void getLowLowState_TransitionTimeValue(Session* pSession, OpcUa_Variant& value);
    // LowState
    virtual void getLowStateValue(Session* pSession, OpcUa_Variant& value);
    void setLowState(OpcUa_Boolean lowState);
    void setLowStateStatus(OpcUa_StatusCode status);
    OpcUa_Boolean getLowState();
    virtual void getLowState_IdValue(Session* pSession, OpcUa_Variant& value);
    void setLowState_TransitionTime(const UaDateTime& TransitionTime);
    void setLowState_TransitionTimeStatus(OpcUa_StatusCode status);
    UaDateTime getLowState_TransitionTime();
    virtual void getLowState_TransitionTimeValue(Session* pSession, OpcUa_Variant& value);


private:
    void initialize();

private:
    UaObjectPointerArray<UaVariant> m_FieldValues;
};


/** Generated base class for a NonExclusiveLimitAlarmType.
 *
 *  This class contains the auto generated code for the object type NonExclusiveLimitAlarmType
 *  representing an OPC UA condition type. This class is used to create the condition type and to
 *  create and represent the condition object in the server address space. It provides also the UaEventData
 *  interface for the access to event data containing the current state of the condition for events sent to
 *  the client.
 *
 *  **Variable members of the NonExclusiveLimitAlarmType:**
 *
 *  Browse Name   | DataType      | TypeDefinition       | Modelling Rule | See Also
 *  --------------|---------------|----------------------|----------------|---------------------------------------------
 *  HighHighState | LocalizedText | TwoStateVariableType | Optional       | \ref getHighHighState, \ref setHighHighState
 *  HighState     | LocalizedText | TwoStateVariableType | Optional       | \ref getHighState, \ref setHighState
 *  LowLowState   | LocalizedText | TwoStateVariableType | Optional       | \ref getLowLowState, \ref setLowLowState
 *  LowState      | LocalizedText | TwoStateVariableType | Optional       | \ref getLowState, \ref setLowState
 *
 *
 *  Used to specify the common behaviour for Alarm Types with multiple
 *  non-exclusive limits
 *
 *  HighHighState, HighState, LowState, and LowLowState represent the non-exclusive
 *  states. As an example, it is possible that both HighState and HighHighState are
 *  in their TRUE state. Vendors may choose to support any subset of these states.
 *
 *  Four optional limits are defined that configure these states. At least the
 *  HighState or the LowState shall be provided even though all states are
 *  optional. It is implied by the definition of a HighState and a LowState, that
 *  these groupings are mutually exclusive. A value cannot exceed both a HighState
 *  value and a LowState value simultaneously.
 *
 *  See also \ref Doc_OpcUa_NonExclusiveLimitAlarmType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT NonExclusiveLimitAlarmTypeBase:
    public OpcUa::LimitAlarmType
{
    friend class NonExclusiveLimitAlarmTypeData;
    UA_DISABLE_COPY(NonExclusiveLimitAlarmTypeBase);
protected:
    // destruction
    virtual ~NonExclusiveLimitAlarmTypeBase();
public:
    // construction
    NonExclusiveLimitAlarmTypeBase(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    NonExclusiveLimitAlarmTypeBase(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    NonExclusiveLimitAlarmTypeBase(
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
    // HighHighState
    virtual void setHighHighState(OpcUa_Boolean highHighState);
    virtual OpcUa_Boolean getHighHighStateBool();
    virtual UaLocalizedText getHighHighState();
    virtual void setHighHighStateStatus(OpcUa_StatusCode status);
    virtual void getHighHighStateValue(Session* pSession, UaVariant& value);
    // HighState
    virtual void setHighState(OpcUa_Boolean highState);
    virtual OpcUa_Boolean getHighStateBool();
    virtual UaLocalizedText getHighState();
    virtual void setHighStateStatus(OpcUa_StatusCode status);
    virtual void getHighStateValue(Session* pSession, UaVariant& value);
    // LowLowState
    virtual void setLowLowState(OpcUa_Boolean lowLowState);
    virtual OpcUa_Boolean getLowLowStateBool();
    virtual UaLocalizedText getLowLowState();
    virtual void setLowLowStateStatus(OpcUa_StatusCode status);
    virtual void getLowLowStateValue(Session* pSession, UaVariant& value);
    // LowState
    virtual void setLowState(OpcUa_Boolean lowState);
    virtual OpcUa_Boolean getLowStateBool();
    virtual UaLocalizedText getLowState();
    virtual void setLowStateStatus(OpcUa_StatusCode status);
    virtual void getLowStateValue(Session* pSession, UaVariant& value);

    virtual OpcUa::TwoStateVariableType* getHighHighStateNode();
    virtual OpcUa::TwoStateVariableType* getHighStateNode();
    virtual OpcUa::TwoStateVariableType* getLowLowStateNode();
    virtual OpcUa::TwoStateVariableType* getLowStateNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(NonExclusiveLimitAlarmTypeBase *pInstance);

    virtual UaStatus triggerEvent(
        const UaDateTime&   time,
        const UaDateTime&   receiveTime,
        const UaByteString& eventId);

    virtual void getNonExclusiveLimitAlarmTypeOptionalFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

protected:
    // Variable nodes
    // Variable ActiveState
    static OpcUa::TwoStateVariableType*  s_pActiveState;
    // ActiveState defined by base type
    // Variable HighHighState
    static OpcUa::TwoStateVariableType*  s_pHighHighState;
    OpcUa::TwoStateVariableType*  m_pHighHighState;
    // Variable HighState
    static OpcUa::TwoStateVariableType*  s_pHighState;
    OpcUa::TwoStateVariableType*  m_pHighState;
    // Variable LowLowState
    static OpcUa::TwoStateVariableType*  s_pLowLowState;
    OpcUa::TwoStateVariableType*  m_pLowLowState;
    // Variable LowState
    static OpcUa::TwoStateVariableType*  s_pLowState;
    OpcUa::TwoStateVariableType*  m_pLowState;



private:
    void initialize();
    void createChildren();

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_NonExclusiveLimitAlarmTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUANONEXCLUSIVELIMITALARMTYPEBASE_H__

