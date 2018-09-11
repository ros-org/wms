/******************************************************************************
** opcua_exclusivelimitstatemachinetype.h
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
#ifndef __OPCUA_EXCLUSIVELIMITSTATEMACHINETYPE_H__
#define __OPCUA_EXCLUSIVELIMITSTATEMACHINETYPE_H__

#include "opcua_finitestatemachinetype.h"
#include "opcua_identifiers.h"
#include "basenodes.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;
class StateType;
class TransitionType;

/** @brief Class implementing the UaObject interface for the ExclusiveLimitStateMachineType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Object members of the ExclusiveLimitStateMachineType:**
 *
 *  Browse Name    | TypeDefinition | Modelling Rule | See Also
 *  ---------------|----------------|----------------|---------
 *  High           | StateType      | None           | &nbsp;
 *  HighHigh       | StateType      | None           | &nbsp;
 *  HighHighToHigh | TransitionType | None           | &nbsp;
 *  HighToHighHigh | TransitionType | None           | &nbsp;
 *  Low            | StateType      | None           | &nbsp;
 *  LowLow         | StateType      | None           | &nbsp;
 *  LowLowToLow    | TransitionType | None           | &nbsp;
 *  LowToLowLow    | TransitionType | None           | &nbsp;
 *
 *  Defines the state machine used by AlarmTypes that handle multiple mutually
 *  exclusive limits.
 *
 *  It is created by extending the FiniteStateMachineType.
 *
 *  The ExclusiveLimitStateMachine defines the sub state machine that represents
 *  the actual level of a multilevel Alarm when it is in the Active state. The sub
 *  state machine defined here includes High, Low, HighHigh and LowLow states. This
 *  model also includes in its transition state a series of transitions to and from
 *  a parent state, the inactive state. This state machine as it is defined shall
 *  be used as a sub state machine for a state machine which has an Active state.
 *  This Active state could be part of a “level” Alarm or “deviation” Alarm or any
 *  other Alarm state machine.
 *
 *  The LowLow, Low, High, HighHigh are typical for many industries. Vendors can
 *  introduce substate models that include additional limits; they may also omit
 *  limits in an instance.
 *
 *  See also \ref Doc_OpcUa_ExclusiveLimitStateMachineType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT ExclusiveLimitStateMachineType:
    public OpcUa::FiniteStateMachineType
{
    UA_DISABLE_COPY(ExclusiveLimitStateMachineType);
protected:
    virtual ~ExclusiveLimitStateMachineType();
public:
    /** This enumaration indicates the state of the exclusice limit state machine.
    */
    enum ExclusiveState
    {
        Disabled,  /*!< The sub state machine is not enabled */
        HighHigh,  /*!< HighHigh state */
        High,      /*!< High state */
        Low,       /*!< Low state */
        LowLow     /*!< LowLow state */
    };

    // construction / destruction
    ExclusiveLimitStateMachineType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    ExclusiveLimitStateMachineType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    ExclusiveLimitStateMachineType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;

    void setExclusiveState(ExclusiveState state);
    ExclusiveState getExclusiveState();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(ExclusiveLimitStateMachineType *pInstance);

protected:
    // Object High
    static OpcUa::StateType*  s_pHigh;
    // Object HighHigh
    static OpcUa::StateType*  s_pHighHigh;
    // Object HighHighToHigh
    static OpcUa::TransitionType*  s_pHighHighToHigh;
    // Object HighToHighHigh
    static OpcUa::TransitionType*  s_pHighToHighHigh;
    // Object Low
    static OpcUa::StateType*  s_pLow;
    // Object LowLow
    static OpcUa::StateType*  s_pLowLow;
    // Object LowLowToLow
    static OpcUa::TransitionType*  s_pLowLowToLow;
    // Object LowToLowLow
    static OpcUa::TransitionType*  s_pLowToLowLow;

private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUAEXCLUSIVELIMITSTATEMACHINETYPE_H__

