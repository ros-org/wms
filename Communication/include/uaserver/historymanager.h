/******************************************************************************
** historymanager.h
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
** Description: OPC server core module HistoryManager interface.
**
******************************************************************************/
#ifndef HISTORYMANAGER_H
#define HISTORYMANAGER_H

#include "coremoduleincludes.h"
#include "variablehandle.h"
#include "uadatavalue.h"
#include "uahistoryeventfieldlist.h"

/** @ingroup ServerCoreInterfaces
 *  The corresponding callback interface for the HistoryManager.
 *  This callback interface provides all corresponding callback methods for the begin methods in the HistoryManager interface.<br>
*/
class SERVER_CORE_EXPORT HistoryManagerCallback
{
    UA_DISABLE_COPY(HistoryManagerCallback);
public:
    /** construction */
    HistoryManagerCallback(){};
    /** destruction */
    virtual ~HistoryManagerCallback(){};

    /** Callback function for a historical read of data.
     *  @param hTransaction Handle for the transaction used by the SDK to identify the transaction in the callbacks. This handle was passed in to the HistoryManager with the beginHistoryTransaction method.
     *  @param callbackHandle Handle for the node in the callback. This handle was passed in to the HistoryManager with either beginReadRawModified, beginReadProcessed or beginReadAtTime.
     *  @param result The result of the current Operation.
     *  @param pContinuationPoint The continuation point data if not all results can be returned in one Read call. Implementers of this interface can store the continuation point data in a derived class.
     *  @param dataValues The requested Values for this operation. The values array will be detached by the SDK.
     *  @param allowThreadUse Indicates if the calling thread can be used by the SDK to send the response to the client.
                              This can happen if this method is the called for the last node in the transaction.<br>
                              True: The thread calling this method can be used to send the response and may block<br>
                              False: The SDK is using a worker thread to send the response to the client.
     *  @return Error code
     */
    virtual UaStatus finishHistoryReadData(
        OpcUa_UInt32               hTransaction,
        OpcUa_UInt32               callbackHandle,
        const UaStatus&            result,
        HistoryReadCPUserDataBase* pContinuationPoint,
        UaDataValues&              dataValues,
        OpcUa_Boolean              allowThreadUse = OpcUa_False) = 0;

    /** Callback function for a historical read of modified data.
     *  @param hTransaction Handle for the transaction used by the SDK to identify the transaction in the callbacks. This handle was passed in to the HistoryManager with the beginHistoryTransaction method.
     *  @param callbackHandle Handle for the node in the callback. This handle was passed in to the HistoryManager with the beginReadRawModified method.
     *  @param result The result of the current Operation.
     *  @param pContinuationPoint The continuation point data if not all results can be returned in one Read call. Implementers of this interface can store the continuation point data in a derived class.
     *  @param dataValues The requested Values for this operation. The values array will be detached by the SDK.
     *  @param modificationInformations The modification information for the requested Values for this operation. The information array will be detached by the SDK.
     *  @param allowThreadUse Indicates if the calling thread can be used by the SDK to send the response to the client.
                              This can happen if this method is the called for the last node in the transaction.<br>
                              True: The thread calling this method can be used to send the response and may block<br>
                              False: The SDK is using a worker thread to send the response to the client.
     *  @return Error code
     */
    virtual UaStatus finishHistoryReadModifiedData(
        OpcUa_UInt32               hTransaction,
        OpcUa_UInt32               callbackHandle,
        const UaStatus&            result,
        HistoryReadCPUserDataBase* pContinuationPoint,
        UaDataValues&              dataValues,
        UaModificationInfo&        modificationInformations,
        OpcUa_Boolean              allowThreadUse = OpcUa_False) = 0;

    /** Finishes a historizing ReadEvent.
     *  @param hTransaction Handle for the transaction used by the SDK to identify the transaction in the callbacks. This handle was passed in to the HistoryManager with the beginHistoryTransaction method.
     *  @param callbackHandle Handle for the node in the callback. This handle was passed in to the HistoryManager with the beginReadEvents method.
     *  @param result the result of the current Operation.
     *  @param pContinuationPoint The continuation point data if not all results can be returned in one Read call. Implementers of this interface can store the continuation point data in a derived class.
     *  @param events a list of events that match the read filter. The event array will be detached by the SDK.
     *  @param allowThreadUse Indicates if the calling thread can be used by the SDK to send the response to the client.
                              This can happen if this method is the called for the last node in the transaction.<br>
                              True: The thread calling this method can be used to send the response and may block<br>
                              False: The SDK is using a worker thread to send the response to the client.
     *  @return Error code
     */
    virtual UaStatus finishHistoryReadEvent(
        OpcUa_UInt32               hTransaction,
        OpcUa_UInt32               callbackHandle,
        const UaStatus&            result,
        HistoryReadCPUserDataBase* pContinuationPoint,
        UaHistoryEventFieldLists&  events,
        OpcUa_Boolean              allowThreadUse = OpcUa_False) = 0;

    /** Finishes a historizing Update.
     *  @param hTransaction Handle for the transaction used by the SDK to identify the transaction in the callbacks. This handle was passed in to the HistoryManager with the beginHistoryTransaction method.
     *  @param callbackHandle Handle for the node in the callback. This handle was passed in to the HistoryManager with either beginUpdateData, beginUpdateEvents, beginDeleteRawModified, beginDeleteAtTime or beginDeleteEvents.
     *  @param result the result of the current Operation.
     *  @param operationResults   The results for the requested updates.
     *  @param operationDiagnosticInfos The diagnostic for the requested updates.
     *  @param allowThreadUse Indicates if the calling thread can be used by the SDK to send the response to the client.
                              This can happen if this method is the called for the last node in the transaction.<br>
                              True: The thread calling this method can be used to send the response and may block<br>
                              False: The SDK is using a worker thread to send the response to the client.
     *  @return Error code
     */
    virtual UaStatus finishHistoryUpdate(
        OpcUa_UInt32       hTransaction,
        OpcUa_UInt32       callbackHandle,
        const UaStatus&    result,
        UaStatusCodeArray& operationResults,
        UaDiagnosticInfos& operationDiagnosticInfos,
        OpcUa_Boolean      allowThreadUse = OpcUa_False) = 0;
};

/** @ingroup ServerCoreInterfaces
 Interface definition of the HistoryManager used for reading, updating and deletion of data and event history.
 The HistoryManager interface provides the reading, updating and deletion capabilities for data and event history. The HistoryManager
 interface is asynchronous. For the HistoryManager callback the HistoryManagerCallback interface is implemented by the consumer of the
 history data or events. One of the consumers is the UA Module. This interface is used by the SDK to multiplex the list of nodes in
 the UA service call to different HistoryManagers. One UA service call is a transaction for the SDK. If an HistoryManager is used in a
 transaction, the beginHistoryTransaction method is called by the SDK. This allows the HistoryManagers to create a context for the transactions
 since the SDK will call the associated begin method (e.g. beginReadRawModified) for each node in the transaction.
 Depending on the underlying system, the action can be started for each node in the begin method or for a list of nodes in the
 finishHistoryTransaction method. If the underlying system allows optimizing access for a list of nodes, the finishHistoryTransaction method
 should be used to start the access to the underlying system. This method is called by the SDK after calling the begin methods
 for all nodes in the transaction.<br>
 */
class SERVER_CORE_EXPORT HistoryManager
{
    UA_DISABLE_COPY(HistoryManager);
public:
    /** TransactionType enumeration */
    enum TransactionType
    {
        TransactionReadEvents,    /*!< Read event history transaction executed through HistoryManager::beginReadEvents*/
        TransactionReadRaw,       /*!< Read raw historical data transaction executed through HistoryManager::beginReadRawModified*/
        TransactionReadModified,  /*!< Read modified historical data  transaction executed through HistoryManager::beginReadRawModified*/
        TransactionReadProcessed, /*!< Read processed historical data transaction executed through HistoryManager::beginReadProcessed*/
        TransactionReadAtTime,    /*!< Read data at time history transaction executed through HistoryManager::beginReadAtTime*/
        TransactionUpdateData,    /*!< Update history data transaction executed through HistoryManager::beginUpdateData*/
        TransactionUpdateStructureData, /*!< Update history structure data like Anotations executed through HistoryManager::beginUpdateData*/
        TransactionUpdateEvents,  /*!< Update event history transaction executed through HistoryManager::beginUpdateEvents*/
        TransactionDeleteData,    /*!< Delete history data transaction executed through HistoryManager::beginDeleteRawModified*/
        TransactionDeleteAtTime,  /*!< Delete history data at time transaction executed through HistoryManager::beginDeleteAtTime*/
        TransactionDeleteEvents   /*!< Delete event history transaction executed through HistoryManager::beginDeleteEvents*/
    };

    /** construction */
    HistoryManager(){};
    /** destruction */
    virtual ~HistoryManager(){};

    /** Begins a transaction for historical access.
     *  @param pCallback              Callback interface used for the transaction. The HistoryManager must use this interface to finish the action for each passed
     *                                variable in the transaction. The callback interface pointer is valid until the transaction is completely finished.
     *  @param serviceContext         General context for the service calls containing information like the session object, return diagnostic mask and timeout hint.
     *  @param hTransaction           Handle for the transaction used by the SDK to identify the transaction in the callbacks.
     *                                The HistoryManager must store this handle and use it in callbacks to HistoryManagerCallback
     *  @param totalItemCountHint     A hint for the HistoryManager about the total number of variables in the transaction.
     *                                The HistoryManager may not be responsible for all variables but he can use this hint if he wants to optimize memory allocation for further processing.
     *  @param transactionType        Type of the history transaction.
     *  @param timestampsToReturn     The client selected timestamp to return. Valid enum values are: OpcUa_TimestampsToReturn_Source, OpcUa_TimestampsToReturn_Server, OpcUa_TimestampsToReturn_Both
     *  @param hHistoryManagerContext Handle provided by the HistoryManager to identify the transaction in the following begin calls.
     *                                The handle is managed by the HistoryManager and must be valid until the transaction is completely finished.
     *  @return Result code of the method call
     */
    virtual UaStatus beginHistoryTransaction (
        HistoryManagerCallback*  pCallback,
        const ServiceContext&    serviceContext,
        OpcUa_UInt32             hTransaction,
        OpcUa_UInt32             totalItemCountHint,
        TransactionType          transactionType,
        OpcUa_TimestampsToReturn timestampsToReturn,
        OpcUa_Handle&            hHistoryManagerContext) = 0;

    /** Read event history for a node.
     *  @param hHistoryManagerContext Handle provided by the HistoryManager in beginHistoryTransaction used to identify the transaction context for this call.
     *  @param callbackHandle         Handle for the variable in the callback.
     *  @param pVariableHandle        Variable handle provided by the NodeManager::getHistoryVariableHandle.
     *        This object contains the information needed by the HistoryManager to identify the variable to read in its context.
     *        The object is reference counted. The reference used by the SDK is released after finishHistoryTransaction is called. If the HistoryManager needs the
     *        VariableHandle of asynchronous handling, the HistoryManager must add its own reference as long as the VariableHandle is used.
     *  @param pContinuationPoint     The continuation point data from a previous Read call. Null if first Read.
     *        Implementers of this interface can store the continuation point data in a derived class.
     *        Implementers of the HistoryManager interface are responsible for deleting the HistoryReadCPUserDataBase object if it is not NULL.
     *  @param numValuesPerNode       The maximum number of values per Node to return.
     *  @param startTime              The start time of the time period to read.
     *  @param endTime                The end time of the time period to read.
     *  @param filter                 An event filter used to select events to read.
     *  @param pReadValueId           Context for the node to read. The context contains the IndexRange and the DataEncoding requested by the client.
     *                                The other parameters of this context are already handled by the HistoryVariableHandle and the SDK.
     *  @return Result code of the method call
     */
    virtual UaStatus beginReadEvents (
        OpcUa_Handle               hHistoryManagerContext,
        OpcUa_UInt32               callbackHandle,
        HistoryVariableHandle*     pVariableHandle,
        HistoryReadCPUserDataBase* pContinuationPoint,
        OpcUa_UInt32               numValuesPerNode,
        OpcUa_DateTime&            startTime,
        OpcUa_DateTime&            endTime,
        const OpcUa_EventFilter&   filter,
        OpcUa_HistoryReadValueId*  pReadValueId) = 0;

    /** Read raw or modified history values for a node.
     *  @param hHistoryManagerContext Handle provided by the HistoryManager in beginHistoryTransaction used to identify the transaction context for this call.
     *  @param callbackHandle         Handle for the variable in the callback.
     *  @param pVariableHandle        Variable handle provided by the NodeManager::getHistoryVariableHandle.
     *        This object contains the information needed by the HistoryManager to identify the variable to read in its context.
     *        The object is reference counted. The reference used by the SDK is released after finishHistoryTransaction is called. If the HistoryManager needs the
     *        VariableHandle of asynchronous handling, the HistoryManager must add its own reference as long as the VariableHandle is used.
     *  @param pContinuationPoint     The continuation point data from a previous Read call. Null if first Read.
     *        Implementers of this interface can store the continuation point data in a derived class.
     *        Implementers of the HistoryManager interface are responsible for deleting the HistoryReadCPUserDataBase object if it is not NULL.
     *  @param IsReadModified         true if modified data should be read - false if raw data should be read.
     *  @param numValuesPerNode       The maximum number of values per Node to return.
     *  @param startTime              The start time of the time period to read.
     *  @param endTime                The end time of the time period to read.
     *  @param returnBounds           Flag that indicates if bounding values should be returned.
     *  @param pReadValueId           Context for the node to read. The context contains the IndexRange and the DataEncoding requested by the client.
     *                                The other parameters of this context are already handled by the HistoryVariableHandle and the SDK.
     *  @return Result code of the method call
     */
    virtual UaStatus beginReadRawModified (
        OpcUa_Handle               hHistoryManagerContext,
        OpcUa_UInt32               callbackHandle,
        HistoryVariableHandle*     pVariableHandle,
        HistoryReadCPUserDataBase* pContinuationPoint,
        OpcUa_Boolean              IsReadModified,
        OpcUa_UInt32               numValuesPerNode,
        OpcUa_DateTime&            startTime,
        OpcUa_DateTime&            endTime,
        OpcUa_Boolean              returnBounds,
        OpcUa_HistoryReadValueId*  pReadValueId) = 0;

    /** Read processed history values for a node.
     *  @param hHistoryManagerContext Handle provided by the HistoryManager in beginHistoryTransaction used to identify the transaction context for this call.
     *  @param callbackHandle         Handle for the variable in the callback.
     *  @param pVariableHandle        Variable handle provided by the NodeManager::getHistoryVariableHandle.
     *        This object contains the information needed by the HistoryManager to identify the variable to read in its context.
     *        The object is reference counted. The reference used by the SDK is released after finishHistoryTransaction is called. If the HistoryManager needs the
     *        VariableHandle of asynchronous handling, the HistoryManager must add its own reference as long as the VariableHandle is used.
     *  @param pContinuationPoint     The continuation point data from a previous Read call. Null if first Read.
     *        Implementers of this interface can store the continuation point data in a derived class.
     *        Implementers of the HistoryManager interface are responsible for deleting the HistoryReadCPUserDataBase object if it is not NULL.
     *  @param startTime              The start time of the time period to read.
     *  @param endTime                The end time of the time period to read.
     *  @param processingInterval     The interval to re sample.
     *  @param aggregateType          The aggregate type node id.
     *  @param aggregateConfiguration The aggregate configuration.
     *  @param pReadValueId           Context for the node to read. The context contains the IndexRange and the DataEncoding requested by the client.
     *                                The other parameters of this context are already handled by the HistoryVariableHandle and the SDK.
     *  @return Result code of the method call
     */
    virtual UaStatus beginReadProcessed (
        OpcUa_Handle                 hHistoryManagerContext,
        OpcUa_UInt32                 callbackHandle,
        HistoryVariableHandle*       pVariableHandle,
        HistoryReadCPUserDataBase*   pContinuationPoint,
        OpcUa_DateTime&              startTime,
        OpcUa_DateTime&              endTime,
        OpcUa_Double                 processingInterval,
        const OpcUa_NodeId&          aggregateType,
        OpcUa_AggregateConfiguration aggregateConfiguration,
        OpcUa_HistoryReadValueId*    pReadValueId) = 0;

    /** Read history values for a node at specific timestamps.
     *  @param hHistoryManagerContext Handle provided by the HistoryManager in beginHistoryTransaction used to identify the transaction context for this call.
     *  @param callbackHandle         Handle for the variable in the callback.
     *  @param pVariableHandle        Variable handle provided by the NodeManager::getHistoryVariableHandle.
     *        This object contains the information needed by the HistoryManager to identify the variable to read in its context.
     *        The object is reference counted. The reference used by the SDK is released after finishHistoryTransaction is called. If the HistoryManager needs the
     *        VariableHandle of asynchronous handling, the HistoryManager must add its own reference as long as the VariableHandle is used.
     *  @param pContinuationPoint     The continuation point data from a previous Read call. Null if first Read.
     *        Implementers of this interface can store the continuation point data in a derived class.
     *        Implementers of the HistoryManager interface are responsible for deleting the HistoryReadCPUserDataBase object if it is not NULL.
     *  @param requestedTimes         The requested timestamps to read.
     *  @param useSimpleBounds        Use SimpleBounds to determine the value at the specific timestamp.
     *  @param pReadValueId           Context for the node to read. The context contains the IndexRange and the DataEncoding requested by the client.
     *                                The other parameters of this context are already handled by the HistoryVariableHandle and the SDK.
     *  @return Result code of the method call
     */
    virtual UaStatus beginReadAtTime (
        OpcUa_Handle               hHistoryManagerContext,
        OpcUa_UInt32               callbackHandle,
        HistoryVariableHandle*     pVariableHandle,
        HistoryReadCPUserDataBase* pContinuationPoint,
        const UaDateTimeArray&     requestedTimes,
        OpcUa_Boolean              useSimpleBounds,
        OpcUa_HistoryReadValueId*  pReadValueId) = 0;

    /** Update history values for a node.
     *  @param hHistoryManagerContext Handle provided by the HistoryManager in beginHistoryTransaction used to identify the transaction context for this call.
     *  @param callbackHandle         Handle for the variable in the callback.
     *  @param pVariableHandle        Variable handle provided by the NodeManager::getHistoryVariableHandle.
     *        This object contains the information needed by the HistoryManager to identify the variable to update in its context.
     *        The object is reference counted. The reference used by the SDK is released after finishHistoryTransaction is called. If the HistoryManager needs the
     *        VariableHandle of asynchronous handling, the HistoryManager must add its own reference as long as the VariableHandle is used.
     *  @param performInsertReplace   The mode to insert data or to replace data.
     *  @param isStructureUpdate      Flag indicating if the provided data is meta data like anotations describing an entry in the history database
     *  @param updateValue            The data values to update.
     *  @return Result code of the method call
     */
    virtual UaStatus beginUpdateData (
        OpcUa_Handle            hHistoryManagerContext,
        OpcUa_UInt32            callbackHandle,
        HistoryVariableHandle*  pVariableHandle,
        OpcUa_PerformUpdateType performInsertReplace,
        OpcUa_Boolean           isStructureUpdate,
        const UaDataValues&     updateValue) = 0;

    /** Update history event for a node.
     *  @param hHistoryManagerContext Handle provided by the HistoryManager in beginHistoryTransaction used to identify the transaction context for this call.
     *  @param callbackHandle         Handle for the variable in the callback.
     *  @param pVariableHandle        Variable handle provided by the NodeManager::getHistoryVariableHandle.
     *        This object contains the information needed by the HistoryManager to identify the variable to update in its context.
     *        The object is reference counted. The reference used by the SDK is released after finishHistoryTransaction is called. If the HistoryManager needs the
     *        VariableHandle of asynchronous handling, the HistoryManager must add its own reference as long as the VariableHandle is used.
     *  @param performInsertReplace   The mode to insert events or to replace events.
     *  @param filter                 An event filter used to select the event to update.
     *  @param eventData              A list of event data to update.
     *  @return Result code of the method call
     */
    virtual UaStatus beginUpdateEvents (
        OpcUa_Handle                    hHistoryManagerContext,
        OpcUa_UInt32                    callbackHandle,
        HistoryVariableHandle*          pVariableHandle,
        OpcUa_PerformUpdateType         performInsertReplace,
        const OpcUa_EventFilter&        filter,
        const UaHistoryEventFieldLists& eventData) = 0;

    /** Delete raw or modified history values for a node.
     *  @param hHistoryManagerContext Handle provided by the HistoryManager in beginHistoryTransaction used to identify the transaction context for this call.
     *  @param callbackHandle         Handle for the variable in the callback.
     *  @param pVariableHandle        Variable handle provided by the NodeManager::getHistoryVariableHandle.
     *        This object contains the information needed by the HistoryManager to identify the variable to delete in its context.
     *        The object is reference counted. The reference used by the SDK is released after finishHistoryTransaction is called. If the HistoryManager needs the
     *        VariableHandle of asynchronous handling, the HistoryManager must add its own reference as long as the VariableHandle is used.
     *  @param isDeleteModified       A flag that indicates if modified values should be deleted instead of raw value.
     *  @param startTime              The start time of the time period to delete.
     *  @param endTime                The end time of the time period to delete.
     *  @return Result code of the method call
     */
    virtual UaStatus beginDeleteRawModified (
        OpcUa_Handle             hHistoryManagerContext,
        OpcUa_UInt32             callbackHandle,
        HistoryVariableHandle*   pVariableHandle,
        OpcUa_Boolean            isDeleteModified,
        OpcUa_DateTime&          startTime,
        OpcUa_DateTime&          endTime) = 0;

    /** Delete history values at given times.
     *  @param hHistoryManagerContext Handle provided by the HistoryManager in beginHistoryTransaction used to identify the transaction context for this call.
     *  @param callbackHandle         Handle for the variable in the callback.
     *  @param pVariableHandle        Variable handle provided by the NodeManager::getHistoryVariableHandle.
     *        This object contains the information needed by the HistoryManager to identify the variable to delete in its context.
     *        The object is reference counted. The reference used by the SDK is released after finishHistoryTransaction is called. If the HistoryManager needs the
     *        VariableHandle of asynchronous handling, the HistoryManager must add its own reference as long as the VariableHandle is used.
     *  @param requestedTimes         The list of timestamps to delete.
     *  @return Result code of the method call
     */
    virtual UaStatus beginDeleteAtTime (
        OpcUa_Handle             hHistoryManagerContext,
        OpcUa_UInt32             callbackHandle,
        HistoryVariableHandle*   pVariableHandle,
        const UaDateTimeArray&   requestedTimes) = 0;

    /** Delete events for a node.
     *  @param hHistoryManagerContext Handle provided by the HistoryManager in beginHistoryTransaction used to identify the transaction context for this call.
     *  @param callbackHandle         Handle for the variable in the callback.
     *  @param pVariableHandle Variable handle provided by the NodeManager::getVariableHandle.
     *        This object contains the information needed by the HistoryManager to identify the node to read in its context.
     *        The object is reference counted. The reference used by the SDK is released after finishHistoryTransaction is called. If the HistoryManager needs the
     *        VariableHandle of asynchronous handling, the HistoryManager must add its own reference as long as the VariableHandle is used.
     *  @param eventIds The list of EventIds for the events to delete.
     *  @return Result code of the method call
     */
    virtual UaStatus beginDeleteEvents (
        OpcUa_Handle             hHistoryManagerContext,
        OpcUa_UInt32             callbackHandle,
        HistoryVariableHandle*   pVariableHandle,
        const UaByteStringArray& eventIds) = 0;

    /** Finishes the transaction for historical access.
     *  @param hHistoryManagerContext Handle provided by the HistoryManager in beginHistoryTransaction used to identify the transaction context for this call.
     *  @return Result code of the method call
     */
    virtual UaStatus finishHistoryTransaction (
        OpcUa_Handle           hHistoryManagerContext) = 0;

    /** Canceles the transaction for historical access.
     *  @param hHistoryManagerContext Handle provided by the HistoryManager in beginHistoryTransaction used to identify the transaction context for this call.
     *  @return Result code of the method call
     */
    virtual UaStatus cancelHistoryTransaction (
        OpcUa_Handle           hHistoryManagerContext);
};

 /** HistoryTransactionContext
  *  @brief Interface definition of the HistoryTransactionContext.
  *  This class provides the Session needed for transactions.
  */
class SERVER_CORE_EXPORT HistoryTransactionContext
{
    UA_DISABLE_COPY(HistoryTransactionContext);
public:
    /** construction with Variable initialization */
    HistoryTransactionContext()
    {
        m_pCallback          = NULL;
        m_hTransaction       = 0;
        m_timestampsToReturn = OpcUa_TimestampsToReturn_Both;
    };
    /** destruction */
    virtual ~HistoryTransactionContext()
    {
    };

    /// @brief Interface pointer for the HistoryManager callback interface.
    HistoryManagerCallback*  m_pCallback;
    /// @brief Transaction handle for the history transaction.
    OpcUa_UInt32             m_hTransaction;
    /// @brief Service context for the history transaction.
    ServiceContext           m_serviceContext;
    /// @brief The client selected timestamp to return.
    OpcUa_TimestampsToReturn m_timestampsToReturn;
};

#endif // HISTORYMANAGER_H
