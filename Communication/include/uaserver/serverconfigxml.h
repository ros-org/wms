/******************************************************************************
** serverconfigxml.h
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
** Project: C++ OPC Server SDK core module
**
** Description: Configuration management class for the OPC Server.
**
******************************************************************************/
#ifndef SERVERCONFIGXML_H
#define SERVERCONFIGXML_H

#include <uabase.h>
#include "serverconfigdata.h"
#include "uapkiprovider.h"

#if SUPPORT_XML_PARSER
#include "xmldocument.h"

/** ServerConfigXml
 *  Derived from ServerConfig.
 *  It is not possible to make shallow copies of this class.
 */
class SERVER_CORE_EXPORT ServerConfigXml: public ServerConfigData
{
    UA_DISABLE_COPY(ServerConfigXml);
public:
    /* construction. */
    ServerConfigXml(const UaString& sXmlFileName, const UaString& sApplicationPath, const UaString& sConfigPath, const UaString& sTracePath);
    /** destruction */
    virtual ~ServerConfigXml();

    //  Load the configuration from the config file.
    UaStatus loadConfiguration();

    // Adds/removes a namespaces configuration entry for preconfigured namespaces
    UaStatus addConfiguredNamespace(OpcUa_UInt16 namespaceIndex, const UaString& namespaceUri, OpcUa_Boolean allowRenameUri, const UaString& uniqueId);
    UaStatus removeConfiguredNamespace(OpcUa_UInt16 namespaceIndex);

    // Save the tagile name, path und file ending.
    UaStatus setTagFileConfiguration(const UaString &defaultTagFileName, const UaString &tagFileLocation, const UaString &tagFileEnding, const UaString &defaultFileUpdatePolicy);

    // Save the thumbprint for the server certificate. This is used to find a certificate in the windows store.
    UaStatus setServerCertificateThumbprint(const UaString &thumbprint);

    // Adds an entry to the mapping list of OPC UA property names to COM Data Access property Ids.
    UaStatus addComDaPropertyMapping(const UaString& propertyName, const UaString& propertyNameSpaceUri, OpcUa_UInt32 propertyId);

    // Adds a mapping list of OPC UA event type NodeIds to COM Alarms and Events category IDs.
    UaStatus addComAeEventCategoryMapping(ComAeEventType eventType, const UaUInt32Array& categoryIDs, const UaStringArray& categoryNames, const UaNodeIdArray& eventTypeIds, const UaStringArray& namespaceUris);

    // Adds an entry to the mapping list of OPC UA event fields to COM Alarms and Events attribute IDs.
    UaStatus addComAeAttributeMapping(
        OpcUa_UInt32 attributeID,
        const UaString& attributeName,
        OpcUa_BuiltInType dataType,
        OpcUa_Boolean isArray,
        const UaStringArray& eventFieldPathNames,
        const UaStringArray& eventFieldPathNamespaceUris);

    // Save the configuration to the config file.
    UaStatus saveConfiguration();

    inline UaString sXmlFileName() const {return m_sXmlFileName;}

private:
    UaString              m_sXmlFileName;
};

/** This class represent an UaEndpoint configured by the XML configuration file.
 */
class SERVER_CORE_EXPORT UaEndpointXml: public UaEndpoint
{
public:
    /** construction. */
    UaEndpointXml(){};
    /** destruction */
    virtual ~UaEndpointXml(){};

    UaStatus setXmlConfig(
        UaXmlElement&   xmlElement,
        const UaString& sApplicationPath,
        const UaString& sConfigPath,
        ServerConfigXml* pServerConfig,
        bool&           updatedConfiguration);
};
#endif // SUPPORT_XML_PARSER

#endif // SERVERCONFIGXML_H
