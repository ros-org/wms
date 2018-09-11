/******************************************************************************
** opcuagds_datatypes.h
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
** Project: C++ OPC Server SDK information model for namespace http://opcfoundation.org/UA/GDS/
**
** Description: OPC Unified Architecture Software Development Kit.
**
******************************************************************************/

#ifndef __OPCUAGDS_DATATYPES_H__
#define __OPCUAGDS_DATATYPES_H__

#include <opcua_proxystub.h>
#include <opcua_builtintypes.h>
#include <opcua_exclusions.h>
#include <opcua_types.h>

#include "opcuagds_identifiers.h"
#include "uaplatformdefs.h"

#define OPCUAGDS_EXTENSIONOBJECT_GET_ENCODEABLE(xExpectedType, xExtensionObject) \
    (OpcUaGds_##xExpectedType*)((((xExtensionObject)->Encoding == OpcUa_ExtensionObjectEncoding_EncodeableObject && \
    (xExtensionObject)->Body.EncodeableObject.Type != OpcUa_Null && \
    (xExtensionObject)->Body.EncodeableObject.Type->TypeId == OpcUaGdsId_##xExpectedType && \
    OpcUa_StrCmpA((xExtensionObject)->Body.EncodeableObject.Type->NamespaceUri, "http://opcfoundation.org/UA/GDS/") == 0 && \
    (xExtensionObject)->Body.EncodeableObject.Object != OpcUa_Null))?((xExtensionObject)->Body.EncodeableObject.Object):OpcUa_Null)


// Namespace for the UA information model http://opcfoundation.org/UA/GDS/
namespace OpcUaGds {

}

#ifndef OPCUA_EXCLUDE_OpcUaGds_ApplicationRecordDataType
/*============================================================================
 * The OpcUaGds_ApplicationRecordDataType structure.
 *===========================================================================*/
typedef struct _OpcUaGds_ApplicationRecordDataType
{
    OpcUa_NodeId ApplicationId;
    OpcUa_String ApplicationUri;
    OpcUa_ApplicationType ApplicationType;
    OpcUa_Int32 NoOfApplicationNames;
    OpcUa_LocalizedText* ApplicationNames;
    OpcUa_String ProductUri;
    OpcUa_Int32 NoOfDiscoveryUrls;
    OpcUa_String* DiscoveryUrls;
    OpcUa_Int32 NoOfServerCapabilities;
    OpcUa_String* ServerCapabilities;
} OpcUaGds_ApplicationRecordDataType;

UABASE_EXPORT OpcUa_Void OpcUaGds_ApplicationRecordDataType_Initialize(OpcUaGds_ApplicationRecordDataType* pValue);

UABASE_EXPORT OpcUa_Void OpcUaGds_ApplicationRecordDataType_Clear(OpcUaGds_ApplicationRecordDataType* pValue);

UABASE_EXPORT OpcUa_StatusCode OpcUaGds_ApplicationRecordDataType_GetSize(OpcUaGds_ApplicationRecordDataType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

UABASE_EXPORT OpcUa_StatusCode OpcUaGds_ApplicationRecordDataType_Encode(OpcUaGds_ApplicationRecordDataType* pValue, struct _OpcUa_Encoder* pEncoder);

UABASE_EXPORT OpcUa_StatusCode OpcUaGds_ApplicationRecordDataType_Decode(OpcUaGds_ApplicationRecordDataType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
UABASE_EXPORT OpcUa_Int        OpcUaGds_ApplicationRecordDataType_Compare(const OpcUaGds_ApplicationRecordDataType* pValue1, const OpcUaGds_ApplicationRecordDataType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
UABASE_EXPORT OpcUa_StatusCode OpcUaGds_ApplicationRecordDataType_Copy(const OpcUaGds_ApplicationRecordDataType* pSource, OpcUaGds_ApplicationRecordDataType** ppCopy);

UABASE_EXPORT OpcUa_StatusCode OpcUaGds_ApplicationRecordDataType_CopyTo(const OpcUaGds_ApplicationRecordDataType* pSource, OpcUaGds_ApplicationRecordDataType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

extern struct _OpcUa_EncodeableType OpcUaGds_ApplicationRecordDataType_EncodeableType;
#endif /*OPCUA_EXCLUDE_OpcUaGds_ApplicationRecordDataType*/


/*============================================================================
 * Table of known types.
 *===========================================================================*/
extern struct _OpcUa_EncodeableType** OpcUaGds_KnownEncodeableTypes;

/*============================================================================
 * Register known types.
 *===========================================================================*/
namespace OpcUaGds
{
    /** Class used to handle data type registration
    */
    class DataTypes
    {
    public:
        static UABASE_EXPORT void registerStructuredTypes();
    private:
        static bool s_dataTypesAdded;
    };
}

#endif // __OPCUAGDS_DATATYPES_H__

