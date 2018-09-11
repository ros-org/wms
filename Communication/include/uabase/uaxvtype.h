/******************************************************************************
** uaxvtype.h
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
** Portable UaXVType class.
**
******************************************************************************/
#ifndef UAXVTYPE_H
#define UAXVTYPE_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaXVTypePrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_XVType.
 *
 *  This class encapsulates the native OpcUa_XVType structure
 *  and handles memory allocation and cleanup for you.
 *  UaXVType uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared XVType it creates a copy for that (copy-on-write).
 *  So assigning another UaXVType or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  Defines a physical value relative to a X axis and it is used as the DataType of
 *  the Value of XYArrayItemType.
 *
 *  Most analysers can produce values that can perfectly be represented with a
 *  float IEEE 32 bits, but they can position them on the X axis with an accuracy
 *  that requires double IEEE 64 bits. For example, the peak value in an absorbance
 *  spectrum where the amplitude of the peak can be represented by a float IEEE 32
 *  bits, but its frequency position required 10 digits which implies the use of a
 *  double IEEE 64 bits.
 */
class UABASE_EXPORT UaXVType
{
    UA_DECLARE_PRIVATE(UaXVType)
public:
    UaXVType();
    UaXVType(const UaXVType &other);
    UaXVType(const OpcUa_XVType &other);
    UaXVType(
        OpcUa_Double x,
        OpcUa_Float value
        );
    UaXVType(const UaExtensionObject &extensionObject);
    UaXVType(const OpcUa_ExtensionObject &extensionObject);
    UaXVType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaXVType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaXVType();

    void clear();

    bool operator==(const UaXVType &other) const;
    bool operator!=(const UaXVType &other) const;

    UaXVType& operator=(const UaXVType &other);

    OpcUa_XVType* copy() const;
    void copyTo(OpcUa_XVType *pDst) const;

    static OpcUa_XVType* clone(const OpcUa_XVType& source);
    static void cloneTo(const OpcUa_XVType& source, OpcUa_XVType& copy);

    void attach(OpcUa_XVType *pValue);
    OpcUa_XVType* detach(OpcUa_XVType* pDst);

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

    OpcUa_StatusCode setXVType(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setXVType(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setXVType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setXVType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setXVType(
        OpcUa_Double x,
        OpcUa_Float value
        );

    OpcUa_Double getX() const;
    OpcUa_Float getValue() const;

    void setX(OpcUa_Double x);
    void setValue(OpcUa_Float value);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_XVType.
 *
 *  This class encapsulates an array of the native OpcUa_XVType structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaXVType for information about the encapsulated structure.
 */
class UABASE_EXPORT UaXVTypes
{
public:
    UaXVTypes();
    UaXVTypes(const UaXVTypes &other);
    UaXVTypes(OpcUa_Int32 length, OpcUa_XVType* data);
    virtual ~UaXVTypes();

    UaXVTypes& operator=(const UaXVTypes &other);
    const OpcUa_XVType& operator[](OpcUa_UInt32 index) const;
    OpcUa_XVType& operator[](OpcUa_UInt32 index);

    bool operator==(const UaXVTypes &other) const;
    bool operator!=(const UaXVTypes &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_XVType* data);
    void attach(OpcUa_Int32 length, OpcUa_XVType* data);
    OpcUa_XVType* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_XVType* rawData() const {return m_data;}
    inline OpcUa_XVType* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setXVTypes(const UaVariant &variant);
    OpcUa_StatusCode setXVTypes(const OpcUa_Variant &variant);
    OpcUa_StatusCode setXVTypes(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setXVTypes(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setXVTypes(OpcUa_Int32 length, OpcUa_XVType* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_XVType* m_data;
};

#endif // UAXVTYPE_H

