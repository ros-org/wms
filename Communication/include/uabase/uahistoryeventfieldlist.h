/******************************************************************************
** uahistoryeventfieldlist.h
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
** Portable UaHistoryEventFieldList class.
**
******************************************************************************/
#ifndef UAHISTORYEVENTFIELDLIST_H
#define UAHISTORYEVENTFIELDLIST_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uavariant.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaDataValue;

class UABASE_EXPORT UaHistoryEventFieldListPrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_HistoryEventFieldList.
 *
 *  This class encapsulates the native OpcUa_HistoryEventFieldList structure
 *  and handles memory allocation and cleanup for you.
 *  UaHistoryEventFieldList uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared HistoryEventFieldList it creates a copy for that (copy-on-write).
 *  So assigning another UaHistoryEventFieldList or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 */
class UABASE_EXPORT UaHistoryEventFieldList
{
    UA_DECLARE_PRIVATE(UaHistoryEventFieldList)
public:
    UaHistoryEventFieldList();
    UaHistoryEventFieldList(const UaHistoryEventFieldList &other);
    UaHistoryEventFieldList(const OpcUa_HistoryEventFieldList &other);
    UaHistoryEventFieldList(
        const UaVariantArray &eventFields
        );
    UaHistoryEventFieldList(const UaExtensionObject &extensionObject);
    UaHistoryEventFieldList(const OpcUa_ExtensionObject &extensionObject);
    UaHistoryEventFieldList(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaHistoryEventFieldList(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaHistoryEventFieldList();

    void clear();

    bool operator==(const UaHistoryEventFieldList &other) const;
    bool operator!=(const UaHistoryEventFieldList &other) const;

    UaHistoryEventFieldList& operator=(const UaHistoryEventFieldList &other);

    const OpcUa_Variant& operator[](OpcUa_UInt32 index) const;
    OpcUa_Variant& operator[](OpcUa_UInt32 index);

    OpcUa_HistoryEventFieldList* copy() const;
    void copyTo(OpcUa_HistoryEventFieldList *pDst) const;

    static OpcUa_HistoryEventFieldList* clone(const OpcUa_HistoryEventFieldList& source);
    static void cloneTo(const OpcUa_HistoryEventFieldList& source, OpcUa_HistoryEventFieldList& copy);

    void attach(OpcUa_HistoryEventFieldList *pValue);
    OpcUa_HistoryEventFieldList* detach(OpcUa_HistoryEventFieldList* pDst);

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

    OpcUa_StatusCode setHistoryEventFieldList(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setHistoryEventFieldList(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setHistoryEventFieldList(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setHistoryEventFieldList(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setHistoryEventFieldList(
        const UaVariantArray &eventFields
        );

    void getEventFields(UaVariantArray& eventFields) const;

    void setEventFields(const UaVariantArray &eventFields);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_HistoryEventFieldList.
 *
 *  This class encapsulates an array of the native OpcUa_HistoryEventFieldList structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaHistoryEventFieldList for information about the encapsulated structure.
 */
class UABASE_EXPORT UaHistoryEventFieldLists
{
public:
    UaHistoryEventFieldLists();
    UaHistoryEventFieldLists(const UaHistoryEventFieldLists &other);
    UaHistoryEventFieldLists(OpcUa_Int32 length, OpcUa_HistoryEventFieldList* data);
    virtual ~UaHistoryEventFieldLists();

    UaHistoryEventFieldLists& operator=(const UaHistoryEventFieldLists &other);
    const OpcUa_HistoryEventFieldList& operator[](OpcUa_UInt32 index) const;
    OpcUa_HistoryEventFieldList& operator[](OpcUa_UInt32 index);

    bool operator==(const UaHistoryEventFieldLists &other) const;
    bool operator!=(const UaHistoryEventFieldLists &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_HistoryEventFieldList* data);
    void attach(OpcUa_Int32 length, OpcUa_HistoryEventFieldList* data);
    OpcUa_HistoryEventFieldList* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_HistoryEventFieldList* rawData() const {return m_data;}
    inline OpcUa_HistoryEventFieldList* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setHistoryEventFieldLists(const UaVariant &variant);
    OpcUa_StatusCode setHistoryEventFieldLists(const OpcUa_Variant &variant);
    OpcUa_StatusCode setHistoryEventFieldLists(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setHistoryEventFieldLists(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setHistoryEventFieldLists(OpcUa_Int32 length, OpcUa_HistoryEventFieldList* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_HistoryEventFieldList* m_data;
};

#endif // UAHISTORYEVENTFIELDLIST_H

