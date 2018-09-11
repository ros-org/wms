/******************************************************************************
** uagenericnodes.h
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
** Description: OPC UA server core module generic node classes.
**
******************************************************************************/
#ifndef __UAGENERIC_H__
#define __UAGENERIC_H__

#include "uabasenodes.h"
#include "uadatetime.h"
#include "uadatavariablecache.h"

/*! \addtogroup ServerCoreAddressModel
*  @{
*/

/** @brief Derived from UaObject and UaReferenceLists.
 */
class SERVER_CORE_EXPORT UaGenericObject :
    public UaObject,
    public UaReferenceLists
{
protected:
    /** destruction */
    virtual ~UaGenericObject();
public:
    /** construction */
    UaGenericObject(
        const UaNodeId&        nodeId,
        const UaQualifiedName& browseName,
        const UaLocalizedText& displayName,
        const UaLocalizedText& description,
        const UaNodeId&        typeDefinitionId,
        OpcUa_Byte             eventNotifier);

    /** Discover the references of a specified node of a view.
     *  This method is used to return a list of references and target nodes for the passed node to browse for the
     *  services Browse and BrowseNext.
     *  @param serviceContext   General context for the service calls containing information like the session object,
     *                          return diagnostic mask and timeout hint.
     *  @param browseContext    Browse context for the first browse or the following browse with continuation point.
     *  @param References       Array of ReferenceDescription results for the browsed node.
     *  @return                 Error code
     */
    UaStatus browse(
        const ServiceContext&    serviceContext,
        BrowseContext&           browseContext,
        UaReferenceDescriptions& References);

    /** Get the NodeId of the current Node.
     *  @return the NodeId of the current Node.
     */
    virtual UaNodeId        nodeId() const {return m_nodeId;};

    /** Get the browseName as QualifiedName of the current Node.
     *  @return the BrowseName for the DataVariable as QualifiedName.
     */
    virtual UaQualifiedName browseName() const {return m_browseName;};

    /** Get the displayName as LocalizedText of the current Node.
     *  @return the LocalizedText of the current Node.
     */
    virtual UaLocalizedText displayName(Session*) const {return m_displayName;};

    /** Check if Node is DescriptionSupported.
     *  @return FALSE if not supported.
     */
    virtual OpcUa_Boolean   isDescriptionSupported() const {return OpcUa_True;};

    /** Get the description as LocalizedText of the current Node.
     *  @return the LocalizedText of the current Node.
     */
    virtual UaLocalizedText description(Session*) const {return m_description;};

    /** Check if Node is WriteMaskSupported.
     *  m@return TRUE if Node is WriteMaskSupported.
     */
    virtual OpcUa_Boolean   isWriteMaskSupported() const {return OpcUa_True;};

    /** Get the writeMask of the current Node.
     *  @return the writeMask.
     */
    virtual OpcUa_UInt32    writeMask() const {return m_writeMask;};

    /** Check if Node is UserWriteMaskSupported.
     *  @return TRUE if Node is UserWriteMaskSupported.
     */
    virtual OpcUa_Boolean   isUserWriteMaskSupported() const {return OpcUa_True;};

    /** Get the WriteMask of the User.
     *  @return the WriteMask of the User.
     */
    virtual OpcUa_UInt32    userWriteMask(Session* /*pSession*/) const {return m_writeMask;};

    /** Get the object type NodeId for the server object.
     *  @return the object type NodeId for the server object.
     */
    virtual UaNodeId        typeDefinitionId() const {return m_typeDefinitionId;};

    /** Provides the information if the object can be used to subscribe for events.
     *  @return the EventNotifier attribute value for the Object.
     */
    virtual OpcUa_Byte      eventNotifier() const {return m_eventNotifier;};

    /** Get the NodeClass of the current Node.
     *  @return the NodeClass of the current Node.
     */
    OpcUa_NodeClass nodeClass() const { return OpcUa_NodeClass_Object; };

    /** Get the MethodManager interface of an Object.
     *  @return the MethodManager interface of an Object.
     */
    virtual MethodManager* getMethodManager(UaMethod* /*pMethod*/) const {return NULL;};

    /** Get the Node.
     *  @return the current searched Node.
     */
    UaNode* getUaNode() const {return (UaNode*)this;};

    /** Get a ReferenceList where all the Nodes are in.
     *  @return a ReferenceList where all the Nodes are in.
     */
    UaReferenceLists* getUaReferenceLists() const {return (UaReferenceLists*)this;};

    /** Sets the write mask attribute.
     */
    virtual void setWriteMask(OpcUa_UInt32 writeMask) {m_writeMask = writeMask;}

    virtual UaStatus  setAttributeValue(Session* pSession, OpcUa_Int32 attributeId, const UaDataValue& dataValue, OpcUa_Boolean checkWriteMask);

private:
    UaNodeId        m_nodeId;
    UaQualifiedName m_browseName;
    UaLocalizedText m_displayName;
    UaLocalizedText m_description;
    OpcUa_UInt32    m_writeMask;
    UaNodeId        m_typeDefinitionId;
    OpcUa_Byte      m_eventNotifier;
};

/** @brief Derived from UaObjectType and UaReferenceLists.
 */
class SERVER_CORE_EXPORT UaGenericObjectType :
    public UaObjectType,
    public UaReferenceLists
{
protected:
    /** destruction */
    virtual ~UaGenericObjectType();
public:
    /** construction */
    UaGenericObjectType(
        const UaNodeId&        nodeId,
        const UaQualifiedName& browseName,
        const UaLocalizedText& displayName,
        const UaLocalizedText& description,
        OpcUa_Boolean          isAbstract);

    /** Discover the references of a specified node of a view.
     *  This method is used to return a list of references and target nodes for the passed node to browse for the
     *  services Browse and BrowseNext.
     *  @param serviceContext   General context for the service calls containing information like the session object,
     *                          return diagnostic mask and timeout hint.
     *  @param browseContext    Browse context for the first browse or the following browse with continuation point.
     *  @param References       Array of ReferenceDescription results for the browsed node.
     *  @return                 Error code
     */
    UaStatus browse(
        const ServiceContext&    serviceContext,
        BrowseContext&           browseContext,
        UaReferenceDescriptions& References);

    /** Get the NodeId of the current Node.
     *  @return the NodeId of the current Node.
     */
    virtual UaNodeId        nodeId() const {return m_nodeId;};

    /** Get the browseName as QualifiedName of the current Node.
     *  @return the BrowseName for the DataVariable as QualifiedName.
     */
    virtual UaQualifiedName browseName() const {return m_browseName;};

    /** Get the displayName as LocalizedText of the current Node.
     *  @return the LocalizedText of the current Node.
     */
    virtual UaLocalizedText displayName(Session*) const {return m_displayName;};

    /** Check if Node is DescriptionSupported.
     *  @return FALSE if not supported.
     */
    virtual OpcUa_Boolean   isDescriptionSupported() const {return OpcUa_True;};

    /** Get the description as LocalizedText of the current Node.
     *  @return the LocalizedText of the current Node.
     */
    virtual UaLocalizedText description(Session*) const {return m_description;};

    /** Check if Node is WriteMaskSupported.
     *  @return TRUE if Node is WriteMaskSupported.
     */
    virtual OpcUa_Boolean   isWriteMaskSupported() const {return OpcUa_True;};

    /** Get the writeMask of the current Node.
     *  @return the writeMask.
     */
    virtual OpcUa_UInt32    writeMask() const {return m_writeMask;};

    /** Check if Node is UserWriteMaskSupported.
     *  @return TRUE if Node is UserWriteMaskSupported.
     */
    virtual OpcUa_Boolean   isUserWriteMaskSupported() const {return OpcUa_True;};

    /** Get the WriteMask of the User.
     *  @return the WriteMask of the User.
     */
    virtual OpcUa_UInt32    userWriteMask(Session* /*pSession*/) const {return m_writeMask;};

    /** Check if Node is Abstract.
     *  @return TRUE if is Abstract FALSE if not.
     */
    virtual OpcUa_Boolean   isAbstract() const {return m_isAbstract;};

    /** Get the NodeClass of the current Node.
     *  @return the NodeClass of the current Node.
     */
    OpcUa_NodeClass   nodeClass() const { return OpcUa_NodeClass_ObjectType; };

    /** Get the object type NodeId for the server object.
     *  @return the object type NodeId for the server object.
     */
    UaNodeId          typeDefinitionId() const { return UaNodeId(); };

    /** Get the Node.
     *  @return the current searched Node.
     */
    UaNode*           getUaNode() const {return (UaNode*)this;};

    /** Get a ReferenceList where all the Nodes are in.
     *  @return a ReferenceList where all the Nodes are in.
     */
    UaReferenceLists* getUaReferenceLists() const {return (UaReferenceLists*)this;};

    /** Sets the write mask attribute.
     */
    virtual void setWriteMask(OpcUa_UInt32 writeMask) {m_writeMask = writeMask;}

    virtual UaStatus  setAttributeValue(Session* pSession, OpcUa_Int32 attributeId, const UaDataValue& dataValue, OpcUa_Boolean checkWriteMask);

private:
    UaNodeId        m_nodeId;
    UaQualifiedName m_browseName;
    UaLocalizedText m_displayName;
    UaLocalizedText m_description;
    OpcUa_UInt32    m_writeMask;
    OpcUa_Boolean   m_isAbstract;
};

/** @brief Derived from UaVariableCache and UaReferenceLists.
 */
class SERVER_CORE_EXPORT UaGenericVariable :
    public UaVariableCache,
    public UaReferenceLists
{
protected:
    /** destruction */
    virtual ~UaGenericVariable();
public:
    /** construction */
    UaGenericVariable(
        const UaNodeId&        nodeId,
        const UaQualifiedName& browseName,
        const UaLocalizedText& displayName,
        const UaLocalizedText& description,
        const UaNodeId&        typeDefinitionId,
        const UaVariant&       value,
        const UaNodeId&        dataTyp,
        OpcUa_Int32            valueRank,
        OpcUa_Byte             accessLevel,
        OpcUa_Byte             userAccessLevel,
        OpcUa_Double           minimumSamplingInterval,
        OpcUa_Boolean          historizing);

    /** Discover the references of a specified node of a view.
     *  This method is used to return a list of references and target nodes for the passed node to browse for the
     *  services Browse and BrowseNext.
     *  @param serviceContext   General context for the service calls containing information like the session object,
     *                          return diagnostic mask and timeout hint.
     *  @param browseContext    Browse context for the first browse or the following browse with continuation point.
     *  @param References       Array of ReferenceDescription results for the browsed node.
     *  @return                 Error code
     */
    UaStatus browse(
        const ServiceContext&    serviceContext,
        BrowseContext&           browseContext,
        UaReferenceDescriptions& References);

    /** Get the NodeId of the current Node.
     *  @return the NodeId of the current Node.
     */
    virtual UaNodeId        nodeId() const {return m_nodeId;};

    /** Get the browseName as QualifiedName of the current Node.
     *  @return the BrowseName for the DataVariable as QualifiedName.
     */
    virtual UaQualifiedName browseName() const {return m_browseName;};

    /** Get the displayName as LocalizedText of the current Node.
     *  @return the LocalizedText of the current Node.
     */
    virtual UaLocalizedText displayName(Session*) const {return m_displayName;};

    /** Check if Node is DescriptionSupported.
     *  @return FALSE if not supported.
     */
    virtual OpcUa_Boolean   isDescriptionSupported() const {return OpcUa_True;};

    /** Get the description as LocalizedText of the current Node.
     *  @return the LocalizedText of the current Node.
     */
    virtual UaLocalizedText description(Session*) const {return m_description;};

    /** Check if Node is WriteMaskSupported.
     *  @return TRUE if Node is WriteMaskSupported.
     */
    virtual OpcUa_Boolean   isWriteMaskSupported() const {return OpcUa_True;};

    /** Get the writeMask of the current Node.
     *  @return the writeMask.
     */
    virtual OpcUa_UInt32    writeMask() const {return m_writeMask;};

    /** Check if Node is UserWriteMaskSupported.
     *  @return TRUE if Node is UserWriteMaskSupported.
     */
    virtual OpcUa_Boolean   isUserWriteMaskSupported() const {return OpcUa_True;};

    /** Get the WriteMask of the User.
     *  @return the WriteMask of the User.
     */
    virtual OpcUa_UInt32    userWriteMask(Session* /*pSession*/) const {return m_writeMask;};

    /** Sets the current value for the DataVariable.
     *  @param pSession Interface to the Session context for the method call
     *  @return the current value for the DataVariable.
     */
    virtual UaDataValue     value(Session* pSession);

    /** Sets the current value for the DataVariable.
     *  @param pSession Interface to the Session context for the method call
     *  @param dataValue Cached value of the DataVariable.
     *  @param checkAccessLevel checks the Access Level of the current Session.
     *  @return Error code
     */
    virtual UaStatus        setValue(Session* pSession, const UaDataValue& dataValue, OpcUa_Boolean checkAccessLevel = OpcUa_True);

    /** Get the DataType for the DataVariable.
     *  @return the DataType for the DataVariable.
     */
    virtual UaNodeId        dataType() const {return m_dataTyp;};

    /** Get the ValueRank for the DataVariable.
     *  @return the ValueRank for the DataVariable.
     */
    virtual OpcUa_Int32     valueRank() const {return m_valueRank;};

    /** Check if the Node is ArrayDimensionsSupported.
     *  @return FALSE if not supported.
     */
    virtual OpcUa_Boolean   isArrayDimensionsSupported() const {return OpcUa_True;};

    /** Get the arrayDimensions value for the passed UaNode.
     *  @param arrayDimensions the arrayDimensions value for the passed UaNode.
     */
    virtual void            arrayDimensions(UaUInt32Array& arrayDimensions) const;

    /** Get the AccessLevel for the DataVariable.
     *  @return the AccessLevel for the DataVariable.
     */
    virtual OpcUa_Byte      accessLevel() const {return m_accessLevel;};

    /** Get the UserAccessLevel for the DataVariable.
     *  @return the UserAccessLevel for the DataVariable.
     */
    virtual OpcUa_Byte      userAccessLevel(Session* /*pSession*/) const {return m_userAccessLevel;};

    /** Check whether a minimum sampling interval is supported.
     *  @return TRUE if supported FALSE if not.
     */
    virtual OpcUa_Boolean   isMinimumSamplingIntervalSupported() const {return OpcUa_True;};

    /** Get the minimum sampling interval of the Node.
     *  @return the minimum sampling interval.
     */
    virtual OpcUa_Double    minimumSamplingInterval() const {return m_minimumSamplingInterval;};

    /** Indicates if historizing is available or not.
     *  @return TRUE if historizing is available FALSE if not.
     */
    virtual OpcUa_Boolean   historizing() const {return m_historizing;};

    /** Get the NodeClass of the current Node.
     *  @return the NodeClass of the current Node.
     */
    OpcUa_NodeClass   nodeClass() const { return OpcUa_NodeClass_Variable; };

    /** Get the object type NodeId for the server object.
     *  @return the object type NodeId for the server object.
     */
    UaNodeId          typeDefinitionId() const { return m_typeDefinitionId; };

    /** Get the Node.
     *  @return the current searched Node.
     */
    UaNode*           getUaNode() const {return (UaNode*)this;};

    /** Get a ReferenceList where all the Nodes are in.
     *  @return a ReferenceList where all the Nodes are in.
     */
    UaReferenceLists* getUaReferenceLists() const {return (UaReferenceLists*)this;};

    /** Sets the write mask attribute.
     */
    virtual void setWriteMask(OpcUa_UInt32 writeMask) {m_writeMask = writeMask;}

    virtual UaStatus  setAttributeValue(Session* pSession, OpcUa_Int32 attributeId, const UaDataValue& dataValue, OpcUa_Boolean checkWriteMask);

private:
    UaNodeId        m_nodeId;
    UaQualifiedName m_browseName;
    UaLocalizedText m_displayName;
    UaLocalizedText m_description;
    OpcUa_UInt32    m_writeMask;
    UaNodeId        m_typeDefinitionId;
    UaDataValue     m_dataValue;
    UaNodeId        m_dataTyp;
    OpcUa_Int32     m_valueRank;
    OpcUa_Byte      m_accessLevel;
    OpcUa_Byte      m_userAccessLevel;
    OpcUa_Double    m_minimumSamplingInterval;
    OpcUa_Boolean   m_historizing;
};

/** @brief Derived from UaVariableType and UaReferenceLists.
 */
class SERVER_CORE_EXPORT UaGenericVariableType :
    public UaVariableType,
    public UaReferenceLists
{
protected:
    /** destruction */
    virtual ~UaGenericVariableType();
public:
    /** construction */
    UaGenericVariableType(
        const UaNodeId&        nodeId,
        const UaQualifiedName& browseName,
        const UaLocalizedText& displayName,
        const UaLocalizedText& description,
        const UaVariant&       value,
        const UaNodeId&        dataTyp,
        OpcUa_Int32            valueRank,
        OpcUa_Boolean          isAbstract);

    /** Discover the references of a specified node of a view.
     *  This method is used to return a list of references and target nodes for the passed node to browse for the
     *  services Browse and BrowseNext.
     *  @param serviceContext   General context for the service calls containing information like the session object,
     *                          return diagnostic mask and timeout hint.
     *  @param browseContext    Browse context for the first browse or the following browse with continuation point.
     *  @param References       Array of ReferenceDescription results for the browsed node.
     *  @return                 Error code
     */
    UaStatus browse(
        const ServiceContext&    serviceContext,
        BrowseContext&           browseContext,
        UaReferenceDescriptions& References);

    /** Get the NodeId of the current Node.
     *  @return the NodeId of the current Node.
     */
    virtual UaNodeId        nodeId() const {return m_nodeId;};

    /** Get the browseName as QualifiedName of the current Node.
     *  @return the BrowseName for the DataVariable as QualifiedName.
     */
    virtual UaQualifiedName browseName() const {return m_browseName;};

    /** Get the displayName as LocalizedText of the current Node.
     *  @return the LocalizedText of the current Node.
     */
    virtual UaLocalizedText displayName(Session*) const {return m_displayName;};

    /** Check if Node is DescriptionSupported.
     *  @return FALSE if not supported.
     */
    virtual OpcUa_Boolean   isDescriptionSupported() const {return OpcUa_True;};

    /** Get the description as LocalizedText of the current Node.
     *  @return the LocalizedText of the current Node.
     */
    virtual UaLocalizedText description(Session*) const {return m_description;};

    /** Check if Node is WriteMaskSupported.
     *  @return TRUE if Node is WriteMaskSupported.
     */
    virtual OpcUa_Boolean   isWriteMaskSupported() const {return OpcUa_True;};

    /** Get the writeMask of the current Node.
     *  @return the writeMask.
     */
    virtual OpcUa_UInt32    writeMask() const {return m_writeMask;};

    /** Check if Node is UserWriteMaskSupported.
     *  @return TRUE if Node is UserWriteMaskSupported.
     */
    virtual OpcUa_Boolean   isUserWriteMaskSupported() const {return OpcUa_True;};

    /** Get the WriteMask of the User.
     *  @return the WriteMask of the User.
     */
    virtual OpcUa_UInt32    userWriteMask(Session* /*pSession*/) const {return m_writeMask;};

    /** Check whether the actual Node is Value supported or not.
     *  @return TRUE if supported.
     */
    virtual OpcUa_Boolean   isValueSupported() const {return OpcUa_True;};

    /** Sets the current value for the DataVariable.
     *  @return the current value for the DataVariable.
     */
    virtual UaDataValue     value(Session* /*pSession*/) {return m_value;};

    /** Get the DataType for the DataVariable.
     *  @return the DataType for the DataVariable.
     */
    virtual UaNodeId        dataType() const {return m_dataTyp;};

    /** Get the ValueRank for the DataVariable.
     *  @return the ValueRank for the DataVariable.
     */
    virtual OpcUa_Int32     valueRank() const {return m_valueRank;};

    /** Check if the Node is ArrayDimensionsSupported.
     *  @return FALSE if not supported.
     */
    virtual OpcUa_Boolean   isArrayDimensionsSupported() const {return OpcUa_False;};

    /** Get the arrayDimensions value for the passed UaNode.
     *  @param arrayDimensions the arrayDimensions value for the passed UaNode.
     */
    virtual void            arrayDimensions(UaUInt32Array& arrayDimensions) const {arrayDimensions.clear();};

    /** Check if Node is Abstract.
     *  @return TRUE if is Abstract FALSE if not.
     */
    virtual OpcUa_Boolean   isAbstract() const {return m_isAbstract;};

    /** Get the NodeClass of the current Node.
     *  @return the NodeClass of the current Node.
     */
    OpcUa_NodeClass nodeClass() const { return OpcUa_NodeClass_VariableType; };

    /** Get the object type NodeId for the server object.
     *  @return the object type NodeId for the server object.
     */
    UaNodeId          typeDefinitionId() const { return UaNodeId(); };

    /** Get the Node.
     *  @return the current searched Node.
     */
    UaNode*           getUaNode() const {return (UaNode*)this;};

    /** Get a ReferenceList where all the Nodes are in.
     *  @return a ReferenceList where all the Nodes are in.
     */
    UaReferenceLists* getUaReferenceLists() const {return (UaReferenceLists*)this;};

    /** Sets the write mask attribute.
     */
    virtual void setWriteMask(OpcUa_UInt32 writeMask) {m_writeMask = writeMask;}

    virtual UaStatus  setAttributeValue(Session* pSession, OpcUa_Int32 attributeId, const UaDataValue& dataValue, OpcUa_Boolean checkWriteMask);

private:
    UaNodeId        m_nodeId;
    UaQualifiedName m_browseName;
    UaLocalizedText m_displayName;
    UaLocalizedText m_description;
    OpcUa_UInt32    m_writeMask;
    UaDataValue     m_value;
    UaNodeId        m_dataTyp;
    OpcUa_Int32     m_valueRank;
    OpcUa_Boolean   m_isAbstract;
};

/** @brief Derived from UaDataType and UaReferenceLists.
 */
class SERVER_CORE_EXPORT UaGenericDataType :
    public UaDataType,
    public UaReferenceLists
{
protected:
    /** destruction */
    virtual ~UaGenericDataType();
public:
    /** construction */
    UaGenericDataType(
        const UaNodeId&        nodeId,
        const UaQualifiedName& browseName,
        const UaLocalizedText& displayName,
        const UaLocalizedText& description,
        OpcUa_Boolean          isAbstract);

    /** Discover the references of a specified node of a view.
     *  This method is used to return a list of references and target nodes for the passed node to browse for the
     *  services Browse and BrowseNext.
     *  @param serviceContext   General context for the service calls containing information like the session object,
     *                          return diagnostic mask and timeout hint.
     *  @param browseContext    Browse context for the first browse or the following browse with continuation point.
     *  @param References       Array of ReferenceDescription results for the browsed node.
     *  @return                 Error code
     */
    UaStatus browse(
        const ServiceContext&    serviceContext,
        BrowseContext&           browseContext,
        UaReferenceDescriptions& References);

    /** Get the NodeId of the current Node.
     *  @return the NodeId of the current Node.
     */
    virtual UaNodeId        nodeId() const {return m_nodeId;};

    /** Get the browseName as QualifiedName of the current Node.
     *  @return the BrowseName for the DataVariable as QualifiedName.
     */
    virtual UaQualifiedName browseName() const {return m_browseName;};

    /** Get the displayName as LocalizedText of the current Node.
     *  @return the LocalizedText of the current Node.
     */
    virtual UaLocalizedText displayName(Session*) const {return m_displayName;};

    /** Check if Node is DescriptionSupported.
     *  @return FALSE if not supported.
     */
    virtual OpcUa_Boolean   isDescriptionSupported() const {return OpcUa_True;};

    /** Get the description as LocalizedText of the current Node.
     *  @return the LocalizedText of the current Node.
     */
    virtual UaLocalizedText description(Session*) const {return m_description;};

    /** Check if Node is WriteMaskSupported.
     *  @return TRUE if Node is WriteMaskSupported.
     */
    virtual OpcUa_Boolean   isWriteMaskSupported() const {return OpcUa_True;};

    /** Get the writeMask of the current Node.
     *  @return the writeMask.
     */
    virtual OpcUa_UInt32    writeMask() const {return m_writeMask;};

    /** Check if Node is UserWriteMaskSupported.
     *  @return TRUE if Node is UserWriteMaskSupported.
     */
    virtual OpcUa_Boolean   isUserWriteMaskSupported() const {return OpcUa_True;};

    /** Get the WriteMask of the User.
     *  @return the WriteMask of the User.
     */
    virtual OpcUa_UInt32    userWriteMask(Session* /*pSession*/) const {return m_writeMask;};

    /** Check if Node is Abstract.
     *  @return TRUE if is Abstract FALSE if not.
     */
    virtual OpcUa_Boolean     isAbstract() const {return m_isAbstract;};

    /** Get the NodeClass of the current Node.
     *  @return the NodeClass of the current Node.
     */
    OpcUa_NodeClass   nodeClass() const { return OpcUa_NodeClass_DataType; };

    /** Get the object type NodeId for the server object.
     *  m@return the object type NodeId for the server object.
     */
    UaNodeId          typeDefinitionId() const { return UaNodeId(); };

    /** Get the Node.
     *  @return the current searched Node.
     */
    UaNode*           getUaNode() const {return (UaNode*)this;};

    /** Get a ReferenceList where all the Nodes are in.
     *  @return a ReferenceList where all the Nodes are in.
     */
    UaReferenceLists* getUaReferenceLists() const {return (UaReferenceLists*)this;};

    /** Sets the write mask attribute.
     */
    virtual void setWriteMask(OpcUa_UInt32 writeMask) {m_writeMask = writeMask;}

    virtual UaStatus  setAttributeValue(Session* pSession, OpcUa_Int32 attributeId, const UaDataValue& dataValue, OpcUa_Boolean checkWriteMask);

private:
    UaNodeId        m_nodeId;
    UaQualifiedName m_browseName;
    UaLocalizedText m_displayName;
    UaLocalizedText m_description;
    OpcUa_UInt32    m_writeMask;
    OpcUa_Boolean   m_isAbstract;
};

/** @brief Derived from UaView and UaReferenceLists.
 */
class SERVER_CORE_EXPORT UaGenericView :
    public UaView,
    public UaReferenceLists
{
protected:
    /** destruction */
    virtual ~UaGenericView();
public:
    /** construction */
    UaGenericView(
        const UaNodeId&        nodeId,
        const UaQualifiedName& browseName,
        const UaLocalizedText& displayName,
        const UaLocalizedText& description,
        OpcUa_Boolean          containsNoLoops,
        OpcUa_Byte             eventNotifier);

    /** Discover the references of a specified node of a view.
     *  This method is used to return a list of references and target nodes for the passed node to browse for the
     *  services Browse and BrowseNext.
     *  @param serviceContext   General context for the service calls containing information like the session object,
     *                          return diagnostic mask and timeout hint.
     *  @param browseContext    Browse context for the first browse or the following browse with continuation point.
     *  @param References       Array of ReferenceDescription results for the browsed node.
     *  @return                 Error code
     */
    UaStatus browse(
        const ServiceContext&    serviceContext,
        BrowseContext&           browseContext,
        UaReferenceDescriptions& References);

    /** Get the NodeId of the current Node.
     *  @return the NodeId of the current Node.
     */
    virtual UaNodeId        nodeId() const {return m_nodeId;};

    /** Get the browseName as QualifiedName of the current Node.
     *  @return the BrowseName for the DataVariable as QualifiedName.
     */
    virtual UaQualifiedName browseName() const {return m_browseName;};

    /** Get the displayName as LocalizedText of the current Node.
     *  @return the LocalizedText of the current Node.
     */
    virtual UaLocalizedText displayName(Session*) const {return m_displayName;};

    /** Check if Node is DescriptionSupported.
     *  @return FALSE if not supported.
     */
    virtual OpcUa_Boolean   isDescriptionSupported() const {return OpcUa_True;};

    /** Get the description as LocalizedText of the current Node.
     *  @return the LocalizedText of the current Node.
     */
    virtual UaLocalizedText description(Session*) const {return m_description;};

    /** Check if Node is WriteMaskSupported.
     *  @return TRUE if Node is WriteMaskSupported.
     */
    virtual OpcUa_Boolean   isWriteMaskSupported() const {return OpcUa_True;};

    /** Get the writeMask of the current Node.
     *  @return the writeMask.
     */
    virtual OpcUa_UInt32    writeMask() const {return m_writeMask;};

    /** Check if Node is UserWriteMaskSupported.
     *  @return TRUE if Node is UserWriteMaskSupported.
     */
    virtual OpcUa_Boolean   isUserWriteMaskSupported() const {return OpcUa_True;};

    /** Get the WriteMask of the User.
     *  @return the WriteMask of the User.
     */
    virtual OpcUa_UInt32    userWriteMask(Session* /*pSession*/) const {return m_writeMask;};

    /** Set the Variables loops.
     *  @return TRUE if there are no loops FALSE otherwise.
     */
    virtual OpcUa_Boolean   containsNoLoops() const {return m_containsNoLoops;};

    /** Provides the information if the object can be used to subscribe for events.
     *  @return the EventNotifier attribute value for the View.
     */
    virtual OpcUa_Byte      eventNotifier() const {return m_eventNotifier;};

    /** Get the NodeClass of the current Node.
     *  @return the NodeClass of the current Node.
     */
    OpcUa_NodeClass nodeClass() const { return OpcUa_NodeClass_View; };

    /** Get the object type NodeId for the server object.
     *  @return the object type NodeId for the server object.
     */
    UaNodeId        typeDefinitionId() const { return UaNodeId(); };

    /** Get the Node.
     *  @return the current searched Node.
     */
    UaNode* getUaNode() const {return (UaNode*)this;};

    /** Get a ReferenceList where all the Nodes are in.
     *  @return a ReferenceList where all the Nodes are in.
     */
    UaReferenceLists* getUaReferenceLists() const {return (UaReferenceLists*)this;};

    /** Sets the write mask attribute.
     */
    virtual void setWriteMask(OpcUa_UInt32 writeMask) {m_writeMask = writeMask;}

    virtual UaStatus  setAttributeValue(Session* pSession, OpcUa_Int32 attributeId, const UaDataValue& dataValue, OpcUa_Boolean checkWriteMask);

private:
    UaNodeId        m_nodeId;
    UaQualifiedName m_browseName;
    UaLocalizedText m_displayName;
    UaLocalizedText m_description;
    OpcUa_UInt32    m_writeMask;
    OpcUa_Boolean   m_containsNoLoops;
    OpcUa_Byte      m_eventNotifier;
};

/** @brief Derived from UaMethod and UaReferenceLists.
 */
class SERVER_CORE_EXPORT UaGenericMethod :
    public UaMethod,
    public UaReferenceLists
{
protected:
    /** destruction */
    virtual ~UaGenericMethod();
public:
    /** construction */
    UaGenericMethod(
        const UaNodeId&        nodeId,
        const UaQualifiedName& browseName,
        const UaLocalizedText& displayName,
        const UaLocalizedText& description,
        OpcUa_Boolean          executable,
        OpcUa_Boolean          userExecutable);

    /** Discover the references of a specified node of a view.
     *  This method is used to return a list of references and target nodes for the passed node to browse for the
     *  services Browse and BrowseNext.
     *  @param serviceContext   General context for the service calls containing information like the session object,
     *                          return diagnostic mask and timeout hint.
     *  @param browseContext    Browse context for the first browse or the following browse with continuation point.
     *  @param References       Array of ReferenceDescription results for the browsed node.
     *  @return                 Error code
     */
    UaStatus browse(
        const ServiceContext&    serviceContext,
        BrowseContext&           browseContext,
        UaReferenceDescriptions& References);

    /** Get the NodeId of the current Node.
     *  @return the NodeId of the current Node.
     */
    virtual UaNodeId        nodeId() const {return m_nodeId;};

    /** Get the browseName as QualifiedName of the current Node.
     *  @return the BrowseName for the DataVariable as QualifiedName.
     */
    virtual UaQualifiedName browseName() const {return m_browseName;};

    /** Get the displayName as LocalizedText of the current Node.
     *  @return the LocalizedText of the current Node.
     */
    virtual UaLocalizedText displayName(Session*) const {return m_displayName;};

    /** Check if Node is DescriptionSupported.
     *  @return FALSE if not supported.
     */
    virtual OpcUa_Boolean   isDescriptionSupported() const {return OpcUa_True;};

    /** Get the description as LocalizedText of the current Node.
     *  @return the LocalizedText of the current Node.
     */
    virtual UaLocalizedText description(Session*) const {return m_description;};

    /** Check if Node is WriteMaskSupported.
     *  @return TRUE if Node is WriteMaskSupported.
     */
    virtual OpcUa_Boolean   isWriteMaskSupported() const {return OpcUa_True;};

    /** Get the writeMask of the current Node.
     *  @return the writeMask.
     */
    virtual OpcUa_UInt32    writeMask() const {return m_writeMask;};

    /** Check if Node is UserWriteMaskSupported.
     *  @return TRUE if Node is UserWriteMaskSupported.
     */
    virtual OpcUa_Boolean   isUserWriteMaskSupported() const {return OpcUa_True;};

    /** Get the WriteMask of the User.
     *  @return the WriteMask of the User.
     */
    virtual OpcUa_UInt32    userWriteMask(Session* /*pSession*/) const {return m_writeMask;};

    /** Indicates if Method is executable.
     *  @return TRUE if executable FALSE if not.
     */
    virtual OpcUa_Boolean   executable() const {return m_executable;};

    /** Indicates if method is executable by the user.
     *  @return TRUE if UserExecutable FALSE if not.
     */
    virtual OpcUa_Boolean   userExecutable(Session*) const {return m_userExecutable;};

    /** Get the NodeClass of the current Node.
     *  @return the NodeClass of the current Node.
     */
    OpcUa_NodeClass   nodeClass() const { return OpcUa_NodeClass_Method; };

    /** Get the object type NodeId for the server object.
     *  @return the object type NodeId for the server object.
     */
    UaNodeId          typeDefinitionId() const { return UaNodeId(); };

    /** Get the Node.
     *  @return the current searched Node.
     */
    UaNode*           getUaNode() const {return (UaNode*)this;};

    /** Get a ReferenceList where all the Nodes are in.
     *  @return a ReferenceList where all the Nodes are in.
     */
    UaReferenceLists* getUaReferenceLists() const {return (UaReferenceLists*)this;};

    /** Sets the write mask attribute.
     */
    virtual void setWriteMask(OpcUa_UInt32 writeMask) {m_writeMask = writeMask;}

    virtual UaStatus  setAttributeValue(Session* pSession, OpcUa_Int32 attributeId, const UaDataValue& dataValue, OpcUa_Boolean checkWriteMask);

private:
    UaNodeId        m_nodeId;
    UaQualifiedName m_browseName;
    UaLocalizedText m_displayName;
    UaLocalizedText m_description;
    OpcUa_UInt32    m_writeMask;
    OpcUa_Boolean   m_executable;
    OpcUa_Boolean   m_userExecutable;
};

/** @brief Derived from UaReferenceType and UaReferenceLists.
 */
class SERVER_CORE_EXPORT UaGenericReferenceType :
    public UaReferenceType,
    public UaReferenceLists
{
    UA_DISABLE_COPY(UaGenericReferenceType);
protected:
    /** destruction */
    virtual ~UaGenericReferenceType();
public:
    /** construction */
    UaGenericReferenceType(
        const UaNodeId&        nodeId,
        const UaQualifiedName& browseName,
        const UaLocalizedText& displayName,
        const UaLocalizedText& description,
        OpcUa_Boolean          isAbstract,
        OpcUa_Boolean          symmetric,
        const UaLocalizedText& inverseName,
        UaReferenceType*       pParentRefType);

    /** Discover the references of a specified node of a view.
     *  This method is used to return a list of references and target nodes for the passed node to browse for the
     *  services Browse and BrowseNext.
     *  @param serviceContext   General context for the service calls containing information like the session object,
     *                          return diagnostic mask and timeout hint.
     *  @param browseContext    Browse context for the first browse or the following browse with continuation point.
     *  @param References       Array of ReferenceDescription results for the browsed node.
     *  @return                 Error code
     */
    UaStatus browse(
        const ServiceContext&    serviceContext,
        BrowseContext&           browseContext,
        UaReferenceDescriptions& References);

    /** Get the NodeId of the current Node.
     *  @return the NodeId of the current Node.
     */
    virtual UaNodeId        nodeId() const {return m_nodeId;};

    /** Get the browseName as QualifiedName of the current Node.
     *  @return the BrowseName for the DataVariable as QualifiedName.
     */
    virtual UaQualifiedName browseName() const {return m_browseName;};

    /** Get the displayName as LocalizedText of the current Node.
     *  @return the LocalizedText of the current Node.
     */
    virtual UaLocalizedText displayName(Session*) const {return m_displayName;};

    /** Check if Node is DescriptionSupported.
     *  @return FALSE if not supported.
     */
    virtual OpcUa_Boolean   isDescriptionSupported() const {return OpcUa_True;};

    /** Get the description as LocalizedText of the current Node.
     *  @return the LocalizedText of the current Node.
     */
    virtual UaLocalizedText description(Session*) const {return m_description;};

    /** Check if Node is WriteMaskSupported.
     *  @return TRUE if Node is WriteMaskSupported.
     */
    virtual OpcUa_Boolean   isWriteMaskSupported() const {return OpcUa_True;};

    /** Get the writeMask of the current Node.
     *  @return the writeMask.
     */
    virtual OpcUa_UInt32    writeMask() const {return m_writeMask;};

    /** Check if Node is UserWriteMaskSupported.
     *  @return TRUE if Node is UserWriteMaskSupported.
     */
    virtual OpcUa_Boolean   isUserWriteMaskSupported() const {return OpcUa_True;};

    /** Get the WriteMask of the User.
     *  @return the WriteMask of the User.
     */
    virtual OpcUa_UInt32    userWriteMask(Session* /*pSession*/) const {return m_writeMask;};

    /** Check if Node is Abstract.
     *  @return TRUE if is Abstract FALSE if not.
     */
    virtual OpcUa_Boolean   isAbstract() const {return m_isAbstract;};

    /** Check if Node is symmetric.
     *  @return TRUE if is symmetric FALSE if not.
     */
    virtual OpcUa_Boolean   symmetric() const {return m_symmetric;};

    /** Check if Node is InverseNameSupported.
     *  @return TRUE if is InverseNameSupported FALSE if not.
     */
    virtual OpcUa_Boolean   isInverseNameSupported() const {return OpcUa_True;};

    /** Get the inverseName as LocalizedText of the current Node.
     *  @return the inverseName as LocalizedText.
     */
    virtual UaLocalizedText inverseName(Session*) const {return m_inverseName;};

    /** Get the NodeClass of the current Node.
     *  @return the NodeClass of the current Node.
     */
    OpcUa_NodeClass   nodeClass() const { return OpcUa_NodeClass_ReferenceType; };

    /** Get the object type NodeId for the server object.
     *  @return the object type NodeId for the server object.
     */
    UaNodeId          typeDefinitionId() const { return UaNodeId(); };

    /** Get the Node.
     *  @return the current searched Node.
     */
    UaNode*           getUaNode() const {return (UaNode*)this;};

    /** Get a ReferenceList where all the Nodes are in.
     *  @return a ReferenceList where all the Nodes are in.
     */
    UaReferenceLists* getUaReferenceLists() const {return (UaReferenceLists*)this;};

    /** Check wether the current Node is a Subtype of another.
     *  @param pNodeId NodeId of the requested Node.
     *  @return TRUE if the Node is a Subtype of another FALSE if not.
     */
    virtual OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;

    /** Sets the write mask attribute.
     */
    virtual void setWriteMask(OpcUa_UInt32 writeMask) {m_writeMask = writeMask;}

    virtual UaStatus  setAttributeValue(Session* pSession, OpcUa_Int32 attributeId, const UaDataValue& dataValue, OpcUa_Boolean checkWriteMask);

private:
    UaNodeId         m_nodeId;
    UaQualifiedName  m_browseName;
    UaLocalizedText  m_displayName;
    UaLocalizedText  m_description;
    OpcUa_UInt32     m_writeMask;
    OpcUa_Boolean    m_isAbstract;
    OpcUa_Boolean    m_symmetric;
    UaLocalizedText  m_inverseName;
    UaReferenceType* m_pParentRefType;
};
/*! @} */

#endif // __UAGENERIC_H__
