/******************************************************************************
** opcua_arrayitemtype.h
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

#ifndef __OPCUA_ARRAYITEMTYPE_H__
#define __OPCUA_ARRAYITEMTYPE_H__

#include "opcua_dataitemtype.h"
#include "opcua_identifiers.h"
#include "uaeuinformation.h"
#include "uarange.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;

/** Implements OPC UA Variables of the type ArrayItemType
 *
 *  **Variable members of the ArrayItemType:**
 *
 *  Browse Name      | DataType             | TypeDefinition | Modelling Rule | See Also
 *  -----------------|----------------------|----------------|----------------|---------------------------------------------------
 *  AxisScaleType    | AxisScaleEnumeration | PropertyType   | Mandatory      | \ref getAxisScaleType, \ref setAxisScaleType
 *  EngineeringUnits | EUInformation        | PropertyType   | Mandatory      | \ref getEngineeringUnits, \ref setEngineeringUnits
 *  EURange          | Range                | PropertyType   | Mandatory      | \ref getEURange, \ref setEURange
 *  InstrumentRange  | Range                | PropertyType   | Optional       | \ref getInstrumentRange, \ref setInstrumentRange
 *  Title            | LocalizedText        | PropertyType   | Mandatory      | \ref getTitle, \ref setTitle
 *
 *  Abstract VariableType defining the general characteristics of an ArrayItem.
 *
 *  Values are exposed in an array, but the content of the array represents a
 *  single entity like an image. Other DataItems might contain arrays that
 *  represent for example several values of several temperature sensors of a
 *  boiler. ArrayItemType or its subtypes shall only be used when the \ref
 *  OpcUa::ArrayItemType::getTitle "getTitle" or \ref
 *  OpcUa::ArrayItemType::setTitle "setTitle" and \ref
 *  OpcUa::ArrayItemType::getAxisScaleType "getAxisScaleType" or \ref
 *  OpcUa::ArrayItemType::setAxisScaleType "setAxisScaleType" Properties can be
 *  filled with reasonable values. If this is not the case, \ref
 *  OpcUa::DataItemType "DataItemType" and subtypes like \ref OpcUa::AnalogItemType
 *  "AnalogItemType", which also support arrays, shall be used.
 *
 *  For additional information about InstrumentRange, EURange, and EngineeringUnits
 *  see the description of \ref OpcUa::AnalogItemType "AnalogItemType"
 *
 *  The StatusCode SemanticsChanged bit shall be set if any of the InstrumentRange,
 *  EURange, EngineeringUnits or Title Properties are changed
 *
 *  See also \ref Doc_OpcUa_ArrayItemType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT ArrayItemType:
    public OpcUa::DataItemType
{
    UA_DISABLE_COPY(ArrayItemType);
protected:
    virtual ~ArrayItemType();
public:
    ArrayItemType(
        UaNode*            pParentNode,
        UaVariable*        pInstanceDeclarationVariable,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    ArrayItemType(
        const UaNodeId&    nodeId,
        const UaString&    name,
        OpcUa_UInt16       browseNameNameSpaceIndex,
        const UaVariant&   initialValue,
        OpcUa_Byte         accessLevel,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    ArrayItemType(
        UaBase::Variable*  pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;

    virtual void setAxisScaleType(OpcUa_AxisScaleEnumeration AxisScaleType);
    virtual OpcUa_AxisScaleEnumeration getAxisScaleType() const;

    virtual void setEngineeringUnits(const UaEUInformation& EngineeringUnits);
    virtual UaEUInformation getEngineeringUnits() const;

    virtual void setEURange(const UaRange& EURange);
    virtual UaRange getEURange() const;

    virtual void setInstrumentRange(const UaRange& InstrumentRange);
    virtual UaRange getInstrumentRange() const;

    virtual void setTitle(const UaLocalizedText& Title);
    virtual UaLocalizedText getTitle(Session* pSession) const;

    virtual OpcUa::PropertyType* getAxisScaleTypeNode();
    virtual OpcUa::PropertyType* getEngineeringUnitsNode();
    virtual OpcUa::PropertyType* getEURangeNode();
    virtual OpcUa::PropertyType* getInstrumentRangeNode();
    virtual OpcUa::PropertyType* getTitleNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(ArrayItemType *pInstance);

protected:
    // Variable nodes
    // Variable AxisScaleType
    static OpcUa::PropertyType*  s_pAxisScaleType;
    OpcUa::PropertyType*  m_pAxisScaleType;
    // Variable EngineeringUnits
    static OpcUa::PropertyType*  s_pEngineeringUnits;
    OpcUa::PropertyType*  m_pEngineeringUnits;
    // Variable EURange
    static OpcUa::PropertyType*  s_pEURange;
    OpcUa::PropertyType*  m_pEURange;
    // Variable InstrumentRange
    static OpcUa::PropertyType*  s_pInstrumentRange;
    OpcUa::PropertyType*  m_pInstrumentRange;
    // Variable Title
    static OpcUa::PropertyType*  s_pTitle;
    OpcUa::PropertyType*  m_pTitle;


private:
    void initialize(NodeManagerConfig* pNodeConfig);

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUA_ARRAYITEMTYPE_H__

