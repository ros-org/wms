/******************************************************************************
** opcua_programstatemachinetypebase.h
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

#ifndef __OPCUA_PROGRAMSTATEMACHINETYPEBASE_H__
#define __OPCUA_PROGRAMSTATEMACHINETYPEBASE_H__

#include "opcua_finitestatemachinetype.h"
#include "basenodes.h"
#include "opcua_finitestatevariabletype.h"
#include "opcua_finitetransitionvariabletype.h"
#include "opcua_identifiers.h"
#include "opcua_propertytype.h"
#include "uaargument.h"
#include "uaprogramdiagnosticdatatype.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class BaseObjectType;
class ProgramDiagnosticType;
class PropertyType;
class StateType;
class TransitionType;

/** Generated base class for a ProgramStateMachineType.
 *
 *  This class contains the generated base code for the object type ProgramStateMachineType
 *  representing an OPC UA ObjectType. This class is used to create the object type and to
 *  create and represent instances of the object type in the server address space.
 *
 *  **Object members of the ProgramStateMachineType:**
 *
 *  Browse Name        | TypeDefinition | Modelling Rule | See Also
 *  -------------------|----------------|----------------|------------------------
 *  FinalResultData    | BaseObjectType | Optional       | \ref getFinalResultData
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
 *  Browse Name        | DataType                  | TypeDefinition        | Modelling Rule  | See Also
 *  -------------------|---------------------------|-----------------------|-----------------|-------------------------------------------------------
 *  AutoDelete         | Boolean                   | PropertyType          | MandatoryShared | &nbsp;
 *  Creatable          | Boolean                   | PropertyType          | None            | &nbsp;
 *  Deletable          | Boolean                   | PropertyType          | Mandatory       | \ref getDeletable, \ref setDeletable
 *  InstanceCount      | UInt32                    | PropertyType          | None            | &nbsp;
 *  MaxInstanceCount   | UInt32                    | PropertyType          | None            | &nbsp;
 *  MaxRecycleCount    | UInt32                    | PropertyType          | None            | &nbsp;
 *  ProgramDiagnostics | ProgramDiagnosticDataType | ProgramDiagnosticType | Optional        | \ref getProgramDiagnostics, \ref setProgramDiagnostics
 *  RecycleCount       | Int32                     | PropertyType          | Mandatory       | \ref getRecycleCount, \ref setRecycleCount
 *
 */
class SERVER_CORE_EXPORT ProgramStateMachineTypeBase:
    public OpcUa::FiniteStateMachineType
{
    UA_DISABLE_COPY(ProgramStateMachineTypeBase);
protected:
    virtual ~ProgramStateMachineTypeBase();
public:
    enum ProgramState
    {
        Halted,
        Ready,
        Running,
        Suspended
    };

    // construction / destruction
    ProgramStateMachineTypeBase(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    ProgramStateMachineTypeBase(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    ProgramStateMachineTypeBase(
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

    /** Method used to to halt a program
     *
     * Causes the Program to transition from the Ready, Running or Suspended state to the Halted state.
     *
     * The method name prefix 'base' is used to avoid naming conflicts if derived types override the
     * methods to add arguments.
     */
    virtual UaStatus baseHalt(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/) = 0;

    /** Method used to to reset a program
     *
     * Causes the Program to transition from the Halted state to the Ready state.
     *
     * The method name prefix 'base' is used to avoid naming conflicts if derived types override the
     * methods to add arguments.
     */
    virtual UaStatus baseReset(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/) = 0;

    /** Method used to to resume a program
     *
     * Causes the Program to transition from the Suspended state to the Running state.
     *
     * The method name prefix 'base' is used to avoid naming conflicts if derived types override the
     * methods to add arguments.
     */
    virtual UaStatus baseResume(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/) = 0;

    /** Method used to to start a program
     *
     * Causes the Program to transition from the Ready state to the Running state.
     *
     * The method name prefix 'base' is used to avoid naming conflicts if derived types override the
     * methods to add arguments.
     */
    virtual UaStatus baseStart(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/) = 0;

    /** Method used to to suspend a program
     *
     * Causes the Program to transition from the Running state to the Suspended state.
     *
     * The method name prefix 'base' is used to avoid naming conflicts if derived types override the
     * methods to add arguments.
     */
    virtual UaStatus baseSuspend(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/) = 0;



    // CurrentState defined by base type

    virtual void setDeletable(OpcUa_Boolean Deletable);
    virtual OpcUa_Boolean getDeletable() const;


    // LastTransition defined by base type



    virtual void setProgramDiagnostics(const UaProgramDiagnosticDataType& ProgramDiagnostics);
    virtual UaProgramDiagnosticDataType getProgramDiagnostics() const;

    virtual void setRecycleCount(OpcUa_Int32 RecycleCount);
    virtual OpcUa_Int32 getRecycleCount() const;

    virtual OpcUa::PropertyType* getDeletableNode();
    virtual const OpcUa::PropertyType* getDeletableNode() const;
    virtual OpcUa::BaseObjectType* getFinalResultData();
    virtual const OpcUa::BaseObjectType* getFinalResultData() const;
    virtual OpcUa::ProgramDiagnosticType* getProgramDiagnosticsNode();
    virtual const OpcUa::ProgramDiagnosticType* getProgramDiagnosticsNode() const;
    virtual OpcUa::PropertyType* getRecycleCountNode();
    virtual const OpcUa::PropertyType* getRecycleCountNode() const;
    virtual OpcUa::BaseMethod* getHalt();
    virtual const OpcUa::BaseMethod* getHalt() const;
    virtual OpcUa::BaseMethod* getReset();
    virtual const OpcUa::BaseMethod* getReset() const;
    virtual OpcUa::BaseMethod* getResume();
    virtual const OpcUa::BaseMethod* getResume() const;
    virtual OpcUa::BaseMethod* getStart();
    virtual const OpcUa::BaseMethod* getStart() const;
    virtual OpcUa::BaseMethod* getSuspend();
    virtual const OpcUa::BaseMethod* getSuspend() const;

    UaStatus setProgramState(ProgramState state);
    ProgramState getProgramState();
    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(ProgramStateMachineTypeBase *pInstance);

protected:
    // Object nodes
    // Object FinalResultData
    static OpcUa::BaseObjectType*  s_pFinalResultData;
    OpcUa::BaseObjectType*  m_pFinalResultData;
    // Object Halted
    static OpcUa::StateType*  s_pHalted;
    // Object HaltedToReady
    static OpcUa::TransitionType*  s_pHaltedToReady;
    // Object Ready
    static OpcUa::StateType*  s_pReady;
    // Object ReadyToHalted
    static OpcUa::TransitionType*  s_pReadyToHalted;
    // Object ReadyToRunning
    static OpcUa::TransitionType*  s_pReadyToRunning;
    // Object Running
    static OpcUa::StateType*  s_pRunning;
    // Object RunningToHalted
    static OpcUa::TransitionType*  s_pRunningToHalted;
    // Object RunningToReady
    static OpcUa::TransitionType*  s_pRunningToReady;
    // Object RunningToSuspended
    static OpcUa::TransitionType*  s_pRunningToSuspended;
    // Object Suspended
    static OpcUa::StateType*  s_pSuspended;
    // Object SuspendedToHalted
    static OpcUa::TransitionType*  s_pSuspendedToHalted;
    // Object SuspendedToReady
    static OpcUa::TransitionType*  s_pSuspendedToReady;
    // Object SuspendedToRunning
    static OpcUa::TransitionType*  s_pSuspendedToRunning;

    // Variable nodes
    // Variable AutoDelete
    static OpcUa::PropertyType*  s_pAutoDelete;
    // AutoDelete defined by base type
    // Variable Creatable
    static OpcUa::PropertyType*  s_pCreatable;
    // Creatable defined by base type
    // Variable CurrentState
    static OpcUa::FiniteStateVariableType*  s_pCurrentState;
    // CurrentState defined by base type
    // Variable Deletable
    static OpcUa::PropertyType*  s_pDeletable;
    OpcUa::PropertyType*  m_pDeletable;
    // Variable InstanceCount
    static OpcUa::PropertyType*  s_pInstanceCount;
    // InstanceCount defined by base type
    // Variable LastTransition
    static OpcUa::FiniteTransitionVariableType*  s_pLastTransition;
    // LastTransition defined by base type
    // Variable MaxInstanceCount
    static OpcUa::PropertyType*  s_pMaxInstanceCount;
    // MaxInstanceCount defined by base type
    // Variable MaxRecycleCount
    static OpcUa::PropertyType*  s_pMaxRecycleCount;
    // MaxRecycleCount defined by base type
    // Variable ProgramDiagnostics
    static OpcUa::ProgramDiagnosticType*  s_pProgramDiagnostics;
    OpcUa::ProgramDiagnosticType*  m_pProgramDiagnostics;
    // Variable RecycleCount
    static OpcUa::PropertyType*  s_pRecycleCount;
    OpcUa::PropertyType*  m_pRecycleCount;


    // Method nodes
    static OpcUa::BaseMethod* s_pHaltMethod;
    OpcUa::BaseMethod*  m_pHaltMethod;
    static OpcUa::BaseMethod* s_pResetMethod;
    OpcUa::BaseMethod*  m_pResetMethod;
    static OpcUa::BaseMethod* s_pResumeMethod;
    OpcUa::BaseMethod*  m_pResumeMethod;
    static OpcUa::BaseMethod* s_pStartMethod;
    OpcUa::BaseMethod*  m_pStartMethod;
    static OpcUa::BaseMethod* s_pSuspendMethod;
    OpcUa::BaseMethod*  m_pSuspendMethod;


private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUAPROGRAMSTATEMACHINETYPEBASE_H__


