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

#ifndef _OpcUa_Channel_H_
#define _OpcUa_Channel_H_ 1

#if OPCUA_HAVE_CLIENTAPI

OPCUA_BEGIN_EXTERN_C

#if OPCUA_SUPPORT_PREENCODED_MESSAGES
#include <opcua_stream.h>
#include <opcua_connection.h>
#endif

/**
 * @brief The Channel Handle.
 */
typedef OpcUa_Void* OpcUa_Channel;

#if OPCUA_HAVE_HTTPS
typedef struct _OpcUa_Channel_HttpsSecurityToken
{
    OpcUa_ByteString    bsServerCertificate;
    OpcUa_String        sUsedCipher;
} OpcUa_Channel_HttpsSecurityToken;
#endif

typedef enum _OpcUa_Channel_SecurityTokenType
{
    OpcUa_Channel_SecurityTokenType_Invalid                 = 0,
    OpcUa_Channel_SecurityTokenType_OpcSecureConversation   = 1,
    OpcUa_Channel_SecurityTokenType_Https                   = 2
} OpcUa_Channel_SecurityTokenType;

typedef struct _OpcUa_Channel_SecurityToken
{
    OpcUa_Channel_SecurityTokenType eTokenType;
    union _SecurityToken
    {
        OpcUa_ChannelSecurityToken*             pOpcChannelSecurityToken;
#if OPCUA_HAVE_HTTPS
        OpcUa_Channel_HttpsSecurityToken        HttpsSecurityToken;
#endif
    } SecurityToken;
} OpcUa_Channel_SecurityToken;

/** 
 * @brief Types of events that can occur at an channel and get reported to the application.
 */
typedef enum eOpcUa_Channel_Event
{
    /** @brief Reserved/Invalid/Ignore */
    eOpcUa_Channel_Event_Invalid,
    /** @brief A secure channel has been connected. (ignore for sync api) */
    eOpcUa_Channel_Event_Connected,
    /** @brief A secure channel has been disconnected. */
    eOpcUa_Channel_Event_Disconnected,
    /** @brief A secure channel has been renewed. */
    eOpcUa_Channel_Event_Renewed,
    /** @brief A certficate error has occured. */
    eOpcUa_Channel_Event_VerifyCertificate,
    /** @brief An asynchronous operation resulted in an error. */
    eOpcUa_Channel_Event_Error
} OpcUa_Channel_Event;

/** 
 * @brief Types of serializers supported by the enpoint.
 *
 * @see OpcUa_Channel_Create
 */
enum _OpcUa_Channel_SerializerType
{
    OpcUa_Channel_SerializerType_Invalid,
    OpcUa_Channel_SerializerType_Binary,
    OpcUa_Channel_SerializerType_Xml
};
typedef enum _OpcUa_Channel_SerializerType OpcUa_Channel_SerializerType;

/** 
 * @brief Called by the stack to report an asynchronous connection event. 
 *
 * @param pChannel         [in] The channel used to send the request.
 * @param pCallbackData    [in] The callback data specifed when the request was sent.
 * @param eEvent           [in] The event that occured.
 * @param uStatus          [in] The status code, with which the operation completed.
 * @param pSecurityToken   [in] The new security token.
 */
typedef OpcUa_StatusCode (OpcUa_Channel_PfnConnectionStateChanged)(
    OpcUa_Channel                   hChannel,
    OpcUa_Void*                     pCallbackData,
    OpcUa_Channel_Event             eEvent,
    OpcUa_StatusCode                uStatus,
    OpcUa_Channel_SecurityToken*    pSecurityToken);

/** 
 * @brief Creates a new channel.
 * 
 * @param ppChannel    [out] The new channel.
 * @param eEncoderType [in]  The type of encoder to use for messages.
 */
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Channel_Create( 
    OpcUa_Channel*               phChannel,
    OpcUa_Channel_SerializerType eSerializerType);

/** 
 * @brief Deletes a channel.
 *
 * @param ppChannel [in/out] The channel to delete.
 */
OPCUA_EXPORT OpcUa_Void OpcUa_Channel_Delete(   
    OpcUa_Channel* phChannel);

/** 
 * @brief Establishes a network connection with the server but does not create the session.
 *
 * @param pChannel                      [in] The channel to connect.
 * @param sUrl                          [in] The url of the server to connect to.
 * @param sTransportProfileUri.         [in] Specifies the transport profile URI, i.e. OpcUa_TransportProfile_UaTcp. (String must be zeroterminated.)
 * @param pfCallback                    [in] Function to call for channel event notification.
 * @param pvCallbackData                [in] Gets passed back to the application in pfCallback.
 * @param pClientCertificate            [in] The clients certificate. This may be a concatenation of several chain certificates with the client certificate being the first element.
 * @param pClientPrivateKey             [in] The clients private key matching the public key in the certificate.
 * @param pServerCertificate            [in] The certificate of the server. Must be the only certificate in the byte string.
 * @param pPKIConfig                    [in] Implementation dependend configuration for the PKI.
 * @param pRequestedSecurityPolicyUri   [in] URI defining the security parameter set applied to the connection.
 * @param nRequestedLifetime            [in] The requested lifetime for the security token.
 * @param messageSecurityMode           [in] The message security mode requested for the communication.
 * @param sAuditEntryId                 [in] The audit entry id the server shall use for the secure channel audit event.
 * @param ppSecurityToken              [out] SecurityToken issued by the server. Read-Only.
 * @param nNetworkTimeout               [in] The network timeout. Also used for disconnect.
 */
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Channel_Connect( 
    OpcUa_Channel                               hChannel,
    const OpcUa_CharA*                          sUrl,
    const OpcUa_CharA*                          sTransportProfileUri,
    OpcUa_Channel_PfnConnectionStateChanged*    pfCallback,
    OpcUa_Void*                                 pvCallbackData,
    OpcUa_ByteString*                           pClientCertificate,
    OpcUa_ByteString*                           pClientPrivateKey,
    OpcUa_ByteString*                           pServerCertificate,
    OpcUa_Void*                                 pPKIConfig,
    OpcUa_String*                               pRequestedSecurityPolicyUri,
    OpcUa_Int32                                 nRequestedLifetime,
    OpcUa_MessageSecurityMode                   messageSecurityMode,
    OpcUa_String*                               sAuditEntryId,
    OpcUa_Channel_SecurityToken**               ppSecurityToken,
    OpcUa_UInt32                                nNetworkTimeout);

/** 
 * @brief Establishes a network connection with the server including the secure conversation but does not create the session.
 *
 * @param pChannel                      [in] The channel to connect.
 * @param sUrl                          [in] The url of the server to connect to.
 * @param sTransportProfileUri          [in] Specifies the transport profile URI, i.e. OpcUa_TransportProfile_UaTcp. (String must be zeroterminated.)
 * @param pClientCertificate            [in] The clients certificate. This may be a concatenation of several chain certificates with the client certificate being the first element.
 * @param pClientPrivateKey             [in] The private key for the certificate.
 * @param pServerCertificate            [in] The certificate of the server. Must be the only certificate in the byte string.
 * @param pPKIConfig                    [in] The platform dependend pki configuration.
 * @param pRequestedSecurityPolicyUri   [in] The URI of the OPC UA security policy to use for this connection.
 * @param nRequestedLifetime            [in] The Lifetime of the connection.
 * @param messageSecurityMode           [in] The constant for None, Sign or SignAndEncrypt mode.
 * @param sAuditEntryId                 [in] The audit entry id the server shall use for the secure channel audit event.
 * @param nNetworkTimeout               [in] The network timeout. Also used for disconnect.
 * @param pfCallback                    [in] Function to call when connection is established.
 * @param pCallbackData                 [in] Data to pass to pfCallback.
 */
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Channel_BeginConnect(
    OpcUa_Channel                               pChannel,
    const OpcUa_CharA*                          sUrl,
    const OpcUa_CharA*                          sTransportProfileUri,
    OpcUa_ByteString*                           pClientCertificate,
    OpcUa_ByteString*                           pClientPrivateKey,
    OpcUa_ByteString*                           pServerCertificate,
    OpcUa_Void*                                 pPKIConfig,
    OpcUa_String*                               pRequestedSecurityPolicyUri,
    OpcUa_Int32                                 nRequestedLifetime,
    OpcUa_MessageSecurityMode                   messageSecurityMode,
    OpcUa_String*                               sAuditEntryId,
    OpcUa_UInt32                                nNetworkTimeout,
    OpcUa_Channel_PfnConnectionStateChanged*    pfCallback,
    OpcUa_Void*                                 pCallbackData);

/** 
 * @brief Closes the network connection with the server.
 *
 * @param pChannel [in] The session to disconnect.
 */
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Channel_Disconnect(OpcUa_Channel pChannel);

/** 
 * @brief Closes the network connection with the server asnchronously.
 *
 * @param pChannel      [in] The session to disconnect.
 * @param pfCallback    [in] Function to call when connection is closed.
 * @param pCallbackData [in] Data to pass to pfCallback.
 */
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Channel_BeginDisconnect(
    OpcUa_Channel                               pChannel,
    OpcUa_Channel_PfnConnectionStateChanged*    pfCallback,
    OpcUa_Void*                                 pCallbackData);

/** 
 * @brief Called by the stack to report an asynchronous request that completed. 
 *
 * @param pChannel         [in] The session used to send the request.
 * @param hAsyncState      [in] The async call state object.
 * @param pCallbackData    [in] The callback data specifed when the request was sent.
 */
typedef OpcUa_StatusCode (OpcUa_Channel_PfnRequestComplete)(
    OpcUa_Channel         hChannel,
    OpcUa_Void*           pResponse,
    OpcUa_EncodeableType* pResponseType,
    OpcUa_Void*           pCallbackData,
    OpcUa_StatusCode      uStatus);

/** 
 * @brief Invokes a service.
 *
 * @param pChannel       [in]  The session to use.
 * @param sName          [in]  The name of the service being invoked.
 * @param pRequest       [in]  The request body.
 * @param pRequestType   [in]  The type of request.
 * @param ppResponse     [out] The response body.
 * @param ppResponseType [out] The type of response.
 */
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Channel_InvokeService(
    OpcUa_Channel          hChannel,
    const OpcUa_CharA*     sName,
    OpcUa_Void*            pRequest,
    OpcUa_EncodeableType*  pRequestType,
    OpcUa_Void**           ppResponse,
    OpcUa_EncodeableType** ppResponseType);

/** 
 * @brief Invokes a service asynchronously.
 *
 * @param pChannel       [in]  The session to use.
 * @param sName          [in]  The name of the service being invoked.
 * @param pRequest       [in]  The request body.
 * @param pRequestType   [in]  The type of request.
 * @param pCallback      [in]  The callback to use when the response arrives.
 * @param pCallbackData  [in]  The data to pass to the callback.
 */
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Channel_BeginInvokeService(
    OpcUa_Channel                     hChannel,
    const OpcUa_CharA*                sName,
    OpcUa_Void*                       pRequest,
    OpcUa_EncodeableType*             pRequestType,
    OpcUa_Channel_PfnRequestComplete* pCallback,
    OpcUa_Void*                       pCallbackData);

#if OPCUA_SUPPORT_PREENCODED_MESSAGES
/** 
 * @brief Sends a message to the server.
 *
 * @param hChannel      [in]  The channel to use.
 * @param pRequest      [in]  The request data to send.
 * @param uTimeout      [in]  The callback to use when the response arrives.
 * @param pCallback     [in]  The callback to use when the response arrives.
 * @param pCallbackData [in]  The data to pass to the callback.
 */
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Channel_BeginSendEncodedRequest(  
    OpcUa_Channel                   hChannel,
    OpcUa_ByteString*               pRequest,
    OpcUa_UInt32                    uTimeout,
    OpcUa_Connection_PfnOnResponse* pCallback,
    OpcUa_Void*                     pCallbackData);
#endif

/*============================================================================
 * OpcUa_ProxyStub_SetNamespaceUris
 *===========================================================================*/
/** Set namespace URI table.
  * @param hChannel         [in]  The channel to use.
  * @param psNamespaceUris  [in] Array of pointers to namespace URIs with OpcUa_Null as last element.
  * @param bMakeCopy        [in] Copy strings instead of only referencing them.
  */
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Channel_SetNamespaceUris(
    OpcUa_Channel   hChannel,
    OpcUa_StringA*  psNamespaceUris,
    OpcUa_Boolean   bMakeCopy);

OPCUA_END_EXTERN_C

#endif /* OPCUA_HAVE_CLIENTAPI */
#endif /* _OpcUa_Channel_H_ */
