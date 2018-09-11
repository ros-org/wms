/******************************************************************************
** opcuadi_configurableobjecttypebase.h
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
** Project: C++ OPC Server SDK information model for namespace http://opcfoundation.org/UA/DI/
**
** Description: OPC Unified Architecture Software Development Kit.
**
******************************************************************************/

#ifndef __OPCUADI_CONFIGURABLEOBJECTTYPEBASE_H__
#define __OPCUADI_CONFIGURABLEOBJECTTYPEBASE_H__

#include "opcua_baseobjecttype.h"
#include "opcuadi_datatypes.h"
#include "basenodes.h"
#include "opcua_baseobjecttype.h"
#include "opcua_foldertype.h"
#include "opcuadi_identifiers.h"
#include "opcuadi_instancefactory_devices.h"

// Namespace for the UA information model http://opcfoundation.org/UA/DI/
namespace OpcUaDi {


/** Generated base class for a ConfigurableObjectType.
 *
 *  This class contains the generated base code for the object type ConfigurableObjectType
 *  representing an OPC UA ObjectType. This class is used to create the object type and to
 *  create and represent instances of the object type in the server address space.
 *
 *  **Object members of the ConfigurableObjectType:**
 *
 *  Browse Name          | TypeDefinition | Modelling Rule      | See Also
 *  ---------------------|----------------|---------------------|-----------------------
 *  \<ObjectIdentifier\> | BaseObjectType | OptionalPlaceholder | &nbsp;
 *  SupportedTypes       | FolderType     | Mandatory           | \ref getSupportedTypes
 *
 */
class UAMODELS_EXPORT ConfigurableObjectTypeBase:
    public OpcUa::BaseObjectType
{
    UA_DISABLE_COPY(ConfigurableObjectTypeBase);
protected:
    virtual ~ConfigurableObjectTypeBase();
public:
    // construction / destruction
    ConfigurableObjectTypeBase(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    ConfigurableObjectTypeBase(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    ConfigurableObjectTypeBase(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;


    virtual OpcUa::FolderType* getSupportedTypes();

// Add placeholders
    virtual UaStatus addObject(OpcUa::BaseObjectType *pObject);

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(ConfigurableObjectTypeBase *pInstance);

protected:
    // Object nodes
    // Object ObjectIdentifier
    static OpcUa::BaseObjectType*  s_pObjectIdentifier;
    // Object SupportedTypes
    static OpcUa::FolderType*  s_pSupportedTypes;
    OpcUa::FolderType*  m_pSupportedTypes;



private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/DI/

#endif // #ifndef __OPCUADICONFIGURABLEOBJECTTYPEBASE_H__


