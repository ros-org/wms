/******************************************************************************
** opcua_nonexclusivelimitalarmtype.h
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

#ifndef __OPCUA_NONEXCLUSIVELIMITALARMTYPE_H__
#define __OPCUA_NONEXCLUSIVELIMITALARMTYPE_H__

#include "opcua_nonexclusivelimitalarmtypebase.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {


/** @brief Class implementing the UaObject interface for the NonExclusiveLimitAlarmType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Variable members of the NonExclusiveLimitAlarmType:**
 *
 *  Browse Name   | DataType      | TypeDefinition       | Modelling Rule | See Also
 *  --------------|---------------|----------------------|----------------|---------------------------------------------------------------------------------------------------------------------------------------------------
 *  ActiveState   | LocalizedText | TwoStateVariableType | Mandatory      | \ref NonExclusiveLimitAlarmTypeBase::getActiveState "getActiveState", \ref NonExclusiveLimitAlarmTypeBase::setActiveState "setActiveState"
 *  HighHighState | LocalizedText | TwoStateVariableType | Optional       | \ref NonExclusiveLimitAlarmTypeBase::getHighHighState "getHighHighState", \ref NonExclusiveLimitAlarmTypeBase::setHighHighState "setHighHighState"
 *  HighState     | LocalizedText | TwoStateVariableType | Optional       | \ref NonExclusiveLimitAlarmTypeBase::getHighState "getHighState", \ref NonExclusiveLimitAlarmTypeBase::setHighState "setHighState"
 *  LowLowState   | LocalizedText | TwoStateVariableType | Optional       | \ref NonExclusiveLimitAlarmTypeBase::getLowLowState "getLowLowState", \ref NonExclusiveLimitAlarmTypeBase::setLowLowState "setLowLowState"
 *  LowState      | LocalizedText | TwoStateVariableType | Optional       | \ref NonExclusiveLimitAlarmTypeBase::getLowState "getLowState", \ref NonExclusiveLimitAlarmTypeBase::setLowState "setLowState"
 *
 *  Used to specify the common behaviour for Alarm Types with multiple
 *  non-exclusive limits
 *
 *  HighHighState, HighState, LowState, and LowLowState represent the non-exclusive
 *  states. As an example, it is possible that both HighState and HighHighState are
 *  in their TRUE state. Vendors may choose to support any subset of these states.
 *
 *  Four optional limits are defined that configure these states. At least the
 *  HighState or the LowState shall be provided even though all states are
 *  optional. It is implied by the definition of a HighState and a LowState, that
 *  these groupings are mutually exclusive. A value cannot exceed both a HighState
 *  value and a LowState value simultaneously.
 *
 *  See also \ref Doc_OpcUa_NonExclusiveLimitAlarmType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT NonExclusiveLimitAlarmType:
    public NonExclusiveLimitAlarmTypeBase
{
    UA_DISABLE_COPY(NonExclusiveLimitAlarmType);
protected:
    // destruction
    virtual ~NonExclusiveLimitAlarmType();
public:
    // construction
    NonExclusiveLimitAlarmType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    NonExclusiveLimitAlarmType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    NonExclusiveLimitAlarmType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    virtual void getActiveState_EffectiveDisplayNameValue(Session* pSession, OpcUa_Variant& value);
    static void createTypes();
    static void clearStaticMembers();

    // Overwrite to add additional initialization
    virtual void setHighHighState(OpcUa_Boolean highHighState);
    virtual void setHighState(OpcUa_Boolean highState);
    virtual void setLowLowState(OpcUa_Boolean lowLowState);
    virtual void setLowState(OpcUa_Boolean lowState);
protected:

private:
    void initialize();

private:
    static TwoStateDisplayNames* s_pHighHighStateDisplayNames;
    static TwoStateDisplayNames* s_pHighStateDisplayNames;
    static TwoStateDisplayNames* s_pLowStateDisplayNames;
    static TwoStateDisplayNames* s_pLowLowStateDisplayNames;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUANONEXCLUSIVELIMITALARMTYPE_H__

