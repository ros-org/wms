/******************************************************************************
** opcua_baseeventtype.h
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
#ifndef __OPCUA_BASEEVENTTYPE_H__
#define __OPCUA_BASEEVENTTYPE_H__

#include "uaeventdata.h"
#include "opcua_baseobjecttype.h"
#include "opcua_propertytype.h"
#include "basenodes.h"

class XmlUaNodeFactoryManager;

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class SERVER_CORE_EXPORT BaseEventType:
    public BaseObjectType,
    public BaseEventTypeData
{
    UA_DISABLE_COPY(BaseEventType);
protected:
    // Destruction
    virtual ~BaseEventType();
public:
    // Construction
    BaseEventType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    BaseEventType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    BaseEventType(
        UaBase::Object*    pObject,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex);
    static void createTypes();
    static void clearStaticMembers();

    // Type definition for the object
    virtual UaNodeId typeDefinitionId() const;

    // Source name event field
    virtual void setSourceNode(const UaNodeId& sourceNode);
    virtual UaNodeId getSourceNode() const;
    virtual void setSourceName(const UaString& sourceName);
    virtual UaString getSourceName() const;

    // Message event field
    virtual void setMessage(const UaLocalizedText& message);
    virtual void setMessageStatus(OpcUa_StatusCode status);
    virtual UaLocalizedText getMessage() const;

    // Severity event field
    virtual void setSeverity(OpcUa_UInt16 severity);
    virtual void setSeverityStatus(OpcUa_StatusCode status);
    virtual OpcUa_UInt16 getSeverity() const;

    // Time event field
    virtual void setTimeStatus(OpcUa_StatusCode status);

    // LocalTime event field
    virtual void setLocalTime(const UaTimeZoneDataType& localTime);
    virtual UaTimeZoneDataType getLocalTime() const;

    // Access to nodes
    virtual OpcUa::PropertyType* getEventIdNode();
    virtual OpcUa::PropertyType* getEventTypeNode();
    virtual OpcUa::PropertyType* getSourceNodeNode();
    virtual OpcUa::PropertyType* getSourceNameNode();
    virtual OpcUa::PropertyType* getTimeNode();
    virtual OpcUa::PropertyType* getReceiveTimeNode();
    virtual OpcUa::PropertyType* getLocalTimeNode();
    virtual OpcUa::PropertyType* getMessageNode();
    virtual OpcUa::PropertyType* getSeverityNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(BaseEventType *pOther);

    virtual UaStatus triggerEvent(
        const UaDateTime&   time,
        const UaDateTime&   receiveTime,
        const UaByteString& eventId);

    /** Lock the access to the object */
    inline void lock(){m_pSharedMutex->lock();}

    /** Unlock the access to the object */
    inline void unlock(){m_pSharedMutex->unlock();}

protected:
    virtual OpcUa_StatusCode sendEvent(UaEventData* pEventData);

protected:
    // Property EventId
    static OpcUa::PropertyType*  s_pEventId;
    OpcUa::PropertyType*  m_pEventId;
    // Property EventType
    static OpcUa::PropertyType*  s_pEventType;
    OpcUa::PropertyType*  m_pEventTypeProperty;
    // Property SourceNode
    static OpcUa::PropertyType*  s_pSourceNode;
    OpcUa::PropertyType*  m_pSourceNode;
    // Property SourceName
    static OpcUa::PropertyType*  s_pSourceName;
    OpcUa::PropertyType*  m_pSourceName;
    // Property Time
    static OpcUa::PropertyType*  s_pTime;
    OpcUa::PropertyType*  m_pTime;
    // Property ReceiveTime
    static OpcUa::PropertyType*  s_pReceiveTime;
    OpcUa::PropertyType*  m_pReceiveTime;
    // Property LocalTime
    static OpcUa::PropertyType*  s_pLocalTime;
    OpcUa::PropertyType*  m_pLocalTime;
    // Property Message
    static OpcUa::PropertyType*  s_pMessage;
    OpcUa::PropertyType*  m_pMessage;
    // Property Severity
    static OpcUa::PropertyType*  s_pSeverity;
    OpcUa::PropertyType*  m_pSeverity;

    // ToDo Remove
    UaString m_defaultLocaleId;

private:
    void initialize(const UaNodeId& sourceNode, const UaString& sourceName);
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUA_BASEEVENTTYPE_H__

