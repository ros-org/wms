/******************************************************************************
** uadatavariablecache.h
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
** Description: OPC UA server DataVariable class based on a cached value..
**
******************************************************************************/
#ifndef __UADATAVARIABLECACHE_H__
#define __UADATAVARIABLECACHE_H__

#include "uabasenodes.h"
#include "uamutex.h"
#include "samplingengine.h"
#include "variablehandle.h"
#include "uanumericrange.h"
#include <list>

/** Interface class for the connection between variables and the data sampling.
 *
 * This class defines the abstract interface for the connection between a variable and the sampling item
 * in an IOManager implementation. It is used to signal changes of the variable value and to indicate that
 * the variable is not longer valid.
 */
class SERVER_CORE_EXPORT CacheSignal
{
public:
    /** destruction */
    virtual ~CacheSignal(){};

    /** Signal a change in value or state */
    virtual void setChanged() = 0;

    /** Get the sampling rate of the item */
    virtual OpcUa_UInt32 getSamplingRate() = 0;

    /** Get the index range for the sampling item. Returns NULL if no index range is set */
    virtual UaNumericRange* getIndexRange(){return NULL;}

    /** Indicates if percent deadband is requested and provides the value of the absulute change necessary to pass the deadband filter. */
    virtual OpcUa_Boolean isPercentDeadband(OpcUa_Double& absoluteChange) {absoluteChange=0; return OpcUa_False;}

    /** Set the item invalid */
    virtual void setInvalid() = 0;

    /** Get the item handle for the signal defined by the IOManager */
    virtual OpcUa_UInt32 hIOVariable() = 0;
};

class SERVER_CORE_EXPORT IOVariableCallback;
class SERVER_CORE_EXPORT UaVariableCache;

/** Class connecting a UaVariableCache object with a monitoring item.
 *
 * This class is used to connect a UaVariableCache object with a monitored item for
 * sampling data by implementing the interfaces CacheSignal and SamplingEngine
 */
class SERVER_CORE_EXPORT CacheVariableConnector:
    public SamplingExecution,
    public CacheSignal
{
    UA_DISABLE_COPY(CacheVariableConnector);
public:
    CacheVariableConnector(
        OpcUa_Int32         samplingInterval,
        UaVariableCache*    pUaVariableCache,
        IOVariableCallback* pIOVariableCallback,
        Session*            pSession);
    virtual ~CacheVariableConnector();

    /** Get IOVariableCallback used for the variable
     *  @return the IOVariableCallback used for the variable
     */
    IOVariableCallback* pIOVariableCallback(){return m_pIOVariableCallback;};

    /** Get UaVariableCache used for the variable
     *  @return the UaVariableCache used for the variable
     */
    UaVariableCache* pUaVariableCache(){return m_pUaVariableCache;};

    /** Set the sampling rate of the item
     *  @param samplingRate the sampling Rate in Milliseconds.
     */
    void setSamplingRate(OpcUa_UInt32 samplingRate){m_SamplingInterval = samplingRate;};

    //-------- Interface SamplingExecution -------------------
    /** Sample signal for the item */
    virtual void sample();
    //-------- Interface SamplingExecution -------------------

    //-------- Interface CacheSignal -------------------
    /** Signal a change in value or state */
    virtual void setChanged();

    /**
     * Get the sampling rate of the item
     * @return the sampling rate of the item.
     */
    virtual OpcUa_UInt32 getSamplingRate();

    /** Set the item invalid */
    virtual void setInvalid();

    /** Set the item valid */
    virtual void setValid(UaVariableCache* pUaVariableCache);

    /** Get the item handle for the signal defined by the IOManager */
    virtual OpcUa_UInt32 hIOVariable();

    /** Set the item handle for the signal defined by the IOManager */
    virtual void sethIOVariable(OpcUa_UInt32 handle);
    //-------- Interface CacheSignal -------------------

private:
    void sendCurrentValue();

private:
    /** This interval defines the sampling rate of the monitored item */
    OpcUa_Int32           m_SamplingInterval;
    /** UaVariableCache used for the variable */
    UaVariableCache*      m_pUaVariableCache;
    /** Changed flag */
    OpcUa_Boolean         m_isChanged;
    /** Callback interface for a IOVariable */
    IOVariableCallback*   m_pIOVariableCallback;
    /** Session object responsible for the sampling item */
    Session*              m_pSession;
    /** Get the item handle for the signal defined by the IOManager */
    OpcUa_UInt32          m_hIOVariable;
};

/** UaVariableCache
 *  @brief Abstract Base Class for UaVariable with a cached value. Derived from UaVariable.
 */
class SERVER_CORE_EXPORT UaVariableCache: public UaVariable
{
    UA_DISABLE_COPY(UaVariableCache);
protected:
    virtual ~UaVariableCache();
public:
    UaVariableCache();
    UaVariableCache(UaMutexRefCounted* pSharedMutex);

    /** Get the mode for the handling of the value attribute.<br>
     The value is a bit mask with the following values<br>
     UaVariable_Value_None = 0x0 - There is no value stored in the variable. The access to the value attribute must be implemented by the user of the SDK<br>
     UaVariable_Value_Cache = 0x1 - The variable has a cached value but normal read and data monitoring will not use the value directly. If only this flag is set
       all read and sampling access uses IOManagerUaNode::readValues that needs to be implemented in the custom NodeManager. All write operations to this variable
       are using IOManagerUaNode::writeValues. The cache value is not updated by the SDK. The custom code is responsible for updating the cache to allow the SDK
       to return values that are not older than the MaxAge parameter in the Read.<br>
     UaVariable_Value_CacheIsSource = 0x2 - If this flag is set, the value in the variable node is the data source and all read, data monitoring and write
       operations are using the value without requiring any custom code. Value changes can be provided with the method UaVariable::setValue().
       IOManagerUaNode::beforeSetAttributeValue and IOManagerUaNode::afterSetAttributeValue can be used to control writing of attributes or to get
       informed about a successful write of an attribute. This requires overwriting these functions in the custom NodeManager implementation class.<br>
     UaVariable_Value_CacheIsUpdatedOnRequest = 0x4 - If this flag is set, the custom code is responsible for updating the cache value for variables monitored
       by one or more clients and to handle read and write operations. Value changes can be provided with the method UaVariable::setValue(). The custom code
       gets informed about monitoring changes for items of this type by overwriting IOManagerUaNode::variableCacheMonitoringChanged in the custom NodeManager implementation.
       In addition it is required to implement IOManagerUaNode::readValues and IOManagerUaNode::writeValues for read and write operations.
       This option allows optimizing cyclic access to devices for data monitoring independent of read operations.
     @return The mode for the handling of the Value attribute.
     */
    virtual OpcUa_UInt32      valueHandling() const { return UaVariable_Value_Cache | UaVariable_Value_CacheIsSource; };

    /** Add a cache item
     *  @param pCacheSignal a pointer to the Variable pCacheSignal.
     */
    void addCacheSignal(CacheSignal* pCacheSignal);

    /** Remove a cache item
     *  @param pCacheSignal a pointer to the Variable pCacheSignal.
     */
    void removeCacheSignal(CacheSignal* pCacheSignal);

    /** Signal change to all cache items */
    void signalChange();

    /** Get the count of connected monitored items
     *  @return Count of monitored items to signal in the case of a data change
     */
    OpcUa_UInt32 signalCount();

    /** Get the minimum sampling interval requested
     *  @return the minimum sampling interval requested
     */
    OpcUa_UInt32 getMinSamplingInterval();

    /** Return the VariableHandle for the DataVariable.
     *  @return the VariableHandle for the DataVariable.
     */
    VariableHandle*    pVariableHandle();
    virtual void setInvalid();
    virtual void setSharedMutex(UaMutexRefCounted* pSharedMutex);
    UaMutexRefCounted* getSharedMutex();
    void getHandleIOVariableList(std::list<OpcUa_UInt32>& handles);
protected:
    UaMutexRefCounted* m_pMutexSignalList;
private:
    /** VariableHandle for the cached Variable. */
    VariableHandle*    m_pVariableHandle;
    /** List of CacheSignals. */
    std::list<CacheSignal*> m_listCacheSignals;
};

/** UaDataVariableCache
 *  @brief Class definition of the UaDataVariableCache. Derived from UaVariableCache and UaReferenceLists.
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaDataVariableCache :
    public UaVariableCache,
    public UaReferenceLists
{
    UaDataVariableCache(){};
protected:
    /** destruction */
    virtual ~UaDataVariableCache();
public:
    /** Construction<br>
     The description of the node class @ref L3UaNodeClassVariable provides more details about the variable attributes.
    */
    UaDataVariableCache(
        const UaString& name,
        const UaNodeId& nodeId,
        const UaVariant& defaultValue,
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

    /** Get the NodeId for the DataVariable.
     *  @return the NodeId for the DataVariable.
     */
    UaNodeId                nodeId() const;

    /** Get the browseName as QualifiedName of the current Node.
     *  @return the BrowseName for the DataVariable as QualifiedName.
     */
    virtual UaQualifiedName browseName() const;

    /** Get the displayName as LocalizedText of the current Node.
     *  @param  pSession Interface to the Session context for the method call
     *  @return the LocalizedText of the current Node.
     */
    virtual UaLocalizedText displayName(Session* pSession) const;

    /** Check if Node is DescriptionSupported.
     *  @return FALSE if not supported.
     */
    virtual OpcUa_Boolean   isDescriptionSupported() const;

    /** Get the description as LocalizedText of the current Node.
     *  @param  pSession Interface to the Session context for the method call
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

    /** Get the WriteMask of the User.
     *  @param  pSession Interface to the Session context for the method call
     *  @return the WriteMask of the User.
     */
    virtual OpcUa_UInt32    userWriteMask(Session* pSession) const;

    /** Gets the current value for the DataVariable.
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

    /** Set the DataType for the DataVariable. */
    virtual void setDataType(const UaNodeId& dataType);

    /** Get the ValueRank for the DataVariable.
     *  @return the ValueRank for the DataVariable.
     */
    virtual OpcUa_Int32     valueRank() const;

    /** Set the ValueRank for the DataVariable.*/
    virtual void setValueRank(OpcUa_Int32 valueRank);

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

    /** Get the Node.
     *  @return the current searched Node.
     */
    UaNode* getUaNode() const {return (UaNode*)this;};
protected:
    /** Default localeId for the DataVariable. */
    UaString           m_defaultLocaleId;

private:
    /** NodeId of the DataVariable. */
    UaNodeId           m_nodeId;
    /** Name of the DataVariable used in BrowseName and DisplayName. */
    UaString           m_name;

    /** Cached value of the DataVariable. */
    UaDataValue        m_dataValue;
    /** Simple data type of the value. */
    UaNodeId           m_dataType;
    /** Array rank of the value. */
    OpcUa_Int32        m_valueRank;
    /** Access level of the DataVariable. */
    OpcUa_Byte         m_accessLevel;
};

/** UaAnalogItemCache
 *  @brief  Class definition of the UaAnalogItemCache. Derived from UaDataVariableCache.
 */
class SERVER_CORE_EXPORT UaAnalogItemCache : public UaDataVariableCache
{
protected:
    /** destruction */
    virtual ~UaAnalogItemCache();
public:
    /** construction */
    UaAnalogItemCache(
        const UaString& name,
        const UaNodeId& nodeId,
        const UaVariant& defaultValue,
        OpcUa_Byte      accessLevel,
        const UaString& defaultLocaleId);

    /** Get the variable type NodeId for the analog item variable.
     *  @return the variable type NodeId for the analog item variable.
     */
    virtual UaNodeId          typeDefinitionId() const;
};

 /** UaPropertyCache
  *  @brief  Class definition of the UaPropertyCache. Derived from UaDataVariableCache.
  */
class SERVER_CORE_EXPORT UaPropertyCache : public UaDataVariableCache
{
protected:
    /** destruction */
    virtual ~UaPropertyCache();
public:
    /** construction */
    UaPropertyCache(
        const UaString& name,
        const UaNodeId& nodeId,
        const UaVariant& defaultValue,
        OpcUa_Byte      accessLevel,
        const UaString& defaultLocaleId);

    /** Get the object type NodeId for the server object.
     *  @return the object type NodeId for the server object.
     */
    virtual UaNodeId          typeDefinitionId() const;
};

/** UaMethodGeneric
 *  @brief Class definition of the UaMethodGeneric. Derived from UaReferenceLists and UaMethod.
 */
class SERVER_CORE_EXPORT UaMethodGeneric: public UaReferenceLists, public UaMethod
{
protected:
    /** destruction */
    virtual ~UaMethodGeneric();
public:
    /** construction */
    UaMethodGeneric(
        const UaString& name,
        const UaNodeId& nodeId,
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

    /** Get the NodeId for the DataVariable.
     *  @return the NodeId for the DataVariable.
     */
    UaNodeId                  nodeId() const;

    /** Get the browseName as QualifiedName of the current Node.
     *  @return the BrowseName for the DataVariable as QualifiedName.
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

    /** Get the WriteMask of the User.
     *  @param  pSession Interface to the Session context for the method call
     *  @return the WriteMask of the User.
     */
    virtual OpcUa_UInt32    userWriteMask(Session* pSession) const;

    /** Indicates if Method is executable.
     *  @return TRUE if executable FALSE if not.
     */
    virtual OpcUa_Boolean   executable() const;

    /** Indicates if method is executable by the user.
     *  @param pSession Interface to the Session context for the method call
     *  @return TRUE if UserExecutable FALSE if not.
     */
    virtual OpcUa_Boolean   userExecutable(Session* pSession) const;

    /** Get the Node.
     *  @return the current searched Node.
     */
    UaNode* getUaNode() const {return (UaNode*)this;};

private:
    /** NodeId of the DataVariable. */
    UaNodeId             m_nodeId;
    /** Name of the DataVariable used in BrowseName and DisplayName. */
    UaString           m_name;
    /** Default localeId for the DataVariable. */
    UaString           m_defaultLocaleId;
};

/** UaPropertyMethodArgument
 *  @brief Class definition of the UaPropertyMethodArgument. Derived from UaVariableCache and UaReferenceLists.
 *  It is not possible to use the default constructor.
 */
class SERVER_CORE_EXPORT UaPropertyMethodArgument :
    public UaVariableCache,
    public UaReferenceLists
{
    UaPropertyMethodArgument(){};
protected:
    /** destruction */
    virtual ~UaPropertyMethodArgument();
public:
    /** ArgumentType enumeration */
    enum ArgumentType
    {
        INARGUMENTS, /*!< Inargument */
        OUTARGUMENTS /*!< Outargument */
    };

    /** construction */
    UaPropertyMethodArgument(
        const UaNodeId& nodeId,
        OpcUa_Byte   accessLevel,
        OpcUa_UInt32 numberOfArguments,
        ArgumentType argumentType);

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

    /** Get the NodeId for the DataVariable.
     *  @return the NodeId for the DataVariable.
     */
    UaNodeId                nodeId() const;

    /** Get the browseName as QualifiedName of the current Node.
     *  @return the BrowseName for the DataVariable as QualifiedName.
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

   /** Get the WriteMask of the User.
    *  @param  pSession Interface to the Session context for the method call
    *  @return the WriteMask of the User.
    */
    virtual OpcUa_UInt32    userWriteMask(Session* pSession) const;

    /**
     * Sets the current value for the DataVariable.
     * @param pSession Interface to the Session context for the method call
     * @return the current value for the DataVariable.
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

    /**
     * Get the AccessLevel for the DataVariable.
     * @return the AccessLevel for the DataVariable.
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

    /** Get the Node.
     *  @return the current searched Node.
     */
    UaNode* getUaNode() const {return (UaNode*)this;};

    /** Set one of the arguments in the argument list.
     *  @param index            the index where the new item is stored.
     *  @param name             the name of the new item.
     *  @param dataType         the DataType of the DataVariable.
     *  @param valueRank        the ValueRank of the DataVariable.
     *  @param arrayDimensions  the arrayDimensions value for the passed UaNode.
     *  @param description      the description as LocalizedText of the current Node.
     *  @return                 Error code
     */
    OpcUa_StatusCode setArgument(
        OpcUa_UInt32           index,
        const UaString&        name,
        const UaNodeId&        dataType,
        OpcUa_Int32            valueRank,
        const UaUInt32Array&   arrayDimensions,
        const UaLocalizedText& description);

private:
    /** NodeId of the Property. */
    UaNodeId               m_nodeId;
    /** Value of the argument property. */
    UaExtensionObjectArray m_arguments;
    /** Timestamp of last value change. */
    OpcUa_DateTime         m_sourceTimestamp;
    /** Access level of the DataVariable. */
    OpcUa_Byte             m_accessLevel;
    /** Type of the argument array (IN or OUT). */
    ArgumentType           m_argumentType;
};

#endif // __UADATAVARIABLECACHE_H__
