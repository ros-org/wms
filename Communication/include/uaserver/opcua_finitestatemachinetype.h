/******************************************************************************
** opcua_finitestatemachinetype.h
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
#ifndef __OPCUA_FINITESTATEMACHINETYPE_H__
#define __OPCUA_FINITESTATEMACHINETYPE_H__

#include "opcua_statemachinetype.h"
#include "opcua_baseobjecttype.h"
#include "opcua_identifiers.h"
#include "basenodes.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class FiniteStateVariableType;
class FiniteTransitionVariableType;

/** @brief Class implementing the UaObject interface for the FiniteStateMachineType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Variable members of the FiniteStateMachineType:**
 *
 *  Browse Name    | DataType      | TypeDefinition               | Modelling Rule | See Also
 *  ---------------|---------------|------------------------------|----------------|-----------------------------------------------
 *  CurrentState   | LocalizedText | FiniteStateVariableType      | Mandatory      | \ref getCurrentState, \ref setCurrentState
 *  LastTransition | LocalizedText | FiniteTransitionVariableType | Optional       | \ref getLastTransition, \ref setLastTransition
 *
 *  The FiniteStateMachineType is the base ObjectType for state machines that
 *  explicitly define the possible states and transitions.
 *
 *  Once the states are defined, subtypes shall not add new states.
 *
 *  The states of the machine are represented with instances of the StateType
 *  ObjectType. Each state shall have a BrowseName which is unique within the state
 *  machine and shall have a StateNumber which shall also be unique across all
 *  states defined in the state machine. Be aware that states in a sub-state
 *  machine may have the same StateNumber or BrowseName as states in the parent
 *  machine. A concrete subtype of FiniteStateMachineType shall define at least one
 *  state.
 *
 *  A state machine may define one state which is an instance of the
 *  InitialStateType. This state is the state that the machine goes into when it is
 *  activated.
 *
 *  The transitions that may occur are represented with instances of the
 *  TransitionType. Each transition shall have a BrowseName which is unique within
 *  the state machine and may have a TransitionNumber which shall also be unique
 *  across all transitions defined in the state machine.
 *
 *  The initial state for a transition is a StateType object which is the target of
 *  a FromState reference. The final state for a transition is a StateType object
 *  which is the target of a ToState reference. The FromState and ToState
 *  references shall always be specified.
 *
 *  A transition may produce an event. The event is indicated by a HasEffect
 *  reference to a subtype of BaseEventType. The StateMachineType shall have
 *  GeneratesEvent references to the targets of a HasEffect reference for each of
 *  its transitions.
 *
 *  A FiniteStateMachineType may define methods that cause a transition to occur.
 *  These methods are targets of HasCause references for each of the transitions
 *  that may be triggered by the method. The Executable attribute for a method is
 *  used to indicate whether the current state of the machine allows the method to
 *  be called.
 *
 *  A FiniteStateMachineType may have sub-state machines which are represented as
 *  instances of StateMachineType ObjectTypes. Each state shall have a
 *  HasSubStateMachine reference to the StateMachineType object which represents
 *  the child states. The SubStateMachine is not active if the parent state is not
 *  active. In this case the CurrentState and LastTransition variables of the
 *  sub-state machine shall have a status equal to Bad_StateNotActive.
 *
 */
class SERVER_CORE_EXPORT FiniteStateMachineType:
    public OpcUa::BaseObjectType
{
    UA_DISABLE_COPY(FiniteStateMachineType);
protected:
    virtual ~FiniteStateMachineType();
public:
    // construction / destruction
    FiniteStateMachineType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    FiniteStateMachineType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    FiniteStateMachineType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;

    virtual void setCurrentState(const UaLocalizedText& currentState);
    virtual UaLocalizedText getCurrentState(Session* pSession);

    virtual void setLastTransition(const UaLocalizedText& lastTransition);
    virtual UaLocalizedText getLastTransition(Session* pSession);

    virtual OpcUa::FiniteStateVariableType* getCurrentStateNode();
    virtual OpcUa::FiniteTransitionVariableType* getLastTransitionNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(FiniteStateMachineType *pInstance);

protected:
    // Variable CurrentState
    static OpcUa::FiniteStateVariableType*  s_pCurrentState;
    OpcUa::FiniteStateVariableType*  m_pCurrentState;
    // Variable LastTransition
    static OpcUa::FiniteTransitionVariableType*  s_pLastTransition;
    OpcUa::FiniteTransitionVariableType*  m_pLastTransition;

private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUAFINITESTATEMACHINETYPE_H__

