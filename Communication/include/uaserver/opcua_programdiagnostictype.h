/******************************************************************************
** opcua_programdiagnostictype.h
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

#ifndef __OPCUA_PROGRAMDIAGNOSTICTYPE_H__
#define __OPCUA_PROGRAMDIAGNOSTICTYPE_H__

#include "opcua_basedatavariabletype.h"
#include "opcua_identifiers.h"
#include "uaargument.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;

/** Implements OPC UA Variables of the type ProgramDiagnosticType
 *
 *  **Variable members of the ProgramDiagnosticType:**
 *
 *  Browse Name               | DataType     | TypeDefinition | Modelling Rule | See Also
 *  --------------------------|--------------|----------------|----------------|---------------------------------------------------------------------
 *  CreateClientName          | String       | PropertyType   | Mandatory      | \ref getCreateClientName, \ref setCreateClientName
 *  CreateSessionId           | NodeId       | PropertyType   | Mandatory      | \ref getCreateSessionId, \ref setCreateSessionId
 *  InvocationCreationTime    | UtcTime      | PropertyType   | Mandatory      | \ref getInvocationCreationTime, \ref setInvocationCreationTime
 *  LastMethodCall            | String       | PropertyType   | Mandatory      | \ref getLastMethodCall, \ref setLastMethodCall
 *  LastMethodCallTime        | UtcTime      | PropertyType   | Mandatory      | \ref getLastMethodCallTime, \ref setLastMethodCallTime
 *  LastMethodInputArguments  | Argument     | PropertyType   | Mandatory      | \ref getLastMethodInputArguments, \ref setLastMethodInputArguments
 *  LastMethodOutputArguments | Argument     | PropertyType   | Mandatory      | \ref getLastMethodOutputArguments, \ref setLastMethodOutputArguments
 *  LastMethodReturnStatus    | StatusResult | PropertyType   | Mandatory      | \ref getLastMethodReturnStatus, \ref setLastMethodReturnStatus
 *  LastMethodSessionId       | NodeId       | PropertyType   | Mandatory      | \ref getLastMethodSessionId, \ref setLastMethodSessionId
 *  LastTransitionTime        | UtcTime      | PropertyType   | Mandatory      | \ref getLastTransitionTime, \ref setLastTransitionTime
 *
 */
class SERVER_CORE_EXPORT ProgramDiagnosticType:
    public OpcUa::BaseDataVariableType
{
    UA_DISABLE_COPY(ProgramDiagnosticType);
protected:
    virtual ~ProgramDiagnosticType();
public:
    ProgramDiagnosticType(
        UaNode*            pParentNode,
        UaVariable*        pInstanceDeclarationVariable,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    ProgramDiagnosticType(
        const UaNodeId&    nodeId,
        const UaString&    name,
        OpcUa_UInt16       browseNameNameSpaceIndex,
        const UaVariant&   initialValue,
        OpcUa_Byte         accessLevel,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    ProgramDiagnosticType(
        UaBase::Variable*  pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;

    virtual void setCreateClientName(const UaString& CreateClientName);
    virtual UaString getCreateClientName() const;

    virtual void setCreateSessionId(const UaNodeId& CreateSessionId);
    virtual UaNodeId getCreateSessionId() const;

    virtual void setInvocationCreationTime(const UaDateTime& InvocationCreationTime);
    virtual UaDateTime getInvocationCreationTime() const;

    virtual void setLastMethodCall(const UaString& LastMethodCall);
    virtual UaString getLastMethodCall() const;

    virtual void setLastMethodCallTime(const UaDateTime& LastMethodCallTime);
    virtual UaDateTime getLastMethodCallTime() const;

    virtual void setLastMethodInputArguments(const UaArguments& LastMethodInputArguments);
    virtual void getLastMethodInputArguments(UaArguments& LastMethodInputArguments) const;

    virtual void setLastMethodOutputArguments(const UaArguments& LastMethodOutputArguments);
    virtual void getLastMethodOutputArguments(UaArguments& LastMethodOutputArguments) const;

    virtual void setLastMethodReturnStatus(const UaStatus& LastMethodReturnStatus);
    virtual UaStatus getLastMethodReturnStatus() const;

    virtual void setLastMethodSessionId(const UaNodeId& LastMethodSessionId);
    virtual UaNodeId getLastMethodSessionId() const;

    virtual void setLastTransitionTime(const UaDateTime& LastTransitionTime);
    virtual UaDateTime getLastTransitionTime() const;

    virtual OpcUa::PropertyType* getCreateClientNameNode();
    virtual const OpcUa::PropertyType* getCreateClientNameNode() const;
    virtual OpcUa::PropertyType* getCreateSessionIdNode();
    virtual const OpcUa::PropertyType* getCreateSessionIdNode() const;
    virtual OpcUa::PropertyType* getInvocationCreationTimeNode();
    virtual const OpcUa::PropertyType* getInvocationCreationTimeNode() const;
    virtual OpcUa::PropertyType* getLastMethodCallNode();
    virtual const OpcUa::PropertyType* getLastMethodCallNode() const;
    virtual OpcUa::PropertyType* getLastMethodCallTimeNode();
    virtual const OpcUa::PropertyType* getLastMethodCallTimeNode() const;
    virtual OpcUa::PropertyType* getLastMethodInputArgumentsNode();
    virtual const OpcUa::PropertyType* getLastMethodInputArgumentsNode() const;
    virtual OpcUa::PropertyType* getLastMethodOutputArgumentsNode();
    virtual const OpcUa::PropertyType* getLastMethodOutputArgumentsNode() const;
    virtual OpcUa::PropertyType* getLastMethodReturnStatusNode();
    virtual const OpcUa::PropertyType* getLastMethodReturnStatusNode() const;
    virtual OpcUa::PropertyType* getLastMethodSessionIdNode();
    virtual const OpcUa::PropertyType* getLastMethodSessionIdNode() const;
    virtual OpcUa::PropertyType* getLastTransitionTimeNode();
    virtual const OpcUa::PropertyType* getLastTransitionTimeNode() const;

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(ProgramDiagnosticType *pInstance);

protected:
    // Variable nodes
    // Variable CreateClientName
    static OpcUa::PropertyType*  s_pCreateClientName;
    OpcUa::PropertyType*  m_pCreateClientName;
    // Variable CreateSessionId
    static OpcUa::PropertyType*  s_pCreateSessionId;
    OpcUa::PropertyType*  m_pCreateSessionId;
    // Variable InvocationCreationTime
    static OpcUa::PropertyType*  s_pInvocationCreationTime;
    OpcUa::PropertyType*  m_pInvocationCreationTime;
    // Variable LastMethodCall
    static OpcUa::PropertyType*  s_pLastMethodCall;
    OpcUa::PropertyType*  m_pLastMethodCall;
    // Variable LastMethodCallTime
    static OpcUa::PropertyType*  s_pLastMethodCallTime;
    OpcUa::PropertyType*  m_pLastMethodCallTime;
    // Variable LastMethodInputArguments
    static OpcUa::PropertyType*  s_pLastMethodInputArguments;
    OpcUa::PropertyType*  m_pLastMethodInputArguments;
    // Variable LastMethodOutputArguments
    static OpcUa::PropertyType*  s_pLastMethodOutputArguments;
    OpcUa::PropertyType*  m_pLastMethodOutputArguments;
    // Variable LastMethodReturnStatus
    static OpcUa::PropertyType*  s_pLastMethodReturnStatus;
    OpcUa::PropertyType*  m_pLastMethodReturnStatus;
    // Variable LastMethodSessionId
    static OpcUa::PropertyType*  s_pLastMethodSessionId;
    OpcUa::PropertyType*  m_pLastMethodSessionId;
    // Variable LastTransitionTime
    static OpcUa::PropertyType*  s_pLastTransitionTime;
    OpcUa::PropertyType*  m_pLastTransitionTime;


private:
    void initialize(NodeManagerConfig* pNodeConfig);

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUA_PROGRAMDIAGNOSTICTYPE_H__

