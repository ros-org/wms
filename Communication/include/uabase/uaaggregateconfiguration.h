/******************************************************************************
** uaaggregateconfiguration.h
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
** Portable UaAggregateConfiguration class.
**
******************************************************************************/
#ifndef UAAGGREGATECONFIGURATION_H
#define UAAGGREGATECONFIGURATION_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaAggregateConfigurationPrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_AggregateConfiguration.
 *
 *  This class encapsulates the native OpcUa_AggregateConfiguration structure
 *  and handles memory allocation and cleanup for you.
 *  UaAggregateConfiguration uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared AggregateConfiguration it creates a copy for that (copy-on-write).
 *  So assigning another UaAggregateConfiguration or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  Allows Clients to override the Aggregate configuration settings supplied by the
 *  AggregateConfiguration object on a per monitored item basis.
 *
 *  See Part 13 of the OPC UA Specification for more information on Aggregate
 *  configurations. If the Server does not support the ability to override the
 *  Aggregate configuration settings it shall return a StatusCode of
 *  Bad_AggregateListMismatch.
 */
class UABASE_EXPORT UaAggregateConfiguration
{
    UA_DECLARE_PRIVATE(UaAggregateConfiguration)
public:
    UaAggregateConfiguration();
    UaAggregateConfiguration(const UaAggregateConfiguration &other);
    UaAggregateConfiguration(const OpcUa_AggregateConfiguration &other);
    UaAggregateConfiguration(
        OpcUa_Boolean useServerCapabilitiesDefaults,
        OpcUa_Boolean treatUncertainAsBad,
        OpcUa_Byte percentDataBad,
        OpcUa_Byte percentDataGood,
        OpcUa_Boolean useSlopedExtrapolation
        );
    UaAggregateConfiguration(const UaExtensionObject &extensionObject);
    UaAggregateConfiguration(const OpcUa_ExtensionObject &extensionObject);
    UaAggregateConfiguration(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaAggregateConfiguration(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaAggregateConfiguration();

    void clear();

    bool operator==(const UaAggregateConfiguration &other) const;
    bool operator!=(const UaAggregateConfiguration &other) const;

    UaAggregateConfiguration& operator=(const UaAggregateConfiguration &other);

    OpcUa_AggregateConfiguration* copy() const;
    void copyTo(OpcUa_AggregateConfiguration *pDst) const;

    static OpcUa_AggregateConfiguration* clone(const OpcUa_AggregateConfiguration& source);
    static void cloneTo(const OpcUa_AggregateConfiguration& source, OpcUa_AggregateConfiguration& copy);

    void attach(OpcUa_AggregateConfiguration *pValue);
    OpcUa_AggregateConfiguration* detach(OpcUa_AggregateConfiguration* pDst);

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

    OpcUa_StatusCode setAggregateConfiguration(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setAggregateConfiguration(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setAggregateConfiguration(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setAggregateConfiguration(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setAggregateConfiguration(
        OpcUa_Boolean useServerCapabilitiesDefaults,
        OpcUa_Boolean treatUncertainAsBad,
        OpcUa_Byte percentDataBad,
        OpcUa_Byte percentDataGood,
        OpcUa_Boolean useSlopedExtrapolation
        );

    OpcUa_Boolean getUseServerCapabilitiesDefaults() const;
    OpcUa_Boolean getTreatUncertainAsBad() const;
    OpcUa_Byte getPercentDataBad() const;
    OpcUa_Byte getPercentDataGood() const;
    OpcUa_Boolean getUseSlopedExtrapolation() const;

    void setUseServerCapabilitiesDefaults(OpcUa_Boolean useServerCapabilitiesDefaults);
    void setTreatUncertainAsBad(OpcUa_Boolean treatUncertainAsBad);
    void setPercentDataBad(OpcUa_Byte percentDataBad);
    void setPercentDataGood(OpcUa_Byte percentDataGood);
    void setUseSlopedExtrapolation(OpcUa_Boolean useSlopedExtrapolation);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_AggregateConfiguration.
 *
 *  This class encapsulates an array of the native OpcUa_AggregateConfiguration structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaAggregateConfiguration for information about the encapsulated structure.
 */
class UABASE_EXPORT UaAggregateConfigurations
{
public:
    UaAggregateConfigurations();
    UaAggregateConfigurations(const UaAggregateConfigurations &other);
    UaAggregateConfigurations(OpcUa_Int32 length, OpcUa_AggregateConfiguration* data);
    virtual ~UaAggregateConfigurations();

    UaAggregateConfigurations& operator=(const UaAggregateConfigurations &other);
    const OpcUa_AggregateConfiguration& operator[](OpcUa_UInt32 index) const;
    OpcUa_AggregateConfiguration& operator[](OpcUa_UInt32 index);

    bool operator==(const UaAggregateConfigurations &other) const;
    bool operator!=(const UaAggregateConfigurations &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_AggregateConfiguration* data);
    void attach(OpcUa_Int32 length, OpcUa_AggregateConfiguration* data);
    OpcUa_AggregateConfiguration* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_AggregateConfiguration* rawData() const {return m_data;}
    inline OpcUa_AggregateConfiguration* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setAggregateConfigurations(const UaVariant &variant);
    OpcUa_StatusCode setAggregateConfigurations(const OpcUa_Variant &variant);
    OpcUa_StatusCode setAggregateConfigurations(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setAggregateConfigurations(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setAggregateConfigurations(OpcUa_Int32 length, OpcUa_AggregateConfiguration* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_AggregateConfiguration* m_data;
};

#endif // UAAGGREGATECONFIGURATION_H

