/******************************************************************************
** opcua_xyarrayitemtype.h
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

#ifndef __OPCUA_XYARRAYITEMTYPE_H__
#define __OPCUA_XYARRAYITEMTYPE_H__

#include "opcua_arrayitemtype.h"
#include "opcua_identifiers.h"
#include "uaaxisinformation.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;

/** Implements OPC UA Variables of the type XYArrayItemType
 *
 *  **Variable members of the XYArrayItemType:**
 *
 *  Browse Name     | DataType        | TypeDefinition | Modelling Rule | See Also
 *  ----------------|-----------------|----------------|----------------|-------------------------------------------------
 *  XAxisDefinition | AxisInformation | PropertyType   | Mandatory      | \ref getXAxisDefinition, \ref setXAxisDefinition
 *
 *  Represents a vector of XVType values, like a list of peaks, where XVType.x is
 *  theposition of the peak and XVType.value is its intensity.
 *
 *  The Value of the XYArrayItem contains an array of structures (XVType) where
 *  each structure specifies the position for the X-Axis (XVType.x) and the value
 *  itself (XVType.value), used for the Y-Axis. Engineering units and range for the
 *  Value are defined by corresponding Properties inherited from the \ref
 *  OpcUa::ArrayItemType "ArrayItemType".
 *
 *  The StatusCode SemanticsChanged bit shall be set if any of the InstrumentRange,
 *  EURange, EngineeringUnits, Title or XAxisDefinition Properties are changed.
 *
 *  See also \ref Doc_OpcUa_XYArrayItemType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT XYArrayItemType:
    public OpcUa::ArrayItemType
{
    UA_DISABLE_COPY(XYArrayItemType);
protected:
    virtual ~XYArrayItemType();
public:
    XYArrayItemType(
        UaNode*            pParentNode,
        UaVariable*        pInstanceDeclarationVariable,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    XYArrayItemType(
        const UaNodeId&    nodeId,
        const UaString&    name,
        OpcUa_UInt16       browseNameNameSpaceIndex,
        const UaVariant&   initialValue,
        OpcUa_Byte         accessLevel,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    XYArrayItemType(
        UaBase::Variable*  pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;

    virtual void setXAxisDefinition(const UaAxisInformation& XAxisDefinition);
    virtual UaAxisInformation getXAxisDefinition() const;

    virtual OpcUa::PropertyType* getXAxisDefinitionNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(XYArrayItemType *pInstance);

protected:
    // Variable nodes
    // Variable XAxisDefinition
    static OpcUa::PropertyType*  s_pXAxisDefinition;
    OpcUa::PropertyType*  m_pXAxisDefinition;


private:
    void initialize(NodeManagerConfig* pNodeConfig);

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUA_XYARRAYITEMTYPE_H__

