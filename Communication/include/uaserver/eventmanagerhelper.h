/******************************************************************************
** eventmanagerhelper.h
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
** Description: Event manager helper classes.
**
******************************************************************************/
#ifndef EVENTMANAGERHELPER_H
#define EVENTMANAGERHELPER_H

#include "opcuatypes.h"
#include "opcuatypesinternal.h"
#include "uaarraytemplates.h"
#include "eventmanager.h"
#include "uaeventdata.h"
#include "uacontentfilter.h"

class SERVER_CORE_EXPORT EventFilterElement;

/** Helper class for the EventManager interface implementation in EventManagerBase.
 *
 *  This class is used to represent an event filter element in the EventFilter class.
 */
class SERVER_CORE_EXPORT EventFilterOperand
{
    UA_DISABLE_COPY(EventFilterOperand);
public:
    EventFilterOperand();
    ~EventFilterOperand();

    UaVariant value(UaEventData* pEventData, Session* pSession);
    OpcUa_Boolean boolValue(UaEventData* pEventData, Session* pSession, OpcUa_Boolean& isNull);

    /// @brief Corresponding content filter element operand.
    const UaFilterOperand* m_pFilterOperand;
    /// @brief Field Index if the operand is a SimpleAttributeOperand.
    OpcUa_UInt32           m_fieldIndex;
    /// @brief EventFilterElement if the operand is an ElementOperand.
    EventFilterElement*    m_pEventFilterElement;
    /// @brief Event filter used for the event item.
    Session*               m_pSession;
};

typedef UaObjectPointerArray<EventFilterOperand> EventFilterOperands;

/** Helper class for the EventManager interface implementation in EventManagerBase.
 *
 *  This class is used to represent an event filter element in the EventFilter class.
 */
class SERVER_CORE_EXPORT EventFilterElement
{
    UA_DISABLE_COPY(EventFilterElement);
public:
    EventFilterElement();
    ~EventFilterElement();

    UaStatus buildFilterTree(OpcUa_EventFilterResult* pEventFilterResult, OpcUa_Boolean& hasFilterError);
    OpcUa_Boolean applyFilter(UaEventData* pEventData, Session* pSession, OpcUa_Boolean& isNull);
    UaVariant applyFilterVariant(UaEventData* pEventData, Session* pSession);

    /// @brief Corresponding content filter element.
    UaContentFilterElement* m_pContentFilterElement;
    /// @brief Event filter operands of this filter element.
    EventFilterOperands     m_filterOperands;
};

/** Helper class for the EventManager interface implementation in EventManagerBase.
 *
 *  This class is used to represent an event filter in the EventItem class.
 */
class SERVER_CORE_EXPORT EventFilter
{
    UA_DISABLE_COPY(EventFilter);
    EventFilter();
public:
    EventFilter(EventManagerBase* pEventManagerBase, const UaNodeId& eventNotifier, Session* pSession);
    ~EventFilter();

    UaStatus updateFilter(const OpcUa_EventFilter* pEventFilter, OpcUa_EventFilterResult* pEventFilterResult, OpcUa_Boolean& hasFilterError);
    UaStatus buildFilterTree(OpcUa_EventFilterResult* pEventFilterResult, OpcUa_Boolean& hasFilterError);

    OpcUa_Boolean applyFilter(UaEventData* pEventData);
    OpcUa_Boolean getEventFields(UaEventData* pEventData, UaVariantArray& eventFields, Session* pSession);

    /// @brief Number of fields selected in the event filter.
    OpcUa_UInt32        m_fieldCount;
    /// @brief Fields selected in the event filter.
    OpcUa_UInt32*       m_pFieldIndexArray;
    /// @brief Content filter in the event filter.
    UaContentFilter*    m_pContentFilter;
    /// @brief Event filter element tree used to execute the filter.
    EventFilterElement* m_pEventFilterElement;
    /// @brief Event filter used for the event item.
    Session*            m_pSession;
    /// @brief Event manager interface.
    EventManagerBase*   m_pEventManagerBase;
    /// @brief NodeId of the event notifier used for this event item.
    UaNodeId            m_EventNotifier;
    OpcUa_Boolean       m_isEventNotifierServerObject;
    OpcUa_UInt32        m_sourceNodeFieldIndex;
};

/** Helper class for the EventManager interface implementation in EventManagerBase.
 *
 *  This class is used to represent an event monitored item in the EventManagerBase.
 */
class SERVER_CORE_EXPORT EventItem
{
    UA_DISABLE_COPY(EventItem);
    EventItem();
public:
    EventItem(
        EventCallback*           pEventCallback,
        EventManagerBase*        pEventManagerBase,
        const UaNodeId&          eventNotifier,
        Session*                 pSession);
    ~EventItem();

    UaStatus updateFilter(
        const OpcUa_EventFilter* pEventFilter,
        OpcUa_UInt32             eventManagerIndex,
        OpcUa_EventFilterResult* pEventFilterResult,
        OpcUa_Boolean&           hasFilterError);

    OpcUa_Boolean applyFilter(UaEventData* pEventData);

    void fireEvent(UaEventData* pEventData);
    void fireRefreshEvent(const UaByteString& eventId, OpcUa_Boolean isStart);
    void fireRefreshRequiredEvent(const UaByteString& eventId);

    /// @brief Callback pointer for new Events.
    EventCallback* m_pEventCallback;
    /// @brief Event filter used for the event item.
    EventFilter    m_EventFilter;
    /// @brief Handle of the event item.
    OpcUa_UInt32   m_hEventItem;
    /// @brief Index of the event manager used by the event receiver to identify the event manager.
    OpcUa_UInt32   m_eventManagerIndex;
    bool           m_isRefreshActive;
};


/** Helper class for the EventManager interface implementation in EventManagerBase.
 *
 *  This class is used to represent an event type in the event type tree in the EventManagerBase.
 */
class SERVER_CORE_EXPORT EventTypeTreeElement
{
    UA_DISABLE_COPY(EventTypeTreeElement);
public:
    EventTypeTreeElement();
    ~EventTypeTreeElement();

    OpcUa_Boolean findType(const UaNodeId& eventType);
    OpcUa_Boolean removeSubType(EventTypeTreeElement* pSubType);

    /// @brief NodeId of the event type.
    UaNodeId                                   m_eventType;
    /// @brief Event filter used for the event item.
    UaObjectPointerArray<EventTypeTreeElement> m_subTypes;
    /// @brief Pointer to super type tree element object.
    EventTypeTreeElement*                      m_pSuperType;
};


/** Helper class for the EventManager interface implementation in EventManagerBase.
 *
 *  This class is used to represent an event notifier in the event notifier tree in the EventManagerBase.
 */
class SERVER_CORE_EXPORT EventNotifierTreeElement
{
    UA_DISABLE_COPY(EventNotifierTreeElement);
public:
    EventNotifierTreeElement();
    ~EventNotifierTreeElement();

    OpcUa_Boolean findSource(const UaNodeId& eventSource);
    void invalidateSubNotifier(EventNotifierTreeElement* pSubNotifier);

    std::list<EventNotifierTreeElement*> m_pParents;
    /// @brief NodeId of the event notifier.
    UaNodeId m_eventNotifier;
    /// @brief Sub tree elements of the notifier.
    UaObjectPointerArray<EventNotifierTreeElement> m_subNotifiers;
    /// @brief Event sources registered for the event notifier.
    std::map<UaNodeId, UaNodeId> m_eventSources;
};


/** Helper class for the EventManager interface implementation in EventManagerBase.
 *
 *  This class is used to represent a list of branches of a condition that is in an interesting state for Refresh.
 */
class SERVER_CORE_EXPORT ConditionBranchList
{
    UA_DISABLE_COPY(ConditionBranchList);
public:
    ConditionBranchList();
    ~ConditionBranchList();

    /// @brief Contains the event data of the main branch if retain is TRUE.
    UaEventData*                 m_pMainBranchData;
    map<UaNodeId, UaEventData*>* m_pActiveBranches;
};


#endif // EVENTMANAGERHELPER_H
