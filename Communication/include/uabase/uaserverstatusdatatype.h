/******************************************************************************
** uaserverstatusdatatype.h
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
** Portable UaServerStatusDataType class.
**
******************************************************************************/
#ifndef UASERVERSTATUSDATATYPE_H
#define UASERVERSTATUSDATATYPE_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uabuildinfo.h"
#include "uadatetime.h"
#include "ualocalizedtext.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaServerStatusDataTypePrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_ServerStatusDataType.
 *
 *  This class encapsulates the native OpcUa_ServerStatusDataType structure
 *  and handles memory allocation and cleanup for you.
 *  UaServerStatusDataType uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared ServerStatusDataType it creates a copy for that (copy-on-write).
 *  So assigning another UaServerStatusDataType or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  Contains elements that describe the status of the Server.
 */
class UABASE_EXPORT UaServerStatusDataType
{
    UA_DECLARE_PRIVATE(UaServerStatusDataType)
public:
    UaServerStatusDataType();
    UaServerStatusDataType(const UaServerStatusDataType &other);
    UaServerStatusDataType(const OpcUa_ServerStatusDataType &other);
    UaServerStatusDataType(
        const UaDateTime& startTime,
        const UaDateTime& currentTime,
        OpcUa_ServerState state,
        const UaBuildInfo& buildInfo,
        OpcUa_UInt32 secondsTillShutdown,
        const UaLocalizedText& shutdownReason
        );
    UaServerStatusDataType(const UaExtensionObject &extensionObject);
    UaServerStatusDataType(const OpcUa_ExtensionObject &extensionObject);
    UaServerStatusDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaServerStatusDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaServerStatusDataType();

    void clear();

    bool operator==(const UaServerStatusDataType &other) const;
    bool operator!=(const UaServerStatusDataType &other) const;

    UaServerStatusDataType& operator=(const UaServerStatusDataType &other);

    OpcUa_ServerStatusDataType* copy() const;
    void copyTo(OpcUa_ServerStatusDataType *pDst) const;

    static OpcUa_ServerStatusDataType* clone(const OpcUa_ServerStatusDataType& source);
    static void cloneTo(const OpcUa_ServerStatusDataType& source, OpcUa_ServerStatusDataType& copy);

    void attach(OpcUa_ServerStatusDataType *pValue);
    OpcUa_ServerStatusDataType* detach(OpcUa_ServerStatusDataType* pDst);

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

    OpcUa_StatusCode setServerStatusDataType(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setServerStatusDataType(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setServerStatusDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setServerStatusDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setServerStatusDataType(
        const UaDateTime& startTime,
        const UaDateTime& currentTime,
        OpcUa_ServerState state,
        const UaBuildInfo& buildInfo,
        OpcUa_UInt32 secondsTillShutdown,
        const UaLocalizedText& shutdownReason
        );

    UaDateTime getStartTime() const;
    UaDateTime getCurrentTime() const;
    OpcUa_ServerState getState() const;
    UaBuildInfo getBuildInfo() const;
    OpcUa_UInt32 getSecondsTillShutdown() const;
    UaLocalizedText getShutdownReason() const;

    void setStartTime(const UaDateTime& startTime);
    void setCurrentTime(const UaDateTime& currentTime);
    void setState(OpcUa_ServerState state);
    void setBuildInfo(const UaBuildInfo& buildInfo);
    void setSecondsTillShutdown(OpcUa_UInt32 secondsTillShutdown);
    void setShutdownReason(const UaLocalizedText& shutdownReason);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_ServerStatusDataType.
 *
 *  This class encapsulates an array of the native OpcUa_ServerStatusDataType structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaServerStatusDataType for information about the encapsulated structure.
 */
class UABASE_EXPORT UaServerStatusDataTypes
{
public:
    UaServerStatusDataTypes();
    UaServerStatusDataTypes(const UaServerStatusDataTypes &other);
    UaServerStatusDataTypes(OpcUa_Int32 length, OpcUa_ServerStatusDataType* data);
    virtual ~UaServerStatusDataTypes();

    UaServerStatusDataTypes& operator=(const UaServerStatusDataTypes &other);
    const OpcUa_ServerStatusDataType& operator[](OpcUa_UInt32 index) const;
    OpcUa_ServerStatusDataType& operator[](OpcUa_UInt32 index);

    bool operator==(const UaServerStatusDataTypes &other) const;
    bool operator!=(const UaServerStatusDataTypes &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_ServerStatusDataType* data);
    void attach(OpcUa_Int32 length, OpcUa_ServerStatusDataType* data);
    OpcUa_ServerStatusDataType* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_ServerStatusDataType* rawData() const {return m_data;}
    inline OpcUa_ServerStatusDataType* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setServerStatusDataTypes(const UaVariant &variant);
    OpcUa_StatusCode setServerStatusDataTypes(const OpcUa_Variant &variant);
    OpcUa_StatusCode setServerStatusDataTypes(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setServerStatusDataTypes(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setServerStatusDataTypes(OpcUa_Int32 length, OpcUa_ServerStatusDataType* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_ServerStatusDataType* m_data;
};

#endif // UASERVERSTATUSDATATYPE_H

