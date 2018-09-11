/******************************************************************************
** uaaddnodesitem.h
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
** Portable UaAddNodesItem class.
**
******************************************************************************/
#ifndef UAADDNODESITEM_H
#define UAADDNODESITEM_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uaexpandednodeid.h"
#include "uaextensionobject.h"
#include "uanodeid.h"
#include "uaqualifiedname.h"
#include "uaarraytemplates.h"

class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaAddNodesItemPrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_AddNodesItem.
 *
 *  This class encapsulates the native OpcUa_AddNodesItem structure
 *  and handles memory allocation and cleanup for you.
 *  UaAddNodesItem uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared AddNodesItem it creates a copy for that (copy-on-write).
 *  So assigning another UaAddNodesItem or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  A structure that is defined as the type of the nodesToAdd parameter of the
 *  AddNodes Service.
 */
class UABASE_EXPORT UaAddNodesItem
{
    UA_DECLARE_PRIVATE(UaAddNodesItem)
public:
    UaAddNodesItem();
    UaAddNodesItem(const UaAddNodesItem &other);
    UaAddNodesItem(const OpcUa_AddNodesItem &other);
    UaAddNodesItem(
        const UaExpandedNodeId& parentNodeId,
        const UaNodeId& referenceTypeId,
        const UaExpandedNodeId& requestedNewNodeId,
        const UaQualifiedName& browseName,
        OpcUa_NodeClass nodeClass,
        UaExtensionObject& nodeAttributes,
        const UaExpandedNodeId& typeDefinition
        );
    UaAddNodesItem(const UaExtensionObject &extensionObject);
    UaAddNodesItem(const OpcUa_ExtensionObject &extensionObject);
    UaAddNodesItem(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaAddNodesItem(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaAddNodesItem();

    void clear();

    bool operator==(const UaAddNodesItem &other) const;
    bool operator!=(const UaAddNodesItem &other) const;

    UaAddNodesItem& operator=(const UaAddNodesItem &other);

    OpcUa_AddNodesItem* copy() const;
    void copyTo(OpcUa_AddNodesItem *pDst) const;

    static OpcUa_AddNodesItem* clone(const OpcUa_AddNodesItem& source);
    static void cloneTo(const OpcUa_AddNodesItem& source, OpcUa_AddNodesItem& copy);

    void attach(OpcUa_AddNodesItem *pValue);
    OpcUa_AddNodesItem* detach(OpcUa_AddNodesItem* pDst);

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

    OpcUa_StatusCode setAddNodesItem(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setAddNodesItem(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setAddNodesItem(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setAddNodesItem(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setAddNodesItem(
        const UaExpandedNodeId& parentNodeId,
        const UaNodeId& referenceTypeId,
        const UaExpandedNodeId& requestedNewNodeId,
        const UaQualifiedName& browseName,
        OpcUa_NodeClass nodeClass,
        UaExtensionObject& nodeAttributes,
        const UaExpandedNodeId& typeDefinition
        );

    UaExpandedNodeId getParentNodeId() const;
    UaNodeId getReferenceTypeId() const;
    UaExpandedNodeId getRequestedNewNodeId() const;
    UaQualifiedName getBrowseName() const;
    OpcUa_NodeClass getNodeClass() const;
    UaExtensionObject getNodeAttributes() const;
    UaExpandedNodeId getTypeDefinition() const;

    void setParentNodeId(const UaExpandedNodeId& parentNodeId);
    void setReferenceTypeId(const UaNodeId& referenceTypeId);
    void setRequestedNewNodeId(const UaExpandedNodeId& requestedNewNodeId);
    void setBrowseName(const UaQualifiedName& browseName);
    void setNodeClass(OpcUa_NodeClass nodeClass);
    void setNodeAttributes(UaExtensionObject& nodeAttributes);
    void setTypeDefinition(const UaExpandedNodeId& typeDefinition);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_AddNodesItem.
 *
 *  This class encapsulates an array of the native OpcUa_AddNodesItem structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaAddNodesItem for information about the encapsulated structure.
 */
class UABASE_EXPORT UaAddNodesItems
{
public:
    UaAddNodesItems();
    UaAddNodesItems(const UaAddNodesItems &other);
    UaAddNodesItems(OpcUa_Int32 length, OpcUa_AddNodesItem* data);
    virtual ~UaAddNodesItems();

    UaAddNodesItems& operator=(const UaAddNodesItems &other);
    const OpcUa_AddNodesItem& operator[](OpcUa_UInt32 index) const;
    OpcUa_AddNodesItem& operator[](OpcUa_UInt32 index);

    bool operator==(const UaAddNodesItems &other) const;
    bool operator!=(const UaAddNodesItems &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_AddNodesItem* data);
    void attach(OpcUa_Int32 length, OpcUa_AddNodesItem* data);
    OpcUa_AddNodesItem* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_AddNodesItem* rawData() const {return m_data;}
    inline OpcUa_AddNodesItem* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setAddNodesItems(const UaVariant &variant);
    OpcUa_StatusCode setAddNodesItems(const OpcUa_Variant &variant);
    OpcUa_StatusCode setAddNodesItems(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setAddNodesItems(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setAddNodesItems(OpcUa_Int32 length, OpcUa_AddNodesItem* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_AddNodesItem* m_data;
};

#endif // UAADDNODESITEM_H

