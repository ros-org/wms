/******************************************************************************
** opcuaplc_ctrltasktype.h
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
** Project: C++ OPC Server SDK information model for namespace http://PLCopen.org/OpcUa/IEC61131-3/
**
** Description: OPC Unified Architecture Software Development Kit.
**
******************************************************************************/

#ifndef __OPCUAPLC_CTRLTASKTYPE_H__
#define __OPCUAPLC_CTRLTASKTYPE_H__

#include "opcuaplc_ctrltasktypebase.h"

// Namespace for the UA information model http://PLCopen.org/OpcUa/IEC61131-3/
namespace OpcUaPlc {


/** @brief Class implementing the UaObject interface for the CtrlTaskType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Variable members of the CtrlTaskType:**
 *
 *  Browse Name | DataType | TypeDefinition | Modelling Rule | See Also
 *  ------------|----------|----------------|----------------|---------------------------------------------------------------------------------------------------
 *  Interval    | String   | PropertyType   | Optional       | \ref CtrlTaskTypeBase::getInterval "getInterval", \ref CtrlTaskTypeBase::setInterval "setInterval"
 *  Priority    | UInt32   | PropertyType   | Mandatory      | \ref CtrlTaskTypeBase::getPriority "getPriority", \ref CtrlTaskTypeBase::setPriority "setPriority"
 *  Single      | String   | PropertyType   | Optional       | \ref CtrlTaskTypeBase::getSingle "getSingle", \ref CtrlTaskTypeBase::setSingle "setSingle"
 *
 */
class UAMODELS_EXPORT CtrlTaskType:
    public CtrlTaskTypeBase
{
    UA_DISABLE_COPY(CtrlTaskType);
protected:
    // destruction
    virtual ~CtrlTaskType();
public:
    // construction
    CtrlTaskType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    CtrlTaskType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    CtrlTaskType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();


protected:

private:
};

} // End namespace for the UA information model http://PLCopen.org/OpcUa/IEC61131-3/

#endif // #ifndef __OPCUAPLCCTRLTASKTYPE_H__

