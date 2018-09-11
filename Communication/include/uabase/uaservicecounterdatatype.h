/******************************************************************************
** uaservicecounterdatatype.h
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
** Portable UaServiceCounterDataType class.
**
******************************************************************************/
#ifndef UASERVICECOUNTERDATATYPE_H
#define UASERVICECOUNTERDATATYPE_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaServiceCounterDataTypePrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_ServiceCounterDataType.
 *
 *  This class encapsulates the native OpcUa_ServiceCounterDataType structure
 *  and handles memory allocation and cleanup for you.
 *  UaServiceCounterDataType uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared ServiceCounterDataType it creates a copy for that (copy-on-write).
 *  So assigning another UaServiceCounterDataType or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  Contains diagnostic information about subscriptions.
 */
class UABASE_EXPORT UaServiceCounterDataType
{
    UA_DECLARE_PRIVATE(UaServiceCounterDataType)
public:
    UaServiceCounterDataType();
    UaServiceCounterDataType(const UaServiceCounterDataType &other);
    UaServiceCounterDataType(const OpcUa_ServiceCounterDataType &other);
    UaServiceCounterDataType(
        OpcUa_UInt32 totalCount,
        OpcUa_UInt32 errorCount
        );
    UaServiceCounterDataType(const UaExtensionObject &extensionObject);
    UaServiceCounterDataType(const OpcUa_ExtensionObject &extensionObject);
    UaServiceCounterDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaServiceCounterDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaServiceCounterDataType();

    void clear();

    bool operator==(const UaServiceCounterDataType &other) const;
    bool operator!=(const UaServiceCounterDataType &other) const;

    UaServiceCounterDataType& operator=(const UaServiceCounterDataType &other);

    OpcUa_ServiceCounterDataType* copy() const;
    void copyTo(OpcUa_ServiceCounterDataType *pDst) const;

    static OpcUa_ServiceCounterDataType* clone(const OpcUa_ServiceCounterDataType& source);
    static void cloneTo(const OpcUa_ServiceCounterDataType& source, OpcUa_ServiceCounterDataType& copy);

    void attach(OpcUa_ServiceCounterDataType *pValue);
    OpcUa_ServiceCounterDataType* detach(OpcUa_ServiceCounterDataType* pDst);

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

    OpcUa_StatusCode setServiceCounterDataType(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setServiceCounterDataType(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setServiceCounterDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setServiceCounterDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setServiceCounterDataType(
        OpcUa_UInt32 totalCount,
        OpcUa_UInt32 errorCount
        );

    OpcUa_UInt32 getTotalCount() const;
    OpcUa_UInt32 getErrorCount() const;

    void setTotalCount(OpcUa_UInt32 totalCount);
    void setErrorCount(OpcUa_UInt32 errorCount);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_ServiceCounterDataType.
 *
 *  This class encapsulates an array of the native OpcUa_ServiceCounterDataType structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaServiceCounterDataType for information about the encapsulated structure.
 */
class UABASE_EXPORT UaServiceCounterDataTypes
{
public:
    UaServiceCounterDataTypes();
    UaServiceCounterDataTypes(const UaServiceCounterDataTypes &other);
    UaServiceCounterDataTypes(OpcUa_Int32 length, OpcUa_ServiceCounterDataType* data);
    virtual ~UaServiceCounterDataTypes();

    UaServiceCounterDataTypes& operator=(const UaServiceCounterDataTypes &other);
    const OpcUa_ServiceCounterDataType& operator[](OpcUa_UInt32 index) const;
    OpcUa_ServiceCounterDataType& operator[](OpcUa_UInt32 index);

    bool operator==(const UaServiceCounterDataTypes &other) const;
    bool operator!=(const UaServiceCounterDataTypes &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_ServiceCounterDataType* data);
    void attach(OpcUa_Int32 length, OpcUa_ServiceCounterDataType* data);
    OpcUa_ServiceCounterDataType* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_ServiceCounterDataType* rawData() const {return m_data;}
    inline OpcUa_ServiceCounterDataType* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setServiceCounterDataTypes(const UaVariant &variant);
    OpcUa_StatusCode setServiceCounterDataTypes(const OpcUa_Variant &variant);
    OpcUa_StatusCode setServiceCounterDataTypes(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setServiceCounterDataTypes(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setServiceCounterDataTypes(OpcUa_Int32 length, OpcUa_ServiceCounterDataType* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_ServiceCounterDataType* m_data;
};

#endif // UASERVICECOUNTERDATATYPE_H

