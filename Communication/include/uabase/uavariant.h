/******************************************************************************
** uavariant.h
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
** Portable UA Variant class.
**
******************************************************************************/
#ifndef UAVARIANT_H
#define UAVARIANT_H

#include <opcua_platformdefs.h>
#include <opcua_types.h>
#include "uaplatformdefs.h"
#include "uanodeid.h"
#include "uaqualifiedname.h"
#include "ualocalizedtext.h"
#include "uaarraytemplates.h"
#include "uaextensionobject.h"
#include "uabytestring.h"
#include "uaguid.h"
#include "uaexpandednodeid.h"
#include "uanumericrange.h"
#if defined(_UA_WIN32) && UASDK_WITH_COM_UTILITIES
#include <oaidl.h>  // windows VARIANT definition
#endif

class UaDataValue;
class UaDateTime;
class UaUniStringList;

/*! \addtogroup CppBaseLibraryClass
*  @{
*/

/** Wrapper class for the UA stack structure OpcUa_Variant

 Helper class for handling the OPC UA built-in data type Variant. It provides conversion and
 comparison functions and handles memory allocation and cleanup.

 The UaVariant class acts like a union for all OPC UA built-in data types.
*/
class UABASE_EXPORT UaVariant
{
public:
    UaVariant();
    UaVariant(const UaVariant&);
    UaVariant(const OpcUa_Variant&);
    UaVariant(OpcUa_Variant* pValue, OpcUa_Boolean detachValue = OpcUa_False);
    UaVariant(OpcUa_Boolean);
    UaVariant(OpcUa_SByte);
    UaVariant(OpcUa_Int16);
    UaVariant(OpcUa_Int32);
    UaVariant(OpcUa_Int64);
    UaVariant(OpcUa_UInt16);
    UaVariant(OpcUa_UInt32);
    UaVariant(OpcUa_UInt64);
    UaVariant(OpcUa_Float);
    UaVariant(OpcUa_Double);
    UaVariant(const UaString&);
    UaVariant(const UaDateTime&);
    UaVariant(const UaGuid&);
    UaVariant(UaByteString& val, OpcUa_Boolean detachValue = OpcUa_False);
    UaVariant(const UaNodeId&);
    UaVariant(const UaQualifiedName&);
    UaVariant(const UaLocalizedText&);
    ~UaVariant();

    void              clear();
    OpcUa_Boolean     isEmpty() const;
    OpcUa_Byte        arrayType() const;
    OpcUa_Boolean     isArray() const;
    OpcUa_Int32       arraySize() const;
    OpcUa_Boolean     isMatrix() const;
    OpcUa_Int32       noOfMatrixElements() const;
    OpcUa_Int32       dimensionSize() const;

    void arrayDimensions(UaUInt32Array& arrayDimensions) const;

    OpcUa_BuiltInType type() const;
    UaNodeId          dataType() const;
    UaNodeId          dataType(const UaStringArray &namespaceTable) const;
    UaExtensionObject::ExtensionObjectEncoding encoding() const;
    UaNodeId          encodingTypeId() const;
    OpcUa_StatusCode  changeType(OpcUa_BuiltInType, OpcUa_Boolean toArray);
    OpcUa_StatusCode  getIndexRange(const UaNumericRange& indexRange, UaVariant& value) const;
    OpcUa_StatusCode  applyIndexRange(const UaNumericRange& indexRange, const UaVariant& value);

#if defined(_UA_WIN32) && UASDK_WITH_COM_UTILITIES
    UaVariant(const VARIANT&); // Throws UaVariantException if type cannot be converted
    UaVariant& operator=(const VARIANT&); // Throws UaVariantException if type cannot be converted
    operator VARIANT() const; // Throws UaVariantException if type cannot be converted
    static OpcUa_StatusCode VartypeToUaType(VARTYPE vt, OpcUa_BuiltInType& ut, OpcUa_Boolean& isArray);
    static OpcUa_StatusCode UaTypeToVartype(OpcUa_BuiltInType ut, OpcUa_Boolean isArray, VARTYPE& vt );
#endif

    UaVariant& operator=(const OpcUa_Variant&);
    UaVariant& operator=(const UaVariant&);
    UaVariant& operator=(double);
    UaVariant& operator=(const UaString&);

    bool operator==(const UaVariant&) const;
    bool operator!=(const UaVariant&) const;
    static bool compare(const OpcUa_Variant&, const OpcUa_Variant&);
    static void adjustTypes(UaVariant& value1, UaVariant& value2, bool bForceConversion = false);

    bool operator>(const UaVariant&) const;
    bool operator<(const UaVariant&) const;
    bool operator>=(const UaVariant&) const;
    bool operator<=(const UaVariant&) const;

    OpcUa_Variant operator[](const OpcUa_UInt32 index) const;

    operator const OpcUa_Variant*() const;

    void detach();
    void attach(const OpcUa_Variant *pSrc);

    OpcUa_Variant* copy() const;
    void copyTo(OpcUa_Variant *pDst) const;

    static OpcUa_Variant* clone(const OpcUa_Variant& source);
    static void cloneTo(const OpcUa_Variant& source, OpcUa_Variant& copy);

    void setBool(OpcUa_Boolean val);
    void setBoolean(OpcUa_Boolean val);
    void setSByte(OpcUa_SByte val);
    void setInt16(OpcUa_Int16 val);
    void setInt32(OpcUa_Int32 val);
    void setInt64(OpcUa_Int64 val);
    void setByte(OpcUa_Byte val);
    void setUInt16(OpcUa_UInt16 val);
    void setUInt32(OpcUa_UInt32 val);
    void setUInt64(OpcUa_UInt64 val);
    void setFloat(OpcUa_Float val);
    void setDouble(OpcUa_Double val);
    void setString(const UaString& val);
    void setDateTime(const UaDateTime& val);
    void setGuid(const UaGuid& val);
    void setByteString(UaByteString& val, OpcUa_Boolean bDetach);
    void setXmlElement(const UaString& val);
    void setXmlElement(UaByteString& val, OpcUa_Boolean bDetach);
    void setNodeId(const UaNodeId& val);
    void setExpandedNodeId(const UaExpandedNodeId& val);
    void setStatusCode(OpcUa_StatusCode val);
    void setQualifiedName(const UaQualifiedName& val);
    void setLocalizedText(const UaLocalizedText& val);
    void setExtensionObject(UaExtensionObject& val, OpcUa_Boolean bDetach);
    void setDataValue(UaDataValue* pVal, OpcUa_Boolean bDetach);

    void setBoolArray(UaBoolArray& val, OpcUa_Boolean bDetach = OpcUa_False);
    void setByteArray(UaByteArray& val, OpcUa_Boolean bDetach = OpcUa_False);
    void setSByteArray(UaSByteArray& val, OpcUa_Boolean bDetach = OpcUa_False);
    void setInt16Array(UaInt16Array& val, OpcUa_Boolean bDetach = OpcUa_False);
    void setUInt16Array(UaUInt16Array& val, OpcUa_Boolean bDetach = OpcUa_False);
    void setInt32Array(UaInt32Array& val, OpcUa_Boolean bDetach = OpcUa_False);
    void setUInt32Array(UaUInt32Array& val, OpcUa_Boolean bDetach = OpcUa_False);
    void setInt64Array(UaInt64Array& val, OpcUa_Boolean bDetach = OpcUa_False);
    void setUInt64Array(UaUInt64Array& val, OpcUa_Boolean bDetach = OpcUa_False);
    void setFloatArray(UaFloatArray& val, OpcUa_Boolean bDetach = OpcUa_False);
    void setDoubleArray(UaDoubleArray& val, OpcUa_Boolean bDetach = OpcUa_False);
    void setStringArray(UaStringArray& val, OpcUa_Boolean bDetach);
    void setStringArray(const UaStringArray& val);
    void setDateTimeArray(UaDateTimeArray& val, OpcUa_Boolean bDetach = OpcUa_False);
    void setGuidArray(UaGuidArray& val, OpcUa_Boolean bDetach = OpcUa_False);
    void setByteStringArray(UaByteStringArray& val, OpcUa_Boolean bDetach = OpcUa_False);
    void setByteStringArray(const UaByteStringArray& val);
    void setXmlElementArray(UaByteStringArray& val, OpcUa_Boolean bDetach = OpcUa_False);
    void setXmlElementArray(const UaByteStringArray& val);
    void setNodeIdArray(UaNodeIdArray& val, OpcUa_Boolean bDetach = OpcUa_False);
    void setExpandedNodeIdArray(UaExpandedNodeIdArray& val, OpcUa_Boolean bDetach = OpcUa_False);
    void setStatusCodeArray(UaStatusCodeArray& val, OpcUa_Boolean bDetach = OpcUa_False);
    void setQualifiedNameArray(UaQualifiedNameArray& val, OpcUa_Boolean bDetach);
    void setQualifiedNameArray(const UaQualifiedNameArray& val);
    void setLocalizedTextArray(UaLocalizedTextArray& val, OpcUa_Boolean bDetach);
    void setLocalizedTextArray(const UaLocalizedTextArray& val);
    void setExtensionObjectArray(UaExtensionObjectArray& val, OpcUa_Boolean bDetach = OpcUa_False);
    void setDataValueArray(UaDataValues& val, OpcUa_Boolean bDetach);
    void setDataValueArray(const UaDataValues& val);
    void setVariantArray(UaVariantArray& val, OpcUa_Boolean bDetach = OpcUa_False);
    void setVariantArray(const UaVariantArray& val);

    OpcUa_StatusCode setBoolMatrix(UaBoolArray& val, const UaInt32Array& dimensions, OpcUa_Boolean bDetach = OpcUa_False);
    OpcUa_StatusCode setSByteMatrix(UaSByteArray& val, const UaInt32Array& dimensions, OpcUa_Boolean bDetach = OpcUa_False);
    OpcUa_StatusCode setByteMatrix(UaByteArray& val, const UaInt32Array& dimensions);
    OpcUa_StatusCode setInt16Matrix(UaInt16Array& val, const UaInt32Array& dimensions, OpcUa_Boolean bDetach = OpcUa_False);
    OpcUa_StatusCode setUInt16Matrix(UaUInt16Array& val, const UaInt32Array& dimensions, OpcUa_Boolean bDetach = OpcUa_False);
    OpcUa_StatusCode setInt32Matrix(UaInt32Array& val, const UaInt32Array& dimensions, OpcUa_Boolean bDetach = OpcUa_False);
    OpcUa_StatusCode setUInt32Matrix(UaUInt32Array& val, const UaInt32Array& dimensions, OpcUa_Boolean bDetach = OpcUa_False);
    OpcUa_StatusCode setInt64Matrix(UaInt64Array& val, const UaInt32Array& dimensions, OpcUa_Boolean bDetach = OpcUa_False);
    OpcUa_StatusCode setUInt64Matrix(UaUInt64Array& val, const UaInt32Array& dimensions, OpcUa_Boolean bDetach = OpcUa_False);
    OpcUa_StatusCode setFloatMatrix(UaFloatArray& val, const UaInt32Array& dimensions, OpcUa_Boolean bDetach = OpcUa_False);
    OpcUa_StatusCode setDoubleMatrix(UaDoubleArray& val, const UaInt32Array& dimensions, OpcUa_Boolean bDetach = OpcUa_False);
    OpcUa_StatusCode setStringMatrix(UaStringArray& val, const UaInt32Array& dimensions, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setStringMatrix(const UaStringArray& val, const UaInt32Array& dimensions);
    OpcUa_StatusCode setDateTimeMatrix(UaDateTimeArray& val, const UaInt32Array& dimensions, OpcUa_Boolean bDetach = OpcUa_False);
    OpcUa_StatusCode setGuidMatrix(UaGuidArray& val, const UaInt32Array& dimensions, OpcUa_Boolean bDetach = OpcUa_False);
    OpcUa_StatusCode setByteStringMatrix(UaByteStringArray& val, const UaInt32Array& dimensions, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setByteStringMatrix(const UaByteStringArray& val, const UaInt32Array& dimensions);
    OpcUa_StatusCode setXmlElementMatrix(UaByteStringArray& val, const UaInt32Array& dimensions, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setXmlElementMatrix(const UaByteStringArray& val, const UaInt32Array& dimensions);
    OpcUa_StatusCode setNodeIdMatrix(UaNodeIdArray& val, const UaInt32Array& dimensions, OpcUa_Boolean bDetach = OpcUa_False);
    OpcUa_StatusCode setExpandedNodeIdMatrix(UaExpandedNodeIdArray& val, const UaInt32Array& dimensions, OpcUa_Boolean bDetach = OpcUa_False);
    OpcUa_StatusCode setStatusCodeMatrix(UaStatusCodeArray& val, const UaInt32Array& dimensions, OpcUa_Boolean bDetach = OpcUa_False);
    OpcUa_StatusCode setQualifiedNameMatrix(UaQualifiedNameArray& val, const UaInt32Array& dimensions, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setQualifiedNameMatrix(const UaQualifiedNameArray& val, const UaInt32Array& dimensions);
    OpcUa_StatusCode setLocalizedTextMatrix(UaLocalizedTextArray& val, const UaInt32Array& dimensions, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setLocalizedTextMatrix(const UaLocalizedTextArray& val, const UaInt32Array& dimensions);
    OpcUa_StatusCode setExtensionObjectMatrix(UaExtensionObjectArray& val, const UaInt32Array& dimensions, OpcUa_Boolean bDetach = OpcUa_False);
    OpcUa_StatusCode setVariantMatrix(UaVariantArray& val, const UaInt32Array& dimensions, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setVariantMatrix(const UaVariantArray& val, const UaInt32Array& dimensions);

    OpcUa_StatusCode toBool(OpcUa_Boolean& val) const;
    OpcUa_StatusCode toBoolean(OpcUa_Boolean& val) const;
    OpcUa_StatusCode toSByte(OpcUa_SByte& val) const;
    OpcUa_StatusCode toInt16(OpcUa_Int16& val) const;
    OpcUa_StatusCode toInt32(OpcUa_Int32& val) const;
    OpcUa_StatusCode toInt64(OpcUa_Int64& val) const;
    OpcUa_StatusCode toByte(OpcUa_Byte& val) const;
    OpcUa_StatusCode toUInt16(OpcUa_UInt16& val) const;
    OpcUa_StatusCode toUInt32(OpcUa_UInt32& val) const;
    OpcUa_StatusCode toUInt64(OpcUa_UInt64& val) const;
    OpcUa_StatusCode toFloat(OpcUa_Float& val) const;
    OpcUa_StatusCode toDouble(OpcUa_Double& val) const;
    OpcUa_StatusCode toDateTime(UaDateTime& val) const;
    OpcUa_StatusCode toGuid(UaGuid& val) const;
    OpcUa_StatusCode toByteString(UaByteString& val) const;
    OpcUa_StatusCode toXmlElement(UaByteString& val) const;
    OpcUa_StatusCode toNodeId(UaNodeId& val) const;
    OpcUa_StatusCode toExpandedNodeId(UaExpandedNodeId& val) const;
    OpcUa_StatusCode toStatusCode(OpcUa_StatusCode& val) const;
    OpcUa_StatusCode toQualifiedName(UaQualifiedName& val) const;
    OpcUa_StatusCode toLocalizedText(UaLocalizedText& val) const;
    OpcUa_StatusCode toExtensionObject(UaExtensionObject& val) const;
    OpcUa_StatusCode toDataValue(UaDataValue* pVal) const;

    OpcUa_StatusCode toBoolArray(UaBoolArray& val) const;
    OpcUa_StatusCode toByteArray(UaByteArray& val) const;
    OpcUa_StatusCode toSByteArray(UaSByteArray& val) const;
    OpcUa_StatusCode toInt16Array(UaInt16Array& val) const;
    OpcUa_StatusCode toUInt16Array(UaUInt16Array& val) const;
    OpcUa_StatusCode toInt32Array(UaInt32Array& val) const;
    OpcUa_StatusCode toUInt32Array(UaUInt32Array& val) const;
    OpcUa_StatusCode toInt64Array(UaInt64Array& val) const;
    OpcUa_StatusCode toUInt64Array(UaUInt64Array& val) const;
    OpcUa_StatusCode toFloatArray(UaFloatArray& val) const;
    OpcUa_StatusCode toDoubleArray(UaDoubleArray& val) const;
    OpcUa_StatusCode toStringArray(UaStringArray& val) const;
    OpcUa_StatusCode toDateTimeArray(UaDateTimeArray& val) const;
    OpcUa_StatusCode toGuidArray(UaGuidArray& val) const;
    OpcUa_StatusCode toByteStringArray(UaByteStringArray& val) const;
    OpcUa_StatusCode toXmlElementArray(UaByteStringArray& val) const;
    OpcUa_StatusCode toNodeIdArray(UaNodeIdArray& val) const;
    OpcUa_StatusCode toExpandedNodeIdArray(UaExpandedNodeIdArray& val) const;
    OpcUa_StatusCode toStatusCodeArray(UaStatusCodeArray& val) const;
    OpcUa_StatusCode toQualifiedNameArray(UaQualifiedNameArray& val) const;
    OpcUa_StatusCode toLocalizedTextArray(UaLocalizedTextArray& val) const;
    OpcUa_StatusCode toExtensionObjectArray(UaExtensionObjectArray& val) const;
    OpcUa_StatusCode toVariantArray(UaVariantArray& val) const;
    OpcUa_StatusCode toDataValueArray(UaDataValues& val) const;

    OpcUa_StatusCode toBoolMatrix(UaBoolArray& val, UaInt32Array& dimensions) const;
    OpcUa_StatusCode toSByteMatrix(UaSByteArray& val, UaInt32Array& dimensions) const;
    OpcUa_StatusCode toByteMatrix(UaByteArray& val, UaInt32Array& dimensions) const;
    OpcUa_StatusCode toInt16Matrix(UaInt16Array& val, UaInt32Array& dimensions) const;
    OpcUa_StatusCode toUInt16Matrix(UaUInt16Array& val, UaInt32Array& dimensions) const;
    OpcUa_StatusCode toInt32Matrix(UaInt32Array& val, UaInt32Array& dimensions) const;
    OpcUa_StatusCode toUInt32Matrix(UaUInt32Array& val, UaInt32Array& dimensions) const;
    OpcUa_StatusCode toInt64Matrix(UaInt64Array& val, UaInt32Array& dimensions) const;
    OpcUa_StatusCode toUInt64Matrix(UaUInt64Array& val, UaInt32Array& dimensions) const;
    OpcUa_StatusCode toFloatMatrix(UaFloatArray& val, UaInt32Array& dimensions) const;
    OpcUa_StatusCode toDoubleMatrix(UaDoubleArray& val, UaInt32Array& dimensions) const;
    OpcUa_StatusCode toStringMatrix(UaStringArray& val, UaInt32Array& dimensions) const;
    OpcUa_StatusCode toDateTimeMatrix(UaDateTimeArray& val, UaInt32Array& dimensions) const;
    OpcUa_StatusCode toGuidMatrix(UaGuidArray& val, UaInt32Array& dimensions) const;
    OpcUa_StatusCode toByteStringMatrix(UaByteStringArray& val, UaInt32Array& dimensions) const;
    OpcUa_StatusCode toXmlElementMatrix(UaByteStringArray& val, UaInt32Array& dimensions) const;
    OpcUa_StatusCode toNodeIdMatrix(UaNodeIdArray& val, UaInt32Array& dimensions) const;
    OpcUa_StatusCode toExpandedNodeIdMatrix(UaExpandedNodeIdArray& val, UaInt32Array& dimensions) const;
    OpcUa_StatusCode toStatusCodeMatrix(UaStatusCodeArray& val, UaInt32Array& dimensions) const;
    OpcUa_StatusCode toQualifiedNameMatrix(UaQualifiedNameArray& val, UaInt32Array& dimensions) const;
    OpcUa_StatusCode toLocalizedTextMatrix(UaLocalizedTextArray& val, UaInt32Array& dimensions) const;
    OpcUa_StatusCode toExtensionObjectMatrix(UaExtensionObjectArray& val, UaInt32Array& dimensions) const;
    OpcUa_StatusCode toVariantMatrix(UaVariantArray& val, UaInt32Array& dimensions) const;

    UaString toString() const;
    UaString toFullString() const;

private:
    static int variantSize(OpcUa_BuiltInType type);
    static int ms_variantsize[26];
    OpcUa_StatusCode getArrayElementsFromString(const OpcUa_String &string, UaStringArray &stringArray) const;
    OpcUa_StatusCode validateMatrixDimensions(OpcUa_UInt32 arrayLength, const UaInt32Array & dimensions) const;
    OpcUa_Variant m_value;

    friend UABASE_EXPORT UaDataStream &operator<<(UaDataStream &, const UaVariant &);
    friend UABASE_EXPORT UaDataStream &operator>>(UaDataStream &, UaVariant &);
};

// define UaDataStream operators for UaVariant.
UABASE_EXPORT UaDataStream &operator<<(UaDataStream &, const UaVariant &);
UABASE_EXPORT UaDataStream &operator>>(UaDataStream &, UaVariant &);

#ifdef _UA_WIN32
/** The UaVariantException class provides a base class
 *  for exceptions that can transferred across variants.
 *  @brief UaVariantException Class.
 */
class UaVariantException
{
public:
    /// @brief Enumeration of error definitions
    enum Error
    {
        UA_OVERFLOW = 0,        /*!< Overflow of data           */
        UA_INVALIDTYPE,         /*!< Type is invalid            */
        UA_INVALIDCONVERSION,   /*!< Conversion is invalid      */
        UA_NOTSUPPORTED         /*!< Operation not supported    */
    };
    UaVariantException(Error err)
    {
        error = err;
    }
    UaVariantException(Error err, UaString msg)
    {
        error = err;
        Message = msg;
    }
    UaString Message;
    Error    error;
};
#endif

/** A template definition for arrays of UaVariantObjects */
typedef UaObjectArray<UaVariant> UaVariantObjects;
/*! @} */

/* A union that contains one of the built in types.
typedef union _OpcUa_VariantUnion
{
    OpcUa_Boolean            Boolean;
    OpcUa_SByte              SByte;
    OpcUa_Byte               Byte;
    OpcUa_Int16              Int16;
    OpcUa_UInt16             UInt16;
    OpcUa_Int32              Int32;
    OpcUa_UInt32             UInt32;
    OpcUa_Int64              Int64;
    OpcUa_UInt64             UInt64;
    OpcUa_Float              Float;
    OpcUa_Double             Double;
    OpcUa_DateTime           DateTime;
    OpcUa_String             String;
    OpcUa_Guid*              Guid;
    OpcUa_ByteString         ByteString;
    OpcUa_XmlElement         XmlElement;
    OpcUa_NodeId*            NodeId;
    OpcUa_ExpandedNodeId*    ExpandedNodeId;
    OpcUa_StatusCode         StatusCode;
    OpcUa_QualifiedName*     QualifiedName;
    OpcUa_LocalizedText*     LocalizedText;
    OpcUa_ExtensionObject*   ExtensionObject;
    struct _OpcUa_DataValue* DataValue;
    OpcUa_VariantArrayValue  Array;
    OpcUa_VariantMatrixValue Matrix;
}
OpcUa_VariantUnion;

typedef struct _OpcUa_Variant
{
    OpcUa_Byte     Datatype;
    OpcUa_Boolean  IsArray;
    OpcUa_UInt16   Reserved;
    OpcUa_VariantUnion Value;
}
OpcUa_Variant;

typedef enum _OpcUa_BuiltInType
{
    OpcUaType_Null = 0,
    OpcUaType_Boolean = 1,
    OpcUaType_SByte = 2,
    OpcUaType_Byte = 3,
    OpcUaType_Int16 = 4,
    OpcUaType_UInt16 = 5,
    OpcUaType_Int32 = 6,
    OpcUaType_UInt32 = 7,
    OpcUaType_Int64 = 8,
    OpcUaType_UInt64 = 9,
    OpcUaType_Float = 10,
    OpcUaType_Double = 11,
    OpcUaType_String = 12,
    OpcUaType_DateTime = 13,
    OpcUaType_Guid = 14,
    OpcUaType_ByteString = 15,
    OpcUaType_XmlElement = 16,
    OpcUaType_NodeId = 17,
    OpcUaType_ExpandedNodeId = 18,
    OpcUaType_StatusCode = 19,
    OpcUaType_QualifiedName = 20,
    OpcUaType_LocalizedText = 21,
    OpcUaType_ExtensionObject = 22,
    OpcUaType_DataValue = 23,
    OpcUaType_Variant = 24,
    OpcUaType_DiagnosticInfo = 25
}
OpcUa_BuiltInType;

typedef struct _OpcUa_VariantArrayValue
{
    OpcUa_Int32 Length;

    union Value
    {
        OpcUa_Void*              Array;
        OpcUa_Boolean*           BooleanArray;
        OpcUa_SByte*             SByteArray;
        OpcUa_Int16*             Int16Array;
        OpcUa_UInt16*            UInt16Array;
        OpcUa_Int32*             Int32Array;
        OpcUa_UInt32*            UInt32Array;
        OpcUa_Int64*             Int64Array;
        OpcUa_UInt64*            UInt64Array;
        OpcUa_Float*             FloatArray;
        OpcUa_Double*            DoubleArray;
        OpcUa_String*            StringArray;
        OpcUa_DateTime*          DateTimeArray;
        OpcUa_Guid*              GuidArray;
        OpcUa_ByteString*        ByteStringArray;
        OpcUa_ByteString*        XmlElementArray;
        OpcUa_NodeId*            NodeIdArray;
        OpcUa_ExpandedNodeId*    ExpandedNodeIdArray;
        OpcUa_StatusCode*        StatusCodeArray;
        OpcUa_DiagnosticInfo*    DiagnosticInfoArray;
        OpcUa_QualifiedName*     QualifiedNameArray;
        OpcUa_LocalizedText*     LocalizedTextArray;
        OpcUa_ExtensionObject*   ExtensionObjectArray;
        struct _OpcUa_DataValue* DataValueArray;
        struct _OpcUa_Variant*   VariantArray;
    }
    Value;
}
OpcUa_VariantArrayValue;

    switch (m_value.Datatype)
    {
        case OpcUaType_Null:
        case OpcUaType_Boolean:
        case OpcUaType_SByte:
        case OpcUaType_Byte:
        case OpcUaType_Int16:
        case OpcUaType_UInt16:
        case OpcUaType_Int32:
        case OpcUaType_UInt32:
        case OpcUaType_Int64:
        case OpcUaType_UInt64:
        case OpcUaType_Float:
        case OpcUaType_Double:
        case OpcUaType_DateTime:
        case OpcUaType_Guid:
        case OpcUaType_StatusCode:
         case OpcUaType_String:
        case OpcUaType_ByteString:
        case OpcUaType_XmlElement:
        case OpcUaType_NodeId:
        case OpcUaType_ExpandedNodeId:
        case OpcUaType_DiagnosticInfo:
        case OpcUaType_QualifiedName:
        case OpcUaType_LocalizedText:
        case OpcUaType_ExtensionObject:
        case OpcUaType_DataValue:
        case OpcUaType_Variant:
        default:
        {
            break;
        }
    }
*/
#endif // UAVARIANT_H
