/******************************************************************************
** opcua_conditionvariabletype.h
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

#ifndef __OPCUA_CONDITIONVARIABLETYPE_H__
#define __OPCUA_CONDITIONVARIABLETYPE_H__

#include "opcua_basedatavariabletype.h"
#include "opcua_identifiers.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;

/** Implements OPC UA Variables of the type ConditionVariableType
 *
 *  **Variable members of the ConditionVariableType:**
 *
 *  Browse Name     | DataType | TypeDefinition | Modelling Rule | See Also
 *  ----------------|----------|----------------|----------------|-------------------------------------------------
 *  SourceTimestamp | UtcTime  | PropertyType   | Mandatory      | \ref getSourceTimestamp, \ref setSourceTimestamp
 *
 *  Various information elements of a Condition are not considered to be states.
 *  However, a change in their value is considered important and supposed to
 *  trigger an Event Notification. These information elements are called
 *  ConditionVariables. ConditionVariables are represented by a
 *  ConditionVariableType. It defines the mandatory Property SourceTimestamp.
 *
 *  See also \ref Doc_OpcUa_ConditionVariableType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT ConditionVariableType:
    public OpcUa::BaseDataVariableType
{
    UA_DISABLE_COPY(ConditionVariableType);
protected:
    virtual ~ConditionVariableType();
public:
    ConditionVariableType(
        UaNode*            pParentNode,
        UaVariable*        pInstanceDeclarationVariable,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    ConditionVariableType(
        const UaNodeId&    nodeId,
        const UaString&    name,
        OpcUa_UInt16       browseNameNameSpaceIndex,
        const UaVariant&   initialValue,
        OpcUa_Byte         accessLevel,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    ConditionVariableType(
        UaBase::Variable*  pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;

    virtual void setSourceTimestamp(const UaDateTime& SourceTimestamp);
    virtual UaDateTime getSourceTimestamp() const;

    virtual OpcUa::PropertyType* getSourceTimestampNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(ConditionVariableType *pInstance);

    // Addition to generated code begin
    virtual UaStatus setValue(Session* pSession, const UaDataValue& dataValue, OpcUa_Boolean checkAccessLevel);
    // Addition to generated code end

protected:
    // Variable nodes
    // Variable SourceTimestamp
    static OpcUa::PropertyType*  s_pSourceTimestamp;
    OpcUa::PropertyType*  m_pSourceTimestamp;


private:
    void initialize(NodeManagerConfig* pNodeConfig);

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUA_CONDITIONVARIABLETYPE_H__

