/******************************************************************************
** uaserverapplication.h
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
** Description: OPC Server Application object.
**
******************************************************************************/
#ifndef UASERVERAPPLICATION_H
#define UASERVERAPPLICATION_H

#include "uamoduleincludes.h"
#include "uacoreserverapplication.h"

class UaServerApplicationPrivate;

/** Base class for the main OPC UA Server management object.

  This class is a utility class managing all server SDK modules including the OPC UA communicaiton module
  for common use cases in a simplified way.
  Enhanced users may replace this class with their own implementation to be able
  to use derived classes to overwrite SDK functionality.

  A derived may overwrite the methods afterInitialize(), afterStartUp() and beforeShutdown() but must call
  also the base class methods.
  In addition the derived class must add the following code to the destructor to make sure beforeShutdown()
  is called before the object is deleted.

  @code
    if ( isStarted() != OpcUa_False )
    {
        UaLocalizedText reason("en","Application shut down");
        stop(0, reason);
    }
  @endcode

  */
class UAMODULE_EXPORT UaServerApplication :
    public UaCoreServerApplication,
    public UaApplicationControlCallback
{
    UA_DISABLE_COPY(UaServerApplication);
public:
    // construction / destruction
    UaServerApplication();
    UaServerApplication(int argc, char* argv[], bool bRunAsService, const UaString &sApplicationName);
    virtual ~UaServerApplication();

    OpcUa_UInt32 getEndpointCount();
    UaEndpoint* getEndpoint(OpcUa_UInt32 endpointIndex);
    OpcUa_UInt32 addEndpoint(UaEndpoint* pEndpoint);
    UaStatus openEndpoint(OpcUa_UInt32 endpointIndex);
    UaStatus closeEndpoint(OpcUa_UInt32 endpointIndex);
    UaStatus requestServerShutDown(OpcUa_Int32 secondsTillShutdown, const UaLocalizedText& shutdownReason, OpcUa_Boolean restart);
    void beforeEndpointOpen(UaEndpoint* pEndpoint, bool certificateAvailable);

protected:
    virtual Session* createDefaultSession(OpcUa_Int32 sessionID, const UaNodeId &authenticationToken);
    virtual UaStatus afterInitialize();
    virtual UaStatus afterStartUp();
    virtual UaStatus beforeShutdown();

private:
    UaServerApplicationPrivate* d;
};

#endif // UASERVERAPPLICATION_H


