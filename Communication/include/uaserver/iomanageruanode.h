/******************************************************************************
** iomanageruanode.h
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
** Description: IOManager base class implementation for UaNode based nodes.
**
******************************************************************************/
#ifndef IOMANAGERUANODE_H
#define IOMANAGERUANODE_H

#include "iomanager.h"
#include "uabasenodes.h"
#include "servermanager.h"

class IOManagerUaNodePrivate;
class IOManagerUaNode;
class UaVariableCache;
class UaThreadPoolJob;

/** Pointer array of UaVariable variables.  */
typedef UaPointerArray<UaVariable>      UaVariableArray;

/** Pointer array of UaNumericRange for index range.  */
typedef UaPointerArray<UaNumericRange>  UaNumericRangeArray;

/** @ingroup ServerCoreBaseClasses
 *  Implementation of the interface IOManager operating on a generic address space node model.
 */
class SERVER_CORE_EXPORT IOManagerUaNode :
    public IOManager
{
    UA_DISABLE_COPY(IOManagerUaNode);
public:

    // SupportedEncoding enumeration
    enum SupportedEncoding
    {
        EncodingNone = 0,
        EncodingDefaultBinary,
        EncodingUnsupported
    };

    IOManagerUaNode();
    virtual ~IOManagerUaNode();
    virtual UaStatus startUpIO(ServerManager* pServerManager);
    virtual UaStatus shutDownIO();

    /** Reads the value attributes for a list of UaVariables.
     *  This method needs to be overwritten by a derived class if the value attribute should be read not from
     *  cache but from an external data source.
     *
     *  This method is called for Read calls from OPC UA clients and for monitoring of Variables where the
     *  UaVariable::valueHandling is not set to UaVariable_Value_CacheIsSource.
     *
     *  This method will be called for monitored items even if the Variable node was removed from the
     *  NodeManager. Monitored items are created by clients and they stay valid even if the node they were
     *  created for was removed. Only the status of the monitored item must change to BadNodeIdUnknown in
    `*  this case. The Variable will be invalidated during removal from address space but will stay in memory
     *  until all monitored items are reoved for it. When the Variable is made invalid, the user data is also set
     *  invalid by calling UserDataBase::setInvalid(). The application specific user data class must implement
     *  this method and must set the user data invalid. If the user data is invalid for a Node, readValue shall
     *  return BadNodeIdInvalid in this case.
     *  @param arrUaVariables  An array of UaVariable interface pointers used to indicate which variables
     *                         should be read. The implementation of the interface needs to have the necessary
     *                         information to access the data from the external source.
     *  @param arrDataValues   An array of UaDataValue classes used to return the read values.
     *  @return Error code
     */
    virtual UaStatus readValues(
        const UaVariableArray& arrUaVariables,
        UaDataValueArray&      arrDataValues);

    /** Writes the value attributes for a list of UaVariables.
     *  This method needs to be overwritten by a derived class if the value attribute should be written
     *  to an external data source.
     *
     *  This method is called for Write calls from OPC UA clients for Variables where the
     *  UaVariable::valueHandling is not set to UaVariable_Value_CacheIsSource.
     *  @param arrUaVariables  An array of UaVariable interface pointers used to indicate which variables
     *                         should be written. The implementation of the interface needs to have the necessary
     *                         information to update the data in the external source.
     *  @param arrpDataValues  Array of pointers to OpcUa_DataValue structures containing the data to write.
     *  @param arrStatusCodes  An array of OpcUa_StatusCode values used to indicate if the write succeeds
     *                         on a single variable base.
     *  @return Error code
     */
    virtual UaStatus writeValues(
        const UaVariableArray& arrUaVariables,
        const PDataValueArray& arrpDataValues,
        UaStatusCodeArray&     arrStatusCodes);

    /** Event that is called before the value of an attribute of a Node is set.
     * Allows to reject the writing of the attribute.
     * This method needs to be overwritten by a derived class to influence the handling of the writing of the attribute
     * @param pSession       [in] Interface of the Session context for the attribute write.
     * @param pNode          [in] Interface of the UaNode to update.
     * @param attributeId    [in] Attribute id indicating the attribute to set.
     * @param dataValue      [in] New value for the attribute.
     * @param checkWriteMask [out] Flag indicating if the write mask of the node attribute or the access level for the value attribute should be checked
                             in UaNode::setAttributeValue.
     * @return               OpcUa_True if the value should be written, OpcUa_False if not.
     */
    virtual OpcUa_Boolean beforeSetAttributeValue(
        Session*           pSession,
        UaNode*            pNode,
        OpcUa_Int32        attributeId,
        const UaDataValue& dataValue,
        OpcUa_Boolean&     checkWriteMask);

    /** Event that is called after the value of an attribute of a Node was updated.
     * This method needs to be overwritten by a derived class to get informed about an attribute change.
     * @param pSession       [in] Interface to the Session context for the attribute write.
     * @param pNode          [in] Interface of the updated UaNode.
     * @param attributeId    [in] Id of the updated attribute.
     * @param dataValue      [in] New value for the attribute.
     */
    virtual void afterSetAttributeValue(
        Session*           pSession,
        UaNode*            pNode,
        OpcUa_Int32        attributeId,
        const UaDataValue& dataValue);

    /** Event that is called after the value of an attribute of a Node was read from the node.
     * This method needs to be overwritten by a derived class to change the value returned to the client.
     * This can be used to return different localized text values or to check if the client is allowed
     * to read the value.
     * @param pSession       [in] Interface to the Session context for the attribute read.
     * @param pNode          [in] Interface of the UaNode to read.
     * @param attributeId    [in] Id of the attribute to read.
     * @param dataValue      [in/out] Value for the attribute.
     */
    virtual void afterGetAttributeValue(
        Session*     pSession,
        UaNode*      pNode,
        OpcUa_Int32  attributeId,
        UaDataValue& dataValue);

    /** Event that is called before a data monitored item is created.
     * This method needs to be overwritten by a derived class to influence the creation of monitored items based on the user rights.
     * This can be used to reject the creation of a monitored item based on the user rights. The OPC UA recommended behavior is to create the
     * monitored item but to send a bad status in the initial data callback. This behavior can be controlled with the flag returnErrorInCreate.
     * @param pSession            [in] Interface to the Session context for the attribute read.
     * @param pNode               [in] Interface of the UaNode to read.
     * @param attributeId         [in] Id of the attribute to read.
     * @param returnErrorInCreate [out] Indicates in the error case if the error should be returned in CreateMonitoredItems or in the first data change notification.
                                        The recommended option is to return the error in the first data change notification.
     * @return               OpcUa_Good if the monitored item should be created. Any bad status code like OpcUa_BadUserAccessDenied if the user is not allowed to subsribe for the attribute.
     */
    virtual UaStatus beforeMonitorAttributeValue(
        Session*       pSession,
        UaNode*        pNode,
        OpcUa_Int32    attributeId,
        OpcUa_Boolean& returnErrorInCreate);

    /** Event that is called after the monitoring of a cache variable was changed.
     *
     * This method needs to be overwritten by a derived class to get informed about monitoring changes for a cache variable.
     * This can be used to start or stop the data acquisition if the values in the cache are only update when the variable is monitored.
     *
     * It is not allowed to block this method since it is called from the network thread
     * @param pVariable       [in] UaVariableCache that was changed. The class UaVariableCache provides information about the number of
                                   subscribed monitored items (UaVariableCache::signalCount) and the smallest requrested sampling interval
                                   (UaVariableCache::getMinSamplingInterval).
     * @param transactionType [in] Type of transaction. Could be MONITOR_BEGIN, MONITOR_MODIFY or MONITOR_STOP
     */
    virtual void variableCacheMonitoringChanged(UaVariableCache* pVariable, TransactionType transactionType);

    /** Method used to enable or disable support for writing timestamp
     * @param isSupported [in] Flag indicating if writing of timestamp should be supported.
    */
    void setTimestampWriteSupport(OpcUa_Boolean isSupported);

    /** Method used to enable or disable support for writing status
     * @param isSupported [in] Flag indicating if writing of status should be supported.
    */
    void setStatusWriteSupport(OpcUa_Boolean isSupported);

    // Implementation of IOManager interface
    UaStatus beginTransaction(IOManagerCallback*, const ServiceContext&, OpcUa_UInt32, OpcUa_UInt32, OpcUa_Double, OpcUa_TimestampsToReturn, TransactionType, OpcUa_Handle&);
    UaStatus beginStartMonitoring(OpcUa_Handle, OpcUa_UInt32, IOVariableCallback*, VariableHandle*, MonitoringContext&);
    UaStatus beginModifyMonitoring(OpcUa_Handle, OpcUa_UInt32, OpcUa_UInt32, MonitoringContext&);
    UaStatus beginStopMonitoring(OpcUa_Handle, OpcUa_UInt32, OpcUa_UInt32);
    UaStatus beginRead(OpcUa_Handle, OpcUa_UInt32, VariableHandle*, OpcUa_ReadValueId*);
    UaStatus beginWrite(OpcUa_Handle, OpcUa_UInt32, VariableHandle*, OpcUa_WriteValue*);
    UaStatus finishTransaction(OpcUa_Handle);

    // Internal helper method for NodeManagerUaNode
    void beforeRemoveMonitoredVariableCache(UaVariableCache* pUaVariableCache);
    void afterAddVariableCache(UaVariableCache* pUaVariableCache);
private:
    IOManagerUaNodePrivate* d;

    OpcUa_Boolean isStructureType(Session* pSession, VariableHandle* pVariableHandle);
    static OpcUa_Boolean isStructureType(const UaNodeId& dataType);
    static OpcUa_Boolean isNumberType(const UaNodeId& dataType);
    UaStatus getAbsoluteChangeValue(const UaVariable *pUaVariable, OpcUa_Double percentDeadband, OpcUa_Double &absoluteChange) const;
};

#endif // IOMANAGERUANODE_H
