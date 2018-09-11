/******************************************************************************
** uabinaryencoder.h
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
#ifndef UABINARYENCODER_H
#define UABINARYENCODER_H

#include "uabase.h"
#include "uaabstractencoder.h"
#include "opcua_messagecontext.h"

struct _OpcUa_Encoder;
struct _OpcUa_OutputStream;

/**
  * Class used to serialize Data to a UaByteString.
  */
class UABASE_EXPORT UaBinaryEncoder : public UaAbstractEncoder
{
    UA_DISABLE_COPY(UaBinaryEncoder);
public:
    UaBinaryEncoder();
    virtual ~UaBinaryEncoder();

    UaStatus create(OpcUa_UInt32 blockSize=0);
    UaStatus create(const UaStringArray &namespaceTable, OpcUa_UInt32 blockSize=0);
    void clear();

    UaStatus getBuffer(UaByteString& buffer);

    OpcUa_StatusCode getPosition(OpcUa_UInt32& postion);
    OpcUa_StatusCode setPosition(OpcUa_UInt32 postion);

    virtual void pushNamespace(const UaString &sNamespace);
    virtual void popNamespace();

    virtual OpcUa_StatusCode writeBoolean(const UaString &sFieldName, OpcUa_Boolean value);
    virtual OpcUa_StatusCode writeByteString(const UaString &sFieldName, const UaByteString &value);
    virtual OpcUa_StatusCode writeDataValue(const UaString &sFieldName, const UaDataValue &value);
    virtual OpcUa_StatusCode writeDateTime(const UaString &sFieldName, const UaDateTime &value);
    virtual OpcUa_StatusCode writeDiagnosticInfo(const UaString &sFieldName, const UaDiagnosticInfo &value);
    virtual OpcUa_StatusCode writeExpandedNodeId(const UaString &sFieldName, const UaExpandedNodeId &value);
    virtual OpcUa_StatusCode writeGuid(const UaString &sFieldName, const UaGuid &value);
    virtual OpcUa_StatusCode writeLocalizedText(const UaString &sFieldName, const UaLocalizedText &value);
    virtual OpcUa_StatusCode writeNodeId(const UaString &sFieldName, const UaNodeId &value);
    virtual OpcUa_StatusCode writeDouble(const UaString &sFieldName, OpcUa_Double value);
    virtual OpcUa_StatusCode writeFloat(const UaString &sFieldName, OpcUa_Float value);
    virtual OpcUa_StatusCode writeInt16(const UaString &sFieldName, OpcUa_Int16 value);
    virtual OpcUa_StatusCode writeInt32(const UaString &sFieldName, OpcUa_Int32 value);
    virtual OpcUa_StatusCode writeInt64(const UaString &sFieldName, OpcUa_Int64 value);
    virtual OpcUa_StatusCode writeSByte(const UaString &sFieldName, OpcUa_SByte value);
    virtual OpcUa_StatusCode writeByte(const UaString &sFieldName, OpcUa_Byte value);
    virtual OpcUa_StatusCode writeUInt16(const UaString &sFieldName, OpcUa_UInt16 value);
    virtual OpcUa_StatusCode writeUInt32(const UaString &sFieldName, OpcUa_UInt32 value);
    virtual OpcUa_StatusCode writeUInt64(const UaString &sFieldName, OpcUa_UInt64 valueu);
    virtual OpcUa_StatusCode writeQualifiedName(const UaString &sFieldName, const UaQualifiedName &value);
    virtual OpcUa_StatusCode writeStatusCode(const UaString &sFieldName, const UaStatusCode &value);
    virtual OpcUa_StatusCode writeString(const UaString &sFieldName, const UaString &value);
    virtual OpcUa_StatusCode writeVariant(const UaString &sFieldName, const UaVariant &value);
    virtual OpcUa_StatusCode writeExtensionObject(const UaString &sFieldName, const UaExtensionObject &value);
    virtual OpcUa_StatusCode writeGenericValue(const UaString &sFieldName, const UaGenericStructureValue &value);
    virtual OpcUa_StatusCode writeGenericUnion(const UaString &sFieldName, const UaGenericUnionValue &value);
    virtual OpcUa_StatusCode writeGenericOptionSet(const UaString &sFieldName, const UaGenericOptionSetValue &value);
    virtual OpcUa_StatusCode writeXmlElement(const UaString &sFieldName, const UaByteString &value);

    virtual OpcUa_StatusCode writeBooleanArray(const UaString &sFieldName, const UaBoolArray &value);
    virtual OpcUa_StatusCode writeByteStringArray(const UaString &sFieldName, const UaByteStringArray &value);
    virtual OpcUa_StatusCode writeDataValueArray(const UaString &sFieldName, const UaDataValues &value);
    virtual OpcUa_StatusCode writeDateTimeArray(const UaString &sFieldName, const UaDateTimeArray &value);
    virtual OpcUa_StatusCode writeDiagnosticInfoArray(const UaString &sFieldName, const UaDiagnosticInfos &value);
    virtual OpcUa_StatusCode writeExpandedNodeIdArray(const UaString &sFieldName, const UaExpandedNodeIdArray &value);
    virtual OpcUa_StatusCode writeGuidArray(const UaString &sFieldName, const UaGuidArray &value);
    virtual OpcUa_StatusCode writeLocalizedTextArray(const UaString &sFieldName, const UaLocalizedTextArray &value);
    virtual OpcUa_StatusCode writeNodeIdArray(const UaString &sFieldName, const UaNodeIdArray &value);
    virtual OpcUa_StatusCode writeDoubleArray(const UaString &sFieldName, const UaDoubleArray &value);
    virtual OpcUa_StatusCode writeFloatArray(const UaString &sFieldName, const UaFloatArray &value);
    virtual OpcUa_StatusCode writeInt16Array(const UaString &sFieldName, const UaInt16Array &value);
    virtual OpcUa_StatusCode writeInt32Array(const UaString &sFieldName, const UaInt32Array &value);
    virtual OpcUa_StatusCode writeInt64Array(const UaString &sFieldName, const UaInt64Array &value);
    virtual OpcUa_StatusCode writeSByteArray(const UaString &sFieldName, const UaSByteArray &value);
    virtual OpcUa_StatusCode writeByteArray(const UaString &sFieldName, const UaByteArray &value);
    virtual OpcUa_StatusCode writeUInt16Array(const UaString &sFieldName, const UaUInt16Array &value);
    virtual OpcUa_StatusCode writeUInt32Array(const UaString &sFieldName, const UaUInt32Array &value);
    virtual OpcUa_StatusCode writeUInt64Array(const UaString &sFieldName, const UaUInt64Array &value);
    virtual OpcUa_StatusCode writeQualifiedNameArray(const UaString &sFieldName, const UaQualifiedNameArray &value);
    virtual OpcUa_StatusCode writeStatusCodeArray(const UaString &sFieldName, const UaStatusCodeArray &value);
    virtual OpcUa_StatusCode writeStringArray(const UaString &sFieldName, const UaStringArray &value);
    virtual OpcUa_StatusCode writeVariantArray(const UaString &sFieldName, const UaVariantArray &value);
    virtual OpcUa_StatusCode writeExtensionObjectArray(const UaString &sFieldName, const UaExtensionObjectArray &value);
    virtual OpcUa_StatusCode writeGenericValueArray(const UaString &sFieldName, const std::vector<UaGenericStructureValue> &value);
    virtual OpcUa_StatusCode writeGenericValueArray(const UaString &sFieldName, const UaGenericStructureArray &value);
    virtual OpcUa_StatusCode writeGenericUnionArray(const UaString &sFieldName, const UaGenericUnionArray &value);
    virtual OpcUa_StatusCode writeGenericOptionSetArray(const UaString &sFieldName, const UaGenericOptionSetArray &value);
    virtual OpcUa_StatusCode writeXmlElementArray(const UaString &sFieldName, const UaByteStringArray &value);

    virtual UaEncoderType encoderType() const;

private:
    OpcUa_StatusCode addBuffer();

private:
    struct _OpcUa_Encoder *m_pEncoder;
    struct _OpcUa_OutputStream *m_pStream;
    OpcUa_Handle m_hEncodeContext;
    OpcUa_MessageContext m_cContext;
    bool m_bFreeNamespaceTable;
};
#endif // UABINARYENCODER_H
