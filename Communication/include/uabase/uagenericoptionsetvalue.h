/******************************************************************************
** uagenericoptionsetvalue.h
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
#ifndef UAGENERICOPTIONSETVALUE_H
#define UAGENERICOPTIONSETVALUE_H

#include "uaabstractgenericvalue.h"
#include "uaarraytemplates.h"
#include "uastructurefielddata.h"

class UaByteString;
class UABASE_EXPORT UaGenericOptionSetValuePrivate;
class UABASE_EXPORT UaGenericOptionSetArrayPrivate;
class UABASE_EXPORT UaGenericOptionSetArray;
class UABASE_EXPORT UaGenericUnionValue;
class UABASE_EXPORT UaGenericUnionArray;

/** A class that serializes and deserializes data that is described by an UaOptionSetDefinition.
 *
 * The serialized data can be accessed by index or by field name.
 * The class can be used for DataTypes that are not registered to the stack.
 */
class UABASE_EXPORT UaGenericOptionSetValue : public UaAbstractGenericValue
{
    UA_DECLARE_PRIVATE(UaGenericOptionSetValue)
public:
    UaGenericOptionSetValue();
    UaGenericOptionSetValue(const UaOptionSetDefinition &optionSetDefinition);
    UaGenericOptionSetValue(const UaGenericOptionSetValue &other);
    UaGenericOptionSetValue(const UaVariant &value, const UaOptionSetDefinition &optionSetDefinition);
    virtual ~UaGenericOptionSetValue();

    virtual void clear();

    bool operator==(const UaGenericOptionSetValue &other) const;
    bool operator!=(const UaGenericOptionSetValue &other) const;

    UaGenericOptionSetValue& operator=(const UaGenericOptionSetValue &other);

    OpcUa_StatusCode setOptionSetValue(const UaVariant &value, const UaOptionSetDefinition &optionSetDefinition);

    OpcUa_StatusCode setValue(const UaString &sFieldName, OpcUa_Boolean bValue);
    OpcUa_StatusCode setValue(int iIndex, OpcUa_Boolean bValue);
    OpcUa_StatusCode setValidBit(const UaString &sFieldName, OpcUa_Boolean bValue);
    OpcUa_StatusCode setValidBit(int iIndex, OpcUa_Boolean bValue);

    OpcUa_Boolean value(const UaString &sFieldName, OpcUa_StatusCode *status = 0) const;
    OpcUa_Boolean value(int iIndex, OpcUa_StatusCode *status = 0) const;
    OpcUa_Boolean validBit(const UaString &sFieldName, OpcUa_StatusCode *status = 0) const;
    OpcUa_Boolean validBit(int iIndex, OpcUa_StatusCode *status = 0) const;

    UaOptionSetDefinition optionSetDefinition() const;
    void setOptionSetDefinition(const UaOptionSetDefinition &definition);

    UaString toString() const;
    virtual void toVariant(UaVariant &variant, Encoding valueEncoding = Encoding_Binary) const;
    virtual void toVariant(OpcUa_Variant &variant, Encoding valueEncoding = Encoding_Binary) const;


    void decode(UaAbstractDecoder *pDecoder);
    void encode(UaAbstractEncoder *pEncoder) const;

protected:
    virtual UaNodeId binaryEncodingId() const;
#ifdef HAVE_XML_ENCODER
    virtual UaNodeId xmlEncodingId() const;
#endif
};

/** The class encapsulates an array of UaGenericOptionSetValue and handles memory allocation
 *  and cleanup.
 */
class UABASE_EXPORT UaGenericOptionSetArray
{
    UA_DECLARE_PRIVATE(UaGenericOptionSetArray)
public:
    UaGenericOptionSetArray(const UaOptionSetDefinition &optionSetDefinition);
    UaGenericOptionSetArray(const UaGenericOptionSetArray &other);
    UaGenericOptionSetArray(const UaVariant &value, const UaOptionSetDefinition &optionSetDefinition);
    ~UaGenericOptionSetArray();

    UaGenericOptionSetArray& operator=(const UaGenericOptionSetArray &other);

    UaOptionSetDefinition optionSetDefinition() const;
    const UaGenericOptionSetValue& operator[](OpcUa_UInt32 index) const;
    UaGenericOptionSetValue& operator[](OpcUa_UInt32 index);

    bool operator==(const UaGenericOptionSetArray &other) const;
    bool operator!=(const UaGenericOptionSetArray &other) const;

    void create(OpcUa_UInt32 length);
    void clear();

    OpcUa_UInt32 length() const;

    void toVariant(UaVariant &variant, UaAbstractGenericValue::Encoding valueEncoding = UaAbstractGenericValue::Encoding_Binary) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps, UaAbstractGenericValue::Encoding valueEncoding = UaAbstractGenericValue::Encoding_Binary) const;
    OpcUa_StatusCode setGenericOptionSetArray(const UaVariant &value);
};

#endif // UAGENERICOPTIONSETVALUE_H
