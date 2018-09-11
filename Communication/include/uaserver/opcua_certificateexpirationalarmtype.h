/******************************************************************************
** opcua_certificateexpirationalarmtype.h
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

#ifndef __OPCUA_CERTIFICATEEXPIRATIONALARMTYPE_H__
#define __OPCUA_CERTIFICATEEXPIRATIONALARMTYPE_H__

#include "opcua_systemoffnormalalarmtype.h"
#include "basenodes.h"
#include "opcua_identifiers.h"
#include "opcua_propertytype.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class CertificateExpirationAlarmType;
class PropertyType;

/** Generated event data class for a CertificateExpirationAlarmType.
 *
 *  This class contains the auto generated code for the object type CertificateExpirationAlarmType
 *  providing UaEventData interface for the access to event data containing the current state of the
 *  condition for events sent to the client. The class is used for condition events if the condition has
 *  no nodes in the address space or for condition branches created as snapshot of the main branch.
 *
 *  **Event Fields of the CertificateExpirationAlarmType:**
 *
 *  Browse Name     | DataType   | TypeDefinition | Modelling Rule | See Also
 *  ----------------|------------|----------------|----------------|-------------------------------------------------
 *  Certificate     | ByteString | PropertyType   | Mandatory      | \ref getCertificate, \ref setCertificate
 *  CertificateType | NodeId     | PropertyType   | Mandatory      | \ref getCertificateType, \ref setCertificateType
 *  ExpirationDate  | DateTime   | PropertyType   | Mandatory      | \ref getExpirationDate, \ref setExpirationDate

 *  A SystemOffNormalAlarmType raised by the Server when the Server’s Certificate
 *  is within the ExpirationLimit of expiration.
 *
 *  This alarm automatically returns to normal when the certificate is updated.
 *
 *  See also \ref Doc_OpcUa_CertificateExpirationAlarmType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT CertificateExpirationAlarmTypeData:
    public OpcUa::SystemOffNormalAlarmTypeData
{
    UA_DISABLE_COPY(CertificateExpirationAlarmTypeData);
protected:
    virtual ~CertificateExpirationAlarmTypeData();
public:
    CertificateExpirationAlarmTypeData();
    void initializeAsBranch(CertificateExpirationAlarmType* pCondition);
    void initializeAsBranch(CertificateExpirationAlarmTypeData* pConditionData);
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // Certificate
    void setCertificate(UaByteString& Certificate);
    void setCertificateStatus(OpcUa_StatusCode status);
    UaByteString getCertificate();
    virtual void getCertificateValue(Session* pSession, OpcUa_Variant& value);
    // CertificateType
    void setCertificateType(const UaNodeId& CertificateType);
    void setCertificateTypeStatus(OpcUa_StatusCode status);
    UaNodeId getCertificateType();
    virtual void getCertificateTypeValue(Session* pSession, OpcUa_Variant& value);
    // ExpirationDate
    void setExpirationDate(const UaDateTime& ExpirationDate);
    void setExpirationDateStatus(OpcUa_StatusCode status);
    UaDateTime getExpirationDate();
    virtual void getExpirationDateValue(Session* pSession, OpcUa_Variant& value);


private:
    void initialize();

private:
    UaObjectPointerArray<UaVariant> m_FieldValues;
};


/** @brief Class implementing the UaObject interface for the CertificateExpirationAlarmType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Variable members of the CertificateExpirationAlarmType:**
 *
 *  Browse Name     | DataType   | TypeDefinition | Modelling Rule | See Also
 *  ----------------|------------|----------------|----------------|-------------------------------------------------
 *  Certificate     | ByteString | PropertyType   | Mandatory      | \ref getCertificate, \ref setCertificate
 *  CertificateType | NodeId     | PropertyType   | Mandatory      | \ref getCertificateType, \ref setCertificateType
 *  ExpirationDate  | DateTime   | PropertyType   | Mandatory      | \ref getExpirationDate, \ref setExpirationDate
 *
 *
 *  A SystemOffNormalAlarmType raised by the Server when the Server’s Certificate
 *  is within the ExpirationLimit of expiration.
 *
 *  This alarm automatically returns to normal when the certificate is updated.
 *
 *  See also \ref Doc_OpcUa_CertificateExpirationAlarmType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT CertificateExpirationAlarmType:
    public OpcUa::SystemOffNormalAlarmType
{
    friend class CertificateExpirationAlarmTypeData;
    UA_DISABLE_COPY(CertificateExpirationAlarmType);
protected:
    // destruction
    virtual ~CertificateExpirationAlarmType();
public:
    // construction
    CertificateExpirationAlarmType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    CertificateExpirationAlarmType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    CertificateExpirationAlarmType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    static void createTypes();
    static void clearStaticMembers();
    virtual UaNodeId typeDefinitionId() const;
    static void registerEventFields();
    static OpcUa_UInt32 registerOptionalEventFields(const UaString& fieldName);
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    void clearFieldData();
    UaNodeId createBranch();


    // Certificate
    virtual void setCertificate(UaByteString& Certificate);
    virtual UaByteString getCertificate() const;
    virtual void setCertificateStatus(OpcUa_StatusCode status);
    virtual void getCertificateValue(Session* pSession, UaVariant& value);
    // CertificateType
    virtual void setCertificateType(const UaNodeId& CertificateType);
    virtual UaNodeId getCertificateType() const;
    virtual void setCertificateTypeStatus(OpcUa_StatusCode status);
    virtual void getCertificateTypeValue(Session* pSession, UaVariant& value);
    // ExpirationDate
    virtual void setExpirationDate(const UaDateTime& ExpirationDate);
    virtual UaDateTime getExpirationDate() const;
    virtual void setExpirationDateStatus(OpcUa_StatusCode status);
    virtual void getExpirationDateValue(Session* pSession, UaVariant& value);

    virtual OpcUa::PropertyType* getCertificateNode();
    virtual OpcUa::PropertyType* getCertificateTypeNode();
    virtual OpcUa::PropertyType* getExpirationDateNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(CertificateExpirationAlarmType *pInstance);

    virtual UaStatus triggerEvent(
        const UaDateTime&   time,
        const UaDateTime&   receiveTime,
        const UaByteString& eventId);

    virtual void getCertificateExpirationAlarmTypeOptionalFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

protected:
    // Variable nodes
    // Variable Certificate
    static OpcUa::PropertyType*  s_pCertificate;
    OpcUa::PropertyType*  m_pCertificate;
    // Variable CertificateType
    static OpcUa::PropertyType*  s_pCertificateType;
    OpcUa::PropertyType*  m_pCertificateType;
    // Variable ExpirationDate
    static OpcUa::PropertyType*  s_pExpirationDate;
    OpcUa::PropertyType*  m_pExpirationDate;



private:
    void initialize();
    void createChildren();

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_CertificateExpirationAlarmTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUACERTIFICATEEXPIRATIONALARMTYPE_H__

