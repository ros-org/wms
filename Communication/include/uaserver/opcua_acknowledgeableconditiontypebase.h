/******************************************************************************
** opcua_acknowledgeableconditiontypebase.h
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

#ifndef __OPCUA_ACKNOWLEDGEABLECONDITIONTYPEBASE_H__
#define __OPCUA_ACKNOWLEDGEABLECONDITIONTYPEBASE_H__

#include "opcua_conditiontype.h"
#include "basenodes.h"
#include "opcua_identifiers.h"
#include "opcua_propertytype.h"
#include "opcua_twostatevariabletype.h"
#include "uaargument.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class AcknowledgeableConditionTypeBase;
class TwoStateVariableType;

/** Generated event data class for a AcknowledgeableConditionType.
 *
 *  This class contains the auto generated code for the object type AcknowledgeableConditionType
 *  providing UaEventData interface for the access to event data containing the current state of the
 *  condition for events sent to the client. The class is used for condition events if the condition has
 *  no nodes in the address space or for condition branches created as snapshot of the main branch.
 *
 *  **Event Fields of the AcknowledgeableConditionType:**
 *
 *  Browse Name    | DataType      | TypeDefinition       | Modelling Rule | See Also
 *  ---------------|---------------|----------------------|----------------|-----------------------------------------------
 *  AckedState     | LocalizedText | TwoStateVariableType | Mandatory      | \ref getAckedState, \ref setAckedState
 *  ConfirmedState | LocalizedText | TwoStateVariableType | Optional       | \ref getConfirmedState, \ref setConfirmedState

 *  Extends the ConditionType by defining acknowledgement characteristics. It is an
 *  abstract type.
 *
 *  The AcknowledgeableConditionType inherits all Properties of the ConditionType.
 *
 *  AcknowledgeableConditions expose states to indicate whether a Condition has to
 *  be acknowledged or confirmed.
 *
 *  The Confirmed Acknowledge model is typically used to differentiate between
 *  acknowledging the presence of a Condition and having done something to address
 *  the Condition. For example an Operator receiving a motor high temperature
 *  Notification calls the Acknowledge method to inform the Server that the high
 *  temperature has been observed. The Operator then takes some action such as
 *  lowering the load on the motor in order to reduce the temperature. The Operator
 *  then calls the Confirm method to inform the Server that a corrective action has
 *  been taken.
 *
 *  AckedState when FALSE indicates that the Condition instance requires
 *  acknowledgement for the reported Condition state. When the Condition instance
 *  is acknowledged the AckedState is set to TRUE. ConfirmedState indicates whether
 *  it requires confirmation. The two states are substates of the TRUE
 *  EnabledState. The EventId used in the Event Notification is considered the
 *  identifier of this state and has to be used when calling the methods for
 *  acknowledgement or confirmation.
 *
 *  A Server may require that previous states be acknowledged. If the
 *  acknowledgement of a previous state is still open and a new state also requires
 *  acknowledgement, the Server shall create a branch of the Condition instance. In
 *  situations where state changes occur in short succession there can be multiple
 *  unacknowledged states and the Server has to maintain ConditionBranches for all
 *  previous unacknowledged states. These branches will be deleted after they have
 *  been acknowledged or if they reached their final state. Clients are expected to
 *  keep track of all ConditionBranches where AckedState is FALSE to allow
 *  acknowledgement of those. See also \ref OpcUa::ConditionTypeData
 *  "ConditionTypeData" for more information about ConditionBranches and the
 *  examples in Annex B.1 of Part 9 of the OPC UA Specification. The handling of
 *  the AckedState and branches also applies to the ConfirmState.
 *
 *  See also \ref Doc_OpcUa_AcknowledgeableConditionType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AcknowledgeableConditionTypeData:
    public OpcUa::ConditionTypeData
{
    UA_DISABLE_COPY(AcknowledgeableConditionTypeData);
protected:
    virtual ~AcknowledgeableConditionTypeData();
public:
    AcknowledgeableConditionTypeData();
    void initializeAsBranch(AcknowledgeableConditionTypeBase* pCondition);
    void initializeAsBranch(AcknowledgeableConditionTypeData* pConditionData);
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // AckedState
    virtual void getAckedStateValue(Session* pSession, OpcUa_Variant& value);
    void setAckedState(OpcUa_Boolean ackedState);
    void setAckedStateStatus(OpcUa_StatusCode status);
    OpcUa_Boolean getAckedState();
    virtual void getAckedState_IdValue(Session* pSession, OpcUa_Variant& value);
    void setAckedState_TransitionTime(const UaDateTime& TransitionTime);
    void setAckedState_TransitionTimeStatus(OpcUa_StatusCode status);
    UaDateTime getAckedState_TransitionTime();
    virtual void getAckedState_TransitionTimeValue(Session* pSession, OpcUa_Variant& value);
    // ConfirmedState
    virtual void getConfirmedStateValue(Session* pSession, OpcUa_Variant& value);
    void setConfirmedState(OpcUa_Boolean confirmedState);
    void setConfirmedStateStatus(OpcUa_StatusCode status);
    OpcUa_Boolean getConfirmedState();
    virtual void getConfirmedState_IdValue(Session* pSession, OpcUa_Variant& value);
    void setConfirmedState_TransitionTime(const UaDateTime& TransitionTime);
    void setConfirmedState_TransitionTimeStatus(OpcUa_StatusCode status);
    UaDateTime getConfirmedState_TransitionTime();
    virtual void getConfirmedState_TransitionTimeValue(Session* pSession, OpcUa_Variant& value);
    // EnabledState already defined by base class


private:
    void initialize();

private:
    UaObjectPointerArray<UaVariant> m_FieldValues;
};


/** Generated base class for a AcknowledgeableConditionType.
 *
 *  This class contains the auto generated code for the object type AcknowledgeableConditionType
 *  representing an OPC UA condition type. This class is used to create the condition type and to
 *  create and represent the condition object in the server address space. It provides also the UaEventData
 *  interface for the access to event data containing the current state of the condition for events sent to
 *  the client.
 *
 *  **Variable members of the AcknowledgeableConditionType:**
 *
 *  Browse Name    | DataType      | TypeDefinition       | Modelling Rule | See Also
 *  ---------------|---------------|----------------------|----------------|-----------------------------------------------
 *  AckedState     | LocalizedText | TwoStateVariableType | Mandatory      | \ref getAckedState, \ref setAckedState
 *  ConfirmedState | LocalizedText | TwoStateVariableType | Optional       | \ref getConfirmedState, \ref setConfirmedState
 *
 *
 *  Extends the ConditionType by defining acknowledgement characteristics. It is an
 *  abstract type.
 *
 *  The AcknowledgeableConditionType inherits all Properties of the ConditionType.
 *
 *  AcknowledgeableConditions expose states to indicate whether a Condition has to
 *  be acknowledged or confirmed.
 *
 *  The Confirmed Acknowledge model is typically used to differentiate between
 *  acknowledging the presence of a Condition and having done something to address
 *  the Condition. For example an Operator receiving a motor high temperature
 *  Notification calls the Acknowledge method to inform the Server that the high
 *  temperature has been observed. The Operator then takes some action such as
 *  lowering the load on the motor in order to reduce the temperature. The Operator
 *  then calls the Confirm method to inform the Server that a corrective action has
 *  been taken.
 *
 *  AckedState when FALSE indicates that the Condition instance requires
 *  acknowledgement for the reported Condition state. When the Condition instance
 *  is acknowledged the AckedState is set to TRUE. ConfirmedState indicates whether
 *  it requires confirmation. The two states are substates of the TRUE
 *  EnabledState. The EventId used in the Event Notification is considered the
 *  identifier of this state and has to be used when calling the methods for
 *  acknowledgement or confirmation.
 *
 *  A Server may require that previous states be acknowledged. If the
 *  acknowledgement of a previous state is still open and a new state also requires
 *  acknowledgement, the Server shall create a branch of the Condition instance. In
 *  situations where state changes occur in short succession there can be multiple
 *  unacknowledged states and the Server has to maintain ConditionBranches for all
 *  previous unacknowledged states. These branches will be deleted after they have
 *  been acknowledged or if they reached their final state. Clients are expected to
 *  keep track of all ConditionBranches where AckedState is FALSE to allow
 *  acknowledgement of those. See also \ref OpcUa::ConditionTypeData
 *  "ConditionTypeData" for more information about ConditionBranches and the
 *  examples in Annex B.1 of Part 9 of the OPC UA Specification. The handling of
 *  the AckedState and branches also applies to the ConfirmState.
 *
 *  See also \ref Doc_OpcUa_AcknowledgeableConditionType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AcknowledgeableConditionTypeBase:
    public OpcUa::ConditionType
{
    friend class AcknowledgeableConditionTypeData;
    UA_DISABLE_COPY(AcknowledgeableConditionTypeBase);
protected:
    // destruction
    virtual ~AcknowledgeableConditionTypeBase();
public:
    // construction
    AcknowledgeableConditionTypeBase(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    AcknowledgeableConditionTypeBase(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    AcknowledgeableConditionTypeBase(
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


    //- Interface MethodManager -----------------------------------------------------------
    /** Call method of an UA object. */
    virtual UaStatus beginCall(
        MethodManagerCallback* pCallback,
        const ServiceContext&  serviceContext,
        OpcUa_UInt32           callbackHandle,
        MethodHandle*          pMethodHandle,
        const UaVariantArray&  inputArguments);
    virtual UaStatus call(
        const ServiceContext&  serviceContext,
        MethodHandle*          pMethodHandle,
        const UaVariantArray&  inputArguments,
        UaVariantArray&        outputArguments,
        UaStatusCodeArray&     inputArgumentResults,
        UaDiagnosticInfos&     inputArgumentDiag);
    //- Interface MethodManager -----------------------------------------------------------


    /**
     *  Acknowledges an Event Notification for a Condition instance state where
     *  AckedState is FALSE.
     *
     *  Normally, the NodeId of the object instance as the ObjectId is passed to the
     *  Call Service. However, some Servers do not expose Condition instances in the
     *  AddressSpace. Therefore all Servers shall also allow Clients to call the
     *  Acknowledge method by specifying ConditionId. The method cannot be called with
     *  an ObjectId of the AcknowledgeableConditionType Node.
     *
     *  ResultCode                       | Description
     *  ---------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
     *  Bad_ConditionBranchAlreadyAcked  | The EventId does not refer to a state that needs acknowledgement.
     *  Bad_MethodInvalid                | The method id does not refer to a method for the specified object or ConditionId.
     *  Bad_EventIdUnknown               | The specified EventId is not known to the Server.
     *  Bad_NodeIdInvalid                | The node id refers to a node that does not exist in the server address space. Used to indicate that the specified ObjectId is not valid or that the method was called on the ConditionType Node.
     */
    virtual UaStatus Acknowledge(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        UaByteString& EventId /**<[in] The identifier for the event to comment.. EventId identifying a particular Event Notification.
            <br>
            Only Event Notifications where AckedState/Id was FALSE can be acknowledged. */,
        const UaLocalizedText& Comment /**<[in] The comment to add to the condition.. A localized text to be applied to the Condition. */) = 0;

    /**
     *  Confirms an Event Notification for a Condition instance state where
     *  ConfirmedState was set to FALSE.
     *
     *  Normally, the NodeId of the object instance as the ObjectId is passed to the
     *  Call Service. However, some Servers do not expose Condition instances in the
     *  AddressSpace. Therefore all Servers shall also allow Clients to call the
     *  Confirm method by specifying ConditionId as the ObjectId. The method cannot be
     *  called with an ObjectIf of the AcknowledgeableConditionType Node.
     *
     *  <b>Method Result Codes</b>
     *
     *  ResultCode                           | Description
     *  -------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
     *  Bad_ConditionBranchAlreadyConfirmed  | The EventId does not refer to a state that needs confirmation.
     *  Bad_MethodInvalid                    | The method id does not refer to a method for the specified object or ConditionId.
     *  Bad_EventIdUnknown                   | The specified EventId is not known to the Server.
     *  Bad_NodeIdUnknown                    | The node id refers to a node that does not exist in the server address space. Used to indicate that the specified ObjectId is not valid or that the method was called on the ConditionType Node.
     */
    virtual UaStatus Confirm(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        UaByteString& EventId /**<[in] The identifier for the event to comment.. EventId identifying a particular Event Notification.
            <br>
            Only Event Notifications where ConfirmedState/Id was TRUE can be confirmed. */,
        const UaLocalizedText& Comment /**<[in] The comment to add to the condition.. A localized text to be applied to the Conditions. */) = 0;

    // AckedState
    virtual void setAckedState(OpcUa_Boolean ackedState);
    virtual OpcUa_Boolean getAckedStateBool();
    virtual UaLocalizedText getAckedState();
    virtual void setAckedStateStatus(OpcUa_StatusCode status);
    virtual void getAckedStateValue(Session* pSession, UaVariant& value);
    // ConfirmedState
    virtual void setConfirmedState(OpcUa_Boolean confirmedState);
    virtual OpcUa_Boolean getConfirmedStateBool();
    virtual UaLocalizedText getConfirmedState();
    virtual void setConfirmedStateStatus(OpcUa_StatusCode status);
    virtual void getConfirmedStateValue(Session* pSession, UaVariant& value);
    // EnabledState
    // Already defined by base class

    virtual OpcUa::TwoStateVariableType* getAckedStateNode();
    virtual OpcUa::TwoStateVariableType* getConfirmedStateNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(AcknowledgeableConditionTypeBase *pInstance);

    virtual UaStatus triggerEvent(
        const UaDateTime&   time,
        const UaDateTime&   receiveTime,
        const UaByteString& eventId);

    virtual void getAcknowledgeableConditionTypeOptionalFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

protected:
    // Variable nodes
    // Variable AckedState
    static OpcUa::TwoStateVariableType*  s_pAckedState;
    OpcUa::TwoStateVariableType*  m_pAckedState;
    // Variable ConfirmedState
    static OpcUa::TwoStateVariableType*  s_pConfirmedState;
    OpcUa::TwoStateVariableType*  m_pConfirmedState;
    // Variable EnabledState
    static OpcUa::TwoStateVariableType*  s_pEnabledState;
    // EnabledState defined by base type


    // Method Acknowledge
    static OpcUa::BaseMethod* s_pAcknowledgeMethod;
    // Method Confirm
    static OpcUa::BaseMethod* s_pConfirmMethod;

private:
    void initialize();
    void createChildren();

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AcknowledgeableConditionTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUAACKNOWLEDGEABLECONDITIONTYPEBASE_H__

