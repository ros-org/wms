/******************************************************************************
** eventmanageruanode.h
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
** Description: Event manager interface implementation.
**
******************************************************************************/
#ifndef EVENTMANAGERUANODE_H
#define EVENTMANAGERUANODE_H

#include "eventmanagerbase.h"
#include "opcua_conditiontype.h"
#include "opcua_alarmconditiontype.h"


/** Implements the EventManager interface for NodeManagerUaNode based node managers
 *  This class implements the EventManager interface for nodes managed by the SDK in a NodeManagerUaNode
 *  based node manager. It handles all active event monitored items and all event filtering and event
 *  field selection.
 */
class SERVER_CORE_EXPORT EventManagerUaNode : public EventManagerBase
{
    UA_DISABLE_COPY(EventManagerUaNode);
public:
    // construction / destruction
    EventManagerUaNode();
    virtual ~EventManagerUaNode();

    //- Event handlers for method calls from UA client need to be implemented by derived class ---
    // Handler for ConditionType method Enable
    virtual UaStatus OnEnable(const ServiceContext& serviceContext, OpcUa::ConditionType* pCondition);
    // Handler for ConditionType method Disable
    virtual UaStatus OnDisable(const ServiceContext& serviceContext, OpcUa::ConditionType* pCondition);
    // Handler for ConditionType method AddComment
    virtual UaStatus OnAddComment(const ServiceContext& serviceContext, OpcUa::ConditionType* pCondition, const UaByteString& EventId, const UaLocalizedText& Comment);
    // Handler for DialogConditionType  method Respond
    virtual UaStatus OnRespond(const ServiceContext& serviceContext, OpcUa::ConditionType* pCondition, OpcUa_UInt32 selectedResponse);
    // Handler for AcknowledgeableConditionType method Acknowledge
    virtual UaStatus OnAcknowledge(const ServiceContext& serviceContext, OpcUa::AcknowledgeableConditionType* pCondition, const UaByteString& EventId, const UaLocalizedText& Comment);
    // Handler for AcknowledgeableConditionType method Confirm
    virtual UaStatus OnConfirm(const ServiceContext& serviceContext, OpcUa::AcknowledgeableConditionType* pCondition, const UaByteString& EventId, const UaLocalizedText& Comment);
    // Handler for AlarmConditionType method OneShotShelve
    virtual UaStatus OnOneShotShelve(const ServiceContext& serviceContext, OpcUa::AlarmConditionType* pCondition);
    // Handler for AlarmConditionType method TimedShelve
    virtual UaStatus OnTimedShelve(const ServiceContext& serviceContext, OpcUa::AlarmConditionType* pCondition, OpcUa_Double ShelvingTime);
    // Handler for AlarmConditionType method Unshelve
    virtual UaStatus OnUnshelve(const ServiceContext& serviceContext, OpcUa::AlarmConditionType* pCondition);
    //--------------------------------------------------------------------------------------------

private:
};


#endif // EVENTMANAGERUANODE_H
