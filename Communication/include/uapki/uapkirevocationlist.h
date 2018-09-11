/******************************************************************************
** uapkirevocationlist.h
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
** Description: PKI certificate revocation list handling class.
**
******************************************************************************/
#ifndef UAPKIREVOCATIONLIST_H
#define UAPKIREVOCATIONLIST_H

#include "uapkiconfig.h"
#include "uapkicertificate.h"
#include "uapkiidentity.h"
#include "uapkirsakeypair.h"
#include "uabytearray.h"
#include "uadatetime.h"
#include <openssl/x509.h>

/*! \addtogroup CppPkiLibraryClass
*  @{
*/

/** Class for handling revocation lists.
*  The following sample demonstrates how to create a revocation list.
*  @code
*  UaPkiIdentity        issuer;
*  issuer.commonName = "Example Company";
*  issuer.organization = "ACME";
*  issuer.organizationUnit = "Development Department";
*  issuer.locality = "Schwabach";
*  issuer.state = "Bavaria";
*  issuer.country = "DE";
*  // create new keypair
*  int                  bits = 2048;
*  UaPkiRsaKeyPair      keyPairIssuer(bits);
*  // create new revocation list with validity set to 5 years and CrlNumber 0
*  UaPkiRevocationList revocationList(3600*24*365*5, issuer, 0);
*  // add a certificate to the list
*  UaPkiCertificate certToRevoke = UaPkiCertificate::fromDERFile("/path/to/certToRevoke.der");
*  revocationList.addRevoked(certToRevoke, UaDateTime::now());
*  // sign the list
*  revocationList.sign(keyPairIssuer.privateKey());
*  // store revocation list in a DER encoded file
*  revocationList.toPEMFile("/path/to/myrevocationlist.crl");
*  @endcode
*/
class UAPKI_EXPORT UaPkiRevocationList
{
public:
    UaPkiRevocationList();
    UaPkiRevocationList( long validity, const UaPkiIdentity &issuer, long iCrlNumber );
    UaPkiRevocationList( const UaPkiRevocationList &copy );
    ~UaPkiRevocationList();

    UaPkiRevocationList& operator=( const UaPkiRevocationList &copy );
    bool operator==( const UaPkiRevocationList &other ) const;
    void addRevoked(const UaPkiCertificate &cert, const UaDateTime &revocationDate);
    bool verify(const UaPkiPrivateKey &issuerPrivateKey) const;
    bool sign(const UaPkiPrivateKey &issuerPrivateKey);
    inline bool isNull() const { return (m_pCrl == 0); }
    UaDateTime validFrom() const;
    UaDateTime nextUpdate() const;
    bool isValid() const;

    UaPkiIdentity issuer() const;
    long crlNumber() const;

    // to/from file/bytestring
    UaByteArray toDER() const;
    int toDERFile ( const char *szFile ) const;
    int toDERFile ( const UaString &sFile ) const;
    int toPEMFile ( const char *szFile ) const;
    int toPEMFile ( const UaString &sFile ) const;

    static UaPkiRevocationList fromDER ( const UaByteArray &DERdata );
    static UaPkiRevocationList fromFile ( const char *szFile );
    static UaPkiRevocationList fromFile ( const UaString &sFile );

#if OPCUA_SUPPORT_PKI_WIN32
    int toWindowsStore(WindowsStoreLocation location, const UaString &sStoreName) const;
    static UaPkiRevocationList fromWindowsStore(WindowsStoreLocation location,
                                                const UaString &sStoreName,
                                                const UaPkiIdentity &issuer,
                                                long iCrlNumber = -1);
#endif // OPCUA_SUPPORT_PKI_WIN32

    std::list<UaString> getErrors();

private:
#if OPCUA_SUPPORT_PKI_WIN32
    void addWindowsError() const;
#endif // OPCUA_SUPPORT_PKI_WIN32
    void addOpenSSLError() const;
    void addError(const UaString &sErr) const;
    mutable std::list<UaString> m_lstErrors;

    UaString getNameEntryByNID( X509_NAME *pName, int id ) const;
    X509_CRL *m_pCrl;
};

/*! @} */

#endif
