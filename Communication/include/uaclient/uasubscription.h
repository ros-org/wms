/******************************************************************************
** uasubscription.h
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
** Project: C++ OPC Client SDK
**
** Description: Interface for UA Subscription.
**
******************************************************************************/
#ifndef UACLIENTSDK_UASUBSCRIPTION_H
#define UACLIENTSDK_UASUBSCRIPTION_H

#include "uaclientsdk.h"

namespace UaClientSdk {
/*! \addtogroup UaClientLibrary
*  @{
*/

/** \brief The UaSubscription class manges a UA Client created subscription.
*
* The class provides all Subscription related UA Services as synchronous and asynchronous methods.
*
* The callback interface UaSubscriptionCallback needs to be implemented by the user of the UaSubscription class
* to receive data change, event and subscription status change callbacks from the Client SDK. The status of the
* subscription is normally monitored by the SDK and changes are indicated by sending subscription status
* changed callbacks.
*
* In cases of Subscription errors the user of the SDK is responsible for creating a new subscription since
* the SDK does not keep the information to recreate the Subscription to not increase memory consumption.
* The necessary information also needs to be kept by the client application anyway. To duplicate this information
* in the SDK consumes too much memory.
*
* A UaSubscription object is thread-safe.
*/
class UACLIENT_EXPORT UaSubscription
{
friend class UaSession;
friend class DeleteSubscriptionJob;
    UA_DISABLE_COPY(UaSubscription);
public:
    // Modify the subscription settings
    UaStatus modifySubscription(
        ServiceSettings&      serviceSettings,
        SubscriptionSettings& subscriptionSettings);

    // Set the publishing mode of the subscription
    UaStatus setPublishingMode(
        ServiceSettings&  serviceSettings,
        OpcUa_Boolean     publishingEnabled);

    // Creates monitored items
    UaStatus createMonitoredItems(
        ServiceSettings&                     serviceSettings,
        OpcUa_TimestampsToReturn             timestampsToReturn,
        const UaMonitoredItemCreateRequests& monitoredItemCreateRequests,
        UaMonitoredItemCreateResults&        monitoredItemCreateResults);

    // Modify monitored items
    UaStatus modifyMonitoredItems(
        ServiceSettings&                     serviceSettings,
        OpcUa_TimestampsToReturn             timestampsToReturn,
        const UaMonitoredItemModifyRequests& monitoredItemModifyRequests,
        UaMonitoredItemModifyResults&        monitoredItemModifyResults);

    // Set monitoring mode for monitored items
    UaStatus setMonitoringMode(
        ServiceSettings&     serviceSettings,
        OpcUa_MonitoringMode monitoringMode,
        const UaUInt32Array& monitoredItemIds,
        UaStatusCodeArray&   results);

    // Set monitoring mode for monitored items
    UaStatus setTriggering(
        ServiceSettings&     serviceSettings,
        OpcUa_UInt32         triggeringItemId,
        const UaUInt32Array& linksToAdd,
        const UaUInt32Array& linksToRemove,
        UaStatusCodeArray&   addResults,
        UaStatusCodeArray&   removeResults);

    // Delete monitored items
    UaStatus deleteMonitoredItems(
        ServiceSettings&     serviceSettings,
        const UaUInt32Array& monitoredItemIds,
        UaStatusCodeArray&   results);

    // Republish call to get lost notifications
    UaStatus republish(
        ServiceSettings&     serviceSettings,
        OpcUa_UInt32         retransmitSequenceNumber,
        UaDataNotifications& dataNotifications,
        UaDiagnosticInfos&   diagnosticInfos,
        UaEventFieldLists&   eventFieldList,
        UaStatus&            subscriptionStatus);

    // Asynchronous call to create monitored items
    UaStatus beginCreateMonitoredItems(
        ServiceSettings&                     serviceSettings,
        OpcUa_TimestampsToReturn             timestampsToReturn,
        const UaMonitoredItemCreateRequests& monitoredItemCreateRequests,
        OpcUa_UInt32                         transactionId);

    // Asynchronous call to modify monitored items
    UaStatus beginModifyMonitoredItems(
        ServiceSettings&                     serviceSettings,
        OpcUa_TimestampsToReturn             timestampsToReturn,
        const UaMonitoredItemModifyRequests& monitoredItemModifyRequests,
        OpcUa_UInt32                         transactionId);

    // Asynchronous call to set monitoring mode for monitored items
    UaStatus beginSetMonitoringMode(
        ServiceSettings&     serviceSettings,
        OpcUa_MonitoringMode monitoringMode,
        const UaUInt32Array& monitoredItemIds,
        OpcUa_UInt32         transactionId);

    // Asynchronous call to delete monitored items
    UaStatus beginDeleteMonitoredItems(
        ServiceSettings&     serviceSettings,
        const UaUInt32Array& monitoredItemIds,
        OpcUa_UInt32         transactionId);

    // Get access functions for subscription settings
    OpcUa_UInt32  subscriptionId();
    OpcUa_UInt32  clientSubscriptionHandle();
    OpcUa_Double  publishingInterval();
    OpcUa_UInt32  lifetimeCount();
    OpcUa_UInt32  maxKeepAliveCount();
    OpcUa_UInt32  maxNotificationsPerPublish();
    OpcUa_Byte    priority();
    OpcUa_Boolean publishingEnabled();

private:
    /** Construction
    * Prohibit use of constructor. The object can only be created through the UaSession.
    */
    UaSubscription(const SubscriptionSettings& subscriptionSettings);
    /** Destruction
    * Prohibit use of Destructor. The object can only be deleted through the UaSession.
    */
    ~UaSubscription();

    /** UaSubscription data */
    UaSubscriptionPrivate* d;
};
/*! @} */
}

#endif // UACLIENTSDK_UASUBSCRIPTION_H


