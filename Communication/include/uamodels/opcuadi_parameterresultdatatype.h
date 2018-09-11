/******************************************************************************
** opcuadi_parameterresultdatatype.h
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


#ifndef __OPCUADI_PARAMETERRESULTDATATYPE_H__
#define __OPCUADI_PARAMETERRESULTDATATYPE_H__

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uaqualifiedname.h"
#include "uaarraytemplates.h"
#include "opcuadi_identifiers.h"
#include "opcuadi_datatypes.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

// Namespace for the UA information model http://opcfoundation.org/UA/DI/
namespace OpcUaDi {

class UAMODELS_EXPORT ParameterResultDataTypePrivate;

/**
 *  @brief Wrapper class for the UA stack structure OpcUaDi_ParameterResultDataType.
 *
 *  This class encapsulates the native OpcUaDi_ParameterResultDataType structure
 *  and handles memory allocation and cleanup for you.
 *  ParameterResultDataType uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared ParameterResultDataType it creates a copy for that (copy-on-write).
 *  So assigning another ParameterResultDataType or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 */
class UAMODELS_EXPORT ParameterResultDataType
{
    OPCUADI_DECLARE_PRIVATE(ParameterResultDataType)
public:
    ParameterResultDataType();
    ParameterResultDataType(const ParameterResultDataType &other);
    ParameterResultDataType(const OpcUaDi_ParameterResultDataType &other);
    ParameterResultDataType(
        const UaQualifiedNameArray& NodePath,
        OpcUa_StatusCode StatusCode,
        const OpcUa_DiagnosticInfo& Diagnostics
        );
    ParameterResultDataType(const UaExtensionObject &extensionObject);
    ParameterResultDataType(const OpcUa_ExtensionObject &extensionObject);
    ParameterResultDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ParameterResultDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~ParameterResultDataType();

    void clear();

    bool operator==(const ParameterResultDataType &other) const;
    bool operator!=(const ParameterResultDataType &other) const;

    ParameterResultDataType& operator=(const ParameterResultDataType &other);

    OpcUaDi_ParameterResultDataType* copy() const;
    void copyTo(OpcUaDi_ParameterResultDataType *pDst) const;

    static OpcUaDi_ParameterResultDataType* clone(const OpcUaDi_ParameterResultDataType& source);
    static void cloneTo(const OpcUaDi_ParameterResultDataType& source, OpcUaDi_ParameterResultDataType& copy);

    void attach(const OpcUaDi_ParameterResultDataType *pValue);
    OpcUaDi_ParameterResultDataType* detach(OpcUaDi_ParameterResultDataType* pDst);

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

    OpcUa_StatusCode setParameterResultDataType(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setParameterResultDataType(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setParameterResultDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setParameterResultDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setParameterResultDataType(
        const UaQualifiedNameArray& NodePath,
        OpcUa_StatusCode StatusCode,
        const OpcUa_DiagnosticInfo& Diagnostics
        );

    void getNodePath(UaQualifiedNameArray& NodePath) const;
    OpcUa_StatusCode getStatusCode() const;
    OpcUa_DiagnosticInfo getDiagnostics() const;

    void setNodePath(const UaQualifiedNameArray& NodePath);
    void setStatusCode(OpcUa_StatusCode StatusCode);
    void setDiagnostics(const OpcUa_DiagnosticInfo& Diagnostics);
};

class ParameterResultDataTypes
{
public:
    ParameterResultDataTypes();
    ParameterResultDataTypes(const ParameterResultDataTypes &other);
    ParameterResultDataTypes(OpcUa_Int32 length, OpcUaDi_ParameterResultDataType* data);
    virtual ~ParameterResultDataTypes();

    ParameterResultDataTypes& operator=(const ParameterResultDataTypes &other);
    OpcUaDi_ParameterResultDataType& operator[](OpcUa_UInt32 index);
    const OpcUaDi_ParameterResultDataType& operator[](OpcUa_UInt32 index) const;

    void attach(OpcUa_UInt32 length, OpcUaDi_ParameterResultDataType* data);
    void attach(OpcUa_Int32 length, OpcUaDi_ParameterResultDataType* data);
    OpcUaDi_ParameterResultDataType* detach();

    bool operator==(const ParameterResultDataTypes &other) const;
    bool operator!=(const ParameterResultDataTypes &other) const;

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUaDi_ParameterResultDataType* rawData() const {return m_data;}
    inline OpcUaDi_ParameterResultDataType* rawData() {return m_data;}
    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setParameterResultDataTypes(const UaVariant &variant);
    OpcUa_StatusCode setParameterResultDataTypes(const OpcUa_Variant &variant);
    OpcUa_StatusCode setParameterResultDataTypes(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setParameterResultDataTypes(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setParameterResultDataTypes(OpcUa_Int32 length, OpcUaDi_ParameterResultDataType* data);

    static ParameterResultDataTypes empty;
private:
    OpcUa_UInt32 m_noOfElements;
    OpcUaDi_ParameterResultDataType* m_data;
};

} // namespace OpcUaDi

#endif // __OPCUADI_PARAMETERRESULTDATATYPE_H__

