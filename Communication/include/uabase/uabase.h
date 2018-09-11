/******************************************************************************
** uabase.h
**
** Copyright (c) 2006-2015 Unified Automation GmbH All rights reserved.
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
** OPC UA base library include.
**
******************************************************************************/
#ifndef UABASE_H
#define UABASE_H

#ifndef RC_INVOKED
#include "opcua_proxystub.h"
#include "uaplatformdefs.h"
#endif

//----------------------------------------------------------------------------
//    Product name and version OPC UA SDK
//
#define PROD_MAJOR  1
#define PROD_MINOR  5
#define PROD_PATCH  6
#define PROD_BUILD  361
#define PROD_SUFFIX " / f354bd7d2993dccda9f971ed95ee1fe44705877d"

// Compat define for 1.4.x versions
#define PROD_MINOR2 PROD_PATCH

// Convert numbers to strings
#define chSTR(x) #x
#define chSTR2(x) chSTR(x)

#define PROD_VER_FILEVERSION PROD_MAJOR,PROD_MINOR,PROD_PATCH,PROD_BUILD
#define PROD_VER_FILEVERSION_STR chSTR2(PROD_MAJOR) "." chSTR2(PROD_MINOR)  "." chSTR2(PROD_PATCH) "." chSTR2(PROD_BUILD) PROD_SUFFIX
//----------------------------------------------------------------------------

const OpcUa_UInt32 Ua_AccessLevel_None                = 0x0;
const OpcUa_UInt32 Ua_AccessLevel_CurrentRead         = 0x1;
const OpcUa_UInt32 Ua_AccessLevel_CurrentWrite        = 0x2;
const OpcUa_UInt32 Ua_AccessLevel_HistoryRead         = 0x4;
const OpcUa_UInt32 Ua_AccessLevel_HistoryWrite        = 0x8;

const OpcUa_UInt32 Ua_EventNotifier_None              = OpcUa_EventNotifiers_None;
const OpcUa_UInt32 Ua_EventNotifier_SubscribeToEvents = OpcUa_EventNotifiers_SubscribeToEvents;
const OpcUa_UInt32 Ua_EventNotifier_HistoryRead       = OpcUa_EventNotifiers_HistoryRead;
const OpcUa_UInt32 Ua_EventNotifier_HistoryWrite      = OpcUa_EventNotifiers_HistoryWrite;

#define UA_DISABLE_COPY(Class) \
     Class(const Class &); \
     Class &operator=(const Class &)

///////////////////////////////////////////////
// Private Class Hiding Macros
#define UA_DECLARE_PRIVATE(Class) \
    inline Class##Private* d_func() { return reinterpret_cast<Class##Private *>(d_ptr); } \
    inline const Class##Private* d_func() const { return reinterpret_cast<const Class##Private *>(d_ptr); } \
    friend class Class##Private; \
    Class##Private *d_ptr;

#define UA_DECLARE_PUBLIC(Class) \
    inline Class* q_func() { return static_cast<Class *>(q_ptr); } \
    inline const Class* q_func() const { return static_cast<const Class *>(q_ptr); } \
    friend class Class;

#define UA_D(Class) Class##Private * const d = d_func()
#define UA_CD(Class) const Class##Private * const d = d_func()
#define UA_Q(Class) Class * const q = q_func()

// Class for handling flags
template<typename Enum>
class UaFlags
{
    OpcUa_Int i;
public:
    typedef Enum enum_type;
    inline UaFlags(const UaFlags &f) : i(f.i) {}
    inline UaFlags(Enum f) : i(f) {}
    inline UaFlags(OpcUa_Int ai = 0) : i(ai) {}

    inline UaFlags operator|(UaFlags f) const { return UaFlags(Enum(i | f.i)); }
    inline UaFlags operator|(Enum f) const { return UaFlags(Enum(i | f)); }
    inline UaFlags &operator|=(UaFlags f) { i |= f.i; return *this; }
    inline UaFlags &operator|=(Enum f) { i |= f; return *this; }

    inline UaFlags operator&(OpcUa_Int mask) const { return UaFlags(Enum(i & mask)); }
    inline UaFlags operator&(OpcUa_UInt mask) const { return UaFlags(Enum(i & mask)); }
    inline UaFlags operator&(Enum f) const { return UaFlags(Enum(i & f)); }
    inline UaFlags &operator&=(OpcUa_Int mask) { i &= mask; return *this; }
    inline UaFlags &operator&=(OpcUa_UInt mask) { i &= mask; return *this; }

    inline UaFlags &operator=(const UaFlags &f) { i = f.i; return *this; }

    inline UaFlags operator^(UaFlags f) const { return UaFlags(Enum(i ^ f.i)); }
    inline UaFlags operator^(Enum f) const { return UaFlags(Enum(i ^ f)); }
    inline UaFlags &operator^=(UaFlags f) { i ^= f.i; return *this; }
    inline UaFlags &operator^=(Enum f) { i ^= f; return *this; }
    inline operator OpcUa_Int() const { return i; }

    inline UaFlags operator~() const { return UaFlags(Enum(~i)); }

    inline OpcUa_Boolean hasFlag(Enum f) const
    {
        if ((i & f) == f &&
            (f != 0 || i == OpcUa_Int(f)))
        {
            return OpcUa_True;
        }
        else
        {
            return OpcUa_False;
        }
    }
};

/** This interface provides a method for mapping namespace indices. */
class NamespaceMappingInterface
{
public:
    virtual ~NamespaceMappingInterface() {}

    virtual OpcUa_UInt16 mapIndex(OpcUa_UInt16 nsIdx) const = 0;
};

#define UA_DECLARE_FLAGS(Flags, Enum)\
typedef UaFlags<Enum> Flags;

// default to to support XML parsing
#ifndef SUPPORT_XML_PARSER
#define SUPPORT_XML_PARSER OPCUA_CONFIG_ON
#endif

// Add COM data type conversion utilities, e.g. in UaVariant
#ifndef UASDK_WITH_COM_UTILITIES
#define UASDK_WITH_COM_UTILITIES OPCUA_CONFIG_OFF
#endif

// Controls case sensitive compare of NodeId in UaNodeId and HashTable
#ifndef CASE_SENSITIVE_Compare_NodeId
#define CASE_SENSITIVE_Compare_NodeId OPCUA_CONFIG_YES
#endif

// Controls case sensitive compare of qualified name in UaQualifiedName
#ifndef CASE_SENSITIVE_Compare_QualifiedName
#define CASE_SENSITIVE_Compare_QualifiedName OPCUA_CONFIG_YES
#endif

#endif // UABASE_H
