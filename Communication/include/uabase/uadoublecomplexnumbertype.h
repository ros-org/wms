/******************************************************************************
** uadoublecomplexnumbertype.h
**
** Copyright (c) 2006-2016 Unified Automation GmbH All rights reserved.
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
** Portable UaDoubleComplexNumberType class.
**
******************************************************************************/
#ifndef UADOUBLECOMPLEXNUMBERTYPE_H
#define UADOUBLECOMPLEXNUMBERTYPE_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaDoubleComplexNumberTypePrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_DoubleComplexNumberType.
 *
 *  This class encapsulates the native OpcUa_DoubleComplexNumberType structure
 *  and handles memory allocation and cleanup for you.
 *  UaDoubleComplexNumberType uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared DoubleComplexNumberType it creates a copy for that (copy-on-write).
 *  So assigning another UaDoubleComplexNumberType or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 */
class UABASE_EXPORT UaDoubleComplexNumberType
{
    UA_DECLARE_PRIVATE(UaDoubleComplexNumberType)
public:
    UaDoubleComplexNumberType();
    UaDoubleComplexNumberType(const UaDoubleComplexNumberType &other);
    UaDoubleComplexNumberType(const OpcUa_DoubleComplexNumberType &other);
    UaDoubleComplexNumberType(
        OpcUa_Double real,
        OpcUa_Double imaginary
        );
    UaDoubleComplexNumberType(const UaExtensionObject &extensionObject);
    UaDoubleComplexNumberType(const OpcUa_ExtensionObject &extensionObject);
    UaDoubleComplexNumberType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaDoubleComplexNumberType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaDoubleComplexNumberType();

    void clear();

    bool operator==(const UaDoubleComplexNumberType &other) const;
    bool operator!=(const UaDoubleComplexNumberType &other) const;

    UaDoubleComplexNumberType& operator=(const UaDoubleComplexNumberType &other);

    OpcUa_DoubleComplexNumberType* copy() const;
    void copyTo(OpcUa_DoubleComplexNumberType *pDst) const;

    static OpcUa_DoubleComplexNumberType* clone(const OpcUa_DoubleComplexNumberType& source);
    static void cloneTo(const OpcUa_DoubleComplexNumberType& source, OpcUa_DoubleComplexNumberType& copy);

    void attach(OpcUa_DoubleComplexNumberType *pValue);
    OpcUa_DoubleComplexNumberType* detach(OpcUa_DoubleComplexNumberType* pDst);

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

    OpcUa_StatusCode setDoubleComplexNumberType(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setDoubleComplexNumberType(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setDoubleComplexNumberType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setDoubleComplexNumberType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setDoubleComplexNumberType(
        OpcUa_Double real,
        OpcUa_Double imaginary
        );

    OpcUa_Double getReal() const;
    OpcUa_Double getImaginary() const;

    void setReal(OpcUa_Double real);
    void setImaginary(OpcUa_Double imaginary);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_DoubleComplexNumberType.
 *
 *  This class encapsulates an array of the native OpcUa_DoubleComplexNumberType structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaDoubleComplexNumberType for information about the encapsulated structure.
 */
class UABASE_EXPORT UaDoubleComplexNumberTypes
{
public:
    UaDoubleComplexNumberTypes();
    UaDoubleComplexNumberTypes(const UaDoubleComplexNumberTypes &other);
    UaDoubleComplexNumberTypes(OpcUa_Int32 length, OpcUa_DoubleComplexNumberType* data);
    virtual ~UaDoubleComplexNumberTypes();

    UaDoubleComplexNumberTypes& operator=(const UaDoubleComplexNumberTypes &other);
    const OpcUa_DoubleComplexNumberType& operator[](OpcUa_UInt32 index) const;
    OpcUa_DoubleComplexNumberType& operator[](OpcUa_UInt32 index);

    bool operator==(const UaDoubleComplexNumberTypes &other) const;
    bool operator!=(const UaDoubleComplexNumberTypes &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_DoubleComplexNumberType* data);
    void attach(OpcUa_Int32 length, OpcUa_DoubleComplexNumberType* data);
    OpcUa_DoubleComplexNumberType* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_DoubleComplexNumberType* rawData() const {return m_data;}
    inline OpcUa_DoubleComplexNumberType* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setDoubleComplexNumberTypes(const UaVariant &variant);
    OpcUa_StatusCode setDoubleComplexNumberTypes(const OpcUa_Variant &variant);
    OpcUa_StatusCode setDoubleComplexNumberTypes(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setDoubleComplexNumberTypes(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setDoubleComplexNumberTypes(OpcUa_Int32 length, OpcUa_DoubleComplexNumberType* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_DoubleComplexNumberType* m_data;
};

#endif // UADOUBLECOMPLEXNUMBERTYPE_H

