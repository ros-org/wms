/******************************************************************************
** nodemanagernodesetxml.h
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
** Description: OPC server core module internal transactions.
**
******************************************************************************/
#ifndef _NODEMANAGERUANODEADVANCEDXMLPARSER_H_
#define _NODEMANAGERUANODEADVANCEDXMLPARSER_H_

#include <uanodesetxmlparser.h>
#include "uagenericnodes.h"
#include "servermanager.h"
#include "nodemanagerbase.h"
#include "uaserverapplicationmodule.h"

class XmlUaNodeFactoryManager;

/** NodeManager implementation used as base class for NodeManagers created from Nodeset XML files.
 *
 *  A derived class can be created by passing in a NodeManagerXmlCreator object to UaNodeSetXmlParserUaNode.
 *  Node creation can be overwritten and the derived class gets informed about the completion of xml file loading.
 */
class SERVER_CORE_EXPORT NodeManagerNodeSetXml : public NodeManagerBase
{
    UA_DISABLE_COPY(NodeManagerNodeSetXml);
public:
    NodeManagerNodeSetXml(const UaString& sNamespaceUri);
    virtual ~NodeManagerNodeSetXml();
    virtual UaStatus   afterStartUp();
    virtual UaStatus   beforeShutDown();
    virtual NodeManagerNodeSetXml* getNodeManagerNodeSetXml();

    void setExtensions(const std::list<UaBase::Extension> &extensions);

    virtual void allNodesAndReferencesCreated();

    virtual void objectTypeCreated(UaObjectType* pNewNode, UaBase::ObjectType *pObjectType);
    virtual void objectCreated(UaObject* pNewNode, UaBase::Object *pObject);
    virtual void variableTypeCreated(UaVariableType* pNewNode, UaBase::VariableType *pVariableType);
    virtual void variableCreated(UaVariable* pNewNode, UaBase::Variable *pVariable);
    virtual void methodCreated(UaMethod* pNewNode, UaBase::Method *pMethod);
    virtual void referenceTypeCreated(UaReferenceType* pNewNode, UaBase::ReferenceType *pReferenceType);
    virtual void dataTypeCreated(UaDataType* pNewNode, UaBase::DataType *pDataType);
    virtual void viewCreated(UaView* pNewNode, UaBase::BaseNode *pView);

protected:
    UaBase::Extension extension(const UaString &sName) const;
    std::list<UaBase::Extension> m_extensions;
};

/** Interface for creating derived classes of NodeManagerBaseXml. */
class SERVER_CORE_EXPORT NodeManagerNodeSetXmlCreator
{
    UA_DISABLE_COPY(NodeManagerNodeSetXmlCreator);
public:
    NodeManagerNodeSetXmlCreator(){}
    virtual ~NodeManagerNodeSetXmlCreator(){}

    /** Creates an instance of NodeManagerNodeSetXml or a class derived from NodeManagerNodeSetXml
    */
    virtual NodeManagerNodeSetXml* createNodeManager(
        const UaString& sNamespaceUri //!< [in] Namespace used for the NodeManager
        );
};

/** Helper class for loading UANodeSet XML files and managing the required NodeManagers.
 *
 * The parser can read UANodeSet XML files that match the schema http://opcfoundation.org/UA/2011/03/UANodeSet.xsd.
 *
 * This class implements the UaServerApplicationModule interface which allows to plug in the
 * parsing and NodeManager startup into the normal startup process handled by the UaServerApplication
 * class and the OpcServer class derived from it.
 */
class SERVER_CORE_EXPORT UaNodeSetXmlParserUaNode:
    public UaBase::UaNodesetXmlParser,
    public UaServerApplicationModule
{
    UA_DISABLE_COPY(UaNodeSetXmlParserUaNode);
public:
    UaNodeSetXmlParserUaNode(
        const UaString&               sFilename,
        NodeManagerNodeSetXmlCreator* pNodeManagerXmlCreator,
        UaBase::BaseNodeFactory*      pBaseNodeFactory,
        XmlUaNodeFactoryManager*      pUaNodeFactory);
    virtual ~UaNodeSetXmlParserUaNode();

    virtual UaStatus startUp(ServerManager* pServerManager);
    virtual UaStatus shutDown();

private:
    UaStatus applyNodeManagers();
    UaStatus createNode(UaBase::BaseNode *pBaseNode);
    UaStatus createUnprocessedNodeRec(
        UaBase::BaseNode *pBaseNode,
        const std::map<UaNodeId, UaBase::BaseNode*> &mapNodes);
    UaStatus addReference(
        NodeManagerNodeSetXml *pNodeManager,
        const UaNodeId &sourceNodeId,
        const UaNodeId &targetNodeId,
        const UaNodeId &referenceTypeId);
    bool referenceAdded(
        UaBase::BaseNode *pBaseNode,
        const std::map<UaNodeId, UaBase::BaseNode*> &mapNodes) const;
    UaStatus processNodeAccessInfo(UaBase::BaseNode* pBaseNode, UaNode* pNode);


private:
    ServerManager* m_pServerManager;
    std::map<OpcUa_UInt16, NodeManagerUaNode*>  m_mapNsNM;
    std::map<OpcUa_UInt16, NodeManagerNodeSetXml*> m_mapNsNMXml;

    UaString                      m_sFilename;
    NodeManagerNodeSetXmlCreator* m_pNodeManagerXmlCreator;
    XmlUaNodeFactoryManager*      m_pUaNodeFactory;
    UaBase::BaseNodeFactory*      m_pProvidedNodeFactory;
};


#endif /*_NODEMANAGERUANODEADVANCEDXMLPARSER_H_*/
