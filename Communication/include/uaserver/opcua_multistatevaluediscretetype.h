/******************************************************************************
** opcua_multistatevaluediscretetype.h
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

#ifndef __OPCUA_MULTISTATEVALUEDISCRETETYPE_H__
#define __OPCUA_MULTISTATEVALUEDISCRETETYPE_H__

#include "opcua_discreteitemtype.h"
#include "opcua_identifiers.h"
#include "uaenumvaluetype.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;

/** Implements OPC UA Variables of the type MultiStateValueDiscreteType
 *
 *  **Variable members of the MultiStateValueDiscreteType:**
 *
 *  Browse Name | DataType      | TypeDefinition | Modelling Rule | See Also
 *  ------------|---------------|----------------|----------------|-----------------------------------------
 *  EnumValues  | EnumValueType | PropertyType   | Mandatory      | \ref getEnumValues, \ref setEnumValues
 *  ValueAsText | LocalizedText | PropertyType   | Mandatory      | \ref getValueAsText, \ref setValueAsText
 *
 *  This VariableType defines the general characteristics of a DiscreteItem that
 *  can have more than two states and where the state values (the enumeration) do
 *  not consist of consecutive numeric values (may have gaps) or where the
 *  enumeration is not zero-based.
 *
 *  The MultiStateValueDiscreteType derives from the DiscreteItemType.
 *  MultiStateValueDiscrete Variables can have any numeric Data Type; this includes
 *  signed and unsigned integers from 8 to 64 Bit length.
 *
 *  The numeric representation of the current enumeration value is provided via the
 *  Value Attribute of the MultiStateValueDiscrete Variable.
 *
 *  See also \ref Doc_OpcUa_MultiStateValueDiscreteType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT MultiStateValueDiscreteType:
    public OpcUa::DiscreteItemType
{
    UA_DISABLE_COPY(MultiStateValueDiscreteType);
protected:
    virtual ~MultiStateValueDiscreteType();
public:
    MultiStateValueDiscreteType(
        UaNode*            pParentNode,
        UaVariable*        pInstanceDeclarationVariable,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    MultiStateValueDiscreteType(
        const UaNodeId&    nodeId,
        const UaString&    name,
        OpcUa_UInt16       browseNameNameSpaceIndex,
        const UaVariant&   initialValue,
        OpcUa_Byte         accessLevel,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    MultiStateValueDiscreteType(
        UaBase::Variable*  pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;

    virtual void setEnumValues(const UaEnumValueTypes& EnumValues);
    virtual void getEnumValues(UaEnumValueTypes& EnumValues) const;

    virtual void setValueAsText(const UaLocalizedText& ValueAsText);
    virtual UaLocalizedText getValueAsText(Session* pSession) const;

    virtual OpcUa::PropertyType* getEnumValuesNode();
    virtual OpcUa::PropertyType* getValueAsTextNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(MultiStateValueDiscreteType *pInstance);

protected:
    // Variable nodes
    // Variable EnumValues
    static OpcUa::PropertyType*  s_pEnumValues;
    OpcUa::PropertyType*  m_pEnumValues;
    // Variable ValueAsText
    static OpcUa::PropertyType*  s_pValueAsText;
    OpcUa::PropertyType*  m_pValueAsText;


private:
    void initialize(NodeManagerConfig* pNodeConfig);

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUA_MULTISTATEVALUEDISCRETETYPE_H__

