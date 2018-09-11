/******************************************************************************
** uaabstractdictionaryreader.h
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
** Project: C++ OPC SDK base module
**
******************************************************************************/
#ifndef UAABSTRACTDICTIONARYREADER_H
#define UAABSTRACTDICTIONARYREADER_H

#include <map>
#include <vector>

#include "statuscode.h"

class UaStructureDefinition;
class UaEnumDefinition;
class UaOptionSetDefinition;
class UaDictionaryDatas;
class UaVariant;
class UaNodeId;

/**
  * Base class for dictionary readers.
  *
  * Reads the values of dictionary nodes and parses these values. Browses the address space to find
  * DataType NodeIds and encoding NodeIds.
  *
  * This class can be inherited on client or server side. This base class provides some abstract
  * methods that must be implemented.
  */
class UABASE_EXPORT UaAbstractDictionaryReader
{
public:
    UaAbstractDictionaryReader();
    virtual ~UaAbstractDictionaryReader();

    UaStatus readDictionariesNew(
            std::map<UaNodeId, UaStructureDefinition> &mapStructures /*out*/,
            std::map<UaNodeId, UaEnumDefinition> &mapEnumerations /*out*/,
            std::map<UaNodeId, UaOptionSetDefinition> &mapOptionSets /*out*/,
            bool bReadNs0 = false);

    UaStatus readDictionaries(
        bool bReadNs0,
        const UaStringArray &namespaceArray,
        std::map<UaQualifiedName, UaStructureDefinition> &mapStructures /*out*/,
        std::map<UaQualifiedName, UaEnumDefinition> &mapEnums /*out*/);
    UaStatus readDictionaries(
        bool bReadNs0,
        const UaStringArray &namespaceArray,
        std::map<UaQualifiedName, UaStructureDefinition> &mapStructures /*out*/,
        std::map<UaQualifiedName, UaEnumDefinition> &mapEnums /*out*/,
        std::vector<UaOptionSetDefinition> &optionSets /*out*/);
    UaStatus readDictionaries(
        bool bReadNs0,
        std::map<UaQualifiedName, UaStructureDefinition> &mapStructures /*out*/,
        std::map<UaQualifiedName, UaEnumDefinition> &mapEnums /*out*/);
    UaStatus readDictionaries(
        bool bReadNs0,
        std::map<UaQualifiedName, UaStructureDefinition> &mapStructures /*out*/,
        std::map<UaQualifiedName, UaEnumDefinition> &mapEnums /*out*/,
        std::vector<UaOptionSetDefinition> &optionSets /*out*/);

protected:
    UaStatus addEnumDefinitionsNew(std::map<UaNodeId, UaEnumDefinition> &mapEnumerations, bool bReadNs0);
    UaStatus addOptionSetsNew(std::map<UaNodeId, UaOptionSetDefinition> &mapOptionSets, bool bReadNs0);
    UaStatus addStructureNodeIds(const UaDictionaryDatas &dictionaryDatas, const UaNodeIdArray &dictionaryNodeIds);

    UaStatus addStructureDefinitions(std::map<UaQualifiedName, UaStructureDefinition> &mapDefinitions, bool bAddNs0 = true) const;
    void addEnumDefinitions(std::map<UaQualifiedName, UaEnumDefinition> &mapDefinitions, const UaStringArray &namespaceArray) const;
    UaStatus addOptionSets(std::vector<UaOptionSetDefinition> &optionSets, const UaStringArray &namespaceArray) const;

    //helpers

    /**
     * Discover forward references of a specified node.
     *
     * This method is used to return a list of references and target nodes for the passed node to browse.
     * @param startingNodeId The NodeId of the node to browse.
     * @param referenceTypeId Only references using this ReferenceType (or one of its subtypes) are returned
     * @param rResults The list of references and target nodes
     */
    virtual UaStatus browse(
        const UaNodeId &startingNodeId,
        const UaNodeId &referenceTypeId,
        /*out*/ UaReferenceDescriptions &rResults) const = 0;
    virtual UaStatus browseInverse(
        const UaNodeId &startingNodeId,
        const UaNodeId &referenceTypeId,
        /*out*/ UaReferenceDescriptions &rResults) const = 0;
    virtual UaStatus browseList(
        const UaBrowseDescriptions &browseDescriptions,
        /* out */ UaBrowseResults &rDescriptions) const;
    virtual UaStatus browseList(
        const UaNodeIdArray &startingNodeIds,
        const UaNodeId &referenceTypeId,
        UaReferenceDescriptions &rResults) const;
    virtual UaStatus browseList(
        const UaNodeIdArray &startingNodeIds,
        const UaNodeId &referenceTypeId,
        UaBrowseResults &rResults) const;
    virtual UaStatus browseListInverse(
        const UaNodeIdArray &startingNodeIds,
        const UaNodeId &referenceTypeId,
        UaReferenceDescriptions &rResults) const;
    virtual UaStatus browseListInverse(
        const UaNodeIdArray &startingNodeIds,
        const UaNodeId &referenceTypeId,
        UaBrowseResults &rResults) const;
    void browseListRec(const UaNodeIdArray &startingNodeIds,
        const UaNodeId &referenceTypeId,
        UaReferenceDescriptions &rResults) const;
    virtual UaStatus translate(
        const UaNodeId &startingNodeId,
        const UaQualifiedName &browseName,
        const UaNodeId &referenceTypeId,
        /*out*/ UaNodeId &targetNodeId) const;
    virtual UaStatus translateInverse(
        const UaNodeId &startingNodeId,
        const UaQualifiedName &browseName,
        const UaNodeId &referenceTypeId,
        /*out*/ UaNodeId &targetNodeId) const;
    virtual UaStatus translateBrowsePaths(
        const UaNodeIdArray &startingNodeIds,
        const UaNodeId &referenceTypeId,
        const UaQualifiedName &browseName,
        /*out*/ UaBrowsePathResults &targetNodes) const;
    virtual UaStatus translateBrowsePathsInverse(
        const UaNodeIdArray &startingNodeIds,
        const UaNodeId &referenceTypeId,
        const UaQualifiedName &browseName,
        /*out*/ UaNodeIdArray &targetNodes) const;
    virtual UaStatus translateBrowsePaths(
        const UaReferenceDescriptions &startingNodes,
        const UaNodeId &referenceTypeId,
        const UaQualifiedName &browseName,
        /*out*/ UaBrowsePathResults &targetNodes) const;
    virtual UaStatus readValue(
        const UaNodeId &nodeId,
        /*out*/ UaVariant &rValue) const = 0;
    virtual UaStatus readValues(
        const UaNodeIdArray &nodeIds,
        /*out*/ UaDataValues &rValues) const = 0;
    virtual UaStatus readDictionaryValues(
        const UaNodeIdArray &nodeIds,
        /*out*/ UaByteStringArray &rValues) const;
    virtual UaStatus readDescriptionAttributes(
        const UaNodeIdArray &nodeIds,
        UaLocalizedTextArray &rValues) const = 0;
    virtual UaStatus getEncoding(
        const UaReferenceDescriptions &structureIds,
        const UaQualifiedName &encodingName,
        /*out*/ UaBrowsePathResults &rEncodings) const;
    virtual UaStatus getEncodings(
        const UaReferenceDescriptions &structureIds,
        /*out*/ UaBrowsePathResults &rBinaryEncodings,
        /*out*/ UaBrowsePathResults &rXmlEncodings) const;
    virtual UaStatus getDescriptions(
        const UaBrowsePathResults &encodings,
        /*out*/UaBrowseResults &rDescriptions) const;
    virtual UaStatus readDescriptionValues(
        const UaNodeIdArray &descriptionIds,
        /*out*/UaDataValues &rDescriptionValues) const;
    virtual UaStatus getBinaryEncodings(
        const UaNodeIdArray &descriptionsIds,
        /*out*/ UaNodeIdArray &binaryEncodingNodeIds) const;
    virtual UaStatus getXmlEncodings(
        const UaNodeIdArray &binaryEncodingNodeIds,
        /*out*/ UaBrowsePathResults &xmlEncodingNodes) const;
    virtual UaStatus getStructures(
        const UaNodeIdArray binaryEncodingIds,
        /*out*/ UaBrowseResults &structures) const;
};

#endif // UAABSTRACTDICTIONARYREADER_H
