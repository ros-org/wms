/******************************************************************************
** opcua_shelvedstatemachinetypebase.h
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

#ifndef __OPCUA_SHELVEDSTATEMACHINETYPEBASE_H__
#define __OPCUA_SHELVEDSTATEMACHINETYPEBASE_H__

#include "opcua_finitestatemachinetype.h"
#include "basenodes.h"
#include "opcua_identifiers.h"
#include "opcua_propertytype.h"
#include "uaargument.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;
class StateType;
class TransitionType;

/** Generated base class for a ShelvedStateMachineType.
 *
 *  This class contains the generated base code for the object type ShelvedStateMachineType
 *  representing an OPC UA ObjectType. This class is used to create the object type and to
 *  create and represent instances of the object type in the server address space.
 *
 *  **Object members of the ShelvedStateMachineType:**
 *
 *  Browse Name                  | TypeDefinition | Modelling Rule | See Also
 *  -----------------------------|----------------|----------------|---------
 *  OneShotShelved               | StateType      | None           | &nbsp;
 *  OneShotShelvedToTimedShelved | TransitionType | None           | &nbsp;
 *  OneShotShelvedToUnshelved    | TransitionType | None           | &nbsp;
 *  TimedShelved                 | StateType      | None           | &nbsp;
 *  TimedShelvedToOneShotShelved | TransitionType | None           | &nbsp;
 *  TimedShelvedToUnshelved      | TransitionType | None           | &nbsp;
 *  Unshelved                    | StateType      | None           | &nbsp;
 *  UnshelvedToOneShotShelved    | TransitionType | None           | &nbsp;
 *  UnshelvedToTimedShelved      | TransitionType | None           | &nbsp;
 *
 *  **Variable members of the ShelvedStateMachineType:**
 *
 *  Browse Name  | DataType | TypeDefinition | Modelling Rule | See Also
 *  -------------|----------|----------------|----------------|-------------------------------------------
 *  UnshelveTime | Duration | PropertyType   | Mandatory      | \ref getUnshelveTime, \ref setUnshelveTime
 *
 *  Defines a substate machine that represents an advanced Alarm filtering model.
 *
 *  The state model supports two types of Shelving: OneShotShelving and
 *  TimedShelving.<!-- They are illustrated in Figure 13. --> The illustration
 *  includes the allowed transitions between the various substates. Shelving is an
 *  Operator initiated activity.
 *
 *  In OneShotShelving, a user requests that an Alarm be Shelved for its current
 *  Active state. This type of Shelving is typically used when an Alarm is
 *  continually occurring on a boundary (i.e. a Condition is jumping between High
 *  Alarm and HighHigh Alarm, always in the Active state). The One Shot Shelving
 *  will automatically clear when an Alarm returns to an inactive state. Another
 *  use for this type of Shelving is for a plant area that is shut down i.e. a long
 *  running Alarm such as a low level Alarm for a tank that is not in use. When the
 *  tank starts operation again the Shelving state will automatically clear.
 *
 *  In TimedShelving, a user specifies that an Alarm be shelved for a fixed time
 *  period. This type of Shelving is quite often used to block nuisance Alarms. For
 *  example, an Alarm that occurs more than ten times in a minute may get shelved
 *  for a few minutes.
 *
 *  In all states, the Unshelve can be called to cause a transition to the Unshelve
 *  state; this includes Un-shelving an Alarm that is in the TimedShelve state
 *  before the time has expired and the OneShotShelve state without a transition to
 *  an inactive state.
 *
 *  <!-- All but two transitions are caused by method calls as illustrated in
 *  Figure 13. -->The “Time Expired” transition is simply a system generated
 *  transition that occurs when the time value defined as part of the “Timed
 *  Shelved Call” has expired. The “Any Transition Occurs” transition is also a
 *  system generated transition; this transition is generated when the Condition
 *  goes to an inactive state.
 *
 *  The ShelvedStateMachine includes a hierarchy of substates. It supports all
 *  transitions between Unshelved, OneShotShelved and TimedShelved.
 *
 *  This FiniteStateMachine supports three Active states; Unshelved, TimedShelved
 *  and OneShotShelved. It also supports six transitions.<!-- The states and
 *  transitions are described in Table 32.--> This FiniteStateMachine also supports
 *  three methods: \ref OpcUa::ShelvedStateMachineType::TimedShelve "TimedShelve",
 *  \ref OpcUa::ShelvedStateMachineType::OneShotShelve "OneShotShelve" and \ref
 *  OpcUa::ShelvedStateMachineType::Unshelve "Unshelve".
 *
 *  See also \ref Doc_OpcUa_ShelvedStateMachineType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT ShelvedStateMachineTypeBase:
    public OpcUa::FiniteStateMachineType
{
    UA_DISABLE_COPY(ShelvedStateMachineTypeBase);
protected:
    virtual ~ShelvedStateMachineTypeBase();
public:
    enum ShelvedState
    {
        OneShotShelved,
        TimedShelved,
        Unshelved
    };

    // construction / destruction
    ShelvedStateMachineTypeBase(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    ShelvedStateMachineTypeBase(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    ShelvedStateMachineTypeBase(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;


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
     *  Sets the AlarmCondition to the OneShotShelved state.
     *
     *  Normally, the MethodId found in the Shelving child of the Condition instance
     *  and the NodeId of the Shelving object as the ObjectId are passed to the Call
     *  Service. However, some Servers do not expose Condition instances in the
     *  AddressSpace. Therefore all Servers shall also allow Clients to call the
     *  OneShotShelve method by specifying ConditionId as the ObjectId. The method
     *  cannot be called with an ObjectId of the ShelvedStateMachineType Node.
     *
     *  <b>Method Result Codes</b>
     *
     *  ResultCode                   | Description
     *  -----------------------------|----------------------------------------------------------------------------------------
     *  Bad_ConditionAlreadyShelved  | The Alarm is already in a shelved state. The Alarm is already in OneShotShelved state.
     */
    virtual UaStatus OneShotShelve(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/) = 0;

    /**
     *  Sets the AlarmCondition to the TimedShelved state.
     *
     *  Normally, the MethodId found in the Shelving child of the Condition instance
     *  and the NodeId of the Shelving object as the ObjectId are passed to the Call
     *  Service. However, some Servers do not expose Condition instances in the
     *  AddressSpace. Therefore all Servers shall also allow Clients to call the
     *  TimedShelve method by specifying ConditionId as the ObjectId. The method cannot
     *  be called with an ObjectId of the ShelvedStateMachineType Node.
     *
     *  <b>Method Result Codes</b>
     *
     *  ResultCode                   | Description
     *  -----------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------
     *  Bad_ConditionAlreadyShelved  | The Alarm is already in a shelved state. The Alarm is already in TimedShelved state and the system does not allow a reset of the shelved timer.
     *  Bad_ShelvingTimeOutOfRange   | The provided Shelving time is outside the range allowed by the Server for Shelving.
     */
    virtual UaStatus TimedShelve(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        OpcUa_Double ShelvingTime /**<[in] If not 0, this parameter specifies a fixed time for which the Alarm is to be shelved.. Specifies a fixed time for which the Alarm is to be shelved.
            <br>
            The Server may refuse the provided duration. If a MaxTimeShelved Property exist
            on the Alarm than the Shelving time shall be less than or equal to the value of
            this Property. */) = 0;

    /**
     *  Unshelve sets the AlarmCondition to the Unshelved state.
     *
     *  Normally, the MethodId found in the Shelving child of the Condition instance
     *  and the NodeId of the Shelving object as the ObjectId are passed to the Call
     *  Service. However, some Servers do not expose Condition instances in the
     *  AddressSpace. Therefore all Servers shall also allow Clients to call the
     *  Unshelve method by specifying ConditionId as the ObjectId. The method cannot be
     *  called with an ObjectId of the ShelvedStateMachineType Node.
     *
     *  <b>Method Result Codes:</b>
     *
     *  ResultCode               | Description
     *  -------------------------|--------------------------------------------------
     *  Bad_ConditionNotShelved  | The Alarm is not in the requested shelved state.
     */
    virtual UaStatus Unshelve(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/) = 0;

    virtual void setUnshelveTime(OpcUa_Double UnshelveTime);
    virtual OpcUa_Double getUnshelveTime() const;

    virtual OpcUa::PropertyType* getUnshelveTimeNode();
    virtual OpcUa::BaseMethod* getOneShotShelve();
    virtual OpcUa::BaseMethod* getTimedShelve();
    virtual OpcUa::BaseMethod* getUnshelve();

    UaStatus setShelvedState(ShelvedState state);
    ShelvedState getShelvedState();
    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(ShelvedStateMachineTypeBase *pInstance);

protected:
    // Object nodes
    // Object OneShotShelved
    static OpcUa::StateType*  s_pOneShotShelved;
    // Object OneShotShelvedToTimedShelved
    static OpcUa::TransitionType*  s_pOneShotShelvedToTimedShelved;
    // Object OneShotShelvedToUnshelved
    static OpcUa::TransitionType*  s_pOneShotShelvedToUnshelved;
    // Object TimedShelved
    static OpcUa::StateType*  s_pTimedShelved;
    // Object TimedShelvedToOneShotShelved
    static OpcUa::TransitionType*  s_pTimedShelvedToOneShotShelved;
    // Object TimedShelvedToUnshelved
    static OpcUa::TransitionType*  s_pTimedShelvedToUnshelved;
    // Object Unshelved
    static OpcUa::StateType*  s_pUnshelved;
    // Object UnshelvedToOneShotShelved
    static OpcUa::TransitionType*  s_pUnshelvedToOneShotShelved;
    // Object UnshelvedToTimedShelved
    static OpcUa::TransitionType*  s_pUnshelvedToTimedShelved;

    // Variable nodes
    // Variable UnshelveTime
    static OpcUa::PropertyType*  s_pUnshelveTime;
    OpcUa::PropertyType*  m_pUnshelveTime;


    // Method nodes
    static OpcUa::BaseMethod* s_pOneShotShelveMethod;
    OpcUa::BaseMethod*  m_pOneShotShelveMethod;
    static OpcUa::BaseMethod* s_pTimedShelveMethod;
    OpcUa::BaseMethod*  m_pTimedShelveMethod;
    static OpcUa::BaseMethod* s_pUnshelveMethod;
    OpcUa::BaseMethod*  m_pUnshelveMethod;


private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUASHELVEDSTATEMACHINETYPEBASE_H__


