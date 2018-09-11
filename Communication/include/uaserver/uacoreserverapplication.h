/******************************************************************************
** uacoreserverapplication.h
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
#ifndef UACORESERVERAPPLICATION_H
#define UACORESERVERAPPLICATION_H

#include <uaapplication.h>
#include "uaserverapplicationmodule.h"
#include "serverconfig.h"
#include "nodemanager.h"

class UaCoreServerApplicationPrivate;
class UaServerApplicationCallback;
class UaServer;
class CoreModule;
class ServerManager;

/** Base class for the main OPC Server management object.

  This class is a utility class managing all server SDK modules for common use cases in a simplified way.
  Enhanced users may replace this class with their own implementation to be able
  to use derived classes to overwrite SDK functionality.

  A derived class must implement the methods afterInitialize(), afterStartUp() and beforeShutdown().
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
class SERVER_CORE_EXPORT UaCoreServerApplication : public UaApplication
{
    UA_DISABLE_COPY(UaCoreServerApplication);
public:
    // construction / destruction
    UaCoreServerApplication();
    UaCoreServerApplication(int argc, char* argv[], bool bRunAsService, const UaString &sApplicationName);
    virtual ~UaCoreServerApplication();

    // Methods used to initialize the server
    int setServerConfig(const UaString& configurationFile, const UaString& sApplicationPath);
    int setServerConfig(const UaString& configurationFile, const UaString& sApplicationPath, const UaString& sConfigPath, const UaString& sTracePath);
    int setServerConfig(ServerConfig* pServerConfig);
    int addNodeManager(NodeManager* pNodeManager);
    int addModule(UaServerApplicationModule* pModule);
    int removeNodeManager(NodeManager* pNodeManager);
    int removeModule(UaServerApplicationModule* pModule);
    int setCallback(UaServerApplicationCallback* pUaServerApplicationCallback);
    void setSecondsTillShutdown(OpcUa_Int32 secondsTillShutdown);
    void setShutdownReason(const UaLocalizedText& shutdownReason);

    // Methods used to start and stop the server
    int start();
    int stop(OpcUa_Int32 secondsTillShutdown, const UaLocalizedText& shutdownReason);

    // Access to members
    NodeManagerConfig* getDefaultNodeManager();
    ServerManager*     getServerManager();
    ServerConfig*      getServerConfig();
    CoreModule*        getCoreModule();
    OpcUa_Boolean      isStarted();
    OpcUa_Int32        secondsTillShutdown();
    UaLocalizedText    shutdownReason();

    /** Creates a session object for the OPC server.
     *  This is the default implementation. It can be overwritten by implementing the UaServerApplicationCallback.
     *  @param sessionID            Session Id created by the server application.
     *  @param authenticationToken  Secret session Id created by the server application.
     *  @return                     A pointer to the created session.
     */
    virtual Session* createDefaultSession(OpcUa_Int32 sessionID, const UaNodeId &authenticationToken) = 0;

    virtual OpcUa_DateTime getBuildDate() const;

protected:
    /** This method needs to be implemented by the derived class and is called to finish the initialization of the UaCoreServerApplication.
     *  This method is typically used to initialize the communication modules like the UaModule.
     *  @return Result code
     */
    virtual UaStatus afterInitialize() = 0;

    /** This method needs to be implemented by the derived class and is called to finish the start-up of the UaCoreServerApplication.
     *  This method is typically used to start up the communication modules like the UaModule.
     *  @return Result code
     */
    virtual UaStatus afterStartUp() = 0;

    /** This method needs to be implemented by the derived class and is called to start the shutdown of the UaCoreServerApplication.
     *  This method is typically used to stop the communication modules like the UaModule.
     *  @return Result code
     */
    virtual UaStatus beforeShutdown() = 0;

    virtual int main();
    UaServerApplicationCallback* getServerApplicationCallback();

private:
    UaCoreServerApplicationPrivate* d;
};


/** Callback interface for the Server application object.
 This callback interface needs to be implemented if the application wants to implement user authentication.
 */
class SERVER_CORE_EXPORT UaServerApplicationCallback
{
public:
    /** Construction */
    UaServerApplicationCallback(){}
    /** Destruction */
    virtual ~UaServerApplicationCallback(){}

    /** Creates a session object for the OPC server.
     * This callback allows the application to create its own session class derived from UaSession to store
     * user specific information and to implement the user logon and user verification.
     * @param sessionID            Session Id created by the server application.
     * @param authenticationToken  Secret session Id created by the server application.
     * @return                     A pointer to the created session.
     */
    virtual Session* createSession(OpcUa_Int32 sessionID, const UaNodeId &authenticationToken) = 0;

    /** Validates the user identity token and sets the user for the session.
     *  @param pSession             Interface to the Session context for the method call
     *  @param pUserIdentityToken   Secret session Id created by the server application.
     *  @param pServerConfig        The server configuration interface
     *  @return                     Error code.
     */
    virtual UaStatus logonSessionUser(Session* pSession, UaUserIdentityToken* pUserIdentityToken, ServerConfig* pServerConfig) = 0;

    /** Optional method used to inform the application that the configuration was loaded.
     * This callback allows the application to overwrite settings from configuration files before the server is started. This ensures
     * that hard coded settings can not be changed by entering the configuration setting into the configuration file.
     * @param pServerConfig        The server configuration interface
     */
    virtual void afterLoadConfiguration(ServerConfig* pServerConfig);

    /** Optional method used to create an application specific UaServer object used as main entry point for the UA communication.
     *  The SDK creates an instance of the UaServer class as default implementation.
     *  @return UaServer object or NULL if the SDK should use the default implementation.
     */
    virtual UaServer* createUaServer() { return NULL; }

    /** Optional method to requests the shutdown of the OPC UA Server application.
     *  @return  Result of the request. If the resul tis Good, the application must shutdown the server. If the result is Bad, the application will not shut down.
     */
    virtual UaStatus requestServerShutDown(
        OpcUa_Int32            secondsTillShutdown, //!< [in] Seconds till shutdown of the server
        const UaLocalizedText& shutdownReason,      //!< [in] Reason for the shutdown
        OpcUa_Boolean          restart              //!< [in] A flag indicating if the Server should be restarted after shutdown
        );

    /** Optional method providing information about an endpoint that will be opened and the certificate that will be used by the server.
     *
     *  This callbacks allows certificate checks or the creation of a certificate before it is created by the SDK.
     *  \ref UaEndpoint::pEndpointCertificateSettings() returns the certificate configuration used by the endpoint
     */
    virtual void beforeEndpointOpen(
        UaEndpoint* pEndpoint,           //!< [in] UaEndpoint that will be opened by the server
        bool        certificateAvailable //!< [in] Flag indicating if a certificate is available
        );
};

#endif // UACORESERVERAPPLICATION_H


