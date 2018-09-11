/******************************************************************************
** opcuadi_transferservicestypebase.h
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

#ifndef __OPCUADI_TRANSFERSERVICESTYPEBASE_H__
#define __OPCUADI_TRANSFERSERVICESTYPEBASE_H__

#include "opcua_baseobjecttype.h"
#include "opcuadi_datatypes.h"
#include "basenodes.h"
#include "opcuadi_fetchresultdatatype.h"
#include "opcuadi_identifiers.h"
#include "opcuadi_instancefactory_devices.h"
#include "uaargument.h"

// Namespace for the UA information model http://opcfoundation.org/UA/DI/
namespace OpcUaDi {


/** Generated base class for a TransferServicesType.
 *
 *  This class contains the generated base code for the object type TransferServicesType
 *  representing an OPC UA ObjectType. This class is used to create the object type and to
 *  create and represent instances of the object type in the server address space.
 *
 */
class UAMODELS_EXPORT TransferServicesTypeBase:
    public OpcUa::BaseObjectType
{
    UA_DISABLE_COPY(TransferServicesTypeBase);
protected:
    virtual ~TransferServicesTypeBase();
public:
    // construction / destruction
    TransferServicesTypeBase(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    TransferServicesTypeBase(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    TransferServicesTypeBase(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;


    //- Interface MethodManager -----------------------------------------------------------
    /** Call method of an UA object. */
    virtual UaStatus beginCall(
        MethodManagerCallback* pCallback,
        const ServiceContext&  serviceContext,
        OpcUa_UInt32           callbackHandle,
        MethodHandle*          pMethodHandle,
        const UaVariantArray&  inputArguments);
    virtual UaStatus call(
        const ServiceContext&  serviceContext,
        MethodHandle*          pMethodHandle,
        const UaVariantArray&  inputArguments,
        UaVariantArray&        outputArguments,
        UaStatusCodeArray&     inputArgumentResults,
        UaDiagnosticInfos&     inputArgumentDiag);
    //- Interface MethodManager -----------------------------------------------------------

    virtual UaStatus FetchTransferResultData(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        OpcUa_Int32 TransferID,          /**<[in] Transfer Identifier returned from TransferTo- or TransferFromDevice.*/
        OpcUa_Int32 SequenceNumber,      /**<[in] The sequence number being acknowledged. The Server may delete the result set with this sequence number.*/
        OpcUa_Int32 MaxParameterResultsToReturn, /**<[in] The number of Parameters in TransferResult.ParameterDefs that the Client wants the Server to return in the response.*/
        OpcUa_Boolean OmitGoodResults,   /**<[in] If TRUE, the Server will omit data for Parameters which have been correctly transferred. Note that this causes all good results to be released.*/
        UaExtensionObject& FetchResult   /**<[out] Fetch result. Two subtypes are possible: TransferResultError, TransferResultData*/) = 0;
    virtual UaStatus TransferFromDevice(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        OpcUa_Int32& TransferID,        /**<[out] Transfer Identifier. This ID has to be used when calling FetchTransferResultData.*/
        OpcUa_Int32& InitTransferStatus /**<[out] Specifies if the transfer has been initiated. 0 – OK, -1 – E_NotLocked – the Device is not locked by the calling Client, -2 – E_NotOnline – the Device is not online/cannot be accessed.*/) = 0;
    virtual UaStatus TransferToDevice(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        OpcUa_Int32& TransferID,        /**<[out] Transfer Identifier. This ID has to be used when calling FetchTransferResultData.*/
        OpcUa_Int32& InitTransferStatus /**<[out] Specifies if the transfer has been initiated. 0 – OK, -1 – E_NotLocked – the Device is not locked by the calling Client, -2 – E_NotOnline – the Device is not online/cannot be accessed.*/) = 0;

    virtual OpcUa::BaseMethod* getFetchTransferResultData();
    virtual OpcUa::BaseMethod* getTransferFromDevice();
    virtual OpcUa::BaseMethod* getTransferToDevice();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(TransferServicesTypeBase *pInstance);

protected:

    // Method nodes
    static OpcUa::BaseMethod* s_pFetchTransferResultDataMethod;
    OpcUa::BaseMethod*  m_pFetchTransferResultDataMethod;
    static OpcUa::BaseMethod* s_pTransferFromDeviceMethod;
    OpcUa::BaseMethod*  m_pTransferFromDeviceMethod;
    static OpcUa::BaseMethod* s_pTransferToDeviceMethod;
    OpcUa::BaseMethod*  m_pTransferToDeviceMethod;


private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/DI/

#endif // #ifndef __OPCUADITRANSFERSERVICESTYPEBASE_H__


