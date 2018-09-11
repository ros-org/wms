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

#ifndef _OpcUa_DateTime_H_
#define _OpcUa_DateTime_H_ 1

OPCUA_BEGIN_EXTERN_C

/*============================================================================
 * Functions for OpcUa_DateTime
 *===========================================================================*/

/**
  @brief Convert a string to a date-time

  @return OpcUa_BadInvalidArgument if a_pchDateTimeString is null
  @return OpcUa_BadInvalidArgument if the string is incorrectly formatted
  @return OpcUa_Bad for other failures
  @return OpcUa_Good on success

  @param szDateTimeString  [in] String to convert
  @param pDateTime        [out] Location to store the date-time
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_DateTime_GetDateTimeFromString( const OpcUa_CharA*  szDateTimeString,
                                                                    OpcUa_DateTime*     pDateTime);

/**
  @brief Convert a date-time to a string

  @return OpcUa_BadInvalidArgument if buffer is null
  @return OpcUa_BadInvalidArgument if the buffer is too short
  @return OpcUa_Good on success

  @param DateTime   [in] Date-time to convert.
  @param pchBuffer  [bi] Byte buffer to store the result (at last 25 bytes long).
  @param uLength    [in] Length of the given buffer in bytes (at least 25).
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_DateTime_GetStringFromDateTime( const OpcUa_DateTime    DateTime,
                                                                    OpcUa_CharA*            pchBuffer,
                                                                    OpcUa_UInt32            uLength);


OPCUA_EXPORT OpcUa_DateTime   OPCUA_DLLCALL OpcUa_DateTime_UtcNow(void);

/*============================================================================
 * Functions for OpcUa_TimeVal
 *===========================================================================*/


/**
  @brief Get the time in OpcUa_TimeVal format

  @return OpcUa_BadInvalidArgument if pValue is null
  @return OpcUa_Good on success

  @param pValue     [out]   Location of an OpcUa_TimeVal to store the time of day
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_DateTime_GetTimeOfDay(OpcUa_TimeVal* pValue);


OPCUA_END_EXTERN_C

#endif /* _OpcUa_DateTime_H_ */
