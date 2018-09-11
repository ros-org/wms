/******************************************************************************
** uacomplexnumbertype.h
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
** Portable UaComplexNumberType class.
**
******************************************************************************/
#ifndef UACOMPLEXNUMBERTYPE_H
#define UACOMPLEXNUMBERTYPE_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaComplexNumberTypePrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_ComplexNumberType.
 *
 *  This class encapsulates the native OpcUa_ComplexNumberType structure
 *  and handles memory allocation and cleanup for you.
 *  UaComplexNumberType uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared ComplexNumberType it creates a copy for that (copy-on-write).
 *  So assigning another UaComplexNumberType or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 */
class UABASE_EXPORT UaComplexNumberType
{
    UA_DECLARE_PRIVATE(UaComplexNumberType)
public:
    UaComplexNumberType();
    UaComplexNumberType(const UaComplexNumberType &other);
    UaComplexNumberType(const OpcUa_ComplexNumberType &other);
    UaComplexNumberType(
        OpcUa_Float real,
        OpcUa_Float imaginary
        );
    UaComplexNumberType(const UaExtensionObject &extensionObject);
    UaComplexNumberType(const OpcUa_ExtensionObject &extensionObject);
    UaComplexNumberType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaComplexNumberType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaComplexNumberType();

    void clear();

    bool operator==(const UaComplexNumberType &other) const;
    bool operator!=(const UaComplexNumberType &other) const;

    UaComplexNumberType& operator=(const UaComplexNumberType &other);

    OpcUa_ComplexNumberType* copy() const;
    void copyTo(OpcUa_ComplexNumberType *pDst) const;

    static OpcUa_ComplexNumberType* clone(const OpcUa_ComplexNumberType& source);
    static void cloneTo(const OpcUa_ComplexNumberType& source, OpcUa_ComplexNumberType& copy);

    void attach(OpcUa_ComplexNumberType *pValue);
    OpcUa_ComplexNumberType* detach(OpcUa_ComplexNumberType* pDst);

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

    OpcUa_StatusCode setComplexNumberType(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setComplexNumberType(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setComplexNumberType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setComplexNumberType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setComplexNumberType(
        OpcUa_Float real,
        OpcUa_Float imaginary
        );

    OpcUa_Float getReal() const;
    OpcUa_Float getImaginary() const;

    void setReal(OpcUa_Float real);
    void setImaginary(OpcUa_Float imaginary);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_ComplexNumberType.
 *
 *  This class encapsulates an array of the native OpcUa_ComplexNumberType structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaComplexNumberType for information about the encapsulated structure.
 */
class UABASE_EXPORT UaComplexNumberTypes
{
public:
    UaComplexNumberTypes();
    UaComplexNumberTypes(const UaComplexNumberTypes &other);
    UaComplexNumberTypes(OpcUa_Int32 length, OpcUa_ComplexNumberType* data);
    virtual ~UaComplexNumberTypes();

    UaComplexNumberTypes& operator=(const UaComplexNumberTypes &other);
    const OpcUa_ComplexNumberType& operator[](OpcUa_UInt32 index) const;
    OpcUa_ComplexNumberType& operator[](OpcUa_UInt32 index);

    bool operator==(const UaComplexNumberTypes &other) const;
    bool operator!=(const UaComplexNumberTypes &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_ComplexNumberType* data);
    void attach(OpcUa_Int32 length, OpcUa_ComplexNumberType* data);
    OpcUa_ComplexNumberType* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_ComplexNumberType* rawData() const {return m_data;}
    inline OpcUa_ComplexNumberType* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setComplexNumberTypes(const UaVariant &variant);
    OpcUa_StatusCode setComplexNumberTypes(const OpcUa_Variant &variant);
    OpcUa_StatusCode setComplexNumberTypes(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setComplexNumberTypes(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setComplexNumberTypes(OpcUa_Int32 length, OpcUa_ComplexNumberType* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_ComplexNumberType* m_data;
};

#endif // UACOMPLEXNUMBERTYPE_H

