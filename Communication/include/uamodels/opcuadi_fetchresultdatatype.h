/******************************************************************************
** opcuadi_fetchresultdatatype.h
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
** Project: C++ OPC Server SDK information model for namespace http://opcfoundation.org/UA/DI/
**
** Description: OPC Unified Architecture Software Development Kit.
**
******************************************************************************/


#ifndef __OPCUADI_FETCHRESULTDATATYPE_H__
#define __OPCUADI_FETCHRESULTDATATYPE_H__

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uaarraytemplates.h"
#include "opcuadi_identifiers.h"
#include "opcuadi_datatypes.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

// Namespace for the UA information model http://opcfoundation.org/UA/DI/
namespace OpcUaDi {

class UAMODELS_EXPORT FetchResultDataTypePrivate;

/**
 *  @brief Wrapper class for the UA stack structure OpcUaDi_FetchResultDataType.
 *
 *  This class encapsulates the native OpcUaDi_FetchResultDataType structure
 *  and handles memory allocation and cleanup for you.
 *  FetchResultDataType uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared FetchResultDataType it creates a copy for that (copy-on-write).
 *  So assigning another FetchResultDataType or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 */
class UAMODELS_EXPORT FetchResultDataType
{
    OPCUADI_DECLARE_PRIVATE(FetchResultDataType)
public:
    FetchResultDataType();
    FetchResultDataType(const FetchResultDataType &other);
    ~FetchResultDataType();

    void clear();

    bool operator==(const FetchResultDataType &other) const;
    bool operator!=(const FetchResultDataType &other) const;

    FetchResultDataType& operator=(const FetchResultDataType &other);
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

    OpcUa_StatusCode setFetchResultDataType(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setFetchResultDataType(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setFetchResultDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setFetchResultDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);


};

class FetchResultDataTypes
{
public:
    FetchResultDataTypes();
    virtual ~FetchResultDataTypes();
    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);


    static FetchResultDataTypes empty;
};

} // namespace OpcUaDi

#endif // __OPCUADI_FETCHRESULTDATATYPE_H__

