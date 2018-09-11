/******************************************************************************
** opcua_shelvedstatemachinetype.h
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

#ifndef __OPCUA_SHELVEDSTATEMACHINETYPE_H__
#define __OPCUA_SHELVEDSTATEMACHINETYPE_H__

#include "opcua_shelvedstatemachinetypebase.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class AlarmConditionType;

/** @brief Class implementing the UaObject interface for the ShelvedStateMachineType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
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
 *  -------------|----------|----------------|----------------|-----------------------------------------------------------------------------------------------------------------------------------------
 *  UnshelveTime | Duration | PropertyType   | Mandatory      | \ref ShelvedStateMachineTypeBase::getUnshelveTime "getUnshelveTime", \ref ShelvedStateMachineTypeBase::setUnshelveTime "setUnshelveTime"
 *
 *  **Method members of the ShelvedStateMachineType:**
 *
 *  Browse Name        | Modelling Rule
 *  -------------------|---------------
 *  \ref OneShotShelve | Mandatory
 *  \ref TimedShelve   | Mandatory
 *  \ref Unshelve      | Mandatory
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
 *  <!-- All but two transitions are caused by Method calls as illustrated in
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
 *  three Methods: \ref OpcUa::ShelvedStateMachineType::TimedShelve "TimedShelve",
 *  \ref OpcUa::ShelvedStateMachineType::OneShotShelve "OneShotShelve" and \ref
 *  OpcUa::ShelvedStateMachineType::Unshelve "Unshelve".
 *
 *  See also \ref Doc_OpcUa_ShelvedStateMachineType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT ShelvedStateMachineType:
    public ShelvedStateMachineTypeBase
{
    UA_DISABLE_COPY(ShelvedStateMachineType);
protected:
    // destruction
    virtual ~ShelvedStateMachineType();
public:
    // construction
    ShelvedStateMachineType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    ShelvedStateMachineType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    ShelvedStateMachineType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    // UaShelvedStateMachineType method OneShotShelve
    virtual UaStatus OneShotShelve(
        const ServiceContext& serviceContext);
    // UaShelvedStateMachineType method TimedShelve
    virtual UaStatus TimedShelve(
        const ServiceContext& serviceContext,
        OpcUa_Double ShelvingTime);
    // UaShelvedStateMachineType method Unshelve
    virtual UaStatus Unshelve(
        const ServiceContext& serviceContext);

    void setCondition(AlarmConditionType* pAlarmCondition);
protected:

private:
    AlarmConditionType* m_pAlarmCondition;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUASHELVEDSTATEMACHINETYPE_H__

