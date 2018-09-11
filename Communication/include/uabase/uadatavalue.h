/******************************************************************************
** uadatavalue.h
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
** Portable Ua DataValue class.
**
******************************************************************************/
#ifndef UADATAVALUE_H
#define UADATAVALUE_H

#include "opcua_proxystub.h"
#include "uavariant.h"

class UABASE_EXPORT UaDataValuePrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_DataValue.
 *
 *  This class encapsulates the native OpcUa_DataValue structure
 *  and handles memory allocation and cleanup for you.
 *  UaDataValue uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared DataValue it creates a copy for that (copy-on-write).
 *  So assigning another UaDataValue or passing it as parameter needs constant time is nearly as fast as assigning a pointer.
 */
class UABASE_EXPORT UaDataValue
{
    UA_DECLARE_PRIVATE(UaDataValue)
public:
    UaDataValue();
    UaDataValue(const UaDataValue &other);
    UaDataValue(const OpcUa_DataValue &other);
    UaDataValue(const UaVariant& value, OpcUa_StatusCode statusCode, const UaDateTime& sourceTimestamp, const UaDateTime& serverTimestamp);
    ~UaDataValue();
    void clear();

    UaDataValue& operator=(const UaDataValue &other);

    bool operator==(const UaDataValue &other) const;
    bool operator!=(const UaDataValue &other) const;

    operator const OpcUa_DataValue*() const;

    OpcUa_DataValue* copy() const;
    void copyTo(OpcUa_DataValue *pDst) const;

    static OpcUa_DataValue* clone(const OpcUa_DataValue& source);
    static void cloneTo(const OpcUa_DataValue& source, OpcUa_DataValue& copy);

    void attach(const OpcUa_DataValue *pValue);
    OpcUa_DataValue* detach(OpcUa_DataValue* pDst);

    void setDataValue(UaVariant& value, OpcUa_Boolean detachValue, OpcUa_StatusCode statusCode, OpcUa_DateTime sourceTimestamp, OpcUa_DateTime serverTimestamp);
    void setDataValue(OpcUa_Variant& value, OpcUa_Boolean detachValue, OpcUa_StatusCode statusCode, OpcUa_DateTime sourceTimestamp, OpcUa_DateTime serverTimestamp);

    void setValue( UaVariant& value, OpcUa_Boolean detachValue, OpcUa_Boolean updateTimeStamps = OpcUa_False );
    void setValue( OpcUa_Variant& value, OpcUa_Boolean detachValue, OpcUa_Boolean updateTimeStamps = OpcUa_False );

    void setStatusCode( OpcUa_StatusCode statusCode );
    void setSourceTimestamp( OpcUa_DateTime sourceTimestamp );
    void setServerTimestamp( OpcUa_DateTime serverTimestamp );
    void setSourcePicoseconds( OpcUa_UInt16 sourcePicoseconds );
    void setServerPicoseconds( OpcUa_UInt16 serverPicoseconds );

    const OpcUa_Variant* value() const;
    OpcUa_StatusCode     statusCode() const;
    OpcUa_DateTime       sourceTimestamp() const;
    OpcUa_DateTime       serverTimestamp() const;
    OpcUa_UInt16         sourcePicoseconds() const;
    OpcUa_UInt16         serverPicoseconds() const;

    OpcUa_Boolean  isSourceTimestampSet() const;
    OpcUa_Boolean  isServerTimestampSet() const;

    static bool compare(const OpcUa_DataValue&, const OpcUa_DataValue&, OpcUa_Boolean bCompareTimestamps);
    static OpcUa_StatusCode checkDeadbandExceeded(const UaDataValue &lastDataValue, const UaDataValue &newDataValue, OpcUa_Double absoluteDeadband, OpcUa_Boolean &bDeadbandExceeded);

private:
    friend UABASE_EXPORT UaDataStream &operator<<(UaDataStream &, const UaDataValue &);
    friend UABASE_EXPORT UaDataStream &operator>>(UaDataStream &, UaDataValue &);
};

// define UaDataStream operators for UaDataValue
UABASE_EXPORT UaDataStream &operator<<(UaDataStream &, const UaDataValue &);
UABASE_EXPORT UaDataStream &operator>>(UaDataStream &, UaDataValue &);

/** Object array of UaDataValue object. */
typedef UaObjectArray<UaDataValue>      UaDataValueArray;

#endif // UADATAVALUE_H
