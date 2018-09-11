/******************************************************************************
** uasupportedprofile.h
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
** Portable UaSupportedProfile class.
**
******************************************************************************/
#ifndef UASUPPORTEDPROFILE_H
#define UASUPPORTEDPROFILE_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uadatetime.h"
#include "uastring.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaSupportedProfilePrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_SupportedProfile.
 *
 *  This class encapsulates the native OpcUa_SupportedProfile structure
 *  and handles memory allocation and cleanup for you.
 *  UaSupportedProfile uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared SupportedProfile it creates a copy for that (copy-on-write).
 *  So assigning another UaSupportedProfile or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 */
class UABASE_EXPORT UaSupportedProfile
{
    UA_DECLARE_PRIVATE(UaSupportedProfile)
public:
    UaSupportedProfile();
    UaSupportedProfile(const UaSupportedProfile &other);
    UaSupportedProfile(const OpcUa_SupportedProfile &other);
    UaSupportedProfile(
        const UaString& organizationUri,
        const UaString& profileId,
        const UaString& complianceTool,
        const UaDateTime& complianceDate,
        OpcUa_ComplianceLevel complianceLevel,
        const UaStringArray &unsupportedUnitIds
        );
    UaSupportedProfile(const UaExtensionObject &extensionObject);
    UaSupportedProfile(const OpcUa_ExtensionObject &extensionObject);
    UaSupportedProfile(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaSupportedProfile(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaSupportedProfile();

    void clear();

    bool operator==(const UaSupportedProfile &other) const;
    bool operator!=(const UaSupportedProfile &other) const;

    UaSupportedProfile& operator=(const UaSupportedProfile &other);

    OpcUa_SupportedProfile* copy() const;
    void copyTo(OpcUa_SupportedProfile *pDst) const;

    static OpcUa_SupportedProfile* clone(const OpcUa_SupportedProfile& source);
    static void cloneTo(const OpcUa_SupportedProfile& source, OpcUa_SupportedProfile& copy);

    void attach(OpcUa_SupportedProfile *pValue);
    OpcUa_SupportedProfile* detach(OpcUa_SupportedProfile* pDst);

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

    OpcUa_StatusCode setSupportedProfile(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setSupportedProfile(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setSupportedProfile(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSupportedProfile(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setSupportedProfile(
        const UaString& organizationUri,
        const UaString& profileId,
        const UaString& complianceTool,
        const UaDateTime& complianceDate,
        OpcUa_ComplianceLevel complianceLevel,
        const UaStringArray &unsupportedUnitIds
        );

    UaString getOrganizationUri() const;
    UaString getProfileId() const;
    UaString getComplianceTool() const;
    UaDateTime getComplianceDate() const;
    OpcUa_ComplianceLevel getComplianceLevel() const;
    void getUnsupportedUnitIds(UaStringArray& unsupportedUnitIds) const;

    void setOrganizationUri(const UaString& organizationUri);
    void setProfileId(const UaString& profileId);
    void setComplianceTool(const UaString& complianceTool);
    void setComplianceDate(const UaDateTime& complianceDate);
    void setComplianceLevel(OpcUa_ComplianceLevel complianceLevel);
    void setUnsupportedUnitIds(const UaStringArray &unsupportedUnitIds);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_SupportedProfile.
 *
 *  This class encapsulates an array of the native OpcUa_SupportedProfile structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaSupportedProfile for information about the encapsulated structure.
 */
class UABASE_EXPORT UaSupportedProfiles
{
public:
    UaSupportedProfiles();
    UaSupportedProfiles(const UaSupportedProfiles &other);
    UaSupportedProfiles(OpcUa_Int32 length, OpcUa_SupportedProfile* data);
    virtual ~UaSupportedProfiles();

    UaSupportedProfiles& operator=(const UaSupportedProfiles &other);
    const OpcUa_SupportedProfile& operator[](OpcUa_UInt32 index) const;
    OpcUa_SupportedProfile& operator[](OpcUa_UInt32 index);

    bool operator==(const UaSupportedProfiles &other) const;
    bool operator!=(const UaSupportedProfiles &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_SupportedProfile* data);
    void attach(OpcUa_Int32 length, OpcUa_SupportedProfile* data);
    OpcUa_SupportedProfile* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_SupportedProfile* rawData() const {return m_data;}
    inline OpcUa_SupportedProfile* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setSupportedProfiles(const UaVariant &variant);
    OpcUa_StatusCode setSupportedProfiles(const OpcUa_Variant &variant);
    OpcUa_StatusCode setSupportedProfiles(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSupportedProfiles(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSupportedProfiles(OpcUa_Int32 length, OpcUa_SupportedProfile* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_SupportedProfile* m_data;
};

#endif // UASUPPORTEDPROFILE_H

