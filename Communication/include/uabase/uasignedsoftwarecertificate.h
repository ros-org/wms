/******************************************************************************
** uasignedsoftwarecertificate.h
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
** Portable UaSignedSoftwareCertificate class.
**
******************************************************************************/
#ifndef UASIGNEDSOFTWARECERTIFICATE_H
#define UASIGNEDSOFTWARECERTIFICATE_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uabytestring.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaSignedSoftwareCertificatePrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_SignedSoftwareCertificate.
 *
 *  This class encapsulates the native OpcUa_SignedSoftwareCertificate structure
 *  and handles memory allocation and cleanup for you.
 *  UaSignedSoftwareCertificate uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared SignedSoftwareCertificate it creates a copy for that (copy-on-write).
 *  So assigning another UaSignedSoftwareCertificate or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  A ByteString containing an encoded Certificate.
 *
 *  The encoding of a SignedSoftwareCertificate depends on the security technology
 *  mapping and is defined completely in Part 6 of the OPC UA Specification.
 */
class UABASE_EXPORT UaSignedSoftwareCertificate
{
    UA_DECLARE_PRIVATE(UaSignedSoftwareCertificate)
public:
    UaSignedSoftwareCertificate();
    UaSignedSoftwareCertificate(const UaSignedSoftwareCertificate &other);
    UaSignedSoftwareCertificate(const OpcUa_SignedSoftwareCertificate &other);
    UaSignedSoftwareCertificate(
        const UaByteString& certificateData,
        const UaByteString& signature
        );
    UaSignedSoftwareCertificate(const UaExtensionObject &extensionObject);
    UaSignedSoftwareCertificate(const OpcUa_ExtensionObject &extensionObject);
    UaSignedSoftwareCertificate(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaSignedSoftwareCertificate(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaSignedSoftwareCertificate();

    void clear();

    bool operator==(const UaSignedSoftwareCertificate &other) const;
    bool operator!=(const UaSignedSoftwareCertificate &other) const;

    UaSignedSoftwareCertificate& operator=(const UaSignedSoftwareCertificate &other);

    OpcUa_SignedSoftwareCertificate* copy() const;
    void copyTo(OpcUa_SignedSoftwareCertificate *pDst) const;

    static OpcUa_SignedSoftwareCertificate* clone(const OpcUa_SignedSoftwareCertificate& source);
    static void cloneTo(const OpcUa_SignedSoftwareCertificate& source, OpcUa_SignedSoftwareCertificate& copy);

    void attach(OpcUa_SignedSoftwareCertificate *pValue);
    OpcUa_SignedSoftwareCertificate* detach(OpcUa_SignedSoftwareCertificate* pDst);

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

    OpcUa_StatusCode setSignedSoftwareCertificate(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setSignedSoftwareCertificate(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setSignedSoftwareCertificate(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSignedSoftwareCertificate(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setSignedSoftwareCertificate(
        const UaByteString& certificateData,
        const UaByteString& signature
        );

    UaByteString getCertificateData() const;
    UaByteString getSignature() const;

    void setCertificateData(const UaByteString& certificateData);
    void setSignature(const UaByteString& signature);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_SignedSoftwareCertificate.
 *
 *  This class encapsulates an array of the native OpcUa_SignedSoftwareCertificate structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaSignedSoftwareCertificate for information about the encapsulated structure.
 */
class UABASE_EXPORT UaSignedSoftwareCertificates
{
public:
    UaSignedSoftwareCertificates();
    UaSignedSoftwareCertificates(const UaSignedSoftwareCertificates &other);
    UaSignedSoftwareCertificates(OpcUa_Int32 length, OpcUa_SignedSoftwareCertificate* data);
    virtual ~UaSignedSoftwareCertificates();

    UaSignedSoftwareCertificates& operator=(const UaSignedSoftwareCertificates &other);
    const OpcUa_SignedSoftwareCertificate& operator[](OpcUa_UInt32 index) const;
    OpcUa_SignedSoftwareCertificate& operator[](OpcUa_UInt32 index);

    bool operator==(const UaSignedSoftwareCertificates &other) const;
    bool operator!=(const UaSignedSoftwareCertificates &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_SignedSoftwareCertificate* data);
    void attach(OpcUa_Int32 length, OpcUa_SignedSoftwareCertificate* data);
    OpcUa_SignedSoftwareCertificate* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_SignedSoftwareCertificate* rawData() const {return m_data;}
    inline OpcUa_SignedSoftwareCertificate* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setSignedSoftwareCertificates(const UaVariant &variant);
    OpcUa_StatusCode setSignedSoftwareCertificates(const OpcUa_Variant &variant);
    OpcUa_StatusCode setSignedSoftwareCertificates(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSignedSoftwareCertificates(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSignedSoftwareCertificates(OpcUa_Int32 length, OpcUa_SignedSoftwareCertificate* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_SignedSoftwareCertificate* m_data;
};

#endif // UASIGNEDSOFTWARECERTIFICATE_H

