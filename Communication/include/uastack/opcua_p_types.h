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

#ifndef _OpcUa_P_Types_H_
#define _OpcUa_P_Types_H_ 1

#include <limits.h>
#include <stdint.h>

#ifndef OPCUA_P_BYTE_ORDER
#error OPCUA_P_BYTE_ORDER not defined
#endif

/*============================================================================
* Type definitions for basic data types.
*===========================================================================*/
typedef int                 OpcUa_Int;
typedef unsigned int        OpcUa_UInt;
typedef void                OpcUa_Void;
typedef void*               OpcUa_Handle;
typedef unsigned char       OpcUa_Boolean;
typedef int8_t              OpcUa_SByte;
typedef uint8_t             OpcUa_Byte;
typedef int16_t             OpcUa_Int16;
typedef uint16_t            OpcUa_UInt16;
typedef int32_t             OpcUa_Int32;
typedef uint32_t            OpcUa_UInt32;
typedef int64_t             OpcUa_Int64;
typedef uint64_t            OpcUa_UInt64;
typedef float               OpcUa_Float;
typedef double              OpcUa_Double;
typedef char                OpcUa_CharA;
typedef unsigned char       OpcUa_UCharA;
typedef unsigned short      OpcUa_Char;
typedef intptr_t            OpcUa_IntPtr;
typedef uintptr_t           OpcUa_UIntPtr;
typedef size_t              OpcUa_Size_t;

#define OpcUa_StringA char*

struct _OpcUa_DateTime
{
    OpcUa_UInt32 dwLowDateTime;
    OpcUa_UInt32 dwHighDateTime;
};
typedef struct _OpcUa_DateTime OpcUa_DateTime;

/**
 * @brief OpcUa_SocketManager Type
 */
typedef OpcUa_Void* OpcUa_SocketManager;

/**
 * @brief OpcUa_Socket Type
 */
typedef OpcUa_Void* OpcUa_Socket;

/**
 * @brief OpcUa_Thread Type
 */
typedef OpcUa_Void* OpcUa_Thread;


/**
 * @brief Internally used thread main entry function.
 */
typedef OpcUa_Void      (OpcUa_PfnInternalThreadMain)(OpcUa_Void* pArguments);

/**
 * @brief The handle for the platform thread.
 */
typedef OpcUa_UInt32    OpcUa_StatusCode;

/**
 * @brief The handle for the mutex.
 */
typedef OpcUa_Void*     OpcUa_Mutex;

/**
 * @brief The handle for the semaphore.
 */
typedef OpcUa_Void*     OpcUa_Semaphore;

/**
 * @brief The handle for a timer.
 */
typedef OpcUa_Void*     OpcUa_Timer;

/**
 * @brief A function used to compare elements when sorting or searching.
 *
 * @param pContext  [in] The context passed to the sorting/searching function.
 * @param pElement1 [in] The first element to compare.
 * @param pElement2 [in] The second element to compare.
 *
 * @return Zero if elements are equal, < 0 if element1 is less that element2.
 */
typedef OpcUa_Int (OPCUA_CDECL OpcUa_PfnCompare)(   const OpcUa_Void* pElement1,
                                                    const OpcUa_Void* pElement2);

/*============================================================================
* Type definitions for data types on the wire.
*===========================================================================*/
typedef OpcUa_Boolean       OpcUa_Boolean_Wire;
typedef OpcUa_SByte         OpcUa_SByte_Wire;
typedef OpcUa_Byte          OpcUa_Byte_Wire;
typedef OpcUa_Int16         OpcUa_Int16_Wire;
typedef OpcUa_UInt16        OpcUa_UInt16_Wire;
typedef OpcUa_Int32         OpcUa_Int32_Wire;
typedef OpcUa_UInt32        OpcUa_UInt32_Wire;
typedef OpcUa_Int64         OpcUa_Int64_Wire;
typedef OpcUa_UInt64        OpcUa_UInt64_Wire;
typedef OpcUa_Float         OpcUa_Float_Wire;
typedef OpcUa_Double        OpcUa_Double_Wire;
typedef OpcUa_CharA         OpcUa_Char_Wire;
typedef OpcUa_Char_Wire*    OpcUa_String_Wire;
typedef OpcUa_DateTime      OpcUa_DateTime_Wire;

/*============================================================================
* Type definitions for structured data types.
*===========================================================================*/
#define OPCUA_GUID_STATICINITIALIZER {0, 0, 0, {0,0,0,0,0,0,0,0}}
typedef struct _OpcUa_Guid
{
    OpcUa_UInt32    Data1;
    OpcUa_UInt16    Data2;
    OpcUa_UInt16    Data3;
    OpcUa_UCharA    Data4[8];
} OpcUa_Guid, *OpcUa_pGuid, OpcUa_Guid_Wire, *pOpcUa_Guid_Wire;

#define OPCUA_STRING_STATICINITIALIZER {0, 0, OpcUa_Null}
#define OPCUA_STRING_STATICINITIALIZEWITH(xText, xLength) {0,xLength,xText}
#ifdef _DEBUG
typedef struct _OpcUa_String
{
    OpcUa_UInt   flags;
#if OPCUA_STRING_SHORT
    OpcUa_UInt16 uLength;
#else /* OPCUA_STRING_SHORT */
    OpcUa_UInt32 uLength;
#endif /* OPCUA_STRING_SHORT */
    OpcUa_CharA* strContent;
} OpcUa_String, *OpcUa_pString;
#else
typedef struct _OpcUa_String
{
    OpcUa_UInt          uReserved1;     /* Content is private to String Implementation */
#if OPCUA_STRING_SHORT
    OpcUa_UInt16        uReserved2;     /* Content is private to String Implementation */
#else /* OPCUA_STRING_SHORT */
    OpcUa_UInt32        uReserved2;     /* Content is private to String Implementation */
#endif /* OPCUA_STRING_SHORT */
    OpcUa_Void*         uReserved4;     /* Content is private to String Implementation */
} OpcUa_String, *OpcUa_pString;
#endif

#define OPCUA_BYTESTRING_STATICINITIALIZER {-1, OpcUa_Null}
typedef struct _OpcUa_ByteString
{
    OpcUa_Int32 Length;
    OpcUa_Byte* Data;
} OpcUa_ByteString;

#define OPCUA_DATETIME_STATICINITIALIZER {0, 0}
typedef struct _OpcUa_FileTime
{
    OpcUa_UInt32 uiLowDateTime;
    OpcUa_UInt32 uiHighDateTime;
} OpcUa_FileTime, *OpcUa_pFileTime;

/**
* @brief Holds a time value with a maximum resolution of micro seconds.
*/
typedef struct _OpcUa_TimeVal OpcUa_TimeVal;

struct _OpcUa_TimeVal
{
    /** @brief The number of full seconds since 1970. */
    OpcUa_UInt32 uintSeconds;
    /** @brief The fraction of the last second. */
    OpcUa_UInt32 uintMicroSeconds;
};

/*============================================================================
 * va_list definitions
 *===========================================================================*/
typedef va_list OpcUa_P_VA_List;

#define OPCUA_P_VA_START(ap,v)  va_start(ap,v)
#define OPCUA_P_VA_END(ap)      va_end(ap)

/*============================================================================
* constant definitions.
*===========================================================================*/
#define OpcUa_Ignore        0           /* Ignore signal */
#define OpcUa_Infinite      0xFFFFFFFF  /* Infinite timeout */


#define OpcUa_False         0
#define OpcUa_True          (!OpcUa_False)
#define OpcUa_Null          0
#define OpcUa_SByte_Min     (OpcUa_SByte)-128
#define OpcUa_SByte_Max     (OpcUa_SByte)127
#define OpcUa_Byte_Min      (OpcUa_Byte)0
#define OpcUa_Byte_Max      (OpcUa_Byte)255
#define OpcUa_Int16_Min     (OpcUa_Int16)-32768
#define OpcUa_Int16_Max     (OpcUa_Int16)32767
#define OpcUa_UInt16_Min    (OpcUa_UInt16)0
#define OpcUa_UInt16_Max    (OpcUa_UInt16)65535
#define OpcUa_Int32_Min     INT_MIN
#define OpcUa_Int32_Max     INT_MAX
#define OpcUa_UInt32_Min    0
#define OpcUa_UInt32_Max    UINT_MAX
#define OpcUa_Int64_Max     (OpcUa_Int64)9223372036854775807LL
#define OpcUa_Int64_Min     (OpcUa_Int64)(-OpcUa_Int64_Max - 1LL)
#define OpcUa_UInt64_Min    (OpcUa_UInt64)0
#define OpcUa_UInt64_Max    (OpcUa_UInt64)18446744073709551615ULL
/* defined as FLT_MIN in "%ProgramFiles\Microsoft Visual Studio 8\VC\include\float.h" */
/* #define FLT_MIN         1.175494351e-38F */
#define OpcUa_Float_Min     (OpcUa_Float)1.175494351e-38F
/* defined as FLT_MAX in "%ProgramFiles\Microsoft Visual Studio 8\VC\include\float.h" */
/* #define FLT_MAX         3.402823466e+38F */
#define OpcUa_Float_Max     (OpcUa_Float)3.402823466e+38F
/* defined as DBL_MIN in "%ProgramFiles\Microsoft Visual Studio 8\VC\include\float.h" */
/* #define DBL_MIN         2.2250738585072014e-308 */
#define OpcUa_Double_Min    (OpcUa_Double)2.2250738585072014e-308
/* defined as DBL_MAX in "%ProgramFiles\Microsoft Visual Studio 8\VC\include\float.h" */
/* #define DBL_MAX         1.7976931348623158e+308 */
#define OpcUa_Double_Max    (OpcUa_Double)1.7976931348623158e+308

#define OpcUa_DateTime_Min  0ll
#define OpcUa_DateTime_Max  2650153247990000000ll
#define OpcUa_DateTime_Max_High 0x24c73c56
#define OpcUa_DateTime_Max_Low  0x82caa980
#define OPCUA_DATETIME_SET_MAX(xDateTime) \
    { \
        xDateTime.dwHighDateTime = OpcUa_DateTime_Max_High; \
        xDateTime.dwLowDateTime =  OpcUa_DateTime_Max_Low; \
    }

#define OpcUa_Infinity      (OpcUa_Double_Max + OpcUa_Double_Max)
#define OpcUa_NaN           (OpcUa_Infinity - OpcUa_Infinity)
#define OpcUa_IsNaN(xTest)  (int)((xTest) != (xTest))

/* set to OPCUA_CONFIG_YES to use the untested optimized byteswap */
#define OPCUA_SWAP_ALTERNATIVE OPCUA_CONFIG_NO

#if OPCUA_SWAP_ALTERNATIVE

#if OPCUA_P_BYTE_ORDER == OPCUA_P_LITTLE_ENDIAN

    /* this is the wire format */

    #define OpcUa_SwapBytes_2(xDst, xSrc) \
    { \
        *xDst = *xSrc; \
    }

    #define OpcUa_SwapBytes_4(xDst, xSrc) \
    { \
        *xDst = *xSrc; \
    }

    #define OpcUa_SwapBytes_8(xDst, xSrc) \
    { \
        *xDst = *xSrc; \
    }

#else

    #define OpcUa_SwapBytes_2(xDst, xSrc) \
    { \
        ((unsigned char*)xDst)[0] = ((unsigned char*)xSrc)[1]; \
        ((unsigned char*)xDst)[1] = ((unsigned char*)xSrc)[0]; \
    }

    #define OpcUa_SwapBytes_4(xDst, xSrc) \
    { \
        ((unsigned char*)xDst)[0] = ((unsigned char*)xSrc)[3]; \
        ((unsigned char*)xDst)[1] = ((unsigned char*)xSrc)[2]; \
        ((unsigned char*)xDst)[2] = ((unsigned char*)xSrc)[1]; \
        ((unsigned char*)xDst)[3] = ((unsigned char*)xSrc)[0]; \
    }

    #define OpcUa_SwapBytes_8(xDst, xSrc) \
    { \
        ((unsigned char*)xDst)[0] = ((unsigned char*)xSrc)[7]; \
        ((unsigned char*)xDst)[1] = ((unsigned char*)xSrc)[6]; \
        ((unsigned char*)xDst)[2] = ((unsigned char*)xSrc)[5]; \
        ((unsigned char*)xDst)[3] = ((unsigned char*)xSrc)[4]; \
        ((unsigned char*)xDst)[4] = ((unsigned char*)xSrc)[3]; \
        ((unsigned char*)xDst)[5] = ((unsigned char*)xSrc)[2]; \
        ((unsigned char*)xDst)[6] = ((unsigned char*)xSrc)[1]; \
        ((unsigned char*)xDst)[7] = ((unsigned char*)xSrc)[0]; \
    }

#endif

#else /* OPCUA_SWAP_ALTERNATIVE */

#if OPCUA_P_BYTE_ORDER == OPCUA_P_LITTLE_ENDIAN
    #define OpcUa_SwapBytes(xDst, xSrc, xCount) \
    { \
        memcpy(xDst, xSrc, xCount); \
    }
#else
    #define OpcUa_SwapBytes(xDst, xSrc, xCount) \
    { \
        OpcUa_UInt32 ii = 0; \
        OpcUa_UInt32 jj = xCount-1; \
        OpcUa_Byte* dst = (OpcUa_Byte*)xDst; \
        OpcUa_Byte* src = (OpcUa_Byte*)xSrc; \
        \
        for (; ii < xCount; ii++, jj--) \
        { \
            dst[ii] = src[jj]; \
        } \
    }
#endif

#endif /* OPCUA_SWAP_ALTERNATIVE */

#endif /* _OpcUa_PlatformDefs_H_ */
/*----------------------------------------------------------------------------------------------------*\
|   End of File                                                                          End of File   |
\*----------------------------------------------------------------------------------------------------*/
