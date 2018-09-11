/******************************************************************************
** sessionmanager.h
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
** Description: Session Manager Utiliy.
**
******************************************************************************/
#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H

#include "serverconfig.h"
#include "uamutex.h"
#include "version_coremodule.h"

#include <map>
#include <list>

class SERVER_CORE_EXPORT NodeManagerRoot;
class SERVER_CORE_EXPORT UaVariable;
class SecureChannelStatus;

/** SessionManager
 *  @brief Class definition of the SessionManager.
 *  Manages the Sessions and creates Secure Channels.
 *  It is not possible to create shallow copies of this Class.
 */
class SERVER_CORE_EXPORT SessionManager
{
    UA_DISABLE_COPY(SessionManager);
public:
    /* construction */
    SessionManager();
    /* destruction */
    virtual ~SessionManager();

    /*  Initialize method for session manager.*/
    UaStatus startUp(ServerConfig* pServerConfig, NodeManagerRoot* pNodeManagerRoot);

    /*  Shut down session manager. */
    UaStatus shutDown();

    /*  Close all sessions created via the UA communication channel */
    UaStatus closeAllUaSessions();

    /*  Create a session. */
    UaStatus createSession(
        const UaString&      sessionName,
        const UaByteString&  clientCertificate,
        const UaString&      sClientApplicationUri,
        OpcUa_Double         requestedSessionTimeout,
        OpcUa_Double&        revisedSessionTimeout,
        Session**            session);

    /*  Activate a session. */
    UaStatus activateSession(
        const OpcUa_NodeId*  authenticationToken,
        OpcUa_UInt32         uSecureChannelId,
        const UaStringArray& localeIDs,
        UaUserIdentityToken* pUserIdentityToken,
        const UaString&      sClientNetworkAddress,
        const OpcUa_Endpoint_SecurityPolicyConfiguration& secureChannelSecurityConfig,
        UaEndpoint*          pEndpoint);

    /*  Get a session by authenticationToken */
    Session* getSession(
        const OpcUa_NodeId* authenticationToken,
        OpcUa_Boolean       updateSession);

    /*  Get a session by integer session ID */
    Session* getSession(
        OpcUa_Int32   integerSessionId,
        OpcUa_Boolean updateSession);

    /*  Close a session identified by session ID */
    UaStatus closeSession(const OpcUa_NodeId* authenticationToken, OpcUa_Boolean deleteSubscriptions);

    // Management of secure channel / session map in SessionManager
    void secureChannelCreated(
        OpcUa_Endpoint  hEndpoint,
        OpcUa_UInt32    uEndpointIndex,
        OpcUa_UInt32    uSecureChannelId,
        const UaString& sSecurityPolicy,
        OpcUa_UInt16    uSecurityMode);
    void secureChannelDeleted(OpcUa_UInt32 uEndpointIndex, OpcUa_UInt32 uSecureChannelId);
    void detachSessionFromSecureChannel(OpcUa_Int32 sessionID, OpcUa_UInt32 uEndpointIndex, OpcUa_UInt32 uSecureChannelId);
    bool secureChannelTransportClosed(OpcUa_Endpoint hEndpoint, OpcUa_UInt32 uEndpointIndex, OpcUa_UInt32 uSecureChannelId);
    void secureChannelRenewed(OpcUa_UInt32 uEndpointIndex, OpcUa_UInt32 uSecureChannelId);
    bool isSecureChannelValid(OpcUa_UInt32 uEndpointIndex, OpcUa_UInt32 uSecureChannelId);
    void removeSessionFromMap(const UaNodeId& authenticationToken);

    /*  Inform the session manager about the shutdown of the server. */
    OpcUa_UInt32 startServerShutDown();

    /*  Purge all sessions which are marked to delete */
    UaStatus purge();

    /** Returns the time when a system time change was detected */
    static UaDateTime getLastSystemTimeChange();

    void lockSessionManager();
    void unlockSessionManager();

    void incrementSecurityRejectedRequestsCount();
    void incrementSecurityRejectedSessionCount();
    void incrementRejectedSessionCount();
    void incrementCurrentSubscriptionCount();
    void decrementCurrentSubscriptionCount();
    void incrementCumulatedSubscriptionCount();
    inline OpcUa_UInt32 getCurrentSubscriptionCount() const {return m_serverDiagSummary.CurrentSubscriptionCount;}

protected:
    virtual void sessionOpened(Session* pSession);
    virtual void sessionActivated(Session* pSession);
    virtual void sessionClosed(Session* pSession, OpcUa_Boolean deleteSubscriptions);

    virtual OpcUa_Int32 getNewSessionId();

    void incrementCurrentSessionCount();
    void decrementCurrentSessionCount();
    void incrementCumulatedSessionCount();
    void incrementSessionTimeoutCount();
    void incrementSessionAbortCount();

    OpcUa_Int32 getClientNameCount(const UaString& sClientName);
    void incrementClientName(const UaString& sClientName);
    void decrementClientName(const UaString& sClientName);

protected:
    /** Mutex to control access to the SessionManager object */
    UaMutex                      m_mutex;
    /** Map of session objects based on session Id */
    std::map< OpcUa_Int32, Session* > m_mapSessions;
    std::map< UaString, OpcUa_Int32 > m_mapClientNames;
    /** Map of session objects based on secure channel Id */
    std::map< OpcUa_UInt64, SecureChannelStatus* > m_mapSecureChannels;
    /** Last used session ID. Session ID must be unique in the server instance */
    OpcUa_Int32                  m_lastSessionID;
    /** Flag that indicates the status of the manager */
    OpcUa_Boolean                m_isStarted;
    /** Server configuration object */
    ServerConfig*                m_pServerConfig;
    /** Root node manager */
    NodeManagerRoot*             m_pNodeManagerRoot;
    /** Namespace index used for the session node ids */
    OpcUa_UInt16                 m_SessionIdNamespaceIndex;
    /** Flag that indicates that the shutdown of the server was started */
    OpcUa_Boolean                m_isShutdownStarted;
    /** Time of the last purge call */
    static OpcUa_DateTime        s_lastPurge;
    /** The time when a system time change was detected */
    static OpcUa_DateTime        s_timeOfLastSystemTimeChangeDetected;
    OpcUa_UInt32                 m_maxRetransmissionQueueSize;

private:
    void disconnectSessionFromSecureChannel(OpcUa_Int32 sessionID, OpcUa_UInt64 uSecureChannelKey, bool bSetChannelInvalid = true);
    void purgeInvalidSessions();

private:
    UaMutexRefCounted* m_pDiagnosticMutex;
    OpcUa_ServerDiagnosticsSummaryDataType m_serverDiagSummary;
};

#endif //SESSIONMANAGER_H
