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
/** \addtogroup UaStackTypes */
/* @{*/

#ifndef _OpcUa_BuiltInTypes_H_
#define _OpcUa_BuiltInTypes_H_ 1

OPCUA_BEGIN_EXTERN_C

/*============================================================================
 * The OpcUa_BuiltInType enumeration
 *===========================================================================*/
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

/*============================================================================
 * Helper for compare functions.
 *===========================================================================*/
#define OPCUA_EQUAL     ((OpcUa_Int)0)
#define OPCUA_NOT_EQUAL ((OpcUa_Int)!OPCUA_EQUAL)

/*============================================================================
 * Scalar value macros (for Code Generator output)
 *===========================================================================*/
#define OpcUa_Scalar_CopyTo(xSource, xDestination) ((*(xDestination) = *(xSource)) != 0)?(OpcUa_Good):(OpcUa_Good)
#define OpcUa_Scalar_Compare(xValue1, xValue2) ((OpcUa_Int)(*(xValue1) - *(xValue2)))

/*============================================================================
 * The Boolean type
 *===========================================================================*/

#define OpcUa_Boolean_Initialize(xValue) *(xValue) = OpcUa_False;

#define OpcUa_Boolean_Clear(xValue) *(xValue) = OpcUa_False;

#define OpcUa_Boolean_Compare(xValue1, xValue2) OpcUa_Scalar_Compare(xValue1, xValue2)

#define OpcUa_Boolean_CopyTo OpcUa_Scalar_CopyTo

/*============================================================================
 * The SByte type
 *===========================================================================*/

#define OpcUa_SByte_Initialize(xValue) *(xValue) = (OpcUa_SByte)0;

#define OpcUa_SByte_Clear(xValue) *(xValue) = (OpcUa_SByte)0;

#define OpcUa_SByte_Compare(xValue1, xValue2) OpcUa_Scalar_Compare(xValue1, xValue2)

#define OpcUa_SByte_CopyTo OpcUa_Scalar_CopyTo

/*============================================================================
 * The Byte type
 *===========================================================================*/

#define OpcUa_Byte_Initialize(xValue) *(xValue) = (OpcUa_Byte)0;

#define OpcUa_Byte_Clear(xValue) *(xValue) = (OpcUa_Byte)0;

#define OpcUa_Byte_Compare(xValue1, xValue2) OpcUa_Scalar_Compare(xValue1, xValue2)

#define OpcUa_Byte_CopyTo OpcUa_Scalar_CopyTo

/*============================================================================
 * The Int16 type
 *===========================================================================*/

#define OpcUa_Int16_Initialize(xValue) *(xValue) = (OpcUa_Int16)0;

#define OpcUa_Int16_Clear(xValue) *(xValue) = (OpcUa_Int16)0;

#define OpcUa_Int16_Compare(xValue1, xValue2) OpcUa_Scalar_Compare(xValue1, xValue2)

#define OpcUa_Int16_CopyTo OpcUa_Scalar_CopyTo

/*============================================================================
 * The UInt16 type
 *===========================================================================*/

#define OpcUa_UInt16_Initialize(xValue) *(xValue) = (OpcUa_UInt16)0;

#define OpcUa_UInt16_Clear(xValue) *(xValue) = (OpcUa_UInt16)0;

#define OpcUa_UInt16_Compare(xValue1, xValue2) OpcUa_Scalar_Compare(xValue1, xValue2)

#define OpcUa_UInt16_CopyTo OpcUa_Scalar_CopyTo

/*============================================================================
 * The Int32 type
 *===========================================================================*/

#define OpcUa_Int32_Initialize(xValue) *(xValue) = (OpcUa_Int32)0;

#define OpcUa_Int32_Clear(xValue) *(xValue) = (OpcUa_Int32)0;

#define OpcUa_Int32_Compare(xValue1, xValue2) OpcUa_Scalar_Compare(xValue1, xValue2)

#define OpcUa_Int32_CopyTo OpcUa_Scalar_CopyTo

/*============================================================================
 * The UInt32 type
 *===========================================================================*/

#define OpcUa_UInt32_Initialize(xValue) *(xValue) = (OpcUa_UInt32)0;

#define OpcUa_UInt32_Clear(xValue) *(xValue) = (OpcUa_UInt32)0;

#define OpcUa_UInt32_Compare(xValue1, xValue2) OpcUa_Scalar_Compare(xValue1, xValue2)

#define OpcUa_UInt32_CopyTo OpcUa_Scalar_CopyTo

/*============================================================================
 * The Int64 type
 *===========================================================================*/

#ifdef OPCUA_USE_NATIVE_64BIT_INTEGERS

#define OpcUa_Int64_Initialize(xValue) *(xValue) = (OpcUa_Int64)0;

#define OpcUa_Int64_Clear(xValue) *(xValue) = (OpcUa_Int64)0;

#define OpcUa_Int64_Compare(xValue1, xValue2) OpcUa_Scalar_Compare(xValue1, xValue2)

#define OpcUa_Int64_CopyTo OpcUa_Scalar_CopyTo

#else /* OPCUA_USE_NATIVE_64BIT_INTEGERS */

#define OpcUa_Int64_Initialize(xValue) OpcUa_MemSet(xValue, 0, sizeof(OpcUa_Int64));

#define OpcUa_Int64_Clear(xValue) OpcUa_MemSet(xValue, 0, sizeof(OpcUa_Int64));

#define OpcUa_Int64_Compare(xValue1, xValue2) (OpcUa_MemCmp(xValue1, xValue2, sizeof(OpcUa_Int64)))

#define OpcUa_Int64_CopyTo(xValue1, xValue2) OpcUa_MemCpy(xValue2, sizeof(OpcUa_Int64), xValue1, sizeof(OpcUa_Int64))

#endif /* OPCUA_USE_NATIVE_64BIT_INTEGERS */

/*============================================================================
 * The UInt64 type
 *===========================================================================*/

#ifdef OPCUA_USE_NATIVE_64BIT_INTEGERS

#define OpcUa_UInt64_Initialize(xValue) *(xValue) = (OpcUa_UInt64)0;

#define OpcUa_UInt64_Clear(xValue) *(xValue) = (OpcUa_UInt64)0;

#define OpcUa_UInt64_Compare(xValue1, xValue2) OpcUa_Scalar_Compare(xValue1, xValue2)

#define OpcUa_UInt64_CopyTo OpcUa_Scalar_CopyTo

#else /* OPCUA_USE_NATIVE_64BIT_INTEGERS */

#define OpcUa_UInt64_Initialize(xValue) OpcUa_MemSet(xValue, 0, sizeof(OpcUa_UInt64));

#define OpcUa_UInt64_Clear(xValue) OpcUa_MemSet(xValue, 0, sizeof(OpcUa_UInt64));

#define OpcUa_UInt64_Compare(xValue1, xValue2) (OpcUa_MemCmp(xValue1, xValue2, sizeof(OpcUa_UInt64)))

#define OpcUa_UInt64_CopyTo(xValue1, xValue2) OpcUa_MemCpy(xValue2, sizeof(OpcUa_UInt64), xValue1, sizeof(OpcUa_UInt64))

#endif /* OPCUA_USE_NATIVE_64BIT_INTEGERS */

/*============================================================================
 * The Float type
 *===========================================================================*/

#define OpcUa_Float_Initialize(xValue) *(xValue) = (OpcUa_Float)0.0;

#define OpcUa_Float_Clear(xValue) *(xValue) = (OpcUa_Float)0.0;

OPCUA_EXPORT OpcUa_Int OpcUa_Float_Compare(const OpcUa_Float* pValue1, const OpcUa_Float* pValue2);

#define OpcUa_Float_CopyTo OpcUa_Scalar_CopyTo

/*============================================================================
 * The Double type
 *===========================================================================*/

#define OpcUa_Double_Initialize(xValue) *(xValue) = (OpcUa_Double)0.0;

#define OpcUa_Double_Clear(xValue) *(xValue) = (OpcUa_Double)0.0;

OPCUA_EXPORT OpcUa_Int OpcUa_Double_Compare(const OpcUa_Double* pValue1, const OpcUa_Double* pValue2);

#define OpcUa_Double_CopyTo OpcUa_Scalar_CopyTo

/*============================================================================
 * The String type
 *===========================================================================*/
/* see opcua_string.h */

/*============================================================================
 * The DateTime type
 *===========================================================================*/

#define OpcUa_DateTime_Initialize(xValue) OpcUa_MemSet(xValue, 0, sizeof(OpcUa_DateTime));

#define OpcUa_DateTime_Clear(xValue) OpcUa_MemSet(xValue, 0, sizeof(OpcUa_DateTime));

#define OpcUa_DateTime_Compare(xValue1, xValue2) (OpcUa_MemCmp(xValue1, xValue2, sizeof(OpcUa_DateTime)))

#define OpcUa_DateTime_CopyTo(xSource, xDestination) OpcUa_MemCpy(xDestination, sizeof(OpcUa_DateTime), xSource, sizeof(OpcUa_DateTime))

/*============================================================================
 * The Guid type
 *===========================================================================*/

#define OpcUa_Guid_Initialize(xValue) *(xValue) = OpcUa_Guid_Null;

#define OpcUa_Guid_Clear(xValue) *(xValue) = OpcUa_Guid_Null;

#define OpcUa_Guid_Compare(xValue1, xValue2) (OpcUa_MemCmp(xValue1, xValue2, sizeof(OpcUa_Guid)))

#define OpcUa_Guid_CopyTo(xSource, xDestination) OpcUa_MemCpy(xDestination, sizeof(OpcUa_Guid), (OpcUa_Void*)xSource, sizeof(OpcUa_Guid))

/*============================================================================
 * The ByteString type
 *===========================================================================*/

OPCUA_EXPORT OpcUa_Void OpcUa_ByteString_Initialize(OpcUa_ByteString* value);

OPCUA_EXPORT OpcUa_Void OpcUa_ByteString_Clear(OpcUa_ByteString* value);

OPCUA_EXPORT OpcUa_Int OpcUa_ByteString_Compare(const OpcUa_ByteString* value1, const OpcUa_ByteString* value2);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ByteString_CopyTo(const OpcUa_ByteString* source, OpcUa_ByteString* destination);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ByteString_Concatenate(const OpcUa_ByteString* source, OpcUa_ByteString* destination, OpcUa_Int len);

/*============================================================================
 * The XmlElement type
 *===========================================================================*/

typedef OpcUa_ByteString OpcUa_XmlElement;

#define OpcUa_XmlElement_Initialize(xValue) OpcUa_ByteString_Initialize((OpcUa_ByteString*)xValue);

#define OpcUa_XmlElement_Clear(xValue) OpcUa_ByteString_Clear((OpcUa_ByteString*)xValue);

#define OpcUa_XmlElement_Compare(xValue1, xValue2) OpcUa_ByteString_Compare((OpcUa_ByteString*)xValue1, (OpcUa_ByteString*)xValue2)

#define OpcUa_XmlElement_CopyTo(xSource, xDestination) OpcUa_ByteString_CopyTo((OpcUa_ByteString*)xSource, (OpcUa_ByteString*)xDestination)

/*============================================================================
 * The NodeId type
 *===========================================================================*/

/** \enum OpcUa_IdentifierType
 * The set of known node identifier types
 *
 * \var IdentifierType::OpcUa_IdentifierType_Numeric 
 * Numeric value
 *
 * \var IdentifierType:: OpcUa_IdentifierType_String
 * String value
 *
 * \var IdentifierType::OpcUa_IdentifierType_Guid
 * Globally Unique %Identifier
 *
 * \var IdentifierType::OpcUa_IdentifierType_Opaque
 * Namespace specific format in a ByteString
 */
typedef enum _OpcUa_IdentifierType
{
    OpcUa_IdentifierType_Numeric = 0x00,
    OpcUa_IdentifierType_String  = 0x01,
    OpcUa_IdentifierType_Guid    = 0x02,
    OpcUa_IdentifierType_Opaque  = 0x03
}
OpcUa_IdentifierType;

/** \struct OpcUa_NodeId
 *  An identifier for a node in the address space of an OPC UA Server.
 * 
 * A Server shall persist the NodeId of a Node, that is, it is not
 * allowed to generate new NodeIds when rebooting. The server is not
 * allowed to change the namespace index for a namespace URI as long as
 * the server is not restarted, but new namespaces can be added.  The
 * namespace index for a namespace URI may change after a server
 * restart.
 *
 * Clients must be prepared for changes of the namespace index in a
 * NodeId and must persist their own namespace table together with the
 * stored NodeIds for a server.
 *
 * The following three elements identify a Node within a Server:
 *
 * Name           | Type   | Description
 * ---------------|--------|------------------------------------------------------------------
 * namespaceIndex | UInt16 | The index for a namespace URI used in an OPC UA server
 * identifierType | enum   | The format and data type of the identifier
 * identifier     | *      | The identifier for a node in the address space of an OPC UA server
 *
 * <b>Namespace Index</b>
 *
 * The namespace is a URI that identifies the naming authority
 * responsible for assigning the identifier element of the
 * NodeId. Naming authorities include the local server, the underlying
 * system, standards bodies and consortia. It is expected that most
 * nodes will use the URI of the server or of the underlying system.
 *
 * Using a namespace URI allows multiple OPC UA servers attached to
 * the same underlying system to use the same identifier to identify
 * the same object. This enables clients that connect to those Servers
 * to recognise Objects that they have in common.
 *
 * Namespace URIs are identified by numeric values in OPC UA services
 * to permit more efficient transfer and processing (e.g. table
 * lookups). The numeric values used to identify namespaces correspond
 * to the index into the NamespaceArray. The NamespaceArray is a
 * variable that is part of the Server object in the address space.
 *
 * The URI for the OPC UA namespace is
 * “http://opcfoundation.org/UA/”. Its corresponding index in the
 * namespace table is 0.
 *
 * The Namespace URI is case sensitive.
 *
 * <b>%Identifier Type</b>
 *
 * The IdentifierType element identifies the type of the NodeId, its
 * format and its scope. The following IdentifierTypes are available:
 *
 * Value                        | Description
 * -----------------------------|--------------------------------------------
 * OpcUa_IdentifierType_Numeric | Numeric value
 * OpcUa_IdentifierType_String  | String value
 * OpcUa_IdentifierType_Guid    | Globally Unique %Identifier
 * OpcUa_IdentifierType_Opaque  | Namespace specific format in a ByteString
 *
 * <b>%Identifier value</b>
 *
 * The identifier value element is used within the context of the
 * first two elements to identify a node. Its data type and format is
 * defined by the identifierType.
 *
 * Numeric identifiers are typically used for static namespaces or for
 * NodeIds in generated code.  Such identifiers in generated code have
 * typically defines generated which makes them easy to use and read
 * in code.
 *
 * String identifiers are typically used for nodes that are
 * dynamically generated during system configuration. The string is
 * either a path of nodes with a server specific delimiters or a
 * server specific addressing schema contained in the string.
 *
 * String identifiers are case sensitive. That is, clients shall
 * consider them case sensitive.  Servers are allowed to provide
 * alternative NodeIds and using this mechanism severs can handle
 * NodeIds as case insensitive.
 *
 * Normally the scope of NodeIds is the server in which they are
 * defined. For certain types of NodeIds, NodeIds can uniquely
 * identify a Node within a system, or across systems (e.g. GUIDs).
 * System-wide and globally-unique identifiers allow clients to track
 * Nodes, such as work orders, as they move between OPC UA servers as
 * they progress through the system.
 *
 * Opaque identifiers are identifiers that are free-format byte
 * strings that might or might not be human interpretable.
 *
 * Identifier values of IdentifierType STRING are restricted to 4096
 * characters. Identifier values of IdentifierType OPAQUE are
 * restricted to 4096 bytes.
 *
 * A null NodeId has special meaning. For example, many services
 * define special behaviour if a null NodeId is passed as a
 * parameter. A null NodeId always has a NamespaceIndex equal to 0. A
 * node in the address space cannot have a null NodeId.  Each
 * identifier type has a set of identifier values that represent a
 * null NodeId:
 *
 * %Identifier Type | %Identifier
 * -----------------|-------------------------------------------------
 * NUMERIC          | 0
 * STRING           | A null or Empty String (“”)
 * GUID             | A Guid initialised with zeros (e.g. 00000000-0000-0000-0000-000000)
 * OPAQUE           | A ByteString with Length=0
 *
 * \var OpcUa_NodeId::NamespaceIndex
 * The index for a namespace URI.
 *
 * \var OpcUa_NodeId::IdentifierType
 * The format and data type of the identifier.
 *
 * \union OpcUa_NodeId::Identifier
 * The identifier for a Node in the AddressSpace of an OPC UA Server.
 *
 */
typedef struct _OpcUa_NodeId
{
    OpcUa_UInt16 IdentifierType;
    OpcUa_UInt16 NamespaceIndex;

    union _Identifier
    {
        OpcUa_UInt32     Numeric;    /**< \memberof OpcUa_NodeId::Identifier Numeric value */
        OpcUa_String     String;     /**< \memberof OpcUa_NodeId::Identifier String value */
        OpcUa_Guid*      Guid;       /**< \memberof OpcUa_NodeId::Identifier Globally Unique %Identifier */
        OpcUa_ByteString ByteString; /**< \memberof OpcUa_NodeId::Identifier Namespace specific format in a ByteString */
    }
    Identifier;
}
OpcUa_NodeId;

OPCUA_EXPORT OpcUa_Void OpcUa_NodeId_Initialize(OpcUa_NodeId* pValue);

OPCUA_EXPORT OpcUa_Void OpcUa_NodeId_Clear(OpcUa_NodeId* pValue);

OPCUA_EXPORT OpcUa_Int OpcUa_NodeId_Compare(const OpcUa_NodeId* pValue1, const OpcUa_NodeId* pValue2);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_NodeId_CopyTo(const OpcUa_NodeId* pSource, OpcUa_NodeId* pDestination);

OPCUA_EXPORT OpcUa_Boolean OpcUa_NodeId_IsNull(OpcUa_NodeId* pValue);

/*============================================================================
 * The ExpandedNodeId type
 *===========================================================================*/
/** \struct OpcUa_ExpandedNodeId
 * Extends the NodeId structure by allowing the NamespaceUri to be
 * explicitly specified instead of using the NamespaceIndex.
 *
 * The NamespaceUri is optional. If it is specified, the
 * NamespaceIndex inside the NodeId shall be ignored.
 *
 * An instance of an ExpandedNodeId may still use the NamespaceIndex
 * instead of the NamespaceUri. In this case, the NamespaceUri is ignored.
 *
 * The possible fields are shown in the following table:
 *
 * \sa OpcUa_NodeId
 *
 * \var OpcUa_ExpandedNodeId::NodeId
 * The NodeId for a node in the Adress Space (see OpcUa_NodeId).
 *
 * \var OpcUa_ExpandedNodeId::NamespaceUri
 * This index is the index of that Server in the local Server’s Server
 * table. The index of the local Server in the Server table is always
 * 0. All remote Servers have indexes greater than 0. The Server table
 * is contained in the Server Object in the AddressSpace (see Part 3
 * and Part 5 of the OPC UA Specification). The Client may read the
 * Server table Variable to access the description of the target
 * Server.
 * 
 * \var OpcUa_ExpandedNodeId::ServerIndex
 * The URI of the namespace.
 *
 * If this parameter is specified, the namespace index is ignored.
 */
typedef struct _OpcUa_ExpandedNodeId
{
    OpcUa_NodeId NodeId;
    OpcUa_String NamespaceUri;
    OpcUa_UInt32 ServerIndex;
}
OpcUa_ExpandedNodeId;

OPCUA_EXPORT OpcUa_Void OpcUa_ExpandedNodeId_Initialize(OpcUa_ExpandedNodeId* pValue);

OPCUA_EXPORT OpcUa_Void OpcUa_ExpandedNodeId_Clear(OpcUa_ExpandedNodeId* pValue);

OPCUA_EXPORT OpcUa_Int OpcUa_ExpandedNodeId_Compare(const OpcUa_ExpandedNodeId* pValue1, const OpcUa_ExpandedNodeId* pValue2);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ExpandedNodeId_CopyTo(const OpcUa_ExpandedNodeId* pSource, OpcUa_ExpandedNodeId* pDestination);

OPCUA_EXPORT OpcUa_Boolean OpcUa_ExpandedNodeId_IsNull(OpcUa_ExpandedNodeId* pValue);

/*============================================================================
 * The StatusCode type
 *===========================================================================*/

#define OpcUa_StatusCode_Initialize(xValue) *(xValue) = (OpcUa_StatusCode)0;

#define OpcUa_StatusCode_Clear(xValue) *(xValue) = (OpcUa_StatusCode)0;

#define OpcUa_StatusCode_Compare(xValue1, xValue2) OpcUa_UInt32_Compare(xValue1, xValue2)

#define OpcUa_StatusCode_CopyTo(xSource, xDestination) OpcUa_UInt32_CopyTo(xSource, xDestination)

/*============================================================================
 * The DiagnosticsInfo type
 *===========================================================================*/
/** \struct OpcUa_DiagnosticInfo
 *  Vendor-specific diagnostic information.
 *
 * The SymbolicId, NamespaceUri, LocalizedText and Locale fields are
 * indexes in a string table which is returned in the response
 * header. Only the index of the corresponding string in the string
 * table is encoded. An index of −1 indicates that there is no value
 * for the string.
 *
 * DiagnosticInfo allows unlimited nesting which could result in stack
 * overflow errors even if the message size is less than the maximum
 * allowed. Decoders shall support at least 100 nesting
 * levels. Decoders shall report an error if the number of nesting
 * levels exceeds what it supports.
 *
 * \var OpcUa_DiagnosticInfo::NamespaceUri
 * The SymbolicId is defined within the context of a namespace.
 *
 * This namespace is represented as a string and is conveyed to the
 * Client in the \ref OpcUa_ResponseHeader::StringTable "StringTable"
 * parameter of the \ref OpcUa_ResponseHeader parameter. The
 * namespaceIndex parameter contains the index into the \ref
 * OpcUa_ResponseHeader::StringTable "StringTable" for this string. -1
 * indicates that no string is specified.
 *
 * The NamespaceUri shall not be the standard OPC UA namespace. There
 * are no SymbolicIds provided for standard StatusCodes.
 *
 * \var OpcUa_DiagnosticInfo::SymbolicId
 * The symbolicId shall be used to identify a vendor-specific error or
 * condition; typically the result of some server internal operation.
 *
 * The maximum length of this string is 32 characters. Servers wishing
 * to return a numeric return code should convert the return code into
 * a string and use this string as symbolicId (e.g., "0xC0040007" or
 * "-4").
 *
 * This symbolic identifier string is conveyed to the Client in the
 * \ref OpcUa_ResponseHeader::StringTable "StringTable" parameter of
 * the \ref OpcUa_ResponseHeader parameter. The SymbolicId parameter
 * contains the index into the \ref OpcUa_ResponseHeader::StringTable
 * "StringTable" for this string. -1 indicates that no string is
 * specified.
 *
 * The SymbolicId shall not contain StatusCodes. If the LocalizedText
 * contains a translation for the description of a StatusCode, the
 * symbolicId is -1.
 *
 * \var OpcUa_DiagnosticInfo::Locale
 * The locale part of the vendor-specific localized text describing
 * the symbolic id.
 *
 * This localized text string is conveyed to the Client in the \ref
 * OpcUa_ResponseHeader::StringTable "StringTable" parameter of the
 * \ref OpcUa_ResponseHeader parameter. The Locale parameter contains
 * the index into the \ref OpcUa_ResponseHeader::StringTable
 * "StringTable" for this string. -1 indicates that no string is
 * specified.
 *
 * \var OpcUa_DiagnosticInfo::LocalizedText
 * A vendor-specific localized text string that describes the symbolic id.
 *
 * The maximum length of this text string is 256 characters. This
 * localized text string is conveyed to the Client in the \ref
 * OpcUa_ResponseHeader::StringTable "StringTable" parameter of the
 * \ref OpcUa_ResponseHeader parameter. The LocalizedText parameter
 * contains the index into the \ref OpcUa_ResponseHeader::StringTable
 * "StringTable" for this string. -1 indicates that no string is
 * specified.
 *
 * The LocalizedText refers to the SymbolicId if present or the string
 * that describes the standard StatusCode if the server provides
 * translations. If the index is -1, the server has no translation to
 * return and the client should use the invariant StatusCode
 * description from the specification.
 *
 * \var OpcUa_DiagnosticInfo::AdditionalInfo
 * Vendor-specific diagnostic information.
 *
 * \var OpcUa_DiagnosticInfo::InnerStatusCode
 * The StatusCode from the inner operation.
 *
 * Many applications will make calls into underlying systems during
 * OPC UA request processing. An OPC UA Server has the option of
 * reporting the status from the underlying system in the diagnostic
 * info.
 *
 * \var OpcUa_DiagnosticInfo::InnerDiagnosticInfo
 * The diagnostic info associated with the inner StatusCode.
 */
typedef struct _OpcUa_DiagnosticInfo
{
    OpcUa_Int32                   SymbolicId;
    OpcUa_Int32                   NamespaceUri;
    OpcUa_Int32                   Locale;
    OpcUa_Int32                   LocalizedText;
    OpcUa_String                  AdditionalInfo;
    OpcUa_StatusCode              InnerStatusCode;
    struct _OpcUa_DiagnosticInfo* InnerDiagnosticInfo;
}
OpcUa_DiagnosticInfo;

OPCUA_EXPORT OpcUa_Void OpcUa_DiagnosticInfo_Initialize(OpcUa_DiagnosticInfo* value);

OPCUA_EXPORT OpcUa_Void OpcUa_DiagnosticInfo_Clear(OpcUa_DiagnosticInfo* value);

OPCUA_EXPORT OpcUa_Int OpcUa_DiagnosticInfo_Compare(const OpcUa_DiagnosticInfo* pValue1, const OpcUa_DiagnosticInfo* pValue2);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DiagnosticInfo_CopyTo(const OpcUa_DiagnosticInfo* pSource, OpcUa_DiagnosticInfo* pDestination);

/*============================================================================
 * The LocalizedText structure.
 *===========================================================================*/
/** \struct OpcUa_LocalizedText
 * A structure containing a String in a locale-specific translation
 * specified in the identifier for the locale.
 *
 * \var OpcUa_LocalizedText::Locale
 * The identifier for the locale, for instance “en-US”.
 * \var OpcUa_LocalizedText::Text
 * The text in the language given by Locale.
 */
typedef struct _OpcUa_LocalizedText
{
    OpcUa_String Locale;
    OpcUa_String Text;
}
OpcUa_LocalizedText;

OPCUA_EXPORT OpcUa_Void OpcUa_LocalizedText_Initialize(OpcUa_LocalizedText* pValue);

OPCUA_EXPORT OpcUa_Void OpcUa_LocalizedText_Clear(OpcUa_LocalizedText* pValue);

OPCUA_EXPORT OpcUa_Int OpcUa_LocalizedText_Compare(const OpcUa_LocalizedText* pValue1, const OpcUa_LocalizedText* pValue2);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_LocalizedText_CopyTo(const OpcUa_LocalizedText* pSource, OpcUa_LocalizedText* pDestination);

/*============================================================================
 * The QualifiedName structure.
 *===========================================================================*/
/** \struct OpcUa_QualifiedName
 *   Contains a qualified name.
 *
 * It is, for example, used as BrowseName. The name part of the
 * QualifiedName is restricted to 512 characters.
 *
 * \var OpcUa_QualifiedName::NamespaceIndex
 * Index that identifies the namespace that defines the name.
 * 
 * This index is the index of that namespace in the local Server’s
 * NamespaceArray.
 *
 * The Client may read the NamespaceArray Variable to access the
 * string value of the namespace.
 *
 * \var OpcUa_QualifiedName::Name
 * The text portion of the QualifiedName.
 */
typedef struct _OpcUa_QualifiedName
{
    OpcUa_UInt16 NamespaceIndex;
    OpcUa_UInt16 Reserved;
    OpcUa_String Name;
}
OpcUa_QualifiedName;

OPCUA_EXPORT OpcUa_Void OpcUa_QualifiedName_Initialize(OpcUa_QualifiedName* pValue);

OPCUA_EXPORT OpcUa_Void OpcUa_QualifiedName_Clear(OpcUa_QualifiedName* pValue);

OPCUA_EXPORT OpcUa_Int OpcUa_QualifiedName_Compare(const OpcUa_QualifiedName* pValue1, const OpcUa_QualifiedName* pValue2);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_QualifiedName_CopyTo(const OpcUa_QualifiedName* pSource, OpcUa_QualifiedName* pDestination);

/*============================================================================
 * String extensions
 *===========================================================================*/
#define OpcUa_String_Compare(xValue1, xValue2) OpcUa_String_StrnCmp(xValue1, xValue2, OPCUA_STRING_LENDONTCARE, OpcUa_False)
#define OpcUa_String_CopyTo(xSource, xDestination) OpcUa_String_StrnCpy(xDestination, xSource, OPCUA_STRING_LENDONTCARE)

/*============================================================================
 * The OpcUa_ExtensionObject type
 *===========================================================================*/
struct _OpcUa_EncodeableType;

/** \enum OpcUa_ExtensionObjectEncoding
 * Indicates how the body of an OpcUa_ExtensionObject is encoded.
 *
 * \var OpcUa_ExtensionObjectEncoding::OpcUa_ExtensionObjectEncoding_None
 * No body is encoded.
 * 
 * \var OpcUa_ExtensionObjectEncoding::OpcUa_ExtensionObjectEncoding_Binary
 * The body is encoded according to the binary encoding rules.
 * 
 * \var OpcUa_ExtensionObjectEncoding::OpcUa_ExtensionObjectEncoding_Xml
 * The body is encoded according to the XML encoding rules.
 * 
 * \var OpcUa_ExtensionObjectEncoding::OpcUa_ExtensionObjectEncoding_EncodeableObject
 * The object is contained unencoded as an encodeable object.
 */
typedef enum _OpcUa_ExtensionObjectEncoding
{
    OpcUa_ExtensionObjectEncoding_None = 0,
    OpcUa_ExtensionObjectEncoding_Binary = 1,
    OpcUa_ExtensionObjectEncoding_Xml = 2,
    OpcUa_ExtensionObjectEncoding_EncodeableObject = 3
}
OpcUa_ExtensionObjectEncoding;

/** \struct OpcUa_ExtensionObject
 * A container for any structured DataTypes which cannot be represented
 * as one of the other built-in data types.
 *
 * The ExtensionObject contains a complex value serialized as a
 * sequence of bytes, as an XML element or not encoded as an
 * Encodeable. It also contains an identifier which indicates what
 * data it contains and how it is encoded.
 *
 * Structured DataTypes are represented in a Server address space as
 * subtypes of the Structure DataType. The DataEncodings available for
 * any given structured DataTypes are represented as a
 * DataTypeEncoding object in the Server address space. The NodeId for
 * the DataTypeEncoding Object is the identifier stored in the
 * ExtensionObject. Part 3 of the OPC UA Specification describes how
 * DataTypeEncoding Nodes are related to other Nodes of the address
 * space. Server implementers should use namespace qualified numeric
 * NodeIds for any DataTypeEncoding objects they define. This will
 * minimize the overhead introduced by packing structured DataType
 * values into an ExtensionObject.
 *
 * ExtensionObjects and Variants allow unlimited nesting which could
 * result in stack overflow errors even if the message size is less
 * than the maximum allowed. Decoders shall support at least 100
 * nesting levels. Decoders shall report an error if the number of
 * nesting levels exceeds what it supports.
 *
 * An ExtensionObject is encoded as sequence of bytes prefixed by the
 * NodeId of its DataTypeEncoding and the number of bytes encoded.
 *
 * An ExtensionObject may be encoded by the Application which means it
 * is passed as a ByteString or an XmlElement to the encoder. In this
 * case, the encoder will be able to write the number of bytes in the
 * object before it encodes the bytes. However, an ExtensionObject may
 * know how to encode/decode itself which means the encoder shall
 * calculate the number of bytes before it encodes the object or it
 * shall be able to seek backwards in the stream and update the length
 * after encoding the body.

 * When a decoder encounters an ExtensionObject it shall check if it
 * recognizes the DataTypeEncoding identifier. If it does then it can
 * call the appropriate function to decode the object body. If the
 * decoder does not recognize the type it shall use the Encoding to
 * determine if the body is a ByteString or an XmlElement and then
 * decode the object body or treat it as opaque data and skip over it.
 *
 * \var OpcUa_ExtensionObject::TypeId
 * The identifier for the DataTypeEncoding node in the Server's
 * AddressSpace.
 *
 * \var OpcUa_ExtensionObject::Encoding
 * The encoding used for the body.
 *
 * \var OpcUa_ExtensionObject::BodySize
 * The length of the encoded body in bytes (updated automatically when
 * GetSize is called).
 *
 * \var OpcUa_ExtensionObject::Body
 * The body of a OpcUa_ExtensionObject as in \ref
 * OpcUa_ExtensionObjectEncoding "Encoding".
 *
 * This field contains an OpcUa_ByteString for binary encoded
 * bodies. For XML encoded bodies this field contains an
 * OpcUa_XmlElement with an UTF-8 string without any null
 * terminator. In case of an encodeable object the object is contained
 * as and OpcUa_EncodeableType.
 *
 * Some binary encoded structures may have a serialized length that is
 * not a multiple of 8 bits. Encoders shall append 0 bits to ensure
 * the serialized length is a multiple of 8 bits. Decoders that
 * understand the serialized format shall ignore the padding bits.
 */
typedef struct _OpcUa_ExtensionObject
{
    OpcUa_ExpandedNodeId TypeId;

    OpcUa_ExtensionObjectEncoding Encoding;

    union _OpcUa_ExtensionObject_Body
    {
        OpcUa_ByteString Binary; /* < \memberof OpcUa_ExtensionObject::Body A pre-encoded binary body. */

        OpcUa_XmlElement Xml;    /* < \memberof OpcUa_ExtensionObject::Body A pre-encoded XML body. */

        struct _OpcUa_EncodeableObjectBody
        {
            /*! @brief The object contained in the extension object. */
            OpcUa_Void* Object;

            /*! @brief Provides information necessary to encode/decode the object. */
            struct _OpcUa_EncodeableType* Type;
        }
        EncodeableObject;
    }
    Body;

    /*! @brief The length of the encoded body in bytes (updated automatically when GetSize is called). */
    OpcUa_Int32 BodySize;
}
OpcUa_ExtensionObject;

OPCUA_EXPORT OpcUa_Void OpcUa_ExtensionObject_Create(OpcUa_ExtensionObject** value);

OPCUA_EXPORT OpcUa_Void OpcUa_ExtensionObject_Initialize(OpcUa_ExtensionObject* value);

OPCUA_EXPORT OpcUa_Void OpcUa_ExtensionObject_Clear(OpcUa_ExtensionObject* value);

OPCUA_EXPORT OpcUa_Void OpcUa_ExtensionObject_Delete(OpcUa_ExtensionObject** value);

OPCUA_EXPORT OpcUa_Int OpcUa_ExtensionObject_Compare(const OpcUa_ExtensionObject* pValue1, const OpcUa_ExtensionObject* pValue2);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_ExtensionObject_CopyTo(const OpcUa_ExtensionObject* pSource, OpcUa_ExtensionObject* pDestination);

/*============================================================================
 * The Variant type
 *===========================================================================*/
struct _OpcUa_Variant;
struct _OpcUa_DataValue;

/* A union that contains arrays of one of the built in types. */
typedef union _OpcUa_VariantArrayUnion
{
    OpcUa_Void*              Array;
    OpcUa_Boolean*           BooleanArray;
    OpcUa_SByte*             SByteArray;
    OpcUa_Byte*              ByteArray;
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
    OpcUa_QualifiedName*     QualifiedNameArray;
    OpcUa_LocalizedText*     LocalizedTextArray;
    OpcUa_ExtensionObject*   ExtensionObjectArray;
    struct _OpcUa_DataValue* DataValueArray;
    struct _OpcUa_Variant*   VariantArray;
}
OpcUa_VariantArrayUnion;

/* A union that contains a one dimensional array of one of the built in types. */
typedef struct _OpcUa_VariantArrayValue
{
    /* The total number of elements in all dimensions. */
    OpcUa_Int32  Length;

    /* The data stored in the array. */
    OpcUa_VariantArrayUnion Value;
}
OpcUa_VariantArrayValue;

/* A union that contains a multi-dimensional array of one of the built in types. */
typedef struct _OpcUa_VariantMatrixValue
{
    /* The number of dimensions in the array. */
    OpcUa_Int32 NoOfDimensions;

    /* The length of each dimension. */
    OpcUa_Int32* Dimensions;

    /* The data stored in the array.

       The higher rank dimensions appear in the array first.
       e.g. a array with dimensions [2,2,2] is written in this order:
       [0,0,0], [0,0,1], [0,1,0], [0,1,1], [1,0,0], [1,0,1], [1,1,0], [1,1,1]

       Using [3] to access the pointer stored in this field would return element [0,1,1] */
    OpcUa_VariantArrayUnion Value;
}
OpcUa_VariantMatrixValue;

/* Returns the total number of elements stored in a matrix value. */
OPCUA_EXPORT OpcUa_StatusCode OpcUa_VariantMatrix_GetElementCount(const OpcUa_VariantMatrixValue* pValue,
                                                                  OpcUa_Int32*                    pLength);

/* A union that contains one of the built in types. */
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
#if !OPCUA_VARIANT_OMIT_MATRIX
    OpcUa_VariantMatrixValue Matrix;
#endif /* !OPCUA_VARIANT_OMIT_MATRIX */
}
OpcUa_VariantUnion;

#define OpcUa_VariantArrayType_Scalar 0x00
#define OpcUa_VariantArrayType_Array  0x01
#define OpcUa_VariantArrayType_Matrix 0x02

/** \struct OpcUa_Variant
 *  A union of all built-in data types including an OpcUa_ExtensionObject.
 *
 * Variants can also contain arrays of any of these built-in
 * types. Variants are used to store any value or parameter with a
 * data type of BaseDataType or one of its subtypes.
 *
 * Variants can be empty. An empty Variant is described as having a
 * null value and should be treated like a null column in a SQL
 * database. A null value in a Variant may not be the same as a null
 * value for data types that support nulls such as Strings. Some
 * development platforms may not be able to preserve the distinction
 * between a null for a DataType and a null for a Variant. Therefore
 * applications shall not rely on this distinction.
 *
 * Variants can contain arrays of Variants but they cannot directly
 * contain another Variant.
 *
 * DataValue and DiagnosticInfo types only have meaning when returned
 * in a response message with an associated StatusCode. As a result,
 * Variants cannot contain instances of DataValue or
 * DiagnosticInfo. This requirement means that if an attribute
 * supports the writing of a null value, it shall also support writing
 * of an empty Variant and vice versa.
 *
 * Variables with a DataType of BaseDataType are mapped to a Variant,
 * however, the ValueRank and ArrayDimensions attributes place
 * restrictions on what is allowed in the Variant. For example, if the
 * ValueRank is Scalar, the Variant may only contain scalar values.
 * 
 * ExtensionObjects and Variants allow unlimited nesting which could
 * result in stack overflow errors even if the message size is less
 * than the maximum allowed. Decoders shall support at least 100
 * nesting levels. Decoders shall report an error if the number of
 * nesting levels exceeds what it supports.
 *
 * \var OpcUa_Variant::Datatype
 * Indicates the data type stored in the Variant.
 *
 * This is always one of the OpcUa_BuiltInType values. It is the data
 * type of a single element if the Variant contains an array.
 *
 * \var OpcUa_Variant::ArrayType
 * A flag indicating that an array with one or more dimensions is
 * stored in the Variant.
 *
 * \var OpcUa_Variant::Value
 * The value stored in the Variant.
 */
typedef struct _OpcUa_Variant
{
    OpcUa_Byte          Datatype;

    OpcUa_Byte          ArrayType;

    /* Not used. Must be ignored. */
    OpcUa_UInt16        Reserved;

    OpcUa_VariantUnion  Value;
}
OpcUa_Variant;

OPCUA_EXPORT OpcUa_Void OpcUa_Variant_Initialize(OpcUa_Variant* value);

OPCUA_EXPORT OpcUa_Void OpcUa_Variant_Clear(OpcUa_Variant* value);

OPCUA_EXPORT OpcUa_Int OpcUa_Variant_Compare(const OpcUa_Variant* pValue1, const OpcUa_Variant* pValue2);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_Variant_CopyTo(const OpcUa_Variant* pSource, OpcUa_Variant* pDestination);

#define OpcUa_Variant_InitializeArray(xValue, xLength) OpcUa_MemSet(xValue, 0, (xLength)*sizeof(OpcUa_Variant));

#define OpcUa_Variant_ClearArray(xValue, xLength) OpcUa_ClearArray(xValue, xLength, OpcUa_Variant);

/*============================================================================
 * The DataValue type
 *===========================================================================*/
/** \struct OpcUa_DataValue
 *  The value and associated information.
 *
 * \var OpcUa_DataValue::Value
 * The data value.
 *
 * If the StatusCode indicates an error, the value is to be ignored
 * and the Server shall set it to null.
 *
 * \var OpcUa_DataValue::StatusCode
 * The StatusCode that defines with the Server’s ability to
 * access/provide the value.
 *
 * \var OpcUa_DataValue::SourceTimestamp
 * The sourceTimestamp is used to reflect the timestamp that was
 * applied to a Variable value by the data source.
 *
 * Once a value has been assigned a source timestamp, the source
 * timestamp for that value instance never changes.
 *
 * \var OpcUa_DataValue::SourcePicoseconds
 * Specifies the number of 10 picoseconds (1,0 e-11 seconds) intervals
 * which shall be added to the SourceTimestamp.
 *
 * \var OpcUa_DataValue::ServerTimestamp
 * The serverTimestamp is used to reflect the time that the Server
 * received a Variable value or knew it to be accurate.
 *
 * \var OpcUa_DataValue::ServerPicoseconds
 * Specifies the number of 10 picoseconds (1,0 e-11 seconds) intervals
 * which shall be added to the serverTimestamp.
 */
typedef struct _OpcUa_DataValue
{
    OpcUa_Variant    Value;
    OpcUa_StatusCode StatusCode;
    OpcUa_DateTime   SourceTimestamp;
    OpcUa_DateTime   ServerTimestamp;
#if !OPCUA_DATAVALUE_OMIT_PICOSECONDS
    OpcUa_UInt16     SourcePicoseconds;
    OpcUa_UInt16     ServerPicoseconds;
#endif /* !OPCUA_DATAVALUE_OMIT_PICOSECONDS */
}
OpcUa_DataValue;

OPCUA_EXPORT OpcUa_Void OpcUa_DataValue_Initialize(OpcUa_DataValue* value);

OPCUA_EXPORT OpcUa_Void OpcUa_DataValue_Clear(OpcUa_DataValue* value);

OPCUA_EXPORT OpcUa_Int OpcUa_DataValue_Compare(const OpcUa_DataValue* pValue1, const OpcUa_DataValue* pValue2);

OPCUA_EXPORT OpcUa_StatusCode OpcUa_DataValue_CopyTo(const OpcUa_DataValue* pSource, OpcUa_DataValue* pDestination);

#define OpcUa_DataValue_InitializeArray(xValue, xLength) OpcUa_MemSet(xValue, 0, (xLength)*sizeof(OpcUa_DataValue));

#define OpcUa_DataValue_ClearArray(xValue, xLength) OpcUa_ClearArray(xValue, xLength, OpcUa_DataValue);

/*============================================================================
 * OpcUa_Field_Initialize
 *===========================================================================*/
#define OpcUa_Field_Initialize(xType, xName) OpcUa_##xType##_Initialize(&a_pValue->xName);

/*============================================================================
 * OpcUa_Field_InitializeEncodeable
 *===========================================================================*/
#define OpcUa_Field_InitializeEncodeable(xType, xName) xType##_Initialize(&a_pValue->xName);

/*============================================================================
 * OpcUa_Field_InitializeEnumerated
 *===========================================================================*/
#define OpcUa_Field_InitializeEnumerated(xType, xName) xType##_Initialize(&a_pValue->xName);

/*============================================================================
 * OpcUa_Field_InitializeArray
 *===========================================================================*/
#define OpcUa_Field_InitializeArray(xType, xName) \
{ \
    a_pValue->xName = OpcUa_Null; \
    a_pValue->NoOf##xName = 0; \
}

/*============================================================================
 * OpcUa_Field_InitializeEncodeableArray
 *===========================================================================*/
#define OpcUa_Field_InitializeEncodeableArray(xType, xName) OpcUa_Field_InitializeArray(xType, xName)

/*============================================================================
 * OpcUa_Field_InitializeEnumeratedArray
 *===========================================================================*/
#define OpcUa_Field_InitializeEnumeratedArray(xType, xName) OpcUa_Field_InitializeArray(xType, xName)

/*============================================================================
 * OpcUa_Field_Clear
 *===========================================================================*/
#define OpcUa_Field_Clear(xType, xName) OpcUa_##xType##_Clear(&a_pValue->xName);

/*============================================================================
 * OpcUa_Field_ClearEncodeable
 *===========================================================================*/
#define OpcUa_Field_ClearEncodeable(xType, xName) xType##_Clear(&a_pValue->xName);

/*============================================================================
 * OpcUa_Field_ClearEnumerated
 *===========================================================================*/
#define OpcUa_Field_ClearEnumerated(xType, xName) xType##_Clear(&a_pValue->xName);

/*============================================================================
 * OpcUa_Field_ClearArray
 *===========================================================================*/
#define OpcUa_Field_ClearArray(xType, xName)\
{ \
    int ii; \
\
    for (ii = 0; ii < a_pValue->NoOf##xName && a_pValue->xName != OpcUa_Null; ii++) \
    { \
        OpcUa_##xType##_Clear(&(a_pValue->xName[ii])); \
    } \
\
    OpcUa_Free(a_pValue->xName); \
\
    a_pValue->xName = OpcUa_Null; \
    a_pValue->NoOf##xName = 0; \
}

/*============================================================================
 * OpcUa_Field_ClearEncodeableArray
 *===========================================================================*/
#define OpcUa_Field_ClearEncodeableArray(xType, xName) \
{ \
    int ii; \
\
    for (ii = 0; ii < a_pValue->NoOf##xName && a_pValue->xName != OpcUa_Null; ii++) \
    { \
        xType##_Clear(&(a_pValue->xName[ii])); \
    } \
\
    OpcUa_Free(a_pValue->xName); \
\
    a_pValue->xName = OpcUa_Null; \
    a_pValue->NoOf##xName = 0; \
}

/*============================================================================
 * OpcUa_Field_ClearEnumeratedArray
 *===========================================================================*/
#define OpcUa_Field_ClearEnumeratedArray(xType, xName) \
{ \
    OpcUa_Free(a_pValue->xName); \
    a_pValue->xName = OpcUa_Null; \
    a_pValue->NoOf##xName = 0; \
}

/*============================================================================
 * OpcUa_Field_Compare
 *===========================================================================*/
#define OpcUa_Field_Compare(xType, xName) {OpcUa_Int i = OpcUa_##xType##_Compare(&a_pValue1->xName, &a_pValue2->xName); if(i) return i;}

/*============================================================================
 * OpcUa_Field_CompareEncodeable
 *===========================================================================*/
#define OpcUa_Field_CompareEncodeable(xType, xName) {OpcUa_Int i = xType##_Compare(&a_pValue1->xName, &a_pValue2->xName); if(i) return i;}

/*============================================================================
 * OpcUa_Field_CompareEnumerated
 *===========================================================================*/
#define OpcUa_Field_CompareEnumerated(xType, xName) {OpcUa_Int i = OpcUa_Int32_Compare(&a_pValue1->xName, &a_pValue2->xName); if(i) return i;}

/*============================================================================
 * OpcUa_Field_CompareArray
 *===========================================================================*/
#define OpcUa_Field_CompareArray(xType, xName)\
{ \
    int ii; \
\
    if(a_pValue1->NoOf##xName != a_pValue2->NoOf##xName) \
    { \
        return 1; \
    } \
\
    for (ii = 0; ii < a_pValue1->NoOf##xName && a_pValue1->xName != OpcUa_Null; ii++) \
    { \
        if(OpcUa_##xType##_Compare(&(a_pValue1->xName[ii]), &(a_pValue2->xName[ii]))){return 1;}; \
    } \
}

/*============================================================================
 * OpcUa_Field_CompareEncodeableArray
 *===========================================================================*/
#define OpcUa_Field_CompareEncodeableArray(xType, xName) \
{ \
    int ii; \
\
    for (ii = 0; ii < a_pValue1->NoOf##xName && a_pValue1->xName != OpcUa_Null; ii++) \
    { \
        if(xType##_Compare(&(a_pValue1->xName[ii]), &(a_pValue2->xName[ii]))){return 1;}; \
    } \
}

/*============================================================================
 * OpcUa_Field_CompareEnumeratedArray
 *===========================================================================*/
#define OpcUa_Field_CompareEnumeratedArray(xType, xName) \
{ \
    int ii; \
\
    for (ii = 0; ii < a_pValue1->NoOf##xName && a_pValue1->xName != OpcUa_Null; ii++) \
    { \
        if(a_pValue1->xName[ii] != a_pValue2->xName[ii]){return 1;}; \
    } \
}

/*============================================================================
 * OpcUa_Field_Copy
 *===========================================================================*/
#define OpcUa_Field_Copy(xType, xName) \
{ \
    a_pDestination->xName = (OpcUa_##xType*)OpcUa_Alloc(sizeof(OpcUa_##xType)); \
    OpcUa_GotoErrorIfAllocFailed(a_pDestination->xName); \
    OpcUa_##xType##_Initialize(a_pDestination->xName); \
    uStatus = OpcUa_##xType##_CopyTo(a_pSource->xName, a_pDestination->xName); \
    OpcUa_GotoErrorIfBad(uStatus); \
}

/*============================================================================
 * OpcUa_Field_CopyTo
 *===========================================================================*/
#define OpcUa_Field_CopyTo(xType, xName) uStatus = OpcUa_##xType##_CopyTo(&(a_pSource->xName), &(a_pDestination->xName)); OpcUa_GotoErrorIfBad(uStatus);

/*============================================================================
 * OpcUa_Field_CopyToScalar
 *===========================================================================*/
#define OpcUa_Field_CopyToScalar(xType, xName) (a_pDestination->xName = a_pSource->xName)

/*============================================================================
 * OpcUa_Field_CopyToEncodeable
 *===========================================================================*/
#define OpcUa_Field_CopyToEncodeable(xType, xName) xType##_CopyTo(&a_pSource->xName, &a_pDestination->xName)

/*============================================================================
 * OpcUa_Field_CopyToEnumerated
 *===========================================================================*/
#define OpcUa_Field_CopyToEnumerated(xType, xName) a_pDestination->xName = a_pSource->xName

/*============================================================================
 * OpcUa_Field_CopyToArray
 *===========================================================================*/
#define OpcUa_Field_CopyToArray(xType, xName)\
{ \
    int ii; \
\
    for (ii = 0; ii < a_pSource->NoOf##xName && a_pSource->xName != OpcUa_Null; ii++) \
    { \
        uStatus = OpcUa_##xType##_CopyTo(&(a_pSource->xName[ii]), &(a_pDestination->xName[ii])); \
        OpcUa_GotoErrorIfBad(uStatus); \
    } \
}

/*============================================================================
 * OpcUa_Field_CopyArray
 *===========================================================================*/
#define OpcUa_Field_CopyArray(xType, xName)\
if(a_pSource->NoOf##xName > 0 && a_pSource->xName != OpcUa_Null) \
{ \
    int ii; \
\
    a_pDestination->xName = (OpcUa_##xType*)OpcUa_Alloc(sizeof(OpcUa_##xType) * a_pSource->NoOf##xName); \
    OpcUa_GotoErrorIfAllocFailed(a_pDestination->xName); \
    OpcUa_MemSet(a_pDestination->xName, 0, sizeof(OpcUa_##xType) * a_pSource->NoOf##xName); \
\
    for (ii = 0; ii < a_pSource->NoOf##xName && a_pSource->xName != OpcUa_Null; ii++) \
    { \
        uStatus = OpcUa_##xType##_CopyTo(&(a_pSource->xName[ii]), &(a_pDestination->xName[ii])); \
        OpcUa_GotoErrorIfBad(uStatus); \
    } \
    a_pDestination->NoOf##xName = a_pSource->NoOf##xName; \
} \
else \
{ \
    a_pDestination->NoOf##xName = 0; \
    a_pDestination->xName = OpcUa_Null; \
}

/*============================================================================
 * OpcUa_Field_CopyToEncodeableArray
 *===========================================================================*/
#define OpcUa_Field_CopyToEncodeableArray(xType, xName) \
{ \
    int ii; \
\
    for (ii = 0; ii < a_pSource->NoOf##xName && a_pSource->xName != OpcUa_Null; ii++) \
    { \
        xType##_CopyTo(&(a_pSource->xName[ii]), &(a_pDestination->xName[ii])); \
    } \
}

/*============================================================================
 * OpcUa_Field_CopyEncodeableArray
 *===========================================================================*/
#define OpcUa_Field_CopyEncodeableArray(xType, xName) \
if(a_pSource->NoOf##xName > 0 && a_pSource->xName != OpcUa_Null) \
{ \
    int ii; \
\
    a_pDestination->xName = (xType*)OpcUa_Alloc(sizeof(xType) * a_pSource->NoOf##xName); \
    OpcUa_GotoErrorIfAllocFailed(a_pDestination->xName); \
    OpcUa_MemSet(a_pDestination->xName, 0, sizeof(xType) * a_pSource->NoOf##xName); \
\
    for (ii = 0; ii < a_pSource->NoOf##xName && a_pSource->xName != OpcUa_Null; ii++) \
    { \
        xType##_CopyTo(&(a_pSource->xName[ii]), &(a_pDestination->xName[ii])); \
    } \
    a_pDestination->NoOf##xName = a_pSource->NoOf##xName; \
} \
else \
{ \
    a_pDestination->NoOf##xName = 0; \
    a_pDestination->xName = OpcUa_Null; \
}

/*============================================================================
 * OpcUa_Field_CopyEnumeratedArray
 *===========================================================================*/
#define OpcUa_Field_CopyEnumeratedArray(xType, xName) \
if(a_pSource->NoOf##xName > 0 && a_pSource->xName != OpcUa_Null) \
{ \
    a_pDestination->xName = (xType*)OpcUa_Alloc(a_pSource->NoOf##xName * sizeof(xType)); \
    OpcUa_GotoErrorIfAllocFailed(a_pDestination->xName); \
    OpcUa_MemCpy(a_pDestination->xName, a_pSource->NoOf##xName * sizeof(xType), a_pSource->xName, a_pSource->NoOf##xName * sizeof(xType)); \
    a_pDestination->NoOf##xName = a_pSource->NoOf##xName; \
} \
else \
{ \
    a_pDestination->NoOf##xName = 0; \
    a_pDestination->xName = OpcUa_Null; \
}

/*============================================================================
 * OpcUa_Field_CopyScalarArray
 *===========================================================================*/
#define OpcUa_Field_CopyScalarArray(xType, xName) \
if(a_pSource->NoOf##xName > 0 && a_pSource->xName != OpcUa_Null) \
{ \
    a_pDestination->xName = (OpcUa_##xType*)OpcUa_Alloc(a_pSource->NoOf##xName * sizeof(OpcUa_##xType)); \
    OpcUa_GotoErrorIfAllocFailed(a_pDestination->xName); \
    OpcUa_MemCpy(a_pDestination->xName, a_pSource->NoOf##xName * sizeof(OpcUa_##xType), a_pSource->xName, a_pSource->NoOf##xName * sizeof(OpcUa_##xType)); \
    a_pDestination->NoOf##xName = a_pSource->NoOf##xName; \
} \
else \
{ \
    a_pDestination->NoOf##xName = 0; \
    a_pDestination->xName = OpcUa_Null; \
}

/*============================================================================
 * OpcUa_UnionField_Initialize
 *===========================================================================*/
#define OpcUa_UnionField_Initialize(xType, xName) OpcUa_##xType##_Initialize(&a_pValue->Value.xName);

/*============================================================================
 * OpcUa_UnionField_InitializeEncodeable
 *===========================================================================*/
#define OpcUa_UnionField_InitializeEncodeable(xType, xName) xType##_Initialize(&a_pValue->Value.xName);

/*============================================================================
 * OpcUa_UnionField_InitializeEnumerated
 *===========================================================================*/
#define OpcUa_UnionField_InitializeEnumerated(xType, xName) xType##_Initialize(&a_pValue->Value.xName);

/*============================================================================
 * OpcUa_UnionField_InitializeArray
 *===========================================================================*/
#define OpcUa_UnionField_InitializeArray(xType, xName) \
{ \
    a_pValue->Value.xName.Data = OpcUa_Null; \
    a_pValue->Value.xName.Count = 0; \
}

/*============================================================================
 * OpcUa_UnionField_InitializeEncodeableArray
 *===========================================================================*/
#define OpcUa_UnionField_InitializeEncodeableArray(xType, xName) OpcUa_UnionField_InitializeArray(xType, xName)

/*============================================================================
 * OpcUa_UnionField_InitializeEnumeratedArray
 *===========================================================================*/
#define OpcUa_UnionField_InitializeEnumeratedArray(xType, xName) OpcUa_UnionField_InitializeArray(xType, xName)

/*============================================================================
 * OpcUa_UnionField_Clear
 *===========================================================================*/
#define OpcUa_UnionField_Clear(xType, xName) OpcUa_##xType##_Clear(&a_pValue->Value.xName);

/*============================================================================
 * OpcUa_UnionField_ClearEncodeable
 *===========================================================================*/
#define OpcUa_UnionField_ClearEncodeable(xType, xName) xType##_Clear(&a_pValue->Value.xName);

/*============================================================================
 * OpcUa_UnionField_ClearEnumerated
 *===========================================================================*/
#define OpcUa_UnionField_ClearEnumerated(xType, xName) xType##_Clear(&a_pValue->Value.xName);

/*============================================================================
 * OpcUa_UnionField_ClearArray
 *===========================================================================*/
#define OpcUa_UnionField_ClearArray(xType, xName)\
{ \
    int ii; \
\
    for (ii = 0; ii < a_pValue->Value.xName.Count && a_pValue->Value.xName.Data != OpcUa_Null; ii++) \
    { \
        OpcUa_##xType##_Clear(&(a_pValue->Value.xName.Data[ii])); \
    } \
\
    OpcUa_Free(a_pValue->Value.xName.Data); \
\
    a_pValue->Value.xName.Data = OpcUa_Null; \
    a_pValue->Value.xName.Count = 0; \
}

/*============================================================================
 * OpcUa_UnionField_ClearEncodeableArray
 *===========================================================================*/
#define OpcUa_UnionField_ClearEncodeableArray(xType, xName) \
{ \
    int ii; \
\
    for (ii = 0; ii < a_pValue->Value.xName.Count && a_pValue->Value.xName.Data != OpcUa_Null; ii++) \
    { \
        xType##_Clear(&(a_pValue->Value.xName.Data[ii])); \
    } \
\
    OpcUa_Free(a_pValue->Value.xName.Data); \
\
    a_pValue->Value.xName.Data = OpcUa_Null; \
    a_pValue->Value.xName.Count = 0; \
}

/*============================================================================
 * OpcUa_UnionField_ClearEnumeratedArray
 *===========================================================================*/
#define OpcUa_UnionField_ClearEnumeratedArray(xType, xName) \
{ \
    OpcUa_Free(a_pValue->Value.xName.Data); \
    a_pValue->Value.xName.Data = OpcUa_Null; \
    a_pValue->Value.xName.Count = 0; \
}

/*============================================================================
 * OpcUa_UnionField_Compare
 *===========================================================================*/
#define OpcUa_UnionField_Compare(xType, xName) {OpcUa_Int i = OpcUa_##xType##_Compare(&a_pValue1->Value.xName, &a_pValue2->Value.xName); if (i) return i;}

/*============================================================================
 * OpcUa_UnionField_CompareEncodeable
 *===========================================================================*/
#define OpcUa_UnionField_CompareEncodeable(xType, xName) {OpcUa_Int i = xType##_Compare(&a_pValue1->Value.xName, &a_pValue2->Value.xName); if (i) return i;}

/*============================================================================
 * OpcUa_UnionField_CompareEnumerated
 *===========================================================================*/
#define OpcUa_UnionField_CompareEnumerated(xType, xName) {OpcUa_Int i = OpcUa_Int32_Compare(&a_pValue1->Value.xName, &a_pValue2->Value.xName); if (i) return i;}

/*============================================================================
 * OpcUa_UnionField_CompareArrayStart
 *===========================================================================*/
#define OpcUa_UnionField_CompareArrayStart(xType, xName) \
    if (a_pValue1->Value.xName.Count != a_pValue2->Value.xName.Count) \
    { \
        return 1; \
    } \
    if (a_pValue1->Value.xName.Data == a_pValue2->Value.xName.Data) \
    { \
        return 0; \
    } \
    if (a_pValue1->Value.xName.Data == OpcUa_Null || a_pValue2->Value.xName.Data == OpcUa_Null) \
    { \
        return 1; \
    }

/*============================================================================
 * OpcUa_UnionField_CompareArray
 *===========================================================================*/
#define OpcUa_UnionField_CompareArray(xType, xName)\
{ \
    int ii; \
\
    OpcUa_UnionField_CompareArrayStart(xType, xName) \
\
    for (ii = 0; ii < a_pValue1->Value.xName.Count; ii++) \
    { \
        if (OpcUa_##xType##_Compare(&(a_pValue1->Value.xName.Data[ii]), &(a_pValue2->Value.xName.Data[ii]))){return 1;}; \
    } \
}

/*============================================================================
 * OpcUa_UnionField_CompareEncodeableArray
 *===========================================================================*/
#define OpcUa_UnionField_CompareEncodeableArray(xType, xName) \
{ \
    int ii; \
\
    OpcUa_UnionField_CompareArrayStart(xType, xName) \
\
    for (ii = 0; ii < a_pValue1->Value.xName.Count; ii++) \
    { \
        if (xType##_Compare(&(a_pValue1->Value.xName.Data[ii]), &(a_pValue2->Value.xName.Data[ii]))){return 1;}; \
    } \
}

/*============================================================================
 * OpcUa_UnionField_CompareEnumeratedArray
 *===========================================================================*/
#define OpcUa_UnionField_CompareEnumeratedArray(xType, xName) \
{ \
    int ii; \
\
    OpcUa_UnionField_CompareArrayStart(xType, xName) \
\
    for (ii = 0; ii < a_pValue1->Value.xName.Count; ii++) \
    { \
        if (a_pValue1->Value.xName.Data[ii] != a_pValue2->Value.xName.Data[ii]){return 1;}; \
    } \
}

/*============================================================================
 * OpcUa_UnionField_Copy
 *===========================================================================*/
#define OpcUa_UnionField_Copy(xType, xName) \
{ \
    a_pDestination->xName = (OpcUa_##xType*)OpcUa_Alloc(sizeof(OpcUa_##xType)); \
    OpcUa_GotoErrorIfAllocFailed(a_pDestination->xName); \
    OpcUa_##xType##_Initialize(a_pDestination->xName); \
    uStatus = OpcUa_##xType##_CopyTo(a_pSource->xName, a_pDestination->xName); \
    OpcUa_GotoErrorIfBad(uStatus); \
}

/*============================================================================
 * OpcUa_UnionField_CopyTo
 *===========================================================================*/
#define OpcUa_UnionField_CopyTo(xType, xName) uStatus = OpcUa_##xType##_CopyTo(&(a_pSource->Value.xName), &(a_pDestination->Value.xName)); OpcUa_GotoErrorIfBad(uStatus);

/*============================================================================
 * OpcUa_UnionField_CopyToScalar
 *===========================================================================*/
#define OpcUa_UnionField_CopyToScalar(xType, xName) (a_pDestination->Value.xName = a_pSource->Value.xName)

/*============================================================================
 * OpcUa_UnionField_CopyToEncodeable
 *===========================================================================*/
#define OpcUa_UnionField_CopyToEncodeable(xType, xName) xType##_CopyTo(&a_pSource->Value.xName, &a_pDestination->Value.xName)

/*============================================================================
 * OpcUa_UnionField_CopyToEnumerated
 *===========================================================================*/
#define OpcUa_UnionField_CopyToEnumerated(xType, xName) a_pDestination->Value.xName = a_pSource->Value.xName

/*============================================================================
 * OpcUa_UnionField_CopyToArray
 *===========================================================================*/
#define OpcUa_UnionField_CopyToArray(xType, xName)\
{ \
    int ii; \
\
    for (ii = 0; ii < a_pSource->NoOf##xName && a_pSource->xName != OpcUa_Null; ii++) \
    { \
        uStatus = OpcUa_##xType##_CopyTo(&(a_pSource->xName[ii]), &(a_pDestination->xName[ii])); \
        OpcUa_GotoErrorIfBad(uStatus); \
    } \
}

/*============================================================================
 * OpcUa_UnionField_CopyArray
 *===========================================================================*/
#define OpcUa_UnionField_CopyArray(xType, xName)\
if (a_pSource->Value.xName.Count > 0 && a_pSource->Value.xName.Data != OpcUa_Null) \
{ \
    int ii; \
\
    a_pDestination->Value.xName.Data = (OpcUa_##xType*)OpcUa_Alloc(sizeof(OpcUa_##xType) * a_pSource->Value.xName.Count); \
    OpcUa_GotoErrorIfAllocFailed(a_pDestination->Value.xName.Data); \
    OpcUa_MemSet(a_pDestination->Value.xName.Data, 0, sizeof(OpcUa_##xType) * a_pSource->Value.xName.Count); \
\
    for (ii = 0; ii < a_pSource->Value.xName.Count && a_pSource->Value.xName.Data != OpcUa_Null; ii++) \
    { \
        uStatus = OpcUa_##xType##_CopyTo(&(a_pSource->Value.xName.Data[ii]), &(a_pDestination->Value.xName.Data[ii])); \
        OpcUa_GotoErrorIfBad(uStatus); \
    } \
    a_pDestination->Value.xName.Count = a_pSource->Value.xName.Count; \
} \
else \
{ \
    a_pDestination->Value.xName.Count = 0; \
    a_pDestination->Value.xName.Data = OpcUa_Null; \
}

/*============================================================================
 * OpcUa_UnionField_CopyToEncodeableArray
 *===========================================================================*/
#define OpcUa_UnionField_CopyToEncodeableArray(xType, xName) \
{ \
    int ii; \
\
    for (ii = 0; ii < a_pSource->NoOf##xName && a_pSource->xName != OpcUa_Null; ii++) \
    { \
        xType##_CopyTo(&(a_pSource->xName[ii]), &(a_pDestination->xName[ii])); \
    } \
}

/*============================================================================
 * OpcUa_UnionField_CopyEncodeableArray
 *===========================================================================*/
#define OpcUa_UnionField_CopyEncodeableArray(xType, xName) \
if (a_pSource->Value.xName.Count > 0 && a_pSource->Value.xName.Data != OpcUa_Null) \
{ \
    int ii; \
\
    a_pDestination->Value.xName.Data = (xType*)OpcUa_Alloc(sizeof(xType) * a_pSource->Value.xName.Count); \
    OpcUa_GotoErrorIfAllocFailed(a_pDestination->Value.xName.Data); \
    OpcUa_MemSet(a_pDestination->Value.xName.Data, 0, sizeof(xType) * a_pSource->Value.xName.Count); \
\
    for (ii = 0; ii < a_pSource->Value.xName.Count && a_pSource->Value.xName.Data != OpcUa_Null; ii++) \
    { \
        xType##_CopyTo(&(a_pSource->Value.xName.Data[ii]), &(a_pDestination->Value.xName.Data[ii])); \
    } \
    a_pDestination->Value.xName.Count = a_pSource->Value.xName.Count; \
} \
else \
{ \
    a_pDestination->Value.xName.Count = 0; \
    a_pDestination->Value.xName.Data = OpcUa_Null; \
}

/*============================================================================
 * OpcUa_UnionField_CopyEnumeratedArray
 *===========================================================================*/
#define OpcUa_UnionField_CopyEnumeratedArray(xType, xName) \
if (a_pSource->Value.xName.Count > 0 && a_pSource->Value.xName.Data != OpcUa_Null) \
{ \
    a_pDestination->Value.xName.Data = (xType*)OpcUa_Alloc(a_pSource->Value.xName.Count * sizeof(xType)); \
    OpcUa_GotoErrorIfAllocFailed(a_pDestination->Value.xName.Data); \
    OpcUa_MemCpy(a_pDestination->Value.xName.Data, a_pSource->Value.xName.Count * sizeof(xType), a_pSource->Value.xName.Data, a_pSource->Value.xName.Count * sizeof(xType)); \
    a_pDestination->Value.xName.Count = a_pSource->Value.xName.Count; \
} \
else \
{ \
    a_pDestination->Value.xName.Count = 0; \
    a_pDestination->Value.xName.Data = OpcUa_Null; \
}

/*============================================================================
 * OpcUa_UnionField_CopyScalarArray
 *===========================================================================*/
#define OpcUa_UnionField_CopyScalarArray(xType, xName) \
if (a_pSource->Value.xName.Count > 0 && a_pSource->Value.xName.Data != OpcUa_Null) \
{ \
    a_pDestination->Value.xName.Data = (OpcUa_##xType*)OpcUa_Alloc(a_pSource->Value.xName.Count * sizeof(OpcUa_##xType)); \
    OpcUa_GotoErrorIfAllocFailed(a_pDestination->Value.xName.Data); \
    OpcUa_MemCpy(a_pDestination->Value.xName.Data, a_pSource->Value.xName.Count * sizeof(OpcUa_##xType), a_pSource->Value.xName.Data, a_pSource->Value.xName.Count * sizeof(OpcUa_##xType)); \
    a_pDestination->Value.xName.Count = a_pSource->Value.xName.Count; \
} \
else \
{ \
    a_pDestination->Value.xName.Count = 0; \
    a_pDestination->Value.xName.Data = OpcUa_Null; \
}

/*============================================================================
 * OpcUa_UnionField_GetSize
 *===========================================================================*/
#define OpcUa_UnionField_GetSize(xType, xName) \
{ \
    OpcUa_Int32 uFieldSize; \
    uStatus = a_pEncoder->Write##xType(a_pEncoder, #xName, &a_pValue->Value.xName, &uFieldSize); \
    OpcUa_GotoErrorIfBad(uStatus); \
    iSize += uFieldSize; \
}

/*============================================================================
 * OpcUa_UnionField_GetSizeEncodeable
 *===========================================================================*/
#define OpcUa_UnionField_GetSizeEncodeable(xType, xName) \
{ \
    OpcUa_Int32 uFieldSize; \
    uStatus = a_pEncoder->WriteEncodeable(a_pEncoder, #xName, &a_pValue->Value.xName, &xType##_EncodeableType, &uFieldSize); \
    OpcUa_GotoErrorIfBad(uStatus); \
    iSize += uFieldSize; \
}

/*============================================================================
 * OpcUa_UnionField_GetSizeEnumerated
 *===========================================================================*/
#define OpcUa_UnionField_GetSizeEnumerated(xType, xName) \
{ \
    OpcUa_Int32 uFieldSize; \
    uStatus = a_pEncoder->WriteEnumerated(a_pEncoder, #xName, (OpcUa_Int32*)&a_pValue->Value.xName, &xType##_EnumeratedType, &uFieldSize); \
    OpcUa_GotoErrorIfBad(uStatus); \
    iSize += uFieldSize; \
}

/*============================================================================
 * OpcUa_UnionField_GetSizeArray
 *===========================================================================*/
#define OpcUa_UnionField_GetSizeArray(xType, xName) \
{ \
    OpcUa_Int32 uFieldSize; \
    uStatus = a_pEncoder->Write##xType##Array(a_pEncoder, #xName, a_pValue->Value.xName.Data, a_pValue->Value.xName.Count, &uFieldSize); \
    OpcUa_GotoErrorIfBad(uStatus); \
    iSize += uFieldSize; \
}

/*============================================================================
 * OpcUa_UnionField_GetSizeEncodeableArray
 *===========================================================================*/
#define OpcUa_UnionField_GetSizeEncodeableArray(xType, xName) \
{ \
    OpcUa_Int32 uFieldSize; \
    uStatus = a_pEncoder->WriteEncodeableArray(a_pEncoder, #xName, a_pValue->Value.xName.Data, a_pValue->Value.xName.Count, &xType##_EncodeableType, &uFieldSize); \
    OpcUa_GotoErrorIfBad(uStatus); \
    iSize += uFieldSize; \
}

/*============================================================================
 * OpcUa_UnionField_GetSizeEnumeratedArray
 *===========================================================================*/
#define OpcUa_UnionField_GetSizeEnumeratedArray(xType, xName) \
{ \
    OpcUa_Int32 uFieldSize; \
    uStatus = a_pEncoder->WriteEnumeratedArray(a_pEncoder, #xName, (OpcUa_Int32*)a_pValue->Value.xName.Data, a_pValue->Value.xName.Count, &xType##_EnumeratedType, &uFieldSize); \
    OpcUa_GotoErrorIfBad(uStatus); \
    iSize += uFieldSize; \
}

/*============================================================================
 * OpcUa_UnionField_Write
 *===========================================================================*/
#define OpcUa_UnionField_Write(xType, xName) \
{ \
    uStatus = a_pEncoder->Write##xType(a_pEncoder, #xName, &a_pValue->Value.xName, OpcUa_Null); \
    OpcUa_GotoErrorIfBad(uStatus); \
}

/*============================================================================
 * OpcUa_UnionField_WriteEncodeable
 *===========================================================================*/
#define OpcUa_UnionField_WriteEncodeable(xType, xName) \
{ \
    uStatus = a_pEncoder->WriteEncodeable(a_pEncoder, #xName, &a_pValue->Value.xName, &xType##_EncodeableType, OpcUa_Null); \
    OpcUa_GotoErrorIfBad(uStatus); \
}

/*============================================================================
 * OpcUa_UnionField_WriteEnumerated
 *===========================================================================*/
#define OpcUa_UnionField_WriteEnumerated(xType, xName) \
{ \
    uStatus = a_pEncoder->WriteEnumerated(a_pEncoder, #xName, (OpcUa_Int32*)&a_pValue->Value.xName, &xType##_EnumeratedType, OpcUa_Null); \
    OpcUa_GotoErrorIfBad(uStatus); \
}

/*============================================================================
 * OpcUa_UnionField_WriteArray
 *===========================================================================*/
#define OpcUa_UnionField_WriteArray(xType, xName) \
{ \
    uStatus = a_pEncoder->Write##xType##Array(a_pEncoder, #xName, a_pValue->Value.xName.Data, a_pValue->Value.xName.Count, OpcUa_Null); \
    OpcUa_GotoErrorIfBad(uStatus); \
}

/*============================================================================
 * OpcUa_UnionField_WriteEncodeableArray
 *===========================================================================*/
#define OpcUa_UnionField_WriteEncodeableArray(xType, xName) \
{ \
    uStatus = a_pEncoder->WriteEncodeableArray(a_pEncoder, #xName, a_pValue->Value.xName.Data, a_pValue->Value.xName.Count, &xType##_EncodeableType, OpcUa_Null); \
    OpcUa_GotoErrorIfBad(uStatus); \
}

/*============================================================================
 * OpcUa_UnionField_WriteEnumeratedArray
 *===========================================================================*/
#define OpcUa_UnionField_WriteEnumeratedArray(xType, xName) \
{ \
    uStatus = a_pEncoder->WriteEnumeratedArray(a_pEncoder, #xName, (OpcUa_Int32*)a_pValue->Value.xName.Data, a_pValue->Value.xName.Count, &xType##_EnumeratedType, OpcUa_Null); \
    OpcUa_GotoErrorIfBad(uStatus); \
}

/*============================================================================
 * OpcUa_UnionField_Read
 *===========================================================================*/
#define OpcUa_UnionField_Read(xType, xName) \
{ \
    uStatus = a_pDecoder->Read##xType(a_pDecoder, #xName, &a_pValue->Value.xName); \
    OpcUa_GotoErrorIfBad(uStatus); \
}

/*============================================================================
 * OpcUa_UnionField_ReadEncodeable
 *===========================================================================*/
#define OpcUa_UnionField_ReadEncodeable(xType, xName) \
{ \
    uStatus = a_pDecoder->ReadEncodeable(a_pDecoder, #xName, &xType##_EncodeableType, &a_pValue->Value.xName); \
    OpcUa_GotoErrorIfBad(uStatus); \
}

/*============================================================================
 * OpcUa_UnionField_ReadEnumerated
 *===========================================================================*/
#define OpcUa_UnionField_ReadEnumerated(xType, xName) \
{ \
    uStatus = a_pDecoder->ReadEnumerated(a_pDecoder, #xName, &xType##_EnumeratedType, (OpcUa_Int32*)&a_pValue->Value.xName); \
    OpcUa_GotoErrorIfBad(uStatus); \
}

/*============================================================================
 * OpcUa_UnionField_ReadArray
 *===========================================================================*/
#define OpcUa_UnionField_ReadArray(xType, xName) \
{ \
    uStatus = a_pDecoder->Read##xType##Array(a_pDecoder, #xName, &(a_pValue->Value.xName.Data), &(a_pValue->Value.xName.Count)); \
    OpcUa_GotoErrorIfBad(uStatus); \
}

/*============================================================================
 * OpcUa_UnionField_ReadEncodeableArray
 *===========================================================================*/
#define OpcUa_UnionField_ReadEncodeableArray(xType, xName) \
{ \
    uStatus = a_pDecoder->ReadEncodeableArray(a_pDecoder, #xName, &xType##_EncodeableType, (OpcUa_Void**)(&(a_pValue->Value.xName.Data)), &(a_pValue->Value.xName.Count)); \
    OpcUa_GotoErrorIfBad(uStatus); \
}

/*============================================================================
 * OpcUa_UnionField_ReadEnumeratedArray
 *===========================================================================*/
#define OpcUa_UnionField_ReadEnumeratedArray(xType, xName) \
{ \
    uStatus = a_pDecoder->ReadEnumeratedArray(a_pDecoder, #xName, &xType##_EnumeratedType, (OpcUa_Int32**)&(a_pValue->Value.xName.Data), &(a_pValue->Value.xName.Count)); \
    OpcUa_GotoErrorIfBad(uStatus); \
}

/*============================================================================
 * OpcUa_UnionField_ReadEncodeableArray
 *===========================================================================*/
#define OpcUa_UnionField_ReadEncodeableArray(xType, xName) \
{ \
    uStatus = a_pDecoder->ReadEncodeableArray(a_pDecoder, #xName, &xType##_EncodeableType, (OpcUa_Void**)(&(a_pValue->Value.xName.Data)), &(a_pValue->Value.xName.Count)); \
    OpcUa_GotoErrorIfBad(uStatus); \
}

/*============================================================================
 * OpcUa_UnionField_ReadEnumeratedArray
 *===========================================================================*/
#define OpcUa_UnionField_ReadEnumeratedArray(xType, xName) \
{ \
    uStatus = a_pDecoder->ReadEnumeratedArray(a_pDecoder, #xName, &xType##_EnumeratedType, (OpcUa_Int32**)&(a_pValue->Value.xName.Data), &(a_pValue->Value.xName.Count)); \
    OpcUa_GotoErrorIfBad(uStatus); \
}

/*============================================================================
 * OpcUa_OptionalField_Read_BaseDefine
 *===========================================================================*/
#define OpcUa_OptionalField_Read_BaseDefine(xStructName, xType, xName, xReadFunction) \
if ((a_pValue->EncodingMask & xStructName##_OptionalFields_##xName) != 0) \
{ \
    uStatus = xReadFunction; \
    OpcUa_GotoErrorIfBad(uStatus); \
}

/*============================================================================
 * OpcUa_OptionalField_Read
 *===========================================================================*/
#define OpcUa_OptionalField_Read(xStructName, xType, xName) \
    OpcUa_OptionalField_Read_BaseDefine(xStructName, xType, xName, a_pDecoder->Read##xType(a_pDecoder, #xName, &a_pValue->xName))

/*============================================================================
 * OpcUa_OptionalField_ReadEncodeable
 *===========================================================================*/
#define OpcUa_OptionalField_ReadEncodeable(xStructName, xType, xName) \
    OpcUa_OptionalField_Read_BaseDefine(xStructName, xType, xName, a_pDecoder->ReadEncodeable(a_pDecoder, #xName, &xType##_EncodeableType, &a_pValue->xName))

/*============================================================================
 * OpcUa_OptionalField_ReadEnumerated
 *===========================================================================*/
#define OpcUa_OptionalField_ReadEnumerated(xStructName, xType, xName) \
    OpcUa_OptionalField_Read_BaseDefine(xStructName, xType, xName, a_pDecoder->ReadEnumerated(a_pDecoder, #xName, &xType##_EnumeratedType, (OpcUa_Int32*)&a_pValue->xName))

/*============================================================================
 * OpcUa_OptionalField_ReadArray
 *===========================================================================*/
#define OpcUa_OptionalField_ReadArray(xStructName, xType, xName) \
    OpcUa_OptionalField_Read_BaseDefine(xStructName, xType, xName, a_pDecoder->Read##xType##Array(a_pDecoder, #xName, &(a_pValue->xName), &(a_pValue->NoOf##xName)))

/*============================================================================
 * OpcUa_OptionalField_ReadEncodeableArray
 *===========================================================================*/
#define OpcUa_OptionalField_ReadEncodeableArray(xStructName, xType, xName) \
    OpcUa_OptionalField_Read_BaseDefine(xStructName, xType, xName, a_pDecoder->ReadEncodeableArray(a_pDecoder, #xName, &xType##_EncodeableType, (OpcUa_Void**)&a_pValue->xName, &(a_pValue->NoOf##xName)))

/*============================================================================
 * OpcUa_OptionalField_ReadEnumeratedArray
 *===========================================================================*/
#define OpcUa_OptionalField_ReadEnumeratedArray(xStructName, xType, xName) \
    OpcUa_OptionalField_Read_BaseDefine(xStructName, xType, xName, a_pDecoder->ReadEnumeratedArray(a_pDecoder, #xName, &xType##_EnumeratedType, (OpcUa_Int32**)&a_pValue->xName, &(a_pValue->NoOf##xName)))

/*============================================================================
 * Flags that can be set for the EventNotifier attribute.
 *===========================================================================*/
  
/* The Object or View produces no event and has no event history. */
#define OpcUa_EventNotifiers_None 0x0

/* The Object or View produces event notifications. */
#define OpcUa_EventNotifiers_SubscribeToEvents 0x1

/* The Object has an event history which may be read. */
#define OpcUa_EventNotifiers_HistoryRead 0x4

/* The Object has an event history which may be updated. */
#define OpcUa_EventNotifiers_HistoryWrite 0x8

/*============================================================================
 * Flags that can be set for the AccessLevel attribute.
 *===========================================================================*/

/* The Variable value cannot be accessed and has no event history. */
#define OpcUa_AccessLevels_None 0x0

/* The current value of the Variable may be read.*/
#define OpcUa_AccessLevels_CurrentRead 0x1

/* The current value of the Variable may be written.*/
#define OpcUa_AccessLevels_CurrentWrite 0x2

/* The current value of the Variable may be read or written.*/
#define OpcUa_AccessLevels_CurrentReadOrWrite 0x3

/* The history for the Variable may be read.*/
#define OpcUa_AccessLevels_HistoryRead 0x4

/* The history for the Variable may be updated.*/
#define OpcUa_AccessLevels_HistoryWrite 0x8

/* The history value of the Variable may be read or updated. */
#define OpcUa_AccessLevels_HistoryReadOrWrite 0xC

/* The variable generates SemanticChangeEvents */
#define OpcUa_AccessLevels_SemanticChange 0x10

/* The variable value StatusCode is writable */
#define OpcUa_AccessLevels_StatusWrite 0x20

/* The variable value SourceTimestamp is writable */
#define OpcUa_AccessLevels_TimestampWrite 0x40

/*============================================================================
 * Constants defined for the ValueRank attribute.
 *===========================================================================*/

/* The variable may be a scalar or a one dimensional array. */
#define OpcUa_ValueRanks_ScalarOrOneDimension -3

/* The variable may be a scalar or an array of any dimension. */
#define OpcUa_ValueRanks_Any -2

/* The variable is always a scalar. */
#define OpcUa_ValueRanks_Scalar -1

/* The variable is always an array with one or more dimensions. */
#define OpcUa_ValueRanks_OneOrMoreDimensions 0

/* The variable is always one dimensional array. */
#define OpcUa_ValueRanks_OneDimension 1

/* The variable is always an array with two or more dimensions. */
#define OpcUa_ValueRanks_TwoDimensions 2

/*============================================================================
 * Constants defined for the MinimumSamplingInterval attribute.
 *===========================================================================*/

/* The server does not know how fast the value can be sampled. */
#define OpcUa_MinimumSamplingIntervals_Indeterminate -1

/* The server can sample the variable continuously. */
#define OpcUa_MinimumSamplingIntervals_Continuous 0

/*============================================================================
 * Constants defined for the DiagnosticsMasks parameter.
 *===========================================================================*/

#define OpcUa_DiagnosticsMasks_ServiceSymbolicId 1
#define OpcUa_DiagnosticsMasks_ServiceLocalizedText 2
#define OpcUa_DiagnosticsMasks_ServiceAdditionalInfo 4
#define OpcUa_DiagnosticsMasks_ServiceInnerStatusCode 8
#define OpcUa_DiagnosticsMasks_ServiceInnerDiagnostics 16
#define OpcUa_DiagnosticsMasks_ServiceSymbolicIdAndText 3
#define OpcUa_DiagnosticsMasks_ServiceNoInnerStatus 15
#define OpcUa_DiagnosticsMasks_ServiceAll 31
#define OpcUa_DiagnosticsMasks_OperationSymbolicId 32
#define OpcUa_DiagnosticsMasks_OperationLocalizedText 64
#define OpcUa_DiagnosticsMasks_OperationAdditionalInfo 128
#define OpcUa_DiagnosticsMasks_OperationInnerStatusCode 256
#define OpcUa_DiagnosticsMasks_OperationInnerDiagnostics 512
#define OpcUa_DiagnosticsMasks_OperationSymbolicIdAndText 96
#define OpcUa_DiagnosticsMasks_OperationNoInnerStatus 224
#define OpcUa_DiagnosticsMasks_OperationAll 992
#define OpcUa_DiagnosticsMasks_SymbolicId 33
#define OpcUa_DiagnosticsMasks_LocalizedText 66
#define OpcUa_DiagnosticsMasks_AdditionalInfo 132
#define OpcUa_DiagnosticsMasks_InnerStatusCode 264
#define OpcUa_DiagnosticsMasks_InnerDiagnostics 528
#define OpcUa_DiagnosticsMasks_SymbolicIdAndText 99
#define OpcUa_DiagnosticsMasks_NoInnerStatus 239
#define OpcUa_DiagnosticsMasks_All 1023

OPCUA_END_EXTERN_C

#endif /* _OpcUa_BuiltInTypes_H_ */
/* @} */
