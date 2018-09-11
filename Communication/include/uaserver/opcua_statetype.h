/******************************************************************************
** opcua_statetype.h
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
#ifndef __OPCUA_STATETYPE_H__
#define __OPCUA_STATETYPE_H__

#include "opcua_baseobjecttype.h"
#include "opcua_identifiers.h"
#include "opcua_propertytype.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

/** @brief Class implementing the UaObject interface for the StateType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Variable members of the StateType:**
 *
 *  Browse Name | DataType | TypeDefinition | Modelling Rule | See Also
 *  ------------|----------|----------------|----------------|-----------------------------------------
 *  StateNumber | UInt32   | PropertyType   | Mandatory      | \ref getStateNumber, \ref setStateNumber
 *
 *  States of a FiniteStateMachine are represented as objects of the StateType.
 *
 *  See also \ref Doc_OpcUa_StateType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT StateType:
    public OpcUa::BaseObjectType
{
    UA_DISABLE_COPY(StateType);
protected:
    virtual ~StateType();
public:
    // construction / destruction
    StateType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    StateType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    StateType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;

    // StateNumber
    virtual void setStateNumber(OpcUa_UInt32 stateNumber);
    virtual OpcUa_UInt32 getStateNumber();

    virtual OpcUa::PropertyType* getStateNumberNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(StateType *pInstance);

protected:
    // Variable StateNumber
    static OpcUa::PropertyType*  s_pStateNumber;
    OpcUa::PropertyType*         m_pStateNumber;

private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};


/** @brief Class implementing the UaObject interface for the InitialStateType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  An object of the InitialStateType represents the state that a
 *  FiniteStateMachine enters when it is activated.
 *
 *  Each FiniteStateMachine can have at most one state of type InitialStateType,
 *  but a FiniteStateMachine does not have to have a state of this type.
 *
 *  A sub-state machine goes into its initial state whenever the parent state is
 *  entered. However, a state machine may define a transition that goes directly to
 *  a state of the sub-state machine. In this case the sub-state machine goes into
 *  that state instead of the initial State.
 *
 *  If no initial state for a sub-state machine exists and the state having the
 *  sub-state machine is entered directly, then the state of the sub-state machine
 *  is server-specific.
 *
 *  See also \ref Doc_OpcUa_InitialStateType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT InitialStateType:
    public OpcUa::StateType
{
    UA_DISABLE_COPY(InitialStateType);
protected:
    virtual ~InitialStateType();
public:
    // construction / destruction
    InitialStateType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    InitialStateType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    InitialStateType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;



    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(InitialStateType *pInstance);

protected:


private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};


} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUASTATETYPE_H__

