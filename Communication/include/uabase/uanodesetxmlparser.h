/******************************************************************************
** uanodesetxmlparser.h
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
** Project: C++ OPC Server SDK XML parser base class for UA information models
**
******************************************************************************/
#ifndef _UANODESETXMLPARSER_H_
#define _UANODESETXMLPARSER_H_

#include <opcua_proxystub.h>
#include "basenodes.h"
#include <uavariant.h>
#include <xmldocument.h>
#include <uaunistring.h>
#include "uaargument.h"
#include "uaenumvaluetype.h"
#include "uaeuinformation.h"
#include "uarange.h"
#include <map>
#include <list>

class UaDataTypeDictionary;

namespace UaBase
{

/** Base class for parsing a NodeSet XML file.
 *
 * This class provides all functionality to parse a NodeSet XML file. The methods of this class
 * store parsed data by using UaBase::BaseNode.
 */
class UABASE_EXPORT UaNodesetXmlParser
{
    UA_DISABLE_COPY(UaNodesetXmlParser);
    UaNodesetXmlParser();
public:
    UaNodesetXmlParser(UaXmlDocument *pXmlDoc);
    virtual ~UaNodesetXmlParser();
    void setDictionary(UaDataTypeDictionary *pDictionary);

protected:
    virtual UaStatus loadXmlFile(const UaString& sFilename, UaString& sErrorText);
    virtual OpcUa_StatusCode readUris();
    void readAliases();
    void readExtensions();
    virtual UaStatus readXmlFile(std::map<UaNodeId, UaBase::BaseNode*>& mapNodes, UaString& sErrorText);
    virtual void evaluateModelParents(std::map<UaNodeId, UaBase::BaseNode*>& mapNodes);

    virtual UaStatus parseVariable(std::map<UaNodeId, UaBase::BaseNode*> &rMapNodes);
    virtual UaStatus parseObject(std::map<UaNodeId, UaBase::BaseNode*> &rMapNodes);
    virtual UaStatus parseMethod(std::map<UaNodeId, UaBase::BaseNode*> &rMapNodes);

    virtual UaStatus parseDataType(std::map<UaNodeId, UaBase::BaseNode*> &rMapNodes);
    virtual UaStatus parseReferenceType(std::map<UaNodeId, UaBase::BaseNode*> &rMapNodes);
    virtual UaStatus parseObjectType(std::map<UaNodeId, UaBase::BaseNode*> &rMapNodes);
    virtual UaStatus parseVariableType(std::map<UaNodeId, UaBase::BaseNode*> &rMapNodes);

    virtual UaStatus parseView(std::map<UaNodeId, UaBase::BaseNode*> &rMapNodes);

    virtual UaStatus parseReferences(UaBase::BaseNode *pBaseNode);
    virtual UaStatus parseExtensions(UaBase::BaseNode *pBaseNode);
    virtual UaStatus parseDefinition(UaBase::DataType *pDataType);
    virtual UaStatus addFieldsOfSuperTypeDefinition(
        UaBase::DataType *pDataType,
        const std::map<UaNodeId, UaBase::BaseNode*> &mapNodes,
        std::map<UaNodeId, UaBase::BaseNode*> &mapCheckedNodes);
    virtual void setValueTypesForFields(
        UaBase::DataType *pDataType,
        const std::map<UaNodeId, UaBase::BaseNode*>& mapNodes);
    virtual UaStructureDefinition structureDefinition(
        const UaNodeId &dataTypeId,
        const std::map<UaNodeId, UaBase::BaseNode*> &mapNodes,
        std::map<UaNodeId, UaBase::BaseNode*> &mapCheckedNodes);
    virtual UaEnumDefinition enumDefinition(
        const UaNodeId &dataTypeId,
        const std::map<UaNodeId, UaBase::BaseNode*> &mapNodes,
        std::map<UaNodeId, UaBase::BaseNode*> &mapCheckedNodes);
    void parseStructureFields(UaStructureDefinition &structure);

    UaNodeId parseNodeId(const UaUniString &sNodeId) const;
    UaQualifiedName parseQualifiedName(const UaUniString &sQualifiedName) const;
    UaLocalizedText parseLocalizedText() const;
    void parseBooleanAttribute(const char *szAttributeName,
                               OpcUa_Boolean bDefaultValue,
                               /*out*/ OpcUa_Boolean &rbValue);
    void parseByteAttribute(const char *szAttributeName,
                            OpcUa_Byte defaultValue,
                            /*out*/ OpcUa_Byte &rbValue);
    void parseInt32Attribute(const char *szAttributeName,
                             OpcUa_Int32 defaultValue,
                             /*out*/ OpcUa_Int32 &rbValue);
    void parseUInt32Attribute(const char *szAttributeName,
                              OpcUa_UInt32 defaultValue,
                              /*out*/ OpcUa_UInt32 &rValue);
    void parseNodeIdAttribute(const char *szAttributeName,
                              const UaNodeId &defaultValue,
                             /*out*/ UaNodeId &rbValue);
    void parseDoubleAttribute(const char *szAttributeName,
                              OpcUa_Double defaultValue,
                             /*out*/ OpcUa_Double &rbValue);
    UaVariant parseValue();
    void parseTypesValue(/*bi*/ UaVariant &rValue);
    OpcUa_Boolean getBooleanValue() const;
    OpcUa_Byte getByteValue() const;
    UaByteString getByteStringValue() const;
    UaDateTime getDateTimeValue() const;
    OpcUa_Double getDoubleValue() const;
    UaExtensionObject getExtensionObjectValue();
    OpcUa_Float  getFloatValue() const;
    UaGuid getGuidValue() const;
    OpcUa_Int16 getInt16Value() const;
    OpcUa_Int32 getInt32Value() const;
    OpcUa_Int64 getInt64Value() const;
    UaLocalizedText getLocalizedTextValue() const;
    UaNodeId getNodeIdValue() const;
    UaQualifiedName getQualifiedNameValue() const;
    UaString getStringValue() const;
    OpcUa_SByte getSByteValue() const;
    OpcUa_UInt16 getUInt16Value() const;
    OpcUa_UInt32 getUInt32Value() const;
    OpcUa_UInt64 getUInt64Value() const;
    void getBoolArray(/*bi*/ UaBoolArray &ret);
    void getByteArray(/*bi*/ UaByteArray &ret);
    void getByteStringArray(/*bi*/ UaByteStringArray &ret);
    void getDateTimeArray(/*bi*/ UaDateTimeArray &ret);
    void getDoubleArray(/*bi*/ UaDoubleArray &ret);
    void getFloatArray(/*bi*/ UaFloatArray &ret);
    void getGuidArray(/*bi*/ UaGuidArray &ret);
    void getInt16Array(/*bi*/ UaInt16Array &ret);
    void getInt32Array(/*bi*/ UaInt32Array &ret);
    void getInt64Array(/*bi*/ UaInt64Array &ret);
    void getLocalizedTextArray(/*bi*/ UaLocalizedTextArray &ret);
    void getNodeIdArray(/*bi*/ UaNodeIdArray &ret);
    void getQualifiedNameArray(/*bi*/ UaQualifiedNameArray &ret);
    void getStringArray(/*bi*/ UaStringArray &ret);
    void getSByteArray(/*bi*/ UaSByteArray &ret);
    void getUInt16Array(/*bi*/ UaUInt16Array &ret);
    void getUInt32Array(/*bi*/ UaUInt32Array &ret);
    void getUInt64Array(/*bi*/ UaUInt64Array &ret);
    void getVariantArray(/*bi*/ UaVariantArray &ret);
    void getXmlElementArray(/*bi*/ UaByteStringArray &ret);

    void getExtensionObjectArray(/*bi*/ UaExtensionObjectArray &ret);
    UaArgument getArgumentValue();
    UaEnumValueType getEnumValueTypeValue();
    UaEUInformation getEUInformationValue();
    UaRange getRangeValue();

    UaStatus parseNode(
        UaNodeId        &rNodeId,
        UaQualifiedName &rBrowseName,
        UaLocalizedText &rDisplayName,
        UaLocalizedText &rDescription,
        OpcUa_UInt32    &riWriteMask,
        OpcUa_UInt32    &riUserWriteMask);

    UaStatus parseReference(
        const UaXmlElementListIterator &it,
        UaNodeId    &rReferenceTypeId,
        bool        &rbIsForward,
        UaNodeId    &rTargetNodeId);

    UaStatus parseExtension(
        UaString &rsName,
        UaByteString &rbsValue,
        UaString &rsNamespace);

    UaStatus parseEnumDefinition(
        UaEnumDefinition &definition);

    UaNodeId    getReferenceType();
    bool        getReferenceTarget(const UaNodeId &referenceType, bool bIsForward, /*out*/ UaNodeId &targetId);

    static bool contains(const std::list<UaNodeId> &lstNodeIds, const UaNodeId &nodeId);

protected:
    static OpcUa_UInt32  s_uWriteMask;
    static OpcUa_UInt32  s_uUserWriteMask;
    static OpcUa_Boolean s_bDefaultIsAbstract;
    static OpcUa_Boolean s_bDefaultHistorizing;
    static OpcUa_Boolean s_bDefaultSymmetric;
    static OpcUa_Boolean s_bDefaultExecutable;
    static OpcUa_Boolean s_bDefaultUserExecutable;
    static OpcUa_Boolean s_bDefaultContainsNoLoops;
    static OpcUa_Byte    s_byDefaultEventNotifier;
    static UaNodeId      s_idDefaultDataType;
    static OpcUa_Int32   s_iDefaultValueRank;
    static OpcUa_Byte    s_byDefaultAccessLevel;
    static OpcUa_Byte    s_byDefaultUserAccessLevel;
    static OpcUa_Double  s_dDefaultMinimumSamplingInterval;

protected:
    UaXmlDocument*                       m_pXmlDocument;
    std::list<UaString>                  m_listNsUris;
    std::map<OpcUa_UInt16, OpcUa_UInt16> m_mapNs;
    std::map<UaUniString, UaNodeId>      m_mapAliases;
    std::list<Extension>                 m_extensions;
    UaDataTypeDictionary *m_pDictionary;
    UaBase::BaseNodeFactory m_standardFactory;
    UaBase::BaseNodeFactory *m_pBaseNodeFactory;
};

}

#endif /*_UANODESETXMLPARSER_H_*/
