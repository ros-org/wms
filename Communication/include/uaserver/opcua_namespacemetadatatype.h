/******************************************************************************
** opcua_namespacemetadatatype.h
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

#ifndef __OPCUA_NAMESPACEMETADATATYPE_H__
#define __OPCUA_NAMESPACEMETADATATYPE_H__

#include "opcua_baseobjecttype.h"
#include "basenodes.h"
#include "opcua_identifiers.h"
#include "opcua_propertytype.h"
#include "uaargument.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class AddressSpaceFileType;
class PropertyType;

/** Generated base class for a NamespaceMetadataType.
 *
 *  This class contains the generated base code for the object type NamespaceMetadataType
 *  representing an OPC UA ObjectType. This class is used to create the object type and to
 *  create and represent instances of the object type in the server address space.
 *
 *  **Object members of the NamespaceMetadataType:**
 *
 *  Browse Name   | TypeDefinition       | Modelling Rule | See Also
 *  --------------|----------------------|----------------|----------------------
 *  NamespaceFile | AddressSpaceFileType | Optional       | \ref getNamespaceFile
 *
 *  **Variable members of the NamespaceMetadataType:**
 *
 *  Browse Name               | DataType     | TypeDefinition | Modelling Rule | See Also
 *  --------------------------|--------------|----------------|----------------|---------------------------------------------------------------------
 *  IsNamespaceSubset         | Boolean      | PropertyType   | Mandatory      | \ref getIsNamespaceSubset, \ref setIsNamespaceSubset
 *  NamespacePublicationDate  | DateTime     | PropertyType   | Mandatory      | \ref getNamespacePublicationDate, \ref setNamespacePublicationDate
 *  NamespaceUri              | String       | PropertyType   | Mandatory      | \ref getNamespaceUri, \ref setNamespaceUri
 *  NamespaceVersion          | String       | PropertyType   | Mandatory      | \ref getNamespaceVersion, \ref setNamespaceVersion
 *  StaticNodeIdTypes         | IdType       | PropertyType   | Mandatory      | \ref getStaticNodeIdTypes, \ref setStaticNodeIdTypes
 *  StaticNumericNodeIdRange  | NumericRange | PropertyType   | Mandatory      | \ref getStaticNumericNodeIdRange, \ref setStaticNumericNodeIdRange
 *  StaticStringNodeIdPattern | String       | PropertyType   | Mandatory      | \ref getStaticStringNodeIdPattern, \ref setStaticStringNodeIdPattern
 *
 *  This object type defines the metadata for a namespace provided by the Server.
 *
 *  Instances of this object allow Servers to provide more information like version
 *  information in addition to the namespace URI. Important information for
 *  aggregating Servers is provided by the StaticNodeIdTypes,
 *  StaticNumericNodeIdRange and StaticStringNodeIdPattern properties.
 *
 *  The browse name of instances of this type shall be derived from the represented
 *  namespace. This can, for example, be done by using the index of the namespace
 *  in the namespace array as namespaceIndex of the \ref OpcUa_QualifiedName
 *  "QualifiedName" and the namespace URI as name of the \ref OpcUa_QualifiedName
 *  "QualifiedName".
 *
 *  See also \ref Doc_OpcUa_NamespaceMetadataType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT NamespaceMetadataType:
    public OpcUa::BaseObjectType
{
    UA_DISABLE_COPY(NamespaceMetadataType);
protected:
    virtual ~NamespaceMetadataType();
public:
    // construction / destruction
    NamespaceMetadataType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    NamespaceMetadataType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    NamespaceMetadataType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;

#if SUPPORT_Method_Server_Facet
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
#endif // SUPPORT_Method_Server_Facet


    virtual void setIsNamespaceSubset(OpcUa_Boolean IsNamespaceSubset);
    virtual OpcUa_Boolean getIsNamespaceSubset() const;

    virtual void setNamespacePublicationDate(const UaDateTime& NamespacePublicationDate);
    virtual UaDateTime getNamespacePublicationDate() const;

    virtual void setNamespaceUri(const UaString& NamespaceUri);
    virtual UaString getNamespaceUri() const;

    virtual void setNamespaceVersion(const UaString& NamespaceVersion);
    virtual UaString getNamespaceVersion() const;

    virtual void setStaticNodeIdTypes(const UaInt32Array &StaticNodeIdTypes);
    virtual void getStaticNodeIdTypes(UaInt32Array &StaticNodeIdTypes) const;

    virtual void setStaticNumericNodeIdRange(const UaStringArray& StaticNumericNodeIdRange);
    virtual void getStaticNumericNodeIdRange(UaStringArray& StaticNumericNodeIdRange) const;

    virtual void setStaticStringNodeIdPattern(const UaString& StaticStringNodeIdPattern);
    virtual UaString getStaticStringNodeIdPattern() const;

    virtual OpcUa::PropertyType* getIsNamespaceSubsetNode();
    virtual const OpcUa::PropertyType* getIsNamespaceSubsetNode() const;
#if SUPPORT_Method_Server_Facet
    virtual OpcUa::AddressSpaceFileType* getNamespaceFile();
    virtual const OpcUa::AddressSpaceFileType* getNamespaceFile() const;
#endif // SUPPORT_Method_Server_Facet
    virtual OpcUa::PropertyType* getNamespacePublicationDateNode();
    virtual const OpcUa::PropertyType* getNamespacePublicationDateNode() const;
    virtual OpcUa::PropertyType* getNamespaceUriNode();
    virtual const OpcUa::PropertyType* getNamespaceUriNode() const;
    virtual OpcUa::PropertyType* getNamespaceVersionNode();
    virtual const OpcUa::PropertyType* getNamespaceVersionNode() const;
    virtual OpcUa::PropertyType* getStaticNodeIdTypesNode();
    virtual const OpcUa::PropertyType* getStaticNodeIdTypesNode() const;
    virtual OpcUa::PropertyType* getStaticNumericNodeIdRangeNode();
    virtual const OpcUa::PropertyType* getStaticNumericNodeIdRangeNode() const;
    virtual OpcUa::PropertyType* getStaticStringNodeIdPatternNode();
    virtual const OpcUa::PropertyType* getStaticStringNodeIdPatternNode() const;

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(NamespaceMetadataType *pInstance);

protected:
    // Object nodes
#if SUPPORT_Method_Server_Facet
    // Object NamespaceFile
    static OpcUa::AddressSpaceFileType*  s_pNamespaceFile;
    OpcUa::AddressSpaceFileType*  m_pNamespaceFile;
#endif // SUPPORT_Method_Server_Facet
    // Variable nodes
    // Variable IsNamespaceSubset
    static OpcUa::PropertyType*  s_pIsNamespaceSubset;
    OpcUa::PropertyType*  m_pIsNamespaceSubset;
    // Variable NamespacePublicationDate
    static OpcUa::PropertyType*  s_pNamespacePublicationDate;
    OpcUa::PropertyType*  m_pNamespacePublicationDate;
    // Variable NamespaceUri
    static OpcUa::PropertyType*  s_pNamespaceUri;
    OpcUa::PropertyType*  m_pNamespaceUri;
    // Variable NamespaceVersion
    static OpcUa::PropertyType*  s_pNamespaceVersion;
    OpcUa::PropertyType*  m_pNamespaceVersion;
    // Variable StaticNodeIdTypes
    static OpcUa::PropertyType*  s_pStaticNodeIdTypes;
    OpcUa::PropertyType*  m_pStaticNodeIdTypes;
    // Variable StaticNumericNodeIdRange
    static OpcUa::PropertyType*  s_pStaticNumericNodeIdRange;
    OpcUa::PropertyType*  m_pStaticNumericNodeIdRange;
    // Variable StaticStringNodeIdPattern
    static OpcUa::PropertyType*  s_pStaticStringNodeIdPattern;
    OpcUa::PropertyType*  m_pStaticStringNodeIdPattern;



private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUANAMESPACEMETADATATYPE_H__


