/******************************************************************************
** opcua_datatypeencodingtypebase.h
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
** Project: C++ OPC Server SDK information model for namespace http://opcfoundation.org/UA/
**
** Description: OPC Unified Architecture Software Development Kit.
**
******************************************************************************/

#ifndef __OPCUA_DATATYPEENCODINGTYPEBASE_H__
#define __OPCUA_DATATYPEENCODINGTYPEBASE_H__

#include "opcua_baseobjecttype.h"
#include "basenodes.h"
#include "opcua_identifiers.h"
#include "opcua_propertytype.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {


/** Generated base class for a DataTypeEncodingType.
 *
 *  This class contains the generated base code for the object type DataTypeEncodingType
 *  representing an OPC UA ObjectType. This class is used to create the object type and to
 *  create and represent instances of the object type in the server address space.
 *
 *  Used as type for DataTypeEncodings.
 *
 *  Different kinds of DataTypes are handled differently regarding their encoding
 *  and whether this encoding is represented in the AddressSpace.
 *
 *  Built-in DataTypes are a fixed set of DataTypes (see Part 6 of the OPC UA
 *  Specification for a complete list of Built-in DataTypes). They have no
 *  encodings visible in the AddressSpace since the encoding should be known to all
 *  OPC UA products. Examples of Built-in DataTypes are Int32 and Double.
 *
 *  Simple DataTypes are subtypes of the Built-in DataTypes. They are handled on
 *  the wire like the Built-in DataType, i.e. they cannot be distinguished on the
 *  wire from their Built-in supertypes. Since they are handled like Built-in
 *  DataTypes regarding the encoding they cannot have encodings defined in the
 *  AddressSpace. Clients can read the DataType Attribute of a Variable or
 *  VariableType to identify the Simple DataType of the Value Attribute. An example
 *  of a Simple DataType is Duration. It is handled on the wire as a Double but the
 *  Client can read the DataType Attribute and thus interpret the value as defined
 *  by Duration.
 *
 *  Structured DataTypes are DataTypes that represent structured data and are not
 *  defined as Built-in DataTypes. Structured DataTypes inherit directly or
 *  indirectly from the DataType Structure. Structured DataTypes may have several
 *  encodings and the encodings are exposed in the AddressSpace. How the encoding
 *  of Structured DataTypes is handled on the wire is defined in Part 6 of the OPC
 *  UA Specification. The encoding of the Structured DataType is transmitted with
 *  each value, thus Clients are aware of the DataType without reading the DataType
 *  Attribute. The encoding has to be transmitted so the Client is able to
 *  interpret the data. An example of a Structured DataType is Argument.
 *
 *  Enumeration DataTypes are DataTypes that represent discrete sets of named
 *  values. Enumerations are always encoded as Int32 on the wire as defined in Part
 *  6 of the OPC UA Specification. Enumeration DataTypes inherit directly or
 *  indirectly from the DataType Enumeration. Enumerations have no encodings
 *  exposed in the AddressSpace. To expose the human-readable representation of an
 *  enumerated value the DataType Node may have the EnumStrings Property that
 *  contains an array of LocalizedText. The Integer representation of the
 *  enumeration value points to a position within that array. The EnumValues
 *  Property can be used instead of the EnumStrings to support integer
 *  representation of enumerations that are not zero-based or have gaps. It
 *  contains an array of a Structured DataType containing the integer
 *  representation as well as the human-readable representation. An example of an
 *  enumeration DataType containing a sparse list of Integers is NodeClass.
 *
 *  In addition to the DataTypes described above, abstract DataTypes are also
 *  supported, which do not have any encodings and cannot be exchanged on the wire.
 *  Variables and VariableTypes use abstract DataTypes to indicate that their Value
 *  may be any one of the subtypes of the abstract DataType. An example of an
 *  abstract DataType is Integer.
 *
 *  See also \ref Doc_OpcUa_DataTypeEncodingType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT DataTypeEncodingTypeBase:
    public OpcUa::BaseObjectType
{
    UA_DISABLE_COPY(DataTypeEncodingTypeBase);
protected:
    virtual ~DataTypeEncodingTypeBase();
public:
    // construction / destruction
    DataTypeEncodingTypeBase(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    DataTypeEncodingTypeBase(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    DataTypeEncodingTypeBase(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;



    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(DataTypeEncodingTypeBase *pInstance);

protected:


private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUADATATYPEENCODINGTYPEBASE_H__


