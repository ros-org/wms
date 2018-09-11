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

#ifndef _OpcUa_StackStatusCodes_H_
#define _OpcUa_StackStatusCodes_H_ 1

OPCUA_BEGIN_EXTERN_C

/*============================================================================
 * Begin of status codes internal to the stack.
 *===========================================================================*/
#define OpcUa_StartOfStackStatusCodes 0x81000000

/*============================================================================
 * The message signature is invalid.
 *===========================================================================*/
#define OpcUa_BadSignatureInvalid 0x81010000

/*============================================================================
 * The extensible parameter provided is not a valid for the service.
 *===========================================================================*/
#define OpcUa_BadExtensibleParameterInvalid 0x81040000

/*============================================================================
 * The extensible parameter provided is valid but the server does not support it.
 *===========================================================================*/
#define OpcUa_BadExtensibleParameterUnsupported 0x81050000

/*============================================================================
 * The hostname could not be resolved.
 *===========================================================================*/
#define OpcUa_BadHostUnknown 0x81060000

/*============================================================================
 * Too many posts were made to a semaphore.
 *===========================================================================*/
#define OpcUa_BadTooManyPosts 0x81070000

/*============================================================================
 * The security configuration is not valid.
 *===========================================================================*/
#define OpcUa_BadSecurityConfig 0x81080000

/*============================================================================
 * Invalid file name specified.
 *===========================================================================*/
#define OpcUa_BadFileNotFound 0x81090000

/*============================================================================
 * Accept bad result and continue anyway.
 *===========================================================================*/
#define OpcUa_BadContinue 0x810A0000

/*============================================================================
 * Accept bad result and continue anyway.
 *===========================================================================*/
#define OpcUa_BadHttpMethodNotAllowed 0x810B0000

/*============================================================================
 * File exists.
 *===========================================================================*/
#define OpcUa_BadFileExists 0x810C0000

OPCUA_END_EXTERN_C

#endif /* _OpcUa_StackStatusCodes_H_ */
