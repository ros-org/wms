/******************************************************************************
** uaserverconfigurationobject.h
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
** Project: C++ OPC Client SDK
**
** Description: Proxy class for OPC UA ObjectType ServerConfigurationType.
**
******************************************************************************/
#ifndef UACLIENTSDK_UASERVERCONFIGURATIONOBJECT_H
#define UACLIENTSDK_UASERVERCONFIGURATIONOBJECT_H

#include "uaclientsdk.h"

namespace UaClientSdk {

class UaServerConfigurationObjectPrivate;
class UaSession;

/*! \addtogroup UaClientLibrary
*  @{
*/

/** This class is a proxy class for access to a ServerConfiguration Object in the server
*
*  The ServerConfiguration Object is an instance of the ServerConfigurationType. There is always exactly one instance
*  in the Server AddressSpace. The Object provides security configuration capabilities like updating
*  the server certificate or configuration of the server trust list.
*
*  A server may have different application instance certificates and trust lists. The available groups can be requested
*  with getCertificateGroups. The certificate types per group can be requested with getSupportedCertificateTypes.
*
*  A server must support at least the DefaultApplicationGroup (OpcUaId_ServerConfiguration_CertificateGroups_DefaultApplicationGroup).
*  The NodeId of the trust list for this group or any other group can be requested with getTrustListObjectNodeId. The trust list can be
*  accessed using the class UaTrustListObject.
*
*  The certificates in the rejected list of the server can be requested with getRejectedList. If a certificate from this list or another
*  certificate should be added to the trust list, this can be done through a method of the class UaTrustListObject without the need
*  to transfer the whole trust list.
*
*  The configuraiton of the server application instance certificates is done through the methods \ref createSigningRequest,
*  \ref updateCertificate, and \ref applyChanges.
*/
class UACLIENT_EXPORT UaServerConfigurationObject
{
    UA_DISABLE_COPY(UaServerConfigurationObject);
    UaServerConfigurationObject();
public:
    UaServerConfigurationObject(UaSession* pSession);
    virtual ~UaServerConfigurationObject();

    // ServerConfigurationType Properties
    UaStatus getCertificateGroups(UaReferenceDescriptions& certificateGroups);
    UaStatus getSupportedCertificateTypes(const UaNodeId& certificateGroupId, UaNodeIdArray& supportedCertificateTypes);
    UaStatus getSupportedPrivateKeyFormats(UaStringArray& supportedPrivateKeyFormats);
    UaNodeId getTrustListObjectNodeId(const UaNodeId& certificateGroupId = UaNodeId());

    // ServerConfigurationType Methods
    UaStatus updateCertificate(
        ServiceSettings&         serviceSettings,
        const UaNodeId&          certificateGroupId,
        const UaNodeId&          certificateTypeId,
        const UaByteString&      certificate,
        const UaByteStringArray& issuerCertificates,
        const UaString&          privateKeyFormat,
        const UaByteString&      privateKey,
        OpcUa_Boolean&           applyChangesRequired);
    UaStatus applyChanges(
        ServiceSettings&    serviceSettings);
    UaStatus createSigningRequest(
        ServiceSettings&    serviceSettings,
        const UaNodeId&     certificateGroupId,
        const UaNodeId&     certificateTypeId,
        const UaString&     subjectName,
        OpcUa_Boolean       regeneratePrivateKey,
        const UaByteString& nonce,
        UaByteString&       certificateRequest);
    UaStatus getRejectedList(
        ServiceSettings&    serviceSettings,
        UaByteStringArray&  certificates);

private:
    /** UaServerConfigurationObject data */
    UaServerConfigurationObjectPrivate* d;
};
/*! @} */
}

#endif // UACLIENTSDK_UASERVERCONFIGURATIONOBJECT_H
