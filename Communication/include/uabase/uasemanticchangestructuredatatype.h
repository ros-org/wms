/******************************************************************************
** uasemanticchangestructuredatatype.h
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
** Portable UaSemanticChangeStructureDataType class.
**
******************************************************************************/
#ifndef UASEMANTICCHANGESTRUCTUREDATATYPE_H
#define UASEMANTICCHANGESTRUCTUREDATATYPE_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uanodeid.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaSemanticChangeStructureDataTypePrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_SemanticChangeStructureDataType.
 *
 *  This class encapsulates the native OpcUa_SemanticChangeStructureDataType structure
 *  and handles memory allocation and cleanup for you.
 *  UaSemanticChangeStructureDataType uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared SemanticChangeStructureDataType it creates a copy for that (copy-on-write).
 *  So assigning another UaSemanticChangeStructureDataType or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  Contains elements that describe a change of the model.
 */
class UABASE_EXPORT UaSemanticChangeStructureDataType
{
    UA_DECLARE_PRIVATE(UaSemanticChangeStructureDataType)
public:
    UaSemanticChangeStructureDataType();
    UaSemanticChangeStructureDataType(const UaSemanticChangeStructureDataType &other);
    UaSemanticChangeStructureDataType(const OpcUa_SemanticChangeStructureDataType &other);
    UaSemanticChangeStructureDataType(
        const UaNodeId& affected,
        const UaNodeId& affectedType
        );
    UaSemanticChangeStructureDataType(const UaExtensionObject &extensionObject);
    UaSemanticChangeStructureDataType(const OpcUa_ExtensionObject &extensionObject);
    UaSemanticChangeStructureDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaSemanticChangeStructureDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaSemanticChangeStructureDataType();

    void clear();

    bool operator==(const UaSemanticChangeStructureDataType &other) const;
    bool operator!=(const UaSemanticChangeStructureDataType &other) const;

    UaSemanticChangeStructureDataType& operator=(const UaSemanticChangeStructureDataType &other);

    OpcUa_SemanticChangeStructureDataType* copy() const;
    void copyTo(OpcUa_SemanticChangeStructureDataType *pDst) const;

    static OpcUa_SemanticChangeStructureDataType* clone(const OpcUa_SemanticChangeStructureDataType& source);
    static void cloneTo(const OpcUa_SemanticChangeStructureDataType& source, OpcUa_SemanticChangeStructureDataType& copy);

    void attach(OpcUa_SemanticChangeStructureDataType *pValue);
    OpcUa_SemanticChangeStructureDataType* detach(OpcUa_SemanticChangeStructureDataType* pDst);

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

    OpcUa_StatusCode setSemanticChangeStructureDataType(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setSemanticChangeStructureDataType(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setSemanticChangeStructureDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSemanticChangeStructureDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setSemanticChangeStructureDataType(
        const UaNodeId& affected,
        const UaNodeId& affectedType
        );

    UaNodeId getAffected() const;
    UaNodeId getAffectedType() const;

    void setAffected(const UaNodeId& affected);
    void setAffectedType(const UaNodeId& affectedType);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_SemanticChangeStructureDataType.
 *
 *  This class encapsulates an array of the native OpcUa_SemanticChangeStructureDataType structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaSemanticChangeStructureDataType for information about the encapsulated structure.
 */
class UABASE_EXPORT UaSemanticChangeStructureDataTypes
{
public:
    UaSemanticChangeStructureDataTypes();
    UaSemanticChangeStructureDataTypes(const UaSemanticChangeStructureDataTypes &other);
    UaSemanticChangeStructureDataTypes(OpcUa_Int32 length, OpcUa_SemanticChangeStructureDataType* data);
    virtual ~UaSemanticChangeStructureDataTypes();

    UaSemanticChangeStructureDataTypes& operator=(const UaSemanticChangeStructureDataTypes &other);
    const OpcUa_SemanticChangeStructureDataType& operator[](OpcUa_UInt32 index) const;
    OpcUa_SemanticChangeStructureDataType& operator[](OpcUa_UInt32 index);

    bool operator==(const UaSemanticChangeStructureDataTypes &other) const;
    bool operator!=(const UaSemanticChangeStructureDataTypes &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_SemanticChangeStructureDataType* data);
    void attach(OpcUa_Int32 length, OpcUa_SemanticChangeStructureDataType* data);
    OpcUa_SemanticChangeStructureDataType* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_SemanticChangeStructureDataType* rawData() const {return m_data;}
    inline OpcUa_SemanticChangeStructureDataType* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setSemanticChangeStructureDataTypes(const UaVariant &variant);
    OpcUa_StatusCode setSemanticChangeStructureDataTypes(const OpcUa_Variant &variant);
    OpcUa_StatusCode setSemanticChangeStructureDataTypes(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSemanticChangeStructureDataTypes(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSemanticChangeStructureDataTypes(OpcUa_Int32 length, OpcUa_SemanticChangeStructureDataType* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_SemanticChangeStructureDataType* m_data;
};

#endif // UASEMANTICCHANGESTRUCTUREDATATYPE_H

