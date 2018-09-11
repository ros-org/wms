/******************************************************************************
** uaserveronnetwork.h
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
** Portable UaServerOnNetwork class.
**
******************************************************************************/
#ifndef UASERVERONNETWORK_H
#define UASERVERONNETWORK_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uastring.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaServerOnNetworkPrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_ServerOnNetwork.
 *
 *  This class encapsulates the native OpcUa_ServerOnNetwork structure
 *  and handles memory allocation and cleanup for you.
 *  UaServerOnNetwork uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared ServerOnNetwork it creates a copy for that (copy-on-write).
 *  So assigning another UaServerOnNetwork or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 */
class UABASE_EXPORT UaServerOnNetwork
{
    UA_DECLARE_PRIVATE(UaServerOnNetwork)
public:
    UaServerOnNetwork();
    UaServerOnNetwork(const UaServerOnNetwork &other);
    UaServerOnNetwork(const OpcUa_ServerOnNetwork &other);
    UaServerOnNetwork(
        OpcUa_UInt32 recordId,
        const UaString& serverName,
        const UaString& discoveryUrl,
        const UaStringArray &serverCapabilities
        );
    UaServerOnNetwork(const UaExtensionObject &extensionObject);
    UaServerOnNetwork(const OpcUa_ExtensionObject &extensionObject);
    UaServerOnNetwork(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaServerOnNetwork(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaServerOnNetwork();

    void clear();

    bool operator==(const UaServerOnNetwork &other) const;
    bool operator!=(const UaServerOnNetwork &other) const;

    UaServerOnNetwork& operator=(const UaServerOnNetwork &other);

    OpcUa_ServerOnNetwork* copy() const;
    void copyTo(OpcUa_ServerOnNetwork *pDst) const;

    static OpcUa_ServerOnNetwork* clone(const OpcUa_ServerOnNetwork& source);
    static void cloneTo(const OpcUa_ServerOnNetwork& source, OpcUa_ServerOnNetwork& copy);

    void attach(OpcUa_ServerOnNetwork *pValue);
    OpcUa_ServerOnNetwork* detach(OpcUa_ServerOnNetwork* pDst);

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

    OpcUa_StatusCode setServerOnNetwork(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setServerOnNetwork(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setServerOnNetwork(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setServerOnNetwork(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setServerOnNetwork(
        OpcUa_UInt32 recordId,
        const UaString& serverName,
        const UaString& discoveryUrl,
        const UaStringArray &serverCapabilities
        );

    OpcUa_UInt32 getRecordId() const;
    UaString getServerName() const;
    UaString getDiscoveryUrl() const;
    void getServerCapabilities(UaStringArray& serverCapabilities) const;

    void setRecordId(OpcUa_UInt32 recordId);
    void setServerName(const UaString& serverName);
    void setDiscoveryUrl(const UaString& discoveryUrl);
    void setServerCapabilities(const UaStringArray &serverCapabilities);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_ServerOnNetwork.
 *
 *  This class encapsulates an array of the native OpcUa_ServerOnNetwork structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaServerOnNetwork for information about the encapsulated structure.
 */
class UABASE_EXPORT UaServerOnNetworks
{
public:
    UaServerOnNetworks();
    UaServerOnNetworks(const UaServerOnNetworks &other);
    UaServerOnNetworks(OpcUa_Int32 length, OpcUa_ServerOnNetwork* data);
    virtual ~UaServerOnNetworks();

    UaServerOnNetworks& operator=(const UaServerOnNetworks &other);
    const OpcUa_ServerOnNetwork& operator[](OpcUa_UInt32 index) const;
    OpcUa_ServerOnNetwork& operator[](OpcUa_UInt32 index);

    bool operator==(const UaServerOnNetworks &other) const;
    bool operator!=(const UaServerOnNetworks &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_ServerOnNetwork* data);
    void attach(OpcUa_Int32 length, OpcUa_ServerOnNetwork* data);
    OpcUa_ServerOnNetwork* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_ServerOnNetwork* rawData() const {return m_data;}
    inline OpcUa_ServerOnNetwork* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setServerOnNetworks(const UaVariant &variant);
    OpcUa_StatusCode setServerOnNetworks(const OpcUa_Variant &variant);
    OpcUa_StatusCode setServerOnNetworks(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setServerOnNetworks(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setServerOnNetworks(OpcUa_Int32 length, OpcUa_ServerOnNetwork* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_ServerOnNetwork* m_data;
};

#endif // UASERVERONNETWORK_H

