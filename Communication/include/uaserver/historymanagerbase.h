/******************************************************************************
** historymanagerbase.h
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
** Description: HistoryManager base implementation to provide a simpliefied synchronous API.
**
******************************************************************************/
#ifndef HISTORYMANAGERBASE_H
#define HISTORYMANAGERBASE_H

#include "historymanager.h"
#include "uathreadpool.h"
#include "opcua_historyservercapabilitiestype.h"

/** HistoryManager base implementation providing a simplified synchronous API.
 *
 *  This class simplifies the HistoryManager interface implementation by changing the interface to a single node based
 *  synchronous API and by providing a default implementation for most of the function, either returning an error BadHistoryOperationUnsupported or
 *  by providing an implementation like for read processed. The only required method to implement in the derived class is the readRawModified method.
 *  Other methods can be implemented if the functionality should be provided by the server.
 */
class SERVER_CORE_EXPORT HistoryManagerBase: public HistoryManager
{
    UA_DISABLE_COPY(HistoryManagerBase);
public:
    HistoryManagerBase();
    HistoryManagerBase(OpcUa_Boolean supportReadProcessed, OpcUa_Boolean supportReadAtTime);
    virtual ~HistoryManagerBase();

    UaStatus startUp(ServerManager* pServerManager);
    OpcUa::HistoryServerCapabilitiesType* pHistoryServerCapabilities();

    /** Read raw history values for a node.
     *
     *  This method is pure virtual and must be implemented by a derived class. Implementation of this method is the minimum requirement for HistoryRead support.
     *
     *  @param serviceContext     General context for the service calls containing information like the session object, return diagnostic mask and timeout hint.
     *  @param pVariableHandle    Variable handle provided by the NodeManager::getHistoryVariableHandle.
     *  @param ppContinuationPoint The continuation point data from a previous Read call. Null if first Read.
     *                    Implementers of this interface can store the continuation point data in a derived class.
     *                    The pointer to the continuation point object must be deleted in the method and must be set to NULL.
     *                    A new continuation point can be created, queued in the Session and assigned to this parameter as out value if necessary.
     *  @param timestampsToReturn The client selected timestamp to return. Valid enum values are: OpcUa_TimestampsToReturn_Source, OpcUa_TimestampsToReturn_Server, OpcUa_TimestampsToReturn_Both
     *  @param maxValues          The maximum number of values to return.
     *  @param startTime          The start time of the time period to read.
     *  @param endTime            The end time of the time period to read.
     *  @param returnBounds       Flag that indicates if bounding values should be returned.
     *  @param pReadValueId       Context for the node to read. The context contains the IndexRange and the DataEncoding requested by the client.
     *                            The other parameters of this context are already handled by the HistoryVariableHandle and the SDK.
     *  @param dataValues         The requested values for this operation.
     *  @return Error code.
     */
   virtual UaStatus readRaw (
        const ServiceContext&       serviceContext,
        HistoryVariableHandle*      pVariableHandle,
        HistoryReadCPUserDataBase** ppContinuationPoint,
        OpcUa_TimestampsToReturn    timestampsToReturn,
        OpcUa_UInt32                maxValues,
        OpcUa_DateTime&             startTime,
        OpcUa_DateTime&             endTime,
        OpcUa_Boolean               returnBounds,
        OpcUa_HistoryReadValueId*   pReadValueId,
        UaDataValues&               dataValues) = 0;

    /** Read modified history values for a node.
     *
     *  The default implementation of this method returns OpcUa_GoodNoData to indicate that there is no modified data available. If the HistoryManager supports
     *  modified data, the derived class must overwrite this method with an implementation that delivers the modified data.
     *
     *  @param serviceContext     General context for the service calls containing information like the session object, return diagnostic mask and timeout hint.
     *  @param pVariableHandle    Variable handle provided by the NodeManager::getHistoryVariableHandle.
     *  @param ppContinuationPoint The continuation point data from a previous Read call. Null if first Read.
     *                    Implementers of this interface can store the continuation point data in a derived class.
     *                    The pointer to the continuation point object must be deleted in the method and must be set to NULL.
     *                    A new continuation point can be created, queued in the Session and assigned to this parameter as out value if necessary.
     *  @param timestampsToReturn The client selected timestamp to return. Valid enum values are: OpcUa_TimestampsToReturn_Source, OpcUa_TimestampsToReturn_Server, OpcUa_TimestampsToReturn_Both
     *  @param maxValues          The maximum number of values to return.
     *  @param startTime          The start time of the time period to read.
     *  @param endTime            The end time of the time period to read.
     *  @param returnBounds       Flag that indicates if bounding values should be returned.
     *  @param pReadValueId       Context for the node to read. The context contains the IndexRange and the DataEncoding requested by the client.
     *                            The other parameters of this context are already handled by the HistoryVariableHandle and the SDK.
     *  @param dataValues         The requested values for this operation.
     *  @param modificationInformations The modification information for the requested Values for this operation. The information array will be detached by the SDK.
     *  @return Error code.
     */
   virtual UaStatus readModified (
        const ServiceContext&       serviceContext,
        HistoryVariableHandle*      pVariableHandle,
        HistoryReadCPUserDataBase** ppContinuationPoint,
        OpcUa_TimestampsToReturn    timestampsToReturn,
        OpcUa_UInt32                maxValues,
        OpcUa_DateTime&             startTime,
        OpcUa_DateTime&             endTime,
        OpcUa_Boolean               returnBounds,
        OpcUa_HistoryReadValueId*   pReadValueId,
        UaDataValues&               dataValues,
        UaModificationInfo&         modificationInformations);

    /** Read processed history values for a node.
     *
     *  The default implementation of this method implements all aggregate calculations defined in the OPC UA Aggregates specification by using the readRaw
     *  method of this class. The calculation can be deactivated when creating the HistoryManagerBase instance.
     *
     *  @param serviceContext     General context for the service calls containing information like the session object, return diagnostic mask and timeout hint.
     *  @param pVariableHandle    Variable handle provided by the NodeManager::getVariableHandle.
     *  @param ppContinuationPoint The continuation point data from a previous Read call. Null if first Read.
     *                    Implementers of this interface can store the continuation point data in a derived class.
     *                    The pointer to the continuation point object must be deleted in the method and must be set to NULL.
     *                    A new continuation point can be created, queued in the Session and assigned to this parameter as out value if necessary.
     *  @param timestampsToReturn The client selected timestamp to return. Valid enum values are: OpcUa_TimestampsToReturn_Source, OpcUa_TimestampsToReturn_Server, OpcUa_TimestampsToReturn_Both
     *  @param startTime          The start time of the time period to read.
     *  @param endTime            The end time of the time period to read.
     *  @param resampleInterval   The interval to re sample.
     *  @param aggregateType      The aggregate type node id.
     *  @param aggregateConfiguration The aggregate configuration.
     *  @param pReadValueId       Context for the node to read. The context contains the IndexRange and the DataEncoding requested by the client.
     *                            The other parameters of this context are already handled by the HistoryVariableHandle and the SDK.
     *  @param dataValues         The requested values for this operation.
     *  @return Error code.
     */
   virtual UaStatus readProcessed (
        const ServiceContext&        serviceContext,
        HistoryVariableHandle*       pVariableHandle,
        HistoryReadCPUserDataBase**  ppContinuationPoint,
        OpcUa_TimestampsToReturn     timestampsToReturn,
        OpcUa_DateTime&              startTime,
        OpcUa_DateTime&              endTime,
        OpcUa_Double                 resampleInterval,
        const UaNodeId&              aggregateType,
        OpcUa_AggregateConfiguration aggregateConfiguration,
        OpcUa_HistoryReadValueId*    pReadValueId,
        UaDataValues&                dataValues);

    /** Read history values for a node at specific timestamps.
     *
     *  The default implementation of this method implements read at specific timestamps by using the readRaw
     *  method of this class. This functionality can be deactivated when creating the HistoryManagerBase instance.
     *
     *  @param serviceContext     General context for the service calls containing information like the session object, return diagnostic mask and timeout hint.
     *  @param pVariableHandle    Variable handle provided by the NodeManager::getVariableHandle.
     *  @param timestampsToReturn The client selected timestamp to return. Valid enum values are: OpcUa_TimestampsToReturn_Source, OpcUa_TimestampsToReturn_Server, OpcUa_TimestampsToReturn_Both
     *  @param requestedTimes     The requested timestamps to read.
     *  @param useSimpleBounds    Use SimpleBounds to determine the value at the specific timestamp.
     *  @param pReadValueId       Context for the node to read. The context contains the IndexRange and the DataEncoding requested by the client.
     *                            The other parameters of this context are already handled by the HistoryVariableHandle and the SDK.
     *  @param dataValues         The requested values for this operation.
     *  @return Error code.
     */
   virtual UaStatus readAtTime (
        const ServiceContext&      serviceContext,
        HistoryVariableHandle*     pVariableHandle,
        OpcUa_TimestampsToReturn   timestampsToReturn,
        const UaDateTimeArray&     requestedTimes,
        OpcUa_Boolean              useSimpleBounds,
        OpcUa_HistoryReadValueId*  pReadValueId,
        UaDataValues&              dataValues);

    /** Read event history for a node.
     *
     *  The default implementation of this method returns OpcUa_BadHistoryOperationUnsupported to indicate that reading of event history is not supported.
     *  If the HistoryManager supports reading of event history, the derived class must overwrite this method with an implementation that delivers the event history.
     *
     *  @param serviceContext     General context for the service calls containing information like the session object, return diagnostic mask and timeout hint.
     *  @param pVariableHandle Variable handle provided by the NodeManager::getVariableHandle.
     *      This object contains the information needed by the IOManager to identify the node to read in its context.
     *  @param ppContinuationPoint The continuation point data from a previous Read call. Null if first Read. Implementers of this interface can store the continuation point data in a derived class.
     *  @param numValuesPerNode the Number of Values per Node.
     *  @param startTime          The start time of the time period to read.
     *  @param endTime            The end time of the time period to read.
     *  @param filter             An event filter used to select events to read.
     *  @param pReadValueId       Context for the node to read. The context contains the IndexRange and the DataEncoding requested by the client.
     *                            The other parameters of this context are already handled by the HistoryVariableHandle and the SDK.
     *  @param events             A list of events that match the read filter.
     *  @return Error code
     */
    virtual UaStatus readEvents (
        const ServiceContext&       serviceContext,
        HistoryVariableHandle*      pVariableHandle,
        HistoryReadCPUserDataBase** ppContinuationPoint,
        OpcUa_UInt32                numValuesPerNode,
        OpcUa_DateTime&             startTime,
        OpcUa_DateTime&             endTime,
        const OpcUa_EventFilter&    filter,
        OpcUa_HistoryReadValueId*   pReadValueId,
        UaHistoryEventFieldLists&   events);

    /** Update history data values for a node.
     *
     *  The default implementation of this method returns OpcUa_BadHistoryOperationUnsupported to indicate that update is not supported.
     *  If the HistoryManager supports update, the derived class must overwrite this method with an implementation that executes the update.
     *
     *  @param serviceContext     General context for the service calls containing information like the session object, return diagnostic mask and timeout hint.
     *  @param pVariableHandle Variable handle provided by the NodeManager::getVariableHandle.
     *      This object contains the information needed by the IOManager to identify the node to read in its context.
     *  @param performInsertReplace The mode to insert data or to replace older data.
     *  @param isStructureUpdate      Flag indicating if the provided data is meta data like anotations describing an entry in the history database
     *  @param updateValue        The list of data values to update.
     *  @param operationResults   The results for the requested update values.
     *  @param operationDiagnosticInfos The diagnostic for the requested update values.
     *  @return Error code
     */
    virtual UaStatus updateData (
        const ServiceContext&   serviceContext,
        HistoryVariableHandle*  pVariableHandle,
        OpcUa_PerformUpdateType performInsertReplace,
        OpcUa_Boolean           isStructureUpdate,
        const UaDataValues&     updateValue,
        UaStatusCodeArray&      operationResults,
        UaDiagnosticInfos&      operationDiagnosticInfos);

    /** Update history events for a node.
     *
     *  The default implementation of this method returns OpcUa_BadHistoryOperationUnsupported to indicate that update is not supported.
     *  If the HistoryManager supports update, the derived class must overwrite this method with an implementation that executes the update.
     *
     *  @param serviceContext     General context for the service calls containing information like the session object, return diagnostic mask and timeout hint.
     *  @param pVariableHandle Variable handle provided by the NodeManager::getVariableHandle.
     *      This object contains the information needed by the IOManager to identify the node to read in its context.
     *  @param performInsertReplace The mode to insert events or to replace older events.
     *  @param filter             An event filter used to select events to update.
     *  @param eventData          A list of events to update.
     *  @param operationResults   The results for the requested update events.
     *  @param operationDiagnosticInfos The diagnsotic for the requested update events.
     *  @return Error code
     */
    virtual UaStatus updateEvents (
        const ServiceContext&           serviceContext,
        HistoryVariableHandle*          pVariableHandle,
        OpcUa_PerformUpdateType         performInsertReplace,
        const OpcUa_EventFilter&        filter,
        const UaHistoryEventFieldLists& eventData,
        UaStatusCodeArray&              operationResults,
        UaDiagnosticInfos&              operationDiagnosticInfos);

    /** Delete raw or modified history values for a node.
     *
     *  The default implementation of this method returns OpcUa_BadHistoryOperationUnsupported to indicate that update is not supported.
     *  If the HistoryManager supports update, the derived class must overwrite this method with an implementation that executes the update.
     *
     *  @param serviceContext     General context for the service calls containing information like the session object, return diagnostic mask and timeout hint.
     *  @param pVariableHandle    Variable handle provided by the NodeManager::getVariableHandle.
     *      This object contains the information needed by the IOManager to identify the node to read in its context.
     *  @param isDeleteModified   A flag that indicates if modified values should be deleted instead of raw value.
     *  @param startTime          The start time of the time period to delete.
     *  @param endTime            The end time of the time period to delete.
     *  @return Error code
     */
    virtual UaStatus deleteRawModified (
        const ServiceContext&    serviceContext,
        HistoryVariableHandle*   pVariableHandle,
        OpcUa_Boolean            isDeleteModified,
        OpcUa_DateTime&          startTime,
        OpcUa_DateTime&          endTime);

    /** Delete history values at the passed timestamps.
     *
     *  The default implementation of this method returns OpcUa_BadHistoryOperationUnsupported to indicate that update is not supported.
     *  If the HistoryManager supports update, the derived class must overwrite this method with an implementation that executes the update.
     *
     *  @param serviceContext     General context for the service calls containing information like the session object, return diagnostic mask and timeout hint.
     *  @param pVariableHandle Variable handle provided by the NodeManager::getVariableHandle.
     *      This object contains the information needed by the IOManager to identify the node to read in its context.
     *  @param requestedTimes     The list of timestamps to delete.
     *  @param operationResults   The results for the requested timestamps to delete.
     *  @param operationDiagnosticInfos The diagnostic for the requested timestamps to delete.
     *  @return Error code
     */
    virtual UaStatus deleteAtTime (
        const ServiceContext&    serviceContext,
        HistoryVariableHandle*   pVariableHandle,
        const UaDateTimeArray&   requestedTimes,
        UaStatusCodeArray&       operationResults,
        UaDiagnosticInfos&       operationDiagnosticInfos);

    /** Delete events for a node.
     *
     *  The default implementation of this method returns OpcUa_BadHistoryOperationUnsupported to indicate that update is not supported.
     *  If the HistoryManager supports update, the derived class must overwrite this method with an implementation that executes the update.
     *
     *  @param serviceContext     General context for the service calls containing information like the session object, return diagnostic mask and timeout hint.
     *  @param pVariableHandle Variable handle provided by the NodeManager::getVariableHandle.
     *      This object contains the information needed by the IOManager to identify the node to read in its context.
     *  @param eventIds The list of EventIds for the events to delete.
     *  @param operationResults   The results for the requested events to delete.
     *  @param operationDiagnosticInfos The diagnostic for the requested events to delete.
     *  @return Error code
     */
    virtual UaStatus deleteEvents (
        const ServiceContext&    serviceContext,
        HistoryVariableHandle*   pVariableHandle,
        const UaByteStringArray& eventIds,
        UaStatusCodeArray&       operationResults,
        UaDiagnosticInfos&       operationDiagnosticInfos);

    // Implementation of HistoryManager interface
    UaStatus beginHistoryTransaction(HistoryManagerCallback*,const ServiceContext&,OpcUa_UInt32,OpcUa_UInt32,HistoryManager::TransactionType,OpcUa_TimestampsToReturn,OpcUa_Handle&);
    UaStatus beginReadRawModified(OpcUa_Handle,OpcUa_UInt32,HistoryVariableHandle*,HistoryReadCPUserDataBase*,OpcUa_Boolean,OpcUa_UInt32,OpcUa_DateTime&,OpcUa_DateTime&,OpcUa_Boolean,OpcUa_HistoryReadValueId*);
    UaStatus beginReadProcessed(OpcUa_Handle,OpcUa_UInt32,HistoryVariableHandle*,HistoryReadCPUserDataBase*,OpcUa_DateTime&,OpcUa_DateTime&,OpcUa_Double,const OpcUa_NodeId&,OpcUa_AggregateConfiguration,OpcUa_HistoryReadValueId*);
    UaStatus beginReadAtTime(OpcUa_Handle,OpcUa_UInt32,HistoryVariableHandle*,HistoryReadCPUserDataBase*,const UaDateTimeArray&,OpcUa_Boolean,OpcUa_HistoryReadValueId*);
    UaStatus beginReadEvents(OpcUa_Handle,OpcUa_UInt32,HistoryVariableHandle*,HistoryReadCPUserDataBase*,OpcUa_UInt32,OpcUa_DateTime&,OpcUa_DateTime&,const OpcUa_EventFilter&,OpcUa_HistoryReadValueId*);
    UaStatus beginUpdateData(OpcUa_Handle,OpcUa_UInt32,HistoryVariableHandle*,OpcUa_PerformUpdateType,OpcUa_Boolean,const UaDataValues&);
    UaStatus beginUpdateEvents(OpcUa_Handle,OpcUa_UInt32,HistoryVariableHandle*,OpcUa_PerformUpdateType,const OpcUa_EventFilter&,const UaHistoryEventFieldLists&);
    UaStatus beginDeleteRawModified(OpcUa_Handle,OpcUa_UInt32,HistoryVariableHandle*,OpcUa_Boolean,OpcUa_DateTime&,OpcUa_DateTime&);
    UaStatus beginDeleteAtTime(OpcUa_Handle,OpcUa_UInt32,HistoryVariableHandle*,const UaDateTimeArray&);
    UaStatus beginDeleteEvents(OpcUa_Handle,OpcUa_UInt32,HistoryVariableHandle*,const UaByteStringArray&);
    UaStatus finishHistoryTransaction (OpcUa_Handle);

private:
    UaThreadPool* getThreadPool();
    UaStatus getValueAtTime(const ServiceContext&,HistoryVariableHandle*,OpcUa_TimestampsToReturn,const OpcUa_DateTime&,OpcUa_Boolean,OpcUa_HistoryReadValueId*,OpcUa_DataValue&);
    OpcUa_Boolean isStructureType(Session* pSession, HistoryVariableHandle* pVariableHandle);
    static OpcUa_Boolean isStructureType(const UaNodeId& dataType);

private:
    UaThreadPool* m_pThreadPool;
    OpcUa_Boolean m_supportReadProcessed;
    OpcUa_Boolean m_supportReadAtTime;
    OpcUa::HistoryServerCapabilitiesType* m_pHistoryServerCapabilities;
};

#endif // HISTORYMANAGERBASE_H
