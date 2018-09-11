/******************************************************************************
** coremodule.h
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
** Project: C++ OPC Server SDK core module
**
** Description: OPC server core module interface.
**
******************************************************************************/
#ifndef COREMODULE_H
#define COREMODULE_H

#ifdef _WIN32
# ifdef _SERVER_CORE_BUILD_DLL
#  define SERVER_CORE_EXPORT __declspec(dllexport)
# elif defined _SERVER_CORE_USE_DLL
#  define SERVER_CORE_EXPORT __declspec(dllimport)
# else
#  define SERVER_CORE_EXPORT
# endif
#else
# define SERVER_CORE_EXPORT
#endif

class SERVER_CORE_EXPORT CoreModulePrivate;
class SERVER_CORE_EXPORT ServerManager;
class SERVER_CORE_EXPORT ServerConfig;

/** @ingroup CppServerCore
 *  Interface class for the Unified Automation Server Core Module.
 *  This class is responsible for the initialization, start up and shut down
 *  of the Server Core Module. This class is used for the integration of the Core Module into a server application.
 */
class SERVER_CORE_EXPORT CoreModule
{
public:
    /* construction */
    CoreModule();
    /* destruction */
    ~CoreModule();

    // Initialize OPC server core module.
    int initialize(ServerManager* pServerManager = 0);

    // Start up OPC server core module.
    int startUp( ServerConfig* pServerConfig );

    // Shut down OPC server core module.
    int shutDown();

    // Get the ServerManager object.
    ServerManager* getServerManager();

private:
    /* Prohibit use of copy constructor */
    CoreModule(const CoreModule&);
    /* Prohibit use of = operator */
    CoreModule& operator=(const CoreModule&);

    CoreModulePrivate* d;
};


#endif // COREMODULE_H
