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

/* pull all core facilities into applications */

#ifndef _OpcUa_Core_H_
#define _OpcUa_Core_H_ 1

#include <opcua_datetime.h>
#include <opcua_guid.h>
#include <opcua_memory.h>
#if OPCUA_MULTITHREADED
# include <opcua_thread.h>
#endif /* OPCUA_MULTITHREADED */
#include <opcua_string.h>
#include <opcua_timer.h>
#include <opcua_trace.h>
#include <opcua_utilities.h>
#if OPCUA_USE_SYNCHRONISATION
#include <opcua_mutex.h>
#include <opcua_semaphore.h>
#endif /* OPCUA_USE_SYNCHRONISATION */
#include <opcua_socket.h>
#include <opcua_cryptofactory.h>
#include <opcua_pkifactory.h>

#endif /* _OpcUa_Core_H_ */
