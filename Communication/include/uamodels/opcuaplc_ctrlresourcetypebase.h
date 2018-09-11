/******************************************************************************
** opcuaplc_ctrlresourcetypebase.h
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
** Project: C++ OPC Server SDK information model for namespace http://PLCopen.org/OpcUa/IEC61131-3/
**
** Description: OPC Unified Architecture Software Development Kit.
**
******************************************************************************/

#ifndef __OPCUAPLC_CTRLRESOURCETYPEBASE_H__
#define __OPCUAPLC_CTRLRESOURCETYPEBASE_H__

#include "opcuadi_devicetype.h"
#include "opcuaplc_datatypes.h"
#include "basenodes.h"
#include "opcua_baseobjecttype.h"
#include "opcua_foldertype.h"
#include "opcuadi_configurableobjecttype.h"
#include "opcuadi_functionalgrouptype.h"
#include "opcuaplc_identifiers.h"
#include "opcuaplc_instancefactory_plcopen.h"

// Namespace for the UA information model http://PLCopen.org/OpcUa/IEC61131-3/
namespace OpcUaPlc {


/** Generated base class for a CtrlResourceType.
 *
 *  This class contains the generated base code for the object type CtrlResourceType
 *  representing an OPC UA ObjectType. This class is used to create the object type and to
 *  create and represent instances of the object type in the server address space.
 *
 *  **Object members of the CtrlResourceType:**
 *
 *  Browse Name   | TypeDefinition         | Modelling Rule | See Also
 *  --------------|------------------------|----------------|----------------------
 *  Configuration | FunctionalGroupType    | Optional       | \ref getConfiguration
 *  Diagnostic    | FunctionalGroupType    | Optional       | \ref getDiagnostic
 *  GlobalVars    | FunctionalGroupType    | Optional       | \ref getGlobalVars
 *  MethodSet     | BaseObjectType         | Optional       | \ref getMethodSet
 *  Programs      | ConfigurableObjectType | Mandatory      | \ref getPrograms
 *  Tasks         | ConfigurableObjectType | Mandatory      | \ref getTasks
 *
 */
class UAMODELS_EXPORT CtrlResourceTypeBase:
    public OpcUaDi::DeviceType
{
    UA_DISABLE_COPY(CtrlResourceTypeBase);
protected:
    virtual ~CtrlResourceTypeBase();
public:
    // construction / destruction
    CtrlResourceTypeBase(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    CtrlResourceTypeBase(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    CtrlResourceTypeBase(
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

    // CtrlResourceType method Start
    virtual UaStatus MethodSet_Start(const ServiceContext& serviceContext /**<General context for the service calls containing
                                             information like the session object,
                                             return diagnostic mask and timeout hint.*/) = 0;
    // CtrlResourceType method Stop
    virtual UaStatus MethodSet_Stop(const ServiceContext& serviceContext /**<General context for the service calls containing
                                             information like the session object,
                                             return diagnostic mask and timeout hint.*/) = 0;

    virtual OpcUaDi::FunctionalGroupType* getConfiguration();
    virtual OpcUaDi::FunctionalGroupType* getDiagnostic();
    virtual OpcUaDi::FunctionalGroupType* getGlobalVars();
    virtual OpcUa::BaseObjectType* getMethodSet();
    virtual OpcUaDi::ConfigurableObjectType* getPrograms();
    virtual OpcUaDi::ConfigurableObjectType* getTasks();
    virtual OpcUa::BaseMethod* getMethodSet_Start();
    virtual OpcUa::BaseMethod* getMethodSet_Stop();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(CtrlResourceTypeBase *pInstance);

protected:
    // Object nodes
    // Object Configuration
    static OpcUaDi::FunctionalGroupType*  s_pConfiguration;
    OpcUaDi::FunctionalGroupType*  m_pConfiguration;
    // Object Diagnostic
    static OpcUaDi::FunctionalGroupType*  s_pDiagnostic;
    OpcUaDi::FunctionalGroupType*  m_pDiagnostic;
    // Object GlobalVars
    static OpcUaDi::FunctionalGroupType*  s_pGlobalVars;
    OpcUaDi::FunctionalGroupType*  m_pGlobalVars;
    // Object MethodSet
    static OpcUa::BaseObjectType*  s_pMethodSet;
    OpcUa::BaseObjectType*  m_pMethodSet;
    // Object Programs
    static OpcUaDi::ConfigurableObjectType*  s_pPrograms;
    OpcUaDi::ConfigurableObjectType*  m_pPrograms;
    // Object Tasks
    static OpcUaDi::ConfigurableObjectType*  s_pTasks;
    OpcUaDi::ConfigurableObjectType*  m_pTasks;


    static OpcUa::BaseMethod* s_pMethodSet_StartMethod;
    OpcUa::BaseMethod*  m_pMethodSet_StartMethod;
    static OpcUa::BaseMethod* s_pMethodSet_StopMethod;
    OpcUa::BaseMethod*  m_pMethodSet_StopMethod;

private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://PLCopen.org/OpcUa/IEC61131-3/

#endif // #ifndef __OPCUAPLCCTRLRESOURCETYPEBASE_H__


