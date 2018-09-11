/******************************************************************************
** uaserverdiagnosticssummarydatatype.h
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
** Portable UaServerDiagnosticsSummaryDataType class.
**
******************************************************************************/
#ifndef UASERVERDIAGNOSTICSSUMMARYDATATYPE_H
#define UASERVERDIAGNOSTICSSUMMARYDATATYPE_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaServerDiagnosticsSummaryDataTypePrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_ServerDiagnosticsSummaryDataType.
 *
 *  This class encapsulates the native OpcUa_ServerDiagnosticsSummaryDataType structure
 *  and handles memory allocation and cleanup for you.
 *  UaServerDiagnosticsSummaryDataType uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared ServerDiagnosticsSummaryDataType it creates a copy for that (copy-on-write).
 *  So assigning another UaServerDiagnosticsSummaryDataType or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  Contains diagnostic summary information for the Server.
 */
class UABASE_EXPORT UaServerDiagnosticsSummaryDataType
{
    UA_DECLARE_PRIVATE(UaServerDiagnosticsSummaryDataType)
public:
    UaServerDiagnosticsSummaryDataType();
    UaServerDiagnosticsSummaryDataType(const UaServerDiagnosticsSummaryDataType &other);
    UaServerDiagnosticsSummaryDataType(const OpcUa_ServerDiagnosticsSummaryDataType &other);
    UaServerDiagnosticsSummaryDataType(
        OpcUa_UInt32 serverViewCount,
        OpcUa_UInt32 currentSessionCount,
        OpcUa_UInt32 cumulatedSessionCount,
        OpcUa_UInt32 securityRejectedSessionCount,
        OpcUa_UInt32 rejectedSessionCount,
        OpcUa_UInt32 sessionTimeoutCount,
        OpcUa_UInt32 sessionAbortCount,
        OpcUa_UInt32 currentSubscriptionCount,
        OpcUa_UInt32 cumulatedSubscriptionCount,
        OpcUa_UInt32 publishingIntervalCount,
        OpcUa_UInt32 securityRejectedRequestsCount,
        OpcUa_UInt32 rejectedRequestsCount
        );
    UaServerDiagnosticsSummaryDataType(const UaExtensionObject &extensionObject);
    UaServerDiagnosticsSummaryDataType(const OpcUa_ExtensionObject &extensionObject);
    UaServerDiagnosticsSummaryDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaServerDiagnosticsSummaryDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaServerDiagnosticsSummaryDataType();

    void clear();

    bool operator==(const UaServerDiagnosticsSummaryDataType &other) const;
    bool operator!=(const UaServerDiagnosticsSummaryDataType &other) const;

    UaServerDiagnosticsSummaryDataType& operator=(const UaServerDiagnosticsSummaryDataType &other);

    OpcUa_ServerDiagnosticsSummaryDataType* copy() const;
    void copyTo(OpcUa_ServerDiagnosticsSummaryDataType *pDst) const;

    static OpcUa_ServerDiagnosticsSummaryDataType* clone(const OpcUa_ServerDiagnosticsSummaryDataType& source);
    static void cloneTo(const OpcUa_ServerDiagnosticsSummaryDataType& source, OpcUa_ServerDiagnosticsSummaryDataType& copy);

    void attach(OpcUa_ServerDiagnosticsSummaryDataType *pValue);
    OpcUa_ServerDiagnosticsSummaryDataType* detach(OpcUa_ServerDiagnosticsSummaryDataType* pDst);

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

    OpcUa_StatusCode setServerDiagnosticsSummaryDataType(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setServerDiagnosticsSummaryDataType(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setServerDiagnosticsSummaryDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setServerDiagnosticsSummaryDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setServerDiagnosticsSummaryDataType(
        OpcUa_UInt32 serverViewCount,
        OpcUa_UInt32 currentSessionCount,
        OpcUa_UInt32 cumulatedSessionCount,
        OpcUa_UInt32 securityRejectedSessionCount,
        OpcUa_UInt32 rejectedSessionCount,
        OpcUa_UInt32 sessionTimeoutCount,
        OpcUa_UInt32 sessionAbortCount,
        OpcUa_UInt32 currentSubscriptionCount,
        OpcUa_UInt32 cumulatedSubscriptionCount,
        OpcUa_UInt32 publishingIntervalCount,
        OpcUa_UInt32 securityRejectedRequestsCount,
        OpcUa_UInt32 rejectedRequestsCount
        );

    OpcUa_UInt32 getServerViewCount() const;
    OpcUa_UInt32 getCurrentSessionCount() const;
    OpcUa_UInt32 getCumulatedSessionCount() const;
    OpcUa_UInt32 getSecurityRejectedSessionCount() const;
    OpcUa_UInt32 getRejectedSessionCount() const;
    OpcUa_UInt32 getSessionTimeoutCount() const;
    OpcUa_UInt32 getSessionAbortCount() const;
    OpcUa_UInt32 getCurrentSubscriptionCount() const;
    OpcUa_UInt32 getCumulatedSubscriptionCount() const;
    OpcUa_UInt32 getPublishingIntervalCount() const;
    OpcUa_UInt32 getSecurityRejectedRequestsCount() const;
    OpcUa_UInt32 getRejectedRequestsCount() const;

    void setServerViewCount(OpcUa_UInt32 serverViewCount);
    void setCurrentSessionCount(OpcUa_UInt32 currentSessionCount);
    void setCumulatedSessionCount(OpcUa_UInt32 cumulatedSessionCount);
    void setSecurityRejectedSessionCount(OpcUa_UInt32 securityRejectedSessionCount);
    void setRejectedSessionCount(OpcUa_UInt32 rejectedSessionCount);
    void setSessionTimeoutCount(OpcUa_UInt32 sessionTimeoutCount);
    void setSessionAbortCount(OpcUa_UInt32 sessionAbortCount);
    void setCurrentSubscriptionCount(OpcUa_UInt32 currentSubscriptionCount);
    void setCumulatedSubscriptionCount(OpcUa_UInt32 cumulatedSubscriptionCount);
    void setPublishingIntervalCount(OpcUa_UInt32 publishingIntervalCount);
    void setSecurityRejectedRequestsCount(OpcUa_UInt32 securityRejectedRequestsCount);
    void setRejectedRequestsCount(OpcUa_UInt32 rejectedRequestsCount);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_ServerDiagnosticsSummaryDataType.
 *
 *  This class encapsulates an array of the native OpcUa_ServerDiagnosticsSummaryDataType structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaServerDiagnosticsSummaryDataType for information about the encapsulated structure.
 */
class UABASE_EXPORT UaServerDiagnosticsSummaryDataTypes
{
public:
    UaServerDiagnosticsSummaryDataTypes();
    UaServerDiagnosticsSummaryDataTypes(const UaServerDiagnosticsSummaryDataTypes &other);
    UaServerDiagnosticsSummaryDataTypes(OpcUa_Int32 length, OpcUa_ServerDiagnosticsSummaryDataType* data);
    virtual ~UaServerDiagnosticsSummaryDataTypes();

    UaServerDiagnosticsSummaryDataTypes& operator=(const UaServerDiagnosticsSummaryDataTypes &other);
    const OpcUa_ServerDiagnosticsSummaryDataType& operator[](OpcUa_UInt32 index) const;
    OpcUa_ServerDiagnosticsSummaryDataType& operator[](OpcUa_UInt32 index);

    bool operator==(const UaServerDiagnosticsSummaryDataTypes &other) const;
    bool operator!=(const UaServerDiagnosticsSummaryDataTypes &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_ServerDiagnosticsSummaryDataType* data);
    void attach(OpcUa_Int32 length, OpcUa_ServerDiagnosticsSummaryDataType* data);
    OpcUa_ServerDiagnosticsSummaryDataType* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_ServerDiagnosticsSummaryDataType* rawData() const {return m_data;}
    inline OpcUa_ServerDiagnosticsSummaryDataType* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setServerDiagnosticsSummaryDataTypes(const UaVariant &variant);
    OpcUa_StatusCode setServerDiagnosticsSummaryDataTypes(const OpcUa_Variant &variant);
    OpcUa_StatusCode setServerDiagnosticsSummaryDataTypes(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setServerDiagnosticsSummaryDataTypes(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setServerDiagnosticsSummaryDataTypes(OpcUa_Int32 length, OpcUa_ServerDiagnosticsSummaryDataType* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_ServerDiagnosticsSummaryDataType* m_data;
};

#endif // UASERVERDIAGNOSTICSSUMMARYDATATYPE_H

