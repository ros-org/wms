/******************************************************************************
** uaobjecttypes.h
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
** Description: OPC UA server object type classes.
**
******************************************************************************/
#ifndef __UAOBJECTTYPES_H__
#define __UAOBJECTTYPES_H__

#include "uabasenodes.h"
#include "uamutex.h"
#include <list>

/*! \addtogroup ServerCoreAddressModel
*  @{
*/

/** @brief Derived from UaObjectType and UaReferenceLists.
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaObjectTypeSimple : public UaObjectType, public UaReferenceLists
{
    UaObjectTypeSimple(){};
protected:
    /** destruction */
    virtual ~UaObjectTypeSimple();
public:
    /** construction */
    UaObjectTypeSimple(
        const UaString& name,
        const UaNodeId& nodeId,
        const UaString& defaultLocaleId,
        OpcUa_Boolean   isAbstract);

    /** Get a ReferenceList where all the Nodes are in.
     *  @return a ReferenceList where all the Nodes are in.
     */
    UaReferenceLists* getUaReferenceLists() const {return (UaReferenceLists*)this;};

    /** Discover the references of a specified node of a view.
     *  This method is used to return a list of references and target nodes for the passed node to browse for the
     *  services Browse and BrowseNext.
     *  @param serviceContext   General context for the service calls containing information like the session object,
     *                          return diagnostic mask and timeout hint.
     *  @param browseContext    Browse context for the first browse or the following browse with continuation point.
     *  @param References       Array of ReferenceDescription results for the browsed node.
     *  @return                 Error code
     */
    virtual UaStatus browse(
        const ServiceContext&    serviceContext,
        BrowseContext&           browseContext,
        UaReferenceDescriptions& References);

    /** Get the NodeId of the current Node.
     *  @return the NodeId of the current Node.
     */
    UaNodeId                nodeId() const;

    /** Get the browseName as QualifiedName of the current Node.
     *  @return the browseName as QualifiedName.
     */
    virtual UaQualifiedName browseName() const;

    /** Get the displayName as LocalizedText of the current Node.
     *  @param pSession Interface to the Session context for the method call
     *  @return the LocalizedText of the current Node.
     */
    virtual UaLocalizedText displayName(Session* pSession) const;

    /** Check if Node is DescriptionSupported.
     *  @return FALSE if not supported.
     */
    virtual OpcUa_Boolean   isDescriptionSupported() const;

    /** Get the description as LocalizedText of the current Node.
     *  @param pSession Interface to the Session context for the method call
     *  @return the LocalizedText of the current Node.
     */
    virtual UaLocalizedText description(Session* pSession) const;

    /** Check if Node is WriteMaskSupported.
     *  @return TRUE if Node is WriteMaskSupported.
     */
    virtual OpcUa_Boolean   isWriteMaskSupported() const;

    /** Get the writeMask of the current Node.
     *  @return the writeMask.
     */
    virtual OpcUa_UInt32    writeMask() const;

    /** Check if Node is UserWriteMaskSupported.
     *  @return TRUE if Node is UserWriteMaskSupported.
     */
    virtual OpcUa_Boolean   isUserWriteMaskSupported() const;

    /** Check if Node has a userWriteMask.
     *  @param pSession Interface to the Session context for the method call
     *  @return the userWriteMask.
     */
    virtual OpcUa_UInt32    userWriteMask(Session* pSession) const;

    /** Check if Node is Abstract.
     *  @return TRUE if is Abstract FALSE if not.
     */
    OpcUa_Boolean           isAbstract() const;

    /** Get the Node.
     *  @return the current searched Node.
     */
    UaNode* getUaNode() const {return (UaNode*)this;};

private:
    /** NodeId of the object type. */
    UaNodeId           m_nodeId;
    /** Name of the object type used in BrowseName and DisplayName. */
    UaString           m_name;
    /** Default localeId for the object type. */
    UaString           m_defaultLocaleId;
    /** IsAbstract flag for the object type. */
    OpcUa_Boolean      m_isAbstract;
};

class SERVER_CORE_EXPORT NodeManagerConfig;

/** @brief Provides a base class to implement an Object
 *  The object is able to register it's own components at his node manager
 *  Derived from UaObject and UaReferenceLists
 *  It is not possible to create shallow copies of this Class.
 */
class SERVER_CORE_EXPORT UaObjectBase : public UaObject, public UaReferenceLists
{
    UA_DISABLE_COPY(UaObjectBase);
protected:
    /** destruction */
    virtual ~UaObjectBase();
public:
    /** construction */
    UaObjectBase(const UaString& name, const UaNodeId& newNodeId, const UaString& defaultLocaleId);

    /** Get a ReferenceList where all the Nodes are in.
     *  @return a ReferenceList where all the Nodes are in.
     */
    UaReferenceLists* getUaReferenceLists() const {return (UaReferenceLists*)this;};

    //- Interface UaObject ----------------------------------------------------------------
    virtual UaStatus browse( const ServiceContext& serviceContext, BrowseContext& browseContext, UaReferenceDescriptions& References);
    UaNodeId                nodeId() const;
    virtual UaQualifiedName browseName() const;
    virtual UaLocalizedText displayName(Session* pSession) const;
    virtual OpcUa_Boolean   isDescriptionSupported() const;
    virtual UaLocalizedText description(Session* pSession) const;
    virtual OpcUa_Boolean   isWriteMaskSupported() const;
    virtual OpcUa_UInt32    writeMask() const;
    virtual OpcUa_Boolean   isUserWriteMaskSupported() const;
    virtual OpcUa_UInt32    userWriteMask(Session* pSession) const;
    UaNode* getUaNode() const {return (UaNode*)this;};
    //- Interface UaObject ----------------------------------------------------------------

protected:
    /** Default localeId for the object.
     *  MemberVar.
     */
    UaString           m_defaultLocaleId;

private:
    /** NodeId of the external module. */
    UaNodeId           m_nodeId;
    /** Name of the external module used in BrowseName and DisplayName. */
    UaString           m_name;
};

/**  @brief Derived from UaVariableType and UaReferenceLists.
 */
class SERVER_CORE_EXPORT UaVariableTypeSimple : public UaVariableType, public UaReferenceLists
{
protected:
    /** destruction */
    virtual ~UaVariableTypeSimple();
public:
    /** construction */
    UaVariableTypeSimple(
        const UaString& name,
        const UaNodeId& nodeId,
        const UaString& defaultLocaleId,
        OpcUa_Boolean   isAbstract);

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
     *  @return the browseName as QualifiedName.
     */
    virtual UaQualifiedName browseName() const {return UaQualifiedName(m_name, m_nodeId.namespaceIndex());};

    /** Get the displayName as LocalizedText of the current Node.
     *  @return the LocalizedText of the current Node.
     */
    virtual UaLocalizedText displayName(Session*) const {return UaLocalizedText(m_defaultLocaleId, m_name);};

    /** Check if Node is DescriptionSupported.
     *  @return FALSE if not supported.
     */
    virtual OpcUa_Boolean   isDescriptionSupported() const {return OpcUa_False;};

    /** Get the description as LocalizedText of the current Node.
     *  @return the LocalizedText of the current Node.
     */
    virtual UaLocalizedText description(Session*) const {return UaLocalizedText();};

    /** Check if Node is WriteMaskSupported.
     *  @return TRUE if Node is WriteMaskSupported.
     */
    virtual OpcUa_Boolean   isWriteMaskSupported() const;

    /** Get the writeMask of the current Node.
     *  @return the writeMask.
     */
    virtual OpcUa_UInt32    writeMask() const;

    /** Check if Node is UserWriteMaskSupported.
     *  @return TRUE if Node is UserWriteMaskSupported.
     */
    virtual OpcUa_Boolean   isUserWriteMaskSupported() const;

    /** Check if Node has a userWriteMask.
     *  @param pSession Interface to the Session context for the method call
     *  @return the userWriteMask.
     */
    virtual OpcUa_UInt32    userWriteMask(Session* pSession) const;

    /** Check if the Value of the Node is supported.
     *  @return FALSE if not supported.
     */
    virtual OpcUa_Boolean   isValueSupported() const {return OpcUa_False;};

    /** Sets the current value for the DataVariable.
     *  @return the current value for the DataVariable.
     */
    virtual UaDataValue     value(Session* /*pSession*/) {return UaDataValue();};

    /** Get the DataType for the DataVariable.
     *  @return the DataType for the DataVariable.
     */
    virtual UaNodeId        dataType() const {return UaNodeId(OpcUaId_BaseDataType);};

    /** Get the ValueRank for the DataVariable.
     *  @return the ValueRank for the DataVariable.
     */
    virtual OpcUa_Int32     valueRank() const {return -2;}; // ScalarOrUnknownSize

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

    /** Get the node class of the current Node.
     *  @return the node class of the current Node.
     */
    OpcUa_NodeClass   nodeClass() const { return OpcUa_NodeClass_VariableType; };

    /** Get the typeDefinitionId of the current Node.
     *  @return the typeDefinitionId of the current Node.
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

private:
    /** NodeId of the variable type. */
    UaNodeId           m_nodeId;
    /** Name of the variable type used in BrowseName and DisplayName. */
    UaString           m_name;
    /** Default localeId for the variable type. */
    UaString           m_defaultLocaleId;
    /** IsAbstract flag for the variable type. */
    OpcUa_Boolean      m_isAbstract;
};

/** @brief Derived from UaVariable and UaReferenceLists.
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaDataVariableDevice : public UaVariable, public UaReferenceLists
{
    UaDataVariableDevice(){};
protected:
    /** destruction */
    virtual ~UaDataVariableDevice();
public:
    /** construction */
    UaDataVariableDevice(
        const UaString& name,
        const UaNodeId& nodeId,
        const UaNodeId& dataType,
        OpcUa_Int32     valueRank,
        OpcUa_Byte      accessLevel,
        const UaString& defaultLocaleId);

    /** Get a ReferenceList where all the Nodes are in.
     *  @return a ReferenceList where all the Nodes are in.
     */
    UaReferenceLists* getUaReferenceLists() const {return (UaReferenceLists*)this;};

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

    /** Get the object type NodeId for the server object.
     *  @return the object type NodeId for the server object.
     */
    virtual UaNodeId        typeDefinitionId() const;

     /** Get the NodeId of the current Node.
      *  @return the NodeId of the current Node.
      */
    UaNodeId                nodeId() const;

    /** Get the browseName as QualifiedName of the current Node.
     *  @return the browseName as QualifiedName.
     */
    virtual UaQualifiedName browseName() const;

    /** Get the displayName as LocalizedText of the current Node.
     *  @param pSession Interface to the Session context for the method call
     *  @return the LocalizedText of the current Node.
     */
    virtual UaLocalizedText displayName(Session* pSession) const;

    /** Check if Node is DescriptionSupported.
     *  @return FALSE if not supported.
     */
    virtual OpcUa_Boolean   isDescriptionSupported() const;

    /** Get the description as LocalizedText of the current Node.
     *  @param pSession Interface to the Session context for the method call
     *  @return the LocalizedText of the current Node.
     */
    virtual UaLocalizedText description(Session* pSession) const;

    /** Check if Node is WriteMaskSupported.
     *  @return TRUE if Node is WriteMaskSupported.
     */
    virtual OpcUa_Boolean   isWriteMaskSupported() const;

    /** Get the writeMask of the current Node.
     *  @return the writeMask.
     */
    virtual OpcUa_UInt32    writeMask() const;

    /** Check if Node is UserWriteMaskSupported.
     *  @return TRUE if Node is UserWriteMaskSupported.
     */
    virtual OpcUa_Boolean   isUserWriteMaskSupported() const;

    /** Check if Node has a userWriteMask.
     *  @param pSession Interface to the Session context for the method call
     *  @return the userWriteMask.
     */
    virtual OpcUa_UInt32    userWriteMask(Session* pSession) const;

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
    virtual UaStatus        setValue(Session* pSession, const UaDataValue& dataValue, OpcUa_Boolean checkAccessLevel);

    /** Get the DataType for the DataVariable.
     *  @return the DataType for the DataVariable.
     */
    virtual UaNodeId        dataType() const;

    /** Get the ValueRank for the DataVariable.
     *  @return the ValueRank for the DataVariable.
     */
    virtual OpcUa_Int32     valueRank() const;

    /** Check if the Node is ArrayDimensionsSupported.
     *  @return FALSE if not supported.
     */
    virtual OpcUa_Boolean   isArrayDimensionsSupported() const;

    /** Get the arrayDimensions value for the passed UaNode.
     *  @param arrayDimensions the arrayDimensions value for the passed UaNode.
     */
    virtual void            arrayDimensions(UaUInt32Array& arrayDimensions) const;

    /** Get the AccessLevel for the DataVariable.
     *  @return the AccessLevel for the DataVariable.
     */
    virtual OpcUa_Byte      accessLevel() const;

    /** Get the UserAccessLevel for the DataVariable.
     *  @param pSession Interface to the Session context for the method call
     *  @return the UserAccessLevel for the DataVariable.
     */
    virtual OpcUa_Byte      userAccessLevel(Session* pSession) const;

    /** Check whether a minimum sampling interval is supported.
     *  @return TRUE if supported FALSE if not.
     */
    virtual OpcUa_Boolean   isMinimumSamplingIntervalSupported() const;

    /** Get the minimum sampling interval of the Node.
     *  @return the minimum sampling interval.
     */
    virtual OpcUa_Double    minimumSamplingInterval() const;

    /** Indicates if historizing is available or not.
     *  @return TRUE if historizing is available FALSE if not.
     */
    virtual OpcUa_Boolean   historizing() const;

    /** Get the handling of a Value (UaVariable_Value_Cache or UaVariable_Value_CacheIsSource).
     *  @return the handling of a Value.
     */
    virtual OpcUa_UInt32    valueHandling() const { return UaVariable_Value_Cache; };

    /** Get the Node.
     *  @return the current searched Node.
     */
    UaNode* getUaNode() const {return (UaNode*)this;};

private:
    /** NodeId of the DataVariable. */
    UaNodeId           m_nodeId;
    /** Name of the DataVariable used in BrowseName and DisplayName. */
    UaString           m_name;
    /** Default localeId for the DataVariable. */
    UaString           m_defaultLocaleId;

    /** Cached value of the DataVariable. */
    UaDataValue        m_dataValue;
    /** Simple data type of the value. */
    UaNodeId           m_dataType;
    /** Array rank of the value. */
    OpcUa_Int32        m_valueRank;
    /** Access level of the DataVariable. */
    OpcUa_Byte         m_accessLevel;
};

/** @brief Derived from UaView and UaReferenceLists.
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaViewSimple : public UaView, public UaReferenceLists
{
    UaViewSimple(){};
protected:
    /** destruction */
    virtual ~UaViewSimple();
public:
    /** construction */
    UaViewSimple(
        const UaString& name,
        const UaNodeId& nodeId,
        const UaString& defaultLocaleId,
        OpcUa_Boolean   containsNoLoops,
        OpcUa_Byte      eventNotifier);

    /** Get a ReferenceList where all the Nodes are in.
     *  @return a ReferenceList where all the Nodes are in.
     */
    UaReferenceLists* getUaReferenceLists() const {return (UaReferenceLists*)this;};

    /** Discover the references of a specified node of a view.
     *  This method is used to return a list of references and target nodes for the passed node to browse for the
     *  services Browse and BrowseNext.
     *  @param serviceContext   General context for the service calls containing information like the session object,
     *                          return diagnostic mask and timeout hint.
     *  @param browseContext    Browse context for the first browse or the following browse with continuation point.
     *  @param References       Array of ReferenceDescription results for the browsed node.
     *  @return                 Error code
     */
    virtual UaStatus browse(
        const ServiceContext&    serviceContext,
        BrowseContext&           browseContext,
        UaReferenceDescriptions& References);

     /** Get the NodeId of the current Node.
      *  @return the NodeId of the current Node.
      */
    UaNodeId                nodeId() const;

    /** Get the browseName as QualifiedName of the current Node.
     *  @return the browseName as QualifiedName.
     */
    virtual UaQualifiedName browseName() const;

    /** Get the displayName as LocalizedText of the current Node.
     *  @param pSession Interface to the Session context for the method call
     *  @return the LocalizedText of the current Node.
     */
    virtual UaLocalizedText displayName(Session* pSession) const;

    /** Check if Node is DescriptionSupported.
     *  @return FALSE if not supported.
     */
    virtual OpcUa_Boolean   isDescriptionSupported() const;

    /** Get the description as LocalizedText of the current Node.
     *  @param pSession Interface to the Session context for the method call
     *  @return the LocalizedText of the current Node.
     */
    virtual UaLocalizedText description(Session* pSession) const;

    /** Check if Node is WriteMaskSupported.
     *  @return TRUE if Node is WriteMaskSupported.
     */
    virtual OpcUa_Boolean   isWriteMaskSupported() const;

    /** Get the writeMask of the current Node.
     *  @return the writeMask.
     */
    virtual OpcUa_UInt32    writeMask() const;

    /** Check if Node is UserWriteMaskSupported.
     *  @return TRUE if Node is UserWriteMaskSupported.
     */
    virtual OpcUa_Boolean   isUserWriteMaskSupported() const;

    /** Check if Node has a userWriteMask.
     *  @param pSession Interface to the Session context for the method call
     *  @return the userWriteMask.
     */
    virtual OpcUa_UInt32    userWriteMask(Session* pSession) const;

    /** Set the Variables loops.
     *  @return TRUE if there are no loops FALSE otherwise.
     */
    virtual OpcUa_Boolean   containsNoLoops() const;

    /** Provides the information if the object can be used to subscribe for events.
     *  @return the EventNotifier attribute value for the View.
     */
    virtual OpcUa_Byte      eventNotifier() const;

    /** Get the Node.
     *  @return the current searched Node.
     */
    UaNode* getUaNode() const {return (UaNode*)this;};

private:
    /** NodeId of the object type. */
    UaNodeId           m_nodeId;
    /** Name of the view used in BrowseName and DisplayName. */
    UaString           m_name;
    /** Default localeId for the view. */
    UaString           m_defaultLocaleId;
    /** ContainsNoLoops flag for the view. */
    OpcUa_Boolean      m_containsNoLoops;
    /** Event notifier member or the view. */
    OpcUa_Byte         m_eventNotifier;
};
/*! @} */

#endif // __UAOBJECTTYPES_H__

