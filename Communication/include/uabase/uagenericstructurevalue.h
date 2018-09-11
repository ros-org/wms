/******************************************************************************
** uagenericvalue.h
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
#ifndef UAGENERICSTRUCTUREVALUE_H
#define UAGENERICSTRUCTUREVALUE_H

#include "uaabstractgenericstructurevalue.h"
#include "uaarraytemplates.h"
#include "uastructurefielddata.h"

class UaByteString;
class UABASE_EXPORT UaGenericStructureValuePrivate;
class UABASE_EXPORT UaGenericStructureArrayPrivate;
class UABASE_EXPORT UaGenericStructureArray;
class UABASE_EXPORT UaGenericUnionValue;
class UABASE_EXPORT UaGenericUnionArray;

/** A class that serializes and deserializes data that is described by an UaStructureDefinition.
 *
 * The serialized data can be accessed by index or by field name.
 * The class can be used for DataTypes that are not registered to the stack.
 */
class UABASE_EXPORT UaGenericStructureValue : public UaAbstractGenericStructureValue
{
    UA_DECLARE_PRIVATE(UaGenericStructureValue)
public:
    UaGenericStructureValue();
    UaGenericStructureValue(const UaStructureDefinition &structureDefinition);
    UaGenericStructureValue(const UaGenericStructureValue &other);
    UaGenericStructureValue(const UaByteString &bsData, Encoding valueEncoding, const UaStructureDefinition &structureDefinition);
    UaGenericStructureValue(const UaExtensionObject &extensionObject, const UaStructureDefinition &structureDefinition);
    virtual ~UaGenericStructureValue();

    virtual void clear();

    bool operator==(const UaGenericStructureValue &other) const;
    bool operator!=(const UaGenericStructureValue &other) const;

    UaGenericStructureValue& operator=(const UaGenericStructureValue &other);

    OpcUa_StatusCode setGenericValue(const UaByteString &bsData, Encoding valueEncoding, const UaStructureDefinition &structureDefinition);
    OpcUa_StatusCode setGenericValue(const UaExtensionObject &extensionObject, const UaStructureDefinition &structureDefinition);

    OpcUa_StatusCode setField(const UaString &sFieldName, UaVariant &value, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setField(int iIndex, UaVariant &value, OpcUa_Boolean bDetach);

    OpcUa_StatusCode setField(const UaString &sFieldName, const UaVariant &value);
    OpcUa_StatusCode setField(int iIndex, const UaVariant &value);

    OpcUa_StatusCode setField(const UaString &sFieldName, const UaGenericStructureValue &value);
    OpcUa_StatusCode setField(int iIndex, const UaGenericStructureValue &value);

    OpcUa_StatusCode setField(const UaString &sFieldName, const UaGenericStructureArray &values);
    OpcUa_StatusCode setField(int iIndex, const UaGenericStructureArray &values);

    OpcUa_StatusCode setField(const UaString &sFieldName, const UaGenericUnionValue &value);
    OpcUa_StatusCode setField(int iIndex, const UaGenericUnionValue &value);

    OpcUa_StatusCode setField(const UaString &sFieldName, const UaGenericUnionArray &values);
    OpcUa_StatusCode setField(int iIndex, const UaGenericUnionArray &values);

    OpcUa_StatusCode setField(const UaString &sFieldName, const UaGenericOptionSetValue &value);
    OpcUa_StatusCode setField(int iIndex, const UaGenericOptionSetValue &value);

    OpcUa_StatusCode setField(const UaString &sFieldName, const UaGenericOptionSetArray &values);
    OpcUa_StatusCode setField(int iIndex, const UaGenericOptionSetArray &values);

    UaStructureFieldDataType valueType(int iIndex, OpcUa_StatusCode *status = 0) const;

    UaVariant value(const UaString &sFieldName, OpcUa_StatusCode *status = 0) const;
    UaVariant value(int iIndex, OpcUa_StatusCode *status = 0) const;

    UaGenericStructureValue genericStructure(const UaString &sFieldName, OpcUa_StatusCode *status = 0) const;
    UaGenericStructureValue genericStructure(int iIndex, OpcUa_StatusCode *status = 0) const;

    UaGenericStructureArray genericStructureArray(const UaString &sFieldName, OpcUa_StatusCode *status = 0) const;
    UaGenericStructureArray genericStructureArray(int iIndex, OpcUa_StatusCode *status = 0) const;

    UaGenericUnionValue genericUnion(const UaString &sFieldName, OpcUa_StatusCode *status = 0) const;
    UaGenericUnionValue genericUnion(int iIndex, OpcUa_StatusCode *status = 0) const;

    UaGenericUnionArray genericUnionArray(const UaString &sFieldName, OpcUa_StatusCode *status = 0) const;
    UaGenericUnionArray genericUnionArray(int iIndex, OpcUa_StatusCode *status = 0) const;

    UaGenericOptionSetValue genericOptionSet(const UaString &sFieldName, OpcUa_StatusCode *status = 0) const;
    UaGenericOptionSetValue genericOptionSet(int iIndex, OpcUa_StatusCode *status = 0) const;

    UaGenericOptionSetArray genericOptionSetArray(const UaString &sFieldName, OpcUa_StatusCode *status = 0) const;
    UaGenericOptionSetArray genericOptionSetArray(int iIndex, OpcUa_StatusCode *status = 0) const;

    bool isFieldSet(const UaString &sFieldName) const;
    bool isFieldSet(int iIndex) const;

    OpcUa_StatusCode unsetField(const UaString &sFieldName);
    OpcUa_StatusCode unsetField(int iIndex);

    UaStructureDefinition definition() const;
    void setDefinition(const UaStructureDefinition &definition, bool bCreateDefaultValues = false);

    UaString toString() const;

    void decode(UaAbstractDecoder *pDecoder);
    void encode(UaAbstractEncoder *pEncoder) const;

private:
    void setField(const UaStructureField &field, int iIndex, UaVariant &value);
    OpcUa_UInt32 optionalFieldMask() const;
    void createDefaultValues();
    OpcUa_StatusCode checkExtensionObject(const UaExtensionObject &extensionObject, const UaStructureDefinition &definition) const;
    void setExtensionObject(const UaExtensionObject &extensionObject, const UaStructureDefinition &definition);
    void checkRefCount();
};

/** The class encapsulates an array of UaGenericStructureValue and handles memory allocation
 *  and cleanup.
 */
class UABASE_EXPORT UaGenericStructureArray
{
    UA_DECLARE_PRIVATE(UaGenericStructureArray)
public:
    UaGenericStructureArray(const UaStructureDefinition &definition);
    UaGenericStructureArray(const UaGenericStructureArray &other);
    UaGenericStructureArray(const UaByteString &bsData,
            UaAbstractGenericValue::Encoding valueEncoding,
            const UaStructureDefinition &structureDefinition);
    UaGenericStructureArray(const UaExtensionObjectArray &extensionObjects,
            const UaStructureDefinition &structureDefinition);
    ~UaGenericStructureArray();

    UaGenericStructureArray& operator=(const UaGenericStructureArray &other);

    UaStructureDefinition definition() const;
    const UaGenericStructureValue& operator[](OpcUa_UInt32 index) const;
    UaGenericStructureValue& operator[](OpcUa_UInt32 index);

    bool operator==(const UaGenericStructureArray &other) const;
    bool operator!=(const UaGenericStructureArray &other) const;

    void create(OpcUa_UInt32 length);
    void clear();

    OpcUa_UInt32 length() const;

    void toVariant(UaVariant &variant) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    OpcUa_StatusCode setGenericValueArray(const UaVariant &variant);
};

#endif // UAGENERICSTRUCTUREVALUE_H
