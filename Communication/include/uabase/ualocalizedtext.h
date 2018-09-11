/******************************************************************************
** ualocalizedtext.h
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
** Portable Ua LocalizedText class.
**
******************************************************************************/
#ifndef UALOCALIZEDTEXT_H
#define UALOCALIZEDTEXT_H

#include "opcua_proxystub.h"
#include "uastring.h"

class UABASE_EXPORT UaVariant;
class UABASE_EXPORT UaDataValue;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_LocalizedText.
 */
class UABASE_EXPORT UaLocalizedText : private OpcUa_LocalizedText
{
public:
    UaLocalizedText();
    UaLocalizedText(const UaLocalizedText &other);
    UaLocalizedText(const OpcUa_LocalizedText &other);
    UaLocalizedText(const UaString& Locale, const UaString& Text);
    ~UaLocalizedText();
    void clear();
    void detach();
    UaLocalizedText& attach(const OpcUa_LocalizedText* pSrc);

    OpcUa_Boolean isNull() const;

    UaLocalizedText& operator=(const UaLocalizedText &other);
    UaLocalizedText& operator=(const OpcUa_LocalizedText &other);

    bool operator==(const UaLocalizedText &other) const;
    bool operator!=(const UaLocalizedText &other) const;
    static bool compare(const OpcUa_LocalizedText&, const OpcUa_LocalizedText&);
    static void compareLocale(const OpcUa_LocalizedText& localizedText, const OpcUa_String& locale, OpcUa_Boolean& fullMatch, OpcUa_Boolean& languageMatch);

    operator const OpcUa_LocalizedText*() const;

    OpcUa_LocalizedText* copy() const;
    void copyTo(OpcUa_LocalizedText *pDst) const;

    static OpcUa_LocalizedText* clone(const OpcUa_LocalizedText& source);
    static void cloneTo(const OpcUa_LocalizedText& source, OpcUa_LocalizedText& copy);

    UaString toString() const;
    UaString toFullString() const;

    void setLocalizedText(const UaString& sLocale, const UaString& sText);
    void setLocalizedText(const UaString& sText);

    void setText(const UaString& sText);
    void setLocale(const UaString& sLocale);

    /** Get the locale string.
     *  @return the locale string.
     */
    inline const OpcUa_String* locale() const { return &this->Locale; };

    /** Get the text string.
     *  @return the text string.
     */
    inline const OpcUa_String* text() const { return &this->Text; };

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
};

#endif // UALOCALIZEDTEXT_H
