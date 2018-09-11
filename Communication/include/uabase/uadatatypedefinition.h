/******************************************************************************
** uadatatypedefinition.h
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
#ifndef UADATATYPEDEFINITION_H
#define UADATATYPEDEFINITION_H

#include <uabase.h>

class UaVariant;
class UaNodeId;
class UaExtensionObject;
class UaEnumDefinition;
class UaStructureDefinition;
class UaOptionSetDefinition;

/** Base class for getting DataType information. */
class UABASE_EXPORT UaDataTypeDictionary
{
public:
  /** Enumeration that indicates whether a UaEnumDefinition or a
   * UaStructureDefinition is available.
   */
    enum DefinitionType
    {
        DefinitionType_None = 0,
        DefinitionType_Structure,
        DefinitionType_Enum,
        DefinitionType_OptionSet
    };

    virtual ~UaDataTypeDictionary() {}

    /** Returns the DefinitionType for the specified data type.
     *
     * Is called by definitionType(const UaVariant &vValue) and
     * definitionType(const UaExtensionObject &vValue).
     */
    virtual DefinitionType definitionType(const UaNodeId &dataTypeId) = 0;
    DefinitionType definitionType(const UaVariant &vValue);
    DefinitionType definitionType(const UaExtensionObject &vValue);

    /** Returns the UaEnumDefinition for the specified data type. */
    virtual UaEnumDefinition enumDefinition(const UaNodeId &dataTypeId) = 0;

    /** Returns the UaOptionSetDefinition for the specified data type. */
    virtual UaOptionSetDefinition optionSetDefinition(const UaNodeId &dataTypeId) = 0;

    /** Returns the UaStructureDefinition for the specified data type.
     *
     * Is called by structureDefinition(const UaVariant &vValue) and
     * structureDefinition(const UaExtensionObject &vValue).
     */
    virtual UaStructureDefinition structureDefinition(const UaNodeId &dataTypeId) = 0;
    UaStructureDefinition structureDefinition(const UaVariant &vValue);
    UaStructureDefinition structureDefinition(const UaExtensionObject &vValue);
};

#endif // UADATATYPEDEFINITION_H
