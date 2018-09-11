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

#ifndef _OpcUa_String_H_
#define _OpcUa_String_H_ 1

OPCUA_BEGIN_EXTERN_C

#define OPCUA_STRING_TRUNCATE

/** 
* @brief Used as length for n-operations to work with full length source strings.
*/
#define OPCUA_STRINGLENZEROTERMINATED   0xffffffffL
#define OPCUA_STRING_LENDONTCARE        OPCUA_STRINGLENZEROTERMINATED

#if OPCUA_PREFERINLINE
    #define OpcUa_String_FromCString(x)  ((OpcUa_String*)((x)==OpcUa_Null?OpcUa_Null:(x)[0]=='\0'?OpcUa_Null:x))
#else /* OPCUA_PREFERINLINE */
    OPCUA_EXPORT
    OpcUa_String* OpcUa_String_FromCString(const OpcUa_CharA* strCString);
#endif /* OPCUA_PREFERINLINE */

/** 
* @brief .
*
* @param
*
* @return Status code; @see opcua_statuscodes.h
*/
OPCUA_EXPORT OpcUa_Int32      OPCUA_DLLCALL OpcUa_StringA_vsnprintf(OpcUa_StringA      sDest,
                                                                    OpcUa_UInt32       uCount,
                                                                    const OpcUa_CharA* sFormat,
                                                                    OpcUa_P_VA_List    argptr);

/** 
* @brief .
*
* @param
*
* @return Status code; @see opcua_statuscodes.h
*/
OPCUA_EXPORT OpcUa_Int32      OPCUA_DLLCALL OpcUa_StringA_snprintf(OpcUa_StringA      sDest,
                                                                   OpcUa_UInt32       uCount,
                                                                   const OpcUa_CharA* sFormat,
                                                                   ...);

/** 
* @brief Initializes a string Structure.
*
* @param pString [out] Pointer to the new string.
*
* @return Status code; @see opcua_statuscodes.h
*/
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_String_Initialize( /*  bi */ OpcUa_String* pString);


/** 
 * @brief Allocates memory for a string of uLength bytes length.
 *
 * @param strSource     [in]  The value of the created string.
 * @param uLength       [in]  Length of string to be created. (OPCUA_STRINGLENZEROTERMINATED Use length of source, must be zero terminated)
 * @param uBufferSize   [in] Length of string buffer to be created. (usefull if larger than uLength)
 * @param bDoCopy       [in]  OpcUa_True: Copy the source string; else: reference it.
 * @param bFreeOnClear  [in]  OpcUa_True: Free the Source string if string gets cleared (only effective, if bDoCopy == OpcUa_False!).
 * @param ppNewString   [out] Pointer to the new string.
 *
 * @return Status code; @see opcua_statuscodes.h
 */
OPCUA_EXPORT
OpcUa_StatusCode    OpcUa_String_CreateNewString(   /*  in */ OpcUa_StringA     strSource,
                                                    /*  in */ OpcUa_UInt32      uLength,
                                                    /*  in */ OpcUa_UInt32      uBufferSize,
                                                    /*  in */ OpcUa_Boolean     bDoCopy,
                                                    /*  in */ OpcUa_Boolean     bFreeOnClear,
                                                    /* out */ OpcUa_String**    ppNewString);

/** 
 * @brief Allocates memory for a string of uLength bytes length when a_bDoCopy is true.
 *
 * @param strSource    [in] The value of the created string.
 * @param uLength      [in] Length of string to be created. (OPCUA_STRINGLENZEROTERMINATED Use length of source, must be zero terminated)
 * @param uBufferSize  [in] Length of string buffer to be created. (usefull if larger than uLength)
 * @param bDoCopy      [in] OpcUa_True: Copy the source string; else: reference it (mind the next parameter!).
 * @param bFreeOnClear [in] OpcUa_True: Free the Source string if string gets cleared (only effective, if bDoCopy == OpcUa_False!).
 * @param pString      [bi] Pointer to the manipulated string.
 *
 * @return Status code; @see opcua_statuscodes.h
 */
OPCUA_EXPORT
OpcUa_StatusCode    OpcUa_String_AttachToString(  /*  in */ OpcUa_StringA strSource,
                                                  /*  in */ OpcUa_UInt32  uLength,
                                                  /*  in */ OpcUa_UInt32  uBufferSize,
                                                  /*  in */ OpcUa_Boolean bDoCopy,
                                                  /*  in */ OpcUa_Boolean bFreeOnClear,
                                                  /*  bi */ OpcUa_String* pString);


/** 
 * @brief Deletes all resources occupied by a OpcUa_String including the OpcUa_String itself.
 *
 * @param ppString [bi] Pointer to the OpcUa_String to be deleted. Set to OpcUa_Null after the call.
 */
OPCUA_EXPORT
OpcUa_Void OpcUa_String_Delete(OpcUa_String** ppString);


/** 
 * @brief Frees all internal resources occupied by a OpcUa_String.
 *
 * @param pString [bi] Pointer to the OpcUa_String to be cleared.
 */
OPCUA_EXPORT
OpcUa_Void OpcUa_String_Clear(OpcUa_String* pString);

/** 
 * @brief Get a direct pointer to the internal UTF-8 string.
 *
 * @param pString [bi] Pointer to the OpcUa_String to get the raw content from.
 */
OPCUA_EXPORT
OpcUa_CharA* OpcUa_String_GetRawString(const OpcUa_String* pString);

/** 
 * @brief Determine if the string is empty (length zero).
 *
 * @param pString [bi] Pointer to the OpcUa_String to be checked.
 */
OPCUA_EXPORT
OpcUa_Boolean OpcUa_String_IsEmpty(const OpcUa_String* pString);

/** 
 * @brief Determine if the string is null (nonexistent -> initialize OpcUa_String).
 *
 * @param pString [bi] Pointer to the OpcUa_String to be checked.
 */
OPCUA_EXPORT
OpcUa_Boolean OpcUa_String_IsNull(const OpcUa_String* pString);

/* C-String Conversion */

/** 
 * @brief Copies a string (maximum bytes of the given len).
 *
 * to simulate a strcpy() pass OPCUA_STRING_LENDONTCARE as a_uLength
 *
 * @param pDestString   [out]    The copy of the string (must be OpcUa_String).
 * @param pSrcString    [in]     The string to copy (can also be OpcUa_StringA).
 * @param uLength       [in]     The number of characters to copy.
 */
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_String_StrnCpy(  OpcUa_String*       pDestString,
                                        const OpcUa_String* pSrcString,
                                        OpcUa_UInt32        uLength);

/** 
 * @brief Appends a string to another string.
 *
 * to simulate a strcat() pass OpcUa_StringLenDontCare as a_uLength
 * 
 * @param pDestString       [in/out] The string to append to (must be OpcUa_String).
 * @param pSrcString        [in]     The string to append (can also be OpcUa_StringA).
 * @param uLength           [in]     The maximum number of characters to copy.
 */ 
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_String_StrnCat(  OpcUa_String*       pDestString,
                                        const OpcUa_String* pSrcString,
                                        OpcUa_UInt32        uLength);

/** 
 * @brief Returns the length in character of the given OpcUa_String.
 *
 * @param pString [in] The string calculate the length of.
 */ 
OPCUA_EXPORT
OpcUa_UInt32 OpcUa_String_StrLen(const OpcUa_String* pString);

/** 
 * @brief Returns the size in bytes of the given OpcUa_String.
 *
 * @param pString [in] The string calculate the length of.
 */ 
OPCUA_EXPORT
OpcUa_UInt32 OpcUa_String_StrSize(const OpcUa_String* pString);

/** 
 * @brief Compares two strings.
 *
 * @return 0 if the strings are the same. <0 if pString2 is less than pString2. >0 if PString2 is greater than pString2.
 * 
 * @param pString1    [in] The first string for comparison.
 * @param pString2    [in] The second string for comparison.
 * @param uLength     [in] Number of characters to compare.
 * @param bIgnoreCase [in] True if no case-sensitive comparison is needed.
 */ 
OPCUA_EXPORT
OpcUa_Int32 OpcUa_String_StrnCmp(   const OpcUa_String* pString1,
                                    const OpcUa_String* pString2,
                                    OpcUa_UInt32        uLength,
                                    OpcUa_Boolean       bIgnoreCase);

/** The following functions are convencience functions for easy use only and call the above API only. **/

/** 
 * @brief Attaches a readonly reference for a string constant to a string object.
 *
 * @param pDst [out] The string object.
 * @param pSrc [in]  The string being referenced.
 *
 * @return Status code; @see opcua_statuscodes.h
 */
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_String_AttachReadOnly(   OpcUa_String*       pDst,
                                                const OpcUa_CharA*  pSrc);

/** 
 * @brief Attaches a copy of a string to a string object.
 *
 * @param pDst [out] The string object.
 * @param pSrc [in]  The string being copied.
 *
 * @return Status code; @see opcua_statuscodes.h
 */
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_String_AttachCopy(   OpcUa_String*       pDst,
                                            const OpcUa_CharA*  pSrc);

/** 
 * @brief Attaches a string to a string object.
 *
 * The string must be allocated with OpcUa_Alloc. The string object will free the string.
 *
 * @param pDst [out] The string object.
 * @param pSrc [in]  The string being copied.
 *
 * @return Status code; @see opcua_statuscodes.h
 */
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_String_AttachWithOwnership(  OpcUa_String* pDst,
                                                    OpcUa_StringA pSrc);

/** 
 * @brief Attaches a raw string to a string object.
 *
 * Attach a string to an OpcUa_String. (Works with OpcUa_String_FromCString() input strings).
 *
 * @param pDst [bi] The string to be set.
 * @param pSrc [in] Can be OpcUa_String or OpcUa_StringA. RawString will be attached to pDst.
 *
 * @return Status code; @see opcua_statuscodes.h
 */
OPCUA_EXPORT
OpcUa_StatusCode OpcUa_String_SafeAttachReadOnly(   OpcUa_String*         pDst,
                                                    const OpcUa_String*   pSrc);

OPCUA_END_EXTERN_C

#endif /* _OpcUa_String_H_ */
