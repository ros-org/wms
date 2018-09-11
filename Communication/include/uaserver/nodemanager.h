/******************************************************************************
** nodemanager.h
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
** Description: OPC server core module NodeManager interface.
**
******************************************************************************/
#ifndef __NODEMANAGER_H__
#define __NODEMANAGER_H__

#include "continuationpoint.h"
#include "variablehandle.h"
#include "version_coremodule.h"
#include "coremoduleincludes.h"
#include "uaserverapplicationmodule.h"
#if SUPPORT_Event_Subscription_Server_Facet
#include "eventmanager.h"
#endif // SUPPORT_Event_Subscription_Server_Facet

class SERVER_CORE_EXPORT ServerManager;
class SERVER_CORE_EXPORT MethodHandle;
class SERVER_CORE_EXPORT UaNode;
class SERVER_CORE_EXPORT UaReferenceLists;
class SERVER_CORE_EXPORT NodeManagerCrossReferences;
class SERVER_CORE_EXPORT NodeManagerConfig;
class SERVER_CORE_EXPORT NodeManagerUaNode;
class SERVER_CORE_EXPORT EventManagerBase;
class SERVER_CORE_EXPORT EventManagerUaNode;
class SERVER_CORE_EXPORT NodeManagerNodeSetXml;

/** @ingroup ServerCoreInterfaces
 *  Interface definition of NodeManager used for browsing and managing the address space.
 *
 *  The NodeManager interface provides the browsing capability for the nodes managed by the NodeManager instance.
 *  It returns also the responsible IOManager, MethodManager, HistoryManager or EventManager for a passed node (NodeId).
 *  The interface provides optional methods to add nodes and references and to delete nodes and references.
 *
 *  One NodeManager is typically responsible for the nodes of one namespace. This is all nodes where the NodeIds have
 *  the same namespace index. A namespace index is assigned a namespace URI when the NodeManager is registered with the SDK.
 *  The interface \ref NodeManagerList is used to register the NodeManager. The method \ref NodeManagerList::addNodeManager
 *  returns the namespace index for the namespace URI. This namespace index is then used for all NodeIds of nodes managed
 *  by this NodeManager.
 *
 *  It is possible to register several namespace URIs for one NodeManager interface. The NodeManager is then responsible for
 *  managing the resulting list of namespace indices.
 *
 *  One NodeManager can use several IOManagers, MethodManagers or HistoryManagers e.g. one NodeManager can manage nodes for several
 *  subsystems but it can use one instance of a IOManager per subsystem. The number of IOManagers, MethodManagers or HistoryManagers
 *  is not limited. But it is strongly recommended to limit the EventManagers in a server.
 */
class SERVER_CORE_EXPORT NodeManager : public UaServerApplicationModule
{
    UA_DISABLE_COPY(NodeManager);
public:
    /** construction */
    NodeManager();
    /** destruction */
    virtual ~NodeManager();

    /** Notifies the node manager that a new session was opened.
     *  This information can be used to establish a connection to an underlying system if Session specific (e.g. user specific)
     *  connections are necessary.
     *  The method can be overwritten in a derived class if the implementation needs to know which sessions are active
     *  @return Error code
     */
    virtual UaStatus sessionOpened(Session*){return OpcUa_Good;};

    /** Notifies the node manager that a session was activated.
     *  The method can be overwritten in a derived class if the implementation needs to know which sessions are active
     *  @return Error code
     */
    virtual UaStatus sessionActivated(Session*){return OpcUa_Good;};

    /** Notifies the node manager that a session was closed.
     *  The method can be overwritten in a derived class if the implementation needs to know which sessions are active
     *  @return Error code
     */
    virtual UaStatus sessionClosed(Session*){return OpcUa_Good;};

    /** Discover the references of a specified node of a view.
     *  This method is used to return a list of references and target nodes for the passed node to browse for the
     *  services Browse and BrowseNext.
     *  @param serviceContext   General context for the service call containing information like the session object,
     *                          return diagnostic mask and timeout hint.
     *  @param browseContext    Browse context for the first browse or the following browse next calls with continuation point.
     *  @param References       Array of ReferenceDescription results for the browsed node.
     *  @return                 Error code
     */
    virtual UaStatus browse(
        const ServiceContext&       serviceContext,
        BrowseContext&              browseContext,
        UaReferenceDescriptions&    References) = 0;

    /** Translates a relative browse path to a node id.
     *  This method is used to request the Server to translate a browse paths to a NodeId for the target node.
     *  There could be a list of target nodes but the normal case is a single result for a starting node and a path.
     *
     *  The browse path is constructed of a starting Node and a RelativePath. The specified starting Node
     *  identifies the Node from which the RelativePath is based. The RelativePath contains a sequence of BrowseNames.
     *  The relative path parameter contains a list of relative path elements and the current position of the translate
     *  process since the translate can affect more than one node manager and the implementation of this method is only required
     *  to process relative path elements and starting nodes managed by the current node manager instance but it may also resolve
     *  the full path for all involved NodeManagers.
     *
     *  If not all path elements can be resolved by the NodeManager, the call can be returned with the last resolved target node
     *  and the remaining index provided in browsePathTargets, or the NodeManager calls translateBrowsePathToNodeId() on the
     *  NodeManager that is responsible for the next node in the path.
     *
     *  If the path cannot be resolved completely but the next node in the path is in another server, the method must return
     *  OpcUa_UncertainReferenceOutOfServer.
     *
     *  If a path results in more than one result, the implementation of this method must resolve the full path for all possible results.
     *
     *  @param serviceContext       General context for the service calls containing information like the session object,
     *                              return diagnostic mask and timeout hint.
     *  @param startingNode         Starting node from where the relative path is defined.
     *  @param relativePath         Relative path from the starting node to the searched node including the current position of
     *                              the translate process. @see UaRelativePath provides more details.
     *  @param browsePathTargets    All result target nodes for the browse path or the partial result for the already resolved part of the path.
     *  @return                     Error code
     */
    virtual UaStatus translateBrowsePathToNodeId(
        const ServiceContext& serviceContext,
        const UaNodeId&       startingNode,
        UaRelativePath&       relativePath,
        UaBrowsePathTargets&  browsePathTargets) = 0;

    /** Get the variable handle for the passed node Id.
     *  This method is used to get the VariableHandle for a node used to access the related
     *  IOManager in the services Read, Write and CreateMonitoredItems.
     *  The provided VariableHandle is reference counted. The reference count is 1 after initial creation of the object.
     *  The SDK will release its reference after the transaction is finished. If the VariableHandle is stored in an application
     *  specific object, the reference counter must be incremented to keep the one reference. If this stored pointer is used to return
     *  the VariableHandle in following getVariableHandle calls, the reference counter must be incremented before returning the pointer.
     *  @param pSession     Interface to the Session context for the method call.
     *                      The Session object is reference counted. The Session is valid until the client has closed the Session or it timed out.
     *                      If the Session pointer is stored in user objects, these objects must add their own reference.
     *  @param serviceType  Service type enumerator
     *  @param pNodeId      NodeId of the requested node. The pointer to the NodeId is only valid during this call.
     *  @param AttributeId  AttributeId of the requested node
     *  @return             The variable handle for the passed node Id and attribute Id combination.
     */
    virtual VariableHandle* getVariableHandle(
        Session*                    pSession,
        VariableHandle::ServiceType serviceType,
        OpcUa_NodeId*               pNodeId,
        OpcUa_Int32                 AttributeId) const = 0;

    /** Get the history variable handle for the passed node Id.
     *  This method is used to get the HistoryVariableHandle for a node used to access the related
     *  HistoryManager in the services ReadHistory and UpdateHistory.
     *  @param pSession     Interface to the Session context for the method call
     *  @param serviceType  Service type enumerator
     *  @param pNodeId      NodeId of the requested node. The pointer to the NodeId is only valid during this call.
     *  @param result       the result of the current Operation.
     *  @return             the history variable handle for the passed node Id.
     */
    virtual HistoryVariableHandle* getHistoryVariableHandle(
        Session*                           pSession,
        HistoryVariableHandle::ServiceType serviceType,
        OpcUa_NodeId*                      pNodeId,
        UaStatus&                          result) const;

#if SUPPORT_Event_Subscription_Server_Facet
    /** Get a list of EventManager interfaces for an event notifier.
     *  This method is used to get a list of EventManager interfaces for the passed object
     *  node which must be an event notifier. Since the event notifier can be the root for
     *  an event hierarchy with different event sources and different EventManagers.
     *  The NodeManager can filter based on the passed event filter.
     *  But this can be done also later by the EventManager.
     *  @param pSession         Interface to the Session context for the method call
     *  @param pNodeId          NodeId of the requested event notifier node. The pointer to the NodeId is only valid during this call.
     *  @param eventFilter      Event filter defined by the client. The pointer to the event filter is only valid during this call.
     *                          The event filter is also passed to EventManager::beginStartMonitoring() in the EventMonitoringContextCreate.
     *  @param eventManagers    The list of EventManager interfaces for the passed event notifier. This list is returned by the NodeManager.
     *  @return                 Error code
     */
    virtual UaStatus getEventManagers(
        Session*           pSession,
        OpcUa_NodeId*      pNodeId,
        OpcUa_EventFilter* eventFilter,
        EventManagerArray& eventManagers) const;
#endif // SUPPORT_Event_Subscription_Server_Facet

    /** Get the method handle for the passed node Id.
     *  This method is used to get the MethodHandle for a Object node / Method combination used
     *  to access the related MethodManager in the service Call.
     *  @param pSession         Interface to the Session context for the method call
     *  @param pObjectNodeId    The NodeId of the requested Object. The pointer to the NodeId is only valid during this call.
     *  @param pMethodNodeId    The NodeId of the requested Method. The pointer to the NodeId is only valid during this call.
     *  @param result           The result of the current Operation.
     *  @return                 Error code
     */
    virtual MethodHandle* getMethodHandle(
        Session*       pSession,
        OpcUa_NodeId*  pObjectNodeId,
        OpcUa_NodeId*  pMethodNodeId,
        UaStatus&      result) const;

    /** Add node to the NodeManager.
     *  @param serviceContext       General context for the service calls containing information like the session object, return diagnostic mask and timeout hint.
     *  @param parentNodeId         The NodeId of the parent node of the node to create.
     *  @param referenceTypeId      Type of the reference to create from the source node to the new node.
     *  @param requestedNewNodeId   The new NodeId of the requested node.
     *  @param browseName           The browse name of the node to create.
     *  @param nodeClass            The node class of the node to create.
     *  @param nodeAttributes       All other attribute values of the node to create.
     *  @param typeDefinition       The type definition of the node to create.
     *  @param addedNodeId          The NodeId of the newly created node.
     *  @return                     Error code
     */
    virtual UaStatus addNode(
        const ServiceContext&    serviceContext,
        const UaNodeId&          parentNodeId,
        const UaNodeId&          referenceTypeId,
        const UaNodeId&          requestedNewNodeId,
        const UaQualifiedName&   browseName,
        OpcUa_NodeClass          nodeClass,
        const UaExtensionObject& nodeAttributes,
        const UaNodeId&          typeDefinition,
        UaNodeId&                addedNodeId);

    /** Add reference to the NodeManager.
     *  @param serviceContext   General context for the service calls containing information like the session object, return diagnostic mask and timeout hint.
     *  @param sourceNodeId     The NodeId of source node for the reference to create.
     *  @param referenceTypeId  Type of the reference to create from the source node to the target node.
     *  @param isForward        Indicates if the reference is in forward direction from the source to the target node.
     *  @param targetNodeId     The NodeId of target node for the reference to create.
     *  @param targetNodeClass  The NodeClass of the target Node.
     *  @return                 Error code
     */
    virtual UaStatus addReference(
        const ServiceContext&   serviceContext,
        const UaNodeId&         sourceNodeId,
        const UaNodeId&         referenceTypeId,
        OpcUa_Boolean           isForward,
        const UaNodeId&         targetNodeId,
        OpcUa_NodeClass         targetNodeClass);

    /** Delete node from the NodeManager.
     *  @param serviceContext           General context for the service calls containing information like the session object, return diagnostic mask and timeout hint.
     *  @param nodeId                   The NodeId of the node to delete.
     *  @param deleteTargetReference    Indicates if the inverse references in the target nodes must be deleted
     *  @return                         Error code
     */
    virtual UaStatus deleteNode(
        const ServiceContext&   serviceContext,
        const UaNodeId&         nodeId,
        OpcUa_Boolean           deleteTargetReference);

    /** Delete reference from the NodeManager.
     *  @param serviceContext       General context for the service calls containing information like the session object, return diagnostic mask and timeout hint.
     *  @param sourceNodeId         The NodeId of source node for the reference to delete.
     *  @param referenceTypeId      Type of the reference to delete from the source node to the target node.
     *  @param isForward            Indicates if the reference is in forward direction from the source to the target node.
     *  @param targetNodeId         The NodeId of target node for the reference to delete.
     *  @param deleteBidirectional  Flag indicating if the reference should be deleted in both directions.
     *  @return                     Error code
     */
    virtual UaStatus deleteReference(
        const ServiceContext&   serviceContext,
        const UaNodeId&         sourceNodeId,
        const UaNodeId&         referenceTypeId,
        OpcUa_Boolean           isForward,
        const UaNodeId&         targetNodeId,
        OpcUa_Boolean           deleteBidirectional);

    /** Get the interface NodeManagerCrossReferences if available.
     *  @return the NodeManagerCrossReferences interface pointer.
     */
    virtual NodeManagerCrossReferences* getNodeManagerCrossReferences();

    /** Get the interface NodeManagerConfig if available.
     *  @return the NodeManagerConfig interface pointer.
     */
    virtual NodeManagerConfig* getNodeManagerConfig();

    /** Get the interface NodeManagerUaNode if available.
     *  @return the NodeManagerUaNode interface pointer.
     */
    virtual NodeManagerUaNode* getNodeManagerUaNode();
};

/** @ingroup ServerCoreInterfaces
 *  NodeManager related interface to create cross references between NodeManagers
 *  It is not possible to create shallow copies of this Interface.
 */
class SERVER_CORE_EXPORT NodeManagerCrossReferences
{
    UA_DISABLE_COPY(NodeManagerCrossReferences);
public:
    /** construction */
    NodeManagerCrossReferences(){};
    /** destruction */
    virtual ~NodeManagerCrossReferences(){};

    /** Connect a starting node to the passed NodeManager
     *  This method is used to tell the NodeManager A (implements this method) that another NodeManager B has a Nodes
     *  with references to a Node in A but is not able to specify the list. All View services called with the specified
     *  Node in A must be called also on NodeManager B to allow B to return affected Nodes.
     *  @param startingNode         NodeId of the node that needs to be connected to the other NodeManager.
     *  @param pNodeManager         Pointer to NodeManager that manages references from the starting node to nodes in the that NodeManager.
     *  @param forwardReferences    Flag that indicates that there are forward references.
     *  @param inverseReferences    Flag that indicates that there are inverse references.
     *  @return                     Error code
     */
    virtual UaStatus connectStartingNode(
        const UaNodeId& startingNode,
        NodeManager*    pNodeManager,
        OpcUa_Boolean   forwardReferences,
        OpcUa_Boolean   inverseReferences) = 0;

    /** Disconnect a starting node from the passed NodeManager
     *  @param startingNode      NodeId of the node that needs to be disconnected from the other NodeManager.
     *  @param pNodeManager      Pointer of the NodeManager to disconnect.
     *  @return Error code
     */
    virtual UaStatus disconnectStartingNode(
        const UaNodeId& startingNode,
        NodeManager*    pNodeManager) = 0;

    /** Create a reference between nodes managed by different node managers.
     *  @return Error code
     */
    virtual UaStatus addCrossReference(
        const UaNodeId& /*sourceNodeId*/,
        const UaNodeId& /*referenceTypeId*/,
        OpcUa_Boolean   /*isForward*/,
        const UaNodeId& /*targetNodeId*/,
        NodeManager*    /*pNodeManager*/){return OpcUa_BadNotImplemented;};

    /** Delete a reference between nodes managed by different node managers.
     *  @return Error code
     */
    virtual UaStatus deleteCrossReference(
        const UaNodeId& /*sourceNodeId*/,
        const UaNodeId& /*referenceTypeId*/,
        OpcUa_Boolean   /*isForward*/,
        const UaNodeId& /*targetNodeId*/,
        NodeManager*    /*pNodeManager*/){return OpcUa_BadNotImplemented;};
};

/** @ingroup ServerCoreInterfaces
 *  Interface used to register and find NodeManagers.
 *  Used to gather access to the NodeManagerList.
 *  It is not possible to create shallow copies of this Interface.
 */
class SERVER_CORE_EXPORT NodeManagerList
{
    UA_DISABLE_COPY(NodeManagerList);
public:
    /** construction */
    NodeManagerList(){};
    /** destruction */
    virtual ~NodeManagerList(){};

    /** Get the NodeManager by namespace index
     *  @param namespaceIndex    Namespace index of the NodeManager to return.
     *  @return                  Interface pointer of NodeManager.
     */
    virtual NodeManager* getNodeManagerByNamespace(OpcUa_UInt16 namespaceIndex) const = 0;

    /** Add a NodeManager to the list
     *  @param pNodeManager             Pointer of the NodeManager to add.
     *  @param sNamespaceUri            Namespace URI used for the NodeManager.
     *  @param assignedNamespaceIndex   Assigned namespace index of the added NodeManager.
     *  @return                         Error code.
     */
    virtual UaStatus addNodeManager(
        NodeManager*    pNodeManager,
        const UaString& sNamespaceUri,
        OpcUa_UInt16&   assignedNamespaceIndex) = 0;

    /** Remove a NodeManager from the list
     *  @param namespaceIndex    Namespace index of the NodeManager to remove.
     *  @return                  Result status of the remove method.
     */
    virtual UaStatus removeNodeManager(OpcUa_UInt16 namespaceIndex) = 0;
};

/** @ingroup ServerCoreInterfaces
 *  Interface used to configure the address space in a NodeManager based on a generic node model.
 *  In this interface it is possible to manage the Nodes.
 *  It is not possible to create shallow copies of this Interface.
 */
class SERVER_CORE_EXPORT NodeManagerConfig
{
    UA_DISABLE_COPY(NodeManagerConfig);
public:
    /** construction */
    NodeManagerConfig(){};
    /** destruction */
    virtual ~NodeManagerConfig(){};

    /** Add a new UaNode to the node management.
     *  Adds the passed new node to the internal node management of the NodeManager.
     *  @param pNewNode    Pointer to UaNode interface of the new node.
     *  @return Error code
     */
    virtual UaStatus addUaNode(UaNode* pNewNode) = 0;

    /** Remove a UaNode from the node management.
     *  Removes the passed node from the internal node management of the NodeManager.
     *  @param pNode                    Pointer to UaNode interface of the node to remove.
     *  @param deleteTargetReferences   Indicates if the references from the node to delete to the target node must be deleted in the target node
     *  @param deleteSourceReferences   Indicates if the references from the source node to the node to delete must be deleted in the source node
     *  @param deleteAllChildren        Indicates if all child nodes of the node to delete and all references of the nodes must be deleted. In this case
     *                                  the function follows all forward references that are a subtype of HasChild like HasComponent or HasProperty and
     *                                  deletes the target nodes and all of their references. If this flag is set and one of the child nodes to delete
     *                                  is shared, the shared node and its children are not deleted.
     *  @return                         Error code
     */
    virtual UaStatus deleteUaNode(
        UaNode*       pNode,
        OpcUa_Boolean deleteTargetReferences,
        OpcUa_Boolean deleteSourceReferences = OpcUa_False,
        OpcUa_Boolean deleteAllChildren = OpcUa_False) = 0;

    /** Add a new node and a reference to the node management
     *  Adds the passed new node to the internal node management of the NodeManager and
     *  creates a reference from the passed source node to the new node.
     *  @param pSourceNode      Pointer to UaReferenceLists interface of the source node.
     *  @param pNewNode         Pointer to UaReferenceLists interface of the new node.
     *  @param referenceTypeId  Type of the reference to create from the source node to the new node.
     *  @return                 Error code
     */
    virtual UaStatus addNodeAndReference(
        UaReferenceLists* pSourceNode,
        UaReferenceLists* pNewNode,
        const UaNodeId&   referenceTypeId ) = 0;

    /** Add a new node and a reference to the node management
     *  Adds the passed new node to the internal node management of the NodeManager and
     *  creates a reference from the passed source node to the new node.
     *  @param sourceNode       NodeId of the source node.
     *  @param pNewNode         Pointer to UaReferenceLists interface of the new node.
     *  @param referenceTypeId  Type of the reference to create from the source node to the new node.
     *  @return                 Error code
     */
    virtual UaStatus addNodeAndReference(
        const UaNodeId&   sourceNode,
        UaReferenceLists* pNewNode,
        const UaNodeId&   referenceTypeId) = 0;

    /** Add a reference from source node to target node
     *  Creates a reference from the passed source node to the target node.
     *  @param pSourceNode      Pointer to UaReferenceLists interface of the source node.
     *  @param pTargetNode      Pointer to UaReferenceLists interface of the target node.
     *  @param referenceTypeId  Type of the reference to create from the source node to the target node.
     *  @return                 Error code
     */
    virtual UaStatus addUaReference(
        UaReferenceLists* pSourceNode,
        UaReferenceLists* pTargetNode,
        const UaNodeId&   referenceTypeId ) = 0;

    /** Add a reference from source node to target node
     *  This functions is provided for convenience and behaves like the functions above.
     *  This function finds the node objects for the specified source and target nodeIds and creates a new reference if the nodes exist.
     *  @param sourceId         NodeId of the source node.
     *  @param targetId         NodeId of the target node.
     *  @param referenceTypeId  Type of the reference to create from the source node to the target node.
     *  @return                 Error code
     */
    virtual UaStatus addUaReference(
        const UaNodeId& sourceId,
        const UaNodeId& targetId,
        const UaNodeId& referenceTypeId) = 0;

    /** Remove a reference from source node to target node
     *  Deletes a reference from the passed source node to the target node.
     *  @param pSourceNode      Pointer to UaReferenceLists interface of the source node.
     *  @param pTargetNode      Pointer to UaReferenceLists interface of the target node.
     *  @param referenceTypeId  Type of the reference to delete from the source node to the target node.
     *  @return                 Error code
     */
    virtual UaStatus deleteUaReference(
        UaReferenceLists* pSourceNode,
        UaReferenceLists* pTargetNode,
        const UaNodeId&   referenceTypeId ) = 0;

    /** Remove a reference from source node to target node
     *  This functions is provided for convenience and behaves like the functions above.
     *  This function finds the node objects for the specified source and target nodeIds and creates a deletes the reference if the nodes exist.
     *  @param sourceId         NodeId of the source node.
     *  @param targetId         NodeId of the target node.
     *  @param referenceTypeId  Type of the reference to delete from the source node to the target node.
     *  @return                 Error code
     */
    virtual UaStatus deleteUaReference(
        const UaNodeId& sourceId,
        const UaNodeId& targetId,
        const UaNodeId& referenceTypeId) = 0;

    /** Get the namespace index of the node manager
     *  @return  Namespace index of the node manager.
     */
    virtual OpcUa_UInt16 getNameSpaceIndex( ) const = 0;

    /** Get the EventManagerUaNode interface if implemented by the class implementing the NodeManagerConfig interface.
     *  The default implementation for the interface returns a NULL pointer. Classes derived from NodeManagerConfig and EventManagerUaNode must
     *  overwrite this method and must return the EventManagerUaNode interface. This connection is used to provide the EventManagerUaNode
     *  interface to UaCondition classes keeping a NodeManagerConfig interface but needing also the EventManagerUaNode Interface for sending
     *  events.
     *  @return  The method implemented in the interface returns a Null pointer.
     */
    virtual EventManagerUaNode* getEventManagerUaNode( );

    /** Get the NodeManagerNodeSetXml interface if implemented by the class implementing the NodeManagerConfig interface.
     *  The default implementation for the interface returns a NULL pointer. Classes derived from NodeManagerConfig
     *  and NodeManagerNodeSetXml must overwrite this method and must return the NodeManagerNodeSetXml interface.
     *  @return  The method implemented in the interface returns a Null pointer.
     */
    virtual NodeManagerNodeSetXml* getNodeManagerNodeSetXml( );

    /** Lock access to nodes managed by the NodeManager */
    virtual void lockNodes();
    /** Unlock access to nodes managed by the NodeManager */
    virtual void unlockNodes();
};


#endif //__NODEMANAGER_H__
