/******************************************************************************
** opcuadi_topologyelementtypebase.h
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
** Project: C++ OPC Server SDK information model for namespace http://opcfoundation.org/UA/DI/
**
** Description: OPC Unified Architecture Software Development Kit.
**
******************************************************************************/

#ifndef __OPCUADI_TOPOLOGYELEMENTTYPEBASE_H__
#define __OPCUADI_TOPOLOGYELEMENTTYPEBASE_H__

#include "opcua_baseobjecttype.h"
#include "opcuadi_datatypes.h"
#include "basenodes.h"
#include "opcua_basedatavariabletype.h"
#include "opcua_baseobjecttype.h"
#include "opcua_propertytype.h"
#include "opcuadi_identifiers.h"
#include "opcuadi_instancefactory_devices.h"
#include "uaargument.h"

// Namespace for the UA information model http://opcfoundation.org/UA/DI/
namespace OpcUaDi {

class FunctionalGroupType;
class LockingServicesType;

/** Generated base class for a TopologyElementType.
 *
 *  This class contains the generated base code for the object type TopologyElementType
 *  representing an OPC UA ObjectType. This class is used to create the object type and to
 *  create and represent instances of the object type in the server address space.
 *
 *  **Object members of the TopologyElementType:**
 *
 *  Browse Name         | TypeDefinition      | Modelling Rule      | See Also
 *  --------------------|---------------------|---------------------|-----------------------
 *  \<GroupIdentifier\> | FunctionalGroupType | OptionalPlaceholder | &nbsp;
 *  Identification      | FunctionalGroupType | Optional            | \ref getIdentification
 *  Lock                | LockingServicesType | Optional            | \ref getLock
 *  MethodSet           | BaseObjectType      | Optional            | \ref getMethodSet
 *  ParameterSet        | BaseObjectType      | Optional            | \ref getParameterSet
 *
 */
class UAMODELS_EXPORT TopologyElementTypeBase:
    public OpcUa::BaseObjectType
{
    UA_DISABLE_COPY(TopologyElementTypeBase);
protected:
    virtual ~TopologyElementTypeBase();
public:
    // construction / destruction
    TopologyElementTypeBase(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    TopologyElementTypeBase(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    TopologyElementTypeBase(
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


    // <ParameterIdentifier> defined at ParameterSet

    virtual OpcUaDi::FunctionalGroupType* getIdentification();
    virtual OpcUaDi::LockingServicesType* getLock();
    virtual OpcUa::BaseObjectType* getMethodSet();
    virtual OpcUa::BaseObjectType* getParameterSet();

// Add placeholders
    virtual UaStatus addGroup(OpcUaDi::FunctionalGroupType *pGroup);
    virtual UaStatus addParameterSet_Parameter(OpcUa::BaseDataVariableType *pParameter);
    virtual UaStatus addMethodSet_Method(OpcUa::BaseMethod *pMethod);

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(TopologyElementTypeBase *pInstance);

protected:
    // Object nodes
    // Object GroupIdentifier
    static OpcUaDi::FunctionalGroupType*  s_pGroupIdentifier;
    // Object Identification
    static OpcUaDi::FunctionalGroupType*  s_pIdentification;
    OpcUaDi::FunctionalGroupType*  m_pIdentification;
    // Object Lock
    static OpcUaDi::LockingServicesType*  s_pLock;
    OpcUaDi::LockingServicesType*  m_pLock;
    // Object MethodSet
    static OpcUa::BaseObjectType*  s_pMethodSet;
    OpcUa::BaseObjectType*  m_pMethodSet;
    // Object ParameterSet
    static OpcUa::BaseObjectType*  s_pParameterSet;
    OpcUa::BaseObjectType*  m_pParameterSet;

    // Variable ParameterSet ParameterIdentifier
    static OpcUa::BaseDataVariableType* s_pParameterSet_ParameterIdentifier;

    static OpcUa::BaseMethod* s_pMethodSet_MethodIdentifierMethod;

private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/DI/

#endif // #ifndef __OPCUADITOPOLOGYELEMENTTYPEBASE_H__


