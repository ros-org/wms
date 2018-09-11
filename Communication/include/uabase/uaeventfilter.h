/******************************************************************************
** uaeventfilter.h
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
** EventFilter handling class.
**
******************************************************************************/
#ifndef UAEVETNFILTER_H
#define UAEVETNFILTER_H

#include "opcua_proxystub.h"
#include "uastring.h"
#include "uacontentfilter.h"

/** @ingroup CppBaseLibraryClass
 * Wrapper class for the OPC UA EventFilter structure
 *
 * The EventFilter provides for the filtering and content selection of Event Subscriptions.
 * If an Event Notification conforms to the filter defined by the where parameter of the
 * EventFilter, then the Notification is sent to the Client. Each Event Notification includes
 * the fields defined by the selectClauses parameter of the EventFilter.
 */
class UABASE_EXPORT UaEventFilter
{
public:
    UaEventFilter();
    UaEventFilter(const UaEventFilter &other);
    UaEventFilter(const OpcUa_EventFilter &other);
    ~UaEventFilter();
    void clear();

    UaEventFilter& operator=(const UaEventFilter &other);

    void setSelectClauseElement(OpcUa_UInt32 index, const UaSimpleAttributeOperand& selectElement, OpcUa_UInt32 arraySize);
    void setWhereClause(UaContentFilter* pWhereClause);

    void detachFilter(OpcUa_ExtensionObject& filter);
    void copyFilter(OpcUa_EventFilter& filter) const;

    const UaSimpleAttributeOperands* pSelectClause() const;
    const UaContentFilter* pWhereClause() const;

private:
    UaSimpleAttributeOperands m_selectClause;
    UaContentFilter*          m_pWhereClause;
};

#endif // UAEVETNFILTER_H

