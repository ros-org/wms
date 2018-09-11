/******************************************************************************
** opcuagds_applicationrecorddatatype.h
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
** Project: C++ OPC Server SDK information model for namespace http://opcfoundation.org/UA/GDS/
**
** Description: OPC Unified Architecture Software Development Kit.
**
******************************************************************************/


#ifndef __OPCUAGDS_APPLICATIONRECORDDATATYPE_H__
#define __OPCUAGDS_APPLICATIONRECORDDATATYPE_H__

#include <opcua_proxystub.h>

#include "uabase.h"
#include "ualocalizedtext.h"
#include "uanodeid.h"
#include "uastring.h"
#include "uaarraytemplates.h"
#include "opcuagds_identifiers.h"
#include "opcuagds_datatypes.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

// Namespace for the UA information model http://opcfoundation.org/UA/GDS/
namespace OpcUaGds {

class UABASE_EXPORT ApplicationRecordDataTypePrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUaGds_ApplicationRecordDataType.
 *
 *  This class encapsulates the native OpcUaGds_ApplicationRecordDataType structure
 *  and handles memory allocation and cleanup for you.
 *  ApplicationRecordDataType uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared ApplicationRecordDataType it creates a copy for that (copy-on-write).
 *  So assigning another ApplicationRecordDataType or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 */
class UABASE_EXPORT ApplicationRecordDataType
{
    OPCUAGDS_DECLARE_PRIVATE(ApplicationRecordDataType)
public:
    ApplicationRecordDataType();
    ApplicationRecordDataType(const ApplicationRecordDataType &other);
    ApplicationRecordDataType(const OpcUaGds_ApplicationRecordDataType &other);
    ApplicationRecordDataType(
        const UaNodeId& ApplicationId,
        const UaString& ApplicationUri,
        OpcUa_ApplicationType ApplicationType,
        const UaLocalizedTextArray& ApplicationNames,
        const UaString& ProductUri,
        const UaStringArray& DiscoveryUrls,
        const UaStringArray& ServerCapabilities
        );
    ApplicationRecordDataType(const UaExtensionObject &extensionObject);
    ApplicationRecordDataType(const OpcUa_ExtensionObject &extensionObject);
    ApplicationRecordDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ApplicationRecordDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~ApplicationRecordDataType();

    void clear();

    bool operator==(const ApplicationRecordDataType &other) const;
    bool operator!=(const ApplicationRecordDataType &other) const;

    ApplicationRecordDataType& operator=(const ApplicationRecordDataType &other);

    OpcUaGds_ApplicationRecordDataType* copy() const;
    void copyTo(OpcUaGds_ApplicationRecordDataType *pDst) const;

    static OpcUaGds_ApplicationRecordDataType* clone(const OpcUaGds_ApplicationRecordDataType& source);
    static void cloneTo(const OpcUaGds_ApplicationRecordDataType& source, OpcUaGds_ApplicationRecordDataType& copy);

    void attach(const OpcUaGds_ApplicationRecordDataType *pValue);
    OpcUaGds_ApplicationRecordDataType* detach(OpcUaGds_ApplicationRecordDataType* pDst);

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

    OpcUa_StatusCode setApplicationRecordDataType(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setApplicationRecordDataType(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setApplicationRecordDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setApplicationRecordDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setApplicationRecordDataType(
        const UaNodeId& ApplicationId,
        const UaString& ApplicationUri,
        OpcUa_ApplicationType ApplicationType,
        const UaLocalizedTextArray& ApplicationNames,
        const UaString& ProductUri,
        const UaStringArray& DiscoveryUrls,
        const UaStringArray& ServerCapabilities
        );

    UaNodeId getApplicationId() const;
    UaString getApplicationUri() const;
    OpcUa_ApplicationType  getApplicationType() const;
    void getApplicationNames(UaLocalizedTextArray& ApplicationNames) const;
    UaString getProductUri() const;
    void getDiscoveryUrls(UaStringArray& DiscoveryUrls) const;
    void getServerCapabilities(UaStringArray& ServerCapabilities) const;

    void setApplicationId(const UaNodeId& ApplicationId);
    void setApplicationUri(const UaString& ApplicationUri);
    void setApplicationType(OpcUa_ApplicationType ApplicationType);
    void setApplicationNames(const UaLocalizedTextArray& ApplicationNames);
    void setProductUri(const UaString& ProductUri);
    void setDiscoveryUrls(const UaStringArray& DiscoveryUrls);
    void setServerCapabilities(const UaStringArray& ServerCapabilities);
};

class UABASE_EXPORT ApplicationRecordDataTypes
{
public:
    ApplicationRecordDataTypes();
    ApplicationRecordDataTypes(const ApplicationRecordDataTypes &other);
    ApplicationRecordDataTypes(OpcUa_Int32 length, OpcUaGds_ApplicationRecordDataType* data);
    virtual ~ApplicationRecordDataTypes();

    ApplicationRecordDataTypes& operator=(const ApplicationRecordDataTypes &other);
    OpcUaGds_ApplicationRecordDataType& operator[](OpcUa_UInt32 index);
    const OpcUaGds_ApplicationRecordDataType& operator[](OpcUa_UInt32 index) const;

    void attach(OpcUa_UInt32 length, OpcUaGds_ApplicationRecordDataType* data);
    void attach(OpcUa_Int32 length, OpcUaGds_ApplicationRecordDataType* data);
    OpcUaGds_ApplicationRecordDataType* detach();

    bool operator==(const ApplicationRecordDataTypes &other) const;
    bool operator!=(const ApplicationRecordDataTypes &other) const;

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUaGds_ApplicationRecordDataType* rawData() const {return m_data;}
    inline OpcUaGds_ApplicationRecordDataType* rawData() {return m_data;}
    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setApplicationRecordDataTypes(const UaVariant &variant);
    OpcUa_StatusCode setApplicationRecordDataTypes(const OpcUa_Variant &variant);
    OpcUa_StatusCode setApplicationRecordDataTypes(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setApplicationRecordDataTypes(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setApplicationRecordDataTypes(OpcUa_Int32 length, OpcUaGds_ApplicationRecordDataType* data);

    static ApplicationRecordDataTypes empty;
private:
    OpcUa_UInt32 m_noOfElements;
    OpcUaGds_ApplicationRecordDataType* m_data;
};

} // namespace OpcUaGds

#endif // __OPCUAGDS_APPLICATIONRECORDDATATYPE_H__

