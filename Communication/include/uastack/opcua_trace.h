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

#ifndef _OpcUa_Trace_H_
#define _OpcUa_Trace_H_ 1

OPCUA_BEGIN_EXTERN_C

/*============================================================================
 * Trace Levels
 *===========================================================================*/
/* custom trace levels - add your trace levels here ... */
#define OPCUA_TRACE_LEVEL_YOURTRACELEVEL 0x00000040 
/* ... */

/* Predefined trace levels. */
/** Critical errors (unexpected and/or requiring external actions) which require attention. */
#define OPCUA_TRACE_LEVEL_ERROR         0x00000020
/** Non-critical faults which should not go unnoticed but are handled internally. */
#define OPCUA_TRACE_LEVEL_WARNING       0x00000010
/** Rare major events (good cases) like initializations, shutdowns, etc. */
#define OPCUA_TRACE_LEVEL_SYSTEM        0x00000008
/** Regular good case events like connects, renews. */
#define OPCUA_TRACE_LEVEL_INFO          0x00000004
/** Used for debugging purposes. */
#define OPCUA_TRACE_LEVEL_DEBUG         0x00000002
/** Used to add additional content (i.e. whole message bodies) to debug traces. */
#define OPCUA_TRACE_LEVEL_CONTENT       0x00000001

/* trace level packages */
#define OPCUA_TRACE_OUTPUT_LEVEL_ERROR   (OPCUA_TRACE_LEVEL_ERROR)
#define OPCUA_TRACE_OUTPUT_LEVEL_WARNING (OPCUA_TRACE_LEVEL_ERROR | OPCUA_TRACE_LEVEL_WARNING)
#define OPCUA_TRACE_OUTPUT_LEVEL_SYSTEM  (OPCUA_TRACE_LEVEL_ERROR | OPCUA_TRACE_LEVEL_WARNING | OPCUA_TRACE_LEVEL_SYSTEM)
#define OPCUA_TRACE_OUTPUT_LEVEL_INFO    (OPCUA_TRACE_LEVEL_ERROR | OPCUA_TRACE_LEVEL_WARNING | OPCUA_TRACE_LEVEL_SYSTEM | OPCUA_TRACE_LEVEL_INFO)
#define OPCUA_TRACE_OUTPUT_LEVEL_DEBUG   (OPCUA_TRACE_LEVEL_ERROR | OPCUA_TRACE_LEVEL_WARNING | OPCUA_TRACE_LEVEL_SYSTEM | OPCUA_TRACE_LEVEL_INFO | OPCUA_TRACE_LEVEL_DEBUG)
#define OPCUA_TRACE_OUTPUT_LEVEL_CONTENT (OPCUA_TRACE_LEVEL_ERROR | OPCUA_TRACE_LEVEL_WARNING | OPCUA_TRACE_LEVEL_SYSTEM | OPCUA_TRACE_LEVEL_INFO | OPCUA_TRACE_LEVEL_DEBUG | OPCUA_TRACE_LEVEL_CONTENT)
#define OPCUA_TRACE_OUTPUT_LEVEL_ALL     (0xFFFFFFFF)
#define OPCUA_TRACE_OUTPUT_LEVEL_NONE    (0x00000000)
/*============================================================================
 * Trace Initialize
 *===========================================================================*/
/**
* Initialize all resources needed for tracing.
*/
OPCUA_EXPORT OpcUa_StatusCode OPCUA_DLLCALL OpcUa_Trace_Initialize(void);

/*============================================================================
 * Trace Initialize
 *===========================================================================*/
/**
* Clear all resources needed for tracing.
*/
OPCUA_EXPORT OpcUa_Void OPCUA_DLLCALL OpcUa_Trace_Clear(void);

/*============================================================================
 * Change Trace Level
 *===========================================================================*/
/**
 * Activate or deactivate trace output during runtime.
 */
OPCUA_EXPORT OpcUa_Void OPCUA_DLLCALL OpcUa_Trace_ChangeTraceLevel(OpcUa_UInt32 a_uNewTraceLevel);

/*============================================================================
 * Get Trace Level
 *===========================================================================*/
/**
 * Query current trace level.
 */
OPCUA_EXPORT OpcUa_UInt32 OPCUA_DLLCALL OpcUa_Trace_GetTraceLevel(void);

/*============================================================================
 * Activate/Deactivate Trace 
 *===========================================================================*/
/**
 * Activate or deactivate trace output during runtime.
 */
OPCUA_EXPORT OpcUa_Void OPCUA_DLLCALL OpcUa_Trace_Toggle(OpcUa_Boolean a_bActive);

/*============================================================================
 * Tracefunction
 *===========================================================================*/
/**
* @brief Writes the given string and the parameters to the trace device, if the given 
* trace level is activated in the header file.
*
* @see OpcUa_P_Trace
*
* @return The number of bytes written to the trace device.
*/
#if OPCUA_TRACE_ENABLE
 #if OPCUA_TRACE_FILE_LINE_INFO
#define OpcUa_Trace(xLevel, xFormat, ...) OpcUa_Trace_Imp(xLevel, xFormat, __FILE__, __LINE__, ##__VA_ARGS__)
 #else /* OPCUA_TRACE_FILE_LINE_INFO */
  #define OpcUa_Trace OpcUa_Trace_Imp
 #endif /* OPCUA_TRACE_FILE_LINE_INFO */
#else /* OPCUA_TRACE_ENABLE */
 #define OpcUa_Trace(xLevel, xFormat, ...) 
#endif /* OPCUA_TRACE_ENABLE */

OPCUA_EXPORT OpcUa_Boolean OPCUA_DLLCALL OpcUa_Trace_Imp( 
    OpcUa_UInt32        uTraceLevel,
    const OpcUa_CharA*  sFormat,
#if OPCUA_TRACE_FILE_LINE_INFO
    const OpcUa_CharA*  sFile,
    OpcUa_UInt32        sLine,
#endif /* OPCUA_TRACE_FILE_LINE_INFO */
                        ...);

OPCUA_END_EXTERN_C

#endif /* _OpcUa_Trace_H_ */
