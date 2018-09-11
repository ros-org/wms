/*****************************************************************************
 *                                                                           *
 * Copyright (c) 2006-2016 Unified Automation GmbH. All rights reserved.     *
 *                                                                           *
 * Software License Agreement ("SLA") Version 2.5                            *
 *                                                                           *
 * Unless explicitly acquired and licensed from Licensor under another       *
 * license, the contents of this file are subject to the Software License    *
 * Agreement ("SLA") Version 2.5, or subsequent versions as allowed by the   *
 * SLA, and You may not copy or use this file in either source code or       *
 * executable form, except in compliance with the terms and conditions of    *
 * the SLA.                                                                  *
 *                                                                           *
 * All software distributed under the SLA is provided strictly on an "AS     *
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,       *
 * AND LICENSOR HEREBY DISCLAIMS ALL SUCH WARRANTIES, INCLUDING WITHOUT      *
 * LIMITATION, ANY WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR   *
 * PURPOSE, QUIET ENJOYMENT, OR NON-INFRINGEMENT. See the SLA for specific   *
 * language governing rights and limitations under the SLA.                  *
 *                                                                           *
 * The complete license agreement can be found here:                         *
 * http://unifiedautomation.com/License/SLA/2.5/                             *
 *                                                                           *
 * Project: Unified Automation OPC UA ANSI C Communication Stack             *
 *                                                                           *
 * This software is based in part on the ANSI C Stack of the OPC Foundation. *
 * Initial version of the ANSI C Stack was founded and copyrighted by OPC    *
 * Foundation, Inc.                                                          *
 * Copyright (C) 2008, 2014 OPC Foundation, Inc., All Rights Reserved.       *
 *****************************************************************************/

#ifndef _OpcUa_Endpoint_H_
#define _OpcUa_Endpoint_H_ 1

#if OPCUA_HAVE_SERVERAPI

struct _OpcUa_Serializer;

#include <opcua_stream.h>

OPCUA_BEGIN_EXTERN_C

/**
 * @brief Associates a supported security policy with message security modes.
 */
struct _OpcUa_Endpoint_SecurityPolicyConfiguration
{
    /** @brief The URI of a supported security policy. */
    OpcUa_String        sSecurityPolicy;
    /** @brief The message security modes allowed for the security policy. (bitmask) */
    OpcUa_UInt16        uMessageSecurityModes;
    /** @brief The client certificate, if provided. */
    OpcUa_ByteString*   pbsClientCertificate;
};

typedef struct _OpcUa_Endpoint_SecurityPolicyConfiguration OpcUa_Endpoint_SecurityPolicyConfiguration;

/**
 * @brief Manages an endpoint for a server.
 */
typedef OpcUa_Void* OpcUa_Endpoint;

/**
 * @brief Types of serializers supported by the enpoint.
 *
 * @see OpcUa_Endpoint_Create
 */

/* TODO: This will match the transport profile in GetEndpoint. */
typedef enum _OpcUa_Endpoint_SerializerType
{
    OpcUa_Endpoint_SerializerType_Invalid,
    OpcUa_Endpoint_SerializerType_Binary,
    OpcUa_Endpoint_SerializerType_Xml
} OpcUa_Endpoint_SerializerType;

/** @brief Used in OpcUa_Endpoint_Open to set the supported message security modes.
 *  Differs from enumeration OpcUa_MessageSecurityMode!
 */
#define OPCUA_ENDPOINT_MESSAGESECURITYMODE_INVALID         0x00
#define OPCUA_ENDPOINT_MESSAGESECURITYMODE_NONE            0x01
#define OPCUA_ENDPOINT_MESSAGESECURITYMODE_SIGN            0x02
#define OPCUA_ENDPOINT_MESSAGESECURITYMODE_SIGNANDENCRYPT  0x04

/**
 * @brief Used to complete processing of a service request.
 *
 * @param hEndpoint [in] The endpoint that received the request.
 * @param pOstrm    [in] The stream used to send the response.
 * @param pResponse [in] The response parameters.
 */
typedef OpcUa_StatusCode (OpcUa_PfnEndInvokeService)(
    OpcUa_Endpoint              hEndpoint,
    struct _OpcUa_OutputStream* pOstrm,
    OpcUa_Void*                 pResponse,
    OpcUa_EncodeableType*       pResponseType);

/**
 * @brief Used to start processing of a service request.
 *
 * This method may block or it may return immediately and process the request
 * asynchronously. In both cases, the implementer must end the request by invoking
 * the callback.
 *
 * This method takes ownership of the stream and response objects and may complete
 * asynchronously. A success code returned from this message does not mean the response
 * reached its destination.
 *
 * @param hEndpoint  [in]     The endpoint that received the request.
 * @param hContext   [in]     The context associated with the request.
 * @param ppRequest  [in/out] The request parameters (set to null if the implementor wants to keep the memory).
 */
typedef OpcUa_StatusCode (OpcUa_PfnBeginInvokeService)(
    OpcUa_Endpoint          hEndpoint,
    OpcUa_Handle            hContext,
    OpcUa_Void**            ppRequest,
    OpcUa_EncodeableType*   pRequestType);

/**
 * @brief A function that implements a service.
 *
 * The exact set of arguments depends on the service type.
 *
 * @param hEndpoint [in] The endpoint that received the request.
 */
typedef OpcUa_StatusCode (OpcUa_PfnInvokeService)(OpcUa_Endpoint hEndpoint, ...);

/**
 * @brief Describes a service supported by an endpoint.
 */
struct _OpcUa_ServiceType
{
    /*! @brief The identifier for the service request. */
    OpcUa_UInt32 RequestTypeId;

    /*! @brief The type object for the service response */
    OpcUa_EncodeableType* ResponseType;

    /*! @brief The function used to start request processing. */
    OpcUa_PfnBeginInvokeService* BeginInvoke;

    /*! @brief The function used to invoke the service. */
    OpcUa_PfnInvokeService* Invoke;
};
typedef struct _OpcUa_ServiceType OpcUa_ServiceType;

/**
 * @brief Creates a new endpoint.
 *
 * @param phEndpoint            [out] The new endpoint.
 * @param eSerializerType       [ in] The serializer type, that should be supported by the endpoint.
 * @param pSupportedServices    [ in] The table with the services supported by the endpoint.
 */
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_Endpoint_Create( OpcUa_Endpoint*                     phEndpoint,
                                        OpcUa_Endpoint_SerializerType       eSerializerType,
                                        OpcUa_ServiceType**                 pSupportedServices);

/**
 * @brief Deletes an endpoint.
 *
 * @param phEndpoint [in/out] The endpoint to delete.
 */
OPCUA_EXPORT
OpcUa_Void OpcUa_Endpoint_Delete(OpcUa_Endpoint* phEndpoint);

/**
 * @brief Types of events that can occur at an endpoint and get reported to the application.
 */
typedef enum eOpcUa_Endpoint_Event
{
    /** @brief Reserved/Invalid/Ignore */
    eOpcUa_Endpoint_Event_Invalid,
    /** @brief A secure channel has been created. */
    eOpcUa_Endpoint_Event_SecureChannelOpened,
    /** @brief A secure channel has been closed. */
    eOpcUa_Endpoint_Event_SecureChannelClosed,
    /** @brief A secure channel has been renewed. */
    eOpcUa_Endpoint_Event_SecureChannelRenewed,
    /** @brief Verify certificate. Return OpcUa_BadContinue to suppress verification errors. */
    eOpcUa_Endpoint_Event_SecureChannelOpenVerifyCertificate,
    /** @brief Verify certificate. Return OpcUa_BadContinue to suppress verification errors. */
    eOpcUa_Endpoint_Event_SecureChannelRenewVerifyCertificate,
    /** @brief A call to an unsupported service has been made. */
    eOpcUa_Endpoint_Event_UnsupportedServiceRequested,
    /** @brief Raw unhandled non-UA request. To be handled by the application if possible. */
    eOpcUa_Endpoint_Event_RawRequest,
    /** @brief An error occurred while decoding a request. */
    eOpcUa_Endpoint_Event_DecoderError,
    /** @brief A secure channel lost its transport connection. */
    eOpcUa_Endpoint_Event_TransportConnectionClosed,
    /** @brief Endpoint is now closed. */
    eOpcUa_Endpoint_Event_Closed
} OpcUa_Endpoint_Event;

/**
 * @brief Describes the function that gets called by the endpoint on certain events. (@see OpcUa_Endpoint_Event)
 *
 * @param hEndpoint                 [in] The to which the secure channel was opened.
 * @param pvEndpointCallbackData    [in] Data given at Endpoint_Open is given back.
 * @param eEvent                    [in] What type of event occured at the endpoint.
 * @param uStatus                   [in] The status of the event.
 * @param uSecureChannelId          [in] The id assigned to the secure channel, if the event type refers to one.
 * @param phRawRequestContext       [bi] A request context for a raw request. Request data can be obtained with @see OpcUa_Endpoint_GetRawRequest.
 * @param pbsClientCertificate      [in] Pointer to the certificate provided by the client.
 * @param pSecurityPolicy           [in] The security policy, if the event type refers to a secure channel.
 * @param uSecurityMode             [in] The security mode, if the event type refers to a secure channel.
 * @param uRequestedLifetime        [in] Requested securechannel lifetime.
 */
typedef OpcUa_StatusCode (OpcUa_Endpoint_PfnEndpointCallback)(
    OpcUa_Endpoint          hEndpoint,
    OpcUa_Void*             pvCallbackData,
    OpcUa_Endpoint_Event    eEvent,
    OpcUa_StatusCode        uStatus,
    OpcUa_UInt32            uSecureChannelId,
    OpcUa_Handle*           phRawRequestContext,
    OpcUa_ByteString*       pbsClientCertificate,
    OpcUa_String*           pSecurityPolicy,
    OpcUa_UInt16            uSecurityMode,
    OpcUa_UInt32            uRequestedLifetime);

/**
 * @brief Obtain the id of the secure channel over which a certain message was transported.
 *
 * @param hEndpoint         [in] The endpoint.
 * @param hContext          [in] The context of the message.
 * @param pSecureChannelId [out] Contains the id of the secure channel if call succeeds.
 */
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_Endpoint_GetMessageSecureChannelId(
    OpcUa_Endpoint  hEndpoint,
    OpcUa_Handle    hContext,
    OpcUa_UInt32*   pSecureChannelId);

/**
 * @brief Obtain the security policy used for the secure channel over which a certain message was transported.
 *
 * @param hEndpoint         [in]    The endpoint.
 * @param hContext          [in]    The request context.
 * @param pSecurityPolicy  [out]   Contains the security policy of the secure channel if call succeeds. Must not(!) be deleted by caller.
 */
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_Endpoint_GetMessageSecureChannelSecurityPolicy(
    OpcUa_Endpoint                              hEndpoint,
    OpcUa_Handle                                hContext,
    OpcUa_Endpoint_SecurityPolicyConfiguration* pSecurityPolicy);


/**
 * @brief Starts accepting connections for the endpoint on the given URL.
 *
 * @param hEndpoint                 [in] The endpoint to open.
 * @param sUrl                      [in] The URL for this endpoint. (String must be zeroterminated.)
 * @param sTransportProfileUri.     [in] Specifies the transport profile URI, i.e. OpcUa_TransportProfile_UaTcp. (String must be zeroterminated.)
 * @param pfEndpointCallback        [in] Function getting called on various events.
 * @param pvEndpointCallbackData    [in] Pointer being passed to pfEndpointCallback.
 * @param pServerCertificate        [in] The application certificate for the server. This may be a concatenation of several chain certificates with the server certificate being the first element.
 * @param pServerPrivateKey         [in] The private key for pServerCertificate.
 * @param pPKIConfig                [in] Platformdependent configuration for the PkiProvider used by this endpoint.
 * @param nNoOfSecurityPolicies     [in] The number of security policies in pSecurityPolicies.
 * @param pSecurityPolicies         [in] Array with security policies supported by the endpoint.
 */
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_Endpoint_Open(
    OpcUa_Endpoint                              hEndpoint,
    const OpcUa_CharA*                          sUrl,
    const OpcUa_CharA*                          sTransportProfileUri,
    OpcUa_Endpoint_PfnEndpointCallback*         pfEndpointCallback,
    OpcUa_Void*                                 pvEndpointCallbackData,
    OpcUa_ByteString*                           pServerCertificate,
    OpcUa_Key*                                  pServerPrivateKey,
    OpcUa_Void*                                 pPKIConfig,
    OpcUa_UInt32                                nNoOfSecurityPolicies,
    OpcUa_Endpoint_SecurityPolicyConfiguration* pSecurityPolicies);

/**
 * @brief Stops accepting connections for the endpoint.
 *
 * @param hEndpoint [in] The endpoint to close.
 */
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_Endpoint_Close(OpcUa_Endpoint hEndpoint);

/**
 * @brief Creates a response object to use for a request.
 *
 * @param hEndpoint         [in]  The endpoint which received the request.
 * @param hContext          [in]  The context associated with the request.
 * @param ppResponse        [out] The response object that must be filled in by the caller.
 * @param ppResponseType    [out] The encodeable object type of the response object.
 */
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_Endpoint_BeginSendResponse(
    OpcUa_Endpoint         hEndpoint,
    OpcUa_Handle           hContext,
    OpcUa_Void**           ppResponse,
    OpcUa_EncodeableType** ppResponseType);

/**
 * @brief Sends the response for a request.
 *
 * If the status code is Bad the response object must be null. (HINT: is ignored)
 * Passing a bad status will cause a stack error to be sent back to the client.
 * Callers should create a valid response object to return application errors whenever possible.
 * Must not be called without OpcUa_Endpoint_BeginSendResponse being called before!
 * Call must be synchronized with a critical section by the application!
 *
 * @param hEndpoint     [in] The endpoint which received the request.
 * @param hContext      [in] The context associated with the request.
 * @param uStatusCode   [in] Indicates why the response object could not be created.
 * @param pResponse     [in] The response object to send.
 * @param pResponseType [in] The type of the response object.
 */
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_Endpoint_EndSendResponse(
    OpcUa_Endpoint        hEndpoint,
    OpcUa_Handle*         hContext,
    OpcUa_StatusCode      uStatusCode,
    OpcUa_Void*           pResponse,
    OpcUa_EncodeableType* pResponseType);

/**
 * @brief Cancels the response for a request.
 *
 * Cleans up resources allocated by OpcUa_Endpoint_BeginSendResponse
 * No data is sent over the wire. No new response can be created afterwards.
 * The response data has to be cleaned up manually.
 * Must not be called without OpcUa_Endpoint_BeginSendResponse being called before!
 * Call must be synchronized with a critical section by the application!
 *
 * @param hEndpoint     [in] The endpoint which received the request.
 * @param uStatus       [in] The status that triggered the cancelation.
 * @param psReason      [in] The reason for the cancelation.
 * @param hContext      [in] The context associated with the request.
 */
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_Endpoint_CancelSendResponse(
    OpcUa_Endpoint        hEndpoint,
    OpcUa_StatusCode      uStatus,
    OpcUa_String*         psReason,
    OpcUa_Handle*         hContext);

/**
 * @brief Sends an error response for a request.
 *
 * @param hEndpoint [in] The endpoint which received the request.
 * @param hContext  [in] The context associated with the request.
 * @param uStatus   [in] The error status to send.
 */
OPCUA_EXPORT
OpcUa_Void OpcUa_Endpoint_SendErrorResponse(
    OpcUa_Endpoint    hEndpoint,
    OpcUa_Handle      hContext,
    OpcUa_StatusCode  uStatus);


/**
 * @brief Returns a pointer to the function that implements the service.
 *
 * @param hEndpoint [in]  The endpoint which received the request.
 * @param hContext  [in]  The context to for a request.
 * @param ppInvoke  [out] A pointer to the service function.
 */
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_Endpoint_GetServiceFunction(
    OpcUa_Endpoint           hEndpoint,
    OpcUa_Handle             hContext,
    OpcUa_PfnInvokeService** ppInvoke);

/**
 * @brief Updates the functions called when a message arrives.
 *
 * The default BeginInvoke function will call the Invoke function. If the BeginInvoke
 * function is changed then the Invoke function will never be called unless the
 * new implementation calls it directly. Passing null for any of the function pointers
 * will leave the function table unchanged.
 *
 * @param hEndpoint      [in] The endpoint which received the request.
 * @param uRequestTypeId [in] The type id for the service request.
 * @param pBeginInvoke   [in] A pointer to the begin invoke function.
 * @param pInvoke        [in] A pointer to the invoke function.
 */
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_Endpoint_UpdateServiceFunctions(
    OpcUa_Endpoint               hEndpoint,
    OpcUa_UInt32                 uRequestTypeId,
    OpcUa_PfnBeginInvokeService* pBeginInvoke,
    OpcUa_PfnInvokeService*      pInvoke);

/**
 * @brief  Returns the callback data given in Endpoint_Open.
 *
 * @param hEndpoint      [in] The endpoint handle.
 * @param ppTypes       [out] Set to the value of callback data if function returns a good status. Else undefinied.
 */
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_Endpoint_GetCallbackData(
    OpcUa_Endpoint  a_hEndpoint,
    OpcUa_Void**    a_ppvCallbackData);

/**
 * @brief Creates a response object to use for a request.
 *
 * @param hEndpoint     [in]  The endpoint which received the request.
 * @param hContext      [in]  The context associated with the request.
 * @param ppInputStream [out] The input stream from the underlying transport handler.
 */
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_Endpoint_GetRawRequest(
    OpcUa_Endpoint      hEndpoint,
    OpcUa_Handle        hContext,
    OpcUa_InputStream** ppInputStream);

/**
 * @brief Turns raw request context into .
 *
 * @param hEndpoint     [in]  The endpoint which received the request.
 * @param hContext      [in]  The context associated with the request.
 */
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_Endpoint_BeginSendRawResponse(
    OpcUa_Endpoint          hEndpoint,
    OpcUa_Handle            hContext,
    OpcUa_OutputStream**    ppOutputStream);

/**
 * @brief Creates a response object to use for a request.
 *
 * @param hEndpoint     [in]  The endpoint which created the response.
 * @param hContext      [in]  The context associated with the response.
 * @param ppInputStream [out] The input stream from the underlying transport handler.
 */
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_Endpoint_EndSendRawResponse(
    OpcUa_Endpoint      hEndpoint,
    OpcUa_StatusCode    uStatus,
    OpcUa_Handle*       phContext);

/** 
 * @brief  Returns the peer connection info of the secure channel used in the context.
 * 
 * @param hEndpoint     [in] The endpoint handle.
 * @param hContext      [in] The context associated with the request.
 * @param pPeerInfo     [out] Returns the peer information as string.
 */
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_Endpoint_GetPeerInfoFromContext(
    OpcUa_Endpoint      hEndpoint,
    OpcUa_Handle        hContext,
    OpcUa_String*       psPeerInfo);

/** 
 * @brief  Returns the peer connection info of the secure channel with the given id.
 * 
 * @param hEndpoint         [in] The endpoint handle.
 * @param uSecureChannelId  [in] ID of the secure channel.
 * @param pPeerInfo         [out] Returns the peer information as string.
 */
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_Endpoint_GetPeerInfoBySecureChannelId(
    OpcUa_Endpoint      hEndpoint,
    OpcUa_UInt32        uSecureChannelId,
    OpcUa_String*       psPeerInfo);

/** 
 * @brief  Returns the audit entry id of the secure channel with the given id.
 * 
 * @param hEndpoint         [in] The endpoint handle.
 * @param uSecureChannelId  [in] ID of the secure channel.
 * @param psAuditEntryId   [out] Returns the audit entry id as string.
 */
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_Endpoint_GetAuditEntryIdBySecureChannelId(
    OpcUa_Endpoint      hEndpoint,
    OpcUa_UInt32        uSecureChannelId,
    OpcUa_String*       psAuditEntryId);

/** 
 * @brief Close the secure channel with the given ID.
 * 
 * @param hEndpoint         [in] The endpoint handle.
 * @param uSecureChannelId  [in] ID of the secure channel to be closed.
 */
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_Endpoint_CloseSecureChannel(
    OpcUa_Endpoint      hEndpoint,
    OpcUa_UInt32        uSecureChannelId,
    OpcUa_StatusCode    uStatus);

/**
 * @brief Check if the given endpoint is currently closed.
 * 
 * @param hEndpoint         [in] The endpoint handle.
 * @return OpcUa_True if endpoint is closed; OpcUa_False otherwise.
 */
OPCUA_EXPORT
OpcUa_Boolean OpcUa_Endpoint_IsClosed(OpcUa_Endpoint a_hEndpoint);

OPCUA_END_EXTERN_C

#endif /* OPCUA_HAVE_SERVERAPI */
#endif /* _OpcUa_Endpoint_H_ */
