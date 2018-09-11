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

#ifndef _OpcUa_ProxyStub_H_
#define _OpcUa_ProxyStub_H_ 1

#include "opcua_platformdefs.h"
#include "opcua_crypto.h"
#include "opcua_pki.h"
#include "opcua_p_interface.h"
#include "opcua_errorhandling.h"
#include "opcua_statuscodes.h"
#include "opcua_stackstatuscodes.h"

#include "opcua_identifiers.h"
#include "opcua_builtintypes.h"
#include "opcua_encodeableobject.h"
#include "opcua_types.h"
#include "opcua_browsenames.h"
#include "opcua_attributes.h"

OPCUA_BEGIN_EXTERN_C

/* TransportProfiles */
#define OpcUa_TransportProfile_UaTcp            "http://opcfoundation.org/UA-Profile/Transport/uatcp-uasc-uabinary"
#define OpcUa_TransportProfile_SoapHttpBinary   "http://opcfoundation.org/UA-Profile/Transport/http-uasc-uabinary"
#define OpcUa_TransportProfile_HttpsBinary      "http://opcfoundation.org/UA-Profile/Transport/https-uabinary"
#define OpcUa_TransportProfile_HttpsSoapBinary  "http://opcfoundation.org/UA-Profile/Transport/https-uasoapxml-uabinary"

/** Holds the runtime configuration values for the proxy stub modules.  
    There may be some interference with the endpoint configuration at this time. 
    Negative numeric values mean to use default values. */
typedef struct _OpcUa_ProxyStubConfiguration
{
    /** Globally enable/disable trace output from the stack (exclude platformlayer) */
    OpcUa_Boolean   bProxyStub_Trace_Enabled;
    /** Configure the level of messages traced. See config.h for values. */
    OpcUa_UInt32    uProxyStub_Trace_Level;

    /** Security constraints for the serializer. Set this values carefully. */
    /** The largest size for a memory block the serializer can do when deserializing a message. */
    OpcUa_Int32     iSerializer_MaxAlloc;
    /** The largest string accepted by the serializer. */
    OpcUa_Int32     iSerializer_MaxStringLength;
    /** The largest byte string accepted by the serializer. */
    OpcUa_Int32     iSerializer_MaxByteStringLength;
    /** Maximum number of elements in an array accepted by the serializer. */
    OpcUa_Int32     iSerializer_MaxArrayLength;
    /** The maximum number of bytes per message in total. */
    OpcUa_Int32     iSerializer_MaxMessageSize;

    /** Be careful! Enabling the threadpool has severe implications on the behavior of your server! */
    /** Controls wether the secure listener uses a thread pool to dispatch received requests. */
    OpcUa_Boolean   bSecureListener_ThreadPool_Enabled;
    /** The minimum number of threads in the thread pool. */
    OpcUa_Int32     iSecureListener_ThreadPool_MinThreads;
    /** The maximum number of threads in the thread pool */
    OpcUa_Int32     iSecureListener_ThreadPool_MaxThreads;
    /** The length of the queue with jobs waiting for a free thread. */
    OpcUa_Int32     iSecureListener_ThreadPool_MaxJobs;
    /** If MaxJobs is reached the add operation can block or return an error. */
    OpcUa_Boolean   bSecureListener_ThreadPool_BlockOnAdd;
    /** If the add operation blocks on a full job queue, this value sets the max waiting time. */
    OpcUa_UInt32    uSecureListener_ThreadPool_Timeout;

    /** The minimum revised lifetime of a secure channel security token in milliseconds. */
    OpcUa_Int32     iSecureConnection_MinRevisedSecureChannelLifetime;
    /** The maximum revised lifetime of a secure channel security token in milliseconds. */
    OpcUa_Int32     iSecureConnection_MaxRevisedSecureChannelLifetime;

    /** If true, the TcpListener request a thread per client from the underlying socketmanager. Must not work with all platform layers. */
    OpcUa_Boolean   bTcpListener_ClientThreadsEnabled;
    /** The default and maximum size for message chunks in the server. Affects network performance and memory usage. */
    OpcUa_Int32     iTcpListener_DefaultChunkSize;

    /** The default (and requested) size for message chunks. Affects network performance and memory usage. */
    OpcUa_Int32     iTcpConnection_DefaultChunkSize;

    /** The default and maximum size for messages. Affects memory usage. */
    OpcUa_Int32     iTcpTransport_MaxMessageLength;
    /** The default and maximum number of message chunks per message. Affects memory usage. */
    OpcUa_Int32     iTcpTransport_MaxChunkCount;

    /** The network stream should block if not all could be send in one go. Be careful and use this only with client threads. Must not work with all platform layers. */
    OpcUa_Boolean   bTcpStream_ExpectWriteToBlock;
} OpcUa_ProxyStubConfiguration;

/*============================================================================
 * OpcUa_ProxyStub_Initialize
 *===========================================================================*/
/** Initialize proxy stub library. */
#if !OPCUA_USE_STATIC_PLATFORM_INTERFACE
OPCUA_EXPORT OpcUa_StatusCode OPCUA_DLLCALL OpcUa_ProxyStub_Initialize( OpcUa_Handle                    pPortLayerHandle,
                                                                        OpcUa_ProxyStubConfiguration*   pProxyStubConfiguration);
#else /* !OPCUA_USE_STATIC_PLATFORM_INTERFACE */
OPCUA_EXPORT OpcUa_StatusCode OPCUA_DLLCALL OpcUa_ProxyStub_Initialize( OpcUa_ProxyStubConfiguration*   pProxyStubConfiguration);
#endif /* !OPCUA_USE_STATIC_PLATFORM_INTERFACE */

/*============================================================================
 * OpcUa_ProxyStub_Initialize
 *===========================================================================*/
/** Initialize structure only. */
OPCUA_EXPORT OpcUa_StatusCode OPCUA_DLLCALL OpcUa_ProxyStub_InitConfiguration(OpcUa_ProxyStubConfiguration* a_pProxyStubConfiguration);

/*============================================================================
 * OpcUa_ProxyStub_ReInitialize
 *===========================================================================*/
/** Set a new proxy stub configuration. Not thread-safe! */
OPCUA_EXPORT OpcUa_StatusCode OPCUA_DLLCALL OpcUa_ProxyStub_ReInitialize( OpcUa_ProxyStubConfiguration*   pProxyStubConfiguration);

/*============================================================================
 * OpcUa_ProxyStub_GetConfiguration
 *===========================================================================*/
/** Get pointer to proxy stub configuration. Read only! */
OPCUA_EXPORT OpcUa_StatusCode OPCUA_DLLCALL OpcUa_ProxyStub_GetConfiguration( OpcUa_ProxyStubConfiguration**   ppProxyStubConfiguration);

/*============================================================================
 * OpcUa_ProxyStub_Clear
 *===========================================================================*/
/** Clean up proxy stub library. */
OPCUA_EXPORT OpcUa_Void OPCUA_DLLCALL OpcUa_ProxyStub_Clear(void);

/*============================================================================
 * OpcUa_ProxyStub_AddTypes
 *===========================================================================*/
/** Add additional types to the known types table.
  * @param ppTypes [in] Array of pointers to vendor types with OpcUa_Null as last element.
  */
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ProxyStub_AddTypes(OpcUa_EncodeableType** ppTypes);

/*============================================================================
 * OpcUa_ProxyStub_SetNamespaceUris
 *===========================================================================*/
/** Set namespace URI table.
  * @param a_psNamespaceUris [in] Array of pointers to namespace URIs with OpcUa_Null as last element.
  * @param a_bMakeCopy       [in] Copy strings instead of only referencing them.
  */
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ProxyStub_SetNamespaceUris(OpcUa_StringA* a_psNamespaceUris,
                                                               OpcUa_Boolean  a_bMakeCopy);

/*============================================================================
 * OpcUa_ProxyStub_GetVersion
 *===========================================================================*/
/** Request the version string of the proxy stub.
  * @return Pointer to a static buffer containing the version information in string format. Must not be freed!
  */
OPCUA_EXPORT const OpcUa_CharA* OPCUA_DLLCALL OpcUa_ProxyStub_GetVersion(void);

/*============================================================================
 * OpcUa_ProxyStub_GetConfigString
 *===========================================================================*/
/** Request the string encoded configuration table.
  * @return Pointer to a buffer containing the configuration string. Must not be freed!
  */
OPCUA_EXPORT const OpcUa_CharA* OPCUA_DLLCALL OpcUa_ProxyStub_GetConfigString(void);

/*============================================================================
 * OpcUa_ProxyStub_GetStaticConfigString
 *===========================================================================*/
/** Request the string encoded built configuration of the stack.
  * @return Pointer to a static string containing the options set by compiler switches. Must not be freed!
  */
OPCUA_EXPORT const OpcUa_CharA* OPCUA_DLLCALL OpcUa_ProxyStub_GetStaticConfigString(void);

OPCUA_END_EXTERN_C
#endif /* _OpcUa_ProxyStub_H_ */
