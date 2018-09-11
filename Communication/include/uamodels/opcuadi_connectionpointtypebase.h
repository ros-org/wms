/******************************************************************************
** opcuadi_connectionpointtypebase.h
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

#ifndef __OPCUADI_CONNECTIONPOINTTYPEBASE_H__
#define __OPCUADI_CONNECTIONPOINTTYPEBASE_H__

#include "opcuadi_topologyelementtype.h"
#include "opcuadi_datatypes.h"
#include "basenodes.h"
#include "opcuadi_identifiers.h"
#include "opcuadi_instancefactory_devices.h"

// Namespace for the UA information model http://opcfoundation.org/UA/DI/
namespace OpcUaDi {

class FunctionalGroupType;
class NetworkType;
class ProtocolType;

/** Generated base class for a ConnectionPointType.
 *
 *  This class contains the generated base code for the object type ConnectionPointType
 *  representing an OPC UA ObjectType. This class is used to create the object type and to
 *  create and represent instances of the object type in the server address space.
 *
 *  **Object members of the ConnectionPointType:**
 *
 *  Browse Name           | TypeDefinition      | Modelling Rule       | See Also
 *  ----------------------|---------------------|----------------------|-----------------------
 *  \<NetworkIdentifier\> | NetworkType         | OptionalPlaceholder  | &nbsp;
 *  \<ProfileId\>         | ProtocolType        | MandatoryPlaceholder | &nbsp;
 *  NetworkAddress        | FunctionalGroupType | Mandatory            | \ref getNetworkAddress
 *
 */
class UAMODELS_EXPORT ConnectionPointTypeBase:
    public OpcUaDi::TopologyElementType
{
    UA_DISABLE_COPY(ConnectionPointTypeBase);
protected:
    virtual ~ConnectionPointTypeBase();
public:
    // construction / destruction
    ConnectionPointTypeBase(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    ConnectionPointTypeBase(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    ConnectionPointTypeBase(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;


    virtual OpcUaDi::FunctionalGroupType* getNetworkAddress();

// Add placeholders
    virtual UaStatus addNetwork(OpcUaDi::NetworkType *pNetwork);
    virtual UaStatus addProfileId(OpcUaDi::ProtocolType *pProfileId);

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(ConnectionPointTypeBase *pInstance);

protected:
    // Object nodes
    // Object NetworkIdentifier
    static OpcUaDi::NetworkType*  s_pNetworkIdentifier;
    // Object ProfileId
    static OpcUaDi::ProtocolType*  s_pProfileId;
    // Object NetworkAddress
    static OpcUaDi::FunctionalGroupType*  s_pNetworkAddress;
    OpcUaDi::FunctionalGroupType*  m_pNetworkAddress;



private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/DI/

#endif // #ifndef __OPCUADICONNECTIONPOINTTYPEBASE_H__


