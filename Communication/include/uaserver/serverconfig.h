/******************************************************************************
** serverconfig.h
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
** Description: OPC server core module ServerConfig interface.
**
******************************************************************************/
#ifndef SERVERCONFIG_H
#define SERVERCONFIG_H

#include "session.h"
#include "uaendpoint.h"
#include "uabytestring.h"
#include "uaapplicationdescription.h"
#include "certificatestoreconfiguration.h"
#include "uanetworkgroupdatatype.h"

class SERVER_CORE_EXPORT NodeManager;
class SERVER_CORE_EXPORT ServerManager;
class SERVER_CORE_EXPORT ComAeAttributeMapping;
/** An array of ComAeAttribute */
typedef SERVER_CORE_EXPORT UaObjectPointerArray<ComAeAttributeMapping> ComAeAttributeMappingArray;

/** @ingroup ServerCoreInterfaces
 *  Server Configuration Interface definition.
 *  This class is responsible for the start up and shut down of the Server.
 *  Also all necessary configuration options can be configured with this class.
 *  Services like discovery and getEndpointConfiguration are defined here.
 *  This Interface configures the Server and all needed parts of it.
 */
class SERVER_CORE_EXPORT ServerConfig
{
public:
    /** construction. */
    ServerConfig(){};

    /** destruction */
    virtual ~ServerConfig(){};

    /** Load the configuration from the config file.
     *  This is the first method called after the creation of ServerConfig. This method must load all
     *  configuration options and must create all NodeManagers before the method startUp is called.
     *  The configuration can be loaded from a file, a data base or any other source to overwrite default
     *  settings defined in the constructor of the implementation class.
     *  @return               Error code.
     */
    virtual UaStatus loadConfiguration() = 0;

    /** Start up OPC ServerConfig.
     *  @return                 Error code
     */
    virtual UaStatus startUp(
        ServerManager* pServerManager   /**< [in] Interface to the central ServerManager object. This interface pointer should be stored in the NodeManager
                                                  instance to have access to core module objects like the root NodeManager or the ServerConfig. */
        ) = 0;

    /** Shut down OPC ServerConfig.
     *  @return Error code
     */
    virtual UaStatus shutDown() = 0;

    /** Save the configuration to the config file.
     *  @return               Error code.
     */
    virtual UaStatus saveConfiguration() = 0;

    /** Get Endpoint Configuration.
     *  This method provides the settings necessary for the SDK to open the endpoints for OPC UA
     *  communication in the UA stack and to implement the GetEndpoints service in the UA Module.
     *  @return                                 Error code.
     */
    virtual UaStatus getEndpointConfiguration(
        UaString&        sRejectedCertificateDirectory, //!< [out] The directory to store rejected client certificates.
        OpcUa_UInt32&    nRejectedCertificatesCount,    //!< [out] The maximum number of rejected certificates in the directory
        UaEndpointArray& uaEndpointArray                //!< [out] UaEndpoint array of configured endpoints for the server.
        ) = 0;

    /** Set state of successfully opened endpoint */
    virtual void endpointOpened(OpcUa_UInt32 index);

    /** Get the configurations for server certificate stores
    */
    virtual UaStatus getCertificateStoreConfigurations(
        CertificateStoreConfigurationPArray& certificateStores //!< [out] List of certificate store configurations
        ) = 0;

    /** Get the enabled settings for the different user identity tokens supported by the server.
     *  Activating other user identity tokens than anonymous requires a user management and the
     *  implementation of ServerConfig::logonSessionUser.
     *  @return                     Error code.
     */
    virtual UaStatus getUserIdentityTokenConfig(
        OpcUa_Boolean&   bEnableAnonymous,  //!< [out] Indicates if Anonymous login is allowed.
        OpcUa_Boolean&   bEnableUserPw,     //!< [out] Indicates if login with user and password is activated.
        OpcUa_Boolean&   bEnableCertificate,//!< [out] Indicates if login with user certificate is activated.
        OpcUa_Boolean&   bEnableKerberosTicket //!< [out] Indicates if login with Kerberos token is activated.
        ) = 0;

    /** Get the security policy to use when encrypting or signing the UserIdentityToken when it is passed to the server.
     *  @return                     Error code.
     */
    virtual UaStatus getUserIdentityTokenSecurityPolicy(
        UaString&   sSecurityPolicyUri      //!< [out] The SecurityPolicyUri to use when encrypting or signing the UserIdentityToken.
        );

    /** Get the configurations for the trust list and rejected folder for user certificates
    */
    virtual UaStatus getDefaultUserCertificateStore(
        CertificateStoreConfiguration** ppCertificateStore,         //!< [out] Certificate store configuration for user certificates
        UaString&                   sRejectedCertificateDirectory,  //!< [out] The directory to store rejected user certificates.
        OpcUa_UInt32&               nRejectedCertificatesCount,     //!< [out] The maximum number of rejected user certificates in the directory
        OpcUa_Boolean&              bCertificateTokenConfigured     //!< [out] Returns true if the user identity token certificate is enabled in the configuration
        );

    /** Get Ids for roles defined in the SDK. These roles are needed to control access to certificate configuration and trace configuration.
     *  @return                     Error code.
     */
    virtual UaStatus getIdsForDefaultRoles(
        OpcUa_UInt16&   nRootUserId,            //!< [out] Id of the root user. This user has all rights. Default is 0.
        OpcUa_UInt16&   nSecurityAdminGroupId,  //!< [out] Id of the security admin group. Members of this group have acceess to administrate certificates. Default is 0.
        OpcUa_UInt16&   nConfigAdminGroupId     //!< [out] Id of the configuration admin group. Members of this group can configure the trace. Default is 0.
        );

    /** Get settings for registration with discovery servers.
     *  @return OPC UA result code.
     */
    virtual UaStatus getDiscoveryRegistrationConfig(
        OpcUa_UInt32&   nRegistrationInterval,   //!< [out] Interval in milliseconds used to register with the discovery servers.
        UaStringArray&  discoveryUrlArray        //!< [out] UaString array of discovery server URLs to register with.
        ) = 0;

    /** Get settings for exchanging certificates with local discovery server on a windows computer for registration with local windows discovery server.
     *  @return OPC UA result code.
     */
    virtual UaStatus getWindowsDiscoveryRegistrationSecuritySetup(
        OpcUa_Boolean&  bAutomaticCertificateExchange,      //!< [out] Flag indicating if the certificates should be exchanged
        UaString&       sDiscoveryServerTrustListLocation,  //!< [out] Path of the local discovery server trust list. This is where the server copies it's certificate to.
        UaString&       sDiscoveryServerStoreName,          //!< [out] Store name used for the local discovery server in the windows certificate store
        UaString&       sDiscoveryServerCertificateName     //!< [out] Certificate name of the local discovery server in the windows certificate store
        );

    /** Get Serializer Configuration.
     *  These are the Security constraints for the serializer. Set these values carefully.
     *  @return                     Error code.
     */
    virtual UaStatus getSerializerConfiguration(
        OpcUa_Int32& iMaxAlloc,             //!< [out] The largest size for a memory block the serializer can do when deserializing a message
        OpcUa_Int32& iMaxStringLength,      //!< [out] The largest string accepted by the serializer
        OpcUa_Int32& iMaxByteStringLength,  //!< [out] The largest byte string accepted by the serializer
        OpcUa_Int32& iMaxArrayLength,       //!< [out] Maximum number of elements in an array accepted by the serializer
        OpcUa_Int32& iMaxMessageSize        //!< [out] The maximum number of bytes per message in total
        ) const = 0;

    /** Returns the settings for the thread pool used in the OPC UA Stack.
     *  @return            Error code.
     */
    virtual UaStatus getStackThreadPoolSettings(
        OpcUa_Boolean&   bEnabled,      //!< [out] Controls wether the secure listener uses a thread pool to dispatch received requests
        OpcUa_Int32&     iMinThreads,   //!< [out] The minimum number of threads in the thread pool
        OpcUa_Int32&     iMaxThreads,   //!< [out] The maximum number of threads in the thread pool
        OpcUa_Int32&     iMaxJobs,      //!< [out] The length of the queue with jobs waiting for a free thread
        OpcUa_Boolean&   bBlockOnAdd,   //!< [out] If MaxJobs is reached the add operation can block or return an error
        OpcUa_UInt32&    nTimeout       //!< [out] If the add operation blocks on a full job queue, this value sets the max waiting time
        ) const = 0;

    /** Get UA Stack trace settings.
     *  @return              Error code.
     */
    virtual UaStatus getStackTraceSettings(
        OpcUa_Boolean& bTraceEnabled,   //!< [out] Globally enable/disable trace output from the stack (exclude platformlayer)
        OpcUa_UInt32&  uTraceLevel      /**< [out] Configures the level of messages traced
                                                   - OPCUA_TRACE_OUTPUT_LEVEL_NONE - No Trace
                                                   - OPCUA_TRACE_OUTPUT_LEVEL_ERROR - Critical errors (unexpected and/or requiring external actions) which require attention
                                                   - OPCUA_TRACE_OUTPUT_LEVEL_WARNING - Non-critical faults which should not go unnoticed but are handled internally
                                                   - OPCUA_TRACE_OUTPUT_LEVEL_SYSTEM - Rare major events (good cases) like initializations, shut-down, etc.
                                                   - OPCUA_TRACE_OUTPUT_LEVEL_INFO - Regular good case events like connects, renews
                                                   - OPCUA_TRACE_OUTPUT_LEVEL_DEBUG - Used for debugging purposes
                                                   - OPCUA_TRACE_OUTPUT_LEVEL_CONTENT - Used to add additional content (i.e. whole message bodies) to debug traces
                                                   - OPCUA_TRACE_OUTPUT_LEVEL_ALL - All outputs */
        ) const = 0;

    /**  Get UA Server SDK trace settings.
     *  @return                 Error code.
     */
    virtual UaStatus getServerTraceSettings(
        OpcUa_Boolean& bTraceEnabled,       //!< [out] Globally enable/disable trace output from the SDK
        OpcUa_UInt32&  uTraceLevel,         /**< [out] Configures the level of messages traced
                                                       - (0) NoTrace - No Trace
                                                       - (1) Errors - Unexpected errors
                                                       - (2) Warning - Unexpected behaviour that is not an error
                                                       - (3) Info - Information about important activities like connection establishment
                                                       - (4) InterfaceCall - Calls to module interfaces
                                                       - (5) CtorDtor - Creation and destruction of objects
                                                       - (6) ProgramFlow - Internal program flow
                                                       - (7) Data - Data */
        OpcUa_UInt32&  uMaxTraceEntries,    //!< [out] Maximum number of trace entries in one trace file
        OpcUa_UInt32&  uMaxBackupFiles,     //!< [out] Maximum number of backup files
        UaString&      sTraceFile,          //!< [out] Name and path of the trace file
        OpcUa_Boolean& bDisableFlush        //!< [out] Disable flushing the trace file after each trace entry
        ) const = 0;

    /**  Get UA Server SDK trace event settings.
     *
     *  This configuration option allows clients to get the SDK trace
     *  outputs for trace levels `Errors`, `Warning` and `Info` via
     *  HistoryRead for Events and/or Events from the server.
     *
     *  Possible values are:
     *    <dl>
     *      <dt>`Disabled`</dt>
     *        <dd>traces are only available via trace files</dd>
     *      <dt>`History` (default)</dt>
     *        <dd>traces are available via HistoryRead for Events</dd>
     *      <dt>`HistoryAndEvents`</dt>
     *        <dd>traces are available via History and live Events</dd>
     *    </dl>
     *
     *  Traces are only sent as events or stored for historical access if
     *  the trace is active, i.e. UaAppTraceEnabled is set to `true`, and
     *  UaAppTraceLevel (i.e. the server application trace level) is set
     *  at least to `Errors`.
     *
     *  @return Error code.
     */
    virtual UaStatus getTraceEventSettings(
        OpcUa_UInt32&  uTraceEventLevel     /**< [out] Configures the level of messages traced;
                                                       possible values are
                                                       - (0) Disabled
                                                       - (1) History
                                                       - (2) HistoryAndEvents */
        ) const;

    /** Returns the maximum age of a request the server allows.
     *  @return               Maximum age of a request the server allows.
     */
    virtual OpcUa_Int32 getMaxRequestAge() const = 0;

    /** Get the setting parameters for session creation.
     *  @return                     Error code.
     */
    virtual UaStatus getSessionSettings(
        OpcUa_Int32& iMaxSessionCount,      //!< [out] Maximum number of sessions the server allows to create
        OpcUa_Int32& iMaxSessionsPerClient, //!< [out] Maximum number of sessions the server allows per Client, 0 is no limitation
        OpcUa_Int32& iMinSessionTimeout,    //!< [out] Minimum timeout in ms for a sessions the server allows to set
        OpcUa_Int32& iMaxSessionTimeout     //!< [out] Maximum timeout in ms for a sessions the server allows to set
        ) const = 0;

    /** Get the general setting parameters for the server.
     *  @return                     Error code.
     */
    virtual UaStatus getServerSettings(
        OpcUa_Double&       minSupportedSampleRate,     //!< [out] Minimum supported sample rate by the server provided as capability information to the client
        UaStringArray&      localeIdArray,              //!< [out] Array of LocaleIds that are known to be supported by the server.
        UaStringArray&      serverProfileArray,         //!< [out] Array of conformance profile URIs indicating the features supported by the server.
        UaByteStringArray&  softwareCertificateArray    //!< [out] Array of software certificates containing all certificates supported by the server.
        ) const = 0;

    /** Returns the maximum number of Browse Continuation Points managed by the server.
     *  @return               Maximum number of Browse Continuation Points managed by the server.
     */
    virtual OpcUa_Int32 getMaxBrowseContinuationPoints() const = 0;

    /** Returns the maximum number of Browse results for one browse operation.
     *  @return               Maximum number of Browse results for one browse operation.
     */
    virtual OpcUa_Int32 getMaxBrowseResults() const;

    /** Returns the maximum number of nodes to browse the server will accept.
     *  @return               Maximum number of nodes to browse. Default 0 is unlimited.
     */
    virtual OpcUa_Int32 getMaxNodesToBrowse() const;

    /** Returns the maximum number of nodes the server will accept for a TranslateBrowsePathsToNodeIds service request.
    *  @return               Maximum number of nodes. Default 0 is unlimited.
    */
    virtual OpcUa_UInt32 getMaxNodesPerTranslateBrowsePathsToNodeIds() const;

    /** Get the operation limit setting parameters for historical access.
     *  @return               Error code.
     */
    virtual UaStatus getMaxNodesPerHistoryService(
        OpcUa_UInt32& iMaxNodesPerHistoryReadData,    //!< [out] Maximum number of nodes for HistoryRead service for Raw, Modified, Processed and AtTime
        OpcUa_UInt32& iMaxNodesPerHistoryReadEvents,  //!< [out] Maximum number of nodes for HistoryRead service for Events
        OpcUa_UInt32& iMaxNodesPerHistoryUpdateData,  //!< [out] Maximum number of nodes for HistoryUpdate service for Data
        OpcUa_UInt32& iMaxNodesPerHistoryUpdateEvents //!< [out] Maximum number of nodes for HistoryUpdate service for Events
        ) const;

    /** Returns the maximum number of History Continuation Points managed by the server.
    * @return               Maximum number of History Continuation Points managed by the server.
    */
    virtual OpcUa_Int32 getMaxHistoryContinuationPoints() const = 0;

    /** Get the setting parameters for a subscription.
     *  @return                             Error code.
     */
    virtual UaStatus getSubscriptionSettings(
        OpcUa_UInt32& iMinPublishingInterval,       //!< [out] Minimum publishing interval in milliseconds the server allows
        OpcUa_UInt32& iMaxPublishingInterval,       //!< [out] Maximum publishing interval in milliseconds the server allows
        OpcUa_UInt32& iMinKeepAliveInterval,        //!< [out] Minimum KeepAlive interval  in milliseconds the server allows
        OpcUa_UInt32& iMinSubscriptionLifetime,     //!< [out] Minimum Subscription lifetime in milliseconds the server allows
        OpcUa_UInt32& iMaxSubscriptionLifetime,     //!< [out] Maximum Subscription lifetime in milliseconds the server allows
        OpcUa_UInt32& iMaxRetransmissionQueueSize,  //!< [out] Maximum number of messages in the republish queue the server allows per Subscription
        OpcUa_UInt32& iMaxNotificationsPerPublish   //!< [out] Maximum number of notifications per Publish the server allows
        ) const = 0;

    /** Get the setting parameters for a MonitoreItem.
     *  @return                             Error code.
     */
    virtual UaStatus getMonitoredItemSettings(
        OpcUa_UInt32& iMaxDataQueueSize,    //!< [out] Maximum queue size for a data monitored item
        OpcUa_UInt32& iMaxEventQueueSize    //!< [out] Maximum queue size for an event monitored item
        ) const = 0;

    /** Get the max object count parameters for Subscriptions.
     *  @return                             Error code.
     */
    virtual UaStatus getSubscriptionMaxCountSettings(
        OpcUa_UInt32& iMaxSubscriptionCount,                 //!< [out] Maximum number of subscriptions the server allows to create. Default value 0 is unlimited
        OpcUa_UInt32& iMaxSubscriptionsPerSession,           //!< [out] Maximum number of subscriptions the server allows to create per session. Default value 0 is unlimited
        OpcUa_UInt32& iMaxMonitoredItemCount,                //!< [out] Maximum number of monitored items the server allows to create. Default value 0 is unlimited
        OpcUa_UInt32& iMaxMonitoredItemPerSubscriptionCount, //!< [out] Maximum number of monitored items per subscriptions the server allows to create. Default value 0 is unlimited
        OpcUa_UInt32& iMaxMonitoredItemPerSessionCount       //!< [out] Maximum number of monitored items per session the server allows to create. Default value 0 is unlimited
        ) const;

    /** Returns the sampling rates provided by the OPC server.
     *  @return Error code.
     */
    virtual UaStatus getAvailableSamplingRates(
        UaUInt32Array& availableSamplingRates   //!< [out] Array of sampling rates provided by the OPC server.
        ) const = 0;

    /** Returns the build information for the OPC server.
     *  @return                 the build information for the OPC server.
     */
    virtual OpcUa_StatusCode getBuildInfo(
        UaString&       ProductUri,         //!< [out] Returns the URI that identifies the software containing the OPC server.
        UaString&       ManufacturerName,   //!< [out] Returns the name of the software manufacturer.
        UaString&       ProductName,        //!< [out] Returns the name of the software containing the OPC server.
        UaString&       sSoftwareVersion,   //!< [out] Returns the software version.
        UaString&       sBuildNumber,       //!< [out] Returns the build number.
        OpcUa_DateTime& BuildDate           //!< [out] Returns the date and time of the build.
        ) const = 0;

    /** Returns the server instance information for the OPC server.
     *  @return             the server instance information for the OPC server.
     */
    virtual OpcUa_StatusCode getServerInstanceInfo(
        UaString&             ServerUri,    //!< [out] Returns the URI that identifies the application instance containing the OPC server.
        UaLocalizedTextArray& ServerName    //!< [out] Returns the name of the software instance containing the OPC server.
        ) const = 0;

    /** Returns the ServerId used for audit events.
     * The default implementation returns the ServerUri. Transparent redundant servers must extend the ServerUri with a unique identifier for
     * the server in the redundant set.
     */
    virtual UaString getServerId() const;

    /** Returns the settings for the thread pools used in the OPC server.
     *  @return                             Error code.
     */
    virtual UaStatus getThreadPoolSettings(
        OpcUa_UInt32&   minSizeTransactionManager,  //!< [out] Returns the number of threads that are created when the thread pool for the UaTransactionManager is created.
        OpcUa_UInt32&   maxSizeTransactionManager,  //!< [out] Returns the maximum number of threads allowed for the thread pool in the UaTransactionManager.
        OpcUa_UInt32&   minSizeSubscriptionManager, //!< [out] Returns the number of threads that are created when the thread pool for the UaSubscriptionManager is created.
        OpcUa_UInt32&   maxSizeSubscriptionManager  //!< [out] Returns the maximum number of threads allowed for the thread pool in the UaSubscriptionManager.
        ) const = 0;

    /** Creates a session object for the OPC server.
     *  This could be an instance of the default Session class provided by the SDK or a derived
     *  class that contains application specific functionality and vendor specific data related
     *  to the underlying system.
     *  @return                    Session object
     */
    virtual Session* createSession(
        OpcUa_Int32 sessionID,                  //!< [out] Session Id created by the server application.
        const UaNodeId &authenticationToken     //!< [out] Secret session Id created by the server application.
        ) = 0;

    /** Validates the user identity token and sets the user for a session.
     *  @return                     Error code
     */
    virtual UaStatus logonSessionUser(
        Session*             pSession,          //!< [out] Interface pointer of the Session
        UaUserIdentityToken* pUserIdentityToken /**< [out] User identity token contained in an ExtensionObject used to handle different types of user identity
                                                           tokens like user/password or an X509 certificate. It provides the credentials of the user associated
                                                           with the Client application. The implementation of this method must use these credentials to determine
                                                           whether the Client should be allowed to activate a Session and what resources the Client has access to
                                                           during this Session.If the method is not able to validate the user or if the user has no right to
                                                           access the server, the method must return the status code OpcUa_BadUserAccessDenied.*/
        ) = 0;

    /** Flag indicating if audit events are activated.
     *  @return  True if audit events are active and False if not.
     */
    virtual OpcUa_Boolean isAuditActivated();

    /** Provides the redundancy settings for the server.
     *
     *  There are three main options available, None, NonTransparent (with cold, warm and hot) and Transparent redundancy.
     *  This configuration covers the options None and NonTransparent. The option Transparent requires an additional SDK module.
     *  This redundancy module is also providing the required settings and creates the corresponding diagnostic and capability object.
     *  @return Error code
     */
    virtual UaStatus getRedundancySettings(
        OpcUa_RedundancySupport& redundancySupport, /**< [out] Redundancy support options
                                                                - OpcUa_RedundancySupport_None (serverUriArray is ignored)
                                                                - OpcUa_RedundancySupport_Cold
                                                                - OpcUa_RedundancySupport_Warm
                                                                - OpcUa_RedundancySupport_Hot
                                                                - OpcUa_RedundancySupport_Transparent (other settings are handled by redundancy module)*/
        UaStringArray&           serverUriArray  //!< [out] List of server URIs for the servers in the NonTransparent redundant set
        );

    /** Provides the network redundancy settings for NonTransparent redundant servers.
     *  @return Error code
     */
    virtual UaStatus getNetworkRedundancySettings(
        UaNetworkGroupDataTypes& networkGroupArray  //!< [out] List of server network groups for NonTransparent redundant set
        );

    /** Provides capability to configure additional servers to be returned in FindServers.
     *
     *  Every server must implement FindServers and must return its own application description. This can also be used to run the
     *  server on the default port 4840 if only one server is installed on the system. This configuration option allows to run this server
     *  on port 4840 but to return also additional servers for a fixed configuration e.g. two servers from the same vendor on one network node.
     *  @return Error code
     */
    virtual UaStatus getAdditionalServerEntries(
        UaApplicationDescriptions& serverDescriptions //!< [out] List of application descriptions containing the information for the additional servers to return.
        );

    /** Provides configuration option for namespaces other than index 0 and 1 (OPC UA and local server).
     *
     *  This allows the assignment of namespace URIs to a specific index independent of the loading sequence of NodeManagers.
     *  @return Error code
     */
    virtual UaStatus getConfiguredNamespaces(
        UaUInt16Array& namespaceIndexArray, //!< [out] List of indices for the namespaces in the namespace table
        UaStringArray& namespaceUriArray,   //!< [out] List of namespace URIs in the namespace table
        UaBoolArray&   allowRenameUriArray, /**< [out] List of flags indicating if module responsible for the namespace supports a change of the namespace URI
                                                       in the configuration. If this flag is set to true, the optional parameter UniqueId must be provided.*/
        UaStringArray& uniqueIdArray,       //!< [out] List of unique IDs required to identify the namespace if the module allows to change the namespace URI in the configuration
        UaStringArray& comAliasArray        //!< [out] List of aliases used to create COM ItemIds or other COM identifiers
        );

    /** Adds a namespaces configuration entry for preconfigured namespaces.
     *
     *  @see getConfiguredNamespaces. The default implementation is empty and is not storing the added entry.
     *  @return Error code
     */
    virtual UaStatus addConfiguredNamespace(
        OpcUa_UInt16    namespaceIndex, //!< [in] Index for the namespace in the namespace table
        const UaString& namespaceUri,   //!< [in] Namespace URI in the namespace table
        OpcUa_Boolean   allowRenameUri, //!< [in] Flag indicating if module responsible for the namespace supports a change of the namespace URI in the configuration
        const UaString& uniqueId        //!< [in] Unique ID required to identify the namespace if the module allows to change the namespace URI in the configuration
        );

    /** Removes a namespaces configuration entry for preconfigured namespaces.
     *
     *  @see getConfiguredNamespaces. The default implementation is empty and is not storing the added entry.
     *  @return Error code
     */
    virtual UaStatus removeConfiguredNamespace(
        OpcUa_UInt16    namespaceIndex //!< [in] Index for the namespace in the namespace table
        );

    /** Provides information about tagfile name, path und file ending used in the NodeManagerTagFile.
     *
     *  The default implementation returns empty strings.
     *  @return Error code
     */
    virtual UaStatus getTagFileConfiguration(
        UaString &defaultTagFileName,       //!< [out] Name of the tagfile to load on server startup.
        UaString &tagFileLocation,          //!< [out] The folder where all tagfiles are stored.
        UaString &tagFileEnding,            //!< [out] The file ending used for new tagfiles.
        UaString &defaultFileUpdatePolicy   //!< [out] How the Default file gets updated (Auto, Manual).
        );

    /** Set information about tagfile name, path und file ending used in the NodeManagerTagFile.
     *
     *  The default implementation does nothing.
     *  @return Error code
     */
    virtual UaStatus setTagFileConfiguration(
        const UaString &defaultTagFileName,     //!< [in] Name of the tagfile to load on server startup.
        const UaString &tagFileLocation,        //!< [in] The folder where all tagfiles are stored.
        const UaString &tagFileEnding,          //!< [in] The file ending used for new tagfiles.
        const UaString &defaultFileUpdatePolicy //!< [in] How the Default file gets updated (Auto, Manual).
        );

    /* Save the thumbprint for the server certificate. This is used to find a certificate in the windows store.
     *
     *  The default implementation does nothing.
     *  @return Error code
     */
    virtual UaStatus setServerCertificateThumbprint(
        const UaString &thumbprint              //!< [in] Thumbprint of the server certificate used for windows store.
        );

    /** Provides settings for HTTP file access capability.
     *
     *  The default implementation returns inactive.
     *  @return Error code
     */
    virtual UaStatus getHttpFileAccess(
        OpcUa_Boolean &active,       //!< [out] Flag indicating if the file access is active.
        UaString      &filePath      //!< [out] The path to the directory with the HTML files.
        );

    /** Provides a mapping list of OPC UA property names to COM Data Access property Ids.
     *
     *  The address space managed by the SDK or custom NodeManager implementations is created based on the OPC UA model.
     *  In OPC UA, properties are identified by qualified names. These names are defined by standardization bodies like the OPC Foundation
     *  for the standard OPC UA properties or by vendors or users.
     *  In classic OPC Data Access, properties are defined by integer IDs defined by the OPC Foundation or by vendors. This method
     *  provides the mapping table of OPC UA porperty names to classic OPC Data Access property IDs. This mapping table is only needed for
     *  servers providing a classic OPC Data Access interface in addition to the OPC UA interface.
     *  The default implementation returns empty lists
     *  @return Error code
     */
    virtual UaStatus getComDaPropertyMapping(
        UaStringArray& propertyNames,      //!< [out] List of OPC UA Property names
        UaStringArray& propertyNameSpaces, //!< [out] List of OPC UA Property name spaces
        UaUInt32Array& propertyIds         //!< [out] List of classic OPC Data Access Property Ids
        );

    /** Adds an entry to the mapping list of OPC UA property names to COM Data Access property Ids.
     *
     *  The address space managed by the SDK or custom NodeManager implementations is created based on the OPC UA model.
     *  In OPC UA, properties are identified by qualified names. These names are defined by standardization bodies like the OPC Foundation
     *  for the standard OPC UA properties or by vendors or users.
     *  In classic OPC Data Access, properties are defined by integer IDs defined by the OPC Foundation or by vendors. This method
     *  adds an entry to the mapping table of OPC UA porperty names to classic OPC Data Access property IDs. This mapping table is only needed for
     *  servers providing a classic OPC Data Access interface in addition to the OPC UA interface.
     *  The default implementation is empty and is not storing the added entry
     *  @return Error code
     */
    virtual UaStatus addComDaPropertyMapping(
        const UaString& propertyName,         //!< [in] OPC UA Property name
        const UaString& propertyNameSpaceUri, //!< [in] OPC UA Property name space URI
        OpcUa_UInt32    propertyId            //!< [in] Classic OPC Data Access Property Id
        );

    /** Provides additional namespace related information for COM DA Server module.
     *
     *  The default implementation returns empty strings and lists.
     *  @return Error code
     */
    virtual UaStatus getComDaNamespaceInformation(
        UaString& defaultNamespace,   //!< [out] Default namespace URI used to create ItemIds without namespace URI
        UaUShort& namespaceDelimiter, //!< [out] Delimiter used in ItemIDs between Namespace URI and Identifier
        OpcUa_Boolean& useComAlias    //!< [out] Flag indicating if the COM alias for namespaces is used in ItemIDs
        );

    /** ComDaTimestampSource enumeration  */
    enum ComDaTimestampSource
    {
        INTERNAL,           /*!< The timestamps are created inside the server. This is invalid for historical access. */
        SOURCE_TIMESTAMP,   /*!< The OPC UA Source Timestamp is used */
        SERVER_TIMESTAMP    /*!< The OPC UA Server Timestamp is used */
    };

    /** Provides the timestamp source for COM Data Access items. */
    virtual ComDaTimestampSource getComDaTimestampSource();

    /** Provides the timestamp source for COM Historical Data Access items. */
    virtual ComDaTimestampSource getComHdaTimestampSource();

    /** When browsing for COM DA items this option causes the server to internally browse one additional level to see if there are any children.
    */
    virtual OpcUa_Boolean getBrowseNextLevelForVariables();

    /** Provides additional namespace related information for COM A&E Server module.
     *
     *  The default implementation returns empty strings and lists.
     *  @return Error code
     */
    virtual UaStatus getComAeNamespaceInformation(
        UaString& defaultNamespace      //!< [out] Default namespace URI used to create fully qualified names without namespace URI
        );

    /** ComAeEventType enumeration  */
    enum ComAeEventType
    {
        SIMPLE_EVENT,     /*!< Simple event */
        TRACKING_EVENT,   /*!< Tracking event */
        CONDITION_EVENT   /*!< Condition event */
    };

    /** Provides a mapping list of OPC UA event type NodeIds to COM Alarms and Events category IDs.
     *
     *  The event type hirarchy managed by the SDK or custom NodeManager implementations is created based on the OPC UA model.
     *  In OPC UA, event types are identified by NodeIds. These NodeIds are defined by standardization bodies like the OPC Foundation
     *  for the standard OPC UA event types or by vendors or users.
     *  In classic OPC Alarms & Events, event category IDs are DWORDS. This method provides the mapping table of OPC UA event type
     *  NodeIds to classic OPC Alarms & Events category IDs. This mapping table is only needed for
     *  servers providing a classic OPC Alarms & Events interface in addition to the OPC UA interface.
     *  The default implementation returns empty lists
     *  @return Error code
     */
    virtual UaStatus getComAeEventCategoryMapping(
        ComAeEventType eventType,     //!< [in] Event type for the categories to return
        UaUInt32Array& categoryIDs,   //!< [out] List of OPC A&E category names
        UaStringArray& categoryNames, //!< [out] List of OPC A&E category names
        UaNodeIdArray& eventTypeIds,  //!< [out] List of OPC UA event type NodeIds
        UaStringArray& namespaceUris, //!< [out] List of namespace URIs for the event type id. The string is empty for namespace 0
        UaBoolArray&   visbilityFlags //!< [out] List of flags indicating if the category is visible
        );

    /** Adds a mapping list of OPC UA event type NodeIds to COM Alarms and Events category IDs.
     *
     *  The event type hirarchy managed by the SDK or custom NodeManager implementations is created based on the OPC UA model.
     *  In OPC UA, event types are identified by NodeIds. These NodeIds are defined by standardization bodies like the OPC Foundation
     *  for the standard OPC UA event types or by vendors or users.
     *  In classic OPC Alarms & Events, event category IDs are DWORDS. This method provides the mapping table of OPC UA event type
     *  NodeIds to classic OPC Alarms & Events category IDs. This mapping table is only needed for
     *  servers providing a classic OPC Alarms & Events interface in addition to the OPC UA interface.
     *  The default implementation does not store the list
     *  @return Error code
     */
    virtual UaStatus addComAeEventCategoryMapping(
        ComAeEventType eventType,           //!< [in] Event type for the categories to add
        const UaUInt32Array& categoryIDs,   //!< [in] List of OPC A&E category names
        const UaStringArray& categoryNames, //!< [in] List of OPC A&E category names
        const UaNodeIdArray& eventTypeIds,  //!< [in] List of OPC UA event type NodeIds
        const UaStringArray& namespaceUris  //!< [in] List of namespace URIs for the event type id. The string is empty for namespace 0
        );

    /** Get the mapping list of OPC UA event fields to COM Alarms and Events attribute IDs.
     *
     *  The event type hirarchy and its event fields are managed by the SDK or custom NodeManager implementations is created based on the OPC UA model.
     *  In OPC UA, event fields are identified by a path of QualifiedNames starting from the EventType. These QualifiedNames are defined by
     *  standardization bodies like the OPC Foundation for the standard OPC UA event types or by vendors or users.
     *  for the standard OPC UA event types or by vendors or users.
     *  In classic OPC Alarms & Events, attribute IDs are DWORDS. This method adds an entrie to the mapping table of OPC UA event fields
     *  to classic OPC Alarms & Events attribute IDs. This mapping table is only needed for
     *  servers providing a classic OPC Alarms & Events interface in addition to the OPC UA interface.
     *  @return                                 Error code.
     */
    virtual UaStatus getComAeAttributeMapping(
        ComAeAttributeMappingArray& comAeAttributeMappingArray //!< [out] Array of configured mappings between OPC UA event fields and COM Alarms and Events attribute IDs.
        );

    /** Adds an entry to the mapping list of OPC UA event fields to COM Alarms and Events attribute IDs.
     *
     *  The event type hirarchy and its event fields are managed by the SDK or custom NodeManager implementations is created based on the OPC UA model.
     *  In OPC UA, event fields are identified by a path of QualifiedNames starting from the EventType. These QualifiedNames are defined by
     *  standardization bodies like the OPC Foundation for the standard OPC UA event types or by vendors or users.
     *  for the standard OPC UA event types or by vendors or users.
     *  In classic OPC Alarms & Events, attribute IDs are DWORDS. This method adds an entrie to the mapping table of OPC UA event fields
     *  to classic OPC Alarms & Events attribute IDs. This mapping table is only needed for
     *  servers providing a classic OPC Alarms & Events interface in addition to the OPC UA interface.
     *  @return Error code
     */
    virtual UaStatus addComAeAttributeMapping(
        OpcUa_UInt32         attributeID,     //!< [in] Attribute ID
        const UaString&      attributeName,   //!< [in] Attribute Name
        OpcUa_BuiltInType    dataType,        //!< [in] Data type of the attribute
        OpcUa_Boolean        isArray,         //!< [in] Array flag for the data type of the attribute
        const UaStringArray& eventFieldPathNames, //!< [in] List of event field path names
        const UaStringArray& eventFieldPathNamespaceUris //!< [in] List of event field path namespace URIs
        );

    /** Lock snchronization object for configuratin changes.
     */
    virtual void lockConfigFile();

    /** Unlock snchronization object for configuratin changes.
     */
    virtual void unlockConfigFile();
};

/** Data class for COM A&E Attributes mapping to OPC UA event fields.
*/
class SERVER_CORE_EXPORT ComAeAttributeMapping
{
public:
    ComAeAttributeMapping();
    ~ComAeAttributeMapping();

    OpcUa_UInt32         m_attributeId;
    UaStringArray        m_eventFieldPathNames;
    UaStringArray        m_eventFieldPathNamespaceUris;
    UaString             m_attributeName;
    OpcUa_BuiltInType    m_dataType;
    OpcUa_Boolean        m_isArray;
    OpcUa_Boolean        m_isVisible;

private:
};

#endif // SERVERCONFIG_H
