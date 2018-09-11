/******************************************************************************
** uapkiprovider.h
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
** PKI Provider handling class.
**
******************************************************************************/
#ifndef UAPKIPROVIDER_H
#define UAPKIPROVIDER_H

#include "opcua_proxystub.h"
#include "opcua_pki.h"
#include "statuscode.h"
#include "uastring.h"
#include "uabytestring.h"

/** The UaPkiProviderCertificateValidationCallback is an interface for retrieving information about certificate validation errors
*
* If detailed information about certificate validation is needed, the UaPkiProvider::setCertificateValidationCallback() method
* can be called to set this callback interface. For each single error during certificate validation, the certificateVerificationError()
* callback will be invoked containing detailed information about the error.
*/
class UABASE_EXPORT UaPkiProviderCertificateValidationCallback
{
public:
    virtual ~UaPkiProviderCertificateValidationCallback() {}

    /** Callback method to inform about errors during certificate validation
    *
    * @return true if a certificate validation error should be ignored, false otherwise. If an error is ignored,
    *         validation continues, otherwise verification will be stopped.
    */
    virtual bool certificateVerificationError(
        OpcUa_Void*          pvVerifyContext,        //!< [out] The verification context. Can be used to get further error details.
        const UaByteString  &certificateChain,       //!< [out] The certificate chain that was constructed during verification.
        OpcUa_StatusCode     uVerificationResult,    //!< [out] The verification error.
        OpcUa_UInt32         uDepth                  //!< [out] The index of the certificate in the certificateChain the error occured on.
        ) = 0;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for a PKI provider.
 *  The core library implements the basic cryptographic functions and provides various utility functions.
 *  It is not possible to create shallow copies of this Class.
 *  It is not possible to use the default constructor.
 */
class UABASE_EXPORT UaPkiProvider
{
    UA_DISABLE_COPY(UaPkiProvider);
protected:
    UaPkiProvider();
public:
    /* Construction */
    UaPkiProvider(UaPkiProvider* pOther);

    /* Destruction */
    virtual ~UaPkiProvider();

    /* Open the certificate store. */
    UaStatus openCertificateStore();

    /* Close the certificate store. */
    UaStatus closeCertificateStore();

    /* Load a certificate from the certificate store. */
    UaStatus loadCertificate(
        UaString&     sCertificateName,
        UaByteString& certificate);

    /* Load a private key from the certificate store. */
    UaStatus loadPrivateKey(
        UaString&          sPrivateKeyName,
        OpcUa_P_FileFormat fileFormat,
        UaString&          sPassword,
        UaByteString&      privateKey);

    /* Split a certificate chain */
    UaStatus splitCertificateChain(const UaByteString &certificateChain, UaByteStringArray &chainEntries);

    /* Validate a certificate */
    UaStatus validateCertificate(const UaByteString& certificate);

    inline OpcUa_Handle getPkiConfigHandle() const {return (OpcUa_Handle)&m_PkiConfig;}

    inline UaString getCertificateTrustListLocation() const {return m_sCertificateTrustListLocation;}

    void setCertificateValidationCallback(UaPkiProviderCertificateValidationCallback* pCertificateValidationCallback);
    inline UaPkiProviderCertificateValidationCallback* getCertificateValidationCallback() const {return m_pCertificateValidationCallback;}

    inline UaString sCertificateRevocationListLocation() const {return m_sCertificateRevocationListLocation;}
    inline UaString sCertificateTrustListLocation() const {return m_sCertificateTrustListLocation;}
    inline UaString sIssuersRevocationListLocation() const {return m_sIssuersRevocationListLocation;}
    inline UaString sIssuersCertificatesLocation() const {return m_sIssuersCertificatesLocation;}

protected:
    UaString                                m_sCertificateRevocationListLocation;
    UaString                                m_sCertificateTrustListLocation;
    UaString                                m_sIssuersRevocationListLocation;
    UaString                                m_sIssuersCertificatesLocation;
    /* PKI Provider */
    OpcUa_PKIProvider                       m_PkiProvider;
    /* PKI Configuration */
    OpcUa_CertificateStoreConfiguration     m_PkiConfig;
    /* Handle of the certificate store */
    OpcUa_Handle                            m_hCertificateStore;
    /* Flag that indicates if the certificate store was opened */
    OpcUa_Boolean                           m_isOpened;
    UaPkiProviderCertificateValidationCallback* m_pCertificateValidationCallback;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for no security PKI provider.
 */
class UABASE_EXPORT UaPkiProviderNoSecurity: public UaPkiProvider
{
    UA_DISABLE_COPY(UaPkiProviderNoSecurity);
public:
    /* Construction */
    UaPkiProviderNoSecurity();

    /* Destruction */
    virtual ~UaPkiProviderNoSecurity();

private:
};

#if OPCUA_SUPPORT_PKI
/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for a OpenSSL PKI provider.
 *  The core library implements the basic cryptographic functions and provides various utility functions.
 *  It is not possible to create shallow copies of this Class.
 *  It is not possible to use the default constructor.
 */
class UABASE_EXPORT UaPkiProviderOpenSSL: public UaPkiProvider
{
    UA_DISABLE_COPY(UaPkiProviderOpenSSL);
    UaPkiProviderOpenSSL(){};
public:
    /* Construction */
    UaPkiProviderOpenSSL(
        const UaString& sCertificateRevocationListLocation,
        const UaString& sCertificateTrustListLocation);

    /* Construction */
    UaPkiProviderOpenSSL(
        const UaString& sCertificateRevocationListLocation,
        const UaString& sCertificateTrustListLocation,
        const UaString& sIssuersRevocationListLocation,
        const UaString& sIssuersCertificatesLocation);

    /* Destruction */
    virtual ~UaPkiProviderOpenSSL();

private:
};

#if OPCUA_SUPPORT_PKI_WIN32
/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for a Windows Store PKI provider.
 *  The core library implements the basic cryptographic functions and provides various utility functions.
 *  It is not possible to create shallow copies of this Class.
 *  It is not possible to use the default constructor.
 */
class UABASE_EXPORT UaPkiProviderWindowsStore: public UaPkiProvider
{
    UA_DISABLE_COPY(UaPkiProviderWindowsStore);
    UaPkiProviderWindowsStore(){}
public:
    /* Construction */
    UaPkiProviderWindowsStore(
        OpcUa_UInt32    windowsStoreLocationFlag,
        const UaString& sStoreName);

    UaPkiProviderWindowsStore(
        OpcUa_UInt32    windowsStoreLocationFlag,
        const UaString& sStoreName,
        const UaString& sIssuersStoreName);

    /* Destruction */
    virtual ~UaPkiProviderWindowsStore();

private:
};
#endif /* OPCUA_SUPPORT_PKI_WIN32 */

#endif // OPCUA_SUPPORT_PKI

#endif // UAPKIPROVIDER_H
