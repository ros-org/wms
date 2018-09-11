/*****************************************************************************
 *                                                                           *
 * Copyright (c) 2006-2016 Unified Automation GmbH. All rights reserved.     *
 *                                                                           *
 * Software License Agreement ("SLA") Version 2.5                            *
 *                                                                           *
 * Unless explicitly acquired and licensed from Licensor under another       *
 * license, the contents of this file are subject to the Software License    *
 * Agreement ("SLA") Version 2.5, or subsequent versions as allowed by the   *
 * SLA, and You may not copy or use this file in either source code or       *
 * executable form, except in compliance with the terms and conditions of    *
 * the SLA.                                                                  *
 *                                                                           *
 * All software distributed under the SLA is provided strictly on an "AS     *
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,       *
 * AND LICENSOR HEREBY DISCLAIMS ALL SUCH WARRANTIES, INCLUDING WITHOUT      *
 * LIMITATION, ANY WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR   *
 * PURPOSE, QUIET ENJOYMENT, OR NON-INFRINGEMENT. See the SLA for specific   *
 * language governing rights and limitations under the SLA.                  *
 *                                                                           *
 * The complete license agreement can be found here:                         *
 * http://unifiedautomation.com/License/SLA/2.5/                             *
 *                                                                           *
 * Project: Unified Automation OPC UA ANSI C Communication Stack             *
 *                                                                           *
 * This software is based in part on the ANSI C Stack of the OPC Foundation. *
 * Initial version of the ANSI C Stack was founded and copyrighted by OPC    *
 * Foundation, Inc.                                                          *
 * Copyright (C) 2008, 2014 OPC Foundation, Inc., All Rights Reserved.       *
 *****************************************************************************/
/** \defgroup UaStackTypes */
/* @{*/

#ifndef _OpcUa_Types_H_
#define _OpcUa_Types_H_ 1

#ifndef OPCUA_FORCE_INT32_ENUMS
# error OPCUA_FORCE_INT32_ENUMS must be defined!
#endif /* OPCUA_FORCE_INT32_ENUMS */

#include <opcua_builtintypes.h>
#include <opcua_exclusions.h>

OPCUA_BEGIN_EXTERN_C

struct _OpcUa_Encoder;
struct _OpcUa_Decoder;
struct _OpcUa_EncodeableType;
struct _OpcUa_EnumeratedType;

#ifndef OPCUA_EXCLUDE_NodeIdType
/*============================================================================
 * The NodeIdType enumeration.
 *===========================================================================*/
/** \enum OpcUa_NodeIdType
 *  The possible encodings for a NodeId value.
 */
typedef enum _OpcUa_NodeIdType
{
    OpcUa_NodeIdType_TwoByte    = 0,
    OpcUa_NodeIdType_FourByte   = 1,
    OpcUa_NodeIdType_Numeric    = 2,
    OpcUa_NodeIdType_String     = 3,
    OpcUa_NodeIdType_Guid       = 4,
    OpcUa_NodeIdType_ByteString = 5
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_NodeIdType_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_NodeIdType;

#define OpcUa_NodeIdType_Clear(xValue) *(xValue) = OpcUa_NodeIdType_TwoByte

#define OpcUa_NodeIdType_Initialize(xValue) *(xValue) = OpcUa_NodeIdType_TwoByte

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_NodeIdType_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_NamingRuleType
/*============================================================================
 * The NamingRuleType enumeration.
 *===========================================================================*/
/** \enum OpcUa_NamingRuleType
 *  This data type is an enumeration that identifies the NamingRule.
 */
typedef enum _OpcUa_NamingRuleType
{
    OpcUa_NamingRuleType_Mandatory  = 1,
    OpcUa_NamingRuleType_Optional   = 2,
    OpcUa_NamingRuleType_Constraint = 3
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_NamingRuleType_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_NamingRuleType;

#define OpcUa_NamingRuleType_Clear(xValue) *(xValue) = OpcUa_NamingRuleType_Mandatory

#define OpcUa_NamingRuleType_Initialize(xValue) *(xValue) = OpcUa_NamingRuleType_Mandatory

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_NamingRuleType_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_OpenFileMode
/*============================================================================
 * The OpenFileMode enumeration.
 *===========================================================================*/
typedef enum _OpcUa_OpenFileMode
{
    OpcUa_OpenFileMode_Read          = 1,
    OpcUa_OpenFileMode_Write         = 2,
    OpcUa_OpenFileMode_EraseExisting = 4,
    OpcUa_OpenFileMode_Append        = 8
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_OpenFileMode_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_OpenFileMode;

#define OpcUa_OpenFileMode_Clear(xValue) *(xValue) = OpcUa_OpenFileMode_Read

#define OpcUa_OpenFileMode_Initialize(xValue) *(xValue) = OpcUa_OpenFileMode_Read

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_OpenFileMode_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_TrustListMasks
/*============================================================================
 * The TrustListMasks enumeration.
 *===========================================================================*/
/** \enum OpcUa_TrustListMasks
 *  Defines the values used for the SpecifiedLists field in the TrustListDataType.
 *
 *  \var OpcUa_TrustListMasks_None
 *  No fields are provided.
 *
 *  \var OpcUa_TrustListMasks_TrustedCertificates
 *  The TrustedCertificates are provided.
 *
 *  \var OpcUa_TrustListMasks_TrustedCrls
 *  The TrustedCrls are provided.
 *
 *  \var OpcUa_TrustListMasks_IssuerCertificates
 *  The IssuerCertificates are provided.
 *
 *  \var OpcUa_TrustListMasks_IssuerCrls
 *  The IssuerCrls are provided.
 *
 *  \var OpcUa_TrustListMasks_All
 *  All fields are provided.
 */
typedef enum _OpcUa_TrustListMasks
{
    OpcUa_TrustListMasks_None                = 0,
    OpcUa_TrustListMasks_TrustedCertificates = 1,
    OpcUa_TrustListMasks_TrustedCrls         = 2,
    OpcUa_TrustListMasks_IssuerCertificates  = 4,
    OpcUa_TrustListMasks_IssuerCrls          = 8,
    OpcUa_TrustListMasks_All                 = 15
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_TrustListMasks_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_TrustListMasks;

#define OpcUa_TrustListMasks_Clear(xValue) *(xValue) = OpcUa_TrustListMasks_None

#define OpcUa_TrustListMasks_Initialize(xValue) *(xValue) = OpcUa_TrustListMasks_None

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_TrustListMasks_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_IdType
/*============================================================================
 * The IdType enumeration.
 *===========================================================================*/
/** \enum OpcUa_IdType
 *  An enumeration that identifies the IdType of a NodeId.
 *
 *  \var OpcUa_IdType_Numeric
 *  Numeric value
 *
 *  \var OpcUa_IdType_String
 *  String value
 *
 *  \var OpcUa_IdType_Guid
 *  Globally Unique Identifier
 *
 *  \var OpcUa_IdType_Opaque
 *  Namespace specific format
 */
typedef enum _OpcUa_IdType
{
    OpcUa_IdType_Numeric = 0,
    OpcUa_IdType_String  = 1,
    OpcUa_IdType_Guid    = 2,
    OpcUa_IdType_Opaque  = 3
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_IdType_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_IdType;

#define OpcUa_IdType_Clear(xValue) *(xValue) = OpcUa_IdType_Numeric

#define OpcUa_IdType_Initialize(xValue) *(xValue) = OpcUa_IdType_Numeric

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_IdType_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_NodeClass
/*============================================================================
 * The NodeClass enumeration.
 *===========================================================================*/
/** \enum OpcUa_NodeClass
 *  An enumeration that identifies a NodeClass.
 */
typedef enum _OpcUa_NodeClass
{
    OpcUa_NodeClass_Unspecified   = 0,
    OpcUa_NodeClass_Object        = 1,
    OpcUa_NodeClass_Variable      = 2,
    OpcUa_NodeClass_Method        = 4,
    OpcUa_NodeClass_ObjectType    = 8,
    OpcUa_NodeClass_VariableType  = 16,
    OpcUa_NodeClass_ReferenceType = 32,
    OpcUa_NodeClass_DataType      = 64,
    OpcUa_NodeClass_View          = 128
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_NodeClass_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_NodeClass;

#define OpcUa_NodeClass_Clear(xValue) *(xValue) = OpcUa_NodeClass_Unspecified

#define OpcUa_NodeClass_Initialize(xValue) *(xValue) = OpcUa_NodeClass_Unspecified

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_NodeClass_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_ApplicationType
/*============================================================================
 * The ApplicationType enumeration.
 *===========================================================================*/
/** \enum OpcUa_ApplicationType
 *  The type of application
 *
 *  \var OpcUa_ApplicationType_Server
 *  The application is a Server.
 *
 *  \var OpcUa_ApplicationType_Client
 *  The application is a Client.
 *
 *  \var OpcUa_ApplicationType_ClientAndServer
 *  The application is a Client and a Server.
 *
 *  \var OpcUa_ApplicationType_DiscoveryServer
 *  The application is a DiscoveryServer.
 */
typedef enum _OpcUa_ApplicationType
{
    OpcUa_ApplicationType_Server          = 0,
    OpcUa_ApplicationType_Client          = 1,
    OpcUa_ApplicationType_ClientAndServer = 2,
    OpcUa_ApplicationType_DiscoveryServer = 3
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_ApplicationType_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_ApplicationType;

#define OpcUa_ApplicationType_Clear(xValue) *(xValue) = OpcUa_ApplicationType_Server

#define OpcUa_ApplicationType_Initialize(xValue) *(xValue) = OpcUa_ApplicationType_Server

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_ApplicationType_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_MessageSecurityMode
/*============================================================================
 * The MessageSecurityMode enumeration.
 *===========================================================================*/
/** \enum OpcUa_MessageSecurityMode
 *  An enumeration that specifies what security should be applied to messages
 *  exchanges during a Session.
 *
 *  \var OpcUa_MessageSecurityMode_Invalid
 *  The MessageSecurityMode is invalid.
 *
 *  This value is the default value to avoid an accidental choice of no security is
 *  applied. This choice will always be rejected.
 *
 *  \var OpcUa_MessageSecurityMode_None
 *  No security is applied.
 *
 *  \var OpcUa_MessageSecurityMode_Sign
 *  All messages are signed but not encrypted.
 *
 *  \var OpcUa_MessageSecurityMode_SignAndEncrypt
 *  All messages are signed and encrypted.
 */
typedef enum _OpcUa_MessageSecurityMode
{
    OpcUa_MessageSecurityMode_Invalid        = 0,
    OpcUa_MessageSecurityMode_None           = 1,
    OpcUa_MessageSecurityMode_Sign           = 2,
    OpcUa_MessageSecurityMode_SignAndEncrypt = 3
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_MessageSecurityMode_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_MessageSecurityMode;

#define OpcUa_MessageSecurityMode_Clear(xValue) *(xValue) = OpcUa_MessageSecurityMode_Invalid

#define OpcUa_MessageSecurityMode_Initialize(xValue) *(xValue) = OpcUa_MessageSecurityMode_Invalid

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_MessageSecurityMode_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_UserTokenType
/*============================================================================
 * The UserTokenType enumeration.
 *===========================================================================*/
/** \enum OpcUa_UserTokenType
 *  The type of user identity token required.
 *
 *  \var OpcUa_UserTokenType_Anonymous
 *  No token is required.
 *
 *  \var OpcUa_UserTokenType_UserName
 *  A username/password token.
 *
 *  \var OpcUa_UserTokenType_Certificate
 *  An X509v3 Certificate token.
 *
 *  \var OpcUa_UserTokenType_IssuedToken
 *  Any WS-Security defined token.
 */
typedef enum _OpcUa_UserTokenType
{
    OpcUa_UserTokenType_Anonymous   = 0,
    OpcUa_UserTokenType_UserName    = 1,
    OpcUa_UserTokenType_Certificate = 2,
    OpcUa_UserTokenType_IssuedToken = 3,
    OpcUa_UserTokenType_Kerberos    = 4
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_UserTokenType_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_UserTokenType;

#define OpcUa_UserTokenType_Clear(xValue) *(xValue) = OpcUa_UserTokenType_Anonymous

#define OpcUa_UserTokenType_Initialize(xValue) *(xValue) = OpcUa_UserTokenType_Anonymous

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_UserTokenType_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_SecurityTokenRequestType
/*============================================================================
 * The SecurityTokenRequestType enumeration.
 *===========================================================================*/
/** \enum OpcUa_SecurityTokenRequestType
 *  An enumeration that is defined as the type of the requestType parameter of the
 *  OpenSecureChannel request.
 *
 *  \var OpcUa_SecurityTokenRequestType_Issue
 *  Creates a new security token for a new secure channel.
 *
 *  \var OpcUa_SecurityTokenRequestType_Renew
 *  Creates a new security token for an existing secure channel.
 */
typedef enum _OpcUa_SecurityTokenRequestType
{
    OpcUa_SecurityTokenRequestType_Issue = 0,
    OpcUa_SecurityTokenRequestType_Renew = 1
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_SecurityTokenRequestType_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_SecurityTokenRequestType;

#define OpcUa_SecurityTokenRequestType_Clear(xValue) *(xValue) = OpcUa_SecurityTokenRequestType_Issue

#define OpcUa_SecurityTokenRequestType_Initialize(xValue) *(xValue) = OpcUa_SecurityTokenRequestType_Issue

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_SecurityTokenRequestType_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_NodeAttributesMask
/*============================================================================
 * The NodeAttributesMask enumeration.
 *===========================================================================*/
/** \enum OpcUa_NodeAttributesMask
The bits used to specify default attributes for a new node.
 */
typedef enum _OpcUa_NodeAttributesMask
{
    OpcUa_NodeAttributesMask_None                    = 0,
    OpcUa_NodeAttributesMask_AccessLevel             = 1,
    OpcUa_NodeAttributesMask_ArrayDimensions         = 2,
    OpcUa_NodeAttributesMask_BrowseName              = 4,
    OpcUa_NodeAttributesMask_ContainsNoLoops         = 8,
    OpcUa_NodeAttributesMask_DataType                = 16,
    OpcUa_NodeAttributesMask_Description             = 32,
    OpcUa_NodeAttributesMask_DisplayName             = 64,
    OpcUa_NodeAttributesMask_EventNotifier           = 128,
    OpcUa_NodeAttributesMask_Executable              = 256,
    OpcUa_NodeAttributesMask_Historizing             = 512,
    OpcUa_NodeAttributesMask_InverseName             = 1024,
    OpcUa_NodeAttributesMask_IsAbstract              = 2048,
    OpcUa_NodeAttributesMask_MinimumSamplingInterval = 4096,
    OpcUa_NodeAttributesMask_NodeClass               = 8192,
    OpcUa_NodeAttributesMask_NodeId                  = 16384,
    OpcUa_NodeAttributesMask_Symmetric               = 32768,
    OpcUa_NodeAttributesMask_UserAccessLevel         = 65536,
    OpcUa_NodeAttributesMask_UserExecutable          = 131072,
    OpcUa_NodeAttributesMask_UserWriteMask           = 262144,
    OpcUa_NodeAttributesMask_ValueRank               = 524288,
    OpcUa_NodeAttributesMask_WriteMask               = 1048576,
    OpcUa_NodeAttributesMask_Value                   = 2097152,
    OpcUa_NodeAttributesMask_All                     = 4194303,
    OpcUa_NodeAttributesMask_BaseNode                = 1335396,
    OpcUa_NodeAttributesMask_Object                  = 1335524,
    OpcUa_NodeAttributesMask_ObjectTypeOrDataType    = 1337444,
    OpcUa_NodeAttributesMask_Variable                = 4026999,
    OpcUa_NodeAttributesMask_VariableType            = 3958902,
    OpcUa_NodeAttributesMask_Method                  = 1466724,
    OpcUa_NodeAttributesMask_ReferenceType           = 1371236,
    OpcUa_NodeAttributesMask_View                    = 1335532
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_NodeAttributesMask_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_NodeAttributesMask;

#define OpcUa_NodeAttributesMask_Clear(xValue) *(xValue) = OpcUa_NodeAttributesMask_None

#define OpcUa_NodeAttributesMask_Initialize(xValue) *(xValue) = OpcUa_NodeAttributesMask_None

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_NodeAttributesMask_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_AttributeWriteMask
/*============================================================================
 * The AttributeWriteMask enumeration.
 *===========================================================================*/
/** \enum OpcUa_AttributeWriteMask
Define bits used to indicate which attributes are writable.
 */
typedef enum _OpcUa_AttributeWriteMask
{
    OpcUa_AttributeWriteMask_None                    = 0,
    OpcUa_AttributeWriteMask_AccessLevel             = 1,
    OpcUa_AttributeWriteMask_ArrayDimensions         = 2,
    OpcUa_AttributeWriteMask_BrowseName              = 4,
    OpcUa_AttributeWriteMask_ContainsNoLoops         = 8,
    OpcUa_AttributeWriteMask_DataType                = 16,
    OpcUa_AttributeWriteMask_Description             = 32,
    OpcUa_AttributeWriteMask_DisplayName             = 64,
    OpcUa_AttributeWriteMask_EventNotifier           = 128,
    OpcUa_AttributeWriteMask_Executable              = 256,
    OpcUa_AttributeWriteMask_Historizing             = 512,
    OpcUa_AttributeWriteMask_InverseName             = 1024,
    OpcUa_AttributeWriteMask_IsAbstract              = 2048,
    OpcUa_AttributeWriteMask_MinimumSamplingInterval = 4096,
    OpcUa_AttributeWriteMask_NodeClass               = 8192,
    OpcUa_AttributeWriteMask_NodeId                  = 16384,
    OpcUa_AttributeWriteMask_Symmetric               = 32768,
    OpcUa_AttributeWriteMask_UserAccessLevel         = 65536,
    OpcUa_AttributeWriteMask_UserExecutable          = 131072,
    OpcUa_AttributeWriteMask_UserWriteMask           = 262144,
    OpcUa_AttributeWriteMask_ValueRank               = 524288,
    OpcUa_AttributeWriteMask_WriteMask               = 1048576,
    OpcUa_AttributeWriteMask_ValueForVariableType    = 2097152
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_AttributeWriteMask_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_AttributeWriteMask;

#define OpcUa_AttributeWriteMask_Clear(xValue) *(xValue) = OpcUa_AttributeWriteMask_None

#define OpcUa_AttributeWriteMask_Initialize(xValue) *(xValue) = OpcUa_AttributeWriteMask_None

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_AttributeWriteMask_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_BrowseDirection
/*============================================================================
 * The BrowseDirection enumeration.
 *===========================================================================*/
/** \enum OpcUa_BrowseDirection
 *  An enumeration that specifies the direction of References to follow.
 *
 *  \var OpcUa_BrowseDirection_Forward
 *  select only forward References
 *
 *  \var OpcUa_BrowseDirection_Inverse
 *  select only inverse References
 *
 *  \var OpcUa_BrowseDirection_Both
 *  select forward and inverse References
 */
typedef enum _OpcUa_BrowseDirection
{
    OpcUa_BrowseDirection_Forward = 0,
    OpcUa_BrowseDirection_Inverse = 1,
    OpcUa_BrowseDirection_Both    = 2
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_BrowseDirection_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_BrowseDirection;

#define OpcUa_BrowseDirection_Clear(xValue) *(xValue) = OpcUa_BrowseDirection_Forward

#define OpcUa_BrowseDirection_Initialize(xValue) *(xValue) = OpcUa_BrowseDirection_Forward

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_BrowseDirection_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_BrowseResultMask
/*============================================================================
 * The BrowseResultMask enumeration.
 *===========================================================================*/
/** \enum OpcUa_BrowseResultMask
A bit mask which specifies what should be returned in a browse response.
 */
typedef enum _OpcUa_BrowseResultMask
{
    OpcUa_BrowseResultMask_None              = 0,
    OpcUa_BrowseResultMask_ReferenceTypeId   = 1,
    OpcUa_BrowseResultMask_IsForward         = 2,
    OpcUa_BrowseResultMask_NodeClass         = 4,
    OpcUa_BrowseResultMask_BrowseName        = 8,
    OpcUa_BrowseResultMask_DisplayName       = 16,
    OpcUa_BrowseResultMask_TypeDefinition    = 32,
    OpcUa_BrowseResultMask_All               = 63,
    OpcUa_BrowseResultMask_ReferenceTypeInfo = 3,
    OpcUa_BrowseResultMask_TargetInfo        = 60
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_BrowseResultMask_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_BrowseResultMask;

#define OpcUa_BrowseResultMask_Clear(xValue) *(xValue) = OpcUa_BrowseResultMask_None

#define OpcUa_BrowseResultMask_Initialize(xValue) *(xValue) = OpcUa_BrowseResultMask_None

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_BrowseResultMask_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_ComplianceLevel
/*============================================================================
 * The ComplianceLevel enumeration.
 *===========================================================================*/
/** \enum OpcUa_ComplianceLevel
 *  Specifies the compliance level of the profile.
 *
 *  \var OpcUa_ComplianceLevel_Untested
 *  The profiled capability has not been tested successfully
 *
 *  \var OpcUa_ComplianceLevel_Partial
 *  The profiled capability has been partially tested and has passed critical
 *  tests, as defined by the certifying authority.
 *
 *  \var OpcUa_ComplianceLevel_SelfTested
 *  The profiled capability has been successfully tested using a self-test system
 *  authorized by the certifying authority.
 *
 *  \var OpcUa_ComplianceLevel_Certified
 *  The profiled capability has been successfully tested by a testing organisation
 *  authorized by the certifying authority.
 */
typedef enum _OpcUa_ComplianceLevel
{
    OpcUa_ComplianceLevel_Untested   = 0,
    OpcUa_ComplianceLevel_Partial    = 1,
    OpcUa_ComplianceLevel_SelfTested = 2,
    OpcUa_ComplianceLevel_Certified  = 3
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_ComplianceLevel_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_ComplianceLevel;

#define OpcUa_ComplianceLevel_Clear(xValue) *(xValue) = OpcUa_ComplianceLevel_Untested

#define OpcUa_ComplianceLevel_Initialize(xValue) *(xValue) = OpcUa_ComplianceLevel_Untested

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_ComplianceLevel_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_FilterOperator
/*============================================================================
 * The FilterOperator enumeration.
 *===========================================================================*/
/** \enum OpcUa_FilterOperator
 *  Defines the basic operators that can be used in a ContentFilter.
 *
 *  \var OpcUa_FilterOperator_Equals
 *  TRUE if operand[0] is equal to operand[1].
 *
 *  If the operands are of different types, the system shall perform any implicit
 *  conversion to a common type. This operator resolves to FALSE if no implicit
 *  conversion is available and the operands are of different types. This operator
 *  returns FALSE if the implicit conversion fails.
 *
 *  \var OpcUa_FilterOperator_IsNull
 *  TRUE if operand[0] is a null value.
 *
 *  \var OpcUa_FilterOperator_GreaterThan
 *  TRUE if operand[0] is greater than operand[1].
 *
 *  The following restrictions apply to the operands: <dl> <dt>[0]</dt><dd>Any
 *  operand that resolves to an ordered value.</dd> <dt>[1]</dt><dd>Any operand
 *  that resolves to an ordered value.</dd> </dl>
 *
 *  The same conversion rules as defined for Equals apply.
 *
 *  \var OpcUa_FilterOperator_LessThan
 *  TRUE if operand[0] is less than operand[1].
 *
 *  The same conversion rules and restrictions as defined for GreaterThan apply.
 *
 *  \var OpcUa_FilterOperator_GreaterThanOrEqual
 *  TRUE if operand[0] is greater than or equal to operand[1].
 *
 *  The same conversion rules and restrictions as defined for GreaterThan apply.
 *
 *  \var OpcUa_FilterOperator_LessThanOrEqual
 *  TRUE if operand[0] is less than or equal to operand[1].
 *
 *  The same conversion rules and restrictions as defined for GreaterThan apply.
 *
 *  \var OpcUa_FilterOperator_Like
 *  TRUE if operand[0] matches a pattern defined by operand[1].
 *
 *  The following restrictions apply to the operands: <dl> <dt>[0]</dt><dd>Any
 *  operand that resolves to a String.</dd> <dt>[1]</dt><dd>Any operand that
 *  resolves to a String.</dd> </dl>
 *
 *  This operator resolves to FALSE if no operand can be resolved to a string.
 *
 *  \var OpcUa_FilterOperator_Not
 *  TRUE if operand[0] is FALSE.
 *
 *  The following restrictions apply to the operands: <dl> <dt>[0]</dt><dd>Any
 *  operand that resolves to a Boolean.</dd> </dl>
 *
 *  If the operand cannot be resolved to a Boolean, the result is a NULL.
 *
 *  \var OpcUa_FilterOperator_Between
 *  TRUE if operand[0] is greater or equal to operand[1] and less than or equal to
 *  operand[2].
 *
 *  The following restrictions apply to the operands: <dl> <dt>[0]</dt><dd>Any
 *  operand that resolves to an ordered value.</dd> <dt>[1]</dt><dd>Any operand
 *  that resolves to an ordered value.</dd> <dt>[0]</dt><dd>Any operand that
 *  resolves to an ordered value.</dd> </dl>
 *
 *  If the operands are of different types, the system shall perform any implicit
 *  conversion to match all operands to a common type. If no implicit conversion is
 *  available and the operands are of different types, the particular result is
 *  FALSE.
 *
 *  \var OpcUa_FilterOperator_InList
 *  TRUE if operand[0] is equal to one or more of the remaining operands.
 *
 *  The Equals Operator is evaluated for operand[0] and each remaining operand in
 *  the list. If any Equals evaluation is TRUE, InList returns TRUE.
 *
 *  \var OpcUa_FilterOperator_And
 *  TRUE if operand[0] and operand[1] are TRUE.
 *
 *  The following restrictions apply to the operands: <dl> <dt>[0]</dt><dd>Any
 *  operand that resolves to a Boolean.</dd> <dt>[0]</dt><dd>Any operand that
 *  resolves to a Boolean.</dd> </dl>
 *
 *  If any operand cannot be resolved to a Boolean it is considered a NULL.
 *
 *  \var OpcUa_FilterOperator_Or
 *  TRUE if operand[0] or operand[1] are TRUE.
 *
 *  The following restrictions apply to the operands: <dl> <dt>[0]</dt><dd>Any
 *  operand that resolves to a Boolean.</dd> <dt>[0]</dt><dd>Any operand that
 *  resolves to a Boolean.</dd> </dl>
 *
 *  If any operand cannot be resolved to a Boolean it is considered a NULL.
 *
 *  \var OpcUa_FilterOperator_Cast
 *  Converts operand[0] to a value with a data type with a NodeId identified by
 *  operand[1].
 *
 *  The following restrictions apply to the operands:
 *
 *  <dl> <dt>[0]</dt><dd>Any operand.</dd> <dt>[1]</dt><dd>Any operand that
 *  resolves to a NodeId or ExpandedNodeId where the Node is of the NodeClass
 *  DataType.</dd> </dl>
 *
 *  If there is any error in conversion or in any of the parameters then the Cast
 *  Operation evaluates to a NULL.
 *
 *  \var OpcUa_FilterOperator_InView
 *  TRUE if the target Node is contained in the View defined by operand[0].
 *
 *  The following restrictions apply to the operands: <dl> <dt>[0]</dt><dd>Any
 *  operand that resolves to a NodeId that identifies a View Node.</dd> </dl>
 *
 *  If operand[0] does not resolve to a NodeId that identifies a View Node, this
 *  operation shall always be False.
 *
 *  \var OpcUa_FilterOperator_OfType
 *  TRUE if the target Node is of type operand[0] or of a subtype of operand[0].
 *
 *  The following restrictions apply to the operands: <dl> <dt>[0]</dt><dd>Any
 *  operand that resolves to a NodeId that identifies an ObjectType or VariableType
 *  Node.</dd> </dl>
 *
 *  If operand[0] does not resolve to a NodeId that identifies an ObjectType or
 *  VariableType Node, this operation shall always be False.
 *
 *  \var OpcUa_FilterOperator_RelatedTo
 *  TRUE if the target Node is of type Operand[0] and is related to a NodeId of the
 *  type defined in Operand[1] by the Reference type defined in Operand[2].
 *
 *  Operand[0] or Operand[1] can also point to an element Reference where the
 *  referred to element is another RelatedTo operator. This allows chaining of
 *  relationships (e.g. A is related to B is related to C), where the relationship
 *  is defined by the ReferenceType defined in Operand[2]. In this case, the
 *  referred to element returns a list of NodeIds instead of TRUE or FALSE. In this
 *  case if any errors occur or any of the operands cannot be resolved to an
 *  appropriate value, the result of the chained relationship is an empty list of
 *  nodes.
 *
 *  Operand[3] defines the number of hops for which the relationship should be
 *  followed. If Operand[3] is 1, then objects shall be directly related. If a hop
 *  is greater than 1, then a NodeId of the type described in Operand[1] is checked
 *  for at the depth specified by the hop. In this case, the type of the
 *  intermediate Node is undefined, and only the Reference type used to reach the
 *  end Node is defined. If the requested number of hops cannot be followed, then
 *  the result is FALSE, i.e., an empty Node list. If Operand[3] is 0, the
 *  relationship is followed to its logical end in a forward direction and each
 *  Node is checked to be of the type specified in Operand[1]. If any Node
 *  satisfies this criterion, then the result is TRUE, i.e., the NodeId is included
 *  in the sublist.
 *
 *  Operand [4] defines if Operands [0] and [1] should include support for subtypes
 *  of the types defined by these operands. A TRUE indicates support for subtypes
 *  Operand [5] defines if Operand [2] should include support for subtypes of the
 *  reference type. A TRUE indicates support for subtypes.
 *
 *  The following restrictions apply to the operands: <dl> <dt>[0]</dt><dd>Any
 *  operand that resolves to a NodeId or ExpandedNodeId that identifies an
 *  ObjectType or VariableType Node or a reference to another element which is a
 *  RelatedTo operator.</dd> <dt>[1]</dt><dd>Any operand that resolves to a NodeId
 *  or ExpandedNodeId that identifies an ObjectType or VariableType Node or a
 *  reference to another element which is a RelatedTo operator.</dd>
 *  <dt>[2]</dt><dd>Any operand that resolves to a NodeId that identifies a
 *  ReferenceType Node.</dd> <dt>[3]</dt><dd>Any operand that resolves to a value
 *  implicitly convertible to Uint32.</dd> <dt>[4]</dt><dd>Any operand that
 *  resolves to a value implicitly convertible to a boolean; if this operand does
 *  not resolve to a Boolean, then a value of FALSE is used.</dd>
 *  <dt>[5]</dt><dd>>Any operand that resolves to a value implicitly convertible to
 *  a boolean; if this operand does not resolve to a Boolean, then a value of FALSE
 *  is used.</dd> </dl>
 *
 *  If none of the operands [0],[1],[2],[3] resolves to an appropriate value then
 *  the result of this operation shall always be False (or an Empty set in the case
 *  of a nested RelatedTo operand).
 *
 *  \var OpcUa_FilterOperator_BitwiseAnd
 *  The result is an integer which matches the size of the largest operand and
 *  contains a bitwise And operation of the two operands where both have been
 *  converted to the same size (largest of the two operands).
 *
 *  The following restrictions apply to the operands:
 *
 *  <dl> <dt>[0]</dt><dd>Any operand that resolves to an integer.</dd>
 *  <dt>[0]</dt><dd>Any operand that resolves to an integer.</dd> </dl>
 *
 *  If any operand cannot be resolved to an integer, it is considered a NULL.
 *
 *  \var OpcUa_FilterOperator_BitwiseOr
 *  The result is an integer which matches the size of the largest operand and
 *  contains a bitwise Or operation of the two operands where both have been
 *  converted to the same size (largest of the two operands).
 *
 *  The following restrictions apply to the operands:
 *
 *  <dl> <dt>[0]</dt><dd>Any operand that resolves to an integer.</dd>
 *  <dt>[0]</dt><dd>Any operand that resolves to an integer.</dd> </dl>
 *
 *  If any operand cannot be resolved to an integer, it is considered a NULL.
 */
typedef enum _OpcUa_FilterOperator
{
    OpcUa_FilterOperator_Equals             = 0,
    OpcUa_FilterOperator_IsNull             = 1,
    OpcUa_FilterOperator_GreaterThan        = 2,
    OpcUa_FilterOperator_LessThan           = 3,
    OpcUa_FilterOperator_GreaterThanOrEqual = 4,
    OpcUa_FilterOperator_LessThanOrEqual    = 5,
    OpcUa_FilterOperator_Like               = 6,
    OpcUa_FilterOperator_Not                = 7,
    OpcUa_FilterOperator_Between            = 8,
    OpcUa_FilterOperator_InList             = 9,
    OpcUa_FilterOperator_And                = 10,
    OpcUa_FilterOperator_Or                 = 11,
    OpcUa_FilterOperator_Cast               = 12,
    OpcUa_FilterOperator_InView             = 13,
    OpcUa_FilterOperator_OfType             = 14,
    OpcUa_FilterOperator_RelatedTo          = 15,
    OpcUa_FilterOperator_BitwiseAnd         = 16,
    OpcUa_FilterOperator_BitwiseOr          = 17
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_FilterOperator_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_FilterOperator;

#define OpcUa_FilterOperator_Clear(xValue) *(xValue) = OpcUa_FilterOperator_Equals

#define OpcUa_FilterOperator_Initialize(xValue) *(xValue) = OpcUa_FilterOperator_Equals

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_FilterOperator_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_TimestampsToReturn
/*============================================================================
 * The TimestampsToReturn enumeration.
 *===========================================================================*/
/** \enum OpcUa_TimestampsToReturn
 *  An enumeration that specifies the Timestamp Attributes to be transmitted for
 *  MonitoredItems or Nodes in Read and HistoryRead.
 *
 *  OPC UA defines two timestamps, the source and the server timestamp. This
 *  parameter allows the client to define which timestamps the server should return
 *  with the value.
 *
 *  The source timestamp is only available for Value Attributes. The source
 *  timestamp is used to reflect the timestamp that was applied to a Variable value
 *  by the data source. It should indicate the last change of the value or status
 *  code. The source timestamp must be always generated by the same physical clock.
 *  This timestamp type was added for OPC UA to cover the use case to get the
 *  timestamp of the last value change which is different than the server timestamp
 *  definition.
 *
 *  The server timestamp is used to reflect the time that the server received a
 *  Variable value or knew it to be accurate if the changes are reported by
 *  exception and the connection to the data source is operating. This is the
 *  behavior expected by Classic OPC.
 *
 *  \var OpcUa_TimestampsToReturn_Source
 *  Return the source timestamp.
 *
 *  \var OpcUa_TimestampsToReturn_Server
 *  Return the Server timestamp.
 *
 *  \var OpcUa_TimestampsToReturn_Both
 *  Return both the source and Server timestamps.
 *
 *  \var OpcUa_TimestampsToReturn_Neither
 *  Return neither timestamp.
 *
 *  This is the default value for MonitoredItems if a Variable value is not being
 *  accessed.
 *
 *  For HistoryRead this is not a valid setting.
 */
typedef enum _OpcUa_TimestampsToReturn
{
    OpcUa_TimestampsToReturn_Source  = 0,
    OpcUa_TimestampsToReturn_Server  = 1,
    OpcUa_TimestampsToReturn_Both    = 2,
    OpcUa_TimestampsToReturn_Neither = 3
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_TimestampsToReturn_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_TimestampsToReturn;

#define OpcUa_TimestampsToReturn_Clear(xValue) *(xValue) = OpcUa_TimestampsToReturn_Source

#define OpcUa_TimestampsToReturn_Initialize(xValue) *(xValue) = OpcUa_TimestampsToReturn_Source

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_TimestampsToReturn_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_HistoryUpdateType
/*============================================================================
 * The HistoryUpdateType enumeration.
 *===========================================================================*/
typedef enum _OpcUa_HistoryUpdateType
{
    OpcUa_HistoryUpdateType_Insert  = 1,
    OpcUa_HistoryUpdateType_Replace = 2,
    OpcUa_HistoryUpdateType_Update  = 3,
    OpcUa_HistoryUpdateType_Delete  = 4
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_HistoryUpdateType_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_HistoryUpdateType;

#define OpcUa_HistoryUpdateType_Clear(xValue) *(xValue) = OpcUa_HistoryUpdateType_Insert

#define OpcUa_HistoryUpdateType_Initialize(xValue) *(xValue) = OpcUa_HistoryUpdateType_Insert

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_HistoryUpdateType_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_PerformUpdateType
/*============================================================================
 * The PerformUpdateType enumeration.
 *===========================================================================*/
/** \enum OpcUa_PerformUpdateType
 *  The value determines which action of insert, replace, or update is performed.
 *
 *  \var OpcUa_PerformUpdateType_Insert
 *  Data was inserted
 *
 *  \var OpcUa_PerformUpdateType_Replace
 *  Data was replaced
 *
 *  \var OpcUa_PerformUpdateType_Update
 *  Data was inserted or replaced
 *
 *  \var OpcUa_PerformUpdateType_Remove
 *  Data was deleted
 */
typedef enum _OpcUa_PerformUpdateType
{
    OpcUa_PerformUpdateType_Insert  = 1,
    OpcUa_PerformUpdateType_Replace = 2,
    OpcUa_PerformUpdateType_Update  = 3,
    OpcUa_PerformUpdateType_Remove  = 4
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_PerformUpdateType_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_PerformUpdateType;

#define OpcUa_PerformUpdateType_Clear(xValue) *(xValue) = OpcUa_PerformUpdateType_Insert

#define OpcUa_PerformUpdateType_Initialize(xValue) *(xValue) = OpcUa_PerformUpdateType_Insert

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_PerformUpdateType_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_MonitoringMode
/*============================================================================
 * The MonitoringMode enumeration.
 *===========================================================================*/
/** \enum OpcUa_MonitoringMode
 *  An enumeration that specifies whether sampling and reporting are enabled or
 *  disabled for a MonitoredItem.
 *
 *  The value of the publishing enabled parameter for a Subscription does not
 *  affect the value of the monitoring mode for a MonitoredItem of the
 *  Subscription.
 *
 *  \var OpcUa_MonitoringMode_Disabled
 *  The item being monitored is not sampled or evaluated, and Notifications are not
 *  generated or queued. Notification reporting is disabled.
 *
 *  \var OpcUa_MonitoringMode_Sampling
 *  The item being monitored is sampled and evaluated, and Notifications are
 *  generated and queued. Notification reporting is disabled.
 *
 *  \var OpcUa_MonitoringMode_Reporting
 *  The item being monitored is sampled and evaluated, and Notifications are
 *  generated and queued. Notification reporting is enabled.
 */
typedef enum _OpcUa_MonitoringMode
{
    OpcUa_MonitoringMode_Disabled  = 0,
    OpcUa_MonitoringMode_Sampling  = 1,
    OpcUa_MonitoringMode_Reporting = 2
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_MonitoringMode_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_MonitoringMode;

#define OpcUa_MonitoringMode_Clear(xValue) *(xValue) = OpcUa_MonitoringMode_Disabled

#define OpcUa_MonitoringMode_Initialize(xValue) *(xValue) = OpcUa_MonitoringMode_Disabled

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_MonitoringMode_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_DataChangeTrigger
/*============================================================================
 * The DataChangeTrigger enumeration.
 *===========================================================================*/
typedef enum _OpcUa_DataChangeTrigger
{
    OpcUa_DataChangeTrigger_Status               = 0,
    OpcUa_DataChangeTrigger_StatusValue          = 1,
    OpcUa_DataChangeTrigger_StatusValueTimestamp = 2
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_DataChangeTrigger_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_DataChangeTrigger;

#define OpcUa_DataChangeTrigger_Clear(xValue) *(xValue) = OpcUa_DataChangeTrigger_Status

#define OpcUa_DataChangeTrigger_Initialize(xValue) *(xValue) = OpcUa_DataChangeTrigger_Status

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_DataChangeTrigger_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_DeadbandType
/*============================================================================
 * The DeadbandType enumeration.
 *===========================================================================*/
/** \enum OpcUa_DeadbandType
 *  A value that defines the Deadband type and behaviour.
 *
 *  \var OpcUa_DeadbandType_None
 *  No Deadband calculation should be applied.
 *
 *  \var OpcUa_DeadbandType_Absolute
 *  An AbsoluteDeadband is used.
 *
 *  For this type the deadbandValue contains the absolute change in a data value
 *  that shall cause a Notification to be generated. This parameter applies only to
 *  Variables with any Number data type.
 *
 *  An exception that causes a DataChange Notification based on an AbsoluteDeadband
 *  is determined as follows:
 *
 *  <b>Generate a Notification if (absolute value of (last cached value - current
 *  value) \> AbsoluteDeadband)</b>
 *
 *  The last cached value is defined as the last value pushed to the queue.
 *
 *  If the item is an array of values, the entire array is returned if any array
 *  element exceeds the AbsoluteDeadband, or the size or dimension of the array
 *  changes.
 *
 *  \var OpcUa_DeadbandType_Percent
 *  A PercentDeadband is used.
 *
 *  For this type of deadband the deadbandValue is defined as the percent age of
 *  the EURange. That is, it applies only to AnalogItems with an EURange Property
 *  that defines the typical value range for the item. This range shall be
 *  multiplied with the deadbandValue and then compared to the actual value change
 *  to determine the need for a data change notification. The following pseudo code
 *  shows how the deadband is calculated:
 *
 *  <b>DataChange if (absolute value of (last cached value - current value) \>
 *  (deadbandValue/100.0) * ((high–low) of EURange)))</b>
 *
 *  The range of the deadbandValue is from 0.0 to 100.0 Percent. Specifying a
 *  deadbandValue outside of this range will be rejected and reported with the
 *  StatusCode Bad_DeadbandFilterInvalid.
 *
 *  If the Value of the MonitoredItem is an array, then the deadband calculation
 *  logic shall be applied to each element of the array. If an element that
 *  requires a DataChange is found, then no further deadband checking is necessary
 *  and the entire array shall be returned.
 */
typedef enum _OpcUa_DeadbandType
{
    OpcUa_DeadbandType_None     = 0,
    OpcUa_DeadbandType_Absolute = 1,
    OpcUa_DeadbandType_Percent  = 2
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_DeadbandType_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_DeadbandType;

#define OpcUa_DeadbandType_Clear(xValue) *(xValue) = OpcUa_DeadbandType_None

#define OpcUa_DeadbandType_Initialize(xValue) *(xValue) = OpcUa_DeadbandType_None

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_DeadbandType_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_EnumeratedTestType
/*============================================================================
 * The EnumeratedTestType enumeration.
 *===========================================================================*/
/** \enum OpcUa_EnumeratedTestType
A simple enumerated type used for testing.
 */
typedef enum _OpcUa_EnumeratedTestType
{
    OpcUa_EnumeratedTestType_Red    = 1,
    OpcUa_EnumeratedTestType_Yellow = 4,
    OpcUa_EnumeratedTestType_Green  = 5
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_EnumeratedTestType_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_EnumeratedTestType;

#define OpcUa_EnumeratedTestType_Clear(xValue) *(xValue) = OpcUa_EnumeratedTestType_Red

#define OpcUa_EnumeratedTestType_Initialize(xValue) *(xValue) = OpcUa_EnumeratedTestType_Red

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_EnumeratedTestType_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_RedundancySupport
/*============================================================================
 * The RedundancySupport enumeration.
 *===========================================================================*/
/** \enum OpcUa_RedundancySupport
 *  Defines the redundancy support of the Server.
 *
 *  \var OpcUa_RedundancySupport_None
 *  There is no redundancy support.
 *
 *  \var OpcUa_RedundancySupport_Cold
 *  The server supports cold redundancy as defined in Part 4 of the OPC UA
 *  Specification.
 *
 *  \var OpcUa_RedundancySupport_Warm
 *  The server supports warm redundancy as defined in Part 4 of the OPC UA
 *  Specification.
 *
 *  \var OpcUa_RedundancySupport_Hot
 *  The server supports hot redundancy as defined in Part 4 of the OPC UA
 *  Specification.
 *
 *  \var OpcUa_RedundancySupport_Transparent
 *  The server supports transparent redundancy as defined in Part 4 of the OPC UA
 *  Specification.
 *
 *  \var OpcUa_RedundancySupport_HotAndMirrored
 *  The server supports HotAndMirrored redundancy as defined in Part 4 of the OPC
 *  UA Specification.
 */
typedef enum _OpcUa_RedundancySupport
{
    OpcUa_RedundancySupport_None           = 0,
    OpcUa_RedundancySupport_Cold           = 1,
    OpcUa_RedundancySupport_Warm           = 2,
    OpcUa_RedundancySupport_Hot            = 3,
    OpcUa_RedundancySupport_Transparent    = 4,
    OpcUa_RedundancySupport_HotAndMirrored = 5
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_RedundancySupport_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_RedundancySupport;

#define OpcUa_RedundancySupport_Clear(xValue) *(xValue) = OpcUa_RedundancySupport_None

#define OpcUa_RedundancySupport_Initialize(xValue) *(xValue) = OpcUa_RedundancySupport_None

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_RedundancySupport_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_ServerState
/*============================================================================
 * The ServerState enumeration.
 *===========================================================================*/
/** \enum OpcUa_ServerState
 *  An enumeration that defines the execution state of the Server.
 *
 *  \var OpcUa_ServerState_Running
 *  The server is running normally.
 *
 *  This is the usual state for a server.
 *
 *  \var OpcUa_ServerState_Failed
 *  A vendor-specific fatal error has occurred within the server.
 *
 *  The server is no longer functioning. The recovery procedure from this situation
 *  is vendor-specific. Most Service requests should be expected to fail.
 *
 *  \var OpcUa_ServerState_NoConfiguration
 *  The server is running but has no configuration information loaded and therefore
 *  does not transfer data.
 *
 *  \var OpcUa_ServerState_Suspended
 *  The server has been temporarily suspended by some vendor-specific method and is
 *  not receiving or sending data.
 *
 *  \var OpcUa_ServerState_Shutdown
 *  The server has shut down or is in the process of shutting down.
 *
 *  Depending on the implementation, this might or might not be visible to clients.
 *
 *  \var OpcUa_ServerState_Test
 *  The server is in Test Mode.
 *
 *  The outputs are disconnected from the real hardware, but the server will
 *  otherwise behave normally. Inputs may be real or may be simulated depending on
 *  the vendor implementation. StatusCode will generally be returned normally.
 *
 *  \var OpcUa_ServerState_CommunicationFault
 *  The server is running properly, but is having difficulty accessing data from
 *  its data sources.
 *
 *  This may be due to communication problems or some other problem preventing the
 *  underlying device, control system, etc. from returning valid data. It may be a
 *  complete failure, meaning that no data is available, or a partial failure,
 *  meaning that some data is still available. It is expected that items affected
 *  by the fault will individually return with a BAD FAILURE status code indication
 *  for the items.
 *
 *  \var OpcUa_ServerState_Unknown
 *  This state is used only to indicate that the OPC UA server does not know the
 *  state of underlying servers.
 */
typedef enum _OpcUa_ServerState
{
    OpcUa_ServerState_Running            = 0,
    OpcUa_ServerState_Failed             = 1,
    OpcUa_ServerState_NoConfiguration    = 2,
    OpcUa_ServerState_Suspended          = 3,
    OpcUa_ServerState_Shutdown           = 4,
    OpcUa_ServerState_Test               = 5,
    OpcUa_ServerState_CommunicationFault = 6,
    OpcUa_ServerState_Unknown            = 7
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_ServerState_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_ServerState;

#define OpcUa_ServerState_Clear(xValue) *(xValue) = OpcUa_ServerState_Running

#define OpcUa_ServerState_Initialize(xValue) *(xValue) = OpcUa_ServerState_Running

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_ServerState_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_ModelChangeStructureVerbMask
/*============================================================================
 * The ModelChangeStructureVerbMask enumeration.
 *===========================================================================*/
typedef enum _OpcUa_ModelChangeStructureVerbMask
{
    OpcUa_ModelChangeStructureVerbMask_NodeAdded        = 1,
    OpcUa_ModelChangeStructureVerbMask_NodeDeleted      = 2,
    OpcUa_ModelChangeStructureVerbMask_ReferenceAdded   = 4,
    OpcUa_ModelChangeStructureVerbMask_ReferenceDeleted = 8,
    OpcUa_ModelChangeStructureVerbMask_DataTypeChanged  = 16
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_ModelChangeStructureVerbMask_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_ModelChangeStructureVerbMask;

#define OpcUa_ModelChangeStructureVerbMask_Clear(xValue) *(xValue) = OpcUa_ModelChangeStructureVerbMask_NodeAdded

#define OpcUa_ModelChangeStructureVerbMask_Initialize(xValue) *(xValue) = OpcUa_ModelChangeStructureVerbMask_NodeAdded

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_ModelChangeStructureVerbMask_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_AxisScaleEnumeration
/*============================================================================
 * The AxisScaleEnumeration enumeration.
 *===========================================================================*/
/** \enum OpcUa_AxisScaleEnumeration
 *  Identifies on which type of axis the data shall be displayed.
 *
 *  \var OpcUa_AxisScaleEnumeration_Linear
 *  Linear Scale
 *
 *  \var OpcUa_AxisScaleEnumeration_Log
 *  Log base 10 scale
 *
 *  \var OpcUa_AxisScaleEnumeration_Ln
 *  Log base e scale
 */
typedef enum _OpcUa_AxisScaleEnumeration
{
    OpcUa_AxisScaleEnumeration_Linear = 0,
    OpcUa_AxisScaleEnumeration_Log    = 1,
    OpcUa_AxisScaleEnumeration_Ln     = 2
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_AxisScaleEnumeration_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_AxisScaleEnumeration;

#define OpcUa_AxisScaleEnumeration_Clear(xValue) *(xValue) = OpcUa_AxisScaleEnumeration_Linear

#define OpcUa_AxisScaleEnumeration_Initialize(xValue) *(xValue) = OpcUa_AxisScaleEnumeration_Linear

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_AxisScaleEnumeration_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_ExceptionDeviationFormat
/*============================================================================
 * The ExceptionDeviationFormat enumeration.
 *===========================================================================*/
typedef enum _OpcUa_ExceptionDeviationFormat
{
    OpcUa_ExceptionDeviationFormat_AbsoluteValue    = 0,
    OpcUa_ExceptionDeviationFormat_PercentOfValue   = 1,
    OpcUa_ExceptionDeviationFormat_PercentOfRange   = 2,
    OpcUa_ExceptionDeviationFormat_PercentOfEURange = 3,
    OpcUa_ExceptionDeviationFormat_Unknown          = 4
#if OPCUA_FORCE_INT32_ENUMS
    ,_OpcUa_ExceptionDeviationFormat_MaxEnumerationValue = OpcUa_Int32_Max
#endif
}
OpcUa_ExceptionDeviationFormat;

#define OpcUa_ExceptionDeviationFormat_Clear(xValue) *(xValue) = OpcUa_ExceptionDeviationFormat_AbsoluteValue

#define OpcUa_ExceptionDeviationFormat_Initialize(xValue) *(xValue) = OpcUa_ExceptionDeviationFormat_AbsoluteValue

OPCUA_IMEXPORT extern struct _OpcUa_EnumeratedType OpcUa_ExceptionDeviationFormat_EnumeratedType;
#endif

#ifndef OPCUA_EXCLUDE_TrustListDataType
/*============================================================================
 * The TrustListDataType structure.
 *===========================================================================*/
/** \struct OpcUa_TrustListDataType
 *  A DataType which stores the trust list of a Server.
 *
 *  \var OpcUa_TrustListDataType::SpecifiedLists
 *  A bit mask which indicates which lists contain information.
 *
 *  See \ref OpcUa_TrustListMasks for allowed values.
 *
 *  \var OpcUa_TrustListDataType::TrustedCertificates
 *  The list of Application and CA Certificates which are trusted.
 *
 *  \var OpcUa_TrustListDataType::TrustedCrls
 *  The CRLs for the CA Certificates in the trustedCertificates list.
 *
 *  \var OpcUa_TrustListDataType::IssuerCertificates
 *  The list of CA Certificates which are necessary to validate Certificates.
 *
 *  \var OpcUa_TrustListDataType::IssuerCrls
 *  The CRLs for the CA Certificates in the issuerCertificates list.
 */
typedef struct _OpcUa_TrustListDataType
{
    OpcUa_UInt32      SpecifiedLists;
    OpcUa_Int32       NoOfTrustedCertificates;
    OpcUa_ByteString* TrustedCertificates;
    OpcUa_Int32       NoOfTrustedCrls;
    OpcUa_ByteString* TrustedCrls;
    OpcUa_Int32       NoOfIssuerCertificates;
    OpcUa_ByteString* IssuerCertificates;
    OpcUa_Int32       NoOfIssuerCrls;
    OpcUa_ByteString* IssuerCrls;
}
OpcUa_TrustListDataType;

OPCUA_EXPORT OpcUa_Void       OpcUa_TrustListDataType_Initialize(OpcUa_TrustListDataType* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_TrustListDataType_Clear(OpcUa_TrustListDataType* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TrustListDataType_GetSize(OpcUa_TrustListDataType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TrustListDataType_Encode(OpcUa_TrustListDataType* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TrustListDataType_Decode(OpcUa_TrustListDataType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_TrustListDataType_Compare(const OpcUa_TrustListDataType* pValue1, const OpcUa_TrustListDataType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_TrustListDataType_Copy(const OpcUa_TrustListDataType* pSource, OpcUa_TrustListDataType** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TrustListDataType_CopyTo(const OpcUa_TrustListDataType* pSource, OpcUa_TrustListDataType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_TrustListDataType_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ReferenceNode
/*============================================================================
 * The ReferenceNode structure.
 *===========================================================================*/
/** \struct OpcUa_ReferenceNode
Specifies a reference which belongs to a node.
 */
typedef struct _OpcUa_ReferenceNode
{
    OpcUa_NodeId         ReferenceTypeId;
    OpcUa_Boolean        IsInverse;
    OpcUa_ExpandedNodeId TargetId;
}
OpcUa_ReferenceNode;

OPCUA_EXPORT OpcUa_Void       OpcUa_ReferenceNode_Initialize(OpcUa_ReferenceNode* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ReferenceNode_Clear(OpcUa_ReferenceNode* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReferenceNode_GetSize(OpcUa_ReferenceNode* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReferenceNode_Encode(OpcUa_ReferenceNode* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReferenceNode_Decode(OpcUa_ReferenceNode* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ReferenceNode_Compare(const OpcUa_ReferenceNode* pValue1, const OpcUa_ReferenceNode* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReferenceNode_Copy(const OpcUa_ReferenceNode* pSource, OpcUa_ReferenceNode** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReferenceNode_CopyTo(const OpcUa_ReferenceNode* pSource, OpcUa_ReferenceNode* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ReferenceNode_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_Argument
/*============================================================================
 * The Argument structure.
 *===========================================================================*/
/** \struct OpcUa_Argument
 *  Defines a method input or output argument specification.
 *
 *  It is for example used in the input and output argument Properties for methods.
 *
 *  \var OpcUa_Argument::Name
 *  The name of the argument
 *
 *  \var OpcUa_Argument::DataType
 *  The NodeId of the DataType of this argument.
 *
 *  \var OpcUa_Argument::ValueRank
 *  Indicates whether the DataType is an array and how many dimensions the array
 *  has.
 *
 *  It may have the following values: <dl> <dt>n \> 1</dt> <dd>The DataType is an
 *  array with the specified number of dimensions.</dd> <dt>OneDimension (1)</dt>
 *  <dd>The DataType is an array with one dimension.</dd> <dt>OneOrMoreDimensions
 *  (0)</dt> <dd>The dataType is an array with one or more dimensions.</dd>
 *  <dt>Scalar (−1)</dt> <dd>The DataType is not an array.</dd> <dt>Any (−2)</dt>
 *  <dd>The DataType can be a scalar or an array with any number of
 *  dimensions.</dd> <dt>ScalarOrOneDimension (−3)</dt> <dd>The DataType can be a
 *  scalar or a one dimensional array.</dd> </dl>
 *
 *  \note All DataTypes are considered to be scalar, even if they have array-like
 *  semantics like ByteString and String.
 *
 *  \var OpcUa_Argument::ArrayDimensions
 *  Specifies the length of each dimension for an array dataType.
 *
 *  It is intended to describe the capability of the DataType, not the current
 *  size.
 *
 *  The number of elements shall be equal to the value of the valueRank. Shall be
 *  null if valueRank ≦ 0.
 *
 *  A value of 0 for an individual dimension indicates that the dimension has a
 *  variable length.
 *
 *  \var OpcUa_Argument::Description
 *  A localised description of the argument.
 */
typedef struct _OpcUa_Argument
{
    OpcUa_String        Name;
    OpcUa_NodeId        DataType;
    OpcUa_Int32         ValueRank;
    OpcUa_Int32         NoOfArrayDimensions;
    OpcUa_UInt32*       ArrayDimensions;
    OpcUa_LocalizedText Description;
}
OpcUa_Argument;

OPCUA_EXPORT OpcUa_Void       OpcUa_Argument_Initialize(OpcUa_Argument* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_Argument_Clear(OpcUa_Argument* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_Argument_GetSize(OpcUa_Argument* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_Argument_Encode(OpcUa_Argument* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_Argument_Decode(OpcUa_Argument* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_Argument_Compare(const OpcUa_Argument* pValue1, const OpcUa_Argument* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Argument_Copy(const OpcUa_Argument* pSource, OpcUa_Argument** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_Argument_CopyTo(const OpcUa_Argument* pSource, OpcUa_Argument* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_Argument_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_EnumValueType
/*============================================================================
 * The EnumValueType structure.
 *===========================================================================*/
/** \struct OpcUa_EnumValueType
 *  A mapping between a value of an enumerated type and a name and description.
 *
 *  When this type is used in an array representing human readable representations
 *  of an enumeration, each Value shall be unique in that array.
 *
 *  \var OpcUa_EnumValueType::Value
 *  The Integer representation of an Enumeration.
 *
 *  \var OpcUa_EnumValueType::DisplayName
 *  A human-readable representation of the Value of the Enumeration.
 *
 *  \var OpcUa_EnumValueType::Description
 *  A localized description of the enumeration value.
 *
 *  This field can contain an empty string if no description is available.
 */
typedef struct _OpcUa_EnumValueType
{
    OpcUa_Int64         Value;
    OpcUa_LocalizedText DisplayName;
    OpcUa_LocalizedText Description;
}
OpcUa_EnumValueType;

OPCUA_EXPORT OpcUa_Void       OpcUa_EnumValueType_Initialize(OpcUa_EnumValueType* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_EnumValueType_Clear(OpcUa_EnumValueType* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EnumValueType_GetSize(OpcUa_EnumValueType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EnumValueType_Encode(OpcUa_EnumValueType* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EnumValueType_Decode(OpcUa_EnumValueType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_EnumValueType_Compare(const OpcUa_EnumValueType* pValue1, const OpcUa_EnumValueType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_EnumValueType_Copy(const OpcUa_EnumValueType* pSource, OpcUa_EnumValueType** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EnumValueType_CopyTo(const OpcUa_EnumValueType* pSource, OpcUa_EnumValueType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_EnumValueType_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_OptionSet
/*============================================================================
 * The OptionSet structure.
 *===========================================================================*/
/** \struct OpcUa_OptionSet
 *  This abstract DataType is the base DataType for all DataTypes representing a
 *  bit mask.
 *
 *  All OptionSet DataTypes representing bit masks shall inherit from this
 *  DataType.
 *
 *  The DataType Nodes representing concrete subtypes of the OptionSet shall have
 *  an OptionSetValues Property.
 *
 *  \var OpcUa_OptionSet::Value
 *  Array of bytes representing the bits in the option set.
 *
 *  The length of the ByteString depends on the number of bits.
 *
 *  \var OpcUa_OptionSet::ValidBits
 *  Array of bytes with same size as value representing the valid bits in the value
 *  parameter.
 *
 *  When the Server returns the value to the Client, the ValidBits provides
 *  information of which bits in the bit mask have a meaning. When the Client
 *  passes the value to the Server, the ValidBits defines which bits should be
 *  written. Only those bits defined in ValidBits are changed in the bit mask, all
 *  others stay the same.
 */
typedef struct _OpcUa_OptionSet
{
    OpcUa_ByteString Value;
    OpcUa_ByteString ValidBits;
}
OpcUa_OptionSet;

OPCUA_EXPORT OpcUa_Void       OpcUa_OptionSet_Initialize(OpcUa_OptionSet* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_OptionSet_Clear(OpcUa_OptionSet* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_OptionSet_GetSize(OpcUa_OptionSet* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_OptionSet_Encode(OpcUa_OptionSet* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_OptionSet_Decode(OpcUa_OptionSet* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_OptionSet_Compare(const OpcUa_OptionSet* pValue1, const OpcUa_OptionSet* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_OptionSet_Copy(const OpcUa_OptionSet* pSource, OpcUa_OptionSet** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_OptionSet_CopyTo(const OpcUa_OptionSet* pSource, OpcUa_OptionSet* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_OptionSet_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_TimeZoneDataType
/*============================================================================
 * The TimeZoneDataType structure.
 *===========================================================================*/
/** \struct OpcUa_TimeZoneDataType
 *  The local time that may or may not take daylight saving time into account.
 *
 *  \var OpcUa_TimeZoneDataType::Offset
 *  The offset in minutes from UtcTime.
 *
 *  \var OpcUa_TimeZoneDataType::DaylightSavingInOffset
 *  If TRUE, daylight saving time (DST) is in effect and offset includes the DST
 *  correction.
 *
 *  If FALSE, the offset does not include the DST correction and DST may or may not
 *  have been in effect.
 */
typedef struct _OpcUa_TimeZoneDataType
{
    OpcUa_Int16   Offset;
    OpcUa_Boolean DaylightSavingInOffset;
}
OpcUa_TimeZoneDataType;

OPCUA_EXPORT OpcUa_Void       OpcUa_TimeZoneDataType_Initialize(OpcUa_TimeZoneDataType* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_TimeZoneDataType_Clear(OpcUa_TimeZoneDataType* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TimeZoneDataType_GetSize(OpcUa_TimeZoneDataType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TimeZoneDataType_Encode(OpcUa_TimeZoneDataType* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TimeZoneDataType_Decode(OpcUa_TimeZoneDataType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_TimeZoneDataType_Compare(const OpcUa_TimeZoneDataType* pValue1, const OpcUa_TimeZoneDataType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_TimeZoneDataType_Copy(const OpcUa_TimeZoneDataType* pSource, OpcUa_TimeZoneDataType** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TimeZoneDataType_CopyTo(const OpcUa_TimeZoneDataType* pSource, OpcUa_TimeZoneDataType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_TimeZoneDataType_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ApplicationDescription
/*============================================================================
 * The ApplicationDescription structure.
 *===========================================================================*/
/** \struct OpcUa_ApplicationDescription
 *  Specifies an application that is available.
 *
 *  \var OpcUa_ApplicationDescription::ApplicationUri
 *  The globally unique identifier for the application instance.
 *
 *  This URI is used as ServerUri in Services if the application is a Server.
 *
 *  \var OpcUa_ApplicationDescription::ProductUri
 *  The globally unique identifier for the product.
 *
 *  \var OpcUa_ApplicationDescription::ApplicationName
 *  A localized descriptive name for the application.
 *
 *  \var OpcUa_ApplicationDescription::ApplicationType
 *  The type of application
 *
 *  See \ref OpcUa_ApplicationType
 *
 *  \var OpcUa_ApplicationDescription::GatewayServerUri
 *  A URI that identifies the Gateway Server associated with the DiscoveryUrls.
 *
 *  This value is not specified if the Server can be accessed directly.
 *
 *  This field is not used if the ApplicationType is Client.
 *
 *  \var OpcUa_ApplicationDescription::DiscoveryProfileUri
 *  A URI that identifies the discovery profile supported by the URLs provided.
 *
 *  This field is not used if the ApplicationType is client.
 *
 *  \var OpcUa_ApplicationDescription::DiscoveryUrls
 *  A list of URLs for the discovery Endpoints provided by the application.
 *
 *  If the ApplicationType is Client, this field shall contain an empty list.
 */
typedef struct _OpcUa_ApplicationDescription
{
    OpcUa_String          ApplicationUri;
    OpcUa_String          ProductUri;
    OpcUa_LocalizedText   ApplicationName;
    OpcUa_ApplicationType ApplicationType;
    OpcUa_String          GatewayServerUri;
    OpcUa_String          DiscoveryProfileUri;
    OpcUa_Int32           NoOfDiscoveryUrls;
    OpcUa_String*         DiscoveryUrls;
}
OpcUa_ApplicationDescription;

OPCUA_EXPORT OpcUa_Void       OpcUa_ApplicationDescription_Initialize(OpcUa_ApplicationDescription* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ApplicationDescription_Clear(OpcUa_ApplicationDescription* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ApplicationDescription_GetSize(OpcUa_ApplicationDescription* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ApplicationDescription_Encode(OpcUa_ApplicationDescription* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ApplicationDescription_Decode(OpcUa_ApplicationDescription* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ApplicationDescription_Compare(const OpcUa_ApplicationDescription* pValue1, const OpcUa_ApplicationDescription* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ApplicationDescription_Copy(const OpcUa_ApplicationDescription* pSource, OpcUa_ApplicationDescription** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ApplicationDescription_CopyTo(const OpcUa_ApplicationDescription* pSource, OpcUa_ApplicationDescription* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ApplicationDescription_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_RequestHeader
/*============================================================================
 * The RequestHeader structure.
 *===========================================================================*/
/** \struct OpcUa_RequestHeader
 *  Common parameters for all requests submitted on a Session.
 *
 *  \var OpcUa_RequestHeader::AuthenticationToken
 *  The secret Session identifier used to verify that the request is associated
 *  with the Session.
 *
 *  \var OpcUa_RequestHeader::Timestamp
 *  The time the Client sent the request.
 *
 *  The parameter is only used for diagnostic and logging purposes in the server.
 *
 *  \var OpcUa_RequestHeader::RequestHandle
 *  A requestHandle associated with the request.
 *
 *  This client defined handle can be used to cancel the request. It is also
 *  returned in the response.
 *
 *  \var OpcUa_RequestHeader::ReturnDiagnostics
 *  A bit mask that identifies the types of vendor-specific diagnostics to be
 *  returned in diagnosticInfo response parameters.
 *
 *  The value of this parameter may consist of zero, one or more of the following
 *  values. No value indicates that diagnostics are not to be returned.
 *
 *  Bit Value    | Diagnostics to return
 *  -------------|----------------------------------
 *  0x0000 0001  | ServiceLevel/SymbolicId
 *  0x0000 0002  | ServiceLevel/LocalizedText
 *  0x0000 0004  | ServiceLevel/AdditionalInfo
 *  0x0000 0008  | ServiceLevel/Inner StatusCode
 *  0x0000 0010  | ServiceLevel/Inner Diagnostics
 *  0x0000 0020  | OperationLevel/SymbolicId
 *  0x0000 0040  | OperationLevel/LocalizedText
 *  0x0000 0080  | OperationLevel/AdditionalInfo
 *  0x0000 0100  | OperationLevel/Inner StatusCode
 *  0x0000 0200  | OperationLevel/Inner Diagnostics
 *
 *  Each of these values is composed of two components, level and type, as
 *  described below. If none are requested, as indicated by a 0 value, or if no
 *  diagnostic information was encountered in processing of the request, then
 *  diagnostics information is not returned.
 *
 *  Level:<br/> <dl> <dt>ServiceLevel</dt> <dd>return diagnostics in the
 *  diagnosticInfo of the Service.</dd> <dt>OperationLevel</dt> <dd>return
 *  diagnostics in the diagnosticInfo defined for individual operations requested
 *  in the Service.</dd> </dl> Type: <br/> <dl> <dt>SymbolicId</dt> <dd>return a
 *  namespace-qualified, symbolic identifier for an error or condition. The maximum
 *  length of this identifier is 32 characters.</dd> <dt>LocalizedText</dt>
 *  <dd>return up to 256 bytes of localized text that describes the symbolic
 *  id.</dd> <dt>AdditionalInfo</dt> <dd>return a byte string that contains
 *  additional diagnostic information, such as a memory image. The format of this
 *  byte string is vendor-specific, and may depend on the type of error or
 *  condition encountered.</dd> <dt>InnerStatusCode</dt> <dd>return the inner
 *  StatusCode associated with the operation or Service.</dd>
 *  <dt>InnerDiagnostics</dt> <dd>return the inner diagnostic info associated with
 *  the operation or Service. The contents of the inner diagnostic info structure
 *  are determined by other bits in the mask. Note that setting this bit could
 *  cause multiple levels of nested diagnostic info structures to be returned.</dd>
 *  </dl>
 *
 *  \var OpcUa_RequestHeader::AuditEntryId
 *  An identifier that identifies the Client’s security audit log entry associated
 *  with this request.
 *
 *  An empty string value means that this parameter is not used.
 *
 *  The AuditEntryId typically contains who initiated the action and from where it
 *  was initiated. The AuditEventId is included in the AuditEvent to allow human
 *  readers to correlate an Event with the initiating action.
 *
 *  More details of the Audit mechanisms are defined in 6.2 and in Part 3.
 *
 *  \var OpcUa_RequestHeader::TimeoutHint
 *  This timeout in milliseconds is used in the Client side Communication Stack to
 *  set the timeout on a per-call base.
 *
 *  For a Server this timeout is only a hint and can be used to cancel long running
 *  operations to free resources. If the Server detects a timeout, he can cancel
 *  the operation by sending the Service result Bad_Timeout. The Server should wait
 *  at minimum the timeout after he received the request before cancelling the
 *  operation.
 *
 *  The value of 0 indicates no timeout.
 *
 *  \var OpcUa_RequestHeader::AdditionalHeader
 *  Reserved for future use.
 *
 *  applications that do not understand the header should ignore it.
 */
typedef struct _OpcUa_RequestHeader
{
    OpcUa_NodeId          AuthenticationToken;
    OpcUa_DateTime        Timestamp;
    OpcUa_UInt32          RequestHandle;
    OpcUa_UInt32          ReturnDiagnostics;
    OpcUa_String          AuditEntryId;
    OpcUa_UInt32          TimeoutHint;
    OpcUa_ExtensionObject AdditionalHeader;
}
OpcUa_RequestHeader;

OPCUA_EXPORT OpcUa_Void       OpcUa_RequestHeader_Initialize(OpcUa_RequestHeader* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_RequestHeader_Clear(OpcUa_RequestHeader* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RequestHeader_GetSize(OpcUa_RequestHeader* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RequestHeader_Encode(OpcUa_RequestHeader* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RequestHeader_Decode(OpcUa_RequestHeader* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_RequestHeader_Compare(const OpcUa_RequestHeader* pValue1, const OpcUa_RequestHeader* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_RequestHeader_Copy(const OpcUa_RequestHeader* pSource, OpcUa_RequestHeader** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RequestHeader_CopyTo(const OpcUa_RequestHeader* pSource, OpcUa_RequestHeader* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_RequestHeader_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ResponseHeader
/*============================================================================
 * The ResponseHeader structure.
 *===========================================================================*/
/** \struct OpcUa_ResponseHeader
 *  Common parameters for all responses.
 *
 *  \var OpcUa_ResponseHeader::Timestamp
 *  The time the Server sent the response.
 *
 *  \var OpcUa_ResponseHeader::RequestHandle
 *  The requestHandle given by the Client to the request.
 *
 *  \var OpcUa_ResponseHeader::ServiceResult
 *  OPC UA-defined result of the Service invocation.
 *
 *  \var OpcUa_ResponseHeader::ServiceDiagnostics
 *  Diagnostic information for the Service invocation.
 *
 *  This parameter is empty if diagnostics information was not requested in the
 *  request header.
 *
 *  \var OpcUa_ResponseHeader::StringTable
 *  There is one string in this list for each unique namespace, symbolic
 *  identifier, and localized text string contained in all of the diagnostics
 *  information parameters contained in the response DiagnosticInfo. Each is
 *  identified within this table by its zero-based index.
 *
 *  \var OpcUa_ResponseHeader::AdditionalHeader
 *  Reserved for future use.
 *
 *  applications that do not understand the header should ignore it.
 */
typedef struct _OpcUa_ResponseHeader
{
    OpcUa_DateTime        Timestamp;
    OpcUa_UInt32          RequestHandle;
    OpcUa_StatusCode      ServiceResult;
    OpcUa_DiagnosticInfo  ServiceDiagnostics;
    OpcUa_Int32           NoOfStringTable;
    OpcUa_String*         StringTable;
    OpcUa_ExtensionObject AdditionalHeader;
}
OpcUa_ResponseHeader;

OPCUA_EXPORT OpcUa_Void       OpcUa_ResponseHeader_Initialize(OpcUa_ResponseHeader* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ResponseHeader_Clear(OpcUa_ResponseHeader* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ResponseHeader_GetSize(OpcUa_ResponseHeader* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ResponseHeader_Encode(OpcUa_ResponseHeader* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ResponseHeader_Decode(OpcUa_ResponseHeader* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ResponseHeader_Compare(const OpcUa_ResponseHeader* pValue1, const OpcUa_ResponseHeader* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ResponseHeader_Copy(const OpcUa_ResponseHeader* pSource, OpcUa_ResponseHeader** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ResponseHeader_CopyTo(const OpcUa_ResponseHeader* pSource, OpcUa_ResponseHeader* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ResponseHeader_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ServiceFault
/*============================================================================
 * The ServiceFault structure.
 *===========================================================================*/
/** \struct OpcUa_ServiceFault
The response returned by all services when there is a service level error.
 */
typedef struct _OpcUa_ServiceFault
{
    OpcUa_ResponseHeader ResponseHeader;
}
OpcUa_ServiceFault;

OPCUA_EXPORT OpcUa_Void       OpcUa_ServiceFault_Initialize(OpcUa_ServiceFault* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ServiceFault_Clear(OpcUa_ServiceFault* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ServiceFault_GetSize(OpcUa_ServiceFault* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ServiceFault_Encode(OpcUa_ServiceFault* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ServiceFault_Decode(OpcUa_ServiceFault* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ServiceFault_Compare(const OpcUa_ServiceFault* pValue1, const OpcUa_ServiceFault* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ServiceFault_Copy(const OpcUa_ServiceFault* pSource, OpcUa_ServiceFault** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ServiceFault_CopyTo(const OpcUa_ServiceFault* pSource, OpcUa_ServiceFault* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ServiceFault_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_FindServers
#ifndef OPCUA_EXCLUDE_FindServersRequest
/*============================================================================
 * The FindServersRequest structure.
 *===========================================================================*/
/** \struct OpcUa_FindServersRequest
 *  Asynchronous call to return the Servers known to a Server or Discovery Server.
 *
 *  The Client may reduce the number of results returned by specifying filter
 *  criteria. A Discovery Server returns an empty list if no Servers match the
 *  criteria specified by the client.
 *
 *  Every Server shall provide a Discovery Endpoint that supports this Service. The
 *  Server shall always return a record that describes itself, however in some
 *  cases more than one record may be returned. Gateway Servers shall return a
 *  record for each Server that they provide access to plus (optionally) a record
 *  that allows the Gateway Server to be accessed as an ordinary OPC UA Server.
 *  Non-transparent redundant Servers shall provide a record for each Server in the
 *  redundant set.
 *
 *  Every Server shall have a globally unique identifier called the ServerUri. This
 *  identifier should be a fully qualified domain name; however, it may be a GUID
 *  or similar construct that ensures global uniqueness. The ServerUri returned by
 *  this Service shall be the same value that appears in index 0 of the ServerArray
 *  property (see Part 5 of the OPC UA Specification). The ServerUri is returned as
 *  the applicationUri field in the \ref OpcUa_ApplicationDescription.
 *
 *  Every Server shall also have a human readable identifier, called the
 *  ServerName, which is not necessarily globally unique. This identifier may be
 *  available in multiple locales.
 *
 *  A Server may have multiple HostNames. For this reason, the Client shall pass
 *  the URL it used to connect to the Endpoint to this Service. The implementation
 *  of this Service shall use this information to return responses that are
 *  accessible to the Client via the provided URL.
 *
 *  This Service shall not require any message security but it may require
 *  transport layer security.
 *
 *  Some Servers may be accessed via a Gateway Server and shall have a value
 *  specified for gatewayServerUri in their \ref OpcUa_ApplicationDescription. The
 *  discoveryUrls provided in ApplicationDescription shall belong to the Gateway
 *  Server. Some Discovery Servers may return multiple records for the same Server
 *  if that Server can be accessed via multiple paths.
 *
 *  This Service can be used without security and it is therefore vulnerable to
 *  Denial Of Service (DOS) attacks. A Server should minimize the amount of
 *  processing required to send the response for this Service. This can be achieved
 *  by preparing the result in advance. The Server should also add a short delay
 *  before starting processing of a request during high traffic conditions.
 *
 *  The DiscoveryUrl returned by this Service is ambiguous if there are multiple
 *  TransportProfiles (e.g. UA XML or UA Binary encoding) associated with the URL
 *  scheme. Clients that support multiple TransportProfiles should attempt to use
 *  alternate TransportProfiles if the first choice does not succeed.
 *
 *  \var OpcUa_FindServersRequest::EndpointUrl
 *  The network address that the Client used to access the Discovery Endpoint.
 *
 *  The Server uses this information for diagnostics and to determine what URLs to
 *  return in the response.
 *
 *  The Server should return a suitable default URL if it does not recognize the
 *  HostName in the URL.
 *
 *  \var OpcUa_FindServersRequest::LocaleIds
 *  List of locales to use.
 *
 *  The server should return the applicationName in the \ref
 *  OpcUa_ApplicationDescription using one of locales specified. If the server
 *  supports more than one of the requested locales, the server shall use the
 *  locale that appears first in this list. If the server does not support any of
 *  the requested locales, it chooses an appropriate default locale.
 *
 *  The server chooses an appropriate default locale if this list is empty.
 *
 *  \var OpcUa_FindServersRequest::ServerUris
 *  List of servers to return.
 *
 *  All known servers are returned if the list is empty.
 *
 *  A serverUri matches the applicationUri from the \ref
 *  OpcUa_ApplicationDescription.
 */
typedef struct _OpcUa_FindServersRequest
{
    OpcUa_RequestHeader RequestHeader;
    OpcUa_String        EndpointUrl;
    OpcUa_Int32         NoOfLocaleIds;
    OpcUa_String*       LocaleIds;
    OpcUa_Int32         NoOfServerUris;
    OpcUa_String*       ServerUris;
}
OpcUa_FindServersRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_FindServersRequest_Initialize(OpcUa_FindServersRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_FindServersRequest_Clear(OpcUa_FindServersRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_FindServersRequest_GetSize(OpcUa_FindServersRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_FindServersRequest_Encode(OpcUa_FindServersRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_FindServersRequest_Decode(OpcUa_FindServersRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_FindServersRequest_Compare(const OpcUa_FindServersRequest* pValue1, const OpcUa_FindServersRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_FindServersRequest_Copy(const OpcUa_FindServersRequest* pSource, OpcUa_FindServersRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_FindServersRequest_CopyTo(const OpcUa_FindServersRequest* pSource, OpcUa_FindServersRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_FindServersRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_FindServers */

#ifndef OPCUA_EXCLUDE_FindServers
#ifndef OPCUA_EXCLUDE_FindServersResponse
/*============================================================================
 * The FindServersResponse structure.
 *===========================================================================*/
/** \struct OpcUa_FindServersResponse
 *
 * Response to a \ref OpcUa_FindServersRequest.
 *
 *  \var OpcUa_FindServersResponse::Servers
 *  List of Servers that meet criteria specified in the request.
 *
 *  This list is empty if no servers meet the criteria.
 */
typedef struct _OpcUa_FindServersResponse
{
    OpcUa_ResponseHeader          ResponseHeader;
    OpcUa_Int32                   NoOfServers;
    OpcUa_ApplicationDescription* Servers;
}
OpcUa_FindServersResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_FindServersResponse_Initialize(OpcUa_FindServersResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_FindServersResponse_Clear(OpcUa_FindServersResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_FindServersResponse_GetSize(OpcUa_FindServersResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_FindServersResponse_Encode(OpcUa_FindServersResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_FindServersResponse_Decode(OpcUa_FindServersResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_FindServersResponse_Compare(const OpcUa_FindServersResponse* pValue1, const OpcUa_FindServersResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_FindServersResponse_Copy(const OpcUa_FindServersResponse* pSource, OpcUa_FindServersResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_FindServersResponse_CopyTo(const OpcUa_FindServersResponse* pSource, OpcUa_FindServersResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_FindServersResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_FindServers */

#ifndef OPCUA_EXCLUDE_ServerOnNetwork
/*============================================================================
 * The ServerOnNetwork structure.
 *===========================================================================*/
typedef struct _OpcUa_ServerOnNetwork
{
    OpcUa_UInt32  RecordId;
    OpcUa_String  ServerName;
    OpcUa_String  DiscoveryUrl;
    OpcUa_Int32   NoOfServerCapabilities;
    OpcUa_String* ServerCapabilities;
}
OpcUa_ServerOnNetwork;

OPCUA_EXPORT OpcUa_Void       OpcUa_ServerOnNetwork_Initialize(OpcUa_ServerOnNetwork* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ServerOnNetwork_Clear(OpcUa_ServerOnNetwork* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ServerOnNetwork_GetSize(OpcUa_ServerOnNetwork* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ServerOnNetwork_Encode(OpcUa_ServerOnNetwork* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ServerOnNetwork_Decode(OpcUa_ServerOnNetwork* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ServerOnNetwork_Compare(const OpcUa_ServerOnNetwork* pValue1, const OpcUa_ServerOnNetwork* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ServerOnNetwork_Copy(const OpcUa_ServerOnNetwork* pSource, OpcUa_ServerOnNetwork** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ServerOnNetwork_CopyTo(const OpcUa_ServerOnNetwork* pSource, OpcUa_ServerOnNetwork* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ServerOnNetwork_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_FindServersOnNetwork
#ifndef OPCUA_EXCLUDE_FindServersOnNetworkRequest
/*============================================================================
 * The FindServersOnNetworkRequest structure.
 *===========================================================================*/
typedef struct _OpcUa_FindServersOnNetworkRequest
{
    OpcUa_RequestHeader RequestHeader;
    OpcUa_UInt32        StartingRecordId;
    OpcUa_UInt32        MaxRecordsToReturn;
    OpcUa_Int32         NoOfServerCapabilityFilter;
    OpcUa_String*       ServerCapabilityFilter;
}
OpcUa_FindServersOnNetworkRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_FindServersOnNetworkRequest_Initialize(OpcUa_FindServersOnNetworkRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_FindServersOnNetworkRequest_Clear(OpcUa_FindServersOnNetworkRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_FindServersOnNetworkRequest_GetSize(OpcUa_FindServersOnNetworkRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_FindServersOnNetworkRequest_Encode(OpcUa_FindServersOnNetworkRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_FindServersOnNetworkRequest_Decode(OpcUa_FindServersOnNetworkRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_FindServersOnNetworkRequest_Compare(const OpcUa_FindServersOnNetworkRequest* pValue1, const OpcUa_FindServersOnNetworkRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_FindServersOnNetworkRequest_Copy(const OpcUa_FindServersOnNetworkRequest* pSource, OpcUa_FindServersOnNetworkRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_FindServersOnNetworkRequest_CopyTo(const OpcUa_FindServersOnNetworkRequest* pSource, OpcUa_FindServersOnNetworkRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_FindServersOnNetworkRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_FindServersOnNetwork */

#ifndef OPCUA_EXCLUDE_FindServersOnNetwork
#ifndef OPCUA_EXCLUDE_FindServersOnNetworkResponse
/*============================================================================
 * The FindServersOnNetworkResponse structure.
 *===========================================================================*/
typedef struct _OpcUa_FindServersOnNetworkResponse
{
    OpcUa_ResponseHeader   ResponseHeader;
    OpcUa_DateTime         LastCounterResetTime;
    OpcUa_Int32            NoOfServers;
    OpcUa_ServerOnNetwork* Servers;
}
OpcUa_FindServersOnNetworkResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_FindServersOnNetworkResponse_Initialize(OpcUa_FindServersOnNetworkResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_FindServersOnNetworkResponse_Clear(OpcUa_FindServersOnNetworkResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_FindServersOnNetworkResponse_GetSize(OpcUa_FindServersOnNetworkResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_FindServersOnNetworkResponse_Encode(OpcUa_FindServersOnNetworkResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_FindServersOnNetworkResponse_Decode(OpcUa_FindServersOnNetworkResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_FindServersOnNetworkResponse_Compare(const OpcUa_FindServersOnNetworkResponse* pValue1, const OpcUa_FindServersOnNetworkResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_FindServersOnNetworkResponse_Copy(const OpcUa_FindServersOnNetworkResponse* pSource, OpcUa_FindServersOnNetworkResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_FindServersOnNetworkResponse_CopyTo(const OpcUa_FindServersOnNetworkResponse* pSource, OpcUa_FindServersOnNetworkResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_FindServersOnNetworkResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_FindServersOnNetwork */

#ifndef OPCUA_EXCLUDE_UserTokenPolicy
/*============================================================================
 * The UserTokenPolicy structure.
 *===========================================================================*/
/** \struct OpcUa_UserTokenPolicy
 *  Specifies a UserIdentityToken that a Server will accept.
 *
 *  \var OpcUa_UserTokenPolicy::PolicyId
 *  An identifier for the UserTokenPolicy assigned by the Server.
 *
 *  The Client specifies this value when it constructs a UserIdentityToken that
 *  conforms to the policy.
 *
 *  This value is only unique within the context of a single Server.
 *
 *  \var OpcUa_UserTokenPolicy::TokenType
 *  The type of user identity token required.
 *
 *  A tokenType of ANONYMOUS indicates that the Server does not require any user
 *  identification. In this case the Client application instance certificate is
 *  used as the user identification.
 *
 *  \var OpcUa_UserTokenPolicy::IssuedTokenType
 *  A URI for the type of token.
 *
 *  Part 6 of the OPC UA Specification defines URIs for common issued token types.
 *  Vendors may specify their own token.
 *
 *  This field may only be specified if TokenType is IssuedToken.
 *
 *  \var OpcUa_UserTokenPolicy::IssuerEndpointUrl
 *  An optional URL for the token issuing service.
 *
 *  The meaning of this value depends on the IssuedTokenType.
 *
 *  \var OpcUa_UserTokenPolicy::SecurityPolicyUri
 *  The security policy to use when encrypting or signing the UserIdentityToken
 *  when it is passed to the Server in the ActivateSession request.
 *
 *  The security policy for the SecureChannel is used if this value is omitted.
 */
typedef struct _OpcUa_UserTokenPolicy
{
    OpcUa_String        PolicyId;
    OpcUa_UserTokenType TokenType;
    OpcUa_String        IssuedTokenType;
    OpcUa_String        IssuerEndpointUrl;
    OpcUa_String        SecurityPolicyUri;
}
OpcUa_UserTokenPolicy;

OPCUA_EXPORT OpcUa_Void       OpcUa_UserTokenPolicy_Initialize(OpcUa_UserTokenPolicy* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_UserTokenPolicy_Clear(OpcUa_UserTokenPolicy* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UserTokenPolicy_GetSize(OpcUa_UserTokenPolicy* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UserTokenPolicy_Encode(OpcUa_UserTokenPolicy* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UserTokenPolicy_Decode(OpcUa_UserTokenPolicy* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_UserTokenPolicy_Compare(const OpcUa_UserTokenPolicy* pValue1, const OpcUa_UserTokenPolicy* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_UserTokenPolicy_Copy(const OpcUa_UserTokenPolicy* pSource, OpcUa_UserTokenPolicy** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UserTokenPolicy_CopyTo(const OpcUa_UserTokenPolicy* pSource, OpcUa_UserTokenPolicy* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_UserTokenPolicy_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_EndpointDescription
/*============================================================================
 * The EndpointDescription structure.
 *===========================================================================*/
/** \struct OpcUa_EndpointDescription
 *  Describes an Endpoint for a Server
 *
 *  \var OpcUa_EndpointDescription::EndpointUrl
 *  The URL for the Endpoint described.
 *
 *  \var OpcUa_EndpointDescription::Server
 *  The description for the Server that the Endpoint belongs to.
 *
 *  \var OpcUa_EndpointDescription::ServerCertificate
 *  The application instance certificate issued to the Server.
 *
 *  \var OpcUa_EndpointDescription::SecurityMode
 *  The type of security to apply to the messages.
 *
 *  A SecureChannel may have to be created even if the securityMode is NONE.
 *
 *  \var OpcUa_EndpointDescription::SecurityPolicyUri
 *  The URI for SecurityPolicy to use when securing messages.
 *
 *  \var OpcUa_EndpointDescription::UserIdentityTokens
 *  The user identity tokens that the Server will accept.
 *
 *  The Client shall pass one of the UserIdentityTokens in the ActivateSession
 *  request.
 *
 *  \var OpcUa_EndpointDescription::TransportProfileUri
 *  The URI of the Transport Profile supported by the Endpoint.
 *
 *  \var OpcUa_EndpointDescription::SecurityLevel
 *  A numeric value that indicates how secure the EndpointDescription is compared
 *  to other EndpointDescriptions for the same Server.
 *
 *  A value of 0 indicates that the EndpointDescription is not recommended and is
 *  only supported for backward compatibility.
 *
 *  A higher value indicates better security.
 */
typedef struct _OpcUa_EndpointDescription
{
    OpcUa_String                 EndpointUrl;
    OpcUa_ApplicationDescription Server;
    OpcUa_ByteString             ServerCertificate;
    OpcUa_MessageSecurityMode    SecurityMode;
    OpcUa_String                 SecurityPolicyUri;
    OpcUa_Int32                  NoOfUserIdentityTokens;
    OpcUa_UserTokenPolicy*       UserIdentityTokens;
    OpcUa_String                 TransportProfileUri;
    OpcUa_Byte                   SecurityLevel;
}
OpcUa_EndpointDescription;

OPCUA_EXPORT OpcUa_Void       OpcUa_EndpointDescription_Initialize(OpcUa_EndpointDescription* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_EndpointDescription_Clear(OpcUa_EndpointDescription* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EndpointDescription_GetSize(OpcUa_EndpointDescription* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EndpointDescription_Encode(OpcUa_EndpointDescription* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EndpointDescription_Decode(OpcUa_EndpointDescription* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_EndpointDescription_Compare(const OpcUa_EndpointDescription* pValue1, const OpcUa_EndpointDescription* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_EndpointDescription_Copy(const OpcUa_EndpointDescription* pSource, OpcUa_EndpointDescription** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EndpointDescription_CopyTo(const OpcUa_EndpointDescription* pSource, OpcUa_EndpointDescription* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_EndpointDescription_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_GetEndpoints
#ifndef OPCUA_EXCLUDE_GetEndpointsRequest
/*============================================================================
 * The GetEndpointsRequest structure.
 *===========================================================================*/
/** \struct OpcUa_GetEndpointsRequest
 *  Asynchronous call to get the Endpoints supported by a Server and all of the
 *  configuration information required to establish a SecureChannel and a Session.
 *
 *  This Service shall not require any message security, but it may require
 *  transport layer security.
 *
 *  A Client may reduce the number of results returned by specifying filter
 *  criteria based on LocaleIds and Transport Profile URIs. The Server returns an
 *  empty list if no Endpoints match the criteria specified by the client.
 *
 *  A Server may support multiple security configurations for the same Endpoint. In
 *  this situation, the Server shall return separate \ref OpcUa_EndpointDescription
 *  records for each available configuration.
 *
 *  Clients should treat each of these configurations as distinct Endpoints, even
 *  if the physical URL happens to be the same.
 *
 *  The security configuration for an Endpoint has four components:
 *
 *  - Server application instance certificate
 *  - Message Security Mode
 *  - Security Policy
 *  - Supported User Identity Tokens
 *
 *  The ApplicationInstanceCertificate is used to secure the OpenSecureChannel
 *  request. The MessageSecurityMode and the SecurityPolicy tell the Client how to
 *  secure messages sent via the SecureChannel. The UserIdentityTokens tell the
 *  client which type of user credentials shall be passed to the Server in the
 *  ActivateSession request.
 *
 *  If the securityPolicyUri is NONE and none of the UserTokenPolicies requires
 *  encryption, the Client shall ignore the ApplicationInstanceCertificate.
 *
 *  Each EndpointDescription also specifies a URI for the Transport Profile that
 *  the Endpoint supports. The Transport Profiles specify information such as
 *  message encoding format and protocol version and are defined in Part 7 of the
 *  OPC UA Specification. Clients shall fetch the Server’s SoftwareCertificates if
 *  they want to discover the complete list of Profiles supported by the Server.
 *
 *  Messages are secured by applying standard cryptography algorithms to the
 *  messages before they are sent over the network. The exact set of algorithms
 *  used depends on the SecurityPolicy for the Endpoint. Part 7 of the OPC UA
 *  Specification defines Profiles for common SecurityPolicies and assigns a unique
 *  URI to them. It is expected that applications have built in knowledge of the
 *  SecurityPolicies that they support. As a result, only the Profile URI for the
 *  SecurityPolicy is specified in the EndpointDescription. A Client cannot connect
 *  to an Endpoint that does not support a SecurityPolicy that it recognizes.
 *
 *  An EndpointDescription may specify that the message security mode is NONE. This
 *  configuration is not recommended unless the applications are communicating on a
 *  physically isolated network where the risk of intrusion is extremely small. If
 *  the message security is NONE, it is possible for Clients to deliberately or
 *  accidentally hijack Sessions created by other Clients.
 *
 *  A Server may have multiple HostNames. For this reason, the Client shall pass
 *  the URL it used to connect to the Endpoint to this Service. The implementation
 *  of this Service shall use this information to return responses that are
 *  accessible to the Client via the provided URL.
 *
 *  This Service can be used without security and it is therefore vulnerable to
 *  Denial Of Service (DOS) attacks. A Server should minimize the amount of
 *  processing required to send the response for this Service. This can be achieved
 *  by preparing the result in advance. The Server should also add a short delay
 *  before starting processing of a request during high traffic conditions.
 *
 *  Some of the EndpointDescriptions returned in a response shall specify the
 *  Endpoint information for a Gateway Server that can be used to access another
 *  Server. In these situations, the gatewayServerUri is specified in the
 *  EndpointDescription and all security checks used to verify certificate s shall
 *  use the gatewayServerUri instead of the serverUri.
 *
 *  To connect to a Server via the gateway, the Client shall first establish a
 *  SecureChannel with the Gateway Server. Then the Client shall call the
 *  CreateSession service and pass the serverUri specified in the
 *  EndpointDescription to the Gateway Server. The Gateway Server shall then
 *  connect to the underlying Server on behalf of the Client.
 *
 *  \var OpcUa_GetEndpointsRequest::EndpointUrl
 *  The network address that the Client used to access the Discovery Endpoint.
 *
 *  The Server uses this information for diagnostics and to determine what URLs to
 *  return in the response.
 *
 *  The Server should return a suitable default URL if it does not recognize the
 *  HostName in the URL.
 *
 *  \var OpcUa_GetEndpointsRequest::LocaleIds
 *  List of locales to use.
 *
 *  Specifies the locale to use when returning human readable strings.
 *
 *  If the server supports more than one of the requested locales, the server shall
 *  use the locale that appears first in this list. If the server does not support
 *  any of the requested locales, it chooses an appropriate default locale.
 *
 *  The server chooses an appropriate default locale if this list is empty.
 *
 *  \var OpcUa_GetEndpointsRequest::ProfileUris
 *  List of Transport Profile that the returned Endpoints shall support.
 *
 *  Part 7 of the OPC UA Specification defines URIs for the Transport Profiles.
 *
 *  All Endpoints are returned if the list is empty.
 */
typedef struct _OpcUa_GetEndpointsRequest
{
    OpcUa_RequestHeader RequestHeader;
    OpcUa_String        EndpointUrl;
    OpcUa_Int32         NoOfLocaleIds;
    OpcUa_String*       LocaleIds;
    OpcUa_Int32         NoOfProfileUris;
    OpcUa_String*       ProfileUris;
}
OpcUa_GetEndpointsRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_GetEndpointsRequest_Initialize(OpcUa_GetEndpointsRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_GetEndpointsRequest_Clear(OpcUa_GetEndpointsRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_GetEndpointsRequest_GetSize(OpcUa_GetEndpointsRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_GetEndpointsRequest_Encode(OpcUa_GetEndpointsRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_GetEndpointsRequest_Decode(OpcUa_GetEndpointsRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_GetEndpointsRequest_Compare(const OpcUa_GetEndpointsRequest* pValue1, const OpcUa_GetEndpointsRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_GetEndpointsRequest_Copy(const OpcUa_GetEndpointsRequest* pSource, OpcUa_GetEndpointsRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_GetEndpointsRequest_CopyTo(const OpcUa_GetEndpointsRequest* pSource, OpcUa_GetEndpointsRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_GetEndpointsRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_GetEndpoints */

#ifndef OPCUA_EXCLUDE_GetEndpoints
#ifndef OPCUA_EXCLUDE_GetEndpointsResponse
/*============================================================================
 * The GetEndpointsResponse structure.
 *===========================================================================*/
/** \struct OpcUa_GetEndpointsResponse
 *
 * Response to a \ref OpcUa_GetEndpointsRequest.
 *
 *  \var OpcUa_GetEndpointsResponse::Endpoints
 *  List of Endpoints that meet criteria specified in the request.
 *
 *  This list is empty if no Endpoints meet the criteria
 */
typedef struct _OpcUa_GetEndpointsResponse
{
    OpcUa_ResponseHeader       ResponseHeader;
    OpcUa_Int32                NoOfEndpoints;
    OpcUa_EndpointDescription* Endpoints;
}
OpcUa_GetEndpointsResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_GetEndpointsResponse_Initialize(OpcUa_GetEndpointsResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_GetEndpointsResponse_Clear(OpcUa_GetEndpointsResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_GetEndpointsResponse_GetSize(OpcUa_GetEndpointsResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_GetEndpointsResponse_Encode(OpcUa_GetEndpointsResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_GetEndpointsResponse_Decode(OpcUa_GetEndpointsResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_GetEndpointsResponse_Compare(const OpcUa_GetEndpointsResponse* pValue1, const OpcUa_GetEndpointsResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_GetEndpointsResponse_Copy(const OpcUa_GetEndpointsResponse* pSource, OpcUa_GetEndpointsResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_GetEndpointsResponse_CopyTo(const OpcUa_GetEndpointsResponse* pSource, OpcUa_GetEndpointsResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_GetEndpointsResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_GetEndpoints */

#ifndef OPCUA_EXCLUDE_RegisteredServer
/*============================================================================
 * The RegisteredServer structure.
 *===========================================================================*/
/** \struct OpcUa_RegisteredServer
 *  The server to register
 *
 *  \var OpcUa_RegisteredServer::ServerUri
 *  The globally unique identifier for the Server instance.
 *
 *  The serverUri matches the applicationUri from the ApplicationDescription.
 *
 *  \var OpcUa_RegisteredServer::ProductUri
 *  The globally unique identifier for the Server product.
 *
 *  \var OpcUa_RegisteredServer::ServerNames
 *  A list of localized descriptive names for the Server.
 *
 *  The list shall have at least one valid entry.
 *
 *  \var OpcUa_RegisteredServer::ServerType
 *  The type of application.
 *
 *  The value “Client” (The application is a Client) is not allowed. The Service
 *  result shall be Bad_InvalidArgument in this case.
 *
 *  \var OpcUa_RegisteredServer::GatewayServerUri
 *  The URI of the Gateway Server associated with the DiscoveryUrls.
 *
 *  This value is only specified by Gateway Servers that wish to register the
 *  Servers that they provide access to.
 *
 *  For Servers that do not act as a Gateway Server this parameter shall be null.
 *
 *  \var OpcUa_RegisteredServer::DiscoveryUrls
 *  A list of Discovery Endpoints for the Server.
 *
 *  The list shall have at least one valid entry.
 *
 *  \var OpcUa_RegisteredServer::SemaphoreFilePath
 *  The path to the semaphore file used to identify an automatically-launched
 *  server instance.
 *
 *  Manually-launched servers will not use this parameter.
 *
 *  If a Semaphore file is provided, the IsOnline flag is ignored.
 *
 *  If a Semaphore file is provided and exists, the LocalDiscoveryServer shall save
 *  the registration information in a persistent data store that it reads whenever
 *  the LocalDiscoveryServer starts.
 *
 *  If a Semaphore file is specified but does not exist, the Discovery Server shall
 *  remove the registration from any persistent data store.
 *
 *  If the Server has registered with a semaphoreFilePath, the DiscoveryServer
 *  shall check that this file exists before returning the ApplicationDescription
 *  to the client.
 *
 *  If the Server did not register with a semaphoreFilePath (it is null or empty),
 *  then the DiscoveryServer does not attempt to verify the existence of the file
 *  before returning the ApplicationDescription to the client.
 *
 *  \var OpcUa_RegisteredServer::IsOnline
 *  True if the Server is currently able to accept connections from Clients.
 *
 *  The DiscoveryServer shall return ApplicationDescriptions to the Client.
 *
 *  The Server is expected to periodically re-register with the DiscoveryServer.
 *
 *  False if the Server is currently unable to accept connections from Clients. The
 *  DiscoveryServer shall NOT return ApplicationDescriptions to the Client.
 *
 *  This parameter is ignored if a semaphoreFilePath is provided.
 */
typedef struct _OpcUa_RegisteredServer
{
    OpcUa_String          ServerUri;
    OpcUa_String          ProductUri;
    OpcUa_Int32           NoOfServerNames;
    OpcUa_LocalizedText*  ServerNames;
    OpcUa_ApplicationType ServerType;
    OpcUa_String          GatewayServerUri;
    OpcUa_Int32           NoOfDiscoveryUrls;
    OpcUa_String*         DiscoveryUrls;
    OpcUa_String          SemaphoreFilePath;
    OpcUa_Boolean         IsOnline;
}
OpcUa_RegisteredServer;

OPCUA_EXPORT OpcUa_Void       OpcUa_RegisteredServer_Initialize(OpcUa_RegisteredServer* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_RegisteredServer_Clear(OpcUa_RegisteredServer* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisteredServer_GetSize(OpcUa_RegisteredServer* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisteredServer_Encode(OpcUa_RegisteredServer* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisteredServer_Decode(OpcUa_RegisteredServer* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_RegisteredServer_Compare(const OpcUa_RegisteredServer* pValue1, const OpcUa_RegisteredServer* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisteredServer_Copy(const OpcUa_RegisteredServer* pSource, OpcUa_RegisteredServer** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisteredServer_CopyTo(const OpcUa_RegisteredServer* pSource, OpcUa_RegisteredServer* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_RegisteredServer_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_RegisterServer
#ifndef OPCUA_EXCLUDE_RegisterServerRequest
/*============================================================================
 * The RegisterServerRequest structure.
 *===========================================================================*/
/** \struct OpcUa_RegisterServerRequest
Registers a server with the discovery server.
 */
typedef struct _OpcUa_RegisterServerRequest
{
    OpcUa_RequestHeader    RequestHeader;
    OpcUa_RegisteredServer Server;
}
OpcUa_RegisterServerRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_RegisterServerRequest_Initialize(OpcUa_RegisterServerRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_RegisterServerRequest_Clear(OpcUa_RegisterServerRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterServerRequest_GetSize(OpcUa_RegisterServerRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterServerRequest_Encode(OpcUa_RegisterServerRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterServerRequest_Decode(OpcUa_RegisterServerRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_RegisterServerRequest_Compare(const OpcUa_RegisterServerRequest* pValue1, const OpcUa_RegisterServerRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterServerRequest_Copy(const OpcUa_RegisterServerRequest* pSource, OpcUa_RegisterServerRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterServerRequest_CopyTo(const OpcUa_RegisterServerRequest* pSource, OpcUa_RegisterServerRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_RegisterServerRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_RegisterServer */

#ifndef OPCUA_EXCLUDE_RegisterServer
#ifndef OPCUA_EXCLUDE_RegisterServerResponse
/*============================================================================
 * The RegisterServerResponse structure.
 *===========================================================================*/
/** \struct OpcUa_RegisterServerResponse
Registers a server with the discovery server.
 */
typedef struct _OpcUa_RegisterServerResponse
{
    OpcUa_ResponseHeader ResponseHeader;
}
OpcUa_RegisterServerResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_RegisterServerResponse_Initialize(OpcUa_RegisterServerResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_RegisterServerResponse_Clear(OpcUa_RegisterServerResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterServerResponse_GetSize(OpcUa_RegisterServerResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterServerResponse_Encode(OpcUa_RegisterServerResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterServerResponse_Decode(OpcUa_RegisterServerResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_RegisterServerResponse_Compare(const OpcUa_RegisterServerResponse* pValue1, const OpcUa_RegisterServerResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterServerResponse_Copy(const OpcUa_RegisterServerResponse* pSource, OpcUa_RegisterServerResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterServerResponse_CopyTo(const OpcUa_RegisterServerResponse* pSource, OpcUa_RegisterServerResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_RegisterServerResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_RegisterServer */

#ifndef OPCUA_EXCLUDE_MdnsDiscoveryConfiguration
/*============================================================================
 * The MdnsDiscoveryConfiguration structure.
 *===========================================================================*/
/** \struct OpcUa_MdnsDiscoveryConfiguration
The discovery information needed for mDNS registration.
 */
typedef struct _OpcUa_MdnsDiscoveryConfiguration
{
    OpcUa_String  MdnsServerName;
    OpcUa_Int32   NoOfServerCapabilities;
    OpcUa_String* ServerCapabilities;
}
OpcUa_MdnsDiscoveryConfiguration;

OPCUA_EXPORT OpcUa_Void       OpcUa_MdnsDiscoveryConfiguration_Initialize(OpcUa_MdnsDiscoveryConfiguration* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_MdnsDiscoveryConfiguration_Clear(OpcUa_MdnsDiscoveryConfiguration* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MdnsDiscoveryConfiguration_GetSize(OpcUa_MdnsDiscoveryConfiguration* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MdnsDiscoveryConfiguration_Encode(OpcUa_MdnsDiscoveryConfiguration* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MdnsDiscoveryConfiguration_Decode(OpcUa_MdnsDiscoveryConfiguration* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_MdnsDiscoveryConfiguration_Compare(const OpcUa_MdnsDiscoveryConfiguration* pValue1, const OpcUa_MdnsDiscoveryConfiguration* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_MdnsDiscoveryConfiguration_Copy(const OpcUa_MdnsDiscoveryConfiguration* pSource, OpcUa_MdnsDiscoveryConfiguration** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MdnsDiscoveryConfiguration_CopyTo(const OpcUa_MdnsDiscoveryConfiguration* pSource, OpcUa_MdnsDiscoveryConfiguration* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_MdnsDiscoveryConfiguration_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_RegisterServer2
#ifndef OPCUA_EXCLUDE_RegisterServer2Request
/*============================================================================
 * The RegisterServer2Request structure.
 *===========================================================================*/
typedef struct _OpcUa_RegisterServer2Request
{
    OpcUa_RequestHeader    RequestHeader;
    OpcUa_RegisteredServer Server;
    OpcUa_Int32            NoOfDiscoveryConfiguration;
    OpcUa_ExtensionObject* DiscoveryConfiguration;
}
OpcUa_RegisterServer2Request;

OPCUA_EXPORT OpcUa_Void       OpcUa_RegisterServer2Request_Initialize(OpcUa_RegisterServer2Request* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_RegisterServer2Request_Clear(OpcUa_RegisterServer2Request* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterServer2Request_GetSize(OpcUa_RegisterServer2Request* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterServer2Request_Encode(OpcUa_RegisterServer2Request* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterServer2Request_Decode(OpcUa_RegisterServer2Request* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_RegisterServer2Request_Compare(const OpcUa_RegisterServer2Request* pValue1, const OpcUa_RegisterServer2Request* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterServer2Request_Copy(const OpcUa_RegisterServer2Request* pSource, OpcUa_RegisterServer2Request** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterServer2Request_CopyTo(const OpcUa_RegisterServer2Request* pSource, OpcUa_RegisterServer2Request* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_RegisterServer2Request_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_RegisterServer2 */

#ifndef OPCUA_EXCLUDE_RegisterServer2
#ifndef OPCUA_EXCLUDE_RegisterServer2Response
/*============================================================================
 * The RegisterServer2Response structure.
 *===========================================================================*/
typedef struct _OpcUa_RegisterServer2Response
{
    OpcUa_ResponseHeader  ResponseHeader;
    OpcUa_Int32           NoOfConfigurationResults;
    OpcUa_StatusCode*     ConfigurationResults;
    OpcUa_Int32           NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo* DiagnosticInfos;
}
OpcUa_RegisterServer2Response;

OPCUA_EXPORT OpcUa_Void       OpcUa_RegisterServer2Response_Initialize(OpcUa_RegisterServer2Response* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_RegisterServer2Response_Clear(OpcUa_RegisterServer2Response* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterServer2Response_GetSize(OpcUa_RegisterServer2Response* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterServer2Response_Encode(OpcUa_RegisterServer2Response* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterServer2Response_Decode(OpcUa_RegisterServer2Response* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_RegisterServer2Response_Compare(const OpcUa_RegisterServer2Response* pValue1, const OpcUa_RegisterServer2Response* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterServer2Response_Copy(const OpcUa_RegisterServer2Response* pSource, OpcUa_RegisterServer2Response** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterServer2Response_CopyTo(const OpcUa_RegisterServer2Response* pSource, OpcUa_RegisterServer2Response* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_RegisterServer2Response_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_RegisterServer2 */

#ifndef OPCUA_EXCLUDE_ChannelSecurityToken
/*============================================================================
 * The ChannelSecurityToken structure.
 *===========================================================================*/
/** \struct OpcUa_ChannelSecurityToken
The token that identifies a set of keys for an active secure channel.
 */
typedef struct _OpcUa_ChannelSecurityToken
{
    OpcUa_UInt32   ChannelId;
    OpcUa_UInt32   TokenId;
    OpcUa_DateTime CreatedAt;
    OpcUa_UInt32   RevisedLifetime;
}
OpcUa_ChannelSecurityToken;

OPCUA_EXPORT OpcUa_Void       OpcUa_ChannelSecurityToken_Initialize(OpcUa_ChannelSecurityToken* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ChannelSecurityToken_Clear(OpcUa_ChannelSecurityToken* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ChannelSecurityToken_GetSize(OpcUa_ChannelSecurityToken* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ChannelSecurityToken_Encode(OpcUa_ChannelSecurityToken* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ChannelSecurityToken_Decode(OpcUa_ChannelSecurityToken* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ChannelSecurityToken_Compare(const OpcUa_ChannelSecurityToken* pValue1, const OpcUa_ChannelSecurityToken* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ChannelSecurityToken_Copy(const OpcUa_ChannelSecurityToken* pSource, OpcUa_ChannelSecurityToken** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ChannelSecurityToken_CopyTo(const OpcUa_ChannelSecurityToken* pSource, OpcUa_ChannelSecurityToken* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ChannelSecurityToken_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_OpenSecureChannel
#ifndef OPCUA_EXCLUDE_OpenSecureChannelRequest
/*============================================================================
 * The OpenSecureChannelRequest structure.
 *===========================================================================*/
/** \struct OpcUa_OpenSecureChannelRequest
Creates a secure channel with a server.
 */
typedef struct _OpcUa_OpenSecureChannelRequest
{
    OpcUa_RequestHeader            RequestHeader;
    OpcUa_UInt32                   ClientProtocolVersion;
    OpcUa_SecurityTokenRequestType RequestType;
    OpcUa_MessageSecurityMode      SecurityMode;
    OpcUa_ByteString               ClientNonce;
    OpcUa_UInt32                   RequestedLifetime;
}
OpcUa_OpenSecureChannelRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_OpenSecureChannelRequest_Initialize(OpcUa_OpenSecureChannelRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_OpenSecureChannelRequest_Clear(OpcUa_OpenSecureChannelRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_OpenSecureChannelRequest_GetSize(OpcUa_OpenSecureChannelRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_OpenSecureChannelRequest_Encode(OpcUa_OpenSecureChannelRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_OpenSecureChannelRequest_Decode(OpcUa_OpenSecureChannelRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_OpenSecureChannelRequest_Compare(const OpcUa_OpenSecureChannelRequest* pValue1, const OpcUa_OpenSecureChannelRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_OpenSecureChannelRequest_Copy(const OpcUa_OpenSecureChannelRequest* pSource, OpcUa_OpenSecureChannelRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_OpenSecureChannelRequest_CopyTo(const OpcUa_OpenSecureChannelRequest* pSource, OpcUa_OpenSecureChannelRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_OpenSecureChannelRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_OpenSecureChannel */

#ifndef OPCUA_EXCLUDE_OpenSecureChannel
#ifndef OPCUA_EXCLUDE_OpenSecureChannelResponse
/*============================================================================
 * The OpenSecureChannelResponse structure.
 *===========================================================================*/
/** \struct OpcUa_OpenSecureChannelResponse
Creates a secure channel with a server.
 */
typedef struct _OpcUa_OpenSecureChannelResponse
{
    OpcUa_ResponseHeader       ResponseHeader;
    OpcUa_UInt32               ServerProtocolVersion;
    OpcUa_ChannelSecurityToken SecurityToken;
    OpcUa_ByteString           ServerNonce;
}
OpcUa_OpenSecureChannelResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_OpenSecureChannelResponse_Initialize(OpcUa_OpenSecureChannelResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_OpenSecureChannelResponse_Clear(OpcUa_OpenSecureChannelResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_OpenSecureChannelResponse_GetSize(OpcUa_OpenSecureChannelResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_OpenSecureChannelResponse_Encode(OpcUa_OpenSecureChannelResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_OpenSecureChannelResponse_Decode(OpcUa_OpenSecureChannelResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_OpenSecureChannelResponse_Compare(const OpcUa_OpenSecureChannelResponse* pValue1, const OpcUa_OpenSecureChannelResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_OpenSecureChannelResponse_Copy(const OpcUa_OpenSecureChannelResponse* pSource, OpcUa_OpenSecureChannelResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_OpenSecureChannelResponse_CopyTo(const OpcUa_OpenSecureChannelResponse* pSource, OpcUa_OpenSecureChannelResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_OpenSecureChannelResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_OpenSecureChannel */

#ifndef OPCUA_EXCLUDE_CloseSecureChannel
#ifndef OPCUA_EXCLUDE_CloseSecureChannelRequest
/*============================================================================
 * The CloseSecureChannelRequest structure.
 *===========================================================================*/
/** \struct OpcUa_CloseSecureChannelRequest
Closes a secure channel.
 */
typedef struct _OpcUa_CloseSecureChannelRequest
{
    OpcUa_RequestHeader RequestHeader;
}
OpcUa_CloseSecureChannelRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_CloseSecureChannelRequest_Initialize(OpcUa_CloseSecureChannelRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_CloseSecureChannelRequest_Clear(OpcUa_CloseSecureChannelRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CloseSecureChannelRequest_GetSize(OpcUa_CloseSecureChannelRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CloseSecureChannelRequest_Encode(OpcUa_CloseSecureChannelRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CloseSecureChannelRequest_Decode(OpcUa_CloseSecureChannelRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_CloseSecureChannelRequest_Compare(const OpcUa_CloseSecureChannelRequest* pValue1, const OpcUa_CloseSecureChannelRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_CloseSecureChannelRequest_Copy(const OpcUa_CloseSecureChannelRequest* pSource, OpcUa_CloseSecureChannelRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CloseSecureChannelRequest_CopyTo(const OpcUa_CloseSecureChannelRequest* pSource, OpcUa_CloseSecureChannelRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_CloseSecureChannelRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_CloseSecureChannel */

#ifndef OPCUA_EXCLUDE_CloseSecureChannel
#ifndef OPCUA_EXCLUDE_CloseSecureChannelResponse
/*============================================================================
 * The CloseSecureChannelResponse structure.
 *===========================================================================*/
/** \struct OpcUa_CloseSecureChannelResponse
Closes a secure channel.
 */
typedef struct _OpcUa_CloseSecureChannelResponse
{
    OpcUa_ResponseHeader ResponseHeader;
}
OpcUa_CloseSecureChannelResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_CloseSecureChannelResponse_Initialize(OpcUa_CloseSecureChannelResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_CloseSecureChannelResponse_Clear(OpcUa_CloseSecureChannelResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CloseSecureChannelResponse_GetSize(OpcUa_CloseSecureChannelResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CloseSecureChannelResponse_Encode(OpcUa_CloseSecureChannelResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CloseSecureChannelResponse_Decode(OpcUa_CloseSecureChannelResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_CloseSecureChannelResponse_Compare(const OpcUa_CloseSecureChannelResponse* pValue1, const OpcUa_CloseSecureChannelResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_CloseSecureChannelResponse_Copy(const OpcUa_CloseSecureChannelResponse* pSource, OpcUa_CloseSecureChannelResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CloseSecureChannelResponse_CopyTo(const OpcUa_CloseSecureChannelResponse* pSource, OpcUa_CloseSecureChannelResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_CloseSecureChannelResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_CloseSecureChannel */

#ifndef OPCUA_EXCLUDE_SignedSoftwareCertificate
/*============================================================================
 * The SignedSoftwareCertificate structure.
 *===========================================================================*/
/** \struct OpcUa_SignedSoftwareCertificate
 *  A ByteString containing an encoded certificate.
 *
 *  The encoding of a SignedSoftwareCertificate depends on the security technology
 *  mapping and is defined completely in Part 6 of the OPC UA Specification.
 *
 *  \var OpcUa_SignedSoftwareCertificate::CertificateData
 *  The certificate data serialized as a ByteString.
 *
 *  \var OpcUa_SignedSoftwareCertificate::Signature
 *  The signature for the certificateData.
 */
typedef struct _OpcUa_SignedSoftwareCertificate
{
    OpcUa_ByteString CertificateData;
    OpcUa_ByteString Signature;
}
OpcUa_SignedSoftwareCertificate;

OPCUA_EXPORT OpcUa_Void       OpcUa_SignedSoftwareCertificate_Initialize(OpcUa_SignedSoftwareCertificate* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_SignedSoftwareCertificate_Clear(OpcUa_SignedSoftwareCertificate* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SignedSoftwareCertificate_GetSize(OpcUa_SignedSoftwareCertificate* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SignedSoftwareCertificate_Encode(OpcUa_SignedSoftwareCertificate* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SignedSoftwareCertificate_Decode(OpcUa_SignedSoftwareCertificate* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_SignedSoftwareCertificate_Compare(const OpcUa_SignedSoftwareCertificate* pValue1, const OpcUa_SignedSoftwareCertificate* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_SignedSoftwareCertificate_Copy(const OpcUa_SignedSoftwareCertificate* pSource, OpcUa_SignedSoftwareCertificate** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SignedSoftwareCertificate_CopyTo(const OpcUa_SignedSoftwareCertificate* pSource, OpcUa_SignedSoftwareCertificate* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_SignedSoftwareCertificate_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_SignatureData
/*============================================================================
 * The SignatureData structure.
 *===========================================================================*/
/** \struct OpcUa_SignatureData
A digital signature.
 */
typedef struct _OpcUa_SignatureData
{
    OpcUa_String     Algorithm;
    OpcUa_ByteString Signature;
}
OpcUa_SignatureData;

OPCUA_EXPORT OpcUa_Void       OpcUa_SignatureData_Initialize(OpcUa_SignatureData* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_SignatureData_Clear(OpcUa_SignatureData* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SignatureData_GetSize(OpcUa_SignatureData* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SignatureData_Encode(OpcUa_SignatureData* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SignatureData_Decode(OpcUa_SignatureData* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_SignatureData_Compare(const OpcUa_SignatureData* pValue1, const OpcUa_SignatureData* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_SignatureData_Copy(const OpcUa_SignatureData* pSource, OpcUa_SignatureData** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SignatureData_CopyTo(const OpcUa_SignatureData* pSource, OpcUa_SignatureData* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_SignatureData_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_CreateSession
#ifndef OPCUA_EXCLUDE_CreateSessionRequest
/*============================================================================
 * The CreateSessionRequest structure.
 *===========================================================================*/
/** \struct OpcUa_CreateSessionRequest
Creates a new session with the server.
 */
typedef struct _OpcUa_CreateSessionRequest
{
    OpcUa_RequestHeader          RequestHeader;
    OpcUa_ApplicationDescription ClientDescription;
    OpcUa_String                 ServerUri;
    OpcUa_String                 EndpointUrl;
    OpcUa_String                 SessionName;
    OpcUa_ByteString             ClientNonce;
    OpcUa_ByteString             ClientCertificate;
    OpcUa_Double                 RequestedSessionTimeout;
    OpcUa_UInt32                 MaxResponseMessageSize;
}
OpcUa_CreateSessionRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_CreateSessionRequest_Initialize(OpcUa_CreateSessionRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_CreateSessionRequest_Clear(OpcUa_CreateSessionRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateSessionRequest_GetSize(OpcUa_CreateSessionRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateSessionRequest_Encode(OpcUa_CreateSessionRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateSessionRequest_Decode(OpcUa_CreateSessionRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_CreateSessionRequest_Compare(const OpcUa_CreateSessionRequest* pValue1, const OpcUa_CreateSessionRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateSessionRequest_Copy(const OpcUa_CreateSessionRequest* pSource, OpcUa_CreateSessionRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateSessionRequest_CopyTo(const OpcUa_CreateSessionRequest* pSource, OpcUa_CreateSessionRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_CreateSessionRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_CreateSession */

#ifndef OPCUA_EXCLUDE_CreateSession
#ifndef OPCUA_EXCLUDE_CreateSessionResponse
/*============================================================================
 * The CreateSessionResponse structure.
 *===========================================================================*/
/** \struct OpcUa_CreateSessionResponse
Creates a new session with the server.
 */
typedef struct _OpcUa_CreateSessionResponse
{
    OpcUa_ResponseHeader             ResponseHeader;
    OpcUa_NodeId                     SessionId;
    OpcUa_NodeId                     AuthenticationToken;
    OpcUa_Double                     RevisedSessionTimeout;
    OpcUa_ByteString                 ServerNonce;
    OpcUa_ByteString                 ServerCertificate;
    OpcUa_Int32                      NoOfServerEndpoints;
    OpcUa_EndpointDescription*       ServerEndpoints;
    OpcUa_Int32                      NoOfServerSoftwareCertificates;
    OpcUa_SignedSoftwareCertificate* ServerSoftwareCertificates;
    OpcUa_SignatureData              ServerSignature;
    OpcUa_UInt32                     MaxRequestMessageSize;
}
OpcUa_CreateSessionResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_CreateSessionResponse_Initialize(OpcUa_CreateSessionResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_CreateSessionResponse_Clear(OpcUa_CreateSessionResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateSessionResponse_GetSize(OpcUa_CreateSessionResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateSessionResponse_Encode(OpcUa_CreateSessionResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateSessionResponse_Decode(OpcUa_CreateSessionResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_CreateSessionResponse_Compare(const OpcUa_CreateSessionResponse* pValue1, const OpcUa_CreateSessionResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateSessionResponse_Copy(const OpcUa_CreateSessionResponse* pSource, OpcUa_CreateSessionResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateSessionResponse_CopyTo(const OpcUa_CreateSessionResponse* pSource, OpcUa_CreateSessionResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_CreateSessionResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_CreateSession */

#ifndef OPCUA_EXCLUDE_UserIdentityToken
/*============================================================================
 * The UserIdentityToken structure.
 *===========================================================================*/
/** \struct OpcUa_UserIdentityToken
 *  Allows Clients to specify the identity of the user they are acting on behalf
 *  of.
 *
 *  The exact mechanism used to identify users depends on the system configuration.
 *  The different types of identity tokens are bas ed on the most common mechanisms
 *  that are used in systems today.
 *
 *  The Client shall always prove possession of a UserIdentityToken when it passes
 *  it to the Server. Some tokens include a secret such as a password which the
 *  Server will accept as proof. In order to protect these secrets the Token shall
 *  be encrypted before it is passed to the Server. Other types of tokens allow the
 *  Client to create a signature with the secret associated with the Token. In
 *  these cases, the Client proves possession of a UserIdentityToken by appending
 *  the last ServerNonce to the ServerCertificate and uses the secret to produce a
 *  Signature which is passed to the Server.
 *
 *  Each UserIdentityToken allowed by an Endpoint shall have a UserTokenPolicy
 *  specified in the EndpointDescription. The UserTokenPolicy specifies what
 *  SecurityPolicy to use when encrypting or signing. If this SecurityPolicy is
 *  omitted, the Client uses the SecurityPolicy in the EndpointDescription. If the
 *  matching SecurityPolicy is set to None, no encryption or signature is required.
 *  It is recommended that Applications never set the SecurityPolicy to None for
 *  UserTokens that include a secret because these secrets could be used by an
 *  attacker to gain access to the system.
 */
typedef struct _OpcUa_UserIdentityToken
{
    OpcUa_String PolicyId;
}
OpcUa_UserIdentityToken;

OPCUA_EXPORT OpcUa_Void       OpcUa_UserIdentityToken_Initialize(OpcUa_UserIdentityToken* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_UserIdentityToken_Clear(OpcUa_UserIdentityToken* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UserIdentityToken_GetSize(OpcUa_UserIdentityToken* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UserIdentityToken_Encode(OpcUa_UserIdentityToken* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UserIdentityToken_Decode(OpcUa_UserIdentityToken* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_UserIdentityToken_Compare(const OpcUa_UserIdentityToken* pValue1, const OpcUa_UserIdentityToken* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_UserIdentityToken_Copy(const OpcUa_UserIdentityToken* pSource, OpcUa_UserIdentityToken** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UserIdentityToken_CopyTo(const OpcUa_UserIdentityToken* pSource, OpcUa_UserIdentityToken* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_UserIdentityToken_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_AnonymousIdentityToken
/*============================================================================
 * The AnonymousIdentityToken structure.
 *===========================================================================*/
/** \struct OpcUa_AnonymousIdentityToken
A token representing an anonymous user.
 */
typedef struct _OpcUa_AnonymousIdentityToken
{
    OpcUa_String PolicyId;
}
OpcUa_AnonymousIdentityToken;

OPCUA_EXPORT OpcUa_Void       OpcUa_AnonymousIdentityToken_Initialize(OpcUa_AnonymousIdentityToken* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_AnonymousIdentityToken_Clear(OpcUa_AnonymousIdentityToken* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AnonymousIdentityToken_GetSize(OpcUa_AnonymousIdentityToken* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AnonymousIdentityToken_Encode(OpcUa_AnonymousIdentityToken* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AnonymousIdentityToken_Decode(OpcUa_AnonymousIdentityToken* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_AnonymousIdentityToken_Compare(const OpcUa_AnonymousIdentityToken* pValue1, const OpcUa_AnonymousIdentityToken* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_AnonymousIdentityToken_Copy(const OpcUa_AnonymousIdentityToken* pSource, OpcUa_AnonymousIdentityToken** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AnonymousIdentityToken_CopyTo(const OpcUa_AnonymousIdentityToken* pSource, OpcUa_AnonymousIdentityToken* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_AnonymousIdentityToken_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_UserNameIdentityToken
/*============================================================================
 * The UserNameIdentityToken structure.
 *===========================================================================*/
/** \struct OpcUa_UserNameIdentityToken
A token representing a user identified by a user name and password.
 */
typedef struct _OpcUa_UserNameIdentityToken
{
    OpcUa_String     PolicyId;
    OpcUa_String     UserName;
    OpcUa_ByteString Password;
    OpcUa_String     EncryptionAlgorithm;
}
OpcUa_UserNameIdentityToken;

OPCUA_EXPORT OpcUa_Void       OpcUa_UserNameIdentityToken_Initialize(OpcUa_UserNameIdentityToken* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_UserNameIdentityToken_Clear(OpcUa_UserNameIdentityToken* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UserNameIdentityToken_GetSize(OpcUa_UserNameIdentityToken* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UserNameIdentityToken_Encode(OpcUa_UserNameIdentityToken* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UserNameIdentityToken_Decode(OpcUa_UserNameIdentityToken* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_UserNameIdentityToken_Compare(const OpcUa_UserNameIdentityToken* pValue1, const OpcUa_UserNameIdentityToken* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_UserNameIdentityToken_Copy(const OpcUa_UserNameIdentityToken* pSource, OpcUa_UserNameIdentityToken** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UserNameIdentityToken_CopyTo(const OpcUa_UserNameIdentityToken* pSource, OpcUa_UserNameIdentityToken* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_UserNameIdentityToken_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_X509IdentityToken
/*============================================================================
 * The X509IdentityToken structure.
 *===========================================================================*/
/** \struct OpcUa_X509IdentityToken
A token representing a user identified by an X509 certificate.
 */
typedef struct _OpcUa_X509IdentityToken
{
    OpcUa_String     PolicyId;
    OpcUa_ByteString CertificateData;
}
OpcUa_X509IdentityToken;

OPCUA_EXPORT OpcUa_Void       OpcUa_X509IdentityToken_Initialize(OpcUa_X509IdentityToken* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_X509IdentityToken_Clear(OpcUa_X509IdentityToken* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_X509IdentityToken_GetSize(OpcUa_X509IdentityToken* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_X509IdentityToken_Encode(OpcUa_X509IdentityToken* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_X509IdentityToken_Decode(OpcUa_X509IdentityToken* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_X509IdentityToken_Compare(const OpcUa_X509IdentityToken* pValue1, const OpcUa_X509IdentityToken* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_X509IdentityToken_Copy(const OpcUa_X509IdentityToken* pSource, OpcUa_X509IdentityToken** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_X509IdentityToken_CopyTo(const OpcUa_X509IdentityToken* pSource, OpcUa_X509IdentityToken* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_X509IdentityToken_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_KerberosIdentityToken
/*============================================================================
 * The KerberosIdentityToken structure.
 *===========================================================================*/
typedef struct _OpcUa_KerberosIdentityToken
{
    OpcUa_String     PolicyId;
    OpcUa_ByteString TicketData;
}
OpcUa_KerberosIdentityToken;

OPCUA_EXPORT OpcUa_Void       OpcUa_KerberosIdentityToken_Initialize(OpcUa_KerberosIdentityToken* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_KerberosIdentityToken_Clear(OpcUa_KerberosIdentityToken* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_KerberosIdentityToken_GetSize(OpcUa_KerberosIdentityToken* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_KerberosIdentityToken_Encode(OpcUa_KerberosIdentityToken* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_KerberosIdentityToken_Decode(OpcUa_KerberosIdentityToken* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_KerberosIdentityToken_Compare(const OpcUa_KerberosIdentityToken* pValue1, const OpcUa_KerberosIdentityToken* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_KerberosIdentityToken_Copy(const OpcUa_KerberosIdentityToken* pSource, OpcUa_KerberosIdentityToken** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_KerberosIdentityToken_CopyTo(const OpcUa_KerberosIdentityToken* pSource, OpcUa_KerberosIdentityToken* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_KerberosIdentityToken_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_IssuedIdentityToken
/*============================================================================
 * The IssuedIdentityToken structure.
 *===========================================================================*/
/** \struct OpcUa_IssuedIdentityToken
A token representing a user identified by a WS-Security XML token.
 */
typedef struct _OpcUa_IssuedIdentityToken
{
    OpcUa_String     PolicyId;
    OpcUa_ByteString TokenData;
    OpcUa_String     EncryptionAlgorithm;
}
OpcUa_IssuedIdentityToken;

OPCUA_EXPORT OpcUa_Void       OpcUa_IssuedIdentityToken_Initialize(OpcUa_IssuedIdentityToken* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_IssuedIdentityToken_Clear(OpcUa_IssuedIdentityToken* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_IssuedIdentityToken_GetSize(OpcUa_IssuedIdentityToken* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_IssuedIdentityToken_Encode(OpcUa_IssuedIdentityToken* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_IssuedIdentityToken_Decode(OpcUa_IssuedIdentityToken* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_IssuedIdentityToken_Compare(const OpcUa_IssuedIdentityToken* pValue1, const OpcUa_IssuedIdentityToken* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_IssuedIdentityToken_Copy(const OpcUa_IssuedIdentityToken* pSource, OpcUa_IssuedIdentityToken** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_IssuedIdentityToken_CopyTo(const OpcUa_IssuedIdentityToken* pSource, OpcUa_IssuedIdentityToken* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_IssuedIdentityToken_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ActivateSession
#ifndef OPCUA_EXCLUDE_ActivateSessionRequest
/*============================================================================
 * The ActivateSessionRequest structure.
 *===========================================================================*/
/** \struct OpcUa_ActivateSessionRequest
Activates a session with the server.
 */
typedef struct _OpcUa_ActivateSessionRequest
{
    OpcUa_RequestHeader              RequestHeader;
    OpcUa_SignatureData              ClientSignature;
    OpcUa_Int32                      NoOfClientSoftwareCertificates;
    OpcUa_SignedSoftwareCertificate* ClientSoftwareCertificates;
    OpcUa_Int32                      NoOfLocaleIds;
    OpcUa_String*                    LocaleIds;
    OpcUa_ExtensionObject            UserIdentityToken;
    OpcUa_SignatureData              UserTokenSignature;
}
OpcUa_ActivateSessionRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_ActivateSessionRequest_Initialize(OpcUa_ActivateSessionRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ActivateSessionRequest_Clear(OpcUa_ActivateSessionRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ActivateSessionRequest_GetSize(OpcUa_ActivateSessionRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ActivateSessionRequest_Encode(OpcUa_ActivateSessionRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ActivateSessionRequest_Decode(OpcUa_ActivateSessionRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ActivateSessionRequest_Compare(const OpcUa_ActivateSessionRequest* pValue1, const OpcUa_ActivateSessionRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ActivateSessionRequest_Copy(const OpcUa_ActivateSessionRequest* pSource, OpcUa_ActivateSessionRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ActivateSessionRequest_CopyTo(const OpcUa_ActivateSessionRequest* pSource, OpcUa_ActivateSessionRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ActivateSessionRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_ActivateSession */

#ifndef OPCUA_EXCLUDE_ActivateSession
#ifndef OPCUA_EXCLUDE_ActivateSessionResponse
/*============================================================================
 * The ActivateSessionResponse structure.
 *===========================================================================*/
/** \struct OpcUa_ActivateSessionResponse
Activates a session with the server.
 */
typedef struct _OpcUa_ActivateSessionResponse
{
    OpcUa_ResponseHeader  ResponseHeader;
    OpcUa_ByteString      ServerNonce;
    OpcUa_Int32           NoOfResults;
    OpcUa_StatusCode*     Results;
    OpcUa_Int32           NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo* DiagnosticInfos;
}
OpcUa_ActivateSessionResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_ActivateSessionResponse_Initialize(OpcUa_ActivateSessionResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ActivateSessionResponse_Clear(OpcUa_ActivateSessionResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ActivateSessionResponse_GetSize(OpcUa_ActivateSessionResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ActivateSessionResponse_Encode(OpcUa_ActivateSessionResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ActivateSessionResponse_Decode(OpcUa_ActivateSessionResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ActivateSessionResponse_Compare(const OpcUa_ActivateSessionResponse* pValue1, const OpcUa_ActivateSessionResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ActivateSessionResponse_Copy(const OpcUa_ActivateSessionResponse* pSource, OpcUa_ActivateSessionResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ActivateSessionResponse_CopyTo(const OpcUa_ActivateSessionResponse* pSource, OpcUa_ActivateSessionResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ActivateSessionResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_ActivateSession */

#ifndef OPCUA_EXCLUDE_CloseSession
#ifndef OPCUA_EXCLUDE_CloseSessionRequest
/*============================================================================
 * The CloseSessionRequest structure.
 *===========================================================================*/
/** \struct OpcUa_CloseSessionRequest
Closes a session with the server.
 */
typedef struct _OpcUa_CloseSessionRequest
{
    OpcUa_RequestHeader RequestHeader;
    OpcUa_Boolean       DeleteSubscriptions;
}
OpcUa_CloseSessionRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_CloseSessionRequest_Initialize(OpcUa_CloseSessionRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_CloseSessionRequest_Clear(OpcUa_CloseSessionRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CloseSessionRequest_GetSize(OpcUa_CloseSessionRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CloseSessionRequest_Encode(OpcUa_CloseSessionRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CloseSessionRequest_Decode(OpcUa_CloseSessionRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_CloseSessionRequest_Compare(const OpcUa_CloseSessionRequest* pValue1, const OpcUa_CloseSessionRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_CloseSessionRequest_Copy(const OpcUa_CloseSessionRequest* pSource, OpcUa_CloseSessionRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CloseSessionRequest_CopyTo(const OpcUa_CloseSessionRequest* pSource, OpcUa_CloseSessionRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_CloseSessionRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_CloseSession */

#ifndef OPCUA_EXCLUDE_CloseSession
#ifndef OPCUA_EXCLUDE_CloseSessionResponse
/*============================================================================
 * The CloseSessionResponse structure.
 *===========================================================================*/
/** \struct OpcUa_CloseSessionResponse
Closes a session with the server.
 */
typedef struct _OpcUa_CloseSessionResponse
{
    OpcUa_ResponseHeader ResponseHeader;
}
OpcUa_CloseSessionResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_CloseSessionResponse_Initialize(OpcUa_CloseSessionResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_CloseSessionResponse_Clear(OpcUa_CloseSessionResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CloseSessionResponse_GetSize(OpcUa_CloseSessionResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CloseSessionResponse_Encode(OpcUa_CloseSessionResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CloseSessionResponse_Decode(OpcUa_CloseSessionResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_CloseSessionResponse_Compare(const OpcUa_CloseSessionResponse* pValue1, const OpcUa_CloseSessionResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_CloseSessionResponse_Copy(const OpcUa_CloseSessionResponse* pSource, OpcUa_CloseSessionResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CloseSessionResponse_CopyTo(const OpcUa_CloseSessionResponse* pSource, OpcUa_CloseSessionResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_CloseSessionResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_CloseSession */

#ifndef OPCUA_EXCLUDE_Cancel
#ifndef OPCUA_EXCLUDE_CancelRequest
/*============================================================================
 * The CancelRequest structure.
 *===========================================================================*/
/** \struct OpcUa_CancelRequest
 *  Asynchronously cancels outstanding service requests on the OPC UA server.
 *
 *  \var OpcUa_CancelRequest::RequestHandle
 *  The request handle assigned to one or more requests that should be cancelled.
 *
 *  All outstanding requests with the matching requestHandle shall be cancelled.
 */
typedef struct _OpcUa_CancelRequest
{
    OpcUa_RequestHeader RequestHeader;
    OpcUa_UInt32        RequestHandle;
}
OpcUa_CancelRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_CancelRequest_Initialize(OpcUa_CancelRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_CancelRequest_Clear(OpcUa_CancelRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CancelRequest_GetSize(OpcUa_CancelRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CancelRequest_Encode(OpcUa_CancelRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CancelRequest_Decode(OpcUa_CancelRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_CancelRequest_Compare(const OpcUa_CancelRequest* pValue1, const OpcUa_CancelRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_CancelRequest_Copy(const OpcUa_CancelRequest* pSource, OpcUa_CancelRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CancelRequest_CopyTo(const OpcUa_CancelRequest* pSource, OpcUa_CancelRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_CancelRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_Cancel */

#ifndef OPCUA_EXCLUDE_Cancel
#ifndef OPCUA_EXCLUDE_CancelResponse
/*============================================================================
 * The CancelResponse structure.
 *===========================================================================*/
/** \struct OpcUa_CancelResponse
 *
 * Response to a \ref OpcUa_CancelRequest.
 *
 *  \var OpcUa_CancelResponse::CancelCount
 *  Number of cancelled requests.
 */
typedef struct _OpcUa_CancelResponse
{
    OpcUa_ResponseHeader ResponseHeader;
    OpcUa_UInt32         CancelCount;
}
OpcUa_CancelResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_CancelResponse_Initialize(OpcUa_CancelResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_CancelResponse_Clear(OpcUa_CancelResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CancelResponse_GetSize(OpcUa_CancelResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CancelResponse_Encode(OpcUa_CancelResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CancelResponse_Decode(OpcUa_CancelResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_CancelResponse_Compare(const OpcUa_CancelResponse* pValue1, const OpcUa_CancelResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_CancelResponse_Copy(const OpcUa_CancelResponse* pSource, OpcUa_CancelResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CancelResponse_CopyTo(const OpcUa_CancelResponse* pSource, OpcUa_CancelResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_CancelResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_Cancel */

#ifndef OPCUA_EXCLUDE_NodeAttributes
/*============================================================================
 * The NodeAttributes structure.
 *===========================================================================*/
/** \struct OpcUa_NodeAttributes
The base attributes for all nodes.
 */
typedef struct _OpcUa_NodeAttributes
{
    OpcUa_UInt32        SpecifiedAttributes;
    OpcUa_LocalizedText DisplayName;
    OpcUa_LocalizedText Description;
    OpcUa_UInt32        WriteMask;
    OpcUa_UInt32        UserWriteMask;
}
OpcUa_NodeAttributes;

OPCUA_EXPORT OpcUa_Void       OpcUa_NodeAttributes_Initialize(OpcUa_NodeAttributes* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_NodeAttributes_Clear(OpcUa_NodeAttributes* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_NodeAttributes_GetSize(OpcUa_NodeAttributes* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_NodeAttributes_Encode(OpcUa_NodeAttributes* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_NodeAttributes_Decode(OpcUa_NodeAttributes* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_NodeAttributes_Compare(const OpcUa_NodeAttributes* pValue1, const OpcUa_NodeAttributes* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_NodeAttributes_Copy(const OpcUa_NodeAttributes* pSource, OpcUa_NodeAttributes** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_NodeAttributes_CopyTo(const OpcUa_NodeAttributes* pSource, OpcUa_NodeAttributes* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_NodeAttributes_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ObjectAttributes
/*============================================================================
 * The ObjectAttributes structure.
 *===========================================================================*/
/** \struct OpcUa_ObjectAttributes
The attributes for an object node.
 */
typedef struct _OpcUa_ObjectAttributes
{
    OpcUa_UInt32        SpecifiedAttributes;
    OpcUa_LocalizedText DisplayName;
    OpcUa_LocalizedText Description;
    OpcUa_UInt32        WriteMask;
    OpcUa_UInt32        UserWriteMask;
    OpcUa_Byte          EventNotifier;
}
OpcUa_ObjectAttributes;

OPCUA_EXPORT OpcUa_Void       OpcUa_ObjectAttributes_Initialize(OpcUa_ObjectAttributes* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ObjectAttributes_Clear(OpcUa_ObjectAttributes* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ObjectAttributes_GetSize(OpcUa_ObjectAttributes* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ObjectAttributes_Encode(OpcUa_ObjectAttributes* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ObjectAttributes_Decode(OpcUa_ObjectAttributes* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ObjectAttributes_Compare(const OpcUa_ObjectAttributes* pValue1, const OpcUa_ObjectAttributes* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ObjectAttributes_Copy(const OpcUa_ObjectAttributes* pSource, OpcUa_ObjectAttributes** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ObjectAttributes_CopyTo(const OpcUa_ObjectAttributes* pSource, OpcUa_ObjectAttributes* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ObjectAttributes_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_VariableAttributes
/*============================================================================
 * The VariableAttributes structure.
 *===========================================================================*/
/** \struct OpcUa_VariableAttributes
The attributes for a variable node.
 */
typedef struct _OpcUa_VariableAttributes
{
    OpcUa_UInt32        SpecifiedAttributes;
    OpcUa_LocalizedText DisplayName;
    OpcUa_LocalizedText Description;
    OpcUa_UInt32        WriteMask;
    OpcUa_UInt32        UserWriteMask;
    OpcUa_Variant       Value;
    OpcUa_NodeId        DataType;
    OpcUa_Int32         ValueRank;
    OpcUa_Int32         NoOfArrayDimensions;
    OpcUa_UInt32*       ArrayDimensions;
    OpcUa_Byte          AccessLevel;
    OpcUa_Byte          UserAccessLevel;
    OpcUa_Double        MinimumSamplingInterval;
    OpcUa_Boolean       Historizing;
}
OpcUa_VariableAttributes;

OPCUA_EXPORT OpcUa_Void       OpcUa_VariableAttributes_Initialize(OpcUa_VariableAttributes* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_VariableAttributes_Clear(OpcUa_VariableAttributes* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_VariableAttributes_GetSize(OpcUa_VariableAttributes* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_VariableAttributes_Encode(OpcUa_VariableAttributes* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_VariableAttributes_Decode(OpcUa_VariableAttributes* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_VariableAttributes_Compare(const OpcUa_VariableAttributes* pValue1, const OpcUa_VariableAttributes* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_VariableAttributes_Copy(const OpcUa_VariableAttributes* pSource, OpcUa_VariableAttributes** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_VariableAttributes_CopyTo(const OpcUa_VariableAttributes* pSource, OpcUa_VariableAttributes* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_VariableAttributes_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_MethodAttributes
/*============================================================================
 * The MethodAttributes structure.
 *===========================================================================*/
/** \struct OpcUa_MethodAttributes
The attributes for a method node.
 */
typedef struct _OpcUa_MethodAttributes
{
    OpcUa_UInt32        SpecifiedAttributes;
    OpcUa_LocalizedText DisplayName;
    OpcUa_LocalizedText Description;
    OpcUa_UInt32        WriteMask;
    OpcUa_UInt32        UserWriteMask;
    OpcUa_Boolean       Executable;
    OpcUa_Boolean       UserExecutable;
}
OpcUa_MethodAttributes;

OPCUA_EXPORT OpcUa_Void       OpcUa_MethodAttributes_Initialize(OpcUa_MethodAttributes* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_MethodAttributes_Clear(OpcUa_MethodAttributes* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MethodAttributes_GetSize(OpcUa_MethodAttributes* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MethodAttributes_Encode(OpcUa_MethodAttributes* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MethodAttributes_Decode(OpcUa_MethodAttributes* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_MethodAttributes_Compare(const OpcUa_MethodAttributes* pValue1, const OpcUa_MethodAttributes* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_MethodAttributes_Copy(const OpcUa_MethodAttributes* pSource, OpcUa_MethodAttributes** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MethodAttributes_CopyTo(const OpcUa_MethodAttributes* pSource, OpcUa_MethodAttributes* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_MethodAttributes_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ObjectTypeAttributes
/*============================================================================
 * The ObjectTypeAttributes structure.
 *===========================================================================*/
/** \struct OpcUa_ObjectTypeAttributes
The attributes for an object type node.
 */
typedef struct _OpcUa_ObjectTypeAttributes
{
    OpcUa_UInt32        SpecifiedAttributes;
    OpcUa_LocalizedText DisplayName;
    OpcUa_LocalizedText Description;
    OpcUa_UInt32        WriteMask;
    OpcUa_UInt32        UserWriteMask;
    OpcUa_Boolean       IsAbstract;
}
OpcUa_ObjectTypeAttributes;

OPCUA_EXPORT OpcUa_Void       OpcUa_ObjectTypeAttributes_Initialize(OpcUa_ObjectTypeAttributes* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ObjectTypeAttributes_Clear(OpcUa_ObjectTypeAttributes* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ObjectTypeAttributes_GetSize(OpcUa_ObjectTypeAttributes* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ObjectTypeAttributes_Encode(OpcUa_ObjectTypeAttributes* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ObjectTypeAttributes_Decode(OpcUa_ObjectTypeAttributes* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ObjectTypeAttributes_Compare(const OpcUa_ObjectTypeAttributes* pValue1, const OpcUa_ObjectTypeAttributes* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ObjectTypeAttributes_Copy(const OpcUa_ObjectTypeAttributes* pSource, OpcUa_ObjectTypeAttributes** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ObjectTypeAttributes_CopyTo(const OpcUa_ObjectTypeAttributes* pSource, OpcUa_ObjectTypeAttributes* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ObjectTypeAttributes_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_VariableTypeAttributes
/*============================================================================
 * The VariableTypeAttributes structure.
 *===========================================================================*/
/** \struct OpcUa_VariableTypeAttributes
The attributes for a variable type node.
 */
typedef struct _OpcUa_VariableTypeAttributes
{
    OpcUa_UInt32        SpecifiedAttributes;
    OpcUa_LocalizedText DisplayName;
    OpcUa_LocalizedText Description;
    OpcUa_UInt32        WriteMask;
    OpcUa_UInt32        UserWriteMask;
    OpcUa_Variant       Value;
    OpcUa_NodeId        DataType;
    OpcUa_Int32         ValueRank;
    OpcUa_Int32         NoOfArrayDimensions;
    OpcUa_UInt32*       ArrayDimensions;
    OpcUa_Boolean       IsAbstract;
}
OpcUa_VariableTypeAttributes;

OPCUA_EXPORT OpcUa_Void       OpcUa_VariableTypeAttributes_Initialize(OpcUa_VariableTypeAttributes* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_VariableTypeAttributes_Clear(OpcUa_VariableTypeAttributes* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_VariableTypeAttributes_GetSize(OpcUa_VariableTypeAttributes* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_VariableTypeAttributes_Encode(OpcUa_VariableTypeAttributes* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_VariableTypeAttributes_Decode(OpcUa_VariableTypeAttributes* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_VariableTypeAttributes_Compare(const OpcUa_VariableTypeAttributes* pValue1, const OpcUa_VariableTypeAttributes* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_VariableTypeAttributes_Copy(const OpcUa_VariableTypeAttributes* pSource, OpcUa_VariableTypeAttributes** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_VariableTypeAttributes_CopyTo(const OpcUa_VariableTypeAttributes* pSource, OpcUa_VariableTypeAttributes* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_VariableTypeAttributes_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ReferenceTypeAttributes
/*============================================================================
 * The ReferenceTypeAttributes structure.
 *===========================================================================*/
/** \struct OpcUa_ReferenceTypeAttributes
The attributes for a reference type node.
 */
typedef struct _OpcUa_ReferenceTypeAttributes
{
    OpcUa_UInt32        SpecifiedAttributes;
    OpcUa_LocalizedText DisplayName;
    OpcUa_LocalizedText Description;
    OpcUa_UInt32        WriteMask;
    OpcUa_UInt32        UserWriteMask;
    OpcUa_Boolean       IsAbstract;
    OpcUa_Boolean       Symmetric;
    OpcUa_LocalizedText InverseName;
}
OpcUa_ReferenceTypeAttributes;

OPCUA_EXPORT OpcUa_Void       OpcUa_ReferenceTypeAttributes_Initialize(OpcUa_ReferenceTypeAttributes* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ReferenceTypeAttributes_Clear(OpcUa_ReferenceTypeAttributes* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReferenceTypeAttributes_GetSize(OpcUa_ReferenceTypeAttributes* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReferenceTypeAttributes_Encode(OpcUa_ReferenceTypeAttributes* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReferenceTypeAttributes_Decode(OpcUa_ReferenceTypeAttributes* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ReferenceTypeAttributes_Compare(const OpcUa_ReferenceTypeAttributes* pValue1, const OpcUa_ReferenceTypeAttributes* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReferenceTypeAttributes_Copy(const OpcUa_ReferenceTypeAttributes* pSource, OpcUa_ReferenceTypeAttributes** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReferenceTypeAttributes_CopyTo(const OpcUa_ReferenceTypeAttributes* pSource, OpcUa_ReferenceTypeAttributes* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ReferenceTypeAttributes_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_DataTypeAttributes
/*============================================================================
 * The DataTypeAttributes structure.
 *===========================================================================*/
/** \struct OpcUa_DataTypeAttributes
The attributes for a data type node.
 */
typedef struct _OpcUa_DataTypeAttributes
{
    OpcUa_UInt32        SpecifiedAttributes;
    OpcUa_LocalizedText DisplayName;
    OpcUa_LocalizedText Description;
    OpcUa_UInt32        WriteMask;
    OpcUa_UInt32        UserWriteMask;
    OpcUa_Boolean       IsAbstract;
}
OpcUa_DataTypeAttributes;

OPCUA_EXPORT OpcUa_Void       OpcUa_DataTypeAttributes_Initialize(OpcUa_DataTypeAttributes* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_DataTypeAttributes_Clear(OpcUa_DataTypeAttributes* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DataTypeAttributes_GetSize(OpcUa_DataTypeAttributes* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DataTypeAttributes_Encode(OpcUa_DataTypeAttributes* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DataTypeAttributes_Decode(OpcUa_DataTypeAttributes* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_DataTypeAttributes_Compare(const OpcUa_DataTypeAttributes* pValue1, const OpcUa_DataTypeAttributes* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_DataTypeAttributes_Copy(const OpcUa_DataTypeAttributes* pSource, OpcUa_DataTypeAttributes** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DataTypeAttributes_CopyTo(const OpcUa_DataTypeAttributes* pSource, OpcUa_DataTypeAttributes* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_DataTypeAttributes_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ViewAttributes
/*============================================================================
 * The ViewAttributes structure.
 *===========================================================================*/
/** \struct OpcUa_ViewAttributes
The attributes for a view node.
 */
typedef struct _OpcUa_ViewAttributes
{
    OpcUa_UInt32        SpecifiedAttributes;
    OpcUa_LocalizedText DisplayName;
    OpcUa_LocalizedText Description;
    OpcUa_UInt32        WriteMask;
    OpcUa_UInt32        UserWriteMask;
    OpcUa_Boolean       ContainsNoLoops;
    OpcUa_Byte          EventNotifier;
}
OpcUa_ViewAttributes;

OPCUA_EXPORT OpcUa_Void       OpcUa_ViewAttributes_Initialize(OpcUa_ViewAttributes* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ViewAttributes_Clear(OpcUa_ViewAttributes* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ViewAttributes_GetSize(OpcUa_ViewAttributes* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ViewAttributes_Encode(OpcUa_ViewAttributes* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ViewAttributes_Decode(OpcUa_ViewAttributes* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ViewAttributes_Compare(const OpcUa_ViewAttributes* pValue1, const OpcUa_ViewAttributes* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ViewAttributes_Copy(const OpcUa_ViewAttributes* pSource, OpcUa_ViewAttributes** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ViewAttributes_CopyTo(const OpcUa_ViewAttributes* pSource, OpcUa_ViewAttributes* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ViewAttributes_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_AddNodesItem
/*============================================================================
 * The AddNodesItem structure.
 *===========================================================================*/
/** \struct OpcUa_AddNodesItem
 *  A structure that is defined as the type of the nodesToAdd parameter of the
 *  AddNodes Service.
 *
 *  \var OpcUa_AddNodesItem::ParentNodeId
 *  ExpandedNodeId of the parent node for the reference.
 *
 *  \var OpcUa_AddNodesItem::ReferenceTypeId
 *  NodeId of the hierarchical ReferenceType to use for the reference from the
 *  parent node to the new node.
 *
 *  \var OpcUa_AddNodesItem::RequestedNewNodeId
 *  Client requested expanded NodeId of the node to add. The server index in the
 *  expanded NodeId shall be 0.
 *
 *  If the Server cannot use this NodeId, it rejects this node and returns the
 *  appropriate error code.
 *
 *  If the Client does not want to request a NodeId, it sets the value of this
 *  parameter to the null expanded NodeId.
 *
 *  If the node to add is a ReferenceType node, its NodeId should be a numeric id.
 *  See Part 3 of the OPC UA specification for a description of ReferenceType
 *  NodeIds.
 *
 *  \var OpcUa_AddNodesItem::BrowseName
 *  The browse name of the node to add.
 *
 *  \var OpcUa_AddNodesItem::NodeClass
 *  NodeClass of the node to add.
 *
 *  \var OpcUa_AddNodesItem::NodeAttributes
 *  The attributes that are specific to the NodeClass.
 *
 *  A Client is allowed to omit values for some or all attributes. If an attribute
 *  value is omitted, the Server shall use the default values from the
 *  TypeDefinitionNode. If a TypeDefinitionNode was not provided, the Server shall
 *  choose a suitable default value.
 *
 *  The Server may still add an optional attribute to the node with an appropriate
 *  default value even if the Client does not specify a value.
 *
 *  \var OpcUa_AddNodesItem::TypeDefinition
 *  NodeId of the TypeDefinitionNode for the node to add.
 *
 *  This parameter shall be null for all node classes other than object and
 *  Variable, in which case it shall be provided.
 */
typedef struct _OpcUa_AddNodesItem
{
    OpcUa_ExpandedNodeId  ParentNodeId;
    OpcUa_NodeId          ReferenceTypeId;
    OpcUa_ExpandedNodeId  RequestedNewNodeId;
    OpcUa_QualifiedName   BrowseName;
    OpcUa_NodeClass       NodeClass;
    OpcUa_ExtensionObject NodeAttributes;
    OpcUa_ExpandedNodeId  TypeDefinition;
}
OpcUa_AddNodesItem;

OPCUA_EXPORT OpcUa_Void       OpcUa_AddNodesItem_Initialize(OpcUa_AddNodesItem* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_AddNodesItem_Clear(OpcUa_AddNodesItem* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddNodesItem_GetSize(OpcUa_AddNodesItem* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddNodesItem_Encode(OpcUa_AddNodesItem* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddNodesItem_Decode(OpcUa_AddNodesItem* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_AddNodesItem_Compare(const OpcUa_AddNodesItem* pValue1, const OpcUa_AddNodesItem* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddNodesItem_Copy(const OpcUa_AddNodesItem* pSource, OpcUa_AddNodesItem** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddNodesItem_CopyTo(const OpcUa_AddNodesItem* pSource, OpcUa_AddNodesItem* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_AddNodesItem_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_AddNodesResult
/*============================================================================
 * The AddNodesResult structure.
 *===========================================================================*/
/** \struct OpcUa_AddNodesResult
 *  A structure that is defined as the type of the results parameter of the
 *  AddNodes Service.
 *
 *  \var OpcUa_AddNodesResult::StatusCode
 *  StatusCode for the node to add.
 *
 *  \var OpcUa_AddNodesResult::AddedNodeId
 *  Server assigned NodeId of the added node.
 *
 *  Null NodeId if the operation failed.
 */
typedef struct _OpcUa_AddNodesResult
{
    OpcUa_StatusCode StatusCode;
    OpcUa_NodeId     AddedNodeId;
}
OpcUa_AddNodesResult;

OPCUA_EXPORT OpcUa_Void       OpcUa_AddNodesResult_Initialize(OpcUa_AddNodesResult* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_AddNodesResult_Clear(OpcUa_AddNodesResult* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddNodesResult_GetSize(OpcUa_AddNodesResult* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddNodesResult_Encode(OpcUa_AddNodesResult* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddNodesResult_Decode(OpcUa_AddNodesResult* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_AddNodesResult_Compare(const OpcUa_AddNodesResult* pValue1, const OpcUa_AddNodesResult* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddNodesResult_Copy(const OpcUa_AddNodesResult* pSource, OpcUa_AddNodesResult** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddNodesResult_CopyTo(const OpcUa_AddNodesResult* pSource, OpcUa_AddNodesResult* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_AddNodesResult_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_AddNodes
#ifndef OPCUA_EXCLUDE_AddNodesRequest
/*============================================================================
 * The AddNodesRequest structure.
 *===========================================================================*/
/** \struct OpcUa_AddNodesRequest
 *  Asynchronously adds one or more nodes into the address space hierarchy.
 *
 *  Using this service, each node is added as the target node of a hierarchical
 *  reference to ensure that the address space is fully connected and that the node
 *  is added as a child within the address space hierarchy (see Part 3 of the OPC
 *  UA Specification).
 *
 *  \var OpcUa_AddNodesRequest::NodesToAdd
 *  List of nodes to add.
 *
 *  All nodes are added as a reference to an existing node using a hierarchical
 *  ReferenceType.
 */
typedef struct _OpcUa_AddNodesRequest
{
    OpcUa_RequestHeader RequestHeader;
    OpcUa_Int32         NoOfNodesToAdd;
    OpcUa_AddNodesItem* NodesToAdd;
}
OpcUa_AddNodesRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_AddNodesRequest_Initialize(OpcUa_AddNodesRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_AddNodesRequest_Clear(OpcUa_AddNodesRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddNodesRequest_GetSize(OpcUa_AddNodesRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddNodesRequest_Encode(OpcUa_AddNodesRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddNodesRequest_Decode(OpcUa_AddNodesRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_AddNodesRequest_Compare(const OpcUa_AddNodesRequest* pValue1, const OpcUa_AddNodesRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddNodesRequest_Copy(const OpcUa_AddNodesRequest* pSource, OpcUa_AddNodesRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddNodesRequest_CopyTo(const OpcUa_AddNodesRequest* pSource, OpcUa_AddNodesRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_AddNodesRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_AddNodes */

#ifndef OPCUA_EXCLUDE_AddNodes
#ifndef OPCUA_EXCLUDE_AddNodesResponse
/*============================================================================
 * The AddNodesResponse structure.
 *===========================================================================*/
/** \struct OpcUa_AddNodesResponse
 *
 * Response to a \ref OpcUa_AddNodesRequest.
 *
 *  \var OpcUa_AddNodesResponse::Results
 *  List of results for the Nodes to add.
 *
 *  The size and order of the list matches the size and order of the \ref
 *  OpcUa_AddNodesRequest::NodesToAdd request parameter.
 *
 *  \var OpcUa_AddNodesResponse::DiagnosticInfos
 *  List of diagnostic information for the nodes to add.
 *
 *  The size and order of the list matches the size and order of the \ref
 *  OpcUa_AddNodesRequest::NodesToAdd request parameter. This list is empty if
 *  diagnostics information was not requested in the request header or if no
 *  diagnostic information was encountered in processing of the request.
 */
typedef struct _OpcUa_AddNodesResponse
{
    OpcUa_ResponseHeader  ResponseHeader;
    OpcUa_Int32           NoOfResults;
    OpcUa_AddNodesResult* Results;
    OpcUa_Int32           NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo* DiagnosticInfos;
}
OpcUa_AddNodesResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_AddNodesResponse_Initialize(OpcUa_AddNodesResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_AddNodesResponse_Clear(OpcUa_AddNodesResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddNodesResponse_GetSize(OpcUa_AddNodesResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddNodesResponse_Encode(OpcUa_AddNodesResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddNodesResponse_Decode(OpcUa_AddNodesResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_AddNodesResponse_Compare(const OpcUa_AddNodesResponse* pValue1, const OpcUa_AddNodesResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddNodesResponse_Copy(const OpcUa_AddNodesResponse* pSource, OpcUa_AddNodesResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddNodesResponse_CopyTo(const OpcUa_AddNodesResponse* pSource, OpcUa_AddNodesResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_AddNodesResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_AddNodes */

#ifndef OPCUA_EXCLUDE_AddReferencesItem
/*============================================================================
 * The AddReferencesItem structure.
 *===========================================================================*/
/** \struct OpcUa_AddReferencesItem
 *  A structure that is defined as the type of the referencesToAdd parameter of the
 *  AddReferences Service.
 *
 *  \var OpcUa_AddReferencesItem::SourceNodeId
 *  NodeId of the node to which the reference is to be added.
 *
 *  The source node shall always exist in the Server to add the reference. The
 *  IsForward parameter can be set to FALSE if the target node is on the local
 *  Server and the source node on the remote Server.
 *
 *  \var OpcUa_AddReferencesItem::ReferenceTypeId
 *  NodeId of the ReferenceType that defines the reference.
 *
 *  \var OpcUa_AddReferencesItem::IsForward
 *  If the value is TRUE, the Server creates a forward reference; if the value is
 *  FALSE, the Server creates an inverse Reference.
 *
 *  \var OpcUa_AddReferencesItem::TargetServerUri
 *  URI of the remote Server.
 *
 *  If this parameter is not null, it overrides the serverIndex in the
 *  TargetNodeId.
 *
 *  \var OpcUa_AddReferencesItem::TargetNodeId
 *  Expanded NodeId of the target node.
 *
 *  \var OpcUa_AddReferencesItem::TargetNodeClass
 *  NodeClass of the target node.
 *
 *  The Client shall specify this since the target node might not be accessible
 *  directly by the Server.
 */
typedef struct _OpcUa_AddReferencesItem
{
    OpcUa_NodeId         SourceNodeId;
    OpcUa_NodeId         ReferenceTypeId;
    OpcUa_Boolean        IsForward;
    OpcUa_String         TargetServerUri;
    OpcUa_ExpandedNodeId TargetNodeId;
    OpcUa_NodeClass      TargetNodeClass;
}
OpcUa_AddReferencesItem;

OPCUA_EXPORT OpcUa_Void       OpcUa_AddReferencesItem_Initialize(OpcUa_AddReferencesItem* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_AddReferencesItem_Clear(OpcUa_AddReferencesItem* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddReferencesItem_GetSize(OpcUa_AddReferencesItem* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddReferencesItem_Encode(OpcUa_AddReferencesItem* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddReferencesItem_Decode(OpcUa_AddReferencesItem* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_AddReferencesItem_Compare(const OpcUa_AddReferencesItem* pValue1, const OpcUa_AddReferencesItem* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddReferencesItem_Copy(const OpcUa_AddReferencesItem* pSource, OpcUa_AddReferencesItem** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddReferencesItem_CopyTo(const OpcUa_AddReferencesItem* pSource, OpcUa_AddReferencesItem* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_AddReferencesItem_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_AddReferences
#ifndef OPCUA_EXCLUDE_AddReferencesRequest
/*============================================================================
 * The AddReferencesRequest structure.
 *===========================================================================*/
/** \struct OpcUa_AddReferencesRequest
 *  Asynchronously adds one or more references to one or more nodes.
 *
 *  The NodeClass is an input parameter that is used to validate that the reference
 *  to be added matches the NodeClass of the target node. This parameter is not
 *  validated if the reference refers to a target node in a remote Server.
 *
 *  In certain cases, adding new references to the address space shall require that
 *  the Server add new Server ids to the Server’s ServerArray variable. For this
 *  reason, remote Servers are identified by their URI and not by their ServerArray
 *  index. This allows the Server to add the remote Server URIs to its ServerArray.
 *
 *  \var OpcUa_AddReferencesRequest::ReferencesToAdd
 *  List of reference instances to add to the source node.
 *
 *  The \ref OpcUa_AddReferencesItem::TargetNodeClass of each reference in the list
 *  shall match the node class of the target node.
 */
typedef struct _OpcUa_AddReferencesRequest
{
    OpcUa_RequestHeader      RequestHeader;
    OpcUa_Int32              NoOfReferencesToAdd;
    OpcUa_AddReferencesItem* ReferencesToAdd;
}
OpcUa_AddReferencesRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_AddReferencesRequest_Initialize(OpcUa_AddReferencesRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_AddReferencesRequest_Clear(OpcUa_AddReferencesRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddReferencesRequest_GetSize(OpcUa_AddReferencesRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddReferencesRequest_Encode(OpcUa_AddReferencesRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddReferencesRequest_Decode(OpcUa_AddReferencesRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_AddReferencesRequest_Compare(const OpcUa_AddReferencesRequest* pValue1, const OpcUa_AddReferencesRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddReferencesRequest_Copy(const OpcUa_AddReferencesRequest* pSource, OpcUa_AddReferencesRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddReferencesRequest_CopyTo(const OpcUa_AddReferencesRequest* pSource, OpcUa_AddReferencesRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_AddReferencesRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_AddReferences */

#ifndef OPCUA_EXCLUDE_AddReferences
#ifndef OPCUA_EXCLUDE_AddReferencesResponse
/*============================================================================
 * The AddReferencesResponse structure.
 *===========================================================================*/
/** \struct OpcUa_AddReferencesResponse
 *
 * Response to a \ref OpcUa_AddReferencesRequest.
 *
 *  \var OpcUa_AddReferencesResponse::Results
 *  List of StatusCodes for the references to add.
 *
 *  The size and order of the list matches the size and order of the \ref
 *  OpcUa_AddReferencesRequest::ReferencesToAdd request parameter.
 *
 *  \var OpcUa_AddReferencesResponse::DiagnosticInfos
 *  List of diagnostic information for the references to add.
 *
 *  The size and order of the list matches the size and order of the \ref
 *  OpcUa_AddReferencesRequest::ReferencesToAdd request parameter. This list is
 *  empty if diagnostics information was not requested in the request header or if
 *  no diagnostic information was encountered in processing of the request.
 */
typedef struct _OpcUa_AddReferencesResponse
{
    OpcUa_ResponseHeader  ResponseHeader;
    OpcUa_Int32           NoOfResults;
    OpcUa_StatusCode*     Results;
    OpcUa_Int32           NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo* DiagnosticInfos;
}
OpcUa_AddReferencesResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_AddReferencesResponse_Initialize(OpcUa_AddReferencesResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_AddReferencesResponse_Clear(OpcUa_AddReferencesResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddReferencesResponse_GetSize(OpcUa_AddReferencesResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddReferencesResponse_Encode(OpcUa_AddReferencesResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddReferencesResponse_Decode(OpcUa_AddReferencesResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_AddReferencesResponse_Compare(const OpcUa_AddReferencesResponse* pValue1, const OpcUa_AddReferencesResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddReferencesResponse_Copy(const OpcUa_AddReferencesResponse* pSource, OpcUa_AddReferencesResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AddReferencesResponse_CopyTo(const OpcUa_AddReferencesResponse* pSource, OpcUa_AddReferencesResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_AddReferencesResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_AddReferences */

#ifndef OPCUA_EXCLUDE_DeleteNodesItem
/*============================================================================
 * The DeleteNodesItem structure.
 *===========================================================================*/
/** \struct OpcUa_DeleteNodesItem
 *  A structure that is defined as the type of the nodesToDelete parameter of the
 *  DeleteNodes Service.
 *
 *  \var OpcUa_DeleteNodesItem::NodeId
 *  NodeId of the node to delete.
 *
 *  \var OpcUa_DeleteNodesItem::DeleteTargetReferences
 *  A boolean parameter indicating whether to delete references for which the node
 *  to delete is the target node.
 *
 *  It has the following values: <dl> <dt>TRUE</dt> <dd>delete References in
 *  TargetNodes that Reference the Node to delete.</dd> <dt>FALSE</dt> <dd>delete
 *  only the References for which the Node to delete is the source.</dd> </dl>
 *
 *  The Server cannot guarantee that it is able to delete all references from
 *  target nodes if this parameter is TRUE.
 */
typedef struct _OpcUa_DeleteNodesItem
{
    OpcUa_NodeId  NodeId;
    OpcUa_Boolean DeleteTargetReferences;
}
OpcUa_DeleteNodesItem;

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteNodesItem_Initialize(OpcUa_DeleteNodesItem* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteNodesItem_Clear(OpcUa_DeleteNodesItem* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteNodesItem_GetSize(OpcUa_DeleteNodesItem* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteNodesItem_Encode(OpcUa_DeleteNodesItem* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteNodesItem_Decode(OpcUa_DeleteNodesItem* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_DeleteNodesItem_Compare(const OpcUa_DeleteNodesItem* pValue1, const OpcUa_DeleteNodesItem* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteNodesItem_Copy(const OpcUa_DeleteNodesItem* pSource, OpcUa_DeleteNodesItem** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteNodesItem_CopyTo(const OpcUa_DeleteNodesItem* pSource, OpcUa_DeleteNodesItem* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_DeleteNodesItem_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_DeleteNodes
#ifndef OPCUA_EXCLUDE_DeleteNodesRequest
/*============================================================================
 * The DeleteNodesRequest structure.
 *===========================================================================*/
/** \struct OpcUa_DeleteNodesRequest
 *  Asynchronously deletes nodes from the OPC UA server’s address space.
 *
 *  If any of the Nodes deleted by an invocation of this service is the target node
 *  of a reference, those references are left unresolved based on the
 *  deleteTargetReferences parameter.
 *
 *  If any of the nodes deleted by an invocation of this service is being
 *  monitored, a notification containing the status code Bad_NodeIdUnknown is sent
 *  to the monitoring Client indicating that the node has been deleted.
 *
 *  \var OpcUa_DeleteNodesRequest::NodesToDelete
 *  List of nodes to delete.
 */
typedef struct _OpcUa_DeleteNodesRequest
{
    OpcUa_RequestHeader    RequestHeader;
    OpcUa_Int32            NoOfNodesToDelete;
    OpcUa_DeleteNodesItem* NodesToDelete;
}
OpcUa_DeleteNodesRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteNodesRequest_Initialize(OpcUa_DeleteNodesRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteNodesRequest_Clear(OpcUa_DeleteNodesRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteNodesRequest_GetSize(OpcUa_DeleteNodesRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteNodesRequest_Encode(OpcUa_DeleteNodesRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteNodesRequest_Decode(OpcUa_DeleteNodesRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_DeleteNodesRequest_Compare(const OpcUa_DeleteNodesRequest* pValue1, const OpcUa_DeleteNodesRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteNodesRequest_Copy(const OpcUa_DeleteNodesRequest* pSource, OpcUa_DeleteNodesRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteNodesRequest_CopyTo(const OpcUa_DeleteNodesRequest* pSource, OpcUa_DeleteNodesRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_DeleteNodesRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_DeleteNodes */

#ifndef OPCUA_EXCLUDE_DeleteNodes
#ifndef OPCUA_EXCLUDE_DeleteNodesResponse
/*============================================================================
 * The DeleteNodesResponse structure.
 *===========================================================================*/
/** \struct OpcUa_DeleteNodesResponse
 *
 * Response to a \ref OpcUa_DeleteNodesRequest.
 *
 *  \var OpcUa_DeleteNodesResponse::Results
 *  List of StatusCodes for the nodes to delete.
 *
 *  The size and order of the list matches the size and order of the list of the
 *  \ref OpcUa_DeleteNodesRequest::NodesToDelete request parameter.
 *
 *  \var OpcUa_DeleteNodesResponse::DiagnosticInfos
 *  List of diagnostic information for the nodes to delete.
 *
 *  The size and order of the list matches the size and order of the \ref
 *  OpcUa_DeleteNodesRequest::NodesToDelete request parameter. This list is empty
 *  if diagnostics information was not requested in the request header or if no
 *  diagnostic information was encountered in processing of the request.
 */
typedef struct _OpcUa_DeleteNodesResponse
{
    OpcUa_ResponseHeader  ResponseHeader;
    OpcUa_Int32           NoOfResults;
    OpcUa_StatusCode*     Results;
    OpcUa_Int32           NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo* DiagnosticInfos;
}
OpcUa_DeleteNodesResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteNodesResponse_Initialize(OpcUa_DeleteNodesResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteNodesResponse_Clear(OpcUa_DeleteNodesResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteNodesResponse_GetSize(OpcUa_DeleteNodesResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteNodesResponse_Encode(OpcUa_DeleteNodesResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteNodesResponse_Decode(OpcUa_DeleteNodesResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_DeleteNodesResponse_Compare(const OpcUa_DeleteNodesResponse* pValue1, const OpcUa_DeleteNodesResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteNodesResponse_Copy(const OpcUa_DeleteNodesResponse* pSource, OpcUa_DeleteNodesResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteNodesResponse_CopyTo(const OpcUa_DeleteNodesResponse* pSource, OpcUa_DeleteNodesResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_DeleteNodesResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_DeleteNodes */

#ifndef OPCUA_EXCLUDE_DeleteReferencesItem
/*============================================================================
 * The DeleteReferencesItem structure.
 *===========================================================================*/
/** \struct OpcUa_DeleteReferencesItem
 *  A structure that is defined as the type of the referencesToDelete parameter of
 *  the DeleteReferences service.
 *
 *  \var OpcUa_DeleteReferencesItem::SourceNodeId
 *  NodeId of the node that contains the reference to delete.
 *
 *  \var OpcUa_DeleteReferencesItem::ReferenceTypeId
 *  NodeId of the ReferenceType that defines the reference to delete.
 *
 *  \var OpcUa_DeleteReferencesItem::IsForward
 *  If the value is TRUE, the Server deletes a forward Reference.
 *
 *  If the value is FALSE, the Server deletes an inverse Reference.
 *
 *  \var OpcUa_DeleteReferencesItem::TargetNodeId
 *  NodeId of the target node of the reference.
 *
 *  If the Server index indicates that the target node is a remote node, then the
 *  nodeId shall contain the absolute namespace URI. If the target node is a local
 *  node the nodeId shall contain the namespace index.
 *
 *  \var OpcUa_DeleteReferencesItem::DeleteBidirectional
 *  A boolean parameter indicating whether the opposite reference from the target
 *  node should be deleted together with the node to delete.
 *
 *  It has the following values: <dl> <dt>TRUE</dt> <dd>delete the specified
 *  Reference and the opposite reference from the target node. If the target node
 *  is located in a remote Server, the Server is permitted to delete the specified
 *  reference only.</dd> <dt>FALSE</dt> <dd>delete only the specified
 *  reference.</dd> </dl>
 */
typedef struct _OpcUa_DeleteReferencesItem
{
    OpcUa_NodeId         SourceNodeId;
    OpcUa_NodeId         ReferenceTypeId;
    OpcUa_Boolean        IsForward;
    OpcUa_ExpandedNodeId TargetNodeId;
    OpcUa_Boolean        DeleteBidirectional;
}
OpcUa_DeleteReferencesItem;

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteReferencesItem_Initialize(OpcUa_DeleteReferencesItem* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteReferencesItem_Clear(OpcUa_DeleteReferencesItem* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteReferencesItem_GetSize(OpcUa_DeleteReferencesItem* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteReferencesItem_Encode(OpcUa_DeleteReferencesItem* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteReferencesItem_Decode(OpcUa_DeleteReferencesItem* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_DeleteReferencesItem_Compare(const OpcUa_DeleteReferencesItem* pValue1, const OpcUa_DeleteReferencesItem* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteReferencesItem_Copy(const OpcUa_DeleteReferencesItem* pSource, OpcUa_DeleteReferencesItem** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteReferencesItem_CopyTo(const OpcUa_DeleteReferencesItem* pSource, OpcUa_DeleteReferencesItem* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_DeleteReferencesItem_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_DeleteReferences
#ifndef OPCUA_EXCLUDE_DeleteReferencesRequest
/*============================================================================
 * The DeleteReferencesRequest structure.
 *===========================================================================*/
/** \struct OpcUa_DeleteReferencesRequest
 *  Asynchronously deletes references from the OPC UA server’s address space.
 *
 *  If any of the references deleted by an invocation of this service are contained
 *  in a view, then the ViewVersion property is updated if this property is
 *  supported.
 *
 *  \var OpcUa_DeleteReferencesRequest::ReferencesToDelete
 *  List of references to delete.
 */
typedef struct _OpcUa_DeleteReferencesRequest
{
    OpcUa_RequestHeader         RequestHeader;
    OpcUa_Int32                 NoOfReferencesToDelete;
    OpcUa_DeleteReferencesItem* ReferencesToDelete;
}
OpcUa_DeleteReferencesRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteReferencesRequest_Initialize(OpcUa_DeleteReferencesRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteReferencesRequest_Clear(OpcUa_DeleteReferencesRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteReferencesRequest_GetSize(OpcUa_DeleteReferencesRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteReferencesRequest_Encode(OpcUa_DeleteReferencesRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteReferencesRequest_Decode(OpcUa_DeleteReferencesRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_DeleteReferencesRequest_Compare(const OpcUa_DeleteReferencesRequest* pValue1, const OpcUa_DeleteReferencesRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteReferencesRequest_Copy(const OpcUa_DeleteReferencesRequest* pSource, OpcUa_DeleteReferencesRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteReferencesRequest_CopyTo(const OpcUa_DeleteReferencesRequest* pSource, OpcUa_DeleteReferencesRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_DeleteReferencesRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_DeleteReferences */

#ifndef OPCUA_EXCLUDE_DeleteReferences
#ifndef OPCUA_EXCLUDE_DeleteReferencesResponse
/*============================================================================
 * The DeleteReferencesResponse structure.
 *===========================================================================*/
/** \struct OpcUa_DeleteReferencesResponse
 *
 * Response to a \ref OpcUa_DeleteReferencesRequest.
 *
 *  \var OpcUa_DeleteReferencesResponse::Results
 *  List of StatusCodes for the references to delete.
 *
 *  The size and order of the list matches the size and order of the \ref
 *  OpcUa_DeleteReferencesRequest::ReferencesToDelete request parameter.
 *
 *  \var OpcUa_DeleteReferencesResponse::DiagnosticInfos
 *  List of diagnostic information for the references to delete.
 *
 *  The size and order of the list matches the size and order of the \ref
 *  OpcUa_DeleteReferencesRequest::ReferencesToDelete request parameter. This list
 *  is empty if diagnostics information was not requested in the request header or
 *  if no diagnostic information was encountered in processing of the request.
 */
typedef struct _OpcUa_DeleteReferencesResponse
{
    OpcUa_ResponseHeader  ResponseHeader;
    OpcUa_Int32           NoOfResults;
    OpcUa_StatusCode*     Results;
    OpcUa_Int32           NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo* DiagnosticInfos;
}
OpcUa_DeleteReferencesResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteReferencesResponse_Initialize(OpcUa_DeleteReferencesResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteReferencesResponse_Clear(OpcUa_DeleteReferencesResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteReferencesResponse_GetSize(OpcUa_DeleteReferencesResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteReferencesResponse_Encode(OpcUa_DeleteReferencesResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteReferencesResponse_Decode(OpcUa_DeleteReferencesResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_DeleteReferencesResponse_Compare(const OpcUa_DeleteReferencesResponse* pValue1, const OpcUa_DeleteReferencesResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteReferencesResponse_Copy(const OpcUa_DeleteReferencesResponse* pSource, OpcUa_DeleteReferencesResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteReferencesResponse_CopyTo(const OpcUa_DeleteReferencesResponse* pSource, OpcUa_DeleteReferencesResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_DeleteReferencesResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_DeleteReferences */

#ifndef OPCUA_EXCLUDE_ViewDescription
/*============================================================================
 * The ViewDescription structure.
 *===========================================================================*/
/** \struct OpcUa_ViewDescription
 *  Specifies a View.
 *
 *  \var OpcUa_ViewDescription::ViewId
 *  NodeId of the View to Query. A null value indicates the entire AddressSpace.
 *
 *  \var OpcUa_ViewDescription::Timestamp
 *  The time date desired.
 *
 *  The corresponding version is the one with the closest previous creation
 *  timestamp. Either the Timestamp or the viewVersion parameter may be set by a
 *  Client, but not both. If ViewVersion is set this parameter shall be null.
 *
 *  \var OpcUa_ViewDescription::ViewVersion
 *  The version number for the View desired.
 *
 *  When Nodes are added to or removed from a View, the value of a View’s
 *  ViewVersion Property is updated. Either the Timestamp or the viewVersion
 *  parameter may be set by a Client, but not both. The ViewVersion Property is
 *  defined in Part 3. If timestamp is set this parameter shall be 0. The current
 *  view is used if timestamp is null and viewVersion is 0.
 */
typedef struct _OpcUa_ViewDescription
{
    OpcUa_NodeId   ViewId;
    OpcUa_DateTime Timestamp;
    OpcUa_UInt32   ViewVersion;
}
OpcUa_ViewDescription;

OPCUA_EXPORT OpcUa_Void       OpcUa_ViewDescription_Initialize(OpcUa_ViewDescription* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ViewDescription_Clear(OpcUa_ViewDescription* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ViewDescription_GetSize(OpcUa_ViewDescription* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ViewDescription_Encode(OpcUa_ViewDescription* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ViewDescription_Decode(OpcUa_ViewDescription* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ViewDescription_Compare(const OpcUa_ViewDescription* pValue1, const OpcUa_ViewDescription* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ViewDescription_Copy(const OpcUa_ViewDescription* pSource, OpcUa_ViewDescription** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ViewDescription_CopyTo(const OpcUa_ViewDescription* pSource, OpcUa_ViewDescription* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ViewDescription_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_BrowseDescription
/*============================================================================
 * The BrowseDescription structure.
 *===========================================================================*/
/** \struct OpcUa_BrowseDescription
 *  A structure defined as the type of the parameter nodesToBrowse of the Browse
 *  service.
 *
 *  \var OpcUa_BrowseDescription::NodeId
 *  NodeId of the Node to be browsed.
 *
 *  If a view is provided, it shall include this Node.
 *
 *  \var OpcUa_BrowseDescription::BrowseDirection
 *  An enumeration that specifies the direction of References to follow.
 *
 *  The returned references do indicate the direction the Server followed in the
 *  isForward parameter of the ReferenceDescription.
 *
 *  Symmetric references are always considered to be in forward direction,
 *  therefore the isForward flag is always set to TRUE and symmetric references are
 *  not returned if browseDirection is set to INVERSE_1.
 *
 *  \var OpcUa_BrowseDescription::ReferenceTypeId
 *  Specifies the NodeId of the ReferenceType to follow.
 *
 *  Only instances of this ReferenceType or its subtypes are returned.
 *
 *  If not specified, all References are returned and includeSubtypes is ignored.
 *
 *  \var OpcUa_BrowseDescription::IncludeSubtypes
 *  Indicates whether subtypes of the ReferenceType should be included in the
 *  browse.
 *
 *  If TRUE, then instances of referenceTypeId and all of its subtypes are
 *  returned.
 *
 *  \var OpcUa_BrowseDescription::NodeClassMask
 *  Specifies the NodeClasses of the TargetNodes.
 *
 *  Only TargetNodes with the selected NodeClasses are returned. The NodeClasses
 *  are assigned the following bits:
 *
 *  Bit  | Node Class
 *  -----|---------------
 *  0    | Object
 *  1    | Variable
 *  2    | Method
 *  3    | ObjectType
 *  4    | VariableType
 *  5    | ReferenceType
 *  6    | DataType
 *  7    | View
 *
 *  If set to zero, then all NodeClasses are returned.
 *
 *  \var OpcUa_BrowseDescription::ResultMask
 *  Specifies the fields in the ReferenceDescription structure that should be
 *  returned.
 *
 *  The fields are assigned the following bits:
 *
 *  Bit  | Result
 *  -----|----------------
 *  0    | ReferenceType
 *  1    | IsForward
 *  2    | NodeClass
 *  3    | BrowseName
 *  4    | DisplayName
 *  5    | TypeDefinition
 */
typedef struct _OpcUa_BrowseDescription
{
    OpcUa_NodeId          NodeId;
    OpcUa_BrowseDirection BrowseDirection;
    OpcUa_NodeId          ReferenceTypeId;
    OpcUa_Boolean         IncludeSubtypes;
    OpcUa_UInt32          NodeClassMask;
    OpcUa_UInt32          ResultMask;
}
OpcUa_BrowseDescription;

OPCUA_EXPORT OpcUa_Void       OpcUa_BrowseDescription_Initialize(OpcUa_BrowseDescription* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_BrowseDescription_Clear(OpcUa_BrowseDescription* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseDescription_GetSize(OpcUa_BrowseDescription* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseDescription_Encode(OpcUa_BrowseDescription* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseDescription_Decode(OpcUa_BrowseDescription* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_BrowseDescription_Compare(const OpcUa_BrowseDescription* pValue1, const OpcUa_BrowseDescription* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseDescription_Copy(const OpcUa_BrowseDescription* pSource, OpcUa_BrowseDescription** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseDescription_CopyTo(const OpcUa_BrowseDescription* pSource, OpcUa_BrowseDescription* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_BrowseDescription_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ReferenceDescription
/*============================================================================
 * The ReferenceDescription structure.
 *===========================================================================*/
/** \struct OpcUa_ReferenceDescription
 *  Reference parameters returned for the Browse Service.
 *
 *  \var OpcUa_ReferenceDescription::ReferenceTypeId
 *  NodeId of the ReferenceType that defines the Reference.
 *
 *  \var OpcUa_ReferenceDescription::IsForward
 *  If the value is TRUE, the Server followed a forward Reference. If the value is
 *  FALSE, the Server followed an inverse Reference.
 *
 *  \var OpcUa_ReferenceDescription::NodeId
 *  NodeId of the TargetNode as assigned by the Server identified by the Server
 *  index.
 *
 *  If the serverIndex indicates that the TargetNode is a remote Node, then the
 *  nodeId shall contain the absolute namespace URI. If the TargetNode is a local
 *  Node the nodeId shall contain the namespace index.
 *
 *  \var OpcUa_ReferenceDescription::BrowseName
 *  The BrowseName of the TargetNode.
 *
 *  \var OpcUa_ReferenceDescription::DisplayName
 *  The DisplayName of the TargetNode.
 *
 *  \var OpcUa_ReferenceDescription::NodeClass
 *  NodeClass of the TargetNode.
 *
 *  \var OpcUa_ReferenceDescription::TypeDefinition
 *  Type definition NodeId of the TargetNode.
 *
 *  Type definitions are only available for the NodeClasses object and Variable.
 *  For all other NodeClasses a null NodeId shall be returned.
 */
typedef struct _OpcUa_ReferenceDescription
{
    OpcUa_NodeId         ReferenceTypeId;
    OpcUa_Boolean        IsForward;
    OpcUa_ExpandedNodeId NodeId;
    OpcUa_QualifiedName  BrowseName;
    OpcUa_LocalizedText  DisplayName;
    OpcUa_NodeClass      NodeClass;
    OpcUa_ExpandedNodeId TypeDefinition;
}
OpcUa_ReferenceDescription;

OPCUA_EXPORT OpcUa_Void       OpcUa_ReferenceDescription_Initialize(OpcUa_ReferenceDescription* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ReferenceDescription_Clear(OpcUa_ReferenceDescription* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReferenceDescription_GetSize(OpcUa_ReferenceDescription* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReferenceDescription_Encode(OpcUa_ReferenceDescription* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReferenceDescription_Decode(OpcUa_ReferenceDescription* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ReferenceDescription_Compare(const OpcUa_ReferenceDescription* pValue1, const OpcUa_ReferenceDescription* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReferenceDescription_Copy(const OpcUa_ReferenceDescription* pSource, OpcUa_ReferenceDescription** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReferenceDescription_CopyTo(const OpcUa_ReferenceDescription* pSource, OpcUa_ReferenceDescription* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ReferenceDescription_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_BrowseResult
/*============================================================================
 * The BrowseResult structure.
 *===========================================================================*/
/** \struct OpcUa_BrowseResult
 *  The results of a Browse operation.
 *
 *  \var OpcUa_BrowseResult::StatusCode
 *  The status for the BrowseDescription.
 *
 *  This value is set to Good if there are still references to return for the
 *  BrowseDescription.
 *
 *  \var OpcUa_BrowseResult::ContinuationPoint
 *  A Server defined opaque value that identifies the continuation point.
 *
 *  \var OpcUa_BrowseResult::References
 *  The set of references that meet the criteria specified in the
 *  BrowseDescription.
 *
 *  Empty if no references met the criteria.
 */
typedef struct _OpcUa_BrowseResult
{
    OpcUa_StatusCode            StatusCode;
    OpcUa_ByteString            ContinuationPoint;
    OpcUa_Int32                 NoOfReferences;
    OpcUa_ReferenceDescription* References;
}
OpcUa_BrowseResult;

OPCUA_EXPORT OpcUa_Void       OpcUa_BrowseResult_Initialize(OpcUa_BrowseResult* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_BrowseResult_Clear(OpcUa_BrowseResult* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseResult_GetSize(OpcUa_BrowseResult* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseResult_Encode(OpcUa_BrowseResult* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseResult_Decode(OpcUa_BrowseResult* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_BrowseResult_Compare(const OpcUa_BrowseResult* pValue1, const OpcUa_BrowseResult* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseResult_Copy(const OpcUa_BrowseResult* pSource, OpcUa_BrowseResult** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseResult_CopyTo(const OpcUa_BrowseResult* pSource, OpcUa_BrowseResult* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_BrowseResult_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_Browse
#ifndef OPCUA_EXCLUDE_BrowseRequest
/*============================================================================
 * The BrowseRequest structure.
 *===========================================================================*/
/** \struct OpcUa_BrowseRequest
 *  The Browse service is used by a client to navigate through the address space by
 *  passing a starting node and browse filters. The server returns the list of
 *  referenced nodes matching the filter criteria.
 *
 *  The Browse service takes a list of starting nodes and returns a list of
 *  connected nodes for each starting node. Nevertheless, most clients will only
 *  pass one starting node for the main purpose of building a tree hierarchy. Since
 *  the OPC UA address space can be a full-meshed network and is not limited to a
 *  pure hierarchy, the capability to pass in a list of starting nodes is mainly
 *  used to browse metadata like the properties of a list of variables.
 *
 *  \var OpcUa_BrowseRequest::View
 *  Description of the View to browse.
 *
 *  An empty ViewDescription value indicates the entire address space. If
 *  ViewDescription is empty, all references of the node to browse are returned. If
 *  any other view is specified, only the references of the node to browse that are
 *  defined for that view are returned.
 *
 *  \var OpcUa_BrowseRequest::RequestedMaxReferencesPerNode
 *  Indicates the maximum number of references to return for each starting Node
 *  specified in the request.
 *
 *  The value 0 indicates that the Client is imposing no limitation.
 *
 *  \var OpcUa_BrowseRequest::NodesToBrowse
 *  A list of nodes to Browse
 */
typedef struct _OpcUa_BrowseRequest
{
    OpcUa_RequestHeader      RequestHeader;
    OpcUa_ViewDescription    View;
    OpcUa_UInt32             RequestedMaxReferencesPerNode;
    OpcUa_Int32              NoOfNodesToBrowse;
    OpcUa_BrowseDescription* NodesToBrowse;
}
OpcUa_BrowseRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_BrowseRequest_Initialize(OpcUa_BrowseRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_BrowseRequest_Clear(OpcUa_BrowseRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseRequest_GetSize(OpcUa_BrowseRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseRequest_Encode(OpcUa_BrowseRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseRequest_Decode(OpcUa_BrowseRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_BrowseRequest_Compare(const OpcUa_BrowseRequest* pValue1, const OpcUa_BrowseRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseRequest_Copy(const OpcUa_BrowseRequest* pSource, OpcUa_BrowseRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseRequest_CopyTo(const OpcUa_BrowseRequest* pSource, OpcUa_BrowseRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_BrowseRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_Browse */

#ifndef OPCUA_EXCLUDE_Browse
#ifndef OPCUA_EXCLUDE_BrowseResponse
/*============================================================================
 * The BrowseResponse structure.
 *===========================================================================*/
/** \struct OpcUa_BrowseResponse
 *
 * Response to a \ref OpcUa_BrowseRequest.
 *
 *  \var OpcUa_BrowseResponse::Results
 *  A list of BrowseResults.
 *
 *  The size and order of the list matches the size and order of the \ref
 *  OpcUa_BrowseRequest::NodesToBrowse specified in the request.
 *
 *  \var OpcUa_BrowseResponse::DiagnosticInfos
 *  List of diagnostic information for the results.
 *
 *  The size and order of the list matches the size and order of the \ref
 *  OpcUa_BrowseResponse::Results response parameter. This list is empty if
 *  diagnostics information was not requested in the request header or if no
 *  diagnostic information was encountered in processing of the request.
 */
typedef struct _OpcUa_BrowseResponse
{
    OpcUa_ResponseHeader  ResponseHeader;
    OpcUa_Int32           NoOfResults;
    OpcUa_BrowseResult*   Results;
    OpcUa_Int32           NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo* DiagnosticInfos;
}
OpcUa_BrowseResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_BrowseResponse_Initialize(OpcUa_BrowseResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_BrowseResponse_Clear(OpcUa_BrowseResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseResponse_GetSize(OpcUa_BrowseResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseResponse_Encode(OpcUa_BrowseResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseResponse_Decode(OpcUa_BrowseResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_BrowseResponse_Compare(const OpcUa_BrowseResponse* pValue1, const OpcUa_BrowseResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseResponse_Copy(const OpcUa_BrowseResponse* pSource, OpcUa_BrowseResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseResponse_CopyTo(const OpcUa_BrowseResponse* pSource, OpcUa_BrowseResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_BrowseResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_Browse */

#ifndef OPCUA_EXCLUDE_BrowseNext
#ifndef OPCUA_EXCLUDE_BrowseNextRequest
/*============================================================================
 * The BrowseNextRequest structure.
 *===========================================================================*/
/** \struct OpcUa_BrowseNextRequest
 *  The BrowseNext service is only used to continue a Browse if not all results
 *  could be returned by the Browse or a following BrowseNext call. The number of
 *  Nodes to return can be limited by the client in the Browse request or by the
 *  Server during processing the Browse Service call.
 *
 *  The BrowseNext shall be submitted on the same session that was used to submit
 *  the Browse or BrowseNext that is being continued.
 *
 *  \var OpcUa_BrowseNextRequest::ReleaseContinuationPoints
 *  A boolean parameter indicating whether continuation points should be released.
 *
 *  It has the following values: <dl> <dt>TRUE</dt> <dd>passed ContinuationPoints
 *  shall be reset to free resources in the Server. The continuation points are
 *  released and the results and diagnosticInfos arrays are empty.</dd>
 *  <dt>FALSE</dt> <dd>passed ContinuationPoints shall be used to get the next set
 *  of browse information.</dd> </dl>
 *
 *  A Client shall always use the continuation point returned by a Browse or
 *  BrowseNext response to free the resources for the continuation point in the
 *  Server. If the Client does not want to get the next set of browse information,
 *  BrowseNext shall be called with this parameter set to TRUE.
 *
 *  \var OpcUa_BrowseNextRequest::ContinuationPoints
 *  A list of Server-defined opaque values that represent continuation points.
 *
 *  The value for a continuation point was returned to the Client in a previous
 *  Browse or BrowseNext response. These values are used to identify the previously
 *  processed Browse or BrowseNext request that is being continued and the point in
 *  the result set from which the browse response is to continue.
 *
 *  Clients may mix continuation points from different Browse or BrowseNext
 *  responses.
 */
typedef struct _OpcUa_BrowseNextRequest
{
    OpcUa_RequestHeader RequestHeader;
    OpcUa_Boolean       ReleaseContinuationPoints;
    OpcUa_Int32         NoOfContinuationPoints;
    OpcUa_ByteString*   ContinuationPoints;
}
OpcUa_BrowseNextRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_BrowseNextRequest_Initialize(OpcUa_BrowseNextRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_BrowseNextRequest_Clear(OpcUa_BrowseNextRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseNextRequest_GetSize(OpcUa_BrowseNextRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseNextRequest_Encode(OpcUa_BrowseNextRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseNextRequest_Decode(OpcUa_BrowseNextRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_BrowseNextRequest_Compare(const OpcUa_BrowseNextRequest* pValue1, const OpcUa_BrowseNextRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseNextRequest_Copy(const OpcUa_BrowseNextRequest* pSource, OpcUa_BrowseNextRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseNextRequest_CopyTo(const OpcUa_BrowseNextRequest* pSource, OpcUa_BrowseNextRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_BrowseNextRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_BrowseNext */

#ifndef OPCUA_EXCLUDE_BrowseNext
#ifndef OPCUA_EXCLUDE_BrowseNextResponse
/*============================================================================
 * The BrowseNextResponse structure.
 *===========================================================================*/
/** \struct OpcUa_BrowseNextResponse
Continues one or more browse operations.
 */
typedef struct _OpcUa_BrowseNextResponse
{
    OpcUa_ResponseHeader  ResponseHeader;
    OpcUa_Int32           NoOfResults;
    OpcUa_BrowseResult*   Results;
    OpcUa_Int32           NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo* DiagnosticInfos;
}
OpcUa_BrowseNextResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_BrowseNextResponse_Initialize(OpcUa_BrowseNextResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_BrowseNextResponse_Clear(OpcUa_BrowseNextResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseNextResponse_GetSize(OpcUa_BrowseNextResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseNextResponse_Encode(OpcUa_BrowseNextResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseNextResponse_Decode(OpcUa_BrowseNextResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_BrowseNextResponse_Compare(const OpcUa_BrowseNextResponse* pValue1, const OpcUa_BrowseNextResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseNextResponse_Copy(const OpcUa_BrowseNextResponse* pSource, OpcUa_BrowseNextResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowseNextResponse_CopyTo(const OpcUa_BrowseNextResponse* pSource, OpcUa_BrowseNextResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_BrowseNextResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_BrowseNext */

#ifndef OPCUA_EXCLUDE_RelativePathElement
/*============================================================================
 * The RelativePathElement structure.
 *===========================================================================*/
/** \struct OpcUa_RelativePathElement
 *  A sequence of References and BrowseNames to follow.
 *
 *  Each element in the sequence is processed by finding the targets and then using
 *  those targets as the starting nodes for the next element. The targets of the
 *  final element are the target of the RelativePath.
 *
 *  \var OpcUa_RelativePathElement::ReferenceTypeId
 *  The type of reference to follow from the current node.
 *
 *  The current path cannot be followed any further if the referenceTypeId is not
 *  available on the Node instance.
 *
 *  If not specified, then all References are included and the parameter
 *  includeSubtypes is ignored.
 *
 *  \var OpcUa_RelativePathElement::IsInverse
 *  Indicates whether the inverse Reference should be followed. The inverse
 *  reference is followed if this value is TRUE.
 *
 *  \var OpcUa_RelativePathElement::IncludeSubtypes
 *  Indicates whether subtypes of the ReferenceType should be followed. Subtypes
 *  are included if this value is TRUE.
 *
 *  \var OpcUa_RelativePathElement::TargetName
 *  The BrowseName of the target node.
 *
 *  The final element may have an empty targetName. In this situation all targets
 *  of the references identified by the referenceTypeId are the targets of the
 *  RelativePath.
 *
 *  The targetName shall be specified for all other elements.
 *
 *  The current path cannot be followed any further if no targets with the
 *  specified BrowseName exist.
 */
typedef struct _OpcUa_RelativePathElement
{
    OpcUa_NodeId        ReferenceTypeId;
    OpcUa_Boolean       IsInverse;
    OpcUa_Boolean       IncludeSubtypes;
    OpcUa_QualifiedName TargetName;
}
OpcUa_RelativePathElement;

OPCUA_EXPORT OpcUa_Void       OpcUa_RelativePathElement_Initialize(OpcUa_RelativePathElement* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_RelativePathElement_Clear(OpcUa_RelativePathElement* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RelativePathElement_GetSize(OpcUa_RelativePathElement* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RelativePathElement_Encode(OpcUa_RelativePathElement* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RelativePathElement_Decode(OpcUa_RelativePathElement* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_RelativePathElement_Compare(const OpcUa_RelativePathElement* pValue1, const OpcUa_RelativePathElement* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_RelativePathElement_Copy(const OpcUa_RelativePathElement* pSource, OpcUa_RelativePathElement** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RelativePathElement_CopyTo(const OpcUa_RelativePathElement* pSource, OpcUa_RelativePathElement* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_RelativePathElement_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_RelativePath
/*============================================================================
 * The RelativePath structure.
 *===========================================================================*/
/** \struct OpcUa_RelativePath
 *  Defines a sequence of References and BrowseNames to follow.
 *
 *  \var OpcUa_RelativePath::Elements
 *  A sequence of References and BrowseNames to follow.
 */
typedef struct _OpcUa_RelativePath
{
    OpcUa_Int32                NoOfElements;
    OpcUa_RelativePathElement* Elements;
}
OpcUa_RelativePath;

OPCUA_EXPORT OpcUa_Void       OpcUa_RelativePath_Initialize(OpcUa_RelativePath* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_RelativePath_Clear(OpcUa_RelativePath* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RelativePath_GetSize(OpcUa_RelativePath* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RelativePath_Encode(OpcUa_RelativePath* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RelativePath_Decode(OpcUa_RelativePath* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_RelativePath_Compare(const OpcUa_RelativePath* pValue1, const OpcUa_RelativePath* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_RelativePath_Copy(const OpcUa_RelativePath* pSource, OpcUa_RelativePath** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RelativePath_CopyTo(const OpcUa_RelativePath* pSource, OpcUa_RelativePath* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_RelativePath_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_BrowsePath
/*============================================================================
 * The BrowsePath structure.
 *===========================================================================*/
/** \struct OpcUa_BrowsePath
 *  A structure that is defined as the type of the browsePaths parameter of the
 *  TranslateBrowsePathsToNodeIds service.
 *
 *  \var OpcUa_BrowsePath::StartingNode
 *  NodeId of the starting Node for the browse path.
 *
 *  \var OpcUa_BrowsePath::RelativePath
 *  The path to follow from the startingNode.
 *
 *  The last element in the relativePath shall always have a targetName specified.
 *  This further restricts the definition of the RelativePath type. The Server
 *  shall return Bad_BrowseNameInvalid if the targetName is missing.
 */
typedef struct _OpcUa_BrowsePath
{
    OpcUa_NodeId       StartingNode;
    OpcUa_RelativePath RelativePath;
}
OpcUa_BrowsePath;

OPCUA_EXPORT OpcUa_Void       OpcUa_BrowsePath_Initialize(OpcUa_BrowsePath* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_BrowsePath_Clear(OpcUa_BrowsePath* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowsePath_GetSize(OpcUa_BrowsePath* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowsePath_Encode(OpcUa_BrowsePath* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowsePath_Decode(OpcUa_BrowsePath* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_BrowsePath_Compare(const OpcUa_BrowsePath* pValue1, const OpcUa_BrowsePath* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowsePath_Copy(const OpcUa_BrowsePath* pSource, OpcUa_BrowsePath** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowsePath_CopyTo(const OpcUa_BrowsePath* pSource, OpcUa_BrowsePath* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_BrowsePath_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_BrowsePathTarget
/*============================================================================
 * The BrowsePathTarget structure.
 *===========================================================================*/
/** \struct OpcUa_BrowsePathTarget
 *  A structure that is defined as the type of the targets parameter of the results
 *  parameter of the TranslateBrowsePathsToNodeIds service.
 *
 *  A Server may encounter a reference to a node in another Server which it cannot
 *  follow while it is processing the RelativePath. If this happens, the Server
 *  returns the NodeId of the external node and sets the remainingPathIndex
 *  parameter to indicate which RelativePath elements still need to be processed.
 *  To complete the operation the Client shall connect to the other Server and call
 *  this service again using the target as the startingNode and the unprocessed
 *  elements as the relativePath.
 *
 *  \var OpcUa_BrowsePathTarget::TargetId
 *  The identifier for a target of the RelativePath.
 *
 *  \var OpcUa_BrowsePathTarget::RemainingPathIndex
 *  The index of the first unprocessed element in the RelativePath.
 *
 *  This value shall be equal to the maximum value of Index data type if all
 *  elements were processed.
 */
typedef struct _OpcUa_BrowsePathTarget
{
    OpcUa_ExpandedNodeId TargetId;
    OpcUa_UInt32         RemainingPathIndex;
}
OpcUa_BrowsePathTarget;

OPCUA_EXPORT OpcUa_Void       OpcUa_BrowsePathTarget_Initialize(OpcUa_BrowsePathTarget* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_BrowsePathTarget_Clear(OpcUa_BrowsePathTarget* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowsePathTarget_GetSize(OpcUa_BrowsePathTarget* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowsePathTarget_Encode(OpcUa_BrowsePathTarget* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowsePathTarget_Decode(OpcUa_BrowsePathTarget* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_BrowsePathTarget_Compare(const OpcUa_BrowsePathTarget* pValue1, const OpcUa_BrowsePathTarget* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowsePathTarget_Copy(const OpcUa_BrowsePathTarget* pSource, OpcUa_BrowsePathTarget** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowsePathTarget_CopyTo(const OpcUa_BrowsePathTarget* pSource, OpcUa_BrowsePathTarget* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_BrowsePathTarget_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_BrowsePathResult
/*============================================================================
 * The BrowsePathResult structure.
 *===========================================================================*/
/** \struct OpcUa_BrowsePathResult
 *  A structure that is defined as the type of the results parameter of the
 *  TranslateBrowsePathsToNodeIds service.
 *
 *  \var OpcUa_BrowsePathResult::StatusCode
 *  StatusCode for the browse path.
 *
 *  \var OpcUa_BrowsePathResult::Targets
 *  List of targets for the relativePath from the startingNode.
 */
typedef struct _OpcUa_BrowsePathResult
{
    OpcUa_StatusCode        StatusCode;
    OpcUa_Int32             NoOfTargets;
    OpcUa_BrowsePathTarget* Targets;
}
OpcUa_BrowsePathResult;

OPCUA_EXPORT OpcUa_Void       OpcUa_BrowsePathResult_Initialize(OpcUa_BrowsePathResult* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_BrowsePathResult_Clear(OpcUa_BrowsePathResult* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowsePathResult_GetSize(OpcUa_BrowsePathResult* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowsePathResult_Encode(OpcUa_BrowsePathResult* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowsePathResult_Decode(OpcUa_BrowsePathResult* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_BrowsePathResult_Compare(const OpcUa_BrowsePathResult* pValue1, const OpcUa_BrowsePathResult* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowsePathResult_Copy(const OpcUa_BrowsePathResult* pSource, OpcUa_BrowsePathResult** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BrowsePathResult_CopyTo(const OpcUa_BrowsePathResult* pSource, OpcUa_BrowsePathResult* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_BrowsePathResult_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_TranslateBrowsePathsToNodeIds
#ifndef OPCUA_EXCLUDE_TranslateBrowsePathsToNodeIdsRequest
/*============================================================================
 * The TranslateBrowsePathsToNodeIdsRequest structure.
 *===========================================================================*/
/** \struct OpcUa_TranslateBrowsePathsToNodeIdsRequest
 *  Asynchronously translates a browse path to a NodeId.
 *
 *  This service is used to request that the Server translates one or more browse
 *  paths to NodeIds. Each browse path is constructed of a starting node and a
 *  RelativePath. The specified starting Node identifies the node from which the
 *  RelativePath is based. The RelativePath contains a sequence of ReferenceTypes
 *  and BrowseNames.
 *
 *  One purpose of this service is to allow programming against type definitions.
 *  Since BrowseNames shall be unique in the context of type definitions, a Client
 *  may create a browse path that is valid for a type definition and use this path
 *  on instances of the type. For example, an ObjectType “Boiler” may have a
 *  “HeatSensor” Variable as InstanceDeclaration. A graphical element programmed
 *  against the “Boiler” may need to display the Value of the “HeatSensor”. If the
 *  graphical element would be called on “Boiler1”, an instance of “Boiler”, it
 *  would need to call this Service specifying the NodeId of “Boiler1” as starting
 *  node and the BrowseName of the “HeatSensor” as browse path. The Service would
 *  return the NodeId of the “HeatSensor” of “Boiler1” and the graphical element
 *  could subscribe to its Value attribute.
 *
 *  If a node has multiple targets with the same BrowseName, the Server shall
 *  return a list of NodeIds. However, since one of the main purposes of this
 *  service is to support programming against type definitions, the NodeId of the
 *  node based on the type definition of the starting node is returned as the first
 *  NodeId in the list.
 *
 *  \var OpcUa_TranslateBrowsePathsToNodeIdsRequest::BrowsePaths
 *  A list of browse paths for which NodeIds are being requested.
 */
typedef struct _OpcUa_TranslateBrowsePathsToNodeIdsRequest
{
    OpcUa_RequestHeader RequestHeader;
    OpcUa_Int32         NoOfBrowsePaths;
    OpcUa_BrowsePath*   BrowsePaths;
}
OpcUa_TranslateBrowsePathsToNodeIdsRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_TranslateBrowsePathsToNodeIdsRequest_Initialize(OpcUa_TranslateBrowsePathsToNodeIdsRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_TranslateBrowsePathsToNodeIdsRequest_Clear(OpcUa_TranslateBrowsePathsToNodeIdsRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TranslateBrowsePathsToNodeIdsRequest_GetSize(OpcUa_TranslateBrowsePathsToNodeIdsRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TranslateBrowsePathsToNodeIdsRequest_Encode(OpcUa_TranslateBrowsePathsToNodeIdsRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TranslateBrowsePathsToNodeIdsRequest_Decode(OpcUa_TranslateBrowsePathsToNodeIdsRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_TranslateBrowsePathsToNodeIdsRequest_Compare(const OpcUa_TranslateBrowsePathsToNodeIdsRequest* pValue1, const OpcUa_TranslateBrowsePathsToNodeIdsRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_TranslateBrowsePathsToNodeIdsRequest_Copy(const OpcUa_TranslateBrowsePathsToNodeIdsRequest* pSource, OpcUa_TranslateBrowsePathsToNodeIdsRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TranslateBrowsePathsToNodeIdsRequest_CopyTo(const OpcUa_TranslateBrowsePathsToNodeIdsRequest* pSource, OpcUa_TranslateBrowsePathsToNodeIdsRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_TranslateBrowsePathsToNodeIdsRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_TranslateBrowsePathsToNodeIds */

#ifndef OPCUA_EXCLUDE_TranslateBrowsePathsToNodeIds
#ifndef OPCUA_EXCLUDE_TranslateBrowsePathsToNodeIdsResponse
/*============================================================================
 * The TranslateBrowsePathsToNodeIdsResponse structure.
 *===========================================================================*/
/** \struct OpcUa_TranslateBrowsePathsToNodeIdsResponse
 *
 * Response to a \ref OpcUa_TranslateBrowsePathsToNodeIdsRequest.
 *
 *  \var OpcUa_TranslateBrowsePathsToNodeIdsResponse::Results
 *  List of results for the list of browse paths.
 *
 *  The size and order of the list matches the size and order of the \ref
 *  OpcUa_TranslateBrowsePathsToNodeIdsRequest::BrowsePaths request parameter.
 *
 *  \var OpcUa_TranslateBrowsePathsToNodeIdsResponse::DiagnosticInfos
 *  List of diagnostic information for the list of browse paths.
 *
 *  The size and order of the list matches the size and order of the request
 *  parameter. This list is empty if diagnostics information was not requested in
 *  the request header or if no diagnostic information was encountered in
 *  processing of the request.
 */
typedef struct _OpcUa_TranslateBrowsePathsToNodeIdsResponse
{
    OpcUa_ResponseHeader    ResponseHeader;
    OpcUa_Int32             NoOfResults;
    OpcUa_BrowsePathResult* Results;
    OpcUa_Int32             NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo*   DiagnosticInfos;
}
OpcUa_TranslateBrowsePathsToNodeIdsResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_TranslateBrowsePathsToNodeIdsResponse_Initialize(OpcUa_TranslateBrowsePathsToNodeIdsResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_TranslateBrowsePathsToNodeIdsResponse_Clear(OpcUa_TranslateBrowsePathsToNodeIdsResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TranslateBrowsePathsToNodeIdsResponse_GetSize(OpcUa_TranslateBrowsePathsToNodeIdsResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TranslateBrowsePathsToNodeIdsResponse_Encode(OpcUa_TranslateBrowsePathsToNodeIdsResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TranslateBrowsePathsToNodeIdsResponse_Decode(OpcUa_TranslateBrowsePathsToNodeIdsResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_TranslateBrowsePathsToNodeIdsResponse_Compare(const OpcUa_TranslateBrowsePathsToNodeIdsResponse* pValue1, const OpcUa_TranslateBrowsePathsToNodeIdsResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_TranslateBrowsePathsToNodeIdsResponse_Copy(const OpcUa_TranslateBrowsePathsToNodeIdsResponse* pSource, OpcUa_TranslateBrowsePathsToNodeIdsResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TranslateBrowsePathsToNodeIdsResponse_CopyTo(const OpcUa_TranslateBrowsePathsToNodeIdsResponse* pSource, OpcUa_TranslateBrowsePathsToNodeIdsResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_TranslateBrowsePathsToNodeIdsResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_TranslateBrowsePathsToNodeIds */

#ifndef OPCUA_EXCLUDE_RegisterNodes
#ifndef OPCUA_EXCLUDE_RegisterNodesRequest
/*============================================================================
 * The RegisterNodesRequest structure.
 *===========================================================================*/
/** \struct OpcUa_RegisterNodesRequest
 *  Asynchronously registers nodes to create shortcuts in the server.
 *
 *  This service allows clients to optimize the cyclic access to nodes, for example
 *  for writing variable values or for calling methods. There are two levels of
 *  optimization.
 *
 *  The first level is to reduce the amount of data on the wire for addressing
 *  information. Since NodeIds are used for addressing in nodes and can be very
 *  long, a more optimized addressing method is desirable for cyclic use of nodes.
 *  Classic OPC provided the concept to create handles for items by adding them to
 *  a group. RegisterNodes provides a similar concept to create handles for nodes
 *  by returning a numeric NodeId that can be used in all functions accessing
 *  information from the server. The transport of numeric NodeIds is very efficient
 *  in the OPC UA binary protocol.
 *
 *  The second level of optimization is possible inside the server. Since the
 *  client is telling the server that it wants to use the node more frequently by
 *  registering the Node, the server is able to prepare everything that is possible
 *  to optimize the access to the node.
 *
 *  The handles returned by the server are only valid during the lifetime of the
 *  session that was used to register the nodes. Clients must call \ref
 *  OpcUa_UnregisterNodesRequest if the node is no longer used, to free the
 *  resources used in the server for the optimization. This method should not be
 *  used to optimize the cyclic read of data, since OPC UA provides a much more
 *  optimized mechanism to subscribe for data changes.
 *
 *  Clients do not have to use the service and servers can simply implement the
 *  service only returning the same list of NodeIds that was passed in if there is
 *  no need to optimize the access.
 *
 *  \var OpcUa_RegisterNodesRequest::NodesToRegister
 *  A list of NodeIds to register that the client has retrieved through browsing,
 *  querying or in some other manner.
 */
typedef struct _OpcUa_RegisterNodesRequest
{
    OpcUa_RequestHeader RequestHeader;
    OpcUa_Int32         NoOfNodesToRegister;
    OpcUa_NodeId*       NodesToRegister;
}
OpcUa_RegisterNodesRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_RegisterNodesRequest_Initialize(OpcUa_RegisterNodesRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_RegisterNodesRequest_Clear(OpcUa_RegisterNodesRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterNodesRequest_GetSize(OpcUa_RegisterNodesRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterNodesRequest_Encode(OpcUa_RegisterNodesRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterNodesRequest_Decode(OpcUa_RegisterNodesRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_RegisterNodesRequest_Compare(const OpcUa_RegisterNodesRequest* pValue1, const OpcUa_RegisterNodesRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterNodesRequest_Copy(const OpcUa_RegisterNodesRequest* pSource, OpcUa_RegisterNodesRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterNodesRequest_CopyTo(const OpcUa_RegisterNodesRequest* pSource, OpcUa_RegisterNodesRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_RegisterNodesRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_RegisterNodes */

#ifndef OPCUA_EXCLUDE_RegisterNodes
#ifndef OPCUA_EXCLUDE_RegisterNodesResponse
/*============================================================================
 * The RegisterNodesResponse structure.
 *===========================================================================*/
/** \struct OpcUa_RegisterNodesResponse
 *
 * Response to a \ref OpcUa_RegisterNodesRequest.
 *
 *  \var OpcUa_RegisterNodesResponse::RegisteredNodeIds
 *  A list of NodeIds which the Client shall use for subsequent access operations.
 *
 *  The size and order of this list matches the size and order of the \ref
 *  OpcUa_RegisterNodesRequest::NodesToRegister request parameter.
 *
 *  The Server may return the NodeId from the request or a new (an alias) NodeId.
 *  It is recommended that the Server returns a numeric NodeId for aliasing.
 *
 *  In case no optimization is supported for a node, the Server shall return the
 *  NodeId from the request.
 */
typedef struct _OpcUa_RegisterNodesResponse
{
    OpcUa_ResponseHeader ResponseHeader;
    OpcUa_Int32          NoOfRegisteredNodeIds;
    OpcUa_NodeId*        RegisteredNodeIds;
}
OpcUa_RegisterNodesResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_RegisterNodesResponse_Initialize(OpcUa_RegisterNodesResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_RegisterNodesResponse_Clear(OpcUa_RegisterNodesResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterNodesResponse_GetSize(OpcUa_RegisterNodesResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterNodesResponse_Encode(OpcUa_RegisterNodesResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterNodesResponse_Decode(OpcUa_RegisterNodesResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_RegisterNodesResponse_Compare(const OpcUa_RegisterNodesResponse* pValue1, const OpcUa_RegisterNodesResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterNodesResponse_Copy(const OpcUa_RegisterNodesResponse* pSource, OpcUa_RegisterNodesResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RegisterNodesResponse_CopyTo(const OpcUa_RegisterNodesResponse* pSource, OpcUa_RegisterNodesResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_RegisterNodesResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_RegisterNodes */

#ifndef OPCUA_EXCLUDE_UnregisterNodes
#ifndef OPCUA_EXCLUDE_UnregisterNodesRequest
/*============================================================================
 * The UnregisterNodesRequest structure.
 *===========================================================================*/
/** \struct OpcUa_UnregisterNodesRequest
 *  Asynchronously unregisters nodes to delete shortcuts in the server.
 *
 *  This Service is used to unregister NodeIds that have been obtained via the
 *  RegisterNodes service.
 *
 *  UnregisterNodes does not validate the NodeIds from the request. Servers shall
 *  simply unregister NodeIds that are known as registered NodeIds. Any NodeIds
 *  that are in the list, but are not registered NodeIds are simply ignored.
 *
 *  \var OpcUa_UnregisterNodesRequest::NodesToUnregister
 *  A list of NodeIds that have been obtained via the RegisterNodes service.
 */
typedef struct _OpcUa_UnregisterNodesRequest
{
    OpcUa_RequestHeader RequestHeader;
    OpcUa_Int32         NoOfNodesToUnregister;
    OpcUa_NodeId*       NodesToUnregister;
}
OpcUa_UnregisterNodesRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_UnregisterNodesRequest_Initialize(OpcUa_UnregisterNodesRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_UnregisterNodesRequest_Clear(OpcUa_UnregisterNodesRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UnregisterNodesRequest_GetSize(OpcUa_UnregisterNodesRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UnregisterNodesRequest_Encode(OpcUa_UnregisterNodesRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UnregisterNodesRequest_Decode(OpcUa_UnregisterNodesRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_UnregisterNodesRequest_Compare(const OpcUa_UnregisterNodesRequest* pValue1, const OpcUa_UnregisterNodesRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_UnregisterNodesRequest_Copy(const OpcUa_UnregisterNodesRequest* pSource, OpcUa_UnregisterNodesRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UnregisterNodesRequest_CopyTo(const OpcUa_UnregisterNodesRequest* pSource, OpcUa_UnregisterNodesRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_UnregisterNodesRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_UnregisterNodes */

#ifndef OPCUA_EXCLUDE_UnregisterNodes
#ifndef OPCUA_EXCLUDE_UnregisterNodesResponse
/*============================================================================
 * The UnregisterNodesResponse structure.
 *===========================================================================*/
/** \struct OpcUa_UnregisterNodesResponse
Unregisters one or more previously registered nodes.
 */
typedef struct _OpcUa_UnregisterNodesResponse
{
    OpcUa_ResponseHeader ResponseHeader;
}
OpcUa_UnregisterNodesResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_UnregisterNodesResponse_Initialize(OpcUa_UnregisterNodesResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_UnregisterNodesResponse_Clear(OpcUa_UnregisterNodesResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UnregisterNodesResponse_GetSize(OpcUa_UnregisterNodesResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UnregisterNodesResponse_Encode(OpcUa_UnregisterNodesResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UnregisterNodesResponse_Decode(OpcUa_UnregisterNodesResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_UnregisterNodesResponse_Compare(const OpcUa_UnregisterNodesResponse* pValue1, const OpcUa_UnregisterNodesResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_UnregisterNodesResponse_Copy(const OpcUa_UnregisterNodesResponse* pSource, OpcUa_UnregisterNodesResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UnregisterNodesResponse_CopyTo(const OpcUa_UnregisterNodesResponse* pSource, OpcUa_UnregisterNodesResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_UnregisterNodesResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_UnregisterNodes */

#ifndef OPCUA_EXCLUDE_EndpointConfiguration
/*============================================================================
 * The EndpointConfiguration structure.
 *===========================================================================*/
typedef struct _OpcUa_EndpointConfiguration
{
    OpcUa_Int32   OperationTimeout;
    OpcUa_Boolean UseBinaryEncoding;
    OpcUa_Int32   MaxStringLength;
    OpcUa_Int32   MaxByteStringLength;
    OpcUa_Int32   MaxArrayLength;
    OpcUa_Int32   MaxMessageSize;
    OpcUa_Int32   MaxBufferSize;
    OpcUa_Int32   ChannelLifetime;
    OpcUa_Int32   SecurityTokenLifetime;
}
OpcUa_EndpointConfiguration;

OPCUA_EXPORT OpcUa_Void       OpcUa_EndpointConfiguration_Initialize(OpcUa_EndpointConfiguration* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_EndpointConfiguration_Clear(OpcUa_EndpointConfiguration* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EndpointConfiguration_GetSize(OpcUa_EndpointConfiguration* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EndpointConfiguration_Encode(OpcUa_EndpointConfiguration* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EndpointConfiguration_Decode(OpcUa_EndpointConfiguration* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_EndpointConfiguration_Compare(const OpcUa_EndpointConfiguration* pValue1, const OpcUa_EndpointConfiguration* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_EndpointConfiguration_Copy(const OpcUa_EndpointConfiguration* pSource, OpcUa_EndpointConfiguration** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EndpointConfiguration_CopyTo(const OpcUa_EndpointConfiguration* pSource, OpcUa_EndpointConfiguration* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_EndpointConfiguration_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_SupportedProfile
/*============================================================================
 * The SupportedProfile structure.
 *===========================================================================*/
/** \struct OpcUa_SupportedProfile
 *
 *  \var OpcUa_SupportedProfile::OrganizationUri
 *  A URI that identifies the organization that defined the profile.
 *
 *  \var OpcUa_SupportedProfile::ProfileId
 *  A string that identifies the Profile.
 *
 *  \var OpcUa_SupportedProfile::ComplianceTool
 *  A string that identifies the tool or certification method used for compliance
 *  testing.
 *
 *  \var OpcUa_SupportedProfile::ComplianceDate
 *  Date and time of the compliance test.
 *
 *  \var OpcUa_SupportedProfile::ComplianceLevel
 *  Specifies the compliance level of the Profile.
 *
 *  \var OpcUa_SupportedProfile::UnsupportedUnitIds
 *  The identifiers for the optional conformance units that were not tested.
 */
typedef struct _OpcUa_SupportedProfile
{
    OpcUa_String          OrganizationUri;
    OpcUa_String          ProfileId;
    OpcUa_String          ComplianceTool;
    OpcUa_DateTime        ComplianceDate;
    OpcUa_ComplianceLevel ComplianceLevel;
    OpcUa_Int32           NoOfUnsupportedUnitIds;
    OpcUa_String*         UnsupportedUnitIds;
}
OpcUa_SupportedProfile;

OPCUA_EXPORT OpcUa_Void       OpcUa_SupportedProfile_Initialize(OpcUa_SupportedProfile* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_SupportedProfile_Clear(OpcUa_SupportedProfile* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SupportedProfile_GetSize(OpcUa_SupportedProfile* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SupportedProfile_Encode(OpcUa_SupportedProfile* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SupportedProfile_Decode(OpcUa_SupportedProfile* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_SupportedProfile_Compare(const OpcUa_SupportedProfile* pValue1, const OpcUa_SupportedProfile* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_SupportedProfile_Copy(const OpcUa_SupportedProfile* pSource, OpcUa_SupportedProfile** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SupportedProfile_CopyTo(const OpcUa_SupportedProfile* pSource, OpcUa_SupportedProfile* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_SupportedProfile_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_SoftwareCertificate
/*============================================================================
 * The SoftwareCertificate structure.
 *===========================================================================*/
/** \struct OpcUa_SoftwareCertificate
 *  A certificate describing a product.
 *
 *  \var OpcUa_SoftwareCertificate::ProductName
 *  The name of the product that is certified.
 *
 *  This field shall be specified.
 *
 *  \var OpcUa_SoftwareCertificate::ProductUri
 *  A globally unique identifier for the product that is certified.
 *
 *  This field shall be specified.
 *
 *  \var OpcUa_SoftwareCertificate::VendorName
 *  The name of the vendor responsible for the product.
 *
 *  This field shall be specified.
 *
 *  \var OpcUa_SoftwareCertificate::VendorProductCertificate
 *  The DER encoded form of the X.509 certificate which is assigned to the product
 *  by the vendor.
 *
 *  This field may be omitted.
 *
 *  \var OpcUa_SoftwareCertificate::SoftwareVersion
 *  Software version.
 *
 *  This field shall be specified.
 *
 *  \var OpcUa_SoftwareCertificate::BuildNumber
 *  Build number.
 *
 *  This field shall be specified.
 *
 *  \var OpcUa_SoftwareCertificate::BuildDate
 *  Date and time of the build.
 *
 *  This field shall be specified.
 *
 *  \var OpcUa_SoftwareCertificate::IssuedBy
 *  URI of the certifying authority.
 *
 *  This field shall be specified.
 *
 *  \var OpcUa_SoftwareCertificate::IssueDate
 *  Specifies when the certificate was issued by the certifying authority.
 *
 *  This field shall be specified.
 *
 *  \var OpcUa_SoftwareCertificate::SupportedProfiles
 *  List of supported Profiles.
 */
typedef struct _OpcUa_SoftwareCertificate
{
    OpcUa_String            ProductName;
    OpcUa_String            ProductUri;
    OpcUa_String            VendorName;
    OpcUa_ByteString        VendorProductCertificate;
    OpcUa_String            SoftwareVersion;
    OpcUa_String            BuildNumber;
    OpcUa_DateTime          BuildDate;
    OpcUa_String            IssuedBy;
    OpcUa_DateTime          IssueDate;
    OpcUa_Int32             NoOfSupportedProfiles;
    OpcUa_SupportedProfile* SupportedProfiles;
}
OpcUa_SoftwareCertificate;

OPCUA_EXPORT OpcUa_Void       OpcUa_SoftwareCertificate_Initialize(OpcUa_SoftwareCertificate* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_SoftwareCertificate_Clear(OpcUa_SoftwareCertificate* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SoftwareCertificate_GetSize(OpcUa_SoftwareCertificate* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SoftwareCertificate_Encode(OpcUa_SoftwareCertificate* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SoftwareCertificate_Decode(OpcUa_SoftwareCertificate* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_SoftwareCertificate_Compare(const OpcUa_SoftwareCertificate* pValue1, const OpcUa_SoftwareCertificate* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_SoftwareCertificate_Copy(const OpcUa_SoftwareCertificate* pSource, OpcUa_SoftwareCertificate** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SoftwareCertificate_CopyTo(const OpcUa_SoftwareCertificate* pSource, OpcUa_SoftwareCertificate* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_SoftwareCertificate_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_QueryDataDescription
/*============================================================================
 * The QueryDataDescription structure.
 *===========================================================================*/
/** \struct OpcUa_QueryDataDescription
 *  A structure that is defined as the type of the dataToReturn parameter of the
 *  nodeTypes parameter of the Query service.
 *
 *  \var OpcUa_QueryDataDescription::RelativePath
 *  Browse path relative to the originating node that identifies the node which
 *  contains the data that is being requested, where the originating node is an
 *  instance node of the type defined by the type definition node.
 *
 *  The instance nodes are further limited by the filter provided as part of this
 *  call.
 *
 *  This relative path could end on a reference, in which case the
 *  ReferenceDescription of the reference would be returned as its value.
 *
 *  The targetName field of the relativePath may contain a type NodeId. This is
 *  done by setting the namespaceIndex of the targetName to zero and the name part
 *  of the targetName to the XML representation of the NodeId.
 *
 *  When matching instances are returned as the target node, the target node shall
 *  be an instance of the specified type or subtype of the specified type.
 *
 *  \var OpcUa_QueryDataDescription::AttributeId
 *  The ID of the attribute.
 *
 *  This shall be a valid attribute ID. If the RelativePath ended in a reference,
 *  this parameter is 0 and ignored by the server.
 *
 *  \var OpcUa_QueryDataDescription::IndexRange
 *  Used to identify a single element of a structure or an array, or a single range
 *  of indexes for arrays.
 *
 *  If a range of elements is specified, the values are returned as a composite.
 *  The first element is identified by index 0 (zero). This parameter is null if
 *  the specified attribute is not an array or a structure. However, if the
 *  specified attribute is an array or a structure and this parameter is null, all
 *  elements are to be included in the range.
 */
typedef struct _OpcUa_QueryDataDescription
{
    OpcUa_RelativePath RelativePath;
    OpcUa_UInt32       AttributeId;
    OpcUa_String       IndexRange;
}
OpcUa_QueryDataDescription;

OPCUA_EXPORT OpcUa_Void       OpcUa_QueryDataDescription_Initialize(OpcUa_QueryDataDescription* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_QueryDataDescription_Clear(OpcUa_QueryDataDescription* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryDataDescription_GetSize(OpcUa_QueryDataDescription* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryDataDescription_Encode(OpcUa_QueryDataDescription* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryDataDescription_Decode(OpcUa_QueryDataDescription* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_QueryDataDescription_Compare(const OpcUa_QueryDataDescription* pValue1, const OpcUa_QueryDataDescription* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryDataDescription_Copy(const OpcUa_QueryDataDescription* pSource, OpcUa_QueryDataDescription** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryDataDescription_CopyTo(const OpcUa_QueryDataDescription* pSource, OpcUa_QueryDataDescription* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_QueryDataDescription_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_NodeTypeDescription
/*============================================================================
 * The NodeTypeDescription structure.
 *===========================================================================*/
/** \struct OpcUa_NodeTypeDescription
 *  A structure that is defined as the type of the nodeTypes parameter of the Query
 *  service.
 *
 *  \var OpcUa_NodeTypeDescription::TypeDefinitionNode
 *  NodeId of the originating TypeDefinitionNode of the instances for which data is
 *  to be returned.
 *
 *  \var OpcUa_NodeTypeDescription::IncludeSubTypes
 *  A flag that indicates whether the Server should include instances of subtypes
 *  of the TypeDefinitionNode in the list of instances of the node type.
 *
 *  \var OpcUa_NodeTypeDescription::DataToReturn
 *  Specifies an attribute or reference from the originating typeDefinitionNode
 *  along a given relativePath for which to return data.
 */
typedef struct _OpcUa_NodeTypeDescription
{
    OpcUa_ExpandedNodeId        TypeDefinitionNode;
    OpcUa_Boolean               IncludeSubTypes;
    OpcUa_Int32                 NoOfDataToReturn;
    OpcUa_QueryDataDescription* DataToReturn;
}
OpcUa_NodeTypeDescription;

OPCUA_EXPORT OpcUa_Void       OpcUa_NodeTypeDescription_Initialize(OpcUa_NodeTypeDescription* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_NodeTypeDescription_Clear(OpcUa_NodeTypeDescription* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_NodeTypeDescription_GetSize(OpcUa_NodeTypeDescription* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_NodeTypeDescription_Encode(OpcUa_NodeTypeDescription* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_NodeTypeDescription_Decode(OpcUa_NodeTypeDescription* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_NodeTypeDescription_Compare(const OpcUa_NodeTypeDescription* pValue1, const OpcUa_NodeTypeDescription* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_NodeTypeDescription_Copy(const OpcUa_NodeTypeDescription* pSource, OpcUa_NodeTypeDescription** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_NodeTypeDescription_CopyTo(const OpcUa_NodeTypeDescription* pSource, OpcUa_NodeTypeDescription* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_NodeTypeDescription_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_QueryDataSet
/*============================================================================
 * The QueryDataSet structure.
 *===========================================================================*/
typedef struct _OpcUa_QueryDataSet
{
    OpcUa_ExpandedNodeId NodeId;
    OpcUa_ExpandedNodeId TypeDefinitionNode;
    OpcUa_Int32          NoOfValues;
    OpcUa_Variant*       Values;
}
OpcUa_QueryDataSet;

OPCUA_EXPORT OpcUa_Void       OpcUa_QueryDataSet_Initialize(OpcUa_QueryDataSet* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_QueryDataSet_Clear(OpcUa_QueryDataSet* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryDataSet_GetSize(OpcUa_QueryDataSet* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryDataSet_Encode(OpcUa_QueryDataSet* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryDataSet_Decode(OpcUa_QueryDataSet* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_QueryDataSet_Compare(const OpcUa_QueryDataSet* pValue1, const OpcUa_QueryDataSet* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryDataSet_Copy(const OpcUa_QueryDataSet* pSource, OpcUa_QueryDataSet** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryDataSet_CopyTo(const OpcUa_QueryDataSet* pSource, OpcUa_QueryDataSet* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_QueryDataSet_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_NodeReference
/*============================================================================
 * The NodeReference structure.
 *===========================================================================*/
typedef struct _OpcUa_NodeReference
{
    OpcUa_NodeId  NodeId;
    OpcUa_NodeId  ReferenceTypeId;
    OpcUa_Boolean IsForward;
    OpcUa_Int32   NoOfReferencedNodeIds;
    OpcUa_NodeId* ReferencedNodeIds;
}
OpcUa_NodeReference;

OPCUA_EXPORT OpcUa_Void       OpcUa_NodeReference_Initialize(OpcUa_NodeReference* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_NodeReference_Clear(OpcUa_NodeReference* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_NodeReference_GetSize(OpcUa_NodeReference* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_NodeReference_Encode(OpcUa_NodeReference* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_NodeReference_Decode(OpcUa_NodeReference* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_NodeReference_Compare(const OpcUa_NodeReference* pValue1, const OpcUa_NodeReference* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_NodeReference_Copy(const OpcUa_NodeReference* pSource, OpcUa_NodeReference** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_NodeReference_CopyTo(const OpcUa_NodeReference* pSource, OpcUa_NodeReference* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_NodeReference_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ContentFilterElement
/*============================================================================
 * The ContentFilterElement structure.
 *===========================================================================*/
/** \struct OpcUa_ContentFilterElement
 *  A structure that is defined as the type of the elements parameter of the
 *  ContentFilter structure.
 *
 *  \var OpcUa_ContentFilterElement::FilterOperator
 *  Filter operator to be evaluated.
 *
 *  \var OpcUa_ContentFilterElement::FilterOperands
 *  Operands used by the selected operator.
 *
 *  The number and use depend on the operators (see \ref OpcUa_FilterOperator).
 *  This array needs at least one entry.
 */
typedef struct _OpcUa_ContentFilterElement
{
    OpcUa_FilterOperator   FilterOperator;
    OpcUa_Int32            NoOfFilterOperands;
    OpcUa_ExtensionObject* FilterOperands;
}
OpcUa_ContentFilterElement;

OPCUA_EXPORT OpcUa_Void       OpcUa_ContentFilterElement_Initialize(OpcUa_ContentFilterElement* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ContentFilterElement_Clear(OpcUa_ContentFilterElement* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ContentFilterElement_GetSize(OpcUa_ContentFilterElement* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ContentFilterElement_Encode(OpcUa_ContentFilterElement* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ContentFilterElement_Decode(OpcUa_ContentFilterElement* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ContentFilterElement_Compare(const OpcUa_ContentFilterElement* pValue1, const OpcUa_ContentFilterElement* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ContentFilterElement_Copy(const OpcUa_ContentFilterElement* pSource, OpcUa_ContentFilterElement** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ContentFilterElement_CopyTo(const OpcUa_ContentFilterElement* pSource, OpcUa_ContentFilterElement* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ContentFilterElement_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ContentFilter
/*============================================================================
 * The ContentFilter structure.
 *===========================================================================*/
/** \struct OpcUa_ContentFilter
 *  Defines a collection of elements that define filtering criteria.
 *
 *  Each element in the collection describes an operator and an array of operands
 *  to be used by the operator. See \ref OpcUa_FilterOperator for a description of
 *  the operators that can be used in a ContentFilter. The filter is evaluated by
 *  evaluating the first entry in the element array starting with the first operand
 *  in the operand array. The operands of an element may contain References to
 *  subelements resulting in the evaluation continuing to the referenced elements
 *  in the element array. If an element cannot be traced back to the starting
 *  element it is ignored. Extra operands for any operator shall result in an
 *  error.
 *
 *  \var OpcUa_ContentFilter::Elements
 *  List of operators and their operands that compose the filter criteria.
 *
 *  The filter is evaluated by starting with the first entry in this array.
 */
typedef struct _OpcUa_ContentFilter
{
    OpcUa_Int32                 NoOfElements;
    OpcUa_ContentFilterElement* Elements;
}
OpcUa_ContentFilter;

OPCUA_EXPORT OpcUa_Void       OpcUa_ContentFilter_Initialize(OpcUa_ContentFilter* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ContentFilter_Clear(OpcUa_ContentFilter* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ContentFilter_GetSize(OpcUa_ContentFilter* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ContentFilter_Encode(OpcUa_ContentFilter* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ContentFilter_Decode(OpcUa_ContentFilter* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ContentFilter_Compare(const OpcUa_ContentFilter* pValue1, const OpcUa_ContentFilter* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ContentFilter_Copy(const OpcUa_ContentFilter* pSource, OpcUa_ContentFilter** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ContentFilter_CopyTo(const OpcUa_ContentFilter* pSource, OpcUa_ContentFilter* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ContentFilter_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ElementOperand
/*============================================================================
 * The ElementOperand structure.
 *===========================================================================*/
/** \struct OpcUa_ElementOperand
 *  Provides the linking to subelements within a \ref OpcUa_ContentFilter.
 *
 *  The link is in the form of an integer that is used to index into the array of
 *  elements contained in the \ref OpcUa_ContentFilter. An index is considered
 *  valid if its value is greater than the element index it is part of and it does
 *  not reference a non-existent element. Clients shall construct filters in this
 *  way to avoid circular and invalid references. Servers should protect against
 *  invalid indexes by verifying the index prior to using it.
 *
 *  \var OpcUa_ElementOperand::Index
 *  Index into the element array.
 */
typedef struct _OpcUa_ElementOperand
{
    OpcUa_UInt32 Index;
}
OpcUa_ElementOperand;

OPCUA_EXPORT OpcUa_Void       OpcUa_ElementOperand_Initialize(OpcUa_ElementOperand* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ElementOperand_Clear(OpcUa_ElementOperand* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ElementOperand_GetSize(OpcUa_ElementOperand* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ElementOperand_Encode(OpcUa_ElementOperand* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ElementOperand_Decode(OpcUa_ElementOperand* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ElementOperand_Compare(const OpcUa_ElementOperand* pValue1, const OpcUa_ElementOperand* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ElementOperand_Copy(const OpcUa_ElementOperand* pSource, OpcUa_ElementOperand** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ElementOperand_CopyTo(const OpcUa_ElementOperand* pSource, OpcUa_ElementOperand* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ElementOperand_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_LiteralOperand
/*============================================================================
 * The LiteralOperand structure.
 *===========================================================================*/
/** \struct OpcUa_LiteralOperand
 *
 *  \var OpcUa_LiteralOperand::Value
 *  A literal value.
 */
typedef struct _OpcUa_LiteralOperand
{
    OpcUa_Variant Value;
}
OpcUa_LiteralOperand;

OPCUA_EXPORT OpcUa_Void       OpcUa_LiteralOperand_Initialize(OpcUa_LiteralOperand* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_LiteralOperand_Clear(OpcUa_LiteralOperand* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_LiteralOperand_GetSize(OpcUa_LiteralOperand* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_LiteralOperand_Encode(OpcUa_LiteralOperand* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_LiteralOperand_Decode(OpcUa_LiteralOperand* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_LiteralOperand_Compare(const OpcUa_LiteralOperand* pValue1, const OpcUa_LiteralOperand* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_LiteralOperand_Copy(const OpcUa_LiteralOperand* pSource, OpcUa_LiteralOperand** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_LiteralOperand_CopyTo(const OpcUa_LiteralOperand* pSource, OpcUa_LiteralOperand* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_LiteralOperand_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_AttributeOperand
/*============================================================================
 * The AttributeOperand structure.
 *===========================================================================*/
/** \struct OpcUa_AttributeOperand
 *  Attribute of a node in the address space.
 *
 *  \var OpcUa_AttributeOperand::NodeId
 *  NodeId of a Node from the type system.
 *
 *  \var OpcUa_AttributeOperand::Alias
 *  An optional parameter used to identify or refer to an alias.
 *
 *  An alias is a symbolic name that can be used to alias this operand and use it
 *  in other locations in the filter structure.
 *
 *  \var OpcUa_AttributeOperand::BrowsePath
 *  Browse path relative to the node identified by the nodeId parameter.
 *
 *  \var OpcUa_AttributeOperand::AttributeId
 *  ID of the attribute.
 *
 *  This shall be a valid.
 *
 *  \var OpcUa_AttributeOperand::IndexRange
 *  This parameter is used to identify a single element of an array or a single
 *  range of indexes for an array.
 *
 *  The first element is identified by index 0 (zero). This parameter is not used
 *  if the specified attribute is not an array. However, if the specified attribute
 *  is an array and this parameter is not used, then all elements are to be
 *  included in the range. The parameter is null if not used.
 */
typedef struct _OpcUa_AttributeOperand
{
    OpcUa_NodeId       NodeId;
    OpcUa_String       Alias;
    OpcUa_RelativePath BrowsePath;
    OpcUa_UInt32       AttributeId;
    OpcUa_String       IndexRange;
}
OpcUa_AttributeOperand;

OPCUA_EXPORT OpcUa_Void       OpcUa_AttributeOperand_Initialize(OpcUa_AttributeOperand* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_AttributeOperand_Clear(OpcUa_AttributeOperand* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AttributeOperand_GetSize(OpcUa_AttributeOperand* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AttributeOperand_Encode(OpcUa_AttributeOperand* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AttributeOperand_Decode(OpcUa_AttributeOperand* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_AttributeOperand_Compare(const OpcUa_AttributeOperand* pValue1, const OpcUa_AttributeOperand* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_AttributeOperand_Copy(const OpcUa_AttributeOperand* pSource, OpcUa_AttributeOperand** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AttributeOperand_CopyTo(const OpcUa_AttributeOperand* pSource, OpcUa_AttributeOperand* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_AttributeOperand_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_SimpleAttributeOperand
/*============================================================================
 * The SimpleAttributeOperand structure.
 *===========================================================================*/
/** \struct OpcUa_SimpleAttributeOperand
 *  A simplified form of the \ref OpcUa_AttributeOperand.
 *
 *  All of the rules that apply to the \ref OpcUa_AttributeOperand also apply to
 *  the SimpleAttributeOperand.
 *
 *  \var OpcUa_SimpleAttributeOperand::TypeDefinitionId
 *  NodeId of a TypeDefinitionNode.
 *
 *  This parameter restricts the operand to instances of the TypeDefinitionNode or
 *  one of its subtypes.
 *
 *  \var OpcUa_SimpleAttributeOperand::BrowsePath
 *  A relative path to a Node.
 *
 *  This parameter specifies a relative path using a list of browse names instead
 *  of the \ref OpcUa_RelativePath structure used in the \ref
 *  OpcUa_AttributeOperand. The list of browse names is equivalent to a relative
 *  path that specifies forward references which are subtypes of the
 *  HierarchicalReferences reference type.
 *
 *  All nodes followed by the browsePath shall be of the NodeClass object or
 *  variable.
 *
 *  If this list is empty, the node is the instance of the TypeDefinition.
 *
 *  \var OpcUa_SimpleAttributeOperand::AttributeId
 *  ID of the Attribute.
 *
 *  The Value attribute shall be supported by all Servers. The support of other
 *  attributes depends on requirements set in Profiles or other parts of this
 *  specification.
 *
 *  \var OpcUa_SimpleAttributeOperand::IndexRange
 *  This parameter is used to identify a single element of an array, or a single
 *  range of indexes for an array.
 *
 *  The first element is identified by index 0 (zero).
 *
 *  This parameter is ignored if the selected node is not a variable or the value
 *  of a variable is not an array.
 *
 *  The parameter is null if not specified.
 *
 *  All values in the array are used if this parameter is not specified.
 */
typedef struct _OpcUa_SimpleAttributeOperand
{
    OpcUa_NodeId         TypeDefinitionId;
    OpcUa_Int32          NoOfBrowsePath;
    OpcUa_QualifiedName* BrowsePath;
    OpcUa_UInt32         AttributeId;
    OpcUa_String         IndexRange;
}
OpcUa_SimpleAttributeOperand;

OPCUA_EXPORT OpcUa_Void       OpcUa_SimpleAttributeOperand_Initialize(OpcUa_SimpleAttributeOperand* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_SimpleAttributeOperand_Clear(OpcUa_SimpleAttributeOperand* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SimpleAttributeOperand_GetSize(OpcUa_SimpleAttributeOperand* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SimpleAttributeOperand_Encode(OpcUa_SimpleAttributeOperand* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SimpleAttributeOperand_Decode(OpcUa_SimpleAttributeOperand* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_SimpleAttributeOperand_Compare(const OpcUa_SimpleAttributeOperand* pValue1, const OpcUa_SimpleAttributeOperand* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_SimpleAttributeOperand_Copy(const OpcUa_SimpleAttributeOperand* pSource, OpcUa_SimpleAttributeOperand** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SimpleAttributeOperand_CopyTo(const OpcUa_SimpleAttributeOperand* pSource, OpcUa_SimpleAttributeOperand* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_SimpleAttributeOperand_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ContentFilterElementResult
/*============================================================================
 * The ContentFilterElementResult structure.
 *===========================================================================*/
/** \struct OpcUa_ContentFilterElementResult
 *  A structure that is defined as the type of the elementResults parameter of the
 *  ContentFilterResult structure.
 *
 *  The size and order of the list matches the size and order of the elements in
 *  the ContentFilter parameter.
 *
 *  \var OpcUa_ContentFilterElementResult::StatusCode
 *  The status code for a single element.
 *
 *  \var OpcUa_ContentFilterElementResult::OperandStatusCodes
 *  A list of status codes for the operands in an element.
 *
 *  The size and order of the list matches the size and order of the operands in
 *  the ContentFilterElement. This list is empty if no operand errors occurred.
 *
 *  \var OpcUa_ContentFilterElementResult::OperandDiagnosticInfos
 *  A list of diagnostic information for the operands in an element.
 *
 *  The size and order of the list matches the size and order of the operands in
 *  the ContentFilterElement. This list is empty if diagnostics information was not
 *  requested in the request header or if no diagnostic information was encountered
 *  in processing of the operands. A list of diagnostic information for individual
 */
typedef struct _OpcUa_ContentFilterElementResult
{
    OpcUa_StatusCode      StatusCode;
    OpcUa_Int32           NoOfOperandStatusCodes;
    OpcUa_StatusCode*     OperandStatusCodes;
    OpcUa_Int32           NoOfOperandDiagnosticInfos;
    OpcUa_DiagnosticInfo* OperandDiagnosticInfos;
}
OpcUa_ContentFilterElementResult;

OPCUA_EXPORT OpcUa_Void       OpcUa_ContentFilterElementResult_Initialize(OpcUa_ContentFilterElementResult* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ContentFilterElementResult_Clear(OpcUa_ContentFilterElementResult* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ContentFilterElementResult_GetSize(OpcUa_ContentFilterElementResult* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ContentFilterElementResult_Encode(OpcUa_ContentFilterElementResult* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ContentFilterElementResult_Decode(OpcUa_ContentFilterElementResult* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ContentFilterElementResult_Compare(const OpcUa_ContentFilterElementResult* pValue1, const OpcUa_ContentFilterElementResult* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ContentFilterElementResult_Copy(const OpcUa_ContentFilterElementResult* pSource, OpcUa_ContentFilterElementResult** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ContentFilterElementResult_CopyTo(const OpcUa_ContentFilterElementResult* pSource, OpcUa_ContentFilterElementResult* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ContentFilterElementResult_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ContentFilterResult
/*============================================================================
 * The ContentFilterResult structure.
 *===========================================================================*/
/** \struct OpcUa_ContentFilterResult
 *  A structure that contains any errors associated with the filter.
 *
 *  \var OpcUa_ContentFilterResult::ElementResults
 *  A list of results for individual elements in the filter.
 *
 *  See \ref OpcUa_ContentFilterElementResult.
 *
 *  \var OpcUa_ContentFilterResult::ElementDiagnosticInfos
 *  A list of diagnostic information for individual elements in the filter.
 *
 *  The size and order of the list matches the size and order of the elements in
 *  the filter request parameter. This list is empty if diagnostics information was
 *  not requested in the request header or if no diagnostic information was
 *  encountered in processing of the elements.
 */
typedef struct _OpcUa_ContentFilterResult
{
    OpcUa_Int32                       NoOfElementResults;
    OpcUa_ContentFilterElementResult* ElementResults;
    OpcUa_Int32                       NoOfElementDiagnosticInfos;
    OpcUa_DiagnosticInfo*             ElementDiagnosticInfos;
}
OpcUa_ContentFilterResult;

OPCUA_EXPORT OpcUa_Void       OpcUa_ContentFilterResult_Initialize(OpcUa_ContentFilterResult* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ContentFilterResult_Clear(OpcUa_ContentFilterResult* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ContentFilterResult_GetSize(OpcUa_ContentFilterResult* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ContentFilterResult_Encode(OpcUa_ContentFilterResult* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ContentFilterResult_Decode(OpcUa_ContentFilterResult* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ContentFilterResult_Compare(const OpcUa_ContentFilterResult* pValue1, const OpcUa_ContentFilterResult* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ContentFilterResult_Copy(const OpcUa_ContentFilterResult* pSource, OpcUa_ContentFilterResult** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ContentFilterResult_CopyTo(const OpcUa_ContentFilterResult* pSource, OpcUa_ContentFilterResult* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ContentFilterResult_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ParsingResult
/*============================================================================
 * The ParsingResult structure.
 *===========================================================================*/
/** \struct OpcUa_ParsingResult
 *  A structure that is defined as the type of the parsingResults parameter of the
 *  Query service.
 *
 *  \var OpcUa_ParsingResult::StatusCode
 *  Parsing result for the requested NodeTypeDescription.
 *
 *  \var OpcUa_ParsingResult::DataStatusCodes
 *  List of results for dataToReturn.
 *
 *  The size and order of the list matches the size and order of the dataToReturn
 *  request parameter. The array can be empty if no errors were encountered.
 *
 *  \var OpcUa_ParsingResult::DataDiagnosticInfos
 *  List of diagnostic information dataToReturn.
 *
 *  The size and order of the list matches the size and order of the dataToReturn
 *  request parameter. This list is empty if diagnostics information was not
 *  requested in the request header or if no diagnostic information was encountered
 *  in processing of the query request.
 */
typedef struct _OpcUa_ParsingResult
{
    OpcUa_StatusCode      StatusCode;
    OpcUa_Int32           NoOfDataStatusCodes;
    OpcUa_StatusCode*     DataStatusCodes;
    OpcUa_Int32           NoOfDataDiagnosticInfos;
    OpcUa_DiagnosticInfo* DataDiagnosticInfos;
}
OpcUa_ParsingResult;

OPCUA_EXPORT OpcUa_Void       OpcUa_ParsingResult_Initialize(OpcUa_ParsingResult* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ParsingResult_Clear(OpcUa_ParsingResult* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ParsingResult_GetSize(OpcUa_ParsingResult* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ParsingResult_Encode(OpcUa_ParsingResult* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ParsingResult_Decode(OpcUa_ParsingResult* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ParsingResult_Compare(const OpcUa_ParsingResult* pValue1, const OpcUa_ParsingResult* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ParsingResult_Copy(const OpcUa_ParsingResult* pSource, OpcUa_ParsingResult** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ParsingResult_CopyTo(const OpcUa_ParsingResult* pSource, OpcUa_ParsingResult* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ParsingResult_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_QueryFirst
#ifndef OPCUA_EXCLUDE_QueryFirstRequest
/*============================================================================
 * The QueryFirstRequest structure.
 *===========================================================================*/
/** \struct OpcUa_QueryFirstRequest
 *  Asynchronously queries the address space.
 *
 *  This Service is used to issue a query request to the Server. The complexity of
 *  the query can range from very simple to highly sophisticated. The query can
 *  simply request data from instances of a TypeDefinitionNode or
 *  TypeDefinitionNode subject to restrictions specified by the filter. On the
 *  other hand, the query can request data from instances of related node types by
 *  specifying a RelativePath from an originating TypeDefinitionNode.In the filter,
 *  a separate set of paths can be constructed for limiting the instances that
 *  supply data. A filtering path can include multiple RelatedTo operators to
 *  define a multi-hop path between source instances and target instances.
 *
 *  The Client provides an array of NodeTypeDescription which specify the NodeId of
 *  a TypeDefinitionNode and selects what attributes are to be returned in the
 *  response. A client can also provide a set of RelativePaths through the type
 *  system starting from an originating TypeDefinitionNode. Using these paths, the
 *  client selects a set of attributes from nodes that are related to instances of
 *  the originating TypeDefinitionNode. Additionally, the Client can request the
 *  Server return instances of subtypes of TypeDefinitionNodes. If a selected
 *  Attribute does not exist in a TypeDefinitionNode but does exist in a subtype,
 *  it is assumed to have a null value in the TypeDefinitionNode in question.
 *  Therefore, this does not constitute an error condition and a null value is
 *  returned for the Attribute.
 *
 *  The Client can use the filter parameter to limit the result set by restricting
 *  attributes and properties to certain values. Another way the Client can use a
 *  filter to limit the result set is by specifying how instances should be
 *  related, using RelatedTo operators. In this case, if an instance at the top of
 *  the RelatedTo path cannot be followed to the bottom of the path via specified
 *  hops, no QueryDataSets are returned for the starting instance or any of the
 *  intermediate instances.
 *
 *  When querying for related instances in the RelativePath, the Client can
 *  optionally ask for references. A reference is requested via a RelativePath that
 *  only includes a ReferenceType. If all references are desired than the root
 *  ReferenceType is listed. These references are returned as part of the
 *  QueryDataSets.
 *
 *  Query services allow a special handling of the targetName field in the
 *  RelativePath. In several query use cases, a type NodeId is necessary in the
 *  path instead of a QualifiedName. Therefore, the Client is allowed to specify a
 *  NodeId in the QualifiedName. This is done by setting the namespaceIndex of the
 *  targetName to zero and the name part of the targetName to the XML
 *  representation of the NodeId. When matching instances are returned as the
 *  target node, the target node shall be an instance of the specified type or
 *  subtype of the specified type.
 *
 *  \var OpcUa_QueryFirstRequest::View
 *  Specifies a view and temporal context to a Server.
 *
 *  \var OpcUa_QueryFirstRequest::NodeTypes
 *  The node type description.
 *
 *  \var OpcUa_QueryFirstRequest::Filter
 *  Resulting nodes shall be limited to the nodes matching the criteria defined by
 *  the filter.
 *
 *  Resulting nodes shall be limited to the nodes matching the criteria defined by
 *  the filter.
 *
 *  \var OpcUa_QueryFirstRequest::MaxDataSetsToReturn
 *  The number of QueryDataSets that the Client wants the Server to return in the
 *  response and on each subsequent continuation call response.
 *
 *  The Server is allowed to further limit the response, but shall not exceed this
 *  limit. A value of 0 indicates that the Client is imposing no limitation.
 *
 *  \var OpcUa_QueryFirstRequest::MaxReferencesToReturn
 *  The number of references that the Client wants the Server to return in the
 *  response for each QueryDataSet and on each subsequent continuation call
 *  response.
 *
 *  The Server is allowed to further limit the response, but shall not exceed this
 *  limit.
 *
 *  A value of 0 indicates that the Client is imposing no limitation.
 *
 *  For example: In a result, 4 Nodes are being returned, but each has 100
 *  References. If this limit was set to 50, only the first 50 References for each
 *  Node would be returned on the initial call, and a continuation point would be
 *  set indicating additional data.
 */
typedef struct _OpcUa_QueryFirstRequest
{
    OpcUa_RequestHeader        RequestHeader;
    OpcUa_ViewDescription      View;
    OpcUa_Int32                NoOfNodeTypes;
    OpcUa_NodeTypeDescription* NodeTypes;
    OpcUa_ContentFilter        Filter;
    OpcUa_UInt32               MaxDataSetsToReturn;
    OpcUa_UInt32               MaxReferencesToReturn;
}
OpcUa_QueryFirstRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_QueryFirstRequest_Initialize(OpcUa_QueryFirstRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_QueryFirstRequest_Clear(OpcUa_QueryFirstRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryFirstRequest_GetSize(OpcUa_QueryFirstRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryFirstRequest_Encode(OpcUa_QueryFirstRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryFirstRequest_Decode(OpcUa_QueryFirstRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_QueryFirstRequest_Compare(const OpcUa_QueryFirstRequest* pValue1, const OpcUa_QueryFirstRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryFirstRequest_Copy(const OpcUa_QueryFirstRequest* pSource, OpcUa_QueryFirstRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryFirstRequest_CopyTo(const OpcUa_QueryFirstRequest* pSource, OpcUa_QueryFirstRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_QueryFirstRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_QueryFirst */

#ifndef OPCUA_EXCLUDE_QueryFirst
#ifndef OPCUA_EXCLUDE_QueryFirstResponse
/*============================================================================
 * The QueryFirstResponse structure.
 *===========================================================================*/
/** \struct OpcUa_QueryFirstResponse
 *
 * Response to a \ref OpcUa_QueryFirstRequest.
 *
 *  \var OpcUa_QueryFirstResponse::QueryDataSets
 *  The array of QueryDataSets.
 *
 *  This array is empty if no nodes or references met the \ref
 *  OpcUa_QueryFirstRequest::NodeTypes criteria. In this case, the
 *  ContinuationPoint parameter shall be empty.
 *
 *  \var OpcUa_QueryFirstResponse::ContinuationPoint
 *  Server-defined opaque value that identifies the continuation point.
 *
 *  The continuation point is used only when the Query results are too large to be
 *  returned in a single response. “Too large” in this context means that the
 *  Server is not able to return a larger response or that the number of
 *  QueryDataSets to return exceeds the maximum number of QueryDataSets to return
 *  that was specified by the Client in the request.
 *
 *  The continuation point is used in the QueryNext Service. If not used, the value
 *  of this parameter is null. If a continuation point is returned, the Client
 *  shall call QueryNext to get the next set of QueryDataSets or to free the
 *  resources for the continuation point in the Server.
 *
 *  A continuation point shall remain active until the Client passes the
 *  continuation point to QueryNext or the session is closed. If the maximum
 *  continuation points have been reached, the oldest continuation point shall be
 *  reset.
 *
 *  \var OpcUa_QueryFirstResponse::ParsingResults
 *  List of parsing results for QueryFirst.
 *
 *  The size and order of the list matches the size and order of the NodeTypes
 *  request parameter.
 *
 *  This list is populated with any status codes that are related to the processing
 *  of the node types that are part of the query. The array can be empty if no
 *  errors were encountered. If any node type encountered an error, all node types
 *  shall have an associated status code.
 *
 *  \var OpcUa_QueryFirstResponse::DiagnosticInfos
 *  List of diagnostic information for the requested NodeTypeDescription.
 *
 *  This list is empty if diagnostics information was not requested in the request
 *  header or if no diagnostic information was encountered in processing of the
 *  query request.
 *
 *  \var OpcUa_QueryFirstResponse::FilterResult
 *  A structure that contains any errors associated with the filter.
 *
 *  This structure shall be empty if no errors occurred.
 */
typedef struct _OpcUa_QueryFirstResponse
{
    OpcUa_ResponseHeader      ResponseHeader;
    OpcUa_Int32               NoOfQueryDataSets;
    OpcUa_QueryDataSet*       QueryDataSets;
    OpcUa_ByteString          ContinuationPoint;
    OpcUa_Int32               NoOfParsingResults;
    OpcUa_ParsingResult*      ParsingResults;
    OpcUa_Int32               NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo*     DiagnosticInfos;
    OpcUa_ContentFilterResult FilterResult;
}
OpcUa_QueryFirstResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_QueryFirstResponse_Initialize(OpcUa_QueryFirstResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_QueryFirstResponse_Clear(OpcUa_QueryFirstResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryFirstResponse_GetSize(OpcUa_QueryFirstResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryFirstResponse_Encode(OpcUa_QueryFirstResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryFirstResponse_Decode(OpcUa_QueryFirstResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_QueryFirstResponse_Compare(const OpcUa_QueryFirstResponse* pValue1, const OpcUa_QueryFirstResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryFirstResponse_Copy(const OpcUa_QueryFirstResponse* pSource, OpcUa_QueryFirstResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryFirstResponse_CopyTo(const OpcUa_QueryFirstResponse* pSource, OpcUa_QueryFirstResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_QueryFirstResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_QueryFirst */

#ifndef OPCUA_EXCLUDE_QueryNext
#ifndef OPCUA_EXCLUDE_QueryNextRequest
/*============================================================================
 * The QueryNextRequest structure.
 *===========================================================================*/
/** \struct OpcUa_QueryNextRequest
 *  This Service is used to request the next set of QueryFirst or QueryNext
 *  response information that is too large to be sent in a single response.
 *
 *  “Too large” in this context means that the Server is not able to return a
 *  larger response or that the number of QueryDataSets to return exceeds the
 *  maximum number of QueryDataSets to return that was specified by the Client in
 *  the original request. The QueryNext shall be submitted on the same session that
 *  was used to submit the QueryFirst or QueryNext that is being continued.
 *
 *  \var OpcUa_QueryNextRequest::ReleaseContinuationPoint
 *  A boolean parameter indicating whether continuation points should be released.
 *
 *  It has the following values: <dl> <dt>TRUE</dt> <dd>passed ContinuationPoints
 *  shall be reset to free resources in the Server.</dd> <dt>FALSE</dt> <dd>passed
 *  ContinuationPoints shall be used to get the next set of QueryDataSEts.</dd>
 *  </dl>
 *
 *  A Client shall always use the continuation point returned by a QueryFirst or
 *  QueryNext response to free the resources for the continuation point in the
 *  Server. If the Client does not want to get the next set of Query information,
 *  QueryNext shall be called with this parameter set to TRUE.
 *
 *  If the parameter is set to TRUE, all array parameters in the response shall
 *  contain empty arrays.
 *
 *  \var OpcUa_QueryNextRequest::ContinuationPoint
 *  Server defined opaque value that represents the continuation point.
 *
 *  The value of the continuation point was returned to the Client in a previous
 *  QueryFirst or QueryNext response. This value is used to identify the previously
 *  processed QueryFirst or QueryNext request that is being continued, and the
 *  point in the result set from which the browse response is to continue.
 */
typedef struct _OpcUa_QueryNextRequest
{
    OpcUa_RequestHeader RequestHeader;
    OpcUa_Boolean       ReleaseContinuationPoint;
    OpcUa_ByteString    ContinuationPoint;
}
OpcUa_QueryNextRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_QueryNextRequest_Initialize(OpcUa_QueryNextRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_QueryNextRequest_Clear(OpcUa_QueryNextRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryNextRequest_GetSize(OpcUa_QueryNextRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryNextRequest_Encode(OpcUa_QueryNextRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryNextRequest_Decode(OpcUa_QueryNextRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_QueryNextRequest_Compare(const OpcUa_QueryNextRequest* pValue1, const OpcUa_QueryNextRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryNextRequest_Copy(const OpcUa_QueryNextRequest* pSource, OpcUa_QueryNextRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryNextRequest_CopyTo(const OpcUa_QueryNextRequest* pSource, OpcUa_QueryNextRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_QueryNextRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_QueryNext */

#ifndef OPCUA_EXCLUDE_QueryNext
#ifndef OPCUA_EXCLUDE_QueryNextResponse
/*============================================================================
 * The QueryNextResponse structure.
 *===========================================================================*/
/** \struct OpcUa_QueryNextResponse
 *
 * Response to a \ref OpcUa_QueryNextRequest.
 *
 *  \var OpcUa_QueryNextResponse::QueryDataSets
 *  The array of QueryDataSets
 *
 *  \var OpcUa_QueryNextResponse::RevisedContinuationPoint
 *  Server-defined opaque value that represents the continuation point.
 *
 *  It is used only if the information to be returned is too large to be contained
 *  in a single response. If not used or if \ref
 *  OpcUa_QueryNextRequest::ReleaseContinuationPoint is set, the value of this
 *  parameter is null.
 */
typedef struct _OpcUa_QueryNextResponse
{
    OpcUa_ResponseHeader ResponseHeader;
    OpcUa_Int32          NoOfQueryDataSets;
    OpcUa_QueryDataSet*  QueryDataSets;
    OpcUa_ByteString     RevisedContinuationPoint;
}
OpcUa_QueryNextResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_QueryNextResponse_Initialize(OpcUa_QueryNextResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_QueryNextResponse_Clear(OpcUa_QueryNextResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryNextResponse_GetSize(OpcUa_QueryNextResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryNextResponse_Encode(OpcUa_QueryNextResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryNextResponse_Decode(OpcUa_QueryNextResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_QueryNextResponse_Compare(const OpcUa_QueryNextResponse* pValue1, const OpcUa_QueryNextResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryNextResponse_Copy(const OpcUa_QueryNextResponse* pSource, OpcUa_QueryNextResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_QueryNextResponse_CopyTo(const OpcUa_QueryNextResponse* pSource, OpcUa_QueryNextResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_QueryNextResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_QueryNext */

#ifndef OPCUA_EXCLUDE_ReadValueId
/*============================================================================
 * The ReadValueId structure.
 *===========================================================================*/
/** \struct OpcUa_ReadValueId
 *  Identifier for an item to read or to monitor.
 *
 *  \var OpcUa_ReadValueId::NodeId
 *  NodeId of a Node.
 *
 *  \var OpcUa_ReadValueId::AttributeId
 *  Id of the Attribute. This shall be a valid Attribute id.
 *
 *  The IntegerIds for the Attributes are defined in NodeAttributesMask.
 *
 *  \var OpcUa_ReadValueId::IndexRange
 *  This parameter is used to identify a single element of an array, or a single
 *  range of indexes for arrays.
 *
 *  If a range of elements is specified, the values are returned as a composite.
 *  The first element is identified by index 0 (zero).
 *
 *  This parameter is null if the specified Attribute is not an array. However, if
 *  the specified Attribute is an array, and this parameter is null, then all
 *  elements are to be included in the range.
 *
 *  \var OpcUa_ReadValueId::DataEncoding
 *  This parameter specifies the BrowseName of the DataTypeEncoding that the Server
 *  should use when returning the Value Attribute of a Variable. It is an error to
 *  specify this parameter for other Attributes.
 *
 *  A Client can discover what DataTypeEncodings are available by following the
 *  HasEncoding Reference from the DataType Node for a Variable.
 *
 *  OPC UA defines BrowseNames which Servers shall recognize even if the DataType
 *  Nodes are not visible in the Server address space. These BrowseNames are:
 *
 *  <dl><dt>DefaultBinary</dt><dd>The default or native binary (or non-XML)
 *  encoding.</dd><dt>DefaultXML</dt><dd>The default XML encoding.</dd></dl>
 *
 *  Each DataType shall support at least one of these encodings. DataTypes that do
 *  not have a true binary encoding (e.g. they only have a non-XML text encoding)
 *  should use the DefaultBinary name to identify the encoding that is considered
 *  to be the default non-XML encoding. DataTypes that support at least one
 *  XML-based encoding shall identify one of the encodings as the DefaultXML
 *  encoding. Other standards bodies may define other well-known data encodings
 *  that could be supported.
 *
 *  If this parameter is not specified then the Server shall choose either the
 *  DefaultBinary or DefaultXML encoding according to what Message encoding (see
 *  Part 6 of the OPC UA Specification) is used for the Session. If the Server does
 *  not support the encoding that matches the Message encoding then the Server
 *  shall choose the default encoding that it does support.
 *
 *  If this parameter is specified for a MonitoredItem, the Server shall set the
 *  StructureChanged bit in the StatusCode if the DataTypeEncoding changes. The
 *  DataTypeEncoding changes if the DataTypeVersion of the DataTypeDescription or
 *  the DataTypeDictionary associated with the DataTypeEncoding changes.
 */
typedef struct _OpcUa_ReadValueId
{
    OpcUa_NodeId        NodeId;
    OpcUa_UInt32        AttributeId;
    OpcUa_String        IndexRange;
    OpcUa_QualifiedName DataEncoding;
}
OpcUa_ReadValueId;

OPCUA_EXPORT OpcUa_Void       OpcUa_ReadValueId_Initialize(OpcUa_ReadValueId* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ReadValueId_Clear(OpcUa_ReadValueId* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadValueId_GetSize(OpcUa_ReadValueId* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadValueId_Encode(OpcUa_ReadValueId* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadValueId_Decode(OpcUa_ReadValueId* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ReadValueId_Compare(const OpcUa_ReadValueId* pValue1, const OpcUa_ReadValueId* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadValueId_Copy(const OpcUa_ReadValueId* pSource, OpcUa_ReadValueId** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadValueId_CopyTo(const OpcUa_ReadValueId* pSource, OpcUa_ReadValueId* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ReadValueId_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_Read
#ifndef OPCUA_EXCLUDE_ReadRequest
/*============================================================================
 * The ReadRequest structure.
 *===========================================================================*/
/** \struct OpcUa_ReadRequest
 *  Reads values and attributes asynchronously from OPC server.
 *
 *  The Read Service is used to read one or more attributes of one or more nodes.
 *  It allows also reading subsets or single elements of array values and to define
 *  a valid age of values to be returned to reduce the need for device reads. Like
 *  most other services, the read is optimized for bulk read operations and not for
 *  reading single Attribute values. Typically all Node Attributes are readable.
 *  For the Value Attribute the Read rights are indicated by the AccessLevel and
 *  UserAccessLevel Attribute of the Variable.
 *
 *  \var OpcUa_ReadRequest::MaxAge
 *  Maximum age of the value to be read in milliseconds.
 *
 *  The age of the value is based on the difference between the ServerTimestamp and
 *  the time when the Server starts processing the request. For example if the
 *  Client specifies a maxAge of 500 milliseconds and it takes 100 milliseconds
 *  until the Server starts processing the request, the age of the returned value
 *  could be 600 milliseconds prior to the time it was requested.
 *
 *  If the Server has one or more values of an Attribute that are within the
 *  maximum age, it can return any one of the values or it can read a new value
 *  from the data source. The number of values of an Attribute that a Server has
 *  depends on the number of MonitoredItems that are defined for the Attribute. In
 *  any case, the Client can make no assumption about which copy of the data will
 *  be returned.
 *
 *  If the Server does not have a value that is within the maximum age, it shall
 *  attempt to read a new value from the data source.
 *
 *  If the Server cannot meet the requested maxAge, it returns its "best effort"
 *  value rather than rejecting the request. This may occur when the time it takes
 *  the Server to process and return the new data value after it has been accessed
 *  is greater than the specified maximum age.
 *
 *  If maxAge is set to 0, the Server shall attempt to read a new value from the
 *  data source.
 *
 *  If maxAge is set to the max Int32 value or greater, the Server shall attempt to
 *  get a cached value.
 *
 *  Negative values are invalid for maxAge.
 *
 *  \var OpcUa_ReadRequest::TimestampsToReturn
 *  An enumeration that specifies the Timestamps to be returned for each requested
 *  Variable Value Attribute. See \ref OpcUa_TimestampsToReturn for more
 *  information.
 *
 *  \var OpcUa_ReadRequest::NodesToRead
 *  List of Nodes and their Attributes to read.
 *
 *  For each entry in this list, a StatusCode is returned, and if it indicates
 *  success, the Attribute Value is also returned.
 */
typedef struct _OpcUa_ReadRequest
{
    OpcUa_RequestHeader      RequestHeader;
    OpcUa_Double             MaxAge;
    OpcUa_TimestampsToReturn TimestampsToReturn;
    OpcUa_Int32              NoOfNodesToRead;
    OpcUa_ReadValueId*       NodesToRead;
}
OpcUa_ReadRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_ReadRequest_Initialize(OpcUa_ReadRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ReadRequest_Clear(OpcUa_ReadRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadRequest_GetSize(OpcUa_ReadRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadRequest_Encode(OpcUa_ReadRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadRequest_Decode(OpcUa_ReadRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ReadRequest_Compare(const OpcUa_ReadRequest* pValue1, const OpcUa_ReadRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadRequest_Copy(const OpcUa_ReadRequest* pSource, OpcUa_ReadRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadRequest_CopyTo(const OpcUa_ReadRequest* pSource, OpcUa_ReadRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ReadRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_Read */

#ifndef OPCUA_EXCLUDE_Read
#ifndef OPCUA_EXCLUDE_ReadResponse
/*============================================================================
 * The ReadResponse structure.
 *===========================================================================*/
/** \struct OpcUa_ReadResponse
 *
 * Response to a \ref OpcUa_ReadRequest.
 *
 *  \var OpcUa_ReadResponse::Results
 *  List of read results contained in an array of DataValue structures.
 *
 *  The DataValue consists of <dl> <dt>Value</dt> <dd>The value of the read node
 *  and attribute combination</dd> <dt>StatusCode</dt> <dd>This parameter is used
 *  to indicate the conditions under which the value was generated, and thereby can
 *  be used as an indicator of the usability of the value.</dd>
 *  <dt>SourceTimestamp</dt> <dd> Reflects the UTC timestamp that was applied to
 *  the value by the data source. It is only available for Value attributes.</dd>
 *  <dt>ServerTimestamp</dt> <dd>Reflects the time that the Server received the
 *  value or knew it to be accurate.</dd> </dl>
 *
 *  The size and order of this list matches the size and order of the request
 *  parameter. There is one entry in this list for each Node contained in the
 *  parameter.
 *
 *  \var OpcUa_ReadResponse::DiagnosticInfos
 *  List of diagnostic information.
 *
 *  The size and order of this list matches the size and order of the \ref
 *  OpcUa_ReadRequest::NodesToRead request parameter. There is one entry in this
 *  list for each Node contained in the \ref OpcUa_ReadRequest::NodesToRead
 *  parameter. This list is empty if diagnostics information was not requested in
 *  the request header or if no diagnostic information was encountered in
 *  processing of the request.
 */
typedef struct _OpcUa_ReadResponse
{
    OpcUa_ResponseHeader  ResponseHeader;
    OpcUa_Int32           NoOfResults;
    OpcUa_DataValue*      Results;
    OpcUa_Int32           NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo* DiagnosticInfos;
}
OpcUa_ReadResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_ReadResponse_Initialize(OpcUa_ReadResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ReadResponse_Clear(OpcUa_ReadResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadResponse_GetSize(OpcUa_ReadResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadResponse_Encode(OpcUa_ReadResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadResponse_Decode(OpcUa_ReadResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ReadResponse_Compare(const OpcUa_ReadResponse* pValue1, const OpcUa_ReadResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadResponse_Copy(const OpcUa_ReadResponse* pSource, OpcUa_ReadResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadResponse_CopyTo(const OpcUa_ReadResponse* pSource, OpcUa_ReadResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ReadResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_Read */

#ifndef OPCUA_EXCLUDE_HistoryReadValueId
/*============================================================================
 * The HistoryReadValueId structure.
 *===========================================================================*/
/** \struct OpcUa_HistoryReadValueId
 *  A structure that is defined as the type of the nodesToRead parameter of the
 *  HistoryRead Service.
 *
 *  \var OpcUa_HistoryReadValueId::NodeId
 *  The nodeId to be read depends on HistoryReadDetails.
 *
 *  If HistoryReadDetails is <dl> <dt>RAW, PROCESSED, MODIFIED or ATTIME</dt>
 *  <dd>The nodeId of the Nodes whose historical values are to be read. The value
 *  returned shall always include a timestamp.</dd> <dt>EVENTS</dt> <dd>The NodeId
 *  of the Node whose Event history is to be read.</dd> </dl>
 *
 *  If the Node does not support the requested access for historical values or
 *  historical events, the appropriate error response for the given node shall be
 *  generated.
 *
 *  \var OpcUa_HistoryReadValueId::IndexRange
 *  This parameter is used to identify a single element of an array, or a single
 *  range of indexes for arrays.
 *
 *  If a range of elements is specified, the values are returned as a composite.
 *  The first element is identified by index 0 (zero).
 *
 *  This parameter is null if the value is not an array. However, if the value is
 *  an array, and this parameter is null, then all elements are to be included in
 *  the range.
 *
 *  \var OpcUa_HistoryReadValueId::DataEncoding
 *  A QualifiedName that specifies the data encoding to be returned for the Value
 *  to be read.
 *
 *  See \ref OpcUa_ReadValueId for a definition on how to specify the data
 *  encoding.
 *
 *  The parameter is ignored when reading history of Events.
 *
 *  \var OpcUa_HistoryReadValueId::ContinuationPoint
 *  For each NodeToRead this parameter specifies a continuation point returned from
 *  a previous HistoryRead call, allowing the Client to continue that read from the
 *  last value received.
 *
 *  The HistoryRead is used to select an ordered sequence of historical values or
 *  events. A continuation point marks a point in that ordered sequence, such that
 *  the Server returns the subset of the sequence that follows that point.
 *
 *  A null value indicates that this parameter is not used.
 *
 *  This continuation point is described in more detail in Part 11 of the OPC UA
 *  Specification.
 */
typedef struct _OpcUa_HistoryReadValueId
{
    OpcUa_NodeId        NodeId;
    OpcUa_String        IndexRange;
    OpcUa_QualifiedName DataEncoding;
    OpcUa_ByteString    ContinuationPoint;
}
OpcUa_HistoryReadValueId;

OPCUA_EXPORT OpcUa_Void       OpcUa_HistoryReadValueId_Initialize(OpcUa_HistoryReadValueId* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_HistoryReadValueId_Clear(OpcUa_HistoryReadValueId* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryReadValueId_GetSize(OpcUa_HistoryReadValueId* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryReadValueId_Encode(OpcUa_HistoryReadValueId* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryReadValueId_Decode(OpcUa_HistoryReadValueId* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_HistoryReadValueId_Compare(const OpcUa_HistoryReadValueId* pValue1, const OpcUa_HistoryReadValueId* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryReadValueId_Copy(const OpcUa_HistoryReadValueId* pSource, OpcUa_HistoryReadValueId** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryReadValueId_CopyTo(const OpcUa_HistoryReadValueId* pSource, OpcUa_HistoryReadValueId* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_HistoryReadValueId_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_HistoryReadResult
/*============================================================================
 * The HistoryReadResult structure.
 *===========================================================================*/
/** \struct OpcUa_HistoryReadResult
 *  A structure that is defined as the type of the results parameter of the
 *  HistoryRead Service.
 *
 *  \var OpcUa_HistoryReadResult::StatusCode
 *  StatusCode for the nodesToRead item.
 *
 *  \var OpcUa_HistoryReadResult::ContinuationPoint
 *  This parameter is used only if the number of values to be returned is too large
 *  to be returned in a single response or if the timeout provided as hint by the
 *  Client is close to expiring and not all nodes have been processed.
 *
 *  If this parameter is not used, its value is null.
 *
 *  Servers shall support at least one continuation point per Session. Servers
 *  specify a maximum number of history continuation points per Session in the
 *  Server capabilities object defined in Part 5 of the OPC UA specification. A
 *  continuation point shall remain active until the Client passes the continuation
 *  point to HistoryRead or the Session is closed. If the maximum number of
 *  continuation points have been reached, the oldest continuation point shall be
 *  reset.
 *
 *  \var OpcUa_HistoryReadResult::HistoryData
 *  The history data returned for the node.
 *
 *  The HistoryData parameter type is an extensible parameter type formally defined
 *  in Part 11 of the OPC UA Specification. It specifies the types of history data
 *  that can be returned.
 */
typedef struct _OpcUa_HistoryReadResult
{
    OpcUa_StatusCode      StatusCode;
    OpcUa_ByteString      ContinuationPoint;
    OpcUa_ExtensionObject HistoryData;
}
OpcUa_HistoryReadResult;

OPCUA_EXPORT OpcUa_Void       OpcUa_HistoryReadResult_Initialize(OpcUa_HistoryReadResult* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_HistoryReadResult_Clear(OpcUa_HistoryReadResult* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryReadResult_GetSize(OpcUa_HistoryReadResult* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryReadResult_Encode(OpcUa_HistoryReadResult* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryReadResult_Decode(OpcUa_HistoryReadResult* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_HistoryReadResult_Compare(const OpcUa_HistoryReadResult* pValue1, const OpcUa_HistoryReadResult* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryReadResult_Copy(const OpcUa_HistoryReadResult* pSource, OpcUa_HistoryReadResult** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryReadResult_CopyTo(const OpcUa_HistoryReadResult* pSource, OpcUa_HistoryReadResult* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_HistoryReadResult_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ReadRawModifiedDetails
/*============================================================================
 * The ReadRawModifiedDetails structure.
 *===========================================================================*/
/** \struct OpcUa_ReadRawModifiedDetails
 *  Selects a set of raw or modified values from the history database by specifying
 *  a time domain for one or more variables.
 *
 *  <b>Read raw functionality</b>
 *
 *  When this structure is used for reading Raw Values, it reads the values,
 *  qualities, and timestamps from the history database for the specified time
 *  domain for one or more HistoricalDataNodes. This parameter is intended for use
 *  by a Client that wants the actual data saved within the historian. The actual
 *  data may be compressed or may be all raw data collected for the item depending
 *  on the historian and the storage rules invoked when the item values were saved.
 *  When returnBounds is TRUE, the bounding values for the time domain are
 *  returned. The optional bounding values are provided to allow the Client to
 *  interpolate values for the start and end times when trending the actual data on
 *  a display.
 *
 *  The time domain of the request is defined by startTime, endTime, and
 *  numValuesPerNode; at least two of these must be specified. If endTime is less
 *  than startTime, or endTime and numValuesPerNode alone are specified, the data
 *  will be returned in reverse order, with later data coming first, as if time was
 *  flowing backward. If all three are specified, the call shall return up to
 *  numValuesPerNode results going from startTime to endTime, in either ascending
 *  or descending order, depending on the relative values of startTime and endTime.
 *  If numValuesPerNode is 0, all the values in the range are returned. A default
 *  value of DateTime.MinValue is used to indicate that startTime or endTime are
 *  not specified.
 *
 *  It is specifically allowed for the startTime and the endTime to be identical.
 *  This allows the Client to request just one value. If startTime and endTime are
 *  identical, time is presumed to be flowing forward. It is specifically not
 *  allowed for the server to return a Bad_InvalidArgument StatusCode if the
 *  requested time domain is outside of the server’s range. Such a case shall be
 *  treated as an interval in which no data exists.
 *
 *  If startTime, endTime, and numValuesPerNode are all provided and if more than
 *  numValuesPerNode values exist within that time range for a given node, only
 *  numValuesPerNode values per node are returned along with a continuationPoint.
 *  When a continuationPoint is returned, a Client wanting the next
 *  numValuesPerNode values should call ReadRaw again with the continuationPoint
 *  set.
 *
 *  If Bounding Values are requested and a non-zero numValuesPerNode was specified,
 *  any bounding values returned are included in the numValuesPerNode count. If
 *  numValuesPerNode is 1, only the start bound is returned (the end bound if
 *  reverse order is needed). If numValuesPerNode is 2, the start bound and the
 *  first data point are returned (the end bound if reverse order is needed). When
 *  bounding values are requested and no bounding value is found, the corresponding
 *  StatusCode entry will be set to Bad_BoundNotFound, a timestamp equal to the
 *  start or end time as appropriate, and a value of null. How far back or forward
 *  to look in history for bounding values is server dependent.
 *
 *  For an interval in which no data exists, if bounding values are not requested,
 *  the corresponding StatusCode must be Good_NoData. If bounding values are
 *  requested and one or both exist, then the result code returned is Success and
 *  the bounding value(s) are returned.
 *
 *  For cases where there are multiple values for a given timestamp, all but the
 *  most recent are considered to be modified values and the server must return the
 *  most recent value. If the server returns a value which hides other values at a
 *  timestamp, it must set the ExtraData bit in the StatusCode associated with that
 *  value. If the Server contains additional information regarding a value, the
 *  ExtraData bit shall also be set. This indicates that ModifiedValues are
 *  available for retrieval.
 *
 *  If the requested timestamp format is not supported for a node, the operation
 *  shall return the Bad_TimestampNotSupported StatusCode.
 *
 *  <b>Read modified functionality</b>
 *
 *  When this structure is used for reading modified values, it reads the values,
 *  StatusCodes, timestamps, modification type, the user identifier, and the
 *  timestamp of the modification from the history database for the specified time
 *  domain for one or more HistoricalDataNodes. If there are multiple replaced
 *  values, the server must return all of them. The updateType specifies which
 *  value is returned in the modification record. If the updateType is INSERT, the
 *  value is the new value that was inserted. If the updateType is anything else,
 *  the value is the old value that was changed.
 *
 *  The purpose of this function is to read values from history that have been
 *  modified. The returnBounds parameter must be set to FALSE for this case,
 *  otherwise the server returns a Bad_InvalidArgument StatusCode.
 *
 *  The domain of the request is defined by startTime, endTime, and
 *  numValuesPerNode; at least two of these must be specified. If endTime is less
 *  than startTime, or endTime and numValuesPerNode alone are specified, the data
 *  shall be returned in reverse order with later data coming first. If all three
 *  are specified, the call shall return up to numValuesPerNode results going from
 *  StartTime to EndTime, in either ascending or descending order, depending on the
 *  relative values of StartTime and EndTime. If more than numValuesPerNode values
 *  exist within that time range for a given Node, only numValuesPerNode values per
 *  node are returned along with a continuationPoint. If a continuationPoint is
 *  returned, a Client wanting the next numValuesPerNode values should call ReadRaw
 *  again with the continuationPoint set. If numValuesPerNode is 0, all of the
 *  values in the range are returned. If the Server cannot return all modified
 *  values for a given timestamp in a single response, it shall return modified
 *  values with the same timestamp in subsequent calls.
 *
 *  If a value has been modified multiple times, all values for the time are
 *  returned. This means that a timestamp can appear in the array more than once.
 *  The order of the returned values with the same timestamp should be from the
 *  most recent to oldest modification timestamp if startTime is less than or equal
 *  to endTime. If endTime is less than startTime, the order of the returned values
 *  will be from the oldest modificfication timestamp to the most recent. It is
 *  server dependent whether multiple modifications are kept or only the most
 *  recent.
 *
 *  A server does not have to create a modification record for data when it is
 *  first added to the historical collection. If it does, it shall set the
 *  ExtraData bit and the Client can read the modification record using a
 *  ReadModified call. If the data is subsequently modified, the server shall
 *  create a second modification record, which is returned along with the original
 *  modification record whenever a Client uses the ReadModified call if the Server
 *  supports multiple modification records per timestamp.
 *
 *  If the requested timestamp format is not supported for a Node, the operation
 *  shall return the Bad_TimestampNotSupported StatusCode.
 *
 *  \var OpcUa_ReadRawModifiedDetails::IsReadModified
 *  TRUE for read modified functionality, FALSE for read raw functionality.
 *
 *  The default value is FALSE.
 *
 *  \var OpcUa_ReadRawModifiedDetails::StartTime
 *  The beginning of the period to read.
 *
 *  Set to default value of DateTime.MinValue if no specific start time is
 *  specified.
 *
 *  \var OpcUa_ReadRawModifiedDetails::EndTime
 *  The end of the period to read.
 *
 *  Set to default value of DateTime.MinValue if no specific end time is specified.
 *
 *  \var OpcUa_ReadRawModifiedDetails::NumValuesPerNode
 *  The maximum number of values returned for any node over the time range.
 *
 *  If only one time is specified, the time range must extend to return this number
 *  of values. The default value 0 indicates that there is no maximum.
 *
 *  \var OpcUa_ReadRawModifiedDetails::ReturnBounds
 *  A boolean parameter indicating whether bounding values should be returned.
 *
 *  It has the following values <dl> <dt>TRUE</dt> <dd>bounding values should be
 *  returned</dd> <dt>FALSE</dt> <dd>all other cases</dd> </dl>
 */
typedef struct _OpcUa_ReadRawModifiedDetails
{
    OpcUa_Boolean  IsReadModified;
    OpcUa_DateTime StartTime;
    OpcUa_DateTime EndTime;
    OpcUa_UInt32   NumValuesPerNode;
    OpcUa_Boolean  ReturnBounds;
}
OpcUa_ReadRawModifiedDetails;

OPCUA_EXPORT OpcUa_Void       OpcUa_ReadRawModifiedDetails_Initialize(OpcUa_ReadRawModifiedDetails* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ReadRawModifiedDetails_Clear(OpcUa_ReadRawModifiedDetails* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadRawModifiedDetails_GetSize(OpcUa_ReadRawModifiedDetails* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadRawModifiedDetails_Encode(OpcUa_ReadRawModifiedDetails* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadRawModifiedDetails_Decode(OpcUa_ReadRawModifiedDetails* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ReadRawModifiedDetails_Compare(const OpcUa_ReadRawModifiedDetails* pValue1, const OpcUa_ReadRawModifiedDetails* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadRawModifiedDetails_Copy(const OpcUa_ReadRawModifiedDetails* pSource, OpcUa_ReadRawModifiedDetails** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadRawModifiedDetails_CopyTo(const OpcUa_ReadRawModifiedDetails* pSource, OpcUa_ReadRawModifiedDetails* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ReadRawModifiedDetails_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ReadAtTimeDetails
/*============================================================================
 * The ReadAtTimeDetails structure.
 *===========================================================================*/
/** \struct OpcUa_ReadAtTimeDetails
 *  Selects a set of raw or interpolated values from the history database by
 *  specifying a series of timestamps for one or more variables.
 *
 *  The ReadAtTimeDetails structure reads the values and qualities from the history
 *  database for the specified timestamps for one or more HistoricalDataNodes. This
 *  function is intended to provide values to correlate with other values with a
 *  known timestamp. For example, a Client may need to read the values of sensors
 *  when lab samples were collected.
 *
 *  The order of the values and qualities returned shall match the order of the
 *  timestamps supplied in the request.
 *
 *  If no value exists for a specified timestamp, a value shall be interpolated
 *  from the surrounding values to represent the value at the specified timestamp.
 *  The interpolation will follow the same rules as the standard interpolated
 *  aggregate as outlined in Part 13 of the OPC UA specification.
 *
 *  If the useSimpleBounds flag is True and interpolation is required, SimpleBounds
 *  will be used to calculate the data value.
 *
 *  If a value is found for the specified timestamp, the server will set the
 *  StatusCode InfoBits to be Raw. If the value is interpolated from the
 *  surrounding values, the server will set the StatusCode InfoBits to be
 *  Interpolated.
 *
 *  If the requested timestamp format is not supported for a node, the operation
 *  shall return the Bad_TimestampNotSupported StatusCode.
 *
 *  \var OpcUa_ReadAtTimeDetails::ReqTimes
 *  Defines the specific timestamps for which values are to be read.
 *
 *  \var OpcUa_ReadAtTimeDetails::UseSimpleBounds
 *  Use simple bounds to determine the value at the specific timestamp.
 */
typedef struct _OpcUa_ReadAtTimeDetails
{
    OpcUa_Int32     NoOfReqTimes;
    OpcUa_DateTime* ReqTimes;
    OpcUa_Boolean   UseSimpleBounds;
}
OpcUa_ReadAtTimeDetails;

OPCUA_EXPORT OpcUa_Void       OpcUa_ReadAtTimeDetails_Initialize(OpcUa_ReadAtTimeDetails* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ReadAtTimeDetails_Clear(OpcUa_ReadAtTimeDetails* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadAtTimeDetails_GetSize(OpcUa_ReadAtTimeDetails* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadAtTimeDetails_Encode(OpcUa_ReadAtTimeDetails* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadAtTimeDetails_Decode(OpcUa_ReadAtTimeDetails* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ReadAtTimeDetails_Compare(const OpcUa_ReadAtTimeDetails* pValue1, const OpcUa_ReadAtTimeDetails* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadAtTimeDetails_Copy(const OpcUa_ReadAtTimeDetails* pSource, OpcUa_ReadAtTimeDetails** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadAtTimeDetails_CopyTo(const OpcUa_ReadAtTimeDetails* pSource, OpcUa_ReadAtTimeDetails* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ReadAtTimeDetails_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_HistoryData
/*============================================================================
 * The HistoryData structure.
 *===========================================================================*/
typedef struct _OpcUa_HistoryData
{
    OpcUa_Int32      NoOfDataValues;
    OpcUa_DataValue* DataValues;
}
OpcUa_HistoryData;

OPCUA_EXPORT OpcUa_Void       OpcUa_HistoryData_Initialize(OpcUa_HistoryData* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_HistoryData_Clear(OpcUa_HistoryData* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryData_GetSize(OpcUa_HistoryData* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryData_Encode(OpcUa_HistoryData* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryData_Decode(OpcUa_HistoryData* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_HistoryData_Compare(const OpcUa_HistoryData* pValue1, const OpcUa_HistoryData* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryData_Copy(const OpcUa_HistoryData* pSource, OpcUa_HistoryData** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryData_CopyTo(const OpcUa_HistoryData* pSource, OpcUa_HistoryData* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_HistoryData_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ModificationInfo
/*============================================================================
 * The ModificationInfo structure.
 *===========================================================================*/
typedef struct _OpcUa_ModificationInfo
{
    OpcUa_DateTime          ModificationTime;
    OpcUa_HistoryUpdateType UpdateType;
    OpcUa_String            UserName;
}
OpcUa_ModificationInfo;

OPCUA_EXPORT OpcUa_Void       OpcUa_ModificationInfo_Initialize(OpcUa_ModificationInfo* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ModificationInfo_Clear(OpcUa_ModificationInfo* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModificationInfo_GetSize(OpcUa_ModificationInfo* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModificationInfo_Encode(OpcUa_ModificationInfo* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModificationInfo_Decode(OpcUa_ModificationInfo* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ModificationInfo_Compare(const OpcUa_ModificationInfo* pValue1, const OpcUa_ModificationInfo* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModificationInfo_Copy(const OpcUa_ModificationInfo* pSource, OpcUa_ModificationInfo** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModificationInfo_CopyTo(const OpcUa_ModificationInfo* pSource, OpcUa_ModificationInfo* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ModificationInfo_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_HistoryModifiedData
/*============================================================================
 * The HistoryModifiedData structure.
 *===========================================================================*/
typedef struct _OpcUa_HistoryModifiedData
{
    OpcUa_Int32             NoOfDataValues;
    OpcUa_DataValue*        DataValues;
    OpcUa_Int32             NoOfModificationInfos;
    OpcUa_ModificationInfo* ModificationInfos;
}
OpcUa_HistoryModifiedData;

OPCUA_EXPORT OpcUa_Void       OpcUa_HistoryModifiedData_Initialize(OpcUa_HistoryModifiedData* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_HistoryModifiedData_Clear(OpcUa_HistoryModifiedData* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryModifiedData_GetSize(OpcUa_HistoryModifiedData* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryModifiedData_Encode(OpcUa_HistoryModifiedData* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryModifiedData_Decode(OpcUa_HistoryModifiedData* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_HistoryModifiedData_Compare(const OpcUa_HistoryModifiedData* pValue1, const OpcUa_HistoryModifiedData* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryModifiedData_Copy(const OpcUa_HistoryModifiedData* pSource, OpcUa_HistoryModifiedData** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryModifiedData_CopyTo(const OpcUa_HistoryModifiedData* pSource, OpcUa_HistoryModifiedData* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_HistoryModifiedData_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_HistoryRead
#ifndef OPCUA_EXCLUDE_HistoryReadRequest
/*============================================================================
 * The HistoryReadRequest structure.
 *===========================================================================*/
/** \struct OpcUa_HistoryReadRequest
 *  Asynchronously reads historical values or events of one or more nodes.
 *
 *  For constructed attribute values whose elements are indexed, such as an array,
 *  this service allows Clients to read the entire set of indexed values as a
 *  composite, to read individual elements or to read ranges of elements of the
 *  composite. Servers may make historical values available to Clients using this
 *  service, although the historical values themselves are not visible in the
 *  address space.
 *
 *  The continuationPoint parameter in the HistoryRead is used to mark a point from
 *  which to continue the read if not all values could be returned in one response.
 *  The value is opaque for the Client and is only used to maintain the state
 *  information for the Server to continue from. A Server may use the timestamp of
 *  the last returned data item if the timestamp is unique. This can reduce the
 *  need in the Server to store state information for the continuation point.
 *
 *  In some cases it may take longer than the Client timeout hint to read the data
 *  for all nodes to read. Then the Server may return zero results with a
 *  continuation point for the affected nodes before the timeout expires. That
 *  allows the Server to resume the data acquisition on the next Client read call.
 *
 *  \var OpcUa_HistoryReadRequest::HistoryReadDetails
 *  The details define the types of history reads that can be performed.
 *
 *  The HistoryReadDetails parameter type is an extensible parameter. It may
 *  contain one of the following: \ref OpcUa_ReadEventDetails, \ref
 *  OpcUa_ReadRawModifiedDetails, \ref OpcUa_ReadProcessedDetails, \ref
 *  OpcUa_ReadAtTimeDetails.
 *
 *  \var OpcUa_HistoryReadRequest::TimestampsToReturn
 *  An enumeration that specifies the timestamps to be returned for each requested
 *  variable value attribute.
 *
 *  Specifying a TimestampsToReturn of NEITHER is not valid. A Server shall return
 *  a Bad_InvalidTimestampArgument StatusCode in this case.
 *
 *  \var OpcUa_HistoryReadRequest::ReleaseContinuationPoints
 *  A Boolean parameter indicating whether to reset passed continuation points.
 *
 *  It has the following values: <dl> <dt>TRUE</dt> <dd>passed continuation points
 *  shall be reset to free resources in the Server.</dd> <dt>FALSE</dt> <dd>passed
 *  continuation points shall be used to get the next set of historical
 *  information.</dd> </dl>
 *
 *  A Client shall always use the continuation point returned by a HistoryRead
 *  response to free the resources for the continuation point in the Server. If the
 *  Client does not want to get the next set of historical information, HistoryRead
 *  shall be called with this parameter set to TRUE.
 *
 *  \var OpcUa_HistoryReadRequest::NodesToRead
 *  contains the list of items upon which the historical retrieval is to be
 *  performed.
 */
typedef struct _OpcUa_HistoryReadRequest
{
    OpcUa_RequestHeader       RequestHeader;
    OpcUa_ExtensionObject     HistoryReadDetails;
    OpcUa_TimestampsToReturn  TimestampsToReturn;
    OpcUa_Boolean             ReleaseContinuationPoints;
    OpcUa_Int32               NoOfNodesToRead;
    OpcUa_HistoryReadValueId* NodesToRead;
}
OpcUa_HistoryReadRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_HistoryReadRequest_Initialize(OpcUa_HistoryReadRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_HistoryReadRequest_Clear(OpcUa_HistoryReadRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryReadRequest_GetSize(OpcUa_HistoryReadRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryReadRequest_Encode(OpcUa_HistoryReadRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryReadRequest_Decode(OpcUa_HistoryReadRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_HistoryReadRequest_Compare(const OpcUa_HistoryReadRequest* pValue1, const OpcUa_HistoryReadRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryReadRequest_Copy(const OpcUa_HistoryReadRequest* pSource, OpcUa_HistoryReadRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryReadRequest_CopyTo(const OpcUa_HistoryReadRequest* pSource, OpcUa_HistoryReadRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_HistoryReadRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_HistoryRead */

#ifndef OPCUA_EXCLUDE_HistoryRead
#ifndef OPCUA_EXCLUDE_HistoryReadResponse
/*============================================================================
 * The HistoryReadResponse structure.
 *===========================================================================*/
/** \struct OpcUa_HistoryReadResponse
 *
 * Response to a \ref OpcUa_HistoryReadRequest.
 *
 *  \var OpcUa_HistoryReadResponse::Results
 *  List of read results.
 *
 *  The size and order of the list matches the size and order of the \ref
 *  OpcUa_HistoryReadRequest::NodesToRead request parameter.
 *
 *  \var OpcUa_HistoryReadResponse::DiagnosticInfos
 *  List of diagnostic information.
 *
 *  The size and order of the list matches the size and order of the \ref
 *  OpcUa_HistoryReadRequest::NodesToRead request parameter. There is one entry in
 *  this list for each node contained in the \ref
 *  OpcUa_HistoryReadRequest::NodesToRead parameter. This list is empty if
 *  diagnostics information was not requested in the request header or if no
 *  diagnostic information was encountered in processing of the request.
 */
typedef struct _OpcUa_HistoryReadResponse
{
    OpcUa_ResponseHeader     ResponseHeader;
    OpcUa_Int32              NoOfResults;
    OpcUa_HistoryReadResult* Results;
    OpcUa_Int32              NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo*    DiagnosticInfos;
}
OpcUa_HistoryReadResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_HistoryReadResponse_Initialize(OpcUa_HistoryReadResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_HistoryReadResponse_Clear(OpcUa_HistoryReadResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryReadResponse_GetSize(OpcUa_HistoryReadResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryReadResponse_Encode(OpcUa_HistoryReadResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryReadResponse_Decode(OpcUa_HistoryReadResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_HistoryReadResponse_Compare(const OpcUa_HistoryReadResponse* pValue1, const OpcUa_HistoryReadResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryReadResponse_Copy(const OpcUa_HistoryReadResponse* pSource, OpcUa_HistoryReadResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryReadResponse_CopyTo(const OpcUa_HistoryReadResponse* pSource, OpcUa_HistoryReadResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_HistoryReadResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_HistoryRead */

#ifndef OPCUA_EXCLUDE_WriteValue
/*============================================================================
 * The WriteValue structure.
 *===========================================================================*/
/** \struct OpcUa_WriteValue
 *  A structure that is defined as the type of the nodesToWrite parameter of the
 *  Write service.
 *
 *  \var OpcUa_WriteValue::NodeId
 *  NodeId of the node that contains the attributes.
 *
 *  \var OpcUa_WriteValue::AttributeId
 *  Id of the attribute.
 *
 *  This shall be a valid attribute id.
 *
 *  The IntegerIds for the Attributes are defined in NodeAttributesMask.
 *
 *  \var OpcUa_WriteValue::IndexRange
 *  This parameter is used to identify a single element of an array, or a single
 *  range of indexes for arrays.
 *
 *  The first element is identified by index 0 (zero).
 *
 *  This parameter is not used if the specified attribute is not an array. However,
 *  if the specified attribute is an array and this parameter is not used, then all
 *  elements are to be included in the range. The parameter is null if not used.
 *
 *  \var OpcUa_WriteValue::Value
 *  The node’s attribute value.
 *
 *  If the indexRange parameter is specified, the Value shall be an array even if
 *  only one element is being written.
 *
 *  If the SourceTimestamp or the ServerTimestamp is specified, the Server shall
 *  use these values. The Server returns a Bad_WriteNotSupported error if it does
 *  not support writing of timestamps.
 *
 *  A Server shall return a Bad_TypeMismatch error if the data type of the written
 *  value is not the same type or subtype as the attribute’s DataType. Based on the
 *  DataType hierarchy, subtypes of the attribute DataType shall be accepted by the
 *  Server. For the value attribute the DataType is defined through the DataType
 *  attribute. A ByteString is structurally the same as a one dimensional array of
 *  Byte. A Server shall accept a ByteString if an array of Byte is expected.
 *
 *  The Server returns a Bad_DataEncodingUnsupported error if it does not support
 *  writing of the passed data encoding.
 */
typedef struct _OpcUa_WriteValue
{
    OpcUa_NodeId    NodeId;
    OpcUa_UInt32    AttributeId;
    OpcUa_String    IndexRange;
    OpcUa_DataValue Value;
}
OpcUa_WriteValue;

OPCUA_EXPORT OpcUa_Void       OpcUa_WriteValue_Initialize(OpcUa_WriteValue* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_WriteValue_Clear(OpcUa_WriteValue* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_WriteValue_GetSize(OpcUa_WriteValue* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_WriteValue_Encode(OpcUa_WriteValue* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_WriteValue_Decode(OpcUa_WriteValue* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_WriteValue_Compare(const OpcUa_WriteValue* pValue1, const OpcUa_WriteValue* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_WriteValue_Copy(const OpcUa_WriteValue* pSource, OpcUa_WriteValue** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_WriteValue_CopyTo(const OpcUa_WriteValue* pSource, OpcUa_WriteValue* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_WriteValue_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_Write
#ifndef OPCUA_EXCLUDE_WriteRequest
/*============================================================================
 * The WriteRequest structure.
 *===========================================================================*/
/** \struct OpcUa_WriteRequest
 *  Asynchronously writes variable values to an OPC UA Server.
 *
 *  This service is used to write values to one or more attributes of one or more
 *  Nodes. For constructed attribute values whose elements are indexed, such as an
 *  array, this service allows Clients to write the entire set of indexed values as
 *  a composite, to write individual elements or to write ranges of elements of the
 *  composite.
 *
 *  The values are written to the data source, such as a device, and the service
 *  does not return until it writes the values or determines that the value cannot
 *  be written. In certain cases, the Server will successfully write to an
 *  intermediate system or Server, and will not know whether the data source was
 *  updated properly. In these cases, the Server should report a success code that
 *  indicates that the write was not verified. In the cases where the Server is
 *  able to verify that it has successfully written to the data source, it reports
 *  an unconditional success.
 *
 *  The order the operations are processed in the Server is not defined and depends
 *  on the different data sources and the internal Server logic. If an attribute
 *  and node combination is contained in more than one operation, the order of the
 *  processing is undefined. If a Client requires sequential processing, the Client
 *  needs separate service calls.
 *
 *  It is possible that the Server may successfully write some attributes, but not
 *  others. Rollback is the responsibility of the Client.
 *
 *  If a Server allows writing of attributes with the DataType LocalizedText, the
 *  Client can add or overwrite the text for a locale by writing the text with the
 *  associated LocaleId. Writing a null string for the text for a locale shall
 *  delete the String for that locale. Writing a null string for the locale and a
 *  non-null string for the text is setting the text for an invariant locale.
 *  Writing a null string for the text and a null string for the locale shall
 *  delete the entries for all locales. If a Client attempts to write a locale that
 *  is either syntactically invalid or not supported, the Server returns
 *  Bad_LocaleNotSupported.
 *
 *  \var OpcUa_WriteRequest::NodesToWrite
 *  List of Nodes and their Attributes to write.
 */
typedef struct _OpcUa_WriteRequest
{
    OpcUa_RequestHeader RequestHeader;
    OpcUa_Int32         NoOfNodesToWrite;
    OpcUa_WriteValue*   NodesToWrite;
}
OpcUa_WriteRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_WriteRequest_Initialize(OpcUa_WriteRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_WriteRequest_Clear(OpcUa_WriteRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_WriteRequest_GetSize(OpcUa_WriteRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_WriteRequest_Encode(OpcUa_WriteRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_WriteRequest_Decode(OpcUa_WriteRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_WriteRequest_Compare(const OpcUa_WriteRequest* pValue1, const OpcUa_WriteRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_WriteRequest_Copy(const OpcUa_WriteRequest* pSource, OpcUa_WriteRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_WriteRequest_CopyTo(const OpcUa_WriteRequest* pSource, OpcUa_WriteRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_WriteRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_Write */

#ifndef OPCUA_EXCLUDE_Write
#ifndef OPCUA_EXCLUDE_WriteResponse
/*============================================================================
 * The WriteResponse structure.
 *===========================================================================*/
/** \struct OpcUa_WriteResponse
 *
 * Response to a \ref OpcUa_WriteRequest.
 *
 *  \var OpcUa_WriteResponse::Results
 *  List of results for the nodes to write.
 *
 *  The size and order of the list matches the size and order of the \ref
 *  OpcUa_WriteRequest::NodesToWrite request parameter. There is one entry in this
 *  list for each node contained in the \ref OpcUa_WriteRequest::NodesToWrite
 *  parameter.
 *
 *  \var OpcUa_WriteResponse::NoOfDiagnosticInfos
 *  List of diagnostic information for the nodes to write.
 *
 *  The size and order of the list matches the size and order of the \ref
 *  OpcUa_WriteRequest::NodesToWrite request parameter. This list is empty if
 *  diagnostics information was not requested in the request header or if no
 *  diagnostic information was encountered in processing of the request.
 */
typedef struct _OpcUa_WriteResponse
{
    OpcUa_ResponseHeader  ResponseHeader;
    OpcUa_Int32           NoOfResults;
    OpcUa_StatusCode*     Results;
    OpcUa_Int32           NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo* DiagnosticInfos;
}
OpcUa_WriteResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_WriteResponse_Initialize(OpcUa_WriteResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_WriteResponse_Clear(OpcUa_WriteResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_WriteResponse_GetSize(OpcUa_WriteResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_WriteResponse_Encode(OpcUa_WriteResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_WriteResponse_Decode(OpcUa_WriteResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_WriteResponse_Compare(const OpcUa_WriteResponse* pValue1, const OpcUa_WriteResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_WriteResponse_Copy(const OpcUa_WriteResponse* pSource, OpcUa_WriteResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_WriteResponse_CopyTo(const OpcUa_WriteResponse* pSource, OpcUa_WriteResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_WriteResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_Write */

#ifndef OPCUA_EXCLUDE_HistoryUpdateDetails
/*============================================================================
 * The HistoryUpdateDetails structure.
 *===========================================================================*/
typedef struct _OpcUa_HistoryUpdateDetails
{
    OpcUa_NodeId NodeId;
}
OpcUa_HistoryUpdateDetails;

OPCUA_EXPORT OpcUa_Void       OpcUa_HistoryUpdateDetails_Initialize(OpcUa_HistoryUpdateDetails* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_HistoryUpdateDetails_Clear(OpcUa_HistoryUpdateDetails* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryUpdateDetails_GetSize(OpcUa_HistoryUpdateDetails* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryUpdateDetails_Encode(OpcUa_HistoryUpdateDetails* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryUpdateDetails_Decode(OpcUa_HistoryUpdateDetails* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_HistoryUpdateDetails_Compare(const OpcUa_HistoryUpdateDetails* pValue1, const OpcUa_HistoryUpdateDetails* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryUpdateDetails_Copy(const OpcUa_HistoryUpdateDetails* pSource, OpcUa_HistoryUpdateDetails** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryUpdateDetails_CopyTo(const OpcUa_HistoryUpdateDetails* pSource, OpcUa_HistoryUpdateDetails* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_HistoryUpdateDetails_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_UpdateDataDetails
/*============================================================================
 * The UpdateDataDetails structure.
 *===========================================================================*/
/** \struct OpcUa_UpdateDataDetails
 *  The details for insert, replace, and insert/replace history updates.
 *
 *  <b>Insert data functionality</b><br/> Setting performInsertReplace = INSERT_1
 *  inserts entries into the history database at the specified timestamps for one
 *  or more HistoricalDataNodes. If an entry exists at the specified timestamp, the
 *  new entry shall not be inserted; instead the StatusCode shall indicate
 *  Bad_EntryExists.
 *
 *  This function is intended to insert new entries at the specified timestamps;
 *  e.g. the insertion of lab data to reflect the time of data collection.
 *
 *  <b>Replace data functionality</b><br/> Setting performInsertReplace = REPLACE_2
 *  replaces entries in the history database at the specified timestamps for one or
 *  more HistoricalDataNodes. If no entry exists at the specified timestamp, the
 *  new entry shall not be inserted; otherwise the StatusCode shall indicate
 *  Bad_NoEntryExists.
 *
 *  This function is intended to replace existing entries at the specified
 *  timestamp; e.g., correct lab data that was improperly processed, but inserted
 *  into the history database.
 *
 *  <b>Update data functionality</b><br/> Setting performInsertReplace = UPDATE_3
 *  inserts or replaces entries in the history database for the specified
 *  timestamps for one or more HistoricalDataNodes. If the item has an entry at the
 *  specified timestamp, the new entry will replace the old one. If there is no
 *  entry at that timestamp, the function will insert the new data.
 *
 *  A Server can create a modified value for a value being replaced or inserted,
 *  however it is not required.
 *
 *  This function is intended to unconditionally insert/replace values and
 *  qualities; e.g., correction of values for bad sensors.
 *
 *  Good as a StatusCode for an individual entry is allowed when the server is
 *  unable to say whether there was already a value at that timestamp. If the
 *  server can determine whether the new entry replaces an entry that was already
 *  there, it should use Good_EntryInserted or Good_EntryReplaced to return that
 *  information.
 *
 *  \var OpcUa_UpdateDataDetails::NodeId
 *  Node ID of the object to be updated.
 *
 *  \var OpcUa_UpdateDataDetails::PerformInsertReplace
 *  Determines which action of insert, replace, or update is performed.
 *
 *  Possible values are INSERT_1, REPLACE_2, or UPDATE_3, see \ref
 *  OpcUa_UpdateDataDetails
 *
 *  \var OpcUa_UpdateDataDetails::UpdateValues
 *  New values to be inserted or to replace.
 */
typedef struct _OpcUa_UpdateDataDetails
{
    OpcUa_NodeId            NodeId;
    OpcUa_PerformUpdateType PerformInsertReplace;
    OpcUa_Int32             NoOfUpdateValues;
    OpcUa_DataValue*        UpdateValues;
}
OpcUa_UpdateDataDetails;

OPCUA_EXPORT OpcUa_Void       OpcUa_UpdateDataDetails_Initialize(OpcUa_UpdateDataDetails* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_UpdateDataDetails_Clear(OpcUa_UpdateDataDetails* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UpdateDataDetails_GetSize(OpcUa_UpdateDataDetails* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UpdateDataDetails_Encode(OpcUa_UpdateDataDetails* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UpdateDataDetails_Decode(OpcUa_UpdateDataDetails* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_UpdateDataDetails_Compare(const OpcUa_UpdateDataDetails* pValue1, const OpcUa_UpdateDataDetails* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_UpdateDataDetails_Copy(const OpcUa_UpdateDataDetails* pSource, OpcUa_UpdateDataDetails** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UpdateDataDetails_CopyTo(const OpcUa_UpdateDataDetails* pSource, OpcUa_UpdateDataDetails* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_UpdateDataDetails_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_UpdateStructureDataDetails
/*============================================================================
 * The UpdateStructureDataDetails structure.
 *===========================================================================*/
/** \struct OpcUa_UpdateStructureDataDetails
 *  This function inserts, replaces or removes structured history data or
 *  annotations into the history database at the specified timestamps for one or
 *  more HistoricalDataNodes.
 *
 *  Structured history data provides metadata describing an entry in the history
 *  database. The server shall define what uniqueness means for each structured
 *  history data structure type. For example, a server may only allow one
 *  annotation per timestamp, which means the timestamp is the unique key for the
 *  structure. Another server may allow for multiple annotations to exist per user,
 *  so a combination of a username, timestamp, and message may be used as the
 *  unique key for the structure. In the following sections the terms “Structured
 *  Histroy Data exists” and “at the specificed parameters” means a matching entry
 *  has been found at the specified timestamp using the Server’s criteria for
 *  uniqueness.
 *
 *  In the case where the Client wishes to replace a parameter that is part of the
 *  uniqueness criteria, the resulting StatusCode would be Bad_NoEntryExists. The
 *  Client must remove the existing structure and then insert the new structure.
 *
 *  <b>Insert functionality</b><br/> Setting performInsertReplace = INSERT_1
 *  inserts structured history data, such as annotations, into the history database
 *  at the specified parameters for one or more properties of HistoricalDataNodes.
 *
 *  If a structured history data entry already exists at the specified parameters,
 *  the StatusCode shall indicate Bad_EntryExists.
 *
 *  <b>Replace functionality</b><br/> Setting performInsertReplace = REPLACE_2
 *  replaces structured history data such as annotations in the history database at
 *  the specified parameters for one or more properties of HistoricalDataNodes.
 *
 *  If a structured history data entry does not already exist at the specified
 *  parameters, the StatusCode shall indicate Bad_NoEntryExists.
 *
 *  <b>Update functionality</b><br/> Setting performInsertReplace = UPDATE_3
 *  inserts or replaces structured history data such as annotations in the history
 *  database at the specified parameters for one or more properties of
 *  HistoricalDataNodes.
 *
 *  If a structure history data entry already exists at the specified paramters, it
 *  is deleted and the value provided by the Client is inserted. If no existing
 *  entry exists, the new entry is inserted.
 *
 *  If an existing entry was replaced successfully, the StatusCode shall be
 *  Good_EntryReplaced. If a new entry was created, the StatusCode shall be
 *  Good_EntryInserted. If the server cannot determine whether it replaced or
 *  inserted an entry, the StatusCode shall be Good.
 *
 *  <b>Remove functionality</b><br/> Setting performInsertReplace = REMOVE_4
 *  removes structured history data such as annotations from the history database
 *  at the specified parameters for one or more properties of HistoricalDataNodes.
 *
 *  If a structure history data entry exists at the specified parameters, it is
 *  deleted. If structured history data does not already exist at the specified
 *  parameters, the StatusCode shall indicate Bad_NoEntryExists.
 *
 *  \var OpcUa_UpdateStructureDataDetails::NodeId
 *  NodeId of the object to be updated.
 *
 *  \var OpcUa_UpdateStructureDataDetails::PerformInsertReplace
 *  Determines which action of insert, replace, update, or remove is performed.
 *
 *  Possible values are INSERT_1, REPLACE_2, UPDATE_3, or REMOVE_4.
 *
 *  \var OpcUa_UpdateStructureDataDetails::UpdateValues
 *  New values to be inserted, replaced, or removed.
 */
typedef struct _OpcUa_UpdateStructureDataDetails
{
    OpcUa_NodeId            NodeId;
    OpcUa_PerformUpdateType PerformInsertReplace;
    OpcUa_Int32             NoOfUpdateValues;
    OpcUa_DataValue*        UpdateValues;
}
OpcUa_UpdateStructureDataDetails;

OPCUA_EXPORT OpcUa_Void       OpcUa_UpdateStructureDataDetails_Initialize(OpcUa_UpdateStructureDataDetails* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_UpdateStructureDataDetails_Clear(OpcUa_UpdateStructureDataDetails* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UpdateStructureDataDetails_GetSize(OpcUa_UpdateStructureDataDetails* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UpdateStructureDataDetails_Encode(OpcUa_UpdateStructureDataDetails* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UpdateStructureDataDetails_Decode(OpcUa_UpdateStructureDataDetails* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_UpdateStructureDataDetails_Compare(const OpcUa_UpdateStructureDataDetails* pValue1, const OpcUa_UpdateStructureDataDetails* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_UpdateStructureDataDetails_Copy(const OpcUa_UpdateStructureDataDetails* pSource, OpcUa_UpdateStructureDataDetails** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UpdateStructureDataDetails_CopyTo(const OpcUa_UpdateStructureDataDetails* pSource, OpcUa_UpdateStructureDataDetails* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_UpdateStructureDataDetails_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_DeleteRawModifiedDetails
/*============================================================================
 * The DeleteRawModifiedDetails structure.
 *===========================================================================*/
/** \struct OpcUa_DeleteRawModifiedDetails
 *  The details for delete raw and delete modified history updates.
 *
 *  These functions are intended to be used to delete data that has been
 *  accidentally entered into the history database, e.g. deletion of data from a
 *  source with incorrect timestamps. Both startTime and endTime must be defined.
 *  The startTime must be less than the endTime, and values up to but not including
 *  the endTime are deleted. It is permissible for startTime = endTime, in which
 *  case the value at the startTime is deleted.
 *
 *  <b>Delete raw functionality</b><br/> Setting isDeleteModified = FALSE deletes
 *  all raw entries from the history database for the specified time domain for one
 *  more HistoricalDataNodes.
 *
 *  If no data is found in the time range for a particular HistoricalDataNode, the
 *  StatusCode for that item is Bad_NoData.
 *
 *  <b>Delete modified functionality</b><br/> Setting isDeleteModified = TRUE
 *  deletes all modified entries from the history database for the specified time
 *  domain for one or more HistoricalDataNodes. If no data is found in the time
 *  range for a particular HistoricalDataNode, the StatusCode for that item is
 *  Bad_NoData.
 *
 *  \var OpcUa_DeleteRawModifiedDetails::NodeId
 *  NodeId of the object for which history values are to be deleted.
 *
 *  \var OpcUa_DeleteRawModifiedDetails::IsDeleteModified
 *  TRUE for MODIFIED, FALSE for RAW.
 *
 *  Default value is FALSE.
 *
 *  \var OpcUa_DeleteRawModifiedDetails::StartTime
 *  The beginning of the period to be deleted.
 *
 *  \var OpcUa_DeleteRawModifiedDetails::EndTime
 *  The end of the period to be deleted.
 */
typedef struct _OpcUa_DeleteRawModifiedDetails
{
    OpcUa_NodeId   NodeId;
    OpcUa_Boolean  IsDeleteModified;
    OpcUa_DateTime StartTime;
    OpcUa_DateTime EndTime;
}
OpcUa_DeleteRawModifiedDetails;

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteRawModifiedDetails_Initialize(OpcUa_DeleteRawModifiedDetails* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteRawModifiedDetails_Clear(OpcUa_DeleteRawModifiedDetails* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteRawModifiedDetails_GetSize(OpcUa_DeleteRawModifiedDetails* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteRawModifiedDetails_Encode(OpcUa_DeleteRawModifiedDetails* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteRawModifiedDetails_Decode(OpcUa_DeleteRawModifiedDetails* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_DeleteRawModifiedDetails_Compare(const OpcUa_DeleteRawModifiedDetails* pValue1, const OpcUa_DeleteRawModifiedDetails* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteRawModifiedDetails_Copy(const OpcUa_DeleteRawModifiedDetails* pSource, OpcUa_DeleteRawModifiedDetails** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteRawModifiedDetails_CopyTo(const OpcUa_DeleteRawModifiedDetails* pSource, OpcUa_DeleteRawModifiedDetails* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_DeleteRawModifiedDetails_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_DeleteAtTimeDetails
/*============================================================================
 * The DeleteAtTimeDetails structure.
 *===========================================================================*/
/** \struct OpcUa_DeleteAtTimeDetails
 *  The DeleteAtTime structure deletes all entries in the history database for the
 *  specified timestamps for one or more HistoricalDataNodes.
 *
 *  This parameter is intended to be used to delete specific data from the history
 *  database, e.g. lab data that is incorrect and cannot be correctly reproduced.
 *
 *  \var OpcUa_DeleteAtTimeDetails::NodeId
 *  NodeId of the object for which history values are to be deleted.
 *
 *  \var OpcUa_DeleteAtTimeDetails::ReqTimes
 *  The entries define the specific timestamps for which values are to be deleted.
 */
typedef struct _OpcUa_DeleteAtTimeDetails
{
    OpcUa_NodeId    NodeId;
    OpcUa_Int32     NoOfReqTimes;
    OpcUa_DateTime* ReqTimes;
}
OpcUa_DeleteAtTimeDetails;

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteAtTimeDetails_Initialize(OpcUa_DeleteAtTimeDetails* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteAtTimeDetails_Clear(OpcUa_DeleteAtTimeDetails* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteAtTimeDetails_GetSize(OpcUa_DeleteAtTimeDetails* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteAtTimeDetails_Encode(OpcUa_DeleteAtTimeDetails* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteAtTimeDetails_Decode(OpcUa_DeleteAtTimeDetails* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_DeleteAtTimeDetails_Compare(const OpcUa_DeleteAtTimeDetails* pValue1, const OpcUa_DeleteAtTimeDetails* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteAtTimeDetails_Copy(const OpcUa_DeleteAtTimeDetails* pSource, OpcUa_DeleteAtTimeDetails** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteAtTimeDetails_CopyTo(const OpcUa_DeleteAtTimeDetails* pSource, OpcUa_DeleteAtTimeDetails* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_DeleteAtTimeDetails_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_DeleteEventDetails
/*============================================================================
 * The DeleteEventDetails structure.
 *===========================================================================*/
/** \struct OpcUa_DeleteEventDetails
 *  Deletes all event entries from the history database matching the EventId for
 *  one or more HistoricalEventNodes.
 *
 *  If no events are found that match the specified filter for a
 *  HistoricalEventNode, the StatusCode for that Node is Bad_NoData.
 *
 *  \var OpcUa_DeleteEventDetails::NodeId
 *  NodeId of the object for which history values are to be deleted.
 *
 *  \var OpcUa_DeleteEventDetails::EventIds
 *  An array of EventIds to identify which events are to be deleted.
 */
typedef struct _OpcUa_DeleteEventDetails
{
    OpcUa_NodeId      NodeId;
    OpcUa_Int32       NoOfEventIds;
    OpcUa_ByteString* EventIds;
}
OpcUa_DeleteEventDetails;

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteEventDetails_Initialize(OpcUa_DeleteEventDetails* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteEventDetails_Clear(OpcUa_DeleteEventDetails* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteEventDetails_GetSize(OpcUa_DeleteEventDetails* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteEventDetails_Encode(OpcUa_DeleteEventDetails* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteEventDetails_Decode(OpcUa_DeleteEventDetails* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_DeleteEventDetails_Compare(const OpcUa_DeleteEventDetails* pValue1, const OpcUa_DeleteEventDetails* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteEventDetails_Copy(const OpcUa_DeleteEventDetails* pSource, OpcUa_DeleteEventDetails** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteEventDetails_CopyTo(const OpcUa_DeleteEventDetails* pSource, OpcUa_DeleteEventDetails* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_DeleteEventDetails_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_HistoryUpdateResult
/*============================================================================
 * The HistoryUpdateResult structure.
 *===========================================================================*/
/** \struct OpcUa_HistoryUpdateResult
 *  A structure that is defined as the type of the results parameter of the
 *  HistoryUpdate Service.
 *
 *  The size and order of the list matches the size and order of the details
 *  element of the historyUpdateDetails parameter specified in the request.
 *
 *  \var OpcUa_HistoryUpdateResult::StatusCode
 *  StatusCode for the update of the node.
 *
 *  \var OpcUa_HistoryUpdateResult::OperationResults
 *  List of StatusCodes for the operations to be performed on a node.
 *
 *  The size and order of the list matches the size and order of any list defined
 *  by the details element being reported by this updateResults entry.
 *
 *  \var OpcUa_HistoryUpdateResult::DiagnosticInfos
 *  List of diagnostic information for the operations to be performed on a node.
 *
 *  The size and order of the list matches the size and order of any list defined
 *  by the details element being reported by this updateResults entry. This list is
 *  empty if diagnostics information was not requested in the request header or if
 *  no diagnostic information was encountered in processing of the request.
 */
typedef struct _OpcUa_HistoryUpdateResult
{
    OpcUa_StatusCode      StatusCode;
    OpcUa_Int32           NoOfOperationResults;
    OpcUa_StatusCode*     OperationResults;
    OpcUa_Int32           NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo* DiagnosticInfos;
}
OpcUa_HistoryUpdateResult;

OPCUA_EXPORT OpcUa_Void       OpcUa_HistoryUpdateResult_Initialize(OpcUa_HistoryUpdateResult* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_HistoryUpdateResult_Clear(OpcUa_HistoryUpdateResult* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryUpdateResult_GetSize(OpcUa_HistoryUpdateResult* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryUpdateResult_Encode(OpcUa_HistoryUpdateResult* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryUpdateResult_Decode(OpcUa_HistoryUpdateResult* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_HistoryUpdateResult_Compare(const OpcUa_HistoryUpdateResult* pValue1, const OpcUa_HistoryUpdateResult* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryUpdateResult_Copy(const OpcUa_HistoryUpdateResult* pSource, OpcUa_HistoryUpdateResult** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryUpdateResult_CopyTo(const OpcUa_HistoryUpdateResult* pSource, OpcUa_HistoryUpdateResult* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_HistoryUpdateResult_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_HistoryUpdate
#ifndef OPCUA_EXCLUDE_HistoryUpdateRequest
/*============================================================================
 * The HistoryUpdateRequest structure.
 *===========================================================================*/
/** \struct OpcUa_HistoryUpdateRequest
 *  Asynchronously updates historical values or events of one or more nodes.
 *
 *  \var OpcUa_HistoryUpdateRequest::HistoryUpdateDetails
 *  Specifies the types of history updates that can be performed.
 *
 *  The HistoryUpdateDetails is an extensible parameter. It may contain one of the
 *  following: \ref OpcUa_UpdateDataDetails, \ref OpcUa_UpdateStructureDataDetails
 *  , \ref OpcUa_UpdateEventDetails, \ref OpcUa_DeleteRawModifiedDetails, \ref
 *  OpcUa_DeleteAtTimeDetails, \ref OpcUa_DeleteEventDetails.
 */
typedef struct _OpcUa_HistoryUpdateRequest
{
    OpcUa_RequestHeader    RequestHeader;
    OpcUa_Int32            NoOfHistoryUpdateDetails;
    OpcUa_ExtensionObject* HistoryUpdateDetails;
}
OpcUa_HistoryUpdateRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_HistoryUpdateRequest_Initialize(OpcUa_HistoryUpdateRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_HistoryUpdateRequest_Clear(OpcUa_HistoryUpdateRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryUpdateRequest_GetSize(OpcUa_HistoryUpdateRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryUpdateRequest_Encode(OpcUa_HistoryUpdateRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryUpdateRequest_Decode(OpcUa_HistoryUpdateRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_HistoryUpdateRequest_Compare(const OpcUa_HistoryUpdateRequest* pValue1, const OpcUa_HistoryUpdateRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryUpdateRequest_Copy(const OpcUa_HistoryUpdateRequest* pSource, OpcUa_HistoryUpdateRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryUpdateRequest_CopyTo(const OpcUa_HistoryUpdateRequest* pSource, OpcUa_HistoryUpdateRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_HistoryUpdateRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_HistoryUpdate */

#ifndef OPCUA_EXCLUDE_HistoryUpdate
#ifndef OPCUA_EXCLUDE_HistoryUpdateResponse
/*============================================================================
 * The HistoryUpdateResponse structure.
 *===========================================================================*/
/** \struct OpcUa_HistoryUpdateResponse
 *
 * Response to a \ref OpcUa_HistoryUpdateRequest.
 *
 *  \var OpcUa_HistoryUpdateResponse::Results
 *  List of update results for the history update details.
 *
 *  The size and order of the list matches the size and order of the details
 *  element of the historyUpdateDetails parameter specified in the request.
 *
 *  \var OpcUa_HistoryUpdateResponse::DiagnosticInfos
 *  List of diagnostic information for the history update details.
 *
 *  The size and order of the list matches the size and order of the details
 *  element of the historyUpdateDetails parameter specified in the request. This
 *  list is empty if diagnostics information was not requested in the request
 *  header or if no diagnostic information was encountered in processing of the
 *  request.
 */
typedef struct _OpcUa_HistoryUpdateResponse
{
    OpcUa_ResponseHeader       ResponseHeader;
    OpcUa_Int32                NoOfResults;
    OpcUa_HistoryUpdateResult* Results;
    OpcUa_Int32                NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo*      DiagnosticInfos;
}
OpcUa_HistoryUpdateResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_HistoryUpdateResponse_Initialize(OpcUa_HistoryUpdateResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_HistoryUpdateResponse_Clear(OpcUa_HistoryUpdateResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryUpdateResponse_GetSize(OpcUa_HistoryUpdateResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryUpdateResponse_Encode(OpcUa_HistoryUpdateResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryUpdateResponse_Decode(OpcUa_HistoryUpdateResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_HistoryUpdateResponse_Compare(const OpcUa_HistoryUpdateResponse* pValue1, const OpcUa_HistoryUpdateResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryUpdateResponse_Copy(const OpcUa_HistoryUpdateResponse* pSource, OpcUa_HistoryUpdateResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryUpdateResponse_CopyTo(const OpcUa_HistoryUpdateResponse* pSource, OpcUa_HistoryUpdateResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_HistoryUpdateResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_HistoryUpdate */

#ifndef OPCUA_EXCLUDE_CallMethod
#ifndef OPCUA_EXCLUDE_CallMethodRequest
/*============================================================================
 * The CallMethodRequest structure.
 *===========================================================================*/
/** \struct OpcUa_CallMethodRequest
 *  A structure that is defined as the type of the methodsToCall parameter of the
 *  Call service.
 *
 *  \var OpcUa_CallMethodRequest::ObjectId
 *  The NodeId shall be that of the object or ObjectType that is the source of a
 *  HasComponent Reference (or subtype of HasComponent Reference) to the method
 *  specified in methodId.
 *
 *  See Part 3 of the OPC UA Specification for a description of objects and their
 *  methods.
 *
 *  \var OpcUa_CallMethodRequest::MethodId
 *  NodeId of the method to invoke.
 *
 *  If the objectId is the NodeId of an object, it is allowed to use the NodeId of
 *  a method that is the target of a HasComponent Reference from the ObjectType of
 *  the object.
 *
 *  \var OpcUa_CallMethodRequest::InputArguments
 *  List of input argument values.
 *
 *  An empty list indicates that there are no input arguments. The size and order
 *  of this list matches the size and order of the input arguments defined by the
 *  input InputArguments Property of the method.
 *
 *  The name, a description and the data type of each argument are defined by the
 *  Argument structure in each element of the method’s InputArguments Property.
 */
typedef struct _OpcUa_CallMethodRequest
{
    OpcUa_NodeId   ObjectId;
    OpcUa_NodeId   MethodId;
    OpcUa_Int32    NoOfInputArguments;
    OpcUa_Variant* InputArguments;
}
OpcUa_CallMethodRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_CallMethodRequest_Initialize(OpcUa_CallMethodRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_CallMethodRequest_Clear(OpcUa_CallMethodRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CallMethodRequest_GetSize(OpcUa_CallMethodRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CallMethodRequest_Encode(OpcUa_CallMethodRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CallMethodRequest_Decode(OpcUa_CallMethodRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_CallMethodRequest_Compare(const OpcUa_CallMethodRequest* pValue1, const OpcUa_CallMethodRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_CallMethodRequest_Copy(const OpcUa_CallMethodRequest* pSource, OpcUa_CallMethodRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CallMethodRequest_CopyTo(const OpcUa_CallMethodRequest* pSource, OpcUa_CallMethodRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_CallMethodRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_CallMethod */

#ifndef OPCUA_EXCLUDE_CallMethodResult
/*============================================================================
 * The CallMethodResult structure.
 *===========================================================================*/
/** \struct OpcUa_CallMethodResult
 *  A structure that is defined as the type of the results parameter of the Call
 *  service.
 *
 *  \var OpcUa_CallMethodResult::StatusCode
 *  StatusCode of the method executed in the server.
 *
 *  This StatusCode is set to the Bad_InvalidArgument StatusCode if at least one
 *  input argument broke a constraint (e.g. wrong data type, value out of range).
 *
 *  This StatusCode is set to a bad StatusCode if the method execution failed in
 *  the server, e.g. based on an exception or an HRESULT.
 *
 *  \var OpcUa_CallMethodResult::InputArgumentResults
 *  List of StatusCodes for each inputArgument.
 *
 *  \var OpcUa_CallMethodResult::InputArgumentDiagnosticInfos
 *  List of diagnostic information for each inputArgument.
 *
 *  This list is empty if diagnostics information was not requested in the request
 *  header or if no diagnostic information was encountered in processing of the
 *  request.
 *
 *  \var OpcUa_CallMethodResult::OutputArguments
 *  List of output argument values.
 *
 *  An empty list indicates that there are no output arguments. The size and order
 *  of this list matches the size and order of the output arguments defined by the
 *  OutputArguments Property of the method.
 *
 *  The name, a description and the data type of each argument are defined by the
 *  Argument structure in each element of the methods OutputArguments Property.
 */
typedef struct _OpcUa_CallMethodResult
{
    OpcUa_StatusCode      StatusCode;
    OpcUa_Int32           NoOfInputArgumentResults;
    OpcUa_StatusCode*     InputArgumentResults;
    OpcUa_Int32           NoOfInputArgumentDiagnosticInfos;
    OpcUa_DiagnosticInfo* InputArgumentDiagnosticInfos;
    OpcUa_Int32           NoOfOutputArguments;
    OpcUa_Variant*        OutputArguments;
}
OpcUa_CallMethodResult;

OPCUA_EXPORT OpcUa_Void       OpcUa_CallMethodResult_Initialize(OpcUa_CallMethodResult* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_CallMethodResult_Clear(OpcUa_CallMethodResult* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CallMethodResult_GetSize(OpcUa_CallMethodResult* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CallMethodResult_Encode(OpcUa_CallMethodResult* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CallMethodResult_Decode(OpcUa_CallMethodResult* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_CallMethodResult_Compare(const OpcUa_CallMethodResult* pValue1, const OpcUa_CallMethodResult* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_CallMethodResult_Copy(const OpcUa_CallMethodResult* pSource, OpcUa_CallMethodResult** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CallMethodResult_CopyTo(const OpcUa_CallMethodResult* pSource, OpcUa_CallMethodResult* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_CallMethodResult_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_Call
#ifndef OPCUA_EXCLUDE_CallRequest
/*============================================================================
 * The CallRequest structure.
 *===========================================================================*/
/** \struct OpcUa_CallRequest
 *  Asynchronously calls a method provided by an object on the OPC UA server.
 *
 *  \var OpcUa_CallRequest::MethodsToCall
 *  List of methods to call.
 */
typedef struct _OpcUa_CallRequest
{
    OpcUa_RequestHeader      RequestHeader;
    OpcUa_Int32              NoOfMethodsToCall;
    OpcUa_CallMethodRequest* MethodsToCall;
}
OpcUa_CallRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_CallRequest_Initialize(OpcUa_CallRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_CallRequest_Clear(OpcUa_CallRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CallRequest_GetSize(OpcUa_CallRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CallRequest_Encode(OpcUa_CallRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CallRequest_Decode(OpcUa_CallRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_CallRequest_Compare(const OpcUa_CallRequest* pValue1, const OpcUa_CallRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_CallRequest_Copy(const OpcUa_CallRequest* pSource, OpcUa_CallRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CallRequest_CopyTo(const OpcUa_CallRequest* pSource, OpcUa_CallRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_CallRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_Call */

#ifndef OPCUA_EXCLUDE_Call
#ifndef OPCUA_EXCLUDE_CallResponse
/*============================================================================
 * The CallResponse structure.
 *===========================================================================*/
/** \struct OpcUa_CallResponse
 *
 * Response to a \ref OpcUa_CallRequest.
 *
 *  \var OpcUa_CallResponse::Results
 *  Result for the method calls.
 *
 *  \var OpcUa_CallResponse::DiagnosticInfos
 *  List of diagnostic information for the StatusCode of the callResult.
 *
 *  This list is empty if diagnostics information was not requested in the request
 *  header or if no diagnostic information was encountered in processing of the
 *  request.
 */
typedef struct _OpcUa_CallResponse
{
    OpcUa_ResponseHeader    ResponseHeader;
    OpcUa_Int32             NoOfResults;
    OpcUa_CallMethodResult* Results;
    OpcUa_Int32             NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo*   DiagnosticInfos;
}
OpcUa_CallResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_CallResponse_Initialize(OpcUa_CallResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_CallResponse_Clear(OpcUa_CallResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CallResponse_GetSize(OpcUa_CallResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CallResponse_Encode(OpcUa_CallResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CallResponse_Decode(OpcUa_CallResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_CallResponse_Compare(const OpcUa_CallResponse* pValue1, const OpcUa_CallResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_CallResponse_Copy(const OpcUa_CallResponse* pSource, OpcUa_CallResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CallResponse_CopyTo(const OpcUa_CallResponse* pSource, OpcUa_CallResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_CallResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_Call */

#ifndef OPCUA_EXCLUDE_DataChangeFilter
/*============================================================================
 * The DataChangeFilter structure.
 *===========================================================================*/
typedef struct _OpcUa_DataChangeFilter
{
    OpcUa_DataChangeTrigger Trigger;
    OpcUa_UInt32            DeadbandType;
    OpcUa_Double            DeadbandValue;
}
OpcUa_DataChangeFilter;

OPCUA_EXPORT OpcUa_Void       OpcUa_DataChangeFilter_Initialize(OpcUa_DataChangeFilter* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_DataChangeFilter_Clear(OpcUa_DataChangeFilter* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DataChangeFilter_GetSize(OpcUa_DataChangeFilter* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DataChangeFilter_Encode(OpcUa_DataChangeFilter* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DataChangeFilter_Decode(OpcUa_DataChangeFilter* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_DataChangeFilter_Compare(const OpcUa_DataChangeFilter* pValue1, const OpcUa_DataChangeFilter* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_DataChangeFilter_Copy(const OpcUa_DataChangeFilter* pSource, OpcUa_DataChangeFilter** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DataChangeFilter_CopyTo(const OpcUa_DataChangeFilter* pSource, OpcUa_DataChangeFilter* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_DataChangeFilter_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_EventFilter
/*============================================================================
 * The EventFilter structure.
 *===========================================================================*/
/** \struct OpcUa_EventFilter
 *  Provides for the filtering and content selection of Event Subscriptions.
 *
 *  \var OpcUa_EventFilter::SelectClauses
 *  List of the values to return with each event in a notification.
 *
 *  At least one valid clause shall be specified.
 *
 *  \var OpcUa_EventFilter::WhereClause
 *  Limit the Notifications to those events that match the criteria defined by this
 *  \ref OpcUa_ContentFilter.
 *
 *  The \ref OpcUa_AttributeOperand structure may not be used in an EventFilter.
 */
typedef struct _OpcUa_EventFilter
{
    OpcUa_Int32                   NoOfSelectClauses;
    OpcUa_SimpleAttributeOperand* SelectClauses;
    OpcUa_ContentFilter           WhereClause;
}
OpcUa_EventFilter;

OPCUA_EXPORT OpcUa_Void       OpcUa_EventFilter_Initialize(OpcUa_EventFilter* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_EventFilter_Clear(OpcUa_EventFilter* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EventFilter_GetSize(OpcUa_EventFilter* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EventFilter_Encode(OpcUa_EventFilter* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EventFilter_Decode(OpcUa_EventFilter* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_EventFilter_Compare(const OpcUa_EventFilter* pValue1, const OpcUa_EventFilter* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_EventFilter_Copy(const OpcUa_EventFilter* pSource, OpcUa_EventFilter** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EventFilter_CopyTo(const OpcUa_EventFilter* pSource, OpcUa_EventFilter* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_EventFilter_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_AggregateConfiguration
/*============================================================================
 * The AggregateConfiguration structure.
 *===========================================================================*/
/** \struct OpcUa_AggregateConfiguration
 *  A structure that is defined as the type of the aggregateConfiguration parameter
 *  of the AggregateFilter structure.
 *
 *  \var OpcUa_AggregateConfiguration::UseServerCapabilitiesDefaults
 *  A Boolean parameter indicating whether to use default aggregate configuration
 *  settings.
 *
 *  <dl><dt>TRUE</dt><dd>use aggregate configuration settings as outlined by the
 *  AggregateConfiguration object.</dd><dt>FALSE</dt><dd>use configuration settings
 *  as outlined in the following aggregate configuration parameters.</dd></dl>
 *
 *  \var OpcUa_AggregateConfiguration::TreatUncertainAsBad
 *  Indicates how the server treats data returned with a StatusCode severity
 *  Uncertain with respect to Aggregate calculations.
 *
 *  It has the following values: <dl> <dt>True</dt><dd>the server considers the
 *  severity equivalent to Bad,</dd> <dt>False</dt><dd>indicates the server
 *  considers the severity equivalent to Good, unless the aggregate definition says
 *  otherwise.</dd> </dl>A value of True indicates the server
 *
 *  The default value is True. Note that the value is still treated as Uncertain
 *  when the StatusCode for the result is calculated.
 *
 *  \var OpcUa_AggregateConfiguration::PercentDataBad
 *  Indicates the minimum percentage of bad data in a given interval required for
 *  the StatusCode for the given interval for processed data request to be set to
 *  Bad.
 *
 *  Uncertain is treated as defined in \ref
 *  OpcUa_AggregateConfiguration::TreatUncertainAsBad. For details on which
 *  Aggregates use the PercentDataBad Variable, see the definition of each
 *  Aggregate. The default value is 100.
 *
 *  The PercentDataGood and PercentDataBad must follow the following
 *  relationship<br/>PercentDataGood \>= (100 – PercentDataBad).<br/>If they are
 *  equal, the result of the PercentDataGood calculation is used.
 *
 *  \var OpcUa_AggregateConfiguration::PercentDataGood
 *  Indicates the minimum percentage of Good data in a given interval required for
 *  the StatusCode for the given interval for the processed data requests to be set
 *  to Good.
 *
 *  For details on which Aggregates use the PercentDataGood Variable, see the
 *  definition of each Aggregate. The default value is 100.
 *
 *  The PercentDataGood and PercentDataBad must follow the following
 *  relationship<br/>PercentDataGood \>= (100 – PercentDataBad).<br/>If they are
 *  equal, the result of the PercentDataGood calculation is used.
 *
 *  \var OpcUa_AggregateConfiguration::UseSlopedExtrapolation
 *  Indicates how the server interpolates data when no boundary value exists (i.e.
 *  extrapolating into the future from the last known value).
 *
 *  <dl> <dt>False</dt><dd>the server will use a SteppedExtrapolation format and
 *  hold the last known value constant.</dd> <dt>True</dt><dd>the server will
 *  project the value using UseSlopedExtrapolation mode.</dd> </dl>
 *
 *  The default value is False. For SimpleBounds this value is ignored.
 */
typedef struct _OpcUa_AggregateConfiguration
{
    OpcUa_Boolean UseServerCapabilitiesDefaults;
    OpcUa_Boolean TreatUncertainAsBad;
    OpcUa_Byte    PercentDataBad;
    OpcUa_Byte    PercentDataGood;
    OpcUa_Boolean UseSlopedExtrapolation;
}
OpcUa_AggregateConfiguration;

OPCUA_EXPORT OpcUa_Void       OpcUa_AggregateConfiguration_Initialize(OpcUa_AggregateConfiguration* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_AggregateConfiguration_Clear(OpcUa_AggregateConfiguration* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AggregateConfiguration_GetSize(OpcUa_AggregateConfiguration* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AggregateConfiguration_Encode(OpcUa_AggregateConfiguration* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AggregateConfiguration_Decode(OpcUa_AggregateConfiguration* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_AggregateConfiguration_Compare(const OpcUa_AggregateConfiguration* pValue1, const OpcUa_AggregateConfiguration* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_AggregateConfiguration_Copy(const OpcUa_AggregateConfiguration* pSource, OpcUa_AggregateConfiguration** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AggregateConfiguration_CopyTo(const OpcUa_AggregateConfiguration* pSource, OpcUa_AggregateConfiguration* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_AggregateConfiguration_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_AggregateFilter
/*============================================================================
 * The AggregateFilter structure.
 *===========================================================================*/
typedef struct _OpcUa_AggregateFilter
{
    OpcUa_DateTime               StartTime;
    OpcUa_NodeId                 AggregateType;
    OpcUa_Double                 ProcessingInterval;
    OpcUa_AggregateConfiguration AggregateConfiguration;
}
OpcUa_AggregateFilter;

OPCUA_EXPORT OpcUa_Void       OpcUa_AggregateFilter_Initialize(OpcUa_AggregateFilter* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_AggregateFilter_Clear(OpcUa_AggregateFilter* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AggregateFilter_GetSize(OpcUa_AggregateFilter* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AggregateFilter_Encode(OpcUa_AggregateFilter* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AggregateFilter_Decode(OpcUa_AggregateFilter* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_AggregateFilter_Compare(const OpcUa_AggregateFilter* pValue1, const OpcUa_AggregateFilter* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_AggregateFilter_Copy(const OpcUa_AggregateFilter* pSource, OpcUa_AggregateFilter** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AggregateFilter_CopyTo(const OpcUa_AggregateFilter* pSource, OpcUa_AggregateFilter* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_AggregateFilter_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_EventFilterResult
/*============================================================================
 * The EventFilterResult structure.
 *===========================================================================*/
/** \struct OpcUa_EventFilterResult
 *  This is the MonitoringFilterResult associated with the EventFilter
 *  MonitoringFilter.
 *
 *  \var OpcUa_EventFilterResult::SelectClauseResults
 *  List of status codes for the elements in the select clause.
 *
 *  The size and order of the list matches the size and order of the elements in
 *  the selectClauses request parameter. The Server returns null for unavailable or
 *  rejected Event fields.
 *
 *  \var OpcUa_EventFilterResult::SelectClauseDiagnosticInfos
 *  A list of diagnostic information for individual elements in the select clause.
 *
 *  The size and order of the list matches the size and order of the elements in
 *  the selectClauses request parameter. This list is empty if diagnostics
 *  information was not requested in the request header or if no diagnostic
 *  information was encountered in processing of the select clauses.
 *
 *  \var OpcUa_EventFilterResult::WhereClauseResult
 *  Any results associated with the whereClause request parameter.
 */
typedef struct _OpcUa_EventFilterResult
{
    OpcUa_Int32               NoOfSelectClauseResults;
    OpcUa_StatusCode*         SelectClauseResults;
    OpcUa_Int32               NoOfSelectClauseDiagnosticInfos;
    OpcUa_DiagnosticInfo*     SelectClauseDiagnosticInfos;
    OpcUa_ContentFilterResult WhereClauseResult;
}
OpcUa_EventFilterResult;

OPCUA_EXPORT OpcUa_Void       OpcUa_EventFilterResult_Initialize(OpcUa_EventFilterResult* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_EventFilterResult_Clear(OpcUa_EventFilterResult* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EventFilterResult_GetSize(OpcUa_EventFilterResult* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EventFilterResult_Encode(OpcUa_EventFilterResult* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EventFilterResult_Decode(OpcUa_EventFilterResult* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_EventFilterResult_Compare(const OpcUa_EventFilterResult* pValue1, const OpcUa_EventFilterResult* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_EventFilterResult_Copy(const OpcUa_EventFilterResult* pSource, OpcUa_EventFilterResult** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EventFilterResult_CopyTo(const OpcUa_EventFilterResult* pSource, OpcUa_EventFilterResult* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_EventFilterResult_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_AggregateFilterResult
/*============================================================================
 * The AggregateFilterResult structure.
 *===========================================================================*/
typedef struct _OpcUa_AggregateFilterResult
{
    OpcUa_DateTime               RevisedStartTime;
    OpcUa_Double                 RevisedProcessingInterval;
    OpcUa_AggregateConfiguration RevisedAggregateConfiguration;
}
OpcUa_AggregateFilterResult;

OPCUA_EXPORT OpcUa_Void       OpcUa_AggregateFilterResult_Initialize(OpcUa_AggregateFilterResult* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_AggregateFilterResult_Clear(OpcUa_AggregateFilterResult* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AggregateFilterResult_GetSize(OpcUa_AggregateFilterResult* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AggregateFilterResult_Encode(OpcUa_AggregateFilterResult* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AggregateFilterResult_Decode(OpcUa_AggregateFilterResult* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_AggregateFilterResult_Compare(const OpcUa_AggregateFilterResult* pValue1, const OpcUa_AggregateFilterResult* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_AggregateFilterResult_Copy(const OpcUa_AggregateFilterResult* pSource, OpcUa_AggregateFilterResult** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AggregateFilterResult_CopyTo(const OpcUa_AggregateFilterResult* pSource, OpcUa_AggregateFilterResult* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_AggregateFilterResult_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_MonitoringParameters
/*============================================================================
 * The MonitoringParameters structure.
 *===========================================================================*/
/** \struct OpcUa_MonitoringParameters
 *  Parameters that define the monitoring characteristics of a MonitoredItem.
 *
 *  \var OpcUa_MonitoringParameters::ClientHandle
 *  Client-supplied id of the MonitoredItem.
 *
 *  This id is used in Notifications generated for the list Node.
 *
 *  \var OpcUa_MonitoringParameters::SamplingInterval
 *  The interval in milliseconds that defines the fastest rate at which the
 *  MonitoredItem(s) should be accessed and evaluated.
 *
 *  The value 0 indicates that the Server should use the fastest practical rate.
 *
 *  The value -1 indicates that the default sampling interval defined by the
 *  publishing interval of the Subscription is requested. A different sampling
 *  interval is used if the publishing interval is not a supported sampling
 *  interval. Any negative number is interpreted as -1. The sampling interval is
 *  not changed if the publishing interval is changed by a subsequent call to the
 *  ModifySubscription Service.
 *
 *  The Server uses this parameter to assign the MonitoredItems to a sampling
 *  interval that it supports.
 *
 *  The assigned interval is provided in the revisedSamplingInterval parameter. The
 *  Server shall always return a revisedSamplingInterval that is equal or higher
 *  than the requested samplingInterval. If the requested samplingInterval is
 *  higher than the maximum sampling interval supported by the Server, the maximum
 *  sampling interval is returned.
 *
 *  \var OpcUa_MonitoringParameters::Filter
 *  A filter used by the Server to determine if the MonitoredItem should generate a
 *  Notification.
 *
 *  If not used, this parameter is null. The MonitoringFilter parameter type is an
 *  extensible parameter type. It specifies the types of filters that can be used.
 *
 *  \var OpcUa_MonitoringParameters::QueueSize
 *  The requested size of the MonitoredItem queue.
 *
 *  The following values have special meaning for data monitored items:
 *
 *  <dl> <dt>0 or 1</dt> <dd>the server returns the default queue size which shall
 *  be 1 as revisedQueueSize for data monitored items. The queue has a single
 *  entry, effectively disabling queuing.</dd> </dl> For values larger than one a
 *  first-in-first-out queue is to be used. The Server may limit the size in
 *  revisedQueueSize. In the case of a queue overflow, the Overflow bit (flag) in
 *  the InfoBits portion of the DataValue statusCode is set in the new value.
 *
 *  The following values have special meaning for event monitored items:
 *
 *  <dl> <dt>0</dt> <dd>the Server returns the default queue size for Event
 *  Notifications as revisedQueueSize for event monitored items.</dd> <dt>1</dt>
 *  <dd>the Server returns the minimum queue size the Server requires for Event
 *  Notifications as revisedQueueSize.</dd> <dt>MaxUInt32</dt> <dd>the Server
 *  returns the maximum queue size that the Server can support for Event
 *  Notifications as revisedQueueSize.</dd> </dl>
 *
 *  If a Client chooses a value between the minimum and maximum settings of the
 *  Server the value shall be returned in the revisedQueueSize. If the requested
 *  queueSize is outside the minimum or maximum, the Server shall return the
 *  corresponding bounding value.
 *
 *  In the case of a queue overflow, an Event of the type
 *  EventQueueOverflowEventType is generated.
 *
 *  \var OpcUa_MonitoringParameters::DiscardOldest
 *  A boolean parameter that specifies the discard policy when the queue is full
 *  and a new Notification is to be enqueued.
 *
 *  It has the following values: <dl> <dt>TRUE</dt> <dd>the oldest (first)
 *  Notification in the queue is discarded. The new Notification is added to the
 *  end of the queue.</dd> <dt>FALSE</dt> <dd>the new Notification is discarded.
 *  The queue is unchanged.</dd> </dl>
 */
typedef struct _OpcUa_MonitoringParameters
{
    OpcUa_UInt32          ClientHandle;
    OpcUa_Double          SamplingInterval;
    OpcUa_ExtensionObject Filter;
    OpcUa_UInt32          QueueSize;
    OpcUa_Boolean         DiscardOldest;
}
OpcUa_MonitoringParameters;

OPCUA_EXPORT OpcUa_Void       OpcUa_MonitoringParameters_Initialize(OpcUa_MonitoringParameters* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_MonitoringParameters_Clear(OpcUa_MonitoringParameters* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoringParameters_GetSize(OpcUa_MonitoringParameters* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoringParameters_Encode(OpcUa_MonitoringParameters* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoringParameters_Decode(OpcUa_MonitoringParameters* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_MonitoringParameters_Compare(const OpcUa_MonitoringParameters* pValue1, const OpcUa_MonitoringParameters* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoringParameters_Copy(const OpcUa_MonitoringParameters* pSource, OpcUa_MonitoringParameters** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoringParameters_CopyTo(const OpcUa_MonitoringParameters* pSource, OpcUa_MonitoringParameters* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_MonitoringParameters_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_MonitoredItemCreate
#ifndef OPCUA_EXCLUDE_MonitoredItemCreateRequest
/*============================================================================
 * The MonitoredItemCreateRequest structure.
 *===========================================================================*/
/** \struct OpcUa_MonitoredItemCreateRequest
 *  A structure that is defined as the type of the itemsToCreate parameter of the
 *  CreateMonitoredItems service.
 *
 *  \var OpcUa_MonitoredItemCreateRequest::ItemToMonitor
 *  Identifies an item in the AddressSpace to monitor.
 *
 *  To monitor for Events, the attributeId element of the ReadValueId structure is
 *  the id of the EventNotifier Attribute.
 *
 *  \var OpcUa_MonitoredItemCreateRequest::MonitoringMode
 *  The monitoring mode to be set for the MonitoredItem.
 *
 *  \var OpcUa_MonitoredItemCreateRequest::RequestedParameters
 *  The requested monitoring parameters.
 *
 *  Servers negotiate the values of these parameters based on the Subscription and
 *  the capabilities of the Server.
 */
typedef struct _OpcUa_MonitoredItemCreateRequest
{
    OpcUa_ReadValueId          ItemToMonitor;
    OpcUa_MonitoringMode       MonitoringMode;
    OpcUa_MonitoringParameters RequestedParameters;
}
OpcUa_MonitoredItemCreateRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_MonitoredItemCreateRequest_Initialize(OpcUa_MonitoredItemCreateRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_MonitoredItemCreateRequest_Clear(OpcUa_MonitoredItemCreateRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoredItemCreateRequest_GetSize(OpcUa_MonitoredItemCreateRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoredItemCreateRequest_Encode(OpcUa_MonitoredItemCreateRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoredItemCreateRequest_Decode(OpcUa_MonitoredItemCreateRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_MonitoredItemCreateRequest_Compare(const OpcUa_MonitoredItemCreateRequest* pValue1, const OpcUa_MonitoredItemCreateRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoredItemCreateRequest_Copy(const OpcUa_MonitoredItemCreateRequest* pSource, OpcUa_MonitoredItemCreateRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoredItemCreateRequest_CopyTo(const OpcUa_MonitoredItemCreateRequest* pSource, OpcUa_MonitoredItemCreateRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_MonitoredItemCreateRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_MonitoredItemCreate */

#ifndef OPCUA_EXCLUDE_MonitoredItemCreateResult
/*============================================================================
 * The MonitoredItemCreateResult structure.
 *===========================================================================*/
/** \struct OpcUa_MonitoredItemCreateResult
 *  A structure that is defined as the type of the results parameter of the
 *  CreateMonitoredItems service.
 *
 *  \var OpcUa_MonitoredItemCreateResult::StatusCode
 *  StatusCode for the MonitoredItem to create.
 *
 *  \var OpcUa_MonitoredItemCreateResult::MonitoredItemId
 *  Server-assigned ID for the MonitoredItem.
 *
 *  This ID is unique within the Subscription, but might not be unique within the
 *  Server or Session. This parameter is present only if the statusCode indicates
 *  that the MonitoredItem was successfully created.
 *
 *  \var OpcUa_MonitoredItemCreateResult::RevisedSamplingInterval
 *  The actual sampling interval that the Server will use.
 *
 *  This value is based on a number of factors, including capabilities of the
 *  underlying system. The Server shall always return a revisedSamplingInterval
 *  that is equal or higher than the requestedSamplingInterval. If the requested
 *  samplingInterval is higher than the maximum sampling interval supported by the
 *  Server, the maximum sampling interval is returned.
 *
 *  \var OpcUa_MonitoredItemCreateResult::RevisedQueueSize
 *  The actual queue size that the Server will use.
 *
 *  \var OpcUa_MonitoredItemCreateResult::FilterResult
 *  Contains any revised parameter values or error results associated with the
 *  MonitoringFilter specified in the request.
 *
 *  This parameter may be omitted if no errors occurred. The MonitoringFilterResult
 *  parameter type is an extensible parameter type.
 */
typedef struct _OpcUa_MonitoredItemCreateResult
{
    OpcUa_StatusCode      StatusCode;
    OpcUa_UInt32          MonitoredItemId;
    OpcUa_Double          RevisedSamplingInterval;
    OpcUa_UInt32          RevisedQueueSize;
    OpcUa_ExtensionObject FilterResult;
}
OpcUa_MonitoredItemCreateResult;

OPCUA_EXPORT OpcUa_Void       OpcUa_MonitoredItemCreateResult_Initialize(OpcUa_MonitoredItemCreateResult* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_MonitoredItemCreateResult_Clear(OpcUa_MonitoredItemCreateResult* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoredItemCreateResult_GetSize(OpcUa_MonitoredItemCreateResult* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoredItemCreateResult_Encode(OpcUa_MonitoredItemCreateResult* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoredItemCreateResult_Decode(OpcUa_MonitoredItemCreateResult* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_MonitoredItemCreateResult_Compare(const OpcUa_MonitoredItemCreateResult* pValue1, const OpcUa_MonitoredItemCreateResult* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoredItemCreateResult_Copy(const OpcUa_MonitoredItemCreateResult* pSource, OpcUa_MonitoredItemCreateResult** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoredItemCreateResult_CopyTo(const OpcUa_MonitoredItemCreateResult* pSource, OpcUa_MonitoredItemCreateResult* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_MonitoredItemCreateResult_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_CreateMonitoredItems
#ifndef OPCUA_EXCLUDE_CreateMonitoredItemsRequest
/*============================================================================
 * The CreateMonitoredItemsRequest structure.
 *===========================================================================*/
/** \struct OpcUa_CreateMonitoredItemsRequest
 *  Asynchronous call to create a list of monitored items in the subscription.
 *
 *  This service is used to create and add one or more MonitoredItems to a
 *  Subscription. A MonitoredItem is deleted automatically by the Server when the
 *  Subscription is deleted. Deleting a MonitoredItem causes its entire set of
 *  triggered item links to be deleted, but has no effect on the MonitoredItems
 *  referenced by the triggered items.
 *
 *  Calling the CreateMonitoredItems service repetitively to add a small number of
 *  MonitoredItems each time may adversely affect the performance of the Server.
 *  Instead, Clients should add a complete set of MonitoredItems to a Subscription
 *  whenever possible.
 *
 *  When a user adds a monitored item that the user is denied read access to, the
 *  add operation for the item shall succeed and the bad status Bad_NotReadable or
 *  Bad_UserAccessDenied shall be returned in the Publish response. This is the
 *  same behaviour for the case where the access rights are changed after the call
 *  to CreateMonitoredItems. If the access rights change to read rights, the Server
 *  shall start sending data for the MonitoredItem. The same procedure shall be
 *  applied for an IndexRange that does not deliver data for the current value but
 *  could deliver data in the future.
 *
 *  Monitored Nodes can be removed from the AddressSpace after the creation of a
 *  MonitoredItem. This does not affect the validity of the MonitoredItem but a
 *  Bad_NodeIdUnknown shall be returned in the Publish response.
 *
 *  The return diagnostic info setting in the request header of the
 *  CreateMonitoredItems or the last ModifyMonitoredItems Service is applied to the
 *  Monitored Items and is used as the diagnostic information settings when sending
 *  notifications in the Publish response.
 *
 *  Illegal request values for parameters that can be revised do not generate
 *  errors. Instead, the server will choose default values and indicate them in the
 *  corresponding revised parameter.
 *
 *  \var OpcUa_CreateMonitoredItemsRequest::SubscriptionId
 *  The Server-assigned identifier for the Subscription that will report
 *  Notifications for this MonitoredItem.
 *
 *  \var OpcUa_CreateMonitoredItemsRequest::TimestampsToReturn
 *  An enumeration that specifies the timestamp Attributes to be transmitted for
 *  each MonitoredItem.
 *
 *  When monitoring Events, this applies only to Event fields that are of type
 *  DataValue.
 *
 *  \var OpcUa_CreateMonitoredItemsRequest::ItemsToCreate
 *  A list of MonitoredItems to be created and assigned to the specified
 *  Subscription.
 */
typedef struct _OpcUa_CreateMonitoredItemsRequest
{
    OpcUa_RequestHeader               RequestHeader;
    OpcUa_UInt32                      SubscriptionId;
    OpcUa_TimestampsToReturn          TimestampsToReturn;
    OpcUa_Int32                       NoOfItemsToCreate;
    OpcUa_MonitoredItemCreateRequest* ItemsToCreate;
}
OpcUa_CreateMonitoredItemsRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_CreateMonitoredItemsRequest_Initialize(OpcUa_CreateMonitoredItemsRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_CreateMonitoredItemsRequest_Clear(OpcUa_CreateMonitoredItemsRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateMonitoredItemsRequest_GetSize(OpcUa_CreateMonitoredItemsRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateMonitoredItemsRequest_Encode(OpcUa_CreateMonitoredItemsRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateMonitoredItemsRequest_Decode(OpcUa_CreateMonitoredItemsRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_CreateMonitoredItemsRequest_Compare(const OpcUa_CreateMonitoredItemsRequest* pValue1, const OpcUa_CreateMonitoredItemsRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateMonitoredItemsRequest_Copy(const OpcUa_CreateMonitoredItemsRequest* pSource, OpcUa_CreateMonitoredItemsRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateMonitoredItemsRequest_CopyTo(const OpcUa_CreateMonitoredItemsRequest* pSource, OpcUa_CreateMonitoredItemsRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_CreateMonitoredItemsRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_CreateMonitoredItems */

#ifndef OPCUA_EXCLUDE_CreateMonitoredItems
#ifndef OPCUA_EXCLUDE_CreateMonitoredItemsResponse
/*============================================================================
 * The CreateMonitoredItemsResponse structure.
 *===========================================================================*/
/** \struct OpcUa_CreateMonitoredItemsResponse
 *
 * Response to a \ref OpcUa_CreateMonitoredItemsRequest.
 *
 *  \var OpcUa_CreateMonitoredItemsResponse::Results
 *  List of results for the MonitoredItems to create.
 *
 *  The size and order of the list matches the size and order of the \ref
 *  OpcUa_CreateMonitoredItemsRequest::ItemsToCreate request parameter.
 *
 *  \var OpcUa_CreateMonitoredItemsResponse::DiagnosticInfos
 *  List of diagnostic information for the MonitoredItems to create.
 *
 *  The size and order of the list matches the size and order of the \ref
 *  OpcUa_CreateMonitoredItemsRequest::ItemsToCreate request parameter. This list
 *  is empty if diagnostics information was not requested in the request header or
 *  if no diagnostic information was encountered in processing of the request.
 */
typedef struct _OpcUa_CreateMonitoredItemsResponse
{
    OpcUa_ResponseHeader             ResponseHeader;
    OpcUa_Int32                      NoOfResults;
    OpcUa_MonitoredItemCreateResult* Results;
    OpcUa_Int32                      NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo*            DiagnosticInfos;
}
OpcUa_CreateMonitoredItemsResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_CreateMonitoredItemsResponse_Initialize(OpcUa_CreateMonitoredItemsResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_CreateMonitoredItemsResponse_Clear(OpcUa_CreateMonitoredItemsResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateMonitoredItemsResponse_GetSize(OpcUa_CreateMonitoredItemsResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateMonitoredItemsResponse_Encode(OpcUa_CreateMonitoredItemsResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateMonitoredItemsResponse_Decode(OpcUa_CreateMonitoredItemsResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_CreateMonitoredItemsResponse_Compare(const OpcUa_CreateMonitoredItemsResponse* pValue1, const OpcUa_CreateMonitoredItemsResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateMonitoredItemsResponse_Copy(const OpcUa_CreateMonitoredItemsResponse* pSource, OpcUa_CreateMonitoredItemsResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateMonitoredItemsResponse_CopyTo(const OpcUa_CreateMonitoredItemsResponse* pSource, OpcUa_CreateMonitoredItemsResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_CreateMonitoredItemsResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_CreateMonitoredItems */

#ifndef OPCUA_EXCLUDE_MonitoredItemModify
#ifndef OPCUA_EXCLUDE_MonitoredItemModifyRequest
/*============================================================================
 * The MonitoredItemModifyRequest structure.
 *===========================================================================*/
/** \struct OpcUa_MonitoredItemModifyRequest
 *  A structure that is defined as the type of the itemsToModify parameter of the
 *  ModifyMonitoredItems service.
 *
 *  \var OpcUa_MonitoredItemModifyRequest::MonitoredItemId
 *  Server-assigned ID for the MonitoredItem.
 *
 *  \var OpcUa_MonitoredItemModifyRequest::RequestedParameters
 *  The requested values for the monitoring parameters.
 *
 *  If the number of notifications in the queue exceeds the new queue size, the
 *  notifications exceeding the size shall be discarded following the configured
 *  discard policy.
 */
typedef struct _OpcUa_MonitoredItemModifyRequest
{
    OpcUa_UInt32               MonitoredItemId;
    OpcUa_MonitoringParameters RequestedParameters;
}
OpcUa_MonitoredItemModifyRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_MonitoredItemModifyRequest_Initialize(OpcUa_MonitoredItemModifyRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_MonitoredItemModifyRequest_Clear(OpcUa_MonitoredItemModifyRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoredItemModifyRequest_GetSize(OpcUa_MonitoredItemModifyRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoredItemModifyRequest_Encode(OpcUa_MonitoredItemModifyRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoredItemModifyRequest_Decode(OpcUa_MonitoredItemModifyRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_MonitoredItemModifyRequest_Compare(const OpcUa_MonitoredItemModifyRequest* pValue1, const OpcUa_MonitoredItemModifyRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoredItemModifyRequest_Copy(const OpcUa_MonitoredItemModifyRequest* pSource, OpcUa_MonitoredItemModifyRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoredItemModifyRequest_CopyTo(const OpcUa_MonitoredItemModifyRequest* pSource, OpcUa_MonitoredItemModifyRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_MonitoredItemModifyRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_MonitoredItemModify */

#ifndef OPCUA_EXCLUDE_MonitoredItemModifyResult
/*============================================================================
 * The MonitoredItemModifyResult structure.
 *===========================================================================*/
/** \struct OpcUa_MonitoredItemModifyResult
 *  A structure that is defined as the type of the results parameter of the
 *  ModifyMonitoredItems service.
 *
 *  \var OpcUa_MonitoredItemModifyResult::StatusCode
 *  StatusCode for the MonitoredItem to be modified.
 *
 *  \var OpcUa_MonitoredItemModifyResult::RevisedSamplingInterval
 *  The actual sampling interval that the Server will use.
 *
 *  The Server returns the value it will actually use for the sampling interval.
 *  This value is based on a number of factors, including capabilities of the
 *  underlying system.
 *
 *  The Server shall always return a revisedSamplingInterval that is equal or
 *  higher than the requested samplingInterval. If the requestedSamplingInterval is
 *  higher than the maximum sampling interval supported by the Server, the maximum
 *  sampling interval is returned.
 *
 *  \var OpcUa_MonitoredItemModifyResult::RevisedQueueSize
 *  The actual queue size that the Server will use.
 *
 *  \var OpcUa_MonitoredItemModifyResult::FilterResult
 *  Contains any revised parameter values or error results associated with the
 *  MonitoringFilter specified in the request.
 *
 *  This parameter may be omitted if no errors occurred. The MonitoringFilterResult
 *  parameter type is an extensible parameter type.
 */
typedef struct _OpcUa_MonitoredItemModifyResult
{
    OpcUa_StatusCode      StatusCode;
    OpcUa_Double          RevisedSamplingInterval;
    OpcUa_UInt32          RevisedQueueSize;
    OpcUa_ExtensionObject FilterResult;
}
OpcUa_MonitoredItemModifyResult;

OPCUA_EXPORT OpcUa_Void       OpcUa_MonitoredItemModifyResult_Initialize(OpcUa_MonitoredItemModifyResult* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_MonitoredItemModifyResult_Clear(OpcUa_MonitoredItemModifyResult* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoredItemModifyResult_GetSize(OpcUa_MonitoredItemModifyResult* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoredItemModifyResult_Encode(OpcUa_MonitoredItemModifyResult* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoredItemModifyResult_Decode(OpcUa_MonitoredItemModifyResult* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_MonitoredItemModifyResult_Compare(const OpcUa_MonitoredItemModifyResult* pValue1, const OpcUa_MonitoredItemModifyResult* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoredItemModifyResult_Copy(const OpcUa_MonitoredItemModifyResult* pSource, OpcUa_MonitoredItemModifyResult** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoredItemModifyResult_CopyTo(const OpcUa_MonitoredItemModifyResult* pSource, OpcUa_MonitoredItemModifyResult* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_MonitoredItemModifyResult_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ModifyMonitoredItems
#ifndef OPCUA_EXCLUDE_ModifyMonitoredItemsRequest
/*============================================================================
 * The ModifyMonitoredItemsRequest structure.
 *===========================================================================*/
/** \struct OpcUa_ModifyMonitoredItemsRequest
 *  Asynchronous call to modify monitored items.
 *
 *  This service is used to modify MonitoredItems of a Subscription. Changes to the
 *  MonitoredItem settings shall be applied immediately by the Server. They take
 *  effect as soon as practical, but not later than twice the new
 *  revisedSamplingInterval.
 *
 *  The return diagnostic info setting in the request header of the
 *  CreateMonitoredItems or the last ModifyMonitoredItems Service is applied to the
 *  Monitored Items and is used as the diagnostic information settings when sending
 *  notifications in the Publish response.
 *
 *  Illegal request values for parameters that can be revised do not generate
 *  errors. Instead the server will choose default values and indicate them in the
 *  corresponding revised parameter.
 *
 *  \var OpcUa_ModifyMonitoredItemsRequest::SubscriptionId
 *  The Server-assigned identifier for the Subscription used to qualify the
 *  monitoredItemId
 *
 *  \var OpcUa_ModifyMonitoredItemsRequest::TimestampsToReturn
 *  An enumeration that specifies the timestamp Attributes to be transmitted for
 *  each MonitoredItem to be modified.
 *
 *  When monitoring Events, this applies only to Event fields that are of type
 *  DataValue.
 *
 *  \var OpcUa_ModifyMonitoredItemsRequest::ItemsToModify
 *  The list of MonitoredItems to modify.
 */
typedef struct _OpcUa_ModifyMonitoredItemsRequest
{
    OpcUa_RequestHeader               RequestHeader;
    OpcUa_UInt32                      SubscriptionId;
    OpcUa_TimestampsToReturn          TimestampsToReturn;
    OpcUa_Int32                       NoOfItemsToModify;
    OpcUa_MonitoredItemModifyRequest* ItemsToModify;
}
OpcUa_ModifyMonitoredItemsRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_ModifyMonitoredItemsRequest_Initialize(OpcUa_ModifyMonitoredItemsRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ModifyMonitoredItemsRequest_Clear(OpcUa_ModifyMonitoredItemsRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModifyMonitoredItemsRequest_GetSize(OpcUa_ModifyMonitoredItemsRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModifyMonitoredItemsRequest_Encode(OpcUa_ModifyMonitoredItemsRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModifyMonitoredItemsRequest_Decode(OpcUa_ModifyMonitoredItemsRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ModifyMonitoredItemsRequest_Compare(const OpcUa_ModifyMonitoredItemsRequest* pValue1, const OpcUa_ModifyMonitoredItemsRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModifyMonitoredItemsRequest_Copy(const OpcUa_ModifyMonitoredItemsRequest* pSource, OpcUa_ModifyMonitoredItemsRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModifyMonitoredItemsRequest_CopyTo(const OpcUa_ModifyMonitoredItemsRequest* pSource, OpcUa_ModifyMonitoredItemsRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ModifyMonitoredItemsRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_ModifyMonitoredItems */

#ifndef OPCUA_EXCLUDE_ModifyMonitoredItems
#ifndef OPCUA_EXCLUDE_ModifyMonitoredItemsResponse
/*============================================================================
 * The ModifyMonitoredItemsResponse structure.
 *===========================================================================*/
/** \struct OpcUa_ModifyMonitoredItemsResponse
 *
 * Response to a \ref OpcUa_ModifyMonitoredItemsRequest.
 *
 *  \var OpcUa_ModifyMonitoredItemsResponse::Results
 *  List of results for the MonitoredItems to modify.
 *
 *  The size and order of the list matches the size and order of the \ref
 *  OpcUa_ModifyMonitoredItemsRequest::ItemsToModify request parameter.
 *
 *  \var OpcUa_ModifyMonitoredItemsResponse::DiagnosticInfos
 *  List of diagnostic information for the MonitoredItems to modify.
 *
 *  The size and order of the list matches the size and order of the \ref
 *  OpcUa_ModifyMonitoredItemsRequest::ItemsToModify request parameter. This list
 *  is empty if diagnostics information was not requested in the request header or
 *  if no diagnostic information was encountered in processing of the request.
 */
typedef struct _OpcUa_ModifyMonitoredItemsResponse
{
    OpcUa_ResponseHeader             ResponseHeader;
    OpcUa_Int32                      NoOfResults;
    OpcUa_MonitoredItemModifyResult* Results;
    OpcUa_Int32                      NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo*            DiagnosticInfos;
}
OpcUa_ModifyMonitoredItemsResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_ModifyMonitoredItemsResponse_Initialize(OpcUa_ModifyMonitoredItemsResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ModifyMonitoredItemsResponse_Clear(OpcUa_ModifyMonitoredItemsResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModifyMonitoredItemsResponse_GetSize(OpcUa_ModifyMonitoredItemsResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModifyMonitoredItemsResponse_Encode(OpcUa_ModifyMonitoredItemsResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModifyMonitoredItemsResponse_Decode(OpcUa_ModifyMonitoredItemsResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ModifyMonitoredItemsResponse_Compare(const OpcUa_ModifyMonitoredItemsResponse* pValue1, const OpcUa_ModifyMonitoredItemsResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModifyMonitoredItemsResponse_Copy(const OpcUa_ModifyMonitoredItemsResponse* pSource, OpcUa_ModifyMonitoredItemsResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModifyMonitoredItemsResponse_CopyTo(const OpcUa_ModifyMonitoredItemsResponse* pSource, OpcUa_ModifyMonitoredItemsResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ModifyMonitoredItemsResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_ModifyMonitoredItems */

#ifndef OPCUA_EXCLUDE_SetMonitoringMode
#ifndef OPCUA_EXCLUDE_SetMonitoringModeRequest
/*============================================================================
 * The SetMonitoringModeRequest structure.
 *===========================================================================*/
/** \struct OpcUa_SetMonitoringModeRequest
 *  Asynchronous call to set the monitoring mode for a list of monitored items.
 *
 *  This Service is used to set the monitoring mode for one or more MonitoredItems
 *  of a Subscription. Setting the mode to DISABLED causes all queued notifications
 *  to be deleted.
 *
 *  \var OpcUa_SetMonitoringModeRequest::SubscriptionId
 *  The Server-assigned identifier for the Subscription used to qualify the
 *  monitoredItemIds.
 *
 *  \var OpcUa_SetMonitoringModeRequest::MonitoringMode
 *  The monitoring mode to be set for the MonitoredItems.
 *
 *  \var OpcUa_SetMonitoringModeRequest::MonitoredItemIds
 *  List of Server-assigned IDs for the MonitoredItems.
 */
typedef struct _OpcUa_SetMonitoringModeRequest
{
    OpcUa_RequestHeader  RequestHeader;
    OpcUa_UInt32         SubscriptionId;
    OpcUa_MonitoringMode MonitoringMode;
    OpcUa_Int32          NoOfMonitoredItemIds;
    OpcUa_UInt32*        MonitoredItemIds;
}
OpcUa_SetMonitoringModeRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_SetMonitoringModeRequest_Initialize(OpcUa_SetMonitoringModeRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_SetMonitoringModeRequest_Clear(OpcUa_SetMonitoringModeRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetMonitoringModeRequest_GetSize(OpcUa_SetMonitoringModeRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetMonitoringModeRequest_Encode(OpcUa_SetMonitoringModeRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetMonitoringModeRequest_Decode(OpcUa_SetMonitoringModeRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_SetMonitoringModeRequest_Compare(const OpcUa_SetMonitoringModeRequest* pValue1, const OpcUa_SetMonitoringModeRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetMonitoringModeRequest_Copy(const OpcUa_SetMonitoringModeRequest* pSource, OpcUa_SetMonitoringModeRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetMonitoringModeRequest_CopyTo(const OpcUa_SetMonitoringModeRequest* pSource, OpcUa_SetMonitoringModeRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_SetMonitoringModeRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_SetMonitoringMode */

#ifndef OPCUA_EXCLUDE_SetMonitoringMode
#ifndef OPCUA_EXCLUDE_SetMonitoringModeResponse
/*============================================================================
 * The SetMonitoringModeResponse structure.
 *===========================================================================*/
/** \struct OpcUa_SetMonitoringModeResponse
 *
 * Response to a \ref OpcUa_SetMonitoringModeRequest.
 *
 *  \var OpcUa_SetMonitoringModeResponse::Results
 *  List of StatusCodes for the MonitoredItems to enable/disable.
 *
 *  The size and order of the list matches the size and order of the \ref
 *  OpcUa_SetMonitoringModeRequest::MonitoredItemIds request parameter.
 *
 *  \var OpcUa_SetMonitoringModeResponse::DiagnosticInfos
 *  List of diagnostic information for the MonitoredItems to enable/disable.
 *
 *  The size and order of the list matches the size and order of the \ref
 *  OpcUa_SetMonitoringModeRequest::MonitoredItemIds request parameter. This list
 *  is empty if diagnostics information was not requested in the request header or
 *  if no diagnostic information was encountered in processing of the request.
 */
typedef struct _OpcUa_SetMonitoringModeResponse
{
    OpcUa_ResponseHeader  ResponseHeader;
    OpcUa_Int32           NoOfResults;
    OpcUa_StatusCode*     Results;
    OpcUa_Int32           NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo* DiagnosticInfos;
}
OpcUa_SetMonitoringModeResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_SetMonitoringModeResponse_Initialize(OpcUa_SetMonitoringModeResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_SetMonitoringModeResponse_Clear(OpcUa_SetMonitoringModeResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetMonitoringModeResponse_GetSize(OpcUa_SetMonitoringModeResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetMonitoringModeResponse_Encode(OpcUa_SetMonitoringModeResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetMonitoringModeResponse_Decode(OpcUa_SetMonitoringModeResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_SetMonitoringModeResponse_Compare(const OpcUa_SetMonitoringModeResponse* pValue1, const OpcUa_SetMonitoringModeResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetMonitoringModeResponse_Copy(const OpcUa_SetMonitoringModeResponse* pSource, OpcUa_SetMonitoringModeResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetMonitoringModeResponse_CopyTo(const OpcUa_SetMonitoringModeResponse* pSource, OpcUa_SetMonitoringModeResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_SetMonitoringModeResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_SetMonitoringMode */

#ifndef OPCUA_EXCLUDE_SetTriggering
#ifndef OPCUA_EXCLUDE_SetTriggeringRequest
/*============================================================================
 * The SetTriggeringRequest structure.
 *===========================================================================*/
/** \struct OpcUa_SetTriggeringRequest
 *  Asynchronously changes the triggering for a monitored item.
 *
 *  This service is used to create and delete triggering links for a triggering
 *  item. The triggering item and the items to report shall belong to the same
 *  subscription.
 *
 *  Each triggering link links a triggering item to an item to report. Each link is
 *  represented by the MonitoredItem id for the item to report. An error code is
 *  returned if this id is invalid.
 *
 *  \var OpcUa_SetTriggeringRequest::SubscriptionId
 *  The Server-assigned identifier for the subscription that contains the
 *  triggering item and the items to report.
 *
 *  \var OpcUa_SetTriggeringRequest::TriggeringItemId
 *  Server-assigned ID for the MonitoredItem used as the triggering item.
 *
 *  \var OpcUa_SetTriggeringRequest::LinksToAdd
 *  The list of Server-assigned IDs of the items to report that are to be added as
 *  triggering links.
 *
 *  The list of linksToRemove is processed before the linksToAdd.
 *
 *  \var OpcUa_SetTriggeringRequest::LinksToRemove
 *  The list of Server-assigned IDs of the items to report for the triggering links
 *  to be deleted.
 *
 *  The list of linksToRemove is processed before the linksToAdd.
 */
typedef struct _OpcUa_SetTriggeringRequest
{
    OpcUa_RequestHeader RequestHeader;
    OpcUa_UInt32        SubscriptionId;
    OpcUa_UInt32        TriggeringItemId;
    OpcUa_Int32         NoOfLinksToAdd;
    OpcUa_UInt32*       LinksToAdd;
    OpcUa_Int32         NoOfLinksToRemove;
    OpcUa_UInt32*       LinksToRemove;
}
OpcUa_SetTriggeringRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_SetTriggeringRequest_Initialize(OpcUa_SetTriggeringRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_SetTriggeringRequest_Clear(OpcUa_SetTriggeringRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetTriggeringRequest_GetSize(OpcUa_SetTriggeringRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetTriggeringRequest_Encode(OpcUa_SetTriggeringRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetTriggeringRequest_Decode(OpcUa_SetTriggeringRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_SetTriggeringRequest_Compare(const OpcUa_SetTriggeringRequest* pValue1, const OpcUa_SetTriggeringRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetTriggeringRequest_Copy(const OpcUa_SetTriggeringRequest* pSource, OpcUa_SetTriggeringRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetTriggeringRequest_CopyTo(const OpcUa_SetTriggeringRequest* pSource, OpcUa_SetTriggeringRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_SetTriggeringRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_SetTriggering */

#ifndef OPCUA_EXCLUDE_SetTriggering
#ifndef OPCUA_EXCLUDE_SetTriggeringResponse
/*============================================================================
 * The SetTriggeringResponse structure.
 *===========================================================================*/
/** \struct OpcUa_SetTriggeringResponse
 *
 * Response to a \ref OpcUa_SetTriggeringRequest.
 *
 *  \var OpcUa_SetTriggeringResponse::AddResults
 *  List of StatusCodes for the items to add.
 *
 *  The size and order of the list matches the size and order of the \ref
 *  OpcUa_SetTriggeringRequest::LinksToAdd parameter specified in the request.
 *
 *  \var OpcUa_SetTriggeringResponse::AddDiagnosticInfos
 *  List of diagnostic information for the links to add.
 *
 *  The size and order of the list matches the size and order of the request
 *  parameter. This list is empty if diagnostics information was not requested in
 *  the request header or if no diagnostic information was encountered in
 *  processing of the request.
 *
 *  \var OpcUa_SetTriggeringResponse::RemoveResults
 *  List of StatusCodes for the items to delete.
 *
 *  The size and order of the list matches the size and order of the parameter
 *  specified in the request.
 *
 *  \var OpcUa_SetTriggeringResponse::RemoveDiagnosticInfos
 *  List of diagnostic information for the links to delete.
 *
 *  The size and order of the list matches the size and order of the request
 *  parameter. This list is empty if diagnostics information was not requested in
 *  the request header or if no diagnostic information was encountered in
 *  processing of the request.
 */
typedef struct _OpcUa_SetTriggeringResponse
{
    OpcUa_ResponseHeader  ResponseHeader;
    OpcUa_Int32           NoOfAddResults;
    OpcUa_StatusCode*     AddResults;
    OpcUa_Int32           NoOfAddDiagnosticInfos;
    OpcUa_DiagnosticInfo* AddDiagnosticInfos;
    OpcUa_Int32           NoOfRemoveResults;
    OpcUa_StatusCode*     RemoveResults;
    OpcUa_Int32           NoOfRemoveDiagnosticInfos;
    OpcUa_DiagnosticInfo* RemoveDiagnosticInfos;
}
OpcUa_SetTriggeringResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_SetTriggeringResponse_Initialize(OpcUa_SetTriggeringResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_SetTriggeringResponse_Clear(OpcUa_SetTriggeringResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetTriggeringResponse_GetSize(OpcUa_SetTriggeringResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetTriggeringResponse_Encode(OpcUa_SetTriggeringResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetTriggeringResponse_Decode(OpcUa_SetTriggeringResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_SetTriggeringResponse_Compare(const OpcUa_SetTriggeringResponse* pValue1, const OpcUa_SetTriggeringResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetTriggeringResponse_Copy(const OpcUa_SetTriggeringResponse* pSource, OpcUa_SetTriggeringResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetTriggeringResponse_CopyTo(const OpcUa_SetTriggeringResponse* pSource, OpcUa_SetTriggeringResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_SetTriggeringResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_SetTriggering */

#ifndef OPCUA_EXCLUDE_DeleteMonitoredItems
#ifndef OPCUA_EXCLUDE_DeleteMonitoredItemsRequest
/*============================================================================
 * The DeleteMonitoredItemsRequest structure.
 *===========================================================================*/
/** \struct OpcUa_DeleteMonitoredItemsRequest
 *  Asynchronous call to delete monitored items.
 *
 *  This Service is used to remove one or more MonitoredItems of a Subscription.
 *  When a MonitoredItem is deleted, its triggered item links are also deleted.
 *
 *  Successful removal of a MonitoredItem, however, might not remove notifications
 *  for the MonitoredItem that are in the process of being sent by the
 *  Subscription. Therefore, Clients may receive notifications for the
 *  MonitoredItem after they have received a positive response that the
 *  MonitoredItem has been deleted.
 *
 *  \var OpcUa_DeleteMonitoredItemsRequest::SubscriptionId
 *  The Server-assigned identifier for the Subscription that contains the
 *  MonitoredItems to be deleted
 *
 *  \var OpcUa_DeleteMonitoredItemsRequest::MonitoredItemIds
 *  List of Server-assigned ids for the MonitoredItems to be deleted.
 */
typedef struct _OpcUa_DeleteMonitoredItemsRequest
{
    OpcUa_RequestHeader RequestHeader;
    OpcUa_UInt32        SubscriptionId;
    OpcUa_Int32         NoOfMonitoredItemIds;
    OpcUa_UInt32*       MonitoredItemIds;
}
OpcUa_DeleteMonitoredItemsRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteMonitoredItemsRequest_Initialize(OpcUa_DeleteMonitoredItemsRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteMonitoredItemsRequest_Clear(OpcUa_DeleteMonitoredItemsRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteMonitoredItemsRequest_GetSize(OpcUa_DeleteMonitoredItemsRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteMonitoredItemsRequest_Encode(OpcUa_DeleteMonitoredItemsRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteMonitoredItemsRequest_Decode(OpcUa_DeleteMonitoredItemsRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_DeleteMonitoredItemsRequest_Compare(const OpcUa_DeleteMonitoredItemsRequest* pValue1, const OpcUa_DeleteMonitoredItemsRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteMonitoredItemsRequest_Copy(const OpcUa_DeleteMonitoredItemsRequest* pSource, OpcUa_DeleteMonitoredItemsRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteMonitoredItemsRequest_CopyTo(const OpcUa_DeleteMonitoredItemsRequest* pSource, OpcUa_DeleteMonitoredItemsRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_DeleteMonitoredItemsRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_DeleteMonitoredItems */

#ifndef OPCUA_EXCLUDE_DeleteMonitoredItems
#ifndef OPCUA_EXCLUDE_DeleteMonitoredItemsResponse
/*============================================================================
 * The DeleteMonitoredItemsResponse structure.
 *===========================================================================*/
/** \struct OpcUa_DeleteMonitoredItemsResponse
 *
 * Response to a \ref OpcUa_DeleteMonitoredItemsRequest.
 *
 *  \var OpcUa_DeleteMonitoredItemsResponse::Results
 *  List of StatusCodes for the MonitoredItems to delete.
 *
 *  The size and order of the list matches the size and order of the
 *  monitoredItemIds request parameter.
 *
 *  \var OpcUa_DeleteMonitoredItemsResponse::DiagnosticInfos
 *  List of diagnostic information for the MonitoredItems to delete.
 *
 *  The size and order of the list matches the size and order of the
 *  monitoredItemIds request parameter. This list is empty if diagnostics
 *  information was not requested in the request header or if no diagnostic
 *  information was encountered in processing of the request.
 */
typedef struct _OpcUa_DeleteMonitoredItemsResponse
{
    OpcUa_ResponseHeader  ResponseHeader;
    OpcUa_Int32           NoOfResults;
    OpcUa_StatusCode*     Results;
    OpcUa_Int32           NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo* DiagnosticInfos;
}
OpcUa_DeleteMonitoredItemsResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteMonitoredItemsResponse_Initialize(OpcUa_DeleteMonitoredItemsResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteMonitoredItemsResponse_Clear(OpcUa_DeleteMonitoredItemsResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteMonitoredItemsResponse_GetSize(OpcUa_DeleteMonitoredItemsResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteMonitoredItemsResponse_Encode(OpcUa_DeleteMonitoredItemsResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteMonitoredItemsResponse_Decode(OpcUa_DeleteMonitoredItemsResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_DeleteMonitoredItemsResponse_Compare(const OpcUa_DeleteMonitoredItemsResponse* pValue1, const OpcUa_DeleteMonitoredItemsResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteMonitoredItemsResponse_Copy(const OpcUa_DeleteMonitoredItemsResponse* pSource, OpcUa_DeleteMonitoredItemsResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteMonitoredItemsResponse_CopyTo(const OpcUa_DeleteMonitoredItemsResponse* pSource, OpcUa_DeleteMonitoredItemsResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_DeleteMonitoredItemsResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_DeleteMonitoredItems */

#ifndef OPCUA_EXCLUDE_CreateSubscription
#ifndef OPCUA_EXCLUDE_CreateSubscriptionRequest
/*============================================================================
 * The CreateSubscriptionRequest structure.
 *===========================================================================*/
/** \struct OpcUa_CreateSubscriptionRequest
 *  Asynchronous call to create a Subscription
 *
 *  Subscriptions monitor a set of MonitoredItems for notifications and return them
 *  to the Client in response to Publish requests.
 *
 *  \var OpcUa_CreateSubscriptionRequest::RequestedPublishingInterval
 *  This interval defines the cyclic rate that the Subscription is being requested
 *  to return Notifications to the Client.
 *
 *  This interval is expressed in milliseconds. This interval is represented by the
 *  publishing timer in the Subscription state table.
 *
 *  The negotiated value for this parameter returned in the response is used as the
 *  default sampling interval for MonitoredItems assigned to this Subscription.
 *
 *  If the requested value is 0 or negative, the server shall revise with the
 *  fastest supported publishing interval.
 *
 *  \var OpcUa_CreateSubscriptionRequest::RequestedLifetimeCount
 *  Requested lifetime count.
 *
 *  The lifetime count shall be a mimimum of three times the keep keep-alive count.
 *  When the publishing timer has expired this number of times without a Publish
 *  request being available to send a NotificationMessage, then the Subscription
 *  shall be deleted by the Server.
 *
 *  \var OpcUa_CreateSubscriptionRequest::RequestedMaxKeepAliveCount
 *  Requested maximum keep-alive count.
 *
 *  When the publishing timer has expired this number of times without requiring
 *  any NotificationMessage to be sent, the Subscription sends a keep-alive Message
 *  to the Client.
 *
 *  The negotiated value for this parameter is returned in the response.
 *
 *  If the requested value is 0, the server shall revise with the smallest
 *  supported keep-alive count.
 *
 *  \var OpcUa_CreateSubscriptionRequest::MaxNotificationsPerPublish
 *  The maximum number of notifications that the Client wishes to receive in a
 *  single Publish response.
 *
 *  A value of zero indicates that there is no limit.
 *
 *  The number of notifiations per Publish is the sum of monitoredItems in the
 *  DataChangeNotification and events in the EventNotificationList.
 *
 *  \var OpcUa_CreateSubscriptionRequest::PublishingEnabled
 *  A Boolean parameter with the following values: <dl> <dt>TRUE</dt>
 *  <dd>publishing is enabled for the Subscription.</dd> <dt>FALSE</dt>
 *  <dd>publishing is disabled for the Subscription.</dd> </dl>
 *
 *  The value of this parameter does not affect the value of the monitoring mode
 *  Attribute of MonitoredItems.
 *
 *  \var OpcUa_CreateSubscriptionRequest::Priority
 *  Indicates the relative priority of the Subscription.
 *
 *  When more than one Subscription needs to send Notifications, the Server should
 *  dequeue a Publish request to the Subscription with the highest priority number.
 *  For Subscriptions with equal priority the Server should dequeue Publish
 *  requests in a round-robin fashion. When the keep-alive period expires for a
 *  Subscription it shall take precedence regardless of its priority, in order to
 *  prevent the Subscription from expiring.
 *
 *  A Client that does not require special priority settings should set this value
 *  to zero.
 */
typedef struct _OpcUa_CreateSubscriptionRequest
{
    OpcUa_RequestHeader RequestHeader;
    OpcUa_Double        RequestedPublishingInterval;
    OpcUa_UInt32        RequestedLifetimeCount;
    OpcUa_UInt32        RequestedMaxKeepAliveCount;
    OpcUa_UInt32        MaxNotificationsPerPublish;
    OpcUa_Boolean       PublishingEnabled;
    OpcUa_Byte          Priority;
}
OpcUa_CreateSubscriptionRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_CreateSubscriptionRequest_Initialize(OpcUa_CreateSubscriptionRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_CreateSubscriptionRequest_Clear(OpcUa_CreateSubscriptionRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateSubscriptionRequest_GetSize(OpcUa_CreateSubscriptionRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateSubscriptionRequest_Encode(OpcUa_CreateSubscriptionRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateSubscriptionRequest_Decode(OpcUa_CreateSubscriptionRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_CreateSubscriptionRequest_Compare(const OpcUa_CreateSubscriptionRequest* pValue1, const OpcUa_CreateSubscriptionRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateSubscriptionRequest_Copy(const OpcUa_CreateSubscriptionRequest* pSource, OpcUa_CreateSubscriptionRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateSubscriptionRequest_CopyTo(const OpcUa_CreateSubscriptionRequest* pSource, OpcUa_CreateSubscriptionRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_CreateSubscriptionRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_CreateSubscription */

#ifndef OPCUA_EXCLUDE_CreateSubscription
#ifndef OPCUA_EXCLUDE_CreateSubscriptionResponse
/*============================================================================
 * The CreateSubscriptionResponse structure.
 *===========================================================================*/
/** \struct OpcUa_CreateSubscriptionResponse
 *
 * Response to a \ref OpcUa_CreateSubscriptionRequest.
 *
 *  \var OpcUa_CreateSubscriptionResponse::SubscriptionId
 *  The Server-assigned identifier for the Subscription.
 *
 *  This identifier shall be unique for the entire Server, not just for the
 *  Session, in order to allow the Subscription to be transferred to another
 *  Session using the TransferSubscriptions service.
 *
 *  \var OpcUa_CreateSubscriptionResponse::RevisedPublishingInterval
 *  The actual publishing interval that the Server will use, expressed in
 *  milliseconds.
 *
 *  The Server should attempt to honor the Client request for this parameter, but
 *  may negotiate this value up or down to meet its own constraints.
 *
 *  \var OpcUa_CreateSubscriptionResponse::RevisedLifetimeCount
 *  The lifetime of the Subscription shall be a minimum of three times the
 *  keep-alive interval negotiated by the Server.
 *
 *  \var OpcUa_CreateSubscriptionResponse::RevisedMaxKeepAliveCount
 *  The actual maximum keep-alive count.
 *
 *  The Server should attempt to honor the Client request for this parameter, but
 *  may negotiate this value up or down to meet its own constraints.
 */
typedef struct _OpcUa_CreateSubscriptionResponse
{
    OpcUa_ResponseHeader ResponseHeader;
    OpcUa_UInt32         SubscriptionId;
    OpcUa_Double         RevisedPublishingInterval;
    OpcUa_UInt32         RevisedLifetimeCount;
    OpcUa_UInt32         RevisedMaxKeepAliveCount;
}
OpcUa_CreateSubscriptionResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_CreateSubscriptionResponse_Initialize(OpcUa_CreateSubscriptionResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_CreateSubscriptionResponse_Clear(OpcUa_CreateSubscriptionResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateSubscriptionResponse_GetSize(OpcUa_CreateSubscriptionResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateSubscriptionResponse_Encode(OpcUa_CreateSubscriptionResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateSubscriptionResponse_Decode(OpcUa_CreateSubscriptionResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_CreateSubscriptionResponse_Compare(const OpcUa_CreateSubscriptionResponse* pValue1, const OpcUa_CreateSubscriptionResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateSubscriptionResponse_Copy(const OpcUa_CreateSubscriptionResponse* pSource, OpcUa_CreateSubscriptionResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CreateSubscriptionResponse_CopyTo(const OpcUa_CreateSubscriptionResponse* pSource, OpcUa_CreateSubscriptionResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_CreateSubscriptionResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_CreateSubscription */

#ifndef OPCUA_EXCLUDE_ModifySubscription
#ifndef OPCUA_EXCLUDE_ModifySubscriptionRequest
/*============================================================================
 * The ModifySubscriptionRequest structure.
 *===========================================================================*/
/** \struct OpcUa_ModifySubscriptionRequest
 *  Asynchronous call to modify a Subscription
 *
 *  Illegal request values for parameters that can be revised do not generate
 *  errors. Instead the server will choose default values and indicate them in the
 *  corresponding revised parameter.
 *
 *  Changes to the Subscription settings shall be applied immediately by the
 *  Server. They take effect as soon as practical but not later than twice the new
 *  \ref OpcUa_ModifySubscriptionResponse::RevisedPublishingInterval.
 *
 *  \var OpcUa_ModifySubscriptionRequest::SubscriptionId
 *  The Server-assigned identifier for the Subscription.
 *
 *  \var OpcUa_ModifySubscriptionRequest::RequestedPublishingInterval
 *  This interval defines the cyclic rate that the Subscription is being requested
 *  to return Notifications to the Client.
 *
 *  This interval is expressed in milliseconds.
 *
 *  The negotiated value for this parameter returned in the response is used as the
 *  default sampling interval for MonitoredItems assigned to this Subscription.
 *
 *  If the requested value is 0 or negative, the server shall revise with the
 *  fastest supported publishing interval.
 *
 *  \var OpcUa_ModifySubscriptionRequest::RequestedLifetimeCount
 *  The requested lifetime count. The lifetime count shall be a mimimum of three
 *  times the keep keep-alive count.
 *
 *  When the publishing timer has expired this number of times without a Publish
 *  request being available to send a NotificationMessage, then the Subscription
 *  shall be deleted by the Server.
 *
 *  \var OpcUa_ModifySubscriptionRequest::RequestedMaxKeepAliveCount
 *  Requested maximum keep-alive count.
 *
 *  When the publishing timer has expired this number of times without requiring
 *  any NotificationMessage to be sent, the Subscription sends a keep-alive Message
 *  to the Client.
 *
 *  The negotiated value for this parameter is returned in the response.
 *
 *  If the requested value is 0, the server shall revise with the smallest
 *  supported keep-alive count.
 *
 *  \var OpcUa_ModifySubscriptionRequest::MaxNotificationsPerPublish
 *  The maximum number of notifications that the Client wishes to receive in a
 *  single Publish response.
 *
 *  A value of zero indicates that there is no limit.
 *
 *  \var OpcUa_ModifySubscriptionRequest::Priority
 *  Indicates the relative priority of the Subscription.
 *
 *  When more than one Subscription needs to send Notifications, the Server should
 *  dequeue a Publish request to the Subscription with the highest priority number.
 *  For Subscriptions with equal priority the Server should dequeue Publish
 *  requests in a round-robin fashion. Any Subscription that needs to send a
 *  keep-alive Message shall take precedence regardless of its priority, in order
 *  to prevent the Subscription from expiring.
 *
 *  A Client that does not require special priority settings should set this value
 *  to zero.
 */
typedef struct _OpcUa_ModifySubscriptionRequest
{
    OpcUa_RequestHeader RequestHeader;
    OpcUa_UInt32        SubscriptionId;
    OpcUa_Double        RequestedPublishingInterval;
    OpcUa_UInt32        RequestedLifetimeCount;
    OpcUa_UInt32        RequestedMaxKeepAliveCount;
    OpcUa_UInt32        MaxNotificationsPerPublish;
    OpcUa_Byte          Priority;
}
OpcUa_ModifySubscriptionRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_ModifySubscriptionRequest_Initialize(OpcUa_ModifySubscriptionRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ModifySubscriptionRequest_Clear(OpcUa_ModifySubscriptionRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModifySubscriptionRequest_GetSize(OpcUa_ModifySubscriptionRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModifySubscriptionRequest_Encode(OpcUa_ModifySubscriptionRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModifySubscriptionRequest_Decode(OpcUa_ModifySubscriptionRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ModifySubscriptionRequest_Compare(const OpcUa_ModifySubscriptionRequest* pValue1, const OpcUa_ModifySubscriptionRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModifySubscriptionRequest_Copy(const OpcUa_ModifySubscriptionRequest* pSource, OpcUa_ModifySubscriptionRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModifySubscriptionRequest_CopyTo(const OpcUa_ModifySubscriptionRequest* pSource, OpcUa_ModifySubscriptionRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ModifySubscriptionRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_ModifySubscription */

#ifndef OPCUA_EXCLUDE_ModifySubscription
#ifndef OPCUA_EXCLUDE_ModifySubscriptionResponse
/*============================================================================
 * The ModifySubscriptionResponse structure.
 *===========================================================================*/
/** \struct OpcUa_ModifySubscriptionResponse
 *
 * Response to a \ref OpcUa_ModifySubscriptionRequest.
 *
 *  \var OpcUa_ModifySubscriptionResponse::RevisedPublishingInterval
 *  The actual publishing interval that the Server will use, expressed in
 *  milliseconds.
 *
 *  The Server should attempt to honor the Client request for this parameter, but
 *  may negotiate this value up or down to meet its own constraints.
 *
 *  \var OpcUa_ModifySubscriptionResponse::RevisedLifetimeCount
 *  The lifetime of the Subscription shall be a minimum of three times the
 *  keep-alive interval negotiated by the Server.
 *
 *  \var OpcUa_ModifySubscriptionResponse::RevisedMaxKeepAliveCount
 *  The actual maximum keep-alive count.
 *
 *  The Server should attempt to honor the Client request for this parameter, but
 *  may negotiate this value up or down to meet its own constraints.
 */
typedef struct _OpcUa_ModifySubscriptionResponse
{
    OpcUa_ResponseHeader ResponseHeader;
    OpcUa_Double         RevisedPublishingInterval;
    OpcUa_UInt32         RevisedLifetimeCount;
    OpcUa_UInt32         RevisedMaxKeepAliveCount;
}
OpcUa_ModifySubscriptionResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_ModifySubscriptionResponse_Initialize(OpcUa_ModifySubscriptionResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ModifySubscriptionResponse_Clear(OpcUa_ModifySubscriptionResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModifySubscriptionResponse_GetSize(OpcUa_ModifySubscriptionResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModifySubscriptionResponse_Encode(OpcUa_ModifySubscriptionResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModifySubscriptionResponse_Decode(OpcUa_ModifySubscriptionResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ModifySubscriptionResponse_Compare(const OpcUa_ModifySubscriptionResponse* pValue1, const OpcUa_ModifySubscriptionResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModifySubscriptionResponse_Copy(const OpcUa_ModifySubscriptionResponse* pSource, OpcUa_ModifySubscriptionResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModifySubscriptionResponse_CopyTo(const OpcUa_ModifySubscriptionResponse* pSource, OpcUa_ModifySubscriptionResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ModifySubscriptionResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_ModifySubscription */

#ifndef OPCUA_EXCLUDE_SetPublishingMode
#ifndef OPCUA_EXCLUDE_SetPublishingModeRequest
/*============================================================================
 * The SetPublishingModeRequest structure.
 *===========================================================================*/
/** \struct OpcUa_SetPublishingModeRequest
 *  Asynchronous call to enable sending of Notifications on one or more
 *  Subscriptions.
 *
 *  \var OpcUa_SetPublishingModeRequest::PublishingEnabled
 *  A Boolean parameter indicating whether publishing is enabled.
 *
 *  It has the following values: <dl> <dt>TRUE</dt> <dd>publishing of
 *  NotificationMessages is enabled for the Subscription.</dd> <dt>FALSE</dt>
 *  <dd>publishing of NotificationMessages is disabled for the Subscription.</dd>
 *  </dl>
 *
 *  The value of this parameter does not affect the value of the monitoring mode
 *  Attribute of MonitoredItems. Setting this value to FALSE does not discontinue
 *  the sending of keep-alive Messages.
 *
 *  \var OpcUa_SetPublishingModeRequest::SubscriptionIds
 *  List of Server-assigned identifiers for the Subscriptions to enable or disable.
 */
typedef struct _OpcUa_SetPublishingModeRequest
{
    OpcUa_RequestHeader RequestHeader;
    OpcUa_Boolean       PublishingEnabled;
    OpcUa_Int32         NoOfSubscriptionIds;
    OpcUa_UInt32*       SubscriptionIds;
}
OpcUa_SetPublishingModeRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_SetPublishingModeRequest_Initialize(OpcUa_SetPublishingModeRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_SetPublishingModeRequest_Clear(OpcUa_SetPublishingModeRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetPublishingModeRequest_GetSize(OpcUa_SetPublishingModeRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetPublishingModeRequest_Encode(OpcUa_SetPublishingModeRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetPublishingModeRequest_Decode(OpcUa_SetPublishingModeRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_SetPublishingModeRequest_Compare(const OpcUa_SetPublishingModeRequest* pValue1, const OpcUa_SetPublishingModeRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetPublishingModeRequest_Copy(const OpcUa_SetPublishingModeRequest* pSource, OpcUa_SetPublishingModeRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetPublishingModeRequest_CopyTo(const OpcUa_SetPublishingModeRequest* pSource, OpcUa_SetPublishingModeRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_SetPublishingModeRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_SetPublishingMode */

#ifndef OPCUA_EXCLUDE_SetPublishingMode
#ifndef OPCUA_EXCLUDE_SetPublishingModeResponse
/*============================================================================
 * The SetPublishingModeResponse structure.
 *===========================================================================*/
/** \struct OpcUa_SetPublishingModeResponse
 *
 * Response to a \ref OpcUa_SetPublishingModeRequest.
 *
 *  \var OpcUa_SetPublishingModeResponse::Results
 *  List of StatusCodes for the Subscriptions to enable/disable.
 *
 *  The size and order of the list matches the size and order of the
 *  subscriptionIds request parameter.
 *
 *  \var OpcUa_SetPublishingModeResponse::NoOfDiagnosticInfos
 *  List of diagnostic information for the Subscriptions to enable/disable.
 *
 *  The size and order of the list matches the size and order of the
 *  subscriptionIds request parameter. This list is empty if diagnostics
 *  information was not requested in the request header or if no diagnostic
 *  information was encountered in processing of the request.
 */
typedef struct _OpcUa_SetPublishingModeResponse
{
    OpcUa_ResponseHeader  ResponseHeader;
    OpcUa_Int32           NoOfResults;
    OpcUa_StatusCode*     Results;
    OpcUa_Int32           NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo* DiagnosticInfos;
}
OpcUa_SetPublishingModeResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_SetPublishingModeResponse_Initialize(OpcUa_SetPublishingModeResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_SetPublishingModeResponse_Clear(OpcUa_SetPublishingModeResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetPublishingModeResponse_GetSize(OpcUa_SetPublishingModeResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetPublishingModeResponse_Encode(OpcUa_SetPublishingModeResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetPublishingModeResponse_Decode(OpcUa_SetPublishingModeResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_SetPublishingModeResponse_Compare(const OpcUa_SetPublishingModeResponse* pValue1, const OpcUa_SetPublishingModeResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetPublishingModeResponse_Copy(const OpcUa_SetPublishingModeResponse* pSource, OpcUa_SetPublishingModeResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SetPublishingModeResponse_CopyTo(const OpcUa_SetPublishingModeResponse* pSource, OpcUa_SetPublishingModeResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_SetPublishingModeResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_SetPublishingMode */

#ifndef OPCUA_EXCLUDE_NotificationMessage
/*============================================================================
 * The NotificationMessage structure.
 *===========================================================================*/
/** \struct OpcUa_NotificationMessage
 *
 *  \var OpcUa_NotificationMessage::SequenceNumber
 *  The Message that contains one or more Notifications.
 *
 *  \var OpcUa_NotificationMessage::PublishTime
 *  The sequence number of the NotificationMessage.
 *
 *  \var OpcUa_NotificationMessage::NoOfNotificationData
 *  The time that this Message was sent to the Client.
 *
 *  If this Message is retransmitted to the Client, this parameter contains the
 *  time it was first transmitted to the Client.
 *
 *  \var OpcUa_NotificationMessage::NotificationData
 *  The list of NotificationData structures.
 *
 *  The NotificationData parameter type is an extensible parameter type. It
 *  specifies the types of Notifications that can be sent.
 *
 *  Notifications of the same type should be grouped into one NotificationData
 *  element. If a Subscription contains MonitoredItems for events and data, this
 *  array should have not more than 2 elements. If the Subscription contains
 *  MonitoredItems only for data or only for events, the array size should always
 *  be one for this Subscription.
 */
typedef struct _OpcUa_NotificationMessage
{
    OpcUa_UInt32           SequenceNumber;
    OpcUa_DateTime         PublishTime;
    OpcUa_Int32            NoOfNotificationData;
    OpcUa_ExtensionObject* NotificationData;
}
OpcUa_NotificationMessage;

OPCUA_EXPORT OpcUa_Void       OpcUa_NotificationMessage_Initialize(OpcUa_NotificationMessage* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_NotificationMessage_Clear(OpcUa_NotificationMessage* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_NotificationMessage_GetSize(OpcUa_NotificationMessage* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_NotificationMessage_Encode(OpcUa_NotificationMessage* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_NotificationMessage_Decode(OpcUa_NotificationMessage* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_NotificationMessage_Compare(const OpcUa_NotificationMessage* pValue1, const OpcUa_NotificationMessage* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_NotificationMessage_Copy(const OpcUa_NotificationMessage* pSource, OpcUa_NotificationMessage** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_NotificationMessage_CopyTo(const OpcUa_NotificationMessage* pSource, OpcUa_NotificationMessage* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_NotificationMessage_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_MonitoredItemNotification
/*============================================================================
 * The MonitoredItemNotification structure.
 *===========================================================================*/
typedef struct _OpcUa_MonitoredItemNotification
{
    OpcUa_UInt32    ClientHandle;
    OpcUa_DataValue Value;
}
OpcUa_MonitoredItemNotification;

OPCUA_EXPORT OpcUa_Void       OpcUa_MonitoredItemNotification_Initialize(OpcUa_MonitoredItemNotification* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_MonitoredItemNotification_Clear(OpcUa_MonitoredItemNotification* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoredItemNotification_GetSize(OpcUa_MonitoredItemNotification* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoredItemNotification_Encode(OpcUa_MonitoredItemNotification* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoredItemNotification_Decode(OpcUa_MonitoredItemNotification* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_MonitoredItemNotification_Compare(const OpcUa_MonitoredItemNotification* pValue1, const OpcUa_MonitoredItemNotification* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoredItemNotification_Copy(const OpcUa_MonitoredItemNotification* pSource, OpcUa_MonitoredItemNotification** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MonitoredItemNotification_CopyTo(const OpcUa_MonitoredItemNotification* pSource, OpcUa_MonitoredItemNotification* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_MonitoredItemNotification_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_EventFieldList
/*============================================================================
 * The EventFieldList structure.
 *===========================================================================*/
typedef struct _OpcUa_EventFieldList
{
    OpcUa_UInt32   ClientHandle;
    OpcUa_Int32    NoOfEventFields;
    OpcUa_Variant* EventFields;
}
OpcUa_EventFieldList;

OPCUA_EXPORT OpcUa_Void       OpcUa_EventFieldList_Initialize(OpcUa_EventFieldList* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_EventFieldList_Clear(OpcUa_EventFieldList* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EventFieldList_GetSize(OpcUa_EventFieldList* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EventFieldList_Encode(OpcUa_EventFieldList* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EventFieldList_Decode(OpcUa_EventFieldList* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_EventFieldList_Compare(const OpcUa_EventFieldList* pValue1, const OpcUa_EventFieldList* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_EventFieldList_Copy(const OpcUa_EventFieldList* pSource, OpcUa_EventFieldList** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EventFieldList_CopyTo(const OpcUa_EventFieldList* pSource, OpcUa_EventFieldList* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_EventFieldList_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_HistoryEventFieldList
/*============================================================================
 * The HistoryEventFieldList structure.
 *===========================================================================*/
/** \struct OpcUa_HistoryEventFieldList
 *
 *  \var OpcUa_HistoryEventFieldList::EventFields
 *  List of selected Event fields.
 *
 *  This will be a one to one match with the fields selected in the EventFilter.
 */
typedef struct _OpcUa_HistoryEventFieldList
{
    OpcUa_Int32    NoOfEventFields;
    OpcUa_Variant* EventFields;
}
OpcUa_HistoryEventFieldList;

OPCUA_EXPORT OpcUa_Void       OpcUa_HistoryEventFieldList_Initialize(OpcUa_HistoryEventFieldList* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_HistoryEventFieldList_Clear(OpcUa_HistoryEventFieldList* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryEventFieldList_GetSize(OpcUa_HistoryEventFieldList* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryEventFieldList_Encode(OpcUa_HistoryEventFieldList* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryEventFieldList_Decode(OpcUa_HistoryEventFieldList* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_HistoryEventFieldList_Compare(const OpcUa_HistoryEventFieldList* pValue1, const OpcUa_HistoryEventFieldList* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryEventFieldList_Copy(const OpcUa_HistoryEventFieldList* pSource, OpcUa_HistoryEventFieldList** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryEventFieldList_CopyTo(const OpcUa_HistoryEventFieldList* pSource, OpcUa_HistoryEventFieldList* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_HistoryEventFieldList_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_StatusChangeNotification
/*============================================================================
 * The StatusChangeNotification structure.
 *===========================================================================*/
typedef struct _OpcUa_StatusChangeNotification
{
    OpcUa_StatusCode     Status;
    OpcUa_DiagnosticInfo DiagnosticInfo;
}
OpcUa_StatusChangeNotification;

OPCUA_EXPORT OpcUa_Void       OpcUa_StatusChangeNotification_Initialize(OpcUa_StatusChangeNotification* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_StatusChangeNotification_Clear(OpcUa_StatusChangeNotification* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_StatusChangeNotification_GetSize(OpcUa_StatusChangeNotification* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_StatusChangeNotification_Encode(OpcUa_StatusChangeNotification* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_StatusChangeNotification_Decode(OpcUa_StatusChangeNotification* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_StatusChangeNotification_Compare(const OpcUa_StatusChangeNotification* pValue1, const OpcUa_StatusChangeNotification* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_StatusChangeNotification_Copy(const OpcUa_StatusChangeNotification* pSource, OpcUa_StatusChangeNotification** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_StatusChangeNotification_CopyTo(const OpcUa_StatusChangeNotification* pSource, OpcUa_StatusChangeNotification* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_StatusChangeNotification_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_SubscriptionAcknowledgement
/*============================================================================
 * The SubscriptionAcknowledgement structure.
 *===========================================================================*/
/** \struct OpcUa_SubscriptionAcknowledgement
 *  A structure that is defined as the type of the subscriptionAcknowledgements
 *  parameter of the Publish service.
 *
 *  \var OpcUa_SubscriptionAcknowledgement::SubscriptionId
 *  The Server assigned identifier for a Subscription.
 *
 *  \var OpcUa_SubscriptionAcknowledgement::SequenceNumber
 *  The sequence number being acknowledged.
 *
 *  The Server may delete the message with this sequence number from its
 *  retransmission queue.
 */
typedef struct _OpcUa_SubscriptionAcknowledgement
{
    OpcUa_UInt32 SubscriptionId;
    OpcUa_UInt32 SequenceNumber;
}
OpcUa_SubscriptionAcknowledgement;

OPCUA_EXPORT OpcUa_Void       OpcUa_SubscriptionAcknowledgement_Initialize(OpcUa_SubscriptionAcknowledgement* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_SubscriptionAcknowledgement_Clear(OpcUa_SubscriptionAcknowledgement* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SubscriptionAcknowledgement_GetSize(OpcUa_SubscriptionAcknowledgement* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SubscriptionAcknowledgement_Encode(OpcUa_SubscriptionAcknowledgement* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SubscriptionAcknowledgement_Decode(OpcUa_SubscriptionAcknowledgement* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_SubscriptionAcknowledgement_Compare(const OpcUa_SubscriptionAcknowledgement* pValue1, const OpcUa_SubscriptionAcknowledgement* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_SubscriptionAcknowledgement_Copy(const OpcUa_SubscriptionAcknowledgement* pSource, OpcUa_SubscriptionAcknowledgement** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SubscriptionAcknowledgement_CopyTo(const OpcUa_SubscriptionAcknowledgement* pSource, OpcUa_SubscriptionAcknowledgement* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_SubscriptionAcknowledgement_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_Publish
#ifndef OPCUA_EXCLUDE_PublishRequest
/*============================================================================
 * The PublishRequest structure.
 *===========================================================================*/
/** \struct OpcUa_PublishRequest
 *  Request the server to return NotificationMessages and acknowledge received
 *  NotificationMessages.
 *
 *  This Service is used for two purposes. First, it is used to acknowledge the
 *  receipt of NotificationMessages for one or more Subscriptions. Second, it is
 *  used to request the Server to return a NotificationMessage or a keep-alive
 *  message. Since Publish requests are not directed to a specific Subscription,
 *  they may be used by any Subscription.
 *
 *  Client strategies for issuing Publish requests may vary depending on the
 *  networking delays between the Client and the Server. In many cases, the Client
 *  may wish to issue a Publish request immediately after creating a Subscription,
 *  and thereafter, immediately after receiving a Publish response.
 *
 *  In other cases, especially in high latency networks, the Client may wish to
 *  pipeline Publish requests to ensure cyclic reporting from the Server.
 *  Pipelining involves sending more than one Publish request for each Subscription
 *  before receiving a response. For example, if the network introduces a delay
 *  between the Client and the Server of five seconds and the publishing interval
 *  for a Subscription is one second, then the Client will have to issue Publish
 *  requests every second instead of waiting for a response to be received before
 *  sending the next request.
 *
 *  A server should limit the number of active Publish requests to avoid an
 *  infinite number since it is expected that the Publish requests are queued in
 *  the Server. But a Server shall accept more queued Publish requests than created
 *  Subscriptions. It is expected that a Server supports several Publish requests
 *  per Subscription. When a Server receives a new Publish request that exceeds its
 *  limit it shall dequeue the oldest Publish request and return a response with
 *  the result set to Bad_TooManyPublishRequests. If a Client receives this Service
 *  result for a Publish request it shall not issue another Publish request before
 *  one of its outstanding Publish requests is returned from the Server.
 *
 *  Clients can limit the size of Publish responses with the
 *  maxNotificationsPerPublish parameter passed to the CreateSubscription Service.
 *  However, this could still result in a message that is too large for the Client
 *  or Server to process. In this situation, the Client will find that either the
 *  SecureChannel goes into a fault state and needs to be reestablished or the
 *  Publish response returns an error and calling the Republish Service also
 *  returns an error. If either situation occurs then the Client will have to
 *  adjust its message processing limits or the parameters for the Subscription
 *  and/or MonitoredItems.
 *
 *  The return diagnostic info setting in the request header of the
 *  CreateMonitoredItems or the last ModifyMonitoredItems Service is applied to the
 *  Monitored Items and is used as the diagnostic information settings when sending
 *  Notifications in the Publish response.
 *
 *  \var OpcUa_PublishRequest::SubscriptionAcknowledgements
 *  The list of acknowledgements for one or more Subscriptions.
 *
 *  This list may contain multiple acknowledgements for the same Subscription
 *  (multiple entries with the same).
 */
typedef struct _OpcUa_PublishRequest
{
    OpcUa_RequestHeader                RequestHeader;
    OpcUa_Int32                        NoOfSubscriptionAcknowledgements;
    OpcUa_SubscriptionAcknowledgement* SubscriptionAcknowledgements;
}
OpcUa_PublishRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_PublishRequest_Initialize(OpcUa_PublishRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_PublishRequest_Clear(OpcUa_PublishRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_PublishRequest_GetSize(OpcUa_PublishRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_PublishRequest_Encode(OpcUa_PublishRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_PublishRequest_Decode(OpcUa_PublishRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_PublishRequest_Compare(const OpcUa_PublishRequest* pValue1, const OpcUa_PublishRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_PublishRequest_Copy(const OpcUa_PublishRequest* pSource, OpcUa_PublishRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_PublishRequest_CopyTo(const OpcUa_PublishRequest* pSource, OpcUa_PublishRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_PublishRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_Publish */

#ifndef OPCUA_EXCLUDE_Publish
#ifndef OPCUA_EXCLUDE_PublishResponse
/*============================================================================
 * The PublishResponse structure.
 *===========================================================================*/
/** \struct OpcUa_PublishResponse
 *
 * Response to a \ref OpcUa_PublishRequest.
 *
 *  \var OpcUa_PublishResponse::SubscriptionId
 *  The Server-assigned identifier for the Subscription for which notifications are
 *  being returned.
 *
 *  The value 0 is used to indicate that there were no Subscriptions defined for
 *  which a response could be sent.
 *
 *  \var OpcUa_PublishResponse::AvailableSequenceNumbers
 *  A list of sequence number ranges that identify unacknowledged
 *  NotificationMessages that are available for retransmission from the
 *  Subscription’s retransmission queue.
 *
 *  This list is prepared after processing the acknowledgements in the request.
 *
 *  \var OpcUa_PublishResponse::MoreNotifications
 *  A Boolean parameter indicating whether all avalaible notifications could be
 *  included in a single response.
 *
 *  It has the following values:
 *
 *  <dl> <dt>TRUE</dt> <dd>The number of Notifications that were ready to be sent
 *  could not be sent in a single response.</dd> <dt>FALSE</dt> <dd>All
 *  Notifications that were ready are included in the response.</dd> </dl>
 *
 *  \var OpcUa_PublishResponse::NotificationMessage
 *  The NotificationMessage that contains the list of Notifications.
 *
 *  \var OpcUa_PublishResponse::Results
 *  List of results for the acknowledgements.
 *
 *  The size and order of the list matches the size and order of the \ref
 *  OpcUa_PublishRequest::SubscriptionAcknowledgements request parameter.
 *
 *  \var OpcUa_PublishResponse::DiagnosticInfos
 *  List of diagnostic information for the acknowledgements.
 *
 *  The size and order of the list matches the size and order of the \ref
 *  OpcUa_PublishRequest::SubscriptionAcknowledgements request parameter. This list
 *  is empty if diagnostics information was not requested in the request header or
 *  if no diagnostic information was encountered in processing of the request.
 */
typedef struct _OpcUa_PublishResponse
{
    OpcUa_ResponseHeader      ResponseHeader;
    OpcUa_UInt32              SubscriptionId;
    OpcUa_Int32               NoOfAvailableSequenceNumbers;
    OpcUa_UInt32*             AvailableSequenceNumbers;
    OpcUa_Boolean             MoreNotifications;
    OpcUa_NotificationMessage NotificationMessage;
    OpcUa_Int32               NoOfResults;
    OpcUa_StatusCode*         Results;
    OpcUa_Int32               NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo*     DiagnosticInfos;
}
OpcUa_PublishResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_PublishResponse_Initialize(OpcUa_PublishResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_PublishResponse_Clear(OpcUa_PublishResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_PublishResponse_GetSize(OpcUa_PublishResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_PublishResponse_Encode(OpcUa_PublishResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_PublishResponse_Decode(OpcUa_PublishResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_PublishResponse_Compare(const OpcUa_PublishResponse* pValue1, const OpcUa_PublishResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_PublishResponse_Copy(const OpcUa_PublishResponse* pSource, OpcUa_PublishResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_PublishResponse_CopyTo(const OpcUa_PublishResponse* pSource, OpcUa_PublishResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_PublishResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_Publish */

#ifndef OPCUA_EXCLUDE_Republish
#ifndef OPCUA_EXCLUDE_RepublishRequest
/*============================================================================
 * The RepublishRequest structure.
 *===========================================================================*/
/** \struct OpcUa_RepublishRequest
 *  Asynchronous republish call to get lost notifications.
 *
 *  This Service requests the Subscription to republish a NotificationMessage from
 *  its retransmission queue. If the Server does not have the requested message in
 *  its retransmission queue, it returns an error response.
 *
 *  \var OpcUa_RepublishRequest::SubscriptionId
 *  The Server assigned identifier for the Subscription to be republished.
 *
 *  \var OpcUa_RepublishRequest::RetransmitSequenceNumber
 *  The sequence number of a specific NotificationMessage to be republished.
 */
typedef struct _OpcUa_RepublishRequest
{
    OpcUa_RequestHeader RequestHeader;
    OpcUa_UInt32        SubscriptionId;
    OpcUa_UInt32        RetransmitSequenceNumber;
}
OpcUa_RepublishRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_RepublishRequest_Initialize(OpcUa_RepublishRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_RepublishRequest_Clear(OpcUa_RepublishRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RepublishRequest_GetSize(OpcUa_RepublishRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RepublishRequest_Encode(OpcUa_RepublishRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RepublishRequest_Decode(OpcUa_RepublishRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_RepublishRequest_Compare(const OpcUa_RepublishRequest* pValue1, const OpcUa_RepublishRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_RepublishRequest_Copy(const OpcUa_RepublishRequest* pSource, OpcUa_RepublishRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RepublishRequest_CopyTo(const OpcUa_RepublishRequest* pSource, OpcUa_RepublishRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_RepublishRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_Republish */

#ifndef OPCUA_EXCLUDE_Republish
#ifndef OPCUA_EXCLUDE_RepublishResponse
/*============================================================================
 * The RepublishResponse structure.
 *===========================================================================*/
/** \struct OpcUa_RepublishResponse
 *
 * Response to a \ref OpcUa_RepublishRequest.
 *
 *  \var OpcUa_RepublishResponse::NotificationMessage
 *  The requested NotificationMessage.
 */
typedef struct _OpcUa_RepublishResponse
{
    OpcUa_ResponseHeader      ResponseHeader;
    OpcUa_NotificationMessage NotificationMessage;
}
OpcUa_RepublishResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_RepublishResponse_Initialize(OpcUa_RepublishResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_RepublishResponse_Clear(OpcUa_RepublishResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RepublishResponse_GetSize(OpcUa_RepublishResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RepublishResponse_Encode(OpcUa_RepublishResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RepublishResponse_Decode(OpcUa_RepublishResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_RepublishResponse_Compare(const OpcUa_RepublishResponse* pValue1, const OpcUa_RepublishResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_RepublishResponse_Copy(const OpcUa_RepublishResponse* pSource, OpcUa_RepublishResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RepublishResponse_CopyTo(const OpcUa_RepublishResponse* pSource, OpcUa_RepublishResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_RepublishResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_Republish */

#ifndef OPCUA_EXCLUDE_TransferResult
/*============================================================================
 * The TransferResult structure.
 *===========================================================================*/
/** \struct OpcUa_TransferResult
 *  A structure that is defined as the type of the results parameter of the
 *  TransferSubscriptions service.
 *
 *  \var OpcUa_TransferResult::StatusCode
 *  StatusCode for each Subscription to be transferred.
 *
 *  \var OpcUa_TransferResult::AvailableSequenceNumbers
 *  A list of sequence number ranges that identify NotificationMessages that are in
 *  the Subscription’s retransmission queue.
 *
 *  This parameter is null if the transfer of the Subscription failed.
 */
typedef struct _OpcUa_TransferResult
{
    OpcUa_StatusCode StatusCode;
    OpcUa_Int32      NoOfAvailableSequenceNumbers;
    OpcUa_UInt32*    AvailableSequenceNumbers;
}
OpcUa_TransferResult;

OPCUA_EXPORT OpcUa_Void       OpcUa_TransferResult_Initialize(OpcUa_TransferResult* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_TransferResult_Clear(OpcUa_TransferResult* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TransferResult_GetSize(OpcUa_TransferResult* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TransferResult_Encode(OpcUa_TransferResult* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TransferResult_Decode(OpcUa_TransferResult* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_TransferResult_Compare(const OpcUa_TransferResult* pValue1, const OpcUa_TransferResult* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_TransferResult_Copy(const OpcUa_TransferResult* pSource, OpcUa_TransferResult** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TransferResult_CopyTo(const OpcUa_TransferResult* pSource, OpcUa_TransferResult* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_TransferResult_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_TransferSubscriptions
#ifndef OPCUA_EXCLUDE_TransferSubscriptionsRequest
/*============================================================================
 * The TransferSubscriptionsRequest structure.
 *===========================================================================*/
/** \struct OpcUa_TransferSubscriptionsRequest
 *  Asynchronous call to transfer a subscription and its MonitoredItems from one
 *  Session to another.
 *
 *  For example, a Client may need to reopen a Session and then transfer its
 *  Subscriptions to that Session. It may also be used by one Client to take over a
 *  Subscription from another Client by transferring the Subscription to its
 *  Session.
 *
 *  The authenticationToken contained in the request header identifies the Session
 *  to which the Subscription and MonitoredItems shall be transferred. The Server
 *  shall validate that the Client of that Session is operating on behalf of the
 *  same user and that the potentially new Client supports the Profiles that are
 *  necessary for the Subscription. If the Server transfers the Subscription, it
 *  returns the sequence numbers of the NotificationMessages that are available for
 *  retransmission. The Client should acknowledge all messages in this list for
 *  which it will not request retransmission.
 *
 *  If the Server transfers the Subscription to the new Session, the Server shall
 *  issue a StatusChangeNotification notificationMessage with the status code
 *  Good_SubscriptionTransferred to the old Session.
 *
 *  \var OpcUa_TransferSubscriptionsRequest::SubscriptionIds
 *  List of identifiers for the Subscriptions to be transferred to the new Client.
 *
 *  These identifiers are transferred from the primary Client to a backup Client
 *  via external mechanisms.
 *
 *  \var OpcUa_TransferSubscriptionsRequest::SendInitialValues
 *  A boolean parameter indicating whether the first publish response should
 *  contain current values of all monitored items.
 *
 *  It has the following values: <dl> <dt>TRUE</dt> <dd>The first Publish response
 *  after the TransferSubscriptions call shall contain the current values of all
 *  Monitored Items in the Subscription where the Monitoring Mode is set to
 *  Reporting.</dd> <dt>FALSE</dt> <dd>The first Publish response after the
 *  TransferSubscriptions call shall contain only the value changes since the last
 *  Publish response was sent.</dd> </dl>
 *
 *  This parameter only applies to MonitoredItems used for monitoring Attribute
 *  changes.
 */
typedef struct _OpcUa_TransferSubscriptionsRequest
{
    OpcUa_RequestHeader RequestHeader;
    OpcUa_Int32         NoOfSubscriptionIds;
    OpcUa_UInt32*       SubscriptionIds;
    OpcUa_Boolean       SendInitialValues;
}
OpcUa_TransferSubscriptionsRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_TransferSubscriptionsRequest_Initialize(OpcUa_TransferSubscriptionsRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_TransferSubscriptionsRequest_Clear(OpcUa_TransferSubscriptionsRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TransferSubscriptionsRequest_GetSize(OpcUa_TransferSubscriptionsRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TransferSubscriptionsRequest_Encode(OpcUa_TransferSubscriptionsRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TransferSubscriptionsRequest_Decode(OpcUa_TransferSubscriptionsRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_TransferSubscriptionsRequest_Compare(const OpcUa_TransferSubscriptionsRequest* pValue1, const OpcUa_TransferSubscriptionsRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_TransferSubscriptionsRequest_Copy(const OpcUa_TransferSubscriptionsRequest* pSource, OpcUa_TransferSubscriptionsRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TransferSubscriptionsRequest_CopyTo(const OpcUa_TransferSubscriptionsRequest* pSource, OpcUa_TransferSubscriptionsRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_TransferSubscriptionsRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_TransferSubscriptions */

#ifndef OPCUA_EXCLUDE_TransferSubscriptions
#ifndef OPCUA_EXCLUDE_TransferSubscriptionsResponse
/*============================================================================
 * The TransferSubscriptionsResponse structure.
 *===========================================================================*/
/** \struct OpcUa_TransferSubscriptionsResponse
 *
 * Response to a \ref OpcUa_TransferSubscriptionsRequest.
 *
 *  \var OpcUa_TransferSubscriptionsResponse::Results
 *  List of results for the Subscriptions to transfer.
 *
 *  The size and order of the list matches the size and order of the \ref
 *  OpcUa_TransferSubscriptionsRequest::SubscriptionIds request parameter.
 *
 *  \var OpcUa_TransferSubscriptionsResponse::DiagnosticInfos
 *  List of diagnostic information for the Subscriptions to transfer.
 *
 *  The size and order of the list matches the size and order of the \ref
 *  OpcUa_TransferSubscriptionsRequest::SubscriptionIds request parameter. This
 *  list is empty if diagnostics information was not requested in the request
 *  header or if no diagnostic information was encountered in processing of the
 *  request.
 */
typedef struct _OpcUa_TransferSubscriptionsResponse
{
    OpcUa_ResponseHeader  ResponseHeader;
    OpcUa_Int32           NoOfResults;
    OpcUa_TransferResult* Results;
    OpcUa_Int32           NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo* DiagnosticInfos;
}
OpcUa_TransferSubscriptionsResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_TransferSubscriptionsResponse_Initialize(OpcUa_TransferSubscriptionsResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_TransferSubscriptionsResponse_Clear(OpcUa_TransferSubscriptionsResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TransferSubscriptionsResponse_GetSize(OpcUa_TransferSubscriptionsResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TransferSubscriptionsResponse_Encode(OpcUa_TransferSubscriptionsResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TransferSubscriptionsResponse_Decode(OpcUa_TransferSubscriptionsResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_TransferSubscriptionsResponse_Compare(const OpcUa_TransferSubscriptionsResponse* pValue1, const OpcUa_TransferSubscriptionsResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_TransferSubscriptionsResponse_Copy(const OpcUa_TransferSubscriptionsResponse* pSource, OpcUa_TransferSubscriptionsResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TransferSubscriptionsResponse_CopyTo(const OpcUa_TransferSubscriptionsResponse* pSource, OpcUa_TransferSubscriptionsResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_TransferSubscriptionsResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_TransferSubscriptions */

#ifndef OPCUA_EXCLUDE_DeleteSubscriptions
#ifndef OPCUA_EXCLUDE_DeleteSubscriptionsRequest
/*============================================================================
 * The DeleteSubscriptionsRequest structure.
 *===========================================================================*/
/** \struct OpcUa_DeleteSubscriptionsRequest
 *  Asynchronous call to delete one or more Subscriptions that belong to the
 *  Client’s Session.
 *
 *  Successful completion of this Service causes all MonitoredItems that use the
 *  Subscription to be deleted. If this is the last Subscription for the Session,
 *  then all Publish requests still queued for that Session are dequeued and shall
 *  be returned with Bad_NoSubscription.
 *
 *  Subscriptions that were transferred to another Session must be deleted by the
 *  Client that owns the Session.
 *
 *  \var OpcUa_DeleteSubscriptionsRequest::SubscriptionIds
 *  The Server-assigned identifier for the Subscription.
 */
typedef struct _OpcUa_DeleteSubscriptionsRequest
{
    OpcUa_RequestHeader RequestHeader;
    OpcUa_Int32         NoOfSubscriptionIds;
    OpcUa_UInt32*       SubscriptionIds;
}
OpcUa_DeleteSubscriptionsRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteSubscriptionsRequest_Initialize(OpcUa_DeleteSubscriptionsRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteSubscriptionsRequest_Clear(OpcUa_DeleteSubscriptionsRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteSubscriptionsRequest_GetSize(OpcUa_DeleteSubscriptionsRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteSubscriptionsRequest_Encode(OpcUa_DeleteSubscriptionsRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteSubscriptionsRequest_Decode(OpcUa_DeleteSubscriptionsRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_DeleteSubscriptionsRequest_Compare(const OpcUa_DeleteSubscriptionsRequest* pValue1, const OpcUa_DeleteSubscriptionsRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteSubscriptionsRequest_Copy(const OpcUa_DeleteSubscriptionsRequest* pSource, OpcUa_DeleteSubscriptionsRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteSubscriptionsRequest_CopyTo(const OpcUa_DeleteSubscriptionsRequest* pSource, OpcUa_DeleteSubscriptionsRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_DeleteSubscriptionsRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_DeleteSubscriptions */

#ifndef OPCUA_EXCLUDE_DeleteSubscriptions
#ifndef OPCUA_EXCLUDE_DeleteSubscriptionsResponse
/*============================================================================
 * The DeleteSubscriptionsResponse structure.
 *===========================================================================*/
/** \struct OpcUa_DeleteSubscriptionsResponse
 *
 * Response to a \ref OpcUa_DeleteSubscriptionsRequest.
 *
 *  \var OpcUa_DeleteSubscriptionsResponse::Results
 *  List of StatusCodes for the Subscriptions to delete.
 *
 *  The size and order of the list matches the size and order of the
 *  subscriptionIds request parameter.
 *
 *  \var OpcUa_DeleteSubscriptionsResponse::DiagnosticInfos
 *  List of diagnostic information for the Subscriptions to delete.
 *
 *  The size and order of the list matches the size and order of the
 *  subscriptionIds request parameter. This list is empty if diagnostics
 *  information was not requested in the request header or if no diagnostic
 *  information was encountered in processing of the request.
 */
typedef struct _OpcUa_DeleteSubscriptionsResponse
{
    OpcUa_ResponseHeader  ResponseHeader;
    OpcUa_Int32           NoOfResults;
    OpcUa_StatusCode*     Results;
    OpcUa_Int32           NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo* DiagnosticInfos;
}
OpcUa_DeleteSubscriptionsResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteSubscriptionsResponse_Initialize(OpcUa_DeleteSubscriptionsResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_DeleteSubscriptionsResponse_Clear(OpcUa_DeleteSubscriptionsResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteSubscriptionsResponse_GetSize(OpcUa_DeleteSubscriptionsResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteSubscriptionsResponse_Encode(OpcUa_DeleteSubscriptionsResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteSubscriptionsResponse_Decode(OpcUa_DeleteSubscriptionsResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_DeleteSubscriptionsResponse_Compare(const OpcUa_DeleteSubscriptionsResponse* pValue1, const OpcUa_DeleteSubscriptionsResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteSubscriptionsResponse_Copy(const OpcUa_DeleteSubscriptionsResponse* pSource, OpcUa_DeleteSubscriptionsResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DeleteSubscriptionsResponse_CopyTo(const OpcUa_DeleteSubscriptionsResponse* pSource, OpcUa_DeleteSubscriptionsResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_DeleteSubscriptionsResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_DeleteSubscriptions */

#ifndef OPCUA_EXCLUDE_ScalarTestType
/*============================================================================
 * The ScalarTestType structure.
 *===========================================================================*/
/** \struct OpcUa_ScalarTestType
A complex type containing all possible scalar types used for testing.
 */
typedef struct _OpcUa_ScalarTestType
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
    OpcUa_String             String;
    OpcUa_DateTime           DateTime;
    OpcUa_Guid               Guid;
    OpcUa_ByteString         ByteString;
    OpcUa_XmlElement         XmlElement;
    OpcUa_NodeId             NodeId;
    OpcUa_ExpandedNodeId     ExpandedNodeId;
    OpcUa_StatusCode         StatusCode;
    OpcUa_DiagnosticInfo     DiagnosticInfo;
    OpcUa_QualifiedName      QualifiedName;
    OpcUa_LocalizedText      LocalizedText;
    OpcUa_ExtensionObject    ExtensionObject;
    OpcUa_DataValue          DataValue;
    OpcUa_EnumeratedTestType EnumeratedValue;
}
OpcUa_ScalarTestType;

OPCUA_EXPORT OpcUa_Void       OpcUa_ScalarTestType_Initialize(OpcUa_ScalarTestType* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ScalarTestType_Clear(OpcUa_ScalarTestType* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ScalarTestType_GetSize(OpcUa_ScalarTestType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ScalarTestType_Encode(OpcUa_ScalarTestType* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ScalarTestType_Decode(OpcUa_ScalarTestType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ScalarTestType_Compare(const OpcUa_ScalarTestType* pValue1, const OpcUa_ScalarTestType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ScalarTestType_Copy(const OpcUa_ScalarTestType* pSource, OpcUa_ScalarTestType** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ScalarTestType_CopyTo(const OpcUa_ScalarTestType* pSource, OpcUa_ScalarTestType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ScalarTestType_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ArrayTestType
/*============================================================================
 * The ArrayTestType structure.
 *===========================================================================*/
/** \struct OpcUa_ArrayTestType
A complex type containing all possible array types used for testing.
 */
typedef struct _OpcUa_ArrayTestType
{
    OpcUa_Int32               NoOfBooleans;
    OpcUa_Boolean*            Booleans;
    OpcUa_Int32               NoOfSBytes;
    OpcUa_SByte*              SBytes;
    OpcUa_Int32               NoOfInt16s;
    OpcUa_Int16*              Int16s;
    OpcUa_Int32               NoOfUInt16s;
    OpcUa_UInt16*             UInt16s;
    OpcUa_Int32               NoOfInt32s;
    OpcUa_Int32*              Int32s;
    OpcUa_Int32               NoOfUInt32s;
    OpcUa_UInt32*             UInt32s;
    OpcUa_Int32               NoOfInt64s;
    OpcUa_Int64*              Int64s;
    OpcUa_Int32               NoOfUInt64s;
    OpcUa_UInt64*             UInt64s;
    OpcUa_Int32               NoOfFloats;
    OpcUa_Float*              Floats;
    OpcUa_Int32               NoOfDoubles;
    OpcUa_Double*             Doubles;
    OpcUa_Int32               NoOfStrings;
    OpcUa_String*             Strings;
    OpcUa_Int32               NoOfDateTimes;
    OpcUa_DateTime*           DateTimes;
    OpcUa_Int32               NoOfGuids;
    OpcUa_Guid*               Guids;
    OpcUa_Int32               NoOfByteStrings;
    OpcUa_ByteString*         ByteStrings;
    OpcUa_Int32               NoOfXmlElements;
    OpcUa_XmlElement*         XmlElements;
    OpcUa_Int32               NoOfNodeIds;
    OpcUa_NodeId*             NodeIds;
    OpcUa_Int32               NoOfExpandedNodeIds;
    OpcUa_ExpandedNodeId*     ExpandedNodeIds;
    OpcUa_Int32               NoOfStatusCodes;
    OpcUa_StatusCode*         StatusCodes;
    OpcUa_Int32               NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo*     DiagnosticInfos;
    OpcUa_Int32               NoOfQualifiedNames;
    OpcUa_QualifiedName*      QualifiedNames;
    OpcUa_Int32               NoOfLocalizedTexts;
    OpcUa_LocalizedText*      LocalizedTexts;
    OpcUa_Int32               NoOfExtensionObjects;
    OpcUa_ExtensionObject*    ExtensionObjects;
    OpcUa_Int32               NoOfDataValues;
    OpcUa_DataValue*          DataValues;
    OpcUa_Int32               NoOfVariants;
    OpcUa_Variant*            Variants;
    OpcUa_Int32               NoOfEnumeratedValues;
    OpcUa_EnumeratedTestType* EnumeratedValues;
}
OpcUa_ArrayTestType;

OPCUA_EXPORT OpcUa_Void       OpcUa_ArrayTestType_Initialize(OpcUa_ArrayTestType* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ArrayTestType_Clear(OpcUa_ArrayTestType* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ArrayTestType_GetSize(OpcUa_ArrayTestType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ArrayTestType_Encode(OpcUa_ArrayTestType* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ArrayTestType_Decode(OpcUa_ArrayTestType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ArrayTestType_Compare(const OpcUa_ArrayTestType* pValue1, const OpcUa_ArrayTestType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ArrayTestType_Copy(const OpcUa_ArrayTestType* pSource, OpcUa_ArrayTestType** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ArrayTestType_CopyTo(const OpcUa_ArrayTestType* pSource, OpcUa_ArrayTestType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ArrayTestType_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_CompositeTestType
/*============================================================================
 * The CompositeTestType structure.
 *===========================================================================*/
typedef struct _OpcUa_CompositeTestType
{
    OpcUa_ScalarTestType Field1;
    OpcUa_ArrayTestType  Field2;
}
OpcUa_CompositeTestType;

OPCUA_EXPORT OpcUa_Void       OpcUa_CompositeTestType_Initialize(OpcUa_CompositeTestType* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_CompositeTestType_Clear(OpcUa_CompositeTestType* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CompositeTestType_GetSize(OpcUa_CompositeTestType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CompositeTestType_Encode(OpcUa_CompositeTestType* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CompositeTestType_Decode(OpcUa_CompositeTestType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_CompositeTestType_Compare(const OpcUa_CompositeTestType* pValue1, const OpcUa_CompositeTestType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_CompositeTestType_Copy(const OpcUa_CompositeTestType* pSource, OpcUa_CompositeTestType** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_CompositeTestType_CopyTo(const OpcUa_CompositeTestType* pSource, OpcUa_CompositeTestType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_CompositeTestType_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_TestStack
#ifndef OPCUA_EXCLUDE_TestStackRequest
/*============================================================================
 * The TestStackRequest structure.
 *===========================================================================*/
typedef struct _OpcUa_TestStackRequest
{
    OpcUa_RequestHeader RequestHeader;
    OpcUa_UInt32        TestId;
    OpcUa_Int32         Iteration;
    OpcUa_Variant       Input;
}
OpcUa_TestStackRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_TestStackRequest_Initialize(OpcUa_TestStackRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_TestStackRequest_Clear(OpcUa_TestStackRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TestStackRequest_GetSize(OpcUa_TestStackRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TestStackRequest_Encode(OpcUa_TestStackRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TestStackRequest_Decode(OpcUa_TestStackRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_TestStackRequest_Compare(const OpcUa_TestStackRequest* pValue1, const OpcUa_TestStackRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_TestStackRequest_Copy(const OpcUa_TestStackRequest* pSource, OpcUa_TestStackRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TestStackRequest_CopyTo(const OpcUa_TestStackRequest* pSource, OpcUa_TestStackRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_TestStackRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_TestStack */

#ifndef OPCUA_EXCLUDE_TestStack
#ifndef OPCUA_EXCLUDE_TestStackResponse
/*============================================================================
 * The TestStackResponse structure.
 *===========================================================================*/
typedef struct _OpcUa_TestStackResponse
{
    OpcUa_ResponseHeader ResponseHeader;
    OpcUa_Variant        Output;
}
OpcUa_TestStackResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_TestStackResponse_Initialize(OpcUa_TestStackResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_TestStackResponse_Clear(OpcUa_TestStackResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TestStackResponse_GetSize(OpcUa_TestStackResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TestStackResponse_Encode(OpcUa_TestStackResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TestStackResponse_Decode(OpcUa_TestStackResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_TestStackResponse_Compare(const OpcUa_TestStackResponse* pValue1, const OpcUa_TestStackResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_TestStackResponse_Copy(const OpcUa_TestStackResponse* pSource, OpcUa_TestStackResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TestStackResponse_CopyTo(const OpcUa_TestStackResponse* pSource, OpcUa_TestStackResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_TestStackResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_TestStack */

#ifndef OPCUA_EXCLUDE_TestStackEx
#ifndef OPCUA_EXCLUDE_TestStackExRequest
/*============================================================================
 * The TestStackExRequest structure.
 *===========================================================================*/
typedef struct _OpcUa_TestStackExRequest
{
    OpcUa_RequestHeader     RequestHeader;
    OpcUa_UInt32            TestId;
    OpcUa_Int32             Iteration;
    OpcUa_CompositeTestType Input;
}
OpcUa_TestStackExRequest;

OPCUA_EXPORT OpcUa_Void       OpcUa_TestStackExRequest_Initialize(OpcUa_TestStackExRequest* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_TestStackExRequest_Clear(OpcUa_TestStackExRequest* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TestStackExRequest_GetSize(OpcUa_TestStackExRequest* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TestStackExRequest_Encode(OpcUa_TestStackExRequest* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TestStackExRequest_Decode(OpcUa_TestStackExRequest* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_TestStackExRequest_Compare(const OpcUa_TestStackExRequest* pValue1, const OpcUa_TestStackExRequest* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_TestStackExRequest_Copy(const OpcUa_TestStackExRequest* pSource, OpcUa_TestStackExRequest** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TestStackExRequest_CopyTo(const OpcUa_TestStackExRequest* pSource, OpcUa_TestStackExRequest* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_TestStackExRequest_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_TestStackEx */

#ifndef OPCUA_EXCLUDE_TestStackEx
#ifndef OPCUA_EXCLUDE_TestStackExResponse
/*============================================================================
 * The TestStackExResponse structure.
 *===========================================================================*/
typedef struct _OpcUa_TestStackExResponse
{
    OpcUa_ResponseHeader    ResponseHeader;
    OpcUa_CompositeTestType Output;
}
OpcUa_TestStackExResponse;

OPCUA_EXPORT OpcUa_Void       OpcUa_TestStackExResponse_Initialize(OpcUa_TestStackExResponse* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_TestStackExResponse_Clear(OpcUa_TestStackExResponse* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TestStackExResponse_GetSize(OpcUa_TestStackExResponse* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TestStackExResponse_Encode(OpcUa_TestStackExResponse* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TestStackExResponse_Decode(OpcUa_TestStackExResponse* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_TestStackExResponse_Compare(const OpcUa_TestStackExResponse* pValue1, const OpcUa_TestStackExResponse* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_TestStackExResponse_Copy(const OpcUa_TestStackExResponse* pSource, OpcUa_TestStackExResponse** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_TestStackExResponse_CopyTo(const OpcUa_TestStackExResponse* pSource, OpcUa_TestStackExResponse* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_TestStackExResponse_EncodeableType;
#endif
#endif /* OPCUA_EXCLUDE_TestStackEx */

#ifndef OPCUA_EXCLUDE_BuildInfo
/*============================================================================
 * The BuildInfo structure.
 *===========================================================================*/
/** \struct OpcUa_BuildInfo
 *  Contains elements that describe the build information of the Server.
 *
 *  \var OpcUa_BuildInfo::ProductUri
 *  URI that identifies the software.
 *
 *  \var OpcUa_BuildInfo::ManufacturerName
 *  Name of the software manufacturer.
 *
 *  \var OpcUa_BuildInfo::ProductName
 *  Name of the software.
 *
 *  \var OpcUa_BuildInfo::SoftwareVersion
 *  Software version.
 *
 *  \var OpcUa_BuildInfo::BuildNumber
 *  Build number.
 *
 *  \var OpcUa_BuildInfo::BuildDate
 *  Date and time of the build.
 */
typedef struct _OpcUa_BuildInfo
{
    OpcUa_String   ProductUri;
    OpcUa_String   ManufacturerName;
    OpcUa_String   ProductName;
    OpcUa_String   SoftwareVersion;
    OpcUa_String   BuildNumber;
    OpcUa_DateTime BuildDate;
}
OpcUa_BuildInfo;

OPCUA_EXPORT OpcUa_Void       OpcUa_BuildInfo_Initialize(OpcUa_BuildInfo* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_BuildInfo_Clear(OpcUa_BuildInfo* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BuildInfo_GetSize(OpcUa_BuildInfo* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BuildInfo_Encode(OpcUa_BuildInfo* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BuildInfo_Decode(OpcUa_BuildInfo* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_BuildInfo_Compare(const OpcUa_BuildInfo* pValue1, const OpcUa_BuildInfo* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_BuildInfo_Copy(const OpcUa_BuildInfo* pSource, OpcUa_BuildInfo** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_BuildInfo_CopyTo(const OpcUa_BuildInfo* pSource, OpcUa_BuildInfo* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_BuildInfo_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_RedundantServerDataType
/*============================================================================
 * The RedundantServerDataType structure.
 *===========================================================================*/
/** \struct OpcUa_RedundantServerDataType
 *  Contains elements that describe the status of the Server.
 *
 *  \var OpcUa_RedundantServerDataType::ServerId
 *  The Id of the server (not the URI).
 *
 *  \var OpcUa_RedundantServerDataType::ServiceLevel
 *  The service level of the server.
 *
 *  \var OpcUa_RedundantServerDataType::ServerState
 *  The current state of the server.
 */
typedef struct _OpcUa_RedundantServerDataType
{
    OpcUa_String      ServerId;
    OpcUa_Byte        ServiceLevel;
    OpcUa_ServerState ServerState;
}
OpcUa_RedundantServerDataType;

OPCUA_EXPORT OpcUa_Void       OpcUa_RedundantServerDataType_Initialize(OpcUa_RedundantServerDataType* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_RedundantServerDataType_Clear(OpcUa_RedundantServerDataType* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RedundantServerDataType_GetSize(OpcUa_RedundantServerDataType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RedundantServerDataType_Encode(OpcUa_RedundantServerDataType* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RedundantServerDataType_Decode(OpcUa_RedundantServerDataType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_RedundantServerDataType_Compare(const OpcUa_RedundantServerDataType* pValue1, const OpcUa_RedundantServerDataType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_RedundantServerDataType_Copy(const OpcUa_RedundantServerDataType* pSource, OpcUa_RedundantServerDataType** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_RedundantServerDataType_CopyTo(const OpcUa_RedundantServerDataType* pSource, OpcUa_RedundantServerDataType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_RedundantServerDataType_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_EndpointUrlListDataType
/*============================================================================
 * The EndpointUrlListDataType structure.
 *===========================================================================*/
/** \struct OpcUa_EndpointUrlListDataType
 *  Structure representing a list of URLs of an Endpoint.
 *
 *  \var OpcUa_EndpointUrlListDataType::EndpointUrlList
 *  List of URLs of an Endpoint.
 */
typedef struct _OpcUa_EndpointUrlListDataType
{
    OpcUa_Int32   NoOfEndpointUrlList;
    OpcUa_String* EndpointUrlList;
}
OpcUa_EndpointUrlListDataType;

OPCUA_EXPORT OpcUa_Void       OpcUa_EndpointUrlListDataType_Initialize(OpcUa_EndpointUrlListDataType* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_EndpointUrlListDataType_Clear(OpcUa_EndpointUrlListDataType* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EndpointUrlListDataType_GetSize(OpcUa_EndpointUrlListDataType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EndpointUrlListDataType_Encode(OpcUa_EndpointUrlListDataType* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EndpointUrlListDataType_Decode(OpcUa_EndpointUrlListDataType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_EndpointUrlListDataType_Compare(const OpcUa_EndpointUrlListDataType* pValue1, const OpcUa_EndpointUrlListDataType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_EndpointUrlListDataType_Copy(const OpcUa_EndpointUrlListDataType* pSource, OpcUa_EndpointUrlListDataType** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EndpointUrlListDataType_CopyTo(const OpcUa_EndpointUrlListDataType* pSource, OpcUa_EndpointUrlListDataType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_EndpointUrlListDataType_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_NetworkGroupDataType
/*============================================================================
 * The NetworkGroupDataType structure.
 *===========================================================================*/
/** \struct OpcUa_NetworkGroupDataType
 *  Contains information on different network paths for one Server.
 *
 *  \var OpcUa_NetworkGroupDataType::ServerUri
 *  URI of the Server represented by the network group.
 *
 *  \var OpcUa_NetworkGroupDataType::NetworkPaths
 *  Array of different network paths to the server, for example provided by
 *  different network cards in a Server node.
 *
 *  Each network path can have several Endpoints representing different protocol
 *  options for the same path.
 */
typedef struct _OpcUa_NetworkGroupDataType
{
    OpcUa_String                   ServerUri;
    OpcUa_Int32                    NoOfNetworkPaths;
    OpcUa_EndpointUrlListDataType* NetworkPaths;
}
OpcUa_NetworkGroupDataType;

OPCUA_EXPORT OpcUa_Void       OpcUa_NetworkGroupDataType_Initialize(OpcUa_NetworkGroupDataType* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_NetworkGroupDataType_Clear(OpcUa_NetworkGroupDataType* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_NetworkGroupDataType_GetSize(OpcUa_NetworkGroupDataType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_NetworkGroupDataType_Encode(OpcUa_NetworkGroupDataType* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_NetworkGroupDataType_Decode(OpcUa_NetworkGroupDataType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_NetworkGroupDataType_Compare(const OpcUa_NetworkGroupDataType* pValue1, const OpcUa_NetworkGroupDataType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_NetworkGroupDataType_Copy(const OpcUa_NetworkGroupDataType* pSource, OpcUa_NetworkGroupDataType** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_NetworkGroupDataType_CopyTo(const OpcUa_NetworkGroupDataType* pSource, OpcUa_NetworkGroupDataType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_NetworkGroupDataType_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_SamplingIntervalDiagnosticsDataType
/*============================================================================
 * The SamplingIntervalDiagnosticsDataType structure.
 *===========================================================================*/
/** \struct OpcUa_SamplingIntervalDiagnosticsDataType
 *  Contains diagnostic information about the sampling rates currently used by the
 *  Server.
 */
typedef struct _OpcUa_SamplingIntervalDiagnosticsDataType
{
    OpcUa_Double SamplingInterval;
    OpcUa_UInt32 MonitoredItemCount;
    OpcUa_UInt32 MaxMonitoredItemCount;
    OpcUa_UInt32 DisabledMonitoredItemCount;
}
OpcUa_SamplingIntervalDiagnosticsDataType;

OPCUA_EXPORT OpcUa_Void       OpcUa_SamplingIntervalDiagnosticsDataType_Initialize(OpcUa_SamplingIntervalDiagnosticsDataType* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_SamplingIntervalDiagnosticsDataType_Clear(OpcUa_SamplingIntervalDiagnosticsDataType* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SamplingIntervalDiagnosticsDataType_GetSize(OpcUa_SamplingIntervalDiagnosticsDataType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SamplingIntervalDiagnosticsDataType_Encode(OpcUa_SamplingIntervalDiagnosticsDataType* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SamplingIntervalDiagnosticsDataType_Decode(OpcUa_SamplingIntervalDiagnosticsDataType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_SamplingIntervalDiagnosticsDataType_Compare(const OpcUa_SamplingIntervalDiagnosticsDataType* pValue1, const OpcUa_SamplingIntervalDiagnosticsDataType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_SamplingIntervalDiagnosticsDataType_Copy(const OpcUa_SamplingIntervalDiagnosticsDataType* pSource, OpcUa_SamplingIntervalDiagnosticsDataType** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SamplingIntervalDiagnosticsDataType_CopyTo(const OpcUa_SamplingIntervalDiagnosticsDataType* pSource, OpcUa_SamplingIntervalDiagnosticsDataType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_SamplingIntervalDiagnosticsDataType_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ServerDiagnosticsSummaryDataType
/*============================================================================
 * The ServerDiagnosticsSummaryDataType structure.
 *===========================================================================*/
/** \struct OpcUa_ServerDiagnosticsSummaryDataType
 *  Contains diagnostic summary information for the Server.
 *
 *  \var OpcUa_ServerDiagnosticsSummaryDataType::ServerViewCount
 *  The number of server-created views in the server.
 *
 *  \var OpcUa_ServerDiagnosticsSummaryDataType::CurrentSessionCount
 *  The number of client sessions currently established in the server.
 *
 *  \var OpcUa_ServerDiagnosticsSummaryDataType::CumulatedSessionCount
 *  The cumulative number of client sessions that have been established in the
 *  server since the server was started (or restarted).
 *
 *  This includes the currentSessionCount.
 *
 *  \var OpcUa_ServerDiagnosticsSummaryDataType::SecurityRejectedSessionCount
 *  The number of client session establishment requests that were rejected due to
 *  security constraints since the server was started (or restarted).
 *
 *  \var OpcUa_ServerDiagnosticsSummaryDataType::RejectedSessionCount
 *  The number of client session establishment requests that were rejected since
 *  the server was started (or restarted).
 *
 *  This number includes the securityRejectedSessionCount.
 *
 *  \var OpcUa_ServerDiagnosticsSummaryDataType::SessionTimeoutCount
 *  The number of client sessions that were closed due to timeout since the server
 *  was started (or restarted).
 *
 *  \var OpcUa_ServerDiagnosticsSummaryDataType::SessionAbortCount
 *  The number of client sessions that were closed due to errors since the server
 *  was started (or restarted).
 *
 *  \var OpcUa_ServerDiagnosticsSummaryDataType::CurrentSubscriptionCount
 *  The number of subscriptions currently established in the server.
 *
 *  \var OpcUa_ServerDiagnosticsSummaryDataType::CumulatedSubscriptionCount
 *  The cumulative number of subscriptions that have been established in the server
 *  since the server was started (or restarted).
 *
 *  This includes the currentSubscriptionCount.
 *
 *  \var OpcUa_ServerDiagnosticsSummaryDataType::PublishingIntervalCount
 *  The number of publishing intervals currently supported in the server.
 *
 *  \var OpcUa_ServerDiagnosticsSummaryDataType::SecurityRejectedRequestsCount
 *  The number of requests that were rejected due to security constraints since the
 *  server was started (or restarted).
 *
 *  The requests include all Services defined in Part 4 of the OPC UA
 *  Specification, also requests to create sessions.
 *
 *  \var OpcUa_ServerDiagnosticsSummaryDataType::RejectedRequestsCount
 *  The number of requests that were rejected since the server was started (or
 *  restarted).
 *
 *  The requests include all Services defined in Part 4 of the OPC UA
 *  Specification, also requests to create sessions. This number includes the
 *  securityRejectedRequestsCount.
 */
typedef struct _OpcUa_ServerDiagnosticsSummaryDataType
{
    OpcUa_UInt32 ServerViewCount;
    OpcUa_UInt32 CurrentSessionCount;
    OpcUa_UInt32 CumulatedSessionCount;
    OpcUa_UInt32 SecurityRejectedSessionCount;
    OpcUa_UInt32 RejectedSessionCount;
    OpcUa_UInt32 SessionTimeoutCount;
    OpcUa_UInt32 SessionAbortCount;
    OpcUa_UInt32 CurrentSubscriptionCount;
    OpcUa_UInt32 CumulatedSubscriptionCount;
    OpcUa_UInt32 PublishingIntervalCount;
    OpcUa_UInt32 SecurityRejectedRequestsCount;
    OpcUa_UInt32 RejectedRequestsCount;
}
OpcUa_ServerDiagnosticsSummaryDataType;

OPCUA_EXPORT OpcUa_Void       OpcUa_ServerDiagnosticsSummaryDataType_Initialize(OpcUa_ServerDiagnosticsSummaryDataType* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ServerDiagnosticsSummaryDataType_Clear(OpcUa_ServerDiagnosticsSummaryDataType* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ServerDiagnosticsSummaryDataType_GetSize(OpcUa_ServerDiagnosticsSummaryDataType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ServerDiagnosticsSummaryDataType_Encode(OpcUa_ServerDiagnosticsSummaryDataType* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ServerDiagnosticsSummaryDataType_Decode(OpcUa_ServerDiagnosticsSummaryDataType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ServerDiagnosticsSummaryDataType_Compare(const OpcUa_ServerDiagnosticsSummaryDataType* pValue1, const OpcUa_ServerDiagnosticsSummaryDataType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ServerDiagnosticsSummaryDataType_Copy(const OpcUa_ServerDiagnosticsSummaryDataType* pSource, OpcUa_ServerDiagnosticsSummaryDataType** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ServerDiagnosticsSummaryDataType_CopyTo(const OpcUa_ServerDiagnosticsSummaryDataType* pSource, OpcUa_ServerDiagnosticsSummaryDataType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ServerDiagnosticsSummaryDataType_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ServerStatusDataType
/*============================================================================
 * The ServerStatusDataType structure.
 *===========================================================================*/
/** \struct OpcUa_ServerStatusDataType
 *  Contains elements that describe the status of the Server.
 *
 *  \var OpcUa_ServerStatusDataType::StartTime
 *  Time (UTC) the server was started.
 *
 *  This is constant for the server instance and is not reset when the server
 *  changes state. Each instance of a server should keep the time when the process
 *  started.
 *
 *  \var OpcUa_ServerStatusDataType::CurrentTime
 *  The current time (UTC) as known by the server.
 *
 *  \var OpcUa_ServerStatusDataType::State
 *  The current state of the server.
 *
 *  \var OpcUa_ServerStatusDataType::BuildInfo
 *  Build information of the server.
 *
 *  \var OpcUa_ServerStatusDataType::SecondsTillShutdown
 *  Approximate number of seconds until the server will be shut down.
 *
 *  The value is only relevant once the state changes into SHUTDOWN.
 *
 *  \var OpcUa_ServerStatusDataType::ShutdownReason
 *  An optional localized text indicating the reason for the shutdown.
 *
 *  The value is only relevant once the state changes into SHUTDOWN.
 */
typedef struct _OpcUa_ServerStatusDataType
{
    OpcUa_DateTime      StartTime;
    OpcUa_DateTime      CurrentTime;
    OpcUa_ServerState   State;
    OpcUa_BuildInfo     BuildInfo;
    OpcUa_UInt32        SecondsTillShutdown;
    OpcUa_LocalizedText ShutdownReason;
}
OpcUa_ServerStatusDataType;

OPCUA_EXPORT OpcUa_Void       OpcUa_ServerStatusDataType_Initialize(OpcUa_ServerStatusDataType* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ServerStatusDataType_Clear(OpcUa_ServerStatusDataType* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ServerStatusDataType_GetSize(OpcUa_ServerStatusDataType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ServerStatusDataType_Encode(OpcUa_ServerStatusDataType* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ServerStatusDataType_Decode(OpcUa_ServerStatusDataType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ServerStatusDataType_Compare(const OpcUa_ServerStatusDataType* pValue1, const OpcUa_ServerStatusDataType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ServerStatusDataType_Copy(const OpcUa_ServerStatusDataType* pSource, OpcUa_ServerStatusDataType** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ServerStatusDataType_CopyTo(const OpcUa_ServerStatusDataType* pSource, OpcUa_ServerStatusDataType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ServerStatusDataType_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_SessionSecurityDiagnosticsDataType
/*============================================================================
 * The SessionSecurityDiagnosticsDataType structure.
 *===========================================================================*/
/** \struct OpcUa_SessionSecurityDiagnosticsDataType
 *  contains security-related diagnostic information about client sessions.
 *
 *  Because this information is security-related, it should not be made accessible
 *  to all users, but only to authorised users.
 *
 *  \var OpcUa_SessionSecurityDiagnosticsDataType::SessionId
 *  Server-assigned identifier of the session.
 *
 *  \var OpcUa_SessionSecurityDiagnosticsDataType::ClientUserIdOfSession
 *  Name of authenticated user when creating the session.
 *
 *  \var OpcUa_SessionSecurityDiagnosticsDataType::ClientUserIdHistory
 *  Array containing the name of the authenticated user currently active (either
 *  from creating the session or from calling the ActivateSession Service) and the
 *  history of those names.
 *
 *  Each time the active user changes, an entry shall be made at the end of the
 *  array. The active user is always at the end of the array. Servers may restrict
 *  the size of this array, but shall support at least a size of 2.
 *
 *  \var OpcUa_SessionSecurityDiagnosticsDataType::AuthenticationMechanism
 *  Type of authentication currently used by the session. The string shall be one
 *  of the UserIdentityTokenType enum.
 *
 *  \var OpcUa_SessionSecurityDiagnosticsDataType::Encoding
 *  Which encoding is used on the wire.
 *
 *  The string shall be “XML” or “UA Binary”.
 *
 *  \var OpcUa_SessionSecurityDiagnosticsDataType::TransportProtocol
 *  Which transport protocol is used.
 *
 *  The string shall be the scheme from the URL used to establish the session, for
 *  example “opc.tcp” or “https”.
 *
 *  \var OpcUa_SessionSecurityDiagnosticsDataType::SecurityMode
 *  The message security mode used for the session.
 *
 *  \var OpcUa_SessionSecurityDiagnosticsDataType::SecurityPolicyUri
 *  The name of the security policy used for the session.
 *
 *  \var OpcUa_SessionSecurityDiagnosticsDataType::ClientCertificate
 *  The application instance certificate provided by the client in the
 *  CreateSession request.
 */
typedef struct _OpcUa_SessionSecurityDiagnosticsDataType
{
    OpcUa_NodeId              SessionId;
    OpcUa_String              ClientUserIdOfSession;
    OpcUa_Int32               NoOfClientUserIdHistory;
    OpcUa_String*             ClientUserIdHistory;
    OpcUa_String              AuthenticationMechanism;
    OpcUa_String              Encoding;
    OpcUa_String              TransportProtocol;
    OpcUa_MessageSecurityMode SecurityMode;
    OpcUa_String              SecurityPolicyUri;
    OpcUa_ByteString          ClientCertificate;
}
OpcUa_SessionSecurityDiagnosticsDataType;

OPCUA_EXPORT OpcUa_Void       OpcUa_SessionSecurityDiagnosticsDataType_Initialize(OpcUa_SessionSecurityDiagnosticsDataType* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_SessionSecurityDiagnosticsDataType_Clear(OpcUa_SessionSecurityDiagnosticsDataType* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SessionSecurityDiagnosticsDataType_GetSize(OpcUa_SessionSecurityDiagnosticsDataType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SessionSecurityDiagnosticsDataType_Encode(OpcUa_SessionSecurityDiagnosticsDataType* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SessionSecurityDiagnosticsDataType_Decode(OpcUa_SessionSecurityDiagnosticsDataType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_SessionSecurityDiagnosticsDataType_Compare(const OpcUa_SessionSecurityDiagnosticsDataType* pValue1, const OpcUa_SessionSecurityDiagnosticsDataType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_SessionSecurityDiagnosticsDataType_Copy(const OpcUa_SessionSecurityDiagnosticsDataType* pSource, OpcUa_SessionSecurityDiagnosticsDataType** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SessionSecurityDiagnosticsDataType_CopyTo(const OpcUa_SessionSecurityDiagnosticsDataType* pSource, OpcUa_SessionSecurityDiagnosticsDataType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_SessionSecurityDiagnosticsDataType_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ServiceCounterDataType
/*============================================================================
 * The ServiceCounterDataType structure.
 *===========================================================================*/
/** \struct OpcUa_ServiceCounterDataType
 *  Contains diagnostic information about subscriptions.
 *
 *  \var OpcUa_ServiceCounterDataType::TotalCount
 *  The number of Service requests that have been received.
 *
 *  \var OpcUa_ServiceCounterDataType::ErrorCount
 *  The total number of Service requests that were rejected.
 */
typedef struct _OpcUa_ServiceCounterDataType
{
    OpcUa_UInt32 TotalCount;
    OpcUa_UInt32 ErrorCount;
}
OpcUa_ServiceCounterDataType;

OPCUA_EXPORT OpcUa_Void       OpcUa_ServiceCounterDataType_Initialize(OpcUa_ServiceCounterDataType* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ServiceCounterDataType_Clear(OpcUa_ServiceCounterDataType* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ServiceCounterDataType_GetSize(OpcUa_ServiceCounterDataType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ServiceCounterDataType_Encode(OpcUa_ServiceCounterDataType* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ServiceCounterDataType_Decode(OpcUa_ServiceCounterDataType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ServiceCounterDataType_Compare(const OpcUa_ServiceCounterDataType* pValue1, const OpcUa_ServiceCounterDataType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ServiceCounterDataType_Copy(const OpcUa_ServiceCounterDataType* pSource, OpcUa_ServiceCounterDataType** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ServiceCounterDataType_CopyTo(const OpcUa_ServiceCounterDataType* pSource, OpcUa_ServiceCounterDataType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ServiceCounterDataType_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_StatusResult
/*============================================================================
 * The StatusResult structure.
 *===========================================================================*/
typedef struct _OpcUa_StatusResult
{
    OpcUa_StatusCode     StatusCode;
    OpcUa_DiagnosticInfo DiagnosticInfo;
}
OpcUa_StatusResult;

OPCUA_EXPORT OpcUa_Void       OpcUa_StatusResult_Initialize(OpcUa_StatusResult* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_StatusResult_Clear(OpcUa_StatusResult* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_StatusResult_GetSize(OpcUa_StatusResult* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_StatusResult_Encode(OpcUa_StatusResult* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_StatusResult_Decode(OpcUa_StatusResult* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_StatusResult_Compare(const OpcUa_StatusResult* pValue1, const OpcUa_StatusResult* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_StatusResult_Copy(const OpcUa_StatusResult* pSource, OpcUa_StatusResult** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_StatusResult_CopyTo(const OpcUa_StatusResult* pSource, OpcUa_StatusResult* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_StatusResult_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_SubscriptionDiagnosticsDataType
/*============================================================================
 * The SubscriptionDiagnosticsDataType structure.
 *===========================================================================*/
/** \struct OpcUa_SubscriptionDiagnosticsDataType
 *  Contains diagnostic information about subscriptions.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::SessionId
 *  Server-assigned identifier of the session the subscription belongs to.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::SubscriptionId
 *  Server-assigned identifier of the subscription.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::Priority
 *  The priority the client assigned to the subscription.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::PublishingInterval
 *  The publishing interval of the subscription in milliseconds.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::MaxKeepAliveCount
 *  The maximum keep-alive count of the subscription.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::MaxLifetimeCount
 *  The maximum lifetime count of the subscription.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::MaxNotificationsPerPublish
 *  The maximum number of notifications per publish response.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::PublishingEnabled
 *  Whether publishing is enabled for the subscription.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::ModifyCount
 *  The number of ModifySubscription requests received for the subscription.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::EnableCount
 *  The number of times the subscription has been enabled.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::DisableCount
 *  The number of times the subscription has been disabled.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::RepublishRequestCount
 *  The number of Republish Service requests that have been received and processed
 *  for the subscription.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::RepublishMessageRequestCount
 *  The total number of messages that have been requested to be republished for the
 *  subscription.
 *
 *  Note that due to the design of the Republish Service this number is always
 *  equal to the republishRequestCount.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::RepublishMessageCount
 *  The number of messages that have been successfully republished for the
 *  subscription.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::TransferRequestCount
 *  The total number of TransferSubscriptions Service requests that have been
 *  received for the subscription.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::TransferredToAltClientCount
 *  The number of times the subscription has been transferred to an alternate
 *  client.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::TransferredToSameClientCount
 *  The number of times the subscription has been transferred to an alternate
 *  session for the same client.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::PublishRequestCount
 *  The number of Publish Service requests that have been received and processed
 *  for the subscription.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::DataChangeNotificationsCount
 *  The number of data change Notifications sent by the subscription.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::EventNotificationsCount
 *  The number of Event Notifications sent by the subscription.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::NotificationsCount
 *  The total number of Notifications sent by the subscription.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::LatePublishRequestCount
 *  The number of times the subscription has entered the LATE State, i.e. the
 *  number of times the publish timer expires and there are unsent notifications.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::CurrentKeepAliveCount
 *  The number of times the subscription has entered the KEEPALIVE State.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::CurrentLifetimeCount
 *  The current lifetime count of the subscription.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::UnacknowledgedMessageCount
 *  The number of unacknowledged messages saved in the republish queue.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::DiscardedMessageCount
 *  The number of messages that were discarded before they were acknowledged.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::MonitoredItemCount
 *  The total number of monitored items of the subscription, including the disabled
 *  monitored items.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::DisabledMonitoredItemCount
 *  The number of disabled monitored items of the subscription.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::MonitoringQueueOverflowCount
 *  The number of times a monitored item dropped notifications because of a queue
 *  overflow.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::NextSequenceNumber
 *  Sequence number for the next notification message.
 *
 *  \var OpcUa_SubscriptionDiagnosticsDataType::EventQueueOverFlowCount
 *  The number of times a monitored item in the subscription has generated an Event
 *  of type EventQueueOverflowEventType.
 */
typedef struct _OpcUa_SubscriptionDiagnosticsDataType
{
    OpcUa_NodeId  SessionId;
    OpcUa_UInt32  SubscriptionId;
    OpcUa_Byte    Priority;
    OpcUa_Double  PublishingInterval;
    OpcUa_UInt32  MaxKeepAliveCount;
    OpcUa_UInt32  MaxLifetimeCount;
    OpcUa_UInt32  MaxNotificationsPerPublish;
    OpcUa_Boolean PublishingEnabled;
    OpcUa_UInt32  ModifyCount;
    OpcUa_UInt32  EnableCount;
    OpcUa_UInt32  DisableCount;
    OpcUa_UInt32  RepublishRequestCount;
    OpcUa_UInt32  RepublishMessageRequestCount;
    OpcUa_UInt32  RepublishMessageCount;
    OpcUa_UInt32  TransferRequestCount;
    OpcUa_UInt32  TransferredToAltClientCount;
    OpcUa_UInt32  TransferredToSameClientCount;
    OpcUa_UInt32  PublishRequestCount;
    OpcUa_UInt32  DataChangeNotificationsCount;
    OpcUa_UInt32  EventNotificationsCount;
    OpcUa_UInt32  NotificationsCount;
    OpcUa_UInt32  LatePublishRequestCount;
    OpcUa_UInt32  CurrentKeepAliveCount;
    OpcUa_UInt32  CurrentLifetimeCount;
    OpcUa_UInt32  UnacknowledgedMessageCount;
    OpcUa_UInt32  DiscardedMessageCount;
    OpcUa_UInt32  MonitoredItemCount;
    OpcUa_UInt32  DisabledMonitoredItemCount;
    OpcUa_UInt32  MonitoringQueueOverflowCount;
    OpcUa_UInt32  NextSequenceNumber;
    OpcUa_UInt32  EventQueueOverFlowCount;
}
OpcUa_SubscriptionDiagnosticsDataType;

OPCUA_EXPORT OpcUa_Void       OpcUa_SubscriptionDiagnosticsDataType_Initialize(OpcUa_SubscriptionDiagnosticsDataType* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_SubscriptionDiagnosticsDataType_Clear(OpcUa_SubscriptionDiagnosticsDataType* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SubscriptionDiagnosticsDataType_GetSize(OpcUa_SubscriptionDiagnosticsDataType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SubscriptionDiagnosticsDataType_Encode(OpcUa_SubscriptionDiagnosticsDataType* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SubscriptionDiagnosticsDataType_Decode(OpcUa_SubscriptionDiagnosticsDataType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_SubscriptionDiagnosticsDataType_Compare(const OpcUa_SubscriptionDiagnosticsDataType* pValue1, const OpcUa_SubscriptionDiagnosticsDataType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_SubscriptionDiagnosticsDataType_Copy(const OpcUa_SubscriptionDiagnosticsDataType* pSource, OpcUa_SubscriptionDiagnosticsDataType** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SubscriptionDiagnosticsDataType_CopyTo(const OpcUa_SubscriptionDiagnosticsDataType* pSource, OpcUa_SubscriptionDiagnosticsDataType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_SubscriptionDiagnosticsDataType_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ModelChangeStructureDataType
/*============================================================================
 * The ModelChangeStructureDataType structure.
 *===========================================================================*/
/** \struct OpcUa_ModelChangeStructureDataType
 *  Contains elements that describe changes of the model.
 *
 *  \var OpcUa_ModelChangeStructureDataType::Affected
 *  NodeId of the Node that was changed.
 *
 *  The client should assume that the affected Node has been created or deleted,
 *  had a Reference added or deleted, or the DataType has changed as described by
 *  the verb.
 *
 *  \var OpcUa_ModelChangeStructureDataType::AffectedType
 *  If the affected Node was an object or Variable, affectedType contains the
 *  NodeId of the TypeDefinitionNode of the affected Node. Otherwise it is set to
 *  null.
 *
 *  \var OpcUa_ModelChangeStructureDataType::Verb
 *  Describes the changes happening to the affected Node.
 *
 *  The verb is an 8-bit unsigned integer used as bit mask with the structure
 *  defined in the following table:
 *
 *  Field             | Bit | Description
 *  ------------------|-----|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *  NodeAdded         | 0   | Indicates the affected Node has been added.
 *  NodeDeleted       | 1   | Indicates the affected Node has been deleted.
 *  ReferenceAdded    | 2   | Indicates a Reference has been added. The affected Node may be either a SourceNode or TargetNode. Note that an added bidirectional Reference is reflected by two ChangeStructures.
 *  ReferenceDeleted  | 3   | Indicates a Reference has been deleted. The affected Node may be either a SourceNode or TargetNode. Note that a deleted bidirectional Reference is reflected by two ChangeStructures.
 *  DataTypeChanged   | 4   | This verb may be used only for affected Nodes that are Variables or VariableTypes. It indicates that the DataType Attribute has changed.
 *  Reserved          | 5:7 | Reserved for future use. Shall always be zero.
 *
 *  A verb may identify several changes on the affected Node at once. This feature
 *  should be used if event compression is used.
 *
 *  Note that all verbs shall always be considered in the context where the
 *  ModelChangeStructureDataType is used. A NodeDeleted may indicate that a Node
 *  was removed from a view but still exists in other Views.
 */
typedef struct _OpcUa_ModelChangeStructureDataType
{
    OpcUa_NodeId Affected;
    OpcUa_NodeId AffectedType;
    OpcUa_Byte   Verb;
}
OpcUa_ModelChangeStructureDataType;

OPCUA_EXPORT OpcUa_Void       OpcUa_ModelChangeStructureDataType_Initialize(OpcUa_ModelChangeStructureDataType* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ModelChangeStructureDataType_Clear(OpcUa_ModelChangeStructureDataType* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModelChangeStructureDataType_GetSize(OpcUa_ModelChangeStructureDataType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModelChangeStructureDataType_Encode(OpcUa_ModelChangeStructureDataType* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModelChangeStructureDataType_Decode(OpcUa_ModelChangeStructureDataType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ModelChangeStructureDataType_Compare(const OpcUa_ModelChangeStructureDataType* pValue1, const OpcUa_ModelChangeStructureDataType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModelChangeStructureDataType_Copy(const OpcUa_ModelChangeStructureDataType* pSource, OpcUa_ModelChangeStructureDataType** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ModelChangeStructureDataType_CopyTo(const OpcUa_ModelChangeStructureDataType* pSource, OpcUa_ModelChangeStructureDataType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ModelChangeStructureDataType_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_SemanticChangeStructureDataType
/*============================================================================
 * The SemanticChangeStructureDataType structure.
 *===========================================================================*/
/** \struct OpcUa_SemanticChangeStructureDataType
 *  Contains elements that describe a change of the model.
 *
 *  \var OpcUa_SemanticChangeStructureDataType::Affected
 *  NodeId of the Node that owns the Property that has changed.
 *
 *  \var OpcUa_SemanticChangeStructureDataType::AffectedType
 *  If the affected Node was an object or Variable, affectedType contains the
 *  NodeId of the TypeDefinitionNode of the affected Node.
 *
 *  Otherwise it is set to null.
 */
typedef struct _OpcUa_SemanticChangeStructureDataType
{
    OpcUa_NodeId Affected;
    OpcUa_NodeId AffectedType;
}
OpcUa_SemanticChangeStructureDataType;

OPCUA_EXPORT OpcUa_Void       OpcUa_SemanticChangeStructureDataType_Initialize(OpcUa_SemanticChangeStructureDataType* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_SemanticChangeStructureDataType_Clear(OpcUa_SemanticChangeStructureDataType* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SemanticChangeStructureDataType_GetSize(OpcUa_SemanticChangeStructureDataType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SemanticChangeStructureDataType_Encode(OpcUa_SemanticChangeStructureDataType* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SemanticChangeStructureDataType_Decode(OpcUa_SemanticChangeStructureDataType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_SemanticChangeStructureDataType_Compare(const OpcUa_SemanticChangeStructureDataType* pValue1, const OpcUa_SemanticChangeStructureDataType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_SemanticChangeStructureDataType_Copy(const OpcUa_SemanticChangeStructureDataType* pSource, OpcUa_SemanticChangeStructureDataType** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SemanticChangeStructureDataType_CopyTo(const OpcUa_SemanticChangeStructureDataType* pSource, OpcUa_SemanticChangeStructureDataType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_SemanticChangeStructureDataType_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_Range
/*============================================================================
 * The Range structure.
 *===========================================================================*/
/** \struct OpcUa_Range
 *  Defines the Range for a value.
 *
 *  \var OpcUa_Range::Low
 *  Lowest value in the range.
 *
 *  \var OpcUa_Range::High
 *  Highest value in the range.
 */
typedef struct _OpcUa_Range
{
    OpcUa_Double Low;
    OpcUa_Double High;
}
OpcUa_Range;

OPCUA_EXPORT OpcUa_Void       OpcUa_Range_Initialize(OpcUa_Range* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_Range_Clear(OpcUa_Range* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_Range_GetSize(OpcUa_Range* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_Range_Encode(OpcUa_Range* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_Range_Decode(OpcUa_Range* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_Range_Compare(const OpcUa_Range* pValue1, const OpcUa_Range* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Range_Copy(const OpcUa_Range* pSource, OpcUa_Range** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_Range_CopyTo(const OpcUa_Range* pSource, OpcUa_Range* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_Range_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_EUInformation
/*============================================================================
 * The EUInformation structure.
 *===========================================================================*/
/** \struct OpcUa_EUInformation
 *  Contains information about the EngineeringUnits.
 *
 *  Understanding the units of a measurement value is essential for a uniform
 *  system. In an open system in particular where servers from different cultures
 *  might be used, it is essential to know what the units of measurement are. Based
 *  on such knowledge, values can be converted if necessary before being used.
 *  Therefore, although defined as optional, support of the EngineeringUnits
 *  Property is strongly advised.
 *
 *  To facilitate interoperability, OPC UA specifies how to apply the widely
 *  accepted “Codes for Units of Measurement (Recommendation No. 20)” published by
 *  the “United Nations Centre for Trade Facilitation and Electronic Business” (see
 *  UN/CEFACT). It uses and is based on the International System of Units (SI
 *  Units) but in addition provides a fixed code that can be used for automated
 *  evaluation. This recommendation has been accepted by many industries on a
 *  global basis.
 *
 *  \var OpcUa_EUInformation::NamespaceUri
 *  Identifies the organization (company, standards organization) that defines the
 *  EUInformation.
 *
 *  \var OpcUa_EUInformation::UnitId
 *  Identifier for programmatic evaluation.
 *
 *  −1 is used if a unitId is not available.
 *
 *  \var OpcUa_EUInformation::DisplayName
 *  The displayName of the engineering unit.
 *
 *  This is typically the abbreviation of the engineering unit, for example ”h” for
 *  hour or ”m/s” for meter per second.
 *
 *  \var OpcUa_EUInformation::Description
 *  Contains the full name of the engineering unit such as ”hour” or ”meter per
 *  second”.
 */
typedef struct _OpcUa_EUInformation
{
    OpcUa_String        NamespaceUri;
    OpcUa_Int32         UnitId;
    OpcUa_LocalizedText DisplayName;
    OpcUa_LocalizedText Description;
}
OpcUa_EUInformation;

OPCUA_EXPORT OpcUa_Void       OpcUa_EUInformation_Initialize(OpcUa_EUInformation* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_EUInformation_Clear(OpcUa_EUInformation* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EUInformation_GetSize(OpcUa_EUInformation* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EUInformation_Encode(OpcUa_EUInformation* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EUInformation_Decode(OpcUa_EUInformation* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_EUInformation_Compare(const OpcUa_EUInformation* pValue1, const OpcUa_EUInformation* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_EUInformation_Copy(const OpcUa_EUInformation* pSource, OpcUa_EUInformation** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EUInformation_CopyTo(const OpcUa_EUInformation* pSource, OpcUa_EUInformation* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_EUInformation_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ComplexNumberType
/*============================================================================
 * The ComplexNumberType structure.
 *===========================================================================*/
typedef struct _OpcUa_ComplexNumberType
{
    OpcUa_Float Real;
    OpcUa_Float Imaginary;
}
OpcUa_ComplexNumberType;

OPCUA_EXPORT OpcUa_Void       OpcUa_ComplexNumberType_Initialize(OpcUa_ComplexNumberType* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ComplexNumberType_Clear(OpcUa_ComplexNumberType* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ComplexNumberType_GetSize(OpcUa_ComplexNumberType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ComplexNumberType_Encode(OpcUa_ComplexNumberType* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ComplexNumberType_Decode(OpcUa_ComplexNumberType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ComplexNumberType_Compare(const OpcUa_ComplexNumberType* pValue1, const OpcUa_ComplexNumberType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ComplexNumberType_Copy(const OpcUa_ComplexNumberType* pSource, OpcUa_ComplexNumberType** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ComplexNumberType_CopyTo(const OpcUa_ComplexNumberType* pSource, OpcUa_ComplexNumberType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ComplexNumberType_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_DoubleComplexNumberType
/*============================================================================
 * The DoubleComplexNumberType structure.
 *===========================================================================*/
typedef struct _OpcUa_DoubleComplexNumberType
{
    OpcUa_Double Real;
    OpcUa_Double Imaginary;
}
OpcUa_DoubleComplexNumberType;

OPCUA_EXPORT OpcUa_Void       OpcUa_DoubleComplexNumberType_Initialize(OpcUa_DoubleComplexNumberType* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_DoubleComplexNumberType_Clear(OpcUa_DoubleComplexNumberType* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DoubleComplexNumberType_GetSize(OpcUa_DoubleComplexNumberType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DoubleComplexNumberType_Encode(OpcUa_DoubleComplexNumberType* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DoubleComplexNumberType_Decode(OpcUa_DoubleComplexNumberType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_DoubleComplexNumberType_Compare(const OpcUa_DoubleComplexNumberType* pValue1, const OpcUa_DoubleComplexNumberType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_DoubleComplexNumberType_Copy(const OpcUa_DoubleComplexNumberType* pSource, OpcUa_DoubleComplexNumberType** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DoubleComplexNumberType_CopyTo(const OpcUa_DoubleComplexNumberType* pSource, OpcUa_DoubleComplexNumberType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_DoubleComplexNumberType_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_AxisInformation
/*============================================================================
 * The AxisInformation structure.
 *===========================================================================*/
/** \struct OpcUa_AxisInformation
 *  Defines the information for auxiliary axis for ArrayItemType Variables.
 *
 *  There are three typical uses of this structure:
 *
 *  1. The step between points is constant and can be predicted using the range
 *  information and the number of points. In this case, axisSteps can be set to
 *  NULL.
 *
 *  2. The step between points is not constant, but remains the same for a long
 *  period of time (from acquisition to acquisition for example). In this case,
 *  axisSteps contains the value of each step on the axis.
 *
 *  3. The step between points is not constant and changes at every update. In this
 *  case, a type like XYArrayType shall be used and axisSteps is set to NULL.
 *
 *  When the steps in the axis are constant, axisSteps may be set to “Null” and in
 *  this case, the Range limits are used to compute the steps. The number of steps
 *  in the axis comes from the parent ArrayItem.ArrayDimensions.
 *
 *  \var OpcUa_AxisInformation::EngineeringUnits
 *  Holds the information about the engineering units for a given axis.
 *
 *  \var OpcUa_AxisInformation::EURange
 *  Limits of the range of the axis
 *
 *  \var OpcUa_AxisInformation::Title
 *  User readable axis title.
 *
 *  This is useful when the units are \%. The Title may be e.g. “Particle size
 *  distribution”
 *
 *  \var OpcUa_AxisInformation::AxisScaleType
 *  LINEAR, LOG, LN, defined by AxisSteps (see \ref OpcUa_AxisScaleEnumeration).
 *
 *  \var OpcUa_AxisInformation::AxisSteps
 *  Specific value of each axis step.
 *
 *  May be set to “Null” if not used.
 */
typedef struct _OpcUa_AxisInformation
{
    OpcUa_EUInformation        EngineeringUnits;
    OpcUa_Range                EURange;
    OpcUa_LocalizedText        Title;
    OpcUa_AxisScaleEnumeration AxisScaleType;
    OpcUa_Int32                NoOfAxisSteps;
    OpcUa_Double*              AxisSteps;
}
OpcUa_AxisInformation;

OPCUA_EXPORT OpcUa_Void       OpcUa_AxisInformation_Initialize(OpcUa_AxisInformation* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_AxisInformation_Clear(OpcUa_AxisInformation* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AxisInformation_GetSize(OpcUa_AxisInformation* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AxisInformation_Encode(OpcUa_AxisInformation* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AxisInformation_Decode(OpcUa_AxisInformation* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_AxisInformation_Compare(const OpcUa_AxisInformation* pValue1, const OpcUa_AxisInformation* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_AxisInformation_Copy(const OpcUa_AxisInformation* pSource, OpcUa_AxisInformation** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_AxisInformation_CopyTo(const OpcUa_AxisInformation* pSource, OpcUa_AxisInformation* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_AxisInformation_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_XVType
/*============================================================================
 * The XVType structure.
 *===========================================================================*/
/** \struct OpcUa_XVType
 *  Defines a physical value relative to a X axis and it is used as the DataType of
 *  the Value of XYArrayItemType.
 *
 *  Most analysers can produce values that can perfectly be represented with a
 *  float IEEE 32 bits, but they can position them on the X axis with an accuracy
 *  that requires double IEEE 64 bits. For example, the peak value in an absorbance
 *  spectrum where the amplitude of the peak can be represented by a float IEEE 32
 *  bits, but its frequency position required 10 digits which implies the use of a
 *  double IEEE 64 bits.
 *
 *  \var OpcUa_XVType::X
 *  Position on the X axis of this value.
 *
 *  \var OpcUa_XVType::Value
 *  The value itself.
 */
typedef struct _OpcUa_XVType
{
    OpcUa_Double X;
    OpcUa_Float  Value;
}
OpcUa_XVType;

OPCUA_EXPORT OpcUa_Void       OpcUa_XVType_Initialize(OpcUa_XVType* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_XVType_Clear(OpcUa_XVType* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_XVType_GetSize(OpcUa_XVType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_XVType_Encode(OpcUa_XVType* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_XVType_Decode(OpcUa_XVType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_XVType_Compare(const OpcUa_XVType* pValue1, const OpcUa_XVType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_XVType_Copy(const OpcUa_XVType* pSource, OpcUa_XVType** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_XVType_CopyTo(const OpcUa_XVType* pSource, OpcUa_XVType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_XVType_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ProgramDiagnosticDataType
/*============================================================================
 * The ProgramDiagnosticDataType structure.
 *===========================================================================*/
typedef struct _OpcUa_ProgramDiagnosticDataType
{
    OpcUa_NodeId       CreateSessionId;
    OpcUa_String       CreateClientName;
    OpcUa_DateTime     InvocationCreationTime;
    OpcUa_DateTime     LastTransitionTime;
    OpcUa_String       LastMethodCall;
    OpcUa_NodeId       LastMethodSessionId;
    OpcUa_Int32        NoOfLastMethodInputArguments;
    OpcUa_Argument*    LastMethodInputArguments;
    OpcUa_Int32        NoOfLastMethodOutputArguments;
    OpcUa_Argument*    LastMethodOutputArguments;
    OpcUa_DateTime     LastMethodCallTime;
    OpcUa_StatusResult LastMethodReturnStatus;
}
OpcUa_ProgramDiagnosticDataType;

OPCUA_EXPORT OpcUa_Void       OpcUa_ProgramDiagnosticDataType_Initialize(OpcUa_ProgramDiagnosticDataType* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ProgramDiagnosticDataType_Clear(OpcUa_ProgramDiagnosticDataType* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ProgramDiagnosticDataType_GetSize(OpcUa_ProgramDiagnosticDataType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ProgramDiagnosticDataType_Encode(OpcUa_ProgramDiagnosticDataType* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ProgramDiagnosticDataType_Decode(OpcUa_ProgramDiagnosticDataType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ProgramDiagnosticDataType_Compare(const OpcUa_ProgramDiagnosticDataType* pValue1, const OpcUa_ProgramDiagnosticDataType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ProgramDiagnosticDataType_Copy(const OpcUa_ProgramDiagnosticDataType* pSource, OpcUa_ProgramDiagnosticDataType** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ProgramDiagnosticDataType_CopyTo(const OpcUa_ProgramDiagnosticDataType* pSource, OpcUa_ProgramDiagnosticDataType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ProgramDiagnosticDataType_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_Annotation
/*============================================================================
 * The Annotation structure.
 *===========================================================================*/
/** \struct OpcUa_Annotation
 *  Describes Annotation information for the history data items.
 *
 *  \var OpcUa_Annotation::Message
 *  Annotation message or text
 *
 *  \var OpcUa_Annotation::UserName
 *  The user that added the Annotation, as supplied by underlying system.
 *
 *  \var OpcUa_Annotation::AnnotationTime
 *  The time the Annotation was added. This will probably be different than the
 *  SourceTimestamp.
 */
typedef struct _OpcUa_Annotation
{
    OpcUa_String   Message;
    OpcUa_String   UserName;
    OpcUa_DateTime AnnotationTime;
}
OpcUa_Annotation;

OPCUA_EXPORT OpcUa_Void       OpcUa_Annotation_Initialize(OpcUa_Annotation* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_Annotation_Clear(OpcUa_Annotation* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_Annotation_GetSize(OpcUa_Annotation* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_Annotation_Encode(OpcUa_Annotation* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_Annotation_Decode(OpcUa_Annotation* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_Annotation_Compare(const OpcUa_Annotation* pValue1, const OpcUa_Annotation* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Annotation_Copy(const OpcUa_Annotation* pSource, OpcUa_Annotation** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_Annotation_CopyTo(const OpcUa_Annotation* pSource, OpcUa_Annotation* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_Annotation_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_Node
/*============================================================================
 * The Node structure.
 *===========================================================================*/
/** \struct OpcUa_Node
Specifies the attributes which belong to all nodes.
 */
typedef struct _OpcUa_Node
{
    OpcUa_NodeId         NodeId;
    OpcUa_NodeClass      NodeClass;
    OpcUa_QualifiedName  BrowseName;
    OpcUa_LocalizedText  DisplayName;
    OpcUa_LocalizedText  Description;
    OpcUa_UInt32         WriteMask;
    OpcUa_UInt32         UserWriteMask;
    OpcUa_Int32          NoOfReferences;
    OpcUa_ReferenceNode* References;
}
OpcUa_Node;

OPCUA_EXPORT OpcUa_Void       OpcUa_Node_Initialize(OpcUa_Node* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_Node_Clear(OpcUa_Node* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_Node_GetSize(OpcUa_Node* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_Node_Encode(OpcUa_Node* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_Node_Decode(OpcUa_Node* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_Node_Compare(const OpcUa_Node* pValue1, const OpcUa_Node* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Node_Copy(const OpcUa_Node* pSource, OpcUa_Node** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_Node_CopyTo(const OpcUa_Node* pSource, OpcUa_Node* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_Node_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ObjectNode
/*============================================================================
 * The ObjectNode structure.
 *===========================================================================*/
/** \struct OpcUa_ObjectNode
Specifies the attributes which belong to object nodes.
 */
typedef struct _OpcUa_ObjectNode
{
    OpcUa_NodeId         NodeId;
    OpcUa_NodeClass      NodeClass;
    OpcUa_QualifiedName  BrowseName;
    OpcUa_LocalizedText  DisplayName;
    OpcUa_LocalizedText  Description;
    OpcUa_UInt32         WriteMask;
    OpcUa_UInt32         UserWriteMask;
    OpcUa_Int32          NoOfReferences;
    OpcUa_ReferenceNode* References;
    OpcUa_Byte           EventNotifier;
}
OpcUa_ObjectNode;

OPCUA_EXPORT OpcUa_Void       OpcUa_ObjectNode_Initialize(OpcUa_ObjectNode* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ObjectNode_Clear(OpcUa_ObjectNode* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ObjectNode_GetSize(OpcUa_ObjectNode* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ObjectNode_Encode(OpcUa_ObjectNode* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ObjectNode_Decode(OpcUa_ObjectNode* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ObjectNode_Compare(const OpcUa_ObjectNode* pValue1, const OpcUa_ObjectNode* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ObjectNode_Copy(const OpcUa_ObjectNode* pSource, OpcUa_ObjectNode** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ObjectNode_CopyTo(const OpcUa_ObjectNode* pSource, OpcUa_ObjectNode* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ObjectNode_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ObjectTypeNode
/*============================================================================
 * The ObjectTypeNode structure.
 *===========================================================================*/
/** \struct OpcUa_ObjectTypeNode
Specifies the attributes which belong to object type nodes.
 */
typedef struct _OpcUa_ObjectTypeNode
{
    OpcUa_NodeId         NodeId;
    OpcUa_NodeClass      NodeClass;
    OpcUa_QualifiedName  BrowseName;
    OpcUa_LocalizedText  DisplayName;
    OpcUa_LocalizedText  Description;
    OpcUa_UInt32         WriteMask;
    OpcUa_UInt32         UserWriteMask;
    OpcUa_Int32          NoOfReferences;
    OpcUa_ReferenceNode* References;
    OpcUa_Boolean        IsAbstract;
}
OpcUa_ObjectTypeNode;

OPCUA_EXPORT OpcUa_Void       OpcUa_ObjectTypeNode_Initialize(OpcUa_ObjectTypeNode* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ObjectTypeNode_Clear(OpcUa_ObjectTypeNode* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ObjectTypeNode_GetSize(OpcUa_ObjectTypeNode* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ObjectTypeNode_Encode(OpcUa_ObjectTypeNode* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ObjectTypeNode_Decode(OpcUa_ObjectTypeNode* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ObjectTypeNode_Compare(const OpcUa_ObjectTypeNode* pValue1, const OpcUa_ObjectTypeNode* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ObjectTypeNode_Copy(const OpcUa_ObjectTypeNode* pSource, OpcUa_ObjectTypeNode** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ObjectTypeNode_CopyTo(const OpcUa_ObjectTypeNode* pSource, OpcUa_ObjectTypeNode* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ObjectTypeNode_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_VariableNode
/*============================================================================
 * The VariableNode structure.
 *===========================================================================*/
/** \struct OpcUa_VariableNode
Specifies the attributes which belong to variable nodes.
 */
typedef struct _OpcUa_VariableNode
{
    OpcUa_NodeId         NodeId;
    OpcUa_NodeClass      NodeClass;
    OpcUa_QualifiedName  BrowseName;
    OpcUa_LocalizedText  DisplayName;
    OpcUa_LocalizedText  Description;
    OpcUa_UInt32         WriteMask;
    OpcUa_UInt32         UserWriteMask;
    OpcUa_Int32          NoOfReferences;
    OpcUa_ReferenceNode* References;
    OpcUa_Variant        Value;
    OpcUa_NodeId         DataType;
    OpcUa_Int32          ValueRank;
    OpcUa_Int32          NoOfArrayDimensions;
    OpcUa_UInt32*        ArrayDimensions;
    OpcUa_Byte           AccessLevel;
    OpcUa_Byte           UserAccessLevel;
    OpcUa_Double         MinimumSamplingInterval;
    OpcUa_Boolean        Historizing;
}
OpcUa_VariableNode;

OPCUA_EXPORT OpcUa_Void       OpcUa_VariableNode_Initialize(OpcUa_VariableNode* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_VariableNode_Clear(OpcUa_VariableNode* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_VariableNode_GetSize(OpcUa_VariableNode* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_VariableNode_Encode(OpcUa_VariableNode* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_VariableNode_Decode(OpcUa_VariableNode* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_VariableNode_Compare(const OpcUa_VariableNode* pValue1, const OpcUa_VariableNode* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_VariableNode_Copy(const OpcUa_VariableNode* pSource, OpcUa_VariableNode** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_VariableNode_CopyTo(const OpcUa_VariableNode* pSource, OpcUa_VariableNode* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_VariableNode_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_VariableTypeNode
/*============================================================================
 * The VariableTypeNode structure.
 *===========================================================================*/
/** \struct OpcUa_VariableTypeNode
Specifies the attributes which belong to variable type nodes.
 */
typedef struct _OpcUa_VariableTypeNode
{
    OpcUa_NodeId         NodeId;
    OpcUa_NodeClass      NodeClass;
    OpcUa_QualifiedName  BrowseName;
    OpcUa_LocalizedText  DisplayName;
    OpcUa_LocalizedText  Description;
    OpcUa_UInt32         WriteMask;
    OpcUa_UInt32         UserWriteMask;
    OpcUa_Int32          NoOfReferences;
    OpcUa_ReferenceNode* References;
    OpcUa_Variant        Value;
    OpcUa_NodeId         DataType;
    OpcUa_Int32          ValueRank;
    OpcUa_Int32          NoOfArrayDimensions;
    OpcUa_UInt32*        ArrayDimensions;
    OpcUa_Boolean        IsAbstract;
}
OpcUa_VariableTypeNode;

OPCUA_EXPORT OpcUa_Void       OpcUa_VariableTypeNode_Initialize(OpcUa_VariableTypeNode* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_VariableTypeNode_Clear(OpcUa_VariableTypeNode* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_VariableTypeNode_GetSize(OpcUa_VariableTypeNode* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_VariableTypeNode_Encode(OpcUa_VariableTypeNode* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_VariableTypeNode_Decode(OpcUa_VariableTypeNode* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_VariableTypeNode_Compare(const OpcUa_VariableTypeNode* pValue1, const OpcUa_VariableTypeNode* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_VariableTypeNode_Copy(const OpcUa_VariableTypeNode* pSource, OpcUa_VariableTypeNode** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_VariableTypeNode_CopyTo(const OpcUa_VariableTypeNode* pSource, OpcUa_VariableTypeNode* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_VariableTypeNode_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ReferenceTypeNode
/*============================================================================
 * The ReferenceTypeNode structure.
 *===========================================================================*/
/** \struct OpcUa_ReferenceTypeNode
Specifies the attributes which belong to reference type nodes.
 */
typedef struct _OpcUa_ReferenceTypeNode
{
    OpcUa_NodeId         NodeId;
    OpcUa_NodeClass      NodeClass;
    OpcUa_QualifiedName  BrowseName;
    OpcUa_LocalizedText  DisplayName;
    OpcUa_LocalizedText  Description;
    OpcUa_UInt32         WriteMask;
    OpcUa_UInt32         UserWriteMask;
    OpcUa_Int32          NoOfReferences;
    OpcUa_ReferenceNode* References;
    OpcUa_Boolean        IsAbstract;
    OpcUa_Boolean        Symmetric;
    OpcUa_LocalizedText  InverseName;
}
OpcUa_ReferenceTypeNode;

OPCUA_EXPORT OpcUa_Void       OpcUa_ReferenceTypeNode_Initialize(OpcUa_ReferenceTypeNode* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ReferenceTypeNode_Clear(OpcUa_ReferenceTypeNode* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReferenceTypeNode_GetSize(OpcUa_ReferenceTypeNode* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReferenceTypeNode_Encode(OpcUa_ReferenceTypeNode* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReferenceTypeNode_Decode(OpcUa_ReferenceTypeNode* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ReferenceTypeNode_Compare(const OpcUa_ReferenceTypeNode* pValue1, const OpcUa_ReferenceTypeNode* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReferenceTypeNode_Copy(const OpcUa_ReferenceTypeNode* pSource, OpcUa_ReferenceTypeNode** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReferenceTypeNode_CopyTo(const OpcUa_ReferenceTypeNode* pSource, OpcUa_ReferenceTypeNode* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ReferenceTypeNode_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_MethodNode
/*============================================================================
 * The MethodNode structure.
 *===========================================================================*/
/** \struct OpcUa_MethodNode
Specifies the attributes which belong to method nodes.
 */
typedef struct _OpcUa_MethodNode
{
    OpcUa_NodeId         NodeId;
    OpcUa_NodeClass      NodeClass;
    OpcUa_QualifiedName  BrowseName;
    OpcUa_LocalizedText  DisplayName;
    OpcUa_LocalizedText  Description;
    OpcUa_UInt32         WriteMask;
    OpcUa_UInt32         UserWriteMask;
    OpcUa_Int32          NoOfReferences;
    OpcUa_ReferenceNode* References;
    OpcUa_Boolean        Executable;
    OpcUa_Boolean        UserExecutable;
}
OpcUa_MethodNode;

OPCUA_EXPORT OpcUa_Void       OpcUa_MethodNode_Initialize(OpcUa_MethodNode* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_MethodNode_Clear(OpcUa_MethodNode* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MethodNode_GetSize(OpcUa_MethodNode* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MethodNode_Encode(OpcUa_MethodNode* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MethodNode_Decode(OpcUa_MethodNode* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_MethodNode_Compare(const OpcUa_MethodNode* pValue1, const OpcUa_MethodNode* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_MethodNode_Copy(const OpcUa_MethodNode* pSource, OpcUa_MethodNode** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_MethodNode_CopyTo(const OpcUa_MethodNode* pSource, OpcUa_MethodNode* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_MethodNode_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ViewNode
/*============================================================================
 * The ViewNode structure.
 *===========================================================================*/
typedef struct _OpcUa_ViewNode
{
    OpcUa_NodeId         NodeId;
    OpcUa_NodeClass      NodeClass;
    OpcUa_QualifiedName  BrowseName;
    OpcUa_LocalizedText  DisplayName;
    OpcUa_LocalizedText  Description;
    OpcUa_UInt32         WriteMask;
    OpcUa_UInt32         UserWriteMask;
    OpcUa_Int32          NoOfReferences;
    OpcUa_ReferenceNode* References;
    OpcUa_Boolean        ContainsNoLoops;
    OpcUa_Byte           EventNotifier;
}
OpcUa_ViewNode;

OPCUA_EXPORT OpcUa_Void       OpcUa_ViewNode_Initialize(OpcUa_ViewNode* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ViewNode_Clear(OpcUa_ViewNode* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ViewNode_GetSize(OpcUa_ViewNode* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ViewNode_Encode(OpcUa_ViewNode* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ViewNode_Decode(OpcUa_ViewNode* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ViewNode_Compare(const OpcUa_ViewNode* pValue1, const OpcUa_ViewNode* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ViewNode_Copy(const OpcUa_ViewNode* pSource, OpcUa_ViewNode** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ViewNode_CopyTo(const OpcUa_ViewNode* pSource, OpcUa_ViewNode* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ViewNode_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_DataTypeNode
/*============================================================================
 * The DataTypeNode structure.
 *===========================================================================*/
typedef struct _OpcUa_DataTypeNode
{
    OpcUa_NodeId         NodeId;
    OpcUa_NodeClass      NodeClass;
    OpcUa_QualifiedName  BrowseName;
    OpcUa_LocalizedText  DisplayName;
    OpcUa_LocalizedText  Description;
    OpcUa_UInt32         WriteMask;
    OpcUa_UInt32         UserWriteMask;
    OpcUa_Int32          NoOfReferences;
    OpcUa_ReferenceNode* References;
    OpcUa_Boolean        IsAbstract;
}
OpcUa_DataTypeNode;

OPCUA_EXPORT OpcUa_Void       OpcUa_DataTypeNode_Initialize(OpcUa_DataTypeNode* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_DataTypeNode_Clear(OpcUa_DataTypeNode* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DataTypeNode_GetSize(OpcUa_DataTypeNode* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DataTypeNode_Encode(OpcUa_DataTypeNode* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DataTypeNode_Decode(OpcUa_DataTypeNode* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_DataTypeNode_Compare(const OpcUa_DataTypeNode* pValue1, const OpcUa_DataTypeNode* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_DataTypeNode_Copy(const OpcUa_DataTypeNode* pSource, OpcUa_DataTypeNode** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DataTypeNode_CopyTo(const OpcUa_DataTypeNode* pSource, OpcUa_DataTypeNode* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_DataTypeNode_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ReadEventDetails
/*============================================================================
 * The ReadEventDetails structure.
 *===========================================================================*/
/** \struct OpcUa_ReadEventDetails
 *  Selects a set of events from the history database by specifying a filter and a
 *  time domain for one or more objects or views.
 *
 *  The ReadEventDetails structure is used to read the events from the history
 *  database for the specified time domain for one or more HistoricalEventNodes.
 *  The events are filtered based on the filter structure provided. This filter
 *  includes the event fields that are to be returned.
 *
 *  The startTime and endTime are used to filter on the Time field for events.
 *
 *  The time domain of the request is defined by startTime, endTime, and
 *  numValuesPerNode; at least two of these must be specified. If endTime is less
 *  than startTime, or endTime and numValuesPerNode alone are specified, the data
 *  will be returned in reverse order with later/newer data provided first, as if
 *  time was flowing backward. If all three are specified, the call shall return up
 *  to numValuesPerNode results, going from startTime to endTime, in either
 *  ascending or descending order, depending on the relative values of startTime
 *  and endTime. If numValuesPerNode is 0, all of the values in the range are
 *  returned. The default value is used to indicate that startTime, endTime, or
 *  numValuesPerNode is not specified.
 *
 *  It is specifically allowed for the startTime and the endTime to be identical.
 *  This allows the Client to request the event at a single instance in time. If
 *  startTime and endTime are identical, time is presumed to be flowing forward. If
 *  no data exists at the time specified, the server must return the Good_NoData
 *  StatusCode.
 *
 *  If a startTime, endTime, and numValuesPerNode are all provided, and if more
 *  than numValuesPerNode events exist within that time range for a given node,
 *  then only numValuesPerNode events per node are returned along with a
 *  continuationPoint. When a continuationPoint is returned, a Client wanting the
 *  next numValuesPerNode values should call HistoryRead again with the
 *  continuationPoint.
 *
 *  For an interval in which no data exists, the corresponding StatusCode shall be
 *  Good_NoData.
 *
 *  The filter parameter is used to determine which historical events and their
 *  corresponding fields are returned. It is possible that the fields of an
 *  EventType are available for real time updating, but not available from the
 *  historian. In this case, a StatusCode value will be returned for any event
 *  field that cannot be returned. The value of the StatusCode must be Bad_NoData.
 *
 *  If the requested timestamp format is not supported for a node, the operation
 *  shall return the Bad_TimestampNotSupported StatusCode. When reading events,
 *  this only applies to Event fields that are of type DataValue.
 *
 *  \var OpcUa_ReadEventDetails::NumValuesPerNode
 *  The maximum number of values returned for any node over the time range.
 *
 *  If only one time is specified, the time range must extend to return this number
 *  of values. The default value of 0 indicates that there is no maximum.
 *
 *  \var OpcUa_ReadEventDetails::StartTime
 *  The beginning of the period to read.
 *
 *  The default value of DateTime.MinValue indicates that the startTime is
 *  Unspecified.
 *
 *  \var OpcUa_ReadEventDetails::EndTime
 *  The end of the period to read.
 *
 *  The default value of DateTime.MinValue indicates that the endTime is
 *  Unspecified.
 *
 *  \var OpcUa_ReadEventDetails::Filter
 *  A filter used by the Server to determine which HistoricalEventNode should be
 *  included.
 *
 *  This parameter must be specified and at least one EventField is required. The
 *  EventFilter parameter type is an extensible parameter type. It is defined and
 *  used in the same manner as defined for monitored data items. This filter also
 *  specifies the EventFields that are to be returned as part of the request.
 */
typedef struct _OpcUa_ReadEventDetails
{
    OpcUa_UInt32      NumValuesPerNode;
    OpcUa_DateTime    StartTime;
    OpcUa_DateTime    EndTime;
    OpcUa_EventFilter Filter;
}
OpcUa_ReadEventDetails;

OPCUA_EXPORT OpcUa_Void       OpcUa_ReadEventDetails_Initialize(OpcUa_ReadEventDetails* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ReadEventDetails_Clear(OpcUa_ReadEventDetails* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadEventDetails_GetSize(OpcUa_ReadEventDetails* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadEventDetails_Encode(OpcUa_ReadEventDetails* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadEventDetails_Decode(OpcUa_ReadEventDetails* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ReadEventDetails_Compare(const OpcUa_ReadEventDetails* pValue1, const OpcUa_ReadEventDetails* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadEventDetails_Copy(const OpcUa_ReadEventDetails* pSource, OpcUa_ReadEventDetails** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadEventDetails_CopyTo(const OpcUa_ReadEventDetails* pSource, OpcUa_ReadEventDetails* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ReadEventDetails_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_ReadProcessedDetails
/*============================================================================
 * The ReadProcessedDetails structure.
 *===========================================================================*/
/** \struct OpcUa_ReadProcessedDetails
 *  Selects a set of aggregate values from the history database by specifying a
 *  time domain for one or more variables.
 *
 *  This structure is used to compute aggregate values, qualities, and timestamps
 *  from data in the history database for the specified time domain for one or more
 *  HistoricalDataNodes. The time domain is divided into intervals of duration
 *  ProcessingInterval. The specified AggregateType is calculated for each interval
 *  beginning with startTime by using the data within the next ProcessingInterval.
 *
 *  For example, this function can provide hourly statistics such as maximum,
 *  minimum, and average for each item during the specified time domain if
 *  ProcessingInterval is 1 hour.
 *
 *  The domain of the request is defined by startTime, endTime, and
 *  ProcessingInterval. All three must be specified. If endTime is less than
 *  startTime, the data shall be returned in reverse order with later data coming
 *  first. If startTime and endTime are the same, the server shall return
 *  Bad_InvalidArgument, as there is no meaningful way to interpret such a case.
 *
 *  The aggregateType[] parameter allows a Client to request multiple aggregate
 *  calculations per requested NodeId. If multiple aggregates are requested, a
 *  corresponding number of entries are required in the NodesToRead array.
 *
 *  For example, requesting Min aggregate for NodeId FIC101, FIC102 and both Min
 *  and Max aggregates for NodeId FIC103 would require NodeId FIC103 to appear
 *  twice in the NodesToRead array request parameter.
 *
 *  aggregateType[]  | NodesToRead[]
 *  -----------------|---------------
 *  Min              | FIC101
 *  Min              | FIC102
 *  Min              | FIC103
 *  Max              | FIC103
 *
 *  If the array of aggregates does not match the array of NodesToRead, the Server
 *  shall return a StatusCode of Bad_AggregateListMismatch. The
 *  aggregateConfiguration parameter allows a Client to override the aggregate
 *  configuration settings supplied by the AggregateConfiguration object on a per
 *  call basis. If the Server does not support the ability to override the
 *  aggregate configuration settings, it shall return a StatusCode of
 *  Bad_AggregateConfigurationRejected. If the aggregate is not valid for the node,
 *  the StatusCode shall be Bad_AggregateNotSupported.
 *
 *  The values used in computing the aggregate for each interval shall include any
 *  value that falls exactly on the timestamp at beginning of the interval, but
 *  shall not include any value that falls directly on the timestamp ending the
 *  interval. Thus, each value shall be included only once in the calculation. If
 *  the time domain is in reverse order, we consider the later timestamp to be the
 *  one beginning the subinterval, and the earlier timestamp to be the one ending
 *  it. Note that this means that simply swapping the start and end times will not
 *  result in getting the same values back in reverse order, as the interval being
 *  requested in the two cases are not the same.
 *
 *  If an aggregate is taking a long time to calculate, the Server can return
 *  partial results with a continuation point. This might be done if the
 *  calculation is going to take more time than the Client timeout hint. In some
 *  cases it may take longer than the Client timeout hint to calculate even one
 *  Aggregate result. Then the server may return zero results with a continuation
 *  point that allows the server to resume the calculation on the next Client read
 *  call.
 *
 *  \var OpcUa_ReadProcessedDetails::StartTime
 *  The beginning of the period to read.
 *
 *  \var OpcUa_ReadProcessedDetails::EndTime
 *  The end of the period to read.
 *
 *  \var OpcUa_ReadProcessedDetails::ProcessingInterval
 *  The interval between returned aggregate values.
 *
 *  The value 0 indicates that there is no ProcessingInterval defined.
 *
 *  \var OpcUa_ReadProcessedDetails::AggregateType
 *  The NodeId of the HistoryAggregate object that indicates the list of aggregates
 *  to be used when retrieving processed history.
 *
 *  \var OpcUa_ReadProcessedDetails::AggregateConfiguration
 *  Allows a Client to override aggregate configuration settings ona per call
 *  basis.
 */
typedef struct _OpcUa_ReadProcessedDetails
{
    OpcUa_DateTime               StartTime;
    OpcUa_DateTime               EndTime;
    OpcUa_Double                 ProcessingInterval;
    OpcUa_Int32                  NoOfAggregateType;
    OpcUa_NodeId*                AggregateType;
    OpcUa_AggregateConfiguration AggregateConfiguration;
}
OpcUa_ReadProcessedDetails;

OPCUA_EXPORT OpcUa_Void       OpcUa_ReadProcessedDetails_Initialize(OpcUa_ReadProcessedDetails* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_ReadProcessedDetails_Clear(OpcUa_ReadProcessedDetails* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadProcessedDetails_GetSize(OpcUa_ReadProcessedDetails* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadProcessedDetails_Encode(OpcUa_ReadProcessedDetails* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadProcessedDetails_Decode(OpcUa_ReadProcessedDetails* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_ReadProcessedDetails_Compare(const OpcUa_ReadProcessedDetails* pValue1, const OpcUa_ReadProcessedDetails* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadProcessedDetails_Copy(const OpcUa_ReadProcessedDetails* pSource, OpcUa_ReadProcessedDetails** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ReadProcessedDetails_CopyTo(const OpcUa_ReadProcessedDetails* pSource, OpcUa_ReadProcessedDetails* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_ReadProcessedDetails_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_HistoryEvent
/*============================================================================
 * The HistoryEvent structure.
 *===========================================================================*/
/** \struct OpcUa_HistoryEvent
 *  A table structure that is used to return Event fields to a Historical Read.
 *
 *  The structure is in the form of a table consisting of one or more Events, each
 *  containing an array of one or more fields. The selection and order of the
 *  fields returned for each Event is identical to the selected parameter of the
 *  EventFilter.
 *
 *  \var OpcUa_HistoryEvent::Events
 *  The list of Events being delivered
 */
typedef struct _OpcUa_HistoryEvent
{
    OpcUa_Int32                  NoOfEvents;
    OpcUa_HistoryEventFieldList* Events;
}
OpcUa_HistoryEvent;

OPCUA_EXPORT OpcUa_Void       OpcUa_HistoryEvent_Initialize(OpcUa_HistoryEvent* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_HistoryEvent_Clear(OpcUa_HistoryEvent* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryEvent_GetSize(OpcUa_HistoryEvent* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryEvent_Encode(OpcUa_HistoryEvent* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryEvent_Decode(OpcUa_HistoryEvent* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_HistoryEvent_Compare(const OpcUa_HistoryEvent* pValue1, const OpcUa_HistoryEvent* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryEvent_Copy(const OpcUa_HistoryEvent* pSource, OpcUa_HistoryEvent** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_HistoryEvent_CopyTo(const OpcUa_HistoryEvent* pSource, OpcUa_HistoryEvent* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_HistoryEvent_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_UpdateEventDetails
/*============================================================================
 * The UpdateEventDetails structure.
 *===========================================================================*/
/** \struct OpcUa_UpdateEventDetails
 *  This function inserts new events or replaces existing events in the history
 *  database for one or more HistoricalEventNodes.
 *
 *  <b>Insert event functionality</b><br/> This function is intended to insert new
 *  entries; e.g., backfilling of historical events.
 *
 *  Setting performInsertReplace = INSERT_1 inserts entries into the event history
 *  database for one or more HistoricalEventNodes. The whereClause parameter of the
 *  EventFilter shall be empty. The SelectClause must as a minimum provide the
 *  following event fields: EventType and Time. It is also recommended that the
 *  SourceNode and the SourceName fields are provided. If one of the required
 *  fields is not provided, the following error is returned: Bad_ArgumentsMissing.
 *  If the historian does not support archiving the specified EventType, the
 *  StatusCode shall indicate Bad_TypeDefinitionInvalid. If the SourceNode is not a
 *  valid source for Events, the StatusCode shall indicate Bad_SourceNodeIdInvalid.
 *  If the time does not fall within range that can be stored, the StatusCode shall
 *  indicate Bad_OutOfRange. If the selectClause does not include fields which are
 *  mandatory for the EventType, the StatusCode shall indicate
 *  Bad_ArgumentsMissing. If the selectClause specifies fields which are not valid
 *  for the EventType or cannot be saved by the historian, the StatusCode shall
 *  indicate Good_DataIgnored and the OperationResults array shall specify
 *  Bad_NotSupported for each ignored field.
 *
 *  The EventId is a server generated opaque value and a Client cannot assume that
 *  it knows how to create valid EventIds. A Server must be able to generate an
 *  appropriate default value for the EventId field. If a Client does specify the
 *  EventId in the selectClause and it matches an exitsting event, the StatusCode
 *  shall indicate Bad_EntryExists. A Client must use a HistoryRead to discover any
 *  automatically generated EventIds.
 *
 *  If any errors occur while processing individual fields, the StatusCode shall
 *  indicate Bad_InvalidArgument and the OperationResults array shall specify the
 *  exact error for each invalid field. The IndexRange parameter of the
 *  SimpleAttributeOperand is not valid for insert operations and the
 *  OperationResults shall specify Bad_IndexRangeInvalid if one is specified.
 *
 *  If no errors occur, the StatusCode shall indicate Good and the OperationResults
 *  array shall be empty. If errors do occur, the OperationResults array will have
 *  one element for each fiel d specified in the selectClause.
 *
 *  A Client may instruct the Server to choose a suitable default value for a field
 *  by specifying a value of null. If the server is not able to select a suitable
 *  default, the corresponding entry in the OperationResults array shall be
 *  Bad_InvalidArgument.
 *
 *  <b>Replace event functionality</b><br/> This function is intended to replace
 *  fields in existing event entries; e.g. correct event data that contained
 *  incorrect data due to a bad sensor.
 *
 *  Setting performInsertReplace = REPLACE_2 replaces entries in the event history
 *  database for the specified filter for one or more HistoricalEventNodes. The
 *  whereClause parameter of the EventFilter shall specify the EventId property. If
 *  no entry exists matching the specified filter, no updates will be performed;
 *  instead the StatusCode shall indicate Bad_NoEntryExists.
 *
 *  If the selectClause specifies fields which are not valid for the EventType or
 *  cannot be saved by the historian, the StatusCode shall indicate
 *  Good_DataIgnored and the OperationResults array shall specify Bad_NotSupported
 *  for each ignored field.
 *
 *  If a field is valid for the EventType but cannot be changed, then the
 *  StatusCode shall indicate Good_DataIgnored and the corresponding entry in the
 *  OperationResults array shall be Bad_NotWriteable.
 *
 *  If fatal errors occur while processing individual fields, the StatusCode shall
 *  indicate Bad_InvalidArgument and the OperationResults array shall specify the
 *  exact error.
 *
 *  If no errors occur, the StatusCode shall indicate Good and the OperationResults
 *  array shall be empty.If errors do occur, the OperationResults array will have
 *  one element for each field specified in the selectClause.
 *
 *  <b>Update event functionality</b><br/> This function is intended to
 *  unconditionally insert/replace events, e.g. synchronizing a backup event
 *  database.
 *
 *  Setting performInsertReplace = UPDATE_3 inserts or replaces entries in the
 *  event history database for the specified filter for one or more
 *  HistoricalEventNodes.
 *
 *  The server will, based on its own criteria, attempt to determine whether the
 *  event already exists. If it does exist, the event will be deleted and the new
 *  event will be inserted (retaining the EventId). If the EventID was provided,
 *  the EventID will be used to determine if the event already exists. If the event
 *  does not exist, a new event will be inserted, including the generation of a new
 *  EventId.
 *
 *  All of the restrictions, behaviours, and errors specified for the insert
 *  functionality also apply to this function.
 *
 *  If an existing entry was replaced successfully, the the StatusCode shall be
 *  Good_EntryReplaced. If a new entry was created, the StatusCode shall be
 *  Good_EntryInserted. If the server cannot determine whether it replaced or
 *  inserted an entry, the StatusCode shall be Good.
 *
 *  \var OpcUa_UpdateEventDetails::NodeId
 *  NodeId of the object to be updated
 *
 *  \var OpcUa_UpdateEventDetails::PerformInsertReplace
 *  Determines which action of insert, replace, or update is performed.
 *
 *  Possible values are INSERT_1, REPLACE_2, or UPDATE_3 (see \ref
 *  OpcUa_UpdateEventDetails).
 *
 *  \var OpcUa_UpdateEventDetails::Filter
 *  If the history of the notification conforms to the EventFilter, the history of
 *  the notification is updated.
 *
 *  \var OpcUa_UpdateEventDetails::EventData
 *  Event notification data to be inserted or updated.
 */
typedef struct _OpcUa_UpdateEventDetails
{
    OpcUa_NodeId                 NodeId;
    OpcUa_PerformUpdateType      PerformInsertReplace;
    OpcUa_EventFilter            Filter;
    OpcUa_Int32                  NoOfEventData;
    OpcUa_HistoryEventFieldList* EventData;
}
OpcUa_UpdateEventDetails;

OPCUA_EXPORT OpcUa_Void       OpcUa_UpdateEventDetails_Initialize(OpcUa_UpdateEventDetails* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_UpdateEventDetails_Clear(OpcUa_UpdateEventDetails* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UpdateEventDetails_GetSize(OpcUa_UpdateEventDetails* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UpdateEventDetails_Encode(OpcUa_UpdateEventDetails* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UpdateEventDetails_Decode(OpcUa_UpdateEventDetails* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_UpdateEventDetails_Compare(const OpcUa_UpdateEventDetails* pValue1, const OpcUa_UpdateEventDetails* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_UpdateEventDetails_Copy(const OpcUa_UpdateEventDetails* pSource, OpcUa_UpdateEventDetails** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_UpdateEventDetails_CopyTo(const OpcUa_UpdateEventDetails* pSource, OpcUa_UpdateEventDetails* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_UpdateEventDetails_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_DataChangeNotification
/*============================================================================
 * The DataChangeNotification structure.
 *===========================================================================*/
typedef struct _OpcUa_DataChangeNotification
{
    OpcUa_Int32                      NoOfMonitoredItems;
    OpcUa_MonitoredItemNotification* MonitoredItems;
    OpcUa_Int32                      NoOfDiagnosticInfos;
    OpcUa_DiagnosticInfo*            DiagnosticInfos;
}
OpcUa_DataChangeNotification;

OPCUA_EXPORT OpcUa_Void       OpcUa_DataChangeNotification_Initialize(OpcUa_DataChangeNotification* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_DataChangeNotification_Clear(OpcUa_DataChangeNotification* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DataChangeNotification_GetSize(OpcUa_DataChangeNotification* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DataChangeNotification_Encode(OpcUa_DataChangeNotification* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DataChangeNotification_Decode(OpcUa_DataChangeNotification* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_DataChangeNotification_Compare(const OpcUa_DataChangeNotification* pValue1, const OpcUa_DataChangeNotification* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_DataChangeNotification_Copy(const OpcUa_DataChangeNotification* pSource, OpcUa_DataChangeNotification** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DataChangeNotification_CopyTo(const OpcUa_DataChangeNotification* pSource, OpcUa_DataChangeNotification* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_DataChangeNotification_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_EventNotificationList
/*============================================================================
 * The EventNotificationList structure.
 *===========================================================================*/
typedef struct _OpcUa_EventNotificationList
{
    OpcUa_Int32           NoOfEvents;
    OpcUa_EventFieldList* Events;
}
OpcUa_EventNotificationList;

OPCUA_EXPORT OpcUa_Void       OpcUa_EventNotificationList_Initialize(OpcUa_EventNotificationList* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_EventNotificationList_Clear(OpcUa_EventNotificationList* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EventNotificationList_GetSize(OpcUa_EventNotificationList* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EventNotificationList_Encode(OpcUa_EventNotificationList* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EventNotificationList_Decode(OpcUa_EventNotificationList* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_EventNotificationList_Compare(const OpcUa_EventNotificationList* pValue1, const OpcUa_EventNotificationList* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_EventNotificationList_Copy(const OpcUa_EventNotificationList* pSource, OpcUa_EventNotificationList** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_EventNotificationList_CopyTo(const OpcUa_EventNotificationList* pSource, OpcUa_EventNotificationList* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_EventNotificationList_EncodeableType;
#endif

#ifndef OPCUA_EXCLUDE_SessionDiagnosticsDataType
/*============================================================================
 * The SessionDiagnosticsDataType structure.
 *===========================================================================*/
/** \struct OpcUa_SessionDiagnosticsDataType
 *  Contains diagnostic information about client sessions.
 *
 *  Most of the values represented in this structure provide information about the
 *  number of calls of a Service, the number of currently used MonitoredItems, etc.
 *  Those numbers need not provide the exact value; they need only provide the
 *  approximate number, so that the Server is not burdened with providing the exact
 *  numbers.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::SessionId
 *  Server-assigned identifier of the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::SessionName
 *  The name of the session provided in the CreateSession request.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::ClientDescription
 *  The description provided by the client in the CreateSession request.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::ServerUri
 *  The serverUri request in the CreateSession request.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::EndpointUrl
 *  The endpointUrl passed by the client to the CreateSession request.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::LocaleIds
 *  Array of LocaleIds specified by the client in the open session call.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::ActualSessionTimeout
 *  The requested session timeout specified by the client in the open session call.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::MaxResponseMessageSize
 *  The maximum size for the response message sent to the client.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::ClientConnectionTime
 *  The server timestamp when the client opens the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::ClientLastContactTime
 *  The server timestamp of the last request of the client in the context of the
 *  session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::CurrentSubscriptionsCount
 *  The number of subscriptions currently used by the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::CurrentMonitoredItemsCount
 *  The number of MonitoredItems currently used by the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::CurrentPublishRequestsInQueue
 *  The number of publish timer expirations when there are data to be sent, but
 *  there are no publish requests for this session.
 *
 *  The value shall be 0 if there are no data to be sent or publish requests
 *  queued.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::TotalRequestCount
 *  Counter of allServices, identifying the number of received requests of any
 *  Services on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::UnauthorizedRequestCount
 *  Counter of all Services, identifying the number of Service requests that were
 *  rejected due to authorization failure.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::ReadCount
 *  Counter of the Read Service, identifying the number of received requests of
 *  this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::HistoryReadCount
 *  Counter of the HistoryRead Service, identifying the number of received requests
 *  of this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::WriteCount
 *  Counter of the Write Service, identifying the number of received requests of
 *  this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::HistoryUpdateCount
 *  Counter of the HistoryUpdate Service, identifying the number of received
 *  requests of this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::CallCount
 *  Counter of the Call Service, identifying the number of received requests of
 *  this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::CreateMonitoredItemsCount
 *  Counter of the CreateMonitoredItems Service, identifying the number of received
 *  requests of this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::ModifyMonitoredItemsCount
 *  Counter of the ModifyMonitoredItems Service, identifying the number of received
 *  requests of this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::SetMonitoringModeCount
 *  Counter of the SetMonitoringMode Service, identifying the number of received
 *  requests of this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::SetTriggeringCount
 *  Counter of the SetTriggering Service, identifying the number of received
 *  requests of this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::DeleteMonitoredItemsCount
 *  Counter of the DeleteMonitoredItems Service, identifying the number of received
 *  requests of this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::CreateSubscriptionCount
 *  Counter of the CreateSubscription Service, identifying the number of received
 *  requests of this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::ModifySubscriptionCount
 *  Counter of the ModifySubscription Service, identifying the number of received
 *  requests of this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::SetPublishingModeCount
 *  Counter of the SetPublishingMode Service, identifying the number of received
 *  requests of this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::PublishCount
 *  Counter of the Publish Service, identifying the number of received requests of
 *  this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::RepublishCount
 *  Counter of the Republish Service, identifying the number of received requests
 *  of this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::TransferSubscriptionsCount
 *  Counter of the TransferSubscriptions Service, identifying the number of
 *  received requests of this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::DeleteSubscriptionsCount
 *  Counter of the DeleteSubscriptions Service, identifying the number of received
 *  requests of this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::AddNodesCount
 *  Counter of the AddNodes Service, identifying the number of received requests of
 *  this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::AddReferencesCount
 *  Counter of the AddReferences Service, identifying the number of received
 *  requests of this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::DeleteNodesCount
 *  Counter of the DeleteNodes Service, identifying the number of received requests
 *  of this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::DeleteReferencesCount
 *  Counter of the DeleteReferences Service, identifying the number of received
 *  requests of this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::BrowseCount
 *  Counter of the Browse Service, identifying the number of received requests of
 *  this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::BrowseNextCount
 *  Counter of the BrowseNext Service, identifying the number of received requests
 *  of this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::TranslateBrowsePathsToNodeIdsCount
 *  Counter of the TranslateBrowsePathsToNodeIds Service, identifying the number of
 *  received requests of this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::QueryFirstCount
 *  Counter of the QueryFirst Service, identifying the number of received requests
 *  of this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::QueryNextCount
 *  Counter of the QueryNext Service, identifying the number of received requests
 *  of this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::RegisterNodesCount
 *  Counter of the RegisterNodes Service, identifying the number of received
 *  requests of this Service on the session.
 *
 *  \var OpcUa_SessionDiagnosticsDataType::UnregisterNodesCount
 *  Counter of the UnregisterNodesService, identifying the number of received
 *  requests of this Service on the session.
 */
typedef struct _OpcUa_SessionDiagnosticsDataType
{
    OpcUa_NodeId                 SessionId;
    OpcUa_String                 SessionName;
    OpcUa_ApplicationDescription ClientDescription;
    OpcUa_String                 ServerUri;
    OpcUa_String                 EndpointUrl;
    OpcUa_Int32                  NoOfLocaleIds;
    OpcUa_String*                LocaleIds;
    OpcUa_Double                 ActualSessionTimeout;
    OpcUa_UInt32                 MaxResponseMessageSize;
    OpcUa_DateTime               ClientConnectionTime;
    OpcUa_DateTime               ClientLastContactTime;
    OpcUa_UInt32                 CurrentSubscriptionsCount;
    OpcUa_UInt32                 CurrentMonitoredItemsCount;
    OpcUa_UInt32                 CurrentPublishRequestsInQueue;
    OpcUa_ServiceCounterDataType TotalRequestCount;
    OpcUa_UInt32                 UnauthorizedRequestCount;
    OpcUa_ServiceCounterDataType ReadCount;
    OpcUa_ServiceCounterDataType HistoryReadCount;
    OpcUa_ServiceCounterDataType WriteCount;
    OpcUa_ServiceCounterDataType HistoryUpdateCount;
    OpcUa_ServiceCounterDataType CallCount;
    OpcUa_ServiceCounterDataType CreateMonitoredItemsCount;
    OpcUa_ServiceCounterDataType ModifyMonitoredItemsCount;
    OpcUa_ServiceCounterDataType SetMonitoringModeCount;
    OpcUa_ServiceCounterDataType SetTriggeringCount;
    OpcUa_ServiceCounterDataType DeleteMonitoredItemsCount;
    OpcUa_ServiceCounterDataType CreateSubscriptionCount;
    OpcUa_ServiceCounterDataType ModifySubscriptionCount;
    OpcUa_ServiceCounterDataType SetPublishingModeCount;
    OpcUa_ServiceCounterDataType PublishCount;
    OpcUa_ServiceCounterDataType RepublishCount;
    OpcUa_ServiceCounterDataType TransferSubscriptionsCount;
    OpcUa_ServiceCounterDataType DeleteSubscriptionsCount;
    OpcUa_ServiceCounterDataType AddNodesCount;
    OpcUa_ServiceCounterDataType AddReferencesCount;
    OpcUa_ServiceCounterDataType DeleteNodesCount;
    OpcUa_ServiceCounterDataType DeleteReferencesCount;
    OpcUa_ServiceCounterDataType BrowseCount;
    OpcUa_ServiceCounterDataType BrowseNextCount;
    OpcUa_ServiceCounterDataType TranslateBrowsePathsToNodeIdsCount;
    OpcUa_ServiceCounterDataType QueryFirstCount;
    OpcUa_ServiceCounterDataType QueryNextCount;
    OpcUa_ServiceCounterDataType RegisterNodesCount;
    OpcUa_ServiceCounterDataType UnregisterNodesCount;
}
OpcUa_SessionDiagnosticsDataType;

OPCUA_EXPORT OpcUa_Void       OpcUa_SessionDiagnosticsDataType_Initialize(OpcUa_SessionDiagnosticsDataType* pValue);

OPCUA_EXPORT OpcUa_Void       OpcUa_SessionDiagnosticsDataType_Clear(OpcUa_SessionDiagnosticsDataType* pValue);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SessionDiagnosticsDataType_GetSize(OpcUa_SessionDiagnosticsDataType* pValue, struct _OpcUa_Encoder* pEncoder, OpcUa_Int32* pSize);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SessionDiagnosticsDataType_Encode(OpcUa_SessionDiagnosticsDataType* pValue, struct _OpcUa_Encoder* pEncoder);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SessionDiagnosticsDataType_Decode(OpcUa_SessionDiagnosticsDataType* pValue, struct _OpcUa_Decoder* pDecoder);

#if OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
OPCUA_EXPORT OpcUa_Int        OpcUa_SessionDiagnosticsDataType_Compare(const OpcUa_SessionDiagnosticsDataType* pValue1, const OpcUa_SessionDiagnosticsDataType* pValue2);
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

#if OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
OPCUA_EXPORT OpcUa_StatusCode OpcUa_SessionDiagnosticsDataType_Copy(const OpcUa_SessionDiagnosticsDataType* pSource, OpcUa_SessionDiagnosticsDataType** ppCopy);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_SessionDiagnosticsDataType_CopyTo(const OpcUa_SessionDiagnosticsDataType* pSource, OpcUa_SessionDiagnosticsDataType* pDestination);
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType OpcUa_SessionDiagnosticsDataType_EncodeableType;
#endif


/*============================================================================
 * IsRequest
 *===========================================================================*/
OPCUA_IMEXPORT OpcUa_Boolean OpcUa_KnownEncodeableTypes_IsRequest(struct _OpcUa_EncodeableType* a_pType);

/*============================================================================
 * Table of known types.
 *===========================================================================*/
OPCUA_IMEXPORT extern struct _OpcUa_EncodeableType** OpcUa_KnownEncodeableTypes;

OPCUA_END_EXTERN_C

#endif
/* @} */
/* This is the last line of an autogenerated file. */

