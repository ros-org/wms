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

#ifndef _OpcUa_P_CompilerInfo_H_
#define _OpcUa_P_CompilerInfo_H_ 1

/* compiler information constants */
#define OPCUA_P_COMPILERNAME_UNKNOWN    "Unknown Compiler"
#define OPCUA_P_COMPILERNAME_MSVC       "Microsoft Visual C/C++"
#define OPCUA_P_COMPILERNAME_MINGNUW    "GNU C++/MINGW"
#define OPCUA_P_COMPILERNAME_GNU        "GNU C++"
#define OPCUA_P_COMPILERNAME_INTEL      "Intel C++"
#define OPCUA_P_COMPILERNAME_BORLAND    "Borland"

/* check for known compilers */
#if defined(_MSC_VER)

  /* compiler name */
# if defined(__INTEL_COMPILER)
#  define OPCUA_P_COMPILERNAME OPCUA_P_COMPILERNAME_INTEL
# else
#  define OPCUA_P_COMPILERNAME OPCUA_P_COMPILERNAME_MSVC
# endif
  /* compiler version */
# define OPCUA_P_COMPILERVERSION OPCUA_TOSTRING(_MSC_VER)

#elif defined(__GNUC__)

  /* compiler name */
# if defined(__MINGW32__)
#  define OPCUA_P_COMPILERNAME OPCUA_P_COMPILERNAME_MINGNUW
# elif defined(__INTEL_COMPILER)
#  define OPCUA_P_COMPILERNAME OPCUA_P_COMPILERNAME_INTEL
# else
#  define OPCUA_P_COMPILERNAME OPCUA_P_COMPILERNAME_GNU
# endif
  /* compiler version */
# define OPCUA_P_COMPILERVERSION OPCUA_TOSTRING(__GNUC__) "." OPCUA_TOSTRING(__GNUC_MINOR__)

#elif defined(__BORLANDC__)

  /* compiler name */
# define OPCUA_P_COMPILERNAME OPCUA_P_COMPILERNAME_BORLAND
  /* compiler version */
# define OPCUA_P_COMPILERVERSION OPCUA_TOSTRING(__BORLANDC__)

#else /* compiler */

/* compiler unknown */
# define OPCUA_P_COMPILERNAME       OPCUA_P_COMPILERNAME_UNKNOWN
# define OPCUA_P_COMPILERVERSION    "0"

#endif /* compiler */

/* create defines used by the stack */
#define OPCUA_P_COMPILERINFO OPCUA_P_COMPILERNAME " " OPCUA_P_COMPILERVERSION

#endif /* _OpcUa_P_CompilerInfo_H_ */
