/******************************************************************************
** uaendpointdescription.h
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
** Portable UaEndpointDescription class.
**
******************************************************************************/
#ifndef UAENDPOINTDESCRIPTION_H
#define UAENDPOINTDESCRIPTION_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uaapplicationdescription.h"
#include "uabytestring.h"
#include "uastring.h"
#include "uausertokenpolicy.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaEndpointDescriptionPrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_EndpointDescription.
 *
 *  This class encapsulates the native OpcUa_EndpointDescription structure
 *  and handles memory allocation and cleanup for you.
 *  UaEndpointDescription uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared EndpointDescription it creates a copy for that (copy-on-write).
 *  So assigning another UaEndpointDescription or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  Describes an Endpoint for a Server
 */
class UABASE_EXPORT UaEndpointDescription
{
    UA_DECLARE_PRIVATE(UaEndpointDescription)
public:
    UaEndpointDescription();
    UaEndpointDescription(const UaEndpointDescription &other);
    UaEndpointDescription(const OpcUa_EndpointDescription &other);
    UaEndpointDescription(
        const UaString& endpointUrl,
        const UaApplicationDescription& server,
        const UaByteString& serverCertificate,
        OpcUa_MessageSecurityMode securityMode,
        const UaString& securityPolicyUri,
        const UaUserTokenPolicys &userIdentityTokens,
        const UaString& transportProfileUri,
        OpcUa_Byte securityLevel
        );
    UaEndpointDescription(const UaExtensionObject &extensionObject);
    UaEndpointDescription(const OpcUa_ExtensionObject &extensionObject);
    UaEndpointDescription(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaEndpointDescription(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaEndpointDescription();

    void clear();

    bool operator==(const UaEndpointDescription &other) const;
    bool operator!=(const UaEndpointDescription &other) const;

    UaEndpointDescription& operator=(const UaEndpointDescription &other);

    OpcUa_EndpointDescription* copy() const;
    void copyTo(OpcUa_EndpointDescription *pDst) const;

    static OpcUa_EndpointDescription* clone(const OpcUa_EndpointDescription& source);
    static void cloneTo(const OpcUa_EndpointDescription& source, OpcUa_EndpointDescription& copy);

    void attach(OpcUa_EndpointDescription *pValue);
    OpcUa_EndpointDescription* detach(OpcUa_EndpointDescription* pDst);

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

    OpcUa_StatusCode setEndpointDescription(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setEndpointDescription(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setEndpointDescription(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setEndpointDescription(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setEndpointDescription(
        const UaString& endpointUrl,
        const UaApplicationDescription& server,
        const UaByteString& serverCertificate,
        OpcUa_MessageSecurityMode securityMode,
        const UaString& securityPolicyUri,
        const UaUserTokenPolicys &userIdentityTokens,
        const UaString& transportProfileUri,
        OpcUa_Byte securityLevel
        );

    UaString getEndpointUrl() const;
    UaApplicationDescription getServer() const;
    UaByteString getServerCertificate() const;
    OpcUa_MessageSecurityMode getSecurityMode() const;
    UaString getSecurityPolicyUri() const;
    void getUserIdentityTokens(UaUserTokenPolicys& userIdentityTokens) const;
    UaString getTransportProfileUri() const;
    OpcUa_Byte getSecurityLevel() const;

    void setEndpointUrl(const UaString& endpointUrl);
    void setServer(const UaApplicationDescription& server);
    void setServerCertificate(const UaByteString& serverCertificate);
    void setSecurityMode(OpcUa_MessageSecurityMode securityMode);
    void setSecurityPolicyUri(const UaString& securityPolicyUri);
    void setUserIdentityTokens(const UaUserTokenPolicys &userIdentityTokens);
    void setTransportProfileUri(const UaString& transportProfileUri);
    void setSecurityLevel(OpcUa_Byte securityLevel);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_EndpointDescription.
 *
 *  This class encapsulates an array of the native OpcUa_EndpointDescription structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaEndpointDescription for information about the encapsulated structure.
 */
class UABASE_EXPORT UaEndpointDescriptions
{
public:
    UaEndpointDescriptions();
    UaEndpointDescriptions(const UaEndpointDescriptions &other);
    UaEndpointDescriptions(OpcUa_Int32 length, OpcUa_EndpointDescription* data);
    virtual ~UaEndpointDescriptions();

    UaEndpointDescriptions& operator=(const UaEndpointDescriptions &other);
    const OpcUa_EndpointDescription& operator[](OpcUa_UInt32 index) const;
    OpcUa_EndpointDescription& operator[](OpcUa_UInt32 index);

    bool operator==(const UaEndpointDescriptions &other) const;
    bool operator!=(const UaEndpointDescriptions &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_EndpointDescription* data);
    void attach(OpcUa_Int32 length, OpcUa_EndpointDescription* data);
    OpcUa_EndpointDescription* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_EndpointDescription* rawData() const {return m_data;}
    inline OpcUa_EndpointDescription* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setEndpointDescriptions(const UaVariant &variant);
    OpcUa_StatusCode setEndpointDescriptions(const OpcUa_Variant &variant);
    OpcUa_StatusCode setEndpointDescriptions(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setEndpointDescriptions(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setEndpointDescriptions(OpcUa_Int32 length, OpcUa_EndpointDescription* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_EndpointDescription* m_data;
};

#endif // UAENDPOINTDESCRIPTION_H

