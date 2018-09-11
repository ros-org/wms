/******************************************************************************
** opcua_addressspacefiletype.h
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

#ifndef __OPCUA_ADDRESSSPACEFILETYPE_H__
#define __OPCUA_ADDRESSSPACEFILETYPE_H__

#include "opcua_filetype.h"
#include "basenodes.h"
#include "opcua_identifiers.h"
#include "opcua_propertytype.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class SERVER_CORE_EXPORT AddressSpaceFileType;

/** Callback interface for handling incoming ExportNamespace Method calls
 */
class SERVER_CORE_EXPORT AddressSpaceFileCallback
{
public:
    AddressSpaceFileCallback(){}
    virtual ~AddressSpaceFileCallback(){}

    /**
     *  Provides a way to export the namespace from the Server address space to the XML
     *  file represented by the AddressSpaceFileType.
     *
     *  Value attributes are only exported if they represent static configuration
     *  information. The client is expected to call the ExportNamespace method first to
     *  update the XML file and then access the file with the methods defined in the
     *  \ref OpcUa::FileType "FileType".
     */
    virtual UaStatus exportNamespace(
        const ServiceContext& serviceContext, /**< General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/
        AddressSpaceFileType* pAddressSpaceFile /**< Affected Object Node.*/
        ) = 0;
};

/** Generated base class for a AddressSpaceFileType.
 *
 *  This class contains the generated base code for the object type AddressSpaceFileType
 *  representing an OPC UA ObjectType. This class is used to create the object type and to
 *  create and represent instances of the object type in the server address space.
 *
 *  This object type defines the file for a namespace provided by the OPC UA
 *  Server.
 *
 *  It represents an XML address space file using the XML schema defined in Part 6
 *  of the OPC UA Specification.
 *
 *  Servers might provide some vendor-specific mechanisms importing parts of an
 *  address space as subtype of this object type, for example by defining
 *  appropriate methods.
 *
 *  See also \ref Doc_OpcUa_AddressSpaceFileType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AddressSpaceFileType:
    public OpcUa::FileType
{
    UA_DISABLE_COPY(AddressSpaceFileType);
protected:
    virtual ~AddressSpaceFileType();
public:
    // construction / destruction
    AddressSpaceFileType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    AddressSpaceFileType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    AddressSpaceFileType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;


    //- Interface MethodManager -----------------------------------------------------------
    /** Call method of an UA object. */
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
    //- Interface MethodManager -----------------------------------------------------------

    virtual UaStatus ExportNamespace(const ServiceContext& serviceContext);

    virtual OpcUa::BaseMethod* getExportNamespace();
    virtual const OpcUa::BaseMethod* getExportNamespace() const;

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(AddressSpaceFileType *pInstance);

    void setCallback(AddressSpaceFileCallback* pCallback);

protected:

    // Method nodes
    static OpcUa::BaseMethod* s_pExportNamespaceMethod;
    OpcUa::BaseMethod*  m_pExportNamespaceMethod;


private:
    void initialize();

private:
    static bool s_typeNodesCreated;
    AddressSpaceFileCallback* m_pCallback;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUAADDRESSSPACEFILETYPE_H__


