/******************************************************************************
** opcua_serverconfigurationtypebase.h
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

#ifndef __OPCUA_SERVERCONFIGURATIONTYPEBASE_H__
#define __OPCUA_SERVERCONFIGURATIONTYPEBASE_H__

#include "opcua_baseobjecttype.h"
#include "basenodes.h"
#include "opcua_identifiers.h"
#include "opcua_propertytype.h"
#include "uaargument.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class CertificateGroupFolderType;
class CertificateGroupType;
class PropertyType;

/** Generated base class for a ServerConfigurationType.
 *
 *  This class contains the generated base code for the object type ServerConfigurationType
 *  representing an OPC UA ObjectType. This class is used to create the object type and to
 *  create and represent instances of the object type in the server address space.
 *
 *  **Object members of the ServerConfigurationType:**
 *
 *  Browse Name       | TypeDefinition             | Modelling Rule | See Also
 *  ------------------|----------------------------|----------------|--------------------------
 *  CertificateGroups | CertificateGroupFolderType | Mandatory      | \ref getCertificateGroups
 *
 *  **Variable members of the ServerConfigurationType:**
 *
 *  Browse Name                | DataType | TypeDefinition | Modelling Rule | See Also
 *  ---------------------------|----------|----------------|----------------|-----------------------------------------------------------------------
 *  MaxTrustListSize           | UInt32   | PropertyType   | Mandatory      | \ref getMaxTrustListSize, \ref setMaxTrustListSize
 *  MulticastDnsEnabled        | Boolean  | PropertyType   | Mandatory      | \ref getMulticastDnsEnabled, \ref setMulticastDnsEnabled
 *  ServerCapabilities         | String   | PropertyType   | Mandatory      | \ref getServerCapabilities, \ref setServerCapabilities
 *  SupportedPrivateKeyFormats | String   | PropertyType   | Mandatory      | \ref getSupportedPrivateKeyFormats, \ref setSupportedPrivateKeyFormats
 *
 *  This type defines an ObjectType which represents the configuration of a Server
 *  which supports Push Management.
 *
 *  There is always exactly one instance in the Server address space.
 *
 *  See also \ref Doc_OpcUa_ServerConfigurationType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT ServerConfigurationTypeBase:
    public OpcUa::BaseObjectType
{
    UA_DISABLE_COPY(ServerConfigurationTypeBase);
protected:
    virtual ~ServerConfigurationTypeBase();
public:
    // construction / destruction
    ServerConfigurationTypeBase(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    ServerConfigurationTypeBase(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    ServerConfigurationTypeBase(
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
     *  Used to tell the Server to apply any security changes.
     *
     *  This method should only be called if a previous call to a method that changed
     *  the configuration returns ApplyChangesRequired=true (see \ref
     *  OpcUa::ServerConfigurationType::UpdateCertificate "UpdateCertificate").
     *
     *  ApplyChanges can have different meanings depending on the Server architecture.
     *  In the ideal case it would only require the endpoints to be closed and
     *  reopened. However, it could require a complete Server shutdown and restart.
     *
     *  This method requires an encrypted channel and that the Client provides
     *  credentials with administrative rights on the Server.
     *
     *  <b>Method Result Codes</b>
     *
     *  Result Code           | Description
     *  ----------------------|-----------------------------------------------------
     *  Bad_UserAccessDenied  | The current user does not have the rights required.
     */
    virtual UaStatus ApplyChanges(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/) = 0;

    /**
     *  Asks the Server to create a PKCS #10 DER encoded certificate request that is
     *  signed with the Server’s private key.
     *
     *  This request can be then used to request a certificate from a CA that expects
     *  requests in this format. See <a href="http://www.ietf.org/rfc/rfc2986.txt">RFC
     *  2986 (txt file)</a> for a description of PKCS #10.
     *
     *  This method requires an encrypted channel and that the Client provides
     *  credentials with administrative rights on the Server.
     *
     *  <b>Method Result Codes</b>
     *
     *  Result Code           | Description
     *  ----------------------|------------------------------------------------------------------------
     *  Bad_InvalidArgument   | The CertificateTypeId, certificateGroupId or SubjectName is not valid.
     *  Bad_UserAccessDenied  | The current user does not have the rights required.
     */
    virtual UaStatus CreateSigningRequest(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        const UaNodeId& CertificateGroupId /**<[in] The NodeId of the certificate group object which is affected by the request.
            <br>
            If null, the \ref
            OpcUa::CertificateGroupFolderType::getDefaultApplicationGroup
            "DefaultApplicationGroup" is used. */,
        const UaNodeId& CertificateTypeId /**<[in] The type of certificate being requested.
            <br>
            The set of permitted types is specified by the \ref
            OpcUa::CertificateGroupType::getCertificateTypes "CertificateTypes"
            property belonging to the certificate group. */,
        const UaString& SubjectName /**<[in] The subject name to use in the certificate request.
            <br>
            If not specified, the SubjectName from the current certificate is used. */,
        OpcUa_Boolean RegeneratePrivateKey /**<[in] Flag indicating whether to create a new private key.
            <br>
            If TRUE, the Server shall create a new private key which it stores until the
            matching signed certificate is uploaded with the \ref
            OpcUa::ServerConfigurationType::UpdateCertificate "UpdateCertificate" method.
            Previously created private keys may be discarded if \ref
            OpcUa::ServerConfigurationType::UpdateCertificate "UpdateCertificate" was not
            called before calling this method again. If FALSE, the Server uses its existing
            private key. */,
        UaByteString& Nonce /**<[in] Additional entropy which the caller shall provide if RegeneratePrivateKey is
            TRUE.
            <br>
            It shall be at least 32 bytes long. */,
        UaByteString& CertificateRequest /**<[out] The PKCS #10 DER encoded certificate request. */) = 0;

    /**
     *  Returns the list of Certificates that have been rejected by the Server.
     *
     *  No rules are defined for how the Server updates this list or how long a
     *  certificate is kept in the list. It is recommended that every valid but
     *  untrusted certificate be added to the rejected list as long as storage is
     *  available. Servers should omit older entries from the list returned if the
     *  maximum message size is not large enough to allow the entire list to be
     *  returned.
     *
     *  This method requires an encrypted channel and that the Client provides
     *  credentials with administrative rights on the Server.
     *
     *  <b>Method Result Codes</b>
     *
     *  Result Code           | Description
     *  ----------------------|-----------------------------------------------------
     *  Bad_UserAccessDenied  | The current user does not have the rights required.
     */
    virtual UaStatus GetRejectedList(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        UaByteStringArray& Certificates /**<[out] The DER encoded form of the Certificates rejected by the Server. */) = 0;

    /**
     *  Used to update a certificate for a Server.
     *
     *  There are the following three use cases for this method.
     *  - The new certificate was created based on a signing request created with the
     *    method \ref OpcUa::ServerConfigurationType::CreateSigningRequest
     *    "CreateSigningRequest". In this case, there is no PrivateKey provided.
     *  - A new PrivateKey and certificate were created outside the Server and both are
     *    updated with this method.
     *  - A new certificate was created and signed with the information from the old
     *    Certificate. In this case, there is no PrivateKey provided.
     *
     *
     *
     *  The Server shall do all normal integrity checks on the certificate and all of
     *  the issuer certificates. If errors occur, the Bad_SecurityChecksFailed error is
     *  returned.
     *
     *  The Server shall report an error if the public key does not match the existing
     *  certificate and PrivateKey was not provided.
     *
     *  This method requires an encrypted channel and that the Client provides
     *  credentials with administrative rights on the Server.
     *
     *  This method may require the \ref OpcUa::ServerConfigurationType::ApplyChanges
     *  "ApplyChanges" method to be called.
     *
     *  <b>Method Result Codes</b>
     *
     *  Result Code               | Description
     *  --------------------------|-------------------------------------------------------------------
     *  Bad_InvalidArgument       | The CertificateTypeId or certificateGroupId is not valid.
     *  Bad_CertificateInvalid    | The certificate is invalid or the format is not supported.
     *  Bad_NotSupported          | The PrivateKey is invalid or the format is not supported.
     *  Bad_UserAccessDenied      | The current user does not have the rights required.
     *  Bad_SecurityChecksFailed  | Some failure occurred verifying the integrity of the certificate.
     */
    virtual UaStatus UpdateCertificate(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        const UaNodeId& CertificateGroupId /**<[in] The NodeId of the certificate group object which is affected by the update.
            <br>
            If null the DefaultApplicationGroup is used. */,
        const UaNodeId& CertificateTypeId /**<[in] The type of certificate being updated.
            <br>
            The set of permitted types is specified by the \ref
            OpcUa::CertificateGroupType::getCertificateTypes "CertificateTypes"
            property belonging to the certificate group. */,
        UaByteString& Certificate /**<[in] The DER encoded certificate which replaces the existing certificate. */,
        const UaByteStringArray& IssuerCertificates /**<[in] The issuer certificates needed to verify the signature on the new certificate. */,
        const UaString& PrivateKeyFormat /**<[in] The format of the private key (PEM or PFX).
            <br>
            If the privateKey is not specified the privateKeyFormat is null or empty. */,
        UaByteString& PrivateKey /**<[in] The private key encoded in the PrivateKeyFormat. */,
        OpcUa_Boolean& ApplyChangesRequired /**<[out] Indicates that the \ref OpcUa::ServerConfigurationType::ApplyChanges
            "ApplyChanges" method must be called before the new certificate will be used. */) = 0;

    virtual void setMaxTrustListSize(OpcUa_UInt32 MaxTrustListSize);
    virtual OpcUa_UInt32 getMaxTrustListSize() const;

    virtual void setMulticastDnsEnabled(OpcUa_Boolean MulticastDnsEnabled);
    virtual OpcUa_Boolean getMulticastDnsEnabled() const;

    virtual void setServerCapabilities(const UaStringArray& ServerCapabilities);
    virtual void getServerCapabilities(UaStringArray& ServerCapabilities) const;

    virtual void setSupportedPrivateKeyFormats(const UaStringArray& SupportedPrivateKeyFormats);
    virtual void getSupportedPrivateKeyFormats(UaStringArray& SupportedPrivateKeyFormats) const;

    virtual OpcUa::CertificateGroupFolderType* getCertificateGroups();
    virtual OpcUa::PropertyType* getMaxTrustListSizeNode();
    virtual OpcUa::PropertyType* getMulticastDnsEnabledNode();
    virtual OpcUa::PropertyType* getServerCapabilitiesNode();
    virtual OpcUa::PropertyType* getSupportedPrivateKeyFormatsNode();
    virtual OpcUa::BaseMethod* getApplyChanges();
    virtual OpcUa::BaseMethod* getCreateSigningRequest();
    virtual OpcUa::BaseMethod* getGetRejectedList();
    virtual OpcUa::BaseMethod* getUpdateCertificate();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(ServerConfigurationTypeBase *pInstance);

protected:
    // Object nodes
    // Object CertificateGroups
    static OpcUa::CertificateGroupFolderType*  s_pCertificateGroups;
    OpcUa::CertificateGroupFolderType*  m_pCertificateGroups;

    // Variable nodes
    // Variable MaxTrustListSize
    static OpcUa::PropertyType*  s_pMaxTrustListSize;
    OpcUa::PropertyType*  m_pMaxTrustListSize;
    // Variable MulticastDnsEnabled
    static OpcUa::PropertyType*  s_pMulticastDnsEnabled;
    OpcUa::PropertyType*  m_pMulticastDnsEnabled;
    // Variable ServerCapabilities
    static OpcUa::PropertyType*  s_pServerCapabilities;
    OpcUa::PropertyType*  m_pServerCapabilities;
    // Variable SupportedPrivateKeyFormats
    static OpcUa::PropertyType*  s_pSupportedPrivateKeyFormats;
    OpcUa::PropertyType*  m_pSupportedPrivateKeyFormats;


    // Method nodes
    static OpcUa::BaseMethod* s_pApplyChangesMethod;
    OpcUa::BaseMethod*  m_pApplyChangesMethod;
    static OpcUa::BaseMethod* s_pCreateSigningRequestMethod;
    OpcUa::BaseMethod*  m_pCreateSigningRequestMethod;
    static OpcUa::BaseMethod* s_pGetRejectedListMethod;
    OpcUa::BaseMethod*  m_pGetRejectedListMethod;
    static OpcUa::BaseMethod* s_pUpdateCertificateMethod;
    OpcUa::BaseMethod*  m_pUpdateCertificateMethod;


private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUASERVERCONFIGURATIONTYPEBASE_H__


