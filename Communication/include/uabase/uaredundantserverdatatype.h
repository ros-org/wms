/******************************************************************************
** uaredundantserverdatatype.h
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
** Portable UaRedundantServerDataType class.
**
******************************************************************************/
#ifndef UAREDUNDANTSERVERDATATYPE_H
#define UAREDUNDANTSERVERDATATYPE_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uastring.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaRedundantServerDataTypePrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_RedundantServerDataType.
 *
 *  This class encapsulates the native OpcUa_RedundantServerDataType structure
 *  and handles memory allocation and cleanup for you.
 *  UaRedundantServerDataType uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared RedundantServerDataType it creates a copy for that (copy-on-write).
 *  So assigning another UaRedundantServerDataType or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  Contains elements that describe the status of the Server.
 */
class UABASE_EXPORT UaRedundantServerDataType
{
    UA_DECLARE_PRIVATE(UaRedundantServerDataType)
public:
    UaRedundantServerDataType();
    UaRedundantServerDataType(const UaRedundantServerDataType &other);
    UaRedundantServerDataType(const OpcUa_RedundantServerDataType &other);
    UaRedundantServerDataType(
        const UaString& serverId,
        OpcUa_Byte serviceLevel,
        OpcUa_ServerState serverState
        );
    UaRedundantServerDataType(const UaExtensionObject &extensionObject);
    UaRedundantServerDataType(const OpcUa_ExtensionObject &extensionObject);
    UaRedundantServerDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaRedundantServerDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaRedundantServerDataType();

    void clear();

    bool operator==(const UaRedundantServerDataType &other) const;
    bool operator!=(const UaRedundantServerDataType &other) const;

    UaRedundantServerDataType& operator=(const UaRedundantServerDataType &other);

    OpcUa_RedundantServerDataType* copy() const;
    void copyTo(OpcUa_RedundantServerDataType *pDst) const;

    static OpcUa_RedundantServerDataType* clone(const OpcUa_RedundantServerDataType& source);
    static void cloneTo(const OpcUa_RedundantServerDataType& source, OpcUa_RedundantServerDataType& copy);

    void attach(OpcUa_RedundantServerDataType *pValue);
    OpcUa_RedundantServerDataType* detach(OpcUa_RedundantServerDataType* pDst);

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

    OpcUa_StatusCode setRedundantServerDataType(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setRedundantServerDataType(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setRedundantServerDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setRedundantServerDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setRedundantServerDataType(
        const UaString& serverId,
        OpcUa_Byte serviceLevel,
        OpcUa_ServerState serverState
        );

    UaString getServerId() const;
    OpcUa_Byte getServiceLevel() const;
    OpcUa_ServerState getServerState() const;

    void setServerId(const UaString& serverId);
    void setServiceLevel(OpcUa_Byte serviceLevel);
    void setServerState(OpcUa_ServerState serverState);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_RedundantServerDataType.
 *
 *  This class encapsulates an array of the native OpcUa_RedundantServerDataType structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaRedundantServerDataType for information about the encapsulated structure.
 */
class UABASE_EXPORT UaRedundantServerDataTypes
{
public:
    UaRedundantServerDataTypes();
    UaRedundantServerDataTypes(const UaRedundantServerDataTypes &other);
    UaRedundantServerDataTypes(OpcUa_Int32 length, OpcUa_RedundantServerDataType* data);
    virtual ~UaRedundantServerDataTypes();

    UaRedundantServerDataTypes& operator=(const UaRedundantServerDataTypes &other);
    const OpcUa_RedundantServerDataType& operator[](OpcUa_UInt32 index) const;
    OpcUa_RedundantServerDataType& operator[](OpcUa_UInt32 index);

    bool operator==(const UaRedundantServerDataTypes &other) const;
    bool operator!=(const UaRedundantServerDataTypes &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_RedundantServerDataType* data);
    void attach(OpcUa_Int32 length, OpcUa_RedundantServerDataType* data);
    OpcUa_RedundantServerDataType* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_RedundantServerDataType* rawData() const {return m_data;}
    inline OpcUa_RedundantServerDataType* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setRedundantServerDataTypes(const UaVariant &variant);
    OpcUa_StatusCode setRedundantServerDataTypes(const OpcUa_Variant &variant);
    OpcUa_StatusCode setRedundantServerDataTypes(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setRedundantServerDataTypes(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setRedundantServerDataTypes(OpcUa_Int32 length, OpcUa_RedundantServerDataType* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_RedundantServerDataType* m_data;
};

#endif // UAREDUNDANTSERVERDATATYPE_H

