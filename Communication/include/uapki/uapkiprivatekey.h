/******************************************************************************
** uapkiprivatekey.h
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
** Description: PKI private key handling class.
**
******************************************************************************/
#ifndef UAPKIPRIVATEKEY_H
#define UAPKIPRIVATEKEY_H

#include "uapkiconfig.h"
#include <list>
#include <openssl/evp.h>
#include <uabytearray.h>
#include "uapkipublickey.h"

typedef int fcnPassword_callback ( char *buf, int size, int rwflag, void *u );

/** Wrapper class for a private key
*/
class UAPKI_EXPORT UaPkiPrivateKey
{
public:
    UaPkiPrivateKey();
    UaPkiPrivateKey ( EVP_PKEY *pKey );
    UaPkiPrivateKey ( const UaPkiPrivateKey& );
    UaPkiPrivateKey& operator= ( const UaPkiPrivateKey& );
    ~UaPkiPrivateKey();

    operator const EVP_PKEY*() const;

    UaByteArray toDER() const;
    static UaPkiPrivateKey fromDER ( const UaByteArray &DERdata, UaPkiKeyType keyType );
    static UaPkiPrivateKey fromPEM ( const UaByteArray &PEMdata, const char *szPassword, fcnPassword_callback *pCallback = 0, void *pCBData = 0 );

    std::list<UaString> getErrors();

private:
    void addOpenSSLError() const;
    void addError(const UaString &sErr) const;
    mutable std::list<UaString> m_lstErrors;

    EVP_PKEY *m_pPrivateKey;
};

#endif
