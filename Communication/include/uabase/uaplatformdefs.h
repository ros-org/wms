/******************************************************************************
** uaplatformdefs.h
**
** Copyright (c) 2006-2016 Unified Automation GmbH. All rights reserved.
**
** Software License Agreement ("SLA") Version 2.5
**
** Unless explicitly acquired and licensed from Licensor under another
** license, the contents of this file are subject to the Software License
** Agreement ("SLA") Version 2.5, or subsequent versions
** as allowed by the SLA, and You may not copy or use this file in either
** source code or executable form, except in compliance with the terms and
** conditions of the SLA.
**
** All software distributed under the SLA is provided strictly on an
** "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
** AND LICENSOR HEREBY DISCLAIMS ALL SUCH WARRANTIES, INCLUDING WITHOUT
** LIMITATION, ANY WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
** PURPOSE, QUIET ENJOYMENT, OR NON-INFRINGEMENT. See the SLA for specific
** language governing rights and limitations under the SLA.
**
** The complete license agreement can be found here:
** http://unifiedautomation.com/License/SLA/2.5/
**
** Project: C++ OPC SDK base module
**
** Linux platform definitions.
**
******************************************************************************/
#ifndef UAPLATFORMDEFS_H_
#define UAPLATFORMDEFS_H_ 1

/* global define for unix */
#ifndef _UA_UNIX
    #define _UA_UNIX
#endif /* _UA_UNIX */

#include <math.h>
#include "opcua_platformdefs.h"
#include "opcua_types.h"
#include "assert.h"

#define UA_ASSERT(x) assert(x)
#define UA_GetHostname(x, y) gethostname(x, y)

#include <malloc.h>
#include <memory.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#define uaDebug(x) printf(x)

#include<stdarg.h>
#define UA_vsnprintf vsnprintf
#define UA_unlink  unlink
#define Ua_rename  rename
#define UA_swprintf swprintf
#define UA_strnlen  strnlen

OpcUa_UInt32 UA_GetLastError();
OpcUa_Void UA_SetLastError(OpcUa_UInt32 nError);

/* Unsigned short used for wide character strings */
typedef unsigned short UaUShort;

/* define format string specifiers according to C99 inttypes.h */
#define OpcUa_PRIi8  PRIi8
#define OpcUa_PRIu8  PRIu8
#define OpcUa_PRIi16 PRIi16
#define OpcUa_PRIu16 PRIu16
#define OpcUa_PRIi32 PRIi32
#define OpcUa_PRIu32 PRIu32
#define OpcUa_PRIi64 PRIi64
#define OpcUa_PRIu64 PRIu64
#define OpcUa_PRIuS  "zu"

OpcUa_Int32 OpcUa_MsecTo(OpcUa_DateTime fromTime, OpcUa_DateTime toTime);

#define UABASE_EXPORT

#if defined(__sun) || defined(sun) || defined(ANDROID)
UABASE_EXPORT time_t timegm(struct tm *tm);
#endif

class UaString;
class UaUniString;
class UaByteArray;

OpcUa_Boolean Utf8ToLocal8Bit(const UaString *pSource, UaByteArray &baLocal8Bit);
OpcUa_Boolean Utf16ToLocal8Bit(const UaUniString *pSource, UaByteArray &baLocal8Bit);

OpcUa_Boolean Local8BitToUtf8(const UaByteArray *pbaLocal8Bit, UaString &sUtf8);
OpcUa_Boolean Local8BitToUtf16(const UaByteArray *pbaLocal8Bit, UaUniString &sUtf16);

#define UA_SECS_BETWEEN_EPOCHS 11644473600ll
#define UA_SECS_TO_100NS          10000000 /* 10^7 */
#define UA_MSECS_TO_100NS            10000 /* 10^4 */
#define UA_HOURS_TO_100NS         36000000000ll

OPCUA_BEGIN_EXTERN_C
#ifndef HAVE_STRLCPY
UABASE_EXPORT size_t strlcpy(char *dst, const char *src, size_t len);
#endif
#ifndef HAVE_STRLCAT
UABASE_EXPORT size_t strlcat(char *dst, const char *src, size_t len);
#endif
OPCUA_END_EXTERN_C

/* The SDK doesn't use strncat and strncpy. But applications might use it.
 * Uncomment the following define for test purpose to find all occurances of strncat and strncpy
 * during compilation.
 */
/*#define NO_STRN_FUNCTIONS*/
#ifdef NO_STRN_FUNCTIONS
# define strncpy(a,b,c) error
# define strncat(a,b,c) error
/* these functions are even more evil!!! */
# define strcpy(a,b) error
# define strcat(a,b) error
#endif

#endif /* UAPLATFORMDEFS_H_ */

