/******************************************************************************
** uacontentfilterresult.h
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
** Portable UaContentFilterResult class.
**
******************************************************************************/
#ifndef UACONTENTFILTERRESULT_H
#define UACONTENTFILTERRESULT_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uacontentfilterelementresult.h"
#include "statuscode.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaContentFilterResultPrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_ContentFilterResult.
 *
 *  This class encapsulates the native OpcUa_ContentFilterResult structure
 *  and handles memory allocation and cleanup for you.
 *  UaContentFilterResult uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared ContentFilterResult it creates a copy for that (copy-on-write).
 *  So assigning another UaContentFilterResult or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 */
class UABASE_EXPORT UaContentFilterResult
{
    UA_DECLARE_PRIVATE(UaContentFilterResult)
public:
    UaContentFilterResult();
    UaContentFilterResult(const UaContentFilterResult &other);
    UaContentFilterResult(const OpcUa_ContentFilterResult &other);
    UaContentFilterResult(
        const UaContentFilterElementResults &elementResults,
        const UaDiagnosticInfos &elementDiagnosticInfos
        );
    UaContentFilterResult(const UaExtensionObject &extensionObject);
    UaContentFilterResult(const OpcUa_ExtensionObject &extensionObject);
    UaContentFilterResult(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaContentFilterResult(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaContentFilterResult();

    void clear();

    bool operator==(const UaContentFilterResult &other) const;
    bool operator!=(const UaContentFilterResult &other) const;

    UaContentFilterResult& operator=(const UaContentFilterResult &other);

    OpcUa_ContentFilterResult* copy() const;
    void copyTo(OpcUa_ContentFilterResult *pDst) const;

    static OpcUa_ContentFilterResult* clone(const OpcUa_ContentFilterResult& source);
    static void cloneTo(const OpcUa_ContentFilterResult& source, OpcUa_ContentFilterResult& copy);

    void attach(OpcUa_ContentFilterResult *pValue);
    OpcUa_ContentFilterResult* detach(OpcUa_ContentFilterResult* pDst);

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    void toExtensionObject(UaExtensionObject &extensionObject) const;
    void toExtensionObject(OpcUa_ExtensionObject &extensionObject) const;
    void toExtensionObject(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    void toExtensionObject(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    OpcUa_StatusCode setContentFilterResult(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setContentFilterResult(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setContentFilterResult(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setContentFilterResult(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setContentFilterResult(
        const UaContentFilterElementResults &elementResults,
        const UaDiagnosticInfos &elementDiagnosticInfos
        );

    void getElementResults(UaContentFilterElementResults& elementResults) const;
    void getElementDiagnosticInfos(UaDiagnosticInfos& elementDiagnosticInfos) const;

    void setElementResults(const UaContentFilterElementResults &elementResults);
    void setElementDiagnosticInfos(const UaDiagnosticInfos &elementDiagnosticInfos);
};

class UABASE_EXPORT UaContentFilterResults
{
public:
    UaContentFilterResults();
    UaContentFilterResults(const UaContentFilterResults &other);
    UaContentFilterResults(OpcUa_Int32 length, OpcUa_ContentFilterResult* data);
    virtual ~UaContentFilterResults();

    UaContentFilterResults& operator=(const UaContentFilterResults &other);
    const OpcUa_ContentFilterResult& operator[](OpcUa_UInt32 index) const;
    OpcUa_ContentFilterResult& operator[](OpcUa_UInt32 index);

    bool operator==(const UaContentFilterResults &other) const;
    bool operator!=(const UaContentFilterResults &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_ContentFilterResult* data);
    void attach(OpcUa_Int32 length, OpcUa_ContentFilterResult* data);
    OpcUa_ContentFilterResult* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_ContentFilterResult* rawData() const {return m_data;}
    inline OpcUa_ContentFilterResult* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setContentFilterResults(const UaVariant &variant);
    OpcUa_StatusCode setContentFilterResults(const OpcUa_Variant &variant);
    OpcUa_StatusCode setContentFilterResults(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setContentFilterResults(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setContentFilterResults(OpcUa_Int32 length, OpcUa_ContentFilterResult* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_ContentFilterResult* m_data;
};

#endif // UACONTENTFILTERRESULT_H

