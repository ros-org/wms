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

#ifndef _OpcUa_Connection_H_
#define _OpcUa_Connection_H_ 1

#include <opcua_socket.h>
#include <opcua_stream.h>
#include <opcua_credentials.h>

OPCUA_BEGIN_EXTERN_C

typedef struct _OpcUa_Connection OpcUa_Connection;

/** 
  @brief The types of events that could be reported by a connection.
*/
typedef enum _OpcUa_ConnectionEvent
{
    /** @brief The failsafe event. */
    OpcUa_ConnectionEvent_Invalid,

    /** @brief The connection is now connected and is ready for use. */
    OpcUa_ConnectionEvent_Connect,

    /** @brief The connection was lost and is now trying to reestablish itself. */
    OpcUa_ConnectionEvent_Reconnecting,

    /** @brief The connection is now disconnected. */
    OpcUa_ConnectionEvent_Disconnect,

    /** @brief The connection has data ready for reading. */
    OpcUa_ConnectionEvent_Response,

    /** @brief The connection has data ready for reading. */
    OpcUa_ConnectionEvent_ResponsePartial,

    /** @brief A message currently being received was aborted. */
    OpcUa_ConnectionEvent_ResponseAbort,

    /** @brief A message currently being sent was finished. */
    OpcUa_ConnectionEvent_AsyncWriteComplete,

    /** @brief An unexpected error occurred and the connection is no longer useable. */
    OpcUa_ConnectionEvent_UnexpectedError,

    /** @brief The connection was lost and is now trying to reestablish itself. */
    OpcUa_ConnectionEvent_Renew,

    /** @brief Request to validate certificate. */
    OpcUa_ConnectionEvent_VerifyCertificate
}
OpcUa_ConnectionEvent;


/** 
  @brief Called by the connection to report the status of the connection.
 
  This method is called when the connection is ready for use or when the connection 
  closes (normally or unexpectedly). 

  @param connection     [in] The connection.
  @param callbackData   [in] The callback data specifed in the Connect call.
  @param eEvent         [in] The type of event that occured.
  @param ppIstrm        [in] A stream that must be used to read the response.
  @param pCertificate   [in] DER encode certificate.
  @param uStatus        [in] The uStatus associated with the connection.
*/
typedef OpcUa_StatusCode (OpcUa_Connection_PfnOnNotify)(
    OpcUa_Connection*         pConnection,
    OpcUa_Void*               pCallbackData,
    OpcUa_ConnectionEvent     eEvent,
    OpcUa_InputStream**       ppIstrm,
    OpcUa_ByteString*         pCertificate,
    OpcUa_StatusCode          uStatus);

/** 
  @brief Called by the connection when a response arrives.

  @param pConnection    [in] The connection.
  @param pCallbackData  [in] The callback data specifed in the EndSendRequest call.
  @param uRequestStatus [in] The uStatus associated with the request.
  @param ppIstrm        [in] A stream that must be used to read the response.
*/
typedef OpcUa_StatusCode (OpcUa_Connection_PfnOnResponse)(
    OpcUa_Connection*         pConnection,
    OpcUa_Void*               pCallbackData,
    OpcUa_StatusCode          uRequestStatus,
    OpcUa_InputStream**       ppIstrm);


/** 
  @brief Asynchronously connects to the server.
 
  @param pConnection   [in] The connection to connect.
  @param sUrl          [in] URL of the server to connect to.
  @param pCredentials  [in] The network credentials to use.
  @param uTimeout      [in] The timeout in milliseconds for blocking operations (zero is infinite).
  @param pCallback     [in] The callback to use when the connection is ready.
  @param pCallbackData [in] The data to return with the callback.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Connection_Connect(
    OpcUa_Connection*               pConnection,
    OpcUa_String*                   sUrl,
    OpcUa_ClientCredential*         pCredentials,
    OpcUa_UInt32                    uTimeout,
    OpcUa_Connection_PfnOnNotify*   pCallback,
    OpcUa_Void*                     pCallbackData);

typedef OpcUa_StatusCode (OpcUa_Connection_PfnConnect)(
    OpcUa_Connection*               pConnection,
    OpcUa_String*                   sUrl,
    OpcUa_ClientCredential*         pCredential,
    OpcUa_UInt32                    uTimeout,
    OpcUa_Connection_PfnOnNotify*   pCallback,
    OpcUa_Void*                     pCallbackData);

/** 
  @brief Closes a connection an releases all resources allocated to it.

  The callback passed to the connect method is called when the disconnect completes.
 
  @param pConnection       [in] The connection to disconnect.
  @param bNotifyOnComplete [in] Whether raised an event when the disconnect completes.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Connection_Disconnect(
    OpcUa_Connection*         pConnection,
    OpcUa_Boolean             bNotifyOnComplete);

typedef OpcUa_StatusCode (OpcUa_Connection_PfnDisconnect)(
    OpcUa_Connection*         pConnection,
    OpcUa_Boolean             bNotifyOnComplete);

/** 
  @brief Creates a stream to write a message to a connection.
 
  The caller is responsible for calling Delete on the returned stream.

  @param pConnection [in]  The connection.
  @param ppOstrm     [out] The output stream.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Connection_BeginSendRequest(
    OpcUa_Connection*         pConnection,
    OpcUa_OutputStream**      ppOstrm);

typedef OpcUa_StatusCode (OpcUa_Connection_PfnBeginSendRequest)(
    OpcUa_Connection*         pConnection,
    OpcUa_OutputStream**      ppOstrm);

/** 
  @brief Tells the connection that the message is complete and it can be sent.
  
  @param pConnection   [in] The connection.
  @param ppOstrm       [in] The output stream. Gets nulled on completion.
  @param uTimeout      [in] The timeout for finishing the send operation in milliseconds.
  @param pCallback     [in] The callback to use when the response arrives.
  @param pCallbackData [in] The data to return with the callback.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Connection_EndSendRequest(
    OpcUa_Connection*               pConnection,
    OpcUa_OutputStream**            ppOstrm,
    OpcUa_UInt32                    uTimeout,
    OpcUa_Connection_PfnOnResponse* pCallback,
    OpcUa_Void*                     pCallbackData);

typedef OpcUa_StatusCode (OpcUa_Connection_PfnEndSendRequest)(
    OpcUa_Connection*               pConnection,
    OpcUa_OutputStream**            ppOstrm,
    OpcUa_UInt32                    uTimeout,
    OpcUa_Connection_PfnOnResponse* pCallback,
    OpcUa_Void*                     pCallbackData);

/** 
  @brief Aborts the a request that was partialy sent to the server.
  
  @param pConnection [in] The connection.
  @param uStatus     [in] The numeric code for the error.
  @param sReason     [in] The reason for the error.
  @param pOstrm      [in] The output stream.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Connection_AbortSendRequest(
    OpcUa_Connection*         pConnection,
    OpcUa_StatusCode          uStatus,
    OpcUa_String*             sReason,
    OpcUa_OutputStream**      pOstrm);

typedef OpcUa_StatusCode (OpcUa_Connection_PfnAbortSendRequest)(
    OpcUa_Connection*         pConnection,
    OpcUa_StatusCode          uStatus,
    OpcUa_String*             sReason,
    OpcUa_OutputStream**      pOstrm);


/** 
  @brief Retrive the recieve buffer size of a particular connection.
  
  @param pConnection [in] The connection.
  @param pBufferSize [in] Pointer to OpcUa_UInt32 for storing the buffer size.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Connection_GetReceiveBufferSize(
    OpcUa_Connection*         pConnection,
    OpcUa_UInt32*             pBufferSize);

typedef OpcUa_StatusCode (OpcUa_Connection_PfnGetReceiveBufferSize)(
    OpcUa_Connection*         pConnection,
    OpcUa_UInt32*             pBufferSize);


/** 
  @brief Frees the connection structure.
 
  @param connection [in] The connection.
*/
OPCUA_EXPORT OpcUa_Void OpcUa_Connection_Delete(OpcUa_Connection** connection);

typedef OpcUa_Void (OpcUa_Connection_PfnDelete)(OpcUa_Connection** connection);


/**
  @brief Forward a buffer list to the transport for sending.

  @param pConnection [in] The connection.
  @param pBufferList [in] Pointer to a list of send buffers.
  @param uFlags      [in] operation flags.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Connection_AddToSendQueue(
    OpcUa_Connection*         pConnection,
    OpcUa_BufferListElement*  pBufferList,
    OpcUa_UInt32              uFlags);

typedef OpcUa_StatusCode (OpcUa_Connection_PfnAddToSendQueue)(
    OpcUa_Connection*         pConnection,
    OpcUa_BufferListElement*  pBufferList,
    OpcUa_UInt32              uFlags);


/** 
  @brief A generic connection to a server.
*/
struct _OpcUa_Connection
{
    /*! @brief An opaque handle that contain data specific to the connection implementation. */
    OpcUa_Handle Handle;

    /*! @brief The string identifing the endpoint for this connection. */
    OpcUa_String Endpoint;
    
    /*! @brief Connects to a server. */
    OpcUa_Connection_PfnConnect* Connect;
    
    /*! @brief Closes the connection. */
    OpcUa_Connection_PfnDisconnect* Disconnect;

    /*! @brief Begins writing an outgoing message. */
    OpcUa_Connection_PfnBeginSendRequest* BeginSendRequest;
    
    /*! @brief Finishes writing an outgoing message. */
    OpcUa_Connection_PfnEndSendRequest* EndSendRequest;

    /*! @brief Aborts writing an outgoing message. */
    OpcUa_Connection_PfnAbortSendRequest* AbortSendRequest;

    /*! @brief Retrive the recieve buffer size of a particular connection. */
    OpcUa_Connection_PfnGetReceiveBufferSize* GetReceiveBufferSize;

    /*! @brief Frees the structure. */
    OpcUa_Connection_PfnDelete* Delete;

    /*! @brief Retrive the recieve buffer size of a particular connection. */
    OpcUa_Connection_PfnAddToSendQueue* AddToSendQueue;
};

OPCUA_END_EXTERN_C

#endif /* _OpcUa_Connection_H_ */
