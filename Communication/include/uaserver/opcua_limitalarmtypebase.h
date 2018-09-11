/******************************************************************************
** opcua_limitalarmtypebase.h
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

#ifndef __OPCUA_LIMITALARMTYPEBASE_H__
#define __OPCUA_LIMITALARMTYPEBASE_H__

#include "opcua_alarmconditiontype.h"
#include "basenodes.h"
#include "opcua_identifiers.h"
#include "opcua_propertytype.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class LimitAlarmTypeBase;
class PropertyType;

/** Generated event data class for a LimitAlarmType.
 *
 *  This class contains the auto generated code for the object type LimitAlarmType
 *  providing UaEventData interface for the access to event data containing the current state of the
 *  condition for events sent to the client. The class is used for condition events if the condition has
 *  no nodes in the address space or for condition branches created as snapshot of the main branch.
 *
 *  **Event Fields of the LimitAlarmType:**
 *
 *  Browse Name   | DataType | TypeDefinition | Modelling Rule | See Also
 *  --------------|----------|----------------|----------------|---------------------------------------------
 *  HighHighLimit | Double   | PropertyType   | Optional       | \ref getHighHighLimit, \ref setHighHighLimit
 *  HighLimit     | Double   | PropertyType   | Optional       | \ref getHighLimit, \ref setHighLimit
 *  LowLimit      | Double   | PropertyType   | Optional       | \ref getLowLimit, \ref setLowLimit
 *  LowLowLimit   | Double   | PropertyType   | Optional       | \ref getLowLowLimit, \ref setLowLowLimit

 *  An abstract type used to provide a base Type for AlarmConditions with multiple
 *  limits
 *
 *  Alarms can be modelled with multiple exclusive substates and assigned limits or
 *  they may be modelled with non exclusive limits that can be used to group
 *  multiple states together.
 *
 *  Four optional limits are defined that configure the states of the derived limit
 *  Alarm Types: HighHighLimit, HighLimit, LowLimit, and LowLowLimit. These
 *  Properties shall be set for any Alarm limits that are exposed by the derived
 *  limit Alarm Types. These Properties are listed as optional but at least one is
 *  required. For cases where an underlying system cannot provide the actual value
 *  of a limit, the limit Property shall still be provided, but will have its
 *  AccessLevel set to not readable. It is assumed that the limits are described
 *  using the same Engineering Unit that is assigned to the variable that is the
 *  source of the alarm. For Rate of change limit alarms, it is assumed this rate
 *  is units per second unless otherwise specified.
 *
 *  The Alarm limits listed may cause an Alarm to be generated when a value equals
 *  the limit or it may generate the Alarm when the limit is exceeded, (i.e. the
 *  Value is above the limit for HighLimit and below the limit for LowLimit). The
 *  exact behaviour when the value is equal to the limit is Server specific.
 *
 *  See also \ref Doc_OpcUa_LimitAlarmType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT LimitAlarmTypeData:
    public OpcUa::AlarmConditionTypeData
{
    UA_DISABLE_COPY(LimitAlarmTypeData);
protected:
    virtual ~LimitAlarmTypeData();
public:
    LimitAlarmTypeData();
    void initializeAsBranch(LimitAlarmTypeBase* pCondition);
    void initializeAsBranch(LimitAlarmTypeData* pConditionData);
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // HighHighLimit
    void setHighHighLimit(OpcUa_Double HighHighLimit);
    void setHighHighLimitStatus(OpcUa_StatusCode status);
    OpcUa_Double getHighHighLimit();
    virtual void getHighHighLimitValue(Session* pSession, OpcUa_Variant& value);
    // HighLimit
    void setHighLimit(OpcUa_Double HighLimit);
    void setHighLimitStatus(OpcUa_StatusCode status);
    OpcUa_Double getHighLimit();
    virtual void getHighLimitValue(Session* pSession, OpcUa_Variant& value);
    // LowLimit
    void setLowLimit(OpcUa_Double LowLimit);
    void setLowLimitStatus(OpcUa_StatusCode status);
    OpcUa_Double getLowLimit();
    virtual void getLowLimitValue(Session* pSession, OpcUa_Variant& value);
    // LowLowLimit
    void setLowLowLimit(OpcUa_Double LowLowLimit);
    void setLowLowLimitStatus(OpcUa_StatusCode status);
    OpcUa_Double getLowLowLimit();
    virtual void getLowLowLimitValue(Session* pSession, OpcUa_Variant& value);


private:
    void initialize();

private:
    UaObjectPointerArray<UaVariant> m_FieldValues;
};


/** Generated base class for a LimitAlarmType.
 *
 *  This class contains the auto generated code for the object type LimitAlarmType
 *  representing an OPC UA condition type. This class is used to create the condition type and to
 *  create and represent the condition object in the server address space. It provides also the UaEventData
 *  interface for the access to event data containing the current state of the condition for events sent to
 *  the client.
 *
 *  **Variable members of the LimitAlarmType:**
 *
 *  Browse Name   | DataType | TypeDefinition | Modelling Rule | See Also
 *  --------------|----------|----------------|----------------|---------------------------------------------
 *  HighHighLimit | Double   | PropertyType   | Optional       | \ref getHighHighLimit, \ref setHighHighLimit
 *  HighLimit     | Double   | PropertyType   | Optional       | \ref getHighLimit, \ref setHighLimit
 *  LowLimit      | Double   | PropertyType   | Optional       | \ref getLowLimit, \ref setLowLimit
 *  LowLowLimit   | Double   | PropertyType   | Optional       | \ref getLowLowLimit, \ref setLowLowLimit
 *
 *
 *  An abstract type used to provide a base Type for AlarmConditions with multiple
 *  limits
 *
 *  Alarms can be modelled with multiple exclusive substates and assigned limits or
 *  they may be modelled with non exclusive limits that can be used to group
 *  multiple states together.
 *
 *  Four optional limits are defined that configure the states of the derived limit
 *  Alarm Types: HighHighLimit, HighLimit, LowLimit, and LowLowLimit. These
 *  Properties shall be set for any Alarm limits that are exposed by the derived
 *  limit Alarm Types. These Properties are listed as optional but at least one is
 *  required. For cases where an underlying system cannot provide the actual value
 *  of a limit, the limit Property shall still be provided, but will have its
 *  AccessLevel set to not readable. It is assumed that the limits are described
 *  using the same Engineering Unit that is assigned to the variable that is the
 *  source of the alarm. For Rate of change limit alarms, it is assumed this rate
 *  is units per second unless otherwise specified.
 *
 *  The Alarm limits listed may cause an Alarm to be generated when a value equals
 *  the limit or it may generate the Alarm when the limit is exceeded, (i.e. the
 *  Value is above the limit for HighLimit and below the limit for LowLimit). The
 *  exact behaviour when the value is equal to the limit is Server specific.
 *
 *  See also \ref Doc_OpcUa_LimitAlarmType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT LimitAlarmTypeBase:
    public OpcUa::AlarmConditionType
{
    friend class LimitAlarmTypeData;
    UA_DISABLE_COPY(LimitAlarmTypeBase);
protected:
    // destruction
    virtual ~LimitAlarmTypeBase();
public:
    // construction
    LimitAlarmTypeBase(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    LimitAlarmTypeBase(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    LimitAlarmTypeBase(
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


    // HighHighLimit
    virtual void setHighHighLimit(OpcUa_Double HighHighLimit);
    virtual OpcUa_Double getHighHighLimit() const;
    virtual void setHighHighLimitStatus(OpcUa_StatusCode status);
    virtual void getHighHighLimitValue(Session* pSession, UaVariant& value);
    // HighLimit
    virtual void setHighLimit(OpcUa_Double HighLimit);
    virtual OpcUa_Double getHighLimit() const;
    virtual void setHighLimitStatus(OpcUa_StatusCode status);
    virtual void getHighLimitValue(Session* pSession, UaVariant& value);
    // LowLimit
    virtual void setLowLimit(OpcUa_Double LowLimit);
    virtual OpcUa_Double getLowLimit() const;
    virtual void setLowLimitStatus(OpcUa_StatusCode status);
    virtual void getLowLimitValue(Session* pSession, UaVariant& value);
    // LowLowLimit
    virtual void setLowLowLimit(OpcUa_Double LowLowLimit);
    virtual OpcUa_Double getLowLowLimit() const;
    virtual void setLowLowLimitStatus(OpcUa_StatusCode status);
    virtual void getLowLowLimitValue(Session* pSession, UaVariant& value);

    virtual OpcUa::PropertyType* getHighHighLimitNode();
    virtual OpcUa::PropertyType* getHighLimitNode();
    virtual OpcUa::PropertyType* getLowLimitNode();
    virtual OpcUa::PropertyType* getLowLowLimitNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(LimitAlarmTypeBase *pInstance);

    virtual UaStatus triggerEvent(
        const UaDateTime&   time,
        const UaDateTime&   receiveTime,
        const UaByteString& eventId);

    virtual void getLimitAlarmTypeOptionalFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

protected:
    // Variable nodes
    // Variable HighHighLimit
    static OpcUa::PropertyType*  s_pHighHighLimit;
    OpcUa::PropertyType*  m_pHighHighLimit;
    // Variable HighLimit
    static OpcUa::PropertyType*  s_pHighLimit;
    OpcUa::PropertyType*  m_pHighLimit;
    // Variable LowLimit
    static OpcUa::PropertyType*  s_pLowLimit;
    OpcUa::PropertyType*  m_pLowLimit;
    // Variable LowLowLimit
    static OpcUa::PropertyType*  s_pLowLowLimit;
    OpcUa::PropertyType*  m_pLowLowLimit;



private:
    void initialize();
    void createChildren();

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_LimitAlarmTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUALIMITALARMTYPEBASE_H__

