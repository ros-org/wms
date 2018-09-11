/******************************************************************************
** opcua_limitalarmtype.h
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

#ifndef __OPCUA_LIMITALARMTYPE_H__
#define __OPCUA_LIMITALARMTYPE_H__

#include "opcua_limitalarmtypebase.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {


/** @brief Class implementing the UaObject interface for the LimitAlarmType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Variable members of the LimitAlarmType:**
 *
 *  Browse Name   | DataType | TypeDefinition | Modelling Rule | See Also
 *  --------------|----------|----------------|----------------|---------------------------------------------------------------------------------------------------------------------------
 *  HighHighLimit | Double   | PropertyType   | Optional       | \ref LimitAlarmTypeBase::getHighHighLimit "getHighHighLimit", \ref LimitAlarmTypeBase::setHighHighLimit "setHighHighLimit"
 *  HighLimit     | Double   | PropertyType   | Optional       | \ref LimitAlarmTypeBase::getHighLimit "getHighLimit", \ref LimitAlarmTypeBase::setHighLimit "setHighLimit"
 *  LowLimit      | Double   | PropertyType   | Optional       | \ref LimitAlarmTypeBase::getLowLimit "getLowLimit", \ref LimitAlarmTypeBase::setLowLimit "setLowLimit"
 *  LowLowLimit   | Double   | PropertyType   | Optional       | \ref LimitAlarmTypeBase::getLowLowLimit "getLowLowLimit", \ref LimitAlarmTypeBase::setLowLowLimit "setLowLowLimit"
 *
 *  An abstract type used to provide a base Type for AlarmConditions with multiple
 *  limits
 *
 *  Alarms can be modelled with multiple exclusive substates and assigned limits or
 *  they may be modelled with non exclusive limits that can be used to group
 *  multiple states together.
 *
 *  Four optional limits are defined that configure the states of the derived limit
 *  Alarm Types: HighHighLimit, HighLimit, LowLimit, and LowLowLimit. These
 *  Properties shall be set for any Alarm limits that are exposed by the derived
 *  limit Alarm Types. These Properties are listed as optional but at least one is
 *  required. For cases where an underlying system cannot provide the actual value
 *  of a limit, the limit Property shall still be provided, but will have its
 *  AccessLevel set to not readable. It is assumed that the limits are described
 *  using the same Engineering Unit that is assigned to the variable that is the
 *  source of the alarm. For Rate of change limit alarms, it is assumed this rate
 *  is units per second unless otherwise specified.
 *
 *  The Alarm limits listed may cause an Alarm to be generated when a value equals
 *  the limit or it may generate the Alarm when the limit is exceeded, (i.e. the
 *  Value is above the limit for HighLimit and below the limit for LowLimit). The
 *  exact behaviour when the value is equal to the limit is Server specific.
 *
 *  See also \ref Doc_OpcUa_LimitAlarmType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT LimitAlarmType:
    public LimitAlarmTypeBase
{
    UA_DISABLE_COPY(LimitAlarmType);
protected:
    // destruction
    virtual ~LimitAlarmType();
public:
    // construction
    LimitAlarmType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    LimitAlarmType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    LimitAlarmType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();


protected:

private:
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUALIMITALARMTYPE_H__

