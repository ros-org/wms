/******************************************************************************
** uapkirsakeypair.h
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
** Description: PKI RSA key pair handling class.
**
******************************************************************************/
#ifndef __UAPKIRSAKEYPAIR_H__
#define __UAPKIRSAKEYPAIR_H__

#include "uapkiconfig.h"
#include "uapkipublickey.h"
#include "uapkiprivatekey.h"
#include <list>

/*! \addtogroup CppPkiLibraryClass
*  @{
*/

typedef int fcnPassword_callback ( char *buf, int size, int rwflag, void *u );

/** UaPkiRsaKeyPair
*/
class UAPKI_EXPORT UaPkiRsaKeyPair
{
public:
    UaPkiRsaKeyPair();
    UaPkiRsaKeyPair(EVP_PKEY *pKey);
    UaPkiRsaKeyPair ( int bits );
    ~UaPkiRsaKeyPair();

    UaPkiRsaKeyPair ( const UaPkiRsaKeyPair &copy );
    UaPkiRsaKeyPair& operator= ( const UaPkiRsaKeyPair &copy );

    UaPkiPrivateKey privateKey() const;
    UaPkiPublicKey publicKey() const;

    int toPEMFile ( const char *szFileName, const char *szPassword ) const;
    int toPEMFile ( const UaString &sFileName, const char *szPassword ) const;
    UaByteArray toDER() const;
    UaByteArray toPEM( const char *szPassword ) const;

    static UaPkiRsaKeyPair fromPEMFile ( const char *szFileName, const char *szPassword, fcnPassword_callback *pCallback = 0, void *pCBData = 0);
    static UaPkiRsaKeyPair fromPEMFile ( const UaString &sFileName, const char *szPassword, fcnPassword_callback *pCallback = 0, void *pCBData = 0);

    static bool checkKeyPair(const UaPkiPublicKey &publicKey, const UaPkiPrivateKey &privateKey);

    inline bool isValid() { return ( m_pKey != 0 && m_pKey->pkey.rsa != 0 && EVP_PKEY_missing_parameters ( m_pKey ) == 0); }

    std::list<UaString> getErrors();

private:
    static int password_callback ( char *buf, int size, int rwflag, void *u );

private:
    void addOpenSSLError() const;
    void addError(const UaString &sErr) const;
    mutable std::list<UaString> m_lstErrors;

    EVP_PKEY *m_pKey;
};
/*! @} */

#endif


