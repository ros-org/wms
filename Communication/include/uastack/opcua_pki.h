/*****************************************************************************
 *                                                                           *
 * Copyright (c) 2006-2016 Unified Automation GmbH. All rights reserved.     *
 *                                                                           *
 * Software License Agreement ("SLA") Version 2.5                            *
 *                                                                           *
 * Unless explicitly acquired and licensed from Licensor under another       *
 * license, the contents of this file are subject to the Software License    *
 * Agreement ("SLA") Version 2.5, or subsequent versions as allowed by the   *
 * SLA, and You may not copy or use this file in either source code or       *
 * executable form, except in compliance with the terms and conditions of    *
 * the SLA.                                                                  *
 *                                                                           *
 * All software distributed under the SLA is provided strictly on an "AS     *
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,       *
 * AND LICENSOR HEREBY DISCLAIMS ALL SUCH WARRANTIES, INCLUDING WITHOUT      *
 * LIMITATION, ANY WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR   *
 * PURPOSE, QUIET ENJOYMENT, OR NON-INFRINGEMENT. See the SLA for specific   *
 * language governing rights and limitations under the SLA.                  *
 *                                                                           *
 * The complete license agreement can be found here:                         *
 * http://unifiedautomation.com/License/SLA/2.5/                             *
 *                                                                           *
 * Project: Unified Automation OPC UA ANSI C Communication Stack             *
 *                                                                           *
 * This software is based in part on the ANSI C Stack of the OPC Foundation. *
 * Initial version of the ANSI C Stack was founded and copyrighted by OPC    *
 * Foundation, Inc.                                                          *
 * Copyright (C) 2008, 2014 OPC Foundation, Inc., All Rights Reserved.       *
 *****************************************************************************/

#ifndef _OpcUa_PKIProvider_H_
#define _OpcUa_PKIProvider_H_ 1

#include <opcua_p_pki.h>

OPCUA_BEGIN_EXTERN_C

/**
  @brief The standard PKI configuration types.
  */
#define OPCUA_PKI_TYPE_NONE         "None"
#define OPCUA_PKI_TYPE_OVERRIDE     "Override"

typedef OpcUa_StatusCode (OPCUA_DLLCALL* OpcUa_CertificateStoreConfiguration_VerifyCallback)(
                    OpcUa_Void*             a_pvVerifyContext,
                    const OpcUa_ByteString* a_pCertificateChain,
                    OpcUa_StatusCode        a_uVerificationResult,
                    OpcUa_UInt32            a_uDepth,
                    OpcUa_Void*             a_pvUserData);

/**
  @brief The openssl pki config.
  */
typedef struct _OpcUa_CertificateStoreConfiguration
{
    /*! @brief used PKI type. */
    OpcUa_StringA                                       strPkiType;

    /*! @brief The trusted certificate store location. */
    OpcUa_StringA                                       strTrustedCertificateListLocation;

    /*! @brief The trusted certificate revocation list location. */
    OpcUa_StringA                                       strRevokedCertificateListLocation;

    /*! @brief The issuer certificate store location. */
    OpcUa_StringA                                       strIssuerCertificateStoreLocation;

    /*! @brief The issuer certificate revocation list location. */
    OpcUa_StringA                                       strRevokedIssuerCertificateListLocation;

    /*! @brief Callback for interactive certificate validation. */
    OpcUa_CertificateStoreConfiguration_VerifyCallback  pfVerifyCallback;

    /*! @brief User data passed to pfVerifyCallback. */
    OpcUa_Void*                                         pvVerifyCallbackUserData;

    /*! @brief PKI-specific flags. */
    OpcUa_UInt32                                        uFlags;

    /*! @brief External PKIProvider IF to override default implementation. Checked when Configuration type is "Override" */
    OpcUa_Void*                                         pvOverride;

    /*! Adds extended configuration data if defined and larger than 0 */
#if OPCUA_P_CERTIFICATESTORECONFIGURATION_DATA_SIZE
    OpcUa_CharA                                         Data[OPCUA_P_CERTIFICATESTORECONFIGURATION_DATA_SIZE];
#endif
} OpcUa_CertificateStoreConfiguration;

/** 
  @brief Allocates and initializes memory for OpcUa_CertificateStoreConfiguration.

  @param ppConfiguration    [out] Pointer to future configuration object.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_CertificateStoreConfiguration_Create(OpcUa_CertificateStoreConfiguration** ppConfiguration);

/** 
  @brief Initializes OpcUa_CertificateStoreConfiguration.

  @param pConfiguration    [in] Pointer to configuration object.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_CertificateStoreConfiguration_Initialize(OpcUa_CertificateStoreConfiguration* pConfiguration);

/** 
  @brief Sets the values in the configuration to the given parameters. Strings are copied to allow clear.

  @param pConfiguration                             [bi] Pointer to configuration object.
  @param strPkiType                                 [in] Requested PKI provider type (depends on platformlayer).
  @param strTrustedCertificateListLocation          [in] Store identifier with explicitely trusted certificates.
  @param strRevokedCertificateListLocation          [in] Store identifier with revoked certificats.
  @param strIssuerCertificateStoreLocation          [in] Store identifier with not trusted issuer certificats.
  @param strRevokedIssuerCertificateListLocation    [in] Store identifier with revoked issuer certificats.
  @param pfVerifyCallback                           [in] Callback function which is invoked during certificate validation.
  @param pvVerifyCallbackUserData                   [in] User data passed to pfVerifyCallback.
  @param uFlags                                     [in] PkiType dependent flags.
  @param pvOverride                                 [in] Custom PKI provider to use if PkiType is Override.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_CertificateStoreConfiguration_Set(
    OpcUa_CertificateStoreConfiguration*                pConfiguration,
    const OpcUa_CharA*                                  strPkiType,
    const OpcUa_CharA*                                  strTrustedCertificateListLocation,
    const OpcUa_CharA*                                  strRevokedCertificateListLocation,
    const OpcUa_CharA*                                  strIssuerCertificateStoreLocation,
    const OpcUa_CharA*                                  strRevokedIssuerCertificateListLocation,
    OpcUa_CertificateStoreConfiguration_VerifyCallback  pfVerifyCallback,
    OpcUa_Void*                                         pvVerifyCallbackUserData,
    OpcUa_UInt32                                        uFlags,
    OpcUa_Void*                                         pvOverride);

/** 
  @brief Frees all memory referenced from pConfiguration.

  @param pConfiguration    [in] Pointer to configuration object.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_CertificateStoreConfiguration_Clear(OpcUa_CertificateStoreConfiguration* pConfiguration);

/** 
  @brief Frees all memory referenced directly and indirectly by ppConfiguration.

  @param ppConfiguration    [bi] Pointer to future configuration object. Null on return.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_CertificateStoreConfiguration_Delete(OpcUa_CertificateStoreConfiguration** ppConfiguration);

struct _OpcUa_PKIProvider;
/** 
  @brief Validates a given X509 certificate object.

   Validation:
   - Subject/Issuer
   - Path
   - Certificate Revocation List (CRL)
   - Certificate Trust List (CTL)

  @param pPKI                     [in]  The pki handle.
  @param pCertificate             [in]  The certificate that should be validated. (DER encoded ByteString)
  @param pCertificateStore        [in]  The certificate store that validates the passed in certificate.

  @param pValidationCode          [out] The validation code, that gives information about the validation result.
*/
typedef OpcUa_StatusCode (OpcUa_PKIProvider_PfnValidateCertificate)(  
    struct _OpcUa_PKIProvider*  pPKI,
    const OpcUa_ByteString*     pCertificate,
    OpcUa_Void*                 pCertificateStore,
    OpcUa_Int*                  pValidationCode); /* Validation return code. */

/** 
  @brief Validates a given X509 certificate object.
 
   Validation:
   - Subject/Issuer
   - Path
   - Certificate Revocation List (CRL)
   - Certificate Trust List (CTL)

  @param pPKI                     [in]  The pki handle.
  @param pCertificate             [in]  The certificate that should be validated.(DER encoded ByteString)
  @param pCertificateStore        [in]  The certificate store that validates the passed in certificate.

  @param pValidationCode          [out] The validation code, that gives information about the validation result.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_PKIProvider_ValidateCertificate(
    struct _OpcUa_PKIProvider*  pPKI,
    const OpcUa_ByteString*     pCertificate,
    OpcUa_Void*                 pCertificateStore,
    OpcUa_Int*                  pValidationCode); /* Validation return code. */


/** 
  @brief Creates a certificate store object.

  @param pPKI                         [in]  The pki handle.
  
  @param ppCertificateStore           [out] The handle to the certificate store.
*/
typedef OpcUa_StatusCode (OpcUa_PKIProvider_PfnOpenCertificateStore)(  
    struct _OpcUa_PKIProvider*  pPKI,
    OpcUa_Void**                ppCertificateStore); /* type depends on store implementation */

/** 
  @brief Creates a certificate store object.

  @param pPKI                         [in]  The PKI handle.
  
  @param ppCertificateStore           [out] The handle to the certificate store.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_PKIProvider_OpenCertificateStore(
    struct _OpcUa_PKIProvider*  pPKI,
    OpcUa_Void**                ppCertificateStore); /* type depends on store implementation */

/** 
  @brief imports a given certificate into given certificate store.

  @param pPKI                     [in]  The pki handle.
  @param pCertificate             [in]  The certificate that should be imported.
  @param pCertificateStore        [in]  The certificate store that should store the passed in certificate.

  @param pCertificateIndex        [int/out] The index that indicates the store location of the certificate within the certificate store.
*/
typedef OpcUa_StatusCode (OpcUa_PKIProvider_PfnSaveCertificate)(  
    struct _OpcUa_PKIProvider*  pPKI,
    const OpcUa_ByteString*     pCertificate,
    OpcUa_Void*                 pCertificateStore,
    OpcUa_Void*                 pSaveHandle);

/** 
  @brief imports a given certificate into given certificate store.
 
  @param pPKI                     [in]  The PKI handle.
  @param pCertificate             [in]  The certificate that should be imported.
  @param pCertificateStore        [in]  The certificate store that should store the passed in certificate.

  @param pCertificateIndex        [in/out] The index that indicates the store location of the certificate within the certificate store.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_PKIProvider_SaveCertificate(
    struct _OpcUa_PKIProvider*  pPKI,
    const OpcUa_ByteString*     pCertificate,
    OpcUa_Void*                 pCertificateStore,
    OpcUa_Void*                 pSaveHandle);



/** 
  @brief imports a given certificate into given certificate store.
 
  @param pPKI                     [in]  The pki handle.
  @param pCertificate             [in]  The certificate that should be imported.
  @param pCertificateStore        [in]  The certificate store that should store the passed in certificate.

  @param pCertificateIndex        [out] The index that indicates the store location of the certificate within the certificate store.
*/
typedef OpcUa_StatusCode (OpcUa_PKIProvider_PfnLoadCertificate)(  
    struct _OpcUa_PKIProvider*  pPKI,
    OpcUa_Void*                 pLoadHandle,
    OpcUa_Void*                 pCertificateStore,
    OpcUa_ByteString*           pCertificate);

/** 
  @brief imports a given certificate into given certificate store.
 
  @param pPKI                     [in]  The PKI handle.
  @param pCertificate             [in]  The certificate that should be imported.
  @param pCertificateStore        [in]  The certificate store that should store the passed in certificate.

  @param pCertificateIndex        [out] The index that indicates the store location of the certificate within the certificate store.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_PKIProvider_LoadCertificate(
    struct _OpcUa_PKIProvider*  pPKI,
    OpcUa_Void*                 pLoadHandle,
    OpcUa_Void*                 pCertificateStore,
    OpcUa_ByteString*           pCertificate);


/** 
  @brief frees a certificate store object.

  @param pProvider             [in]  The crypto provider handle.

  @param pCertificateStore     [out] The certificate store object.
*/
typedef OpcUa_StatusCode (OpcUa_PKIProvider_PfnCloseCertificateStore)(  
    struct _OpcUa_PKIProvider*  pPKI,
    OpcUa_Void**                ppCertificateStore); /* type depends on store implementation */


/** 
  @brief frees a certificate store object.

  @param pProvider             [in]  The crypto provider handle.

  @param pCertificateStore     [out] The certificate store object.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_PKIProvider_CloseCertificateStore(
    struct _OpcUa_PKIProvider*  pPKI,
    OpcUa_Void**                ppCertificateStore); /* type depends on store implementation */


/** 
  @brief frees a certificate store object.

  @param pProvider             [in]  The crypto provider handle.

  @param pCertificateStore     [out] The certificate store object.
*/
typedef OpcUa_StatusCode (OpcUa_PKIProvider_PfnLoadPrivateKeyFromFile)(
    const OpcUa_CharA*          privateKeyFile,
    OpcUa_P_FileFormat          fileFormat,
    const OpcUa_CharA*          password,
    OpcUa_ByteString*           pPrivateKey);

/** 
  @brief frees a certificate store object.

  @param pProvider             [in]  The crypto provider handle.

  @param pCertificateStore     [out] The certificate store object.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_PKIProvider_LoadPrivateKeyFromFile(
    struct _OpcUa_PKIProvider*   a_pPKI,
    const OpcUa_CharA*           a_privateKeyFile,
    OpcUa_P_FileFormat           a_fileFormat,
    const OpcUa_CharA*           a_password,
    OpcUa_ByteString*            a_pPrivateKey);

/**
  @brief Add given private key data to store.

  @param storeLocation      [in]  The storage location depending on implementation (i.e. file name).
  @param format             [in]  The destination format (OpcUa_Crypto_Encoding_*)
  @param password           [in]  Optional password.
  @param pPrivateKey        [in]  Private key data.
*/
typedef OpcUa_StatusCode (OpcUa_PKIProvider_PfnSavePrivateKeyToFile)(
    const OpcUa_CharA*          storeLocation,
    OpcUa_P_FileFormat          format,
    const OpcUa_CharA*          password,
    const OpcUa_ByteString*     pPrivateKey);

/**
  @brief Add given private key data to store.

  @param a_pPKI               [in]  The PKI provider handle.
  @param a_StoreLocation      [in]  The storage location depending on implementation (i.e. file name).
  @param a_Format             [in]  The destination format (OpcUa_Crypto_Encoding_*)
  @param a_password           [in]  Optional password.
  @param a_pPrivateKey        [in]  Private key data.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_PKIProvider_SavePrivateKeyToFile(
    struct _OpcUa_PKIProvider*   a_pPKI,
    const OpcUa_CharA*           a_StoreLocation,
    OpcUa_P_FileFormat           a_Format,
    const OpcUa_CharA*           a_password,
    const OpcUa_ByteString*      a_pPrivateKey);

/**
  @brief Splits certificate chain into its elements.

  The returned byte strings reference the memory blocks in the input parameter.
  The data pointers become invalid if the chain is freed! Also, freeing the memory
  referenced by the chain elements is not allowed!

  @param pCertificateChain      [in]  Byte string consisting of concatenated DER certificates.

  @param pNumberOfChainElements [out] Number of certificates found in the chain.
  @param pabyChainElements      [out] Array of byte strings referencing certificates in pCertificateChain (don't free contents).
*/
typedef OpcUa_StatusCode (OpcUa_PKIProvider_PfnSplitCertificateChain)(
    const OpcUa_ByteString*     pCertificateChain,
    OpcUa_UInt32*               pNumberOfChainElements,
    OpcUa_ByteString**          pabyChainElements);

/**
  @brief Splits certificate chain into its elements.

  The returned byte strings reference the memory blocks in the input parameter.
  The data pointers become invalid if the chain is freed! Also, freeing the memory
  referenced by the chain elements is not allowed!

  @param a_pPKI                   [in]  The PKI provider handle.
  @param a_pCertificateChain      [in]  Byte string consisting of concatenated DER certificates.

  @param a_pNumberOfChainElements [out] Number of certificates found in the chain.
  @param a_pabyChainElements      [out] Array of byte strings referencing certificates in pCertificateChain (don't free contents).
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_PKIProvider_SplitCertificateChain(
    struct _OpcUa_PKIProvider*  a_pPKI,
    const OpcUa_ByteString*     a_pCertificateChain,
    OpcUa_UInt32*               a_pNumberOfChainElements,
    OpcUa_ByteString**          a_pabyChainElements);

typedef struct _OpcUa_PKIProvider
{
    OpcUa_Handle                                 Handle; /* Certificate Store */
    OpcUa_PKIProvider_PfnValidateCertificate*    ValidateCertificate;
    OpcUa_PKIProvider_PfnLoadPrivateKeyFromFile* LoadPrivateKeyFromFile;
    OpcUa_PKIProvider_PfnSavePrivateKeyToFile*   SavePrivateKeyToFile;
    OpcUa_PKIProvider_PfnOpenCertificateStore*   OpenCertificateStore;
    OpcUa_PKIProvider_PfnSaveCertificate*        SaveCertificate;
    OpcUa_PKIProvider_PfnLoadCertificate*        LoadCertificate;
    OpcUa_PKIProvider_PfnCloseCertificateStore*  CloseCertificateStore;
    OpcUa_PKIProvider_PfnSplitCertificateChain*  SplitCertificateChain;
}
OpcUa_PKIProvider;

OPCUA_END_EXTERN_C

#endif
