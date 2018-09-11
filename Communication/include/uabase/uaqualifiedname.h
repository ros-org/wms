/******************************************************************************
** uaqualifiedname.h
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
#ifndef UAQUALIFIEDNAME_H
#define UAQUALIFIEDNAME_H

#include "uabase.h"
#include "uastring.h"

class UABASE_EXPORT UaVariant;
class UABASE_EXPORT UaDataValue;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_QualifiedName.
 *  Qualified names are two-part names: namespace index (UInt16) and name (String).
 *  The name part of QualifiedNames is restricted to 512 characters.
 *  Derived from OpcUa_QualifiedName.
 */
class UABASE_EXPORT UaQualifiedName : private OpcUa_QualifiedName
{
public:
    UaQualifiedName();
    UaQualifiedName(const UaQualifiedName &other);
    UaQualifiedName(const OpcUa_QualifiedName &other);
    UaQualifiedName(const UaString& sName, OpcUa_UInt16 nameSpaceIdx);
    ~UaQualifiedName();
    void clear();
    void detach();
    UaQualifiedName& attach(const OpcUa_QualifiedName* pSrc);

    OpcUa_Boolean isNull() const;

    UaQualifiedName& operator=(const UaQualifiedName &other);
    UaQualifiedName& operator=(const OpcUa_QualifiedName &other);

    bool operator==(const UaQualifiedName &other) const;
    bool operator!=(const UaQualifiedName &other) const;
    static bool compare(const OpcUa_QualifiedName&, const OpcUa_QualifiedName&);

    bool operator<(const UaQualifiedName &other) const;

    operator const OpcUa_QualifiedName*() const;

    OpcUa_QualifiedName* copy() const;
    void copyTo(OpcUa_QualifiedName *pDst) const;

    static OpcUa_QualifiedName* clone(const OpcUa_QualifiedName& source);
    static void cloneTo(const OpcUa_QualifiedName& source, OpcUa_QualifiedName& copy);

    UaString toString() const;
    UaString toFullString() const;

    void setQualifiedName(const UaString& sName, OpcUa_UInt16 nameSpaceIdx);
    void setNamespaceIndex(OpcUa_UInt16 namespaceIndex);

    inline OpcUa_UInt16 namespaceIndex() const { return this->NamespaceIndex; };
    inline const OpcUa_String* name() const { return &this->Name; };

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
};


#endif // UAQUALIFIEDNAME_H
