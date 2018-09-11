/******************************************************************************
** uamoduleincludes.h
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
** Project: C++ OPC Server SDK UA communication module
**
** Description: OPC server UA module main include file.
**
******************************************************************************/
#ifndef OPCUASERVERINCLUDES_H
#define OPCUASERVERINCLUDES_H

#ifdef _WIN32
#ifdef _UA_MODULE_BUILD_DLL
# define UAMODULE_EXPORT __declspec(dllexport)
#elif defined _UA_MODULE_USE_DLL
# define UAMODULE_EXPORT __declspec(dllimport)
#else
# define UAMODULE_EXPORT
#endif
#else
# define UAMODULE_EXPORT
#endif

// Core module includes
#include "servermanager.h"
#include "sessionmanager.h"
#include "nodemanagerroot.h"
#include "coremoduleincludes.h"

// OPC UA stack includes
#include "opcua_endpoint.h"
#include "opcua_identifiers.h"
#include "opcua_servicetable.h"

#endif // OPCUASERVERINCLUDES_H
