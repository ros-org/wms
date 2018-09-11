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
#ifndef UASESSION_H
#define UASESSION_H

#include "session.h"
#include "uamoduleincludes.h"

class UaPublishContext;
class UaSubscription;
class UaSessionPrivate;
class UaTMBaseContext;

/**  Class used to manage a OPC UA client session in the server.
 It manages all OPC UA session relevant settings. All general session settings including the lifetime of the session
 are managed by the Session class which this class is derived from.
 The object is reference counted and can not be deleted directly.
 */
class UAMODULE_EXPORT UaSession: public Session
{
    friend class UaServer;
    /* Disable shallow copy of Headerfile */
    UA_DISABLE_COPY(UaSession);
protected:
    /* Prohibit use of default constructor */
    UaSession();
    /* Prohibit use of default destructor */
    virtual ~UaSession();
public:
    //  construction
    UaSession(
        OpcUa_Int32     sessionId,
        const UaNodeId &authenticationToken);

    //  Close the session
    virtual UaStatus close(OpcUa_Boolean deleteSubscriptions);
    void afterActivate();

    virtual OpcUa_Boolean matchUser(UaSession* pOtherSession);

    // Publish handling
    virtual UaStatus queuePublishRequest(UaPublishContext* pUaPublishContext, UaSubscription** ppSubscription);
    virtual UaPublishContext* getPublishRequest();
    virtual void setSecureChannelInvalid();
    virtual void checkResponseLock();

    // Subscription handling
    virtual UaStatus queueSubscriptionForPublish(UaSubscription* pSubscription);
    virtual void queueSubscriptionStatusChangeNotification(OpcUa_UInt32 subscriptionId, const UaStatus& status);
    virtual UaStatus subscriptionCreated(UaSubscription* pSubscription);
    virtual UaStatus subscriptionInvalidated(UaSubscription* pSubscription);
    virtual void sendSubscriptionStatusChangeNotification(UaPublishContext* pUaPublishContext, OpcUa_UInt32 subscriptionId, const UaStatus& status);
    OpcUa_UInt32 getNumberOfSubscriptions();
    OpcUa_UInt32 getNumberOfMonitoredItems();
    void updateSubscriptionCountDiagnostics();
    void updateMonitoredItemCountDiagnostics();
    virtual void setMaxRetransmissionQueueSize(OpcUa_UInt32 maxQueueSize);

    // Registered nodes handling
    virtual RegisteredNode* getRegisteredNode(OpcUa_UInt32 handle) const;
    virtual OpcUa_UInt32 addRegisteredNode(RegisteredNode* pRegisteredNode);
    virtual UaStatusCode removeRegisteredNode(OpcUa_UInt32 handle);

    // Active service call handling
    void lockSendResponse();
    void unlockSendResponse();
    void startingServiceProcessing();
    void finishedServiceProcessing();
    OpcUa_UInt32 activeServiceCount() const;

    // Transaction handling
    void addOutstandingTransaction(OpcUa_UInt32 hTransaction, OpcUa_UInt32 requestHandle);
    void removeOutstandingTransaction(OpcUa_UInt32 hTransaction, OpcUa_UInt32 requestHandle);
    void getOutstandingTransactionsByHandle(OpcUa_UInt32 requestHandle, std::list<OpcUa_UInt32>& transactionHandletList);

    //  Server Nonce handling
    void setServerNonce(const OpcUa_ByteString* pServerNonce);
    const OpcUa_ByteString* getServerNonce() const;

    // Endpoint handling
    virtual void setEndpoint(UaEndpoint* pEndpoint);
    virtual UaEndpoint* pEndpoint() const;

    UaStatus cancelPublishRequest(UaPublishContext* pUaPublishContext, OpcUa_StatusCode closeStatus);

    virtual OpcUa_UInt64 getSecureChannelKey() const;

private:
    UaStatus cancelPublishRequests(OpcUa_StatusCode closeStatus);
    void clearPublishRequests();

protected:
    UaSessionPrivate* dua;
};

#endif // UASESSION_H
