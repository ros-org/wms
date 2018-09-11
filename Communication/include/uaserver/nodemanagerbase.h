/******************************************************************************
** nodemanagerbase.h
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
** Description: OPC server core module NodeManager base class for toolkit users.
**
******************************************************************************/
#ifndef __NODEMANAGERBASE_H__
#define __NODEMANAGERBASE_H__

#include "nodemanageruanode.h"
#include "iomanageruanode.h"
#if SUPPORT_Event_Subscription_Server_Facet
#include "eventmanageruanode.h"
#endif // SUPPORT_Event_Subscription_Server_Facet

/** Class providing a simplified base NodeManager, IOManager and optional EventManager implementation for most use cases */
class SERVER_CORE_EXPORT NodeManagerBase :
    public NodeManagerUaNode,
#if SUPPORT_Event_Subscription_Server_Facet
    public EventManagerUaNode,
#endif // SUPPORT_Event_Subscription_Server_Facet
    public IOManagerUaNode
{
    UA_DISABLE_COPY(NodeManagerBase);
public:
    NodeManagerBase(const UaString& sNamespaceUri, OpcUa_Boolean firesEvents = OpcUa_False, OpcUa_Int32 nHashTableSize = 10007);
    virtual ~NodeManagerBase();

    // Activate event functionality
    void setFiresEvents(OpcUa_Boolean firesEvents);

    // Activate history manager functionality
    void setHistoryManager(HistoryManager* pHistoryManager);
    void setHistoryManagerForUaNode(const UaNodeId& nodeWithHistory, HistoryManager* pHistoryManager);
    void removeHistoryManagerForUaNode(const UaNodeId& nodeToRemove);

    //- Interface NodeManager --------------------------------------------------------
    virtual UaStatus startUp(ServerManager*);
#if SUPPORT_Event_Subscription_Server_Facet
    virtual UaStatus getEventManagers(Session *pSession, OpcUa_NodeId *pNodeId, OpcUa_EventFilter *eventFilter, EventManagerArray &eventManagers) const;
#endif // SUPPORT_Event_Subscription_Server_Facet
    virtual HistoryVariableHandle* getHistoryVariableHandle(Session* pSession, HistoryVariableHandle::ServiceType serviceType, OpcUa_NodeId* pNodeId, UaStatus& result) const;
    //- Interface NodeManager --------------------------------------------------------

    //- Interface NodeManagerUaNode --------------------------------------------------
    virtual IOManager* getIOManager(UaNode* pUaNode, OpcUa_Int32 attributeId) const;
#if SUPPORT_Event_Subscription_Server_Facet
    virtual EventManagerUaNode* getEventManagerUaNode();
#endif // SUPPORT_Event_Subscription_Server_Facet
    virtual IOManagerUaNode* getIOManagerUaNode();
    //- Interface NodeManagerUaNode --------------------------------------------------

private:
    OpcUa_Boolean   m_firesEvents;
    HistoryManager* m_pHistoryManager;
    std::map<UaNodeId, HistoryManager*> m_historyManagers;
};

#endif //__NODEMANAGERBASE_H__
