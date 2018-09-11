/******************************************************************************
** opcua_alarmconditiontype.h
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
#ifndef __OPCUA_ALARMCONDITIONTYPE_H__
#define __OPCUA_ALARMCONDITIONTYPE_H__

#include "opcua_acknowledgeableconditiontype.h"
#include "opcua_identifiers.h"
#include "opcua_alarmconditiontypebase.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {


/** @brief Class implementing the UaObject interface for the AlarmConditionType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Object members of the AlarmConditionType:**
 *
 *  Browse Name   | TypeDefinition          | Modelling Rule | See Also
 *  --------------|-------------------------|----------------|-----------------------------------------------------------------
 *  ShelvingState | ShelvedStateMachineType | Optional       | \ref AlarmConditionTypeBase::getShelvingState "getShelvingState"
 *
 *  **Variable members of the AlarmConditionType:**
 *
 *  Browse Name         | DataType      | TypeDefinition       | Modelling Rule | See Also
 *  --------------------|---------------|----------------------|----------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------
 *  ActiveState         | LocalizedText | TwoStateVariableType | Mandatory      | \ref AlarmConditionTypeBase::getActiveState "getActiveState", \ref AlarmConditionTypeBase::setActiveState "setActiveState"
 *  EnabledState        | LocalizedText | TwoStateVariableType | Mandatory      | \ref AlarmConditionTypeBase::getEnabledState "getEnabledState", \ref AlarmConditionTypeBase::setEnabledState "setEnabledState"
 *  InputNode           | NodeId        | PropertyType         | Mandatory      | \ref AlarmConditionTypeBase::getInputNode "getInputNode", \ref AlarmConditionTypeBase::setInputNode "setInputNode"
 *  MaxTimeShelved      | Duration      | PropertyType         | Optional       | \ref AlarmConditionTypeBase::getMaxTimeShelved "getMaxTimeShelved", \ref AlarmConditionTypeBase::setMaxTimeShelved "setMaxTimeShelved"
 *  SuppressedOrShelved | Boolean       | PropertyType         | Mandatory      | \ref AlarmConditionTypeBase::getSuppressedOrShelved "getSuppressedOrShelved", \ref AlarmConditionTypeBase::setSuppressedOrShelved "setSuppressedOrShelved"
 *  SuppressedState     | LocalizedText | TwoStateVariableType | Optional       | \ref AlarmConditionTypeBase::getSuppressedState "getSuppressedState", \ref AlarmConditionTypeBase::setSuppressedState "setSuppressedState"
 *
 *  An abstract type that extends the AcknowledgeableConditionType by introducing
 *  an ActiveState, SuppressedState and ShelvingState.
 *
 *  The AlarmConditionType inherits all Properties of the
 *  AcknowledgeableConditionType. The following states are substates of the TRUE
 *  EnabledState.
 *
 *  See also \ref Doc_OpcUa_AlarmConditionType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AlarmConditionType:
    public AlarmConditionTypeBase
{
    UA_DISABLE_COPY(AlarmConditionType);
protected:
    // destruction
    virtual ~AlarmConditionType();
public:
    // construction
    AlarmConditionType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    AlarmConditionType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    AlarmConditionType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    static void addActiveStateLocale(const UaLocalizedText& falseName, const UaLocalizedText& trueName);
    static void addSuppressedStateLocale(const UaLocalizedText& falseName, const UaLocalizedText& trueName);

    void setShelvedState(ShelvedStateMachineType::ShelvedState state);
    ShelvedStateMachineType::ShelvedState getShelvedState();

    virtual void getEnabledState_EffectiveDisplayNameValue(Session* pSession, OpcUa_Variant& value);
    static void createTypes();
    static void clearStaticMembers();

    // Overwrite base class to add initialization
    virtual void setSuppressedState(OpcUa_Boolean suppressedState);
    virtual void createShelvedStateMachine();
    virtual void setActiveState(OpcUa_Boolean activeState);

protected:
    static TwoStateDisplayNames* s_pActiveStateDisplayNames;

private:
    void initialize();

private:
    static bool                  s_typeNodesCreated;
    static TwoStateDisplayNames* s_pSuppressedStateDisplayNames;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUAALARMCONDITIONTYPE_H__

