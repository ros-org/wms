/******************************************************************************
** opcua_programtransitioneventtypedata.h
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

#ifndef __OPCUA_PROGRAMTRANSITIONEVENTTYPE_H__
#define __OPCUA_PROGRAMTRANSITIONEVENTTYPE_H__

#include "opcua_transitioneventtypedata.h"
#include "basenodes.h"
#include "opcua_identifiers.h"
#include "opcua_propertytype.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;

/** Event data class for the OPC UA event type ProgramTransitionEventType.
 *
 *  This class provides the functionality necessary to create an event of type ProgramTransitionEventType, to set the values
 *  of the event fields and to send the event to interested clients through EventManagerBase::fireEvent().
 *
 *  **Event Fields of the ProgramTransitionEventType:**
 *
 *  Browse Name        | DataType     | TypeDefinition | Modelling Rule | See Also
 *  -------------------|--------------|----------------|----------------|-------------------------------------------------------
 *  IntermediateResult | BaseDataType | PropertyType   | Mandatory      | \ref getIntermediateResult, \ref setIntermediateResult

 */
class SERVER_CORE_EXPORT ProgramTransitionEventTypeData:
    public OpcUa::TransitionEventTypeData
{
    UA_DISABLE_COPY(ProgramTransitionEventTypeData);
public:
    ProgramTransitionEventTypeData();
    virtual ~ProgramTransitionEventTypeData();

    static void createTypes();
    static void clearStaticMembers();
    static void registerEventFields();
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // IntermediateResult
    void setIntermediateResult(const UaVariant&IntermediateResult);
    void setIntermediateResultStatus(OpcUa_StatusCode status);
    UaVariant getIntermediateResult();
    virtual void getIntermediateResultValue(Session* pSession, OpcUa_Variant& value);

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_ProgramTransitionEventTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUAPROGRAMTRANSITIONEVENTTYPE_H__
