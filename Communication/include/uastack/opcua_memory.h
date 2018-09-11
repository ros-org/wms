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

#ifndef _OpcUa_Memory_H_
#define _OpcUa_Memory_H_ 1

OPCUA_BEGIN_EXTERN_C

/** 
 * @brief Allocates a new block of memory.
 *
 * @param nSize [in] The size of the block to allocate.
*/
OPCUA_EXPORT OpcUa_Void* OPCUA_DLLCALL OpcUa_Memory_Alloc(OpcUa_UInt32 nSize);

/** 
 * @brief Reallocates a block of memory
 *
 * @param pBuffer [in] The existing memory block.
 * @param nSize   [in] The size of the block to allocate.
*/
OPCUA_EXPORT OpcUa_Void* OPCUA_DLLCALL OpcUa_Memory_ReAlloc(OpcUa_Void*  pBuffer, 
                                                            OpcUa_UInt32 nSize);

/** 
 * @brief Frees a block of memory.
 *
 * @param pvBuffer [in] The existing memory block.
*/
OPCUA_EXPORT OpcUa_Void OPCUA_DLLCALL OpcUa_Memory_Free(OpcUa_Void* pvBuffer);

/** 
 * @brief Copies a block of memory.
 *
 * @param pBuffer      [in] The destination memory block.
 * @param nSizeInBytes [in] The size of the destination memory block. 
 * @param pSource      [in] The memory block being copied.
 * @param nCount       [in] The number of bytes to copy.
 *
 * @return StatusCode:
 *   OpcUa_BadInvalidArgument if Buffer or Source equals OpcUa_Null;
 *   OpcUa_BadOutOfRange      if number of bytes to copy greater nSizeInBytes
*/
OPCUA_EXPORT OpcUa_StatusCode OPCUA_DLLCALL OpcUa_Memory_MemCpy(OpcUa_Void*         pBuffer,
                                                                OpcUa_UInt32        nSizeInBytes,
                                                                const OpcUa_Void*   pSource,
                                                                OpcUa_UInt32        nCount);

OPCUA_END_EXTERN_C

#endif /* _OpcUa_Memory_H_ */
