/******************************************************************************
** uaregisteredserver.h
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
** Portable UaRegisteredServer class.
**
******************************************************************************/
#ifndef UAREGISTEREDSERVER_H
#define UAREGISTEREDSERVER_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "ualocalizedtext.h"
#include "uastring.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaRegisteredServerPrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_RegisteredServer.
 *
 *  This class encapsulates the native OpcUa_RegisteredServer structure
 *  and handles memory allocation and cleanup for you.
 *  UaRegisteredServer uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared RegisteredServer it creates a copy for that (copy-on-write).
 *  So assigning another UaRegisteredServer or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  The server to register
 */
class UABASE_EXPORT UaRegisteredServer
{
    UA_DECLARE_PRIVATE(UaRegisteredServer)
public:
    UaRegisteredServer();
    UaRegisteredServer(const UaRegisteredServer &other);
    UaRegisteredServer(const OpcUa_RegisteredServer &other);
    UaRegisteredServer(
        const UaString& serverUri,
        const UaString& productUri,
        const UaLocalizedTextArray &serverNames,
        OpcUa_ApplicationType serverType,
        const UaString& gatewayServerUri,
        const UaStringArray &discoveryUrls,
        const UaString& semaphoreFilePath,
        OpcUa_Boolean isOnline
        );
    UaRegisteredServer(const UaExtensionObject &extensionObject);
    UaRegisteredServer(const OpcUa_ExtensionObject &extensionObject);
    UaRegisteredServer(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaRegisteredServer(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaRegisteredServer();

    void clear();

    bool operator==(const UaRegisteredServer &other) const;
    bool operator!=(const UaRegisteredServer &other) const;

    UaRegisteredServer& operator=(const UaRegisteredServer &other);

    OpcUa_RegisteredServer* copy() const;
    void copyTo(OpcUa_RegisteredServer *pDst) const;

    static OpcUa_RegisteredServer* clone(const OpcUa_RegisteredServer& source);
    static void cloneTo(const OpcUa_RegisteredServer& source, OpcUa_RegisteredServer& copy);

    void attach(OpcUa_RegisteredServer *pValue);
    OpcUa_RegisteredServer* detach(OpcUa_RegisteredServer* pDst);

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

    OpcUa_StatusCode setRegisteredServer(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setRegisteredServer(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setRegisteredServer(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setRegisteredServer(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setRegisteredServer(
        const UaString& serverUri,
        const UaString& productUri,
        const UaLocalizedTextArray &serverNames,
        OpcUa_ApplicationType serverType,
        const UaString& gatewayServerUri,
        const UaStringArray &discoveryUrls,
        const UaString& semaphoreFilePath,
        OpcUa_Boolean isOnline
        );

    UaString getServerUri() const;
    UaString getProductUri() const;
    void getServerNames(UaLocalizedTextArray& serverNames) const;
    OpcUa_ApplicationType getServerType() const;
    UaString getGatewayServerUri() const;
    void getDiscoveryUrls(UaStringArray& discoveryUrls) const;
    UaString getSemaphoreFilePath() const;
    OpcUa_Boolean getIsOnline() const;

    void setServerUri(const UaString& serverUri);
    void setProductUri(const UaString& productUri);
    void setServerNames(const UaLocalizedTextArray &serverNames);
    void setServerType(OpcUa_ApplicationType serverType);
    void setGatewayServerUri(const UaString& gatewayServerUri);
    void setDiscoveryUrls(const UaStringArray &discoveryUrls);
    void setSemaphoreFilePath(const UaString& semaphoreFilePath);
    void setIsOnline(OpcUa_Boolean isOnline);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_RegisteredServer.
 *
 *  This class encapsulates an array of the native OpcUa_RegisteredServer structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaRegisteredServer for information about the encapsulated structure.
 */
class UABASE_EXPORT UaRegisteredServers
{
public:
    UaRegisteredServers();
    UaRegisteredServers(const UaRegisteredServers &other);
    UaRegisteredServers(OpcUa_Int32 length, OpcUa_RegisteredServer* data);
    virtual ~UaRegisteredServers();

    UaRegisteredServers& operator=(const UaRegisteredServers &other);
    const OpcUa_RegisteredServer& operator[](OpcUa_UInt32 index) const;
    OpcUa_RegisteredServer& operator[](OpcUa_UInt32 index);

    bool operator==(const UaRegisteredServers &other) const;
    bool operator!=(const UaRegisteredServers &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_RegisteredServer* data);
    void attach(OpcUa_Int32 length, OpcUa_RegisteredServer* data);
    OpcUa_RegisteredServer* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_RegisteredServer* rawData() const {return m_data;}
    inline OpcUa_RegisteredServer* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setRegisteredServers(const UaVariant &variant);
    OpcUa_StatusCode setRegisteredServers(const OpcUa_Variant &variant);
    OpcUa_StatusCode setRegisteredServers(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setRegisteredServers(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setRegisteredServers(OpcUa_Int32 length, OpcUa_RegisteredServer* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_RegisteredServer* m_data;
};

#endif // UAREGISTEREDSERVER_H

