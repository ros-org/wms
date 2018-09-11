/******************************************************************************
** uastructuredefinition.h
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
#ifndef UASTRUCTUREDEFINITION_H
#define UASTRUCTUREDEFINITION_H

#include <vector>

#include "uabase.h"
#include "uadatatypedefinition.h"
#include "uastructurefield.h"
#include "userdatareferencecounted.h"
#if SUPPORT_XML_PARSER
#include "uabsdreader.h"
#endif // SUPPORT_XML_PARSER

class UaString;
class UaStructureField;
class UaDataTypeDictionary;

class UABASE_EXPORT UaStructureDefinitionPrivate;

/** The class describes a structured data type.
 *
 * Structured DataTypes that are not known at compile time can be described using this class.
 * This class can be used to add a structured DataType on server side as well as as result
 * of reading the DataType Dictionary of a server on client side.
 *
 * Each UaStructureDefinition is described by its name, its DataTypeId, the encoding Ids and
 * a list of UaStructureFields.
 *
 * This class is used by UaGenericValue for storing DataType information and for accessing the
 * fields.
 */
class UABASE_EXPORT UaStructureDefinition
{
#if SUPPORT_XML_PARSER
    friend class UaBsdReader;
#endif // SUPPORT_XML_PARSER
    UA_DECLARE_PRIVATE(UaStructureDefinition)
public:
    UaStructureDefinition();
    UaStructureDefinition(const UaStructureDefinition &other);
    virtual ~UaStructureDefinition();

    UaStructureDefinition& operator=(const UaStructureDefinition &other);

    bool operator==(const UaStructureDefinition &other) const;
    bool operator!=(const UaStructureDefinition &other) const;

    void clear();
    bool isNull() const;

    void setDataTypeId(const UaNodeId &nodeId);
    UaNodeId dataTypeId() const;

    void setName(const UaString &sName);
    UaString name() const;

    void setDocumentation(const UaLocalizedText &documentation);
    UaLocalizedText documentation() const;

    void setNamespace(const UaString &sNamespace);
    UaString getNamespace() const;

    void setBaseType(const UaStructureDefinition &newBaseType);
    UaNodeId baseTypeId() const;

    UaStructureDefinition createSubtype() const;

    int childrenCount() const;
    UaStructureField child(int i) const;
    void addChild(const UaStructureField &newChild);

    void setBinaryEncodingId(const UaNodeId &nodeId);
    UaNodeId binaryEncodingId() const;
    void setXmlEncodingId(const UaNodeId &nodeId);
    UaNodeId xmlEncodingId() const;

    void remove(const UaString &sFieldName);

    bool isUnion() const;
    void setUnion(bool bUnion);

    bool hasOptionalFields() const;

    void findDefinitionsForFields(UaDataTypeDictionary *pDictionary);

    UaStructureDefinition mapNamespaces(NamespaceMappingInterface *pMapper) const;

    void setUserData(UserDataReferenceCounted* pUserData);
    UserDataReferenceCounted* getUserData() const;

private:
    void addChildInternal(const UaStructureField &newChild);
    void removeChildInternal(const UaString &sFieldName);
    void setUnionInternal(bool bUnion);

};

#endif // UASTRUCTUREDEFINITION_H
