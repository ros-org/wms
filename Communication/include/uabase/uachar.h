/******************************************************************************
** uachar.h
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
** OPC UA character class for UTF-8 handling.
**
******************************************************************************/
#ifndef __UABYTECHAR_H__
#define __UABYTECHAR_H__

#include "uaplatformdefs.h"

/** @ingroup CppBaseLibraryClass
 *  @brief Helper class for modifying UaChar elements.
 *  The UaChar class provides a 16-bit Unicode character.
 *  It is lightweight, so it can be used everywhere.
 */
class UABASE_EXPORT UaChar
{
public:
    UaChar();
    explicit UaChar(char c);
    explicit UaChar(UaUShort c);
    UaChar(const char *pUtf8);
    ~UaChar();

    UaUShort unicode() const;

    /** Get the actual size.
     *  @return the actual size.
     */
    int size() const { return m_iSize; };
    const char* data() const { return &m_szUtf8[0]; }

    bool operator==(const UaChar &other) const;
    bool operator!=(const UaChar &other) const;

private:
    char m_szUtf8[4];
    int m_iSize;
};

#endif /* __UABYTECHAR_H__ */

