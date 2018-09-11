/******************************************************************************
** uaunistring.h
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
** Implementation for Unicode handling.
**
******************************************************************************/
#ifndef __UAUNISTRING_H__
#define __UAUNISTRING_H__

/* check if UA types are included correctly */
#ifndef _OpcUa_P_Types_H_
    #ifdef _UA_WIN32
        #pragma message("ATTENTION: Please include <opcua_proxystub.h> before including <UaUniString.h>")
    #else
        #warning "ATTENTION: Please include <opcua_proxystub.h> before including <UaUniString.h>"
    #endif
#endif

#include "uaplatformdefs.h"
#include "uabytearray.h"

class UaUniStringList;

class UABASE_EXPORT UaUniStringPrivate
{
    UA_DISABLE_COPY(UaUniStringPrivate);
public:
    UaUniStringPrivate();
    UaUniStringPrivate(bool bStatic);
    UaUniStringPrivate(const UaUShort *other);
    ~UaUniStringPrivate();

    void attach(UaUShort *other, int len);

    bool operator==(const UaUniStringPrivate &other) const;
    bool operator!=(const UaUniStringPrivate &other) const;

    int addRef();
    int release();
    int length() const;
    int size() const;

private:
    int m_iRefCnt;
    UaUShort *m_pStrContent;    // string represented as a UTF-16 encoded string, always null terminated
    int m_iLength;              // number of characters
    friend class UaUniString;
};

/** OPC UA string handling class.
* This class encapsulates an UTF16 encoded string
*/
class UABASE_EXPORT UaUniString
{
    UA_DECLARE_PRIVATE(UaUniString)
public:
    UaUniString();
    UaUniString(const UaByteArray &other);
    UaUniString(const UaUniString &other);
    UaUniString(const UaUShort *other);
    UaUniString(const char *other);
    ~UaUniString();

    UaUniString& operator=(const UaUniString &other);
    UaUniString& attach(UaUShort *other, int len);

    int length() const;
    int size() const;
    bool isEmpty() const;
    bool isNull() const;
    void clear();

    UaUniString left(int len) const;
    UaUniString mid(int pos, int len = -1) const;
    UaUniString right(int len) const;

    UaUniString arg(unsigned int num, int fieldWidth = 0, int base = 10);
    UaUniString arg(int num, int fieldWidth = 0, int base = 10);
    UaUniString arg(double num, int fieldWidth = 0, char format = 'g', int precision = -1);
    UaUniString arg(const UaUniString &text);

    UaUShort at(int pos) const;
    bool startsWith(const UaUniString &strToFind) const;
    bool endsWith(const UaUniString &strToFind) const;

    UaUniString& replace(const UaUniString &before, const UaUniString &after);
    UaUniString& replace(const UaUShort &before, const UaUShort &after);

    UaUniString& replace(int position, int n, const UaUniString &after);
    UaUniString& replace(int position, const UaUShort &after);

    UaUniStringList split(const UaUniString &separator) const ;

    UaUniString& append(const UaUniString &str);
    UaUniString& append(const UaUShort ch);

    UaUniString& prepend(const UaUniString &str);
    UaUniString& prepend(const UaUShort ch);

    UaUniString toUpper() const;
    UaUniString toLower() const;

    UaUniString trimmed() const;

    int indexOf(const UaUniString &strToFind, int from = 0) const;
    int indexOf(const UaUShort charToFind, int from = 0) const;
    int lastIndexOf(const UaUniString &strToFind, int from = -1) const;
    int lastIndexOf(const UaUShort charToFind, int from = -1) const;

    void chop(int n);

    bool operator==(const UaUniString &other) const;
    bool operator!=(const UaUniString &other) const;

    bool operator<(const UaUniString &other) const;
    bool operator>(const UaUniString &other) const;

    UaUniString& operator+=(const UaUniString &other);
    UaUniString operator+(const UaUniString &other) const;

    UaUShort operator[](int index) const;
    UaUShort& operator[](int index);

    /* Extractor functions */
    const UaUShort* toUtf16() const;
    UaByteArray toLocal8Bit() const;

#if defined(_UA_WIN32) && UASDK_WITH_COM_UTILITIES
    BSTR toBSTR() const;
    wchar_t* toCOMWChar() const;
#endif

    /* Comparison functions needed for alphabetical sorting */
    bool isBiggerThan(const UaUniString &other, bool bCaseSensitive) const;
    bool isSmallerThan(const UaUniString &other, bool bCaseSensitive) const;

private:
    friend class UaUniStringList;
};

#endif // #ifndef __UAUNISTRING_H__
