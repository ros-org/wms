/******************************************************************************
** opcua_ndimensionarrayitemtype.h
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

#ifndef __OPCUA_NDIMENSIONARRAYITEMTYPE_H__
#define __OPCUA_NDIMENSIONARRAYITEMTYPE_H__

#include "opcua_arrayitemtype.h"
#include "opcua_identifiers.h"
#include "uaaxisinformation.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;

/** Implements OPC UA Variables of the type NDimensionArrayItemType
 *
 *  **Variable members of the NDimensionArrayItemType:**
 *
 *  Browse Name    | DataType        | TypeDefinition | Modelling Rule | See Also
 *  ---------------|-----------------|----------------|----------------|-----------------------------------------------
 *  AxisDefinition | AxisInformation | PropertyType   | Mandatory      | \ref getAxisDefinition, \ref setAxisDefinition
 *
 *  This VariableType defines a generic multi-dimensional ArrayItem.
 *
 *  This approach minimizes the number of types, however it may be proved more
 *  difficult to utilize for control system interactions.
 *
 *  The DataType of this VariableType is restricted to SByte, Int16, Int32, Int64,
 *  Float, Double, ComplexNumberType and DoubleComplexNumberType.
 *
 *  The StatusCode SemanticsChanged bit shall be set if any of the InstrumentRange,
 *  EURange, EngineeringUnits, Title or AxisDefinition Properties are changed
 *
 *  See also \ref Doc_OpcUa_NDimensionArrayItemType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT NDimensionArrayItemType:
    public OpcUa::ArrayItemType
{
    UA_DISABLE_COPY(NDimensionArrayItemType);
protected:
    virtual ~NDimensionArrayItemType();
public:
    NDimensionArrayItemType(
        UaNode*            pParentNode,
        UaVariable*        pInstanceDeclarationVariable,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    NDimensionArrayItemType(
        const UaNodeId&    nodeId,
        const UaString&    name,
        OpcUa_UInt16       browseNameNameSpaceIndex,
        const UaVariant&   initialValue,
        OpcUa_Byte         accessLevel,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    NDimensionArrayItemType(
        UaBase::Variable*  pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;

    virtual void setAxisDefinition(const UaAxisInformations& AxisDefinition);
    virtual void getAxisDefinition(UaAxisInformations& AxisDefinition) const;

    virtual OpcUa::PropertyType* getAxisDefinitionNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(NDimensionArrayItemType *pInstance);

protected:
    // Variable nodes
    // Variable AxisDefinition
    static OpcUa::PropertyType*  s_pAxisDefinition;
    OpcUa::PropertyType*  m_pAxisDefinition;


private:
    void initialize(NodeManagerConfig* pNodeConfig);

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUA_NDIMENSIONARRAYITEMTYPE_H__

