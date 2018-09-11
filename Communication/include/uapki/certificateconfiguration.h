/******************************************************************************
** certificateconfiguration.h
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
#ifndef OPCUACERTIFICATECONFIGURATION_H
#define OPCUACERTIFICATECONFIGURATION_H

#include "uapkiconfig.h"
#include "uaplatformdefs.h"
#include "referencecounter.h"
#include "uaarraytemplates.h"
#include "statuscode.h"
#include "uaunistringlist.h"
#include "uapkiprovider.h"

class UAPKI_EXPORT CertificateStoreConfiguration;
class UAPKI_EXPORT UaPkiCertificate;

/** Data class for settings used to create a certificate
*/
class UAPKI_EXPORT CertificateCreateSettings
{
public:
    enum CertificateType
    {
        CertificateType_RsaMin,
        CertificateType_RsaSha256
    };

    CertificateCreateSettings();
    ~CertificateCreateSettings();

    /** Name of the application*/
    UaString        m_sCommonName;
    /** Name of the domain the OPC UA Application belongs to*/
    UaString        m_sDomainComponent;
    /** Name of the organization unit using the OPC UA server*/
    UaString        m_sOrganization;
    /** Name of the organization unit using the OPC UA server*/
    UaString        m_sOrganizationUnit;
    /** Name of the location where the OPC UA server is running*/
    UaString        m_sLocality;
    /** State where the OPC UA server is running*/
    UaString        m_sState;
    /** Two letter code for country where the OPC UA server is running e.g. DE or US*/
    UaString        m_sCountry;
    /** The number of years the certificate is valid for. The maximum accepted number is 20 but it is strongly recommended to use a shorter time.*/
    OpcUa_Byte      m_yearsValidFor;
    /** Key length of the certificate to create. Valid values are 1024, 2048 for and RsaMin and 2048, 3072 and 4096 for RsaSha256.*/
    OpcUa_Int32     m_KeyLength;
    /** Defines the algorithm used to sign the certificate. Valid values are RsaMin and RsaSha256.
        RsaMin uses a SHA1 hash, RsaSha256 uses a SHA256 hash.*/
    CertificateType m_certificateType;
    /** A list of IPAddresses the certificate is valid for. */
    UaStringArray   m_arrIPAddresses;
    /** A list of DNSNames the certificate is valid for. */
    UaStringArray   m_arrDNSNames;
};


/** Data class for certificate configuration
*/
class UAPKI_EXPORT CertificateConfiguration : public ReferenceCounter, public UaPkiProviderCertificateValidationCallback
{
    UA_DISABLE_COPY(CertificateConfiguration);
    friend class CertificateStoreConfiguration;
protected:
    virtual ~CertificateConfiguration();
    void setCertificateStoreConfiguration(CertificateStoreConfiguration* pCertificateStoreConfiguration);
    inline CertificateStoreConfiguration* pCertificateStoreConfiguration() const { return m_pCertificateStoreConfiguration; }

#if OPCUA_SUPPORT_PKI
    UaStatus buildCertificateChain(const UaByteString& certFromStore, UaPkiProvider* pPkiProvider, UaString& sError);
    UaStatus validateOwnCertificate();
    bool findIssuerCertificate(UaPkiCertificate* pIssuedCert, UaUniStringList& lstCertFiles, UaByteStringArray& lstCertData, UaPkiCertificate* pIssuerCert);
#endif // OPCUA_SUPPORT_PKI

public:
    CertificateConfiguration();

    bool isCertificateAvailable();
    UaStatus loadCertificate(UaString& sError);

    UaStatus setupCertificateStore();
    UaStatus createCertificate(const UaString& sApplicationUri);

    UaString issuerCertificateLocation() const;

    // implementation of UaPkiProviderCertificateValidationCallback
    virtual bool certificateVerificationError(
        OpcUa_Void*          pvVerifyContext,
        const UaByteString  &certificateChain,
        OpcUa_StatusCode     uVerificationResult,
        OpcUa_UInt32         uDepth);

public:
    /** Flag indicating if the certificate is loaded */
    bool                            m_isCertificateLoaded;
    /** The certificate chain containing the server certificate used for this endpoint.
      * The issued certificate is the first element in the array.
      * The rootCA certificate is the last element in the array.
      * For self signed certificates this array has length 1. */
    UaByteStringArray               m_certificateChainArray;
    /** The application certificate with the complete chain if necessary. */
    UaByteString                    m_certificateWithChain;
    /** The private key. */
    UaByteString                    m_privateKey;

    /** Path and filename of the application instance certificate.*/
    UaString                  m_sCertificateLocation;
    /** Path and filename of the private key*/
    UaString                  m_sPrivateKeyLocation;
    /** Flag indicating if the OpenSSL file store is used*/
    bool                      m_isOpenSSLStore;
#if OPCUA_SUPPORT_PKI
# if OPCUA_SUPPORT_PKI_WIN32
    WindowsStoreLocation      m_windowsStoreLocation;
    /* When using the WindowsStore this variable contains the thumbprint of the certificate.*/
    UaString                  m_thumbprint;
# endif // OPCUA_SUPPORT_PKI_WIN32
#endif // OPCUA_SUPPORT_PKI
    /** Flag indicating if the certificate should be generated if no certificate is available*/
    bool                      m_createCertificate;
    /** Try to automatically build the complete chain from the issuers list if the certificate is issued*/
    bool                      m_autoCompleteCertificateChain;
    /** Settings for the creation of a certificate*/
    CertificateCreateSettings m_certificateCreateSetting;
    /** List of endpoints using the certificate*/
    UaUInt32Array             m_endpointIndexList;

private:
    CertificateStoreConfiguration*   m_pCertificateStoreConfiguration;
};

typedef UABASE_EXPORT UaPointerArray<CertificateConfiguration> CertificateConfigurationPArray;

#endif // OPCUACERTIFICATECONFIGURATION_H
