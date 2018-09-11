/******************************************************************************
** opcua_historicaldataconfigurationtypebase.h
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

#ifndef __OPCUA_HISTORICALDATACONFIGURATIONTYPEBASE_H__
#define __OPCUA_HISTORICALDATACONFIGURATIONTYPEBASE_H__

#include "opcua_baseobjecttype.h"
#include "basenodes.h"
#include "opcua_foldertype.h"
#include "opcua_identifiers.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class AggregateConfigurationType;
class FolderType;
class PropertyType;

/** Generated base class for a HistoricalDataConfigurationType.
 *
 *  This class contains the generated base code for the object type HistoricalDataConfigurationType
 *  representing an OPC UA ObjectType. This class is used to create the object type and to
 *  create and represent instances of the object type in the server address space.
 *
 *  **Object members of the HistoricalDataConfigurationType:**
 *
 *  Browse Name            | TypeDefinition             | Modelling Rule | See Also
 *  -----------------------|----------------------------|----------------|-------------------------------
 *  AggregateConfiguration | AggregateConfigurationType | Mandatory      | \ref getAggregateConfiguration
 *  AggregateFunctions     | FolderType                 | Optional       | \ref getAggregateFunctions
 *
 *  **Variable members of the HistoricalDataConfigurationType:**
 *
 *  Browse Name              | DataType                 | TypeDefinition | Modelling Rule | See Also
 *  -------------------------|--------------------------|----------------|----------------|-------------------------------------------------------------------
 *  Definition               | String                   | PropertyType   | Optional       | \ref getDefinition, \ref setDefinition
 *  ExceptionDeviation       | Double                   | PropertyType   | Optional       | \ref getExceptionDeviation, \ref setExceptionDeviation
 *  ExceptionDeviationFormat | ExceptionDeviationFormat | PropertyType   | Optional       | \ref getExceptionDeviationFormat, \ref setExceptionDeviationFormat
 *  MaxTimeInterval          | Duration                 | PropertyType   | Optional       | \ref getMaxTimeInterval, \ref setMaxTimeInterval
 *  MinTimeInterval          | Duration                 | PropertyType   | Optional       | \ref getMinTimeInterval, \ref setMinTimeInterval
 *  StartOfArchive           | UtcTime                  | PropertyType   | Optional       | \ref getStartOfArchive, \ref setStartOfArchive
 *  StartOfOnlineArchive     | UtcTime                  | PropertyType   | Optional       | \ref getStartOfOnlineArchive, \ref setStartOfOnlineArchive
 *  Stepped                  | Boolean                  | PropertyType   | Mandatory      | \ref getStepped, \ref setStepped
 *
 */
class SERVER_CORE_EXPORT HistoricalDataConfigurationTypeBase:
    public OpcUa::BaseObjectType
{
    UA_DISABLE_COPY(HistoricalDataConfigurationTypeBase);
protected:
    virtual ~HistoricalDataConfigurationTypeBase();
public:
    // construction / destruction
    HistoricalDataConfigurationTypeBase(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    HistoricalDataConfigurationTypeBase(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    HistoricalDataConfigurationTypeBase(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;


    virtual void setDefinition(const UaString& Definition);
    virtual UaString getDefinition() const;

    virtual void setExceptionDeviation(OpcUa_Double ExceptionDeviation);
    virtual OpcUa_Double getExceptionDeviation() const;

    virtual void setExceptionDeviationFormat(OpcUa_ExceptionDeviationFormat ExceptionDeviationFormat);
    virtual OpcUa_ExceptionDeviationFormat getExceptionDeviationFormat() const;

    virtual void setMaxTimeInterval(OpcUa_Double MaxTimeInterval);
    virtual OpcUa_Double getMaxTimeInterval() const;

    virtual void setMinTimeInterval(OpcUa_Double MinTimeInterval);
    virtual OpcUa_Double getMinTimeInterval() const;

    virtual void setStartOfArchive(const UaDateTime& StartOfArchive);
    virtual UaDateTime getStartOfArchive() const;

    virtual void setStartOfOnlineArchive(const UaDateTime& StartOfOnlineArchive);
    virtual UaDateTime getStartOfOnlineArchive() const;

    virtual void setStepped(OpcUa_Boolean Stepped);
    virtual OpcUa_Boolean getStepped() const;

    virtual OpcUa::AggregateConfigurationType* getAggregateConfiguration();
    virtual OpcUa::FolderType* getAggregateFunctions();
    virtual OpcUa::PropertyType* getDefinitionNode();
    virtual OpcUa::PropertyType* getExceptionDeviationNode();
    virtual OpcUa::PropertyType* getExceptionDeviationFormatNode();
    virtual OpcUa::PropertyType* getMaxTimeIntervalNode();
    virtual OpcUa::PropertyType* getMinTimeIntervalNode();
    virtual OpcUa::PropertyType* getStartOfArchiveNode();
    virtual OpcUa::PropertyType* getStartOfOnlineArchiveNode();
    virtual OpcUa::PropertyType* getSteppedNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(HistoricalDataConfigurationTypeBase *pInstance);

protected:
    // Object nodes
    // Object AggregateConfiguration
    static OpcUa::AggregateConfigurationType*  s_pAggregateConfiguration;
    OpcUa::AggregateConfigurationType*  m_pAggregateConfiguration;
    // Object AggregateFunctions
    static OpcUa::FolderType*  s_pAggregateFunctions;
    OpcUa::FolderType*  m_pAggregateFunctions;

    // Variable nodes
    // Variable Definition
    static OpcUa::PropertyType*  s_pDefinition;
    OpcUa::PropertyType*  m_pDefinition;
    // Variable ExceptionDeviation
    static OpcUa::PropertyType*  s_pExceptionDeviation;
    OpcUa::PropertyType*  m_pExceptionDeviation;
    // Variable ExceptionDeviationFormat
    static OpcUa::PropertyType*  s_pExceptionDeviationFormat;
    OpcUa::PropertyType*  m_pExceptionDeviationFormat;
    // Variable MaxTimeInterval
    static OpcUa::PropertyType*  s_pMaxTimeInterval;
    OpcUa::PropertyType*  m_pMaxTimeInterval;
    // Variable MinTimeInterval
    static OpcUa::PropertyType*  s_pMinTimeInterval;
    OpcUa::PropertyType*  m_pMinTimeInterval;
    // Variable StartOfArchive
    static OpcUa::PropertyType*  s_pStartOfArchive;
    OpcUa::PropertyType*  m_pStartOfArchive;
    // Variable StartOfOnlineArchive
    static OpcUa::PropertyType*  s_pStartOfOnlineArchive;
    OpcUa::PropertyType*  m_pStartOfOnlineArchive;
    // Variable Stepped
    static OpcUa::PropertyType*  s_pStepped;
    OpcUa::PropertyType*  m_pStepped;



private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUAHISTORICALDATACONFIGURATIONTYPEBASE_H__


