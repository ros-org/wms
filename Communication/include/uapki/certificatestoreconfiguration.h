/******************************************************************************
** certificatestoreconfiguration.h
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
** Project: C++ OPC SDK base module
**
******************************************************************************/
#ifndef OPCUACERTIFICATESTORECONFIGURATION_H
#define OPCUACERTIFICATESTORECONFIGURATION_H

#include "uapkiconfig.h"
#include "uaplatformdefs.h"
#include "uastring.h"
#include "referencecounter.h"
#include "uaarraytemplates.h"
#include "uapkiprovider.h"
#include "certificateconfiguration.h"


/** Data class for trust list configuration
*/
class UAPKI_EXPORT CertificateStoreConfiguration : public ReferenceCounter
{
    UA_DISABLE_COPY(CertificateStoreConfiguration);
protected:
    virtual ~CertificateStoreConfiguration();
public:
    CertificateStoreConfiguration();

    UaPkiProvider* getPkiProvider();
    UaStatus setupCertificateStore();
    OpcUa_UInt32 addCertificate(CertificateConfiguration* pCertificateConfiguration);
    OpcUa_UInt32 certificateCount();
    CertificateConfiguration* getCertificate(OpcUa_UInt32 index);
    bool sendCertificateWithChain() const;
    void setSendCertificateWithChain(bool bSendCertificateWithChain);

public:
    /** The folder where certificates of trusted applications and trusted CAs should be stored
      * When using the windows store this is variable contains the store name.*/
    UaString                  m_sCertificateTrustListLocation;
    /** The folder where revocation lists for trusted CAs should be stored*/
    UaString                  m_sCertificateRevocationListLocation;
    /** The folder where issuer certificates are stored.
      * Issuer certificates are CA certificates necessary for the verification of the full trust
      * chain of CA certificates in the trust list*/
    UaString                  m_sIssuersCertificatesLocation;
    /** The folder where revocation lists for issuer CAs should be stored*/
    UaString                  m_sIssuersRevocationListLocation;
    /** Flag indicating if the OpenSSL file store is used*/
    bool                      m_isOpenSSLStore;
    /** The maximum size of the TrustList in bytes. 0 means no limit.*/
    OpcUa_UInt32              m_maxTrustListSize;
#if OPCUA_SUPPORT_PKI
# if OPCUA_SUPPORT_PKI_WIN32
    WindowsStoreLocation      m_windowsStoreLocation;
# endif // OPCUA_SUPPORT_PKI_WIN32
#endif // OPCUA_SUPPORT_PKI
    /** List of endpoints using the trust list*/
    UaUInt32Array             m_endpointIndexList;

private:
    UaPkiProvider*                 m_pPkiProvider;
    CertificateConfigurationPArray m_certificates;
    bool                           m_bSendCertificateWithChain;
};

typedef UABASE_EXPORT UaPointerArray<CertificateStoreConfiguration> CertificateStoreConfigurationPArray;

#endif // OPCUACERTIFICATESTORECONFIGURATION_H
