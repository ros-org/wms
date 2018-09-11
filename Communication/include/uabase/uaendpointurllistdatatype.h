/******************************************************************************
** uaendpointurllistdatatype.h
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
** Portable UaEndpointUrlListDataType class.
**
******************************************************************************/
#ifndef UAENDPOINTURLLISTDATATYPE_H
#define UAENDPOINTURLLISTDATATYPE_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uastring.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaEndpointUrlListDataTypePrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_EndpointUrlListDataType.
 *
 *  This class encapsulates the native OpcUa_EndpointUrlListDataType structure
 *  and handles memory allocation and cleanup for you.
 *  UaEndpointUrlListDataType uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared EndpointUrlListDataType it creates a copy for that (copy-on-write).
 *  So assigning another UaEndpointUrlListDataType or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  Structure representing a list of URLs of an Endpoint.
 */
class UABASE_EXPORT UaEndpointUrlListDataType
{
    UA_DECLARE_PRIVATE(UaEndpointUrlListDataType)
public:
    UaEndpointUrlListDataType();
    UaEndpointUrlListDataType(const UaEndpointUrlListDataType &other);
    UaEndpointUrlListDataType(const OpcUa_EndpointUrlListDataType &other);
    UaEndpointUrlListDataType(
        const UaStringArray &endpointUrlList
        );
    UaEndpointUrlListDataType(const UaExtensionObject &extensionObject);
    UaEndpointUrlListDataType(const OpcUa_ExtensionObject &extensionObject);
    UaEndpointUrlListDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaEndpointUrlListDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaEndpointUrlListDataType();

    void clear();

    bool operator==(const UaEndpointUrlListDataType &other) const;
    bool operator!=(const UaEndpointUrlListDataType &other) const;

    UaEndpointUrlListDataType& operator=(const UaEndpointUrlListDataType &other);

    OpcUa_EndpointUrlListDataType* copy() const;
    void copyTo(OpcUa_EndpointUrlListDataType *pDst) const;

    static OpcUa_EndpointUrlListDataType* clone(const OpcUa_EndpointUrlListDataType& source);
    static void cloneTo(const OpcUa_EndpointUrlListDataType& source, OpcUa_EndpointUrlListDataType& copy);

    void attach(OpcUa_EndpointUrlListDataType *pValue);
    OpcUa_EndpointUrlListDataType* detach(OpcUa_EndpointUrlListDataType* pDst);

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

    OpcUa_StatusCode setEndpointUrlListDataType(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setEndpointUrlListDataType(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setEndpointUrlListDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setEndpointUrlListDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setEndpointUrlListDataType(
        const UaStringArray &endpointUrlList
        );

    void getEndpointUrlList(UaStringArray& endpointUrlList) const;

    void setEndpointUrlList(const UaStringArray &endpointUrlList);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_EndpointUrlListDataType.
 *
 *  This class encapsulates an array of the native OpcUa_EndpointUrlListDataType structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaEndpointUrlListDataType for information about the encapsulated structure.
 */
class UABASE_EXPORT UaEndpointUrlListDataTypes
{
public:
    UaEndpointUrlListDataTypes();
    UaEndpointUrlListDataTypes(const UaEndpointUrlListDataTypes &other);
    UaEndpointUrlListDataTypes(OpcUa_Int32 length, OpcUa_EndpointUrlListDataType* data);
    virtual ~UaEndpointUrlListDataTypes();

    UaEndpointUrlListDataTypes& operator=(const UaEndpointUrlListDataTypes &other);
    const OpcUa_EndpointUrlListDataType& operator[](OpcUa_UInt32 index) const;
    OpcUa_EndpointUrlListDataType& operator[](OpcUa_UInt32 index);

    bool operator==(const UaEndpointUrlListDataTypes &other) const;
    bool operator!=(const UaEndpointUrlListDataTypes &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_EndpointUrlListDataType* data);
    void attach(OpcUa_Int32 length, OpcUa_EndpointUrlListDataType* data);
    OpcUa_EndpointUrlListDataType* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_EndpointUrlListDataType* rawData() const {return m_data;}
    inline OpcUa_EndpointUrlListDataType* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setEndpointUrlListDataTypes(const UaVariant &variant);
    OpcUa_StatusCode setEndpointUrlListDataTypes(const OpcUa_Variant &variant);
    OpcUa_StatusCode setEndpointUrlListDataTypes(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setEndpointUrlListDataTypes(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setEndpointUrlListDataTypes(OpcUa_Int32 length, OpcUa_EndpointUrlListDataType* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_EndpointUrlListDataType* m_data;
};

#endif // UAENDPOINTURLLISTDATATYPE_H

