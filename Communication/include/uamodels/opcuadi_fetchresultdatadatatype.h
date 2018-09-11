/******************************************************************************
** opcuadi_fetchresultdatadatatype.h
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


#ifndef __OPCUADI_FETCHRESULTDATADATATYPE_H__
#define __OPCUADI_FETCHRESULTDATADATATYPE_H__

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

class UAMODELS_EXPORT FetchResultDataDataTypePrivate;
class UAMODELS_EXPORT ParameterResultDataTypes;

/**
 *  @brief Wrapper class for the UA stack structure OpcUaDi_FetchResultDataDataType.
 *
 *  This class encapsulates the native OpcUaDi_FetchResultDataDataType structure
 *  and handles memory allocation and cleanup for you.
 *  FetchResultDataDataType uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared FetchResultDataDataType it creates a copy for that (copy-on-write).
 *  So assigning another FetchResultDataDataType or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 */
class UAMODELS_EXPORT FetchResultDataDataType
{
    OPCUADI_DECLARE_PRIVATE(FetchResultDataDataType)
public:
    FetchResultDataDataType();
    FetchResultDataDataType(const FetchResultDataDataType &other);
    FetchResultDataDataType(const OpcUaDi_FetchResultDataDataType &other);
    FetchResultDataDataType(
        OpcUa_Int32 SequenceNumber,
        OpcUa_Boolean EndOfResults,
        const OpcUaDi::ParameterResultDataTypes& ParameterDefs
        );
    FetchResultDataDataType(const UaExtensionObject &extensionObject);
    FetchResultDataDataType(const OpcUa_ExtensionObject &extensionObject);
    FetchResultDataDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    FetchResultDataDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~FetchResultDataDataType();

    void clear();

    bool operator==(const FetchResultDataDataType &other) const;
    bool operator!=(const FetchResultDataDataType &other) const;

    FetchResultDataDataType& operator=(const FetchResultDataDataType &other);

    OpcUaDi_FetchResultDataDataType* copy() const;
    void copyTo(OpcUaDi_FetchResultDataDataType *pDst) const;

    static OpcUaDi_FetchResultDataDataType* clone(const OpcUaDi_FetchResultDataDataType& source);
    static void cloneTo(const OpcUaDi_FetchResultDataDataType& source, OpcUaDi_FetchResultDataDataType& copy);

    void attach(const OpcUaDi_FetchResultDataDataType *pValue);
    OpcUaDi_FetchResultDataDataType* detach(OpcUaDi_FetchResultDataDataType* pDst);

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

    OpcUa_StatusCode setFetchResultDataDataType(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setFetchResultDataDataType(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setFetchResultDataDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setFetchResultDataDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setFetchResultDataDataType(
        OpcUa_Int32 SequenceNumber,
        OpcUa_Boolean EndOfResults,
        const OpcUaDi::ParameterResultDataTypes& ParameterDefs
        );

    OpcUa_Int32 getSequenceNumber() const;
    OpcUa_Boolean getEndOfResults() const;
    void getParameterDefs(OpcUaDi::ParameterResultDataTypes& ParameterDefs) const;

    void setSequenceNumber(OpcUa_Int32 SequenceNumber);
    void setEndOfResults(OpcUa_Boolean EndOfResults);
    void setParameterDefs(const OpcUaDi::ParameterResultDataTypes& ParameterDefs);
};

class FetchResultDataDataTypes
{
public:
    FetchResultDataDataTypes();
    FetchResultDataDataTypes(const FetchResultDataDataTypes &other);
    FetchResultDataDataTypes(OpcUa_Int32 length, OpcUaDi_FetchResultDataDataType* data);
    virtual ~FetchResultDataDataTypes();

    FetchResultDataDataTypes& operator=(const FetchResultDataDataTypes &other);
    OpcUaDi_FetchResultDataDataType& operator[](OpcUa_UInt32 index);
    const OpcUaDi_FetchResultDataDataType& operator[](OpcUa_UInt32 index) const;

    void attach(OpcUa_UInt32 length, OpcUaDi_FetchResultDataDataType* data);
    void attach(OpcUa_Int32 length, OpcUaDi_FetchResultDataDataType* data);
    OpcUaDi_FetchResultDataDataType* detach();

    bool operator==(const FetchResultDataDataTypes &other) const;
    bool operator!=(const FetchResultDataDataTypes &other) const;

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUaDi_FetchResultDataDataType* rawData() const {return m_data;}
    inline OpcUaDi_FetchResultDataDataType* rawData() {return m_data;}
    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setFetchResultDataDataTypes(const UaVariant &variant);
    OpcUa_StatusCode setFetchResultDataDataTypes(const OpcUa_Variant &variant);
    OpcUa_StatusCode setFetchResultDataDataTypes(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setFetchResultDataDataTypes(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setFetchResultDataDataTypes(OpcUa_Int32 length, OpcUaDi_FetchResultDataDataType* data);

    static FetchResultDataDataTypes empty;
private:
    OpcUa_UInt32 m_noOfElements;
    OpcUaDi_FetchResultDataDataType* m_data;
};

} // namespace OpcUaDi

#endif // __OPCUADI_FETCHRESULTDATADATATYPE_H__

