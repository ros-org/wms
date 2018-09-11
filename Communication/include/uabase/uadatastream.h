/******************************************************************************
** uadatastream.h
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
#ifndef UADATASTREAM_H
#define UADATASTREAM_H

#include "uaplatformdefs.h"
#include "uabase.h"

class UABASE_EXPORT UaIODevice;

// Define system byte order
// ToDo: read that information from platform layer??
#ifndef DATASTREAM_LITTLE_ENDIAN
# define DATASTREAM_LITTLE_ENDIAN 1234
#endif
#ifndef DATASTREAM_BIG_ENDIAN
# define DATASTREAM_BIG_ENDIAN    4321
#endif

#ifndef DATASTREAM_BYTE_ORDER
# define DATASTREAM_BYTE_ORDER DATASTREAM_BIG_ENDIAN
#endif

#define Swap_Bytes_2(x) (((x) & 0x00ff) << 8) | \
                        (((x) & 0xff00) >> 8)
#define Swap_Bytes_4(x) (((x) & 0x000000ff) << 24) | \
                        (((x) & 0x0000ff00) <<  8) | \
                        (((x) & 0x00ff0000) >>  8) | \
                        (((x) & 0xff000000) >> 24)
#ifndef _UA_WIN32
#define Swap_Bytes_8(x) (((x) & 0x00000000000000ffll) << 56) | \
                        (((x) & 0x000000000000ff00ll) << 40) | \
                        (((x) & 0x0000000000ff0000ll) << 24) | \
                        (((x) & 0x00000000ff000000ll) <<  8) | \
                        (((x) & 0x000000ff00000000ll) >>  8) | \
                        (((x) & 0x0000ff0000000000ll) >> 24) | \
                        (((x) & 0x00ff000000000000ll) >> 40) | \
                        (((x) & 0xff00000000000000ll) >> 56)
#else
#define Swap_Bytes_8(x) (((x) & 0x00000000000000ffi64) << 56) | \
                        (((x) & 0x000000000000ff00i64) << 40) | \
                        (((x) & 0x0000000000ff0000i64) << 24) | \
                        (((x) & 0x00000000ff000000i64) <<  8) | \
                        (((x) & 0x000000ff00000000i64) >>  8) | \
                        (((x) & 0x0000ff0000000000i64) >> 24) | \
                        (((x) & 0x00ff000000000000i64) >> 40) | \
                        (((x) & 0xff00000000000000i64) >> 56)
#endif

class UABASE_EXPORT UaDataStream
{
    UA_DISABLE_COPY(UaDataStream);
public:
    enum ByteOrder
    {
        BigEndian,
        LittleEndian
    };

    UaDataStream();
    UaDataStream(UaIODevice* pIODevice);
    virtual ~UaDataStream();

    ByteOrder byteOrder() const;
    void setByteOrder(ByteOrder order);

    UaIODevice* device() const;
    void setDevice(UaIODevice* pDevice);

    // BuiltIn Types
    // SByte
    UaDataStream & operator<<(OpcUa_SByte val);
    UaDataStream & operator>>(OpcUa_SByte &val);
    // Byte or Bool
    UaDataStream & operator<<(OpcUa_Byte val);
    UaDataStream & operator>>(OpcUa_Byte &val);
    // Int16
    UaDataStream & operator<<(OpcUa_Int16 val);
    UaDataStream & operator>>(OpcUa_Int16 &val);
    // UInt16
    UaDataStream & operator<<(OpcUa_UInt16 val);
    UaDataStream & operator>>(OpcUa_UInt16 &val);
    // Int32
    UaDataStream & operator<<(OpcUa_Int32 val);
    UaDataStream & operator>>(OpcUa_Int32 &val);
    // UInt32 or StatusCode
    UaDataStream & operator<<(OpcUa_UInt32 val);
    UaDataStream & operator>>(OpcUa_UInt32 &val);
    // Int64
    UaDataStream & operator<<(OpcUa_Int64 val);
    UaDataStream & operator>>(OpcUa_Int64 &val);
    // UInt64
    UaDataStream & operator<<(OpcUa_UInt64 val);
    UaDataStream & operator>>(OpcUa_UInt64 &val);
    // Float
    UaDataStream & operator<<(OpcUa_Float val);
    UaDataStream & operator>>(OpcUa_Float &val);
    // Double
    UaDataStream & operator<<(OpcUa_Double val);
    UaDataStream & operator>>(OpcUa_Double &val);
    // String
    UaDataStream & operator<<(OpcUa_String val);
    UaDataStream & operator>>(OpcUa_String &val);
    // DateTime
    UaDataStream & operator<<(OpcUa_DateTime val);
    UaDataStream & operator>>(OpcUa_DateTime &val);
    // Guid
    UaDataStream & operator<<(OpcUa_Guid val);
    UaDataStream & operator>>(OpcUa_Guid &val);
    // ByteString or XmlElement
    UaDataStream & operator<<(OpcUa_ByteString val);
    UaDataStream & operator>>(OpcUa_ByteString &val);
    // NodeId
    UaDataStream & operator<<(OpcUa_NodeId val);
    UaDataStream & operator>>(OpcUa_NodeId &val);
    // ExpandedNodeId
    UaDataStream & operator<<(OpcUa_ExpandedNodeId val);
    UaDataStream & operator>>(OpcUa_ExpandedNodeId &val);
    // QualifiedName
    UaDataStream & operator<<(OpcUa_QualifiedName val);
    UaDataStream & operator>>(OpcUa_QualifiedName &val);
    // LocalizedText
    UaDataStream & operator<<(OpcUa_LocalizedText val);
    UaDataStream & operator>>(OpcUa_LocalizedText &val);
    // ExtensionObject
    UaDataStream & operator<<(OpcUa_ExtensionObject val);
    UaDataStream & operator>>(OpcUa_ExtensionObject &val);
    // DataValue
    UaDataStream & operator<<(OpcUa_DataValue val);
    UaDataStream & operator>>(OpcUa_DataValue &val);
    // Variant
    UaDataStream & operator<<(OpcUa_Variant val);
    UaDataStream & operator>>(OpcUa_Variant &val);
    // DiagnosticInfo
    UaDataStream & operator<<(OpcUa_DiagnosticInfo val);
    UaDataStream & operator>>(OpcUa_DiagnosticInfo &val);

private:
    bool systemEndianessIsTargetEndianess();

private:
    ByteOrder   m_byteOrder;
    UaIODevice* m_pDevice;
};

#endif
