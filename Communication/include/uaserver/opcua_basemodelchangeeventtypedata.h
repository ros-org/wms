/******************************************************************************
** opcua_basemodelchangeeventtypedata.h
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

#ifndef __OPCUA_BASEMODELCHANGEEVENTTYPE_H__
#define __OPCUA_BASEMODELCHANGEEVENTTYPE_H__

#include "uaeventdata.h"
#include "basenodes.h"
#include "opcua_identifiers.h"
#include "opcua_propertytype.h"
#include "uamodelchangestructuredatatype.h"
#include "uasemanticchangestructuredatatype.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;

/** Event data class for the OPC UA event type BaseModelChangeEventType.
 *
 *  This class provides the functionality necessary to create an event of type BaseModelChangeEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().

 *  BaseType for ModelChangeEvents.
 *
 *  This Event does not contain information about the changes but only indicates
 *  that changes occurred. Therefore the Client shall assume that any or all of the
 *  Nodes may have changed.
 *
 *  This EventType inherits all Properties of the BaseEventType. There are no
 *  additional Properties defined for this EventType. The SourceNode for Events of
 *  this type should be the Node of the View that gives the context of the changes.
 *  If the whole AddressSpace is the context, the SourceNode is set to the NodeId
 *  of the Server object. The SourceName for Events of this type should be the
 *  String part of the BrowseName of the View; for the whole AddressSpace it should
 *  be “Server”.
 *
 *  Two types of ModelChangeEvents are defined: the BaseModelChangeEvent that does
 *  not contain any information about the changes and the GeneralModelChangeEvent
 *  that identifies the changed Nodes via an array. The precision used depends on
 *  both the capability of the OPC UA Server and the nature of the update. An OPC
 *  UA Server may use either ModelChangeEvent type depending on circumstances. It
 *  may also define subtypes of these EventTypes adding additional information. To
 *  ensure interoperability, one should follow the guidelines for Events listed
 *  below.
 *
 *  - If the array of the GeneralModelChangeEvent is present, then it should
 *    identify every Node that has changed since the preceding ModelChangeEvent.
 *  - The OPC UA Server should emit exactly one ModelChangeEvent for an update or
 *    series of updates. It should not issue multiple types of ModelChangeEvent for
 *    the same update.
 *  - Any Client that responds to ModelChangeEvents should respond to any Event of
 *    the \ref OpcUa::BaseModelChangeEventTypeData "BaseModelChangeEventTypeData"
 *    including its subtypes like the \ref OpcUa::GeneralModelChangeEventTypeData
 *    "GeneralModelChangeEventTypeData".
 *
 *  If a Client is not capable of interpreting additional information of the
 *  subtypes of the \ref OpcUa::BaseModelChangeEventTypeData
 *  "BaseModelChangeEventTypeData", it should treat Events of these types the same
 *  way as Events of the \ref OpcUa::BaseModelChangeEventTypeData
 *  "BaseModelChangeEventTypeData".
 *
 *  See also \ref Doc_OpcUa_BaseModelChangeEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT BaseModelChangeEventTypeData:
    public BaseEventTypeData
{
    UA_DISABLE_COPY(BaseModelChangeEventTypeData);
public:
    BaseModelChangeEventTypeData();
    virtual ~BaseModelChangeEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_BaseModelChangeEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type GeneralModelChangeEventType.
 *
 *  This class provides the functionality necessary to create an event of type GeneralModelChangeEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the GeneralModelChangeEventType:**
 *
 *  Browse Name | DataType                     | TypeDefinition | Modelling Rule | See Also
 *  ------------|------------------------------|----------------|----------------|---------------------------------
 *  Changes     | ModelChangeStructureDataType | PropertyType   | Mandatory      | \ref getChanges, \ref setChanges

 *  Contains information about the Node that was changed and the action that
 *  occurred to cause the ModelChangeEvent (e.g. add a Node, delete a Node, etc.).
 *
 *  If the affected Node is a Variable or object, then the TypeDefinitionNode is
 *  also present.
 *
 *  To allow Event compression, a GeneralModelChangeEvent contains an array of
 *  changes.
 *
 *  This EventType inherits all Properties of the BaseModelChangeEventType.
 *
 *  Two types of ModelChangeEvents are defined: the BaseModelChangeEvent that does
 *  not contain any information about the changes and the GeneralModelChangeEvent
 *  that identifies the changed Nodes via an array. The precision used depends on
 *  both the capability of the OPC UA Server and the nature of the update. An OPC
 *  UA Server may use either ModelChangeEvent type depending on circumstances. It
 *  may also define subtypes of these EventTypes adding additional information. To
 *  ensure interoperability, one should follow the guidelines for Events listed
 *  below.
 *
 *  - If the array of the GeneralModelChangeEvent is present, then it should
 *    identify every Node that has changed since the preceding ModelChangeEvent.
 *  - The OPC UA Server should emit exactly one ModelChangeEvent for an update or
 *    series of updates. It should not issue multiple types of ModelChangeEvent for
 *    the same update.
 *  - Any Client that responds to ModelChangeEvents should respond to any Event of
 *    the \ref OpcUa::BaseModelChangeEventTypeData "BaseModelChangeEventTypeData"
 *    including its subtypes like the \ref OpcUa::GeneralModelChangeEventTypeData
 *    "GeneralModelChangeEventTypeData".
 *
 *  If a Client is not capable of interpreting additional information of the
 *  subtypes of the \ref OpcUa::BaseModelChangeEventTypeData
 *  "BaseModelChangeEventTypeData", it should treat Events of these types the same
 *  way as Events of the \ref OpcUa::BaseModelChangeEventTypeData
 *  "BaseModelChangeEventTypeData".
 *
 *  See also \ref Doc_OpcUa_GeneralModelChangeEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT GeneralModelChangeEventTypeData:
    public OpcUa::BaseModelChangeEventTypeData
{
    UA_DISABLE_COPY(GeneralModelChangeEventTypeData);
public:
    GeneralModelChangeEventTypeData();
    virtual ~GeneralModelChangeEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // Changes
    void setChanges(const UaModelChangeStructureDataTypes& Changes);
    void setChangesStatus(OpcUa_StatusCode status);
    void getChanges(UaModelChangeStructureDataTypes& Changes);
    virtual void getChangesValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_GeneralModelChangeEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

/** Event data class for the OPC UA event type SemanticChangeEventType.
 *
 *  This class provides the functionality necessary to create an event of type SemanticChangeEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the SemanticChangeEventType:**
 *
 *  Browse Name | DataType                        | TypeDefinition | Modelling Rule | See Also
 *  ------------|---------------------------------|----------------|----------------|---------------------------------
 *  Changes     | SemanticChangeStructureDataType | PropertyType   | Mandatory      | \ref getChanges, \ref setChanges

 *  Event that indicates a change of the AddressSpace semantics.
 *
 *  The change consists of a change to the Value Attribute of a Property.
 *
 *  The SemanticChangeEvent contains information about the Node owning the Property
 *  that was changed. If this is a Variable or object, the TypeDefinitionNode is
 *  also present.
 *
 *  The SemanticChange bit of the AccessLevel Attribute of a Property indicates
 *  whether changes of the Property value are considered for SemanticChangeEvents
 *
 *  The ViewVersion and NodeVersion Properties do not change due to the publication
 *  of a SemanticChangeEvent. There is no standard way to identify which Nodes
 *  trigger a SemanticChangeEvent and which Nodes do not.
 *
 *  SemanticChangeEvents are handled in the context of a View the same way as
 *  ModelChangeEvents.
 *
 *  SemanticChangeEvents can be compressed the same way as ModelChangeEvents.
 *
 *  This EventType inherits all Properties of the BaseEventType. There are no
 *  additional Properties defined for this EventType. The SourceNode for Events of
 *  this type should be the Node of the View that gives the context of the changes.
 *  If the whole AddressSpace is the context, the SourceNode is set to the NodeId
 *  of the Server object. The SourceName for Events of this type should be the
 *  String part of the BrowseName of the View, for the whole AddressSpace it should
 *  be “Server”.
 *
 *  See also \ref Doc_OpcUa_SemanticChangeEventType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT SemanticChangeEventTypeData:
    public OpcUa::BaseModelChangeEventTypeData
{
    UA_DISABLE_COPY(SemanticChangeEventTypeData);
public:
    SemanticChangeEventTypeData();
    virtual ~SemanticChangeEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // Changes
    void setChanges(const UaSemanticChangeStructureDataTypes& Changes);
    void setChangesStatus(OpcUa_StatusCode status);
    void getChanges(UaSemanticChangeStructureDataTypes& Changes);
    virtual void getChangesValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_SemanticChangeEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};


} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUABASEMODELCHANGEEVENTTYPE_H__
