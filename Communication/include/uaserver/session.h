/******************************************************************************
** session.h
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
** Description: OPC server core module session management class.
**
******************************************************************************/
#ifndef SESSION_H
#define SESSION_H

#include "opcuatypes.h"
#include "statuscode.h"
#include "uaarraytemplates.h"
#include "variablehandle.h"
#include "uauseridentitytoken.h"
#include "uaapplicationdescription.h"
#include "uaendpoint.h"

class BrowseContext;
class QueryContext;
class HistoryReadCPUserDataBase;
class SessionPrivate;
class SessionUserContext;

/** @brief Base class for user data stored in a Session.

 User data classes need to be derived from this class if the user data should be added to a Session to
 allow the Session to clean the memory of the user data when the Session is deleted.
 */
class SERVER_CORE_EXPORT SessionUserDataBase
{
public:
    /** Construction of the SessionUserDataBase.*/
    SessionUserDataBase(){}
    /** Destruction of the SessionUserDataBase.*/
    virtual ~SessionUserDataBase(){}

    /** Method to check the type of the SessionUserData implementation. */
    virtual bool checkUserDataTypeMatch(const UaString& typeName) const = 0;
};


/** @brief Callback interface class for Session callbacks.
 *
 * Objects interested in the session status can implement this callback interface and can
 * register with the Session to get informed about
 */
class SERVER_CORE_EXPORT SessionCallback
{
public:
    /** Construction of the SessionCallback.*/
    SessionCallback(){}
    /** Destruction of the SessionCallback.*/
    virtual ~SessionCallback(){}

    /*  Inform a registered object that the session was opened.
     *  Needs to be overwritten by the derived class. */
    virtual void sessionOpened(){}

    /*  Inform a registered object that the session was activated.
     *  Needs to be overwritten by the derived class. */
    virtual void sessionActivated(){}

    /*  Inform a registered object that the session is invalid.
     *  Needs to be overwritten by the derived class. */
    virtual void sessionInvalidated(){}

    /* Inform a registered object that the session was closed.
     *  Needs to be implemented by the derived class. */
    virtual void sessionClosed() = 0;
};


/**  Class used to manage a client session in the server.
 *
 * It manages all Session relevant settings including the lifetime of the Session.
 * The object is reference counted and can not be deleted directly.
 */
class SERVER_CORE_EXPORT Session: public ReferenceCounter
{
    UA_DISABLE_COPY(Session);
protected:
    /** Prohibit use of default constructor */
    Session();
    /** Prohibit use of destructor */
    virtual ~Session();
public:
    Session(OpcUa_Int32 sessionId, const UaNodeId &authenticationToken);

    //  Open the session.
    virtual UaStatus open(
        const UaString&      sessionName,
        const UaByteString   clientCertificate,
        OpcUa_UInt32         sessionTimeout);
    //  Activate the session.
    virtual UaStatus activate(
        OpcUa_UInt32         uSecureChannelId,
        UaUserIdentityToken* pUserIdentityToken,
        const UaStringArray& localeIDs);
    //  Close the session
    virtual UaStatus close(OpcUa_Boolean deleteSubscriptions);

    virtual OpcUa_Boolean hasExpired() const;
    virtual UaStatus isValid(OpcUa_UInt32 uSecureChannelId);
    virtual void setInvalid();
    OpcUa_Boolean isActivated();
    UaDateTime lastTimeoutReset();
    virtual OpcUa_Boolean mustDelete();
    virtual OpcUa_Boolean isSecureChannelValid();
    virtual void setSecureChannelInvalid();
    virtual void setSecureChannelValid();
    virtual void checkResponseLock(){}
    virtual void setMaxRetransmissionQueueSize(OpcUa_UInt32){}

    //  Queue a browse continuation point
    virtual UaStatus queueBrowseContext( BrowseContext* pBCP, OpcUa_ByteString* pCP );
    //  Get a browse continuation point
    virtual BrowseContext* getBrowseContext( OpcUa_ByteString* pCP );
    //  Get the maximum number of browse continuation points
    virtual OpcUa_UInt16 getMaxBrowseCPs();

    //  Queue a query continuation point
    virtual UaStatus queueQueryContext( QueryContext* pBCP, OpcUa_ByteString* pCP );
    //  Get a query continuation point
    virtual QueryContext* getQueryContext( OpcUa_ByteString* pCP );

    //  Queue a history read continuation point
    virtual UaStatus queueHistoryReadCP( HistoryReadCPUserDataBase* pHistoryReadCP, OpcUa_ByteString* pCP );
    //  Get a history read continuation point
    virtual HistoryReadCPUserDataBase* getHistoryReadCP( OpcUa_ByteString* pCP );

    void registerSessionCallback(SessionCallback* pCallback);
    void unregisterSessionCallback(SessionCallback* pCallback);

    void resetTimeout();

    void getSessionNodeId(OpcUa_NodeId& sessionId) const;
    OpcUa_Int32 getIntegerSessionId() const;
    void getAuthenticationToken(OpcUa_NodeId& authenticationToken) const;
    OpcUa_UInt32 getSessionTimeout() const;
    UaString getSessionName() const;
    OpcUa_UInt32 getSecureChannelId() const;
    void setSecureChannelSecurityPolicy(const UaString& sSecurityPolicy);
    UaString getSecureChannelSecurityPolicy() const;
    void setSecureChannelMessageSecurityMode(OpcUa_MessageSecurityMode messageSecurityMode);
    OpcUa_MessageSecurityMode getSecureChannelMessageSecurityMode() const;
    void setSecureChannelEndpointConfiguration(const UaEndpoint* pEndpoint);
    const UaEndpoint* getSecureChannelEndpointConfiguration() const;
    const OpcUa_ByteString* getClientCertificate() const;
    void setClientApplicationDescription(const UaApplicationDescription& clientApplicationDescription);
    UaApplicationDescription getClientApplicationDescription() const;
    void setClientNetworkAddress(const UaString& clientNetworkAddress);
    UaString getClientNetworkAddress() const;
    UaString getLocalId() const;
    OPCUA_P_DEPRECATED(const UaStringArray* getLocalIds() const);
    UaStringArray getLocalIdArray() const;
    void setClientUserId(const UaString& sClientUserId);
    UaString getClientUserId() const;
    virtual OpcUa_UInt64 getSecureChannelKey() const;
    static OpcUa_UInt64 getSecureChannelKey(UaEndpoint* pEndpoint, OpcUa_UInt32 uSecureChannelId);
    void setUserData(SessionUserDataBase* pUserData);
    SessionUserDataBase* pUserData() const;
    void setUserContext(SessionUserContext* pUserContext);
    SessionUserContext* pUserContext() const;

    virtual void setEndpoint(UaEndpoint*){}
    virtual UaEndpoint* pEndpoint() const {return NULL;}

    static int instanceCount();

protected:
    /*  Inform a derived class that the session was opened.
     *  Needs to be overwritten by the derived class. */
    virtual void sessionOpened(){};

    /*  Inform a derived class that the session was activated.
     *  Needs to be overwritten by the derived class. */
    virtual void sessionActivated(){};

    /*  Inform a derived class that the session is invalid.
     *  Needs to be overwritten by the derived class. */
    virtual void sessionInvalidated(){};

    /*  Inform a derived class that the session was closed.
     *  Needs to be overwritten by the derived class. */
    virtual void sessionClosed(){};

protected:
    SessionPrivate* d;
};

#endif // SESSION_H
