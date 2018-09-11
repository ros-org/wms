/******************************************************************************
** opcua_serverconfigurationtype.h
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

#ifndef __OPCUA_SERVERCONFIGURATIONTYPE_H__
#define __OPCUA_SERVERCONFIGURATIONTYPE_H__

#include "opcua_serverconfigurationtypebase.h"
#include "serverconfig.h"
#include "servermanager.h"
#include <map>

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {


class SERVER_CORE_EXPORT ServerConfigurationChanges
{
    UA_DISABLE_COPY(ServerConfigurationChanges);
public:
    ServerConfigurationChanges();
    ~ServerConfigurationChanges();

    void setCertificateConfiguration(CertificateConfiguration* pCertificateConfiguration);
    inline CertificateConfiguration* pCertificateConfiguration() const { return m_pCertificateConfiguration; }

    bool              m_isNewPrivateKey;
    bool              m_isChangeComplete;
    UaByteString      m_privateKey;
    UaByteString      m_certificate;
    UaByteStringArray m_issuerCertificates;
    UaNodeId          m_certificateType;

private:
    CertificateConfiguration* m_pCertificateConfiguration;
};

/** @brief Class implementing the UaObject interface for the ServerConfigurationType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Object members of the ServerConfigurationType:**
 *
 *  Browse Name       | TypeDefinition             | Modelling Rule | See Also
 *  ------------------|----------------------------|----------------|------------------------------------------------------------------------------
 *  CertificateGroups | CertificateGroupFolderType | Mandatory      | \ref ServerConfigurationTypeBase::getCertificateGroups "getCertificateGroups"
 *
 *  **Variable members of the ServerConfigurationType:**
 *
 *  Browse Name                | DataType | TypeDefinition | Modelling Rule | See Also
 *  ---------------------------|----------|----------------|----------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *  MaxTrustListSize           | UInt32   | PropertyType   | Mandatory      | \ref ServerConfigurationTypeBase::getMaxTrustListSize "getMaxTrustListSize", \ref ServerConfigurationTypeBase::setMaxTrustListSize "setMaxTrustListSize"
 *  MulticastDnsEnabled        | Boolean  | PropertyType   | Mandatory      | \ref ServerConfigurationTypeBase::getMulticastDnsEnabled "getMulticastDnsEnabled", \ref ServerConfigurationTypeBase::setMulticastDnsEnabled "setMulticastDnsEnabled"
 *  ServerCapabilities         | String   | PropertyType   | Mandatory      | \ref ServerConfigurationTypeBase::getServerCapabilities "getServerCapabilities", \ref ServerConfigurationTypeBase::setServerCapabilities "setServerCapabilities"
 *  SupportedPrivateKeyFormats | String   | PropertyType   | Mandatory      | \ref ServerConfigurationTypeBase::getSupportedPrivateKeyFormats "getSupportedPrivateKeyFormats", \ref ServerConfigurationTypeBase::setSupportedPrivateKeyFormats "setSupportedPrivateKeyFormats"
 *
 *  **Method members of the ServerConfigurationType:**
 *
 *  Browse Name               | Modelling Rule
 *  --------------------------|---------------
 *  \ref ApplyChanges         | Mandatory
 *  \ref CreateSigningRequest | Mandatory
 *  \ref GetRejectedList      | Mandatory
 *  \ref UpdateCertificate    | Mandatory
 *
 *  This type defines an ObjectType which represents the configuration of a Server
 *  which supports Push Management.
 *
 *  There is always exactly one instance in the Server address space.
 *
 *  See also \ref Doc_OpcUa_ServerConfigurationType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT ServerConfigurationType:
    public ServerConfigurationTypeBase
{
    UA_DISABLE_COPY(ServerConfigurationType);
protected:
    // destruction
    virtual ~ServerConfigurationType();
public:
    // construction
    ServerConfigurationType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    ServerConfigurationType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    ServerConfigurationType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();
    void initialize();

    void setCertificateStoreConfiguration(
        const UaString& sServerRejectedList,
        const CertificateStoreConfigurationPArray& certificateStores,
        NodeAccessInfo* pAccessInfoSecurityAdmin,
        CertificateStoreConfiguration* pUserCertificateStore);

    // UaServerConfigurationType method ApplyChanges
    virtual UaStatus ApplyChanges(
        const ServiceContext& serviceContext);
    // UaServerConfigurationType method CreateSigningRequest
    virtual UaStatus CreateSigningRequest(
        const ServiceContext& serviceContext,
        const UaNodeId& CertificateGroupId,
        const UaNodeId& CertificateTypeId,
        const UaString& SubjectName,
        OpcUa_Boolean RegeneratePrivateKey,
        UaByteString& Nonce,
        UaByteString& CertificateRequest);
    // UaServerConfigurationType method GetRejectedList
    virtual UaStatus GetRejectedList(
        const ServiceContext& serviceContext,
        UaByteStringArray& Certificates);
    // UaServerConfigurationType method UpdateCertificate
    virtual UaStatus UpdateCertificate(
        const ServiceContext& serviceContext,
        const UaNodeId& CertificateGroupId,
        const UaNodeId& CertificateTypeId,
        UaByteString& Certificate,
        const UaByteStringArray& IssuerCertificates,
        const UaString& PrivateKeyFormat,
        UaByteString& PrivateKey,
        OpcUa_Boolean& ApplyChangesRequired);

    void resetConfigCallActive();
    void setAccessInfoAdminRecursive(NodeAccessInfo* pAccessInfo);
    void setAccessInfoVisibleChildren(NodeAccessInfo* pAccessInfo);
protected:

private:
    UaString                                        m_sServerRejectedList;
    CertificateStoreConfigurationPArray             m_certificateStores;
    std::map<UaNodeId, ServerConfigurationChanges*> m_mapConfigChanges;
    bool                                            m_isConfigCallActive;
    ServerManager*                                  m_pServerManager;

    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUASERVERCONFIGURATIONTYPE_H__

