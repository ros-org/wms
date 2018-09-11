/******************************************************************************
** opcua_cubeitemtype.h
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

#ifndef __OPCUA_CUBEITEMTYPE_H__
#define __OPCUA_CUBEITEMTYPE_H__

#include "opcua_arrayitemtype.h"
#include "opcua_identifiers.h"
#include "uaaxisinformation.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;

/** Implements OPC UA Variables of the type CubeItemType
 *
 *  **Variable members of the CubeItemType:**
 *
 *  Browse Name     | DataType        | TypeDefinition | Modelling Rule | See Also
 *  ----------------|-----------------|----------------|----------------|-------------------------------------------------
 *  XAxisDefinition | AxisInformation | PropertyType   | Mandatory      | \ref getXAxisDefinition, \ref setXAxisDefinition
 *  YAxisDefinition | AxisInformation | PropertyType   | Mandatory      | \ref getYAxisDefinition, \ref setYAxisDefinition
 *  ZAxisDefinition | AxisInformation | PropertyType   | Mandatory      | \ref getZAxisDefinition, \ref setZAxisDefinition
 *
 *  Represents a cube of values like a spatial particle distribution, where the
 *  particle position is given by X which is the column, Y the row and Z the depth.
 *
 *  In the example of a spatial partical distribution, the value is the particle
 *  size.
 *
 *  Engineering units and range for the Value are defined by corresponding
 *  Properties inherited from the \ref OpcUa::ArrayItemType "ArrayItemType".
 *
 *  The DataType of this VariableType is restricted to SByte, Int16, Int32, Int64,
 *  Float, Double, ComplexNumberType and DoubleComplexNumberType.
 *
 *  The ArrayDimensions Attribute for Variables of this type or subtypes should use
 *  the first entry in the array ([0]) to define the number of columns, the second
 *  entry ([1]) to define the number of rows, and the third entry ([2]) define the
 *  number of steps in the Z axis, assuming the size of the matrix is not dynamic.
 *
 *  The StatusCode SemanticsChanged bit shall be set if any of the InstrumentRange,
 *  EURange, EngineeringUnits, Title, XAxisDefinition, YAxisDefinition or
 *  ZAxisDefinition Properties are changed.
 *
 *  See also \ref Doc_OpcUa_CubeItemType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT CubeItemType:
    public OpcUa::ArrayItemType
{
    UA_DISABLE_COPY(CubeItemType);
protected:
    virtual ~CubeItemType();
public:
    CubeItemType(
        UaNode*            pParentNode,
        UaVariable*        pInstanceDeclarationVariable,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    CubeItemType(
        const UaNodeId&    nodeId,
        const UaString&    name,
        OpcUa_UInt16       browseNameNameSpaceIndex,
        const UaVariant&   initialValue,
        OpcUa_Byte         accessLevel,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    CubeItemType(
        UaBase::Variable*  pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;

    virtual void setXAxisDefinition(const UaAxisInformation& XAxisDefinition);
    virtual UaAxisInformation getXAxisDefinition() const;

    virtual void setYAxisDefinition(const UaAxisInformation& YAxisDefinition);
    virtual UaAxisInformation getYAxisDefinition() const;

    virtual void setZAxisDefinition(const UaAxisInformation& ZAxisDefinition);
    virtual UaAxisInformation getZAxisDefinition() const;

    virtual OpcUa::PropertyType* getXAxisDefinitionNode();
    virtual OpcUa::PropertyType* getYAxisDefinitionNode();
    virtual OpcUa::PropertyType* getZAxisDefinitionNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(CubeItemType *pInstance);

protected:
    // Variable nodes
    // Variable XAxisDefinition
    static OpcUa::PropertyType*  s_pXAxisDefinition;
    OpcUa::PropertyType*  m_pXAxisDefinition;
    // Variable YAxisDefinition
    static OpcUa::PropertyType*  s_pYAxisDefinition;
    OpcUa::PropertyType*  m_pYAxisDefinition;
    // Variable ZAxisDefinition
    static OpcUa::PropertyType*  s_pZAxisDefinition;
    OpcUa::PropertyType*  m_pZAxisDefinition;


private:
    void initialize(NodeManagerConfig* pNodeConfig);

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUA_CUBEITEMTYPE_H__

