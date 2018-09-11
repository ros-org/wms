/******************************************************************************
** uaserverapplicationmodule.h
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
** Description: OPC Server Application interface.
**
******************************************************************************/
#ifndef UASERVERAPPLICATIONMODULE_H
#define UASERVERAPPLICATIONMODULE_H

#include "opcuatypes.h"

class ServerManager;

/** Interface for modules managed by the UaServerApplication object
 */
class SERVER_CORE_EXPORT UaServerApplicationModule
{
    UA_DISABLE_COPY(UaServerApplicationModule);
public:
    UaServerApplicationModule(){}
    virtual ~UaServerApplicationModule(){}

    /** Start up module.
     *  Method is called during start up of OPC Server and must load the initial
     *  module configuration.
     *  @param pServerManager   Interface to the central ServerManager object.
     *                          This interface pointer should be stored in the module instance to have access to core
     *                          module objects like the root NodeManager or the ServerConfig
     *  @return                 Error code
     */
    virtual UaStatus startUp(ServerManager* pServerManager) = 0;

    /** Shut down module.
     *  Method is called during shut down of OPC Server and can be used to
     *  clean up the configuration of the module.
     *  @return Error code
     */
    virtual UaStatus shutDown() = 0;
};

#endif // UASERVERAPPLICATIONMODULE_H


