/******************************************************************************
** uaenumdefinition.h
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
#ifndef UAENUMDEFINITION_H
#define UAENUMDEFINITION_H

#include <map>

#include "uadatatypedefinition.h"
#include "uaenumvalue.h"

class UABASE_EXPORT UaEnumDefinitionPrivate;

/** The class describes an Enumeration.
 *
 * You can access the EnumValues by index or by value.
 *
 * Enumerated DataTypes that are not known at compile time can be described using this class.
 * This class can be used to add an enumerated DataType on server side as well as as result
 * of reading the DataType Dictionary of a server on client side.
 *
 * Each UaStructureDefinition is described by its name, its DataTypeId, the encoding Ids and
 * a list of UaStructureFields.
 */
class UABASE_EXPORT UaEnumDefinition
{
    UA_DECLARE_PRIVATE(UaEnumDefinition)
public:
    UaEnumDefinition();
    UaEnumDefinition(const UaEnumDefinition &other);
    virtual ~UaEnumDefinition();

    UaEnumDefinition& operator=(const UaEnumDefinition &other);

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

    int childrenCount() const;
    UaEnumValue child(int i) const;
    void addChild(const UaEnumValue &newChild);

    UaEnumValue enumValue(int iValue) const;
};

#endif // UAENUMDEFINITION_H
