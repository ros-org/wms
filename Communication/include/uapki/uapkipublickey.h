/******************************************************************************
** uapkipublickey.h
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
** Project: C++ OPC SDK PKI module
**
** Description: PKI public key handling class.
**
******************************************************************************/
#ifndef __UAPKIPUBLICKEY_H__
#define __UAPKIPUBLICKEY_H__

#include "uapkiconfig.h"
#include <list>
#include <openssl/x509.h>
#include <uabytearray.h>
#include <uastring.h>

/*! \addtogroup CppPkiLibraryClass
*  @{
*/

/// @brief KeyType Enumeration
enum UaPkiKeyType
{
    UaPkiKeyType_RSA        = EVP_PKEY_RSA,     /*!< KeyType: RSA       */
    UaPkiKeyType_DSA        = EVP_PKEY_DSA,     /*!< KeyType: DSA       */
    UaPkiKeyType_Unknown    = EVP_PKEY_NONE     /*!< KeyType: Unknown   */
};

/** UaPkiPublicKey */
class UAPKI_EXPORT UaPkiPublicKey
{
public:
    UaPkiPublicKey();
    UaPkiPublicKey ( EVP_PKEY *pKey );
    ~UaPkiPublicKey();

    UaPkiPublicKey ( const UaPkiPublicKey &copy );
    UaPkiPublicKey& operator= ( const UaPkiPublicKey &copy );

    UaByteArray toDER() const;

    operator EVP_PKEY*() const;
    int keySize() const;
    UaPkiKeyType keyType() const;

    static UaPkiPublicKey fromDER ( const UaByteArray &DERdata );

    std::list<UaString> getErrors();

private:
    void addOpenSSLError() const;
    void addError(const UaString &sErr) const;
    mutable std::list<UaString> m_lstErrors;

    X509_PUBKEY *m_pPublicKey;
};
/*! @} */

#endif

