/******************************************************************************
** uanetworkgroupdatatype.h
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
** Portable UaNetworkGroupDataType class.
**
******************************************************************************/
#ifndef UANETWORKGROUPDATATYPE_H
#define UANETWORKGROUPDATATYPE_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uaendpointurllistdatatype.h"
#include "uastring.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaNetworkGroupDataTypePrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_NetworkGroupDataType.
 *
 *  This class encapsulates the native OpcUa_NetworkGroupDataType structure
 *  and handles memory allocation and cleanup for you.
 *  UaNetworkGroupDataType uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared NetworkGroupDataType it creates a copy for that (copy-on-write).
 *  So assigning another UaNetworkGroupDataType or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  Contains information on different network paths for one Server.
 */
class UABASE_EXPORT UaNetworkGroupDataType
{
    UA_DECLARE_PRIVATE(UaNetworkGroupDataType)
public:
    UaNetworkGroupDataType();
    UaNetworkGroupDataType(const UaNetworkGroupDataType &other);
    UaNetworkGroupDataType(const OpcUa_NetworkGroupDataType &other);
    UaNetworkGroupDataType(
        const UaString& serverUri,
        const UaEndpointUrlListDataTypes &networkPaths
        );
    UaNetworkGroupDataType(const UaExtensionObject &extensionObject);
    UaNetworkGroupDataType(const OpcUa_ExtensionObject &extensionObject);
    UaNetworkGroupDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaNetworkGroupDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaNetworkGroupDataType();

    void clear();

    bool operator==(const UaNetworkGroupDataType &other) const;
    bool operator!=(const UaNetworkGroupDataType &other) const;

    UaNetworkGroupDataType& operator=(const UaNetworkGroupDataType &other);

    OpcUa_NetworkGroupDataType* copy() const;
    void copyTo(OpcUa_NetworkGroupDataType *pDst) const;

    static OpcUa_NetworkGroupDataType* clone(const OpcUa_NetworkGroupDataType& source);
    static void cloneTo(const OpcUa_NetworkGroupDataType& source, OpcUa_NetworkGroupDataType& copy);

    void attach(OpcUa_NetworkGroupDataType *pValue);
    OpcUa_NetworkGroupDataType* detach(OpcUa_NetworkGroupDataType* pDst);

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

    OpcUa_StatusCode setNetworkGroupDataType(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setNetworkGroupDataType(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setNetworkGroupDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setNetworkGroupDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setNetworkGroupDataType(
        const UaString& serverUri,
        const UaEndpointUrlListDataTypes &networkPaths
        );

    UaString getServerUri() const;
    void getNetworkPaths(UaEndpointUrlListDataTypes& networkPaths) const;

    void setServerUri(const UaString& serverUri);
    void setNetworkPaths(const UaEndpointUrlListDataTypes &networkPaths);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_NetworkGroupDataType.
 *
 *  This class encapsulates an array of the native OpcUa_NetworkGroupDataType structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaNetworkGroupDataType for information about the encapsulated structure.
 */
class UABASE_EXPORT UaNetworkGroupDataTypes
{
public:
    UaNetworkGroupDataTypes();
    UaNetworkGroupDataTypes(const UaNetworkGroupDataTypes &other);
    UaNetworkGroupDataTypes(OpcUa_Int32 length, OpcUa_NetworkGroupDataType* data);
    virtual ~UaNetworkGroupDataTypes();

    UaNetworkGroupDataTypes& operator=(const UaNetworkGroupDataTypes &other);
    const OpcUa_NetworkGroupDataType& operator[](OpcUa_UInt32 index) const;
    OpcUa_NetworkGroupDataType& operator[](OpcUa_UInt32 index);

    bool operator==(const UaNetworkGroupDataTypes &other) const;
    bool operator!=(const UaNetworkGroupDataTypes &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_NetworkGroupDataType* data);
    void attach(OpcUa_Int32 length, OpcUa_NetworkGroupDataType* data);
    OpcUa_NetworkGroupDataType* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_NetworkGroupDataType* rawData() const {return m_data;}
    inline OpcUa_NetworkGroupDataType* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setNetworkGroupDataTypes(const UaVariant &variant);
    OpcUa_StatusCode setNetworkGroupDataTypes(const OpcUa_Variant &variant);
    OpcUa_StatusCode setNetworkGroupDataTypes(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setNetworkGroupDataTypes(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setNetworkGroupDataTypes(OpcUa_Int32 length, OpcUa_NetworkGroupDataType* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_NetworkGroupDataType* m_data;
};

#endif // UANETWORKGROUPDATATYPE_H

