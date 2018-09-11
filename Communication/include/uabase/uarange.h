/******************************************************************************
** uarange.h
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
** Portable UaRange class.
**
******************************************************************************/
#ifndef UARANGE_H
#define UARANGE_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaRangePrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_Range.
 *
 *  This class encapsulates the native OpcUa_Range structure
 *  and handles memory allocation and cleanup for you.
 *  UaRange uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared Range it creates a copy for that (copy-on-write).
 *  So assigning another UaRange or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  Defines the Range for a value.
 */
class UABASE_EXPORT UaRange
{
    UA_DECLARE_PRIVATE(UaRange)
public:
    UaRange();
    UaRange(const UaRange &other);
    UaRange(const OpcUa_Range &other);
    UaRange(
        OpcUa_Double low,
        OpcUa_Double high
        );
    UaRange(const UaExtensionObject &extensionObject);
    UaRange(const OpcUa_ExtensionObject &extensionObject);
    UaRange(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaRange(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaRange();

    void clear();

    bool operator==(const UaRange &other) const;
    bool operator!=(const UaRange &other) const;

    UaRange& operator=(const UaRange &other);

    OpcUa_Range* copy() const;
    void copyTo(OpcUa_Range *pDst) const;

    static OpcUa_Range* clone(const OpcUa_Range& source);
    static void cloneTo(const OpcUa_Range& source, OpcUa_Range& copy);

    void attach(OpcUa_Range *pValue);
    OpcUa_Range* detach(OpcUa_Range* pDst);

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

    OpcUa_StatusCode setRange(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setRange(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setRange(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setRange(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setRange(
        OpcUa_Double low,
        OpcUa_Double high
        );

    OpcUa_Double getLow() const;
    OpcUa_Double getHigh() const;

    void setLow(OpcUa_Double low);
    void setHigh(OpcUa_Double high);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_Range.
 *
 *  This class encapsulates an array of the native OpcUa_Range structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaRange for information about the encapsulated structure.
 */
class UABASE_EXPORT UaRanges
{
public:
    UaRanges();
    UaRanges(const UaRanges &other);
    UaRanges(OpcUa_Int32 length, OpcUa_Range* data);
    virtual ~UaRanges();

    UaRanges& operator=(const UaRanges &other);
    const OpcUa_Range& operator[](OpcUa_UInt32 index) const;
    OpcUa_Range& operator[](OpcUa_UInt32 index);

    bool operator==(const UaRanges &other) const;
    bool operator!=(const UaRanges &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_Range* data);
    void attach(OpcUa_Int32 length, OpcUa_Range* data);
    OpcUa_Range* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_Range* rawData() const {return m_data;}
    inline OpcUa_Range* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setRanges(const UaVariant &variant);
    OpcUa_StatusCode setRanges(const OpcUa_Variant &variant);
    OpcUa_StatusCode setRanges(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setRanges(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setRanges(OpcUa_Int32 length, OpcUa_Range* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_Range* m_data;
};

#endif // UARANGE_H

