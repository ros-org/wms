/******************************************************************************
** uasamplingintervaldiagnosticsdatatype.h
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
** Portable UaSamplingIntervalDiagnosticsDataType class.
**
******************************************************************************/
#ifndef UASAMPLINGINTERVALDIAGNOSTICSDATATYPE_H
#define UASAMPLINGINTERVALDIAGNOSTICSDATATYPE_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaSamplingIntervalDiagnosticsDataTypePrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_SamplingIntervalDiagnosticsDataType.
 *
 *  This class encapsulates the native OpcUa_SamplingIntervalDiagnosticsDataType structure
 *  and handles memory allocation and cleanup for you.
 *  UaSamplingIntervalDiagnosticsDataType uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared SamplingIntervalDiagnosticsDataType it creates a copy for that (copy-on-write).
 *  So assigning another UaSamplingIntervalDiagnosticsDataType or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  Contains diagnostic information about the sampling rates currently used by the
 *  Server.
 */
class UABASE_EXPORT UaSamplingIntervalDiagnosticsDataType
{
    UA_DECLARE_PRIVATE(UaSamplingIntervalDiagnosticsDataType)
public:
    UaSamplingIntervalDiagnosticsDataType();
    UaSamplingIntervalDiagnosticsDataType(const UaSamplingIntervalDiagnosticsDataType &other);
    UaSamplingIntervalDiagnosticsDataType(const OpcUa_SamplingIntervalDiagnosticsDataType &other);
    UaSamplingIntervalDiagnosticsDataType(
        OpcUa_Double samplingInterval,
        OpcUa_UInt32 monitoredItemCount,
        OpcUa_UInt32 maxMonitoredItemCount,
        OpcUa_UInt32 disabledMonitoredItemCount
        );
    UaSamplingIntervalDiagnosticsDataType(const UaExtensionObject &extensionObject);
    UaSamplingIntervalDiagnosticsDataType(const OpcUa_ExtensionObject &extensionObject);
    UaSamplingIntervalDiagnosticsDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaSamplingIntervalDiagnosticsDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaSamplingIntervalDiagnosticsDataType();

    void clear();

    bool operator==(const UaSamplingIntervalDiagnosticsDataType &other) const;
    bool operator!=(const UaSamplingIntervalDiagnosticsDataType &other) const;

    UaSamplingIntervalDiagnosticsDataType& operator=(const UaSamplingIntervalDiagnosticsDataType &other);

    OpcUa_SamplingIntervalDiagnosticsDataType* copy() const;
    void copyTo(OpcUa_SamplingIntervalDiagnosticsDataType *pDst) const;

    static OpcUa_SamplingIntervalDiagnosticsDataType* clone(const OpcUa_SamplingIntervalDiagnosticsDataType& source);
    static void cloneTo(const OpcUa_SamplingIntervalDiagnosticsDataType& source, OpcUa_SamplingIntervalDiagnosticsDataType& copy);

    void attach(OpcUa_SamplingIntervalDiagnosticsDataType *pValue);
    OpcUa_SamplingIntervalDiagnosticsDataType* detach(OpcUa_SamplingIntervalDiagnosticsDataType* pDst);

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

    OpcUa_StatusCode setSamplingIntervalDiagnosticsDataType(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setSamplingIntervalDiagnosticsDataType(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setSamplingIntervalDiagnosticsDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSamplingIntervalDiagnosticsDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setSamplingIntervalDiagnosticsDataType(
        OpcUa_Double samplingInterval,
        OpcUa_UInt32 monitoredItemCount,
        OpcUa_UInt32 maxMonitoredItemCount,
        OpcUa_UInt32 disabledMonitoredItemCount
        );

    OpcUa_Double getSamplingInterval() const;
    OpcUa_UInt32 getMonitoredItemCount() const;
    OpcUa_UInt32 getMaxMonitoredItemCount() const;
    OpcUa_UInt32 getDisabledMonitoredItemCount() const;

    void setSamplingInterval(OpcUa_Double samplingInterval);
    void setMonitoredItemCount(OpcUa_UInt32 monitoredItemCount);
    void setMaxMonitoredItemCount(OpcUa_UInt32 maxMonitoredItemCount);
    void setDisabledMonitoredItemCount(OpcUa_UInt32 disabledMonitoredItemCount);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_SamplingIntervalDiagnosticsDataType.
 *
 *  This class encapsulates an array of the native OpcUa_SamplingIntervalDiagnosticsDataType structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaSamplingIntervalDiagnosticsDataType for information about the encapsulated structure.
 */
class UABASE_EXPORT UaSamplingIntervalDiagnosticsDataTypes
{
public:
    UaSamplingIntervalDiagnosticsDataTypes();
    UaSamplingIntervalDiagnosticsDataTypes(const UaSamplingIntervalDiagnosticsDataTypes &other);
    UaSamplingIntervalDiagnosticsDataTypes(OpcUa_Int32 length, OpcUa_SamplingIntervalDiagnosticsDataType* data);
    virtual ~UaSamplingIntervalDiagnosticsDataTypes();

    UaSamplingIntervalDiagnosticsDataTypes& operator=(const UaSamplingIntervalDiagnosticsDataTypes &other);
    const OpcUa_SamplingIntervalDiagnosticsDataType& operator[](OpcUa_UInt32 index) const;
    OpcUa_SamplingIntervalDiagnosticsDataType& operator[](OpcUa_UInt32 index);

    bool operator==(const UaSamplingIntervalDiagnosticsDataTypes &other) const;
    bool operator!=(const UaSamplingIntervalDiagnosticsDataTypes &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_SamplingIntervalDiagnosticsDataType* data);
    void attach(OpcUa_Int32 length, OpcUa_SamplingIntervalDiagnosticsDataType* data);
    OpcUa_SamplingIntervalDiagnosticsDataType* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_SamplingIntervalDiagnosticsDataType* rawData() const {return m_data;}
    inline OpcUa_SamplingIntervalDiagnosticsDataType* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setSamplingIntervalDiagnosticsDataTypes(const UaVariant &variant);
    OpcUa_StatusCode setSamplingIntervalDiagnosticsDataTypes(const OpcUa_Variant &variant);
    OpcUa_StatusCode setSamplingIntervalDiagnosticsDataTypes(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSamplingIntervalDiagnosticsDataTypes(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSamplingIntervalDiagnosticsDataTypes(OpcUa_Int32 length, OpcUa_SamplingIntervalDiagnosticsDataType* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_SamplingIntervalDiagnosticsDataType* m_data;
};

#endif // UASAMPLINGINTERVALDIAGNOSTICSDATATYPE_H

