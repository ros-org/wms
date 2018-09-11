/******************************************************************************
** uatimezonedatatype.h
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
** Portable UaTimeZoneDataType class.
**
******************************************************************************/
#ifndef UATIMEZONEDATATYPE_H
#define UATIMEZONEDATATYPE_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaTimeZoneDataTypePrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_TimeZoneDataType.
 *
 *  This class encapsulates the native OpcUa_TimeZoneDataType structure
 *  and handles memory allocation and cleanup for you.
 *  UaTimeZoneDataType uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared TimeZoneDataType it creates a copy for that (copy-on-write).
 *  So assigning another UaTimeZoneDataType or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  The local time that may or may not take daylight saving time into account.
 */
class UABASE_EXPORT UaTimeZoneDataType
{
    UA_DECLARE_PRIVATE(UaTimeZoneDataType)
public:
    UaTimeZoneDataType();
    UaTimeZoneDataType(const UaTimeZoneDataType &other);
    UaTimeZoneDataType(const OpcUa_TimeZoneDataType &other);
    UaTimeZoneDataType(
        OpcUa_Int16 offset,
        OpcUa_Boolean daylightSavingInOffset
        );
    UaTimeZoneDataType(const UaExtensionObject &extensionObject);
    UaTimeZoneDataType(const OpcUa_ExtensionObject &extensionObject);
    UaTimeZoneDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaTimeZoneDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaTimeZoneDataType();

    void clear();

    bool operator==(const UaTimeZoneDataType &other) const;
    bool operator!=(const UaTimeZoneDataType &other) const;

    UaTimeZoneDataType& operator=(const UaTimeZoneDataType &other);

    OpcUa_TimeZoneDataType* copy() const;
    void copyTo(OpcUa_TimeZoneDataType *pDst) const;

    static OpcUa_TimeZoneDataType* clone(const OpcUa_TimeZoneDataType& source);
    static void cloneTo(const OpcUa_TimeZoneDataType& source, OpcUa_TimeZoneDataType& copy);

    void attach(OpcUa_TimeZoneDataType *pValue);
    OpcUa_TimeZoneDataType* detach(OpcUa_TimeZoneDataType* pDst);

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

    OpcUa_StatusCode setTimeZoneDataType(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setTimeZoneDataType(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setTimeZoneDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setTimeZoneDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setTimeZoneDataType(
        OpcUa_Int16 offset,
        OpcUa_Boolean daylightSavingInOffset
        );

    OpcUa_Int16 getOffset() const;
    OpcUa_Boolean getDaylightSavingInOffset() const;

    void setOffset(OpcUa_Int16 offset);
    void setDaylightSavingInOffset(OpcUa_Boolean daylightSavingInOffset);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_TimeZoneDataType.
 *
 *  This class encapsulates an array of the native OpcUa_TimeZoneDataType structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaTimeZoneDataType for information about the encapsulated structure.
 */
class UABASE_EXPORT UaTimeZoneDataTypes
{
public:
    UaTimeZoneDataTypes();
    UaTimeZoneDataTypes(const UaTimeZoneDataTypes &other);
    UaTimeZoneDataTypes(OpcUa_Int32 length, OpcUa_TimeZoneDataType* data);
    virtual ~UaTimeZoneDataTypes();

    UaTimeZoneDataTypes& operator=(const UaTimeZoneDataTypes &other);
    const OpcUa_TimeZoneDataType& operator[](OpcUa_UInt32 index) const;
    OpcUa_TimeZoneDataType& operator[](OpcUa_UInt32 index);

    bool operator==(const UaTimeZoneDataTypes &other) const;
    bool operator!=(const UaTimeZoneDataTypes &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_TimeZoneDataType* data);
    void attach(OpcUa_Int32 length, OpcUa_TimeZoneDataType* data);
    OpcUa_TimeZoneDataType* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_TimeZoneDataType* rawData() const {return m_data;}
    inline OpcUa_TimeZoneDataType* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setTimeZoneDataTypes(const UaVariant &variant);
    OpcUa_StatusCode setTimeZoneDataTypes(const OpcUa_Variant &variant);
    OpcUa_StatusCode setTimeZoneDataTypes(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setTimeZoneDataTypes(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setTimeZoneDataTypes(OpcUa_Int32 length, OpcUa_TimeZoneDataType* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_TimeZoneDataType* m_data;
};

#endif // UATIMEZONEDATATYPE_H

