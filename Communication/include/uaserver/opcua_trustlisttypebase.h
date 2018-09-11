/******************************************************************************
** opcua_trustlisttypebase.h
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

#ifndef __OPCUA_TRUSTLISTTYPEBASE_H__
#define __OPCUA_TRUSTLISTTYPEBASE_H__

#include "opcua_filetype.h"
#include "basenodes.h"
#include "opcua_identifiers.h"
#include "opcua_propertytype.h"
#include "uaargument.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;

/** Generated base class for a TrustListType.
 *
 *  This class contains the generated base code for the object type TrustListType
 *  representing an OPC UA ObjectType. This class is used to create the object type and to
 *  create and represent instances of the object type in the server address space.
 *
 *  **Variable members of the TrustListType:**
 *
 *  Browse Name    | DataType | TypeDefinition | Modelling Rule | See Also
 *  ---------------|----------|----------------|----------------|-----------------------------------------------
 *  LastUpdateTime | UtcTime  | PropertyType   | Mandatory      | \ref getLastUpdateTime, \ref setLastUpdateTime
 *
 *  Defines a \ref OpcUa::FileType "FileType" that can be used to access a trust
 *  list.
 *
 *  The CertificateManager uses this type to implement the Pull Model.
 *
 *  Servers use this type when implementing the Push Model.
 *
 *  An instance of a TrustListType must restrict access to appropriate users or
 *  applications. This may be a CertificateManager administrative user that can
 *  change the contents of a trust list, it may be an administrative user that is
 *  reading a trust list to deploy to an application host or it may be an
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
 *  "CloseAndUpdate" method is called. Simply calling Close will discard the
 *  updates. The bit masks in the TrustListDataType structure allow the Client to
 *  only update part of the trust list.
 *
 *  When the \ref OpcUa::TrustListType::CloseAndUpdate "CloseAndUpdate" method is
 *  called, the Server will validate all new Certificates and CRLs. If this
 *  validation fails, the trust list is not updated and the Server returns the
 *  appropriate certificate error code.
 *
 *  If auditing is supported, the CertificateManager shall generate the
 *  TrustListUpdatedAuditEventType when the \ref
 *  OpcUa::TrustListType::CloseAndUpdate "CloseAndUpdate", \ref
 *  OpcUa::TrustListType::AddCertificate "AddCertificate" or \ref
 *  OpcUa::TrustListType::RemoveCertificate "RemoveCertificate" methods are called.
 *
 *  See also \ref Doc_OpcUa_TrustListType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT TrustListTypeBase:
    public OpcUa::FileType
{
    UA_DISABLE_COPY(TrustListTypeBase);
protected:
    virtual ~TrustListTypeBase();
public:
    // construction / destruction
    TrustListTypeBase(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    TrustListTypeBase(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    TrustListTypeBase(
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


    /**
     *  Allows a Client to add a single certificate to the trust list.
     *
     *  The Server shall verify that the certificate is valid according to the
     *  mandatory rules defined in Part 4 of the OPC UA Specification. If an invalid
     *  certificate is found, the Server shall return an error and shall not update the
     *  trust list.
     *
     *  This method cannot be called if the file object is open.
     *
     *  <b>Method Result Codes</b>
     *
     *  Result Code             | Description
     *  ------------------------|-----------------------------------------------------
     *  Bad_UserAccessDenied    | The current user does not have the rights required.
     *  Bad_CertificateInvalid  | The certificate to add is invalid.
     *  Bad_InvalidState        | The object is opened.
     */
    virtual UaStatus AddCertificate(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        UaByteString& Certificate /**<[in] The DER encoded certificate to add. */,
        OpcUa_Boolean IsTrustedCertificate /**<[in] If TRUE, the certificate is added to the trusted certificate s list.
            <br>
            If FALSE, the certificate is added to the Issuer certificate s list. */) = 0;

    /**
     *  Closes the file and applies the changes to the trust list.
     *
     *  This method can only be called if the file was opened for writing. If the Close
     *  method is called, any cached data is discarded and the trust list is not
     *  changed.
     *
     *  The Server shall verify that every certificate in the new trust list is valid
     *  according to the mandatory rules defined in Part 4 of the OPC UA Specification.
     *  If an invalid certificate is found, the Server shall return an error and shall
     *  not update the trust list. If only part of the trust list is being updated, the
     *  Server creates a temporary trust list that includes the existing trust list
     *  plus any updates and validates the temporary trust list.
     *
     *  If the file cannot be processed, this method still closes the file and discards
     *  the data before returning an error. This method is required if the Server
     *  supports updates to the trust list.
     *
     *  The structure uploaded includes a mask that specifies which fields are updated.
     *  If a bit is not set, the associated field is not changed.
     *
     *  <b>Method Result Codes</b>
     *
     *  Result Code             | Description
     *  ------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------
     *  Bad_UserAccessDenied    | The current user does not have the rights required.
     *  Bad_CertificateInvalid  | The Server could not validate all certificate s in the trust list. The DiagnosticInfo shall specify which certificate (s) are invalid and the specific error.
     */
    virtual UaStatus CloseAndUpdate(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        OpcUa_UInt32 FileHandle /**<[in] The handle of the previously opened file. */,
        OpcUa_Boolean& ApplyChangesRequired /**<[out] A flag indicating whether the \ref OpcUa::ServerConfigurationType::ApplyChanges
            "ApplyChanges" method must be called before the new trust list will be used by
            the Server. */) = 0;

    /**
     *  Allows a Client to read only the portion of the trust list.
     *
     *  This method can only be used to read the trust list.
     *
     *  <b>Method Result Codes</b>
     *
     *  Result Code           | Description
     *  ----------------------|-----------------------------------------------------
     *  Bad_UserAccessDenied  | The current user does not have the rights required.
     */
    virtual UaStatus OpenWithMasks(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        OpcUa_UInt32 Masks /**<[in] The parts of the trust list that are to be included in the file to read. */,
        OpcUa_UInt32& FileHandle /**<[out] The handle of the newly opened file. */) = 0;

    /**
     *  Allows a Client to remove a single certificate from the trust list.
     *
     *  This method returns Bad_InvalidArgument if the thumbprint does not match a
     *  certificate in the trust list.
     *
     *  This method cannot be called if the file object is open.
     *
     *  <b>Method Result Codes</b>
     *
     *  Result Code           | Description
     *  ----------------------|-----------------------------------------------------
     *  Bad_UserAccessDenied  | The current user does not have the rights required.
     *  Bad_InvalidArgument   | The certificate to remove was not found.
     *  Bad_InvalidState      | The object is opened.
     */
    virtual UaStatus RemoveCertificate(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        const UaString& Thumbprint /**<[in] The SHA1 hash of the certificate to remove. */,
        OpcUa_Boolean IsTrustedCertificate /**<[in] If TRUE, the certificate is removed from the trusted certificate s list.
            <br>
            If FALSE, the certificate is removed from the Issuer certificate s list. */) = 0;

    virtual void setLastUpdateTime(const UaDateTime& LastUpdateTime);
    virtual UaDateTime getLastUpdateTime() const;

    virtual OpcUa::PropertyType* getLastUpdateTimeNode();
    virtual OpcUa::BaseMethod* getAddCertificate();
    virtual OpcUa::BaseMethod* getCloseAndUpdate();
    virtual OpcUa::BaseMethod* getOpenWithMasks();
    virtual OpcUa::BaseMethod* getRemoveCertificate();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(TrustListTypeBase *pInstance);

protected:
    // Variable nodes
    // Variable LastUpdateTime
    static OpcUa::PropertyType*  s_pLastUpdateTime;
    OpcUa::PropertyType*  m_pLastUpdateTime;


    // Method nodes
    static OpcUa::BaseMethod* s_pAddCertificateMethod;
    OpcUa::BaseMethod*  m_pAddCertificateMethod;
    static OpcUa::BaseMethod* s_pCloseAndUpdateMethod;
    OpcUa::BaseMethod*  m_pCloseAndUpdateMethod;
    static OpcUa::BaseMethod* s_pOpenWithMasksMethod;
    OpcUa::BaseMethod*  m_pOpenWithMasksMethod;
    static OpcUa::BaseMethod* s_pRemoveCertificateMethod;
    OpcUa::BaseMethod*  m_pRemoveCertificateMethod;


private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUATRUSTLISTTYPEBASE_H__


