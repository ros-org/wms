/******************************************************************************
** opcua_transitioneventtypedata.h
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

#ifndef __OPCUA_TRANSITIONEVENTTYPE_H__
#define __OPCUA_TRANSITIONEVENTTYPE_H__

#include "uaeventdata.h"
#include "basenodes.h"
#include "opcua_identifiers.h"
#include "opcua_propertytype.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;
class StateVariableType;
class TransitionVariableType;

/** Event data class for the OPC UA event type TransitionEventType.
 *
 *  This class provides the functionality necessary to create an event of type TransitionEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the TransitionEventType:**
 *
 *  Browse Name | DataType      | TypeDefinition         | Modelling Rule | See Also
 *  ------------|---------------|------------------------|----------------|---------------------------------------
 *  FromState   | LocalizedText | StateVariableType      | Mandatory      | \ref getFromState, \ref setFromState
 *  ToState     | LocalizedText | StateVariableType      | Mandatory      | \ref getToState, \ref setToState
 *  Transition  | LocalizedText | TransitionVariableType | Mandatory      | \ref getTransition, \ref setTransition

 */
class SERVER_CORE_EXPORT TransitionEventTypeData:
    public BaseEventTypeData
{
    UA_DISABLE_COPY(TransitionEventTypeData);
public:
    TransitionEventTypeData();
    virtual ~TransitionEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // FromState
    void setFromState(const UaLocalizedText& FromState);
    void setFromStateStatus(OpcUa_StatusCode status);
    UaLocalizedText getFromState();
    virtual void getFromStateValue(Session* pSession, OpcUa_Variant& value);
    void setFromState_Id(const UaVariant&Id);
    void setFromState_IdStatus(OpcUa_StatusCode status);
    UaVariant getFromState_Id();
    virtual void getFromState_IdValue(Session* pSession, OpcUa_Variant& value);
    // ToState
    void setToState(const UaLocalizedText& ToState);
    void setToStateStatus(OpcUa_StatusCode status);
    UaLocalizedText getToState();
    virtual void getToStateValue(Session* pSession, OpcUa_Variant& value);
    void setToState_Id(const UaVariant&Id);
    void setToState_IdStatus(OpcUa_StatusCode status);
    UaVariant getToState_Id();
    virtual void getToState_IdValue(Session* pSession, OpcUa_Variant& value);
    // Transition
    void setTransition(const UaLocalizedText& Transition);
    void setTransitionStatus(OpcUa_StatusCode status);
    UaLocalizedText getTransition();
    virtual void getTransitionValue(Session* pSession, OpcUa_Variant& value);
    void setTransition_Id(const UaVariant&Id);
    void setTransition_IdStatus(OpcUa_StatusCode status);
    UaVariant getTransition_Id();
    virtual void getTransition_IdValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_TransitionEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUATRANSITIONEVENTTYPE_H__
