/******************************************************************************
** opcuadi_transferservicestype.h
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
** Project: C++ OPC Server SDK information model for namespace http://opcfoundation.org/UA/DI/
**
** Description: OPC Unified Architecture Software Development Kit.
**
******************************************************************************/

#ifndef __OPCUADI_TRANSFERSERVICESTYPE_H__
#define __OPCUADI_TRANSFERSERVICESTYPE_H__

#include "opcuadi_transferservicestypebase.h"

// Namespace for the UA information model http://opcfoundation.org/UA/DI/
namespace OpcUaDi {

/** Callback interface used to implement the TransferServices interface in the user application
 *
 * The transfer of information (Parameters) between offline nodes and the physical device is supported through OPC UA Methods.
 * These Methods are built on device specific knowledge and functionality.
 *
 * The transfer is usually terminated if an error occurs for any of the Parameters. No automatic retry will be conducted by the
 * Server. However, whenever possible after a failure, the Server should bring the Device back into a functional state. The Client
 * has to retry by calling the transfer Method again.
 *
 * The transfer may involve thousands of Parameters so that it can take a long time (up to minutes), and with a result that may
 * be too large for a single response. Therefore, the initiation of the transfer and the collection of result data are performed
 * with separate Methods.
 *
 * The Device shall have been locked by the Client prior to invoking these Methods.
 */
class UAMODELS_EXPORT TransferServicesCallback
{
    UA_DISABLE_COPY(TransferServicesCallback);
public:
    TransferServicesCallback(){}
    virtual ~TransferServicesCallback(){}

    /** Method used to initiate the transfer of offline parameters to the device
     *
     * TransferToDevice initiates the transfer of offline configured data (Parameters) to the physical
     * device. This Method has no input arguments. Which Parameters are transferred is based on serverinternal knowledge.
     *
     * The Server shall ensure integrity of the data before star ting the transfer. Once the transfer has been
     * started successfully, the Method returns immediately with InitTransferStatus = 0. Any status
     * information regarding the transfer itself has to be collected using the FetchTransferResultData Method.
     *
     * The Server will reset any cached value for Nodes in the online instance representing Parameters
     * affected by the transfer. That way the cache will be re-populated from the Device next time they are requested.
     */
    virtual UaStatus TransferToDevice(
        const ServiceContext& serviceContext, //!< [in] The session and client call context
        OpcUa_Int32& TransferID, //!< [out] Transfer Identifier. This ID has to be used when calling FetchTransferResultData.
        OpcUa_Int32& InitTransferStatus) //!< [out] Specifies if the transfer has been initiated. 0 - OK, -1 – E_NotLocked, -2 – E_NotOnline
        = 0;

    /** Method used to initiate the transfer of parameters from the device to the offline configuration
     *
     * TransferFromDevice initiates the transfer of values from the physical device to corresponding Parameters in the offline
     * representation of the Device. This Method has no input arguments. Which Parameters are transferred is based on server-internal knowledge.
     *
     * Once the transfer has been started successfully, the Method returns immediately with InitTransferStatus = 0. Any status information
     * regarding the transfer itself has to be collected using the FetchTransferResultData Method.
     */
    virtual UaStatus TransferFromDevice(
        const ServiceContext& serviceContext, //!< [in] The session and client call context
        OpcUa_Int32& TransferID, //!< [out] Transfer Identifier. This ID has to be used when calling FetchTransferResultData.
        OpcUa_Int32& InitTransferStatus) //!< [out] Specifies if the transfer has been initiated. 0 - OK, -1 – E_NotLocked, -2 – E_NotOnline
        = 0;

    /** Method used to get the results of transfer from and to device methods
     *
     * The TransferTo- and TransferFromDevice Methods execute asynchronously after sending a response to the Client. Excution status and
     * execution results are collected during execution and can be retrieved using the FetchTransferResultData Method. The TransferId is
     * used as identifier to retrieve the data.
     *
     * The Client is assumed to fetch the result data in a timely manner. However, because of the asynchronous execution and the possibility
     * of data loss due to transmission errors to the Client, the Server shall wait some time (some minutes) before deleting data that have
     * not been acknowledged. This should be even beyond Session termination; i.e. Clients that have to re-establish a Session after an error
     * may try to retrieve missing result data.
     *
     * Result data will be deleted with each new Transfer request for the same Device.
     *
     * FetchTransferResultData is used to request the execution status and a set of result data. If called before the transfer is finished
     * it will return only partial data. The amount of data returned may be further limited if it would be too large. “Too large” in this
     * context means that the Server is not able to return a larger response or that the number of results to return exceeds the maximum number
     * of results that was specified by the Client when calling this Method.
     *
     * Each result returned to the Client is assigned a sequence number. The Client acknowledges that it received the result by passing the
     * sequence number in the new call to this Method. The Server can delete the acknowledged result and will return the next result set with
     * a new sequence number.
     *
     * Clients shall not call the Method before the previous one returned. If it returns with an error (e.g. Bad_Timeout), the Client can call
     * the FetchTransferResultData with a sequence number 0. In this case the Server will resend the last result set.
     *
     * The Server will return Bad_NothingToDo in the Method-specific StatusCode of the Call Service if the transfer is finished and no further result data are available.
     */
    virtual UaStatus FetchTransferResultData(
        const ServiceContext& serviceContext, //!< [in] The session and client call context
        OpcUa_Int32 TransferID, //!< [in] Transfer Identifier returned from TransferTo- or TransferFromDevice
        OpcUa_Int32 SequenceNumber, //!< [in] The sequence number being acknowledged. The Server may delete the result set with this sequence number.
        OpcUa_Int32 MaxParameterResultsToReturn, //!< [in] The number of Parameters in TransferResult.ParameterDefs that the Client wants the Server to return in the response. The Server is allowed to further limit the response, but shall not exceed this limit.
        OpcUa_Boolean OmitGoodResults, //!< [in] If TRUE, the Server will omit data for Parameters which have been correctly transferred.
        UaExtensionObject& FetchResult) //!< [out] Two subtypes are possible, TransferResultError if transfer failed completely and TransferResultData with result data.
        = 0;
};

/** @brief Class implementing the UaObject interface for the TransferServicesType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.<br>
 *
 *  **Method members of the TransferServicesType:**
 *
 *  Browse Name                  | Modelling Rule
 *  -----------------------------|---------------
 *  \ref FetchTransferResultData | Mandatory
 *  \ref TransferFromDevice      | Mandatory
 *  \ref TransferToDevice        | Mandatory
 *
 * The transfer of information (Parameters) between offline nodes and the physical device is supported through OPC UA Methods.
 * These Methods are built on device specific knowledge and functionality.
 *
 * The transfer is usually terminated if an error occurs for any of the Parameters. No automatic retry will be conducted by the
 * Server. However, whenever possible after a failure, the Server should bring the Device back into a functional state. The Client
 * has to retry by calling the transfer Method again.
 *
 * The transfer may involve thousands of Parameters so that it can take a long time (up to minutes), and with a result that may
 * be too large for a single response. Therefore, the initiation of the transfer and the collection of result data are performed
 * with separate Methods.
 *
 * The Device shall have been locked by the Client prior to invoking these Methods.
 */
class UAMODELS_EXPORT TransferServicesType:
    public TransferServicesTypeBase
{
    UA_DISABLE_COPY(TransferServicesType);
protected:
    // destruction
    virtual ~TransferServicesType();
public:
    // construction
    TransferServicesType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    TransferServicesType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    TransferServicesType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    // UaTransferServicesType method FetchTransferResultData
    virtual UaStatus FetchTransferResultData(
        const ServiceContext& serviceContext,
        OpcUa_Int32 TransferID,
        OpcUa_Int32 SequenceNumber,
        OpcUa_Int32 MaxParameterResultsToReturn,
        OpcUa_Boolean OmitGoodResults,
        UaExtensionObject& FetchResult);
    // UaTransferServicesType method TransferFromDevice
    virtual UaStatus TransferFromDevice(
        const ServiceContext& serviceContext,
        OpcUa_Int32& TransferID,
        OpcUa_Int32& InitTransferStatus);
    // UaTransferServicesType method TransferToDevice
    virtual UaStatus TransferToDevice(
        const ServiceContext& serviceContext,
        OpcUa_Int32& TransferID,
        OpcUa_Int32& InitTransferStatus);

    void setTransferServicesCallback(TransferServicesCallback* pCallback);

protected:
    TransferServicesCallback* m_pCallback;
private:
};

} // End namespace for the UA information model http://opcfoundation.org/UA/DI/

#endif // #ifndef __OPCUADITRANSFERSERVICESTYPE_H__

