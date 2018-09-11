/******************************************************************************
** uaatomic.h
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
** Functions for atomic increment and decrement.
** We try to use most performant implmentation here, and than the most portable.
** 1.) Compiler Intrinsics (it's actually inline assembly done by the compiler)
** 2.) Self-made inline assemlby routines (architecture dependent)
** 3.) Operating system calls (portable over different architectures,
**       but performance overhead due to function call)
** 4.) We throw an compiler error: Unsupported OS or architecture
**
******************************************************************************/
#ifndef __UAATOMIC_H__
#define __UAATOMIC_H__


/** Currently supported operating systems and compilers:
 *
 * Win32+Win64+WinCE
 *   MSC
 *   GNUC
 * Linux 32bit + 64bit
 *   GNUC
 *   INTELC
 * QNX
 *   GNUC
 * VXWORKS
 *   GNUC
 * Sun Solaris 10
 *   SunCC
 */

/****************************/
/* Windows Operating System */
#if defined(_WIN32) /* defined for 32bit and 64bit OS */

/* Microsoft Compiler */
# if defined(_MSC_VER)
#  include <arch/windows/uaatomic.h>
/* GNU Compiler */
# elif defined(__GNUC__) /* _MSC_VER */
/* GNU MinGW */
#  if defined(__MINGW32__)
#   include <arch/gcc/uaatomic.h>
#  else /* __MINGW32__ */
#   error "The UA SDK has not been ported to this compiler!"
#  endif /* __MINGW32__ */
# else /* _MSC_VER */
#  error "The UA SDK has not been ported to this compiler!"
# endif /* _MSC_VER */

/****************************/
/* Linux Operating System   */
#elif defined(__linux__) /* _WIN32 */

/* GNU Compiler */
# if defined(__GNUC__)
#  include <arch/gcc/uaatomic.h>
/* Intel Compiler */
# elif defined(__INTEL_COMPILER) /* __GNUC__ */
#  error "The UA SDK has not been ported to this compiler!"
# else  /* __GNUC__ */
#  error "The UA SDK has not been ported to this compiler!"
# endif /* __GNUC__ */

/****************************/
/* QNX Operating System     */
#elif defined(__QNXNTO__) /* _WIN32 */
# include <arch/qnx/uaatomic.h>

/****************************/
/* vxWorks Operating System */
#elif defined(VXWORKS)/* _WIN32 */
# include <arch/vxworks/uaatomic.h>

/****************************/
/* Sun Solaris Operating System   */
#elif defined(__sun) || defined(sun)

/* SunCC Compiler */
# if defined(__SUNPRO_C) || defined(__SUNPRO_CC)
#  include <arch/suncc/uaatomic.h>
# else  /* __SUNPRO_C */
#  error "The UA SDK has not been ported to this compiler!"
# endif /* __SUNPRO_C */

#else
#  include <arch/vxworks/uaatomic.h>
#endif /* _WIN32 */



#endif /* __UAATOMIC_H__ */

