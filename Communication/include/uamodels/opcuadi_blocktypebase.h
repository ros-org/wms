/******************************************************************************
** opcuadi_blocktypebase.h
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
** Project: C++ OPC Server SDK information model for namespace http://opcfoundation.org/UA/DI/
**
** Description: OPC Unified Architecture Software Development Kit.
**
******************************************************************************/

#ifndef __OPCUADI_BLOCKTYPEBASE_H__
#define __OPCUADI_BLOCKTYPEBASE_H__

#include "opcuadi_topologyelementtype.h"
#include "opcuadi_datatypes.h"
#include "basenodes.h"
#include "opcua_propertytype.h"
#include "opcuadi_identifiers.h"
#include "opcuadi_instancefactory_devices.h"

// Namespace for the UA information model http://opcfoundation.org/UA/DI/
namespace OpcUaDi {


/** Generated base class for a BlockType.
 *
 *  This class contains the generated base code for the object type BlockType
 *  representing an OPC UA ObjectType. This class is used to create the object type and to
 *  create and represent instances of the object type in the server address space.
 *
 *  **Variable members of the BlockType:**
 *
 *  Browse Name     | DataType      | TypeDefinition | Modelling Rule | See Also
 *  ----------------|---------------|----------------|----------------|-------------------------------------------------
 *  ActualMode      | LocalizedText | PropertyType   | Optional       | \ref getActualMode, \ref setActualMode
 *  NormalMode      | LocalizedText | PropertyType   | Optional       | \ref getNormalMode, \ref setNormalMode
 *  PermittedMode   | LocalizedText | PropertyType   | Optional       | \ref getPermittedMode, \ref setPermittedMode
 *  RevisionCounter | UInt32        | PropertyType   | Optional       | \ref getRevisionCounter, \ref setRevisionCounter
 *  TargetMode      | LocalizedText | PropertyType   | Optional       | \ref getTargetMode, \ref setTargetMode
 *
 */
class UAMODELS_EXPORT BlockTypeBase:
    public OpcUaDi::TopologyElementType
{
    UA_DISABLE_COPY(BlockTypeBase);
protected:
    virtual ~BlockTypeBase();
public:
    // construction / destruction
    BlockTypeBase(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    BlockTypeBase(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    BlockTypeBase(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;


    virtual void setActualMode(const UaLocalizedText& ActualMode);
    virtual UaLocalizedText getActualMode(Session* pSession) const;

    virtual void setNormalMode(const UaLocalizedTextArray& NormalMode);
    virtual void getNormalMode(UaLocalizedTextArray& NormalMode) const;

    virtual void setPermittedMode(const UaLocalizedTextArray& PermittedMode);
    virtual void getPermittedMode(UaLocalizedTextArray& PermittedMode) const;

    virtual void setRevisionCounter(OpcUa_UInt32 RevisionCounter);
    virtual OpcUa_UInt32 getRevisionCounter() const;

    virtual void setTargetMode(const UaLocalizedTextArray& TargetMode);
    virtual void getTargetMode(UaLocalizedTextArray& TargetMode) const;

    virtual OpcUa::PropertyType* getActualModeNode();
    virtual OpcUa::PropertyType* getNormalModeNode();
    virtual OpcUa::PropertyType* getPermittedModeNode();
    virtual OpcUa::PropertyType* getRevisionCounterNode();
    virtual OpcUa::PropertyType* getTargetModeNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(BlockTypeBase *pInstance);

protected:
    // Variable nodes
    // Variable ActualMode
    static OpcUa::PropertyType*  s_pActualMode;
    OpcUa::PropertyType*  m_pActualMode;
    // Variable NormalMode
    static OpcUa::PropertyType*  s_pNormalMode;
    OpcUa::PropertyType*  m_pNormalMode;
    // Variable PermittedMode
    static OpcUa::PropertyType*  s_pPermittedMode;
    OpcUa::PropertyType*  m_pPermittedMode;
    // Variable RevisionCounter
    static OpcUa::PropertyType*  s_pRevisionCounter;
    OpcUa::PropertyType*  m_pRevisionCounter;
    // Variable TargetMode
    static OpcUa::PropertyType*  s_pTargetMode;
    OpcUa::PropertyType*  m_pTargetMode;



private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/DI/

#endif // #ifndef __OPCUADIBLOCKTYPEBASE_H__


