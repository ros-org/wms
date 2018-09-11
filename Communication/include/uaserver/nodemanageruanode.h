/******************************************************************************
** nodemanageruanode.h
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
#ifndef __NODEMANAGERUANODE_H__
#define __NODEMANAGERUANODE_H__

#include "nodemanager.h"
#include "uafolder.h"
#include "uadatavariablecache.h"
#include "version_coremodule.h"
#include <map>
#include <uadatatypedefinition.h>
#include "opcua_datatypedictionarytype.h"

class IOManagerUaNode;
class UaStructureDefinition;
class UaEnumDefinition;
class TypeDictionaries;

/** @ingroup ServerCoreBaseClasses
 *  Callback interface for user specific browse result manipulation.
 *
 *  This interface needs to be registered with the NodeManagerUaNode using the method NodeManagerUaNode::registerBrowseUaNodeCallback.
 *  The methods of this interface allow the product specific implementation to manipulate the results of browse calls to the
 *  NodeManagerUaNode for example to limit browse access to nodes based on the user logged on for the session.
 */
class SERVER_CORE_EXPORT BrowseUaNodeCallback: public BrowseCallback
{
    UA_DISABLE_COPY(BrowseUaNodeCallback);
public:
    BrowseUaNodeCallback(){}
    virtual ~BrowseUaNodeCallback(){}

    /** This method tells the NodeManagerUaNode whether the requested node pNodeToBrowse should return any browse result.
     *
     *  @returns OpcUa_True if the user is allowed to browse the node and OpcUa_False if not.
     */
    virtual OpcUa_Boolean browseNode(
        Session*             pSession,      //!< [in] Session context for the browse call. A user defined derived class must contain the user context.
        const BrowseContext& browseContext, //!< [in] Browse context for the browse call.
        UaNode*              pNodeToBrowse  //!< [in] UaNode interface of the node requested to be browsed.
        ) const = 0;

    /** This method tells the NodeManagerUaNode whether the result node should be returned to the client.
     *
     *  @returns OpcUa_True if the node should be returned and OpcUa_False if not.
     */
    virtual OpcUa_Boolean returnBrowseResultNode(
        Session*             pSession,        //!< [in] Session context for the browse call. A user defined derived class must contain the user context.
        const BrowseContext& browseContext,   //!< [in] Browse context for the browse call.
        UaNode*              pNodeToBrowse,   //!< [in] UaNode interface of the browsed node.
        const UaNodeId&      referenceTypeId, //!< [in] The reference type NodeId from the browsed node to the result node.
        UaNode*              pResultNode      //!< [in] UaNode interface of the node requested to be returned by the browse call.
        ) const = 0;
};

/** @ingroup ServerCoreBaseClasses
 *  Implementation of the interface NodeManager operating on a generic address space node model.
 *
 *  This class implements most of the functionality necessary for a client to navigate through the
 *  nodes of the namespace managed by this NodeManager. A derived class containing the product specific
 *  implementation must implement the functions #afterStartUp to create the nodes of the address space and
 *  #beforeShutDown to clean up resources in the NodeManager. It is possible to add and remove nodes and
 *  references by using the interface NodeManagerConfig implemented by this NodeManager class.
 */
class SERVER_CORE_EXPORT NodeManagerUaNode:
    public NodeManager,
    public NodeManagerConfig,
    public NodeManagerCrossReferences,
    public UaDataTypeDictionary
{
    UA_DISABLE_COPY(NodeManagerUaNode);
    NodeManagerUaNode();
public:
    NodeManagerUaNode(const UaString& sNamespaceUri, OpcUa_Int32 nHashTableSize);
    virtual ~NodeManagerUaNode();

    /** This method needs to be implemented by the derived class and is called to finish the startup of the NodeManager.
     *
     *  This method is typically used to initialize the NodeManager and to create the nodes available at startup.
     *  @return Result code
     */
    virtual UaStatus   afterStartUp() = 0;

    /** This method needs to be implemented by the derived class and is called to start the shutdown of the NodeManager.
     *
     *  This method is typically used to clean up resources in the NodeManager. The nodes created in the NodeManager are
     *  automatically deleted by the NodeManager.
     *  @return Result code
     */
    virtual UaStatus   beforeShutDown() = 0;

    /** Get the responsible IOManager for the node and attribute combination.
     *  @param pUaNode the actual Node where to get all information from.
     *  @param attributeId AttributeId of the requested node
     *  @return a Variable to the IOManager.
     */
    virtual IOManager* getIOManager(UaNode* pUaNode, OpcUa_Int32 attributeId) const = 0;

    virtual UaNode* getNode(const UaNodeId& nodeId);

    void registerBrowseUaNodeCallback(BrowseUaNodeCallback* pBrowseUaNodeCallback);

    // Setter for specialized MethodManagers
    void setDefaultMethodManager(MethodManager* pMethodManager);
    void setFallbackMethodManager(MethodManager* pMethodManager);

    //- Interface NodeManagerConfig --------------------------------------------------------
    UaStatus addUaNode(UaNode* pNewNode);
    UaStatus deleteUaNode(UaNode* pNode, OpcUa_Boolean deleteTargetReferences, OpcUa_Boolean deleteSourceReferences = OpcUa_False, OpcUa_Boolean deleteAllChildren = OpcUa_False);
    UaStatus addNodeAndReference(UaReferenceLists* pSourceNode, UaReferenceLists* pNewNode, const UaNodeId& referenceTypeId);
    UaStatus addNodeAndReference(const UaNodeId& sourceNode, UaReferenceLists* pNewNode, const UaNodeId& referenceTypeId);
    UaStatus addUaReference(UaReferenceLists* pSourceNode, UaReferenceLists* pTargetNode, const UaNodeId& referenceTypeId);
    UaStatus addUaReference(const UaNodeId& sourceId, const UaNodeId& targetId, const UaNodeId& referenceTypeId);
    UaStatus deleteUaReference(UaReferenceLists* pSourceNode, UaReferenceLists* pTargetNode, const UaNodeId& referenceTypeId);
    UaStatus deleteUaReference(const UaNodeId& sourceId, const UaNodeId& targetId, const UaNodeId& referenceTypeId);
    /** Get the namespace index of the NodeManager. */
    inline OpcUa_UInt16 getNameSpaceIndex() const {return m_nNamespaceIndex;};
    void lockNodes();
    void unlockNodes();
    //- Interface NodeManagerConfig --------------------------------------------------------

    //- Interface NodeManager ------------------------------------------------------------------
    virtual UaStatus startUp(ServerManager*);
    virtual UaStatus shutDown();
    virtual UaStatus browse(const ServiceContext&, BrowseContext&, UaReferenceDescriptions&);
    virtual UaStatus translateBrowsePathToNodeId(const ServiceContext&, const UaNodeId&, UaRelativePath&, UaBrowsePathTargets&);
    virtual VariableHandle* getVariableHandle(Session*, VariableHandle::ServiceType, OpcUa_NodeId*, OpcUa_Int32) const;
#if SUPPORT_Method_Server_Facet
    virtual MethodHandle* getMethodHandle(Session*, OpcUa_NodeId*, OpcUa_NodeId*, UaStatus&) const;
#endif // SUPPORT_Method_Server_Facet
    virtual NodeManagerCrossReferences* getNodeManagerCrossReferences();
    virtual NodeManagerConfig* getNodeManagerConfig();
    virtual NodeManagerUaNode* getNodeManagerUaNode();
    //- Interface NodeManager ------------------------------------------------------------------

    //- Interface NodeManagerCrossReferences -----------------------------------------------
    virtual UaStatus connectStartingNode(const UaNodeId&, NodeManager*, OpcUa_Boolean, OpcUa_Boolean);
    virtual UaStatus disconnectStartingNode(const UaNodeId&, NodeManager*);
    virtual UaStatus addCrossReference(const UaNodeId&, const UaNodeId&, OpcUa_Boolean, const UaNodeId&, NodeManager*);
    virtual UaStatus deleteCrossReference(const UaNodeId&, const UaNodeId&, OpcUa_Boolean, const UaNodeId&, NodeManager*);
    //- Interface NodeManagerCrossReferences -----------------------------------------------

    //- Generic structured type support ----------------------------------------------------
    UaStatus addTypeDictionary(const UaNodeId &nodeId, const UaString &sName, const UaString &sNamespaceUri = UaString());
    UaStatus setTypeDictionary(OpcUa::DataTypeDictionaryType* pTypeDictionary);
#ifdef HAVE_XML_ENCODER
    UaStatus addTypeDictionaryXml(const UaNodeId &nodeId, const UaString &sName, const UaString &sNamespaceUri = UaString());
    UaStatus setXmlTypeDictionary(OpcUa::DataTypeDictionaryType* pTypeDictionary);
#endif
    UaStatus addStructuredType(const UaStructureDefinition &structure);
    UaStatus addStructuredTypes(std::list<UaStructureDefinition> &structures);
    UaStatus addStructuredTypeDefinition(const UaStructureDefinition &structure);
    UaStatus addEnumeratedType(const UaEnumDefinition &enumeration, const UaNodeId &enumerationPropertyId = UaNodeId());
    UaStatus addEnumeratedTypes(std::list<UaEnumDefinition> &enumerations);
    UaStatus addEnumeratedTypeDefinition(const UaEnumDefinition &enumeration);
    UaStatus addOptionSetType(const UaOptionSetDefinition &optionSet, const UaNodeId &optionSetPropertyId = UaNodeId());
    UaStatus addOptionSetTypes(std::list<UaOptionSetDefinition> &optionSets);
    UaStatus addOptionSetTypeDefinition(const UaOptionSetDefinition &optionSet);
    void setDataTypeVersion(const UaString &sDataTypeVersion);
    UaString dataTypeVersion() const;

    void findDefinitionsForStructureFields();

    /* UaDataTypeDictionary interface */
    virtual UaDataTypeDictionary::DefinitionType definitionType(const UaNodeId &dataTypeId);
    virtual UaEnumDefinition enumDefinition(const UaNodeId &dataTypeId);
    virtual UaStructureDefinition structureDefinition(const UaNodeId &dataTypeId);
    virtual UaOptionSetDefinition optionSetDefinition(const UaNodeId &dataTypeId);
    //- Generic structured type support ----------------------------------------------------

    virtual IOManagerUaNode* getIOManagerUaNode(){return NULL;}
protected:
    UaStatusCode createNodeManagerAliasNode(const UaNodeId &sourceNodeId);
    UaStatusCode clearAllNodes();

    /* Find a UaNode by UaNodeId. */
    UaNode* findNode(const UaNodeId &nodeId) const;

    /* Find a UaNode by OpcUa_NodeId. */
    UaNode* findNode(const OpcUa_NodeId* pNodeId) const;

    /** Gets the namespace URI of this NodeManager.
     *  @return the requested namespace URI.
     */
    inline UaString      getNameSpaceUri(){return m_sNamespaceUri;};

    /** Checks whether the NodeManager is started or not.
     *  @return a bool value indicating whether the nodemanager is started or not.
     */
    inline OpcUa_Boolean isStarted(){return m_isStarted;};

    /// @brief Central server manager object.
    ServerManager*                 m_pServerManager;
    /// @brief NodeManagerCrossReferences interface of NodeManager root (namespace 0).
    NodeManagerCrossReferences*    m_pNodeManagerCrossReferences0;
    /// @brief NodeManagerList interface of NodeManager root (namespace 0).
    NodeManagerList*               m_pNodeManagerList;
    /// @brief Default LocaleId for the NodeManager.
    UaString                       m_defaultLocaleId;
    /// @brief Flag indicating whether the NodeManager was started.
    OpcUa_Boolean                  m_isStarted;
    OpcUa_Boolean                  m_isStartUpCompleted;
    /// @brief This mutex is used to synchronize access to the nodes and references in this NodeManager.
    mutable UaMutex                m_mutexNodes;
    /// @brief Namespace index of this NodeManager.
    OpcUa_UInt16                   m_nNamespaceIndex;
    /// @brief Namespace URI of this NodeManager.
    UaString                       m_sNamespaceUri;
    /// @brief Hash table for the nodes managed by this NodeManager.
    HashTable*                     m_pTable;
    /// @brief Mutex used to protect access to the cross NodeManager alias nodes.
    UaMutex                        m_mutexAliasTable;
    /// @brief List of cross NodeManager alias nodes.
    UaObjectPointerArray<UaNodeId> m_crossNodeManagerAliasNodes;
    /// @brief Callback interface to influence browse results.
    BrowseUaNodeCallback*          m_pBrowseUaNodeCallback;
    /// @brief Method manager called if object and method were found but object does not implement MethodManager.
    MethodManager*                 m_pDefaultMethodManager;
    /// @brief Method manager called with NodeIds if object and method were not found, like for conditions without nodes in address space.
    MethodManager*                 m_pFallbackMethodManager;
    /// @brief Used for managing custom Structured DataTypes and Enumerated DataTypes that are added
    /// during runtime.
    TypeDictionaries *m_pTypeDictionaries;
};


#endif //__NODEMANAGER_H__
