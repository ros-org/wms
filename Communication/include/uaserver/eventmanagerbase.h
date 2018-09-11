/******************************************************************************
** eventmanagerbase.h
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
** Description: Event manager interface base implementation.
**
******************************************************************************/
#ifndef EVENTMANAGERBASE_H
#define EVENTMANAGERBASE_H

#include "eventmanagerhelper.h"
#include <map>

/** Implements the EventManager interface base functionality independent of the node management
 *  It handles all active event monitored items and all event filtering and event field selection.
 */
class SERVER_CORE_EXPORT EventManagerBase : public EventManager
{
    UA_DISABLE_COPY(EventManagerBase);
public:
    // construction / destruction
    EventManagerBase();
    virtual ~EventManagerBase();
    virtual void shutDownEM();

    // Get a unique event id
    static void buildEventId(const UaByteString& userEventId, UaByteString& clientEventId);
    static void getUserEventId(const UaByteString& clientEventId, UaByteString& userEventId);

    // Fires an event with the passed data
    virtual void fireEvent(UaEventData* pEventData);
    // Can be overloaded to check user rights for event delivery to a client
    virtual bool beforeSendEvent(UaEventData* pEventData, Session* pSession);

    //- Custom event type handling ---------------------------------------------------------------
    // Add a custom event types and fields to allow selection of the field.
    static void registerEventType(const UaNodeId& superType, const UaNodeId& newType);
    static OpcUa_UInt32 registerEventField(const UaQualifiedName& fieldName);
    static OpcUa_UInt32 registerEventField(const UaQualifiedNameArray& path);
    static OpcUa_UInt32 registerEventField(const UaString& fieldName);
    // Remove a custom event type or field if not longer available.
    static void unregisterEventType(const UaNodeId& typeToRemove);
    static void unregisterEventField(OpcUa_UInt32 fieldIndex);
    // Internal SDK methods.
    static OpcUa_UInt32 getFieldIndex(const OpcUa_SimpleAttributeOperand &selectClause, OpcUa_StatusCode& fieldResult);
    static OpcUa_Boolean isOfType(const UaNodeId& eventType, const UaNodeId& typeToEvaluate);
    //--------------------------------------------------------------------------------------------

    //- Event notifier handling ------------------------------------------------------------------
    virtual void registerEventNotifier(const UaNodeId& parentNotifier, const UaNodeId& newNotifier);
    virtual void registerEventSource(const UaNodeId& parentNotifier, const UaNodeId& newSource);
    virtual void unregisterEventNotifier(const UaNodeId& notifier);
    virtual OpcUa_Boolean isNotifier(const UaNodeId& eventNotifier) const;
    virtual OpcUa_Boolean isEventManagerRootNotifier(const UaNodeId& notifier) const;
    virtual OpcUa_Boolean inNotifierTree(const UaNodeId& eventNotifier, const UaNodeId& sourceNode, UaEventData* pEventData) const;
    //--------------------------------------------------------------------------------------------

    //- Interface EventManager -------------------------------------------------------------------
    virtual UaStatus beginEventTransaction(EventManagerCallback*, const ServiceContext&, OpcUa_UInt32, OpcUa_UInt32, EventTransactionType, OpcUa_Handle&);
    virtual UaStatus beginStartMonitoring(OpcUa_Handle, OpcUa_UInt32, OpcUa_UInt32, EventCallback*, const EventMonitoringContextCreate&);
    virtual UaStatus beginModifyMonitoring(OpcUa_Handle, OpcUa_UInt32, OpcUa_UInt32, OpcUa_UInt32, const EventMonitoringContext&);
    virtual UaStatus beginStopMonitoring(OpcUa_Handle hEventManagerContext, OpcUa_UInt32, OpcUa_UInt32, OpcUa_UInt32);
    virtual UaStatus finishEventTransaction(OpcUa_Handle);
    virtual UaStatus beginConditionRefresh(const ServiceContext& serviceContext, OpcUa_UInt32 hEventItem, const UaByteString&, const UaByteString&);
    virtual UaStatus sendRefreshRequired(OpcUa_UInt32 hEventItem, const UaByteString& eventId);
    //--------------------------------------------------------------------------------------------

    static void clearStaticMembers();
protected:
    // Manages the event items
    HandleManager<EventItem>                      m_EventItemsHandleManager;
    // Mutex for the class data
    mutable UaMutex                               m_mutex;
    // Manages the event notifier object tree
    EventNotifierTreeElement*                     m_pEventNotifierTree;
    std::map<UaNodeId, EventNotifierTreeElement*> m_notifierTreeEntries;
    // Manages the active conditions
    std::map<UaNodeId, ConditionBranchList*>      m_activeConditions;
    // Flag indicating if the EventManager is shut down
    OpcUa_Boolean                                 m_isShutDown;

    static UaMutex*                                  s_pMutex;
    static OpcUa_UInt32                              s_maxFieldIndex;
    static std::map<UaString, OpcUa_UInt32>          s_eventFields;
    static EventTypeTreeElement*                     s_pEventTypeTree;
    static std::map<UaNodeId, EventTypeTreeElement*> s_eventTreeEntries;
};


#endif // EVENTMANAGERBASE_H
