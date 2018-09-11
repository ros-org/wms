/******************************************************************************
** uabinarydecoder.h
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
#ifndef UABINARYDECODER_H
#define UABINARYDECODER_H

#include "uabase.h"
#include "uaabstractdecoder.h"
#include "opcua_messagecontext.h"

struct _OpcUa_InputStream;
struct _OpcUa_Decoder;

/** Class used for deserializing a UaByteString.
 *
 * This class is typically used to deserialze Data to a UaGenericStructureValue or UaGenericUnionValue.
 */
class UABASE_EXPORT UaBinaryDecoder : public UaAbstractDecoder
{
    UA_DISABLE_COPY(UaBinaryDecoder);
public:
    UaBinaryDecoder();
    virtual ~UaBinaryDecoder();

    UaStatus create(const UaByteString &bsValue);
    UaStatus create(const OpcUa_ByteString &bsValue);
    UaStatus create(const UaByteString &bsValue, const UaStringArray &namespaceTable);
    UaStatus create(const OpcUa_ByteString &bsValue, const UaStringArray &namespaceTable);
    void clear();

    OpcUa_StatusCode getPosition(OpcUa_UInt32& postion);
    OpcUa_StatusCode setPosition(OpcUa_UInt32 postion);

    virtual void pushNamespace(const UaString &sNamespace);
    virtual void popNamespace();

    virtual OpcUa_StatusCode readBoolean(const UaString &sFieldName, OpcUa_Boolean &rValue);
    virtual OpcUa_StatusCode readByteString(const UaString &sFieldName, UaByteString &rValue);
    virtual OpcUa_StatusCode readDataValue(const UaString &sFieldName, UaDataValue &rValue);
    virtual OpcUa_StatusCode readDateTime(const UaString &sFieldName, UaDateTime &rValue);
    virtual OpcUa_StatusCode readDiagnosticInfo(const UaString &sFieldName, UaDiagnosticInfo &rValue);
    virtual OpcUa_StatusCode readExpandedNodeId(const UaString &sFieldName, UaExpandedNodeId &rValue);
    virtual OpcUa_StatusCode readGuid(const UaString &sFieldName, UaGuid &rValue);
    virtual OpcUa_StatusCode readLocalizedText(const UaString &sFieldName, UaLocalizedText &rValue);
    virtual OpcUa_StatusCode readNodeId(const UaString &sFieldName, UaNodeId &rValue);
    virtual OpcUa_StatusCode readDouble(const UaString &sFieldName, OpcUa_Double &rValue);
    virtual OpcUa_StatusCode readFloat(const UaString &sFieldName, OpcUa_Float &rValue);
    virtual OpcUa_StatusCode readInt16(const UaString &sFieldName, OpcUa_Int16 &rValue);
    virtual OpcUa_StatusCode readInt32(const UaString &sFieldName, OpcUa_Int32 &rValue);
    virtual OpcUa_StatusCode readInt64(const UaString &sFieldName, OpcUa_Int64 &rValue);
    virtual OpcUa_StatusCode readSByte(const UaString &sFieldName, OpcUa_SByte &rValue);
    virtual OpcUa_StatusCode readByte(const UaString &sFieldName, OpcUa_Byte &rValue);
    virtual OpcUa_StatusCode readUInt16(const UaString &sFieldName, OpcUa_UInt16 &rValue);
    virtual OpcUa_StatusCode readUInt32(const UaString &sFieldName, OpcUa_UInt32 &rValue);
    virtual OpcUa_StatusCode readUInt64(const UaString &sFieldName, OpcUa_UInt64 &rValue);
    virtual OpcUa_StatusCode readQualifiedName(const UaString &sFieldName, UaQualifiedName &rValue);
    virtual OpcUa_StatusCode readStatusCode(const UaString &sFieldName, UaStatusCode &rValue);
    virtual OpcUa_StatusCode readString(const UaString &sFieldName, UaString &rValue);
    virtual OpcUa_StatusCode readVariant(const UaString &sFieldName, UaVariant &rValue);
    virtual OpcUa_StatusCode readExtensionObject(const UaString &sFieldName, UaExtensionObject &rValue);
    virtual OpcUa_StatusCode readGenericValue(const UaString &sFieldName, UaGenericStructureValue &rValue);
    virtual OpcUa_StatusCode readGenericUnion(const UaString &sFieldName, UaGenericUnionValue &rValue);
    virtual OpcUa_StatusCode readGenericOptionSet(const UaString &sFieldName, UaGenericOptionSetValue &rValue);
    virtual OpcUa_StatusCode readXmlElement(const UaString &sFieldName, UaByteString &rValue);

    virtual OpcUa_StatusCode readBooleanArray(const UaString &sFieldName, UaBoolArray &rValue);
    virtual OpcUa_StatusCode readByteStringArray(const UaString &sFieldName, UaByteStringArray &rValue);
    virtual OpcUa_StatusCode readDataValueArray(const UaString &sFieldName, UaDataValues &rValue);
    virtual OpcUa_StatusCode readDateTimeArray(const UaString &sFieldName, UaDateTimeArray &rValue);
    virtual OpcUa_StatusCode readDiagnosticInfoArray(const UaString &sFieldName, UaDiagnosticInfos &rValue);
    virtual OpcUa_StatusCode readExpandedNodeIdArray(const UaString &sFieldName, UaExpandedNodeIdArray &rValue);
    virtual OpcUa_StatusCode readGuidArray(const UaString &sFieldName, UaGuidArray &rValue);
    virtual OpcUa_StatusCode readLocalizedTextArray(const UaString &sFieldName, UaLocalizedTextArray &rValue);
    virtual OpcUa_StatusCode readNodeIdArray(const UaString &sFieldName, UaNodeIdArray &rValue);
    virtual OpcUa_StatusCode readDoubleArray(const UaString &sFieldName, UaDoubleArray &rValue);
    virtual OpcUa_StatusCode readFloatArray(const UaString &sFieldName, UaFloatArray &rValue);
    virtual OpcUa_StatusCode readInt16Array(const UaString &sFieldName, UaInt16Array &rValue);
    virtual OpcUa_StatusCode readInt32Array(const UaString &sFieldName, UaInt32Array &rValue);
    virtual OpcUa_StatusCode readInt64Array(const UaString &sFieldName, UaInt64Array &rValue);
    virtual OpcUa_StatusCode readSByteArray(const UaString &sFieldName, UaSByteArray &rValue);
    virtual OpcUa_StatusCode readByteArray(const UaString &sFieldName, UaByteArray &rValue);
    virtual OpcUa_StatusCode readUInt16Array(const UaString &sFieldName, UaUInt16Array &rValue);
    virtual OpcUa_StatusCode readUInt32Array(const UaString &sFieldName, UaUInt32Array &rValue);
    virtual OpcUa_StatusCode readUInt64Array(const UaString &sFieldName, UaUInt64Array &rValue);
    virtual OpcUa_StatusCode readQualifiedNameArray(const UaString &sFieldName, UaQualifiedNameArray &rValue);
    virtual OpcUa_StatusCode readStatusCodeArray(const UaString &sFieldName, UaStatusCodeArray &rValue);
    virtual OpcUa_StatusCode readStringArray(const UaString &sFieldName, UaStringArray &rValue);
    virtual OpcUa_StatusCode readVariantArray(const UaString &sFieldName, UaVariantArray &rValue);
    virtual OpcUa_StatusCode readExtensionObjectArray(const UaString &sFieldName, UaExtensionObjectArray &rValue);
    virtual OpcUa_StatusCode readGenericValueArray(const UaString &sFieldName, std::vector<UaGenericStructureValue> &rValue, UaStructureDefinition structureDefinition);
    virtual OpcUa_StatusCode readGenericValueArray(const UaString &sFieldName, UaGenericStructureArray &rValue);
    virtual OpcUa_StatusCode readGenericUnionArray(const UaString &sFieldName, UaGenericUnionArray &rValue);
    virtual OpcUa_StatusCode readGenericOptionSetArray(const UaString &sFieldName, UaGenericOptionSetArray &rValue);
    virtual OpcUa_StatusCode readXmlElementArray(const UaString &sFieldName, UaByteStringArray &rValue);

    virtual UaEncoderType decoderType() const;

private:
    struct _OpcUa_InputStream *m_pStream;
    struct _OpcUa_Decoder *m_pDecoder;
    OpcUa_Handle m_hDecodeContext;
    OpcUa_MessageContext m_cContext;
    bool m_bFreeNamespaceTable;
};

#endif // UABINARYDECODER_H
