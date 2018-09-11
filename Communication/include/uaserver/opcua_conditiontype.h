/******************************************************************************
** opcua_conditiontype.h
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
** Project: C++ OPC Server SDK information model for namespace http://opcfoundation.org/UA/
**
** Description: OPC Unified Architecture Software Development Kit.
**
******************************************************************************/
#ifndef __OPCUA_CONDITIONTYPE_H__
#define __OPCUA_CONDITIONTYPE_H__

#include "opcua_baseeventtype.h"
#include "opcua_identifiers.h"
#include "opcua_conditiontypebase.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class TwoStateDisplayNames;

/** @brief Class implementing the UaObject interface for the ConditionType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Variable members of the ConditionType:**
 *
 *  Browse Name        | DataType      | TypeDefinition        | Modelling Rule | See Also
 *  -------------------|---------------|-----------------------|----------------|---------------------------------------------------------------------------------------------------------------------------------------------
 *  BranchId           | NodeId        | PropertyType          | Mandatory      | \ref ConditionTypeBase::getBranchId "getBranchId", \ref ConditionTypeBase::setBranchId "setBranchId"
 *  ClientUserId       | String        | PropertyType          | Mandatory      | \ref ConditionTypeBase::getClientUserId "getClientUserId", \ref ConditionTypeBase::setClientUserId "setClientUserId"
 *  Comment            | LocalizedText | ConditionVariableType | Mandatory      | \ref ConditionTypeBase::getComment "getComment", \ref ConditionTypeBase::setComment "setComment"
 *  ConditionClassId   | NodeId        | PropertyType          | Mandatory      | \ref ConditionTypeBase::getConditionClassId "getConditionClassId", \ref ConditionTypeBase::setConditionClassId "setConditionClassId"
 *  ConditionClassName | LocalizedText | PropertyType          | Mandatory      | \ref ConditionTypeBase::getConditionClassName "getConditionClassName", \ref ConditionTypeBase::setConditionClassName "setConditionClassName"
 *  ConditionName      | String        | PropertyType          | Mandatory      | \ref ConditionTypeBase::getConditionName "getConditionName", \ref ConditionTypeBase::setConditionName "setConditionName"
 *  EnabledState       | LocalizedText | TwoStateVariableType  | Mandatory      | \ref ConditionTypeBase::getEnabledState "getEnabledState", \ref ConditionTypeBase::setEnabledState "setEnabledState"
 *  LastSeverity       | UInt16        | ConditionVariableType | Mandatory      | \ref ConditionTypeBase::getLastSeverity "getLastSeverity", \ref ConditionTypeBase::setLastSeverity "setLastSeverity"
 *  Quality            | StatusCode    | ConditionVariableType | Mandatory      | \ref ConditionTypeBase::getQuality "getQuality", \ref ConditionTypeBase::setQuality "setQuality"
 *  Retain             | Boolean       | PropertyType          | Mandatory      | \ref ConditionTypeBase::getRetain "getRetain", \ref ConditionTypeBase::setRetain "setRetain"
 *
 *  **Method members of the ConditionType:**
 *
 *  Browse Name       | Modelling Rule
 *  ------------------|---------------
 *  \ref AddComment   | Mandatory
 *  ConditionRefresh  | None
 *  ConditionRefresh2 | None
 *  \ref Disable      | Mandatory
 *  \ref Enable       | Mandatory
 *
 *  The ConditionType defines all general characteristics of a Condition. All other
 *  ConditionTypes derive from it.
 *
 *  The FALSE state of the EnabledState shall not be extended with a substate
 *  machine. The ConditionType inherits all Properties of the BaseEventType.
 *
 *  SourceNode identifies the ConditionSource. If the ConditionSource is not a Node
 *  in the AddressSpace, the NodeId is set to null. The SourceNode is the Node
 *  which the condition is associated with, it may be the same as the InputNode for
 *  an alarm, but it may be a separate node. For example, a motor which is a
 *  variable with a value that is an RPM may be the ConditionSource for Conditions
 *  that are related to the motor, as well as a temperature sensor associated with
 *  the motor. In the former, the InputNode for the High RPM alarm is the value of
 *  the Motor RPM, while in the later the InputNode of the High Alarm would be the
 *  value of the temperature sensor that is associated with the motor.
 *
 *  Events are only generated for Conditions that have their Retain field set to
 *  true.
 *
 *  The NodeId of the Condition instance is used as ConditionId. It is not
 *  explicitly modelled as a component of the ConditionType. However, it can be
 *  requested with the following SimpleAttributeOperand in the SelectClause of the
 *  EventFilter:
 *
 *  Name          | Type          | Description
 *  --------------|---------------|----------------------------------
 *  typeId        | NodeId        | NodeId of the ConditionType Node
 *  browsePath[]  | QualifiedName | empty
 *  attributeId   | IntegerId     | Id of the NodeId Attribute
 *
 *  See also \ref Doc_OpcUa_ConditionType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT ConditionType:
    public ConditionTypeBase
{
    UA_DISABLE_COPY(ConditionType);
protected:
    // destruction
    virtual ~ConditionType();
public:
    // construction
    ConditionType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    ConditionType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    ConditionType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    ReferenceCounter* getConditionDataReferenceCounter(){ return this;}

    // UaConditionType method AddComment
    virtual UaStatus AddComment(
        const ServiceContext& serviceContext,
        UaByteString& EventId,
        const UaLocalizedText& Comment);
    // UaConditionType method Disable
    virtual UaStatus Disable(
        const ServiceContext& serviceContext);
    // UaConditionType method Enable
    virtual UaStatus Enable(
        const ServiceContext& serviceContext);

    static void addEnabledStateLocale(const UaLocalizedText& falseName, const UaLocalizedText& trueName);

    virtual UaNodeId getConditionNodeId();
    virtual UaNodeId getConditionBranchNodeId();
    virtual OpcUa_Boolean getConditionRetain();

    static void clearStaticMembers();

    OpcUa_UInt32 getBranchCount();
    ConditionTypeData* getBranch(const UaNodeId& branchNodeId);
    ConditionTypeData* getBranchByEventId(const UaByteString& eventId, UaByteString& userEventId);
    void getAllBranches(UaPointerArray<ConditionTypeData>& branchArray);
    OpcUa_StatusCode deleteBranch(const UaNodeId& branchNodeId);
    UaStatus triggerBranchEvent(ConditionTypeData* pConditionTypeData, const UaDateTime& time, const UaDateTime& receiveTime, const UaByteString& eventId);

    virtual void setInvalid();

protected:
    void addBranch(ConditionTypeData* pConditionTypeData, const UaNodeId& branchNodeId);

protected:
    std::map<UaNodeId, ConditionTypeData*>* m_pBranches;
    static TwoStateDisplayNames* s_pEnabledStateDisplayNames;
    bool m_bIsInvalid;

private:
    void initialize();

private:
    static bool                  s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUACONDITIONTYPE_H__

