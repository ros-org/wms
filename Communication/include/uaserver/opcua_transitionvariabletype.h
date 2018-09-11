/******************************************************************************
** opcua_transitionvariabletype.h
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

#ifndef __OPCUA_TRANSITIONVARIABLETYPE_H__
#define __OPCUA_TRANSITIONVARIABLETYPE_H__

#include "opcua_basedatavariabletype.h"
#include "opcua_identifiers.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;

/** Implements OPC UA Variables of the type TransitionVariableType
 *
 *  **Variable members of the TransitionVariableType:**
 *
 *  Browse Name             | DataType      | TypeDefinition | Modelling Rule | See Also
 *  ------------------------|---------------|----------------|----------------|-----------------------------------------------------------------
 *  EffectiveTransitionTime | UtcTime       | PropertyType   | Optional       | \ref getEffectiveTransitionTime, \ref setEffectiveTransitionTime
 *  Id                      | BaseDataType  | PropertyType   | Mandatory      | \ref getId, \ref setId
 *  Name                    | QualifiedName | PropertyType   | Optional       | \ref getName, \ref setName
 *  Number                  | UInt32        | PropertyType   | Optional       | \ref getNumber, \ref setNumber
 *  TransitionTime          | UtcTime       | PropertyType   | Optional       | \ref getTransitionTime, \ref setTransitionTime
 *
 *  The base VariableType for Variables that store a Transition that occurred
 *  within a StateMachine as a human readable name.
 *
 *  The SourceTimestamp for the value specifies when the Transition occurred. This
 *  value may also be exposed with the TransitionTime Property.
 *
 *  See also \ref Doc_OpcUa_TransitionVariableType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT TransitionVariableType:
    public OpcUa::BaseDataVariableType
{
    UA_DISABLE_COPY(TransitionVariableType);
protected:
    virtual ~TransitionVariableType();
public:
    TransitionVariableType(
        UaNode*            pParentNode,
        UaVariable*        pInstanceDeclarationVariable,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    TransitionVariableType(
        const UaNodeId&    nodeId,
        const UaString&    name,
        OpcUa_UInt16       browseNameNameSpaceIndex,
        const UaVariant&   initialValue,
        OpcUa_Byte         accessLevel,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    TransitionVariableType(
        UaBase::Variable*  pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;

    virtual void setEffectiveTransitionTime(const UaDateTime& EffectiveTransitionTime);
    virtual UaDateTime getEffectiveTransitionTime() const;

    virtual void setId(const UaVariant&Id);
    virtual UaVariant getId() const;

    virtual void setName(const UaQualifiedName& Name);
    virtual UaQualifiedName getName() const;

    virtual void setNumber(OpcUa_UInt32 Number);
    virtual OpcUa_UInt32 getNumber() const;

    virtual void setTransitionTime(const UaDateTime& TransitionTime);
    virtual UaDateTime getTransitionTime() const;

    virtual OpcUa::PropertyType* getEffectiveTransitionTimeNode();
    virtual OpcUa::PropertyType* getIdNode();
    virtual OpcUa::PropertyType* getNameNode();
    virtual OpcUa::PropertyType* getNumberNode();
    virtual OpcUa::PropertyType* getTransitionTimeNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(TransitionVariableType *pInstance);

protected:
    // Variable nodes
    // Variable EffectiveTransitionTime
    static OpcUa::PropertyType*  s_pEffectiveTransitionTime;
    OpcUa::PropertyType*  m_pEffectiveTransitionTime;
    // Variable Id
    static OpcUa::PropertyType*  s_pId;
    OpcUa::PropertyType*  m_pId;
    // Variable Name
    static OpcUa::PropertyType*  s_pName;
    OpcUa::PropertyType*  m_pName;
    // Variable Number
    static OpcUa::PropertyType*  s_pNumber;
    OpcUa::PropertyType*  m_pNumber;
    // Variable TransitionTime
    static OpcUa::PropertyType*  s_pTransitionTime;
    OpcUa::PropertyType*  m_pTransitionTime;


private:
    void initialize(NodeManagerConfig* pNodeConfig);

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUA_TRANSITIONVARIABLETYPE_H__

