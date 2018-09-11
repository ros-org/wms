/******************************************************************************
** opcua_datatypedictionarytype.h
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

#ifndef __OPCUA_DATATYPEDICTIONARYTYPE_H__
#define __OPCUA_DATATYPEDICTIONARYTYPE_H__

#include "opcua_basedatavariabletype.h"
#include "opcua_identifiers.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;

/** Implements OPC UA Variables of the type DataTypeDictionaryType
 *
 *  **Variable members of the DataTypeDictionaryType:**
 *
 *  Browse Name     | DataType | TypeDefinition | Modelling Rule | See Also
 *  ----------------|----------|----------------|----------------|-------------------------------------------------
 *  DataTypeVersion | String   | PropertyType   | Optional       | \ref getDataTypeVersion, \ref setDataTypeVersion
 *  NamespaceUri    | String   | PropertyType   | Optional       | \ref getNamespaceUri, \ref setNamespaceUri
 *
 *  This VariableType is used as the type for the DataTypeDictionaries.
 *
 *  There are no References specified for this VariableType. It defines the
 *  optional properties DataTypeVersion and NamespaceUri.
 *
 *  Changes in DataTypeDictionaries may be a result of a change to a type
 *  description, but it is more likely that dictionary changes are a result of the
 *  addition or deletion of type descriptions. This includes changes made while the
 *  Server is offline so that the new version is available when the Server
 *  restarts. Clients may subscribe to the DataTypeVersion Property to determine if
 *  the DataTypeDictionary has changed since it was last read.
 *
 *  See also \ref Doc_OpcUa_DataTypeDictionaryType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT DataTypeDictionaryType:
    public OpcUa::BaseDataVariableType
{
    UA_DISABLE_COPY(DataTypeDictionaryType);
protected:
    virtual ~DataTypeDictionaryType();
public:
    DataTypeDictionaryType(
        UaNode*            pParentNode,
        UaVariable*        pInstanceDeclarationVariable,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    DataTypeDictionaryType(
        const UaNodeId&    nodeId,
        const UaString&    name,
        OpcUa_UInt16       browseNameNameSpaceIndex,
        const UaVariant&   initialValue,
        OpcUa_Byte         accessLevel,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    DataTypeDictionaryType(
        UaBase::Variable*  pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;

    virtual void setDataTypeVersion(const UaString& DataTypeVersion);
    virtual UaString getDataTypeVersion() const;

    virtual void setNamespaceUri(const UaString& NamespaceUri);
    virtual UaString getNamespaceUri() const;

    virtual OpcUa::PropertyType* getDataTypeVersionNode();
    virtual OpcUa::PropertyType* getNamespaceUriNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(DataTypeDictionaryType *pInstance);

protected:
    // Variable nodes
    // Variable DataTypeVersion
    static OpcUa::PropertyType*  s_pDataTypeVersion;
    OpcUa::PropertyType*  m_pDataTypeVersion;
    // Variable NamespaceUri
    static OpcUa::PropertyType*  s_pNamespaceUri;
    OpcUa::PropertyType*  m_pNamespaceUri;


private:
    void initialize(NodeManagerConfig* pNodeConfig);

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUA_DATATYPEDICTIONARYTYPE_H__

