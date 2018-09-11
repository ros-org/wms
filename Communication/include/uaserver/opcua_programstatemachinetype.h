/******************************************************************************
** opcua_programstatemachinetype.h
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

#ifndef __OPCUA_PROGRAMSTATEMACHINETYPE_H__
#define __OPCUA_PROGRAMSTATEMACHINETYPE_H__

#include "opcua_programstatemachinetypebase.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

/** Callback interface for handling incoming Program Method calls
 */
class SERVER_CORE_EXPORT ProgramStateMachineCallback
{
public:
    ProgramStateMachineCallback(){}
    virtual ~ProgramStateMachineCallback(){}

    /** Method used to to halt a program
     * Causes the Program to transition from the Ready, Running or Suspended state to the Halted state.
     */
    virtual UaStatus halt(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/) = 0;

    /** Method used to to reset a program
     * Causes the Program to transition from the Halted state to the Ready state.
     */
    virtual UaStatus reset(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/) = 0;

    /** Method used to to resume a program
     * Causes the Program to transition from the Suspended state to the Running state.
     */
    virtual UaStatus resume(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/) = 0;

    /** Method used to to start a program
     * Causes the Program to transition from the Ready state to the Running state.
     */
    virtual UaStatus start(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/) = 0;

    /** Method used to to suspend a program
     * Causes the Program to transition from the Running state to the Suspended state.
     */
    virtual UaStatus suspend(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/) = 0;
};


/** @brief Class implementing the UaObject interface for the ProgramStateMachineType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Object members of the ProgramStateMachineType:**
 *
 *  Browse Name        | TypeDefinition | Modelling Rule | See Also
 *  -------------------|----------------|----------------|--------------------------------------------------------------------------
 *  FinalResultData    | BaseObjectType | Optional       | \ref ProgramStateMachineTypeBase::getFinalResultData "getFinalResultData"
 *  Halted             | StateType      | None           | &nbsp;
 *  HaltedToReady      | TransitionType | None           | &nbsp;
 *  Ready              | StateType      | None           | &nbsp;
 *  ReadyToHalted      | TransitionType | None           | &nbsp;
 *  ReadyToRunning     | TransitionType | None           | &nbsp;
 *  Running            | StateType      | None           | &nbsp;
 *  RunningToHalted    | TransitionType | None           | &nbsp;
 *  RunningToReady     | TransitionType | None           | &nbsp;
 *  RunningToSuspended | TransitionType | None           | &nbsp;
 *  Suspended          | StateType      | None           | &nbsp;
 *  SuspendedToHalted  | TransitionType | None           | &nbsp;
 *  SuspendedToReady   | TransitionType | None           | &nbsp;
 *  SuspendedToRunning | TransitionType | None           | &nbsp;
 *
 *  **Variable members of the ProgramStateMachineType:**
 *
 *  Browse Name        | DataType                  | TypeDefinition               | Modelling Rule  | See Also
 *  -------------------|---------------------------|------------------------------|-----------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------
 *  AutoDelete         | Boolean                   | PropertyType                 | Mandatory       | &nbsp;
 *  Creatable          | Boolean                   | PropertyType                 | None            | &nbsp;
 *  CurrentState       | LocalizedText             | FiniteStateVariableType      | Mandatory       | \ref ProgramStateMachineTypeBase::getCurrentState "getCurrentState", \ref ProgramStateMachineTypeBase::setCurrentState "setCurrentState"
 *  Deletable          | Boolean                   | PropertyType                 | Mandatory       | \ref ProgramStateMachineTypeBase::getDeletable "getDeletable", \ref ProgramStateMachineTypeBase::setDeletable "setDeletable"
 *  InstanceCount      | UInt32                    | PropertyType                 | None            | &nbsp;
 *  LastTransition     | LocalizedText             | FiniteTransitionVariableType | Mandatory       | \ref ProgramStateMachineTypeBase::getLastTransition "getLastTransition", \ref ProgramStateMachineTypeBase::setLastTransition "setLastTransition"
 *  MaxInstanceCount   | UInt32                    | PropertyType                 | None            | &nbsp;
 *  MaxRecycleCount    | UInt32                    | PropertyType                 | None            | &nbsp;
 *  ProgramDiagnostics | ProgramDiagnosticDataType | ProgramDiagnosticType        | Optional        | \ref ProgramStateMachineTypeBase::getProgramDiagnostics "getProgramDiagnostics", \ref ProgramStateMachineTypeBase::setProgramDiagnostics "setProgramDiagnostics"
 *  RecycleCount       | Int32                     | PropertyType                 | Mandatory       | \ref ProgramStateMachineTypeBase::getRecycleCount "getRecycleCount", \ref ProgramStateMachineTypeBase::setRecycleCount "setRecycleCount"
 *
 *  **Method members of the ProgramStateMachineType:**
 *
 *  Browse Name                | Modelling Rule
 *  ---------------------------|---------------
 *  \ref baseHalt "Halt"       | Mandatory
 *  \ref baseReset "Reset"     | Mandatory
 *  \ref baseResume "Resume"   | Mandatory
 *  \ref baseStart "Start"     | Mandatory
 *  \ref baseSuspend "Suspend" | Mandatory
 *
 */
class SERVER_CORE_EXPORT ProgramStateMachineType:
    public ProgramStateMachineTypeBase
{
    UA_DISABLE_COPY(ProgramStateMachineType);
protected:
    // destruction
    virtual ~ProgramStateMachineType();
public:
    // construction
    ProgramStateMachineType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    ProgramStateMachineType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    ProgramStateMachineType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    // UaProgramStateMachineType method Halt
    virtual UaStatus baseHalt(
        const ServiceContext& serviceContext);
    // UaProgramStateMachineType method Reset
    virtual UaStatus baseReset(
        const ServiceContext& serviceContext);
    // UaProgramStateMachineType method Resume
    virtual UaStatus baseResume(
        const ServiceContext& serviceContext);
    // UaProgramStateMachineType method Start
    virtual UaStatus baseStart(
        const ServiceContext& serviceContext);
    // UaProgramStateMachineType method Suspend
    virtual UaStatus baseSuspend(
        const ServiceContext& serviceContext);

    void setCallback(ProgramStateMachineCallback* pCallback);

protected:

private:
    ProgramStateMachineCallback* m_pCallback;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUAPROGRAMSTATEMACHINETYPE_H__

