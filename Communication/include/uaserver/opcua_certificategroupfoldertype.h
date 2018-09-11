/******************************************************************************
** opcua_certificategroupfoldertype.h
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

#ifndef __OPCUA_CERTIFICATEGROUPFOLDERTYPE_H__
#define __OPCUA_CERTIFICATEGROUPFOLDERTYPE_H__

#include "opcua_foldertype.h"
#include "basenodes.h"
#include "opcua_identifiers.h"
#include "opcua_propertytype.h"
#include "uaargument.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class CertificateGroupType;
class PropertyType;
class TrustListType;

/** Generated base class for a CertificateGroupFolderType.
 *
 *  This class contains the auto generated code for the object type CertificateGroupFolderType
 *  representing an OPC UA ObjectType. This class is used to create the object type and to
 *  create and represent the object in the server address space.
 *
 *  **Object members of the CertificateGroupFolderType:**
 *
 *  Browse Name             | TypeDefinition       | Modelling Rule       | See Also
 *  ------------------------|----------------------|----------------------|--------------------------------
 *  \<CertificateGroup\>    | CertificateGroupType | MandatoryPlaceholder | &nbsp;
 *  DefaultApplicationGroup | CertificateGroupType | Mandatory            | \ref getDefaultApplicationGroup
 *  DefaultHttpsGroup       | CertificateGroupType | Optional             | \ref getDefaultHttpsGroup
 *  DefaultUserTokenGroup   | CertificateGroupType | Optional             | \ref getDefaultUserTokenGroup
 *
 *  This type is used for Folders which organize Certificate Groups in the address
 *  space.
 *
 *  See also \ref Doc_OpcUa_CertificateGroupFolderType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT CertificateGroupFolderType:
    public OpcUa::FolderType
{
    UA_DISABLE_COPY(CertificateGroupFolderType);
protected:
    virtual ~CertificateGroupFolderType();
public:
    // construction / destruction
    CertificateGroupFolderType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    CertificateGroupFolderType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    CertificateGroupFolderType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;


    virtual OpcUa::CertificateGroupType* getDefaultApplicationGroup();
    virtual OpcUa::CertificateGroupType* getDefaultHttpsGroup();
    virtual OpcUa::CertificateGroupType* getDefaultUserTokenGroup();

// Add placeholders
    virtual UaStatus addCertificateGroup(OpcUa::CertificateGroupType *pCertificateGroup);

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(CertificateGroupFolderType *pInstance);
    virtual void recursivSetAccessInfo(NodeAccessInfo* pAccessInfo);

protected:
    // Object nodes
    // Object xCertificateGroupx
    static OpcUa::CertificateGroupType*  s_pxCertificateGroupx;
    // Object DefaultApplicationGroup
    static OpcUa::CertificateGroupType*  s_pDefaultApplicationGroup;
    OpcUa::CertificateGroupType*  m_pDefaultApplicationGroup;
    // Object DefaultHttpsGroup
    static OpcUa::CertificateGroupType*  s_pDefaultHttpsGroup;
    OpcUa::CertificateGroupType*  m_pDefaultHttpsGroup;
    // Object DefaultUserTokenGroup
    static OpcUa::CertificateGroupType*  s_pDefaultUserTokenGroup;
    OpcUa::CertificateGroupType*  m_pDefaultUserTokenGroup;



private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUACERTIFICATEGROUPFOLDERTYPE_H__


