/******************************************************************************
** uaapplicationdescription.h
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
** Portable UaApplicationDescription class.
**
******************************************************************************/
#ifndef UAAPPLICATIONDESCRIPTION_H
#define UAAPPLICATIONDESCRIPTION_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "ualocalizedtext.h"
#include "uastring.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaApplicationDescriptionPrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_ApplicationDescription.
 *
 *  This class encapsulates the native OpcUa_ApplicationDescription structure
 *  and handles memory allocation and cleanup for you.
 *  UaApplicationDescription uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared ApplicationDescription it creates a copy for that (copy-on-write).
 *  So assigning another UaApplicationDescription or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  Specifies an application that is available.
 */
class UABASE_EXPORT UaApplicationDescription
{
    UA_DECLARE_PRIVATE(UaApplicationDescription)
public:
    UaApplicationDescription();
    UaApplicationDescription(const UaApplicationDescription &other);
    UaApplicationDescription(const OpcUa_ApplicationDescription &other);
    UaApplicationDescription(
        const UaString& applicationUri,
        const UaString& productUri,
        const UaLocalizedText& applicationName,
        OpcUa_ApplicationType applicationType,
        const UaString& gatewayServerUri,
        const UaString& discoveryProfileUri,
        const UaStringArray &discoveryUrls
        );
    UaApplicationDescription(const UaExtensionObject &extensionObject);
    UaApplicationDescription(const OpcUa_ExtensionObject &extensionObject);
    UaApplicationDescription(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaApplicationDescription(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaApplicationDescription();

    void clear();

    bool operator==(const UaApplicationDescription &other) const;
    bool operator!=(const UaApplicationDescription &other) const;

    UaApplicationDescription& operator=(const UaApplicationDescription &other);

    OpcUa_ApplicationDescription* copy() const;
    void copyTo(OpcUa_ApplicationDescription *pDst) const;

    static OpcUa_ApplicationDescription* clone(const OpcUa_ApplicationDescription& source);
    static void cloneTo(const OpcUa_ApplicationDescription& source, OpcUa_ApplicationDescription& copy);

    void attach(OpcUa_ApplicationDescription *pValue);
    OpcUa_ApplicationDescription* detach(OpcUa_ApplicationDescription* pDst);

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

    OpcUa_StatusCode setApplicationDescription(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setApplicationDescription(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setApplicationDescription(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setApplicationDescription(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setApplicationDescription(
        const UaString& applicationUri,
        const UaString& productUri,
        const UaLocalizedText& applicationName,
        OpcUa_ApplicationType applicationType,
        const UaString& gatewayServerUri,
        const UaString& discoveryProfileUri,
        const UaStringArray &discoveryUrls
        );

    UaString getApplicationUri() const;
    UaString getProductUri() const;
    UaLocalizedText getApplicationName() const;
    OpcUa_ApplicationType getApplicationType() const;
    UaString getGatewayServerUri() const;
    UaString getDiscoveryProfileUri() const;
    void getDiscoveryUrls(UaStringArray& discoveryUrls) const;

    void setApplicationUri(const UaString& applicationUri);
    void setProductUri(const UaString& productUri);
    void setApplicationName(const UaLocalizedText& applicationName);
    void setApplicationType(OpcUa_ApplicationType applicationType);
    void setGatewayServerUri(const UaString& gatewayServerUri);
    void setDiscoveryProfileUri(const UaString& discoveryProfileUri);
    void setDiscoveryUrls(const UaStringArray &discoveryUrls);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_ApplicationDescription.
 *
 *  This class encapsulates an array of the native OpcUa_ApplicationDescription structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaApplicationDescription for information about the encapsulated structure.
 */
class UABASE_EXPORT UaApplicationDescriptions
{
public:
    UaApplicationDescriptions();
    UaApplicationDescriptions(const UaApplicationDescriptions &other);
    UaApplicationDescriptions(OpcUa_Int32 length, OpcUa_ApplicationDescription* data);
    virtual ~UaApplicationDescriptions();

    UaApplicationDescriptions& operator=(const UaApplicationDescriptions &other);
    const OpcUa_ApplicationDescription& operator[](OpcUa_UInt32 index) const;
    OpcUa_ApplicationDescription& operator[](OpcUa_UInt32 index);

    bool operator==(const UaApplicationDescriptions &other) const;
    bool operator!=(const UaApplicationDescriptions &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_ApplicationDescription* data);
    void attach(OpcUa_Int32 length, OpcUa_ApplicationDescription* data);
    OpcUa_ApplicationDescription* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_ApplicationDescription* rawData() const {return m_data;}
    inline OpcUa_ApplicationDescription* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setApplicationDescriptions(const UaVariant &variant);
    OpcUa_StatusCode setApplicationDescriptions(const OpcUa_Variant &variant);
    OpcUa_StatusCode setApplicationDescriptions(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setApplicationDescriptions(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setApplicationDescriptions(OpcUa_Int32 length, OpcUa_ApplicationDescription* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_ApplicationDescription* m_data;
};

#endif // UAAPPLICATIONDESCRIPTION_H

