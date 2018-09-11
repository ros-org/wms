/******************************************************************************
** uasession.h
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
** Project: C++ OPC Client SDK
**
** Description: Interface for UA Session.
**
******************************************************************************/
#ifndef UACLIENTSDK_UASESSION_H
#define UACLIENTSDK_UASESSION_H

#include "uaclientsdk.h"
#include "uasubscription.h"
#include "uacontentfilter.h"
#include <uaaddnodesitem.h>
#include <uaaddreferencesitem.h>
#include <uadeletenodesitem.h>
#include <uadeletereferencesitem.h>
#include <uadatatypedefinition.h>
#include <uaargument.h>

namespace UaClientSdk {

/*! \addtogroup UaClientLibrary
*  @{
*/

/** \brief The UaSession class manges a UA Client side application session.
*
* This is the main class for connecting with any OPC UA Server. The class manages the connection
* to an OPC Unified Architecture server and the application session established with the server.
* The class provides all non Subscription related UA Services as synchronous and asynchronous methods.
*
* The connect call establishes and maintains a Session with a Server. After a successful connect, the
* connection is monitored by the SDK. Connection status changes are reported through the callback
* \ref UaClientSdk::UaSessionCallback::connectionStatusChanged "UaSessionCallback::connectionStatusChanged".
*
* A UaSession object is thread-safe.
*/
class UACLIENT_EXPORT UaSession : public UaDataTypeDictionary, protected CertificateValidationCallback
{
    friend class UaSessionPrivate;
    UA_DISABLE_COPY(UaSession);
    UaSession(UaSessionPrivate* pSessionPrivate);
public:
    UaSession();
    UaSession(UaSession* pSession);
    virtual ~UaSession();

    // Establish a connection to the OPC UA server
    UaStatus connect(
        const UaString&      sURL,
        SessionConnectInfo&  sessionConnectInfo,
        SessionSecurityInfo& sessionSecurityInfo,
        UaSessionCallback*   pSessionCallback);

    // Disconnect client application from OPC UA server
    UaStatus disconnect(
        ServiceSettings& serviceSettings,
        OpcUa_Boolean    bDeleteSubscriptions);

    // Change user for the connection to the OPC UA server
    UaStatus changeUser(
        ServiceSettings&     serviceSettings,
        UaUserIdentityToken* pUserIdentityToken);

    // Browse OPC server address space with one starting node.
    UaStatus browse(
        ServiceSettings&         serviceSettings,
        const UaNodeId&          nodeToBrowse,
        const BrowseContext&     browseContext,
        UaByteString&            continuationPoint,
        UaReferenceDescriptions& referenceDescriptions);

    // Continue a previous browse request
    UaStatus browseNext(
        ServiceSettings&         serviceSettings,
        OpcUa_Boolean            releaseContinuationPoint,
        UaByteString&            continuationPoint,
        UaReferenceDescriptions& referenceDescriptions);

    // Browse OPC server address space with a list of starting node.
    UaStatus browseList(
        ServiceSettings&             serviceSettings,
        const OpcUa_ViewDescription& viewDescription,
        OpcUa_UInt32                 maxReferencesToReturn,
        const UaBrowseDescriptions&  browseDescription,
        UaBrowseResults&             browseResults,
        UaDiagnosticInfos&           diagnosticInfos);

    // Continue a previous browseList request
    UaStatus browseListNext(
        ServiceSettings&         serviceSettings,
        OpcUa_Boolean            releaseContinuationPoint,
        const UaByteStringArray& continuationPoints,
        UaBrowseResults&         browseResults,
        UaDiagnosticInfos&       diagnosticInfos);

    // Translate a browse path to a NodeId.
    UaStatus translateBrowsePathsToNodeIds(
        ServiceSettings&     serviceSettings,
        const UaBrowsePaths& browsePaths,
        UaBrowsePathResults& browsePathResults,
        UaDiagnosticInfos&   diagnosticInfos);

    // Register nodes to create shortcuts in the server.
    UaStatus registerNodes(
        ServiceSettings&     serviceSettings,
        const UaNodeIdArray& nodesToRegister,
        UaNodeIdArray&       registeredNodesIds);

    // Unregister nodes to delete shortcuts in the server.
    UaStatus unregisterNodes(
        ServiceSettings&     serviceSettings,
        const UaNodeIdArray& registeredNodesIds);

    // Reads variable values synchronous from OPC server
    UaStatus read(
        ServiceSettings&         serviceSettings,
        OpcUa_Double             maxAge,
        OpcUa_TimestampsToReturn timeStamps,
        const UaReadValueIds&    nodesToRead,
        UaDataValues&            values,
        UaDiagnosticInfos&       diagnosticInfos);

    // Reads variable values asynchronous from OPC server
    UaStatus beginRead(
        ServiceSettings&         serviceSettings,
        OpcUa_Double             maxAge,
        OpcUa_TimestampsToReturn timeStamps,
        const UaReadValueIds&    nodesToRead,
        OpcUa_UInt32             transactionId);

    // Writes variable values synchronous to OPC server
    UaStatus write(
        ServiceSettings&     serviceSettings,
        const UaWriteValues& nodesToWrite,
        UaStatusCodeArray&   results,
        UaDiagnosticInfos&   diagnosticInfos);

    // Writes variable values asynchronous to OPC server
    UaStatus beginWrite(
        ServiceSettings&     serviceSettings,
        const UaWriteValues& nodesToWrite,
        OpcUa_UInt32         transactionId);

    // Creates a subscription
    UaStatus createSubscription(
        ServiceSettings&        serviceSettings,
        UaSubscriptionCallback* pUaSubscriptionCallback,
        OpcUa_UInt32            clientSubscriptionHandle,
        SubscriptionSettings&   subscriptionSettings,
        OpcUa_Boolean           publishingEnabled,
        UaSubscription**        ppUaSubscription);

    // Deletes a subscription
    UaStatus deleteSubscription(
        ServiceSettings& serviceSettings,
        UaSubscription** ppUaSubscription,
        OpcUa_UInt32 waitTimeForTransactionCompletion = 100);

    // Transfer a subscription from another client to this session
    UaStatus transferSubscription(
        ServiceSettings&        serviceSettings,
        UaSubscriptionCallback* pUaSubscriptionCallback,
        OpcUa_UInt32            clientSubscriptionHandle,
        OpcUa_UInt32            subscriptionId,
        SubscriptionSettings&   subscriptionSettings,
        OpcUa_Boolean           publishingEnabled,
        OpcUa_Boolean           sendInitialValues,
        UaSubscription**        ppUaSubscription,
        UaUInt32Array&          availableSequenceNumbers);

    // Calls a method of an Object in the OPC server
    UaStatus call(
        ServiceSettings& serviceSettings,
        const CallIn&    callRequest,
        CallOut&         results);

    // Calls a method of an Object in the OPC server asynchronous
    UaStatus beginCall(
        ServiceSettings& serviceSettings,
        const CallIn&    callRequest,
        OpcUa_UInt32     transactionId);

    // Calls a list of methods of Objects in the OPC server
    UaStatus callList(
        ServiceSettings&            serviceSettings,
        const UaCallMethodRequests& callMethodRequests,
        UaCallMethodResults&        callMethodResults,
        UaDiagnosticInfos&          diagnosticInfos);

    // Reads the history of item values synchronous from OPC server
    UaStatus historyReadRawModified(
        ServiceSettings&                     serviceSettings,
        const HistoryReadRawModifiedContext& historyReadRawModifiedContext,
        const UaHistoryReadValueIds&         nodesToRead,
        HistoryReadDataResults&              results,
        UaDiagnosticInfos&                   diagnosticInfos);

    // Reads the processed history of item values synchronous from the OPC server based on a passed aggregate
    UaStatus historyReadProcessed(
        ServiceSettings&                   serviceSettings,
        const HistoryReadProcessedContext& historyReadProcessedContext,
        const UaHistoryReadValueIds&       nodesToRead,
        HistoryReadDataResults&            results,
        UaDiagnosticInfos&                 diagnosticInfos);

    // Reads the history of item values synchronous from OPC server for the given timestamps
    UaStatus historyReadAtTime(
        ServiceSettings&                serviceSettings,
        const HistoryReadAtTimeContext& historyReadAtTimeContext,
        const UaHistoryReadValueIds&    nodesToRead,
        HistoryReadDataResults&         results,
        UaDiagnosticInfos&              diagnosticInfos);

    // Reads the history of events from an event notifier object synchronous from OPC server
    UaStatus historyReadEvent(
        ServiceSettings&                serviceSettings,
        const HistoryReadEventContext&  historyReadEventContext,
        const UaHistoryReadValueIds&    nodesToRead,
        HistoryReadEventResults&        results,
        UaDiagnosticInfos&              diagnosticInfos);

    // Update the history of item values synchronous at OPC server
    UaStatus historyUpdateData(
        ServiceSettings&         serviceSettings,
        const UpdateDataDetails& updateDataDetails,
        UaHistoryUpdateResults&  results,
        UaDiagnosticInfos&       diagnosticInfos);

    // Delete the history of item values synchronous at OPC server
    UaStatus historyDeleteRawModified(
        ServiceSettings&          serviceSettings,
        const DeleteRawModifiedDetails& deleteDetails,
        UaHistoryUpdateResults&   results,
        UaDiagnosticInfos&        diagnosticInfos);

    // Delete the history of item values synchronous at OPC server for the given timestamps
    UaStatus historyDeleteAtTime(
        ServiceSettings&           serviceSettings,
        const DeleteAtTimeDetails& deleteDetails,
        UaHistoryUpdateResults&    results,
        UaDiagnosticInfos&         diagnosticInfos);

    // Update the history of events synchronous at OPC server
    UaStatus historyUpdateEvents(
        ServiceSettings&          serviceSettings,
        const UpdateEventDetails& updateEventDetails,
        UaHistoryUpdateResults&   results,
        UaDiagnosticInfos&        diagnosticInfos);

    // Delete the history of events synchronous at OPC server for the given event Ids
    UaStatus historyDeleteEvents(
        ServiceSettings&          serviceSettings,
        const DeleteEventDetails& deleteDetails,
        UaHistoryUpdateResults&   results,
        UaDiagnosticInfos&        diagnosticInfos);

    // Reads the history of item values asynchronous from OPC server
    UaStatus beginHistoryReadRawModified(
        ServiceSettings&                     serviceSettings,
        const HistoryReadRawModifiedContext& historyReadRawModifiedContext,
        const UaHistoryReadValueIds&         nodesToRead,
        OpcUa_UInt32                         transactionId);

    // Reads the processed history of item values asynchronous from the OPC server based on a passed aggregate
    UaStatus beginHistoryReadProcessed(
        ServiceSettings&                   serviceSettings,
        const HistoryReadProcessedContext& historyReadProcessedContext,
        const UaHistoryReadValueIds&       nodesToRead,
        OpcUa_UInt32                       transactionId);

    // Reads the history of item values asynchronous from OPC server for the given timestamps
    UaStatus beginHistoryReadAtTime(
        ServiceSettings&                serviceSettings,
        const HistoryReadAtTimeContext& historyReadAtTimeContext,
        const UaHistoryReadValueIds&    nodesToRead,
        OpcUa_UInt32                    transactionId);

    // Reads the history of events from an event notifier object asynchronous from OPC server
    UaStatus beginHistoryReadEvent(
        ServiceSettings&                serviceSettings,
        const HistoryReadEventContext&  historyReadEventContext,
        const UaHistoryReadValueIds&    nodesToRead,
        OpcUa_UInt32                    transactionId);

    // Update the history of item values asynchronous at OPC server
    UaStatus beginHistoryUpdateData(
        ServiceSettings&         serviceSettings,
        const UpdateDataDetails& updateDataDetails,
        OpcUa_UInt32             transactionId);

    // Delete the history of item values asynchronous at OPC server
    UaStatus beginHistoryDeleteRawModified(
        ServiceSettings&                serviceSettings,
        const DeleteRawModifiedDetails& deleteDetails,
        OpcUa_UInt32                    transactionId);

    // Delete the history of item values asynchronous at OPC server for the given timestamps
    UaStatus beginHistoryDeleteAtTime(
        ServiceSettings&           serviceSettings,
        const DeleteAtTimeDetails& deleteDetails,
        OpcUa_UInt32               transactionId);

    // Update the history of events asynchronous at OPC server
    UaStatus beginHistoryUpdateEvents(
        ServiceSettings&          serviceSettings,
        const UpdateEventDetails& updateEventDetails,
        OpcUa_UInt32              transactionId);

    // Delete the history of events asynchronous at OPC server for the given event Ids
    UaStatus beginHistoryDeleteEvents(
        ServiceSettings&          serviceSettings,
        const DeleteEventDetails& deleteDetails,
        OpcUa_UInt32              transactionId);

    // Adds a list of nodes to the OPC server address space
    UaStatus addNodes(
        ServiceSettings&       serviceSettings,
        const UaAddNodesItems& nodesToAdd,
        UaAddNodesResults&     results,
        UaDiagnosticInfos&     diagnosticInfos);

    // Adds a list of references to the OPC server address space
    UaStatus addReferences(
        ServiceSettings&            serviceSettings,
        const UaAddReferencesItems& referencesToAdd,
        UaStatusCodeArray&          results,
        UaDiagnosticInfos&          diagnosticInfos);

    // Removes a list of nodes from the OPC server address space
    UaStatus deleteNodes(
        ServiceSettings&          serviceSettings,
        const UaDeleteNodesItems& nodesToDelete,
        UaStatusCodeArray&        results,
        UaDiagnosticInfos&        diagnosticInfos);

    // Removes a list of references from the OPC server address space
    UaStatus deleteReferences(
        ServiceSettings&               serviceSettings,
        const UaDeleteReferencesItems& referencesToDelete,
        UaStatusCodeArray&             results,
        UaDiagnosticInfos&             diagnosticInfos);

    // Adds a list of nodes asynchronous to the OPC server address space
    UaStatus beginAddNodes(
        ServiceSettings&       serviceSettings,
        const UaAddNodesItems& nodesToAdd,
        OpcUa_UInt32           transactionId);

    // Adds a list of references asynchronous to the OPC server address space
    UaStatus beginAddReferences(
        ServiceSettings&            serviceSettings,
        const UaAddReferencesItems& referencesToAdd,
        OpcUa_UInt32                transactionId);

    // Removes a list of nodes asynchronous from the OPC server address space
    UaStatus beginDeleteNodes(
        ServiceSettings&          serviceSettings,
        const UaDeleteNodesItems& nodesToDelete,
        OpcUa_UInt32              transactionId);

    // Removes a list of references asynchronous from the OPC server address space
    UaStatus beginDeleteReferences(
        ServiceSettings&               serviceSettings,
        const UaDeleteReferencesItems& referencesToDelete,
        OpcUa_UInt32                   transactionId);

    // Query OPC server address space
    UaStatus queryFirst(
        ServiceSettings&              serviceSettings,
        const OpcUa_ViewDescription&  view,
        const UaNodeTypeDescriptions& nodeTypes,
        const UaContentFilter&        filter,
        OpcUa_UInt32                  maxDataSetsToReturn,
        OpcUa_UInt32                  maxReferencesToReturn,
        UaByteString&                 continuationPoint,
        UaQueryDataSets&              queryDataSets,
        UaDiagnosticInfos&            diagnosticInfos,
        UaParsingResults&             parsingResults);

    // Continue a previous query request
    UaStatus queryNext(
        ServiceSettings&  serviceSettings,
        OpcUa_Boolean     releaseContinuationPoint,
        UaByteString&     continuationPoint,
        UaQueryDataSets&  queryDataSets);

    // Cancel outstanding service requests in the OPC UA server
    UaStatus cancel(
        ServiceSettings& serviceSettings,
        OpcUa_UInt32     requestHandle,
        OpcUa_UInt32&    cancelCount);

    // Indicates if the UaSession is connected. This flag does not reflect the actual server status.
    OpcUa_Boolean isConnected() const;

    // Provides the actual connection status to the UA server
    UaClient::ServerStatus serverStatus() const;

    // Provides the actual state of the UA server
    OpcUa_ServerState serverState() const;

    // Provides the currently used URL for the connection to the UA server
    UaString currentlyUsedEndpointUrl() const;

    // Provides the Id assigned from the server to this session. This Id uniquely identifies the session on the server.
    UaNodeId sessionId() const;

    // Provides the certificate of the UA server
    UaByteString serverCertificate() const;

    // Get a description for all arguments of a given Method
    UaStatus getMethodArguments(
        ServiceSettings& serviceSettings,
        const UaNodeId& methodId,
        UaArguments& inputArguments,
        UaArguments& outputArguments);

    OpcUa_UInt32 connectTimeout() const;
    void setConnectTimeout(OpcUa_UInt32 connectTimeout);

    OpcUa_UInt32 maxOperationsPerServiceCall() const;
    void setMaxOperationsPerServiceCall(OpcUa_UInt32 maxOperationsPerServiceCall);
    OpcUa_UInt32 maxNodesPerBrowse() const;
    OpcUa_UInt32 maxNodesPerHistoryReadData() const;
    OpcUa_UInt32 maxNodesPerHistoryReadEvents() const;
    OpcUa_UInt32 maxNodesPerHistoryUpdateData() const;
    OpcUa_UInt32 maxNodesPerHistoryUpdateEvents() const;
    OpcUa_UInt32 maxNodesPerMethodCall() const;
    OpcUa_UInt32 maxNodesPerNodeManagement() const;
    OpcUa_UInt32 maxNodesPerRead() const;
    OpcUa_UInt32 maxNodesPerRegisterNodes() const;
    OpcUa_UInt32 maxNodesPerTranslateBrowsePathsToNodeIds() const;
    OpcUa_UInt32 maxNodesPerWrite() const;

    OpcUa_UInt32 watchdogTime() const;
    void setWatchdogTime(OpcUa_UInt32 watchdogTime);
    OpcUa_UInt32 watchdogTimeout() const;
    void setWatchdogTimeout(OpcUa_UInt32 watchdogTimeout);

    OpcUa_UInt32 revisedSecureChannelLifetime() const;
    OpcUa_Double revisedSessionTimeout() const;

    UaStringArray getNamespaceTable() const;
    void updateNamespaceTable();

    // UaDataTypeDictionary interface
    virtual UaDataTypeDictionary::DefinitionType definitionType(const UaNodeId &dataTypeId);
    virtual UaEnumDefinition enumDefinition(const UaNodeId &dataTypeId);
    virtual UaStructureDefinition structureDefinition(const UaNodeId &dataTypeId);
    virtual UaOptionSetDefinition optionSetDefinition(const UaNodeId &dataTypeId);

    void loadDataTypeDictionaries();
    void clearDataTypeDictionaries();

    OpcUa_UInt32 maxArrayLength() const;
    OpcUa_UInt16 maxBrowseContinuationPoints() const;
    OpcUa_UInt32 maxByteStringLength() const;
    OpcUa_UInt16 maxHistoryContinuationPoints() const;
    OpcUa_UInt16 maxQueryContinuationPoints() const;
    OpcUa_UInt32 maxStringLength() const;
    OpcUa_Double minSupportedSampleRate() const;

    static char* getHostFromUrl(const OpcUa_String *pURL, bool expandIPv6);
    static OpcUa_Int32 getPortFromUrl(const OpcUa_String *pURL);

protected:
    // CertificateValidationCallback interface
    virtual bool verificationError(SessionSecurityInfo *pInfo,
                                   OpcUa_Void*          pvVerifyContext,
                                   const UaByteString  &certificateChain,
                                   OpcUa_StatusCode     uVerificationResult,
                                   OpcUa_UInt32         uDepth);

private:
    /** UaService data */
    UaSessionPrivate* d;
    bool m_isOwner;
};
/*! @} */
}

#endif // UACLIENTSDK_UASESSION_H

