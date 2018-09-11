/******************************************************************************
** opcua_baseobjecttype.h
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
#ifndef __UABASEOBJECTTYPE_H__
#define __UABASEOBJECTTYPE_H__

#include "nodemanager.h"
#include "uamutex.h"
#include "uaobjecttypes.h"
#include "uadatavariablecache.h"
#include "methodmanager.h"
#include "uagenericnodes.h"
#include "uathreadpool.h"
#include "basenodes.h"

class XmlUaNodeFactoryManager;

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class UaObjectAttributes;

/** @brief Class implementing the UaObject interface for the BaseObjectType.

 OPC UA Objects are used to represent systems, system components, real-world objects and software
 objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 can be found in the general description of the @ref L3UaNodeClassObject node class.

 The BaseObjectType is used as type definition whenever there is an
 Object having no more concrete type definitions available. Servers
 should avoid using this ObjectType and use a more specific type, if
 possible. This ObjectType is the base ObjectType and all other
 ObjectTypes shall either directly or indirectly inherit from
 it. However, it might not be possible for Servers to provide all
 HasSubtype References from this ObjectType to its subtypes, and
 therefore it is not required to provide this information.
 */
class SERVER_CORE_EXPORT BaseObjectType:
    public MethodManager,
    public UaObject,
    public UaReferenceLists
{
    UA_DISABLE_COPY(BaseObjectType);
protected:
    // Destruction
    virtual ~BaseObjectType();
public:
    // Construction
    BaseObjectType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    BaseObjectType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    BaseObjectType(
        UaBase::Object*    pObject,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void clearStaticMembers();

    //- Interface UaNode and UaObject ------------------------------------------------------
    UaReferenceLists* getUaReferenceLists() const {return (UaReferenceLists*)this;};
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
    virtual UaNodeId        typeDefinitionId() const;
    virtual OpcUa_Byte      eventNotifier() const;
    virtual MethodManager*  getMethodManager(UaMethod* pMethod) const;
    virtual void            setUserData(UserDataBase* pUserData);
    virtual UserDataBase*   getUserData() const;
    //- Interface UaObject ----------------------------------------------------------------

    virtual void            setBrowseName(const UaQualifiedName& browseName);
    virtual void            setDisplayName(const UaLocalizedText& displayName);
    virtual void            setDescription(const UaLocalizedText& description);
    virtual void            setWriteMask(OpcUa_UInt32 writeMask);
    virtual void            setEventNotifier(OpcUa_Byte eventNotifier);

    virtual void            setModellingRuleId(const UaNodeId& modellingRuleId);
    virtual UaNodeId        modellingRuleId() const;

    void setMethodManager(MethodManager* pMethodManager);
    static void setDefaultLocalId(const UaString& defaultLocaleId);

    virtual UaStatus setAttributeValue(Session* pSession, OpcUa_Int32 attributeId, const UaDataValue& dataValue, OpcUa_Boolean checkWriteMask);

    // Interface MethodManager::beginCall
    virtual UaStatus beginCall(
        MethodManagerCallback* pCallback,
        const ServiceContext&  serviceContext,
        OpcUa_UInt32           callbackHandle,
        MethodHandle*          pMethodHandle,
        const UaVariantArray&  inputArguments);
    virtual UaStatus call(
        const ServiceContext&  serviceContext,
        MethodHandle*          pMethodHandle,
        const UaVariantArray&  inputArguments,
        UaVariantArray&        outputArguments,
        UaStatusCodeArray&     inputArgumentResults,
        UaDiagnosticInfos&     inputArgumentDiag);

    inline NodeManagerConfig* getNodeManagerConfig() const { return m_pNodeConfig; }
    inline UaMutexRefCounted* getSharedMutex() const { return m_pSharedMutex; }

    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(BaseObjectType* pInstance);

protected:
    NodeManagerConfig*  m_pNodeConfig;
    UaMutexRefCounted*  m_pSharedMutex;
private:
    UaObjectAttributes* m_pObjectAttributes;
    UserDataBase*       m_pUserData;
};

/** Base class for representing UA Object of any type definition.
* The type definition NodeId can be set on instances of this class to represent an OPC UA object of any type.
*/
class SERVER_CORE_EXPORT BaseObjectTypeGeneric: public BaseObjectType
{
    UA_DISABLE_COPY(BaseObjectTypeGeneric);
protected:
    virtual ~BaseObjectTypeGeneric();
public:
    BaseObjectTypeGeneric(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig);
    BaseObjectTypeGeneric(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig);

    virtual UaNodeId typeDefinitionId() const;
    virtual void setTypeDefinitionId(const UaNodeId& typeDefinitionId);

private:
    UaNodeId m_typeDefinitionId;
};

typedef void (GenericObjectType_PfnStaticClear)();

class SERVER_CORE_EXPORT GenericObjectType:
    public UaGenericObjectType
{
    UA_DISABLE_COPY(GenericObjectType);
protected:
    virtual ~GenericObjectType();
public:
    GenericObjectType(
        const UaNodeId&        nodeId,
        const UaQualifiedName& browseName,
        const UaLocalizedText& displayName,
        const UaLocalizedText& description,
        OpcUa_Boolean          isAbstract,
        GenericObjectType_PfnStaticClear* pStaticClear);
private:
    GenericObjectType_PfnStaticClear* m_pStaticClear;
};


class UaMethodAttributes;

/** @brief Class implementing the UaMethod interface for the Method handling.

 OPC UA Methods are used to represent methods that can be called on objects.<br>
 */
class SERVER_CORE_EXPORT BaseMethod:
    public UaMethod,
    public UaReferenceLists
{
    UA_DISABLE_COPY(BaseMethod);
protected:
    // Destruction
    virtual ~BaseMethod();
public:
    // Construction
    BaseMethod(UaNode* pParentNode, UaMethod* pInstanceDeclarationMethod, UaMutexRefCounted* pSharedMutex = NULL);
    BaseMethod(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, UaMutexRefCounted* pSharedMutex = NULL);

    //- Interface UaNode and UaObject ------------------------------------------------------
    UaReferenceLists* getUaReferenceLists() const {return (UaReferenceLists*)this;};
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
    virtual OpcUa_Boolean   executable() const;
    virtual OpcUa_Boolean   userExecutable(Session* pSession) const;
    virtual void            setUserData(UserDataBase* pUserData);
    virtual UserDataBase*   getUserData() const;
    //- Interface UaObject ----------------------------------------------------------------

    virtual void            setBrowseName(const UaQualifiedName& browseName);
    virtual void            setDisplayName(const UaLocalizedText& displayName);
    virtual void            setDescription(const UaLocalizedText& description);
    virtual void            setWriteMask(OpcUa_UInt32 writeMask);
    virtual void            setExecutable(OpcUa_Boolean executable);

    virtual void            setModellingRuleId(const UaNodeId& modellingRuleId);
    virtual UaNodeId        modellingRuleId() const;

    virtual UaStatus setAttributeValue(Session* pSession, OpcUa_Int32 attributeId, const UaDataValue& dataValue, OpcUa_Boolean checkWriteMask);

    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(BaseObjectType* pInstance);

protected:
    UaMutexRefCounted*  m_pSharedMutex;
private:
    UaMethodAttributes* m_pMethodAttributes;
    UserDataBase*       m_pUserData;
};

/** Helper class for executing methods in a worker thread pool job.
 */
class SERVER_CORE_EXPORT MethodCallJob: public UaThreadPoolJob
{
    UA_DISABLE_COPY(MethodCallJob);
public:
    MethodCallJob();
    virtual ~MethodCallJob();
    void execute();
    void initialize(
        BaseObjectType*        pBaseObjectType,
        MethodManagerCallback* pCallback,
        const ServiceContext&  serviceContext,
        OpcUa_UInt32           callbackHandle,
        MethodHandle*          pMethodHandle,
        const UaVariantArray&  inputArguments);

private:
    MethodManagerCallback* m_pCallback;
    ServiceContext         m_serviceContext;
    OpcUa_UInt32           m_callbackHandle;
    MethodHandle*          m_pMethodHandle;
    UaVariantArray         m_inputArguments;
    BaseObjectType*        m_pBaseObjectType;
};

}

#endif // #ifndef __UABASEOBJECTTYPE_H__

