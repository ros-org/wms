/******************************************************************************
** opcuadi_fetchresulterrordatatype.h
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


#ifndef __OPCUADI_FETCHRESULTERRORDATATYPE_H__
#define __OPCUADI_FETCHRESULTERRORDATATYPE_H__

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

class UAMODELS_EXPORT FetchResultErrorDataTypePrivate;

/**
 *  @brief Wrapper class for the UA stack structure OpcUaDi_FetchResultErrorDataType.
 *
 *  This class encapsulates the native OpcUaDi_FetchResultErrorDataType structure
 *  and handles memory allocation and cleanup for you.
 *  FetchResultErrorDataType uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared FetchResultErrorDataType it creates a copy for that (copy-on-write).
 *  So assigning another FetchResultErrorDataType or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 */
class UAMODELS_EXPORT FetchResultErrorDataType
{
    OPCUADI_DECLARE_PRIVATE(FetchResultErrorDataType)
public:
    FetchResultErrorDataType();
    FetchResultErrorDataType(const FetchResultErrorDataType &other);
    FetchResultErrorDataType(const OpcUaDi_FetchResultErrorDataType &other);
    FetchResultErrorDataType(
        OpcUa_Int32 Status,
        const OpcUa_DiagnosticInfo& Diagnostics
        );
    FetchResultErrorDataType(const UaExtensionObject &extensionObject);
    FetchResultErrorDataType(const OpcUa_ExtensionObject &extensionObject);
    FetchResultErrorDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    FetchResultErrorDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~FetchResultErrorDataType();

    void clear();

    bool operator==(const FetchResultErrorDataType &other) const;
    bool operator!=(const FetchResultErrorDataType &other) const;

    FetchResultErrorDataType& operator=(const FetchResultErrorDataType &other);

    OpcUaDi_FetchResultErrorDataType* copy() const;
    void copyTo(OpcUaDi_FetchResultErrorDataType *pDst) const;

    static OpcUaDi_FetchResultErrorDataType* clone(const OpcUaDi_FetchResultErrorDataType& source);
    static void cloneTo(const OpcUaDi_FetchResultErrorDataType& source, OpcUaDi_FetchResultErrorDataType& copy);

    void attach(const OpcUaDi_FetchResultErrorDataType *pValue);
    OpcUaDi_FetchResultErrorDataType* detach(OpcUaDi_FetchResultErrorDataType* pDst);

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

    OpcUa_StatusCode setFetchResultErrorDataType(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setFetchResultErrorDataType(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setFetchResultErrorDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setFetchResultErrorDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setFetchResultErrorDataType(
        OpcUa_Int32 Status,
        const OpcUa_DiagnosticInfo& Diagnostics
        );

    OpcUa_Int32 getStatus() const;
    OpcUa_DiagnosticInfo getDiagnostics() const;

    void setStatus(OpcUa_Int32 Status);
    void setDiagnostics(const OpcUa_DiagnosticInfo& Diagnostics);
};

class FetchResultErrorDataTypes
{
public:
    FetchResultErrorDataTypes();
    FetchResultErrorDataTypes(const FetchResultErrorDataTypes &other);
    FetchResultErrorDataTypes(OpcUa_Int32 length, OpcUaDi_FetchResultErrorDataType* data);
    virtual ~FetchResultErrorDataTypes();

    FetchResultErrorDataTypes& operator=(const FetchResultErrorDataTypes &other);
    OpcUaDi_FetchResultErrorDataType& operator[](OpcUa_UInt32 index);
    const OpcUaDi_FetchResultErrorDataType& operator[](OpcUa_UInt32 index) const;

    void attach(OpcUa_UInt32 length, OpcUaDi_FetchResultErrorDataType* data);
    void attach(OpcUa_Int32 length, OpcUaDi_FetchResultErrorDataType* data);
    OpcUaDi_FetchResultErrorDataType* detach();

    bool operator==(const FetchResultErrorDataTypes &other) const;
    bool operator!=(const FetchResultErrorDataTypes &other) const;

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUaDi_FetchResultErrorDataType* rawData() const {return m_data;}
    inline OpcUaDi_FetchResultErrorDataType* rawData() {return m_data;}
    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setFetchResultErrorDataTypes(const UaVariant &variant);
    OpcUa_StatusCode setFetchResultErrorDataTypes(const OpcUa_Variant &variant);
    OpcUa_StatusCode setFetchResultErrorDataTypes(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setFetchResultErrorDataTypes(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setFetchResultErrorDataTypes(OpcUa_Int32 length, OpcUaDi_FetchResultErrorDataType* data);

    static FetchResultErrorDataTypes empty;
private:
    OpcUa_UInt32 m_noOfElements;
    OpcUaDi_FetchResultErrorDataType* m_data;
};

} // namespace OpcUaDi

#endif // __OPCUADI_FETCHRESULTERRORDATATYPE_H__

