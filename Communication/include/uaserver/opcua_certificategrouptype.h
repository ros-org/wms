/******************************************************************************
** opcua_certificategrouptype.h
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

#ifndef __OPCUA_CERTIFICATEGROUPTYPE_H__
#define __OPCUA_CERTIFICATEGROUPTYPE_H__

#include "opcua_baseobjecttype.h"
#include "basenodes.h"
#include "opcua_identifiers.h"
#include "opcua_propertytype.h"
#include "uaargument.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;
class TrustListType;

/** @brief Class implementing the UaObject interface for the CertificateGroupType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Object members of the CertificateGroupType:**
 *
 *  Browse Name | TypeDefinition | Modelling Rule | See Also
 *  ------------|----------------|----------------|------------------
 *  TrustList   | TrustListType  | Mandatory      | \ref getTrustList
 *
 *  **Variable members of the CertificateGroupType:**
 *
 *  Browse Name      | DataType | TypeDefinition | Modelling Rule | See Also
 *  -----------------|----------|----------------|----------------|---------------------------------------------------
 *  CertificateTypes | NodeId   | PropertyType   | Mandatory      | \ref getCertificateTypes, \ref setCertificateTypes
 *
 *  A type used for Objects which represent Certificate Groups in the address
 *  space.
 *
 *  A Certificate Group is a context that contains a Trust List and one or more
 *  Certificates that can be assigned to an Application. This type exists to allow
 *  an Application which has multiple Trust Lists and/or Application Certificates
 *  to express them in its AddressSpace.
 *
 *  The TrustList Object is the Trust List associated with the Certificate Group.
 *
 *  See also \ref Doc_OpcUa_CertificateGroupType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT CertificateGroupType:
    public OpcUa::BaseObjectType
{
    UA_DISABLE_COPY(CertificateGroupType);
protected:
    virtual ~CertificateGroupType();
public:
    // construction / destruction
    CertificateGroupType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    CertificateGroupType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    CertificateGroupType(
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


    virtual void setCertificateTypes(const UaNodeIdArray& CertificateTypes);
    virtual void getCertificateTypes(UaNodeIdArray& CertificateTypes) const;

    virtual OpcUa::PropertyType* getCertificateTypesNode();
    virtual OpcUa::TrustListType* getTrustList();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(CertificateGroupType *pInstance);
    virtual void recursivSetAccessInfo(NodeAccessInfo* pAccessInfo);

protected:
    // Object nodes
    // Object TrustList
    static OpcUa::TrustListType*  s_pTrustList;
    OpcUa::TrustListType*  m_pTrustList;

    // Variable nodes
    // Variable CertificateTypes
    static OpcUa::PropertyType*  s_pCertificateTypes;
    OpcUa::PropertyType*  m_pCertificateTypes;



private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUACERTIFICATEGROUPTYPE_H__


