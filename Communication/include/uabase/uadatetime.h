/******************************************************************************
** uadatetime.h
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
** Date and time handling class.
**
******************************************************************************/
#ifndef UADATETIME_H
#define UADATETIME_H

#include <time.h>
#include "opcua_proxystub.h"
#include "opcua_datetime.h"
#include "uastring.h"

class UABASE_EXPORT UaVariant;
class UABASE_EXPORT UaDataValue;

/** @ingroup CppBaseLibraryClass
 @brief Wrapper class for the UA stack structure OpcUa_DateTime.

 Helper class for handling the OPC UA built-in data type DateTime. It provides conversion and
 comparison functions and allows to create a current timestamp.

 A DateTime value is a 64-bit signed integer which represents the number of 100 nanosecond intervals
 since January 1, 1601 (UTC). It is normally represented by the structure OpcUa_DateTime with the two UInt32
 members dwLowDateTime and dwHighDateTime. This may be different on special platforms.

 Not all platforms will be able to represent the full range of dates and times that can be
 represented with this built-in data type. For example, the UNIX time_t structure only has a 1 second
 resolution and cannot represent dates prior to 1970. For this reason, a number of rules shall be
 applied when dealing with date/time values that exceed the dynamic range of a platform. These rules are:
 - A DateTime value is 0 if either the value is equal to or earlier than 1601-01-01 12:00AM or the value is the
   earliest date that can be represented within the platform.
 - A DateTime value is the maximum Int64 value if either the value is equal to or greater than 9999-01-01 11:59:59PM
   or the value is the latest date/time that can be represented within the platform.
 - A value is the earliest time on the platform if either the DateTime value is 0 or the DateTime value represents a time
   earlier than the earliest time that can be represented within the platform.
 - A value is the latest time on the platform if either the DateTime is the maximum value for an Int64 or the DateTime
   represents a time later than the latest time that can be represented within the platform.

 These rules imply that the earliest and latest times that can be represented on a given platform are invalid date/time
 values and should be treated that way by applications.
*/
class UABASE_EXPORT UaDateTime
{
public:
    UaDateTime();
    UaDateTime(const OpcUa_DateTime&);
    virtual ~UaDateTime();

#ifdef _UA_WIN32
    UaDateTime(const FILETIME&);
    UaDateTime& operator=(const FILETIME&);
    operator FILETIME() const;
#endif

    UaDateTime(const OpcUa_Int64&);
    UaDateTime& operator=(const OpcUa_Int64&);
    operator OpcUa_Int64() const;

    operator OpcUa_DateTime() const;
    bool operator<(const UaDateTime &other) const;
    bool operator>(const UaDateTime &other) const;
    bool operator==(const UaDateTime &other) const;
    bool operator!=(const UaDateTime &other) const;

    static UaDateTime now();
    static UaDateTime fromString(const UaString&);
    static UaDateTime fromTime_t(time_t tim);
    UaString toString() const;
    UaString toDateString() const;
    UaString toTimeString() const;
    time_t   toTime_t() const;
    int msec() const;

    OpcUa_Boolean isNull() const;

    OpcUa_Int32 daysTo(const UaDateTime&) const;
    OpcUa_Int32 secsTo(const UaDateTime&) const;
    OpcUa_Int64 msecsTo(const UaDateTime&) const;
    void addSecs(int secs);
    void addMilliSecs(int msecs);

    void copyTo(OpcUa_DateTime *copy) const;

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;

private:
    OpcUa_DateTime m_dateTime;

    friend UABASE_EXPORT UaDataStream &operator<<(UaDataStream &, const UaDateTime &);
    friend UABASE_EXPORT UaDataStream &operator>>(UaDataStream &, UaDateTime &);
};

// define UaDataStream operators for UaDateTime
UABASE_EXPORT UaDataStream &operator<<(UaDataStream &, const UaDateTime &);
UABASE_EXPORT UaDataStream &operator>>(UaDataStream &, UaDateTime &);

#endif // UADATETIME_H

