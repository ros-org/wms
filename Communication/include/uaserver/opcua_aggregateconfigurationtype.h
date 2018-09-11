/******************************************************************************
** opcua_aggregateconfigurationtype.h
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

#ifndef __OPCUA_AGGREGATECONFIGURATIONTYPE_H__
#define __OPCUA_AGGREGATECONFIGURATIONTYPE_H__

#include "opcua_aggregateconfigurationtypebase.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {


/** @brief Class implementing the UaObject interface for the AggregateConfigurationType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Variable members of the AggregateConfigurationType:**
 *
 *  Browse Name            | DataType | TypeDefinition | Modelling Rule | See Also
 *  -----------------------|----------|----------------|----------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *  PercentDataBad         | Byte     | PropertyType   | Mandatory      | \ref AggregateConfigurationTypeBase::getPercentDataBad "getPercentDataBad", \ref AggregateConfigurationTypeBase::setPercentDataBad "setPercentDataBad"
 *  PercentDataGood        | Byte     | PropertyType   | Mandatory      | \ref AggregateConfigurationTypeBase::getPercentDataGood "getPercentDataGood", \ref AggregateConfigurationTypeBase::setPercentDataGood "setPercentDataGood"
 *  TreatUncertainAsBad    | Boolean  | PropertyType   | Mandatory      | \ref AggregateConfigurationTypeBase::getTreatUncertainAsBad "getTreatUncertainAsBad", \ref AggregateConfigurationTypeBase::setTreatUncertainAsBad "setTreatUncertainAsBad"
 *  UseSlopedExtrapolation | Boolean  | PropertyType   | Mandatory      | \ref AggregateConfigurationTypeBase::getUseSlopedExtrapolation "getUseSlopedExtrapolation", \ref AggregateConfigurationTypeBase::setUseSlopedExtrapolation "setUseSlopedExtrapolation"
 *
 */
class SERVER_CORE_EXPORT AggregateConfigurationType:
    public AggregateConfigurationTypeBase
{
    UA_DISABLE_COPY(AggregateConfigurationType);
protected:
    // destruction
    virtual ~AggregateConfigurationType();
public:
    // construction
    AggregateConfigurationType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    AggregateConfigurationType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    AggregateConfigurationType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    // Addition to generated code begin
    void intitialize();
    // Addition to generated code end

protected:
    // Addition to generated code begin
    static bool s_typeCreated;
    // Addition to generated code end

private:
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUAAGGREGATECONFIGURATIONTYPE_H__

