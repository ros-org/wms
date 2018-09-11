/******************************************************************************
** uaaddreferencesitem.h
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
** Portable UaAddReferencesItem class.
**
******************************************************************************/
#ifndef UAADDREFERENCESITEM_H
#define UAADDREFERENCESITEM_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uaexpandednodeid.h"
#include "uanodeid.h"
#include "uastring.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaAddReferencesItemPrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_AddReferencesItem.
 *
 *  This class encapsulates the native OpcUa_AddReferencesItem structure
 *  and handles memory allocation and cleanup for you.
 *  UaAddReferencesItem uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared AddReferencesItem it creates a copy for that (copy-on-write).
 *  So assigning another UaAddReferencesItem or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  A structure that is defined as the type of the referencesToAdd parameter of the
 *  AddReferences Service.
 */
class UABASE_EXPORT UaAddReferencesItem
{
    UA_DECLARE_PRIVATE(UaAddReferencesItem)
public:
    UaAddReferencesItem();
    UaAddReferencesItem(const UaAddReferencesItem &other);
    UaAddReferencesItem(const OpcUa_AddReferencesItem &other);
    UaAddReferencesItem(
        const UaNodeId& sourceNodeId,
        const UaNodeId& referenceTypeId,
        OpcUa_Boolean isForward,
        const UaString& targetServerUri,
        const UaExpandedNodeId& targetNodeId,
        OpcUa_NodeClass targetNodeClass
        );
    UaAddReferencesItem(const UaExtensionObject &extensionObject);
    UaAddReferencesItem(const OpcUa_ExtensionObject &extensionObject);
    UaAddReferencesItem(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaAddReferencesItem(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaAddReferencesItem();

    void clear();

    bool operator==(const UaAddReferencesItem &other) const;
    bool operator!=(const UaAddReferencesItem &other) const;

    UaAddReferencesItem& operator=(const UaAddReferencesItem &other);

    OpcUa_AddReferencesItem* copy() const;
    void copyTo(OpcUa_AddReferencesItem *pDst) const;

    static OpcUa_AddReferencesItem* clone(const OpcUa_AddReferencesItem& source);
    static void cloneTo(const OpcUa_AddReferencesItem& source, OpcUa_AddReferencesItem& copy);

    void attach(OpcUa_AddReferencesItem *pValue);
    OpcUa_AddReferencesItem* detach(OpcUa_AddReferencesItem* pDst);

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

    OpcUa_StatusCode setAddReferencesItem(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setAddReferencesItem(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setAddReferencesItem(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setAddReferencesItem(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setAddReferencesItem(
        const UaNodeId& sourceNodeId,
        const UaNodeId& referenceTypeId,
        OpcUa_Boolean isForward,
        const UaString& targetServerUri,
        const UaExpandedNodeId& targetNodeId,
        OpcUa_NodeClass targetNodeClass
        );

    UaNodeId getSourceNodeId() const;
    UaNodeId getReferenceTypeId() const;
    OpcUa_Boolean getIsForward() const;
    UaString getTargetServerUri() const;
    UaExpandedNodeId getTargetNodeId() const;
    OpcUa_NodeClass getTargetNodeClass() const;

    void setSourceNodeId(const UaNodeId& sourceNodeId);
    void setReferenceTypeId(const UaNodeId& referenceTypeId);
    void setIsForward(OpcUa_Boolean isForward);
    void setTargetServerUri(const UaString& targetServerUri);
    void setTargetNodeId(const UaExpandedNodeId& targetNodeId);
    void setTargetNodeClass(OpcUa_NodeClass targetNodeClass);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_AddReferencesItem.
 *
 *  This class encapsulates an array of the native OpcUa_AddReferencesItem structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaAddReferencesItem for information about the encapsulated structure.
 */
class UABASE_EXPORT UaAddReferencesItems
{
public:
    UaAddReferencesItems();
    UaAddReferencesItems(const UaAddReferencesItems &other);
    UaAddReferencesItems(OpcUa_Int32 length, OpcUa_AddReferencesItem* data);
    virtual ~UaAddReferencesItems();

    UaAddReferencesItems& operator=(const UaAddReferencesItems &other);
    const OpcUa_AddReferencesItem& operator[](OpcUa_UInt32 index) const;
    OpcUa_AddReferencesItem& operator[](OpcUa_UInt32 index);

    bool operator==(const UaAddReferencesItems &other) const;
    bool operator!=(const UaAddReferencesItems &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_AddReferencesItem* data);
    void attach(OpcUa_Int32 length, OpcUa_AddReferencesItem* data);
    OpcUa_AddReferencesItem* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_AddReferencesItem* rawData() const {return m_data;}
    inline OpcUa_AddReferencesItem* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setAddReferencesItems(const UaVariant &variant);
    OpcUa_StatusCode setAddReferencesItems(const OpcUa_Variant &variant);
    OpcUa_StatusCode setAddReferencesItems(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setAddReferencesItems(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setAddReferencesItems(OpcUa_Int32 length, OpcUa_AddReferencesItem* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_AddReferencesItem* m_data;
};

#endif // UAADDREFERENCESITEM_H

