/******************************************************************************
** uaeventdata.h
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
** Description: Event Data classes.
**
******************************************************************************/
#ifndef UAEVENTDATA_H
#define UAEVENTDATA_H

#include "opcuatypes.h"
#include "opcuatypesinternal.h"
#include "uaarraytemplates.h"
#include "methodmanager.h"
#include "uaobjecttypes.h"
#include "uadatavariablecache.h"
#include "uatimezonedatatype.h"
#include "nodemanager.h"
#include <vector>
#include <map>
using std::vector;
using std::map;

/** Represents the event field data for an event fired by the server application
 *
 * This interface is used to pass an event to EventManagerBase::fireEvent() for distribution to interested clients.
 * It provides access to the event field data used for filtering and event data delivery.
 *
 * The method getFieldData() is used by the EventManagerBase to access the event field data within a Session context.
 * Therefore it can be used to provide language specific strings or to limit access to certain fields based on the user rights of the Session.
 *
 * Implementation classes like BaseEventTypeData normally provide convenience functions like BaseEventTypeData::getMessageValue()
 * to allow Session specific access to localized text values.
 *
 * @see BaseEventTypeData for an event creation example
 */
class SERVER_CORE_EXPORT UaEventData
{
    UA_DISABLE_COPY(UaEventData);
public:
    /** construction */
    UaEventData();
    /** destruction */
    virtual ~UaEventData();

    /** Registers all event type fields with the EventManagerBase.
     */
    static void registerEventFields(){}

    /** Get the field value for the passed index.
     *  @param index The index of the selected field. The index is provided by the server application
     *               when the event field is registered with EventManagerBase::registerEventField().
     *  @param pSession The session context for the field access
     *  @param data The data for the selected field.
     */
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data) = 0;

    /** Returns the condition NodeId if the event data is related to a condition object.
     *  Returns a null NodeId if the event data is related to a simple event.
     */
    virtual UaNodeId getConditionNodeId(){return UaNodeId();}

    /** Returns the condition branch NodeId if the event data is related to a condition object.
     *  Returns a null NodeId if the event data is related to a simple event.
     */
    virtual UaNodeId getConditionBranchNodeId(){return UaNodeId();}

    /** Returns the Retain flag if the event data is related to a condition object.
     *  Returns a OpcUa_False if the event data is related to a simple event.
     */
    virtual OpcUa_Boolean getConditionRetain(){return OpcUa_False;}

    /** Lock the event data for data update and event handling.
     *
     * This method is used for event data objects maintaining a state for conditions since there
     * may be concurrent access to the condition data by a condition update and a condition refresh
     * triggered by a client. This method is also used during the event processing in the SDK.
     * The method is implemented by condition related event data classes.
     */
    virtual void lockEventData(){}

    /** Unlock the event data after data update or event handling.
     *
     * This method is used for event data objects maintaining a state for conditions since there
     * may be concurrent access to the condition data by a condition update and a condition refresh
     * triggered by a client. This method is also used during the event processing in the SDK.
     * The method is implemented by condition related event data classes.
     */
    virtual void unlockEventData(){}

    void setEventUserData(OpcUa_Handle pEventUserData);
    OpcUa_Handle getEventUserData() const;

    const NodeAccessInfo* getEventAccessInfo() const;
    void useEventAccessInfoFrom(const UaEventData* pOther);
    void setEventAccessInfo(NodeAccessInfo* pAccessInfo);
    void attachEventAccessInfo(NodeAccessInfo* pAccessInfo);

    /** Get the ReferenceCounter interface necessary for condition event data classes
    */
    virtual ReferenceCounter* getConditionDataReferenceCounter(){return NULL;}

private:
    OpcUa_Handle    m_pEventUserData;
    NodeAccessInfo* m_pEventAccessInfo;
};

/** Base class for all event data classes representing the event fields of the BaseEventType
 *
 *  **Event Fields of the BaseEventType:**
 *
 *  Browse Name | DataType         | TypeDefinition | Modelling Rule | See Also
 *  ------------|------------------|----------------|-----------------------------------------
 *  EventId     | ByteString       | Property Type  | Mandatory      | \ref getEventId
 *  EventType   | NodeId           | Property Type  | Mandatory      | \ref getEventTypeId
 *  SourceNode  | NodeId           | Property Type  | Mandatory      | \ref getSourceNode, \ref setSourceNode
 *  SourceName  | String           | Property Type  | Mandatory      | \ref getSourceName, \ref setSourceName
 *  Time        | UtcTime          | Property Type  | Mandatory      | \ref getTime, \ref setTime
 *  ReceiveTime | UtcTime          | Property Type  | Mandatory      | \ref getReceiveTime, \ref setReceiveTime
 *  LocalTime   | TimeZoneDataType | Property Type  | Optional       | \ref getLocalTime, \ref setLocalTime
 *  Message     | LocalizedText    | Property Type  | Mandatory      | \ref getMessage, \ref setMessage
 *  Severity    | UInt16           | Property Type  | Mandatory      | \ref getSeverity, \ref setSeverity
 *
 *  The BaseEventType defines all characteristics of an Event. All
 *  other EventTypes derive from it.
 *
 @code
    UaNode* pNode;
    // Get the node that is the source for the event

    BaseEventTypeData eventData;
    // Fill all default event fields
    eventData.m_SourceNode.setNodeId(pNode->nodeId());
    eventData.m_SourceName.setString(pNode->browseName().toString());
    eventData.setMessage(UaLocalizedText("en", "Base Event was triggererd."));
    eventData.setSeverity(500);
    // Set timestamps and unique EventId
    eventData.prepareNewEvent(UaDateTime::now(), UaDateTime::now(), UaByteString());
    // Fire the event (if your class is derived from EventManagerBase (e.g. NodeManagerBase)
    fireEvent(&eventData);
    // Otherwise call fireEvent on the event manager
    // myEventManager->fireEvent(&eventData);
 @endcode
 *
 */
class SERVER_CORE_EXPORT BaseEventTypeData: public UaEventData
{
    UA_DISABLE_COPY(BaseEventTypeData);
public:
    BaseEventTypeData();
    virtual ~BaseEventTypeData();
    virtual void initializeFromEventData(BaseEventTypeData* pEventData);

    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

    virtual void prepareNewEvent(const UaDateTime& time, const UaDateTime& receiveTime, const UaByteString& userEventId);
    virtual UaByteString getEventId() const;
    virtual UaNodeId getEventTypeId() const;
    virtual void setSource(const UaNode* pNode);
    virtual void setSourceNode(const UaNodeId& sourceNode);
    virtual UaNodeId getSourceNode() const;
    virtual void setSourceName(const UaString& sourceName);
    virtual UaString getSourceName() const;
    virtual void setTime(const UaDateTime& time);
    virtual UaDateTime getTime() const;
    virtual void setReceiveTime(const UaDateTime& receiveTime);
    virtual UaDateTime getReceiveTime() const;
    virtual void setMessage(const UaLocalizedText& message);
    virtual UaLocalizedText getMessage() const;
    virtual void getMessageValue(Session* pSession, UaVariant& data);
    virtual void setSeverity(OpcUa_UInt16 severity);
    virtual OpcUa_UInt16 getSeverity() const;
    virtual void setLocalTime(const UaTimeZoneDataType& localTime);
    virtual UaTimeZoneDataType getLocalTime() const;

    /** Field 01 - EventId */
    UaVariant m_EventId;
    /** Field 02 - EventType */
    UaNodeId  m_EventTypeId;
    /** Field 03 - SourceNode */
    UaVariant m_SourceNode;
    /** Field 04 - SourceName */
    UaVariant m_SourceName;
    /** Field 05 - Time */
    UaVariant m_Time;
    /** Field 06 - ReceiveTime */
    UaVariant m_ReceiveTime;
    /** Field 07 - LocalTime */
    UaVariant m_LocalTime;
    /** Field 08 - Message */
    UaVariant m_Message;
    /** Field 09 - Severity */
    UaVariant m_Severity;
};

#endif // UAEVENTDATA_H
