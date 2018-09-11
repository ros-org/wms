/******************************************************************************
** uaguid.h
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
** GUID handling class.
**
******************************************************************************/
#ifndef UAGUID_H
#define UAGUID_H

#include "opcua_proxystub.h"
#include "opcua_guid.h"
#include "uastring.h"

class UABASE_EXPORT UaVariant;
class UABASE_EXPORT UaDataValue;

/** @ingroup CppBaseLibraryClass
 @brief Wrapper class for the UA stack structure OpcUa_Guid

 Helper class for handling the OPC UA built-in data type Guid. It provides conversion and
 comparison functions and allows creation of a Guid.

 Using Globally Unique IDentifiers (GUID) is a standard way to globally identify
 entities in a distributed computing environment. It is a 128-bit value.
*/
class UABASE_EXPORT UaGuid : private OpcUa_Guid
{
    bool operator<(const UaGuid&) const; // not implemented
    bool operator>(const UaGuid&) const; // not implemented
public:
    UaGuid();
    UaGuid(const UaGuid &other);
    UaGuid(const OpcUa_Guid &other);
    ~UaGuid();
    void clear();

    UaGuid& operator=(const UaGuid &other);

    static UaGuid create();

    bool operator==(const UaGuid &other) const;
    bool operator!=(const UaGuid &other) const;
    static bool compare(const OpcUa_Guid&, const OpcUa_Guid&);

    bool isNull() const;

    operator const OpcUa_Guid*() const;

    OpcUa_Guid* copy() const;
    void copyTo(OpcUa_Guid *pDst) const;

    static OpcUa_Guid* clone(const OpcUa_Guid& source);
    static void cloneTo(const OpcUa_Guid& source, const OpcUa_Guid& copy);

    UaString toString() const;
    OpcUa_StatusCode fromString(const UaString &);

    inline const OpcUa_Guid* guid() const { return this; };

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
};

#endif // UAGUID_H

