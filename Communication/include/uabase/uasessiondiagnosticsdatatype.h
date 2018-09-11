/******************************************************************************
** uasessiondiagnosticsdatatype.h
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
** Portable UaSessionDiagnosticsDataType class.
**
******************************************************************************/
#ifndef UASESSIONDIAGNOSTICSDATATYPE_H
#define UASESSIONDIAGNOSTICSDATATYPE_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uaapplicationdescription.h"
#include "uadatetime.h"
#include "uanodeid.h"
#include "uaservicecounterdatatype.h"
#include "uastring.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaSessionDiagnosticsDataTypePrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_SessionDiagnosticsDataType.
 *
 *  This class encapsulates the native OpcUa_SessionDiagnosticsDataType structure
 *  and handles memory allocation and cleanup for you.
 *  UaSessionDiagnosticsDataType uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared SessionDiagnosticsDataType it creates a copy for that (copy-on-write).
 *  So assigning another UaSessionDiagnosticsDataType or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  Contains diagnostic information about client sessions.
 *
 *  Most of the values represented in this structure provide information about the
 *  number of calls of a Service, the number of currently used MonitoredItems, etc.
 *  Those numbers need not provide the exact value; they need only provide the
 *  approximate number, so that the Server is not burdened with providing the exact
 *  numbers.
 */
class UABASE_EXPORT UaSessionDiagnosticsDataType
{
    UA_DECLARE_PRIVATE(UaSessionDiagnosticsDataType)
public:
    UaSessionDiagnosticsDataType();
    UaSessionDiagnosticsDataType(const UaSessionDiagnosticsDataType &other);
    UaSessionDiagnosticsDataType(const OpcUa_SessionDiagnosticsDataType &other);
    UaSessionDiagnosticsDataType(
        const UaNodeId& sessionId,
        const UaString& sessionName,
        const UaApplicationDescription& clientDescription,
        const UaString& serverUri,
        const UaString& endpointUrl,
        const UaStringArray &localeIds,
        OpcUa_Double actualSessionTimeout,
        OpcUa_UInt32 maxResponseMessageSize,
        const UaDateTime& clientConnectionTime,
        const UaDateTime& clientLastContactTime,
        OpcUa_UInt32 currentSubscriptionsCount,
        OpcUa_UInt32 currentMonitoredItemsCount,
        OpcUa_UInt32 currentPublishRequestsInQueue,
        const UaServiceCounterDataType& totalRequestCount,
        OpcUa_UInt32 unauthorizedRequestCount,
        const UaServiceCounterDataType& readCount,
        const UaServiceCounterDataType& historyReadCount,
        const UaServiceCounterDataType& writeCount,
        const UaServiceCounterDataType& historyUpdateCount,
        const UaServiceCounterDataType& callCount,
        const UaServiceCounterDataType& createMonitoredItemsCount,
        const UaServiceCounterDataType& modifyMonitoredItemsCount,
        const UaServiceCounterDataType& setMonitoringModeCount,
        const UaServiceCounterDataType& setTriggeringCount,
        const UaServiceCounterDataType& deleteMonitoredItemsCount,
        const UaServiceCounterDataType& createSubscriptionCount,
        const UaServiceCounterDataType& modifySubscriptionCount,
        const UaServiceCounterDataType& setPublishingModeCount,
        const UaServiceCounterDataType& publishCount,
        const UaServiceCounterDataType& republishCount,
        const UaServiceCounterDataType& transferSubscriptionsCount,
        const UaServiceCounterDataType& deleteSubscriptionsCount,
        const UaServiceCounterDataType& addNodesCount,
        const UaServiceCounterDataType& addReferencesCount,
        const UaServiceCounterDataType& deleteNodesCount,
        const UaServiceCounterDataType& deleteReferencesCount,
        const UaServiceCounterDataType& browseCount,
        const UaServiceCounterDataType& browseNextCount,
        const UaServiceCounterDataType& translateBrowsePathsToNodeIdsCount,
        const UaServiceCounterDataType& queryFirstCount,
        const UaServiceCounterDataType& queryNextCount,
        const UaServiceCounterDataType& registerNodesCount,
        const UaServiceCounterDataType& unregisterNodesCount
        );
    UaSessionDiagnosticsDataType(const UaExtensionObject &extensionObject);
    UaSessionDiagnosticsDataType(const OpcUa_ExtensionObject &extensionObject);
    UaSessionDiagnosticsDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaSessionDiagnosticsDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaSessionDiagnosticsDataType();

    void clear();

    bool operator==(const UaSessionDiagnosticsDataType &other) const;
    bool operator!=(const UaSessionDiagnosticsDataType &other) const;

    UaSessionDiagnosticsDataType& operator=(const UaSessionDiagnosticsDataType &other);

    OpcUa_SessionDiagnosticsDataType* copy() const;
    void copyTo(OpcUa_SessionDiagnosticsDataType *pDst) const;

    static OpcUa_SessionDiagnosticsDataType* clone(const OpcUa_SessionDiagnosticsDataType& source);
    static void cloneTo(const OpcUa_SessionDiagnosticsDataType& source, OpcUa_SessionDiagnosticsDataType& copy);

    void attach(OpcUa_SessionDiagnosticsDataType *pValue);
    OpcUa_SessionDiagnosticsDataType* detach(OpcUa_SessionDiagnosticsDataType* pDst);

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

    OpcUa_StatusCode setSessionDiagnosticsDataType(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setSessionDiagnosticsDataType(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setSessionDiagnosticsDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSessionDiagnosticsDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setSessionDiagnosticsDataType(
        const UaNodeId& sessionId,
        const UaString& sessionName,
        const UaApplicationDescription& clientDescription,
        const UaString& serverUri,
        const UaString& endpointUrl,
        const UaStringArray &localeIds,
        OpcUa_Double actualSessionTimeout,
        OpcUa_UInt32 maxResponseMessageSize,
        const UaDateTime& clientConnectionTime,
        const UaDateTime& clientLastContactTime,
        OpcUa_UInt32 currentSubscriptionsCount,
        OpcUa_UInt32 currentMonitoredItemsCount,
        OpcUa_UInt32 currentPublishRequestsInQueue,
        const UaServiceCounterDataType& totalRequestCount,
        OpcUa_UInt32 unauthorizedRequestCount,
        const UaServiceCounterDataType& readCount,
        const UaServiceCounterDataType& historyReadCount,
        const UaServiceCounterDataType& writeCount,
        const UaServiceCounterDataType& historyUpdateCount,
        const UaServiceCounterDataType& callCount,
        const UaServiceCounterDataType& createMonitoredItemsCount,
        const UaServiceCounterDataType& modifyMonitoredItemsCount,
        const UaServiceCounterDataType& setMonitoringModeCount,
        const UaServiceCounterDataType& setTriggeringCount,
        const UaServiceCounterDataType& deleteMonitoredItemsCount,
        const UaServiceCounterDataType& createSubscriptionCount,
        const UaServiceCounterDataType& modifySubscriptionCount,
        const UaServiceCounterDataType& setPublishingModeCount,
        const UaServiceCounterDataType& publishCount,
        const UaServiceCounterDataType& republishCount,
        const UaServiceCounterDataType& transferSubscriptionsCount,
        const UaServiceCounterDataType& deleteSubscriptionsCount,
        const UaServiceCounterDataType& addNodesCount,
        const UaServiceCounterDataType& addReferencesCount,
        const UaServiceCounterDataType& deleteNodesCount,
        const UaServiceCounterDataType& deleteReferencesCount,
        const UaServiceCounterDataType& browseCount,
        const UaServiceCounterDataType& browseNextCount,
        const UaServiceCounterDataType& translateBrowsePathsToNodeIdsCount,
        const UaServiceCounterDataType& queryFirstCount,
        const UaServiceCounterDataType& queryNextCount,
        const UaServiceCounterDataType& registerNodesCount,
        const UaServiceCounterDataType& unregisterNodesCount
        );

    UaNodeId getSessionId() const;
    UaString getSessionName() const;
    UaApplicationDescription getClientDescription() const;
    UaString getServerUri() const;
    UaString getEndpointUrl() const;
    void getLocaleIds(UaStringArray& localeIds) const;
    OpcUa_Double getActualSessionTimeout() const;
    OpcUa_UInt32 getMaxResponseMessageSize() const;
    UaDateTime getClientConnectionTime() const;
    UaDateTime getClientLastContactTime() const;
    OpcUa_UInt32 getCurrentSubscriptionsCount() const;
    OpcUa_UInt32 getCurrentMonitoredItemsCount() const;
    OpcUa_UInt32 getCurrentPublishRequestsInQueue() const;
    UaServiceCounterDataType getTotalRequestCount() const;
    OpcUa_UInt32 getUnauthorizedRequestCount() const;
    UaServiceCounterDataType getReadCount() const;
    UaServiceCounterDataType getHistoryReadCount() const;
    UaServiceCounterDataType getWriteCount() const;
    UaServiceCounterDataType getHistoryUpdateCount() const;
    UaServiceCounterDataType getCallCount() const;
    UaServiceCounterDataType getCreateMonitoredItemsCount() const;
    UaServiceCounterDataType getModifyMonitoredItemsCount() const;
    UaServiceCounterDataType getSetMonitoringModeCount() const;
    UaServiceCounterDataType getSetTriggeringCount() const;
    UaServiceCounterDataType getDeleteMonitoredItemsCount() const;
    UaServiceCounterDataType getCreateSubscriptionCount() const;
    UaServiceCounterDataType getModifySubscriptionCount() const;
    UaServiceCounterDataType getSetPublishingModeCount() const;
    UaServiceCounterDataType getPublishCount() const;
    UaServiceCounterDataType getRepublishCount() const;
    UaServiceCounterDataType getTransferSubscriptionsCount() const;
    UaServiceCounterDataType getDeleteSubscriptionsCount() const;
    UaServiceCounterDataType getAddNodesCount() const;
    UaServiceCounterDataType getAddReferencesCount() const;
    UaServiceCounterDataType getDeleteNodesCount() const;
    UaServiceCounterDataType getDeleteReferencesCount() const;
    UaServiceCounterDataType getBrowseCount() const;
    UaServiceCounterDataType getBrowseNextCount() const;
    UaServiceCounterDataType getTranslateBrowsePathsToNodeIdsCount() const;
    UaServiceCounterDataType getQueryFirstCount() const;
    UaServiceCounterDataType getQueryNextCount() const;
    UaServiceCounterDataType getRegisterNodesCount() const;
    UaServiceCounterDataType getUnregisterNodesCount() const;

    void setSessionId(const UaNodeId& sessionId);
    void setSessionName(const UaString& sessionName);
    void setClientDescription(const UaApplicationDescription& clientDescription);
    void setServerUri(const UaString& serverUri);
    void setEndpointUrl(const UaString& endpointUrl);
    void setLocaleIds(const UaStringArray &localeIds);
    void setActualSessionTimeout(OpcUa_Double actualSessionTimeout);
    void setMaxResponseMessageSize(OpcUa_UInt32 maxResponseMessageSize);
    void setClientConnectionTime(const UaDateTime& clientConnectionTime);
    void setClientLastContactTime(const UaDateTime& clientLastContactTime);
    void setCurrentSubscriptionsCount(OpcUa_UInt32 currentSubscriptionsCount);
    void setCurrentMonitoredItemsCount(OpcUa_UInt32 currentMonitoredItemsCount);
    void setCurrentPublishRequestsInQueue(OpcUa_UInt32 currentPublishRequestsInQueue);
    void setTotalRequestCount(const UaServiceCounterDataType& totalRequestCount);
    void setUnauthorizedRequestCount(OpcUa_UInt32 unauthorizedRequestCount);
    void setReadCount(const UaServiceCounterDataType& readCount);
    void setHistoryReadCount(const UaServiceCounterDataType& historyReadCount);
    void setWriteCount(const UaServiceCounterDataType& writeCount);
    void setHistoryUpdateCount(const UaServiceCounterDataType& historyUpdateCount);
    void setCallCount(const UaServiceCounterDataType& callCount);
    void setCreateMonitoredItemsCount(const UaServiceCounterDataType& createMonitoredItemsCount);
    void setModifyMonitoredItemsCount(const UaServiceCounterDataType& modifyMonitoredItemsCount);
    void setSetMonitoringModeCount(const UaServiceCounterDataType& setMonitoringModeCount);
    void setSetTriggeringCount(const UaServiceCounterDataType& setTriggeringCount);
    void setDeleteMonitoredItemsCount(const UaServiceCounterDataType& deleteMonitoredItemsCount);
    void setCreateSubscriptionCount(const UaServiceCounterDataType& createSubscriptionCount);
    void setModifySubscriptionCount(const UaServiceCounterDataType& modifySubscriptionCount);
    void setSetPublishingModeCount(const UaServiceCounterDataType& setPublishingModeCount);
    void setPublishCount(const UaServiceCounterDataType& publishCount);
    void setRepublishCount(const UaServiceCounterDataType& republishCount);
    void setTransferSubscriptionsCount(const UaServiceCounterDataType& transferSubscriptionsCount);
    void setDeleteSubscriptionsCount(const UaServiceCounterDataType& deleteSubscriptionsCount);
    void setAddNodesCount(const UaServiceCounterDataType& addNodesCount);
    void setAddReferencesCount(const UaServiceCounterDataType& addReferencesCount);
    void setDeleteNodesCount(const UaServiceCounterDataType& deleteNodesCount);
    void setDeleteReferencesCount(const UaServiceCounterDataType& deleteReferencesCount);
    void setBrowseCount(const UaServiceCounterDataType& browseCount);
    void setBrowseNextCount(const UaServiceCounterDataType& browseNextCount);
    void setTranslateBrowsePathsToNodeIdsCount(const UaServiceCounterDataType& translateBrowsePathsToNodeIdsCount);
    void setQueryFirstCount(const UaServiceCounterDataType& queryFirstCount);
    void setQueryNextCount(const UaServiceCounterDataType& queryNextCount);
    void setRegisterNodesCount(const UaServiceCounterDataType& registerNodesCount);
    void setUnregisterNodesCount(const UaServiceCounterDataType& unregisterNodesCount);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_SessionDiagnosticsDataType.
 *
 *  This class encapsulates an array of the native OpcUa_SessionDiagnosticsDataType structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaSessionDiagnosticsDataType for information about the encapsulated structure.
 */
class UABASE_EXPORT UaSessionDiagnosticsDataTypes
{
public:
    UaSessionDiagnosticsDataTypes();
    UaSessionDiagnosticsDataTypes(const UaSessionDiagnosticsDataTypes &other);
    UaSessionDiagnosticsDataTypes(OpcUa_Int32 length, OpcUa_SessionDiagnosticsDataType* data);
    virtual ~UaSessionDiagnosticsDataTypes();

    UaSessionDiagnosticsDataTypes& operator=(const UaSessionDiagnosticsDataTypes &other);
    const OpcUa_SessionDiagnosticsDataType& operator[](OpcUa_UInt32 index) const;
    OpcUa_SessionDiagnosticsDataType& operator[](OpcUa_UInt32 index);

    bool operator==(const UaSessionDiagnosticsDataTypes &other) const;
    bool operator!=(const UaSessionDiagnosticsDataTypes &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_SessionDiagnosticsDataType* data);
    void attach(OpcUa_Int32 length, OpcUa_SessionDiagnosticsDataType* data);
    OpcUa_SessionDiagnosticsDataType* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_SessionDiagnosticsDataType* rawData() const {return m_data;}
    inline OpcUa_SessionDiagnosticsDataType* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setSessionDiagnosticsDataTypes(const UaVariant &variant);
    OpcUa_StatusCode setSessionDiagnosticsDataTypes(const OpcUa_Variant &variant);
    OpcUa_StatusCode setSessionDiagnosticsDataTypes(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSessionDiagnosticsDataTypes(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSessionDiagnosticsDataTypes(OpcUa_Int32 length, OpcUa_SessionDiagnosticsDataType* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_SessionDiagnosticsDataType* m_data;
};

#endif // UASESSIONDIAGNOSTICSDATATYPE_H

