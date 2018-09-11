/******************************************************************************
** uamodule.h
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
** Description: OPC server UA module interface.
**
******************************************************************************/
#ifndef UAMODULE_H
#define UAMODULE_H

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

class UaModulePrivate;
class CoreModule;
class ServerConfig;
class UaServer;

/** @ingroup CppUaModule
 *  @brief Inteface class for the OPC UA server module.
 *  This class is responsible for the start up and the shut down
 *  of the OPC UA server module.
 */
class UAMODULE_EXPORT UaModule
{
public:
    // construction / destruction
    UaModule();
    ~UaModule();

    // Optional stack initialization before start up
    int initialize(ServerConfig* pServerConfig, UaServer* pUaServer = 0);

    // Start up OPC UA server module.
    int startUp(CoreModule* pCoreModule);

    // Shut down OPC UA server module.
    int shutDown();

    UaServer* pUaServer();

private:
    /* Prohibit use of copy constructor */
    UaModule(const UaModule&);
    /* Prohibit use of = operator */
    UaModule& operator=(const UaModule&);

    UaModulePrivate* d;
};


#endif // UAMODULE_H
