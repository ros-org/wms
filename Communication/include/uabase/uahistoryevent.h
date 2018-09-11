/******************************************************************************
** uahistoryevent.h
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
** Portable UaHistoryEvent class.
**
******************************************************************************/
#ifndef UAHISTORYEVENT_H
#define UAHISTORYEVENT_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uahistoryeventfieldlist.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaHistoryEventPrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_HistoryEvent.
 *
 *  This class encapsulates the native OpcUa_HistoryEvent structure
 *  and handles memory allocation and cleanup for you.
 *  UaHistoryEvent uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared HistoryEvent it creates a copy for that (copy-on-write).
 *  So assigning another UaHistoryEvent or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  A table structure that is used to return Event fields to a Historical Read.
 *
 *  The structure is in the form of a table consisting of one or more Events, each
 *  containing an array of one or more fields. The selection and order of the
 *  fields returned for each Event is identical to the selected parameter of the
 *  EventFilter.
 */
class UABASE_EXPORT UaHistoryEvent
{
    UA_DECLARE_PRIVATE(UaHistoryEvent)
public:
    UaHistoryEvent();
    UaHistoryEvent(const UaHistoryEvent &other);
    UaHistoryEvent(const OpcUa_HistoryEvent &other);
    UaHistoryEvent(
        const UaHistoryEventFieldLists &events
        );
    UaHistoryEvent(const UaExtensionObject &extensionObject);
    UaHistoryEvent(const OpcUa_ExtensionObject &extensionObject);
    UaHistoryEvent(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaHistoryEvent(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaHistoryEvent();

    void clear();

    bool operator==(const UaHistoryEvent &other) const;
    bool operator!=(const UaHistoryEvent &other) const;

    UaHistoryEvent& operator=(const UaHistoryEvent &other);

    OpcUa_HistoryEvent* copy() const;
    void copyTo(OpcUa_HistoryEvent *pDst) const;

    static OpcUa_HistoryEvent* clone(const OpcUa_HistoryEvent& source);
    static void cloneTo(const OpcUa_HistoryEvent& source, OpcUa_HistoryEvent& copy);

    void attach(OpcUa_HistoryEvent *pValue);
    OpcUa_HistoryEvent* detach(OpcUa_HistoryEvent* pDst);

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

    OpcUa_StatusCode setHistoryEvent(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setHistoryEvent(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setHistoryEvent(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setHistoryEvent(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setHistoryEvent(
        const UaHistoryEventFieldLists &events
        );

    void getEvents(UaHistoryEventFieldLists& events) const;

    void setEvents(const UaHistoryEventFieldLists &events);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_HistoryEvent.
 *
 *  This class encapsulates an array of the native OpcUa_HistoryEvent structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaHistoryEvent for information about the encapsulated structure.
 */
class UABASE_EXPORT UaHistoryEvents
{
public:
    UaHistoryEvents();
    UaHistoryEvents(const UaHistoryEvents &other);
    UaHistoryEvents(OpcUa_Int32 length, OpcUa_HistoryEvent* data);
    virtual ~UaHistoryEvents();

    UaHistoryEvents& operator=(const UaHistoryEvents &other);
    const OpcUa_HistoryEvent& operator[](OpcUa_UInt32 index) const;
    OpcUa_HistoryEvent& operator[](OpcUa_UInt32 index);

    bool operator==(const UaHistoryEvents &other) const;
    bool operator!=(const UaHistoryEvents &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_HistoryEvent* data);
    void attach(OpcUa_Int32 length, OpcUa_HistoryEvent* data);
    OpcUa_HistoryEvent* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_HistoryEvent* rawData() const {return m_data;}
    inline OpcUa_HistoryEvent* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setHistoryEvents(const UaVariant &variant);
    OpcUa_StatusCode setHistoryEvents(const OpcUa_Variant &variant);
    OpcUa_StatusCode setHistoryEvents(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setHistoryEvents(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setHistoryEvents(OpcUa_Int32 length, OpcUa_HistoryEvent* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_HistoryEvent* m_data;
};

#endif // UAHISTORYEVENT_H

