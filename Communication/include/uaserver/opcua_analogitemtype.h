/******************************************************************************
** opcua_analogitemtype.h
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

#ifndef __OPCUA_ANALOGITEMTYPE_H__
#define __OPCUA_ANALOGITEMTYPE_H__

#include "opcua_dataitemtype.h"
#include "opcua_identifiers.h"
#include "uaeuinformation.h"
#include "uarange.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;

/** Implements OPC UA Variables of the type AnalogItemType
 *
 *  **Variable members of the AnalogItemType:**
 *
 *  Browse Name      | DataType      | TypeDefinition | Modelling Rule | See Also
 *  -----------------|---------------|----------------|----------------|---------------------------------------------------
 *  EngineeringUnits | EUInformation | PropertyType   | Optional       | \ref getEngineeringUnits, \ref setEngineeringUnits
 *  EURange          | Range         | PropertyType   | Mandatory      | \ref getEURange, \ref setEURange
 *  InstrumentRange  | Range         | PropertyType   | Optional       | \ref getInstrumentRange, \ref setInstrumentRange
 *
 *  This VariableType defines the general characteristics of an AnalogItem.
 *
 *  The AnalogItemType derives from the DataItemType.
 *
 *  The StatusCode delivered with the value also contains an informational bit
 *  called SemanticsChanged. Servers that implement Data Access shall set this Bit
 *  in notifications if EURange (could change the behaviour of a Subscription if a
 *  PercentDeadband filter is used) or EngineeringUnits (could create problems if
 *  the client uses the value to perform calculations) Properties are changed.
 *  Clients that use any of these Properties should re-read them before they
 *  process the data value.
 *
 *  In addition a server can send SemanticChangeEvents if the value of the
 *  properties EURange and EngineeringUnits are changed. To indicate this
 *  capability, the SemanticChange flag must be set in the AccessLevel and
 *  UserAccessLevel attributes of this variable.
 *
 *  See also \ref Doc_OpcUa_AnalogItemType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT AnalogItemType:
    public OpcUa::DataItemType
{
    UA_DISABLE_COPY(AnalogItemType);
protected:
    virtual ~AnalogItemType();
public:
    AnalogItemType(
        UaNode*            pParentNode,
        UaVariable*        pInstanceDeclarationVariable,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    AnalogItemType(
        const UaNodeId&    nodeId,
        const UaString&    name,
        OpcUa_UInt16       browseNameNameSpaceIndex,
        const UaVariant&   initialValue,
        OpcUa_Byte         accessLevel,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    AnalogItemType(
        UaBase::Variable*  pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;

    virtual void setEngineeringUnits(const UaEUInformation& EngineeringUnits);
    virtual UaEUInformation getEngineeringUnits() const;

    virtual void setEURange(const UaRange& EURange);
    virtual UaRange getEURange() const;

    virtual void setInstrumentRange(const UaRange& InstrumentRange);
    virtual UaRange getInstrumentRange() const;

    virtual OpcUa::PropertyType* getEngineeringUnitsNode();
    virtual OpcUa::PropertyType* getEURangeNode();
    virtual OpcUa::PropertyType* getInstrumentRangeNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(AnalogItemType *pInstance);

protected:
    // Variable nodes
    // Variable EngineeringUnits
    static OpcUa::PropertyType*  s_pEngineeringUnits;
    OpcUa::PropertyType*  m_pEngineeringUnits;
    // Variable EURange
    static OpcUa::PropertyType*  s_pEURange;
    OpcUa::PropertyType*  m_pEURange;
    // Variable InstrumentRange
    static OpcUa::PropertyType*  s_pInstrumentRange;
    OpcUa::PropertyType*  m_pInstrumentRange;


private:
    void initialize(NodeManagerConfig* pNodeConfig);

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUA_ANALOGITEMTYPE_H__

