/******************************************************************************
** uanodeid.h
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
** Description: OPC server core module variable handle class.
**
******************************************************************************/
#ifndef UANODEID_H
#define UANODEID_H

#include "uabase.h"
#include "uaguid.h"
#include "uabytestring.h"

class UABASE_EXPORT UaVariant;
class UABASE_EXPORT UaDataValue;
class UABASE_EXPORT UaNodeIdPrivate;

/** @ingroup CppBaseLibraryClass
 @brief Wrapper class for the UA stack structure OpcUa_NodeId

 Helper class for handling the OPC UA built-in data type NodeId. It provides conversion and
 comparison functions and handles memory allocation and cleanup.

 UaNodeId uses implicit sharing to avoid needless copying and to boost the performance.
 Only if you modify a shared NodeId, it creates a copy for that (copy-on-write).
 So assigning another UaNodeId or passing it as parameter is as fast as assigning a pointer.

 <b>NodeId as defined by OPC UA</b>

 A Server shall persist the NodeId of a Node, that is, it is not allowed to generate new
 NodeIds when rebooting. The server is not allowed to change the namespace index for a
 namespace URI as long as the server is not restarted but new namespaces can be added.
 The namespace index for a namespace URI may change after a server restart.

 Clients must be prepared for changes of the namespace index in a NodeId and must persist
 their own namespace table together with the stored NodeIds for a server.

 <b>Structure of the NodeId</b>

 The NodeId data type is a structure with the following elements
 Name           | Type   | Description
 ---------------|--------|------------------------------------------------------------------
 namespaceIndex | UInt16 | The index for a namespace URI used in an OPC UA server
 identifierType | enum   | The format and data type of the identifier
 identifier     | *      | The identifier for a node in the address space of an OPC UA server

 <b>NamespaceIndex</b>

 The namespace is a URI that identifies the naming authority responsible for assigning the
 identifier element of the NodeId. Naming authorities include the local server, the underlying
 system, standards bodies and consortia. It is expected that most nodes will use the URI of
 the server or of the underlying system.

 Using a namespace URI allows multiple OPC UA servers attached to the same underlying system
 to use the same identifier to identify the same object. This enables clients that connect to
 those Servers to recognise Objects that they have in common. The namespace URI is case sensitive.
 Namespace URIs are identified by numeric values in OPC UA services to permit more efficient
 transfer and processing (e.g. table lookups). The numeric values used to identify namespaces
 correspond to the index into the NamespaceArray. The NamespaceArray is a variable that is part
 of the Server object in the address space.

 The URI for the OPC UA namespace is “http://opcfoundation.org/UA/”. Its corresponding index
 in the namespace table is 0.

 The Namespace URI is case sensitive.

 <b>IdentifierType</b>

 The following IdentifierTypes are available:
 Value                        | Description
 -----------------------------|--------------------------------------------
 OpcUa_IdentifierType_Numeric | Numeric value
 OpcUa_IdentifierType_String  | String value
 OpcUa_IdentifierType_Guid    | Globally Unique Identifier
 OpcUa_IdentifierType_Opaque  | Namespace specific format in a ByteString

 <b>Identifier value</b>

 The identifier value element is used within the context of the first two elements to identify
 a node. Its data type and format is defined by the identifierType.

 Numeric identifiers are typically used for static namespaces or for NodeIds in generated code.
 Such identifiers in generated code have typically defines generated which makes them easy to
 use and read in code.

 @code
 // Construct NodeId with numeric identifier from namespace 0
 // Namespace index 0 is default value for constructor with numeric value
 UaNodeId nodeId1(OpcUaId_Server_NamespaceArray);

 // Get current namespace index for namespace URI
 OpcUa_UInt16 namespaceIndex = 0;
 // Server: Get index from NodeManager
 namespaceIndex = OpcUaDi::NodeManagerDevices::getTypeNamespace();
 // Client: Get namespace index by reading the NamespaceArray from server, search for URI, use index of URI

 // Construct NodeId from numeric identifier from other namespace
 UaNodeId nodeId2(OpcUaDiId_DeviceSet, namespaceIndex);
 @endcode

 String identifiers are typically used for nodes that are dynamically generated during system
 configuration. The string is either a path of nodes with a server specific delimiters or
 a server specific addressing schema contained in the string.

 String identifiers are case sensitive. That is, clients shall consider them case sensitive.
 Servers are allowed to provide alternative NodeIds and using this mechanism severs can handle
 NodeIds as case insensitive.

 @code
 // Construct NodeId from string identifier
 UaNodeId nodeId2("MyNode", namespaceIndex);
 @endcode

 Normally the scope of NodeIds is the server in which they are defined. For certain types of
 NodeIds, NodeIds can uniquely identify a Node within a system, or across systems (e.g. GUIDs).
 System-wide and globally-unique identifiers allow clients to track Nodes, such as work orders,
 as they move between OPC UA servers as they progress through the system.

 @code
 // Create GUID for new node
 UaGuid guidIdentifier = UaGuid::create();
 // Or get GUID from configuration file
 guidIdentifier.fromString(myGuidString);
 // Construct NodeId from GUID identifier
 UaNodeId nodeId2(guidIdentifier, namespaceIndex);
 @endcode

 Opaque identifiers are identifiers that are free-format byte strings that might or might not
 be human interpretable.

 Identifier values of IdentifierType STRING are restricted to 4096 characters. Identifier
 values of IdentifierType OPAQUE are restricted to 4096 bytes.

 A null NodeId has special meaning. For example, many services define special behaviour if a
 null NodeId is passed as a parameter. A node in the address space cannot have a null NodeId.
*/
class UABASE_EXPORT UaNodeId
{
    UA_DECLARE_PRIVATE(UaNodeId)
    bool operator>(const UaNodeId&) const; // not implemented
public:
    UaNodeId();
    UaNodeId(const UaNodeId &other);
    UaNodeId(const OpcUa_NodeId &other);
    UaNodeId(OpcUa_UInt32 id, OpcUa_UInt16 NsIdx = 0);
    UaNodeId(const UaString& sId, OpcUa_UInt16 NsIdx);
    UaNodeId(const UaGuid& guid, OpcUa_UInt16 NsIdx);
    UaNodeId(const UaByteString& data, OpcUa_UInt16 NsIdx);
    ~UaNodeId();

    /* Checks whether a value is Null or not. */
    OpcUa_Boolean isNull() const;

    /* Clear data. */
    void clear();

    /* Attaches to the native NodeId structure. */
    void attach(const OpcUa_NodeId *pOther);

    /* Detaches the internal NodeId structure from this class. */
    OpcUa_NodeId* detach(OpcUa_NodeId *pDst);

    /* Assigns a new namespace index to the NodeId. */
    void setNamespaceIndex(OpcUa_UInt16 NsIdx);

    /* Set the currently used node id. */
    void setNodeId(OpcUa_UInt32 id, OpcUa_UInt16 NsIdx = 0);

    /* Set the currently used node id. */
    void setNodeId(const UaString& sId, OpcUa_UInt16 NsIdx = 1);

    /* Set the currently used node id. */
    void setNodeId(const UaGuid& id, OpcUa_UInt16 NsIdx);

    /* Set the currently used node id. */
    void setNodeId(const UaByteString& id, OpcUa_UInt16 NsIdx);

    /* Returns the OpcUa_NodeId pointer to the internal data structure. */
    operator const OpcUa_NodeId*() const;

    /* Creates a copy of the internal NodeId. */
    OpcUa_NodeId* copy() const;

    /*  Creates a copy of the internal NodeId. */
    void copyTo(OpcUa_NodeId *pDst) const;

    /* Creates a copy of the source NodeId. */
    static OpcUa_NodeId* clone(const OpcUa_NodeId& source);

    /* Creates a copy of the source NodeId. */
    static void cloneTo(const OpcUa_NodeId& source, OpcUa_NodeId& copy);

    /* Assigns another NodeId to the current instance. */
    UaNodeId& operator=(const UaNodeId &other);

    bool operator<(const UaNodeId &other) const;

    bool operator==(const UaNodeId &other) const;

    bool operator!=(const UaNodeId &other) const;

    bool nodeIdCompare(OpcUa_NodeId* pNodeId) const;

    /* Compares two nodeIds and returns true if they are equal. */
    static bool compare(const OpcUa_NodeId&, const OpcUa_NodeId&);

    /* Converts the identifier of the NodeId to a UaString. */
    UaString toString() const;

    /* Converts all elements of a NodeId to a human readable string. */
    UaString toFullString() const;

    /* Converts all elements of a NodeId to a string where the syntax is defined by the OPC UA XML Schema. */
    UaString toXmlString() const;

    /* Creates a NodeId to from a string where the syntax is defined by the OPC UA XML Schema. */
    static UaNodeId fromXmlString(UaString xmlString);

    /* Get the identifier type. */
    OpcUa_IdentifierType identifierType() const;

    /* Returns the namespace index as numeric value. */
    OpcUa_UInt16 namespaceIndex() const;

    /* Returns the numeric identifier as numeric value. */
    OpcUa_UInt32 identifierNumeric() const;

    /* Returns the string identifier as string value. */
    const OpcUa_String* identifierString() const;

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

private:
    friend UABASE_EXPORT UaDataStream &operator<<(UaDataStream &, const UaNodeId &);
    friend UABASE_EXPORT UaDataStream &operator>>(UaDataStream &, UaNodeId &);
};

/* define UaDataStream operators for UaNodeId. */
UABASE_EXPORT UaDataStream &operator<<(UaDataStream &, const UaNodeId &);
UABASE_EXPORT UaDataStream &operator>>(UaDataStream &, UaNodeId &);

#endif
