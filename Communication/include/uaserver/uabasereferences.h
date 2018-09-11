/******************************************************************************
** uabasereferences.h
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
** Project: C++ OPC Server SDK core module
**
** Description: OPC UA server core module base reference classes.
**
******************************************************************************/
#ifndef __UABASEREFERENCES_H__
#define __UABASEREFERENCES_H__

#include "uanodeid.h"
#include "opcuatypes.h"
#include "version_coremodule.h"

class SERVER_CORE_EXPORT UaNode;
class SERVER_CORE_EXPORT UaReferenceType;
class SERVER_CORE_EXPORT NodeManager;

/*! \addtogroup ServerCoreAddressModel
*  @{
*/

/** Interface definition of the UaReference.
 *  Abstract base class for OPC UA references between UA nodes.
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaReference
{
    UA_DISABLE_COPY(UaReference);
    UaReference();
public:
     /// @brief Enumeration of cross node manager reference type
    enum CrossNodeManagerReferenceType
    {
        UA_NO_CROSSNODEMANAGER = 0, /*!< This is not a cross node manager reference */
        UA_LIST_OF_REFERENCES,      /*!< This cross node manager reference can have a list of target nodes */
        UA_SINGLE_REFERENCE         /*!< This cross node manager reference has one target node */
    };

    /** construction */
    UaReference(UaNode * pSourceNode, UaNode * pTargetNode);
    /** destruction */
    virtual ~UaReference();

    /** Checks whether this reference is across node managers or not.
     *  @return The type of cross node manager reference or UA_NO_CROSSNODEMANAGER if it is a normal reference.
     */
    virtual CrossNodeManagerReferenceType isCrossNodeManagerRef() const { return UA_NO_CROSSNODEMANAGER; };

    /** Checks whether a Node is out of Servers References.
     *  @return FALSE if out of Server Reference.
     */
    virtual OpcUa_Boolean isOutOfServerRef() const { return OpcUa_False; }

    /** Get the source Node.
     *  @return the source Node.
     */
    inline UaNode *       pSourceNode() const { return m_pSourceNode; }

    /** Get the target Node.
     *  @return the target Node.
     */
    inline UaNode *       pTargetNode() const { return m_pTargetNode; }

    /** Get the ReferenceType NodeId of the current Reference.
     *  @return the ReferenceTypeId of the current Reference.
     */
    virtual UaNodeId      referenceTypeId() const = 0;

    /** Check whether the current reference is a subtype of the passed reference type node id.
     *  @param pNodeId NodeId of the requested reference type.
     *  @return TRUE if the reference is a subtype of the passed type FALSE if not.
     */
    virtual OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const = 0;

    virtual UaReference* createCPCopy();
    virtual void clearCPCopy();

    /** Set source node to invalid. */
    inline void       setSourceNodeInvalid() { m_pSourceNode = NULL; }

    /** Set target Node to invalid. */
    inline void       setTargetNodeInvalid() { m_pTargetNode = NULL; }

    /** Set the next reference for a list of forward references. */
    inline void       setNextForwardReference(UaReference * pNextReference) { m_pNextForwardReference = pNextReference; }

    /** Get the next reference in a list of forward references. */
    inline UaReference* pNextForwardReference() { return m_pNextForwardReference; }

    /** Set the next reference for a list of inverse references. */
    inline void       setNextInverseReference(UaReference * pNextReference) { m_pNextInverseReference = pNextReference; }

    /** Get the next reference in a list of inverse references. */
    inline UaReference* pNextInverseReference() { return m_pNextInverseReference; }

#if SUPPORT_Class_Statistic
    static int s_referenceInstanceCount;
#endif // SUPPORT_Class_Statistic

protected:
    /// @brief Source node of the reference.
    UaNode * m_pSourceNode;
    /// @brief Target node of the reference.
    UaNode * m_pTargetNode;
    /// @brief Next reference in a list of forward references.
    UaReference * m_pNextForwardReference;
    /// @brief Next reference in a list of inverse references.
    UaReference * m_pNextInverseReference;
};

/** @brief Implements a reference between nodes in two different NodeManagers.
 *  This class is used to create a reference between nodes in two different NodeManagers. The reference stores the node manager
 *  of the target node instead of the target node since the reference represents 0..N references requested by forwarding the browse
 *  request to the other target node manager.
 *  Derived from UaReference.
 */
class SERVER_CORE_EXPORT UaRefCrossNodeManager : public UaReference
{
    UA_DISABLE_COPY(UaRefCrossNodeManager);
public:
    /** construction */
    UaRefCrossNodeManager(NodeManager*  pNodeManager);
    /** destruction */
    virtual ~UaRefCrossNodeManager(){}

    /** Checks whether this reference is across node managers or not.
     *  @return The type of cross node manager reference or UA_NO_CROSSNODEMANAGER if it is a normal reference.
     */
    CrossNodeManagerReferenceType isCrossNodeManagerRef() const { return UA_LIST_OF_REFERENCES; }

    /** Get the ReferenceType NodeId of the current Reference.
     *  @return the ReferenceTypeId of the current Reference.
     */
    UaNodeId      referenceTypeId() const { return UaNodeId(); }

    /** Check whether the current reference is a subtype of the passed reference type node id.
     *  @param pNodeId NodeId of the requested reference type.
     *  @return TRUE if the reference is a subtype of the passed type FALSE if not.
     */
    OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;

    /** Get the actual NodeManager.
     *  @return Interface pointer of NodeManager.
     */
    inline NodeManager*  pNodeManager() const { return m_pNodeManager; }

private:
    NodeManager*  m_pNodeManager;
};

/** @brief Implements a reference between two nodes in two different NodeManagers.
 *  This class is used to create a reference between two nodes in different NodeManagers.
 *  Derived from UaReference.
 */
class SERVER_CORE_EXPORT UaRefCrossNodeManagerSingle : public UaReference
{
public:
    /** construction */
    UaRefCrossNodeManagerSingle(UaNode * pSourceNode, const UaNodeId& targetNodeId, const UaNodeId& referenceTypeId, OpcUa_NodeClass targetNodeClass);
    UaRefCrossNodeManagerSingle(UaRefCrossNodeManagerSingle * pOther);
    /** destruction */
    virtual ~UaRefCrossNodeManagerSingle(){}

    /** Checks whether this reference is across node managers or not.
     *  @return The type of cross node manager reference or UA_NO_CROSSNODEMANAGER if it is a normal reference.
     */
    CrossNodeManagerReferenceType isCrossNodeManagerRef() const { return UA_SINGLE_REFERENCE; }

    /** Get the ReferenceType NodeId of the current Reference.
     *  @return the ReferenceTypeId of the current Reference.
     */
    UaNodeId      referenceTypeId() const { return m_referenceTypeId; }

    /** Check whether the current reference is a subtype of the passed reference type node id.
     *  @param pNodeId NodeId of the requested reference type.
     *  @return TRUE if the reference is a subtype of the passed type FALSE if not.
     */
    OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;

    /** Get the NodeId of the target node.
     *  @return NodeId of the target node.
     */
    inline UaNodeId targetNodeId() const { return m_targetNodeId; }

    /** Get the node class of the target node.
     *  @return Node class of the target node.
     */
    inline OpcUa_NodeClass targetNodeClass() const { return m_targetNodeClass; }

private:
    UaNodeId        m_targetNodeId;
    UaNodeId        m_referenceTypeId;
    OpcUa_NodeClass m_targetNodeClass;
};

/** @brief Class definition of the UaRefOutOfServer.
 *  Creates references out of the server.
 *  Derived from UaReference.
 */
class SERVER_CORE_EXPORT UaRefOutOfServer : public UaReference
{
    UA_DISABLE_COPY(UaRefOutOfServer);
public:
    /** construction */
    UaRefOutOfServer(UaRefOutOfServer * pOther);
    UaRefOutOfServer(UaReferenceType * pReferenceTypeNode);
    /** destruction */
    virtual ~UaRefOutOfServer(){}

    /** Checks whether a Node is out of Servers References.
     *  @return FALSE if out of Server Reference.
     */
    OpcUa_Boolean isOutOfServerRef() const { return OpcUa_True; }

    /** Get the ReferenceTypeId of the current Node.
     *  @return the ReferenceTypeId of the current Node.
     */
    UaNodeId      referenceTypeId() const { return m_referenceTypeId; }

    /** Check whether the current reference is a subtype of the passed reference type node id.
     *  @param pNodeId NodeId of the requested reference type.
     *  @return TRUE if the reference is a subtype of the passed type FALSE if not.
     */
    OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;

    /* ToDo return everything that is needed for browse like
        - ExpandedNodeId
        - BrowseName
        - DisplayName
        etc.
    */
    /* ToDo We need also a reference counter to handle several off server
       references pointing to the same node in the other server with the
       same instance of this class */
private:
    UaReferenceType * m_pReferenceTypeNode;
    UaNodeId          m_referenceTypeId;
    //ExpandedNodeId  m_nodeInOtherServer;
};

/** @brief Class definition of the UaGenericReference.
 *  Creates generic references of all Nodes.
 *  Derived from UaReference.
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaGenericReference : public UaReference
{
    UA_DISABLE_COPY(UaGenericReference);
    UaGenericReference();
public:
    /** construction */
    UaGenericReference(UaNode * pSourceNode, UaNode * pTargetNode, UaReferenceType * pReferenceTypeNode);
    /** destruction */
    virtual ~UaGenericReference();

    /** Get the ReferenceTypeId of the current Node.
     *  @return the ReferenceTypeId of the current Node.
     */
    UaNodeId      referenceTypeId() const;

    /** Check whether the current reference is a subtype of the passed reference type node id.
     *  @param pNodeId NodeId of the requested reference type.
     *  @return TRUE if the reference is a subtype of the passed type FALSE if not.
     */
    OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;

private:
    UaReferenceType * m_pReferenceTypeNode;
};

/** @brief Class definition of the UaGenericReference.
 *  Creates generic references of all Nodes.
 *  Derived from UaReference.
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaReferenceCPCopy : public UaReference
{
    UaReferenceCPCopy();
public:
    /** construction */
    UaReferenceCPCopy(UaNode * pSourceNode, UaNode * pTargetNode, const UaNodeId& referenceTypeId);
    /** destruction */
    virtual ~UaReferenceCPCopy();

    /** Get the ReferenceTypeId of the current Node.
     *  @return the ReferenceTypeId of the current Node.
     */
    UaNodeId      referenceTypeId() const;

    /** Check whether the current reference is a subtype of the passed reference type node id.
     *  @param pNodeId NodeId of the requested reference type.
     *  @return TRUE if the reference is a subtype of the passed type FALSE if not.
     */
    OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;

private:
    UaNodeId m_referenceTypeId;
};

/** @brief Class definition of the UaRefOrganizes.
 *  Organizes references of all Nodes.
 *  Derived from UaReference.
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaRefOrganizes : public UaReference
{
    UaRefOrganizes();
public:
    /** construction */
    UaRefOrganizes(UaNode * pSourceNode, UaNode * pTargetNode);
    /** destruction */
    virtual ~UaRefOrganizes(){}

    /** Get the ReferenceTypeId of the current Node.
     *  @return the ReferenceTypeId of the current Node.
     */
    UaNodeId      referenceTypeId() const;

    /** Check whether the current reference is a subtype of the passed reference type node id.
     *  @param pNodeId NodeId of the requested reference type.
     *  @return TRUE if the reference is a subtype of the passed type FALSE if not.
    */
    OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;
};

/** @brief Class definition of the UaRefHasComponent.
 *  Checks whether a reference has components.
 *  Derived from UaReference.
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaRefHasComponent : public UaReference
{
    UaRefHasComponent();
public:
    /** construction */
    UaRefHasComponent(UaNode * pSourceNode, UaNode * pTargetNode);
    /** destruction */
    virtual ~UaRefHasComponent(){}

    /** Get the ReferenceTypeId of the current Node.
     *  @return the ReferenceTypeId of the current Node.
     */
    UaNodeId      referenceTypeId() const;

    /** Check wether the current reference is a subtype of the passed reference type node id.
     *  @param pNodeId NodeId of the requested reference type.
     *  @return TRUE if the reference is a subtype of the passed type FALSE if not.
     */
    OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;
};

/** @brief Class definition of the UaRefHasHistoricalConfiguration.
 *  Checks wether a reference has components.
 *  Derived from UaReference.
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaRefHasHistoricalConfiguration : public UaReference
{
    UaRefHasHistoricalConfiguration();
public:
    /** construction */
    UaRefHasHistoricalConfiguration(UaNode * pSourceNode, UaNode * pTargetNode);
    /** destruction */
    virtual ~UaRefHasHistoricalConfiguration(){}

    /** Get the ReferenceTypeId of the current Node.
     *  @return the ReferenceTypeId of the current Node.
     */
    UaNodeId      referenceTypeId() const;

    /** Check whether the current reference is a subtype of the passed reference type node id.
     *  @param pNodeId NodeId of the requested reference type.
     *  @return TRUE if the reference is a subtype of the passed type FALSE if not.
     */
    OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;
};

/** @brief Class definition of the UaRefHasOrderedComponent.
 *  Checks whether a reference has ordered components.
 *  Derived from UaReference.
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaRefHasOrderedComponent : public UaReference
{
    UaRefHasOrderedComponent();
public:
    /** construction */
    UaRefHasOrderedComponent(UaNode * pSourceNode, UaNode * pTargetNode);
    /** destruction */
    virtual ~UaRefHasOrderedComponent(){}

    /** Get the ReferenceTypeId of the current Node.
     *  @return the ReferenceTypeId of the current Node.
     */
    UaNodeId      referenceTypeId() const;

    /** Check whether the current reference is a subtype of the passed reference type node id.
     *  @param pNodeId NodeId of the requested reference type.
     *  @return TRUE if the reference is a subtype of the passed type FALSE if not.
     */
    OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;
};

/** @brief Class definition of the UaRefHasProperty.
 *  Checks whether a reference has properties.
 *  Derived from UaReference.
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaRefHasProperty : public UaReference
{
    UaRefHasProperty();
public:
    /** construction */
    UaRefHasProperty(UaNode * pSourceNode, UaNode * pTargetNode);
    /** destruction */
    virtual ~UaRefHasProperty(){}

    /** Get the ReferenceTypeId of the current Node.
     *  @return the ReferenceTypeId of the current Node.
     */
    UaNodeId      referenceTypeId() const;

    /** Check whether the current reference is a subtype of the passed reference type node id.
     *  @param pNodeId NodeId of the requested reference type.
     *  @return TRUE if the reference is a subtype of the passed type FALSE if not.
     */
    OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;
};

/** @brief Class definition of the UaRefHasSubtype. Derived from UaReference.
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaRefHasSubtype : public UaReference
{
    UaRefHasSubtype();
public:
    /** construction */
    UaRefHasSubtype(UaNode * pSourceNode, UaNode * pTargetNode);
    /** destruction */
    virtual ~UaRefHasSubtype(){}

    /** Get the ReferenceTypeId of the current Node.
     *  @return the ReferenceTypeId of the current Node.
     */
    UaNodeId      referenceTypeId() const;

    /** Check whether the current reference is a subtype of the passed reference type node id.
     *  @param pNodeId NodeId of the requested reference type.
     *  @return TRUE if the reference is a subtype of the passed type FALSE if not.
     */
    OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;
};

/** @brief Class definition of the UaRefHasEventSource.
 *  Checks whether a reference has event sources.
 *  Derived from UaReference.
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaRefHasEventSource : public UaReference
{
    UaRefHasEventSource();
public:
    /** construction */
    UaRefHasEventSource(UaNode * pSourceNode, UaNode * pTargetNode);
    /** destruction */
    virtual ~UaRefHasEventSource(){}

    /** Get the ReferenceTypeId of the current Node.
     *  @return the ReferenceTypeId of the current Node.
     */
    UaNodeId      referenceTypeId() const;

    /** Check whether the current reference is a subtype of the passed reference type node id.
     *  @param pNodeId NodeId of the requested reference type.
     *  @return TRUE if the reference is a subtype of the passed type FALSE if not.
     */
    OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;
};

/** @brief Class definition of the UaRefHasNotifier.
 *  Checks whether a reference has notifiers.
 *  Derived from UaReference.
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaRefHasNotifier : public UaReference
{
    UaRefHasNotifier();
public:
    /** construction */
    UaRefHasNotifier(UaNode * pSourceNode, UaNode * pTargetNode);
    /** destruction */
    virtual ~UaRefHasNotifier(){}

    /** Get the ReferenceTypeId of the current Node.
     *  @return the ReferenceTypeId of the current Node.
     */
    UaNodeId      referenceTypeId() const;

    /** Check whether the current reference is a subtype of the passed reference type node id.
     *  @param pNodeId NodeId of the requested reference type.
     *  @return TRUE if the reference is a subtype of the passed type FALSE if not.
     */
    OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;
};

/** @brief Class definition of the UaRefHasTypeDefinition.
 *  Checks whether a reference has type definitions.
 *  Derived from UaReference.
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaRefHasTypeDefinition : public UaReference
{
    UaRefHasTypeDefinition();
public:
    /** construction */
    UaRefHasTypeDefinition(UaNode * pSourceNode, UaNode * pTargetNode);
    /** destruction */
    virtual ~UaRefHasTypeDefinition(){}

    /** Get the ReferenceTypeId of the current Node.
     *  @return the ReferenceTypeId of the current Node.
     */
    UaNodeId      referenceTypeId() const;

    /** Check whether the current reference is a subtype of the passed reference type node id.
     *  @param pNodeId NodeId of the requested reference type.
     *  @return TRUE if the reference is a subtype of the passed type FALSE if not.
     */
    OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;
};

/** @brief Class definition of the UaRefGeneratesEvent.
 *  Checks whether a reference generates events.
 *  Derived from UaReference.
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaRefGeneratesEvent : public UaReference
{
    UaRefGeneratesEvent();
public:
    /** construction */
    UaRefGeneratesEvent(UaNode * pSourceNode, UaNode * pTargetNode);
    /** destruction */
    virtual ~UaRefGeneratesEvent(){}

    /** Get the ReferenceTypeId of the current Node.
     *  @return the ReferenceTypeId of the current Node.
     */
    UaNodeId      referenceTypeId() const;

    /** Check whether the current reference is a subtype of the passed reference type node id.
     *  @param pNodeId NodeId of the requested reference type.
     *  @return TRUE if the reference is a subtype of the passed type FALSE if not.
     */
    OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;
};

/** @brief Class definition of the UaRefAlwaysGeneratesEvent.
 *  Checks whether a reference generates events.
 *  Derived from UaReference.
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaRefAlwaysGeneratesEvent : public UaReference
{
    UaRefAlwaysGeneratesEvent();
public:
    /** construction */
    UaRefAlwaysGeneratesEvent(UaNode * pSourceNode, UaNode * pTargetNode);
    /** destruction */
    virtual ~UaRefAlwaysGeneratesEvent(){};

    /** Get the ReferenceTypeId of the current Node.
     *  @return the ReferenceTypeId of the current Node.
     */
    UaNodeId      referenceTypeId() const;

    /** Check whether the current reference is a subtype of the passed reference type node id.
     *  @param pNodeId NodeId of the requested reference type.
     *  @return TRUE if the reference is a subtype of the passed type FALSE if not.
     */
    OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;
};

/** Reference class used to represent a HasCondition reference.
 */
class SERVER_CORE_EXPORT UaRefHasCondition : public UaReference
{
    UaRefHasCondition();
public:
    /** construction */
    UaRefHasCondition(UaNode * pSourceNode, UaNode * pTargetNode);
    /** destruction */
    virtual ~UaRefHasCondition(){}

    /** Get the ReferenceTypeId of the current Node.
     *  @return the ReferenceTypeId of the current Node.
     */
    UaNodeId      referenceTypeId() const;

    /** Check whether the current reference is a subtype of the passed reference type node id.
     *  @param pNodeId NodeId of the requested reference type.
     *  @return TRUE if the reference is a subtype of the passed type FALSE if not.
     */
    OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;
};

/** @brief Class definition of the UaRefHasDescription.
 *  Checks whether a reference has descriptions or not.
 *  Derived from UaReference.
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaRefHasDescription : public UaReference
{
    UaRefHasDescription();
public:
    /** construction */
    UaRefHasDescription(UaNode * pSourceNode, UaNode * pTargetNode);
    /** destruction */
    virtual ~UaRefHasDescription(){}

    /** Get the ReferenceTypeId of the current Node.
     *  @return the ReferenceTypeId of the current Node.
     */
    UaNodeId      referenceTypeId() const;

    /** Check whether the current reference is a subtype of the passed reference type node id.
     *  @param pNodeId NodeId of the requested reference type.
     *  @return TRUE if the reference is a subtype of the passed type FALSE if not.
     */
    OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;
};

/** @brief Class definition of the UaRefHasEncoding.
 *  Derived from UaReference.
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaRefHasEncoding : public UaReference
{
    UaRefHasEncoding();
public:
    /** construction */
    UaRefHasEncoding(UaNode * pSourceNode, UaNode * pTargetNode);
    /** destruction */
    virtual ~UaRefHasEncoding(){}

    /** Get the ReferenceTypeId of the current Node.
     *  @return the ReferenceTypeId of the current Node.
     */
    UaNodeId      referenceTypeId() const;

    /** Check whether the current reference is a subtype of the passed reference type node id.
     *  @param pNodeId NodeId of the requested reference type.
     *  @return TRUE if the reference is a subtype of the passed type FALSE if not.
     */
    OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;
};

/** @brief Class definition of the UaRefHasModellingRule.
 *  Derived from UaReference.
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaRefHasModellingRule : public UaReference
{
    UaRefHasModellingRule();
public:
    /** construction */
    UaRefHasModellingRule(UaNode * pSourceNode, UaNode * pTargetNode);
    /** destruction */
    virtual ~UaRefHasModellingRule(){}

    /** Get the ReferenceTypeId of the current Node.
     *  @return the ReferenceTypeId of the current Node.
     */
    UaNodeId      referenceTypeId() const;

    /** Check whether the current reference is a subtype of the passed reference type node id.
     *  @param pNodeId NodeId of the requested reference type.
     *  @return TRUE if the reference is a subtype of the passed type FALSE if not.
     */
    OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;
};

/** @brief Class definition of the UaRefFromState.
 *  Derived from UaReference
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaRefFromState : public UaReference
{
    UaRefFromState();
public:
    /** construction */
    UaRefFromState(UaNode * pSourceNode, UaNode * pTargetNode);
    /** destruction */
    virtual ~UaRefFromState(){}

    /** Get the ReferenceTypeId of the current Node.
     *  @return the ReferenceTypeId of the current Node.
     */
    UaNodeId      referenceTypeId() const;

    /** Check whether the current reference is a subtype of the passed reference type node id.
     *  @param pNodeId NodeId of the requested reference type.
     *  @return TRUE if the reference is a subtype of the passed type FALSE if not.
     */
    OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;
};

/** @brief Class definition of the UaRefHasCause.
 *  Derived from UaReference.
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaRefHasCause : public UaReference
{
    UaRefHasCause();
public:
    /** construction */
    UaRefHasCause(UaNode * pSourceNode, UaNode * pTargetNode);
    /** destruction */
    virtual ~UaRefHasCause(){}

    /** Get the ReferenceTypeId of the current Node.
     *  @return the ReferenceTypeId of the current Node.
     */
    UaNodeId      referenceTypeId() const;

    /** Check whether the current reference is a subtype of the passed reference type node id.
     *  @param pNodeId NodeId of the requested reference type.
     *  @return TRUE if the reference is a subtype of the passed type FALSE if not.
     */
    OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;
};

/** @brief Class definition of the UaRefHasEffect.
 *  Derived from UaReference.
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaRefHasEffect : public UaReference
{
    UaRefHasEffect();
public:
    /** construction */
    UaRefHasEffect(UaNode * pSourceNode, UaNode * pTargetNode);
    /** destruction */
    virtual ~UaRefHasEffect(){}

    /** Get the ReferenceTypeId of the current Node.
     *  @return the ReferenceTypeId of the current Node.
     */
    UaNodeId      referenceTypeId() const;

    /** Check whether the current reference is a subtype of the passed reference type node id.
     *  @param pNodeId NodeId of the requested reference type.
     *  @return TRUE if the reference is a subtype of the passed type FALSE if not.
     */
    OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;
};

/** @brief Class definition of the UaRefToState.
 *  Derived from UaReference
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaRefToState : public UaReference
{
    UaRefToState();
public:
    /** construction */
    UaRefToState(UaNode * pSourceNode, UaNode * pTargetNode);
    /** destruction */
    virtual ~UaRefToState(){}

    /** Get the ReferenceTypeId of the current Node.
     *  @return the ReferenceTypeId of the current Node.
     */
    UaNodeId      referenceTypeId() const;

    /** Check whether the current reference is a subtype of the passed reference type node id.
     *  @param pNodeId NodeId of the requested reference type.
     *  @return TRUE if the reference is a subtype of the passed type FALSE if not.
     */
    OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;
};
/*! @} */

#endif // __UABASEREFERENCES_H__
