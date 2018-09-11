/******************************************************************************
** uaabstractdecoder.h
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
#ifndef UAABSTRACTDECODER_H
#define UAABSTRACTDECODER_H

#include "uabase.h"

#include <vector>

#include <statuscode.h>
#include "uaencodertype.h"

class UaByteString;
class UaExpandedNodeId;
class UaExtensionObject;
class UaGuid;
class UaNodeId;
class UaDateTime;
class UaGenericStructureValue;
class UaGenericStructureArray;
class UaGenericUnionValue;
class UaGenericUnionArray;
class UaGenericOptionSetValue;
class UaGenericOptionSetArray;
class UaStructureDefinition;

/** This is an abstract base class for a decoder.
 * The decoder is used for deserializing data to an UaGenericValue.
 */
class UABASE_EXPORT UaAbstractDecoder
{
public:
    UaAbstractDecoder();
    virtual ~UaAbstractDecoder();

    /** Returns the type of the decoder - Binary or Xml
    */
    virtual UaEncoderType decoderType() const = 0;

    /** Pushes a namespace to the namespace stack.
     *
     * The NamespaceUri of a structured or an enumerated
     * DataType has to be pushed before reading it.
     */
    virtual void pushNamespace(const UaString &sNamespace) = 0;
    /** Pops a namespace from the namespace stack.
     *
     * Has to be called after reading a structured or an
     * enumerated DataType.
     */
    virtual void popNamespace() = 0;

    /** Reads a Boolean value. */
    virtual OpcUa_StatusCode readBoolean(const UaString &sFieldName, OpcUa_Boolean &rValue) = 0;
    /** Reads a ByteString value. */
    virtual OpcUa_StatusCode readByteString(const UaString &sFieldName, UaByteString &rValue) = 0;
    /** Reads a DataValue value. */
    virtual OpcUa_StatusCode readDataValue(const UaString &sFieldName, UaDataValue &rValue) = 0;
    /** Reads a DateTime value. */
    virtual OpcUa_StatusCode readDateTime(const UaString &sFieldName, UaDateTime &rValue) = 0;
    /** Reads a DiagnosticInfo value. */
    virtual OpcUa_StatusCode readDiagnosticInfo(const UaString &sFieldName, UaDiagnosticInfo &rValue) = 0;
    /** Reads an ExpandedNodeId value. */
    virtual OpcUa_StatusCode readExpandedNodeId(const UaString &sFieldName, UaExpandedNodeId &rValue) = 0;
    /** Reads a Guid value. */
    virtual OpcUa_StatusCode readGuid(const UaString &sFieldName, UaGuid &rValue) = 0;
    /** Reads a LocalizedText value. */
    virtual OpcUa_StatusCode readLocalizedText(const UaString &sFieldName, UaLocalizedText &rValue) = 0;
    /** Reads a NodeId value. */
    virtual OpcUa_StatusCode readNodeId(const UaString &sFieldName, UaNodeId &rValue) = 0;
    /** Reads a Double value. */
    virtual OpcUa_StatusCode readDouble(const UaString &sFieldName, OpcUa_Double &rValue) = 0;
    /** Reads a Float value. */
    virtual OpcUa_StatusCode readFloat(const UaString &sFieldName, OpcUa_Float &rValue) = 0;
    /** Reads an Int16 value. */
    virtual OpcUa_StatusCode readInt16(const UaString &sFieldName, OpcUa_Int16 &rValue) = 0;
    /** Reads an Int32 value. */
    virtual OpcUa_StatusCode readInt32(const UaString &sFieldName, OpcUa_Int32 &rValue) = 0;
    /** Reads an Int64 value. */
    virtual OpcUa_StatusCode readInt64(const UaString &sFieldName, OpcUa_Int64 &rValue) = 0;
    /** Reads a SByte value. */
    virtual OpcUa_StatusCode readSByte(const UaString &sFieldName, OpcUa_SByte &rValue) = 0;
    /** Reads a Byte value. */
    virtual OpcUa_StatusCode readByte(const UaString &sFieldName, OpcUa_Byte &rValue) = 0;
    /** Reads an UInt16 value. */
    virtual OpcUa_StatusCode readUInt16(const UaString &sFieldName, OpcUa_UInt16 &rValue) = 0;
    /** Reads an UInt32 value. */
    virtual OpcUa_StatusCode readUInt32(const UaString &sFieldName, OpcUa_UInt32 &rValue) = 0;
    /** Reads an UInt64 value. */
    virtual OpcUa_StatusCode readUInt64(const UaString &sFieldName, OpcUa_UInt64 &rValue) = 0;
    /** Reads a QualifiedName value. */
    virtual OpcUa_StatusCode readQualifiedName(const UaString &sFieldName, UaQualifiedName &rValue) = 0;
    /** Reads a StatusCode value. */
    virtual OpcUa_StatusCode readStatusCode(const UaString &sFieldName, UaStatusCode &rValue) = 0;
    /** Reads a String value. */
    virtual OpcUa_StatusCode readString(const UaString &sFieldName, UaString &rValue) = 0;
    /** Reads a Variant value. */
    virtual OpcUa_StatusCode readVariant(const UaString &sFieldName, UaVariant &rValue) = 0;
    /** Reads an ExtensionObject value. */
    virtual OpcUa_StatusCode readExtensionObject(const UaString &sFieldName, UaExtensionObject &rValue) = 0;
    /** Reads a GenericValue value. */
    virtual OpcUa_StatusCode readGenericValue(const UaString &sFieldName, UaGenericStructureValue &rValue) = 0;
    /** Reads a GenericUnion value. */
    virtual OpcUa_StatusCode readGenericUnion(const UaString &sFieldName, UaGenericUnionValue &rValue) = 0;
    /** Reads a GenericOptionSet value. */
    virtual OpcUa_StatusCode readGenericOptionSet(const UaString &sFieldName, UaGenericOptionSetValue &rValue) = 0;
    /** Reads an XmlElement value. */
    virtual OpcUa_StatusCode readXmlElement(const UaString &sFieldName, UaByteString &rValue) = 0;

    /** Reads an array of Boolean values. */
    virtual OpcUa_StatusCode readBooleanArray(const UaString &sFieldName, UaBoolArray &rValue) = 0;
    /** Reads an array of ByteString values. */
    virtual OpcUa_StatusCode readByteStringArray(const UaString &sFieldName, UaByteStringArray &rValue) = 0;
    /** Reads an array of DataValue values. */
    virtual OpcUa_StatusCode readDataValueArray(const UaString &sFieldName, UaDataValues &rValue) = 0;
    /** Reads an array of DateTime values. */
    virtual OpcUa_StatusCode readDateTimeArray(const UaString &sFieldName, UaDateTimeArray &rValue) = 0;
    /** Reads an array of DiagnosticInfo values. */
    virtual OpcUa_StatusCode readDiagnosticInfoArray(const UaString &sFieldName, UaDiagnosticInfos &rValue) = 0;
    /** Reads an array of NodeId values. */
    virtual OpcUa_StatusCode readExpandedNodeIdArray(const UaString &sFieldName, UaExpandedNodeIdArray &rValue) = 0;
    /** Reads an array of Guid values. */
    virtual OpcUa_StatusCode readGuidArray(const UaString &sFieldName, UaGuidArray &rValue) = 0;
    /** Reads an array of LocalizedText values. */
    virtual OpcUa_StatusCode readLocalizedTextArray(const UaString &sFieldName, UaLocalizedTextArray &rValue) = 0;
    /** Reads an array of NodeId values. */
    virtual OpcUa_StatusCode readNodeIdArray(const UaString &sFieldName, UaNodeIdArray &rValue) = 0;
    /** Reads an array of Double values. */
    virtual OpcUa_StatusCode readDoubleArray(const UaString &sFieldName, UaDoubleArray &rValue) = 0;
    /** Reads an array of Float values. */
    virtual OpcUa_StatusCode readFloatArray(const UaString &sFieldName, UaFloatArray &rValue) = 0;
    /** Reads an array of Int16 values. */
    virtual OpcUa_StatusCode readInt16Array(const UaString &sFieldName, UaInt16Array &rValue) = 0;
    /** Reads an array of Int32 values. */
    virtual OpcUa_StatusCode readInt32Array(const UaString &sFieldName, UaInt32Array &rValue) = 0;
    /** Reads an array of Int64 values. */
    virtual OpcUa_StatusCode readInt64Array(const UaString &sFieldName, UaInt64Array &rValue) = 0;
    /** Reads an array of SByte values. */
    virtual OpcUa_StatusCode readSByteArray(const UaString &sFieldName, UaSByteArray &rValue) = 0;
    /** Reads an array of Byte values. */
    virtual OpcUa_StatusCode readByteArray(const UaString &sFieldName, UaByteArray &rValue) = 0;
    /** Reads an array of UInt16 values. */
    virtual OpcUa_StatusCode readUInt16Array(const UaString &sFieldName, UaUInt16Array &rValue) = 0;
    /** Reads an array of UInt32 values. */
    virtual OpcUa_StatusCode readUInt32Array(const UaString &sFieldName, UaUInt32Array &rValue) = 0;
    /** Reads an array of UInt64 values. */
    virtual OpcUa_StatusCode readUInt64Array(const UaString &sFieldName, UaUInt64Array &rValue) = 0;
    /** Reads an array of QualifiedName values. */
    virtual OpcUa_StatusCode readQualifiedNameArray(const UaString &sFieldName, UaQualifiedNameArray &rValue) = 0;
    /** Reads an array of StatusCode values. */
    virtual OpcUa_StatusCode readStatusCodeArray(const UaString &sFieldName, UaStatusCodeArray &rValue) = 0;
    /** Reads an array of String values. */
    virtual OpcUa_StatusCode readStringArray(const UaString &sFieldName, UaStringArray &rValue) = 0;
    /** Reads an array of Variant values. */
    virtual OpcUa_StatusCode readVariantArray(const UaString &sFieldName, UaVariantArray &rValue) = 0;
    /** Reads an array of ExtensionObject values. */
    virtual OpcUa_StatusCode readExtensionObjectArray(const UaString &sFieldName, UaExtensionObjectArray &rValue) = 0;
    /** Deprecated: Reads an array of GenericValue values. */
    virtual OpcUa_StatusCode readGenericValueArray(const UaString &sFieldName, std::vector<UaGenericStructureValue> &rValue, UaStructureDefinition structureDefinition) = 0;
    /** Reads an array of GenericValue values. */
    virtual OpcUa_StatusCode readGenericValueArray(const UaString &sFieldName, UaGenericStructureArray &rValue) = 0;
    /** Reads an array of GenericUnion values. */
    virtual OpcUa_StatusCode readGenericUnionArray(const UaString &sFieldName, UaGenericUnionArray &rValue) = 0;
    /** Reads an array of GenericOptionSet values. */
    virtual OpcUa_StatusCode readGenericOptionSetArray(const UaString &sFieldName, UaGenericOptionSetArray &rValue) = 0;
    /** Reads an array of XmlElement values. */
    virtual OpcUa_StatusCode readXmlElementArray(const UaString &sFieldName, UaByteStringArray &rValue) = 0;
};

#endif // UAABSTRACTDECODER_H
