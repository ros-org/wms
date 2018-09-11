/******************************************************************************
** opcua_basevariabletype.h
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
#ifndef __OPCUA_BASEVARIABLETYPE_H__
#define __OPCUA_BASEVARIABLETYPE_H__

#include "nodemanager.h"
#include "uadatavariablecache.h"
#include "opcua_identifiers.h"
#include "uagenericnodes.h"
#include "basenodes.h"

class XmlUaNodeFactoryManager;

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class UaVariableAttributes;

/** Base class for all classes representing UA Variables
*/
class SERVER_CORE_EXPORT BaseVariableType:
    public UaVariableCache,
    public UaReferenceLists
{
    UA_DISABLE_COPY(BaseVariableType);
protected:
    virtual ~BaseVariableType();
public:
    BaseVariableType(
        UaNode*            pParentNode,
        UaVariable*        pInstanceDeclarationVariable,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    BaseVariableType(
        const UaNodeId&    nodeId,
        const UaString&    name,
        OpcUa_UInt16       browseNameNameSpaceIndex,
        const UaVariant&   initialValue,
        OpcUa_Byte         accessLevel,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    BaseVariableType(
        UaBase::Variable*  pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    static void createTypes();
    static void clearStaticMembers();

    UaReferenceLists* getUaReferenceLists() const;
    UaStatus          browse(const ServiceContext& serviceContext, BrowseContext& browseContext, UaReferenceDescriptions& References);

    UaNodeId                nodeId() const;
    virtual UaQualifiedName browseName() const;
    virtual UaLocalizedText displayName(Session* pSession) const;
    virtual OpcUa_Boolean   isDescriptionSupported() const;
    virtual UaLocalizedText description(Session* pSession) const;
    virtual OpcUa_Boolean   isWriteMaskSupported() const;
    virtual OpcUa_UInt32    writeMask() const;
    virtual OpcUa_Boolean   isUserWriteMaskSupported() const;
    virtual OpcUa_UInt32    userWriteMask(Session* pSession) const;
    virtual UaDataValue     value(Session* pSession);
    virtual UaStatus        setValue(Session* pSession, const UaDataValue& dataValue, OpcUa_Boolean checkAccessLevel);
    virtual UaNodeId        dataType() const;
    virtual OpcUa_Int32     valueRank() const;
    virtual OpcUa_Boolean   isArrayDimensionsSupported() const;
    virtual void            arrayDimensions(UaUInt32Array& arrayDimensions) const;
    virtual OpcUa_Byte      accessLevel() const;
    virtual OpcUa_Byte      userAccessLevel(Session* pSession) const;
    virtual OpcUa_Boolean   isMinimumSamplingIntervalSupported() const;
    virtual OpcUa_Double    minimumSamplingInterval() const;
    virtual OpcUa_Boolean   historizing() const;

    virtual void            setBrowseName(const UaQualifiedName& browseName);
    virtual void            setDisplayName(const UaLocalizedText& displayName);
    virtual void            setDescription(const UaLocalizedText& description);
    virtual void            setWriteMask(OpcUa_UInt32 writeMask);
    virtual void            setDataType(const UaNodeId& dataType);
    virtual void            setValueRank(OpcUa_Int32 valueRank);
    virtual void            setArrayDimensions(const UaUInt32Array& arrayDimensions);
    virtual void            setAccessLevel(OpcUa_Byte accessLevel);
    virtual void            setMinimumSamplingInterval(OpcUa_Double minimumSamplingInterval);
    virtual void            setHistorizing(OpcUa_Boolean historizing);

    virtual void            setModellingRuleId(const UaNodeId& modellingRuleId);
    virtual UaNodeId        modellingRuleId() const;
    UaNode* getUaNode() const;

    virtual OpcUa_UInt32    valueHandling() const;
    virtual void            setValueHandling(OpcUa_UInt32 valueHandling);
    virtual void            setInvalid();
    virtual void            setUserData(UserDataBase* pUserData);
    virtual UserDataBase*   getUserData() const;
    virtual UaStatus        setAttributeValue(Session* pSession, OpcUa_Int32 attributeId, const UaDataValue& dataValue, OpcUa_Boolean checkWriteMask);

    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(BaseVariableType* pInstance);

private:
    /** Cached value of the DataVariable. */
    UaDataValue m_dataValue;
    /** Interface to object providing variable attribute values */
    UaVariableAttributes* m_pVariableAttributes;
    UserDataBase* m_pUserData;
    static bool s_typeNodesCreated;
};

/** Base class for representing UA Variables of any type definition.
* The type definition NodeId can be set on instances of this class to represent an OPC UA variable of any type.
*/
class SERVER_CORE_EXPORT BaseVariableTypeGeneric: public BaseVariableType
{
    UA_DISABLE_COPY(BaseVariableTypeGeneric);
protected:
    virtual ~BaseVariableTypeGeneric();
public:
    BaseVariableTypeGeneric(
        UaNode*            pParentNode,
        UaVariable*        pInstanceDeclarationVariable,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    BaseVariableTypeGeneric(
        const UaNodeId&    nodeId,
        const UaString&    name,
        OpcUa_UInt16       browseNameNameSpaceIndex,
        const UaVariant&   initialValue,
        OpcUa_Byte         accessLevel,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    virtual UaNodeId typeDefinitionId() const;
    virtual void setTypeDefinitionId(const UaNodeId& typeDefinitionId);
private:
    UaNodeId      m_typeDefinitionId;
};

/** Base class for representing UA Variables with a localized text value for several locale.
 *
 * Text with different locales can be added or overwritten for a locale by setting the text with the
 * associated LocaleId with setValue(). Setting a null String for the text for a locale will delete the String for that locale.
 * Setting a null String for the locale and a text is setting the text for an invariant locale. Setting a null
 * String for the text and a null String for the LocaleId will delete the entries for all locales.
 */
class SERVER_CORE_EXPORT BaseVariableTypeLocalizedTextValue: public BaseVariableTypeGeneric
{
    UA_DISABLE_COPY(BaseVariableTypeLocalizedTextValue);
protected:
    virtual ~BaseVariableTypeLocalizedTextValue();
public:
    BaseVariableTypeLocalizedTextValue(
        UaNode*            pParentNode,
        UaVariable*        pInstanceDeclarationVariable,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    BaseVariableTypeLocalizedTextValue(
        const UaNodeId&    nodeId,
        const UaString&    name,
        OpcUa_UInt16       browseNameNameSpaceIndex,
        const UaVariant&   initialValue,
        OpcUa_Byte         accessLevel,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    virtual UaDataValue    value(Session* pSession);
    virtual UaStatus       setValue(Session* pSession, const UaDataValue& dataValue, OpcUa_Boolean checkAccessLevel);

private:
    UaLocalizedTextArray m_localizedTextValue;
};

typedef void (GenericVariableType_PfnStaticClear)();

class SERVER_CORE_EXPORT GenericVariableType:
    public UaGenericVariableType
{
    UA_DISABLE_COPY(GenericVariableType);
protected:
    virtual ~GenericVariableType();
public:
    GenericVariableType(
        const UaNodeId&        nodeId,
        const UaQualifiedName& browseName,
        const UaLocalizedText& displayName,
        const UaLocalizedText& description,
        const UaVariant&       value,
        const UaNodeId&        dataTyp,
        OpcUa_Int32            valueRank,
        OpcUa_Boolean          isAbstract,
        GenericVariableType_PfnStaticClear* pStaticClear);
private:
    GenericVariableType_PfnStaticClear* m_pStaticClear;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUA_BASEVARIABLETYPE_H__

