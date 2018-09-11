/******************************************************************************
** uaeventfilterresult.h
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
** Portable UaEventFilterResult class.
**
******************************************************************************/
#ifndef UAEVENTFILTERRESULT_H
#define UAEVENTFILTERRESULT_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uacontentfilterresult.h"
#include "statuscode.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaEventFilterResultPrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_EventFilterResult.
 *
 *  This class encapsulates the native OpcUa_EventFilterResult structure
 *  and handles memory allocation and cleanup for you.
 *  UaEventFilterResult uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared EventFilterResult it creates a copy for that (copy-on-write).
 *  So assigning another UaEventFilterResult or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 */
class UABASE_EXPORT UaEventFilterResult
{
    UA_DECLARE_PRIVATE(UaEventFilterResult)
public:
    UaEventFilterResult();
    UaEventFilterResult(const UaEventFilterResult &other);
    UaEventFilterResult(const OpcUa_EventFilterResult &other);
    UaEventFilterResult(
        const UaStatusCodeArray &selectClauseResults,
        const UaDiagnosticInfos &selectClauseDiagnosticInfos,
        const UaContentFilterResult& whereClauseResult
        );
    UaEventFilterResult(const UaExtensionObject &extensionObject);
    UaEventFilterResult(const OpcUa_ExtensionObject &extensionObject);
    UaEventFilterResult(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaEventFilterResult(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaEventFilterResult();

    void clear();

    bool operator==(const UaEventFilterResult &other) const;
    bool operator!=(const UaEventFilterResult &other) const;

    UaEventFilterResult& operator=(const UaEventFilterResult &other);

    OpcUa_EventFilterResult* copy() const;
    void copyTo(OpcUa_EventFilterResult *pDst) const;

    static OpcUa_EventFilterResult* clone(const OpcUa_EventFilterResult& source);
    static void cloneTo(const OpcUa_EventFilterResult& source, OpcUa_EventFilterResult& copy);

    void attach(OpcUa_EventFilterResult *pValue);
    OpcUa_EventFilterResult* detach(OpcUa_EventFilterResult* pDst);

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

    OpcUa_StatusCode setEventFilterResult(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setEventFilterResult(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setEventFilterResult(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setEventFilterResult(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setEventFilterResult(
        const UaStatusCodeArray &selectClauseResults,
        const UaDiagnosticInfos &selectClauseDiagnosticInfos,
        const UaContentFilterResult& whereClauseResult
        );

    void getSelectClauseResults(UaStatusCodeArray& selectClauseResults) const;
    void getSelectClauseDiagnosticInfos(UaDiagnosticInfos& selectClauseDiagnosticInfos) const;
    UaContentFilterResult getWhereClauseResult() const;

    void setSelectClauseResults(const UaStatusCodeArray &selectClauseResults);
    void setSelectClauseDiagnosticInfos(const UaDiagnosticInfos &selectClauseDiagnosticInfos);
    void setWhereClauseResult(const UaContentFilterResult& whereClauseResult);
};

class UABASE_EXPORT UaEventFilterResults
{
public:
    UaEventFilterResults();
    UaEventFilterResults(const UaEventFilterResults &other);
    UaEventFilterResults(OpcUa_Int32 length, OpcUa_EventFilterResult* data);
    virtual ~UaEventFilterResults();

    UaEventFilterResults& operator=(const UaEventFilterResults &other);
    const OpcUa_EventFilterResult& operator[](OpcUa_UInt32 index) const;
    OpcUa_EventFilterResult& operator[](OpcUa_UInt32 index);

    bool operator==(const UaEventFilterResults &other) const;
    bool operator!=(const UaEventFilterResults &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_EventFilterResult* data);
    void attach(OpcUa_Int32 length, OpcUa_EventFilterResult* data);
    OpcUa_EventFilterResult* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_EventFilterResult* rawData() const {return m_data;}
    inline OpcUa_EventFilterResult* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setEventFilterResults(const UaVariant &variant);
    OpcUa_StatusCode setEventFilterResults(const OpcUa_Variant &variant);
    OpcUa_StatusCode setEventFilterResults(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setEventFilterResults(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setEventFilterResults(OpcUa_Int32 length, OpcUa_EventFilterResult* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_EventFilterResult* m_data;
};

#endif // UAEVENTFILTERRESULT_H

