/******************************************************************************
** uabsdreader.h
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
#ifndef UABSDREADER_H
#define UABSDREADER_H

#include <list>
#include <map>

#include "statuscode.h"
#include "uaqualifiedname.h"

class UaStructureDefinition;
class UaStructureField;
class UaEnumDefinition;
class UaXmlDocument;
class UaXmlElement;
class UaString;
class UaStringArray;
class UaNodeId;
class UaDictionaryData;
class UaDictionaryDatas;

class UABASE_EXPORT UaBsdReader
{
public:
    UaBsdReader();
    virtual ~UaBsdReader();

    void readTypesNew(UaXmlDocument *pDictionary,
                      UaDictionaryData **ppDictionaryData) const;
    void readDictionaryNew(
            UaXmlDocument *pDictionary,
            const UaDictionaryDatas &dictionaryDatas);
    void readTypes(UaXmlDocument &dictionary,
                   const UaString &sNamespaceUri,
                   std::list<UaStructureDefinition> &lstStructureDefinitions,
                   std::list<UaEnumDefinition> &lstEnumDefinitions);
    void readDictionary(const UaByteString &bsDictionary,
                        std::map<UaQualifiedName, UaStructureDefinition> &mapStructures,
                        std::map<UaQualifiedName, UaEnumDefinition> &mapEnums,
                        const UaStringArray &namespaceArray,
                        OpcUa_UInt16 uNsIdx);

private:
    UaStructureDefinition readStructure(UaXmlElement &structure) const;
    UaStatusCode fillStructureNew(
                       UaStructureDefinition &rStructureDefinition,
                       UaXmlDocument *pDictionaryDocument,
                       const UaDictionaryDatas &dictionaryDatas);
    UaStatusCode fillStructure(UaXmlElement &structure,
                       UaStructureDefinition &rStructureDefinition,
                       const UaStringArray &namespaceArray,
                       const std::map<UaString, UaString> &mapNamespaces,
                       const std::map<UaQualifiedName, UaStructureDefinition> &mapStructures,
                       const std::map<UaQualifiedName, UaEnumDefinition> &mapEnums);
    UaEnumDefinition readEnumeration(UaXmlElement &enumeration) const;

    enum FieldSet
    {
        FieldSet_Field,
        FieldSet_Bit
    };

    UaStatus evaluateTypeNameNew(
            const char* sTypeName,
            UaXmlDocument *pDictionaryDocument,
            const UaDictionaryDatas &dictionaryDatas,
            FieldSet &rFieldSet /*out*/,
            UaStructureField &rField/*out*/) const;
    UaStatus evaluateTypeName(
            const UaString &sTypeName,
            const UaStringArray &namespaceArray,
            const std::map<UaString, UaString> &mapNamespaces,
            const std::map<UaQualifiedName, UaStructureDefinition> &mapStructures,
            const std::map<UaQualifiedName, UaEnumDefinition> &mapEnums,
            FieldSet &rFieldSet /*out*/,
            UaStructureField &rField/*out*/) const;
    UaStatus typeIdFromString(const UaString &sTypeName,
                              const UaStringArray &namespaceArray,
                              const std::map<UaString, UaString> &mapNamespaces,
                              const std::map<UaQualifiedName, UaStructureDefinition> &mapStructures,
                              const std::map<UaQualifiedName, UaEnumDefinition> &mapEnums,
                              UaStructureDefinition &structureDefinition /*out*/,
                              UaEnumDefinition &enumDefinition /*out*/,
                              UaNodeId &rDataTypeId /*out*/,
                              OpcUa_BuiltInType &rValueType /*out*/) const;

    void getNamespace(const UaByteString &bsDictionary, std::map<UaString, UaString> &rMapNamespaces);

#define HAVE_GLOBAL_NAMESPACES 1
#if HAVE_GLOBAL_NAMESPACES
    UaString m_sOpc;
    UaString m_sUa;
    UaString m_sNs0;
#endif
};

#endif // UABSDREADER_H
