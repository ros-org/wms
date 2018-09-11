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

#ifndef _OpcUa_Utilities_H_
#define _OpcUa_Utilities_H_ 1

#include <opcua_platformdefs.h>

OPCUA_BEGIN_EXTERN_C

enum _OpcUa_ProtocolType
{
    OpcUa_ProtocolType_Invalid,
    OpcUa_ProtocolType_Http,
    OpcUa_ProtocolType_Tcp
};
typedef enum _OpcUa_ProtocolType OpcUa_ProtocolType;

/** 
 * @brief Sorts an array.
 *
 * @param pElements     [in] The array of elements to sort.
 * @param nElementCount [in] The number of elements in the array.
 * @param nElementSize  [in] The size a single element in the array.
 * @param pfnCompare    [in] The function used to compare elements.
 * @param pContext      [in] A context that is passed to the compare function.
 */
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_QSort(   OpcUa_Void*       pElements, 
                                OpcUa_UInt32      nElementCount, 
                                OpcUa_UInt32      nElementSize, 
                                OpcUa_PfnCompare* pfnCompare, 
                                OpcUa_Void*       pContext);

/** 
 * @brief Searches a sorted array.
 *
 * @param pKey          [in] The element to find.
 * @param pElements     [in] The array of elements to sort.
 * @param nElementCount [in] The number of elements in the array.
 * @param nElementSize  [in] The size a single element in the array.
 * @param pfnCompare    [in] The function used to compare elements.
 * @param pContext      [in] A context that is passed to the compare function.
 */
OPCUA_EXPORT
OpcUa_Void* OpcUa_BSearch(  OpcUa_Void*       pKey,
                            OpcUa_Void*       pElements, 
                            OpcUa_UInt32      nElementCount, 
                            OpcUa_UInt32      nElementSize, 
                            OpcUa_PfnCompare* pfnCompare, 
                            OpcUa_Void*       pContext);

/** 
 * @brief Returns the CRT errno constant.
 */
OPCUA_EXPORT
OpcUa_UInt32 OpcUa_GetLastError(void);

/** 
 * @brief Returns the number of milliseconds since the system or process was started.
 */
OPCUA_EXPORT
OpcUa_UInt32 OpcUa_GetTickCount(void);


OPCUA_END_EXTERN_C

#endif /* _OpcUa_Utilities_H_ */
