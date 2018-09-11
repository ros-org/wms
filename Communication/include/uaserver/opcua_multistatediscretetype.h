/******************************************************************************
** opcua_multistatediscretetype.h
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

#ifndef __OPCUA_MULTISTATEDISCRETETYPE_H__
#define __OPCUA_MULTISTATEDISCRETETYPE_H__

#include "opcua_discreteitemtype.h"
#include "opcua_identifiers.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;

/** Implements OPC UA Variables of the type MultiStateDiscreteType
 *
 *  **Variable members of the MultiStateDiscreteType:**
 *
 *  Browse Name | DataType      | TypeDefinition | Modelling Rule | See Also
 *  ------------|---------------|----------------|----------------|-----------------------------------------
 *  EnumStrings | LocalizedText | PropertyType   | Mandatory      | \ref getEnumStrings, \ref setEnumStrings
 *
 *  Defines the general characteristics of a DiscreteItem that can have more than
 *  two states.
 *
 *  The value of the DiscreteItem is delivered as UInteger but the EnumStrings
 *  Property defined by the MultiStateDiscreteType provides display strings for
 *  every possible state value.
 *
 *  The EnumStrings Property is also used for Enumeration DataTypes.
 *
 *  The StatusCode delivered with the value also contains an informational bit
 *  called SemanticsChanged. Servers that implement Data Access shall set this Bit
 *  in notifications if the EnumStrings (changes can cause misinterpretation by
 *  users or (scripting) programs) Property is changed. Clients that use any of
 *  these Properties should re-read them before they process the data value.
 *
 *  In addition a server can send SemanticChangeEvents if the value of the Property
 *  EnumStrings is changed. To indicate this capability, the SemanticChange flag
 *  must be set in the AccessLevel and UserAccessLevel attributes of this variable.
 *
 *  See also \ref Doc_OpcUa_MultiStateDiscreteType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT MultiStateDiscreteType:
    public OpcUa::DiscreteItemType
{
    UA_DISABLE_COPY(MultiStateDiscreteType);
protected:
    virtual ~MultiStateDiscreteType();
public:
    MultiStateDiscreteType(
        UaNode*            pParentNode,
        UaVariable*        pInstanceDeclarationVariable,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    MultiStateDiscreteType(
        const UaNodeId&    nodeId,
        const UaString&    name,
        OpcUa_UInt16       browseNameNameSpaceIndex,
        const UaVariant&   initialValue,
        OpcUa_Byte         accessLevel,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    MultiStateDiscreteType(
        UaBase::Variable*  pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;

    virtual void setEnumStrings(const UaLocalizedTextArray& EnumStrings);
    virtual void getEnumStrings(UaLocalizedTextArray& EnumStrings) const;

    virtual OpcUa::PropertyType* getEnumStringsNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(MultiStateDiscreteType *pInstance);

protected:
    // Variable nodes
    // Variable EnumStrings
    static OpcUa::PropertyType*  s_pEnumStrings;
    OpcUa::PropertyType*  m_pEnumStrings;


private:
    void initialize(NodeManagerConfig* pNodeConfig);

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUA_MULTISTATEDISCRETETYPE_H__

