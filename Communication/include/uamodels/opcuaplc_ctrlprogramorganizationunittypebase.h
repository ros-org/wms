/******************************************************************************
** opcuaplc_ctrlprogramorganizationunittypebase.h
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
** Project: C++ OPC Server SDK information model for namespace http://PLCopen.org/OpcUa/IEC61131-3/
**
** Description: OPC Unified Architecture Software Development Kit.
**
******************************************************************************/

#ifndef __OPCUAPLC_CTRLPROGRAMORGANIZATIONUNITTYPEBASE_H__
#define __OPCUAPLC_CTRLPROGRAMORGANIZATIONUNITTYPEBASE_H__

#include "opcuadi_blocktype.h"
#include "opcuaplc_datatypes.h"
#include "basenodes.h"
#include "opcua_basedatavariabletype.h"
#include "opcuaplc_identifiers.h"
#include "opcuaplc_instancefactory_plcopen.h"

// Namespace for the UA information model http://PLCopen.org/OpcUa/IEC61131-3/
namespace OpcUaPlc {


/** Generated base class for a CtrlProgramOrganizationUnitType.
 *
 *  This class contains the generated base code for the object type CtrlProgramOrganizationUnitType
 *  representing an OPC UA ObjectType. This class is used to create the object type and to
 *  create and represent instances of the object type in the server address space.
 *
 *  **Variable members of the CtrlProgramOrganizationUnitType:**
 *
 *  Browse Name | DataType   | TypeDefinition       | Modelling Rule | See Also
 *  ------------|------------|----------------------|----------------|---------------------------
 *  Body        | XmlElement | BaseDataVariableType | Optional       | \ref getBody, \ref setBody
 *
 */
class UAMODELS_EXPORT CtrlProgramOrganizationUnitTypeBase:
    public OpcUaDi::BlockType
{
    UA_DISABLE_COPY(CtrlProgramOrganizationUnitTypeBase);
protected:
    virtual ~CtrlProgramOrganizationUnitTypeBase();
public:
    // construction / destruction
    CtrlProgramOrganizationUnitTypeBase(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    CtrlProgramOrganizationUnitTypeBase(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    CtrlProgramOrganizationUnitTypeBase(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;


    virtual void setBody(UaByteString& Body);
    virtual UaByteString getBody() const;

    virtual OpcUa::BaseDataVariableType* getBodyNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(CtrlProgramOrganizationUnitTypeBase *pInstance);

protected:
    // Variable nodes
    // Variable Body
    static OpcUa::BaseDataVariableType*  s_pBody;
    OpcUa::BaseDataVariableType*  m_pBody;



private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://PLCopen.org/OpcUa/IEC61131-3/

#endif // #ifndef __OPCUAPLCCTRLPROGRAMORGANIZATIONUNITTYPEBASE_H__


