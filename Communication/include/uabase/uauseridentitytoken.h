/******************************************************************************
** uauseridentitytoken.h
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
** Description: User identity token management classes.
**
******************************************************************************/
#ifndef UAUSERIDENTITYTOKEN_H
#define UAUSERIDENTITYTOKEN_H

#include "uabase.h"
#include "uastring.h"

/** @brief Base class for the different user identity token classes.

 *  The specific user identity tokens are represented by the derived classes UaUserIdentityTokenAnonymous and
 *  UaUserIdentityTokenUserPassword. This base class is only used in method signatures.
 */
class UABASE_EXPORT UaUserIdentityToken
{
    UA_DISABLE_COPY(UaUserIdentityToken);
public:
    UaUserIdentityToken();
    virtual ~UaUserIdentityToken();

    /** Returns the user identity token type.<br>
     *  Possible values are:<br>
     *  - OpcUa_UserTokenType_Anonymous
     *  - OpcUa_UserTokenType_UserName
     *  - OpcUa_UserTokenType_Certificate
     *  - OpcUa_UserTokenType_KerberosToken
     *  @return the token type
     */
    virtual OpcUa_UserTokenType getTokenType() const = 0;
};

/** @brief Class representing an anonymous user identity token.

 *  The class is derived from UaUserIdentityToken and is the default user settings if no
 *  specific user identity is provided.
 */
class UABASE_EXPORT UaUserIdentityTokenAnonymous: public UaUserIdentityToken
{
    UA_DISABLE_COPY(UaUserIdentityTokenAnonymous);
public:
    UaUserIdentityTokenAnonymous();
    virtual ~UaUserIdentityTokenAnonymous();

    OpcUa_UserTokenType getTokenType() const;
};

/** @brief Class representing an User and Password user identity token.

 *  The class is derived from UaUserIdentityToken and is used if user name and password based
 *  user identity is provided.
 */
class UABASE_EXPORT UaUserIdentityTokenUserPassword: public UaUserIdentityToken
{
    UA_DISABLE_COPY(UaUserIdentityTokenUserPassword);
public:
    UaUserIdentityTokenUserPassword();
    virtual ~UaUserIdentityTokenUserPassword();

    OpcUa_UserTokenType getTokenType() const;

    /// @brief User name string
    UaString sUserName;
    /// @brief Password string
    UaString sPassword;
};

/** @brief Class representing a Certificate user identity token.

 *  The class is derived from UaUserIdentityToken and is used if certificate based
 *  user identity is provided.
 */
class UABASE_EXPORT UaUserIdentityTokenCertificate: public UaUserIdentityToken
{
    UA_DISABLE_COPY(UaUserIdentityTokenCertificate);
public:
    UaUserIdentityTokenCertificate();
    virtual ~UaUserIdentityTokenCertificate();

    OpcUa_UserTokenType getTokenType() const;

    /// @brief User certificate data
    UaByteString userCertificateData;

    /// @brief User private key
    UaByteString userPrivateKey;
};

/** @brief Class representing a KerberosToken user identity token.

 *  The class is derived from UaUserIdentityToken and is used if KerberosToken based
 *  user identity is provided.
 */
class UABASE_EXPORT UaUserIdentityTokenKerberosTicket: public UaUserIdentityToken
{
    UA_DISABLE_COPY(UaUserIdentityTokenKerberosTicket);
public:
    UaUserIdentityTokenKerberosTicket();
    virtual ~UaUserIdentityTokenKerberosTicket();

    OpcUa_UserTokenType getTokenType() const;

    /// @brief User token data
    UaByteString kerberosTicket;
};

#endif // UAUSERIDENTITYTOKEN_H
