/******************************************************************************
** version_coremodule.h
**
** Copyright (c) 2006-2015 Unified Automation GmbH All rights reserved.
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
** Description: OPC server core module version file.
**
******************************************************************************/
#ifndef VERSION_COREMODULE_H
#define VERSION_COREMODULE_H

#include "uabase.h"
#include "opcuatypes.h"

/** Class providing static member functions to request the version information for the
* UA Server SDK, the UA Stack and the UA Stack Platform Layer.
*/
class SERVER_CORE_EXPORT VersionInfoCoreModule
{
public:
    VersionInfoCoreModule();
    ~VersionInfoCoreModule();

    static UaString getCoreModuleVersionInfo();
    static UaString getCoreModuleVersion();

    static UaString getUaStackVersionInfo();
    static UaString getUaStackVersion();
    static UaString getUaStackStaticConfigInfo();
    static UaString getUaStackRuntimeConfigInfo();

    static UaString getUaStackPlatformLayerVersionInfo();
    static UaString getUaStackPlatformLayerVersion();
    static UaString getUaStackPlatformLayerConfigInfo();
};

// Default setting for browse continuation point
#ifndef DEFAULT_MAX_BROWSE_CP
#define DEFAULT_MAX_BROWSE_CP                   10
#endif

// Default setting for browse continuation point
#ifndef DEFAULT_MAX_BROWSE_RESULTS
#define DEFAULT_MAX_BROWSE_RESULTS              1000
#endif

// Method Server Facet
#ifndef SUPPORT_Method_Server_Facet
#define SUPPORT_Method_Server_Facet             OPCUA_CONFIG_ON
#endif

// Event Subscription Server Facet
#ifndef SUPPORT_Event_Subscription_Server_Facet
#define SUPPORT_Event_Subscription_Server_Facet OPCUA_CONFIG_ON
#endif

// Auditing Server Facet
#if SUPPORT_Event_Subscription_Server_Facet
#ifndef SUPPORT_Auditing_Server_Facet
#define SUPPORT_Auditing_Server_Facet           OPCUA_CONFIG_ON
#endif
#else
#define SUPPORT_Auditing_Server_Facet OPCUA_CONFIG_NO
#endif // SUPPORT_Event_Subscription_Server_Facet

// Node Management Server Facet
#ifndef SUPPORT_Node_Management_Server_Facet
#define SUPPORT_Node_Management_Server_Facet    OPCUA_CONFIG_ON
#endif

// Historical Access
#ifndef SUPPORT_Historical_Access
#define SUPPORT_Historical_Access               OPCUA_CONFIG_ON
#endif
#ifndef DEFAULT_MAX_HISTORY_READ_CP
#define DEFAULT_MAX_HISTORY_READ_CP             100
#endif

// IOManager2 interface use
#ifndef USE_IOManager2_Interface
#define USE_IOManager2_Interface                OPCUA_CONFIG_NO
#endif

// Counting instances of classes like Session, Subscription and UaNodes
// These counts are reflecting the C++ object instances and not their OPC UA status
#ifndef SUPPORT_Class_Statistic
#define SUPPORT_Class_Statistic                 OPCUA_CONFIG_YES
#endif
// Name of the folder containing the class statistic variables below the object VendorServerInfo
#if SUPPORT_Class_Statistic
#define CLASS_STATISTIC_Folder_Name "ObjectStatistics"
#endif // SUPPORT_Class_Statistic

// Support of trace configuration through VendorServerInfo in Server Object
#ifndef SUPPORT_TRACE_CONFIGURATION
#define SUPPORT_TRACE_CONFIGURATION             OPCUA_CONFIG_ON
#endif

// Support of trace output as OPC UA events
#if SUPPORT_Event_Subscription_Server_Facet && SUPPORT_Historical_Access && SUPPORT_TRACE_CONFIGURATION
#ifndef SUPPORT_TRACE_EVENTS
#define SUPPORT_TRACE_EVENTS                   OPCUA_CONFIG_ON
#endif
#ifndef SUPPORT_TRACE_EVENTS_MAX_LIST_SIZE
#define SUPPORT_TRACE_EVENTS_MAX_LIST_SIZE     1000
#endif
#else
#define SUPPORT_TRACE_EVENTS                   OPCUA_CONFIG_NO
#endif // SUPPORT_Event_Subscription_Server_Facet


// Default settings for ServerConfig
#ifndef SERVERCONFIG_PRODUCTURI
#define SERVERCONFIG_PRODUCTURI       "urn:UnifiedAutomation:UaServerCpp"
#endif
#ifndef SERVERCONFIG_MANUFACTURERNAME
#define SERVERCONFIG_MANUFACTURERNAME "Unified Automation GmbH"
#endif
#ifndef SERVERCONFIG_PRODUCTNAME
#define SERVERCONFIG_PRODUCTNAME      "C++ SDK OPC UA Demo Server"
#endif
#ifndef SERVERCONFIG_SOFTWAREVERSION
#define SERVERCONFIG_SOFTWAREVERSION  chSTR2(PROD_MAJOR) "." chSTR2(PROD_MINOR)  "." chSTR2(PROD_PATCH)
#endif
#ifndef SERVERCONFIG_BUILDNUMBER
#define SERVERCONFIG_BUILDNUMBER      chSTR2(PROD_BUILD)
#endif
#ifndef SERVERCONFIG_SERVERURI
#define SERVERCONFIG_SERVERURI        "urn:[NodeName]:UnifiedAutomation:UaServerCpp"
#endif
#ifndef SERVERCONFIG_SERVERNAME
#define SERVERCONFIG_SERVERNAME       "UaServerCpp@[NodeName]"
#endif
#ifndef SERVERCONFIG_SERVERTRACEFILE
#define SERVERCONFIG_SERVERTRACEFILE  "[ApplicationPath]/SrvTrace.log"
#endif
// Default security settings
// 1 -> Basic256 / SignAndEncrypt 0 -> None / None
#ifndef SERVERCONFIG_DEFAULT_SECURE
#define SERVERCONFIG_DEFAULT_SECURE   1
#endif

#endif // VERSION_COREMODULE_H
