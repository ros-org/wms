/******************************************************************************
** instancefactory.h
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
#ifndef XMLUANODEFACTORYMANAGER_H
#define XMLUANODEFACTORYMANAGER_H

#include "basenodes.h"
#include "opcua_basevariabletype.h"
#include "opcua_baseobjecttype.h"
#include <map>

class XmlUaNodeFactoryManager;

/** Abstract factory for creating UaVariables or UaObjects of a namespace.
 *
 * This class provides an interface for creating UaNodes and its children depending on
 * \ref UaBase::BaseNode "UaBase::BaseNodes" and for adding the new nodes to a
 * NodeManagerConfig. The TypeDefinition of the UaBase::BaseNode can be used to
 * create an instance of a toolkit class.
 *
 * Subtypes of this class are used by XmlUaNodeFactoryManager.
 */
class SERVER_CORE_EXPORT XmlUaNodeFactoryNamespace
{
public:
    XmlUaNodeFactoryNamespace(OpcUa_UInt16 namespaceIndex);
    virtual ~XmlUaNodeFactoryNamespace(){}

    virtual UaVariable* createVariable(
        UaBase::Variable *pVariable,
        XmlUaNodeFactoryManager *pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL) = 0;
    virtual UaObject* createObject(
        UaBase::Object *pObject,
        XmlUaNodeFactoryManager *pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL) = 0;

    OpcUa_UInt16 namespaceIndex() const;

    virtual OpcUa::BaseVariableTypeGeneric* createGenericVariable(
        UaBase::Variable *pVariable,
        XmlUaNodeFactoryManager *pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex);
    virtual OpcUa::BaseObjectTypeGeneric* createGenericObject(
        UaBase::Object *pObject,
        XmlUaNodeFactoryManager *pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex);
    virtual OpcUa::BaseMethod* createGenericMethod(
        UaBase::Method *pMethod,
        XmlUaNodeFactoryManager *pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex);
    virtual UaVariant defaultValue(const UaNodeId &dataTypeId, OpcUa_Int32 valueRank) const = 0;

private:
    OpcUa_UInt16 m_namespaceIndex;
};

/** This class is the factory for creating instances of ObjectTypes and VariableType
 * defined in namespace 0.*/
class SERVER_CORE_EXPORT XmlUaNodeFactoryNamespace0 : public XmlUaNodeFactoryNamespace
{
public:
    XmlUaNodeFactoryNamespace0();

    virtual UaVariable* createVariable(
        UaBase::Variable *pVariable,
        XmlUaNodeFactoryManager *pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    virtual UaObject* createObject(
        UaBase::Object *pObject,
        XmlUaNodeFactoryManager *pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    virtual UaVariant defaultValue(const UaNodeId &dataTypeId, OpcUa_Int32 valueRank) const;
};

/** The manager of the factories for creating instances.
 *
 * The main use case for this class is to parse a NodeSet XML file using NodeManagerNodeSetXml
 * and to create instances of toolkit classes using the resulting \ref UaBase::BaseNode
 * "UaBase::BaseNodes".
 */
class SERVER_CORE_EXPORT XmlUaNodeFactoryManager
{
public:
    XmlUaNodeFactoryManager();
    virtual ~XmlUaNodeFactoryManager();
    void addNamespace(XmlUaNodeFactoryNamespace *pFactoryNamespace);

    UaVariable* createVariable(
        UaBase::Variable *pVariable,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    UaObject* createObject(
        UaBase::Object *pObject,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    virtual UaMethod* createMethod(
        UaBase::Method *pMethod,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    virtual UaDataType* createDataType(
        UaBase::DataType *pDataType,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    virtual UaReferenceType* createReferenceType(
        UaBase::ReferenceType *pReferenceType,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    virtual UaObjectType* createObjectType(
        UaBase::ObjectType *pObjectType,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    virtual UaVariableType* createVariableType(
        UaBase::VariableType *pVariableType,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    UaVariant defaultValue(const UaNodeId &dataTypeId, OpcUa_Int32 valueRank) const;

private:
    std::map<OpcUa_UInt16, XmlUaNodeFactoryNamespace*> m_mapFactories;
    XmlUaNodeFactoryNamespace0 m_namespace0;
    std::map<UaNodeId, UaEnumDefinition> m_customEnumerations;

};
#endif // INSTANCEFACTORY_H
