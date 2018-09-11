/******************************************************************************
** uaplatformlayer.h
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
** Project: C++ OPC SDK base module
**
** UA Stack Platform layer handling class.
**
******************************************************************************/
#ifndef UAPLATFORMLAYER_H
#define UAPLATFORMLAYER_H

#include "uaplatformdefs.h"
#include "opcua_proxystub.h"

/** @ingroup CppBaseLibraryClass
 *  @brief Platform layer handling class.
 */
class UABASE_EXPORT UaPlatformLayer
{
public:

    static int init();
    static int reInitConfig();
    static void cleanup();
    static void lockConfig(OpcUa_Boolean lockState);

    static void changeTraceSettings(
        OpcUa_Boolean bTraceEnabled,
        OpcUa_UInt32  uTraceLevel);

    static void changeSerializerSettings(
        OpcUa_Int32     iMaxAlloc,
        OpcUa_Int32     iMaxStringLength,
        OpcUa_Int32     iMaxByteStringLength,
        OpcUa_Int32     iMaxArrayLength,
        OpcUa_Int32     iMaxMessageSize);

    static void changeThreadPoolSettings(
        OpcUa_Boolean   bEnabled,
        OpcUa_Int32     iMinThreads,
        OpcUa_Int32     iMaxThreads,
        OpcUa_Int32     iMaxJobs,
        OpcUa_Boolean   bBlockOnAdd,
        OpcUa_UInt32    nTimeout);

    static void changeTransportSettings(
        OpcUa_Boolean bTcpListener_ClientThreadsEnabled,
        OpcUa_Int32   iTcpListener_DefaultChunkSize,
        OpcUa_Int32   iTcpConnection_DefaultChunkSize,
        OpcUa_Int32   iTcpTransport_MaxMessageLength,
        OpcUa_Int32   iTcpTransport_MaxChunkCount);

    static void changeSecureConnectionSettings(
        OpcUa_Int32   iSecureConnection_MinRevisedSecureChannelLifetime,
        OpcUa_Int32   iSecureConnection_MaxRevisedSecureChannelLifetime);

    /********** Getter for Serializer settings *************************************/
    /** Get the current maxMessageSize setting for the serializer. */
    static OpcUa_UInt32 nMaxMessageSize() { return s_nMaxMessageSize; }
    /** Get the current maxArrayLength setting for the serializer. */
    static OpcUa_UInt32 nMaxArrayLength() { return s_nMaxArrayLength; }
    /** Get the current maxByteStringLength setting for the serializer. */
    static OpcUa_UInt32 nMaxByteStringLength() { return s_nMaxByteStringLength; }
    /** Get the current maxStringLength setting for the serializer. */
    static OpcUa_UInt32 nMaxStringLength() { return s_nMaxStringLength; }
    /** Get the largest size for a memory block the serializer can do when deserializing a message. */
    static OpcUa_UInt32 nMaxAlloc() { return s_nMaxAlloc; }

    /********** Getter for Tcp Transport settings **********************************/
    /** The default and maximum size for message chunks in the server. */
    static OpcUa_UInt32 nListenerDefaultChunkSize() { return s_nListenerDefaultChunkSize; }
    /** The default and maximum size for message chunks in the client. */
    static OpcUa_UInt32 nConnectionDefaultChunkSize() { return s_nConnectionDefaultChunkSize; }
    /** The default and maximum number of message chunks per message. Affects memory usage. */
    static OpcUa_UInt32 nMaxChunkCount() { return s_nMaxChunkCount; }
    /** The default and maximum size for messages. Affects memory usage. */
    static OpcUa_UInt32 nTcpMaxMessageLength() { return s_nTcpMaxMessageLength; }
    /** If true, the TcpListener request a thread per client from the underlying socketmanager. Must not work with all platform layers. */
    static OpcUa_Boolean bClientThreadsEnabled() { return s_bClientThreadsEnabled; }

    /********** Getter for ThreadPool settings *************************************/
    /** Controls wether the secure listener uses a thread pool to dispatch received requests. */
    static OpcUa_Boolean bThreadPoolEnabled() { return s_bThreadPoolEnabled; }
    /** The minimum number of threads in the thread pool. */
    static OpcUa_UInt32 nThreadPoolMinThreads() { return s_ProxyStubConfiguration.iSecureListener_ThreadPool_MinThreads; }
    /** The maximum number of threads in the thread pool */
    static OpcUa_UInt32 nThreadPoolMaxThreads() { return s_nThreadPoolMaxThreads; }
    /** The length of the queue with jobs waiting for a free thread. */
    static OpcUa_UInt32 nThreadPoolMaxJobs() { return s_nThreadPoolMaxJobs; }
    /** If MaxJobs is reached the add operation can block or return an error. */
    static OpcUa_Boolean bThreadPoolBlockOnAdd() { return s_bThreadPoolBlockOnAdd; }
    /** If the add operation blocks on a full job queue, this value sets the max waiting time. */
    static OpcUa_UInt32 nThreadPoolTimeout() { return s_nThreadPoolTimeout; }

    /********** Getter for SecureChannel settings **********************************/
    /** The minimum revised lifetime of a secure channel security token in milliseconds. */
    static OpcUa_UInt32 nMinSecureChannelLifetime() { return s_nMinSecureChannelLifetime; }
    /** The maximum revised lifetime of a secure channel security token in milliseconds. */
    static OpcUa_UInt32 nMaxSecureChannelLifetime() { return s_nMaxSecureChannelLifetime; }

private:
    static void configInit();

    // Serializer settings
    static OpcUa_UInt32                 s_nMaxMessageSize;
    static OpcUa_UInt32                 s_nMaxArrayLength;
    static OpcUa_UInt32                 s_nMaxByteStringLength;
    static OpcUa_UInt32                 s_nMaxStringLength;
    static OpcUa_UInt32                 s_nMaxAlloc;
    // Tcp Transport settings
    static OpcUa_UInt32                 s_nListenerDefaultChunkSize;
    static OpcUa_UInt32                 s_nConnectionDefaultChunkSize;
    static OpcUa_UInt32                 s_nMaxChunkCount;
    static OpcUa_UInt32                 s_nTcpMaxMessageLength;
    static OpcUa_Boolean                s_bClientThreadsEnabled;
    // ThreadPool settings
    static OpcUa_Boolean                s_bThreadPoolEnabled;
    static OpcUa_UInt32                 s_nThreadPoolMinThreads;
    static OpcUa_UInt32                 s_nThreadPoolMaxThreads;
    static OpcUa_UInt32                 s_nThreadPoolMaxJobs;
    static OpcUa_Boolean                s_bThreadPoolBlockOnAdd;
    static OpcUa_UInt32                 s_nThreadPoolTimeout;
    // SecureChannel settings
    static OpcUa_UInt32                 s_nMinSecureChannelLifetime;
    static OpcUa_UInt32                 s_nMaxSecureChannelLifetime;

    static OpcUa_ProxyStubConfiguration s_ProxyStubConfiguration;
    static OpcUa_Boolean                s_isConfigInit;
    static OpcUa_UInt32                 s_initCounter;
    static OpcUa_Boolean                s_isConfigLocked;
};

#endif /* UAPLATFORMLAYER_H */


