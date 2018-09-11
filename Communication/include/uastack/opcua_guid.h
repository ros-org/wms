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

#ifndef _OpcUa_Guid_H_
#define _OpcUa_Guid_H_ 1

OPCUA_BEGIN_EXTERN_C

/*============================================================================
 * Defines
 *===========================================================================*/

/* length of the lexical representation without trailing limiter! */
#if OPCUA_GUID_STRING_USE_CURLYBRACE
# define OPCUA_GUID_LEXICAL_LENGTH 38
#else
# define OPCUA_GUID_LEXICAL_LENGTH 36
#endif

/*============================================================================
 * Types
 *===========================================================================*/

/**
  @brief An empty GUID.
*/
OPCUA_IMEXPORT extern OpcUa_Guid OpcUa_Guid_Null;

/**
  @brief Creates a new GUID.

  @param pGuid [bi] The buffer to store the new GUID in.
*/
OPCUA_EXPORT OpcUa_Guid* OpcUa_Guid_Create(OpcUa_Guid* pGuid);

/**
  @brief Converts a UTF-8 string representation of a GUID to a binary representation.

  @param szText  [in] The string representation.
  @param pGuid  [out] The binary representation.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Guid_FromString(     
    const OpcUa_CharA* szText,
    OpcUa_Guid*        pGuid);

/**
  @brief Converts a binary representation of a GUID to a UTF-8 representation.

  @param pGuid  [in] The binary representation.
  @param szText [bi] The string representation.
*/
OPCUA_EXPORT OpcUa_CharA* OpcUa_Guid_ToStringA( 
    const OpcUa_Guid* pGuid,
    OpcUa_CharA*      szText);

/**
  @brief Converts a binary representation of a GUID to a newly created OpcUa_String.

  @param pGuid   [in]  The binary representation.
  @param pszText [out] The string representation.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Guid_ToString(   
    const OpcUa_Guid* pGuid,
    OpcUa_String**    pszText);

/**
  @brief Returns true if the two guids are equal.

  @param pGuid1 [in] The first guid to compare.
  @param pGuid2 [in] The second guid to compare.
*/
OPCUA_EXPORT OpcUa_Boolean OpcUa_Guid_IsEqual(
    const OpcUa_Guid* pGuid1,
    const OpcUa_Guid* pGuid2);

/**
  @brief Returns true if the guid is a null guid.

  @param pGuid [in] The guid to test.
*/
OPCUA_EXPORT OpcUa_Boolean OpcUa_Guid_IsNull(const OpcUa_Guid* pGuid);

/**
  @brief Copies a guid.

  @param pSource        [in] The guid to copy.
  @param ppDestination  [bi] The guid to change.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Guid_Copy(
    const OpcUa_Guid* pSource,
    OpcUa_Guid**      ppDestination);

OPCUA_END_EXTERN_C

#endif /* _OpcUa_Guid_H_ */
