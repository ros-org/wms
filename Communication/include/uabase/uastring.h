/******************************************************************************
** uastring.h
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
** OPC UA string handling class.
**
******************************************************************************/
#ifndef __UASTRING_H__
#define __UASTRING_H__

/* check if UA types are included correctly */
#ifndef _OpcUa_P_Types_H_
    #ifdef _UA_WIN32
        #pragma message("ATTENTION: Please include <opcua_proxystub.h> before including <uastring.h>")
    #else
        #warning "ATTENTION: Please include <opcua_proxystub.h> before including <uastring.h>"
    #endif
#endif

#include "uaplatformdefs.h"
#include "uabytearray.h"
#include "uabytestring.h"
#include "uachar.h"
#include "uadatastream.h"

class UABASE_EXPORT UaStringPrivate;
class UABASE_EXPORT UaVariant;
class UABASE_EXPORT UaDataValue;


/** @ingroup CppBaseLibraryClass
 @brief Wrapper class for the UA stack structure OpcUa_String

 Helper class for handling the OPC UA built-in data type String. It provides conversion,
 comparison and string creation functions and handles memory allocation and clean-up.

 The OPC UA built-in data type String defines a Unicode character string that should exclude control characters that are not
 whitespaces. All String values are encoded as a sequence of UTF8 characters. Therefore the
 internal representation is using the wire format to avoid data copying.

 Since the internal representation of a String in the class UaString is UTF8 encoded, the class does not provide string manipulation
 functions. The class #UaUniString provides string manipulation functions. The necessary conversion to UTF-16 is provided by #toUtf16.
 The native string can be extracted as char* with #toUtf8.

 @code
 UaString myString("This is the string to process");

 UaUniString myTempString(myString.toUtf16());
 myTempString.replace("string", "text");

 myString = myTempString.toUtf16();

 printf("%s", myString.toUtf8());

 // Output is "This is the text to process"
 @endcode

 A string can be created with #arg, appended with #operator+ and #operator+= and created from different string formats and a #number.

 @code
 UaString myString;
 UaString sTemp("variable string");
 int iTemp = 5;

 // Create the string "5 times variable string" from variables
 myString = UaString::number(iTemp);
 myString += " times ";
 myString += sTemp;

 // The following option is more efficient
 myString = UaString("%1 times %2").arg(iTemp).arg(sTemp);
 @endcode

 UaString uses implicit sharing to avoid needless copying and to boost the performance.
 Only if you modify a shared string it creates a copy for that (copy-on-write).
 So assigning another UaString or passing it as parameter needs constant time is nearly as fast as assigning a pointer.
*/
class UABASE_EXPORT UaString
{
    UA_DECLARE_PRIVATE(UaString)
    bool operator>(const UaString&) const; // not implemented
public:
    UaString();
#ifdef _OpcUa_P_Types_H_
    UaString(const OpcUa_String *other);
    UaString(const OpcUa_String &other);
#endif
    UaString(const UaString &other);
    UaString(const UaByteString &other);
    UaString(const char *other);
    UaString(const UaUShort *other);
    ~UaString();

    UaString& operator=(const UaString &other);
    UaString& attach(char *other, int len);
#ifdef _OpcUa_P_Types_H_
    UaString& attach(const OpcUa_String* pSrc);
    OpcUa_String *detach(OpcUa_String *pDst);
#endif

    int size() const;
    int length() const;
    bool isEmpty() const;
    bool isNull() const;
    const UaChar at(int i) const;
    int find(UaChar cFind) const;
    int find(UaChar cFind, unsigned int iStart) const;

    static bool isLikePatternValid(const UaString &pattern);
    bool like(const UaString &pattern) const;

    bool operator==(const UaString &other) const;
    bool operator!=(const UaString &other) const;

    bool operator<(const UaString &other) const;

    UaString& operator+=(const UaString &other);
    UaString operator+(const UaString &other);

    UaString arg(const UaString &a, int fieldWidth = 0, const UaChar &fillChar = UaChar(' ')) const;
    UaString arg(int a, int fieldWidth = 0, int base = 10, const UaChar &fillChar = UaChar(' ')) const;
    UaString arg(unsigned int a, int fieldWidth = 0, int base = 10, const UaChar &fillChar = UaChar(' ')) const;
    UaString arg(double a, int fieldWidth = 0, char format = 'g', int precision = -1, const UaChar &fillChar = UaChar(' ')) const;

    static UaString number(int n, int base = 10);
    static UaString number(unsigned int n, int base = 10);

    /* Extractor functions */
#ifdef _OpcUa_P_Types_H_
    OpcUa_String* copy() const;
    void copyTo(OpcUa_String *pDst) const;

    static OpcUa_String* clone(const OpcUa_String& source);
    static void cloneTo(const OpcUa_String& source, OpcUa_String& copy);

    const OpcUa_String* toOpcUaString() const;
    operator const OpcUa_String*() const;
#endif
    const char* toUtf8() const;
    UaByteArray toUtf16() const;
    UaByteArray toLocal8Bit() const;

    static UaString fromLocal8Bit(const char *other);

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

private:
    friend UABASE_EXPORT UaDataStream &operator<<(UaDataStream &, const UaString &);
    friend UABASE_EXPORT UaDataStream &operator>>(UaDataStream &, UaString &);
};

/** define UaDataStream operators for UaString. */
UABASE_EXPORT UaDataStream &operator<<(UaDataStream &, const UaString &);
UABASE_EXPORT UaDataStream &operator>>(UaDataStream &, UaString &);

#endif // #ifndef __UASTRING_H__
