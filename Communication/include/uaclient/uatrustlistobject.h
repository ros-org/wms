/******************************************************************************
** uatrustlistobject.h
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
** Description: Proxy class for OPC UA ObjectType TrustListType.
**
******************************************************************************/
#ifndef UACLIENTSDK_UATRUSTLISTOBJECT_H
#define UACLIENTSDK_UATRUSTLISTOBJECT_H

#include "uaclientsdk.h"
#include "uatrustlistdatatype.h"

namespace UaClientSdk {

class UaTrustListObjectPrivate;
class UaSession;

/*! \addtogroup UaClientLibrary
*  @{
*/

/** The UaTrustListObject class manges a UA Client side interaction with a TrustListType object in a server
*
*  The class hides all details necessary for the trust list access and provides simple methods to read or write
*  the content of a TrustListType object in a server.
*/
class UACLIENT_EXPORT UaTrustListObject
{
    UA_DISABLE_COPY(UaTrustListObject);
    UaTrustListObject();
public:
    UaTrustListObject(UaSession* pSession);
    virtual ~UaTrustListObject();

    // Simplified read and write of trust list
    UaStatus readTrustList(
        ServiceSettings&     serviceSettings,
        const UaNodeId&      trustListObjectNodeId,
        OpcUa_UInt32         masks,
        UaTrustListDataType& trustListData);
    UaStatus writeTrustList(
        ServiceSettings&           serviceSettings,
        const UaNodeId&            trustListObjectNodeId,
        const UaTrustListDataType& trustListData,
        OpcUa_UInt32               maxWriteLength,
        OpcUa_Boolean&             applyChangesRequired);

    // TrustListType methods
    UaStatus addCertificate(
        ServiceSettings&    serviceSettings,
        const UaNodeId&     trustListObjectNodeId,
        const UaByteString& certificate,
        OpcUa_Boolean       isTrustedCertificate);
    UaStatus removeCertificate(
        ServiceSettings&    serviceSettings,
        const UaNodeId&     trustListObjectNodeId,
        const UaString&     thumbprint,
        OpcUa_Boolean       isTrustedCertificate);

    // Helper methods used to load or store TrustList from files
    static UaStatus saveTrustListAsFiles(
        const UaString& sCertificateRevocationListLocation,
        const UaString& sCertificateTrustListLocation,
        const UaString& sIssuersRevocationListLocation,
        const UaString& sIssuersCertificatesLocation,
        const UaTrustListDataType& trustListData);
    static void loadTrustListFromFiles(
        const UaString& sCertificateRevocationListLocation,
        const UaString& sCertificateTrustListLocation,
        const UaString& sIssuersRevocationListLocation,
        const UaString& sIssuersCertificatesLocation,
        OpcUa_UInt32         masks,
        UaTrustListDataType& trustListData);

private:
    /** UaTrustListObject data */
    UaTrustListObjectPrivate* d;
};
/*! @} */
}

#endif // UACLIENTSDK_UATRUSTLISTOBJECT_H
