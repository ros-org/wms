/******************************************************************************
** uamodelchangestructuredatatype.h
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
** Portable UaModelChangeStructureDataType class.
**
******************************************************************************/
#ifndef UAMODELCHANGESTRUCTUREDATATYPE_H
#define UAMODELCHANGESTRUCTUREDATATYPE_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uanodeid.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaModelChangeStructureDataTypePrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_ModelChangeStructureDataType.
 *
 *  This class encapsulates the native OpcUa_ModelChangeStructureDataType structure
 *  and handles memory allocation and cleanup for you.
 *  UaModelChangeStructureDataType uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared ModelChangeStructureDataType it creates a copy for that (copy-on-write).
 *  So assigning another UaModelChangeStructureDataType or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  Contains elements that describe changes of the model.
 */
class UABASE_EXPORT UaModelChangeStructureDataType
{
    UA_DECLARE_PRIVATE(UaModelChangeStructureDataType)
public:
    UaModelChangeStructureDataType();
    UaModelChangeStructureDataType(const UaModelChangeStructureDataType &other);
    UaModelChangeStructureDataType(const OpcUa_ModelChangeStructureDataType &other);
    UaModelChangeStructureDataType(
        const UaNodeId& affected,
        const UaNodeId& affectedType,
        OpcUa_Byte verb
        );
    UaModelChangeStructureDataType(const UaExtensionObject &extensionObject);
    UaModelChangeStructureDataType(const OpcUa_ExtensionObject &extensionObject);
    UaModelChangeStructureDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaModelChangeStructureDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaModelChangeStructureDataType();

    void clear();

    bool operator==(const UaModelChangeStructureDataType &other) const;
    bool operator!=(const UaModelChangeStructureDataType &other) const;

    UaModelChangeStructureDataType& operator=(const UaModelChangeStructureDataType &other);

    OpcUa_ModelChangeStructureDataType* copy() const;
    void copyTo(OpcUa_ModelChangeStructureDataType *pDst) const;

    static OpcUa_ModelChangeStructureDataType* clone(const OpcUa_ModelChangeStructureDataType& source);
    static void cloneTo(const OpcUa_ModelChangeStructureDataType& source, OpcUa_ModelChangeStructureDataType& copy);

    void attach(OpcUa_ModelChangeStructureDataType *pValue);
    OpcUa_ModelChangeStructureDataType* detach(OpcUa_ModelChangeStructureDataType* pDst);

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

    OpcUa_StatusCode setModelChangeStructureDataType(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setModelChangeStructureDataType(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setModelChangeStructureDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setModelChangeStructureDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setModelChangeStructureDataType(
        const UaNodeId& affected,
        const UaNodeId& affectedType,
        OpcUa_Byte verb
        );

    UaNodeId getAffected() const;
    UaNodeId getAffectedType() const;
    OpcUa_Byte getVerb() const;

    void setAffected(const UaNodeId& affected);
    void setAffectedType(const UaNodeId& affectedType);
    void setVerb(OpcUa_Byte verb);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_ModelChangeStructureDataType.
 *
 *  This class encapsulates an array of the native OpcUa_ModelChangeStructureDataType structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaModelChangeStructureDataType for information about the encapsulated structure.
 */
class UABASE_EXPORT UaModelChangeStructureDataTypes
{
public:
    UaModelChangeStructureDataTypes();
    UaModelChangeStructureDataTypes(const UaModelChangeStructureDataTypes &other);
    UaModelChangeStructureDataTypes(OpcUa_Int32 length, OpcUa_ModelChangeStructureDataType* data);
    virtual ~UaModelChangeStructureDataTypes();

    UaModelChangeStructureDataTypes& operator=(const UaModelChangeStructureDataTypes &other);
    const OpcUa_ModelChangeStructureDataType& operator[](OpcUa_UInt32 index) const;
    OpcUa_ModelChangeStructureDataType& operator[](OpcUa_UInt32 index);

    bool operator==(const UaModelChangeStructureDataTypes &other) const;
    bool operator!=(const UaModelChangeStructureDataTypes &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_ModelChangeStructureDataType* data);
    void attach(OpcUa_Int32 length, OpcUa_ModelChangeStructureDataType* data);
    OpcUa_ModelChangeStructureDataType* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_ModelChangeStructureDataType* rawData() const {return m_data;}
    inline OpcUa_ModelChangeStructureDataType* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setModelChangeStructureDataTypes(const UaVariant &variant);
    OpcUa_StatusCode setModelChangeStructureDataTypes(const OpcUa_Variant &variant);
    OpcUa_StatusCode setModelChangeStructureDataTypes(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setModelChangeStructureDataTypes(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setModelChangeStructureDataTypes(OpcUa_Int32 length, OpcUa_ModelChangeStructureDataType* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_ModelChangeStructureDataType* m_data;
};

#endif // UAMODELCHANGESTRUCTUREDATATYPE_H

