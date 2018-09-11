/******************************************************************************
** opcua_statevariabletype.h
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

#ifndef __OPCUA_STATEVARIABLETYPE_H__
#define __OPCUA_STATEVARIABLETYPE_H__

#include "opcua_basedatavariabletype.h"
#include "opcua_identifiers.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;

/** Implements OPC UA Variables of the type StateVariableType
 *
 *  **Variable members of the StateVariableType:**
 *
 *  Browse Name          | DataType      | TypeDefinition | Modelling Rule | See Also
 *  ---------------------|---------------|----------------|----------------|-----------------------------------------------------------
 *  EffectiveDisplayName | LocalizedText | PropertyType   | Optional       | \ref getEffectiveDisplayName, \ref setEffectiveDisplayName
 *  Id                   | BaseDataType  | PropertyType   | Mandatory      | \ref getId, \ref setId
 *  Name                 | QualifiedName | PropertyType   | Optional       | \ref getName, \ref setName
 *  Number               | UInt32        | PropertyType   | Optional       | \ref getNumber, \ref setNumber
 *
 *  The base VariableType for Variables that store the current state of a
 *  StateMachine as a human readable name.
 *
 *  See also \ref Doc_OpcUa_StateVariableType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT StateVariableType:
    public OpcUa::BaseDataVariableType
{
    UA_DISABLE_COPY(StateVariableType);
protected:
    virtual ~StateVariableType();
public:
    StateVariableType(
        UaNode*            pParentNode,
        UaVariable*        pInstanceDeclarationVariable,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    StateVariableType(
        const UaNodeId&    nodeId,
        const UaString&    name,
        OpcUa_UInt16       browseNameNameSpaceIndex,
        const UaVariant&   initialValue,
        OpcUa_Byte         accessLevel,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    StateVariableType(
        UaBase::Variable*  pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;

    virtual void setEffectiveDisplayName(const UaLocalizedText& EffectiveDisplayName);
    virtual UaLocalizedText getEffectiveDisplayName(Session* pSession) const;

    virtual void setId(const UaVariant&Id);
    virtual UaVariant getId() const;

    virtual void setName(const UaQualifiedName& Name);
    virtual UaQualifiedName getName() const;

    virtual void setNumber(OpcUa_UInt32 Number);
    virtual OpcUa_UInt32 getNumber() const;

    virtual OpcUa::PropertyType* getEffectiveDisplayNameNode();
    virtual OpcUa::PropertyType* getIdNode();
    virtual OpcUa::PropertyType* getNameNode();
    virtual OpcUa::PropertyType* getNumberNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(StateVariableType *pInstance);

protected:
    // Variable nodes
    // Variable EffectiveDisplayName
    static OpcUa::PropertyType*  s_pEffectiveDisplayName;
    OpcUa::PropertyType*  m_pEffectiveDisplayName;
    // Variable Id
    static OpcUa::PropertyType*  s_pId;
    OpcUa::PropertyType*  m_pId;
    // Variable Name
    static OpcUa::PropertyType*  s_pName;
    OpcUa::PropertyType*  m_pName;
    // Variable Number
    static OpcUa::PropertyType*  s_pNumber;
    OpcUa::PropertyType*  m_pNumber;


private:
    void initialize(NodeManagerConfig* pNodeConfig);

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUA_STATEVARIABLETYPE_H__

