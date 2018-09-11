/******************************************************************************
** opcua_conditiontypebase.h
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

#ifndef __OPCUA_CONDITIONTYPEBASE_H__
#define __OPCUA_CONDITIONTYPEBASE_H__

#include "opcua_baseeventtype.h"
#include "basenodes.h"
#include "opcua_identifiers.h"
#include "opcua_propertytype.h"
#include "uaargument.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class ConditionTypeBase;
class ConditionVariableType;
class PropertyType;
class TwoStateVariableType;

/** Generated event data class for a ConditionType.
 *
 *  This class contains the auto generated code for the object type ConditionType
 *  providing UaEventData interface for the access to event data containing the current state of the
 *  condition for events sent to the client. The class is used for condition events if the condition has
 *  no nodes in the address space or for condition branches created as snapshot of the main branch.
 *
 *  **Event Fields of the ConditionType:**
 *
 *  Browse Name        | DataType      | TypeDefinition        | Modelling Rule | See Also
 *  -------------------|---------------|-----------------------|----------------|-------------------------------------------------------
 *  BranchId           | NodeId        | PropertyType          | Mandatory      | \ref getBranchId, \ref setBranchId
 *  ClientUserId       | String        | PropertyType          | Mandatory      | \ref getClientUserId, \ref setClientUserId
 *  Comment            | LocalizedText | ConditionVariableType | Mandatory      | \ref getComment, \ref setComment
 *  ConditionClassId   | NodeId        | PropertyType          | Mandatory      | \ref getConditionClassId, \ref setConditionClassId
 *  ConditionClassName | LocalizedText | PropertyType          | Mandatory      | \ref getConditionClassName, \ref setConditionClassName
 *  ConditionName      | String        | PropertyType          | Mandatory      | \ref getConditionName, \ref setConditionName
 *  EnabledState       | LocalizedText | TwoStateVariableType  | Mandatory      | \ref getEnabledState, \ref setEnabledState
 *  LastSeverity       | UInt16        | ConditionVariableType | Mandatory      | \ref getLastSeverity, \ref setLastSeverity
 *  Quality            | StatusCode    | ConditionVariableType | Mandatory      | \ref getQuality, \ref setQuality
 *  Retain             | Boolean       | PropertyType          | Mandatory      | \ref getRetain, \ref setRetain

 *  The ConditionType defines all general characteristics of a Condition. All other
 *  ConditionTypes derive from it.
 *
 *  The FALSE state of the EnabledState shall not be extended with a substate
 *  machine. The ConditionType inherits all Properties of the BaseEventType.
 *
 *  SourceNode identifies the ConditionSource. If the ConditionSource is not a Node
 *  in the AddressSpace, the NodeId is set to null. The SourceNode is the Node
 *  which the condition is associated with, it may be the same as the InputNode for
 *  an alarm, but it may be a separate node. For example, a motor which is a
 *  variable with a value that is an RPM may be the ConditionSource for Conditions
 *  that are related to the motor, as well as a temperature sensor associated with
 *  the motor. In the former, the InputNode for the High RPM alarm is the value of
 *  the Motor RPM, while in the later the InputNode of the High Alarm would be the
 *  value of the temperature sensor that is associated with the motor.
 *
 *  Events are only generated for Conditions that have their Retain field set to
 *  true.
 *
 *  The NodeId of the Condition instance is used as ConditionId. It is not
 *  explicitly modelled as a component of the ConditionType. However, it can be
 *  requested with the following SimpleAttributeOperand in the SelectClause of the
 *  EventFilter:
 *
 *  Name          | Type          | Description
 *  --------------|---------------|----------------------------------
 *  typeId        | NodeId        | NodeId of the ConditionType Node
 *  browsePath[]  | QualifiedName | empty
 *  attributeId   | IntegerId     | Id of the NodeId Attribute
 *
 *  See also \ref Doc_OpcUa_ConditionType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT ConditionTypeData:
    public BaseEventTypeData,
    public ReferenceCounter
{
    UA_DISABLE_COPY(ConditionTypeData);
protected:
    virtual ~ConditionTypeData();
public:
    ConditionTypeData();
    void initializeAsBranch(ConditionTypeBase* pCondition);
    void initializeAsBranch(ConditionTypeData* pConditionData);
    ReferenceCounter* getConditionDataReferenceCounter(){ return this;}

    void setConditionNodeId(const UaNodeId& conditionNodeId);
    virtual UaNodeId getConditionNodeId();
    virtual UaNodeId getConditionBranchNodeId();
    virtual OpcUa_Boolean getConditionRetain();

    /** Lock the event data for data update and event handling.
     *
     * This method is used for event data objects maintaining a state for conditions since there
     * may be concurrent access to the condition data by a condition update and a condition refresh
     * triggered by a client. This method is also used during the event processing in the SDK.
     */
    virtual void lockEventData(){m_mutex.lock();}

    /** Unlock the event data after data update or event handling.
     *
     * This method is used for event data objects maintaining a state for conditions since there
     * may be concurrent access to the condition data by a condition update and a condition refresh
     * triggered by a client. This method is also used during the event processing in the SDK.
     */
    virtual void unlockEventData(){m_mutex.unlock();}
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // BranchId
    void setBranchId(const UaNodeId& BranchId);
    void setBranchIdStatus(OpcUa_StatusCode status);
    UaNodeId getBranchId();
    virtual void getBranchIdValue(Session* pSession, OpcUa_Variant& value);
    // ClientUserId
    void setClientUserId(const UaString& ClientUserId);
    void setClientUserIdStatus(OpcUa_StatusCode status);
    UaString getClientUserId();
    virtual void getClientUserIdValue(Session* pSession, OpcUa_Variant& value);
    // Comment
    void setComment(const UaLocalizedText& Comment);
    void setCommentStatus(OpcUa_StatusCode status);
    UaLocalizedText getComment();
    virtual void getCommentValue(Session* pSession, OpcUa_Variant& value);
    void setComment_SourceTimestamp(const UaDateTime& SourceTimestamp);
    void setComment_SourceTimestampStatus(OpcUa_StatusCode status);
    UaDateTime getComment_SourceTimestamp();
    virtual void getComment_SourceTimestampValue(Session* pSession, OpcUa_Variant& value);
    // ConditionClassId
    void setConditionClassId(const UaNodeId& ConditionClassId);
    void setConditionClassIdStatus(OpcUa_StatusCode status);
    UaNodeId getConditionClassId();
    virtual void getConditionClassIdValue(Session* pSession, OpcUa_Variant& value);
    // ConditionClassName
    void setConditionClassName(const UaLocalizedText& ConditionClassName);
    void setConditionClassNameStatus(OpcUa_StatusCode status);
    UaLocalizedText getConditionClassName();
    virtual void getConditionClassNameValue(Session* pSession, OpcUa_Variant& value);
    // ConditionName
    void setConditionName(const UaString& ConditionName);
    void setConditionNameStatus(OpcUa_StatusCode status);
    UaString getConditionName();
    virtual void getConditionNameValue(Session* pSession, OpcUa_Variant& value);
    // EnabledState
    virtual void getEnabledStateValue(Session* pSession, OpcUa_Variant& value);
    void setEnabledState(OpcUa_Boolean enabledState);
    void setEnabledStateStatus(OpcUa_StatusCode status);
    OpcUa_Boolean getEnabledState();
    void setEnabledState_EffectiveDisplayName(const UaLocalizedText& EffectiveDisplayName);
    void setEnabledState_EffectiveDisplayNameStatus(OpcUa_StatusCode status);
    UaLocalizedText getEnabledState_EffectiveDisplayName();
    virtual void getEnabledState_EffectiveDisplayNameValue(Session* pSession, OpcUa_Variant& value);
    void setEnabledState_EffectiveTransitionTime(const UaDateTime& EffectiveTransitionTime);
    void setEnabledState_EffectiveTransitionTimeStatus(OpcUa_StatusCode status);
    UaDateTime getEnabledState_EffectiveTransitionTime();
    virtual void getEnabledState_EffectiveTransitionTimeValue(Session* pSession, OpcUa_Variant& value);
    virtual void getEnabledState_IdValue(Session* pSession, OpcUa_Variant& value);
    void setEnabledState_TransitionTime(const UaDateTime& TransitionTime);
    void setEnabledState_TransitionTimeStatus(OpcUa_StatusCode status);
    UaDateTime getEnabledState_TransitionTime();
    virtual void getEnabledState_TransitionTimeValue(Session* pSession, OpcUa_Variant& value);
    // LastSeverity
    void setLastSeverity(OpcUa_UInt16 LastSeverity);
    void setLastSeverityStatus(OpcUa_StatusCode status);
    OpcUa_UInt16 getLastSeverity();
    virtual void getLastSeverityValue(Session* pSession, OpcUa_Variant& value);
    void setLastSeverity_SourceTimestamp(const UaDateTime& SourceTimestamp);
    void setLastSeverity_SourceTimestampStatus(OpcUa_StatusCode status);
    UaDateTime getLastSeverity_SourceTimestamp();
    virtual void getLastSeverity_SourceTimestampValue(Session* pSession, OpcUa_Variant& value);
    // Quality
    void setQuality(OpcUa_StatusCode Quality);
    void setQualityStatus(OpcUa_StatusCode status);
    OpcUa_StatusCode getQuality();
    virtual void getQualityValue(Session* pSession, OpcUa_Variant& value);
    void setQuality_SourceTimestamp(const UaDateTime& SourceTimestamp);
    void setQuality_SourceTimestampStatus(OpcUa_StatusCode status);
    UaDateTime getQuality_SourceTimestamp();
    virtual void getQuality_SourceTimestampValue(Session* pSession, OpcUa_Variant& value);
    // Retain
    void setRetain(OpcUa_Boolean Retain);
    void setRetainStatus(OpcUa_StatusCode status);
    OpcUa_Boolean getRetain();
    virtual void getRetainValue(Session* pSession, OpcUa_Variant& value);


private:
    void initialize();

protected:
    UaMutex m_mutex;

private:
    UaObjectPointerArray<UaVariant> m_FieldValues;
};


/** Generated base class for a ConditionType.
 *
 *  This class contains the auto generated code for the object type ConditionType
 *  representing an OPC UA condition type. This class is used to create the condition type and to
 *  create and represent the condition object in the server address space. It provides also the UaEventData
 *  interface for the access to event data containing the current state of the condition for events sent to
 *  the client.
 *
 *  **Variable members of the ConditionType:**
 *
 *  Browse Name        | DataType      | TypeDefinition        | Modelling Rule | See Also
 *  -------------------|---------------|-----------------------|----------------|-------------------------------------------------------
 *  BranchId           | NodeId        | PropertyType          | Mandatory      | \ref getBranchId, \ref setBranchId
 *  ClientUserId       | String        | PropertyType          | Mandatory      | \ref getClientUserId, \ref setClientUserId
 *  Comment            | LocalizedText | ConditionVariableType | Mandatory      | \ref getComment, \ref setComment
 *  ConditionClassId   | NodeId        | PropertyType          | Mandatory      | \ref getConditionClassId, \ref setConditionClassId
 *  ConditionClassName | LocalizedText | PropertyType          | Mandatory      | \ref getConditionClassName, \ref setConditionClassName
 *  ConditionName      | String        | PropertyType          | Mandatory      | \ref getConditionName, \ref setConditionName
 *  EnabledState       | LocalizedText | TwoStateVariableType  | Mandatory      | \ref getEnabledState, \ref setEnabledState
 *  LastSeverity       | UInt16        | ConditionVariableType | Mandatory      | \ref getLastSeverity, \ref setLastSeverity
 *  Quality            | StatusCode    | ConditionVariableType | Mandatory      | \ref getQuality, \ref setQuality
 *  Retain             | Boolean       | PropertyType          | Mandatory      | \ref getRetain, \ref setRetain
 *
 *
 *  The ConditionType defines all general characteristics of a Condition. All other
 *  ConditionTypes derive from it.
 *
 *  The FALSE state of the EnabledState shall not be extended with a substate
 *  machine. The ConditionType inherits all Properties of the BaseEventType.
 *
 *  SourceNode identifies the ConditionSource. If the ConditionSource is not a Node
 *  in the AddressSpace, the NodeId is set to null. The SourceNode is the Node
 *  which the condition is associated with, it may be the same as the InputNode for
 *  an alarm, but it may be a separate node. For example, a motor which is a
 *  variable with a value that is an RPM may be the ConditionSource for Conditions
 *  that are related to the motor, as well as a temperature sensor associated with
 *  the motor. In the former, the InputNode for the High RPM alarm is the value of
 *  the Motor RPM, while in the later the InputNode of the High Alarm would be the
 *  value of the temperature sensor that is associated with the motor.
 *
 *  Events are only generated for Conditions that have their Retain field set to
 *  true.
 *
 *  The NodeId of the Condition instance is used as ConditionId. It is not
 *  explicitly modelled as a component of the ConditionType. However, it can be
 *  requested with the following SimpleAttributeOperand in the SelectClause of the
 *  EventFilter:
 *
 *  Name          | Type          | Description
 *  --------------|---------------|----------------------------------
 *  typeId        | NodeId        | NodeId of the ConditionType Node
 *  browsePath[]  | QualifiedName | empty
 *  attributeId   | IntegerId     | Id of the NodeId Attribute
 *
 *  See also \ref Doc_OpcUa_ConditionType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT ConditionTypeBase:
    public OpcUa::BaseEventType
{
    friend class ConditionTypeData;
    UA_DISABLE_COPY(ConditionTypeBase);
protected:
    // destruction
    virtual ~ConditionTypeBase();
public:
    // construction
    ConditionTypeBase(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    ConditionTypeBase(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    ConditionTypeBase(
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

    /** Lock the event data for data update and event handling.
     *
     * This method is used for event data objects maintaining a state for conditions since there
     * may be concurrent access to the condition data by a condition update and a condition refresh
     * triggered by a client. This method is also used during the event processing in the SDK.
     */
    virtual void lockEventData(){m_pSharedMutex->lock();}

    /** Unlock the event data after data update or event handling.
     *
     * This method is used for event data objects maintaining a state for conditions since there
     * may be concurrent access to the condition data by a condition update and a condition refresh
     * triggered by a client. This method is also used during the event processing in the SDK.
     */
    virtual void unlockEventData(){m_pSharedMutex->unlock();}


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
     *  Applies a comment to a specific state of a Condition instance.
     *
     *  Normally, the NodeId of the object instance as the ObjectId is passed to the
     *  Call Service. However, some Servers do not expose Condition instances in the
     *  AddressSpace. Therefore all Servers shall also allow Clients to call the
     *  AddComment method by specifying ConditionId as the ObjectId. The method cannot
     *  be called with an ObjectId of the ConditionType Node.
     *
     *  <b>Method Result Codes</b>
     *
     *  ResultCode          | Description
     *  --------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
     *  Bad_MethodInvalid   | The method id does not refer to a method for the specified object. The MethodId provided does not correspond to the ObjectId provided.
     *  Bad_EventIdUnknown  | The specified EventId is not known to the Server.
     *  Bad_NodeIdUnknown   | The node id refers to a node that does not exist in the server address space. Used to indicate that the specified Object is not valid or that the method was called on the ConditionType Node.
     */
    virtual UaStatus AddComment(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        UaByteString& EventId /**<[in] The identifier for the event to comment. */,
        const UaLocalizedText& Comment /**<[in] The comment to add to the condition. */) = 0;

    /**
     *  Changes a Condition instance to the Disabled state.
     *
     *  Normally, the NodeId of the object instance as the ObjectId is passed to the
     *  Call Service. However, some Servers do not expose Condition instances in the
     *  AddressSpace. Therefore all Servers shall allow Clients to call the Disable
     *  method by specifying ConditionId as the ObjectId. The method cannot be called
     *  with an ObjectId of the ConditionType node.
     *
     *  <b>Method Result Codes</b>
     *
     *  ResultCode                    | Description
     *  ------------------------------|----------------------------------------------
     *  Bad_ConditionAlreadyDisabled  | The addressed Condition is already disabled.
     */
    virtual UaStatus Disable(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/) = 0;

    /**
     *  Changes a Condition instance to the enabled state.
     *
     *  Normally, the NodeId of the object instance as the ObjectId is passed to the
     *  Call Service. However, some Servers do not expose Condition instances in the
     *  AddressSpace. Therefore all Servers shall allow Clients to call the Enable
     *  method by specifying ConditionId as the ObjectId. The method cannot be called
     *  with an ObjectId of the ConditionType Node. If the condition instance is not
     *  exposed, it may be difficult for a Client to determine the ConditionId for a
     *  disabled condition.
     *
     *  <b>Method Result Codes</b>
     *
     *  ResultCode                   | Description
     *  -----------------------------|---------------------------------------------
     *  Bad_ConditionAlreadyEnabled  | The addressed Condition is already enabled.
     */
    virtual UaStatus Enable(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/) = 0;

    // BranchId
    virtual void setBranchId(const UaNodeId& BranchId);
    virtual UaNodeId getBranchId() const;
    virtual void setBranchIdStatus(OpcUa_StatusCode status);
    virtual void getBranchIdValue(Session* pSession, UaVariant& value);
    // ClientUserId
    virtual void setClientUserId(const UaString& ClientUserId);
    virtual UaString getClientUserId() const;
    virtual void setClientUserIdStatus(OpcUa_StatusCode status);
    virtual void getClientUserIdValue(Session* pSession, UaVariant& value);
    // Comment
    virtual void setComment(const UaLocalizedText& Comment);
    virtual UaLocalizedText getComment(Session* pSession) const;
    virtual void setCommentStatus(OpcUa_StatusCode status);
    virtual void getCommentValue(Session* pSession, UaVariant& value);
    // ConditionClassId
    virtual void setConditionClassId(const UaNodeId& ConditionClassId);
    virtual UaNodeId getConditionClassId() const;
    virtual void setConditionClassIdStatus(OpcUa_StatusCode status);
    virtual void getConditionClassIdValue(Session* pSession, UaVariant& value);
    // ConditionClassName
    virtual void setConditionClassName(const UaLocalizedText& ConditionClassName);
    virtual UaLocalizedText getConditionClassName(Session* pSession) const;
    virtual void setConditionClassNameStatus(OpcUa_StatusCode status);
    virtual void getConditionClassNameValue(Session* pSession, UaVariant& value);
    // ConditionName
    virtual void setConditionName(const UaString& ConditionName);
    virtual UaString getConditionName() const;
    virtual void setConditionNameStatus(OpcUa_StatusCode status);
    virtual void getConditionNameValue(Session* pSession, UaVariant& value);
    // EnabledState
    virtual void setEnabledState(OpcUa_Boolean enabledState);
    virtual OpcUa_Boolean getEnabledStateBool();
    virtual UaLocalizedText getEnabledState();
    virtual void setEnabledStateStatus(OpcUa_StatusCode status);
    virtual void getEnabledStateValue(Session* pSession, UaVariant& value);
    virtual void getEnabledState_EffectiveDisplayNameValue(Session* pSession, OpcUa_Variant& value);
    // LastSeverity
    virtual void setLastSeverity(OpcUa_UInt16 LastSeverity);
    virtual OpcUa_UInt16 getLastSeverity() const;
    virtual void setLastSeverityStatus(OpcUa_StatusCode status);
    virtual void getLastSeverityValue(Session* pSession, UaVariant& value);
    // Quality
    virtual void setQuality(OpcUa_StatusCode Quality);
    virtual OpcUa_StatusCode getQuality() const;
    virtual void setQualityStatus(OpcUa_StatusCode status);
    virtual void getQualityValue(Session* pSession, UaVariant& value);
    // Retain
    virtual void setRetain(OpcUa_Boolean Retain);
    virtual OpcUa_Boolean getRetain() const;
    virtual void setRetainStatus(OpcUa_StatusCode status);
    virtual void getRetainValue(Session* pSession, UaVariant& value);

    virtual OpcUa::PropertyType* getBranchIdNode();
    virtual OpcUa::PropertyType* getClientUserIdNode();
    virtual OpcUa::ConditionVariableType* getCommentNode();
    virtual OpcUa::PropertyType* getConditionClassIdNode();
    virtual OpcUa::PropertyType* getConditionClassNameNode();
    virtual OpcUa::PropertyType* getConditionNameNode();
    virtual OpcUa::TwoStateVariableType* getEnabledStateNode();
    virtual OpcUa::ConditionVariableType* getLastSeverityNode();
    virtual OpcUa::ConditionVariableType* getQualityNode();
    virtual OpcUa::PropertyType* getRetainNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(ConditionTypeBase *pInstance);

    virtual UaStatus triggerEvent(
        const UaDateTime&   time,
        const UaDateTime&   receiveTime,
        const UaByteString& eventId);

    virtual void getConditionTypeOptionalFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

protected:
    // Variable nodes
    // Variable BranchId
    static OpcUa::PropertyType*  s_pBranchId;
    OpcUa::PropertyType*  m_pBranchId;
    // Variable ClientUserId
    static OpcUa::PropertyType*  s_pClientUserId;
    OpcUa::PropertyType*  m_pClientUserId;
    // Variable Comment
    static OpcUa::ConditionVariableType*  s_pComment;
    OpcUa::ConditionVariableType*  m_pComment;
    // Variable ConditionClassId
    static OpcUa::PropertyType*  s_pConditionClassId;
    OpcUa::PropertyType*  m_pConditionClassId;
    // Variable ConditionClassName
    static OpcUa::PropertyType*  s_pConditionClassName;
    OpcUa::PropertyType*  m_pConditionClassName;
    // Variable ConditionName
    static OpcUa::PropertyType*  s_pConditionName;
    OpcUa::PropertyType*  m_pConditionName;
    // Variable EnabledState
    static OpcUa::TwoStateVariableType*  s_pEnabledState;
    OpcUa::TwoStateVariableType*  m_pEnabledState;
    // Variable LastSeverity
    static OpcUa::ConditionVariableType*  s_pLastSeverity;
    OpcUa::ConditionVariableType*  m_pLastSeverity;
    // Variable Quality
    static OpcUa::ConditionVariableType*  s_pQuality;
    OpcUa::ConditionVariableType*  m_pQuality;
    // Variable Retain
    static OpcUa::PropertyType*  s_pRetain;
    OpcUa::PropertyType*  m_pRetain;


    // Method AddComment
    static OpcUa::BaseMethod* s_pAddCommentMethod;
    // Method ConditionRefresh
    static OpcUa::BaseMethod* s_pConditionRefreshMethod;
    // Method ConditionRefresh2
    static OpcUa::BaseMethod* s_pConditionRefresh2Method;
    // Method Disable
    static OpcUa::BaseMethod* s_pDisableMethod;
    // Method Enable
    static OpcUa::BaseMethod* s_pEnableMethod;

private:
    void initialize();
    void createChildren();

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_ConditionTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUACONDITIONTYPEBASE_H__

