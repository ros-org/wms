/******************************************************************************
** opcua_transitiontype.h
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
#ifndef __OPCUA_TRANSITIONTYPE_H__
#define __OPCUA_TRANSITIONTYPE_H__

#include "opcua_baseobjecttype.h"
#include "opcua_identifiers.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;

/** @brief Class implementing the UaObject interface for the TransitionType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Variable members of the TransitionType:**
 *
 *  Browse Name      | DataType | TypeDefinition | Modelling Rule | See Also
 *  -----------------|----------|----------------|----------------|---------------------------------------------------
 *  TransitionNumber | UInt32   | PropertyType   | Mandatory      | \ref getTransitionNumber, \ref setTransitionNumber
 *
 *  Transitions of a FiniteStateMachine are represented as objects of the
 *  ObjectType TransitionType.
 *
 *  Each valid transition shall have exactly one FromState reference and exactly
 *  one ToState reference, each pointing to an object of the ObjectType StateType.
 *
 *  Each transition can have one or more HasCause references pointing to the cause
 *  that triggers the transition.
 *
 *  Each transition can have one or more HasEffect references pointing to the
 *  effects that occur when the transition was triggered.
 *
 */
class SERVER_CORE_EXPORT TransitionType:
    public OpcUa::BaseObjectType
{
    UA_DISABLE_COPY(TransitionType);
protected:
    virtual ~TransitionType();
public:
    // construction / destruction
    TransitionType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    TransitionType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    TransitionType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;

    virtual void setTransitionNumber(OpcUa_UInt32 TransitionNumber);
    virtual OpcUa_UInt32 getTransitionNumber() const;

    virtual OpcUa::PropertyType* getTransitionNumberNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(TransitionType *pInstance);

protected:
    // Variable TransitionNumber
    static OpcUa::PropertyType*  s_pTransitionNumber;
    OpcUa::PropertyType*  m_pTransitionNumber;

private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUATRANSITIONTYPE_H__

