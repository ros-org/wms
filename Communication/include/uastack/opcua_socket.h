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

#ifndef _OpcUa_Socket_H_
#define _OpcUa_Socket_H_ 1

OPCUA_BEGIN_EXTERN_C

OPCUA_EXPORT OpcUa_StatusCode OPCUA_DLLCALL OpcUa_SocketManager_Create( OpcUa_SocketManager*  ppSocketManager,
                                                                        OpcUa_UInt32          nSockets,
                                                                        OpcUa_UInt32          uintFlags);

OPCUA_EXPORT OpcUa_Void OPCUA_DLLCALL OpcUa_SocketManager_Delete(       OpcUa_SocketManager* pSocketManager);

OPCUA_EXPORT OpcUa_StatusCode OPCUA_DLLCALL OpcUa_SocketManager_CreateServer(   OpcUa_SocketManager         pSocketManager,
                                                                                const OpcUa_CharA*          LocalAdress,
                                                                                OpcUa_ByteString*           pServerCertificate,
                                                                                OpcUa_Key*                  pServerPrivateKey,
                                                                                OpcUa_Void*                 pPKIConfig,
                                                                                OpcUa_Socket_EventCallback  pfnSocketCallBack,
                                                                                OpcUa_Void*                 pCookie,
                                                                                OpcUa_Socket*               ppSocket);


OPCUA_EXPORT OpcUa_StatusCode OPCUA_DLLCALL OpcUa_SocketManager_CreateClient(   OpcUa_SocketManager                 pSocketManager,
                                                                                const OpcUa_CharA*                  RemoteAdress,
                                                                                OpcUa_UInt16                        LocalPort,
                                                                                OpcUa_ByteString*                   pClientCertificate,
                                                                                OpcUa_Key*                          pClientPrivateKey,
                                                                                OpcUa_Void*                         pPKIConfig,
                                                                                OpcUa_Socket_EventCallback          pfnSocketCallBack,
                                                                                OpcUa_Socket_CertificateCallback    pfnCertificateCallback,
                                                                                OpcUa_Void*                         pCookie,
                                                                                OpcUa_Socket*                       ppSocket);

OPCUA_EXPORT OpcUa_StatusCode OPCUA_DLLCALL OpcUa_Socket_Close(         OpcUa_Socket                pSocket);

OPCUA_EXPORT OpcUa_StatusCode OPCUA_DLLCALL OpcUa_Socket_Read(          OpcUa_Socket                pSocket,
                                                                        OpcUa_Byte*                 pBuffer,
                                                                        OpcUa_UInt32                BufferSize,
                                                                        OpcUa_UInt32*               puintBytesRead);

OPCUA_EXPORT OpcUa_Int32      OPCUA_DLLCALL OpcUa_Socket_Write(         OpcUa_Socket                pSocket,
                                                                        OpcUa_Byte*                 pBuffer,
                                                                        OpcUa_UInt32                BufferSize,
                                                                        OpcUa_Boolean               bBlock);

OPCUA_EXPORT OpcUa_StatusCode OPCUA_DLLCALL OpcUa_SocketManager_Loop(   OpcUa_SocketManager pSocketManager,
                                                                        OpcUa_UInt32        msecTimeout,
                                                                        OpcUa_Boolean       bRunOnce);

OPCUA_EXPORT OpcUa_StatusCode OPCUA_DLLCALL OpcUa_SocketManager_SignalEvent(OpcUa_SocketManager pSocketManager,
                                                                        OpcUa_UInt32        uintEvent,
                                                                        OpcUa_Boolean       bAllLists);

OPCUA_EXPORT OpcUa_StatusCode OPCUA_DLLCALL OpcUa_SocketManager_AddSocket(OpcUa_SocketManager        hSocketManager,
                                                                          OpcUa_RawSocket            hRawSocket,
                                                                          OpcUa_Boolean              bIsClient,
                                                                          OpcUa_ByteString*          pClientCertificate,
                                                                          OpcUa_Key*                 pClientPrivateKey,
                                                                          OpcUa_Void*                pPKIConfig,
                                                                          OpcUa_Socket_EventCallback pfnSocketCallBack,
                                                                          OpcUa_Void*                pCallbackData,
                                                                          OpcUa_Socket*              ppSocket);

OPCUA_END_EXTERN_C

#endif /* _OpcUa_Socket_H_ */
