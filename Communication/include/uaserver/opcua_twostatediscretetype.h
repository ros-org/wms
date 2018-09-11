/******************************************************************************
** opcua_twostatediscretetype.h
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

#ifndef __OPCUA_TWOSTATEDISCRETETYPE_H__
#define __OPCUA_TWOSTATEDISCRETETYPE_H__

#include "opcua_discreteitemtype.h"
#include "opcua_identifiers.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;

/** Implements OPC UA Variables of the type TwoStateDiscreteType
 *
 *  **Variable members of the TwoStateDiscreteType:**
 *
 *  Browse Name | DataType      | TypeDefinition | Modelling Rule | See Also
 *  ------------|---------------|----------------|----------------|---------------------------------------
 *  FalseState  | LocalizedText | PropertyType   | Mandatory      | \ref getFalseState, \ref setFalseState
 *  TrueState   | LocalizedText | PropertyType   | Mandatory      | \ref getTrueState, \ref setTrueState
 *
 *  This VariableType defines the general characteristics of a DiscreteItem that
 *  can have two states.
 *
 *  The value of the DiscreteItem is delivered as boolean but the TrueState and
 *  FalseState properties defined by the TwoStateDiscreteType provides display
 *  strings for the two possible states.
 *
 *  The StatusCode delivered with the value also contains an informational bit
 *  called SemanticsChanged. Servers that implement Data Access shall set this Bit
 *  in notifications if any of the FalseState or TrueState (changes can cause
 *  misinterpretation by users or (scripting) programs) Properties are changed.
 *  Clients that use any of these Properties should re-read them before they
 *  process the data value.
 *
 *  In addition a server can send SemanticChangeEvents if the value of the Property
 *  EnumStrings is changed. To indicate this capability, the SemanticChange flag
 *  must be set in the AccessLevel and UserAccessLevel attributes of this variable.
 *
 *  See also \ref Doc_OpcUa_TwoStateDiscreteType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT TwoStateDiscreteType:
    public OpcUa::DiscreteItemType
{
    UA_DISABLE_COPY(TwoStateDiscreteType);
protected:
    virtual ~TwoStateDiscreteType();
public:
    TwoStateDiscreteType(
        UaNode*            pParentNode,
        UaVariable*        pInstanceDeclarationVariable,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    TwoStateDiscreteType(
        const UaNodeId&    nodeId,
        const UaString&    name,
        OpcUa_UInt16       browseNameNameSpaceIndex,
        const UaVariant&   initialValue,
        OpcUa_Byte         accessLevel,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    TwoStateDiscreteType(
        UaBase::Variable*  pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;

    virtual void setFalseState(const UaLocalizedText& FalseState);
    virtual UaLocalizedText getFalseState(Session* pSession) const;

    virtual void setTrueState(const UaLocalizedText& TrueState);
    virtual UaLocalizedText getTrueState(Session* pSession) const;

    virtual OpcUa::PropertyType* getFalseStateNode();
    virtual OpcUa::PropertyType* getTrueStateNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(TwoStateDiscreteType *pInstance);

protected:
    // Variable nodes
    // Variable FalseState
    static OpcUa::PropertyType*  s_pFalseState;
    OpcUa::PropertyType*  m_pFalseState;
    // Variable TrueState
    static OpcUa::PropertyType*  s_pTrueState;
    OpcUa::PropertyType*  m_pTrueState;


private:
    void initialize(NodeManagerConfig* pNodeConfig);

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUA_TWOSTATEDISCRETETYPE_H__

