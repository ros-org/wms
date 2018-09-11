/******************************************************************************
** uaabstractencoder.h
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
#ifndef UAABSTRACTENCODER_H
#define UAABSTRACTENCODER_H

#include "uabase.h"

#include <vector>

#include <statuscode.h>
#include "uaencodertype.h"

class UaByteString;
class UaDateTime;
class UaGuid;
class UaNodeId;
class UaExpandedNodeId;
class UaDiagnosticInfo;
class UaExpandedNodeId;
class UaExtensionObject;
class UaGenericStructureValue;
class UaGenericStructureArray;
class UaGenericUnionValue;
class UaGenericUnionArray;
class UaGenericOptionSetValue;
class UaGenericOptionSetArray;

/** This is an abstract base class for an encoder.
 * The encoder is used for serializing the data of a UaGenericValue.
  */
class UABASE_EXPORT UaAbstractEncoder
{
public:
    UaAbstractEncoder();
    virtual ~UaAbstractEncoder();

    /** Returns the type of the encoder - Binary or Xml
    */
    virtual UaEncoderType encoderType() const = 0;

    /** Pushes a namespace to the namespace stack.
     *
     * The NamespaceUri of a structured or an enumerated
     * DataType has to be pushed before writing it.
     */
    virtual void pushNamespace(const UaString &sNamespace) = 0;
    /** Pops a namespace from the namespace stack.
     *
     * Has to be called after writing a structured or an
     * enumerated DataType.
     */
    virtual void popNamespace() = 0;

    /** Writes a Boolean value. */
    virtual OpcUa_StatusCode writeBoolean(const UaString &sFieldName, OpcUa_Boolean value) = 0;
    /** Writes a ByteString value. */
    virtual OpcUa_StatusCode writeByteString(const UaString &sFieldName, const UaByteString &value) = 0;
    /** Writes a DataValue value. */
    virtual OpcUa_StatusCode writeDataValue(const UaString &sFieldName, const UaDataValue &value) = 0;
    /** Writes a DateTime value. */
    virtual OpcUa_StatusCode writeDateTime(const UaString &sFieldName, const UaDateTime &value) = 0;
    /** Writes a DiagnosticInfo value. */
    virtual OpcUa_StatusCode writeDiagnosticInfo(const UaString &sFieldName, const UaDiagnosticInfo &value) = 0;
    /** Writes an ExpandedNodeId value. */
    virtual OpcUa_StatusCode writeExpandedNodeId(const UaString &sFieldName, const UaExpandedNodeId &value) = 0;
    /** Writes a Guid value. */
    virtual OpcUa_StatusCode writeGuid(const UaString &sFieldName, const UaGuid &value) = 0;
    /** Writes a LocalizedText value. */
    virtual OpcUa_StatusCode writeLocalizedText(const UaString &sFieldName, const UaLocalizedText &value) = 0;
    /** Writes a NodeId value. */
    virtual OpcUa_StatusCode writeNodeId(const UaString &sFieldName, const UaNodeId &value) = 0;
    /** Writes a Double value. */
    virtual OpcUa_StatusCode writeDouble(const UaString &sFieldName, OpcUa_Double value) = 0;
    /** Writes a Float value. */
    virtual OpcUa_StatusCode writeFloat(const UaString &sFieldName, OpcUa_Float value) = 0;
    /** Writes an Int16 value. */
    virtual OpcUa_StatusCode writeInt16(const UaString &sFieldName, OpcUa_Int16 value) = 0;
    /** Writes an Int32 value. */
    virtual OpcUa_StatusCode writeInt32(const UaString &sFieldName, OpcUa_Int32 value) = 0;
    /** Writes an Int64 value. */
    virtual OpcUa_StatusCode writeInt64(const UaString &sFieldName, OpcUa_Int64 value) = 0;
    /** Writes an SByte value. */
    virtual OpcUa_StatusCode writeSByte(const UaString &sFieldName, OpcUa_SByte value) = 0;
    /** Writes a Byte value. */
    virtual OpcUa_StatusCode writeByte(const UaString &sFieldName, OpcUa_Byte value) = 0;
    /** Writes a UInt16 value. */
    virtual OpcUa_StatusCode writeUInt16(const UaString &sFieldName, OpcUa_UInt16 value) = 0;
    /** Writes a UInt32 value. */
    virtual OpcUa_StatusCode writeUInt32(const UaString &sFieldName, OpcUa_UInt32 value) = 0;
    /** Writes a UInt64 value. */
    virtual OpcUa_StatusCode writeUInt64(const UaString &sFieldName, OpcUa_UInt64 valueu) = 0;
    /** Writes a QualifiedName value. */
    virtual OpcUa_StatusCode writeQualifiedName(const UaString &sFieldName, const UaQualifiedName &value) = 0;
    /** Writes a StatusCode value. */
    virtual OpcUa_StatusCode writeStatusCode(const UaString &sFieldName, const UaStatusCode &value) = 0;
    /** Writes a Boolean value. */
    virtual OpcUa_StatusCode writeString(const UaString &sFieldName, const UaString &value) = 0;
    /** Writes a Variant value. */
    virtual OpcUa_StatusCode writeVariant(const UaString &sFieldName, const UaVariant &value) = 0;
    /** Writes an ExtensionObject value. */
    virtual OpcUa_StatusCode writeExtensionObject(const UaString &sFieldName, const UaExtensionObject &value) = 0;
    /** Writes a GenericValue value. */
    virtual OpcUa_StatusCode writeGenericValue(const UaString &sFieldName, const UaGenericStructureValue &value) = 0;
    /** Writes a GenericUnion value. */
    virtual OpcUa_StatusCode writeGenericUnion(const UaString &sFieldName, const UaGenericUnionValue &value) = 0;
    /** Writes a GenericOptionSet value. */
    virtual OpcUa_StatusCode writeGenericOptionSet(const UaString &sFieldName, const UaGenericOptionSetValue &value) = 0;
    /** Writes an XmlElement value. */
    virtual OpcUa_StatusCode writeXmlElement(const UaString &sFieldName, const UaByteString &value) = 0;

    /** Writes an array of Boolean values. */
    virtual OpcUa_StatusCode writeBooleanArray(const UaString &sFieldName, const UaBoolArray &value) = 0;
    /** Writes an array of ByteString values. */
    virtual OpcUa_StatusCode writeByteStringArray(const UaString &sFieldName, const UaByteStringArray &value) = 0;
    /** Writes an array of DataValue values. */
    virtual OpcUa_StatusCode writeDataValueArray(const UaString &sFieldName, const UaDataValues &value) = 0;
    /** Writes an array of DateTime values. */
    virtual OpcUa_StatusCode writeDateTimeArray(const UaString &sFieldName, const UaDateTimeArray &value) = 0;
    /** Writes an array of DiagnosticInfo values. */
    virtual OpcUa_StatusCode writeDiagnosticInfoArray(const UaString &sFieldName, const UaDiagnosticInfos &value) = 0;
    /** Writes an array of ExpandedNodeId values. */
    virtual OpcUa_StatusCode writeExpandedNodeIdArray(const UaString &sFieldName, const UaExpandedNodeIdArray &value) = 0;
    /** Writes an array of Guid values. */
    virtual OpcUa_StatusCode writeGuidArray(const UaString &sFieldName, const UaGuidArray &value) = 0;
    /** Writes an array of LocalizedText values. */
    virtual OpcUa_StatusCode writeLocalizedTextArray(const UaString &sFieldName, const UaLocalizedTextArray &value) = 0;
    /** Writes an array of NodeId values. */
    virtual OpcUa_StatusCode writeNodeIdArray(const UaString &sFieldName, const UaNodeIdArray &value) = 0;
    /** Writes an array of Double values. */
    virtual OpcUa_StatusCode writeDoubleArray(const UaString &sFieldName, const UaDoubleArray &value) = 0;
    /** Writes an array of Float values. */
    virtual OpcUa_StatusCode writeFloatArray(const UaString &sFieldName, const UaFloatArray &value) = 0;
    /** Writes an array of Int16 values. */
    virtual OpcUa_StatusCode writeInt16Array(const UaString &sFieldName, const UaInt16Array &value) = 0;
    /** Writes an array of Int32 values. */
    virtual OpcUa_StatusCode writeInt32Array(const UaString &sFieldName, const UaInt32Array &value) = 0;
    /** Writes an array of Int64 values. */
    virtual OpcUa_StatusCode writeInt64Array(const UaString &sFieldName, const UaInt64Array &value) = 0;
    /** Writes an array of SByte values. */
    virtual OpcUa_StatusCode writeSByteArray(const UaString &sFieldName, const UaSByteArray &value) = 0;
    /** Writes an array of Byte values. */
    virtual OpcUa_StatusCode writeByteArray(const UaString &sFieldName, const UaByteArray &value) = 0;
    /** Writes an array of UInt16 values. */
    virtual OpcUa_StatusCode writeUInt16Array(const UaString &sFieldName, const UaUInt16Array &value) = 0;
    /** Writes an array of UInt32 values. */
    virtual OpcUa_StatusCode writeUInt32Array(const UaString &sFieldName, const UaUInt32Array &value) = 0;
    /** Writes an array of UInt64 values. */
    virtual OpcUa_StatusCode writeUInt64Array(const UaString &sFieldName, const UaUInt64Array &value) = 0;
    /** Writes an array of QualifiedName values. */
    virtual OpcUa_StatusCode writeQualifiedNameArray(const UaString &sFieldName, const UaQualifiedNameArray &value) = 0;
    /** Writes an array of StatusCode values. */
    virtual OpcUa_StatusCode writeStatusCodeArray(const UaString &sFieldName, const UaStatusCodeArray &value) = 0;
    /** Writes an array of String values. */
    virtual OpcUa_StatusCode writeStringArray(const UaString &sFieldName, const UaStringArray &value) = 0;
    /** Writes an array of Variant values. */
    virtual OpcUa_StatusCode writeVariantArray(const UaString &sFieldName, const UaVariantArray &value) = 0;
    /** Writes an array of ExtensionObject values. */
    virtual OpcUa_StatusCode writeExtensionObjectArray(const UaString &sFieldName, const UaExtensionObjectArray &value) = 0;
    /** Deprecated: Writes an array of GenericValue values. */
    virtual OpcUa_StatusCode writeGenericValueArray(const UaString &sFieldName, const std::vector<UaGenericStructureValue> &value) = 0;
    /** Writes an array of GenericValue values. */
    virtual OpcUa_StatusCode writeGenericValueArray(const UaString &sFieldName, const UaGenericStructureArray &value) = 0;
    /** Writes an array of GenericUnion values. */
    virtual OpcUa_StatusCode writeGenericUnionArray(const UaString &sFieldName, const UaGenericUnionArray &value) = 0;
    /** Writes an array of GenericOptionSet values. */
    virtual OpcUa_StatusCode writeGenericOptionSetArray(const UaString &sFieldName, const UaGenericOptionSetArray &value) = 0;
    /** Writes an array of XmlElement values. */
    virtual OpcUa_StatusCode writeXmlElementArray(const UaString &sFieldName, const UaByteStringArray &value) = 0;
};
#endif // UAABSTRACTENCODER_H
