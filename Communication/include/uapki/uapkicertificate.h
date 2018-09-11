/******************************************************************************
** uapkicertificate.h
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
** Description: PKI certificate handling class.
**
******************************************************************************/
#ifndef UAPKICERTIFICATE_H
#define UAPKICERTIFICATE_H

#include "uapkiidentity.h"
#include "uapkirsakeypair.h"
#include "uadatetime.h"
#include "uaarraytemplates.h"
#include <list>

class UaPkiCertificateCollection;

/*! \addtogroup CppPkiLibraryClass
*  @{
*/

/** Class for handling X509 certificate signing requests.
* Can only be created by instances of UaPkiCertificate.
*/
class UAPKI_EXPORT UaPkiCSR
{
    friend class UaPkiCertificate;
    UaPkiCSR();
    UaPkiCSR(X509_REQ *pCSR);
    UaPkiCSR& operator=(const UaPkiCSR&);
public:
    UaPkiCSR(const UaPkiCSR &copy);
    ~UaPkiCSR();

    UaByteArray toDER() const;
    int toDERFile(const char *szFile) const;
    int toDERFile(const UaString &sFile) const;

    static UaPkiCSR fromDER(const UaByteArray &DERdata);
    static UaPkiCSR fromDERFile(const char *szFile);
    static UaPkiCSR fromDERFile(const UaString &sFile);

    inline bool isNull() const { return (m_pCSR == 0); }

    std::list<UaString> getErrors();

private:
    void addOpenSSLError() const;
    void addError(const UaString &sErr) const;

    mutable std::list<UaString>  m_lstErrors;
    X509_REQ                    *m_pCSR;
};

/** OPC UA specific certificate information. */
class UAPKI_EXPORT UaPkiCertificateInfo
{
public:
    UaPkiCertificateInfo() : validTime(0), serialNumber(0), validFrom(0) {}

    UaString URI;
    UaStringArray IPAddresses;
    UaStringArray DNSNames;
    UaString eMail;
    long validTime; ///< The time in seconds this certificate should be valid.
    long serialNumber; ///< The serial number of the certificate. If set to 0, the return value of time() is used.
    long validFrom; ///< The time in seconds when this certificates starts getting valid. 0 means now.
};

/** Class for handling X509 certificates.
*
*  This class encapsulates OpenSSL X509 functionality
*  and simplifies the certificate handling.
*
*  The following sample code demonstrates how to create a self signed certificate:
*  @code
*  UaPkiIdentity        ident;
*  UaPkiCertificateInfo info;
*  int                  bits = 2048;
*  ident.commonName = "MyGreatUaApp";
*  ident.organization = "ACME";
*  ident.organizationUnit = "Development Department";
*  ident.locality = "Schwabach";
*  ident.state = "Bavaria";
*  ident.country = "DE";
*  info.URI = "urn:myhostname:ACME:MyGreatUaApp";
*  info.IP = ""; // optional IP of no DNS is available
*  info.DNS = "opcua.acme.com";
*  info.validTime = 3600*24*365*5; // 5 years
*  info.serialNumber = 123;
*  // create key pair
*  UaPkiRsaKeyPair keyPair(bits);
*  // store key pair in a PEM encoded file without password
*  keyPair.toPEMFile("/path/to/mykey.pem", 0);
*  // create new certificate
*  UaPkiCertificate newCert(info, ident, keyPair);
*  // store certificate in a DER encoded file
*  newCert.toDERFile("/path/to/mycert.der");
*  @endcode
*
*  The following sample code demonstrates how to store a certificate as file, e.g. in the application trust list:
@code
void storeTrustedCertificate(const UaByteString& trustedCertificate, const UaString& sTrustListLocation)
{
    // Assign certificate byte string to UaPkiCertificate class
    UaByteArray      derCertificate(*(const OpcUa_ByteString*)trustedCertificate);
    UaPkiCertificate cert = UaPkiCertificate::fromDER(derCertificate);

    // Create file name for the certificate
    // Use the thumbprint as file name
    UaString sThumbPrint = cert.thumbPrint().toHex();
    UaString sFileName = sTrustListLocation;
    sFileName += "/";
    sFileName += sThumbPrint;
    sFileName += ".der";

    // Store certificate
    cert.toDERFile(sFileName.toUtf8());
}
@endcode
*/
class UAPKI_EXPORT UaPkiCertificate
{
public:
    /** Extensions Enumeration */
    enum Extension
    {
        Extension_SubjectAltName            = NID_subject_alt_name,
        Extension_BasicConstraints          = NID_basic_constraints,
        Extension_NetscapeComment           = NID_netscape_comment,
        Extension_SubjectKeyIdentifier      = NID_subject_key_identifier,
        Extension_AuthorityKeyIdentifier    = NID_authority_key_identifier,
        Extension_KeyUsage                  = NID_key_usage,
        Extension_ExtendedKeyUsage          = NID_ext_key_usage
    };
    /** SignaturAlgorithm Enumeration */
    enum SignatureAlgorithm
    {
        SignatureAlgorithm_Sha1,
        SignatureAlgorithm_Sha256
    };

    UaPkiCertificate();
    OPCUA_P_DEPRECATED(UaPkiCertificate ( const UaPkiCertificateInfo &info, const UaPkiIdentity &subject, const UaPkiPublicKey &subjectPublicKey, const UaPkiIdentity &issuer, const UaPkiPrivateKey &issuerPrivateKey ));
    UaPkiCertificate ( const UaPkiCertificateInfo &info,
                       const UaPkiIdentity &subject,
                       const UaPkiRsaKeyPair &subjectKeyPair,
                       bool bCACert = false,
                       SignatureAlgorithm signatureAlgorithm = SignatureAlgorithm_Sha1);
    UaPkiCertificate ( const UaPkiCertificateInfo &info,
                       const UaPkiIdentity &subject,
                       const UaPkiPublicKey &subjectPublicKey,
                       const UaPkiCertificate &issuerCert,
                       const UaPkiPrivateKey &issuerPrivateKey,
                       bool bCACert = false,
                       SignatureAlgorithm signatureAlgorithm = SignatureAlgorithm_Sha1);
    UaPkiCertificate( const UaPkiCertificate &copy );
    UaPkiCertificate( X509 *pCert );
    ~UaPkiCertificate();
    UaPkiCertificate& operator=( const UaPkiCertificate &copy );
    bool operator==( const UaPkiCertificate &other );

    UaPkiPublicKey publicKey() const;
    UaString commonName() const;
    UaPkiIdentity subject() const;
    UaPkiIdentity issuer() const;
    unsigned long subjectNameHash() const;
    UaPkiCertificateInfo info() const;
    UaDateTime validFrom() const;
    UaDateTime validTo() const;
    UaString serialNumber() const;
    int signatureTypeNID() const;
    UaString signatureTypeString() const;
    bool isValid() const;
    bool isSelfSigned() const;
    bool sign(const UaPkiCertificate &issuerCert, const UaPkiPrivateKey &issuerPrivateKey, SignatureAlgorithm signatureAlgorithm = SignatureAlgorithm_Sha1);
    bool verifySignature(const UaPkiPublicKey& issuerKey);
    SignatureAlgorithm signatureAlgorithm() const;

    // X509 extensions
    bool hasExtension(UaPkiCertificate::Extension extension) const;
    UaString extensionValue(UaPkiCertificate::Extension extension) const;

    UaByteArray toDER() const;
    UaByteString toByteStringDER() const;
    int toDERFile ( const char *szFile ) const;
    int toDERFile ( const UaString &sFile ) const;
    int toPEMFile ( const char *szFile ) const;
    int toPEMFile ( const UaString &sFile ) const;
    UaByteArray thumbPrint() const;
    static UaByteArray thumbPrint(const UaByteArray &DERData);

    inline bool isNull() const { return (m_pCert == 0); }

    static UaPkiCertificate fromDER ( const UaByteArray &DERdata );
    static UaPkiCertificate fromDER ( const UaByteString &DERdata );
    static UaPkiCertificate fromDERFile ( const char *szFile );
    static UaPkiCertificate fromDERFile ( const UaString &sFile );
    static UaPkiCertificate fromPEMFile ( const char *szFile );
    static UaPkiCertificate fromPEMFile ( const UaString &sFile );

    // CSR handling
    UaPkiCSR createCSR(const UaPkiPrivateKey &subjectPrivateKey, SignatureAlgorithm signatureAlgorithm);
    static UaPkiCSR createCSR(const UaPkiCertificateInfo &info,
                              const UaPkiIdentity &subject,
                              const UaPkiRsaKeyPair &subjectKeyPair,
                              SignatureAlgorithm signatureAlgorithm,
                              bool bCACert = false);
    static UaPkiCertificate fromCSR(const UaPkiCSR &inCSR,
                                    const UaPkiCertificate &issuerCert,
                                    const UaPkiPrivateKey &issuerPrivateKey,
                                    long validTime,
                                    long serialNumber,
                                    SignatureAlgorithm signatureAlgorithm);

#if OPCUA_SUPPORT_PKI_WIN32
    int toWindowsStore(WindowsStoreLocation location, const UaString &sStoreName) const;
    int toWindowsStoreWithPrivateKey(WindowsStoreLocation location, const UaString &sStoreName, const UaPkiRsaKeyPair &subjectKeyPair) const;

    static UaPkiCertificate fromWindowsStore(WindowsStoreLocation location, const UaString &sStoreName, const UaByteArray &baThumbprint);
    static UaPkiCertificate fromWindowsStoreWithPrivateKey(WindowsStoreLocation location, const UaString &sStoreName, const UaByteArray &baThumbprint, UaPkiRsaKeyPair &subjectKeyPair);

    static int deleteFromWindowsStore(WindowsStoreLocation location, const UaString &sStoreName, const UaByteArray &baThumbprint);

    static UaPkiCertificate nextCertInWindowsStore(WindowsStoreLocation location, const UaString &sStoreName, const UaPkiCertificate &previous = UaPkiCertificate());
#endif // OPCUA_SUPPORT_PKI_WIN32

    std::list<UaString> getErrors();

    static UaDateTime convertAsn1UtcTimeToDateTime(const char *szAsn1UtcTime, bool *pbOK = 0);
    static UaDateTime convertAsn1GeneralizedTimeToDateTime(const char *szAsn1GeneralizedTime, bool *pbOK = 0);

private:
#if OPCUA_SUPPORT_PKI_WIN32
    void addWindowsError() const;
#endif // OPCUA_SUPPORT_PKI_WIN32
    void addOpenSSLError() const;
    void addError(const UaString &sErr) const;
    mutable std::list<UaString> m_lstErrors;

    UaString getNameEntryByNID(X509_NAME *pName, int id) const;
    UaString getExtensionByNID(int id) const;
    static X509_NAME* createX509_NAME(const UaPkiIdentity &identity);
    static X509_EXTENSION* createSubjectAltName(X509V3_CTX *pCtx, const UaPkiCertificateInfo &info);
    X509 *m_pCert;
};

/** UaPkiCertificateCollection
*  OPC UA specific certificate collection.
*/
class UAPKI_EXPORT UaPkiCertificateCollection
{
public:
    UaPkiCertificateCollection();
    ~UaPkiCertificateCollection();

    void addCertificate(const UaPkiCertificate &cert);
    int size() const;
    UaPkiCertificate certificate(int index) const;
    UaPkiCertificate operator[](int index) const;

private:
    std::list<UaPkiCertificate> m_lstCertificates;
};
/*! @} */

#endif
