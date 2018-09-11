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

#ifndef _OpcUa_EnumeratedType_H_
#define _OpcUa_EnumeratedType_H_ 1

OPCUA_BEGIN_EXTERN_C

/** 
  @brief Describes an enumerated valie.
*/
typedef struct _OpcUa_EnumeratedValue
{
    /*! @brief The name. */
    const OpcUa_CharA* Name;

    /*! @brief The value associated with the name. */
    OpcUa_Int32 Value;
}
OpcUa_EnumeratedValue;

/** 
  @brief Describes an enumerated type.
*/
typedef struct _OpcUa_EnumeratedType
{
    /*! @brief The name of the enumerated type. */
    const OpcUa_CharA* TypeName;

    /*! @brief A null terminated list of values. */
    OpcUa_EnumeratedValue* Values;
}
OpcUa_EnumeratedType;

/** 
  @brief Finds the name associated with a value of an enumerated type.

  @param pType  [in]  The enumerated type to search.
  @param nValue [in]  The value to look for.
  @param pName  [out] The name associated with the value.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_EnumeratedType_FindName(
    OpcUa_EnumeratedType* pType,
    OpcUa_Int32           nValue,
    const OpcUa_CharA**   pName);

/** 
  @brief Finds the value associated with a name for an enumerated type.

  @param pType  [in]  The enumerated type to search.
  @param sName  [in]  The name to look for.
  @param pValue [out] The value associated with the name.
*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_EnumeratedType_FindValue(
    OpcUa_EnumeratedType* pType,
    const OpcUa_CharA*    sName,
    OpcUa_Int32*          pValue);

OPCUA_END_EXTERN_C

#endif /* _OpcUa_EnumeratedType_H_ */
