/******************************************************************************
** uaarraytemplates.h
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
** Portable Ua ArrayTemplates classes.
**
******************************************************************************/
#ifndef UAARRAYTEMPLATES_H
#define UAARRAYTEMPLATES_H

#include "uaplatformdefs.h"
#include "assert.h"
#include "opcua_memory.h"
#include "uabase.h"
#include "opcua_string.h"

class UaVariant;
class UaDataValue;

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_AddNodesResult.
 *
 *  This class encapsulates an array of the native OpcUa_AddNodesResult structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaAddNodesResults
{
public:
    UaAddNodesResults();
    UaAddNodesResults(const UaAddNodesResults &other);
    UaAddNodesResults(OpcUa_Int32 length, OpcUa_AddNodesResult* data);
    virtual ~UaAddNodesResults();

    UaAddNodesResults& operator=(const UaAddNodesResults &other);
    const OpcUa_AddNodesResult& operator[](OpcUa_UInt32 index) const;
    OpcUa_AddNodesResult& operator[](OpcUa_UInt32 index);

    bool operator==(const UaAddNodesResults &other) const;
    bool operator!=(const UaAddNodesResults &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_AddNodesResult* data);
    void attach(OpcUa_Int32 length, OpcUa_AddNodesResult* data);
    OpcUa_AddNodesResult* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_AddNodesResult* rawData() const {return m_data;}
    inline OpcUa_AddNodesResult* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setAddNodesResults(const UaVariant &variant);
    OpcUa_StatusCode setAddNodesResults(const OpcUa_Variant &variant);
    OpcUa_StatusCode setAddNodesResults(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setAddNodesResults(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setAddNodesResults(OpcUa_Int32 length, OpcUa_AddNodesResult* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_AddNodesResult* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_Boolean.
 *
 *  This class encapsulates an array of the native OpcUa_Boolean structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaBooleanArray
{
public:
    UaBooleanArray();
    UaBooleanArray(const UaBooleanArray &other);
    UaBooleanArray(OpcUa_Int32 length, OpcUa_Boolean* data);
    virtual ~UaBooleanArray();

    UaBooleanArray& operator=(const UaBooleanArray &other);
    const OpcUa_Boolean& operator[](OpcUa_UInt32 index) const;
    OpcUa_Boolean& operator[](OpcUa_UInt32 index);

    bool operator==(const UaBooleanArray &other) const;
    bool operator!=(const UaBooleanArray &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_Boolean* data);
    void attach(OpcUa_Int32 length, OpcUa_Boolean* data);
    OpcUa_Boolean* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_Boolean* rawData() const {return m_data;}
    inline OpcUa_Boolean* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setBooleanArray(const UaVariant &variant);
    OpcUa_StatusCode setBooleanArray(const OpcUa_Variant &variant);
    OpcUa_StatusCode setBooleanArray(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setBooleanArray(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setBooleanArray(OpcUa_Int32 length, OpcUa_Boolean* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_Boolean* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_BrowseDescription.
 *
 *  This class encapsulates an array of the native OpcUa_BrowseDescription structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaBrowseDescriptions
{
public:
    UaBrowseDescriptions();
    UaBrowseDescriptions(const UaBrowseDescriptions &other);
    UaBrowseDescriptions(OpcUa_Int32 length, OpcUa_BrowseDescription* data);
    virtual ~UaBrowseDescriptions();

    UaBrowseDescriptions& operator=(const UaBrowseDescriptions &other);
    const OpcUa_BrowseDescription& operator[](OpcUa_UInt32 index) const;
    OpcUa_BrowseDescription& operator[](OpcUa_UInt32 index);

    bool operator==(const UaBrowseDescriptions &other) const;
    bool operator!=(const UaBrowseDescriptions &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_BrowseDescription* data);
    void attach(OpcUa_Int32 length, OpcUa_BrowseDescription* data);
    OpcUa_BrowseDescription* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_BrowseDescription* rawData() const {return m_data;}
    inline OpcUa_BrowseDescription* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setBrowseDescriptions(const UaVariant &variant);
    OpcUa_StatusCode setBrowseDescriptions(const OpcUa_Variant &variant);
    OpcUa_StatusCode setBrowseDescriptions(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setBrowseDescriptions(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setBrowseDescriptions(OpcUa_Int32 length, OpcUa_BrowseDescription* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_BrowseDescription* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_BrowsePath.
 *
 *  This class encapsulates an array of the native OpcUa_BrowsePath structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaBrowsePaths
{
public:
    UaBrowsePaths();
    UaBrowsePaths(const UaBrowsePaths &other);
    UaBrowsePaths(OpcUa_Int32 length, OpcUa_BrowsePath* data);
    virtual ~UaBrowsePaths();

    UaBrowsePaths& operator=(const UaBrowsePaths &other);
    const OpcUa_BrowsePath& operator[](OpcUa_UInt32 index) const;
    OpcUa_BrowsePath& operator[](OpcUa_UInt32 index);

    bool operator==(const UaBrowsePaths &other) const;
    bool operator!=(const UaBrowsePaths &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_BrowsePath* data);
    void attach(OpcUa_Int32 length, OpcUa_BrowsePath* data);
    OpcUa_BrowsePath* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_BrowsePath* rawData() const {return m_data;}
    inline OpcUa_BrowsePath* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setBrowsePaths(const UaVariant &variant);
    OpcUa_StatusCode setBrowsePaths(const OpcUa_Variant &variant);
    OpcUa_StatusCode setBrowsePaths(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setBrowsePaths(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setBrowsePaths(OpcUa_Int32 length, OpcUa_BrowsePath* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_BrowsePath* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_BrowsePathResult.
 *
 *  This class encapsulates an array of the native OpcUa_BrowsePathResult structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaBrowsePathResults
{
public:
    UaBrowsePathResults();
    UaBrowsePathResults(const UaBrowsePathResults &other);
    UaBrowsePathResults(OpcUa_Int32 length, OpcUa_BrowsePathResult* data);
    virtual ~UaBrowsePathResults();

    UaBrowsePathResults& operator=(const UaBrowsePathResults &other);
    const OpcUa_BrowsePathResult& operator[](OpcUa_UInt32 index) const;
    OpcUa_BrowsePathResult& operator[](OpcUa_UInt32 index);

    bool operator==(const UaBrowsePathResults &other) const;
    bool operator!=(const UaBrowsePathResults &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_BrowsePathResult* data);
    void attach(OpcUa_Int32 length, OpcUa_BrowsePathResult* data);
    OpcUa_BrowsePathResult* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_BrowsePathResult* rawData() const {return m_data;}
    inline OpcUa_BrowsePathResult* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setBrowsePathResults(const UaVariant &variant);
    OpcUa_StatusCode setBrowsePathResults(const OpcUa_Variant &variant);
    OpcUa_StatusCode setBrowsePathResults(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setBrowsePathResults(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setBrowsePathResults(OpcUa_Int32 length, OpcUa_BrowsePathResult* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_BrowsePathResult* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_BrowsePathTarget.
 *
 *  This class encapsulates an array of the native OpcUa_BrowsePathTarget structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaBrowsePathTargets
{
public:
    UaBrowsePathTargets();
    UaBrowsePathTargets(const UaBrowsePathTargets &other);
    UaBrowsePathTargets(OpcUa_Int32 length, OpcUa_BrowsePathTarget* data);
    virtual ~UaBrowsePathTargets();

    UaBrowsePathTargets& operator=(const UaBrowsePathTargets &other);
    const OpcUa_BrowsePathTarget& operator[](OpcUa_UInt32 index) const;
    OpcUa_BrowsePathTarget& operator[](OpcUa_UInt32 index);

    bool operator==(const UaBrowsePathTargets &other) const;
    bool operator!=(const UaBrowsePathTargets &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_BrowsePathTarget* data);
    void attach(OpcUa_Int32 length, OpcUa_BrowsePathTarget* data);
    OpcUa_BrowsePathTarget* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_BrowsePathTarget* rawData() const {return m_data;}
    inline OpcUa_BrowsePathTarget* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setBrowsePathTargets(const UaVariant &variant);
    OpcUa_StatusCode setBrowsePathTargets(const OpcUa_Variant &variant);
    OpcUa_StatusCode setBrowsePathTargets(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setBrowsePathTargets(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setBrowsePathTargets(OpcUa_Int32 length, OpcUa_BrowsePathTarget* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_BrowsePathTarget* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_BrowseResult.
 *
 *  This class encapsulates an array of the native OpcUa_BrowseResult structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaBrowseResults
{
public:
    UaBrowseResults();
    UaBrowseResults(const UaBrowseResults &other);
    UaBrowseResults(OpcUa_Int32 length, OpcUa_BrowseResult* data);
    virtual ~UaBrowseResults();

    UaBrowseResults& operator=(const UaBrowseResults &other);
    const OpcUa_BrowseResult& operator[](OpcUa_UInt32 index) const;
    OpcUa_BrowseResult& operator[](OpcUa_UInt32 index);

    bool operator==(const UaBrowseResults &other) const;
    bool operator!=(const UaBrowseResults &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_BrowseResult* data);
    void attach(OpcUa_Int32 length, OpcUa_BrowseResult* data);
    OpcUa_BrowseResult* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_BrowseResult* rawData() const {return m_data;}
    inline OpcUa_BrowseResult* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setBrowseResults(const UaVariant &variant);
    OpcUa_StatusCode setBrowseResults(const OpcUa_Variant &variant);
    OpcUa_StatusCode setBrowseResults(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setBrowseResults(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setBrowseResults(OpcUa_Int32 length, OpcUa_BrowseResult* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_BrowseResult* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_ByteString.
 *
 *  This class encapsulates an array of the native OpcUa_ByteString structure
 *  and handles memory allocation and cleanup for you.
 *  @see @ref UaByteString for information about the encapsulated structure.
 */
class UABASE_EXPORT UaByteStringArray
{
public:
    UaByteStringArray();
    UaByteStringArray(const UaByteStringArray &other);
    UaByteStringArray(OpcUa_Int32 length, OpcUa_ByteString* data);
    virtual ~UaByteStringArray();

    UaByteStringArray& operator=(const UaByteStringArray &other);
    const OpcUa_ByteString& operator[](OpcUa_UInt32 index) const;
    OpcUa_ByteString& operator[](OpcUa_UInt32 index);

    bool operator==(const UaByteStringArray &other) const;
    bool operator!=(const UaByteStringArray &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_ByteString* data);
    void attach(OpcUa_Int32 length, OpcUa_ByteString* data);
    OpcUa_ByteString* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_ByteString* rawData() const {return m_data;}
    inline OpcUa_ByteString* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setByteStringArray(const UaVariant &variant);
    OpcUa_StatusCode setByteStringArray(const OpcUa_Variant &variant);
    OpcUa_StatusCode setByteStringArray(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setByteStringArray(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setByteStringArray(OpcUa_Int32 length, OpcUa_ByteString* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_ByteString* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_CallMethodRequest.
 *
 *  This class encapsulates an array of the native OpcUa_CallMethodRequest structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaCallMethodRequests
{
public:
    UaCallMethodRequests();
    UaCallMethodRequests(const UaCallMethodRequests &other);
    UaCallMethodRequests(OpcUa_Int32 length, OpcUa_CallMethodRequest* data);
    virtual ~UaCallMethodRequests();

    UaCallMethodRequests& operator=(const UaCallMethodRequests &other);
    const OpcUa_CallMethodRequest& operator[](OpcUa_UInt32 index) const;
    OpcUa_CallMethodRequest& operator[](OpcUa_UInt32 index);

    bool operator==(const UaCallMethodRequests &other) const;
    bool operator!=(const UaCallMethodRequests &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_CallMethodRequest* data);
    void attach(OpcUa_Int32 length, OpcUa_CallMethodRequest* data);
    OpcUa_CallMethodRequest* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_CallMethodRequest* rawData() const {return m_data;}
    inline OpcUa_CallMethodRequest* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setCallMethodRequests(const UaVariant &variant);
    OpcUa_StatusCode setCallMethodRequests(const OpcUa_Variant &variant);
    OpcUa_StatusCode setCallMethodRequests(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setCallMethodRequests(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setCallMethodRequests(OpcUa_Int32 length, OpcUa_CallMethodRequest* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_CallMethodRequest* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_CallMethodResult.
 *
 *  This class encapsulates an array of the native OpcUa_CallMethodResult structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaCallMethodResults
{
public:
    UaCallMethodResults();
    UaCallMethodResults(const UaCallMethodResults &other);
    UaCallMethodResults(OpcUa_Int32 length, OpcUa_CallMethodResult* data);
    virtual ~UaCallMethodResults();

    UaCallMethodResults& operator=(const UaCallMethodResults &other);
    const OpcUa_CallMethodResult& operator[](OpcUa_UInt32 index) const;
    OpcUa_CallMethodResult& operator[](OpcUa_UInt32 index);

    bool operator==(const UaCallMethodResults &other) const;
    bool operator!=(const UaCallMethodResults &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_CallMethodResult* data);
    void attach(OpcUa_Int32 length, OpcUa_CallMethodResult* data);
    OpcUa_CallMethodResult* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_CallMethodResult* rawData() const {return m_data;}
    inline OpcUa_CallMethodResult* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setCallMethodResults(const UaVariant &variant);
    OpcUa_StatusCode setCallMethodResults(const OpcUa_Variant &variant);
    OpcUa_StatusCode setCallMethodResults(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setCallMethodResults(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setCallMethodResults(OpcUa_Int32 length, OpcUa_CallMethodResult* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_CallMethodResult* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_DataValue.
 *
 *  This class encapsulates an array of the native OpcUa_DataValue structure
 *  and handles memory allocation and cleanup for you.
 *  @see @ref UaDataValue for information about the encapsulated structure.
 */
class UABASE_EXPORT UaDataValues
{
public:
    UaDataValues();
    UaDataValues(const UaDataValues &other);
    UaDataValues(OpcUa_Int32 length, OpcUa_DataValue* data);
    virtual ~UaDataValues();

    UaDataValues& operator=(const UaDataValues &other);
    const OpcUa_DataValue& operator[](OpcUa_UInt32 index) const;
    OpcUa_DataValue& operator[](OpcUa_UInt32 index);

    bool operator==(const UaDataValues &other) const;
    bool operator!=(const UaDataValues &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_DataValue* data);
    void attach(OpcUa_Int32 length, OpcUa_DataValue* data);
    OpcUa_DataValue* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_DataValue* rawData() const {return m_data;}
    inline OpcUa_DataValue* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setDataValues(const UaVariant &variant);
    OpcUa_StatusCode setDataValues(const OpcUa_Variant &variant);
    OpcUa_StatusCode setDataValues(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setDataValues(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setDataValues(OpcUa_Int32 length, OpcUa_DataValue* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_DataValue* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_DateTime.
 *
 *  This class encapsulates an array of the native OpcUa_DateTime structure
 *  and handles memory allocation and cleanup for you.
 *  @see @ref UaDateTime for information about the encapsulated structure.
 */
class UABASE_EXPORT UaDateTimeArray
{
public:
    UaDateTimeArray();
    UaDateTimeArray(const UaDateTimeArray &other);
    UaDateTimeArray(OpcUa_Int32 length, OpcUa_DateTime* data);
    virtual ~UaDateTimeArray();

    UaDateTimeArray& operator=(const UaDateTimeArray &other);
    const OpcUa_DateTime& operator[](OpcUa_UInt32 index) const;
    OpcUa_DateTime& operator[](OpcUa_UInt32 index);

    bool operator==(const UaDateTimeArray &other) const;
    bool operator!=(const UaDateTimeArray &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_DateTime* data);
    void attach(OpcUa_Int32 length, OpcUa_DateTime* data);
    OpcUa_DateTime* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_DateTime* rawData() const {return m_data;}
    inline OpcUa_DateTime* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setDateTimeArray(const UaVariant &variant);
    OpcUa_StatusCode setDateTimeArray(const OpcUa_Variant &variant);
    OpcUa_StatusCode setDateTimeArray(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setDateTimeArray(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setDateTimeArray(OpcUa_Int32 length, OpcUa_DateTime* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_DateTime* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_Double.
 *
 *  This class encapsulates an array of the native OpcUa_Double structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaDoubleArray
{
public:
    UaDoubleArray();
    UaDoubleArray(const UaDoubleArray &other);
    UaDoubleArray(OpcUa_Int32 length, OpcUa_Double* data);
    virtual ~UaDoubleArray();

    UaDoubleArray& operator=(const UaDoubleArray &other);
    const OpcUa_Double& operator[](OpcUa_UInt32 index) const;
    OpcUa_Double& operator[](OpcUa_UInt32 index);

    bool operator==(const UaDoubleArray &other) const;
    bool operator!=(const UaDoubleArray &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_Double* data);
    void attach(OpcUa_Int32 length, OpcUa_Double* data);
    OpcUa_Double* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_Double* rawData() const {return m_data;}
    inline OpcUa_Double* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setDoubleArray(const UaVariant &variant);
    OpcUa_StatusCode setDoubleArray(const OpcUa_Variant &variant);
    OpcUa_StatusCode setDoubleArray(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setDoubleArray(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setDoubleArray(OpcUa_Int32 length, OpcUa_Double* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_Double* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_EventFieldList.
 *
 *  This class encapsulates an array of the native OpcUa_EventFieldList structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaEventFieldLists
{
public:
    UaEventFieldLists();
    UaEventFieldLists(const UaEventFieldLists &other);
    UaEventFieldLists(OpcUa_Int32 length, OpcUa_EventFieldList* data);
    virtual ~UaEventFieldLists();

    UaEventFieldLists& operator=(const UaEventFieldLists &other);
    const OpcUa_EventFieldList& operator[](OpcUa_UInt32 index) const;
    OpcUa_EventFieldList& operator[](OpcUa_UInt32 index);

    bool operator==(const UaEventFieldLists &other) const;
    bool operator!=(const UaEventFieldLists &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_EventFieldList* data);
    void attach(OpcUa_Int32 length, OpcUa_EventFieldList* data);
    OpcUa_EventFieldList* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_EventFieldList* rawData() const {return m_data;}
    inline OpcUa_EventFieldList* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setEventFieldLists(const UaVariant &variant);
    OpcUa_StatusCode setEventFieldLists(const OpcUa_Variant &variant);
    OpcUa_StatusCode setEventFieldLists(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setEventFieldLists(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setEventFieldLists(OpcUa_Int32 length, OpcUa_EventFieldList* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_EventFieldList* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_ExpandedNodeId.
 *
 *  This class encapsulates an array of the native OpcUa_ExpandedNodeId structure
 *  and handles memory allocation and cleanup for you.
 *  @see @ref UaExpandedNodeId for information about the encapsulated structure.
 */
class UABASE_EXPORT UaExpandedNodeIdArray
{
public:
    UaExpandedNodeIdArray();
    UaExpandedNodeIdArray(const UaExpandedNodeIdArray &other);
    UaExpandedNodeIdArray(OpcUa_Int32 length, OpcUa_ExpandedNodeId* data);
    virtual ~UaExpandedNodeIdArray();

    UaExpandedNodeIdArray& operator=(const UaExpandedNodeIdArray &other);
    const OpcUa_ExpandedNodeId& operator[](OpcUa_UInt32 index) const;
    OpcUa_ExpandedNodeId& operator[](OpcUa_UInt32 index);

    bool operator==(const UaExpandedNodeIdArray &other) const;
    bool operator!=(const UaExpandedNodeIdArray &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_ExpandedNodeId* data);
    void attach(OpcUa_Int32 length, OpcUa_ExpandedNodeId* data);
    OpcUa_ExpandedNodeId* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_ExpandedNodeId* rawData() const {return m_data;}
    inline OpcUa_ExpandedNodeId* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setExpandedNodeIdArray(const UaVariant &variant);
    OpcUa_StatusCode setExpandedNodeIdArray(const OpcUa_Variant &variant);
    OpcUa_StatusCode setExpandedNodeIdArray(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setExpandedNodeIdArray(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setExpandedNodeIdArray(OpcUa_Int32 length, OpcUa_ExpandedNodeId* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_ExpandedNodeId* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_ExtensionObject.
 *
 *  This class encapsulates an array of the native OpcUa_ExtensionObject structure
 *  and handles memory allocation and cleanup for you.
 *  @see @ref UaExtensionObject for information about the encapsulated structure.
 */
class UABASE_EXPORT UaExtensionObjectArray
{
public:
    UaExtensionObjectArray();
    UaExtensionObjectArray(const UaExtensionObjectArray &other);
    UaExtensionObjectArray(OpcUa_Int32 length, OpcUa_ExtensionObject* data);
    virtual ~UaExtensionObjectArray();

    UaExtensionObjectArray& operator=(const UaExtensionObjectArray &other);
    const OpcUa_ExtensionObject& operator[](OpcUa_UInt32 index) const;
    OpcUa_ExtensionObject& operator[](OpcUa_UInt32 index);

    bool operator==(const UaExtensionObjectArray &other) const;
    bool operator!=(const UaExtensionObjectArray &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_ExtensionObject* data);
    void attach(OpcUa_Int32 length, OpcUa_ExtensionObject* data);
    OpcUa_ExtensionObject* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_ExtensionObject* rawData() const {return m_data;}
    inline OpcUa_ExtensionObject* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setExtensionObjectArray(const UaVariant &variant);
    OpcUa_StatusCode setExtensionObjectArray(const OpcUa_Variant &variant);
    OpcUa_StatusCode setExtensionObjectArray(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setExtensionObjectArray(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setExtensionObjectArray(OpcUa_Int32 length, OpcUa_ExtensionObject* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_ExtensionObject* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_Float.
 *
 *  This class encapsulates an array of the native OpcUa_Float structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaFloatArray
{
public:
    UaFloatArray();
    UaFloatArray(const UaFloatArray &other);
    UaFloatArray(OpcUa_Int32 length, OpcUa_Float* data);
    virtual ~UaFloatArray();

    UaFloatArray& operator=(const UaFloatArray &other);
    const OpcUa_Float& operator[](OpcUa_UInt32 index) const;
    OpcUa_Float& operator[](OpcUa_UInt32 index);

    bool operator==(const UaFloatArray &other) const;
    bool operator!=(const UaFloatArray &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_Float* data);
    void attach(OpcUa_Int32 length, OpcUa_Float* data);
    OpcUa_Float* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_Float* rawData() const {return m_data;}
    inline OpcUa_Float* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setFloatArray(const UaVariant &variant);
    OpcUa_StatusCode setFloatArray(const OpcUa_Variant &variant);
    OpcUa_StatusCode setFloatArray(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setFloatArray(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setFloatArray(OpcUa_Int32 length, OpcUa_Float* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_Float* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_Guid.
 *
 *  This class encapsulates an array of the native OpcUa_Guid structure
 *  and handles memory allocation and cleanup for you.
 *  @see @ref UaGuid for information about the encapsulated structure.
 */
class UABASE_EXPORT UaGuidArray
{
public:
    UaGuidArray();
    UaGuidArray(const UaGuidArray &other);
    UaGuidArray(OpcUa_Int32 length, OpcUa_Guid* data);
    virtual ~UaGuidArray();

    UaGuidArray& operator=(const UaGuidArray &other);
    const OpcUa_Guid& operator[](OpcUa_UInt32 index) const;
    OpcUa_Guid& operator[](OpcUa_UInt32 index);

    bool operator==(const UaGuidArray &other) const;
    bool operator!=(const UaGuidArray &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_Guid* data);
    void attach(OpcUa_Int32 length, OpcUa_Guid* data);
    OpcUa_Guid* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_Guid* rawData() const {return m_data;}
    inline OpcUa_Guid* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setGuidArray(const UaVariant &variant);
    OpcUa_StatusCode setGuidArray(const OpcUa_Variant &variant);
    OpcUa_StatusCode setGuidArray(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setGuidArray(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setGuidArray(OpcUa_Int32 length, OpcUa_Guid* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_Guid* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_HistoryReadResult.
 *
 *  This class encapsulates an array of the native OpcUa_HistoryReadResult structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaHistoryReadResults
{
public:
    UaHistoryReadResults();
    UaHistoryReadResults(const UaHistoryReadResults &other);
    UaHistoryReadResults(OpcUa_Int32 length, OpcUa_HistoryReadResult* data);
    virtual ~UaHistoryReadResults();

    UaHistoryReadResults& operator=(const UaHistoryReadResults &other);
    const OpcUa_HistoryReadResult& operator[](OpcUa_UInt32 index) const;
    OpcUa_HistoryReadResult& operator[](OpcUa_UInt32 index);

    bool operator==(const UaHistoryReadResults &other) const;
    bool operator!=(const UaHistoryReadResults &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_HistoryReadResult* data);
    void attach(OpcUa_Int32 length, OpcUa_HistoryReadResult* data);
    OpcUa_HistoryReadResult* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_HistoryReadResult* rawData() const {return m_data;}
    inline OpcUa_HistoryReadResult* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setHistoryReadResults(const UaVariant &variant);
    OpcUa_StatusCode setHistoryReadResults(const OpcUa_Variant &variant);
    OpcUa_StatusCode setHistoryReadResults(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setHistoryReadResults(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setHistoryReadResults(OpcUa_Int32 length, OpcUa_HistoryReadResult* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_HistoryReadResult* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_HistoryReadValueId.
 *
 *  This class encapsulates an array of the native OpcUa_HistoryReadValueId structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaHistoryReadValueIds
{
public:
    UaHistoryReadValueIds();
    UaHistoryReadValueIds(const UaHistoryReadValueIds &other);
    UaHistoryReadValueIds(OpcUa_Int32 length, OpcUa_HistoryReadValueId* data);
    virtual ~UaHistoryReadValueIds();

    UaHistoryReadValueIds& operator=(const UaHistoryReadValueIds &other);
    const OpcUa_HistoryReadValueId& operator[](OpcUa_UInt32 index) const;
    OpcUa_HistoryReadValueId& operator[](OpcUa_UInt32 index);

    bool operator==(const UaHistoryReadValueIds &other) const;
    bool operator!=(const UaHistoryReadValueIds &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_HistoryReadValueId* data);
    void attach(OpcUa_Int32 length, OpcUa_HistoryReadValueId* data);
    OpcUa_HistoryReadValueId* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_HistoryReadValueId* rawData() const {return m_data;}
    inline OpcUa_HistoryReadValueId* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setHistoryReadValueIds(const UaVariant &variant);
    OpcUa_StatusCode setHistoryReadValueIds(const OpcUa_Variant &variant);
    OpcUa_StatusCode setHistoryReadValueIds(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setHistoryReadValueIds(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setHistoryReadValueIds(OpcUa_Int32 length, OpcUa_HistoryReadValueId* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_HistoryReadValueId* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_HistoryUpdateResult.
 *
 *  This class encapsulates an array of the native OpcUa_HistoryUpdateResult structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaHistoryUpdateResults
{
public:
    UaHistoryUpdateResults();
    UaHistoryUpdateResults(const UaHistoryUpdateResults &other);
    UaHistoryUpdateResults(OpcUa_Int32 length, OpcUa_HistoryUpdateResult* data);
    virtual ~UaHistoryUpdateResults();

    UaHistoryUpdateResults& operator=(const UaHistoryUpdateResults &other);
    const OpcUa_HistoryUpdateResult& operator[](OpcUa_UInt32 index) const;
    OpcUa_HistoryUpdateResult& operator[](OpcUa_UInt32 index);

    bool operator==(const UaHistoryUpdateResults &other) const;
    bool operator!=(const UaHistoryUpdateResults &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_HistoryUpdateResult* data);
    void attach(OpcUa_Int32 length, OpcUa_HistoryUpdateResult* data);
    OpcUa_HistoryUpdateResult* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_HistoryUpdateResult* rawData() const {return m_data;}
    inline OpcUa_HistoryUpdateResult* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setHistoryUpdateResults(const UaVariant &variant);
    OpcUa_StatusCode setHistoryUpdateResults(const OpcUa_Variant &variant);
    OpcUa_StatusCode setHistoryUpdateResults(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setHistoryUpdateResults(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setHistoryUpdateResults(OpcUa_Int32 length, OpcUa_HistoryUpdateResult* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_HistoryUpdateResult* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_Int16.
 *
 *  This class encapsulates an array of the native OpcUa_Int16 structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaInt16Array
{
public:
    UaInt16Array();
    UaInt16Array(const UaInt16Array &other);
    UaInt16Array(OpcUa_Int32 length, OpcUa_Int16* data);
    virtual ~UaInt16Array();

    UaInt16Array& operator=(const UaInt16Array &other);
    const OpcUa_Int16& operator[](OpcUa_UInt32 index) const;
    OpcUa_Int16& operator[](OpcUa_UInt32 index);

    bool operator==(const UaInt16Array &other) const;
    bool operator!=(const UaInt16Array &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_Int16* data);
    void attach(OpcUa_Int32 length, OpcUa_Int16* data);
    OpcUa_Int16* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_Int16* rawData() const {return m_data;}
    inline OpcUa_Int16* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setInt16Array(const UaVariant &variant);
    OpcUa_StatusCode setInt16Array(const OpcUa_Variant &variant);
    OpcUa_StatusCode setInt16Array(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setInt16Array(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setInt16Array(OpcUa_Int32 length, OpcUa_Int16* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_Int16* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_Int32.
 *
 *  This class encapsulates an array of the native OpcUa_Int32 structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaInt32Array
{
public:
    UaInt32Array();
    UaInt32Array(const UaInt32Array &other);
    UaInt32Array(OpcUa_Int32 length, OpcUa_Int32* data);
    virtual ~UaInt32Array();

    UaInt32Array& operator=(const UaInt32Array &other);
    const OpcUa_Int32& operator[](OpcUa_UInt32 index) const;
    OpcUa_Int32& operator[](OpcUa_UInt32 index);

    bool operator==(const UaInt32Array &other) const;
    bool operator!=(const UaInt32Array &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_Int32* data);
    void attach(OpcUa_Int32 length, OpcUa_Int32* data);
    OpcUa_Int32* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_Int32* rawData() const {return m_data;}
    inline OpcUa_Int32* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setInt32Array(const UaVariant &variant);
    OpcUa_StatusCode setInt32Array(const OpcUa_Variant &variant);
    OpcUa_StatusCode setInt32Array(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setInt32Array(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setInt32Array(OpcUa_Int32 length, OpcUa_Int32* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_Int32* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_Int64.
 *
 *  This class encapsulates an array of the native OpcUa_Int64 structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaInt64Array
{
public:
    UaInt64Array();
    UaInt64Array(const UaInt64Array &other);
    UaInt64Array(OpcUa_Int32 length, OpcUa_Int64* data);
    virtual ~UaInt64Array();

    UaInt64Array& operator=(const UaInt64Array &other);
    const OpcUa_Int64& operator[](OpcUa_UInt32 index) const;
    OpcUa_Int64& operator[](OpcUa_UInt32 index);

    bool operator==(const UaInt64Array &other) const;
    bool operator!=(const UaInt64Array &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_Int64* data);
    void attach(OpcUa_Int32 length, OpcUa_Int64* data);
    OpcUa_Int64* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_Int64* rawData() const {return m_data;}
    inline OpcUa_Int64* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setInt64Array(const UaVariant &variant);
    OpcUa_StatusCode setInt64Array(const OpcUa_Variant &variant);
    OpcUa_StatusCode setInt64Array(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setInt64Array(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setInt64Array(OpcUa_Int32 length, OpcUa_Int64* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_Int64* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_LocalizedText.
 *
 *  This class encapsulates an array of the native OpcUa_LocalizedText structure
 *  and handles memory allocation and cleanup for you.
 *  @see @ref UaLocalizedText for information about the encapsulated structure.
 */
class UABASE_EXPORT UaLocalizedTextArray
{
public:
    UaLocalizedTextArray();
    UaLocalizedTextArray(const UaLocalizedTextArray &other);
    UaLocalizedTextArray(OpcUa_Int32 length, OpcUa_LocalizedText* data);
    virtual ~UaLocalizedTextArray();

    UaLocalizedTextArray& operator=(const UaLocalizedTextArray &other);
    const OpcUa_LocalizedText& operator[](OpcUa_UInt32 index) const;
    OpcUa_LocalizedText& operator[](OpcUa_UInt32 index);

    bool operator==(const UaLocalizedTextArray &other) const;
    bool operator!=(const UaLocalizedTextArray &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_LocalizedText* data);
    void attach(OpcUa_Int32 length, OpcUa_LocalizedText* data);
    OpcUa_LocalizedText* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_LocalizedText* rawData() const {return m_data;}
    inline OpcUa_LocalizedText* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setLocalizedTextArray(const UaVariant &variant);
    OpcUa_StatusCode setLocalizedTextArray(const OpcUa_Variant &variant);
    OpcUa_StatusCode setLocalizedTextArray(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setLocalizedTextArray(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setLocalizedTextArray(OpcUa_Int32 length, OpcUa_LocalizedText* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_LocalizedText* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_ModificationInfo.
 *
 *  This class encapsulates an array of the native OpcUa_ModificationInfo structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaModificationInfos
{
public:
    UaModificationInfos();
    UaModificationInfos(const UaModificationInfos &other);
    UaModificationInfos(OpcUa_Int32 length, OpcUa_ModificationInfo* data);
    virtual ~UaModificationInfos();

    UaModificationInfos& operator=(const UaModificationInfos &other);
    const OpcUa_ModificationInfo& operator[](OpcUa_UInt32 index) const;
    OpcUa_ModificationInfo& operator[](OpcUa_UInt32 index);

    bool operator==(const UaModificationInfos &other) const;
    bool operator!=(const UaModificationInfos &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_ModificationInfo* data);
    void attach(OpcUa_Int32 length, OpcUa_ModificationInfo* data);
    OpcUa_ModificationInfo* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_ModificationInfo* rawData() const {return m_data;}
    inline OpcUa_ModificationInfo* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setModificationInfos(const UaVariant &variant);
    OpcUa_StatusCode setModificationInfos(const OpcUa_Variant &variant);
    OpcUa_StatusCode setModificationInfos(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setModificationInfos(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setModificationInfos(OpcUa_Int32 length, OpcUa_ModificationInfo* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_ModificationInfo* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_MonitoredItemCreateRequest.
 *
 *  This class encapsulates an array of the native OpcUa_MonitoredItemCreateRequest structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaMonitoredItemCreateRequests
{
public:
    UaMonitoredItemCreateRequests();
    UaMonitoredItemCreateRequests(const UaMonitoredItemCreateRequests &other);
    UaMonitoredItemCreateRequests(OpcUa_Int32 length, OpcUa_MonitoredItemCreateRequest* data);
    virtual ~UaMonitoredItemCreateRequests();

    UaMonitoredItemCreateRequests& operator=(const UaMonitoredItemCreateRequests &other);
    const OpcUa_MonitoredItemCreateRequest& operator[](OpcUa_UInt32 index) const;
    OpcUa_MonitoredItemCreateRequest& operator[](OpcUa_UInt32 index);

    bool operator==(const UaMonitoredItemCreateRequests &other) const;
    bool operator!=(const UaMonitoredItemCreateRequests &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_MonitoredItemCreateRequest* data);
    void attach(OpcUa_Int32 length, OpcUa_MonitoredItemCreateRequest* data);
    OpcUa_MonitoredItemCreateRequest* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_MonitoredItemCreateRequest* rawData() const {return m_data;}
    inline OpcUa_MonitoredItemCreateRequest* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setMonitoredItemCreateRequests(const UaVariant &variant);
    OpcUa_StatusCode setMonitoredItemCreateRequests(const OpcUa_Variant &variant);
    OpcUa_StatusCode setMonitoredItemCreateRequests(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setMonitoredItemCreateRequests(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setMonitoredItemCreateRequests(OpcUa_Int32 length, OpcUa_MonitoredItemCreateRequest* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_MonitoredItemCreateRequest* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_MonitoredItemCreateResult.
 *
 *  This class encapsulates an array of the native OpcUa_MonitoredItemCreateResult structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaMonitoredItemCreateResults
{
public:
    UaMonitoredItemCreateResults();
    UaMonitoredItemCreateResults(const UaMonitoredItemCreateResults &other);
    UaMonitoredItemCreateResults(OpcUa_Int32 length, OpcUa_MonitoredItemCreateResult* data);
    virtual ~UaMonitoredItemCreateResults();

    UaMonitoredItemCreateResults& operator=(const UaMonitoredItemCreateResults &other);
    const OpcUa_MonitoredItemCreateResult& operator[](OpcUa_UInt32 index) const;
    OpcUa_MonitoredItemCreateResult& operator[](OpcUa_UInt32 index);

    bool operator==(const UaMonitoredItemCreateResults &other) const;
    bool operator!=(const UaMonitoredItemCreateResults &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_MonitoredItemCreateResult* data);
    void attach(OpcUa_Int32 length, OpcUa_MonitoredItemCreateResult* data);
    OpcUa_MonitoredItemCreateResult* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_MonitoredItemCreateResult* rawData() const {return m_data;}
    inline OpcUa_MonitoredItemCreateResult* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setMonitoredItemCreateResults(const UaVariant &variant);
    OpcUa_StatusCode setMonitoredItemCreateResults(const OpcUa_Variant &variant);
    OpcUa_StatusCode setMonitoredItemCreateResults(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setMonitoredItemCreateResults(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setMonitoredItemCreateResults(OpcUa_Int32 length, OpcUa_MonitoredItemCreateResult* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_MonitoredItemCreateResult* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_MonitoredItemModifyRequest.
 *
 *  This class encapsulates an array of the native OpcUa_MonitoredItemModifyRequest structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaMonitoredItemModifyRequests
{
public:
    UaMonitoredItemModifyRequests();
    UaMonitoredItemModifyRequests(const UaMonitoredItemModifyRequests &other);
    UaMonitoredItemModifyRequests(OpcUa_Int32 length, OpcUa_MonitoredItemModifyRequest* data);
    virtual ~UaMonitoredItemModifyRequests();

    UaMonitoredItemModifyRequests& operator=(const UaMonitoredItemModifyRequests &other);
    const OpcUa_MonitoredItemModifyRequest& operator[](OpcUa_UInt32 index) const;
    OpcUa_MonitoredItemModifyRequest& operator[](OpcUa_UInt32 index);

    bool operator==(const UaMonitoredItemModifyRequests &other) const;
    bool operator!=(const UaMonitoredItemModifyRequests &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_MonitoredItemModifyRequest* data);
    void attach(OpcUa_Int32 length, OpcUa_MonitoredItemModifyRequest* data);
    OpcUa_MonitoredItemModifyRequest* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_MonitoredItemModifyRequest* rawData() const {return m_data;}
    inline OpcUa_MonitoredItemModifyRequest* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setMonitoredItemModifyRequests(const UaVariant &variant);
    OpcUa_StatusCode setMonitoredItemModifyRequests(const OpcUa_Variant &variant);
    OpcUa_StatusCode setMonitoredItemModifyRequests(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setMonitoredItemModifyRequests(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setMonitoredItemModifyRequests(OpcUa_Int32 length, OpcUa_MonitoredItemModifyRequest* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_MonitoredItemModifyRequest* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_MonitoredItemModifyResult.
 *
 *  This class encapsulates an array of the native OpcUa_MonitoredItemModifyResult structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaMonitoredItemModifyResults
{
public:
    UaMonitoredItemModifyResults();
    UaMonitoredItemModifyResults(const UaMonitoredItemModifyResults &other);
    UaMonitoredItemModifyResults(OpcUa_Int32 length, OpcUa_MonitoredItemModifyResult* data);
    virtual ~UaMonitoredItemModifyResults();

    UaMonitoredItemModifyResults& operator=(const UaMonitoredItemModifyResults &other);
    const OpcUa_MonitoredItemModifyResult& operator[](OpcUa_UInt32 index) const;
    OpcUa_MonitoredItemModifyResult& operator[](OpcUa_UInt32 index);

    bool operator==(const UaMonitoredItemModifyResults &other) const;
    bool operator!=(const UaMonitoredItemModifyResults &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_MonitoredItemModifyResult* data);
    void attach(OpcUa_Int32 length, OpcUa_MonitoredItemModifyResult* data);
    OpcUa_MonitoredItemModifyResult* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_MonitoredItemModifyResult* rawData() const {return m_data;}
    inline OpcUa_MonitoredItemModifyResult* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setMonitoredItemModifyResults(const UaVariant &variant);
    OpcUa_StatusCode setMonitoredItemModifyResults(const OpcUa_Variant &variant);
    OpcUa_StatusCode setMonitoredItemModifyResults(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setMonitoredItemModifyResults(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setMonitoredItemModifyResults(OpcUa_Int32 length, OpcUa_MonitoredItemModifyResult* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_MonitoredItemModifyResult* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_MonitoredItemNotification.
 *
 *  This class encapsulates an array of the native OpcUa_MonitoredItemNotification structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaMonitoredItemNotifications
{
public:
    UaMonitoredItemNotifications();
    UaMonitoredItemNotifications(const UaMonitoredItemNotifications &other);
    UaMonitoredItemNotifications(OpcUa_Int32 length, OpcUa_MonitoredItemNotification* data);
    virtual ~UaMonitoredItemNotifications();

    UaMonitoredItemNotifications& operator=(const UaMonitoredItemNotifications &other);
    const OpcUa_MonitoredItemNotification& operator[](OpcUa_UInt32 index) const;
    OpcUa_MonitoredItemNotification& operator[](OpcUa_UInt32 index);

    bool operator==(const UaMonitoredItemNotifications &other) const;
    bool operator!=(const UaMonitoredItemNotifications &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_MonitoredItemNotification* data);
    void attach(OpcUa_Int32 length, OpcUa_MonitoredItemNotification* data);
    OpcUa_MonitoredItemNotification* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_MonitoredItemNotification* rawData() const {return m_data;}
    inline OpcUa_MonitoredItemNotification* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setMonitoredItemNotifications(const UaVariant &variant);
    OpcUa_StatusCode setMonitoredItemNotifications(const OpcUa_Variant &variant);
    OpcUa_StatusCode setMonitoredItemNotifications(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setMonitoredItemNotifications(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setMonitoredItemNotifications(OpcUa_Int32 length, OpcUa_MonitoredItemNotification* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_MonitoredItemNotification* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_NodeId.
 *
 *  This class encapsulates an array of the native OpcUa_NodeId structure
 *  and handles memory allocation and cleanup for you.
 *  @see @ref UaNodeId for information about the encapsulated structure.
 */
class UABASE_EXPORT UaNodeIdArray
{
public:
    UaNodeIdArray();
    UaNodeIdArray(const UaNodeIdArray &other);
    UaNodeIdArray(OpcUa_Int32 length, OpcUa_NodeId* data);
    virtual ~UaNodeIdArray();

    UaNodeIdArray& operator=(const UaNodeIdArray &other);
    const OpcUa_NodeId& operator[](OpcUa_UInt32 index) const;
    OpcUa_NodeId& operator[](OpcUa_UInt32 index);

    bool operator==(const UaNodeIdArray &other) const;
    bool operator!=(const UaNodeIdArray &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_NodeId* data);
    void attach(OpcUa_Int32 length, OpcUa_NodeId* data);
    OpcUa_NodeId* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_NodeId* rawData() const {return m_data;}
    inline OpcUa_NodeId* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setNodeIdArray(const UaVariant &variant);
    OpcUa_StatusCode setNodeIdArray(const OpcUa_Variant &variant);
    OpcUa_StatusCode setNodeIdArray(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setNodeIdArray(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setNodeIdArray(OpcUa_Int32 length, OpcUa_NodeId* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_NodeId* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_NodeTypeDescription.
 *
 *  This class encapsulates an array of the native OpcUa_NodeTypeDescription structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaNodeTypeDescriptions
{
public:
    UaNodeTypeDescriptions();
    UaNodeTypeDescriptions(const UaNodeTypeDescriptions &other);
    UaNodeTypeDescriptions(OpcUa_Int32 length, OpcUa_NodeTypeDescription* data);
    virtual ~UaNodeTypeDescriptions();

    UaNodeTypeDescriptions& operator=(const UaNodeTypeDescriptions &other);
    const OpcUa_NodeTypeDescription& operator[](OpcUa_UInt32 index) const;
    OpcUa_NodeTypeDescription& operator[](OpcUa_UInt32 index);

    bool operator==(const UaNodeTypeDescriptions &other) const;
    bool operator!=(const UaNodeTypeDescriptions &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_NodeTypeDescription* data);
    void attach(OpcUa_Int32 length, OpcUa_NodeTypeDescription* data);
    OpcUa_NodeTypeDescription* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_NodeTypeDescription* rawData() const {return m_data;}
    inline OpcUa_NodeTypeDescription* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setNodeTypeDescriptions(const UaVariant &variant);
    OpcUa_StatusCode setNodeTypeDescriptions(const OpcUa_Variant &variant);
    OpcUa_StatusCode setNodeTypeDescriptions(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setNodeTypeDescriptions(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setNodeTypeDescriptions(OpcUa_Int32 length, OpcUa_NodeTypeDescription* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_NodeTypeDescription* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_ParsingResult.
 *
 *  This class encapsulates an array of the native OpcUa_ParsingResult structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaParsingResults
{
public:
    UaParsingResults();
    UaParsingResults(const UaParsingResults &other);
    UaParsingResults(OpcUa_Int32 length, OpcUa_ParsingResult* data);
    virtual ~UaParsingResults();

    UaParsingResults& operator=(const UaParsingResults &other);
    const OpcUa_ParsingResult& operator[](OpcUa_UInt32 index) const;
    OpcUa_ParsingResult& operator[](OpcUa_UInt32 index);

    bool operator==(const UaParsingResults &other) const;
    bool operator!=(const UaParsingResults &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_ParsingResult* data);
    void attach(OpcUa_Int32 length, OpcUa_ParsingResult* data);
    OpcUa_ParsingResult* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_ParsingResult* rawData() const {return m_data;}
    inline OpcUa_ParsingResult* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setParsingResults(const UaVariant &variant);
    OpcUa_StatusCode setParsingResults(const OpcUa_Variant &variant);
    OpcUa_StatusCode setParsingResults(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setParsingResults(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setParsingResults(OpcUa_Int32 length, OpcUa_ParsingResult* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_ParsingResult* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_QualifiedName.
 *
 *  This class encapsulates an array of the native OpcUa_QualifiedName structure
 *  and handles memory allocation and cleanup for you.
 *  @see @ref UaQualifiedName for information about the encapsulated structure.
 */
class UABASE_EXPORT UaQualifiedNameArray
{
public:
    UaQualifiedNameArray();
    UaQualifiedNameArray(const UaQualifiedNameArray &other);
    UaQualifiedNameArray(OpcUa_Int32 length, OpcUa_QualifiedName* data);
    virtual ~UaQualifiedNameArray();

    UaQualifiedNameArray& operator=(const UaQualifiedNameArray &other);
    const OpcUa_QualifiedName& operator[](OpcUa_UInt32 index) const;
    OpcUa_QualifiedName& operator[](OpcUa_UInt32 index);

    bool operator==(const UaQualifiedNameArray &other) const;
    bool operator!=(const UaQualifiedNameArray &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_QualifiedName* data);
    void attach(OpcUa_Int32 length, OpcUa_QualifiedName* data);
    OpcUa_QualifiedName* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_QualifiedName* rawData() const {return m_data;}
    inline OpcUa_QualifiedName* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setQualifiedNameArray(const UaVariant &variant);
    OpcUa_StatusCode setQualifiedNameArray(const OpcUa_Variant &variant);
    OpcUa_StatusCode setQualifiedNameArray(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setQualifiedNameArray(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setQualifiedNameArray(OpcUa_Int32 length, OpcUa_QualifiedName* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_QualifiedName* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_QueryDataSet.
 *
 *  This class encapsulates an array of the native OpcUa_QueryDataSet structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaQueryDataSets
{
public:
    UaQueryDataSets();
    UaQueryDataSets(const UaQueryDataSets &other);
    UaQueryDataSets(OpcUa_Int32 length, OpcUa_QueryDataSet* data);
    virtual ~UaQueryDataSets();

    UaQueryDataSets& operator=(const UaQueryDataSets &other);
    const OpcUa_QueryDataSet& operator[](OpcUa_UInt32 index) const;
    OpcUa_QueryDataSet& operator[](OpcUa_UInt32 index);

    bool operator==(const UaQueryDataSets &other) const;
    bool operator!=(const UaQueryDataSets &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_QueryDataSet* data);
    void attach(OpcUa_Int32 length, OpcUa_QueryDataSet* data);
    OpcUa_QueryDataSet* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_QueryDataSet* rawData() const {return m_data;}
    inline OpcUa_QueryDataSet* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setQueryDataSets(const UaVariant &variant);
    OpcUa_StatusCode setQueryDataSets(const OpcUa_Variant &variant);
    OpcUa_StatusCode setQueryDataSets(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setQueryDataSets(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setQueryDataSets(OpcUa_Int32 length, OpcUa_QueryDataSet* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_QueryDataSet* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_ReadValueId.
 *
 *  This class encapsulates an array of the native OpcUa_ReadValueId structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaReadValueIds
{
public:
    UaReadValueIds();
    UaReadValueIds(const UaReadValueIds &other);
    UaReadValueIds(OpcUa_Int32 length, OpcUa_ReadValueId* data);
    virtual ~UaReadValueIds();

    UaReadValueIds& operator=(const UaReadValueIds &other);
    const OpcUa_ReadValueId& operator[](OpcUa_UInt32 index) const;
    OpcUa_ReadValueId& operator[](OpcUa_UInt32 index);

    bool operator==(const UaReadValueIds &other) const;
    bool operator!=(const UaReadValueIds &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_ReadValueId* data);
    void attach(OpcUa_Int32 length, OpcUa_ReadValueId* data);
    OpcUa_ReadValueId* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_ReadValueId* rawData() const {return m_data;}
    inline OpcUa_ReadValueId* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setReadValueIds(const UaVariant &variant);
    OpcUa_StatusCode setReadValueIds(const OpcUa_Variant &variant);
    OpcUa_StatusCode setReadValueIds(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setReadValueIds(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setReadValueIds(OpcUa_Int32 length, OpcUa_ReadValueId* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_ReadValueId* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_ReferenceDescription.
 *
 *  This class encapsulates an array of the native OpcUa_ReferenceDescription structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaReferenceDescriptions
{
public:
    UaReferenceDescriptions();
    UaReferenceDescriptions(const UaReferenceDescriptions &other);
    UaReferenceDescriptions(OpcUa_Int32 length, OpcUa_ReferenceDescription* data);
    virtual ~UaReferenceDescriptions();

    UaReferenceDescriptions& operator=(const UaReferenceDescriptions &other);
    const OpcUa_ReferenceDescription& operator[](OpcUa_UInt32 index) const;
    OpcUa_ReferenceDescription& operator[](OpcUa_UInt32 index);

    bool operator==(const UaReferenceDescriptions &other) const;
    bool operator!=(const UaReferenceDescriptions &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_ReferenceDescription* data);
    void attach(OpcUa_Int32 length, OpcUa_ReferenceDescription* data);
    OpcUa_ReferenceDescription* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_ReferenceDescription* rawData() const {return m_data;}
    inline OpcUa_ReferenceDescription* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setReferenceDescriptions(const UaVariant &variant);
    OpcUa_StatusCode setReferenceDescriptions(const OpcUa_Variant &variant);
    OpcUa_StatusCode setReferenceDescriptions(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setReferenceDescriptions(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setReferenceDescriptions(OpcUa_Int32 length, OpcUa_ReferenceDescription* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_ReferenceDescription* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_RelativePathElement.
 *
 *  This class encapsulates an array of the native OpcUa_RelativePathElement structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaRelativePathElements
{
public:
    UaRelativePathElements();
    UaRelativePathElements(const UaRelativePathElements &other);
    UaRelativePathElements(OpcUa_Int32 length, OpcUa_RelativePathElement* data);
    virtual ~UaRelativePathElements();

    UaRelativePathElements& operator=(const UaRelativePathElements &other);
    const OpcUa_RelativePathElement& operator[](OpcUa_UInt32 index) const;
    OpcUa_RelativePathElement& operator[](OpcUa_UInt32 index);

    bool operator==(const UaRelativePathElements &other) const;
    bool operator!=(const UaRelativePathElements &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_RelativePathElement* data);
    void attach(OpcUa_Int32 length, OpcUa_RelativePathElement* data);
    OpcUa_RelativePathElement* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_RelativePathElement* rawData() const {return m_data;}
    inline OpcUa_RelativePathElement* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setRelativePathElements(const UaVariant &variant);
    OpcUa_StatusCode setRelativePathElements(const OpcUa_Variant &variant);
    OpcUa_StatusCode setRelativePathElements(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setRelativePathElements(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setRelativePathElements(OpcUa_Int32 length, OpcUa_RelativePathElement* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_RelativePathElement* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_SByte.
 *
 *  This class encapsulates an array of the native OpcUa_SByte structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaSByteArray
{
public:
    UaSByteArray();
    UaSByteArray(const UaSByteArray &other);
    UaSByteArray(OpcUa_Int32 length, OpcUa_SByte* data);
    virtual ~UaSByteArray();

    UaSByteArray& operator=(const UaSByteArray &other);
    const OpcUa_SByte& operator[](OpcUa_UInt32 index) const;
    OpcUa_SByte& operator[](OpcUa_UInt32 index);

    bool operator==(const UaSByteArray &other) const;
    bool operator!=(const UaSByteArray &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_SByte* data);
    void attach(OpcUa_Int32 length, OpcUa_SByte* data);
    OpcUa_SByte* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_SByte* rawData() const {return m_data;}
    inline OpcUa_SByte* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setSByteArray(const UaVariant &variant);
    OpcUa_StatusCode setSByteArray(const OpcUa_Variant &variant);
    OpcUa_StatusCode setSByteArray(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSByteArray(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSByteArray(OpcUa_Int32 length, OpcUa_SByte* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_SByte* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_SimpleAttributeOperand.
 *
 *  This class encapsulates an array of the native OpcUa_SimpleAttributeOperand structure
 *  and handles memory allocation and cleanup for you.
 *  @see @ref UaSimpleAttributeOperand for information about the encapsulated structure.
 */
class UABASE_EXPORT UaSimpleAttributeOperands
{
public:
    UaSimpleAttributeOperands();
    UaSimpleAttributeOperands(const UaSimpleAttributeOperands &other);
    UaSimpleAttributeOperands(OpcUa_Int32 length, OpcUa_SimpleAttributeOperand* data);
    virtual ~UaSimpleAttributeOperands();

    UaSimpleAttributeOperands& operator=(const UaSimpleAttributeOperands &other);
    const OpcUa_SimpleAttributeOperand& operator[](OpcUa_UInt32 index) const;
    OpcUa_SimpleAttributeOperand& operator[](OpcUa_UInt32 index);

    bool operator==(const UaSimpleAttributeOperands &other) const;
    bool operator!=(const UaSimpleAttributeOperands &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_SimpleAttributeOperand* data);
    void attach(OpcUa_Int32 length, OpcUa_SimpleAttributeOperand* data);
    OpcUa_SimpleAttributeOperand* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_SimpleAttributeOperand* rawData() const {return m_data;}
    inline OpcUa_SimpleAttributeOperand* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setSimpleAttributeOperands(const UaVariant &variant);
    OpcUa_StatusCode setSimpleAttributeOperands(const OpcUa_Variant &variant);
    OpcUa_StatusCode setSimpleAttributeOperands(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSimpleAttributeOperands(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSimpleAttributeOperands(OpcUa_Int32 length, OpcUa_SimpleAttributeOperand* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_SimpleAttributeOperand* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_StatusCode.
 *
 *  This class encapsulates an array of the native OpcUa_StatusCode structure
 *  and handles memory allocation and cleanup for you.
 *  @see @ref UaStatusCode for information about the encapsulated structure.
 */
class UABASE_EXPORT UaStatusCodeArray
{
public:
    UaStatusCodeArray();
    UaStatusCodeArray(const UaStatusCodeArray &other);
    UaStatusCodeArray(OpcUa_Int32 length, OpcUa_StatusCode* data);
    virtual ~UaStatusCodeArray();

    UaStatusCodeArray& operator=(const UaStatusCodeArray &other);
    const OpcUa_StatusCode& operator[](OpcUa_UInt32 index) const;
    OpcUa_StatusCode& operator[](OpcUa_UInt32 index);

    bool operator==(const UaStatusCodeArray &other) const;
    bool operator!=(const UaStatusCodeArray &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_StatusCode* data);
    void attach(OpcUa_Int32 length, OpcUa_StatusCode* data);
    OpcUa_StatusCode* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_StatusCode* rawData() const {return m_data;}
    inline OpcUa_StatusCode* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setStatusCodeArray(const UaVariant &variant);
    OpcUa_StatusCode setStatusCodeArray(const OpcUa_Variant &variant);
    OpcUa_StatusCode setStatusCodeArray(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setStatusCodeArray(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setStatusCodeArray(OpcUa_Int32 length, OpcUa_StatusCode* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_StatusCode* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_String.
 *
 *  This class encapsulates an array of the native OpcUa_String structure
 *  and handles memory allocation and cleanup for you.
 *  @see @ref UaString for information about the encapsulated structure.
 */
class UABASE_EXPORT UaStringArray
{
public:
    UaStringArray();
    UaStringArray(const UaStringArray &other);
    UaStringArray(OpcUa_Int32 length, OpcUa_String* data);
    virtual ~UaStringArray();

    UaStringArray& operator=(const UaStringArray &other);
    const OpcUa_String& operator[](OpcUa_UInt32 index) const;
    OpcUa_String& operator[](OpcUa_UInt32 index);

    bool operator==(const UaStringArray &other) const;
    bool operator!=(const UaStringArray &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_String* data);
    void attach(OpcUa_Int32 length, OpcUa_String* data);
    OpcUa_String* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_String* rawData() const {return m_data;}
    inline OpcUa_String* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setStringArray(const UaVariant &variant);
    OpcUa_StatusCode setStringArray(const OpcUa_Variant &variant);
    OpcUa_StatusCode setStringArray(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setStringArray(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setStringArray(OpcUa_Int32 length, OpcUa_String* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_String* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_UInt16.
 *
 *  This class encapsulates an array of the native OpcUa_UInt16 structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaUInt16Array
{
public:
    UaUInt16Array();
    UaUInt16Array(const UaUInt16Array &other);
    UaUInt16Array(OpcUa_Int32 length, OpcUa_UInt16* data);
    virtual ~UaUInt16Array();

    UaUInt16Array& operator=(const UaUInt16Array &other);
    const OpcUa_UInt16& operator[](OpcUa_UInt32 index) const;
    OpcUa_UInt16& operator[](OpcUa_UInt32 index);

    bool operator==(const UaUInt16Array &other) const;
    bool operator!=(const UaUInt16Array &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_UInt16* data);
    void attach(OpcUa_Int32 length, OpcUa_UInt16* data);
    OpcUa_UInt16* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_UInt16* rawData() const {return m_data;}
    inline OpcUa_UInt16* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setUInt16Array(const UaVariant &variant);
    OpcUa_StatusCode setUInt16Array(const OpcUa_Variant &variant);
    OpcUa_StatusCode setUInt16Array(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setUInt16Array(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setUInt16Array(OpcUa_Int32 length, OpcUa_UInt16* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_UInt16* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_UInt32.
 *
 *  This class encapsulates an array of the native OpcUa_UInt32 structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaUInt32Array
{
public:
    UaUInt32Array();
    UaUInt32Array(const UaUInt32Array &other);
    UaUInt32Array(OpcUa_Int32 length, OpcUa_UInt32* data);
    virtual ~UaUInt32Array();

    UaUInt32Array& operator=(const UaUInt32Array &other);
    const OpcUa_UInt32& operator[](OpcUa_UInt32 index) const;
    OpcUa_UInt32& operator[](OpcUa_UInt32 index);

    bool operator==(const UaUInt32Array &other) const;
    bool operator!=(const UaUInt32Array &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_UInt32* data);
    void attach(OpcUa_Int32 length, OpcUa_UInt32* data);
    OpcUa_UInt32* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_UInt32* rawData() const {return m_data;}
    inline OpcUa_UInt32* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setUInt32Array(const UaVariant &variant);
    OpcUa_StatusCode setUInt32Array(const OpcUa_Variant &variant);
    OpcUa_StatusCode setUInt32Array(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setUInt32Array(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setUInt32Array(OpcUa_Int32 length, OpcUa_UInt32* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_UInt32* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_UInt64.
 *
 *  This class encapsulates an array of the native OpcUa_UInt64 structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaUInt64Array
{
public:
    UaUInt64Array();
    UaUInt64Array(const UaUInt64Array &other);
    UaUInt64Array(OpcUa_Int32 length, OpcUa_UInt64* data);
    virtual ~UaUInt64Array();

    UaUInt64Array& operator=(const UaUInt64Array &other);
    const OpcUa_UInt64& operator[](OpcUa_UInt32 index) const;
    OpcUa_UInt64& operator[](OpcUa_UInt32 index);

    bool operator==(const UaUInt64Array &other) const;
    bool operator!=(const UaUInt64Array &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_UInt64* data);
    void attach(OpcUa_Int32 length, OpcUa_UInt64* data);
    OpcUa_UInt64* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_UInt64* rawData() const {return m_data;}
    inline OpcUa_UInt64* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setUInt64Array(const UaVariant &variant);
    OpcUa_StatusCode setUInt64Array(const OpcUa_Variant &variant);
    OpcUa_StatusCode setUInt64Array(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setUInt64Array(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setUInt64Array(OpcUa_Int32 length, OpcUa_UInt64* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_UInt64* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_Variant.
 *
 *  This class encapsulates an array of the native OpcUa_Variant structure
 *  and handles memory allocation and cleanup for you.
 *  @see @ref UaVariant for information about the encapsulated structure.
 */
class UABASE_EXPORT UaVariantArray
{
public:
    UaVariantArray();
    UaVariantArray(const UaVariantArray &other);
    UaVariantArray(OpcUa_Int32 length, OpcUa_Variant* data);
    virtual ~UaVariantArray();

    UaVariantArray& operator=(const UaVariantArray &other);
    const OpcUa_Variant& operator[](OpcUa_UInt32 index) const;
    OpcUa_Variant& operator[](OpcUa_UInt32 index);

    bool operator==(const UaVariantArray &other) const;
    bool operator!=(const UaVariantArray &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_Variant* data);
    void attach(OpcUa_Int32 length, OpcUa_Variant* data);
    OpcUa_Variant* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_Variant* rawData() const {return m_data;}
    inline OpcUa_Variant* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setVariantArray(const UaVariant &variant);
    OpcUa_StatusCode setVariantArray(const OpcUa_Variant &variant);
    OpcUa_StatusCode setVariantArray(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setVariantArray(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setVariantArray(OpcUa_Int32 length, OpcUa_Variant* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_Variant* m_data;
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_WriteValue.
 *
 *  This class encapsulates an array of the native OpcUa_WriteValue structure
 *  and handles memory allocation and cleanup for you.
 */
class UABASE_EXPORT UaWriteValues
{
public:
    UaWriteValues();
    UaWriteValues(const UaWriteValues &other);
    UaWriteValues(OpcUa_Int32 length, OpcUa_WriteValue* data);
    virtual ~UaWriteValues();

    UaWriteValues& operator=(const UaWriteValues &other);
    const OpcUa_WriteValue& operator[](OpcUa_UInt32 index) const;
    OpcUa_WriteValue& operator[](OpcUa_UInt32 index);

    bool operator==(const UaWriteValues &other) const;
    bool operator!=(const UaWriteValues &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_WriteValue* data);
    void attach(OpcUa_Int32 length, OpcUa_WriteValue* data);
    OpcUa_WriteValue* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_WriteValue* rawData() const {return m_data;}
    inline OpcUa_WriteValue* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setWriteValues(const UaVariant &variant);
    OpcUa_StatusCode setWriteValues(const OpcUa_Variant &variant);
    OpcUa_StatusCode setWriteValues(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setWriteValues(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setWriteValues(OpcUa_Int32 length, OpcUa_WriteValue* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_WriteValue* m_data;
};

#define UaBoolArray UaBooleanArray
#define UaModificationInfo UaModificationInfos
#define UaDataNotifications UaMonitoredItemNotifications
#define UaXmlElementArray UaByteStringArray

/** UaObjectPointerArray
 *  @brief Template wrapper class for an array of pointers to C++ class instances.
 *  This class is a template for wrapper classes used to manage arrays of pointers to C++ class instances.
 *  It provides methods to create, to resize and to delete such arrays. In the case of the array deletion
 *  in the clear method or in the destructor, delete gets called for each valid object in the array.
 *  It is not possible to create shallow copies of this Class.
 */
template<class T>
class UaObjectPointerArray
{
    UA_DISABLE_COPY(UaObjectPointerArray);
public:
    UaObjectPointerArray()
        : m_noOfElements(0),
          m_data(NULL)
    {
    };
    ~UaObjectPointerArray()
    {
        clear();
    };
    inline T*& operator[](OpcUa_UInt32 index) const
    {
        assert(index<m_noOfElements);
        return m_data[index];
    }
    void create(OpcUa_UInt32 length)
    {
        clear();
        m_data = new T*[length];
        OpcUa_MemSet(m_data, 0, length * sizeof(T*));
        m_noOfElements = length;
    }
    void attach(OpcUa_UInt32 length, T** data)
    {
        clear();
        m_data = data;
        m_noOfElements = length;
    }
    void attach(OpcUa_Int32 length, T** data)
    {
        clear();
        if (length >= 0)
        {
            m_data = data;
            m_noOfElements = length;
        }
    }
    /* Adds an object to an empty slot and returns the index*/
    OpcUa_UInt32 addObject(T* data)
    {
        // Check if we have already a data array
        if ( m_data == NULL )
        {
            create(1);
        }
        // Find an empty slot
        for ( OpcUa_UInt32 i=0; i<m_noOfElements; i++ )
        {
            if ( NULL == m_data[i] )
            {
                m_data[i] = data;
                return i;
            }
        }
        // No slot found, resize the array
        OpcUa_UInt32 index = length();
        resize( index + index/10 + 1 );
        m_data[index] = data;
        return index;
    }
    void resize(OpcUa_UInt32 length)
    {
        if ( length < m_noOfElements )
        {
            for ( OpcUa_UInt32 i=length; i<m_noOfElements; i++ )
            {
                if ( NULL != m_data[i] )
                {
                    delete m_data[i];
                }
            }
            m_noOfElements = length;
        }
        else if ( length > m_noOfElements )
        {
            T** newData = new T*[length];
            OpcUa_MemSet(newData, 0, length * sizeof(T*));
            if (m_data)
            {
                for ( OpcUa_UInt32 i=0; i<m_noOfElements; i++ )
                {
                    newData[i] = m_data[i];
                }
                delete[] m_data;
            }
            m_data = newData;
            m_noOfElements = length;
        }
    }
    T** detach()
    {
        T** ret = m_data;
        m_noOfElements = 0;
        m_data         = NULL;
        return ret;
    }
    void clear()
    {
        if (m_data)
        {
            for ( OpcUa_UInt32 i=0; i<m_noOfElements; i++ )
            {
                if ( NULL != m_data[i] )
                {
                    delete m_data[i];
                }
            }
            delete [] m_data ;
            m_data = NULL;
            m_noOfElements = 0;
        }
    }
    const T** rawData() const
    {
        return m_data;
    }
    T** rawData()
    {
        return m_data;
    }
    /* Get the length of the data array */
    OpcUa_UInt32 length() const
    {
        return m_noOfElements;
    }
private:
    OpcUa_UInt32 m_noOfElements;
    T**          m_data;
};

/** UaObjectArray
 *  @brief Template wrapper class for an array of C++ class instances.
 *  This class is a template for wrapper classes used to manage arrays of C++ class instances.
 *  It provides methods to create and to delete such arrays.
 *  It is not possible to create shallow copies of this Class.
 */
template<class T>
class UaObjectArray
{
    UA_DISABLE_COPY(UaObjectArray);
public:
    UaObjectArray()
        : m_noOfElements(0),
          m_data(NULL)
    {
    };
    virtual ~UaObjectArray()
    {
        clear();
    };
    inline T& operator[](OpcUa_UInt32 index) const
    {
        assert(index<m_noOfElements);
        return m_data[index];
    }
    void create(OpcUa_UInt32 length)
    {
        clear();
        m_data = new T[length];
        m_noOfElements = length;
    }
    void clear()
    {
        if (m_data)
        {
            delete [] m_data ;
            m_data = NULL;
            m_noOfElements = 0;
        }
    }
    const T* rawData() const
    {
        return m_data;
    }
    T* rawData()
    {
        return m_data;
    }
    /* Get the length of the data array */
    OpcUa_UInt32 length() const
    {
        return m_noOfElements;
    }
private:
    OpcUa_UInt32 m_noOfElements;
    T*           m_data;
};

/** UaPointerArray
 *  @brief Template wrapper class for an array of pointers.
 *  This class is a template for wrapper classes used to manage arrays of pointers.
 *  It provides methods to create, to resize and to delete such array
 *  It is not possible to create shallow copies of this Class.
 */
template<class T>
class UaPointerArray
{
public:
    UaPointerArray()
    : m_noOfElements(0),
      m_data(NULL)
    {}
    UaPointerArray(const UaPointerArray<T> &other)
    : m_noOfElements(0),
      m_data(NULL)
    {
        *this=other;
    }
    virtual ~UaPointerArray()
    {
        clear();
    }
    UaPointerArray<T>& operator=(const UaPointerArray<T> &other)
    {
        if (this == &other) {return *this;}

        clear();
        if (other.m_noOfElements > 0)
        {
            m_noOfElements = other.m_noOfElements;
            m_data = new T*[m_noOfElements];
            for ( OpcUa_UInt32 i=0; i<m_noOfElements; i++ )
            {
                m_data[i] = other.m_data[i];
            }
        }
        return *this;
    }
    inline T*& operator[](OpcUa_UInt32 index) const
    {
        assert(index<m_noOfElements);
        return m_data[index];
    }
    void create(OpcUa_UInt32 length)
    {
        clear();
        m_data = new T*[length];
        OpcUa_MemSet(m_data, 0, length * sizeof(T*));
        m_noOfElements = length;
    }
    void resize(OpcUa_UInt32 length)
    {
        if ( length < m_noOfElements )
        {
            m_noOfElements = length;
        }
        else if ( length > m_noOfElements )
        {
            T** newData = new T*[length];
            OpcUa_MemSet(newData, 0, length * sizeof(T*));
            if (m_data)
            {
                for ( OpcUa_UInt32 i=0; i<m_noOfElements; i++ )
                {
                    newData[i] = m_data[i];
                }
                delete[] m_data;
            }
            m_data = newData;
            m_noOfElements = length;
        }
    }
    void clear()
    {
        if (m_data)
        {
            delete [] m_data ;
            m_data = NULL;
            m_noOfElements = 0;
        }
    }
    /* Get the length of the data array */
    OpcUa_UInt32 length() const
    {
        return m_noOfElements;
    }
private:
    OpcUa_UInt32 m_noOfElements;
    T**          m_data;
};

typedef UaPointerArray<OpcUa_DataValue> PDataValueArray;

#endif // UAARRAYTEMPLATES_H

