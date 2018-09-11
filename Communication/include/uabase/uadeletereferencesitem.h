/******************************************************************************
** uadeletereferencesitem.h
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
** Portable UaDeleteReferencesItem class.
**
******************************************************************************/
#ifndef UADELETEREFERENCESITEM_H
#define UADELETEREFERENCESITEM_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uaexpandednodeid.h"
#include "uanodeid.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaDeleteReferencesItemPrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_DeleteReferencesItem.
 *
 *  This class encapsulates the native OpcUa_DeleteReferencesItem structure
 *  and handles memory allocation and cleanup for you.
 *  UaDeleteReferencesItem uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared DeleteReferencesItem it creates a copy for that (copy-on-write).
 *  So assigning another UaDeleteReferencesItem or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  A structure that is defined as the type of the referencesToDelete parameter of
 *  the DeleteReferences service.
 */
class UABASE_EXPORT UaDeleteReferencesItem
{
    UA_DECLARE_PRIVATE(UaDeleteReferencesItem)
public:
    UaDeleteReferencesItem();
    UaDeleteReferencesItem(const UaDeleteReferencesItem &other);
    UaDeleteReferencesItem(const OpcUa_DeleteReferencesItem &other);
    UaDeleteReferencesItem(
        const UaNodeId& sourceNodeId,
        const UaNodeId& referenceTypeId,
        OpcUa_Boolean isForward,
        const UaExpandedNodeId& targetNodeId,
        OpcUa_Boolean deleteBidirectional
        );
    UaDeleteReferencesItem(const UaExtensionObject &extensionObject);
    UaDeleteReferencesItem(const OpcUa_ExtensionObject &extensionObject);
    UaDeleteReferencesItem(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaDeleteReferencesItem(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaDeleteReferencesItem();

    void clear();

    bool operator==(const UaDeleteReferencesItem &other) const;
    bool operator!=(const UaDeleteReferencesItem &other) const;

    UaDeleteReferencesItem& operator=(const UaDeleteReferencesItem &other);

    OpcUa_DeleteReferencesItem* copy() const;
    void copyTo(OpcUa_DeleteReferencesItem *pDst) const;

    static OpcUa_DeleteReferencesItem* clone(const OpcUa_DeleteReferencesItem& source);
    static void cloneTo(const OpcUa_DeleteReferencesItem& source, OpcUa_DeleteReferencesItem& copy);

    void attach(OpcUa_DeleteReferencesItem *pValue);
    OpcUa_DeleteReferencesItem* detach(OpcUa_DeleteReferencesItem* pDst);

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

    OpcUa_StatusCode setDeleteReferencesItem(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setDeleteReferencesItem(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setDeleteReferencesItem(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setDeleteReferencesItem(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setDeleteReferencesItem(
        const UaNodeId& sourceNodeId,
        const UaNodeId& referenceTypeId,
        OpcUa_Boolean isForward,
        const UaExpandedNodeId& targetNodeId,
        OpcUa_Boolean deleteBidirectional
        );

    UaNodeId getSourceNodeId() const;
    UaNodeId getReferenceTypeId() const;
    OpcUa_Boolean getIsForward() const;
    UaExpandedNodeId getTargetNodeId() const;
    OpcUa_Boolean getDeleteBidirectional() const;

    void setSourceNodeId(const UaNodeId& sourceNodeId);
    void setReferenceTypeId(const UaNodeId& referenceTypeId);
    void setIsForward(OpcUa_Boolean isForward);
    void setTargetNodeId(const UaExpandedNodeId& targetNodeId);
    void setDeleteBidirectional(OpcUa_Boolean deleteBidirectional);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_DeleteReferencesItem.
 *
 *  This class encapsulates an array of the native OpcUa_DeleteReferencesItem structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaDeleteReferencesItem for information about the encapsulated structure.
 */
class UABASE_EXPORT UaDeleteReferencesItems
{
public:
    UaDeleteReferencesItems();
    UaDeleteReferencesItems(const UaDeleteReferencesItems &other);
    UaDeleteReferencesItems(OpcUa_Int32 length, OpcUa_DeleteReferencesItem* data);
    virtual ~UaDeleteReferencesItems();

    UaDeleteReferencesItems& operator=(const UaDeleteReferencesItems &other);
    const OpcUa_DeleteReferencesItem& operator[](OpcUa_UInt32 index) const;
    OpcUa_DeleteReferencesItem& operator[](OpcUa_UInt32 index);

    bool operator==(const UaDeleteReferencesItems &other) const;
    bool operator!=(const UaDeleteReferencesItems &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_DeleteReferencesItem* data);
    void attach(OpcUa_Int32 length, OpcUa_DeleteReferencesItem* data);
    OpcUa_DeleteReferencesItem* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_DeleteReferencesItem* rawData() const {return m_data;}
    inline OpcUa_DeleteReferencesItem* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setDeleteReferencesItems(const UaVariant &variant);
    OpcUa_StatusCode setDeleteReferencesItems(const OpcUa_Variant &variant);
    OpcUa_StatusCode setDeleteReferencesItems(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setDeleteReferencesItems(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setDeleteReferencesItems(OpcUa_Int32 length, OpcUa_DeleteReferencesItem* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_DeleteReferencesItem* m_data;
};

#endif // UADELETEREFERENCESITEM_H

