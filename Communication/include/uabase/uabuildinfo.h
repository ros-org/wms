/******************************************************************************
** uabuildinfo.h
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
** Portable UaBuildInfo class.
**
******************************************************************************/
#ifndef UABUILDINFO_H
#define UABUILDINFO_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uadatetime.h"
#include "uastring.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaBuildInfoPrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_BuildInfo.
 *
 *  This class encapsulates the native OpcUa_BuildInfo structure
 *  and handles memory allocation and cleanup for you.
 *  UaBuildInfo uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared BuildInfo it creates a copy for that (copy-on-write).
 *  So assigning another UaBuildInfo or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  Contains elements that describe the build information of the Server.
 */
class UABASE_EXPORT UaBuildInfo
{
    UA_DECLARE_PRIVATE(UaBuildInfo)
public:
    UaBuildInfo();
    UaBuildInfo(const UaBuildInfo &other);
    UaBuildInfo(const OpcUa_BuildInfo &other);
    UaBuildInfo(
        const UaString& productUri,
        const UaString& manufacturerName,
        const UaString& productName,
        const UaString& softwareVersion,
        const UaString& buildNumber,
        const UaDateTime& buildDate
        );
    UaBuildInfo(const UaExtensionObject &extensionObject);
    UaBuildInfo(const OpcUa_ExtensionObject &extensionObject);
    UaBuildInfo(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaBuildInfo(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaBuildInfo();

    void clear();

    bool operator==(const UaBuildInfo &other) const;
    bool operator!=(const UaBuildInfo &other) const;

    UaBuildInfo& operator=(const UaBuildInfo &other);

    OpcUa_BuildInfo* copy() const;
    void copyTo(OpcUa_BuildInfo *pDst) const;

    static OpcUa_BuildInfo* clone(const OpcUa_BuildInfo& source);
    static void cloneTo(const OpcUa_BuildInfo& source, OpcUa_BuildInfo& copy);

    void attach(OpcUa_BuildInfo *pValue);
    OpcUa_BuildInfo* detach(OpcUa_BuildInfo* pDst);

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

    OpcUa_StatusCode setBuildInfo(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setBuildInfo(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setBuildInfo(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setBuildInfo(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setBuildInfo(
        const UaString& productUri,
        const UaString& manufacturerName,
        const UaString& productName,
        const UaString& softwareVersion,
        const UaString& buildNumber,
        const UaDateTime& buildDate
        );

    UaString getProductUri() const;
    UaString getManufacturerName() const;
    UaString getProductName() const;
    UaString getSoftwareVersion() const;
    UaString getBuildNumber() const;
    UaDateTime getBuildDate() const;

    void setProductUri(const UaString& productUri);
    void setManufacturerName(const UaString& manufacturerName);
    void setProductName(const UaString& productName);
    void setSoftwareVersion(const UaString& softwareVersion);
    void setBuildNumber(const UaString& buildNumber);
    void setBuildDate(const UaDateTime& buildDate);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_BuildInfo.
 *
 *  This class encapsulates an array of the native OpcUa_BuildInfo structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaBuildInfo for information about the encapsulated structure.
 */
class UABASE_EXPORT UaBuildInfos
{
public:
    UaBuildInfos();
    UaBuildInfos(const UaBuildInfos &other);
    UaBuildInfos(OpcUa_Int32 length, OpcUa_BuildInfo* data);
    virtual ~UaBuildInfos();

    UaBuildInfos& operator=(const UaBuildInfos &other);
    const OpcUa_BuildInfo& operator[](OpcUa_UInt32 index) const;
    OpcUa_BuildInfo& operator[](OpcUa_UInt32 index);

    bool operator==(const UaBuildInfos &other) const;
    bool operator!=(const UaBuildInfos &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_BuildInfo* data);
    void attach(OpcUa_Int32 length, OpcUa_BuildInfo* data);
    OpcUa_BuildInfo* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_BuildInfo* rawData() const {return m_data;}
    inline OpcUa_BuildInfo* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setBuildInfos(const UaVariant &variant);
    OpcUa_StatusCode setBuildInfos(const OpcUa_Variant &variant);
    OpcUa_StatusCode setBuildInfos(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setBuildInfos(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setBuildInfos(OpcUa_Int32 length, OpcUa_BuildInfo* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_BuildInfo* m_data;
};

#endif // UABUILDINFO_H

