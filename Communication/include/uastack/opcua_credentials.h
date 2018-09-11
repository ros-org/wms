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

#ifndef _OpcUa_Credentials_H_
#define _OpcUa_Credentials_H_ 1

OPCUA_BEGIN_EXTERN_C

/*============================================================================
 * OpcUa_UserNameCredential
 *
 * A username/password credential.
 *
 * Name     - the name of the user.
 * Password - the password (could be hashed). 
 *===========================================================================*/
typedef struct _OpcUa_UserNameCredential
{
    OpcUa_String Name;
    OpcUa_String Password;
}
OpcUa_UserNameCredential;

/*============================================================================
 * OpcUa_X509Credentials
 *
 * An X509 certificate credential.
 *
 * Subject       - the subject of the certificate.
 * Thumbprint    - the thumbprint of the certificate.
 * Password      - the password required to access the private key.
 * StoreLocation - the location of the certificate store.
 * StoreName     - the name of the certificate store.
 *===========================================================================*/
typedef struct _OpcUa_X509Credential
{
    OpcUa_String Subject;
    OpcUa_String Thumbprint;
    OpcUa_String Password;
    OpcUa_String StoreLocation;
    OpcUa_String StoreName;
}
OpcUa_X509Credential;

/*============================================================================
 * OpcUa_ActualCredential
 *
 * An actually used credential.
 *===========================================================================*/
typedef struct _OpcUa_ActualCredential
{
    OpcUa_ByteString*               pClientCertificateChain;
    OpcUa_ByteString*               pClientPrivateKey;
    OpcUa_ByteString*               pServerCertificate;
    OpcUa_Void*                     pkiConfig;
    OpcUa_String*                   pRequestedSecurityPolicyUri;
    OpcUa_Int32                     nRequestedLifetime;
    OpcUa_MessageSecurityMode       messageSecurityMode;
}
OpcUa_ActualCredential;

/*============================================================================
 * OpcUa_CredentialType
 *===========================================================================*/
typedef enum _OpcUa_CredentialType
{
    OpcUa_CredentialType_UserName = 0x1,
    OpcUa_CredentialType_X509     = 0x2,
    OpcUa_CredentialType_Actual   = 0x4
}
OpcUa_CredentialType;

/*============================================================================
 * OpcUa_ClientCredential
 *
 * A union of all possible credential types.
 *
 * Type     - the type of credential.
 * UserName - a username/password credential.
 * X509     - an X509 certificate credential.
 *===========================================================================*/
typedef struct _OpcUa_ClientCredential
{
    OpcUa_CredentialType     Type;
    
    union _Credential
    {
    OpcUa_UserNameCredential UserName;
    OpcUa_X509Credential     X509;
    OpcUa_ActualCredential   TheActuallyUsedCredential;
    }
    Credential;
}
OpcUa_ClientCredential;

OPCUA_END_EXTERN_C

#endif /* _OpcUa_Credentials_H_ */
