/******************************************************************************
** opcua_historyservercapabilitiestype.h
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
#ifndef __OPCUA_HISTORYSERVERCAPABILITIESTYPE_H__
#define __OPCUA_HISTORYSERVERCAPABILITIESTYPE_H__

#include "opcua_baseobjecttype.h"
#include "opcua_identifiers.h"
#include "opcua_propertytype.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class FolderType;

/** @brief Class implementing the UaObject interface for the HistoryServerCapabilitiesType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Object members of the HistoryServerCapabilitiesType:**
 *
 *  Browse Name        | TypeDefinition | Modelling Rule | See Also
 *  -------------------|----------------|----------------|--------------------------------------------------------------------------------------
 *  AggregateFunctions | FolderType     | Mandatory      | &nbsp;
 *
 *  **Variable members of the HistoryServerCapabilitiesType:**
 *
 *  Browse Name                   | DataType | TypeDefinition | Modelling Rule | See Also
 *  ------------------------------|----------|----------------|----------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *  AccessHistoryDataCapability   | Boolean  | PropertyType   | Mandatory      | \ref getAccessHistoryDataCapability, \ref setAccessHistoryDataCapability
 *  AccessHistoryEventsCapability | Boolean  | PropertyType   | Mandatory      | \ref getAccessHistoryEventsCapability, \ref setAccessHistoryEventsCapability
 *  DeleteAtTimeCapability        | Boolean  | PropertyType   | Mandatory      | \ref getDeleteAtTimeCapability, \ref setDeleteAtTimeCapability
 *  DeleteEventCapability         | Boolean  | PropertyType   | Mandatory      | \ref getDeleteEventCapability, \ref setDeleteEventCapability
 *  DeleteRawCapability           | Boolean  | PropertyType   | Mandatory      | \ref getDeleteRawCapability, \ref setDeleteRawCapability
 *  InsertAnnotationCapability    | Boolean  | PropertyType   | Mandatory      | \ref getInsertAnnotationCapability, \ref setInsertAnnotationCapability
 *  InsertDataCapability          | Boolean  | PropertyType   | Mandatory      | \ref getInsertDataCapability, \ref setInsertDataCapability
 *  InsertEventCapability         | Boolean  | PropertyType   | Mandatory      | \ref getInsertEventCapability, \ref setInsertEventCapability
 *  MaxReturnDataValues           | UInt32   | PropertyType   | Mandatory      | \ref getMaxReturnDataValues, \ref setMaxReturnDataValues
 *  MaxReturnEventValues          | UInt32   | PropertyType   | Mandatory      | \ref getMaxReturnEventValues, \ref setMaxReturnEventValues
 *  ReplaceDataCapability         | Boolean  | PropertyType   | Mandatory      | \ref getReplaceDataCapability, \ref setReplaceDataCapability
 *  ReplaceEventCapability        | Boolean  | PropertyType   | Mandatory      | \ref getReplaceEventCapability, \ref setReplaceEventCapability
 *  UpdateDataCapability          | Boolean  | PropertyType   | Mandatory      | \ref getUpdateDataCapability, \ref setUpdateDataCapability
 *  UpdateEventCapability         | Boolean  | PropertyType   | Mandatory      | \ref getUpdateEventCapability, \ref setUpdateEventCapability
 *
 *  The ServerCapabilitiesType Objects for any
 *  OPC UA Server supporting Historical Access shall contain a Reference to a
 *  HistoryServerCapabilitiesType Object.
 *
 *  The content of this \ref OpcUa::BaseObjectType "BaseObjectType" is already
 *  defined by its type definition in Part 5 of the OPC UA Specification.
 *
 *  The object extensions are intended to inform a Client of the general
 *  capabilities of the server. They do not guarantee that all capabilities will be
 *  available for all Nodes. For example, not all Nodes will support Events, or in
 *  the case of an aggregating server where underlying servers may not support
 *  Insert or a particular Aggregate. In such cases, the HistoryServerCapabilities
 *  Property would indicate the capability is supported, and the server would
 *  return appropriate StatusCodes for situations where the capability does not
 *  apply.
 *
 *  All UA servers that support Historical access shall include the
 *  HistoryServerCapabilities as part of its ServerCapabilities.
 *
 *  See also \ref Doc_OpcUa_HistoryServerCapabilitiesType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT HistoryServerCapabilitiesType:
    public OpcUa::BaseObjectType
{
    UA_DISABLE_COPY(HistoryServerCapabilitiesType);
protected:
    virtual ~HistoryServerCapabilitiesType();
public:
    // construction / destruction
    HistoryServerCapabilitiesType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    HistoryServerCapabilitiesType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;

    // Creat aggregate functions
    void createDefaultAggregateFunctions();
    // AccessHistoryDataCapability
    virtual void setAccessHistoryDataCapability(OpcUa_Boolean AccessHistoryDataCapability);
    virtual OpcUa_Boolean getAccessHistoryDataCapability() const;
    // AccessHistoryEventsCapability
    virtual void setAccessHistoryEventsCapability(OpcUa_Boolean AccessHistoryEventsCapability);
    virtual OpcUa_Boolean getAccessHistoryEventsCapability() const;
    // DeleteAtTimeCapability
    virtual void setDeleteAtTimeCapability(OpcUa_Boolean DeleteAtTimeCapability);
    virtual OpcUa_Boolean getDeleteAtTimeCapability() const;
    // DeleteEventCapability
    virtual void setDeleteEventCapability(OpcUa_Boolean DeleteEventCapability);
    virtual OpcUa_Boolean getDeleteEventCapability() const;
    // DeleteRawCapability
    virtual void setDeleteRawCapability(OpcUa_Boolean DeleteRawCapability);
    virtual OpcUa_Boolean getDeleteRawCapability() const;
    // InsertAnnotationCapability
    virtual void setInsertAnnotationCapability(OpcUa_Boolean InsertAnnotationCapability);
    virtual OpcUa_Boolean getInsertAnnotationCapability() const;
    // InsertDataCapability
    virtual void setInsertDataCapability(OpcUa_Boolean InsertDataCapability);
    virtual OpcUa_Boolean getInsertDataCapability() const;
    // InsertEventCapability
    virtual void setInsertEventCapability(OpcUa_Boolean InsertEventCapability);
    virtual OpcUa_Boolean getInsertEventCapability() const;
    // MaxReturnDataValues
    virtual void setMaxReturnDataValues(OpcUa_UInt32 MaxReturnDataValues);
    virtual OpcUa_UInt32 getMaxReturnDataValues() const;
    // MaxReturnEventValues
    virtual void setMaxReturnEventValues(OpcUa_UInt32 MaxReturnEventValues);
    virtual OpcUa_UInt32 getMaxReturnEventValues() const;
    // ReplaceDataCapability
    virtual void setReplaceDataCapability(OpcUa_Boolean ReplaceDataCapability);
    virtual OpcUa_Boolean getReplaceDataCapability() const;
    // ReplaceEventCapability
    virtual void setReplaceEventCapability(OpcUa_Boolean ReplaceEventCapability);
    virtual OpcUa_Boolean getReplaceEventCapability() const;
    // UpdateDataCapability
    virtual void setUpdateDataCapability(OpcUa_Boolean UpdateDataCapability);
    virtual OpcUa_Boolean getUpdateDataCapability() const;
    // UpdateEventCapability
    virtual void setUpdateEventCapability(OpcUa_Boolean UpdateEventCapability);
    virtual OpcUa_Boolean getUpdateEventCapability() const;
protected:
    // Object nodes
    // Object AggregateFunctions
    static OpcUa::FolderType*  s_pAggregateFunctions;
    OpcUa::FolderType*  m_pAggregateFunctions;

    // Variable AccessHistoryDataCapability
    static OpcUa::PropertyType*  s_pAccessHistoryDataCapability;
    OpcUa::PropertyType*  m_pAccessHistoryDataCapability;
    // Variable AccessHistoryEventsCapability
    static OpcUa::PropertyType*  s_pAccessHistoryEventsCapability;
    OpcUa::PropertyType*  m_pAccessHistoryEventsCapability;
    // Variable DeleteAtTimeCapability
    static OpcUa::PropertyType*  s_pDeleteAtTimeCapability;
    OpcUa::PropertyType*  m_pDeleteAtTimeCapability;
    // Variable DeleteEventCapability
    static OpcUa::PropertyType*  s_pDeleteEventCapability;
    OpcUa::PropertyType*  m_pDeleteEventCapability;
    // Variable DeleteRawCapability
    static OpcUa::PropertyType*  s_pDeleteRawCapability;
    OpcUa::PropertyType*  m_pDeleteRawCapability;
    // Variable InsertAnnotationCapability
    static OpcUa::PropertyType*  s_pInsertAnnotationCapability;
    OpcUa::PropertyType*  m_pInsertAnnotationCapability;
    // Variable InsertDataCapability
    static OpcUa::PropertyType*  s_pInsertDataCapability;
    OpcUa::PropertyType*  m_pInsertDataCapability;
    // Variable InsertEventCapability
    static OpcUa::PropertyType*  s_pInsertEventCapability;
    OpcUa::PropertyType*  m_pInsertEventCapability;
    // Variable MaxReturnDataValues
    static OpcUa::PropertyType*  s_pMaxReturnDataValues;
    OpcUa::PropertyType*  m_pMaxReturnDataValues;
    // Variable MaxReturnEventValues
    static OpcUa::PropertyType*  s_pMaxReturnEventValues;
    OpcUa::PropertyType*  m_pMaxReturnEventValues;
    // Variable ReplaceDataCapability
    static OpcUa::PropertyType*  s_pReplaceDataCapability;
    OpcUa::PropertyType*  m_pReplaceDataCapability;
    // Variable ReplaceEventCapability
    static OpcUa::PropertyType*  s_pReplaceEventCapability;
    OpcUa::PropertyType*  m_pReplaceEventCapability;
    // Variable UpdateDataCapability
    static OpcUa::PropertyType*  s_pUpdateDataCapability;
    OpcUa::PropertyType*  m_pUpdateDataCapability;
    // Variable UpdateEventCapability
    static OpcUa::PropertyType*  s_pUpdateEventCapability;
    OpcUa::PropertyType*  m_pUpdateEventCapability;

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(HistoryServerCapabilitiesType *pInstance);

protected:

private:
    void initialize();

private:
    static bool s_typeNodesCreated;
    static bool s_aggregateNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUAHISTORYSERVERCAPABILITIESTYPE_H__
