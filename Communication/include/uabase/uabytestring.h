/******************************************************************************
** uabytestring.h
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
** Portable Ua ByteString class.
**
******************************************************************************/
#ifndef UABYTESTRING_H
#define UABYTESTRING_H

#include "uaplatformdefs.h"
#include "opcua_proxystub.h"
#include "uadatastream.h"

class UABASE_EXPORT UaVariant;
class UABASE_EXPORT UaDataValue;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_ByteString.
 *  Derived from OpcUa_ByteString.
 */
class UABASE_EXPORT UaByteString: private OpcUa_ByteString
{
public:
    UaByteString();
    UaByteString(const UaByteString &other);
    UaByteString(const OpcUa_ByteString &other);
    UaByteString(OpcUa_Int32 iLength, OpcUa_Byte* pData);
    UaByteString(const UaByteArray &other);
    ~UaByteString();

    void clear();
    void setByteString(OpcUa_Int32 iLength, OpcUa_Byte* pData);
    void resize(OpcUa_Int32 newLength);

    UaByteString& operator=(const UaByteString &other);

    void operator<<(const UaByteString&);
    bool operator==(const UaByteString&) const;
    bool operator!=(const UaByteString&) const;
    bool operator<(const UaByteString&) const;
    bool operator>(const UaByteString&) const;
    static bool compare(const OpcUa_ByteString&, const OpcUa_ByteString&);
    operator const OpcUa_ByteString*() const;

    OpcUa_ByteString* copy() const;
    void copyTo(OpcUa_ByteString *pDst) const;

    static OpcUa_ByteString* clone(const OpcUa_ByteString& source);
    static void cloneTo(const OpcUa_ByteString& source, OpcUa_ByteString& copy);

    UaString toHex(bool bSeparateWithSpace = false) const;
    static UaByteString fromHex(const UaString &src);

    void detach();
    void attach(const OpcUa_ByteString *pSrc);

    UaByteString& append(const UaByteString &other);

    /** Get the length of the var.
     *  @return the length of the var.
     */
    inline OpcUa_Int32        length() const { return this->Length; };

    /** Get the data of the actual variable.
     *  @return the data of the actual variable.
     */
    inline const OpcUa_Byte*  data() const { return this->Data; };

    static char* base64encode(const OpcUa_ByteString rawData);
    static OpcUa_StatusCode base64decode(const char *pBase64, UaByteString& rawData, int size = -1);

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
static int base64format(char **szInput);
private:
    static char s_base64[65];
    static OpcUa_Byte s_decoding[256];

    friend UABASE_EXPORT UaDataStream &operator<<(UaDataStream &, const UaByteString &);
    friend UABASE_EXPORT UaDataStream &operator>>(UaDataStream &, UaByteString &);
};

// define UaDataStream operators for UaByteString.
UABASE_EXPORT UaDataStream &operator<<(UaDataStream &, const UaByteString &);
UABASE_EXPORT UaDataStream &operator>>(UaDataStream &, UaByteString &);

#endif // UABYTESTRING_H
