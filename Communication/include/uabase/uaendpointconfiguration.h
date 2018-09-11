/******************************************************************************
** uaendpointconfiguration.h
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
** Portable UaEndpointConfiguration class.
**
******************************************************************************/
#ifndef UAENDPOINTCONFIGURATION_H
#define UAENDPOINTCONFIGURATION_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaEndpointConfigurationPrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_EndpointConfiguration.
 *
 *  This class encapsulates the native OpcUa_EndpointConfiguration structure
 *  and handles memory allocation and cleanup for you.
 *  UaEndpointConfiguration uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared EndpointConfiguration it creates a copy for that (copy-on-write).
 *  So assigning another UaEndpointConfiguration or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 */
class UABASE_EXPORT UaEndpointConfiguration
{
    UA_DECLARE_PRIVATE(UaEndpointConfiguration)
public:
    UaEndpointConfiguration();
    UaEndpointConfiguration(const UaEndpointConfiguration &other);
    UaEndpointConfiguration(const OpcUa_EndpointConfiguration &other);
    UaEndpointConfiguration(
        OpcUa_Int32 operationTimeout,
        OpcUa_Boolean useBinaryEncoding,
        OpcUa_Int32 maxStringLength,
        OpcUa_Int32 maxByteStringLength,
        OpcUa_Int32 maxArrayLength,
        OpcUa_Int32 maxMessageSize,
        OpcUa_Int32 maxBufferSize,
        OpcUa_Int32 channelLifetime,
        OpcUa_Int32 securityTokenLifetime
        );
    UaEndpointConfiguration(const UaExtensionObject &extensionObject);
    UaEndpointConfiguration(const OpcUa_ExtensionObject &extensionObject);
    UaEndpointConfiguration(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaEndpointConfiguration(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaEndpointConfiguration();

    void clear();

    bool operator==(const UaEndpointConfiguration &other) const;
    bool operator!=(const UaEndpointConfiguration &other) const;

    UaEndpointConfiguration& operator=(const UaEndpointConfiguration &other);

    OpcUa_EndpointConfiguration* copy() const;
    void copyTo(OpcUa_EndpointConfiguration *pDst) const;

    static OpcUa_EndpointConfiguration* clone(const OpcUa_EndpointConfiguration& source);
    static void cloneTo(const OpcUa_EndpointConfiguration& source, OpcUa_EndpointConfiguration& copy);

    void attach(OpcUa_EndpointConfiguration *pValue);
    OpcUa_EndpointConfiguration* detach(OpcUa_EndpointConfiguration* pDst);

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

    OpcUa_StatusCode setEndpointConfiguration(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setEndpointConfiguration(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setEndpointConfiguration(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setEndpointConfiguration(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setEndpointConfiguration(
        OpcUa_Int32 operationTimeout,
        OpcUa_Boolean useBinaryEncoding,
        OpcUa_Int32 maxStringLength,
        OpcUa_Int32 maxByteStringLength,
        OpcUa_Int32 maxArrayLength,
        OpcUa_Int32 maxMessageSize,
        OpcUa_Int32 maxBufferSize,
        OpcUa_Int32 channelLifetime,
        OpcUa_Int32 securityTokenLifetime
        );

    OpcUa_Int32 getOperationTimeout() const;
    OpcUa_Boolean getUseBinaryEncoding() const;
    OpcUa_Int32 getMaxStringLength() const;
    OpcUa_Int32 getMaxByteStringLength() const;
    OpcUa_Int32 getMaxArrayLength() const;
    OpcUa_Int32 getMaxMessageSize() const;
    OpcUa_Int32 getMaxBufferSize() const;
    OpcUa_Int32 getChannelLifetime() const;
    OpcUa_Int32 getSecurityTokenLifetime() const;

    void setOperationTimeout(OpcUa_Int32 operationTimeout);
    void setUseBinaryEncoding(OpcUa_Boolean useBinaryEncoding);
    void setMaxStringLength(OpcUa_Int32 maxStringLength);
    void setMaxByteStringLength(OpcUa_Int32 maxByteStringLength);
    void setMaxArrayLength(OpcUa_Int32 maxArrayLength);
    void setMaxMessageSize(OpcUa_Int32 maxMessageSize);
    void setMaxBufferSize(OpcUa_Int32 maxBufferSize);
    void setChannelLifetime(OpcUa_Int32 channelLifetime);
    void setSecurityTokenLifetime(OpcUa_Int32 securityTokenLifetime);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_EndpointConfiguration.
 *
 *  This class encapsulates an array of the native OpcUa_EndpointConfiguration structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaEndpointConfiguration for information about the encapsulated structure.
 */
class UABASE_EXPORT UaEndpointConfigurations
{
public:
    UaEndpointConfigurations();
    UaEndpointConfigurations(const UaEndpointConfigurations &other);
    UaEndpointConfigurations(OpcUa_Int32 length, OpcUa_EndpointConfiguration* data);
    virtual ~UaEndpointConfigurations();

    UaEndpointConfigurations& operator=(const UaEndpointConfigurations &other);
    const OpcUa_EndpointConfiguration& operator[](OpcUa_UInt32 index) const;
    OpcUa_EndpointConfiguration& operator[](OpcUa_UInt32 index);

    bool operator==(const UaEndpointConfigurations &other) const;
    bool operator!=(const UaEndpointConfigurations &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_EndpointConfiguration* data);
    void attach(OpcUa_Int32 length, OpcUa_EndpointConfiguration* data);
    OpcUa_EndpointConfiguration* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_EndpointConfiguration* rawData() const {return m_data;}
    inline OpcUa_EndpointConfiguration* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setEndpointConfigurations(const UaVariant &variant);
    OpcUa_StatusCode setEndpointConfigurations(const OpcUa_Variant &variant);
    OpcUa_StatusCode setEndpointConfigurations(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setEndpointConfigurations(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setEndpointConfigurations(OpcUa_Int32 length, OpcUa_EndpointConfiguration* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_EndpointConfiguration* m_data;
};

#endif // UAENDPOINTCONFIGURATION_H

