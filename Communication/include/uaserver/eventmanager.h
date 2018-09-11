/******************************************************************************
** eventmanager.h
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
** Description: OPC server core module EventManager interface.
**
******************************************************************************/
#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "coremoduleincludes.h"

/** @ingroup ServerCoreInterfaces
*  The callback interface for event monitored items.
 */
class SERVER_CORE_EXPORT EventCallback
{
public:

    /** construction */
    EventCallback(){};
    /** destruction */
    virtual ~EventCallback(){};

    /** A new event occured. The implementation of this method should never block. Only fill data into a queue here and process asynchronously.
     * @param eventFields a field of all Events that can occur.
     * @param detach Indicates if the event data contained in the eventFields can be detached or not.
     */
    virtual void newEvent(UaVariantArray& eventFields, OpcUa_Boolean detach) = 0;

    /** Invalidate the event manager in the event receiver to be able to remove the EventManager from the system.
     * @param eventManagerIndex index of the event manager used by the event receiver to identify the event manager.
                                This index was provided in beginStartMonitoring or beginModifyMonitoring
     */
    virtual void invalidateEventManager(OpcUa_UInt32 eventManagerIndex) = 0;
};


/** @ingroup ServerCoreInterfaces
 *  The corresponding callback interface for the EventManager.
 *  This callback interface provides all corresponding callback methods for the begin methods in the EventManager interface.
 */
class SERVER_CORE_EXPORT EventManagerCallback
{
    /// @brief Prevents shallow copy
    UA_DISABLE_COPY(EventManagerCallback);

public:
    /// construction
    EventManagerCallback(){};
    /// destruction
    virtual ~EventManagerCallback(){};

    /** Finished transaction to start monitoring an event item.
     *  @param hTransaction Handle for the transaction used by the SDK to identify the transaction in the callbacks. This handle was passed in to the IOManager with the beginTransaction method.
     *  @param callbackHandle Handle for the node in the callback. This handle was passed in to the EventManager with the beginStartMonitoring method.
     *  @param eventManagerIndex an Index of different EventManagers.
     *  @param hEventItem an EventItem used to fire an Event.
     *  @param revisedSamplingInterval The corresponding revised sampling interval for the requested sampling interval in beginStartMonitoring.
     *  @param statusCode Result of the StartMonitoring operation.
     *  @param pEventFilterResult Detailed result for the event filter. Can be NULL if no error occurred. The SDK detaches the result content.
     *  @return Result code of the method call
     */
    virtual UaStatus finishStartMonitoring(
        OpcUa_UInt32             hTransaction,
        OpcUa_UInt32             callbackHandle,
        OpcUa_UInt32             eventManagerIndex,
        OpcUa_UInt32             hEventItem,
        OpcUa_Double             revisedSamplingInterval,
        const UaStatus&          statusCode,
        OpcUa_EventFilterResult* pEventFilterResult) = 0;

    /** Finished transaction to modify monitoring an event item.
     *  @param hTransaction Handle for the transaction used by the SDK to identify the transaction in the callbacks. This handle was passed in to the IOManager with the beginTransaction method.
     *  @param callbackHandle Handle for the node in the callback. This handle was passed in to the EventManager with the beginModifyMonitoring method.
     *  @param eventManagerIndex an Index of different EventManagers.
     *  @param revisedSamplingInterval The corresponding revised sampling interval for the requested sampling interval in beginModifyMonitoring.
     *  @param statusCode Result of the ModifyMonitoring operation.
     *  @param pEventFilterResult Detailed result for the event filter. Can be NULL if no error occurred. The SDK detaches the result content.
     *  @return Result code of the method call
     */
    virtual UaStatus finishModifyMonitoring(
        OpcUa_UInt32             hTransaction,
        OpcUa_UInt32             callbackHandle,
        OpcUa_UInt32             eventManagerIndex,
        OpcUa_Double             revisedSamplingInterval,
        const UaStatus&          statusCode,
        OpcUa_EventFilterResult* pEventFilterResult) = 0;

    /** Finished transaction to stop monitoring an event item.
     *  @param hTransaction Handle for the transaction used by the SDK to identify the transaction in the callbacks. This handle was passed in to the IOManager with the beginTransaction method.
     *  @param callbackHandle Handle for the node in the callback. This handle was passed in to the EventManager with the beginStopMonitoring method.
     *  @param eventManagerIndex an Index of different EventManagers.
     *  @param statusCode Result of the StopMonitoring operation.
     *  @return Result code of the method call
     */
    virtual UaStatus finishStopMonitoring(
        OpcUa_UInt32    hTransaction,
        OpcUa_UInt32    callbackHandle,
        OpcUa_UInt32    eventManagerIndex,
        const UaStatus& statusCode) = 0;
};

/** @ingroup ServerCoreHelper
*  This class provides the settings for an event monitored item.
*/
class SERVER_CORE_EXPORT EventMonitoringContext
{
    UA_DISABLE_COPY(EventMonitoringContext);
public:
    /** Construction with initialized Parameters */
    EventMonitoringContext()
    {
        pEventFilter     = NULL;
        samplingInterval = 0;
    };
    /** Destruction */
    virtual ~EventMonitoringContext(){};

    /** @brief Event filter for the monitored item. */
    const OpcUa_EventFilter*   pEventFilter;
    /** @brief Sampling interval for the monitored item to create. */
    OpcUa_Double               samplingInterval;
};

/** @ingroup ServerCoreHelper
*  This class provides the settings for an event monitored item.
*/
class SERVER_CORE_EXPORT EventMonitoringContextCreate: public EventMonitoringContext
{
    UA_DISABLE_COPY(EventMonitoringContextCreate);
public:
    /** Construction with initialized Parameters */
    EventMonitoringContextCreate()
    {
        pNodeId          = NULL;
        pIndexRange      = NULL;
        pDataEncoding    = NULL;
    };
    /** Destruction */
    virtual ~EventMonitoringContextCreate(){};

    /** @brief NodeId of the event notifier object to monitored. */
    const OpcUa_NodeId*        pNodeId;
    /** @brief Index range for the monitored item to create. */
    const OpcUa_String*        pIndexRange;
    /** @brief Data encoding for the monitored item to create. This parameter is only relevant if one or more event fields of the events to monitor are complex. */
    const OpcUa_QualifiedName* pDataEncoding;
};

/** @ingroup ServerCoreInterfaces
 Interface definition of the EventManager used for monitoring events.
 The EventManager interface provides the monitoring capabilities for object notifiers. The EventManager
 interface is asynchronous. For the EventManager callback the EventManagerCallback interface is implemented by the consumer of the
 events. One of the consumers is the UA Module. This interface is used by the SDK to multiplex the list of event monitored items in
 the UA service call to different EventManager. One UA service call is a transaction for the SDK. If an EventManager is used in a
 transaction, the beginEventTransaction method is called by the SDK. This allows the EventManager to create a context for the transactions
 since the SDK will call the associated begin method (e.g. beginStartMonitoring) for each monitored item in the transaction.
 Depending on the underlying system, the action can be started for each monitored item in the begin method or for a list of monitored items in the
 finishEventTransaction method. If the underlying system allows optimizing access for a list of monitored items, the finishEventTransaction method
 should be used to start the access to the underlying system. This method is called by the SDK after calling the begin methods
 for all monitored items in the transaction.
 */
class SERVER_CORE_EXPORT EventManager
{
    /// @brief Prevents shallow copy
    UA_DISABLE_COPY(EventManager);
public:
    /** EventTransactionType enumeration  */
    enum EventTransactionType
    {
        MONITOR_BEGIN,  /*!< Begin monitoring for a list of data items */
        MONITOR_MODIFY, /*!< Modify monitoring for a list of data items */
        MONITOR_STOP,   /*!< Stop monitoring for a list of data items */
        INVALID         /*!< Invalid transaction */
    };

    /// construction
    EventManager(){};
    /// destruction
    virtual ~EventManager(){};

    /** Begins a transaction for modifying the list of event monitored items.
     *  @param pCallback            Callback interface used for the transaction. The EventManager must use this interface to finish the action for each passed
     *                              event monitored item in the transaction. The callback interface pointer is valid until the transaction is completely finished.
     *  @param serviceContext       General context for the service calls containing information like the session object, return diagnostic mask and timeout hint.
     *  @param hTransaction         Handle for the transaction used by the SDK to identify the transaction in the callbacks.
     *                              The Event manager must store this handle and use it in callbacks to EventManagerCallback
     *  @param totalItemCountHint   A hint for the EventManager about the total number of monitored items in the transaction.
                                    The EventManager may not be responsible for all items but he can use this hint if he wants to optimize memory allocation.
     *  @param transactionType      Type of the transaction. The possible enum values are:
     *      MONITOR_BEGIN
     *      MONITOR_MODIFY
     *      MONITOR_STOP
     *  @param hEventManagerContext Handle provided by the EventManager to identify the transaction in the following begin calls.
     *                              The handle is managed by the EventManager and must be valid until the transaction is completely finished.
     *  @return   Result code of the method call
     */
    virtual UaStatus beginEventTransaction (
        EventManagerCallback* pCallback,
        const ServiceContext& serviceContext,
        OpcUa_UInt32          hTransaction,
        OpcUa_UInt32          totalItemCountHint,
        EventTransactionType  transactionType,
        OpcUa_Handle&         hEventManagerContext) = 0;

    /** Start monitoring of an event notifier.
     *  @param hEventManagerContext   Handle provided by the EventManager in beginEventTransaction used to identify the transaction context for this call.
     *  @param callbackHandle         Handle for the item in the callback.
     *  @param eventManagerIndex      Index of the EventManager that needs to be passed to the callback function.
     *  @param pEventCallback         Callback interface used for event callbacks to the event MonitoredItem managed by the SDK.
     *                                The callback interface is valid until the monitoring is stopped through beginStopMonitoring.
     *  @param eventMonitoringContext Settings for an event monitored item contained in the EventMonitoringContext class.
     *                                The object is only valid during this method is called.
     *  @return Result code of the method call
     */
    virtual UaStatus beginStartMonitoring(
        OpcUa_Handle   hEventManagerContext,
        OpcUa_UInt32   callbackHandle,
        OpcUa_UInt32   eventManagerIndex,
        EventCallback* pEventCallback,
        const EventMonitoringContextCreate& eventMonitoringContext) = 0;

    /** Notify EventManager about modifying monitoring parameters of an event notifier.
     *
     *  If this method or the finishModifyMonitoring callback returns an error for a valid event item in the EventManager, the EventManager must suspend
     *  the event item until another modify succeeds or until it is removed.
     *
     *  @param hEventManagerContext   Handle provided by the EventManager in beginEventTransaction used to identify the transaction context for this call.
     *  @param callbackHandle         Handle for the item in the callback.
     *  @param eventManagerIndex      Index of the EventManager that needs to be passed to the callback function.
     *  @param hEventItem             Handle used to identify the EventItem in the EventManager.
     *                                The handle is provided by the EventManager in the callback EventManagerCallback::finishStartMonitoring.
     *  @param eventMonitoringContext Settings for an event monitored item contained in the EventMonitoringContext class.
     *                                The object is only valid during this method is called.
     *  @return Result code of the method call
     */
    virtual UaStatus beginModifyMonitoring(
        OpcUa_Handle                  hEventManagerContext,
        OpcUa_UInt32                  callbackHandle,
        OpcUa_UInt32                  eventManagerIndex,
        OpcUa_UInt32                  hEventItem,
        const EventMonitoringContext& eventMonitoringContext) = 0;

    /** Notify EventManager about stopping monitoring of an event notifier.
     *  @param hEventManagerContext Handle provided by the EventManager in beginEventTransaction used to identify the transaction context for this call.
     *  @param callbackHandle       Handle for the item in the callback.
     *  @param eventManagerIndex    Index of the EventManager that needs to be passed to the callback function.
     *  @param hEventItem           Handle used to identify the EventItem in the EventManager.
     *                              The handle is provided by the EventManager in the callback EventManagerCallback::finishStartMonitoring.
     *  @return Result code of the method call
     */
    virtual UaStatus beginStopMonitoring(
        OpcUa_Handle        hEventManagerContext,
        OpcUa_UInt32        callbackHandle,
        OpcUa_UInt32        eventManagerIndex,
        OpcUa_UInt32        hEventItem) = 0;

    /** Finishes the transaction for changing the list of event monitored items.
     *  @param hEventManagerContext Handle of the event transaction.
     *  @return Result code of the method call
     */
    virtual UaStatus finishEventTransaction (
        OpcUa_Handle        hEventManagerContext) = 0;

    /** This optional method triggers a refresh for all conditions of interest in the EventManager. Conditions of interest have the Retain flag set to true.
     *  This method needs to be implemented if the EventManager provides access to condition objects.
     *  The method is not allowed to be blocked in the EventManager. The actual refresh must be executed in a worker thread.
     *  If the method is called, the EventManager must issue a RefreshStartEventType, must resend the state for any condition where the retain flag is set
     *  to true and must send a RefreshEndEventType after the conditions are processed. The refresh start and end events must be sent independent of the
     *  number of conditions.
     *  @param serviceContext General context for the service calls containing information like the session object, return diagnostic mask and timeout hint.
     *  @param hEventItem Handle used to identify the EventItem in the EventManager.
     *                    The handle is provided by the EventManager in the callback EventManagerCallback::finishStartMonitoring.
     *  @param beginEventId EventId used for the RefreshStartEvent. All monitored items must use the same EventId for this event.
     *                      The RefreshStartEvent is only sent if the beginEventId is not NULL.
     *  @param endEventId EventId used for the RefreshEndEvent. All monitored items must use the same EventId for this event.
     *                      The RefreshEndEvent is only sent if the endEventId is not NULL.
     *  @return Result code of the method call
     */
    virtual UaStatus beginConditionRefresh(
        const ServiceContext& serviceContext,
        OpcUa_UInt32 hEventItem,
        const UaByteString& beginEventId,
        const UaByteString& endEventId);

    /** This method triggers a RefreshRequired event to the clients
     *  This event forces the clients to synchronize with the current Condition states by calling ConditionRefresh
     *  This method needs to be implemented in every EventManager that is part of a system that provides condition objects.
     *  The method is not allowed to be blocked in the EventManager.
     *  If the method is called, the EventManager must issue a RefreshStartEventType, must resend the state for any condition where the retain flag is set
     *  to true and must send a RefreshEndEventType after the conditions are processed. The refresh start and end events must be sent independent of the
     *  number of conditions.
     *  @param hEventItem Handle used to identify the EventItem in the EventManager.
     *                    The handle is provided by the EventManager in the callback EventManagerCallback::finishStartMonitoring.
     *  @param eventId EventId used for the RefreshRequired. All monitored items must use the same EventId for this event.
     *  @return Result code of the method call
     */
    virtual UaStatus sendRefreshRequired(
        OpcUa_UInt32        hEventItem,
        const UaByteString& eventId);
};

/** @ingroup ServerCoreHelper
Pointer array of EventManager variables.
*/
typedef UaPointerArray<EventManager> EventManagerArray;

/** @ingroup ServerCoreHelper
 This class holds the context for an event transaction.
 */
class SERVER_CORE_EXPORT EventTransactionContext
{
    UA_DISABLE_COPY(EventTransactionContext);
public:

    /**  construction with initialized Variables */
    EventTransactionContext()
    {
        m_pCallback    = NULL;
        m_hTransaction = 0;
        m_pSession     = NULL;
    };
    /// destruction
    virtual ~EventTransactionContext()
    {
        if ( m_pSession )
        {
            m_pSession->releaseReference();
        }
    };

    /** Set the Session of the current Session.
     *  @param pSession a pointer to the Session to be set.
     */
    void setSession(Session* pSession)
    {
        if ( pSession )
        {
            m_pSession = pSession;
            pSession->addReference();
        }
    };

    /** Get the actual Session via pointer.
     *  @return the actual Session.
     */
    inline Session* pSession()
    {
        return m_pSession;
    };

    EventManagerCallback* m_pCallback;
    OpcUa_UInt32          m_hTransaction;
private:
    Session*              m_pSession;
};

/** @ingroup ServerCoreHelper
 This class holds the context for one EventManager in the transaction.
 */
class SERVER_CORE_EXPORT EventManagerSubset
{
    /// @brief Prevents shallow copy
    UA_DISABLE_COPY(EventManagerSubset);
public:
    /**  construction with initialized Variables */
    EventManagerSubset()
    {
        m_pEventManager                   = NULL;
        m_hEventManagerTransactionContext = NULL;
    };

    EventManager*       m_pEventManager;
    OpcUa_Handle        m_hEventManagerTransactionContext;
};

#endif // EVENTMANAGER_H

