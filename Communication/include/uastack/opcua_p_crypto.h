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

#ifndef _OpcUa_P_Crypto_H_
#define _OpcUa_P_Crypto_H_ 1

OPCUA_BEGIN_EXTERN_C

/* MESSAGE DIGEST */
#define OPCUA_P_SHA_160 160
#define OPCUA_P_SHA_224 224
#define OPCUA_P_SHA_256 256
#define OPCUA_P_SHA_384 384
#define OPCUA_P_SHA_512 512

/* Signature Algorithm Uris */
#define OpcUa_AlgorithmUri_Signature_RsaSha1   "http://www.w3.org/2000/09/xmldsig#rsa-sha1"
#define OpcUa_AlgorithmUri_Signature_RsaSha256 "http://www.w3.org/2001/04/xmldsig-more#rsa-sha256"

/* Encryption Algorithms Uris */
#define OpcUa_AlgorithmUri_Encryption_RsaOaep  "http://www.w3.org/2001/04/xmlenc#rsa-oaep"
#define OpcUa_AlgorithmUri_Encryption_Rsa15    "http://www.w3.org/2001/04/xmlenc#rsa-1_5"

/* Encryption Algs */
#define OpcUa_P_NoEncryption_Name                   ""
#define OpcUa_P_NoEncryption_Id                     0

#define OpcUa_P_AES_128_CBC_Name                    "AES-128-CBC"
#define OpcUa_P_AES_128_CBC_Id                      1

#define OpcUa_P_AES_256_CBC_Name                    "AES-256-CBC"
#define OpcUa_P_AES_256_CBC_Id                      2

#define OpcUa_P_RSA_PKCS1_V15_Name                  "RSA-PKCS-#1-V1.5"
#define OpcUa_P_RSA_PKCS1_V15_Id                    3

#define OpcUa_P_RSA_OAEP_Name                       "RSA-OAEP"
#define OpcUa_P_RSA_OAEP_Id                         4

#define OpcUa_P_DES3_Name                           "3DES"
#define OpcUa_P_DES3_Id                             5

#define OpcUa_P_EncryptionMethodsCount              5

/* Signature Algs */
#define OpcUa_P_NoSignature_Name                    ""
#define OpcUa_P_NoSignature_Id                      0

#define OpcUa_P_RSA_PKCS1_V15_SHA1_Name             "RSA-PKCS-#1-V1.5-SHA1"
#define OpcUa_P_RSA_PKCS1_V15_SHA1_Id               6

#define OpcUa_P_RSA_PKCS1_V15_SHA256_Name           "RSA-PKCS-#1-V1.5-SHA256"
#define OpcUa_P_RSA_PKCS1_V15_SHA256_Id             7

#define OpcUa_P_HMAC_SHA1_Name                      "HMAC-SHA1"
#define OpcUa_P_HMAC_SHA1_Id                        8

#define OpcUa_P_HMAC_SHA256_Name                    "HMAC-SHA256"
#define OpcUa_P_HMAC_SHA256_Id                      9

#define OpcUa_P_RSA_PKCS1_OAEP_SHA1_Name            "RSA-PKCS-#1-OAEP-SHA1"
#define OpcUa_P_RSA_PKCS1_OAEP_SHA1_Id              10

#define OpcUa_P_RSA_PKCS1_OAEP_SHA256_Name          "RSA-PKCS-#1-OAEP-SHA256"
#define OpcUa_P_RSA_PKCS1_OAEP_SHA256_Id            11

#define OpcUa_P_SignatureMethodsCount               6

/* PRF Algs */
#define OpcUa_P_PSHA1_Name                          "P-SHA1"
#define OpcUa_P_PSHA1_Id                            12

#define OpcUa_P_PRFMethodsCount                     1

OPCUA_END_EXTERN_C

#endif
