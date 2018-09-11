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
** Atomic ops implementation using GCC intrinsics.
**
******************************************************************************/
#ifndef __UAATOMICGCC_H__
#define __UAATOMICGCC_H__

#define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

/* Note: to use GCC atomic builtins on x86 you should define at least -march=486,
 * because 386 instruction sets do not support cmpxchg.
 * If you get an undefined reference error when linking you have most likely forgotten
 * to set this architecture. Default on GCC is still i386.
 * Today -march=i686 is a good option, as older CPUs are really rare.
 */

# if defined(__i486__) || defined(__i586__) || defined(__i686__)
# if GCC_VERSION >= 40102
#  define GCC_HAS_ATOMIC_BUILTINS
# endif
#elif defined(__amd64__) || defined(__x86_64__)
# if GCC_VERSION >= 40102
#  define GCC_HAS_ATOMIC_BUILTINS
# endif
#elif defined(__powerpc__)
# if GCC_VERSION >= 40501 /* the only tested version known to work */
#  define GCC_HAS_ATOMIC_BUILTINS
# endif
#elif defined(__arm__)
# if GCC_VERSION >= 40303
#  define GCC_HAS_ATOMIC_BUILTINS
# elif GCC_VERSION >= 40302
#  define LIBSTDCPP_HAS_ATOMIC_OPS
#  include <ext/atomicity.h>
#  if defined(__GLIBCXX__)
using __gnu_cxx::__atomic_add;
using __gnu_cxx::__exchange_and_add;
#  else
#   error "g++ required to build this file."
#  endif /* __GLIBCXX__ */
# endif /* GCC_VERSION */
#elif defined(__ia64__)
#error "currently not supported"
#else
#error "Unknown CPU"
#endif


/* use compiler intrinsics if supported (aka atomic builtins) */
#if defined(GCC_HAS_ATOMIC_BUILTINS)

static inline int ua_atomic_increment(volatile int *ptr)
{
    return __sync_add_and_fetch(ptr, 1);
}

static inline int ua_atomic_decrement(volatile int *ptr)
{
    return __sync_sub_and_fetch(ptr, 1);
}
#elif defined(LIBSTDCPP_HAS_ATOMIC_OPS)

static inline int ua_atomic_increment(volatile int *ptr)
{
    return __exchange_and_add(ptr, +1);
}

static inline int ua_atomic_decrement(volatile int *ptr)
{
    return __exchange_and_add(ptr, -1);
}

#else /* NOT GCC_HAS_ATOMIC_BUILTINS AND NOT LIBSTDCPP_HAS_ATOMIC_OPS */

/* fallback to inline assembler for x86 */
# if defined(__i486__) || defined(__i586__) || defined(__i686__)

static inline int ua_atomic_increment(volatile int *ptr)
{
    unsigned char ret;
    asm volatile("lock\n"
                 "incl %0\n"
                 "setne %1"
                 : "=m" (*ptr), "=qm" (ret)
                 : "m" (*ptr)
                 : "memory");
    return (int)(ret);
}

static inline int ua_atomic_decrement(volatile int *ptr)
{
    unsigned char ret;
    asm    volatile("lock\n"
                 "decl %0\n"
                 "setne %1"
                 : "=m" (*ptr), "=qm" (ret)
                 : "m" (*ptr)
                 : "memory");
    return (int)(ret);
}

# elif defined(__powerpc__)

#include <linux/compiler.h>
#include <asm/system.h>

static inline int ua_atomic_increment(volatile int *ptr)
{
    int t;

    __asm__ __volatile__(
"1:     lwarx   %0,0,%3         # atomic_add\n\
        add     %0,%2,%0\n\
        stwcx.  %0,0,%3 \n\
        bne-    1b"
        : "=&r" (t), "+m" (*ptr)
        : "r" (1), "r" (ptr)
        : "cc");
    return *ptr;
}

static inline int ua_atomic_decrement(volatile int *ptr)
{
    int t;

    __asm__ __volatile__(
"1:     lwarx   %0,0,%3         # atomic_sub\n\
        subf    %0,%2,%0\n\
        stwcx.  %0,0,%3 \n\
        bne-    1b"
        : "=&r" (t), "+m" (*ptr)
        : "r" (1), "r" (ptr)
        : "cc");
    return *ptr;
}

# else /* CPU detection */

/* If you see this error, either write you own inline assembly routines
 * for your archticture, or use a newer GCC which has built-in compiler intrinsics for that.
 */
#  error "Atomic functions are not ported to your platform yet."

# endif /* CPU detection */
#endif /* NOT GCC_HAS_ATOMIC_BUILTINS AND NOT LIBSTDCPP_HAS_ATOMIC_OPS */

#endif /* __UAATOMICGCC_H__ */

