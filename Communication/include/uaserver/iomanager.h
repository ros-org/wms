/******************************************************************************
** iomanager.h
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
** Description: OPC server core module IOManager interface.
**
******************************************************************************/
#ifndef IOMANAGER_H
#define IOMANAGER_H

#include "coremoduleincludes.h"
#include "variablehandle.h"
#include "uadatavalue.h"

/** @ingroup ServerCoreInterfaces
*  The callback interface for data monitored items.
*/
class SERVER_CORE_EXPORT IOVariableCallback
{
public:
    /** Construction */
    IOVariableCallback(){};

    /** Destruction */
    virtual ~IOVariableCallback(){};

    /** Send changed data.
     *  @param dataValue Contains the value, timestamps and result code for the changed data
     */
    virtual void dataChange(const UaDataValue& dataValue) = 0;

    /** Get last value send with dataChange.
     */
    virtual UaDataValue getLastValue() = 0;

    /** Get the number of free slots in the queue
     * If no queue is provided, the return value is -1
     */
    virtual OpcUa_Int32 getRemainingQueueSize(){return -1;}
};


/** @ingroup ServerCoreHelper
*  This class provides the settings for a data monitored item.
*/
class SERVER_CORE_EXPORT MonitoringContext
{
    MonitoringContext(const MonitoringContext&);
public:
    /** Construction with initialized Parameters */
    MonitoringContext()
    {
        samplingInterval              = 0;
        deadband                      = 0;
        isAbsoluteDeadband            = OpcUa_False;
        sdkMustHandleAbsoluteDeadband = OpcUa_False;
        dataChangeTrigger             = OpcUa_DataChangeTrigger_StatusValue;
        pIndexRange                   = NULL;
        pDataEncoding                 = NULL;
        queueSize                     = 1;
    }
    /** Destruction */
    virtual ~MonitoringContext() {}

    MonitoringContext& operator=(const MonitoringContext &other)
    {
        samplingInterval              = other.samplingInterval;
        deadband                      = other.deadband;
        isAbsoluteDeadband            = other.isAbsoluteDeadband;
        sdkMustHandleAbsoluteDeadband = other.sdkMustHandleAbsoluteDeadband;
        dataChangeTrigger             = other.dataChangeTrigger;
        pIndexRange                   = other.pIndexRange;
        pDataEncoding                 = other.pDataEncoding;
        queueSize                     = other.queueSize;
        return *this;
    }

    /** @brief Sampling interval for the monitored item to create. */
    OpcUa_Double            samplingInterval;
    /** @brief Dead band value for the monitored item to create.  */
    OpcUa_Double            deadband;
    /** @brief Indicates if it is an absolute deadband or a percent deadband if a deadband value is set.  */
    OpcUa_Boolean           isAbsoluteDeadband;
    /** @brief Set by the implementation of the IOManager if a configured absolute deadband should be handles by the SDK. */
    OpcUa_Boolean           sdkMustHandleAbsoluteDeadband;

    /** @brief Type of data change trigger for the monitored item to create.<br>
     *  Possible values are OpcUa_DataChangeTrigger_Status, OpcUa_DataChangeTrigger_StatusValue (default),
     *  OpcUa_DataChangeTrigger_StatusValueTimestamp.
     */
    OpcUa_DataChangeTrigger dataChangeTrigger;
    /** @brief Index range for the monitored item to create. This parameter is NULL if no index range is specified.*/
    OpcUa_String*           pIndexRange;
    /** @brief Data encoding for the monitored item to create. This parameter is only relevant if the data type or the variable to monitore is complex.  */
    OpcUa_QualifiedName*    pDataEncoding;

    /** @brief QueueSize for the monitored item to create. This is a hint for the IOManager implementation. The queue is managed in the MonitoredItem */
    OpcUa_UInt32            queueSize;
};

/** @ingroup ServerCoreInterfaces
 *  The corresponding callback interface for the IOManager.
 *  This callback interface provides all corresponding callback methods for the begin methods in the IOManager interface.
 */
class SERVER_CORE_EXPORT IOManagerCallback
{
    UA_DISABLE_COPY(IOManagerCallback);
public:

    /** Construction */
    IOManagerCallback(){};

    /** Destruction */
    virtual ~IOManagerCallback(){};

    /** Finished reading of an attribute value of a node.
     *  The method is called to finish a read call for an attribute value of a node. The read is started with the beginRead method of the interface IOManager.
     *  @param hTransaction Handle for the transaction used by the SDK to identify the transaction in the callbacks. This handle was passed in to the IOManager with the beginTransaction method.
     *  @param callbackHandle Handle for the node in the callback. This handle was passed in to the IOManager with the beginRead method.
     *  @param dataValue Contains the value, timestamps and result code for the Read operation.
     *  @param detachValue Indicates if the method can detach the value from the wrapper class.
     *  @param allowThreadUse Indicates if the calling thread can be used by the SDK to send the response to the client.
                              This can happen if this method is the called for the last node in the transaction.<br>
                              True: The thread calling this method can be used to send the response and may block<br>
                              False: The SDK is using a worker thread to send the response to the client.
     *  @param pDiagnosticInfo Optional diagnostig information requested by the client in the parameter ServiceContext::returnDiagnostics of IOManager::beginTransaction
     *  @return Error code
     */
    virtual UaStatus finishRead(
        OpcUa_UInt32      hTransaction,
        OpcUa_UInt32      callbackHandle,
        UaDataValue&      dataValue,
        OpcUa_Boolean     detachValue = OpcUa_False,
        OpcUa_Boolean     allowThreadUse = OpcUa_False,
        UaDiagnosticInfo* pDiagnosticInfo = NULL) = 0;

    /** Finished writing of an attribute value of a node.
     *  The method is called to finish a write call for an attribute value of a node. The write is started with the beginWrite method of the interface IOManager.
     *  @param hTransaction Handle for the transaction used by the SDK to identify the transaction in the callbacks. This handle was passed in to the IOManager with the beginTransaction method.
     *  @param callbackHandle Handle for the node in the callback. This handle was passed in to the IOManager with the beginWrite method.
     *  @param statusCode Result of the Write operation.
                          Optional diagnostig information requested by the client in the parameter ServiceContext::returnDiagnostics of IOManager::beginTransaction
                          can be provided through UaStatus::setDiagnosticInfo().
     *  @param allowThreadUse Indicates if the calling thread can be used by the SDK to send the response to the client.
                              This can happen if this method is the called for the last node in the transaction.<br>
                              True: The thread calling this method can be used to send the response and may block<br>
                              False: The SDK is using a worker thread to send the response to the client.
     *  @return Error code
     */
    virtual UaStatus finishWrite(
        OpcUa_UInt32    hTransaction,
        OpcUa_UInt32    callbackHandle,
        const UaStatus& statusCode,
        OpcUa_Boolean   allowThreadUse = OpcUa_False) = 0;

    /** Finished start monitoring of an attribute value of a node.
     *  The method is called to finish the starting of the sampling for a monitored item. The sampling is started with the beginStartMonitoring method of the interface IOManager.
     *  @param hTransaction Handle for the transaction used by the SDK to identify the transaction in the callbacks. This handle was passed in to the IOManager with the beginTransaction method.
     *  @param callbackHandle Handle for the node in the callback. This handle was passed in to the IOManager with the beginStartMonitoring method.
     *  @param hIOVariable The handle of the item in the IOManager created with beginStartMonitoring. The handle is used by the SDK in beginModifyMonitoring and beginStopMonitoring to adress the item in the IOManager.
     *  @param revisedSamplingInterval The corresponding revised sampling interval for the requested sampling interval in beginStartMonitoring.
     *  @param initialDataValueAvailable Indicates if the initial value parameter is valid.
     *  @param initialDataValue Contains the value, timestamps and result code for the initial value.
     *  @param statusCode Result of the StartMonitoring operation.
                          Optional diagnostig information requested by the client in the parameter ServiceContext::returnDiagnostics of IOManager::beginTransaction
                          can be provided through UaStatus::setDiagnosticInfo().
     *  @return Error code
     */
    virtual UaStatus finishStartMonitoring(
        OpcUa_UInt32       hTransaction,
        OpcUa_UInt32       callbackHandle,
        OpcUa_UInt32       hIOVariable,
        OpcUa_Double       revisedSamplingInterval,
        OpcUa_Boolean      initialDataValueAvailable,
        const UaDataValue& initialDataValue,
        const UaStatus&    statusCode) = 0;

    /** Finished modify monitoring of an attribute value of a node.
     *  The method is called to finish the modifying of the sampling attributes for a monitored item. The modifying is started with the beginModifyMonitoring method of the interface IOManager.
     *  @param hTransaction Handle for the transaction used by the SDK to identify the transaction in the callbacks. This handle was passed in to the IOManager with the beginTransaction method.
     *  @param callbackHandle Handle for the node in the callback. This handle was passed in to the IOManager with the beginModifyMonitoring method.
     *  @param revisedSamplingInterval The corresponding revised sampling interval for the requested sampling interval in beginModifyMonitoring.
     *  @param statusCode Result of the ModifyMonitoring operation.
                          Optional diagnostig information requested by the client in the parameter ServiceContext::returnDiagnostics of IOManager::beginTransaction
                          can be provided through UaStatus::setDiagnosticInfo().
     *  @return Error code
     */
    virtual UaStatus finishModifyMonitoring(
        OpcUa_UInt32       hTransaction,
        OpcUa_UInt32       callbackHandle,
        OpcUa_Double       revisedSamplingInterval,
        const UaStatus&    statusCode) = 0;

    /** Finished stop monitoring of an attribute value of a node.
     *  The method is called to finish the stopping of the sampling for a monitored item. The stopping is started with the beginStopMonitoring method of the interface IOManager.
     *  @param hTransaction Handle for the transaction used by the SDK to identify the transaction in the callbacks. This handle was passed in to the IOManager with the beginTransaction method.
     *  @param callbackHandle Handle for the node in the callback. This handle was passed in to the IOManager with the beginStopMonitoring method.
     *  @param statusCode Result of the StopMonitoring operation.
                          Optional diagnostig information requested by the client in the parameter ServiceContext::returnDiagnostics of IOManager::beginTransaction
                          can be provided through UaStatus::setDiagnosticInfo().
     *  @return Error code
     */
    virtual UaStatus finishStopMonitoring(
        OpcUa_UInt32       hTransaction,
        OpcUa_UInt32       callbackHandle,
        const UaStatus&    statusCode) = 0;
};

/** @ingroup ServerCoreInterfaces
 * Interface definition of the IOManager used for reading, writing and monitoring data.
 *
 * The IOManager interface provides the reading, writing and monitoring capabilities for node attributes. The IOManager
 * interface is asynchronous. For the IOManager callback the IOManagerCallback interface is implemented by the consumer of the
 * attribute data. One of the consumers is the UA Module. This interface is used by the SDK to multiplex the list of nodes in
 * the UA service call to different IOManagers. One UA service call is a transaction for the SDK. If an IOManager is used in a
 * transaction, the beginTransaction method is called by the SDK. This allows the IOManager to create a context for the transactions
 * since the SDK will call the associated begin method (e.g. beginRead for the UA Read service) for each node in the transaction.
 *
 * Depending on the underlying system, the action can be started for each node in the begin method or for a list of nodes in the
 * finishTransaction method. If the underlying system allows optimizing access for a list of nodes, the finishTransaction method
 * should be used to start the access to the underlying system. This method is called by the SDK after calling the begin methods
 * for all nodes in the transaction.
 */
class SERVER_CORE_EXPORT IOManager
{
    UA_DISABLE_COPY(IOManager);
public:
    /** TransactionType enumeration  */
    enum TransactionType
    {
        TransactionRead,           /*!< Read a list of node attributes */
        TransactionWrite,          /*!< Write a list of node attributes */
        TransactionMonitorBegin,   /*!< Begin monitoring for a list of data items */
        TransactionMonitorModify,  /*!< Modify monitoring for a list of data items */
        TransactionMonitorStop,    /*!< Stop monitoring for a list of data items */
        TransactionInvalid         /*!< Invalid transaction */
    };

    /** Construction */
    IOManager(){};

    /** Destruction */
    virtual ~IOManager(){};

    /** Begin a IOManager transaction.
     *  Is called by the SDK before the first begin method call for a transaction. This method must create a context in the IOManager for the transaction.
     *  @param pCallback Callback interface used for the transaction. The IOManager must use this interface to finish the action for each passed
     *                   node in the transaction. The callback interface pointer is valid until the transaction is completely finished.
     *  @param serviceContext Service context including the session context used for the UA service call.
     *  @param hTransaction Handle for the transaction used by the SDK to identify the transaction in the callbacks.
     *  @param totalItemCountHint A hint for the IOManager about the total number of nodes in the transaction. The IOManager may not be responsible for all nodes but he can use this hint if he wants to optimize memory allocation.
     *  @param maxAge Max age parameter used only in the Read service.
     *  @param timestampsToReturn Indicates which timestamps should be returned in a Read or a Publish response.
     *  The possible enum values are:
     *      OpcUa_TimestampsToReturn_Source
     *      OpcUa_TimestampsToReturn_Server
     *      OpcUa_TimestampsToReturn_Both
     *      OpcUa_TimestampsToReturn_Neither
     *  @param transactionType Type of the transaction. The possible enum values are:
     *      - READ
     *      - WRITE
     *      - MONITOR_BEGIN
     *      - MONITOR_MODIFY
     *      - MONITOR_STOP
     *  @param hIOManagerContext Handle to the context in the IOManager for the transaction. The handle is managed by the IOManager and must be valid until
     *                           the transaction is completely finished.
     *  This handle is passed into the IOManager begin methods to identify the transaction context in the IOManager.
     *  @return Error code
     */
    virtual UaStatus beginTransaction (
        IOManagerCallback*       pCallback,
        const ServiceContext&    serviceContext,
        OpcUa_UInt32             hTransaction,
        OpcUa_UInt32             totalItemCountHint,
        OpcUa_Double             maxAge,
        OpcUa_TimestampsToReturn timestampsToReturn,
        TransactionType          transactionType,
        OpcUa_Handle&            hIOManagerContext) = 0;

    /** Begin start monitoring of an item.
     *  Is called by the SDK for each node in a UA CreateMonitoredItems service call if sampling is enabled or for service calls enabling the sampling for a monitored item.
     *  It is expected that this method does not block for external communication with the underlying system. See also beginRead description for more details.
     *  The corresponding callback method is the finishStartMonitoring method.
     *  @param hIOManagerContext IOManager handle for the transaction context. This handle is used to identify the transaction in the IOManager.
     *  @param callbackHandle Handle for the node in the callback.
     *  @param pIOVariableCallback Callback interface used for data change callbacks to the MonitoredItem managed by the SDK.
     *                             The callback interface is valid until the monitoring is stopped through beginStopMonitoring.
     *  @param pVariableHandle Variable handle provided by the NodeManager::getVariableHandle.
     *        This object contains the information needed by the IOManager to identify the node to monitor in its context.
     *        The object is reference counted. The reference used by the SDK is released after finishTransaction is called. If the IOManager needs the
     *        VariableHandle of asynchronous handling, the IOManager must add its own reference as long as the VariableHandle is used.
     *  @param monitoringContext Object containing the requested settings for the monitored item like sampling interval or deadband.
     *                           The object is only valid during this method is called
     *  @return Error code
     */
    virtual UaStatus beginStartMonitoring(
        OpcUa_Handle        hIOManagerContext,
        OpcUa_UInt32        callbackHandle,
        IOVariableCallback* pIOVariableCallback,
        VariableHandle*     pVariableHandle,
        MonitoringContext&  monitoringContext) = 0;

    /** Begin modify monitoring of an item.
     *  Is called by the SDK for each node in a UA ModifyMonitoredItems service call.
     *  It is expected that this method does not block for external communication with the underlying system. See also beginRead description for more details.
     *  The corresponding callback method is the finishModifyMonitoring method.
     *  @param hIOManagerContext IOManager handle for the transaction context. This handle is used to identify the transaction in the IOManager.
     *  @param callbackHandle Handle for the node in the callback.
     *  @param hIOVariable The handle of the variable in the IOManager created with beginStartMonitoring.
     *      The handle was passed to the SDK in the callback finishStartMonitoring.
     *  @param monitoringContext Object containing the requested settings for the monitored item like sampling interval or deadband.
     *                           The object is only valid during this method is called
     *  @return Error code
     */
    virtual UaStatus beginModifyMonitoring(
        OpcUa_Handle        hIOManagerContext,
        OpcUa_UInt32        callbackHandle,
        OpcUa_UInt32        hIOVariable,
        MonitoringContext&  monitoringContext) = 0;

    /** Begin stop monitoring of an item.
     *  Is called by the SDK for each node in a UA DeleteMonitoredItems service call if sampling is enabled for the monitored item to delete or for service calls disabling the sampling for a monitored item.
     *  It is expected that this method does not block for external communication with the underlying system. See also beginRead description for more details.
     *  The corresponding callback method is the finishStopMonitoring method.
     *  @param hIOManagerContext IOManager handle for the transaction context. This handle is used to identify the transaction in the IOManager.
     *  @param callbackHandle Handle for the node in the callback.
     *  @param hIOVariable The handle of the variable in the IOManager created with beginStartMonitoring.
     *      The handle was passed to the SDK in the callback finishStartMonitoring.
     *  @return Error code
     */
    virtual UaStatus beginStopMonitoring(
        OpcUa_Handle        hIOManagerContext,
        OpcUa_UInt32        callbackHandle,
        OpcUa_UInt32        hIOVariable) = 0;

    /** Begin reading an attribute value of a node.
     *  Is called by the SDK for each node in a UA Read service call. It is expected that this method does not block for external communication with the underlying system.
     *  If the read can be done inside the local process memory, the read can be executed and the finishRead method can be called inside this method call.
     *  If the underlying system is able to queue the read for the node without blocking for external communication, the beginRead can queue the node in the underlying system.
     *  If the communication with the underlying system can block, the node must be stored in the context of the transaction and the communication with the underlying system must be started asynchronous in the finishTransaction method.
     *  The corresponding callback method is the finishRead method. The in parameters are valid until the last finishRead method is called for the transaction.
     *  @param hIOManagerContext IOManager handle for the transaction context. This handle is used to identify the transaction in the IOManager.
     *  @param callbackHandle Handle for the node in the callback.
     *  @param pVariableHandle Variable handle provided by the NodeManager::getVariableHandle.
     *        This object contains the information needed by the IOManager to identify the node to read in its context.
     *        The object is reference counted. The reference used by the SDK is released after finishTransaction is called. If the IOManager needs the
     *        VariableHandle of asynchronous handling, the IOManager must add its own reference as long as the VariableHandle is used.
     *  @param pReadValueId Context for the node to read. The context contains the IndexRange and the DataEncoding requested by the client.
     *                      The other parameters of this context are already handled by the VariableHandle.
     *                      The read context pointer is valid until the transaction is completely finished.
     *  @return Error code
     */
    virtual UaStatus beginRead (
        OpcUa_Handle        hIOManagerContext,
        OpcUa_UInt32        callbackHandle,
        VariableHandle*     pVariableHandle,
        OpcUa_ReadValueId*  pReadValueId) = 0;

    /** Begin writing an attribute value for a node.
     *  Is called by the SDK for each node in a UA Write service call.
     *  It is expected that this method does not block for external communication with the underlying system. See also beginRead description for more details.
     *  The corresponding callback method is the finishWrite method.
     *
     *  OPC UA is not providing data type conversions on the server side. The client is responsible for converting the variable data type to the data type he
     *  needs for internally. The server must return OpcUa_BadTypeMismatch if the client is not writing the variable data type or a subtype of it. The only
     *  exception is an array of Byte. In this case the client is allowed to write a ByteString instead since environments like JAVA and .NET can not
     *  preserve the distinction between a ByteString and a one dimensional array of Byte.
     *  @param hIOManagerContext IOManager handle for the transaction context. This handle is used to identify the transaction in the IOManager.
     *  @param callbackHandle Handle for the node in the callback. The in parameters are valid until the last finishRead method is called for the transaction.
     *  @param pVariableHandle Variable handle provided by the NodeManager::getVariableHandle.
     *        This object contains the information needed by the IOManager to identify the node to write in its context.
     *        The object is reference counted. The reference used by the SDK is released after finishTransaction is called. If the IOManager needs the
     *        VariableHandle of asynchronous handling, the IOManager must add its own reference as long as the VariableHandle is used.
     *  @param pWriteValue Context for the node to write. The context contains the IndexRange requested by the client.
     *                     The NodeId and Attribute parameters of this context are already handled by the VariableHandle
     *                     The write context pointer is valid until the transaction is completely finished.
     *  @return Error code
     */
    virtual UaStatus beginWrite (
        OpcUa_Handle        hIOManagerContext,
        OpcUa_UInt32        callbackHandle,
        VariableHandle*     pVariableHandle,
        OpcUa_WriteValue*   pWriteValue) = 0;

    /** Finish a transaction.
     *  Is called by the SDK after the last begin method call for a transaction.
     *  If the nodes for the transaction are stored in the transaction context and the access to the underlying system is done in the finishTransaction, this access must be done asynchronous like in an own worker thread. It is expected that this method does not block for external communication with the underlying system. After finishing the communication with the underlying system, the corresponding finish callback methods of the interface IOManagerCallback can be called for each node in the transaction
     *  @param hIOManagerContext IOManager handle for the transaction context. This handle is used to identify the transaction to finish in the IOManager.
     *  @return Error code
     */
    virtual UaStatus finishTransaction (
        OpcUa_Handle        hIOManagerContext) = 0;
};

#endif // IOMANAGER_H
