/******************************************************************************
** opcua_finitestatevariabletype.h
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

#ifndef __OPCUA_FINITESTATEVARIABLETYPE_H__
#define __OPCUA_FINITESTATEVARIABLETYPE_H__

#include "opcua_statevariabletype.h"
#include "opcua_identifiers.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;

/** Implements OPC UA Variables of the type FiniteStateVariableType
 *
 *  The FiniteStateVariableType is a subtype of StateVariableType and is used to
 *  store the current state of a FiniteStateMachine as a human readable name. It
 *  inherits the Properties Id, Name, and Number from the StateVariableType.
 *
 *  The optional Name Property is inherited from StateVariableType. Its Value shall
 *  be the BrowseName of one of the State objects of the FiniteStateMachineType.
 *
 *  The optional Number Property is inherited from StateVariableType. Its Value
 *  shall be the StateNumber for one of the State objects of the
 *  FiniteStateMachineType.
 *
 *  See also \ref Doc_OpcUa_FiniteStateVariableType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT FiniteStateVariableType:
    public OpcUa::StateVariableType
{
    UA_DISABLE_COPY(FiniteStateVariableType);
protected:
    virtual ~FiniteStateVariableType();
public:
    FiniteStateVariableType(
        UaNode*            pParentNode,
        UaVariable*        pInstanceDeclarationVariable,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    FiniteStateVariableType(
        const UaNodeId&    nodeId,
        const UaString&    name,
        OpcUa_UInt16       browseNameNameSpaceIndex,
        const UaVariant&   initialValue,
        OpcUa_Byte         accessLevel,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    FiniteStateVariableType(
        UaBase::Variable*  pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;

    virtual void setId(const UaVariant&Id);
    virtual UaVariant getId() const;
    virtual void setIdNodeId(const UaNodeId& Id);
    virtual UaNodeId getIdNodeId() const;
    // Id defined by base type

    virtual OpcUa::PropertyType* getIdNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(FiniteStateVariableType *pInstance);

protected:
    // Variable nodes
    // Variable Id
    static OpcUa::PropertyType*  s_pId;
    // Id defined by base type


private:
    void initialize(NodeManagerConfig* pNodeConfig);

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUA_FINITESTATEVARIABLETYPE_H__

