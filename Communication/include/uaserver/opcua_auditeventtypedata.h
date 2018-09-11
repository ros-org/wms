/******************************************************************************
** opcua_auditeventtypedata.h
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

#ifndef __OPCUA_AUDITEVENTTYPE_H__
#define __OPCUA_AUDITEVENTTYPE_H__

#include "uaeventdata.h"
#include "basenodes.h"
#include "opcua_finitetransitionvariabletype.h"
#include "opcua_identifiers.h"
#include "opcua_propertytype.h"
#include "uaaddnodesitem.h"
#include "uaaddreferencesitem.h"
#include "uadeletenodesitem.h"
#include "uadeletereferencesitem.h"
#if SUPPORT_Event_Subscription_Server_Facet
#include "uaeventfilter.h"
#endif // SUPPORT_Event_Subscription_Server_Facet
#if SUPPORT_Historical_Access
#include "uahistoryeventfieldlist.h"
#endif // SUPPORT_Historical_Access
#include "uasignedsoftwarecertificate.h"
#include "uauseridentitytoken.h"

#if SUPPORT_Auditing_Server_Facet

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class FiniteTransitionVariableType;
class PropertyType;

/** Event data class for the OPC UA event type AuditEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditEventType:**
 *
 *  Browse Name        | DataType | TypeDefinition | Modelling Rule | See Also
 *  -------------------|----------|----------------|----------------|-------------------------------------------------------
 *  ActionTimeStamp    | UtcTime  | PropertyType   | Mandatory      | \ref getActionTimeStamp, \ref setActionTimeStamp
 *  ClientAuditEntryId | String   | PropertyType   | Mandatory      | \ref getClientAuditEntryId, \ref setClientAuditEntryId
 *  ClientUserId       | String   | PropertyType   | Mandatory      | \ref getClientUserId, \ref setClientUserId
 *  ServerId           | String   | PropertyType   | Mandatory      | \ref getServerId, \ref setServerId
 *  Status             | Boolean  | PropertyType   | Mandatory      | \ref getStatus, \ref setStatus

 *  OPC UA includes support for security audit trails with traceability between
 *  Client and Server audit logs. OPC UA defines audit events for security related
 *  client actions, like creating a connection with a server, and also audit events
 *  for actions changing the system, like write calls to variables or method calls.
 *  If a security-related problem is detected at the Server, the associated Client
 *  audit log entry can be located and examined. OPC UA also provides the
 *  capability for Servers to generate Event Notifications that report auditable
 *  Events to Clients capable of processing and logging them. OPC UA defines
 *  security audit parameters that can be included in audit log entries and in
 *  audit Event Notifications.
 *
 *  AuditEvents are Events of AuditEventType or subtypes that are generated as a
 *  result of an action taken on the Server by a Client of the Server. For example,
 *  in response to a Client issuing a write to a Variable, the Server would
 *  generate an AuditEvent describing the Variable as the source and the user and
 *  Client session as the initiators of the Event.
 *
 *  OPC UA Servers create audit events for an auditable action request. If the
 *  action is accepted, then an action AuditEvent is generated and processed by the
 *  Server. If the action is not accepted due to security reasons, a security
 *  AuditEvent is generated and processed by the Server. The Server may involve the
 *  underlying device or system in the process, but it is the Server’s
 *  responsibility to provide the Event to any interested Clients. Clients are free
 *  to subscribe to Events from the Server and will receive the AuditEvents in
 *  response to normal Publish requests.
 *
 *  See also \ref Doc_OpcUa_AuditEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditEventTypeData:
    public BaseEventTypeData
{
    UA_DISABLE_COPY(AuditEventTypeData);
public:
    AuditEventTypeData();
    virtual ~AuditEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // ActionTimeStamp
    void setActionTimeStamp(const UaDateTime& ActionTimeStamp);
    void setActionTimeStampStatus(OpcUa_StatusCode status);
    UaDateTime getActionTimeStamp();
    virtual void getActionTimeStampValue(Session* pSession, OpcUa_Variant& value);
    // ClientAuditEntryId
    void setClientAuditEntryId(const UaString& ClientAuditEntryId);
    void setClientAuditEntryIdStatus(OpcUa_StatusCode status);
    UaString getClientAuditEntryId();
    virtual void getClientAuditEntryIdValue(Session* pSession, OpcUa_Variant& value);
    // ClientUserId
    void setClientUserId(const UaString& ClientUserId);
    void setClientUserIdStatus(OpcUa_StatusCode status);
    UaString getClientUserId();
    virtual void getClientUserIdValue(Session* pSession, OpcUa_Variant& value);
    // ServerId
    void setServerId(const UaString& ServerId);
    void setServerIdStatus(OpcUa_StatusCode status);
    UaString getServerId();
    virtual void getServerIdValue(Session* pSession, OpcUa_Variant& value);
    // Status
    void setStatus(OpcUa_Boolean Status);
    void setStatusStatus(OpcUa_StatusCode status);
    OpcUa_Boolean getStatus();
    virtual void getStatusValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditNodeManagementEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditNodeManagementEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().

 *  This is a subtype of \ref OpcUa::AuditEventTypeData "AuditEventTypeData" and is
 *  used for categorization of node management related Events. This type follows
 *  all behaviours of its parent type.
 *
 *  This EventType inherits all Properties of the \ref OpcUa::AuditEventTypeData
 *  "AuditEventTypeData". There are no additional Properties defined for this
 *  EventType. The SourceNode for Events of this type should be assigned to the
 *  Server object. The SourceName for Events of this type should be
 *  “NodeManagement/” and the Service that generates the Event (e.g. AddNodes,
 *  AddReferences, DeleteNodes, DeleteReferences).
 *
 *  See also \ref Doc_OpcUa_AuditNodeManagementEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditNodeManagementEventTypeData:
    public OpcUa::AuditEventTypeData
{
    UA_DISABLE_COPY(AuditNodeManagementEventTypeData);
public:
    AuditNodeManagementEventTypeData();
    virtual ~AuditNodeManagementEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditNodeManagementEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditAddNodesEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditAddNodesEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditAddNodesEventType:**
 *
 *  Browse Name | DataType     | TypeDefinition | Modelling Rule | See Also
 *  ------------|--------------|----------------|----------------|---------------------------------------
 *  NodesToAdd  | AddNodesItem | PropertyType   | Mandatory      | \ref getNodesToAdd, \ref setNodesToAdd

 *  This is a subtype of \ref OpcUa::AuditNodeManagementEventTypeData
 *  "AuditNodeManagementEventTypeData" and is used for Events generated from
 *  calling the AddNodes Service defined in Part 4 of the OPC UA Specification.
 *
 *  This EventType inherits all Properties of the \ref
 *  OpcUa::AuditNodeManagementEventTypeData "AuditNodeManagementEventTypeData". The
 *  SourceName for Events of this type should be “NodeManagement/AddNodes”.
 *
 *  The additional Properties defined for this EventType reflect parameters of the
 *  Service call that triggers the Event.
 *
 *  See also \ref Doc_OpcUa_AuditAddNodesEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditAddNodesEventTypeData:
    public OpcUa::AuditNodeManagementEventTypeData
{
    UA_DISABLE_COPY(AuditAddNodesEventTypeData);
public:
    AuditAddNodesEventTypeData();
    virtual ~AuditAddNodesEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // NodesToAdd
    void setNodesToAdd(const UaAddNodesItems& NodesToAdd);
    void setNodesToAddStatus(OpcUa_StatusCode status);
    void getNodesToAdd(UaAddNodesItems& NodesToAdd);
    virtual void getNodesToAddValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditAddNodesEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditAddReferencesEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditAddReferencesEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditAddReferencesEventType:**
 *
 *  Browse Name     | DataType          | TypeDefinition | Modelling Rule | See Also
 *  ----------------|-------------------|----------------|----------------|-------------------------------------------------
 *  ReferencesToAdd | AddReferencesItem | PropertyType   | Mandatory      | \ref getReferencesToAdd, \ref setReferencesToAdd

 *  This is a subtype of \ref OpcUa::AuditNodeManagementEventTypeData
 *  "AuditNodeManagementEventTypeData" and is used for Events generated from
 *  calling the AddReferences Service defined in Part 4 of the OPC UA
 *  Specification.
 *
 *  This EventType inherits all Properties of the \ref
 *  OpcUa::AuditNodeManagementEventTypeData "AuditNodeManagementEventTypeData".
 *
 *  The SourceName for Events of this type should be
 *  “NodeManagement/AddReferences”.
 *
 *  The additional Properties defined for this EventType reflect parameters of the
 *  Service call that triggers the Event.
 *
 *  See also \ref Doc_OpcUa_AuditAddReferencesEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditAddReferencesEventTypeData:
    public OpcUa::AuditNodeManagementEventTypeData
{
    UA_DISABLE_COPY(AuditAddReferencesEventTypeData);
public:
    AuditAddReferencesEventTypeData();
    virtual ~AuditAddReferencesEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // ReferencesToAdd
    void setReferencesToAdd(const UaAddReferencesItems& ReferencesToAdd);
    void setReferencesToAddStatus(OpcUa_StatusCode status);
    void getReferencesToAdd(UaAddReferencesItems& ReferencesToAdd);
    virtual void getReferencesToAddValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditAddReferencesEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditDeleteNodesEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditDeleteNodesEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditDeleteNodesEventType:**
 *
 *  Browse Name   | DataType        | TypeDefinition | Modelling Rule | See Also
 *  --------------|-----------------|----------------|----------------|---------------------------------------------
 *  NodesToDelete | DeleteNodesItem | PropertyType   | Mandatory      | \ref getNodesToDelete, \ref setNodesToDelete

 *  This is a subtype of \ref OpcUa::AuditNodeManagementEventTypeData
 *  "AuditNodeManagementEventTypeData" and is used for Events generated from
 *  calling the DeleteNodes Service defined in Part 4 of the OPC UA Specification.
 *
 *  This EventType inherits all Properties of the AuditNodeManagementEventType. The
 *  SourceName for Events of this type should be “NodeManagement/DeleteNodes”.
 *
 *  The additional Properties defined for this EventType reflect parameters of the
 *  Service call that triggers the Event.
 *
 *  See also \ref Doc_OpcUa_AuditDeleteNodesEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditDeleteNodesEventTypeData:
    public OpcUa::AuditNodeManagementEventTypeData
{
    UA_DISABLE_COPY(AuditDeleteNodesEventTypeData);
public:
    AuditDeleteNodesEventTypeData();
    virtual ~AuditDeleteNodesEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // NodesToDelete
    void setNodesToDelete(const UaDeleteNodesItems& NodesToDelete);
    void setNodesToDeleteStatus(OpcUa_StatusCode status);
    void getNodesToDelete(UaDeleteNodesItems& NodesToDelete);
    virtual void getNodesToDeleteValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditDeleteNodesEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditDeleteReferencesEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditDeleteReferencesEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditDeleteReferencesEventType:**
 *
 *  Browse Name        | DataType             | TypeDefinition | Modelling Rule | See Also
 *  -------------------|----------------------|----------------|----------------|-------------------------------------------------------
 *  ReferencesToDelete | DeleteReferencesItem | PropertyType   | Mandatory      | \ref getReferencesToDelete, \ref setReferencesToDelete

 *  This is a subtype of \ref OpcUa::AuditNodeManagementEventTypeData
 *  "AuditNodeManagementEventTypeData" and is used for Events generated from
 *  calling the DeleteReferences Service defined in Part 4 of the OPC UA
 *  Specification.
 *
 *  This EventType inherits all Properties of the \ref
 *  OpcUa::AuditNodeManagementEventTypeData "AuditNodeManagementEventTypeData". The
 *  SourceName for Events of this type should be “NodeManagement/DeleteReferences”.
 *
 *  The additional Properties defined for this EventType reflect parameters of the
 *  Service call that triggers the Event.
 *
 *  See also \ref Doc_OpcUa_AuditDeleteReferencesEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditDeleteReferencesEventTypeData:
    public OpcUa::AuditNodeManagementEventTypeData
{
    UA_DISABLE_COPY(AuditDeleteReferencesEventTypeData);
public:
    AuditDeleteReferencesEventTypeData();
    virtual ~AuditDeleteReferencesEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // ReferencesToDelete
    void setReferencesToDelete(const UaDeleteReferencesItems& ReferencesToDelete);
    void setReferencesToDeleteStatus(OpcUa_StatusCode status);
    void getReferencesToDelete(UaDeleteReferencesItems& ReferencesToDelete);
    virtual void getReferencesToDeleteValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditDeleteReferencesEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditSecurityEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditSecurityEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().

 *  This EventType is a subtype of \ref OpcUa::AuditEventTypeData
 *  "AuditEventTypeData" and is used only for categorization of security-related
 *  Events. This type follows all behaviour of its parent type.
 *
 *  There are no additional Properties defined for this EventType.
 *
 *  See also \ref Doc_OpcUa_AuditSecurityEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditSecurityEventTypeData:
    public OpcUa::AuditEventTypeData
{
    UA_DISABLE_COPY(AuditSecurityEventTypeData);
public:
    AuditSecurityEventTypeData();
    virtual ~AuditSecurityEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditSecurityEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditCertificateEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditCertificateEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditCertificateEventType:**
 *
 *  Browse Name | DataType   | TypeDefinition | Modelling Rule | See Also
 *  ------------|------------|----------------|----------------|-----------------------------------------
 *  Certificate | ByteString | PropertyType   | Mandatory      | \ref getCertificate, \ref setCertificate

 *  This is a subtype of \ref OpcUa::AuditSecurityEventTypeData
 *  "AuditSecurityEventTypeData" and is used only for categorization of certificate
 *  related Events. This type follows all behaviours of its parent type. These
 *  AuditEvents will be generated for certificate errors in addition to other
 *  AuditEvents related to service calls.
 *
 *  This EventType inherits all Properties of the AuditSecurityEventType. The
 *  SourceName for Events of this type should be “Security/Certificate”.
 *
 *  See also \ref Doc_OpcUa_AuditCertificateEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditCertificateEventTypeData:
    public OpcUa::AuditSecurityEventTypeData
{
    UA_DISABLE_COPY(AuditCertificateEventTypeData);
public:
    AuditCertificateEventTypeData();
    virtual ~AuditCertificateEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // Certificate
    void setCertificate(UaByteString& Certificate);
    void setCertificateStatus(OpcUa_StatusCode status);
    UaByteString getCertificate();
    virtual void getCertificateValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditCertificateEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditCertificateDataMismatchEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditCertificateDataMismatchEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditCertificateDataMismatchEventType:**
 *
 *  Browse Name     | DataType | TypeDefinition | Modelling Rule | See Also
 *  ----------------|----------|----------------|----------------|-------------------------------------------------
 *  InvalidHostname | String   | PropertyType   | Mandatory      | \ref getInvalidHostname, \ref setInvalidHostname
 *  InvalidUri      | String   | PropertyType   | Mandatory      | \ref getInvalidUri, \ref setInvalidUri

 *  This is a subtype of \ref OpcUa::AuditCertificateEventTypeData
 *  "AuditCertificateEventTypeData" and is used only for categorization of
 *  certificate related Events. This type follows all behaviours of its parent
 *  type. This AuditEvent is generated if the HostName in the URL used to connect
 *  to the Server is not the same as one of the HostNames specified in the
 *  certificate, or if the application and Software certificates contain an
 *  application or product URI that does not match the URI specified in the
 *  ApplicationDescription provided with the certificate. For more details on
 *  certificates see Part 4 of the OPC UA Specification.
 *
 *  This EventType inherits all Properties of the \ref
 *  OpcUa::AuditCertificateEventTypeData "AuditCertificateEventTypeData". The
 *  SourceName for Events of this type should be “Security/Certificate”.
 *
 *  See also \ref Doc_OpcUa_AuditCertificateDataMismatchEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditCertificateDataMismatchEventTypeData:
    public OpcUa::AuditCertificateEventTypeData
{
    UA_DISABLE_COPY(AuditCertificateDataMismatchEventTypeData);
public:
    AuditCertificateDataMismatchEventTypeData();
    virtual ~AuditCertificateDataMismatchEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // InvalidHostname
    void setInvalidHostname(const UaString& InvalidHostname);
    void setInvalidHostnameStatus(OpcUa_StatusCode status);
    UaString getInvalidHostname();
    virtual void getInvalidHostnameValue(Session* pSession, OpcUa_Variant& value);
    // InvalidUri
    void setInvalidUri(const UaString& InvalidUri);
    void setInvalidUriStatus(OpcUa_StatusCode status);
    UaString getInvalidUri();
    virtual void getInvalidUriValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditCertificateDataMismatchEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditCertificateExpiredEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditCertificateExpiredEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().

 *  This is a subtype of \ref OpcUa::AuditCertificateEventTypeData
 *  "AuditCertificateEventTypeData" and is used only for categorization of
 *  certificate related Events. This type follows all behaviours of its parent
 *  type. This AuditEvent is generated if the current time is outside the validity
 *  period’s start date and end date.
 *
 *  This EventType inherits all Properties of the AuditCertificateEventType. The
 *  SourceName for Events of this type should be “Security/Certificate”. The
 *  Message Variable shall include a description of why the certificate was expired
 *  (i.e. time before start or time after end). There are no additional Properties
 *  defined for this EventType.
 *
 *  See also \ref Doc_OpcUa_AuditCertificateExpiredEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditCertificateExpiredEventTypeData:
    public OpcUa::AuditCertificateEventTypeData
{
    UA_DISABLE_COPY(AuditCertificateExpiredEventTypeData);
public:
    AuditCertificateExpiredEventTypeData();
    virtual ~AuditCertificateExpiredEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditCertificateExpiredEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditCertificateInvalidEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditCertificateInvalidEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().

 *  This is a subtype of \ref OpcUa::AuditCertificateEventTypeData
 *  "AuditCertificateEventTypeData" and is used only for categorization of
 *  certificate related Events. This type follows all behaviours of its parent
 *  type. This AuditEvent is generated if the certificate structure is invalid or
 *  if the certificate has an invalid signature.
 *
 *  This EventType inherits all Properties of the \ref
 *  OpcUa::AuditCertificateEventTypeData "AuditCertificateEventTypeData". The
 *  SourceName for Events of this type should be “Security/Certificate”. The
 *  Message shall include a description of why the certificate is invalid. There
 *  are no additional Properties defined for this EventType.
 *
 *  See also \ref Doc_OpcUa_AuditCertificateInvalidEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditCertificateInvalidEventTypeData:
    public OpcUa::AuditCertificateEventTypeData
{
    UA_DISABLE_COPY(AuditCertificateInvalidEventTypeData);
public:
    AuditCertificateInvalidEventTypeData();
    virtual ~AuditCertificateInvalidEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditCertificateInvalidEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditCertificateMismatchEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditCertificateMismatchEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().

 *  This is a subtype of \ref OpcUa::AuditCertificateEventTypeData
 *  "AuditCertificateEventTypeData" and is used only for categorization of
 *  certificate related Events. This type follows all behaviours of its parent
 *  type. This AuditEvent is generated if a certificate set of uses does not match
 *  the requested use for the certificate (i.e. application, Software or
 *  Certificate Authority).
 *
 *  This EventType inherits all Properties of the \ref
 *  OpcUa::AuditCertificateEventTypeData "AuditCertificateEventTypeData". The
 *  SourceName for Events of this type should be “Security/Certificate”. The
 *  Message Variable shall include a description of the misuse of the certificate.
 *  There are no additional Properties defined for this EventType.
 *
 *  See also \ref Doc_OpcUa_AuditCertificateMismatchEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditCertificateMismatchEventTypeData:
    public OpcUa::AuditCertificateEventTypeData
{
    UA_DISABLE_COPY(AuditCertificateMismatchEventTypeData);
public:
    AuditCertificateMismatchEventTypeData();
    virtual ~AuditCertificateMismatchEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditCertificateMismatchEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditCertificateRevokedEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditCertificateRevokedEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().

 *  This is a subtype of \ref OpcUa::AuditCertificateEventTypeData
 *  "AuditCertificateEventTypeData" and is used only for categorization of
 *  certificate related Events. This type follows all behaviours of its parent
 *  type. This AuditEvent is generated if a certificate has been revoked or if the
 *  revocation list is not available (i.e. a network interruption prevents the
 *  application from accessing the list).
 *
 *  This EventType inherits all Properties of the \ref
 *  OpcUa::AuditCertificateEventTypeData "AuditCertificateEventTypeData". The
 *  SourceName for Events of this type should be “Security/Certificate”. The
 *  Message Variable shall include a description of why the certificate is revoked
 *  (was the revocation list unavailable or was the certificate on the list). There
 *  are no additional Properties defined for this EventType.
 *
 *  See also \ref Doc_OpcUa_AuditCertificateRevokedEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditCertificateRevokedEventTypeData:
    public OpcUa::AuditCertificateEventTypeData
{
    UA_DISABLE_COPY(AuditCertificateRevokedEventTypeData);
public:
    AuditCertificateRevokedEventTypeData();
    virtual ~AuditCertificateRevokedEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditCertificateRevokedEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditCertificateUntrustedEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditCertificateUntrustedEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().

 *  This is a subtype of \ref OpcUa::AuditCertificateEventTypeData
 *  "AuditCertificateEventTypeData" and is used only for categorization of
 *  certificate related Events. This type follows all behaviours of its parent
 *  type. This AuditEvent is generated if the certificate is not trusted, that is,
 *  if the Issuer certificate is unknown.
 *
 *  This EventType inherits all Properties of the \ref
 *  OpcUa::AuditCertificateEventTypeData "AuditCertificateEventTypeData". The
 *  SourceName for Events of this type should be “Security/Certificate”. The
 *  Message Variable shall include a description of why the certificate is not
 *  trusted. If a trust chain is involved, then the certificate that failed in the
 *  trust chain should be described. There are no additional Properties defined for
 *  this EventType.
 *
 *  See also \ref Doc_OpcUa_AuditCertificateUntrustedEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditCertificateUntrustedEventTypeData:
    public OpcUa::AuditCertificateEventTypeData
{
    UA_DISABLE_COPY(AuditCertificateUntrustedEventTypeData);
public:
    AuditCertificateUntrustedEventTypeData();
    virtual ~AuditCertificateUntrustedEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditCertificateUntrustedEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditChannelEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditChannelEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditChannelEventType:**
 *
 *  Browse Name     | DataType | TypeDefinition | Modelling Rule | See Also
 *  ----------------|----------|----------------|----------------|-------------------------------------------------
 *  SecureChannelId | String   | PropertyType   | Mandatory      | \ref getSecureChannelId, \ref setSecureChannelId

 *  This is a subtype of \ref OpcUa::AuditSecurityEventTypeData
 *  "AuditSecurityEventTypeData" and is used for categorization of security-related
 *  Events from the SecureChannel Service Set defined in Part 4 of the OPC UA
 *  Specification.
 *
 *  This EventType inherits all Properties of the \ref
 *  OpcUa::AuditSecurityEventTypeData "AuditSecurityEventTypeData". SourceNode for
 *  Events of this type should be assigned to the Server object. The SourceName for
 *  Events of this type should be “SecureChannel/” followed by the Service that
 *  generates the Event (e.g. SecureChannel/OpenSecureChannel or
 *  SecureChannel/CloseSecureChannel). If the ClientUserId is not available for a
 *  CloseSecureChannel call, then this parameter shall be set to
 *  “System/CloseSecureChannel”.
 *
 *  See also \ref Doc_OpcUa_AuditChannelEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditChannelEventTypeData:
    public OpcUa::AuditSecurityEventTypeData
{
    UA_DISABLE_COPY(AuditChannelEventTypeData);
public:
    AuditChannelEventTypeData();
    virtual ~AuditChannelEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // SecureChannelId
    void setSecureChannelId(const UaString& SecureChannelId);
    void setSecureChannelIdStatus(OpcUa_StatusCode status);
    UaString getSecureChannelId();
    virtual void getSecureChannelIdValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditChannelEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditOpenSecureChannelEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditOpenSecureChannelEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditOpenSecureChannelEventType:**
 *
 *  Browse Name                 | DataType                 | TypeDefinition | Modelling Rule | See Also
 *  ----------------------------|--------------------------|----------------|----------------|-------------------------------------------------------------------------
 *  ClientCertificate           | ByteString               | PropertyType   | Mandatory      | \ref getClientCertificate, \ref setClientCertificate
 *  ClientCertificateThumbprint | String                   | PropertyType   | Mandatory      | \ref getClientCertificateThumbprint, \ref setClientCertificateThumbprint
 *  RequestedLifetime           | Duration                 | PropertyType   | Mandatory      | \ref getRequestedLifetime, \ref setRequestedLifetime
 *  RequestType                 | SecurityTokenRequestType | PropertyType   | Mandatory      | \ref getRequestType, \ref setRequestType
 *  SecurityMode                | MessageSecurityMode      | PropertyType   | Mandatory      | \ref getSecurityMode, \ref setSecurityMode
 *  SecurityPolicyUri           | String                   | PropertyType   | Mandatory      | \ref getSecurityPolicyUri, \ref setSecurityPolicyUri

 *  This is a subtype of \ref OpcUa::AuditChannelEventTypeData
 *  "AuditChannelEventTypeData" and is used for Events generated from calling the
 *  OpenSecureChannel Service defined in Part 4 of the OPC UA Specification.
 *
 *  This EventType inherits all Properties of the \ref
 *  OpcUa::AuditChannelEventTypeData "AuditChannelEventTypeData". SourceName for
 *  Events of this type should be “SecureChannel/OpenSecureChannel”. The
 *  ClientUserId is not available for this call, thus this parameter shall be set
 *  to “System/OpenSecureChannel”. The additional Properties defined for this
 *  EventType reflect parameters of the Service call that triggers the Event.
 *
 *  See also \ref Doc_OpcUa_AuditOpenSecureChannelEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditOpenSecureChannelEventTypeData:
    public OpcUa::AuditChannelEventTypeData
{
    UA_DISABLE_COPY(AuditOpenSecureChannelEventTypeData);
public:
    AuditOpenSecureChannelEventTypeData();
    virtual ~AuditOpenSecureChannelEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // ClientCertificate
    void setClientCertificate(UaByteString& ClientCertificate);
    void setClientCertificateStatus(OpcUa_StatusCode status);
    UaByteString getClientCertificate();
    virtual void getClientCertificateValue(Session* pSession, OpcUa_Variant& value);
    // ClientCertificateThumbprint
    void setClientCertificateThumbprint(const UaString& ClientCertificateThumbprint);
    void setClientCertificateThumbprintStatus(OpcUa_StatusCode status);
    UaString getClientCertificateThumbprint();
    virtual void getClientCertificateThumbprintValue(Session* pSession, OpcUa_Variant& value);
    // RequestedLifetime
    void setRequestedLifetime(OpcUa_Double RequestedLifetime);
    void setRequestedLifetimeStatus(OpcUa_StatusCode status);
    OpcUa_Double getRequestedLifetime();
    virtual void getRequestedLifetimeValue(Session* pSession, OpcUa_Variant& value);
    // RequestType
    void setRequestType(OpcUa_SecurityTokenRequestType RequestType);
    void setRequestTypeStatus(OpcUa_StatusCode status);
    OpcUa_SecurityTokenRequestType getRequestType();
    virtual void getRequestTypeValue(Session* pSession, OpcUa_Variant& value);
    // SecurityMode
    void setSecurityMode(OpcUa_MessageSecurityMode SecurityMode);
    void setSecurityModeStatus(OpcUa_StatusCode status);
    OpcUa_MessageSecurityMode getSecurityMode();
    virtual void getSecurityModeValue(Session* pSession, OpcUa_Variant& value);
    // SecurityPolicyUri
    void setSecurityPolicyUri(const UaString& SecurityPolicyUri);
    void setSecurityPolicyUriStatus(OpcUa_StatusCode status);
    UaString getSecurityPolicyUri();
    virtual void getSecurityPolicyUriValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditOpenSecureChannelEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditSessionEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditSessionEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditSessionEventType:**
 *
 *  Browse Name | DataType | TypeDefinition | Modelling Rule | See Also
 *  ------------|----------|----------------|----------------|-------------------------------------
 *  SessionId   | NodeId   | PropertyType   | Mandatory      | \ref getSessionId, \ref setSessionId

 *  This is a subtype of \ref OpcUa::AuditSecurityEventTypeData
 *  "AuditSecurityEventTypeData" and is used for categorization of security-related
 *  Events from the Session Service Set defined in Part 4 of the OPC UA
 *  Specification.
 *
 *  This EventType inherits all Properties of the \ref
 *  OpcUa::AuditSecurityEventTypeData "AuditSecurityEventTypeData".
 *
 *  If the Event is generated by a TransferSubscriptions Service call, the
 *  SourceNode should be assigned to the SessionDiagnostics object that represents
 *  the session. The SourceName for Events of this type should be
 *  “Session/TransferSubscriptions”.
 *
 *  Otherwise, the SourceNode for Events of this type should be assigned to the
 *  Server object. The SourceName for Events of this type should be “Session/” and
 *  the Service that generates the Event (e.g. CreateSession, ActivateSession or
 *  CloseSession).
 *
 *  See also \ref Doc_OpcUa_AuditSessionEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditSessionEventTypeData:
    public OpcUa::AuditSecurityEventTypeData
{
    UA_DISABLE_COPY(AuditSessionEventTypeData);
public:
    AuditSessionEventTypeData();
    virtual ~AuditSessionEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // SessionId
    void setSessionId(const UaNodeId& SessionId);
    void setSessionIdStatus(OpcUa_StatusCode status);
    UaNodeId getSessionId();
    virtual void getSessionIdValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditSessionEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditActivateSessionEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditActivateSessionEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditActivateSessionEventType:**
 *
 *  Browse Name                | DataType                  | TypeDefinition | Modelling Rule | See Also
 *  ---------------------------|---------------------------|----------------|----------------|-----------------------------------------------------------------------
 *  ClientSoftwareCertificates | SignedSoftwareCertificate | PropertyType   | Mandatory      | \ref getClientSoftwareCertificates, \ref setClientSoftwareCertificates
 *  SecureChannelId            | String                    | PropertyType   | Mandatory      | \ref getSecureChannelId, \ref setSecureChannelId
 *  UserIdentityToken          | UserIdentityToken         | PropertyType   | Mandatory      | \ref getUserIdentityToken, \ref setUserIdentityToken

 *  This is a subtype of \ref OpcUa::AuditSessionEventTypeData
 *  "AuditSessionEventTypeData" and is used for Events generated from calling the
 *  ActivateSession Service defined in Part 4 of the OPC UA Specification.
 *
 *  This EventType inherits all Properties of the \ref
 *  OpcUa::AuditSessionEventTypeData "AuditSessionEventTypeData". The SourceName
 *  for Events of this type should be “Session/ActivateSession”.
 *
 *  The additional Properties defined for this EventType reflect parameters of the
 *  Service call that triggers the Event.
 *
 *  See also \ref Doc_OpcUa_AuditActivateSessionEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditActivateSessionEventTypeData:
    public OpcUa::AuditSessionEventTypeData
{
    UA_DISABLE_COPY(AuditActivateSessionEventTypeData);
public:
    AuditActivateSessionEventTypeData();
    virtual ~AuditActivateSessionEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // ClientSoftwareCertificates
    void setClientSoftwareCertificates(const UaSignedSoftwareCertificates& ClientSoftwareCertificates);
    void setClientSoftwareCertificatesStatus(OpcUa_StatusCode status);
    void getClientSoftwareCertificates(UaSignedSoftwareCertificates& ClientSoftwareCertificates);
    virtual void getClientSoftwareCertificatesValue(Session* pSession, OpcUa_Variant& value);
    // SecureChannelId
    void setSecureChannelId(const UaString& SecureChannelId);
    void setSecureChannelIdStatus(OpcUa_StatusCode status);
    UaString getSecureChannelId();
    virtual void getSecureChannelIdValue(Session* pSession, OpcUa_Variant& value);
    // UserIdentityToken
    void setUserIdentityToken(const UaExtensionObject& UserIdentityToken);
    void setUserIdentityTokenStatus(OpcUa_StatusCode status);
    UaExtensionObject getUserIdentityToken();
    virtual void getUserIdentityTokenValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditActivateSessionEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditCancelEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditCancelEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditCancelEventType:**
 *
 *  Browse Name   | DataType | TypeDefinition | Modelling Rule | See Also
 *  --------------|----------|----------------|----------------|---------------------------------------------
 *  RequestHandle | UInt32   | PropertyType   | Mandatory      | \ref getRequestHandle, \ref setRequestHandle

 *  This is a subtype of \ref OpcUa::AuditSessionEventTypeData
 *  "AuditSessionEventTypeData" and is used for Events generated from calling the
 *  Cancel Service defined in Part 4 of the OPC UA Specification.
 *
 *  This EventType inherits all Properties of the \ref
 *  OpcUa::AuditSessionEventTypeData "AuditSessionEventTypeData". The SourceName
 *  for Events of this type should be “Session/Cancel”.
 *
 *  The additional Properties defined for this EventType reflect parameters of the
 *  Service call that triggers the Event.
 *
 *  See also \ref Doc_OpcUa_AuditCancelEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditCancelEventTypeData:
    public OpcUa::AuditSessionEventTypeData
{
    UA_DISABLE_COPY(AuditCancelEventTypeData);
public:
    AuditCancelEventTypeData();
    virtual ~AuditCancelEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // RequestHandle
    void setRequestHandle(OpcUa_UInt32 RequestHandle);
    void setRequestHandleStatus(OpcUa_StatusCode status);
    OpcUa_UInt32 getRequestHandle();
    virtual void getRequestHandleValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditCancelEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditCreateSessionEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditCreateSessionEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditCreateSessionEventType:**
 *
 *  Browse Name                 | DataType   | TypeDefinition | Modelling Rule | See Also
 *  ----------------------------|------------|----------------|----------------|-------------------------------------------------------------------------
 *  ClientCertificate           | ByteString | PropertyType   | Mandatory      | \ref getClientCertificate, \ref setClientCertificate
 *  ClientCertificateThumbprint | String     | PropertyType   | Mandatory      | \ref getClientCertificateThumbprint, \ref setClientCertificateThumbprint
 *  RevisedSessionTimeout       | Duration   | PropertyType   | Mandatory      | \ref getRevisedSessionTimeout, \ref setRevisedSessionTimeout
 *  SecureChannelId             | String     | PropertyType   | Mandatory      | \ref getSecureChannelId, \ref setSecureChannelId

 *  This is a subtype of \ref OpcUa::AuditSessionEventTypeData
 *  "AuditSessionEventTypeData" and is used for Events generated from calling the
 *  CreateSession Service defined in Part 4 of the OPC UA Specification.
 *
 *  This EventType inherits all Properties of the AuditSessionEventType. The
 *  SourceName for Events of this type should be “Session/CreateSession”. The
 *  ClientUserId is not available for this call thus this parameter shall be set to
 *  the “System/CreateSession”.
 *
 *  The additional Properties defined for this EventType reflect parameters of the
 *  Service call that triggers the Event.
 *
 *  See also \ref Doc_OpcUa_AuditCreateSessionEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditCreateSessionEventTypeData:
    public OpcUa::AuditSessionEventTypeData
{
    UA_DISABLE_COPY(AuditCreateSessionEventTypeData);
public:
    AuditCreateSessionEventTypeData();
    virtual ~AuditCreateSessionEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // ClientCertificate
    void setClientCertificate(UaByteString& ClientCertificate);
    void setClientCertificateStatus(OpcUa_StatusCode status);
    UaByteString getClientCertificate();
    virtual void getClientCertificateValue(Session* pSession, OpcUa_Variant& value);
    // ClientCertificateThumbprint
    void setClientCertificateThumbprint(const UaString& ClientCertificateThumbprint);
    void setClientCertificateThumbprintStatus(OpcUa_StatusCode status);
    UaString getClientCertificateThumbprint();
    virtual void getClientCertificateThumbprintValue(Session* pSession, OpcUa_Variant& value);
    // RevisedSessionTimeout
    void setRevisedSessionTimeout(OpcUa_Double RevisedSessionTimeout);
    void setRevisedSessionTimeoutStatus(OpcUa_StatusCode status);
    OpcUa_Double getRevisedSessionTimeout();
    virtual void getRevisedSessionTimeoutValue(Session* pSession, OpcUa_Variant& value);
    // SecureChannelId
    void setSecureChannelId(const UaString& SecureChannelId);
    void setSecureChannelIdStatus(OpcUa_StatusCode status);
    UaString getSecureChannelId();
    virtual void getSecureChannelIdValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditCreateSessionEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditUrlMismatchEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditUrlMismatchEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditUrlMismatchEventType:**
 *
 *  Browse Name | DataType | TypeDefinition | Modelling Rule | See Also
 *  ------------|----------|----------------|----------------|-----------------------------------------
 *  EndpointUrl | String   | PropertyType   | Mandatory      | \ref getEndpointUrl, \ref setEndpointUrl

 *  This is a subtype of \ref OpcUa::AuditCreateSessionEventTypeData
 *  "AuditCreateSessionEventTypeData" and is used for Events generated from calling
 *  the CreateSession Service defined in Part 4 of the OPC UA Specification if the
 *  EndpointUrl used in the service call does not match the Server’s HostNames (see
 *  Part 4 of the OPC UA Specification for details).
 *
 *  This EventType inherits all Properties of the \ref
 *  OpcUa::AuditSessionEventTypeData "AuditSessionEventTypeData". The additional
 *  Properties defined for this EventType reflect parameters of the Service call
 *  that triggers the Event.
 *
 *  See also \ref Doc_OpcUa_AuditUrlMismatchEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditUrlMismatchEventTypeData:
    public OpcUa::AuditCreateSessionEventTypeData
{
    UA_DISABLE_COPY(AuditUrlMismatchEventTypeData);
public:
    AuditUrlMismatchEventTypeData();
    virtual ~AuditUrlMismatchEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // EndpointUrl
    void setEndpointUrl(const UaString& EndpointUrl);
    void setEndpointUrlStatus(OpcUa_StatusCode status);
    UaString getEndpointUrl();
    virtual void getEndpointUrlValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditUrlMismatchEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditUpdateEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditUpdateEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().

 *  This is a subtype of \ref OpcUa::AuditEventTypeData "AuditEventTypeData" and is
 *  used for categorization of update related Events. This type follows all
 *  behaviours of its parent type.
 *
 *  This EventType inherits all Properties of the \ref OpcUa::AuditEventTypeData
 *  "AuditEventTypeData". The SourceNode for Events of this type should be assigned
 *  to the NodeId that was changed. The SourceName for Events of this type should
 *  be “Attribute/” and the Service that generated the event (e.g. Write,
 *  HistoryUpdate). Note that one Service call may generate several Events of this
 *  type, one per changed value.
 *
 *  See also \ref Doc_OpcUa_AuditUpdateEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditUpdateEventTypeData:
    public OpcUa::AuditEventTypeData
{
    UA_DISABLE_COPY(AuditUpdateEventTypeData);
public:
    AuditUpdateEventTypeData();
    virtual ~AuditUpdateEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditUpdateEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditHistoryUpdateEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditHistoryUpdateEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditHistoryUpdateEventType:**
 *
 *  Browse Name         | DataType | TypeDefinition | Modelling Rule | See Also
 *  --------------------|----------|----------------|----------------|---------------------------------------------------------
 *  ParameterDataTypeId | NodeId   | PropertyType   | Mandatory      | \ref getParameterDataTypeId, \ref setParameterDataTypeId

 *  This is a subtype of \ref OpcUa::AuditUpdateEventTypeData
 *  "AuditUpdateEventTypeData" and is used for categorization of history update
 *  related Events. This type follows all behaviours of its parent type.
 *
 *  This EventType inherits all Properties of the \ref
 *  OpcUa::AuditUpdateEventTypeData "AuditUpdateEventTypeData".
 *
 *  Subtypes of this EventType are defined in Part 11 of the OPC UA Specification,
 *  representing the different possibilities to manipulate historical data.
 *
 *  See also \ref Doc_OpcUa_AuditHistoryUpdateEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditHistoryUpdateEventTypeData:
    public OpcUa::AuditUpdateEventTypeData
{
    UA_DISABLE_COPY(AuditHistoryUpdateEventTypeData);
public:
    AuditHistoryUpdateEventTypeData();
    virtual ~AuditHistoryUpdateEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // ParameterDataTypeId
    void setParameterDataTypeId(const UaNodeId& ParameterDataTypeId);
    void setParameterDataTypeIdStatus(OpcUa_StatusCode status);
    UaNodeId getParameterDataTypeId();
    virtual void getParameterDataTypeIdValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditHistoryUpdateEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditHistoryDeleteEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditHistoryDeleteEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditHistoryDeleteEventType:**
 *
 *  Browse Name | DataType | TypeDefinition | Modelling Rule | See Also
 *  ------------|----------|----------------|----------------|-----------------------------------------
 *  UpdatedNode | NodeId   | PropertyType   | Mandatory      | \ref getUpdatedNode, \ref setUpdatedNode

 *  This is a subtype of \ref OpcUa::AuditHistoryUpdateEventTypeData
 *  "AuditHistoryUpdateEventTypeData" and is used for categorization of history
 *  delete related Events.
 *
 *  This type follows all behaviour of its parent type. It inherits all Properties
 *  of the \ref OpcUa::AuditUpdateEventTypeData "AuditUpdateEventTypeData".
 *
 *  See also \ref Doc_OpcUa_AuditHistoryDeleteEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditHistoryDeleteEventTypeData:
    public OpcUa::AuditHistoryUpdateEventTypeData
{
    UA_DISABLE_COPY(AuditHistoryDeleteEventTypeData);
public:
    AuditHistoryDeleteEventTypeData();
    virtual ~AuditHistoryDeleteEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // UpdatedNode
    void setUpdatedNode(const UaNodeId& UpdatedNode);
    void setUpdatedNodeStatus(OpcUa_StatusCode status);
    UaNodeId getUpdatedNode();
    virtual void getUpdatedNodeValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditHistoryDeleteEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditHistoryAtTimeDeleteEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditHistoryAtTimeDeleteEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditHistoryAtTimeDeleteEventType:**
 *
 *  Browse Name | DataType  | TypeDefinition | Modelling Rule | See Also
 *  ------------|-----------|----------------|----------------|-------------------------------------
 *  OldValues   | DataValue | PropertyType   | Mandatory      | \ref getOldValues, \ref setOldValues
 *  ReqTimes    | UtcTime   | PropertyType   | Mandatory      | \ref getReqTimes, \ref setReqTimes

 *  This is a subtype of \ref OpcUa::AuditHistoryDeleteEventTypeData
 *  "AuditHistoryDeleteEventTypeData" and is used for categorization of history
 *  delete related Events.
 *
 *  This type follows all behaviour of its parent type. It inherits all Properties
 *  of the \ref OpcUa::AuditHistoryDeleteEventTypeData
 *  "AuditHistoryDeleteEventTypeData".
 *
 *  See also \ref Doc_OpcUa_AuditHistoryAtTimeDeleteEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditHistoryAtTimeDeleteEventTypeData:
    public OpcUa::AuditHistoryDeleteEventTypeData
{
    UA_DISABLE_COPY(AuditHistoryAtTimeDeleteEventTypeData);
public:
    AuditHistoryAtTimeDeleteEventTypeData();
    virtual ~AuditHistoryAtTimeDeleteEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // OldValues
    void setOldValues(const UaDataValues& OldValues);
    void setOldValuesStatus(OpcUa_StatusCode status);
    void getOldValues(UaDataValues& OldValues);
    virtual void getOldValuesValue(Session* pSession, OpcUa_Variant& value);
    // ReqTimes
    void setReqTimes(const UaDateTimeArray& ReqTimes);
    void setReqTimesStatus(OpcUa_StatusCode status);
    void getReqTimes(UaDateTimeArray& ReqTimes);
    virtual void getReqTimesValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditHistoryAtTimeDeleteEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditHistoryEventDeleteEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditHistoryEventDeleteEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditHistoryEventDeleteEventType:**
 *
 *  Browse Name | DataType              | TypeDefinition | Modelling Rule | See Also
 *  ------------|-----------------------|----------------|----------------|-------------------------------------
 *  EventIds    | ByteString            | PropertyType   | Mandatory      | \ref getEventIds, \ref setEventIds
 *  OldValues   | HistoryEventFieldList | PropertyType   | Mandatory      | \ref getOldValues, \ref setOldValues

 *  This is a subtype of \ref OpcUa::AuditHistoryDeleteEventTypeData
 *  "AuditHistoryDeleteEventTypeData" and is used for categorization of history
 *  delete related Events.
 *
 *  This type follows all behaviour of its parent type. It inherits all Properties
 *  of the \ref OpcUa::AuditHistoryDeleteEventTypeData
 *  "AuditHistoryDeleteEventTypeData".
 *
 *  See also \ref Doc_OpcUa_AuditHistoryEventDeleteEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditHistoryEventDeleteEventTypeData:
    public OpcUa::AuditHistoryDeleteEventTypeData
{
    UA_DISABLE_COPY(AuditHistoryEventDeleteEventTypeData);
public:
    AuditHistoryEventDeleteEventTypeData();
    virtual ~AuditHistoryEventDeleteEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // EventIds
    void setEventIds(const UaByteStringArray& EventIds);
    void setEventIdsStatus(OpcUa_StatusCode status);
    void getEventIds(UaByteStringArray& EventIds);
    virtual void getEventIdsValue(Session* pSession, OpcUa_Variant& value);
    // OldValues
#if SUPPORT_Historical_Access
    void setOldValues(const UaHistoryEventFieldList& OldValues);
    UaHistoryEventFieldList getOldValues();
#endif // SUPPORT_Historical_Access
    void setOldValuesStatus(OpcUa_StatusCode status);
    virtual void getOldValuesValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditHistoryEventDeleteEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditHistoryRawModifyDeleteEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditHistoryRawModifyDeleteEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditHistoryRawModifyDeleteEventType:**
 *
 *  Browse Name      | DataType  | TypeDefinition | Modelling Rule | See Also
 *  -----------------|-----------|----------------|----------------|---------------------------------------------------
 *  EndTime          | UtcTime   | PropertyType   | Mandatory      | \ref getEndTime, \ref setEndTime
 *  IsDeleteModified | Boolean   | PropertyType   | Mandatory      | \ref getIsDeleteModified, \ref setIsDeleteModified
 *  OldValues        | DataValue | PropertyType   | Mandatory      | \ref getOldValues, \ref setOldValues
 *  StartTime        | UtcTime   | PropertyType   | Mandatory      | \ref getStartTime, \ref setStartTime

 *  This is a subtype of \ref OpcUa::AuditHistoryDeleteEventTypeData
 *  "AuditHistoryDeleteEventTypeData" and is used for categorization of history
 *  delete related Events.
 *
 *  This type follows all behaviour of its parent type. It inherits all Properties
 *  of the \ref OpcUa::AuditHistoryDeleteEventTypeData
 *  "AuditHistoryDeleteEventTypeData".
 *
 *  See also \ref Doc_OpcUa_AuditHistoryRawModifyDeleteEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditHistoryRawModifyDeleteEventTypeData:
    public OpcUa::AuditHistoryDeleteEventTypeData
{
    UA_DISABLE_COPY(AuditHistoryRawModifyDeleteEventTypeData);
public:
    AuditHistoryRawModifyDeleteEventTypeData();
    virtual ~AuditHistoryRawModifyDeleteEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // EndTime
    void setEndTime(const UaDateTime& EndTime);
    void setEndTimeStatus(OpcUa_StatusCode status);
    UaDateTime getEndTime();
    virtual void getEndTimeValue(Session* pSession, OpcUa_Variant& value);
    // IsDeleteModified
    void setIsDeleteModified(OpcUa_Boolean IsDeleteModified);
    void setIsDeleteModifiedStatus(OpcUa_StatusCode status);
    OpcUa_Boolean getIsDeleteModified();
    virtual void getIsDeleteModifiedValue(Session* pSession, OpcUa_Variant& value);
    // OldValues
    void setOldValues(const UaDataValues& OldValues);
    void setOldValuesStatus(OpcUa_StatusCode status);
    void getOldValues(UaDataValues& OldValues);
    virtual void getOldValuesValue(Session* pSession, OpcUa_Variant& value);
    // StartTime
    void setStartTime(const UaDateTime& StartTime);
    void setStartTimeStatus(OpcUa_StatusCode status);
    UaDateTime getStartTime();
    virtual void getStartTimeValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditHistoryRawModifyDeleteEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditHistoryEventUpdateEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditHistoryEventUpdateEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditHistoryEventUpdateEventType:**
 *
 *  Browse Name          | DataType              | TypeDefinition | Modelling Rule | See Also
 *  ---------------------|-----------------------|----------------|----------------|-----------------------------------------------------------
 *  Filter               | EventFilter           | PropertyType   | Mandatory      | \ref setFilter
 *  NewValues            | HistoryEventFieldList | PropertyType   | Mandatory      | \ref getNewValues, \ref setNewValues
 *  OldValues            | HistoryEventFieldList | PropertyType   | Mandatory      | \ref getOldValues, \ref setOldValues
 *  PerformInsertReplace | PerformUpdateType     | PropertyType   | Mandatory      | \ref getPerformInsertReplace, \ref setPerformInsertReplace
 *  UpdatedNode          | NodeId                | PropertyType   | Mandatory      | \ref getUpdatedNode, \ref setUpdatedNode

 *  This is a subtype of \ref OpcUa::AuditHistoryUpdateEventTypeData
 *  "AuditHistoryUpdateEventTypeData" and is used for categorization of History
 *  Event update related Events.
 *
 *  This type follows all behaviour of its parent type. It inherits all Properties
 *  of the \ref OpcUa::AuditHistoryUpdateEventTypeData
 *  "AuditHistoryUpdateEventTypeData".
 *
 *  See also \ref Doc_OpcUa_AuditHistoryEventUpdateEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditHistoryEventUpdateEventTypeData:
    public OpcUa::AuditHistoryUpdateEventTypeData
{
    UA_DISABLE_COPY(AuditHistoryEventUpdateEventTypeData);
public:
    AuditHistoryEventUpdateEventTypeData();
    virtual ~AuditHistoryEventUpdateEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // Filter
#if SUPPORT_Event_Subscription_Server_Facet
    void setFilter(const UaEventFilter& Filter);
#endif // SUPPORT_Event_Subscription_Server_Facet
    void setFilterStatus(OpcUa_StatusCode status);
    virtual void getFilterValue(Session* pSession, OpcUa_Variant& value);
    // NewValues
#if SUPPORT_Historical_Access
    void setNewValues(const UaHistoryEventFieldLists& NewValues);
    void getNewValues(UaHistoryEventFieldLists& NewValues);
#endif // SUPPORT_Historical_Access
    void setNewValuesStatus(OpcUa_StatusCode status);
    virtual void getNewValuesValue(Session* pSession, OpcUa_Variant& value);
    // OldValues
#if SUPPORT_Historical_Access
    void setOldValues(const UaHistoryEventFieldLists& OldValues);
    void getOldValues(UaHistoryEventFieldLists& OldValues);
#endif // SUPPORT_Historical_Access
    void setOldValuesStatus(OpcUa_StatusCode status);
    virtual void getOldValuesValue(Session* pSession, OpcUa_Variant& value);
    // PerformInsertReplace
    void setPerformInsertReplace(OpcUa_PerformUpdateType PerformInsertReplace);
    void setPerformInsertReplaceStatus(OpcUa_StatusCode status);
    OpcUa_PerformUpdateType getPerformInsertReplace();
    virtual void getPerformInsertReplaceValue(Session* pSession, OpcUa_Variant& value);
    // UpdatedNode
    void setUpdatedNode(const UaNodeId& UpdatedNode);
    void setUpdatedNodeStatus(OpcUa_StatusCode status);
    UaNodeId getUpdatedNode();
    virtual void getUpdatedNodeValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditHistoryEventUpdateEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditHistoryValueUpdateEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditHistoryValueUpdateEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditHistoryValueUpdateEventType:**
 *
 *  Browse Name          | DataType          | TypeDefinition | Modelling Rule | See Also
 *  ---------------------|-------------------|----------------|----------------|-----------------------------------------------------------
 *  NewValues            | DataValue         | PropertyType   | Mandatory      | \ref getNewValues, \ref setNewValues
 *  OldValues            | DataValue         | PropertyType   | Mandatory      | \ref getOldValues, \ref setOldValues
 *  PerformInsertReplace | PerformUpdateType | PropertyType   | Mandatory      | \ref getPerformInsertReplace, \ref setPerformInsertReplace
 *  UpdatedNode          | NodeId            | PropertyType   | Mandatory      | \ref getUpdatedNode, \ref setUpdatedNode

 *  This is a subtype of \ref OpcUa::AuditHistoryUpdateEventTypeData
 *  "AuditHistoryUpdateEventTypeData" and is used for categorization of history
 *  value update related Events.
 *
 *  This type follows all behaviour of its parent type. It inherits all Properties
 *  of the \ref OpcUa::AuditHistoryUpdateEventTypeData
 *  "AuditHistoryUpdateEventTypeData".
 *
 *  See also \ref Doc_OpcUa_AuditHistoryValueUpdateEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditHistoryValueUpdateEventTypeData:
    public OpcUa::AuditHistoryUpdateEventTypeData
{
    UA_DISABLE_COPY(AuditHistoryValueUpdateEventTypeData);
public:
    AuditHistoryValueUpdateEventTypeData();
    virtual ~AuditHistoryValueUpdateEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // NewValues
    void setNewValues(const UaDataValues& NewValues);
    void setNewValuesStatus(OpcUa_StatusCode status);
    void getNewValues(UaDataValues& NewValues);
    virtual void getNewValuesValue(Session* pSession, OpcUa_Variant& value);
    // OldValues
    void setOldValues(const UaDataValues& OldValues);
    void setOldValuesStatus(OpcUa_StatusCode status);
    void getOldValues(UaDataValues& OldValues);
    virtual void getOldValuesValue(Session* pSession, OpcUa_Variant& value);
    // PerformInsertReplace
    void setPerformInsertReplace(OpcUa_PerformUpdateType PerformInsertReplace);
    void setPerformInsertReplaceStatus(OpcUa_StatusCode status);
    OpcUa_PerformUpdateType getPerformInsertReplace();
    virtual void getPerformInsertReplaceValue(Session* pSession, OpcUa_Variant& value);
    // UpdatedNode
    void setUpdatedNode(const UaNodeId& UpdatedNode);
    void setUpdatedNodeStatus(OpcUa_StatusCode status);
    UaNodeId getUpdatedNode();
    virtual void getUpdatedNodeValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditHistoryValueUpdateEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditWriteUpdateEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditWriteUpdateEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditWriteUpdateEventType:**
 *
 *  Browse Name | DataType     | TypeDefinition | Modelling Rule | See Also
 *  ------------|--------------|----------------|----------------|-----------------------------------------
 *  AttributeId | UInt32       | PropertyType   | Mandatory      | \ref getAttributeId, \ref setAttributeId
 *  IndexRange  | NumericRange | PropertyType   | Mandatory      | \ref getIndexRange, \ref setIndexRange
 *  NewValue    | BaseDataType | PropertyType   | Mandatory      | \ref getNewValue, \ref setNewValue
 *  OldValue    | BaseDataType | PropertyType   | Mandatory      | \ref getOldValue, \ref setOldValue

 *  This is a subtype of \ref OpcUa::AuditUpdateEventTypeData
 *  "AuditUpdateEventTypeData" and is used for categorization of write update
 *  related Events. This type follows all behaviours of its parent type.
 *
 *  This EventType inherits all Properties of the AuditUpdateEventType. The
 *  SourceName for Events of this type should be “Attribute/Write”.
 *
 *  See also \ref Doc_OpcUa_AuditWriteUpdateEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditWriteUpdateEventTypeData:
    public OpcUa::AuditUpdateEventTypeData
{
    UA_DISABLE_COPY(AuditWriteUpdateEventTypeData);
public:
    AuditWriteUpdateEventTypeData();
    virtual ~AuditWriteUpdateEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // AttributeId
    void setAttributeId(OpcUa_UInt32 AttributeId);
    void setAttributeIdStatus(OpcUa_StatusCode status);
    OpcUa_UInt32 getAttributeId();
    virtual void getAttributeIdValue(Session* pSession, OpcUa_Variant& value);
    // IndexRange
    void setIndexRange(const UaString& IndexRange);
    void setIndexRangeStatus(OpcUa_StatusCode status);
    UaString getIndexRange();
    virtual void getIndexRangeValue(Session* pSession, OpcUa_Variant& value);
    // NewValue
    void setNewValue(const UaVariant&NewValue);
    void setNewValueStatus(OpcUa_StatusCode status);
    UaVariant getNewValue();
    virtual void getNewValueValue(Session* pSession, OpcUa_Variant& value);
    // OldValue
    void setOldValue(const UaVariant&OldValue);
    void setOldValueStatus(OpcUa_StatusCode status);
    UaVariant getOldValue();
    virtual void getOldValueValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditWriteUpdateEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditUpdateMethodEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditUpdateMethodEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditUpdateMethodEventType:**
 *
 *  Browse Name    | DataType     | TypeDefinition | Modelling Rule | See Also
 *  ---------------|--------------|----------------|----------------|-----------------------------------------------
 *  InputArguments | BaseDataType | PropertyType   | Mandatory      | \ref getInputArguments, \ref setInputArguments
 *  MethodId       | NodeId       | PropertyType   | Mandatory      | \ref getMethodId, \ref setMethodId

 *  This is a subtype of \ref OpcUa::AuditEventTypeData "AuditEventTypeData" and is
 *  used for categorization of Method related Events. This type follows all
 *  behaviours of its parent type.
 *
 *  This EventType inherits all Properties of the \ref OpcUa::AuditEventTypeData
 *  "AuditEventTypeData". The SourceNode for Events of this type should be assigned
 *  to the NodeId of the object that the method resides on. The SourceName for
 *  Events of this type should be “Attribute/Call”. Note that one Service call may
 *  generate several Events of this type, one per method called. This EventType
 *  should be further subtyped to better reflect the functionality of the method
 *  and to reflect changes to the address space or updated values triggered by the
 *  method.
 *
 *  See also \ref Doc_OpcUa_AuditUpdateMethodEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditUpdateMethodEventTypeData:
    public OpcUa::AuditEventTypeData
{
    UA_DISABLE_COPY(AuditUpdateMethodEventTypeData);
public:
    AuditUpdateMethodEventTypeData();
    virtual ~AuditUpdateMethodEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // InputArguments
    void setInputArguments(const UaVariantArray& InputArguments);
    void setInputArgumentsStatus(OpcUa_StatusCode status);
    void getInputArguments(UaVariantArray& InputArguments);
    virtual void getInputArgumentsValue(Session* pSession, OpcUa_Variant& value);
    // MethodId
    void setMethodId(const UaNodeId& MethodId);
    void setMethodIdStatus(OpcUa_StatusCode status);
    UaNodeId getMethodId();
    virtual void getMethodIdValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditUpdateMethodEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditConditionEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditConditionEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().

 *  This EventType is used to subsume all Audit Condition EventTypes.
 *
 *  Audit Condition EventTypes inherit all Properties of the \ref
 *  OpcUa::AuditUpdateMethodEventTypeData "AuditUpdateMethodEventTypeData". Unless
 *  a subtype overrides the definition, the inherited properties of the Condition
 *  will be used as defined.
 *
 *  - The inherited Property SourceNode shall be filled with the ConditionId.
 *  - The SourceName shall be “Method/” and the name of the Service that generated
 *    the Event (e.g. Disable, Enable, Acknowledge, etc).
 *
 *  This Event Type can be further customized to reflect particular Condition
 *  related actions.
 *
 *  See also \ref Doc_OpcUa_AuditConditionEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditConditionEventTypeData:
    public OpcUa::AuditUpdateMethodEventTypeData
{
    UA_DISABLE_COPY(AuditConditionEventTypeData);
public:
    AuditConditionEventTypeData();
    virtual ~AuditConditionEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditConditionEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditConditionAcknowledgeEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditConditionAcknowledgeEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditConditionAcknowledgeEventType:**
 *
 *  Browse Name | DataType      | TypeDefinition | Modelling Rule | See Also
 *  ------------|---------------|----------------|----------------|---------------------------------
 *  Comment     | LocalizedText | PropertyType   | Mandatory      | \ref getComment, \ref setComment

 *  This EventType is used to indicate acknowledgement or confirmation of one or
 *  more Conditions.
 *
 *  See also \ref Doc_OpcUa_AuditConditionAcknowledgeEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditConditionAcknowledgeEventTypeData:
    public OpcUa::AuditConditionEventTypeData
{
    UA_DISABLE_COPY(AuditConditionAcknowledgeEventTypeData);
public:
    AuditConditionAcknowledgeEventTypeData();
    virtual ~AuditConditionAcknowledgeEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // Comment
    void setComment(const UaLocalizedText& Comment);
    void setCommentStatus(OpcUa_StatusCode status);
    UaLocalizedText getComment();
    virtual void getCommentValue(Session* pSession, OpcUa_Variant& value);
    // EventId already defined by base class

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditConditionAcknowledgeEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditConditionCommentEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditConditionCommentEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditConditionCommentEventType:**
 *
 *  Browse Name | DataType      | TypeDefinition | Modelling Rule | See Also
 *  ------------|---------------|----------------|----------------|---------------------------------
 *  Comment     | LocalizedText | PropertyType   | Mandatory      | \ref getComment, \ref setComment

 *  This EventType is used to report an AddComment action.
 *
 *  See also \ref Doc_OpcUa_AuditConditionCommentEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditConditionCommentEventTypeData:
    public OpcUa::AuditConditionEventTypeData
{
    UA_DISABLE_COPY(AuditConditionCommentEventTypeData);
public:
    AuditConditionCommentEventTypeData();
    virtual ~AuditConditionCommentEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // Comment
    void setComment(const UaLocalizedText& Comment);
    void setCommentStatus(OpcUa_StatusCode status);
    UaLocalizedText getComment();
    virtual void getCommentValue(Session* pSession, OpcUa_Variant& value);
    // EventId already defined by base class

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditConditionCommentEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditConditionConfirmEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditConditionConfirmEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditConditionConfirmEventType:**
 *
 *  Browse Name | DataType      | TypeDefinition | Modelling Rule | See Also
 *  ------------|---------------|----------------|----------------|---------------------------------
 *  Comment     | LocalizedText | PropertyType   | Mandatory      | \ref getComment, \ref setComment

 *  This EventType is used to report a Confirm action.
 *
 *  See also \ref Doc_OpcUa_AuditConditionConfirmEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditConditionConfirmEventTypeData:
    public OpcUa::AuditConditionEventTypeData
{
    UA_DISABLE_COPY(AuditConditionConfirmEventTypeData);
public:
    AuditConditionConfirmEventTypeData();
    virtual ~AuditConditionConfirmEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // Comment
    void setComment(const UaLocalizedText& Comment);
    void setCommentStatus(OpcUa_StatusCode status);
    UaLocalizedText getComment();
    virtual void getCommentValue(Session* pSession, OpcUa_Variant& value);
    // EventId already defined by base class

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditConditionConfirmEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditConditionEnableEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditConditionEnableEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().

 *  This EventType is used to indicate a change in the enabled state of a Condition
 *  instance.
 *
 *  The SourceName shall indicate Method/Enable or Method/Disable. If the audit
 *  Event is not the result of a method call, but due to an internal action of the
 *  Server, the SourceName shall reflect Enable or Disable, it may be preceded by
 *  an appropriate description such as “Internal/Enable” or “Remote/Enable”.
 *
 *  See also \ref Doc_OpcUa_AuditConditionEnableEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditConditionEnableEventTypeData:
    public OpcUa::AuditConditionEventTypeData
{
    UA_DISABLE_COPY(AuditConditionEnableEventTypeData);
public:
    AuditConditionEnableEventTypeData();
    virtual ~AuditConditionEnableEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditConditionEnableEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditConditionRespondEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditConditionRespondEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditConditionRespondEventType:**
 *
 *  Browse Name      | DataType | TypeDefinition | Modelling Rule | See Also
 *  -----------------|----------|----------------|----------------|---------------------------------------------------
 *  SelectedResponse | Int32    | PropertyType   | Mandatory      | \ref getSelectedResponse, \ref setSelectedResponse

 *  This EventType is used to report a Respond action.
 *
 *  See also \ref Doc_OpcUa_AuditConditionRespondEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditConditionRespondEventTypeData:
    public OpcUa::AuditConditionEventTypeData
{
    UA_DISABLE_COPY(AuditConditionRespondEventTypeData);
public:
    AuditConditionRespondEventTypeData();
    virtual ~AuditConditionRespondEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // SelectedResponse
    void setSelectedResponse(OpcUa_Int32 SelectedResponse);
    void setSelectedResponseStatus(OpcUa_StatusCode status);
    OpcUa_Int32 getSelectedResponse();
    virtual void getSelectedResponseValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditConditionRespondEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditConditionShelvingEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditConditionShelvingEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditConditionShelvingEventType:**
 *
 *  Browse Name  | DataType | TypeDefinition | Modelling Rule | See Also
 *  -------------|----------|----------------|----------------|-------------------------------------------
 *  ShelvingTime | Duration | PropertyType   | Mandatory      | \ref getShelvingTime, \ref setShelvingTime

 *  This EventType is used to indicate a change to the Shelving state of a
 *  Condition instance.
 *
 *  See also \ref Doc_OpcUa_AuditConditionShelvingEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AuditConditionShelvingEventTypeData:
    public OpcUa::AuditConditionEventTypeData
{
    UA_DISABLE_COPY(AuditConditionShelvingEventTypeData);
public:
    AuditConditionShelvingEventTypeData();
    virtual ~AuditConditionShelvingEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // ShelvingTime
    void setShelvingTime(OpcUa_Double ShelvingTime);
    void setShelvingTimeStatus(OpcUa_StatusCode status);
    OpcUa_Double getShelvingTime();
    virtual void getShelvingTimeValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditConditionShelvingEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditUpdateStateEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditUpdateStateEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditUpdateStateEventType:**
 *
 *  Browse Name | DataType     | TypeDefinition | Modelling Rule | See Also
 *  ------------|--------------|----------------|----------------|---------------------------------------
 *  NewStateId  | BaseDataType | PropertyType   | Mandatory      | \ref getNewStateId, \ref setNewStateId
 *  OldStateId  | BaseDataType | PropertyType   | Mandatory      | \ref getOldStateId, \ref setOldStateId

 */
class SERVER_CORE_EXPORT AuditUpdateStateEventTypeData:
    public OpcUa::AuditUpdateMethodEventTypeData
{
    UA_DISABLE_COPY(AuditUpdateStateEventTypeData);
public:
    AuditUpdateStateEventTypeData();
    virtual ~AuditUpdateStateEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // NewStateId
    void setNewStateId(const UaVariant&NewStateId);
    void setNewStateIdStatus(OpcUa_StatusCode status);
    UaVariant getNewStateId();
    virtual void getNewStateIdValue(Session* pSession, OpcUa_Variant& value);
    // OldStateId
    void setOldStateId(const UaVariant&OldStateId);
    void setOldStateIdStatus(OpcUa_StatusCode status);
    UaVariant getOldStateId();
    virtual void getOldStateIdValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditUpdateStateEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type AuditProgramTransitionEventType.
 *
 *  This class provides the functionality necessary to create an event of type AuditProgramTransitionEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the AuditProgramTransitionEventType:**
 *
 *  Browse Name      | DataType | TypeDefinition | Modelling Rule | See Also
 *  -----------------|----------|----------------|----------------|---------------------------------------------------
 *  TransitionNumber | UInt32   | PropertyType   | Mandatory      | \ref getTransitionNumber, \ref setTransitionNumber

 */
class SERVER_CORE_EXPORT AuditProgramTransitionEventTypeData:
    public OpcUa::AuditUpdateStateEventTypeData
{
    UA_DISABLE_COPY(AuditProgramTransitionEventTypeData);
public:
    AuditProgramTransitionEventTypeData();
    virtual ~AuditProgramTransitionEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // TransitionNumber
    void setTransitionNumber(OpcUa_UInt32 TransitionNumber);
    void setTransitionNumberStatus(OpcUa_StatusCode status);
    OpcUa_UInt32 getTransitionNumber();
    virtual void getTransitionNumberValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_AuditProgramTransitionEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type ProgramTransitionAuditEventType.
 *
 *  This class provides the functionality necessary to create an event of type ProgramTransitionAuditEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the ProgramTransitionAuditEventType:**
 *
 *  Browse Name | DataType      | TypeDefinition               | Modelling Rule | See Also
 *  ------------|---------------|------------------------------|----------------|---------------------------------------
 *  Transition  | LocalizedText | FiniteTransitionVariableType | Mandatory      | \ref getTransition, \ref setTransition

 */
class SERVER_CORE_EXPORT ProgramTransitionAuditEventTypeData:
    public OpcUa::AuditUpdateStateEventTypeData
{
    UA_DISABLE_COPY(ProgramTransitionAuditEventTypeData);
public:
    ProgramTransitionAuditEventTypeData();
    virtual ~ProgramTransitionAuditEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // Transition
    void setTransition(const UaLocalizedText& Transition);
    void setTransitionStatus(OpcUa_StatusCode status);
    UaLocalizedText getTransition();
    virtual void getTransitionValue(Session* pSession, OpcUa_Variant& value);
    void setTransition_Id(const UaNodeId& Id);
    void setTransition_IdStatus(OpcUa_StatusCode status);
    UaNodeId getTransition_Id();
    virtual void getTransition_IdValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_ProgramTransitionAuditEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type CertificateUpdatedAuditEventType.
 *
 *  This class provides the functionality necessary to create an event of type CertificateUpdatedAuditEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the CertificateUpdatedAuditEventType:**
 *
 *  Browse Name      | DataType | TypeDefinition | Modelling Rule | See Also
 *  -----------------|----------|----------------|----------------|---------------------------------------------------
 *  CertificateGroup | NodeId   | PropertyType   | Mandatory      | \ref getCertificateGroup, \ref setCertificateGroup
 *  CertificateType  | NodeId   | PropertyType   | Mandatory      | \ref getCertificateType, \ref setCertificateType

 *  This event is raised when the application certificate is changed.
 *
 *  This is the result of a \ref OpcUa::ServerConfigurationType::UpdateCertificate
 *  "UpdateCertificate" method completing successfully or failing.
 *
 *  This EventType inherits all properties of the \ref
 *  OpcUa::AuditUpdateMethodEventTypeData "AuditUpdateMethodEventTypeData".
 *
 *  See also \ref Doc_OpcUa_CertificateUpdatedAuditEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT CertificateUpdatedAuditEventTypeData:
    public OpcUa::AuditUpdateMethodEventTypeData
{
    UA_DISABLE_COPY(CertificateUpdatedAuditEventTypeData);
public:
    CertificateUpdatedAuditEventTypeData();
    virtual ~CertificateUpdatedAuditEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // CertificateGroup
    void setCertificateGroup(const UaNodeId& CertificateGroup);
    void setCertificateGroupStatus(OpcUa_StatusCode status);
    UaNodeId getCertificateGroup();
    virtual void getCertificateGroupValue(Session* pSession, OpcUa_Variant& value);
    // CertificateType
    void setCertificateType(const UaNodeId& CertificateType);
    void setCertificateTypeStatus(OpcUa_StatusCode status);
    UaNodeId getCertificateType();
    virtual void getCertificateTypeValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_CertificateUpdatedAuditEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type TrustListUpdatedAuditEventType.
 *
 *  This class provides the functionality necessary to create an event of type TrustListUpdatedAuditEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().

 *  This event is raised when a trust list is changed.
 *
 *  This is the result of a \ref OpcUa::TrustListType::CloseAndUpdate
 *  "CloseAndUpdate" method on a TrustListType object being called. It shall also
 *  be raised when the \ref OpcUa::TrustListType::AddCertificate "AddCertificate"
 *  or \ref OpcUa::TrustListType::RemoveCertificate "RemoveCertificate" method
 *  causes an update to the trust list.
 *
 *  This EventType inherits all Properties of the \ref
 *  OpcUa::AuditUpdateMethodEventTypeData "AuditUpdateMethodEventTypeData".
 *
 *  See also \ref Doc_OpcUa_TrustListUpdatedAuditEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT TrustListUpdatedAuditEventTypeData:
    public OpcUa::AuditUpdateMethodEventTypeData
{
    UA_DISABLE_COPY(TrustListUpdatedAuditEventTypeData);
public:
    TrustListUpdatedAuditEventTypeData();
    virtual ~TrustListUpdatedAuditEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_TrustListUpdatedAuditEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};


} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // SUPPORT_Auditing_Server_Facet

#endif // #ifndef __OPCUAAUDITEVENTTYPE_H__
