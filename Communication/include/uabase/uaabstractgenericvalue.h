/******************************************************************************
** uaabstractgenericvalue.h
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
#ifndef UAABSTRACTGENERICVALUE_H
#define UAABSTRACTGENERICVALUE_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uastructuredefinition.h"
//#include "uastructurefielddata.h"

class UaExtensionObject;
class UaDataValue;
class UaAbstractDecoder;
class UaAbstractEncoder;
class UaStructureField;
class UaStructureFieldData;

/******************************************************************************
** Class UaAbstractGenericValue
******************************************************************************/

/** Base class for handling values of structured DataTypes that are not known at compile time.*/
class UABASE_EXPORT UaAbstractGenericValue
{
public:
    /** The possible encodings for a UaAbstractGenericValue. */
    enum Encoding
    {
#ifdef HAVE_XML_ENCODER
        Encoding_Binary = OpcUa_ExtensionObjectEncoding_Binary,
        Encoding_Xml    = OpcUa_ExtensionObjectEncoding_Xml
#else
        Encoding_Binary = OpcUa_ExtensionObjectEncoding_Binary
#endif
    };

    UaAbstractGenericValue();
    virtual ~UaAbstractGenericValue();

    /** Clears the value. */
    virtual void clear() = 0;

    virtual void toVariant(UaVariant &variant, Encoding valueEncoding = Encoding_Binary) const;
    virtual void toVariant(OpcUa_Variant &variant, Encoding valueEncoding = Encoding_Binary) const;

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps, Encoding valueEncoding = Encoding_Binary) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps, Encoding valueEncoding = Encoding_Binary) const;

    void toExtensionObject(UaExtensionObject &extensionObject, Encoding valueEncoding = Encoding_Binary) const;
    void toExtensionObject(OpcUa_ExtensionObject &extensionObject, Encoding valueEncoding = Encoding_Binary) const;

    /** Deserializes the instance. */
    virtual void decode(UaAbstractDecoder *pDecoder) = 0;
    /** Serializes the instance. */
    virtual void encode(UaAbstractEncoder *pEncoder) const = 0;

protected:
    virtual UaNodeId binaryEncodingId() const = 0;
#ifdef HAVE_XML_ENCODER
    virtual UaNodeId xmlEncodingId() const = 0;
#endif

protected:
    UaStructureFieldData readField(UaAbstractDecoder *pDecoder, const UaStructureField &field) const;
    void writeField(UaAbstractEncoder *pEncoder, const UaStructureField &field, const UaStructureFieldData &value) const;
};

#endif // UAABSTRACTGENERICVALUE_H
