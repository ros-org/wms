/******************************************************************************
** opcuadi_datatypes.h
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

#ifndef __OPCUADI_DATATYPES_H__
#define __OPCUADI_DATATYPES_H__

#include <opcua_proxystub.h>
#include <opcua_builtintypes.h>
#include <opcua_exclusions.h>
#include <opcua_types.h>

#include "opcuadi_identifiers.h"

#define OPCUADI_EXTENSIONOBJECT_GET_ENCODEABLE(xExpectedType, xExtensionObject) \
    (OpcUaDi_##xExpectedType*)((((xExtensionObject)->Encoding == OpcUa_ExtensionObjectEncoding_EncodeableObject && \
    (xExtensionObject)->Body.EncodeableObject.Type != OpcUa_Null && \
    (xExtensionObject)->Body.EncodeableObject.Type->TypeId == OpcUaDiId_##xExpectedType && \
    OpcUa_StrCmpA((xExtensionObject)->Body.EncodeableObject.Type->NamespaceUri, "http://opcfoundation.org/UA/DI/") == 0 && \
    (xExtensionObject)->Body.EncodeableObject.Object != OpcUa_Null))?((xExtensionObject)->Body.EncodeableObject.Object):OpcUa_Null)


// Namespace for the UA information model http://opcfoundation.org/UA/DI/
namespace OpcUaDi {

#ifndef OPCUA_EXCLUDE_DeviceHealthEnumeration
/*============================================================================
 * The DeviceHealthEnumeration enumeration.
 *===========================================================================*/
enum DeviceHealthEnumeration
{
    DeviceHealthEnumeration_NORMAL = 0 /**<This device functions normally.*/,
    DeviceHealthEnumeration_FAILURE = 1 /**<Malfunction of the device or any of its peripherals.*/,
    DeviceHealthEnumeration_CHECK_FUNCTION = 2 /**<Functional checks are currently performed.*/,
    DeviceHealthEnumeration_OFF_SPEC = 3 /**<The device is currently working outside of its specified range or that internal diagnoses indicate deviations from measured or set values.*/,
    DeviceHealthEnumeration_MAINTENANCE_REQUIRED = 4 /**<This element is working, but a maintenance operation is required.*/
#if OPCUA_FORCE_INT32_ENUMS
    ,_DeviceHealthEnumeration_MaxEnumerationValue = OpcUa_Int32_Max
#endif
};

UAMODELS_EXPORT inline void DeviceHealthEnumeration_Clear(DeviceHealthEnumeration *pValue) {*pValue = DeviceHealthEnumeration_NORMAL;}

UAMODELS_EXPORT inline void DeviceHealthEnumeration_Initialize(DeviceHealthEnumeration *pValue) {*pValue = DeviceHealthEnumeration_NORMAL;}

UAMODELS_EXPORT extern struct ::_OpcUa_EnumeratedType DeviceHealthEnumeration_EnumeratedType;

#endif /*OPCUA_EXCLUDE_DeviceHealthEnumeration*/
}

#ifndef OPCUA_EXCLUDE_OpcUaDi_FetchResultDataDataType
/*============================================================================
 * The OpcUaDi_FetchResultDataDataType structure.
 *===========================================================================*/
typedef struct _OpcUaDi_FetchResultDataDataType
{
    OpcUa_Int32 SequenceNumber;
    OpcUa_Boolean EndOfResults;
    OpcUa_Int32 NoOfParameterDefs;
    struct _OpcUaDi_ParameterResultDataType* ParameterDefs;
} OpcUaDi_FetchResultDataDataType;

UAMODELS_EXPORT OpcUa_Void OpcUaDi_FetchResultDataDataType_Initialize(OpcUaDi_FetchResultDataDataType* pValue);

UAMODELS_EXPORT OpcUa_Void OpcUaDi_FetchResultDataDataType_Clear(OpcUaDi_FetchResultDataDataType* pValue);

UAMODELS_EXPORT OpcUa_StatusCode OpcUaDi_FetchResultDataDataType_GetSize(OpcUaDi_FetchResultDataDataType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

UAMODELS_EXPORT OpcUa_StatusCode OpcUaDi_FetchResultDataDataType_Encode(OpcUaDi_FetchResultDataDataType* pValue, struct _OpcUa_Encoder* pEncoder);

UAMODELS_EXPORT OpcUa_StatusCode OpcUaDi_FetchResultDataDataType_Decode(OpcUaDi_FetchResultDataDataType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
UAMODELS_EXPORT OpcUa_Int        OpcUaDi_FetchResultDataDataType_Compare(const OpcUaDi_FetchResultDataDataType* pValue1, const OpcUaDi_FetchResultDataDataType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
UAMODELS_EXPORT OpcUa_StatusCode OpcUaDi_FetchResultDataDataType_Copy(const OpcUaDi_FetchResultDataDataType* pSource, OpcUaDi_FetchResultDataDataType** ppCopy);

UAMODELS_EXPORT OpcUa_StatusCode OpcUaDi_FetchResultDataDataType_CopyTo(const OpcUaDi_FetchResultDataDataType* pSource, OpcUaDi_FetchResultDataDataType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

extern struct _OpcUa_EncodeableType OpcUaDi_FetchResultDataDataType_EncodeableType;
#endif /*OPCUA_EXCLUDE_OpcUaDi_FetchResultDataDataType*/

#ifndef OPCUA_EXCLUDE_OpcUaDi_FetchResultErrorDataType
/*============================================================================
 * The OpcUaDi_FetchResultErrorDataType structure.
 *===========================================================================*/
typedef struct _OpcUaDi_FetchResultErrorDataType
{
    OpcUa_Int32 Status;
    OpcUa_DiagnosticInfo Diagnostics;
} OpcUaDi_FetchResultErrorDataType;

UAMODELS_EXPORT OpcUa_Void OpcUaDi_FetchResultErrorDataType_Initialize(OpcUaDi_FetchResultErrorDataType* pValue);

UAMODELS_EXPORT OpcUa_Void OpcUaDi_FetchResultErrorDataType_Clear(OpcUaDi_FetchResultErrorDataType* pValue);

UAMODELS_EXPORT OpcUa_StatusCode OpcUaDi_FetchResultErrorDataType_GetSize(OpcUaDi_FetchResultErrorDataType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

UAMODELS_EXPORT OpcUa_StatusCode OpcUaDi_FetchResultErrorDataType_Encode(OpcUaDi_FetchResultErrorDataType* pValue, struct _OpcUa_Encoder* pEncoder);

UAMODELS_EXPORT OpcUa_StatusCode OpcUaDi_FetchResultErrorDataType_Decode(OpcUaDi_FetchResultErrorDataType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
UAMODELS_EXPORT OpcUa_Int        OpcUaDi_FetchResultErrorDataType_Compare(const OpcUaDi_FetchResultErrorDataType* pValue1, const OpcUaDi_FetchResultErrorDataType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
UAMODELS_EXPORT OpcUa_StatusCode OpcUaDi_FetchResultErrorDataType_Copy(const OpcUaDi_FetchResultErrorDataType* pSource, OpcUaDi_FetchResultErrorDataType** ppCopy);

UAMODELS_EXPORT OpcUa_StatusCode OpcUaDi_FetchResultErrorDataType_CopyTo(const OpcUaDi_FetchResultErrorDataType* pSource, OpcUaDi_FetchResultErrorDataType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

extern struct _OpcUa_EncodeableType OpcUaDi_FetchResultErrorDataType_EncodeableType;
#endif /*OPCUA_EXCLUDE_OpcUaDi_FetchResultErrorDataType*/

#ifndef OPCUA_EXCLUDE_OpcUaDi_ParameterResultDataType
/*============================================================================
 * The OpcUaDi_ParameterResultDataType structure.
 *===========================================================================*/
typedef struct _OpcUaDi_ParameterResultDataType
{
    OpcUa_Int32 NoOfNodePath;
    OpcUa_QualifiedName* NodePath;
    OpcUa_StatusCode StatusCode;
    OpcUa_DiagnosticInfo Diagnostics;
} OpcUaDi_ParameterResultDataType;

UAMODELS_EXPORT OpcUa_Void OpcUaDi_ParameterResultDataType_Initialize(OpcUaDi_ParameterResultDataType* pValue);

UAMODELS_EXPORT OpcUa_Void OpcUaDi_ParameterResultDataType_Clear(OpcUaDi_ParameterResultDataType* pValue);

UAMODELS_EXPORT OpcUa_StatusCode OpcUaDi_ParameterResultDataType_GetSize(OpcUaDi_ParameterResultDataType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

UAMODELS_EXPORT OpcUa_StatusCode OpcUaDi_ParameterResultDataType_Encode(OpcUaDi_ParameterResultDataType* pValue, struct _OpcUa_Encoder* pEncoder);

UAMODELS_EXPORT OpcUa_StatusCode OpcUaDi_ParameterResultDataType_Decode(OpcUaDi_ParameterResultDataType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
UAMODELS_EXPORT OpcUa_Int        OpcUaDi_ParameterResultDataType_Compare(const OpcUaDi_ParameterResultDataType* pValue1, const OpcUaDi_ParameterResultDataType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
UAMODELS_EXPORT OpcUa_StatusCode OpcUaDi_ParameterResultDataType_Copy(const OpcUaDi_ParameterResultDataType* pSource, OpcUaDi_ParameterResultDataType** ppCopy);

UAMODELS_EXPORT OpcUa_StatusCode OpcUaDi_ParameterResultDataType_CopyTo(const OpcUaDi_ParameterResultDataType* pSource, OpcUaDi_ParameterResultDataType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

extern struct _OpcUa_EncodeableType OpcUaDi_ParameterResultDataType_EncodeableType;
#endif /*OPCUA_EXCLUDE_OpcUaDi_ParameterResultDataType*/


/*============================================================================
 * Table of known types.
 *===========================================================================*/
extern struct _OpcUa_EncodeableType** OpcUaDi_KnownEncodeableTypes;

/*============================================================================
 * Register known types.
 *===========================================================================*/
namespace OpcUaDi
{
    /** Class used to handle data type registration
    */
    class DataTypes
    {
    public:
        static void registerStructuredTypes();
    private:
        static bool s_dataTypesAdded;
    };
}

#endif // __OPCUADI_DATATYPES_H__

