/******************************************************************************
** uasoftwarecertificate.h
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
** Portable UaSoftwareCertificate class.
**
******************************************************************************/
#ifndef UASOFTWARECERTIFICATE_H
#define UASOFTWARECERTIFICATE_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uabytestring.h"
#include "uadatetime.h"
#include "uastring.h"
#include "uasupportedprofile.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaSoftwareCertificatePrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_SoftwareCertificate.
 *
 *  This class encapsulates the native OpcUa_SoftwareCertificate structure
 *  and handles memory allocation and cleanup for you.
 *  UaSoftwareCertificate uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared SoftwareCertificate it creates a copy for that (copy-on-write).
 *  So assigning another UaSoftwareCertificate or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  A Certificate describing a product.
 */
class UABASE_EXPORT UaSoftwareCertificate
{
    UA_DECLARE_PRIVATE(UaSoftwareCertificate)
public:
    UaSoftwareCertificate();
    UaSoftwareCertificate(const UaSoftwareCertificate &other);
    UaSoftwareCertificate(const OpcUa_SoftwareCertificate &other);
    UaSoftwareCertificate(
        const UaString& productName,
        const UaString& productUri,
        const UaString& vendorName,
        const UaByteString& vendorProductCertificate,
        const UaString& softwareVersion,
        const UaString& buildNumber,
        const UaDateTime& buildDate,
        const UaString& issuedBy,
        const UaDateTime& issueDate,
        const UaSupportedProfiles &supportedProfiles
        );
    UaSoftwareCertificate(const UaExtensionObject &extensionObject);
    UaSoftwareCertificate(const OpcUa_ExtensionObject &extensionObject);
    UaSoftwareCertificate(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaSoftwareCertificate(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaSoftwareCertificate();

    void clear();

    bool operator==(const UaSoftwareCertificate &other) const;
    bool operator!=(const UaSoftwareCertificate &other) const;

    UaSoftwareCertificate& operator=(const UaSoftwareCertificate &other);

    OpcUa_SoftwareCertificate* copy() const;
    void copyTo(OpcUa_SoftwareCertificate *pDst) const;

    static OpcUa_SoftwareCertificate* clone(const OpcUa_SoftwareCertificate& source);
    static void cloneTo(const OpcUa_SoftwareCertificate& source, OpcUa_SoftwareCertificate& copy);

    void attach(OpcUa_SoftwareCertificate *pValue);
    OpcUa_SoftwareCertificate* detach(OpcUa_SoftwareCertificate* pDst);

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    void toExtensionObject(UaExtensionObject &extensionObject) const;
    void toExtensionObject(OpcUa_ExtensionObject &extensionObject) const;
    void toExtensionObject(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    void toExtensionObject(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    OpcUa_StatusCode setSoftwareCertificate(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setSoftwareCertificate(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setSoftwareCertificate(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSoftwareCertificate(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setSoftwareCertificate(
        const UaString& productName,
        const UaString& productUri,
        const UaString& vendorName,
        const UaByteString& vendorProductCertificate,
        const UaString& softwareVersion,
        const UaString& buildNumber,
        const UaDateTime& buildDate,
        const UaString& issuedBy,
        const UaDateTime& issueDate,
        const UaSupportedProfiles &supportedProfiles
        );

    UaString getProductName() const;
    UaString getProductUri() const;
    UaString getVendorName() const;
    UaByteString getVendorProductCertificate() const;
    UaString getSoftwareVersion() const;
    UaString getBuildNumber() const;
    UaDateTime getBuildDate() const;
    UaString getIssuedBy() const;
    UaDateTime getIssueDate() const;
    void getSupportedProfiles(UaSupportedProfiles& supportedProfiles) const;

    void setProductName(const UaString& productName);
    void setProductUri(const UaString& productUri);
    void setVendorName(const UaString& vendorName);
    void setVendorProductCertificate(const UaByteString& vendorProductCertificate);
    void setSoftwareVersion(const UaString& softwareVersion);
    void setBuildNumber(const UaString& buildNumber);
    void setBuildDate(const UaDateTime& buildDate);
    void setIssuedBy(const UaString& issuedBy);
    void setIssueDate(const UaDateTime& issueDate);
    void setSupportedProfiles(const UaSupportedProfiles &supportedProfiles);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_SoftwareCertificate.
 *
 *  This class encapsulates an array of the native OpcUa_SoftwareCertificate structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaSoftwareCertificate for information about the encapsulated structure.
 */
class UABASE_EXPORT UaSoftwareCertificates
{
public:
    UaSoftwareCertificates();
    UaSoftwareCertificates(const UaSoftwareCertificates &other);
    UaSoftwareCertificates(OpcUa_Int32 length, OpcUa_SoftwareCertificate* data);
    virtual ~UaSoftwareCertificates();

    UaSoftwareCertificates& operator=(const UaSoftwareCertificates &other);
    const OpcUa_SoftwareCertificate& operator[](OpcUa_UInt32 index) const;
    OpcUa_SoftwareCertificate& operator[](OpcUa_UInt32 index);

    bool operator==(const UaSoftwareCertificates &other) const;
    bool operator!=(const UaSoftwareCertificates &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_SoftwareCertificate* data);
    void attach(OpcUa_Int32 length, OpcUa_SoftwareCertificate* data);
    OpcUa_SoftwareCertificate* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_SoftwareCertificate* rawData() const {return m_data;}
    inline OpcUa_SoftwareCertificate* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setSoftwareCertificates(const UaVariant &variant);
    OpcUa_StatusCode setSoftwareCertificates(const OpcUa_Variant &variant);
    OpcUa_StatusCode setSoftwareCertificates(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSoftwareCertificates(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSoftwareCertificates(OpcUa_Int32 length, OpcUa_SoftwareCertificate* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_SoftwareCertificate* m_data;
};

#endif // UASOFTWARECERTIFICATE_H

