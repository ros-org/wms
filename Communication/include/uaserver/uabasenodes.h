/******************************************************************************
** uabasenodes.h
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
** Description: OPC UA server core module base node classes.
**
******************************************************************************/
#ifndef __UABASENODES_H__
#define __UABASENODES_H__

#include "opcua_proxystub.h"
#include "hashtable.h"
#include "uanodeid.h"
#include "uabasereferences.h"
#include "uaqualifiedname.h"
#include "ualocalizedtext.h"
#include "uadatavalue.h"
#include "statuscode.h"
#include "continuationpoint.h"
#include "uamutex.h"
#include "opcuatypes.h"
#include "variablehandle.h"
#include "version_coremodule.h"

class SERVER_CORE_EXPORT Session;
class SERVER_CORE_EXPORT UaReferenceLists;
class SERVER_CORE_EXPORT UaMethod;
class SERVER_CORE_EXPORT MethodManager;
class SERVER_CORE_EXPORT NodeManagerConfig;
class UABASE_EXPORT UserDataBase;


/*! \addtogroup ServerCoreAddressModel
*  @{
*/

bool SERVER_CORE_EXPORT checkReferenceTypeMatch(const OpcUa_NodeId* pReferenceTypeId, OpcUa_UInt32 numericNodeId, OpcUa_Boolean bIncludeSubtype);

/** @brief Interface class for OPC UA Nodes created and managed with the SDK.

 The OPC UA Address Space Model defines a Base NodeClass from which all other NodeClasses are derived.
 The derived NodeClasses represent the various components of the OPC UA @ref L2UaAdrSpaceConceptObjectModel.
 The detailed description of the base node class and their attributes can be found in the general description of the @ref L3UaNodeClassBase.<br>
 */
class SERVER_CORE_EXPORT UaNode : public ChainEntry
{
    UA_DISABLE_COPY(UaNode);
protected:
    /** Destruction of the UaNode.
     The object is reference counted and can not be deleted directly.
     The methods addReference and releaseReference are used to manage the reference to this object.
     */
    virtual ~UaNode();
public:
    /** Construction of the UaNode.
     The object is reference counted and can not be deleted directly. The reference counter is set to one after the object is created.
     If the object was successfully added to a NodeManager using the methods NodeManagerConfig::addUaNode or NodeManagerConfig::addNodeAndReference the
     NodeManager will release this reference during shut down. If the object was not added to a NodeManager, it must be deleted using the releaseReference
     method. If the interface pointer is used in other places, the availability of the object must be ensured by incrementing the reference counter with
     addReference when the pointer is stored somewhere and decremented with releaseReference if the interface pointer is not longer needed.
     */
    UaNode();

   /** Get the key of the node used for the hash table.
    *  @return  The key of the current NodeId.
    */
    virtual UaNodeId getKey() const;

   /** Get the UaReferenceLists interface for the node.
    *  The UaReferenceLists interface is used to manage and to access the references from and to this node.
    *  @return UaReferenceLists interface for the node.
    */
    virtual UaReferenceLists* getUaReferenceLists() const {return (UaReferenceLists*)NULL;};

    /** Discover the references of a specified node of a view.
     *  This method is used to return a list of references and target nodes for the passed node to browse for the
     *  services Browse and BrowseNext.
     *  @param serviceContext   General context for the service calls containing information like the session object, return diagnostic mask and timeout hint.
     *  @param browseContext    Browse context for the first browse or the following browse with continuation point.
     *  @param References       Array of ReferenceDescription results for the browsed node.
     *  @return                 Error code
     */
    virtual UaStatus browse(
        const ServiceContext&    serviceContext,
        BrowseContext&           browseContext,
        UaReferenceDescriptions& References)  = 0;

    /** Get NodeId of the type definition node for this node.
     Only Object and Variable nodes have type definition nodes.
     This method provides a shortcut to get the type definition of a node. This information is available
     for a client by following the HasTypeDefinition reference (Browse or TranslateBrowsePathToNodeIds)
     from this node or is returned as part of the browse result for the node.
     The HasTypeDefinition reference is not contained
     in the list of references for the nodes and is handled by the SDK using this method.
     @return The type definition NodeId of the node if the node is a Variable or Object.
     */
    virtual UaNodeId typeDefinitionId() const { return UaNodeId(); }

    /** Get value of the NodeClass attribute of this Node.
     Valid values for the node class enumeration are<br>
     OpcUa_NodeClass_Object<br>
     OpcUa_NodeClass_Variable<br>
     OpcUa_NodeClass_Method<br>
     OpcUa_NodeClass_ObjectType<br>
     OpcUa_NodeClass_VariableType<br>
     OpcUa_NodeClass_ReferenceType<br>
     OpcUa_NodeClass_DataType<br>
     OpcUa_NodeClass_View<br>
     @return The NodeClass of the current Node.
     */
    virtual OpcUa_NodeClass nodeClass() const = 0;

    /** Get value of the NodeId attribute of this Node.
      @return the NodeId of the current Node.
      */
    virtual UaNodeId        nodeId() const = 0;

    /** Get value of the BrowseName attribute of this Node.
      @return The BrowseName of the node as UaQualifiedName.
      */
    virtual UaQualifiedName browseName() const = 0;

    /** Get value of the DisplayName attribute of this Node.
      @param  pSession Interface to the Session context for the method call.
              The session provides the locale id requested by the client
      @return The DisplayName of the node as UaLocalizedText.
      */
    virtual UaLocalizedText displayName(Session* pSession) const = 0;

    /** Flag indicating if the optional attribute Description is supported.
      @return TRUE if available and FALSE if not supported.
      */
    virtual OpcUa_Boolean   isDescriptionSupported() const = 0;

    /** Get value of the Description attribute of this Node.
      @param  pSession Interface to the Session context for the method call.
              The session provides the locale id requested by the client
      @return The Description of the node as UaLocalizedText.
      */
    virtual UaLocalizedText description(Session* pSession) const = 0;

    /** Flag indicating if the optional attribute WriteMask is supported.
     *  @return TRUE if available and FALSE if not supported.
     */
    virtual OpcUa_Boolean   isWriteMaskSupported() const = 0;

    /** Get value of the WriteMask attribute of this Node.
     *  @return The WriteMask of the node.
     */
    virtual OpcUa_UInt32    writeMask() const = 0;

    /** Flag indicating if the optional attribute UserWriteMask is supported.
     *  @return TRUE if available and FALSE if not supported.
     */
    virtual OpcUa_Boolean   isUserWriteMaskSupported() const = 0;

    /** Get value of the UserWriteMask attribute of this Node.
     *  @param  pSession Interface to the Session context for the method call.
     *  @return The UserWriteMask of the node.
     */
    virtual OpcUa_UInt32    userWriteMask(Session* pSession) const = 0;

    /** Get NodeId of the modeling rule for this node.
     Only instance declaration nodes like Objects, Variables or Methods have modeling rules type definition nodes.
     This method provides a shortcut to get the modeling rule of a node. This information is available
     for a client by following the HasModellingRule reference (Browse or TranslateBrowsePathToNodeIds)
     from this node. The HasModellingRule reference is normally not contained in the list of references for the
     nodes and is handled by the SDK using this method. Creating the reference as normal reference instead of using this
     shortcut is also possible.
     The default implementation of this method returns a null NodeId which means there is no modeling rule defined.
     The method must be overwritten in a derived class to return a modeling rule.
     @return The modeling rule NodeId for the node if it is an instance declaration node with a modeling rule defined.
     */
    virtual UaNodeId        modellingRuleId() const;

    // Generic getter and setter for the node attributes used in read and write operations
    virtual UaStatus        setAttributeValue(Session* pSession, OpcUa_Int32 attributeId, const UaDataValue& dataValue, OpcUa_Boolean checkWriteMask);
    virtual void            getAttributeValue(Session* pSession, OpcUa_Int32 attributeId, UaDataValue& uaDataValue);

    // Interface methods with empty implementation for handling of user data
    virtual void            setUserData(UserDataBase* pUserData);
    virtual UserDataBase*   getUserData() const;

    // Get and set NodeAccessInfo
    const NodeAccessInfo* getAccessInfo() const;
    void useAccessInfoFrom(const UaNode* pOther);
    void setAccessInfo(NodeAccessInfo* pAccessInfo);
    void attachAccessInfo(NodeAccessInfo* pAccessInfo);

    virtual OpcUa_Boolean isAttributeReadable(Session* pSession) const;
    virtual OpcUa_Boolean isReadable(Session* pSession) const;
    virtual OpcUa_Boolean isWritable(Session* pSession) const;
    virtual OpcUa_Boolean isBrowseable(Session* pSession) const;
    virtual OpcUa_Boolean isHistoryReadable(Session* pSession) const;
    virtual OpcUa_Boolean isHistoryInsertable(Session* pSession) const;
    virtual OpcUa_Boolean isHistoryModifiable(Session* pSession) const;
    virtual OpcUa_Boolean isHistoryDeletable(Session* pSession) const;
    virtual OpcUa_Boolean isEventReadable(Session* pSession) const;
    virtual OpcUa_Boolean isExecutable(Session* pSession) const;
    virtual OpcUa_Boolean isAttributeWritable(Session* pSession) const;
    virtual OpcUa_Boolean checkSecurityMode(Session* pSession) const;

#if SUPPORT_Class_Statistic
    static int s_baseNodeInstanceCount;
#endif // SUPPORT_Class_Statistic

private:
    NodeAccessInfo* m_pAccessInfo;
};

/** @brief Interface for OPC UA Object nodes created and managed with the SDK.

 The class is derived from the interface UaNode. Classes implementing the interface UaObject must also implement the interface UaNode.
 OPC UA Objects are used to represent systems, system components, real-world objects and software
 objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 can be found in the general description of the @ref L3UaNodeClassObject node class.<br>
 For the use of the toolkit level of the SDK where the nodes are managed by the SDK, all Object nodes
 must implement this interface.
 */
class SERVER_CORE_EXPORT UaObject : public UaNode
{
protected:
    /** Destruction of the UaObject.
     The object is reference counted and can not be deleted directly.
     The methods addReference and releaseReference are used to manage the reference to this object.
     */
    virtual ~UaObject();
public:
    /** Construction of the UaObject.
     The object is reference counted and can not be deleted directly. The reference counter is set to one after the object is created.
     If the object was successfully added to a NodeManager using the methods NodeManagerConfig::addUaNode or NodeManagerConfig::addNodeAndReference the
     NodeManager will release this reference during shut down. If the object was not added to a NodeManager, it must be deleted using the releaseReference
     method. If the interface pointer is used in other places, the availability of the object must be ensured by incrementing the reference counter with
     addReference when the pointer is stored somewhere and decremented with releaseReference if the interface pointer is not longer needed.
     */
    UaObject();

    /** Returns the value of the EventNotifier attribute.

     The EventNotifier Attribute is used to indicate if the Node can be used to subscribe to Events or the read/write historic Events.

     The EventNotifier is an 8-bit unsigned integer used as bit field with the following bit fields:
     <table>
     <tr><th>Define</th><th>Value</th><th>Bit</th><th>Description</th></tr>
     <tr><td>OpcUa_EventNotifiers_None</td><td>0x0</td><td></td><td>The Object does not produce events and has no event history.</td></tr>
     <tr><td>OpcUa_EventNotifiers_SubscribeToEvents</td><td>0x1</td><td>0</td><td>The Object produces event notifications.</td></tr>
     <tr><td></td><td></td><td>1</td><td>Reserved for future use. Must always be zero.</td></tr>
     <tr><td>OpcUa_EventNotifiers_HistoryRead</td><td>0x4</td><td>2</td><td>The Object has an event history which may be read.</td></tr>
     <tr><td>OpcUa_EventNotifiers_HistoryWrite</td><td>0x8</td><td>3</td><td>The Object has an event history which may be updated.</td></tr>
     </table>
     The second two bits also indicate if the history of the Events is available via the OPC UA server.
     @return The value of the EventNotifier attribute.
     */
    virtual OpcUa_Byte  eventNotifier() const = 0;

    /** Get the MethodManager interface for a method of this object.
     @param pMethod The method object the manager is requested for.
     @return The MethodManager interface responsible for the method.
     */
    virtual MethodManager* getMethodManager(UaMethod* pMethod) const;

    /** Get the node class of the Node.
     *  @return The node class Object for the object node.
     */
    OpcUa_NodeClass nodeClass() const { return OpcUa_NodeClass_Object; };

    // Generic getter for the node attributes used in read operations
    virtual void    getAttributeValue(Session* pSession, OpcUa_Int32 attributeId, UaDataValue& uaDataValue);

#if SUPPORT_Class_Statistic
    static int s_instanceCount;
#endif // SUPPORT_Class_Statistic
};

/** @brief Class definition of the UaObjectType. Derived from UaNode
 *  Get all information about the types.
 */
class SERVER_CORE_EXPORT UaObjectType : public UaNode
{
protected:
    /** destruction */
    virtual ~UaObjectType();
public:
    /** construction */
    UaObjectType();

    /** Check if Node is Abstract.
     *  @return TRUE if is Abstract FALSE if not.
     */
    virtual OpcUa_Boolean   isAbstract() const = 0;

    /** Get the NodeClass of the current Node.
     *  @return the NodeClass of the current Node.
     */
    OpcUa_NodeClass nodeClass() const { return OpcUa_NodeClass_ObjectType; };

    // Generic getter for the node attributes used in read operations
    virtual void    getAttributeValue(Session* pSession, OpcUa_Int32 attributeId, UaDataValue& uaDataValue);

#if SUPPORT_Class_Statistic
    static int s_instanceCount;
#endif // SUPPORT_Class_Statistic
};

/** Bit mask for UaVariable::valueHandling. */
const OpcUa_UInt32 UaVariable_Value_None          = 0x0;

/** The variable has a cached value but normal read and data monitoring will not use the value directly. If only this flag is set
 * all read and sampling access uses IOManagerUaNode::readValues that needs to be implemented in the custom NodeManager. All write operations to this variable
 * are using IOManagerUaNode::writeValues. The cache value is not updated by the SDK. The custom code is responsible for updating the cache to allow the SDK
 * to return values that are not older than the MaxAge parameter in the Read.*/
const OpcUa_UInt32 UaVariable_Value_Cache         = 0x1;

/** If this flag is set, the value in the variable node is the data source and all read, data monitoring and write
 * operations are using the value without requiring any custom code. Value changes can be provided with the method UaVariable::setValue().
 * IOManagerUaNode::beforeSetAttributeValue and IOManagerUaNode::afterSetAttributeValue can be used to control writing of attributes or to get
 * informed about a successful write of an attribute. This requires overwriting these functions in the custom NodeManager implementation class. */
const OpcUa_UInt32 UaVariable_Value_CacheIsSource = 0x2;

/** If this flag is set, the custom code is responsible for updating the cache value for variables monitored by
 *  one or more clients and to handle read and write operations. Value changes can be provided with the method UaVariable::setValue().
 *  The custom code gets informed about monitoring changes for items of this type by overwriting IOManagerUaNode::variableCacheMonitoringChanged in
 *  the custom NodeManager implementation. In addition it is required to implement IOManagerUaNode::readValues and IOManagerUaNode::writeValues
 *  for read and write operations. This option allows optimizing cyclic access to devices for data monitoring independent of read operations
 */
const OpcUa_UInt32 UaVariable_Value_CacheIsUpdatedOnRequest = 0x4;

/**
 *  @brief Class definition of the UaVariable. Derived from UaNode
 *  Get all information about UaVariables and their references.
 */
class SERVER_CORE_EXPORT UaVariable : public UaNode
{
protected:
    /** destruction */
    virtual ~UaVariable();
public:
    /** construction */
    UaVariable();

    /** Returns the value of the Variable.
     *  @param pSession Interface to the Session context for the method call
     *  @return The current value for the Variable.
     */
    virtual UaDataValue       value(Session* pSession) = 0;

    /** Sets the value of the Variable.
     *  @param pSession         Interface to the Session context for the method call
     *  @param dataValue        New value for the variable.
     *  @param checkAccessLevel Flag indicating if the access level of the variable should be checked before setting the new value.
     *                          The default value is true but may be changed to false for internal calls where the value should be changed
     *                          even if this is not possible from a UA client.
     *  @return                 Error code
     */
    virtual UaStatus          setValue(Session* pSession, const UaDataValue& dataValue, OpcUa_Boolean checkAccessLevel = OpcUa_True) = 0;

    /** Get the DataType for the Variable.
     *  @return the DataType for the DataVariable.
     */
    virtual UaNodeId          dataType() const = 0;

    /** Get the ValueRank for the Variable.
     *  This Attribute indicates whether the Value Attribute of the VariableType is
     *  an array and how many dimensions the array has.
     *
     *  It may have the following values:
     *  <dl>
     *  <dt>n>1</dt><dd>the Value is an array with the specified number of dimensions.</dd>
     *  <dt>OneDimension (1)</dt><dd>The value is an array with one dimension.</dd>
     *  <dt>OneOrMoreDimensions (0)</dt><dd>The value is an array with one or more dimensions.</dd>
     *  <dt>Scalar (-1)</dt><dd>The value is not an array.</dd>
     *  <dt>Any (-2)</dt><dd>The value can be a scalar or an array with any number of dimensions.</dd>
     *  <dt>ScalarOrOneDimension (-3)</dt><dd>The value can be a scalar or a one dimensional array.</dd>
     *  </dl>
     *  @return the ValueRank for the DataVariable.
     */
    virtual OpcUa_Int32       valueRank() const = 0;

    /** Check if the Node is ArrayDimensionsSupported.
     *  @return FALSE if not supported.
     */
    virtual OpcUa_Boolean     isArrayDimensionsSupported() const = 0;

    /** Get the arrayDimensions value for the passed UaNode.
     *  @param arrayDimensions the arrayDimensions value for the passed UaNode.
     */
    virtual void              arrayDimensions(UaUInt32Array& arrayDimensions) const = 0;

    /** Get the AccessLevel for the Variable Value.
     *
     *  The valid flags are:
     *  <dl>
     *    <dt>OpcUa_AccessLevels_CurrentRead</dt>
     *    <dd>The current value of the Variable may be read</dd>
     *    <dt>OpcUa_AccessLevels_CurrentWrite</dt>
     *    <dd>The current value of the Variable may be written</dd>
     *    <dt>OpcUa_AccessLevels_HistoryRead</dt>
     *    <dd>The history for the Variable may be read</dd>
     *    <dt>OpcUa_AccessLevels_HistoryWrite</dt>
     *    <dd>The history for the Variable may be updated</dd>
     *    <dt>OpcUa_AccessLevels_SemanticChange</dt>
     *    <dd>The variable semantic may change. A change is indicated through SemanticChange flag or event.</dd>
     *    <dt>OpcUa_AccessLevels_StatusWrite</dt>
     *    <dd>The variable value StatusCode is writable</dd>
     *    <dt>OpcUa_AccessLevels_TimestampWrite</dt>
     *    <dd>The variable value SourceTimestamp is writable</dd>
     *  </dl>
     *
     *  @return the AccessLevel for the Variable.
     */
    virtual OpcUa_Byte        accessLevel() const = 0;

    /** Get the UserAccessLevel for the Variable.
     *  @param pSession Interface to the Session context for the method call
     *  @return the UserAccessLevel for the Variable.
     */
    virtual OpcUa_Byte        userAccessLevel(Session* pSession) const = 0;

    /** Check whether a minimum sampling interval is supported.
     *  @return TRUE if supported FALSE if not.
     */
    virtual OpcUa_Boolean     isMinimumSamplingIntervalSupported() const = 0;

    /** Get the minimum sampling interval of the Variable.
     *  @return the minimum sampling interval.
     */
    virtual OpcUa_Double      minimumSamplingInterval() const = 0;

    /** Indicates if variable value is currently historized or not.
     *  @return OpcUa_True if historizing is active OpcUa_False if not.
     */
    virtual OpcUa_Boolean     historizing() const = 0;

    /** Get the mode for the handling of the value attribute.

     The value is a bit mask with the following values:

     <dl>
     <dt>UaVariable_Value_None = 0x0</dt>
     <dd>There is no value stored in the variable. The access to the value
     attribute must be implemented by the user of the SDK</dd>
     <dt>UaVariable_Value_Cache = 0x1</dt>
     <dd>The variable has a cached value but normal read and data monitoring
     will not use the value directly. If only this flag is set, all read and
     sampling access uses IOManagerUaNode::readValues that needs to be
     implemented in the custom NodeManager. All write operations to this
     variable are using IOManagerUaNode::writeValues. The cache value is not
     updated by the SDK. The custom code is responsible for updating the cache
     to allow the SDK to return values that are not older than the MaxAge
     parameter in the Read.</dd>
     <dt>UaVariable_Value_CacheIsSource = 0x2</dt>
     <dd>If this flag is set, the value in the variable node is the data
     source and all read, data monitoring and write operations are using the
     value without requiring any custom code. Value changes can be provided
     with the method
     UaVariable::setValue(). IOManagerUaNode::beforeSetAttributeValue and
     IOManagerUaNode::afterSetAttributeValue can be used to control writing of
     attributes or to get informed about a successful write of an
     attribute. This requires overwriting these functions in the custom
     NodeManager implementation class.</dd>
     <dt>UaVariable_Value_CacheIsUpdatedOnRequest = 0x4</dt>
     <dd>If this flag is set, the custom code is responsible for updating the
     cache value for variables monitored by one or more clients and to handle
     read and write operations. Value changes can be provided with the method
     UaVariable::setValue(). The custom code gets informed about monitoring
     changes for items of this type by overwriting
     IOManagerUaNode::variableCacheMonitoringChanged in the custom NodeManager
     implementation.  In addition it is required to implement
     IOManagerUaNode::readValues and IOManagerUaNode::writeValues for read and
     write operations.  This option allows optimizing cyclic access to devices
     for data monitoring independent of read operations.</dd>
     </dl>
     @return The mode for the handling of the Value attribute.
     */
    virtual OpcUa_UInt32      valueHandling() const { return UaVariable_Value_None; };
    virtual void              setValueHandling(OpcUa_UInt32 valueHandling);

    /** Return the VariableHandle for the Value Attribute of the UaVariable.
     *  Needs to be implemented by the derived class if the creation of the VariableHandle should be optimize
     *  by keeping a created variable handle in memory.
     *  @return the VariableHandle for the Value Attribute of the UaVariable.
     */
    virtual VariableHandle*   pVariableHandle() { return NULL; };

    /** Get the NodeClass of the current Node.
     *  @return the NodeClass of the current Node.
     */
    OpcUa_NodeClass nodeClass() const { return OpcUa_NodeClass_Variable; };

    // Generic getter and setter for the node attributes used in read and write operations
    virtual UaStatus setAttributeValue(Session* pSession, OpcUa_Int32 attributeId, const UaDataValue& dataValue, OpcUa_Boolean checkWriteMask);
    virtual void     getAttributeValue(Session* pSession, OpcUa_Int32 attributeId, UaDataValue& uaDataValue);

#if SUPPORT_Class_Statistic
    static int s_instanceCount;
#endif // SUPPORT_Class_Statistic
};

/** @brief Class definition of the UaVariableType. Derived from UaNode
 *  Get all information about the variable types.
 */
class SERVER_CORE_EXPORT UaVariableType : public UaNode
{
protected:
    /** destruction */
    virtual ~UaVariableType();
public:
    /** construction */
    UaVariableType();

    /** Check whether the actual Node is Value supported or not.
     *  @return TRUE if supported.
     */
    virtual OpcUa_Boolean     isValueSupported() const = 0;

    /** Sets the current value for the DataVariable.
     *  @param pSession Interface to the Session context for the method call
     *  @return the current value for the DataVariable.
     */
    virtual UaDataValue       value(Session* pSession) = 0;

    /** Get the DataType for the DataVariable.
     *  @return the DataType for the DataVariable.
     */
    virtual UaNodeId          dataType() const = 0;

    /** Get the ValueRank for the DataVariable.
     *  @return the ValueRank for the DataVariable.
     */
    virtual OpcUa_Int32       valueRank() const = 0;

    /** Check if the Node is ArrayDimensionsSupported.
     *  @return FALSE if not supported.
     */
    virtual OpcUa_Boolean     isArrayDimensionsSupported() const = 0;

    /** Get the arrayDimensions value for the passed UaNode.
     *  @param arrayDimensions the arrayDimensions value for the passed UaNode.
     */
    virtual void              arrayDimensions(UaUInt32Array& arrayDimensions) const = 0;

    /** Check if Node is Abstract.
     *  @return TRUE if is Abstract FALSE if not.
     */
    virtual OpcUa_Boolean     isAbstract() const = 0;

    /** Get the NodeClass of the current Node.
     *  @return the NodeClass of the current Node.
     */
    OpcUa_NodeClass nodeClass() const { return OpcUa_NodeClass_VariableType; };

    // Generic getter for the node attributes used in read operations
    virtual void    getAttributeValue(Session* pSession, OpcUa_Int32 attributeId, UaDataValue& uaDataValue);

#if SUPPORT_Class_Statistic
    static int s_instanceCount;
#endif // SUPPORT_Class_Statistic
};

/** @brief Class definition of the UaDataType. Derived from UaNode
 *  Get all information about UaDataType and their references.
 */
class SERVER_CORE_EXPORT UaDataType : public UaNode
{
protected:
    /** destruction */
    virtual ~UaDataType();
public:
    /** construction */
    UaDataType();

    /** Check if Node is Abstract.
     *  @return TRUE if is Abstract FALSE if not.
     */
    virtual OpcUa_Boolean   isAbstract() const = 0;

    /** Get the NodeClass of the current Node.
     *  @return the NodeClass of the current Node.
     */
    OpcUa_NodeClass nodeClass() const { return OpcUa_NodeClass_DataType; };

    // Generic getter for the node attributes used in read operations
    virtual void    getAttributeValue(Session* pSession, OpcUa_Int32 attributeId, UaDataValue& uaDataValue);

#if SUPPORT_Class_Statistic
    static int s_instanceCount;
#endif // SUPPORT_Class_Statistic
};

/** @brief Interface representing a OPC UA View node. Derived from UaNode.
 */
class SERVER_CORE_EXPORT UaView : public UaNode
{
protected:
    /** destruction */
    virtual ~UaView();
public:
    /** construction */
    UaView();

    /** Set the Variables loops.
     *  @return TRUE if there are no loops FALSE otherwise.
     */
    virtual OpcUa_Boolean   containsNoLoops() const = 0;

    /** Provides the information if the object can be used to subscribe for events.
     *  @return the EventNotifier attribute value for the View.
     */
    virtual OpcUa_Byte      eventNotifier() const = 0;

    /** Get the NodeClass of the current Node.
     *  @return the NodeClass of the current Node.
     */
    OpcUa_NodeClass nodeClass() const { return OpcUa_NodeClass_View; };

    // Generic getter for the node attributes used in read operations
    virtual void    getAttributeValue(Session* pSession, OpcUa_Int32 attributeId, UaDataValue& uaDataValue);

#if SUPPORT_Class_Statistic
    static int s_instanceCount;
#endif // SUPPORT_Class_Statistic
};

/** @brief Class definition of the UaMethod. Derived from UaNode
 *  Get all information about the methods.
 */
class SERVER_CORE_EXPORT UaMethod : public UaNode
{
protected:
    /** destruction */
    virtual ~UaMethod();
public:
    /** construction */
    UaMethod();

    /** Indicates if Method is executable.
     *  @return TRUE if executable FALSE if not.
     */
    virtual OpcUa_Boolean   executable() const = 0;

    /** Indicates if method is executable by the user.
     *  @param pSession Interface to the Session context for the method call
     *  @return TRUE if UserExecutable FALSE if not.
     */
    virtual OpcUa_Boolean   userExecutable(Session* pSession) const = 0;

    /** Get the NodeClass of the current Node.
     *  @return The node class Method.
     */
    OpcUa_NodeClass nodeClass() const { return OpcUa_NodeClass_Method; };

    // Generic getter for the node attributes used in read operations
    virtual void    getAttributeValue(Session* pSession, OpcUa_Int32 attributeId, UaDataValue& uaDataValue);

#if SUPPORT_Class_Statistic
    static int s_instanceCount;
#endif // SUPPORT_Class_Statistic
};

/** @brief Class definition of the UaReferenceType. Derived from UaNode
 *  Get all information about the reference types.
 */
class SERVER_CORE_EXPORT UaReferenceType : public UaNode
{
protected:
    /** destruction */
    virtual ~UaReferenceType();
public:
    /** construction */
    UaReferenceType();

    /** Check if Node is Abstract.
     *  @return TRUE if is Abstract FALSE if not.
     */
    virtual OpcUa_Boolean   isAbstract() const = 0;

    /** Check if Node is symmetric.
     *  @return TRUE if is symmetric FALSE if not.
     */
    virtual OpcUa_Boolean   symmetric() const = 0;

    /** Check if Node is InverseNameSupported.
     *  @return TRUE if is InverseNameSupported FALSE if not.
     */
    virtual OpcUa_Boolean   isInverseNameSupported() const = 0;

    /** Get the inverseName as LocalizedText of the current Node.
      @param  pSession Interface to the Session context for the method call.
              The session provides the locale id requested by the client
      @return the inverseName as LocalizedText.
      */
    virtual UaLocalizedText inverseName(Session* pSession) const = 0;

    /** Get the NodeClass of the current Node.
     *  @return the NodeClass of the current Node.
     */
    OpcUa_NodeClass nodeClass() const { return OpcUa_NodeClass_ReferenceType; };

    /** Check whether the current Node is a Subtype of another.
     *  @param pNodeId NodeId of the requested Node.
     *  @return TRUE if the Node is a Subtype of another FALSE if not.
     */
    virtual OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const = 0;

    // Generic getter for the node attributes used in read operations
    virtual void    getAttributeValue(Session* pSession, OpcUa_Int32 attributeId, UaDataValue& uaDataValue);

#if SUPPORT_Class_Statistic
    static int s_instanceCount;
#endif // SUPPORT_Class_Statistic
};

/** Class implementing the reference handling for UaNodes
 *
 * Concrete implementation of one of the UaNode interfaces like UaObject or UaVariable can derive from this class
 * to get the default reference handling for UaNodes. This includes adding and removing references, browsing and the
 * implementation of translateBrowsePathToNodeIds.
 *
 * The class is not thread safe. It is strongly recommended to lock the protected member m_mutexNodes of NodeManagerUaNode
 * if the methods of this class are used directly in the NodeManager. The methods browseReferences and translateBrowsePathToNodeId
 * are using a mutex that is passed in to the serviceContext parameter. This is automatically used by the SDK when using one of
 * the two methods.
 */
class SERVER_CORE_EXPORT UaReferenceLists
{
    UA_DISABLE_COPY(UaReferenceLists);
public:
    UaReferenceLists();
    virtual ~UaReferenceLists();

    virtual UaStatus browseReferences(const ServiceContext& serviceContext, BrowseContext& browseContext, UaReferenceDescriptions& References);
    virtual UaStatus translateBrowsePathToNodeId(const ServiceContext& serviceContext,const UaNodeId& startingNode, UaRelativePath& relativePath, UaBrowsePathTargets&  browsePathTargets);

    virtual const UaReference* pTargetNodes() const;
    virtual const UaReference* pSourceNodes() const;

    virtual UaNode* getTargetNodeByBrowseName(const UaQualifiedName& browseName) const;
    virtual void addTargetNode(UaReference *pReference);
    virtual void addSourceNode(UaReference *pReference);
    virtual UaStatus removeSourceNode(UaReference *pReferenceToRemove);
    virtual bool     removeSourceReference(UaReference *pReferenceToRemove);
    virtual UaStatus removeTargetNode(UaNode* pTargetNode, const UaNodeId& referenceTypeId, OpcUa_Boolean deleteBidirectional);
    virtual UaStatus removeTargetNode(const UaNodeId& targetNodeId, const UaNodeId& referenceTypeId, OpcUa_Boolean deleteBidirectional);
    virtual bool     removeTargetReference(UaReference *pReferenceToRemove);
    virtual UaStatus removeCrossNodeManagerRef(NodeManager* pNodeManager);
    virtual UaStatus invalidateSourceReferences(OpcUa_Boolean deleteSourceReferences);
    virtual UaStatus invalidateTargetReferences(OpcUa_Boolean deleteTargetReferences);
    virtual UaStatus deleteAllChildren(NodeManagerConfig* pNodeManagerConfig);

    /** Get the UaNode interface pointer of this node. */
    virtual UaNode* getUaNode() const = 0;

protected:
    /** List of references to target nodes where this node is the source node. */
    UaReference* m_pTargetNodes;
    /** Last references in the list of references to the target nodes. */
    UaReference* m_pLastTargetNode;
    /** List of references to source nodes where this node is the target node. */
    UaReference* m_pSourceNodes;
};
/*! @} */

#endif // __UABASENODES_H__
