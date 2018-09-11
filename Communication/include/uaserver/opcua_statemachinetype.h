/******************************************************************************
** opcua_statemachinetype.h
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

#ifndef __OPCUA_STATEMACHINETYPE_H__
#define __OPCUA_STATEMACHINETYPE_H__

#include "opcua_baseobjecttype.h"
#include "opcua_identifiers.h"
#include "basenodes.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class StateVariableType;
class TransitionVariableType;

/** @brief Class implementing the UaObject interface for the StateMachineType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Variable members of the StateMachineType:**
 *
 *  Browse Name    | DataType      | TypeDefinition         | Modelling Rule | See Also
 *  ---------------|---------------|------------------------|----------------|-----------------------------------------------
 *  CurrentState   | LocalizedText | StateVariableType      | Mandatory      | \ref getCurrentState, \ref setCurrentState
 *  LastTransition | LocalizedText | TransitionVariableType | Optional       | \ref getLastTransition, \ref setLastTransition
 *
 */
class SERVER_CORE_EXPORT StateMachineType:
    public OpcUa::BaseObjectType
{
    UA_DISABLE_COPY(StateMachineType);
protected:
    virtual ~StateMachineType();
public:
    // construction / destruction
    StateMachineType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    StateMachineType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    StateMachineType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;

    virtual void setCurrentState(const UaLocalizedText& CurrentState);
    virtual UaLocalizedText getCurrentState(Session* pSession) const;

    virtual void setLastTransition(const UaLocalizedText& LastTransition);
    virtual UaLocalizedText getLastTransition(Session* pSession) const;

    virtual OpcUa::StateVariableType* getCurrentStateNode();
    virtual OpcUa::TransitionVariableType* getLastTransitionNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(StateMachineType *pInstance);

protected:
    // Variable CurrentState
    static OpcUa::StateVariableType*  s_pCurrentState;
    OpcUa::StateVariableType*  m_pCurrentState;
    // Variable LastTransition
    static OpcUa::TransitionVariableType*  s_pLastTransition;
    OpcUa::TransitionVariableType*  m_pLastTransition;

private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUASTATEMACHINETYPE_H__

