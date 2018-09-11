/******************************************************************************
** uatrustlistdatatype.h
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
** Portable UaTrustListDataType class.
**
******************************************************************************/
#ifndef UATRUSTLISTDATATYPE_H
#define UATRUSTLISTDATATYPE_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uabytestring.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaTrustListDataTypePrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_TrustListDataType.
 *
 *  This class encapsulates the native OpcUa_TrustListDataType structure
 *  and handles memory allocation and cleanup for you.
 *  UaTrustListDataType uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared TrustListDataType it creates a copy for that (copy-on-write).
 *  So assigning another UaTrustListDataType or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 */
class UABASE_EXPORT UaTrustListDataType
{
    UA_DECLARE_PRIVATE(UaTrustListDataType)
public:
    UaTrustListDataType();
    UaTrustListDataType(const UaTrustListDataType &other);
    UaTrustListDataType(const OpcUa_TrustListDataType &other);
    UaTrustListDataType(
        OpcUa_UInt32 specifiedLists,
        const UaByteStringArray &trustedCertificates,
        const UaByteStringArray &trustedCrls,
        const UaByteStringArray &issuerCertificates,
        const UaByteStringArray &issuerCrls
        );
    UaTrustListDataType(const UaExtensionObject &extensionObject);
    UaTrustListDataType(const OpcUa_ExtensionObject &extensionObject);
    UaTrustListDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaTrustListDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaTrustListDataType();

    void clear();

    bool operator==(const UaTrustListDataType &other) const;
    bool operator!=(const UaTrustListDataType &other) const;

    UaTrustListDataType& operator=(const UaTrustListDataType &other);

    OpcUa_TrustListDataType* copy() const;
    void copyTo(OpcUa_TrustListDataType *pDst) const;

    static OpcUa_TrustListDataType* clone(const OpcUa_TrustListDataType& source);
    static void cloneTo(const OpcUa_TrustListDataType& source, OpcUa_TrustListDataType& copy);

    void attach(OpcUa_TrustListDataType *pValue);
    OpcUa_TrustListDataType* detach(OpcUa_TrustListDataType* pDst);

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

    OpcUa_StatusCode setTrustListDataType(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setTrustListDataType(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setTrustListDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setTrustListDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setTrustListDataType(
        OpcUa_UInt32 specifiedLists,
        const UaByteStringArray &trustedCertificates,
        const UaByteStringArray &trustedCrls,
        const UaByteStringArray &issuerCertificates,
        const UaByteStringArray &issuerCrls
        );

    OpcUa_UInt32 getSpecifiedLists() const;
    void getTrustedCertificates(UaByteStringArray& trustedCertificates) const;
    void getTrustedCrls(UaByteStringArray& trustedCrls) const;
    void getIssuerCertificates(UaByteStringArray& issuerCertificates) const;
    void getIssuerCrls(UaByteStringArray& issuerCrls) const;

    void setSpecifiedLists(OpcUa_UInt32 specifiedLists);
    void setTrustedCertificates(const UaByteStringArray &trustedCertificates);
    void setTrustedCrls(const UaByteStringArray &trustedCrls);
    void setIssuerCertificates(const UaByteStringArray &issuerCertificates);
    void setIssuerCrls(const UaByteStringArray &issuerCrls);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_TrustListDataType.
 *
 *  This class encapsulates an array of the native OpcUa_TrustListDataType structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaTrustListDataType for information about the encapsulated structure.
 */
class UABASE_EXPORT UaTrustListDataTypes
{
public:
    UaTrustListDataTypes();
    UaTrustListDataTypes(const UaTrustListDataTypes &other);
    UaTrustListDataTypes(OpcUa_Int32 length, OpcUa_TrustListDataType* data);
    virtual ~UaTrustListDataTypes();

    UaTrustListDataTypes& operator=(const UaTrustListDataTypes &other);
    const OpcUa_TrustListDataType& operator[](OpcUa_UInt32 index) const;
    OpcUa_TrustListDataType& operator[](OpcUa_UInt32 index);

    bool operator==(const UaTrustListDataTypes &other) const;
    bool operator!=(const UaTrustListDataTypes &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_TrustListDataType* data);
    void attach(OpcUa_Int32 length, OpcUa_TrustListDataType* data);
    OpcUa_TrustListDataType* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_TrustListDataType* rawData() const {return m_data;}
    inline OpcUa_TrustListDataType* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setTrustListDataTypes(const UaVariant &variant);
    OpcUa_StatusCode setTrustListDataTypes(const OpcUa_Variant &variant);
    OpcUa_StatusCode setTrustListDataTypes(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setTrustListDataTypes(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setTrustListDataTypes(OpcUa_Int32 length, OpcUa_TrustListDataType* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_TrustListDataType* m_data;
};

#endif // UATRUSTLISTDATATYPE_H

