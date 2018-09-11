/******************************************************************************
** uagenericunion.h
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
#ifndef UAGENERICUNIONVALUE_H
#define UAGENERICUNIONVALUE_H

#include "uaabstractgenericstructurevalue.h"

class UaByteString;
class UABASE_EXPORT UaGenericUnionValuePrivate;
class UABASE_EXPORT UaGenericUnionArrayPrivate;
class UABASE_EXPORT UaGenericStructureValue;
class UABASE_EXPORT UaGenericStructureArray;
class UABASE_EXPORT UaGenericUnionValue;
class UABASE_EXPORT UaGenericUnionArray;
class UABASE_EXPORT UaGenericOptionSetValue;
class UABASE_EXPORT UaGenericOptionSetArray;
class UABASE_EXPORT UaExtensionObjectArray;

/** A class that serializes and deserializes unions that is described by an UaStructureDefinition.
 *
 * The class can be used for DataTypes that are not registered to the stack.
 */
class UABASE_EXPORT UaGenericUnionValue : public UaAbstractGenericStructureValue
{
    UA_DECLARE_PRIVATE(UaGenericUnionValue)
public:
    UaGenericUnionValue();
    UaGenericUnionValue(const UaStructureDefinition &structureDefinition);
    UaGenericUnionValue(const UaGenericUnionValue &other);
    UaGenericUnionValue(const UaByteString &bsData, Encoding valueEncoding, const UaStructureDefinition &structureDefinition);
    UaGenericUnionValue(const UaExtensionObject &extensionObject, const UaStructureDefinition &structureDefinition);
    virtual ~UaGenericUnionValue();

    virtual void clear();

    bool operator==(const UaGenericUnionValue &other) const;
    bool operator!=(const UaGenericUnionValue &other) const;

    UaGenericUnionValue& operator=(const UaGenericUnionValue &other);

    OpcUa_StatusCode setGenericUnion(const UaByteString &bsData, UaAbstractGenericValue::Encoding valueEncoding, const UaStructureDefinition &structureDefinition);
    OpcUa_StatusCode setGenericUnion(const UaExtensionObject &extensionObject, const UaStructureDefinition &structureDefinition);

    OpcUa_StatusCode setValue(const UaString &sFieldName, UaVariant &value, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setValue(int iIndex, UaVariant &value, OpcUa_Boolean bDetach);

    OpcUa_StatusCode setValue(const UaString &sFieldName, const UaVariant &value);
    OpcUa_StatusCode setValue(int iIndex, const UaVariant &value);

    OpcUa_StatusCode setValue(const UaString &sFieldName, const UaGenericStructureValue &value);
    OpcUa_StatusCode setValue(int iIndex, const UaGenericStructureValue &value);

    OpcUa_StatusCode setValue(const UaString &sFieldName, const UaGenericStructureArray &value);
    OpcUa_StatusCode setValue(int iIndex, const UaGenericStructureArray &value);

    OpcUa_StatusCode setValue(const UaString &sFieldName, const UaGenericUnionValue &value);
    OpcUa_StatusCode setValue(int iIndex, const UaGenericUnionValue &value);

    OpcUa_StatusCode setValue(const UaString &sFieldName, const UaGenericUnionArray &value);
    OpcUa_StatusCode setValue(int iIndex, const UaGenericUnionArray &value);

    OpcUa_StatusCode setValue(const UaString &sFieldName, const UaGenericOptionSetValue &value);
    OpcUa_StatusCode setValue(int iIndex, const UaGenericOptionSetValue &value);

    OpcUa_StatusCode setValue(const UaString &sFieldName, const UaGenericOptionSetArray &value);
    OpcUa_StatusCode setValue(int iIndex, const UaGenericOptionSetArray &value);

    UaVariant value() const;
    UaGenericStructureValue genericStructure(OpcUa_StatusCode *status = 0) const;
    UaGenericStructureArray genericStructureArray(OpcUa_StatusCode *status = 0) const;
    UaGenericUnionValue genericUnion(OpcUa_StatusCode *status = 0) const;
    UaGenericUnionArray genericUnionArray(OpcUa_StatusCode *status = 0) const;
    UaGenericOptionSetValue genericOptionSet(OpcUa_StatusCode *status = 0) const;
    UaGenericOptionSetArray genericOptionSetArray(OpcUa_StatusCode *status = 0) const;
    int switchValue() const;
    UaStructureField field() const;

    virtual UaStructureDefinition definition() const;

    void decode(UaAbstractDecoder *pDecoder);
    void encode(UaAbstractEncoder *pEncoder) const;

    OpcUa_StatusCode checkExtensionObject(const UaExtensionObject &extensionObject, const UaStructureDefinition &definition) const;
    void setExtensionObject(const UaExtensionObject &extensionObject, const UaStructureDefinition &definition);

    UaString toString() const;
};

/** The class encapsulates an array of UaGenericUnionValue and handles memory allocation
 *  and cleanup.
 */
class UABASE_EXPORT UaGenericUnionArray
{
    UA_DECLARE_PRIVATE(UaGenericUnionArray)
public:
    UaGenericUnionArray(const UaStructureDefinition &definition);
    UaGenericUnionArray(const UaGenericUnionArray &other);
    UaGenericUnionArray(const UaByteString &bsData,
            UaAbstractGenericValue::Encoding valueEncoding,
            const UaStructureDefinition &structureDefinition);
    UaGenericUnionArray(const UaExtensionObjectArray &extensionObjects,
            const UaStructureDefinition &structureDefinition);
    ~UaGenericUnionArray();

    UaGenericUnionArray& operator=(const UaGenericUnionArray &other);

    UaStructureDefinition definition() const;
    const UaGenericUnionValue& operator[](OpcUa_UInt32 index) const;
    UaGenericUnionValue& operator[](OpcUa_UInt32 index);

    bool operator==(const UaGenericUnionArray &other) const;
    bool operator!=(const UaGenericUnionArray &other) const;

    void create(OpcUa_UInt32 length);
    void clear();

    OpcUa_UInt32 length() const;

    void toVariant(UaVariant &variant) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    OpcUa_StatusCode setGenericUnionArray(const UaVariant &variant);
};

#endif // UAGENERICUNIONVALUE_H
