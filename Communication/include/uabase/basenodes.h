/******************************************************************************
** basenodes.h
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
** Description: OPC UA SDK base module
**
******************************************************************************/
#ifndef BASENODES_H
#define BASENODES_H

#include <uanodeid.h>
#include <uaqualifiedname.h>
#include <ualocalizedtext.h>
#include <uavariant.h>
#include <uaarraytemplates.h>
#include "userdatabase.h"
#include "uastructuredefinition.h"
#include "uaenumdefinition.h"

#include <list>
#include <map>


namespace UaBase
{

class BaseNode;

/** Stores the information of the Reference.
 *
 * Contains the UaNodeId of the target, the ReferenceTypeId and a flag that indicates whether
 * the reference is a forward reference.
 * Used by UaNodeSetXmlParser.
 */
class UABASE_EXPORT Reference
{
public:
    Reference();
    Reference(const UaNodeId &referenceTypeId, bool bIsForward, const UaNodeId &targetNodeId);
    ~Reference();

    void setTargetNodeId(const UaNodeId &targetNodeId);
    UaNodeId targetNodeId() const;
    void setIsForward(bool bIsForward);
    bool isForward() const;
    void setReferenceTypeId(const UaNodeId &referenceTypeId);
    UaNodeId referenceTypeId() const;

    bool operator ==(const Reference &other) const;

private:
    UaNodeId m_referenceTypeId;
    bool m_bIsForward;
    UaNodeId m_targetNodeId;
};

/** Stores the information of the Reference.
 *
 * Contains pointers of the source and the target node of the reference and the
 * ReferenceTypeId.
 * Used by UaNodeSetXmlParser.
 */
class UABASE_EXPORT FullReference
{
public:
    FullReference();
    FullReference(const UaNodeId &referenceTypeId, BaseNode *pSource, BaseNode *pTarget);
    FullReference(const FullReference &other);

    void setReferenceTypeId(const UaNodeId &referenceTypeId);
    UaNodeId referenceTypeId() const;
    void setSourceNode(BaseNode *pSource);
    BaseNode* sourceNode() const;
    void setTargetNode(BaseNode *pTarget);
    BaseNode* targetNode() const;

    FullReference& operator=(const FullReference &other);
    bool operator ==(const FullReference &other) const;

private:
    UaNodeId m_referenceTypeId;
    BaseNode *m_pSourceNode;
    BaseNode *m_pTargetNode;

};

/** Stores the information of an Extension that is added to a node in a NodeSet XML file.
 *
 * Used by UaNodeSetXmlParser.
 */
class UABASE_EXPORT Extension
{
public:
    Extension();

    UaString name() const;
    void setName(const UaString &sName);
    UaByteString value() const;
    void setValue(const UaByteString &bsValue);
    UaString xmlNamespace() const;
    void setXmlNamespace(const UaString &sNamespace);

private:
    UaString m_sName;
    UaByteString m_bsValue;
    UaString m_sNamespace;
};

/** Stores the information of BaseNode.
 *
 * Implements a default method for accessing UserData from the Extensions.
 * Used by UaNodeSetXmlParser.
 */
class UABASE_EXPORT BaseNode
{
protected:
    BaseNode();
public:
    virtual ~BaseNode();

    virtual void setNodeId(const UaNodeId &nodeId);
    UaNodeId nodeId() const;
    /**Returns the NodeClass of the BaseNode.*/
    virtual OpcUa_NodeClass nodeClass() const = 0;
    void setBrowseName(const UaQualifiedName &browseName);
    UaQualifiedName browseName() const;
    void setDisplayName(const UaLocalizedText &displayName);
    UaLocalizedText displayName() const;
    void setDescription(const UaLocalizedText &description);
    UaLocalizedText description() const;
    void setWriteMask(OpcUa_UInt32 writeMask);
    OpcUa_UInt32 writeMask() const;
    void setUserWriteMask(OpcUa_UInt32 userWriteMask);
    OpcUa_UInt32 userWriteMask() const;

    void setParentNodeId(const UaNodeId &parentNodeId);
    UaNodeId parentNodeId() const;
    BaseNode* parentNode(const std::map<UaNodeId, BaseNode*> &mapNodes) const;

    void setProcessed(bool bProcessed = true);
    bool isProcessed() const;

    virtual void evaluateReferences(const std::map<UaNodeId, BaseNode*> &mapNodes);
    virtual bool evaluateModelParents(const std::map<UaNodeId, BaseNode*> &mapNodes);
    void parentNode(UaNodeId &rNodeId, UaNodeId &rReferenceTypeId) const;

    void addReference(const Reference &reference);
    void removeReference(const Reference &reference);
    void addFullReference(const FullReference &reference);

    bool isHierarchicallyReferenced() const;
    std::list<BaseNode*> hierarchicallyReferencedNodes() const;
    const std::list<Reference>& references() const;

    void addExtension(const Extension &extension);
    OpcUa_UInt32 extensionCount();
    const std::list<Extension>& extensions() const;
    const Extension* extension(const UaString &sName) const;
    const Extension* extension(const UaString &sName, const UaString &sNamespace) const;

    virtual UserDataBase* userData() const;

protected:
    UaNodeId m_nodeId;
    UaQualifiedName m_browseName;
    UaLocalizedText m_displayName;
    UaLocalizedText m_description;
    OpcUa_UInt32    m_writeMask;
    OpcUa_UInt32    m_userWriteMask;

    UaNodeId        m_parentNodeId;

    bool            m_bProcessed;

    std::list<Reference> m_lstReferences;
    std::list<FullReference> m_lstFullReferences;
    std::list<Extension> m_lstExtensions;
};

/** Stores the information of an Object node.
 *
 * Used by UaNodeSetXmlParser.
 */
class UABASE_EXPORT Object :
    public BaseNode
{
public:
    Object();
    Object(const UaNodeId &nodeId);
    ~Object();

    virtual OpcUa_NodeClass nodeClass() const;

    UaNodeId typeDefinitionId() const;
    UaNodeId modellingRuleId() const;
    void setTypeDefinitionId(const UaNodeId &typeDefinitionId);
    void setModellingRuleId(const UaNodeId &typeDefinitionId);

    void setEventNotifier(OpcUa_Byte eventNotifier);
    OpcUa_Byte eventNotifier() const;

private:
    OpcUa_Byte m_eventNotifier;
};

/** Stores the information of a Variable node.
 *
 * Used by UaNodeSetXmlParser.
 */
class UABASE_EXPORT Variable :
    public BaseNode
{
public:
    Variable();
    Variable(const UaNodeId &nodeId);
    ~Variable();

    virtual OpcUa_NodeClass nodeClass() const;

    UaNodeId typeDefinitionId() const;
    UaNodeId modellingRuleId() const;
    void setTypeDefinitionId(const UaNodeId &typeDefinitionId);
    void setModellingRuleId(const UaNodeId &typeDefinitionId);

    void setAccessLevel(OpcUa_Byte accessLevel);
    OpcUa_Byte accessLevel() const;
    void setUserAccessLevel(OpcUa_Byte userAccessLevel);
    OpcUa_Byte userAccessLevel() const;
    void setDataTypeId(const UaNodeId &dataTypeId);
    UaNodeId dataTypeId() const;
    void setValueRank(OpcUa_Int32 valueRank);
    OpcUa_Int32 valueRank() const;
    void setArrayDimensions(const UaUInt32Array &arrayDimensions);
    UaUInt32Array arrayDimensions() const;
    void setValue(const UaVariant &value);
    UaVariant value() const;
    void setMinimumSamplingInterval(OpcUa_Double minimumSamplingInterval);
    OpcUa_Double minimumSamplingInterval() const;
    void setHistorizing(OpcUa_Boolean historizing);
    OpcUa_Boolean historizing() const;

    virtual bool evaluateModelParents(const std::map<UaNodeId, BaseNode*> &mapNodes);

private:
    OpcUa_Byte m_accessLevel;
    OpcUa_Byte m_userAccessLevel;
    UaNodeId m_dataTypeId;
    OpcUa_Int32 m_valueRank;
    UaUInt32Array m_arrayDimensions;
    UaVariant m_value;
    OpcUa_Double m_minimumSamplingInterval;
    OpcUa_Boolean m_historizing;
};

/** Stores the information of a Method node.
 *
 * Used by UaNodeSetXmlParser.
 */
class UABASE_EXPORT Method :
    public BaseNode
{
public:
    Method();
    Method(const UaNodeId &nodeId);

    virtual OpcUa_NodeClass nodeClass() const;

    UaNodeId modellingRuleId() const;
    void setModellingRuleId(const UaNodeId &typeDefinitionId);

    void setExecutable(OpcUa_Boolean bExecutable);
    OpcUa_Boolean executable() const;
    void setUserExecutable(OpcUa_Boolean bExecutable);
    OpcUa_Boolean userExecutable() const;

private:
    OpcUa_Boolean m_executable;
    OpcUa_Boolean m_userExecutable;
};

/** Stores the information of a Type node.
 *
 * Used by UaNodeSetXmlParser.
 */
class UABASE_EXPORT TypeNode :
    public BaseNode
{
protected:
    TypeNode();
public:
    void setIsAbstract(OpcUa_Boolean bIsAbstract);
    OpcUa_Boolean isAbstract() const;
    void setSuperTypeId(const UaNodeId &superTypeId);
    UaNodeId superTypeId() const;
    virtual void evaluateReferences(const std::map<UaNodeId, BaseNode*> &mapNodes);

private:
    OpcUa_Boolean m_bIsAbstract;
    UaNodeId m_superTypeId;
};

/** Stores the information of a DataType node.
 *
 * Used by UaNodeSetXmlParser.
 */
class UABASE_EXPORT DataType :
    public TypeNode
{
public:
    DataType();
    DataType(const UaNodeId &nodeId);

    virtual OpcUa_NodeClass nodeClass() const;

    void setStructureDefinition(const UaStructureDefinition &structure);
    UaStructureDefinition structureDefinition() const;
    void setEnumDefinition(const UaEnumDefinition &enumeration);
    UaEnumDefinition enumDefinition() const;

    virtual void evaluateReferences(const std::map<UaNodeId, BaseNode*> &mapNodes);

private:
    UaStructureDefinition m_structureDefinition;
    UaEnumDefinition m_enumDefinition;
};

/** Stores the information of a ReferenceType node.
 *
 * Used by UaNodeSetXmlParser.
 */
class UABASE_EXPORT ReferenceType :
    public TypeNode
{
public:
    ReferenceType();
    ReferenceType(const UaNodeId &nodeId);

    virtual OpcUa_NodeClass nodeClass() const;

    void setSymmetric(OpcUa_Boolean bSymmetric);
    OpcUa_Boolean symmetric() const;
    void setInverseName(const UaLocalizedText &inverseName);
    UaLocalizedText inverseName() const;

private:
    OpcUa_Boolean m_bSymmetric;
    UaLocalizedText m_inverseName;
};

/** Stores the information of an ObjectType node.
 *
 * Used by UaNodeSetXmlParser.
 */
class UABASE_EXPORT ObjectType :
    public TypeNode
{
public:
    ObjectType();
    ObjectType(const UaNodeId &nodeId);

    virtual OpcUa_NodeClass nodeClass() const;
};

/** Stores the information of a VariableType node.
 *
 * Used by UaNodeSetXmlParser.
 */
class UABASE_EXPORT VariableType :
    public TypeNode
{
public:
    VariableType();
    VariableType(const UaNodeId &nodeId);
    ~VariableType();

    virtual OpcUa_NodeClass nodeClass() const;

    void setDataType(const UaNodeId &dataTypeId);
    UaNodeId dataTypeId() const;
    void setValueRank(OpcUa_Int32 valueRank);
    OpcUa_Int32 valueRank() const;
    void setArrayDimensions(const UaUInt32Array &arrayDimensions);
    UaUInt32Array arrayDimensions() const;
    void setValue(const UaVariant &value);
    UaVariant value() const;

private:
    UaNodeId m_dataTypeId;
    OpcUa_Int32 m_valueRank;
    UaUInt32Array m_arrayDimensions;
    UaVariant m_value;
};

/** A factory to create subtypes of BaseNode.
 *
 * You can create a subtype to instantiate your own subtypes of BaseNode, e.g. within
 * UaNodeSetXmlParser.
 */
class UABASE_EXPORT BaseNodeFactory
{
public:
    BaseNodeFactory(){}
    virtual ~BaseNodeFactory(){}
    virtual Object* createObject(const UaNodeId &nodeId) const;
    virtual Variable* createVariable(const UaNodeId &nodeId) const;
    virtual Method* createMethod(const UaNodeId &nodeId) const;
    virtual DataType* createDataType(const UaNodeId &nodeId) const;
    virtual ReferenceType* createReferenceType(const UaNodeId &nodeId) const;
    virtual ObjectType* createObjectType(const UaNodeId &nodeId) const;
    virtual VariableType* createVariableType(const UaNodeId &nodeId) const;
};

/** A default class for UserData.
 *
 * Parses the content of an Extension. Sets the Address attribute of the Extension to the
 * address.
 */
class UABASE_EXPORT BaseNodeStandardUserData : public UserDataBase
{
public:
    BaseNodeStandardUserData(const Extension &extension);
    virtual UserDataType getUserDataType() const;
    int address() const;
private:
    int m_iAddress;
};

}

#endif // BASENODES_H
