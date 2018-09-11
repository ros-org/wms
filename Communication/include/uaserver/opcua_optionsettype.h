/******************************************************************************
** opcua_optionsettype.h
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

#ifndef __OPCUA_OPTIONSETTYPE_H__
#define __OPCUA_OPTIONSETTYPE_H__

#include "opcua_basedatavariabletype.h"
#include "opcua_identifiers.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;

/** Implements OPC UA Variables of the type OptionSetType
 *
 *  **Variable members of the OptionSetType:**
 *
 *  Browse Name     | DataType      | TypeDefinition | Modelling Rule | See Also
 *  ----------------|---------------|----------------|----------------|-------------------------------------------------
 *  BitMask         | Boolean       | PropertyType   | Optional       | \ref getBitMask, \ref setBitMask
 *  OptionSetValues | LocalizedText | PropertyType   | Mandatory      | \ref getOptionSetValues, \ref setOptionSetValues
 *
 *  This VariableType is used to represent a bit mask.
 *
 *  Each array element of the OptionSetValues Property contains either the
 *  human-readable representation for the corresponding bit used in the option set
 *  or an empty LocalizedText for a bit that has no specific meaning. The order of
 *  the bits of the bit mask maps to a position of the array, i.e. the first bit
 *  (least significant bit) maps to the first entry in the array, etc.
 *
 *  The DataType of this VariableType shall be capable of representing a bit mask.
 *  It shall be either a numeric DataType representing a signed or unsigned
 *  integer, or a ByteString. For example, it can be the BitFieldMaskDataType.
 *
 *  See also \ref Doc_OpcUa_OptionSetType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT OptionSetType:
    public OpcUa::BaseDataVariableType
{
    UA_DISABLE_COPY(OptionSetType);
protected:
    virtual ~OptionSetType();
public:
    OptionSetType(
        UaNode*            pParentNode,
        UaVariable*        pInstanceDeclarationVariable,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    OptionSetType(
        const UaNodeId&    nodeId,
        const UaString&    name,
        OpcUa_UInt16       browseNameNameSpaceIndex,
        const UaVariant&   initialValue,
        OpcUa_Byte         accessLevel,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    OptionSetType(
        UaBase::Variable*  pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;

    virtual void setBitMask(const UaBoolArray& BitMask);
    virtual void getBitMask(UaBoolArray& BitMask) const;

    virtual void setOptionSetValues(const UaLocalizedTextArray& OptionSetValues);
    virtual void getOptionSetValues(UaLocalizedTextArray& OptionSetValues) const;

    virtual OpcUa::PropertyType* getBitMaskNode();
    virtual OpcUa::PropertyType* getOptionSetValuesNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(OptionSetType *pInstance);

protected:
    // Variable nodes
    // Variable BitMask
    static OpcUa::PropertyType*  s_pBitMask;
    OpcUa::PropertyType*  m_pBitMask;
    // Variable OptionSetValues
    static OpcUa::PropertyType*  s_pOptionSetValues;
    OpcUa::PropertyType*  m_pOptionSetValues;


private:
    void initialize(NodeManagerConfig* pNodeConfig);

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUA_OPTIONSETTYPE_H__

