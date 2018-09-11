/******************************************************************************
** uacertificatedirectoryobject.h
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
** Description: Proxy class for OPC UA ObjectType CertificateDirectoryType.
**
******************************************************************************/
#ifndef UACLIENTSDK_UACERTIFICATEDIRECTORYOBJECT_H
#define UACLIENTSDK_UACERTIFICATEDIRECTORYOBJECT_H

#include "uaclientsdk.h"
#include "uaserveronnetwork.h"
#include "opcuagds_applicationrecorddatatype.h"

namespace UaClientSdk {

class UaCertificateDirectoryObjectPrivate;
class UaSession;

/*! \addtogroup UaClientLibrary
*  @{
*/

/** The UaCertificateDirectoryObject class manges a UA Client side interaction with a Global Directory Service (GDS)
*
* There are two main parts of GDS functionality provided through this class.
*
* The one part is the registration and management of OPC UA applications in the GDS through the methods defined
* by the DirectoryType. This includes register, update and unregister an application.
*
* The second part is the creation and access to application instance certificates and trust list managed by the
* GDS through methods defined by the CertificateDirectoryType. This includes to request, sign or renew an application
* instance certificate and to check the state of these requests. In addition it provides the method to get the trust
* list for the OPC UA application.
*/
class UACLIENT_EXPORT UaCertificateDirectoryObject
{
    UA_DISABLE_COPY(UaCertificateDirectoryObject);
    UaCertificateDirectoryObject();
public:
    UaCertificateDirectoryObject(UaSession* pSession);
    virtual ~UaCertificateDirectoryObject();

    // DirectoryType methods
    UaStatus findApplications(
        ServiceSettings& serviceSettings,
        const UaString& applicationUri,
        OpcUaGds::ApplicationRecordDataTypes& applications);
    UaStatus getApplication(
        ServiceSettings& serviceSettings,
        const UaNodeId& applicationId,
        OpcUaGds::ApplicationRecordDataType& application);
    UaStatus registerApplication(
        ServiceSettings& serviceSettings,
        const OpcUaGds::ApplicationRecordDataType& application,
        UaNodeId& applicationId);
    UaStatus unregisterApplication(
        ServiceSettings& serviceSettings,
        const UaNodeId& applicationId);
    UaStatus updateApplication(
        ServiceSettings& serviceSettings,
        const OpcUaGds::ApplicationRecordDataType& application);

    // CertificateDirectoryType methods
    UaStatus getCertificateGroups(
        ServiceSettings& serviceSettings,
        const UaNodeId& applicationId,
        UaNodeIdArray&  certificateGroupIds);
    UaStatus getCertificateTypesForGroup(
        ServiceSettings& serviceSettings,
        const UaNodeId& certificateGroupId,
        UaNodeIdArray&  certificateTypes);
    UaStatus startSigningRequest(
        ServiceSettings& serviceSettings,
        const UaNodeId& applicationId,
        const UaNodeId& certificateGroupId,
        const UaNodeId& certificateTypeId,
        UaByteString& certificateRequest,
        UaNodeId& requestId);
    UaStatus startNewKeyPairRequest(
        ServiceSettings& serviceSettings,
        const UaNodeId& applicationId,
        const UaNodeId& certificateGroupId,
        const UaNodeId& certificateTypeId,
        const UaString& subjectName,
        const UaStringArray& domainNames,
        const UaString& privateKeyFormat,
        const UaString& privateKeyPassword,
        UaNodeId& requestId);
    UaStatus finishRequest(
        ServiceSettings& serviceSettings,
        const UaNodeId& applicationId,
        const UaNodeId& requestId,
        UaByteString& certificate,
        UaByteString& privateKey,
        UaByteStringArray& issuerCertificates);
    UaStatus getTrustList(
        ServiceSettings& serviceSettings,
        const UaNodeId& applicationId,
        const UaNodeId& certificateGroupId,
        UaNodeId& trustListId);
    UaStatus getCertificateStatus(
        ServiceSettings& serviceSettings,
        const UaNodeId& applicationId,
        const UaNodeId& certificateGroupId,
        const UaNodeId& certificateTypeId,
        OpcUa_Boolean& updateRequired);

private:
    /** UaCertificateDirectoryObject data */
    UaCertificateDirectoryObjectPrivate* d;
};
/*! @} */
}

#endif // UACLIENTSDK_UACERTIFICATEDIRECTORYOBJECT_H
