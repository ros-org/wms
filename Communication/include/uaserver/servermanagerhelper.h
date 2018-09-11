/******************************************************************************
** servermanagerhelper.h
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
** Description: OPC server core module interface.
**
******************************************************************************/
#ifndef SERVERMANAGERHELPER_H
#define SERVERMANAGERHELPER_H

#include "iomanager.h"
#include "continuationpoint.h"
#include "version_coremodule.h"
#include "uathreadpool.h"
#if SUPPORT_Event_Subscription_Server_Facet
#include "eventmanager.h"
#endif // SUPPORT_Event_Subscription_Server_Facet

class SessionManager;
class ServerConfig;
class NodeManager;
#if USE_IOManager2_Interface
class IOManager2;
#endif // USE_IOManager2_Interface
#include <list>
class CoreTransactions;
namespace OpcUa {class HistoryServerCapabilitiesType;}

/** Class containing the information necessary to create a Data MonitoredItem
 */
class SERVER_CORE_EXPORT DataMonitoredItemSpec
{
    UA_DISABLE_COPY(DataMonitoredItemSpec);
public:
    DataMonitoredItemSpec();
    virtual ~DataMonitoredItemSpec();

public:
    /// @brief Node and attribute used to monitor for data changes
    OpcUa_ReadValueId   m_itemToMonitor;
    /// @brief Callback interface for the monitored item
    IOVariableCallback* m_pDataCallback;
    /// @brief Requested sampling interval for the monitored item
    OpcUa_Double        m_requestedSamplingInterval;
    /// @brief Create result for the data monitored item
    UaStatus            m_createResult;
    /// @brief Id of the created monitored item
    OpcUa_UInt32        m_monitoredItemId;
    /// @brief Revised sampling interval used for the monitored item
    OpcUa_Double        m_revisedSamplingInterval;
    /// @brief Flag indicating if an initial value was provided
    OpcUa_Boolean       m_isInitialValueProvided;
    /// @brief Initial value
    UaDataValue         m_initialValue;
};

#if SUPPORT_Event_Subscription_Server_Facet
class SERVER_CORE_EXPORT EventManagerRegisteredCallback
{
    UA_DISABLE_COPY(EventManagerRegisteredCallback);
public:
    EventManagerRegisteredCallback(){}
    virtual ~EventManagerRegisteredCallback(){}

    virtual void dynamicEventManagerRegistered(EventManager* pEventManager) = 0;
};
#endif // SUPPORT_Event_Subscription_Server_Facet

/** A pointer array of VariableHandles. */
typedef UaObjectArray<DataMonitoredItemSpec> DataMonitoredItemSpecArray;



/** Callback interface for providing application control funtions through methods.

 This callback interface needs to be implemented if the application wants to allow control of
 application behaviour like server shutdown or close/reopen of endpoints to be controlled
 through methods in the server address space.
 */
class SERVER_CORE_EXPORT UaApplicationControlCallback
{
public:
    /** Construction */
    UaApplicationControlCallback(){}
    /** Destruction */
    virtual ~UaApplicationControlCallback(){}

    /** Returns the number of OPC UA endpoints in the server. */
    virtual OpcUa_UInt32 getEndpointCount() = 0;

    /** Returns the endpoint at the sepcified index. */
    virtual UaEndpoint* getEndpoint(
        OpcUa_UInt32 endpointIndex //!< [in] Index of the Endpoint to return
        ) = 0;

    /** Opens the endpoint sepcified by the index. */
    virtual UaStatus openEndpoint(
        OpcUa_UInt32 endpointIndex //!< [in] Index of the Endpoint to open
        ) = 0;

    /** Closes the endpoint sepcified by the index. */
    virtual UaStatus closeEndpoint(
        OpcUa_UInt32 endpointIndex //!< [in] Index of the Endpoint to close
        ) = 0;

    /** Requests the shutdown of the OPC UA Server application.
     *  @return  Result of the request. If the result is Bad, the application will not shut down
     */
    virtual UaStatus requestServerShutDown(
        OpcUa_Int32            secondsTillShutdown, //!< [in] Seconds till shutdown of the server
        const UaLocalizedText& shutdownReason,      //!< [in] Reason for the shutdown
        OpcUa_Boolean          restart              //!< [in] A flag indicating if the Server should be restarted after shutdown
        ) = 0;

    /** Information about an endpoint that will be opened by the server. This callbacks allows certificate checks or creation.
     */
    virtual void beforeEndpointOpen(
        UaEndpoint* pEndpoint,           //!< [in] UaEndpoint that will be opened by the server
        bool        certificateAvailable //!< [in] Flag indicating if a certificate is available
        ) = 0;
};

class SERVER_CORE_EXPORT ServerShutDownCallback
{
    UA_DISABLE_COPY(ServerShutDownCallback);
public:
    ServerShutDownCallback(){};
    virtual ~ServerShutDownCallback(){};

    virtual OpcUa_UInt32 startServerShutDown(OpcUa_Int32 secondsTillShutdown, const UaLocalizedText& shutdownReason) = 0;
};

#endif // SERVERMANAGERHELPER_H
