/******************************************************************************
** opcua_offnormalalarmtype.h
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

#ifndef __OPCUA_OFFNORMALALARMTYPE_H__
#define __OPCUA_OFFNORMALALARMTYPE_H__

#include "opcua_offnormalalarmtypebase.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {


/** @brief Class implementing the UaObject interface for the OffNormalAlarmType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Variable members of the OffNormalAlarmType:**
 *
 *  Browse Name | DataType | TypeDefinition | Modelling Rule | See Also
 *  ------------|----------|----------------|----------------|---------------------------------------------------------------------------------------------------------------------------
 *  NormalState | NodeId   | PropertyType   | Mandatory      | \ref OffNormalAlarmTypeBase::getNormalState "getNormalState", \ref OffNormalAlarmTypeBase::setNormalState "setNormalState"
 *
 *  A specialization of the DiscreteAlarmType intended to represent a discrete
 *  Condition that is considered to be not normal.
 *
 *  This subtype is usually used to indicate that a discrete value is in an Alarm
 *  state, it is active as long as a non-normal value is present.
 *
 *  See also \ref Doc_OpcUa_OffNormalAlarmType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT OffNormalAlarmType:
    public OffNormalAlarmTypeBase
{
    UA_DISABLE_COPY(OffNormalAlarmType);
protected:
    // destruction
    virtual ~OffNormalAlarmType();
public:
    // construction
    OffNormalAlarmType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    OffNormalAlarmType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    OffNormalAlarmType(
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

#endif // #ifndef __OPCUAOFFNORMALALARMTYPE_H__

