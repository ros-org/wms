/******************************************************************************
** methodmanager.h
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
** Description: OPC server core module MethodManager interface.
**
******************************************************************************/
#ifndef METHODMANAGER_H
#define METHODMANAGER_H

#include "opcuatypes.h"
#include "referencecounter.h"

class SERVER_CORE_EXPORT MethodManagerCallback;
class SERVER_CORE_EXPORT MethodHandle;

/** @ingroup ServerCoreInterfaces
 @brief  Interface definition of the MethodManager used for calling methods in the server.

 The MethodManager interface provides the method call capability for objects. The MethodManager
 interface is asynchronous. For the MethodManager callback the MethodManagerCallback interface is implemented by the consumer
 of the call results. One of the consumers is the UA Module. This interface is used by the SDK to multiplex the list of calls in
 the UA service to different MethodManagers.
 */
class SERVER_CORE_EXPORT MethodManager
{
    UA_DISABLE_COPY(MethodManager);
public:
    /** construction */
    MethodManager(){};
    /** destruction */
    virtual ~MethodManager(){};

    /** Call method of an UA object.
     *  @param pCallback Callback interface used for the transaction.
     *      The MethodManager must use this interface to finish the action for each passed node in the transaction.
     *      The callback interface pointer is valid until the transaction is completely finished.
     *  @param serviceContext General context for the service calls containing information like the session object, return diagnostic mask and timeout hint.
     *  @param callbackHandle Handle for the method call in the callback.
     *  @param pMethodHandle MethodHandle provided by the NodeManager::getMethodHandle.
     *         This object contains the information needed by the MethodManager to identify the object and the method to call.
     *         The object is reference counted. The reference used by the SDK is released after beginCall is returned. If the MethodManager
     *         needs the MethodHandle of asynchronous handling, the MethodManager must add its own reference as long as the MethodHandle is used.
     *  @param inputArguments The list of input arguments for the method call.
     *  @return Error code
     */
    virtual UaStatus beginCall(
        MethodManagerCallback* pCallback,
        const ServiceContext&  serviceContext,
        OpcUa_UInt32           callbackHandle,
        MethodHandle*          pMethodHandle,
        const UaVariantArray&  inputArguments) = 0;
};

/** @ingroup ServerCoreInterfaces
 *  The corresponding callback interface for the MethodManager.
 *  This callback interface provides the corresponding callback methods for the begin method in the MethodManager interface.
 */
class SERVER_CORE_EXPORT MethodManagerCallback
{
    UA_DISABLE_COPY(MethodManagerCallback);
public:
    /** construction */
    MethodManagerCallback(){};
    /** destruction */
    virtual ~MethodManagerCallback(){};

    /** Finishes a call to a method of an UA object.
     *  @param callbackHandle Handle for the node in the callback.
     *      This handle was passed in to the MethodManager with the beginCall method.
     *  @param inputArgumentResults the Result of the actual input Argument.
     *      The result array is only filled if the overall result of the method call operation is BadInvalidArgument.
     *      In this case the result array must have the same length like the input argument array.
     *  @param inputArgumentDiag the actual input Argument.
     *  @param outputArguments the actual output Argument.
     *  @param statusCode Result of the method call operation.
     *  @return Error code
     */
    virtual UaStatus finishCall(
        OpcUa_UInt32       callbackHandle,
        UaStatusCodeArray& inputArgumentResults,
        UaDiagnosticInfos& inputArgumentDiag,
        UaVariantArray&    outputArguments,
        UaStatus&          statusCode) = 0;
};

/** @brief Base class containing the information necessary to execute a method call.

 *  The instance of the MethodHandle class or a derived class is created in the function NodeManager::getMethodHandle and contains all
 *  information necessary for the SDK to call the MethodManager and for the MethodManager implementation to execute the method.
 *  The information for a MethodManager implementation must be provided by a derived class.
 *  The class is reference counted by deriving from ReferenceCounter. The class can not be deleted directly.
 */
class SERVER_CORE_EXPORT MethodHandle: public ReferenceCounter
{
    UA_DISABLE_COPY(MethodHandle);
public:
    /** Enumeration for the different MethodVariableHandle implementations */
    enum HandleImplementation
    {
        CUSTOM,   /*!< A product specific handle implementation is used */
        NODE_ID,  /*!< The class MethodHandleNodeId is used */
        UA_NODE   /*!< The class MethodHandleUaNode is used */
    };

    /** Construction with initialization of member variables */
    MethodHandle()
    {
        m_pMethodManager = NULL;
    };

    /** Returns the type of handle implementation */
    virtual HandleImplementation getHandleImplementation() const { return CUSTOM; }

    /** @brief Interface pointer of the responsible MethodManager for the node. */
    MethodManager* m_pMethodManager;
protected:
    /**  Destruction of the class. The reference counted class can not be deleted directly.
    * Use releaseReference to release your reference to the class instance.
    */
    virtual ~MethodHandle(){};
};

/** @brief MethodHandle containing the information necessary to execute a method with the object and method NodeId.

 *  The instance of the MethodHandleUaNode class is created in the function NodeManager::getMethodHandle and contains all
 *  information necessary for the SDK to call the MethodManager and for the MethodManager implementation to execute the method.
 *  The information for a MethodManager implementation are the NodeIds for Object and Method contained as members in this class.
 *  The class is reference counted by deriving from ReferenceCounter. The class can not be deleted directly.
 */
class SERVER_CORE_EXPORT MethodHandleNodeId: public MethodHandle
{
    UA_DISABLE_COPY(MethodHandleNodeId);
public:
    MethodHandleNodeId(){}

    /** Returns the type of handle implementation */
    virtual HandleImplementation getHandleImplementation() const { return MethodHandle::NODE_ID; }

    /// @brief NodeId of the object the method is called on.
    UaNodeId m_objectNodeId;

    /// @brief NodeId of the method to call.
    UaNodeId m_methodNodeId;

protected:
    virtual ~MethodHandleNodeId(){}
};


#endif // METHODMANAGER_H
