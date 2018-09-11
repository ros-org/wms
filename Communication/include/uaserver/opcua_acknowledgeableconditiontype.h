/******************************************************************************
** opcua_acknowledgeableconditiontype.h
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
#ifndef __OPCUA_ACKNOWLEDGEABLECONDITIONTYPE_H__
#define __OPCUA_ACKNOWLEDGEABLECONDITIONTYPE_H__

#include "opcua_conditiontype.h"
#include "opcua_identifiers.h"
#include "opcua_acknowledgeableconditiontypebase.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {


/** @brief Class implementing the UaObject interface for the AcknowledgeableConditionType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Variable members of the AcknowledgeableConditionType:**
 *
 *  Browse Name    | DataType      | TypeDefinition       | Modelling Rule | See Also
 *  ---------------|---------------|----------------------|----------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------
 *  AckedState     | LocalizedText | TwoStateVariableType | Mandatory      | \ref AcknowledgeableConditionTypeBase::getAckedState "getAckedState", \ref AcknowledgeableConditionTypeBase::setAckedState "setAckedState"
 *  ConfirmedState | LocalizedText | TwoStateVariableType | Optional       | \ref AcknowledgeableConditionTypeBase::getConfirmedState "getConfirmedState", \ref AcknowledgeableConditionTypeBase::setConfirmedState "setConfirmedState"
 *  EnabledState   | LocalizedText | TwoStateVariableType | Mandatory      | \ref AcknowledgeableConditionTypeBase::getEnabledState "getEnabledState", \ref AcknowledgeableConditionTypeBase::setEnabledState "setEnabledState"
 *
 *  **Method members of the AcknowledgeableConditionType:**
 *
 *  Browse Name      | Modelling Rule
 *  -----------------|---------------
 *  \ref Acknowledge | Mandatory
 *  \ref Confirm     | Optional
 *
 *  Extends the ConditionType by defining acknowledgement characteristics. It is an
 *  abstract type.
 *
 *  The AcknowledgeableConditionType inherits all Properties of the ConditionType.
 *
 *  AcknowledgeableConditions expose states to indicate whether a Condition has to
 *  be acknowledged or confirmed.
 *
 *  The Confirmed Acknowledge model is typically used to differentiate between
 *  acknowledging the presence of a Condition and having done something to address
 *  the Condition. For example an Operator receiving a motor high temperature
 *  Notification calls the Acknowledge Method to inform the Server that the high
 *  temperature has been observed. The Operator then takes some action such as
 *  lowering the load on the motor in order to reduce the temperature. The Operator
 *  then calls the Confirm Method to inform the Server that a corrective action has
 *  been taken.
 *
 *  AckedState when FALSE indicates that the Condition instance requires
 *  acknowledgement for the reported Condition state. When the Condition instance
 *  is acknowledged the AckedState is set to TRUE. ConfirmedState indicates whether
 *  it requires confirmation. The two states are substates of the TRUE
 *  EnabledState. The EventId used in the Event Notification is considered the
 *  identifier of this state and has to be used when calling the Methods for
 *  acknowledgement or confirmation.
 *
 *  A Server may require that previous states be acknowledged. If the
 *  acknowledgement of a previous state is still open and a new state also requires
 *  acknowledgement, the Server shall create a branch of the Condition instance. In
 *  situations where state changes occur in short succession there can be multiple
 *  unacknowledged states and the Server has to maintain ConditionBranches for all
 *  previous unacknowledged states. These branches will be deleted after they have
 *  been acknowledged or if they reached their final state. Clients are expected to
 *  keep track of all ConditionBranches where AckedState is FALSE to allow
 *  acknowledgement of those. See also \ref OpcUa::ConditionTypeData
 *  "ConditionTypeData" for more information about ConditionBranches and the
 *  examples in Annex B.1 of Part 9 of the OPC UA Specification. The handling of
 *  the AckedState and branches also applies to the ConfirmState.
 *
 *  See also \ref Doc_OpcUa_AcknowledgeableConditionType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AcknowledgeableConditionType:
    public AcknowledgeableConditionTypeBase
{
    UA_DISABLE_COPY(AcknowledgeableConditionType);
protected:
    // destruction
    virtual ~AcknowledgeableConditionType();
public:
    // construction
    AcknowledgeableConditionType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    AcknowledgeableConditionType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    AcknowledgeableConditionType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    // UaAcknowledgeableConditionType method Acknowledge
    virtual UaStatus Acknowledge(
        const ServiceContext& serviceContext,
        UaByteString& EventId,
        const UaLocalizedText& Comment);
    // UaAcknowledgeableConditionType method Confirm
    virtual UaStatus Confirm(
        const ServiceContext& serviceContext,
        UaByteString& EventId,
        const UaLocalizedText& Comment);

    static void addAckedStateLocale(const UaLocalizedText& falseName, const UaLocalizedText& trueName);
    static void addConfirmedStateLocale(const UaLocalizedText& falseName, const UaLocalizedText& trueName);

    static void createTypes();
    static void clearStaticMembers();

    // Overwrite to add additional initialization
    virtual void setConfirmedState(OpcUa_Boolean confirmedState);
    virtual void setAckedState(OpcUa_Boolean ackedState);
protected:

private:
    void initialize();
private:
    static bool                  s_typeNodesCreated;
    static TwoStateDisplayNames* s_pAckedStateDisplayNames;
    static TwoStateDisplayNames* s_pConfirmedStateDisplayNames;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUAACKNOWLEDGEABLECONDITIONTYPE_H__

