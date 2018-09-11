/******************************************************************************
** opcua_aggregateconfigurationtypebase.h
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

#ifndef __OPCUA_AGGREGATECONFIGURATIONTYPEBASE_H__
#define __OPCUA_AGGREGATECONFIGURATIONTYPEBASE_H__

#include "opcua_baseobjecttype.h"
#include "basenodes.h"
#include "opcua_identifiers.h"
#include "opcua_propertytype.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;

/** Generated base class for a AggregateConfigurationType.
 *
 *  This class contains the generated base code for the object type AggregateConfigurationType
 *  representing an OPC UA ObjectType. This class is used to create the object type and to
 *  create and represent instances of the object type in the server address space.
 *
 *  **Variable members of the AggregateConfigurationType:**
 *
 *  Browse Name            | DataType | TypeDefinition | Modelling Rule | See Also
 *  -----------------------|----------|----------------|----------------|---------------------------------------------------------------
 *  PercentDataBad         | Byte     | PropertyType   | Mandatory      | \ref getPercentDataBad, \ref setPercentDataBad
 *  PercentDataGood        | Byte     | PropertyType   | Mandatory      | \ref getPercentDataGood, \ref setPercentDataGood
 *  TreatUncertainAsBad    | Boolean  | PropertyType   | Mandatory      | \ref getTreatUncertainAsBad, \ref setTreatUncertainAsBad
 *  UseSlopedExtrapolation | Boolean  | PropertyType   | Mandatory      | \ref getUseSlopedExtrapolation, \ref setUseSlopedExtrapolation
 *
 */
class SERVER_CORE_EXPORT AggregateConfigurationTypeBase:
    public OpcUa::BaseObjectType
{
    UA_DISABLE_COPY(AggregateConfigurationTypeBase);
protected:
    virtual ~AggregateConfigurationTypeBase();
public:
    // construction / destruction
    AggregateConfigurationTypeBase(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    AggregateConfigurationTypeBase(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    AggregateConfigurationTypeBase(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;


    virtual void setPercentDataBad(OpcUa_Byte PercentDataBad);
    virtual OpcUa_Byte getPercentDataBad() const;

    virtual void setPercentDataGood(OpcUa_Byte PercentDataGood);
    virtual OpcUa_Byte getPercentDataGood() const;

    virtual void setTreatUncertainAsBad(OpcUa_Boolean TreatUncertainAsBad);
    virtual OpcUa_Boolean getTreatUncertainAsBad() const;

    virtual void setUseSlopedExtrapolation(OpcUa_Boolean UseSlopedExtrapolation);
    virtual OpcUa_Boolean getUseSlopedExtrapolation() const;

    virtual OpcUa::PropertyType* getPercentDataBadNode();
    virtual OpcUa::PropertyType* getPercentDataGoodNode();
    virtual OpcUa::PropertyType* getTreatUncertainAsBadNode();
    virtual OpcUa::PropertyType* getUseSlopedExtrapolationNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(AggregateConfigurationTypeBase *pInstance);

protected:
    // Variable nodes
    // Variable PercentDataBad
    static OpcUa::PropertyType*  s_pPercentDataBad;
    OpcUa::PropertyType*  m_pPercentDataBad;
    // Variable PercentDataGood
    static OpcUa::PropertyType*  s_pPercentDataGood;
    OpcUa::PropertyType*  m_pPercentDataGood;
    // Variable TreatUncertainAsBad
    static OpcUa::PropertyType*  s_pTreatUncertainAsBad;
    OpcUa::PropertyType*  m_pTreatUncertainAsBad;
    // Variable UseSlopedExtrapolation
    static OpcUa::PropertyType*  s_pUseSlopedExtrapolation;
    OpcUa::PropertyType*  m_pUseSlopedExtrapolation;



private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUAAGGREGATECONFIGURATIONTYPEBASE_H__


