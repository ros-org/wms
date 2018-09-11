/******************************************************************************
** opcua_trustlisttype.h
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

#ifndef __OPCUA_TRUSTLISTTYPE_H__
#define __OPCUA_TRUSTLISTTYPE_H__

#include "opcua_trustlisttypebase.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {


/** @brief Class implementing the UaObject interface for the TrustListType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Variable members of the TrustListType:**
 *
 *  Browse Name    | DataType | TypeDefinition | Modelling Rule | See Also
 *  ---------------|----------|----------------|----------------|-----------------------------------------------------------------------------------------------------------------------------
 *  LastUpdateTime | UtcTime  | PropertyType   | Mandatory      | \ref TrustListTypeBase::getLastUpdateTime "getLastUpdateTime", \ref TrustListTypeBase::setLastUpdateTime "setLastUpdateTime"
 *
 *  **Method members of the TrustListType:**
 *
 *  Browse Name            | Modelling Rule
 *  -----------------------|---------------
 *  \ref AddCertificate    | Optional
 *  \ref CloseAndUpdate    | Optional
 *  \ref OpenWithMasks     | Mandatory
 *  \ref RemoveCertificate | Optional
 *
 *  Defines a \ref OpcUa::FileType "FileType" that can be used to access a trust
 *  list.
 *
 *  The CertificateManager uses this type to implement the Pull model.
 *
 *  Servers use this type when implementing the Push model.
 *
 *  An instance of a TrustListType must restrict access to appropriate users or
 *  applications. This may be a CertificateManager administrative user that can
 *  change the contents of a trust list, it may be an administrative user that is
 *  reading a trust list to deploy to an application host, or it may be an
 *  application that can only access the trust list assigned to it.
 *
 *  The trust list file is a UA Binary encoded stream containing an instance of
 *  TrustListDataType.
 *
 *  The Open method shall not support modes other than Read (0x01) and the Write +
 *  EraseExisting (0x06).
 *
 *  When a Client opens the file for writing, the Server will not actually update
 *  the trust list until the \ref OpcUa::TrustListType::CloseAndUpdate
 *  "CloseAndUpdate" Method is called. Simply calling Close will discard the
 *  updates. The bit masks in the TrustListDataType structure allow the Client to
 *  only update part of the trust list.
 *
 *  When the \ref OpcUa::TrustListType::CloseAndUpdate "CloseAndUpdate" method is
 *  called, the Server will validate all new certificates and CRLs. If this
 *  validation fails, the trust list is not updated and the Server returns the
 *  appropriate certificate error code.
 *
 *  If auditing is supported, the CertificateManager shall generate the
 *  TrustListUpdatedAuditEventType when the \ref
 *  OpcUa::TrustListType::CloseAndUpdate "CloseAndUpdate", \ref
 *  OpcUa::TrustListType::AddCertificate "AddCertificate" or \ref
 *  OpcUa::TrustListType::RemoveCertificate "RemoveCertificate" Methods are called.
 *
 *  See also \ref Doc_OpcUa_TrustListType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT TrustListType:
    public TrustListTypeBase
{
    UA_DISABLE_COPY(TrustListType);
protected:
    // destruction
    virtual ~TrustListType();
public:
    // construction
    TrustListType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    TrustListType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    TrustListType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    void setTrustListConfiguration(
        OpcUa_UInt32    nMaxTrustListSize,
        const UaString& sCertificateRevocationListLocation,
        const UaString& sCertificateTrustListLocation,
        const UaString& sIssuersRevocationListLocation,
        const UaString& sIssuersCertificatesLocation);

    // UaFileType method Open
    virtual UaStatus Open(const ServiceContext&  serviceContext, /*IN*/OpcUa_Byte  Mode, /*OUT*/OpcUa_UInt32&  FileHandle);
    // UaFileType method Close
    virtual UaStatus Close(const ServiceContext&  serviceContext, /*IN*/OpcUa_UInt32  FileHandle);

    // UaTrustListType method AddCertificate
    virtual UaStatus AddCertificate(
        const ServiceContext& serviceContext,
        UaByteString& Certificate,
        OpcUa_Boolean IsTrustedCertificate);
    // UaTrustListType method CloseAndUpdate
    virtual UaStatus CloseAndUpdate(
        const ServiceContext& serviceContext,
        OpcUa_UInt32 FileHandle,
        OpcUa_Boolean& ApplyChangesRequired);
    // UaTrustListType method OpenWithMasks
    virtual UaStatus OpenWithMasks(
        const ServiceContext& serviceContext,
        OpcUa_UInt32 Masks,
        OpcUa_UInt32& FileHandle);
    // UaTrustListType method RemoveCertificate
    virtual UaStatus RemoveCertificate(
        const ServiceContext& serviceContext,
        const UaString& Thumbprint,
        OpcUa_Boolean IsTrustedCertificate);

    // override FileType method setFilePath
    bool setFilePath(const UaString& sFilePath);

    // NodeAccessInfo management
    virtual void recursivSetAccessInfo(NodeAccessInfo* pAccessInfo);

protected:
    // Overwrite file access
    UaFile* createFileAccessObject(Session* pSession, const UaString& sFileName);

private:
    OpcUa_UInt32 m_nMaxTrustListSize;
    UaString     m_sCertificateRevocationListLocation;
    UaString     m_sCertificateTrustListLocation;
    UaString     m_sIssuersRevocationListLocation;
    UaString     m_sIssuersCertificatesLocation;
    OpcUa_UInt32 m_writeFileHandle;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUATRUSTLISTTYPE_H__

