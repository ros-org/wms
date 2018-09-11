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

#ifndef _OpcUa_Thread_H_
#define _OpcUa_Thread_H_ 1

OPCUA_BEGIN_EXTERN_C

/*============================================================================
 * Type Definition
 *===========================================================================*/

/**
 * @brief Thread main entry function definition.
 */
typedef OpcUa_Void (OpcUa_PfnThreadMain)(OpcUa_Void* pArgument);

/**
 * @brief Describes a thread handle.
 */

/*============================================================================
 * Type Management
 *===========================================================================*/

/**
 * @brief Create a thread.
 *
 * @param ppThread [in/out] Pointer to the thread handle. Contains the created thread or OpcUa_Null.
 *
 * @return An error code for the operation.
 */
OPCUA_EXPORT 
OpcUa_StatusCode    OpcUa_Thread_Create(        OpcUa_Thread*        pThread,
                                                OpcUa_PfnThreadMain* pThreadMain,
                                                OpcUa_Void*          pThreadArgument);

/**
 * @brief Delete a thread.
 *
 * @param ppThread [in] Pointer to the thread handle.
 *
 * @return
 */
OPCUA_EXPORT 
OpcUa_Void          OpcUa_Thread_Delete(        OpcUa_Thread* pThread);


/*============================================================================
 * Type Operations
 *===========================================================================*/

/**
 * @brief Start a Thread.
 *
 * @param Thread [in] The thread handle.
 *
 * @return An error code for the operation.
 */
OPCUA_EXPORT 
OpcUa_StatusCode OpcUa_Thread_Start(            OpcUa_Thread   Thread);

/**
 * @brief Wait For Thread Shutdown.
 *
 * @param Thread        [in] The thread handle.
 * @param msecTimeout   [in] The maximum time to wait for shutdown.
 *
 * @return An error code for the operation.
 */
OPCUA_EXPORT 
OpcUa_StatusCode OpcUa_Thread_WaitForShutdown(  OpcUa_Thread   Thread, 
                                                OpcUa_UInt32    msecTimeout);


/**
 * @brief Lets the thread sleep for a certain amount of time.
 *
 * @param msecTimeout [in] The time in milliseconds to suspend the calling thread.
 */
OPCUA_EXPORT 
OpcUa_Void OpcUa_Thread_Sleep(                  OpcUa_UInt32    msecTimeout);

/**
 * @brief Get the ID of the current thread.
 *
 * @return The thread ID.
 */
OPCUA_EXPORT
OpcUa_UInt32 OpcUa_Thread_GetCurrentThreadId(void);

/**
 * @brief Check if the main function of the given thread object is running.
 *        State may have already changed when function returns!
 *
 * @return OpcUa_True if running, OpcUa_False else.
 */
OPCUA_EXPORT
OpcUa_Boolean OpcUa_Thread_IsRunning(           OpcUa_Thread    hThread);

OPCUA_END_EXTERN_C

#endif /* _OpcUa_Thread_H_ */
