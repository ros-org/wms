/******************************************************************************
** uastructurefield.h
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
#ifndef UASTRUCTUREFIELD_H
#define UASTRUCTUREFIELD_H

#include <opcua_proxystub.h>
#include "uabase.h"
#include "uastring.h"
#include "ualocalizedtext.h"
#include "uaabstractdictionaryreader.h"

class UaNodeId;
class UaEnumDefinition;
class UaStructureDefinition;
class UaOptionSetDefinition;
class UaDataTypeDictionary;

class UABASE_EXPORT UaStructureFieldPrivate;

/** This class describes a field of a structure data type represented by UaStructureDefinition.
 *
 *  The minimum settings for a field in a structure are
 *  - Name \ref UaStructureField::setName "setName()" / \ref UaStructureField::name "name()"
 *  - DataType NodeId \ref UaStructureField::setValueType "setValueType()" / \ref UaStructureField::valueType "valueType()"
 *    or \ref UaStructureField::setDataTypeId "setDataTypeId()" / \ref UaStructureField::typeId "typeId()"
 *
 *  OPC UA supports different kind of data types. The following options are available for setting the data type
 *  - Built-in data types without ExtensionObject (see structure)<br>
 *    There are 24 so called built-in types like Boolean, Float, UInt32 or String. For these data types, the numeric part of the
 *    DataType NodeId matches the built-in type number. Such a built-in type can be set with \ref UaStructureField::setValueType "setValueType()".
 *    The member DataTypeId is set automatically. If \ref UaStructureField::setDataTypeId "setDataTypeId()" is used, the ValueType is set automtically.
 *  - Structure data types<br>
 *    A structure data type can be set with \ref UaStructureField::setStructureDefinition "setStructureDefinition()". The ValueType (built-in type = ExtensionObject)
 *    and the DataTypeId members are set automatically
 *  - Enumeration data type<br>
 *    An enumeration data type can be set with \ref UaStructureField::setEnumDefinition "setEnumDefinition()". The ValueType (built-in type = Int32)
 *    and the DataTypeId members are set automatically
 *  - Data type derived from built-in types<br>
 *    An example is UtcTime with is derived from built-in data type DateTime. In this case the DataTypeId (UtcTime) must be set with
 *    \ref UaStructureField::setDataTypeId "setDataTypeId()" and the built-in type (DateTime) must be set with \ref UaStructureField::setValueType "setValueType()"
 *
 *  Additional setting for a field have default values. These additional settings are
 *  - ValueRank has default value sclar. Possible options are sclar and array (\ref UaStructureField::setArrayType "setArrayType()" / \ref UaStructureField::arrayType "arrayType()")
 *  - Optional with default value false (\ref UaStructureField::setOptional "setOptional()" / \ref UaStructureField::isOptional "isOptional()")
 */
class UABASE_EXPORT UaStructureField
{
#if SUPPORT_XML_PARSER
    friend class UaAbstractDictionaryReader;
    friend class UaNodeSetXmlParser;
#endif // SUPPORT_XML_PARSER

    UA_DECLARE_PRIVATE(UaStructureField)
public:
    enum ArrayType
    {
        ArrayType_Scalar = OpcUa_VariantArrayType_Scalar,
        ArrayType_Array = OpcUa_VariantArrayType_Array
#ifdef GENERICTYPES_SUPPORT_MATRIX
        , ArrayType_Matrix = OpcUa_VariantArrayType_Matrix
#endif
    };

    UaStructureField();
    UaStructureField(const UaStructureField &other);
    virtual ~UaStructureField();

    UaStructureField& operator=(const UaStructureField &other);

    bool isNull();

    void setName(const UaString &sName);
    UaString name() const;
    void setDocumentation(const UaLocalizedText &sDocumentation);
    UaLocalizedText documentation() const;

    void setDataTypeId(const UaNodeId &dataTypeId);
    UaNodeId typeId() const;
    void setValueType(OpcUa_BuiltInType type);
    OpcUa_BuiltInType valueType() const;

    void setEnumDefinition(const UaEnumDefinition &newEnumDefinition);
    UaEnumDefinition enumDefinition() const;

    void setStructureDefinition(const UaStructureDefinition &newStructureDefinition);
    UaStructureDefinition structureDefinition() const;

    void setOptionSetDefinition(const UaOptionSetDefinition &newOptionSetDefinition);
    UaOptionSetDefinition optionSetDefinition() const;

    void setArrayType(ArrayType arrayType);
    ArrayType arrayType() const;

    void setSourceType(const UaStructureDefinition &parent);
    UaStructureDefinition sourceType() const;

    bool isOptional() const;
    void setOptional(bool bOptional);

    void setStructureDefinitionInternal(const UaStructureDefinition &newStructureDefinition);
    void setEnumDefinitionInternal(const UaEnumDefinition &newEnumDefinition);
    void setValueTypeInternal(OpcUa_BuiltInType type);

    static OpcUa_BuiltInType builtInTypeFromDataTypeId(const UaNodeId &dataTypeId, UaDataTypeDictionary *pDataTypeDictionary = NULL);

private:
    void setOptionSetDefinitionInternal(const UaOptionSetDefinition &newOptionSetDefinition);

};
#endif // UASTRUCTUREFIELD_H
