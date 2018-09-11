/******************************************************************************
** opcua_dataitemtype.h
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

#ifndef __OPCUA_DATAITEMTYPE_H__
#define __OPCUA_DATAITEMTYPE_H__

#include "opcua_basedatavariabletype.h"
#include "opcua_identifiers.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;

/** Implements OPC UA Variables of the type DataItemType
 *
 *  **Variable members of the DataItemType:**
 *
 *  Browse Name    | DataType | TypeDefinition | Modelling Rule | See Also
 *  ---------------|----------|----------------|----------------|-----------------------------------------------
 *  Definition     | String   | PropertyType   | Optional       | \ref getDefinition, \ref setDefinition
 *  ValuePrecision | Double   | PropertyType   | Optional       | \ref getValuePrecision, \ref setValuePrecision
 *
 *  This VariableType defines the general characteristics of a DataItem.
 *
 *  All other DataItem Types derive from it. It defines the optional properties
 *  Definition and ValuePrecision. The DataItemType derives from the
 *  BaseDataVariableType.
 *
 *  See also \ref Doc_OpcUa_DataItemType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT DataItemType:
    public OpcUa::BaseDataVariableType
{
    UA_DISABLE_COPY(DataItemType);
protected:
    virtual ~DataItemType();
public:
    DataItemType(
        UaNode*            pParentNode,
        UaVariable*        pInstanceDeclarationVariable,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    DataItemType(
        const UaNodeId&    nodeId,
        const UaString&    name,
        OpcUa_UInt16       browseNameNameSpaceIndex,
        const UaVariant&   initialValue,
        OpcUa_Byte         accessLevel,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    DataItemType(
        UaBase::Variable*  pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;

    virtual void setDefinition(const UaString& Definition);
    virtual UaString getDefinition() const;

    virtual void setValuePrecision(OpcUa_Double ValuePrecision);
    virtual OpcUa_Double getValuePrecision() const;

    virtual OpcUa::PropertyType* getDefinitionNode();
    virtual OpcUa::PropertyType* getValuePrecisionNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(DataItemType *pInstance);

protected:
    // Variable nodes
    // Variable Definition
    static OpcUa::PropertyType*  s_pDefinition;
    OpcUa::PropertyType*  m_pDefinition;
    // Variable ValuePrecision
    static OpcUa::PropertyType*  s_pValuePrecision;
    OpcUa::PropertyType*  m_pValuePrecision;


private:
    void initialize(NodeManagerConfig* pNodeConfig);

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUA_DATAITEMTYPE_H__

