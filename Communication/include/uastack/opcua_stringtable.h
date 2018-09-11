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

#ifndef _OpcUa_StringTable_H_
#define _OpcUa_StringTable_H_ 1

OPCUA_BEGIN_EXTERN_C

/** 
  @brief A table of strings accessible by index.
*/
typedef struct _OpcUa_StringTable
{
    /*! @brief The number of entries in the table. */
    OpcUa_UInt32 Count; 

    /*! @brief The number of entries allocated in the table. */
    OpcUa_UInt32 Length; 

    /*! @brief The table of strings. */
    OpcUa_String* Values;
}
OpcUa_StringTable;

/** 
  @brief Puts the table into a known state.

  @param pTable [in] The table to initialize.
*/
OPCUA_EXPORT OpcUa_Void OpcUa_StringTable_Initialize(
    OpcUa_StringTable* pTable);

/** 
  @brief Frees all memory used by a string table.

  @param pTable [in] The table to clear.
*/
OPCUA_EXPORT OpcUa_Void OpcUa_StringTable_Clear(
    OpcUa_StringTable* pTable);

/** 
  @brief Adds a null terminated list of strings to the table.

  @param pTable    [in] The table to update.
  @param pStrings  [in] The strings to add.
  @param bMakeCopy [in] Copy strings instead of only referencing them.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_StringTable_AddStringList(
    OpcUa_StringTable* pTable,
    OpcUa_StringA*     pStrings,
    OpcUa_Boolean      bMakeCopy);

/** 
  @brief Adds an array of strings to the table.

  @param pTable       [in] The table to update.
  @param pStrings     [in] The array of strings to add.
  @param nNoOfStrings [in] The number of elements in the array.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_StringTable_AddStrings(
    OpcUa_StringTable* pTable,
    OpcUa_String*      pStrings,
    OpcUa_UInt32       nNoOfStrings);

/** 
  @brief Finds the index of the specified string.

  @param pTable  [in]  The string table to search.
  @param pString [in]  The string to look for.
  @param pIndex  [out] The index associated with the string.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_StringTable_FindIndex(
    OpcUa_StringTable* pTable,
    OpcUa_String*      pString,
    OpcUa_Int32*       pIndex);

/** 
  @brief Finds the string at the specified index.

  @param pTable  [in]  The string table to search.
  @param nIndex  [in]  The index to look for.
  @param pString [out] The string at the index.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_StringTable_FindString(
    OpcUa_StringTable* pTable,
    OpcUa_Int32        nIndex,
    OpcUa_String*      pString);

OPCUA_END_EXTERN_C

#endif /* _OpcUa_StringTable_H_ */
