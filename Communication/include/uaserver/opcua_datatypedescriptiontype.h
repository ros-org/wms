/******************************************************************************
** opcua_datatypedescriptiontype.h
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

#ifndef __OPCUA_DATATYPEDESCRIPTIONTYPE_H__
#define __OPCUA_DATATYPEDESCRIPTIONTYPE_H__

#include "opcua_basedatavariabletype.h"
#include "opcua_identifiers.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;

/** Implements OPC UA Variables of the type DataTypeDescriptionType
 *
 *  **Variable members of the DataTypeDescriptionType:**
 *
 *  Browse Name        | DataType   | TypeDefinition | Modelling Rule | See Also
 *  -------------------|------------|----------------|----------------|-------------------------------------------------------
 *  DataTypeVersion    | String     | PropertyType   | Optional       | \ref getDataTypeVersion, \ref setDataTypeVersion
 *  DictionaryFragment | ByteString | PropertyType   | Optional       | \ref getDictionaryFragment, \ref setDictionaryFragment
 *
 *  Used as the type for the DataTypeDescriptions.
 *
 *  There are no References specified for this VariableType. It defines the
 *  optional properties DataTypeVersion and DictionaryFragment.
 *
 *  DataTypeVersion indicates whether the type description of the DataType has
 *  changed. Changes to the DataTypeVersion may impact the operation of
 *  Subscriptions. If the DataTypeVersion changes for a Variable that is being
 *  monitored for a Subscription and that uses this DataTypeDescription, then the
 *  next data change Notification sent for the Variable will contain a status that
 *  indicates the change in the DataTypeDescription.
 *
 *  In some scenarios an OPC UA Server may have resource limitations which make it
 *  impractical to expose large DataTypeDictionaries. In these scenarios the Server
 *  may be able to provide access to descriptions for individual DataTypes even if
 *  the entire dictionary cannot be read. For this reason, this standard defines a
 *  Property for the DataTypeDescription called DictionaryFragment. This Property
 *  is a ByteString that contains a subset of the DataTypeDictionary which
 *  describes the format of the DataType associated with the DataTypeDescription.
 *  Thus, the Server splits the large DataTypeDictionary into several small parts
 *  and Clients can access without affecting the overall system performance.
 *
 *  See also \ref Doc_OpcUa_DataTypeDescriptionType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT DataTypeDescriptionType:
    public OpcUa::BaseDataVariableType
{
    UA_DISABLE_COPY(DataTypeDescriptionType);
protected:
    virtual ~DataTypeDescriptionType();
public:
    DataTypeDescriptionType(
        UaNode*            pParentNode,
        UaVariable*        pInstanceDeclarationVariable,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    DataTypeDescriptionType(
        const UaNodeId&    nodeId,
        const UaString&    name,
        OpcUa_UInt16       browseNameNameSpaceIndex,
        const UaVariant&   initialValue,
        OpcUa_Byte         accessLevel,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    DataTypeDescriptionType(
        UaBase::Variable*  pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;

    virtual void setDataTypeVersion(const UaString& DataTypeVersion);
    virtual UaString getDataTypeVersion() const;

    virtual void setDictionaryFragment(UaByteString& DictionaryFragment);
    virtual UaByteString getDictionaryFragment() const;

    virtual OpcUa::PropertyType* getDataTypeVersionNode();
    virtual OpcUa::PropertyType* getDictionaryFragmentNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(DataTypeDescriptionType *pInstance);

protected:
    // Variable nodes
    // Variable DataTypeVersion
    static OpcUa::PropertyType*  s_pDataTypeVersion;
    OpcUa::PropertyType*  m_pDataTypeVersion;
    // Variable DictionaryFragment
    static OpcUa::PropertyType*  s_pDictionaryFragment;
    OpcUa::PropertyType*  m_pDictionaryFragment;


private:
    void initialize(NodeManagerConfig* pNodeConfig);

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUA_DATATYPEDESCRIPTIONTYPE_H__

