/******************************************************************************
** uasubscriptiondiagnosticsdatatype.h
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
** Project: C++ OPC SDK base module
**
** Portable UaSubscriptionDiagnosticsDataType class.
**
******************************************************************************/
#ifndef UASUBSCRIPTIONDIAGNOSTICSDATATYPE_H
#define UASUBSCRIPTIONDIAGNOSTICSDATATYPE_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uanodeid.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaSubscriptionDiagnosticsDataTypePrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_SubscriptionDiagnosticsDataType.
 *
 *  This class encapsulates the native OpcUa_SubscriptionDiagnosticsDataType structure
 *  and handles memory allocation and cleanup for you.
 *  UaSubscriptionDiagnosticsDataType uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared SubscriptionDiagnosticsDataType it creates a copy for that (copy-on-write).
 *  So assigning another UaSubscriptionDiagnosticsDataType or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  Contains diagnostic information about subscriptions.
 */
class UABASE_EXPORT UaSubscriptionDiagnosticsDataType
{
    UA_DECLARE_PRIVATE(UaSubscriptionDiagnosticsDataType)
public:
    UaSubscriptionDiagnosticsDataType();
    UaSubscriptionDiagnosticsDataType(const UaSubscriptionDiagnosticsDataType &other);
    UaSubscriptionDiagnosticsDataType(const OpcUa_SubscriptionDiagnosticsDataType &other);
    UaSubscriptionDiagnosticsDataType(
        const UaNodeId& sessionId,
        OpcUa_UInt32 subscriptionId,
        OpcUa_Byte priority,
        OpcUa_Double publishingInterval,
        OpcUa_UInt32 maxKeepAliveCount,
        OpcUa_UInt32 maxLifetimeCount,
        OpcUa_UInt32 maxNotificationsPerPublish,
        OpcUa_Boolean publishingEnabled,
        OpcUa_UInt32 modifyCount,
        OpcUa_UInt32 enableCount,
        OpcUa_UInt32 disableCount,
        OpcUa_UInt32 republishRequestCount,
        OpcUa_UInt32 republishMessageRequestCount,
        OpcUa_UInt32 republishMessageCount,
        OpcUa_UInt32 transferRequestCount,
        OpcUa_UInt32 transferredToAltClientCount,
        OpcUa_UInt32 transferredToSameClientCount,
        OpcUa_UInt32 publishRequestCount,
        OpcUa_UInt32 dataChangeNotificationsCount,
        OpcUa_UInt32 eventNotificationsCount,
        OpcUa_UInt32 notificationsCount,
        OpcUa_UInt32 latePublishRequestCount,
        OpcUa_UInt32 currentKeepAliveCount,
        OpcUa_UInt32 currentLifetimeCount,
        OpcUa_UInt32 unacknowledgedMessageCount,
        OpcUa_UInt32 discardedMessageCount,
        OpcUa_UInt32 monitoredItemCount,
        OpcUa_UInt32 disabledMonitoredItemCount,
        OpcUa_UInt32 monitoringQueueOverflowCount,
        OpcUa_UInt32 nextSequenceNumber,
        OpcUa_UInt32 eventQueueOverFlowCount
        );
    UaSubscriptionDiagnosticsDataType(const UaExtensionObject &extensionObject);
    UaSubscriptionDiagnosticsDataType(const OpcUa_ExtensionObject &extensionObject);
    UaSubscriptionDiagnosticsDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaSubscriptionDiagnosticsDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaSubscriptionDiagnosticsDataType();

    void clear();

    bool operator==(const UaSubscriptionDiagnosticsDataType &other) const;
    bool operator!=(const UaSubscriptionDiagnosticsDataType &other) const;

    UaSubscriptionDiagnosticsDataType& operator=(const UaSubscriptionDiagnosticsDataType &other);

    OpcUa_SubscriptionDiagnosticsDataType* copy() const;
    void copyTo(OpcUa_SubscriptionDiagnosticsDataType *pDst) const;

    static OpcUa_SubscriptionDiagnosticsDataType* clone(const OpcUa_SubscriptionDiagnosticsDataType& source);
    static void cloneTo(const OpcUa_SubscriptionDiagnosticsDataType& source, OpcUa_SubscriptionDiagnosticsDataType& copy);

    void attach(OpcUa_SubscriptionDiagnosticsDataType *pValue);
    OpcUa_SubscriptionDiagnosticsDataType* detach(OpcUa_SubscriptionDiagnosticsDataType* pDst);

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    void toExtensionObject(UaExtensionObject &extensionObject) const;
    void toExtensionObject(OpcUa_ExtensionObject &extensionObject) const;
    void toExtensionObject(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    void toExtensionObject(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    OpcUa_StatusCode setSubscriptionDiagnosticsDataType(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setSubscriptionDiagnosticsDataType(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setSubscriptionDiagnosticsDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSubscriptionDiagnosticsDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setSubscriptionDiagnosticsDataType(
        const UaNodeId& sessionId,
        OpcUa_UInt32 subscriptionId,
        OpcUa_Byte priority,
        OpcUa_Double publishingInterval,
        OpcUa_UInt32 maxKeepAliveCount,
        OpcUa_UInt32 maxLifetimeCount,
        OpcUa_UInt32 maxNotificationsPerPublish,
        OpcUa_Boolean publishingEnabled,
        OpcUa_UInt32 modifyCount,
        OpcUa_UInt32 enableCount,
        OpcUa_UInt32 disableCount,
        OpcUa_UInt32 republishRequestCount,
        OpcUa_UInt32 republishMessageRequestCount,
        OpcUa_UInt32 republishMessageCount,
        OpcUa_UInt32 transferRequestCount,
        OpcUa_UInt32 transferredToAltClientCount,
        OpcUa_UInt32 transferredToSameClientCount,
        OpcUa_UInt32 publishRequestCount,
        OpcUa_UInt32 dataChangeNotificationsCount,
        OpcUa_UInt32 eventNotificationsCount,
        OpcUa_UInt32 notificationsCount,
        OpcUa_UInt32 latePublishRequestCount,
        OpcUa_UInt32 currentKeepAliveCount,
        OpcUa_UInt32 currentLifetimeCount,
        OpcUa_UInt32 unacknowledgedMessageCount,
        OpcUa_UInt32 discardedMessageCount,
        OpcUa_UInt32 monitoredItemCount,
        OpcUa_UInt32 disabledMonitoredItemCount,
        OpcUa_UInt32 monitoringQueueOverflowCount,
        OpcUa_UInt32 nextSequenceNumber,
        OpcUa_UInt32 eventQueueOverFlowCount
        );

    UaNodeId getSessionId() const;
    OpcUa_UInt32 getSubscriptionId() const;
    OpcUa_Byte getPriority() const;
    OpcUa_Double getPublishingInterval() const;
    OpcUa_UInt32 getMaxKeepAliveCount() const;
    OpcUa_UInt32 getMaxLifetimeCount() const;
    OpcUa_UInt32 getMaxNotificationsPerPublish() const;
    OpcUa_Boolean getPublishingEnabled() const;
    OpcUa_UInt32 getModifyCount() const;
    OpcUa_UInt32 getEnableCount() const;
    OpcUa_UInt32 getDisableCount() const;
    OpcUa_UInt32 getRepublishRequestCount() const;
    OpcUa_UInt32 getRepublishMessageRequestCount() const;
    OpcUa_UInt32 getRepublishMessageCount() const;
    OpcUa_UInt32 getTransferRequestCount() const;
    OpcUa_UInt32 getTransferredToAltClientCount() const;
    OpcUa_UInt32 getTransferredToSameClientCount() const;
    OpcUa_UInt32 getPublishRequestCount() const;
    OpcUa_UInt32 getDataChangeNotificationsCount() const;
    OpcUa_UInt32 getEventNotificationsCount() const;
    OpcUa_UInt32 getNotificationsCount() const;
    OpcUa_UInt32 getLatePublishRequestCount() const;
    OpcUa_UInt32 getCurrentKeepAliveCount() const;
    OpcUa_UInt32 getCurrentLifetimeCount() const;
    OpcUa_UInt32 getUnacknowledgedMessageCount() const;
    OpcUa_UInt32 getDiscardedMessageCount() const;
    OpcUa_UInt32 getMonitoredItemCount() const;
    OpcUa_UInt32 getDisabledMonitoredItemCount() const;
    OpcUa_UInt32 getMonitoringQueueOverflowCount() const;
    OpcUa_UInt32 getNextSequenceNumber() const;
    OpcUa_UInt32 getEventQueueOverFlowCount() const;

    void setSessionId(const UaNodeId& sessionId);
    void setSubscriptionId(OpcUa_UInt32 subscriptionId);
    void setPriority(OpcUa_Byte priority);
    void setPublishingInterval(OpcUa_Double publishingInterval);
    void setMaxKeepAliveCount(OpcUa_UInt32 maxKeepAliveCount);
    void setMaxLifetimeCount(OpcUa_UInt32 maxLifetimeCount);
    void setMaxNotificationsPerPublish(OpcUa_UInt32 maxNotificationsPerPublish);
    void setPublishingEnabled(OpcUa_Boolean publishingEnabled);
    void setModifyCount(OpcUa_UInt32 modifyCount);
    void setEnableCount(OpcUa_UInt32 enableCount);
    void setDisableCount(OpcUa_UInt32 disableCount);
    void setRepublishRequestCount(OpcUa_UInt32 republishRequestCount);
    void setRepublishMessageRequestCount(OpcUa_UInt32 republishMessageRequestCount);
    void setRepublishMessageCount(OpcUa_UInt32 republishMessageCount);
    void setTransferRequestCount(OpcUa_UInt32 transferRequestCount);
    void setTransferredToAltClientCount(OpcUa_UInt32 transferredToAltClientCount);
    void setTransferredToSameClientCount(OpcUa_UInt32 transferredToSameClientCount);
    void setPublishRequestCount(OpcUa_UInt32 publishRequestCount);
    void setDataChangeNotificationsCount(OpcUa_UInt32 dataChangeNotificationsCount);
    void setEventNotificationsCount(OpcUa_UInt32 eventNotificationsCount);
    void setNotificationsCount(OpcUa_UInt32 notificationsCount);
    void setLatePublishRequestCount(OpcUa_UInt32 latePublishRequestCount);
    void setCurrentKeepAliveCount(OpcUa_UInt32 currentKeepAliveCount);
    void setCurrentLifetimeCount(OpcUa_UInt32 currentLifetimeCount);
    void setUnacknowledgedMessageCount(OpcUa_UInt32 unacknowledgedMessageCount);
    void setDiscardedMessageCount(OpcUa_UInt32 discardedMessageCount);
    void setMonitoredItemCount(OpcUa_UInt32 monitoredItemCount);
    void setDisabledMonitoredItemCount(OpcUa_UInt32 disabledMonitoredItemCount);
    void setMonitoringQueueOverflowCount(OpcUa_UInt32 monitoringQueueOverflowCount);
    void setNextSequenceNumber(OpcUa_UInt32 nextSequenceNumber);
    void setEventQueueOverFlowCount(OpcUa_UInt32 eventQueueOverFlowCount);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_SubscriptionDiagnosticsDataType.
 *
 *  This class encapsulates an array of the native OpcUa_SubscriptionDiagnosticsDataType structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaSubscriptionDiagnosticsDataType for information about the encapsulated structure.
 */
class UABASE_EXPORT UaSubscriptionDiagnosticsDataTypes
{
public:
    UaSubscriptionDiagnosticsDataTypes();
    UaSubscriptionDiagnosticsDataTypes(const UaSubscriptionDiagnosticsDataTypes &other);
    UaSubscriptionDiagnosticsDataTypes(OpcUa_Int32 length, OpcUa_SubscriptionDiagnosticsDataType* data);
    virtual ~UaSubscriptionDiagnosticsDataTypes();

    UaSubscriptionDiagnosticsDataTypes& operator=(const UaSubscriptionDiagnosticsDataTypes &other);
    const OpcUa_SubscriptionDiagnosticsDataType& operator[](OpcUa_UInt32 index) const;
    OpcUa_SubscriptionDiagnosticsDataType& operator[](OpcUa_UInt32 index);

    bool operator==(const UaSubscriptionDiagnosticsDataTypes &other) const;
    bool operator!=(const UaSubscriptionDiagnosticsDataTypes &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_SubscriptionDiagnosticsDataType* data);
    void attach(OpcUa_Int32 length, OpcUa_SubscriptionDiagnosticsDataType* data);
    OpcUa_SubscriptionDiagnosticsDataType* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_SubscriptionDiagnosticsDataType* rawData() const {return m_data;}
    inline OpcUa_SubscriptionDiagnosticsDataType* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setSubscriptionDiagnosticsDataTypes(const UaVariant &variant);
    OpcUa_StatusCode setSubscriptionDiagnosticsDataTypes(const OpcUa_Variant &variant);
    OpcUa_StatusCode setSubscriptionDiagnosticsDataTypes(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSubscriptionDiagnosticsDataTypes(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSubscriptionDiagnosticsDataTypes(OpcUa_Int32 length, OpcUa_SubscriptionDiagnosticsDataType* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_SubscriptionDiagnosticsDataType* m_data;
};

#endif // UASUBSCRIPTIONDIAGNOSTICSDATATYPE_H

