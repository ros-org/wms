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

#ifndef _OpcUa_P_PKI_H_
#define _OpcUa_P_PKI_H_ 1

OPCUA_BEGIN_EXTERN_C

#define OPCUA_P_CERTIFICATESTORECONFIGURATION_DATA_SIZE 0

/**
  @brief The PK infrastructure systems supported by the platform layer.
*/
#define OPCUA_P_PKI_TYPE_OPENSSL            "OpenSSL"

/**
  @brief The openssl pki config.
  */

/**
  @brief The OpenSSL PKI specific store flags.
*/
#define OpcUa_P_PKI_OPENSSL_CHECK_REVOCATION_STATUS     1
#define OpcUa_P_PKI_OPENSSL_SET_DEFAULT_PATHS           2
#define OpcUa_P_PKI_OPENSSL_CERT_PATH_IS_HASH_DIRECTORY 4
#define OpcUa_P_PKI_OPENSSL_CRL_PATH_IS_HASH_DIRECTORY  8
#define OpcUa_P_PKI_OPENSSL_CRL_PATH_IS_MULTI_CRL_FILE  16

/**
  @brief The certificate und key format enumeration.
*/
typedef enum _OpcUa_P_FileFormat
{
    OpcUa_Crypto_Encoding_Invalid   = 0,
    OpcUa_Crypto_Encoding_DER       = 1,
    OpcUa_Crypto_Encoding_PEM       = 2,
    OpcUa_Crypto_Encoding_PKCS12    = 3
}
OpcUa_P_FileFormat;

/**
  @brief Loads a X.509 certificate from the specified file.
  */
OpcUa_StatusCode OpcUa_P_OpenSSL_X509_LoadFromFile(
    OpcUa_StringA               fileName,
    OpcUa_P_FileFormat          fileFormat,
    OpcUa_StringA               sPassword,      /* optional: just for OpcUa_PKCS12 */
    OpcUa_ByteString*           pCertificate);

/**
  @brief Loads a RSA private key from the specified file.
  */
OpcUa_StatusCode OpcUa_P_OpenSSL_RSA_LoadPrivateKeyFromFile(
    const OpcUa_CharA*      privateKeyFile,
    OpcUa_P_FileFormat      fileFormat,
    const OpcUa_CharA*      password,
    OpcUa_ByteString*       pPrivateKey);

OpcUa_StatusCode OpcUa_P_OpenSSL_RSA_SavePrivateKeyToFile(
    const OpcUa_CharA*      privateKeyFile,
    OpcUa_P_FileFormat      fileFormat,
    const OpcUa_CharA*      password,
    const OpcUa_ByteString* pPrivateKey);

/**
  @brief Get native PKI system information about current certificate error.
  */
OPCUA_IMEXPORT OpcUa_StatusCode OpcUa_P_OpenSSL_VerifyContext_GetCurrentErrorInformation(
                    OpcUa_Void*         a_pvVerifyContext,
                    OpcUa_Int32*        a_piNativeError,
                    const OpcUa_CharA** a_psErrorMessage);

OPCUA_END_EXTERN_C

#endif
