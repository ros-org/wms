#ifndef UADICTIONARYDATA_H
#define UADICTIONARYDATA_H

#include <map>
#include <uastructuredefinition.h>
#include <uaenumdefinition.h>

class UaDictionaryDatas;
class UaXmlDocument;

class UaDictionaryData
{
    friend class UaDictionaryDatas;
public:
    UaDictionaryData(const UaString &sNamespaceUri);
    void addStructureDefinition(const UaStructureDefinition &definition);
    void addEnumDefinition(const UaEnumDefinition &definition);
    void removeStructureDefinition(const UaStructureDefinition &definition);

    UaString namespaceUri() const;
    UaStructureDefinition structureDefinition(const UaString &sName) const;
    UaEnumDefinition enumDefinition(const UaString &sName) const;

private:
    UaString m_sNamespaceUri;
    std::map<UaString, UaStructureDefinition> m_structureDefinitions;
    std::map<UaString, UaEnumDefinition> m_enumDefinitions;
};

class UaDictionaryDatas
{
public:
    UaDictionaryDatas();
    ~UaDictionaryDatas();
    void addDictionary(const UaNodeId &dictionaryId, UaDictionaryData *pDictionaryData);
    UaDictionaryData* dictionaryData(const UaNodeId &dictionaryId) const;
    UaDictionaryData* dictionaryData(const UaString &sNamespaceUri) const;
    UaStructureDefinition structureDefinition(
        const UaString &sNamespaceUri,
        const UaString &sTypeName) const;
    UaEnumDefinition enumDefinition(
        const UaString &sNamespaceUri,
        const UaString &sTypeName) const;

    void toStructureMap(std::map<UaNodeId, UaStructureDefinition> &rMapStructures) const;

private:
    bool m_bHaveDoubleUsedNamespaceUris;
    std::map<UaNodeId, UaDictionaryData*> m_dictionaries;
};


#endif
