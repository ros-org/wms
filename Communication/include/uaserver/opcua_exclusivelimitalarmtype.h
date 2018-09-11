/******************************************************************************
** opcua_exclusivelimitalarmtype.h
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
#ifndef __OPCUA_EXCLUSIVELIMITALARMTYPE_H__
#define __OPCUA_EXCLUSIVELIMITALARMTYPE_H__

#include "opcua_limitalarmtype.h"
#include "opcua_identifiers.h"
#include "opcua_exclusivelimitalarmtypebase.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {


/** @brief Class implementing the UaObject interface for the ExclusiveLimitAlarmType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Object members of the ExclusiveLimitAlarmType:**
 *
 *  Browse Name | TypeDefinition                 | Modelling Rule | See Also
 *  ------------|--------------------------------|----------------|----------------------------------------------------------------
 *  LimitState  | ExclusiveLimitStateMachineType | Mandatory      | \ref ExclusiveLimitAlarmTypeBase::getLimitState "getLimitState"
 *
 *  **Variable members of the ExclusiveLimitAlarmType:**
 *
 *  Browse Name | DataType      | TypeDefinition       | Modelling Rule | See Also
 *  ------------|---------------|----------------------|----------------|-------------------------------------------------------------------------------------------------------------------------------------
 *  ActiveState | LocalizedText | TwoStateVariableType | Mandatory      | \ref ExclusiveLimitAlarmTypeBase::getActiveState "getActiveState", \ref ExclusiveLimitAlarmTypeBase::setActiveState "setActiveState"
 *
 *  Used to specify the common behaviour for Alarm Types with multiple mutually
 *  exclusive limits.
 *
 *  The LimitState is a Substate of the ActiveState and has a IsTrueSubstate
 *  reference to the ActiveState.
 *
 *  See also \ref Doc_OpcUa_ExclusiveLimitAlarmType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT ExclusiveLimitAlarmType:
    public ExclusiveLimitAlarmTypeBase
{
    UA_DISABLE_COPY(ExclusiveLimitAlarmType);
protected:
    // destruction
    virtual ~ExclusiveLimitAlarmType();
public:
    // construction
    ExclusiveLimitAlarmType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    ExclusiveLimitAlarmType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    ExclusiveLimitAlarmType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    virtual void getActiveState_EffectiveDisplayNameValue(Session* pSession, OpcUa_Variant& value);
    static void createTypes();
    static void clearStaticMembers();
    static void addStatesLocale(const UaLocalizedText& LowLowName, const UaLocalizedText& LowName, const UaLocalizedText& HighName, const UaLocalizedText& HighHighName);

    void setExclusiveState(ExclusiveLimitStateMachineType::ExclusiveState state);
    ExclusiveLimitStateMachineType::ExclusiveState getExclusiveState();

    static UaLocalizedText getLowLowName(Session* pSession);
    static UaLocalizedText getLowName(Session* pSession);
    static UaLocalizedText getHighName(Session* pSession);
    static UaLocalizedText getHighHighName(Session* pSession);

private:
    void initialize();

private:
    static bool s_typeNodesCreated;
    static UaLocalizedTextArray s_LowLowNames;
    static UaLocalizedTextArray s_LowNames;
    static UaLocalizedTextArray s_HighNames;
    static UaLocalizedTextArray s_HighHighNames;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUAEXCLUSIVELIMITALARMTYPE_H__


