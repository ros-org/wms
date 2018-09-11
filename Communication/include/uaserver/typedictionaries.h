/******************************************************************************
** typedictionaries.h
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
** Project: C++ OPC Server SDK core module
**
** Description: Node managager base classes.
**
******************************************************************************/

#include "nodemanager.h"
#include "opcua_datatypedictionarytype.h"
#include <uadatatypedefinition.h>
#include <uastructuredefinition.h>
#include <uaenumdefinition.h>
#include <uaoptionsetdefinition.h>

/**
  * Class for adding and accessing DataType Definitions
  *
  * Using this class DataType nodes cannot be added.
  */
class TypeDictionariesAccess : public UaDataTypeDictionary
{
    UA_DISABLE_COPY(TypeDictionariesAccess);
public:
    TypeDictionariesAccess(const UaString &sNamespaceUri);
    virtual ~TypeDictionariesAccess();

    void addStructuredTypeDefinition(const UaStructureDefinition &structure);
    void addEnumeratedTypeDefinition(const UaEnumDefinition &enumeration);
    void addOptionSetTypeDefinition(const UaOptionSetDefinition &optionSet);

    /* UaDataTypeDictionary interface */
    virtual UaDataTypeDictionary::DefinitionType definitionType(const UaNodeId &dataTypeId);
    virtual UaEnumDefinition enumDefinition(const UaNodeId &dataTypeId);
    virtual UaStructureDefinition structureDefinition(const UaNodeId &dataTypeId);
    virtual UaOptionSetDefinition optionSetDefinition(const UaNodeId &dataTypeId);

    void findDefinitionsForStructureFields();

protected:
    void addNestedStructureDefinitions(const UaStructureDefinition &structure);

    std::map<UaString, UaStructureDefinition> m_mapStructures;
    std::map<UaNodeId, UaStructureDefinition> m_mapStructureEncodings;
    std::map<UaString, UaEnumDefinition> m_mapEnumerationNames;
    std::map<UaNodeId, UaEnumDefinition> m_mapEnumerations;
    std::map<UaNodeId, UaOptionSetDefinition> m_mapOptionSetDefinitions;
    UaString m_sNamespaceUri;
};


/**
  * Class for adding DataType definitions. This class adds nodes and updates the dictionary.
  */
class TypeDictionaries : public TypeDictionariesAccess
{
    UA_DISABLE_COPY(TypeDictionaries);
public:
    TypeDictionaries(
        NodeManagerConfig *pNodeConfig,
        const UaString &sNamespaceUri);
    TypeDictionaries(
        NodeManagerConfig *pNodeConfig,
        const UaString &sNamespaceUri,
        const UaNodeId &typeDictionaryId,
        const UaString &sDictionaryName);
    virtual ~TypeDictionaries(){}

    UaStatus addTypeDictionary(const UaNodeId &nodeId, const UaString &sName);
    void setTypeDictionary(OpcUa::DataTypeDictionaryType* pTypeDictionary);
#ifdef HAVE_XML_ENCODER
    UaStatus addXmlTypeDictionary(const UaNodeId &nodeId, const UaString &sName);
    void setXmlTypeDictionary(OpcUa::DataTypeDictionaryType* pTypeDictionary);
#endif
    UaStatus addStructuredType(const UaStructureDefinition &structure);
    UaStatus addEnumeratedType(const UaEnumDefinition &enumeration, const UaNodeId &enumerationPropertyId = UaNodeId());
    UaStatus addOptionSetType(const UaOptionSetDefinition &optionSet, const UaNodeId &optionSetPropertyId = UaNodeId());

    UaStatus addStructuredTypes(std::list<UaStructureDefinition> &structures);
    UaStatus addEnumeratedTypes(std::list<UaEnumDefinition> &enumerations);
    UaStatus addOptionSetTypes(std::list<UaOptionSetDefinition> &optionSets);

    void setDataTypeVersion(const UaString &sDataTypeVersion);
    UaString dataTypeVersion() const;

protected:
    virtual void updateDictionaries();
    virtual UaString typeNameFromField(const UaStructureField &field);

private:
    UaStatus addStructuredTypeWithoutUpdate(const UaStructureDefinition &structure);
    UaStatus addEnumeratedTypeWithoutUpdate(const UaEnumDefinition &enumeration, const UaNodeId &enumerationPropertyId = UaNodeId());
    UaStatus addOptionSetTypeWithoutUpdate(const UaOptionSetDefinition &optionSet, const UaNodeId &optionSetPropertyId = UaNodeId());
    UaStatus addEncodingNodes(
        UaGenericDataType *pDataType,
        const UaNodeId &binaryEncodingId
#ifdef HAVE_XML_ENCODER
        , const UaNodeId &xmlEncodingId = UaNodeId()
#endif
        );
    UaString getTypeName(
            const UaString &sDataTypeName,
            const UaNodeId &dataTypeId,
            const UaString &sNamespaceUri);

    NodeManagerConfig *m_pNodeConfig;

    OpcUa::DataTypeDictionaryType* m_pTypeDictionary;
#ifdef HAVE_XML_ENCODER
    OpcUa::DataTypeDictionaryType* m_pTypeDictionaryXml;
#endif
};
