/******************************************************************************
** opcua_historicaldataconfigurationtype.h
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

#ifndef __OPCUA_HISTORICALDATACONFIGURATIONTYPE_H__
#define __OPCUA_HISTORICALDATACONFIGURATIONTYPE_H__

#include "opcua_historicaldataconfigurationtypebase.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {


/** @brief Class implementing the UaObject interface for the HistoricalDataConfigurationType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Object members of the HistoricalDataConfigurationType:**
 *
 *  Browse Name            | TypeDefinition             | Modelling Rule | See Also
 *  -----------------------|----------------------------|----------------|------------------------------------------------------------------------------------------------
 *  AggregateConfiguration | AggregateConfigurationType | Mandatory      | \ref HistoricalDataConfigurationTypeBase::getAggregateConfiguration "getAggregateConfiguration"
 *  AggregateFunctions     | FolderType                 | Optional       | \ref HistoricalDataConfigurationTypeBase::getAggregateFunctions "getAggregateFunctions"
 *
 *  **Variable members of the HistoricalDataConfigurationType:**
 *
 *  Browse Name              | DataType                 | TypeDefinition | Modelling Rule | See Also
 *  -------------------------|--------------------------|----------------|----------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *  Definition               | String                   | PropertyType   | Optional       | \ref HistoricalDataConfigurationTypeBase::getDefinition "getDefinition", \ref HistoricalDataConfigurationTypeBase::setDefinition "setDefinition"
 *  ExceptionDeviation       | Double                   | PropertyType   | Optional       | \ref HistoricalDataConfigurationTypeBase::getExceptionDeviation "getExceptionDeviation", \ref HistoricalDataConfigurationTypeBase::setExceptionDeviation "setExceptionDeviation"
 *  ExceptionDeviationFormat | ExceptionDeviationFormat | PropertyType   | Optional       | \ref HistoricalDataConfigurationTypeBase::getExceptionDeviationFormat "getExceptionDeviationFormat", \ref HistoricalDataConfigurationTypeBase::setExceptionDeviationFormat "setExceptionDeviationFormat"
 *  MaxTimeInterval          | Duration                 | PropertyType   | Optional       | \ref HistoricalDataConfigurationTypeBase::getMaxTimeInterval "getMaxTimeInterval", \ref HistoricalDataConfigurationTypeBase::setMaxTimeInterval "setMaxTimeInterval"
 *  MinTimeInterval          | Duration                 | PropertyType   | Optional       | \ref HistoricalDataConfigurationTypeBase::getMinTimeInterval "getMinTimeInterval", \ref HistoricalDataConfigurationTypeBase::setMinTimeInterval "setMinTimeInterval"
 *  StartOfArchive           | UtcTime                  | PropertyType   | Optional       | \ref HistoricalDataConfigurationTypeBase::getStartOfArchive "getStartOfArchive", \ref HistoricalDataConfigurationTypeBase::setStartOfArchive "setStartOfArchive"
 *  StartOfOnlineArchive     | UtcTime                  | PropertyType   | Optional       | \ref HistoricalDataConfigurationTypeBase::getStartOfOnlineArchive "getStartOfOnlineArchive", \ref HistoricalDataConfigurationTypeBase::setStartOfOnlineArchive "setStartOfOnlineArchive"
 *  Stepped                  | Boolean                  | PropertyType   | Mandatory      | \ref HistoricalDataConfigurationTypeBase::getStepped "getStepped", \ref HistoricalDataConfigurationTypeBase::setStepped "setStepped"
 *
 */
class SERVER_CORE_EXPORT HistoricalDataConfigurationType:
    public HistoricalDataConfigurationTypeBase
{
    UA_DISABLE_COPY(HistoricalDataConfigurationType);
protected:
    // destruction
    virtual ~HistoricalDataConfigurationType();
public:
    // construction
    HistoricalDataConfigurationType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    HistoricalDataConfigurationType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    HistoricalDataConfigurationType(
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

#endif // #ifndef __OPCUAHISTORICALDATACONFIGURATIONTYPE_H__

