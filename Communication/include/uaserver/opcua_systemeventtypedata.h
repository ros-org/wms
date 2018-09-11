/******************************************************************************
** opcua_systemeventtypedata.h
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

#ifndef __OPCUA_SYSTEMEVENTTYPE_H__
#define __OPCUA_SYSTEMEVENTTYPE_H__

#include "uaeventdata.h"
#include "basenodes.h"
#include "opcua_identifiers.h"
#include "opcua_propertytype.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {


/** Event data class for the OPC UA event type SystemEventType.
 *
 *  This class provides the functionality necessary to create an event of type SystemEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().

 *  Event which is generated as a result of some Event that occurs within the
 *  Server or by a system that the Server is representing.
 *
 *  This EventType inherits all Properties of the BaseEventType. There are no
 *  additional Properties defined for this EventType.
 *
 *  See also \ref Doc_OpcUa_SystemEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT SystemEventTypeData:
    public BaseEventTypeData
{
    UA_DISABLE_COPY(SystemEventTypeData);
public:
    SystemEventTypeData();
    virtual ~SystemEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_SystemEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type DeviceFailureEventType.
 *
 *  This class provides the functionality necessary to create an event of type DeviceFailureEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().

 *  Event that indicates a failure in a device of the underlying system.
 *
 *  This EventType inherits all Properties of the SystemEventType. There are no
 *  additional Properties defined for this EventType.
 *
 *  See also \ref Doc_OpcUa_DeviceFailureEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT DeviceFailureEventTypeData:
    public OpcUa::SystemEventTypeData
{
    UA_DISABLE_COPY(DeviceFailureEventTypeData);
public:
    DeviceFailureEventTypeData();
    virtual ~DeviceFailureEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_DeviceFailureEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type SystemStatusChangeEventType.
 *
 *  This class provides the functionality necessary to create an event of type SystemStatusChangeEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the SystemStatusChangeEventType:**
 *
 *  Browse Name | DataType    | TypeDefinition | Modelling Rule | See Also
 *  ------------|-------------|----------------|----------------|-----------------------------------------
 *  SystemState | ServerState | PropertyType   | Mandatory      | \ref getSystemState, \ref setSystemState

 *  Event that indicates a status change in a system.
 *
 *  For example, if the status indicates that an underlying system is not running,
 *  then a Client cannot expect any Events from the underlying system. A Server can
 *  identify its own status changes using this EventType.
 *
 *  This EventType inherits all Properties of the SystemEventType. The SourceNode
 *  and the SourceName shall identify the system. The system can be the Server
 *  itself or some underlying system.
 *
 *  See also \ref Doc_OpcUa_SystemStatusChangeEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT SystemStatusChangeEventTypeData:
    public OpcUa::SystemEventTypeData
{
    UA_DISABLE_COPY(SystemStatusChangeEventTypeData);
public:
    SystemStatusChangeEventTypeData();
    virtual ~SystemStatusChangeEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // SystemState
    void setSystemState(OpcUa_ServerState SystemState);
    void setSystemStateStatus(OpcUa_StatusCode status);
    OpcUa_ServerState getSystemState();
    virtual void getSystemStateValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_SystemStatusChangeEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUASYSTEMEVENTTYPE_H__
