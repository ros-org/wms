/******************************************************************************
** uasessionsecuritydiagnosticsdatatype.h
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
** Portable UaSessionSecurityDiagnosticsDataType class.
**
******************************************************************************/
#ifndef UASESSIONSECURITYDIAGNOSTICSDATATYPE_H
#define UASESSIONSECURITYDIAGNOSTICSDATATYPE_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uabytestring.h"
#include "uanodeid.h"
#include "uastring.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaSessionSecurityDiagnosticsDataTypePrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_SessionSecurityDiagnosticsDataType.
 *
 *  This class encapsulates the native OpcUa_SessionSecurityDiagnosticsDataType structure
 *  and handles memory allocation and cleanup for you.
 *  UaSessionSecurityDiagnosticsDataType uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared SessionSecurityDiagnosticsDataType it creates a copy for that (copy-on-write).
 *  So assigning another UaSessionSecurityDiagnosticsDataType or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  contains security-related diagnostic information about client sessions.
 *
 *  Because this information is security-related, it should not be made accessible
 *  to all users, but only to authorised users.
 */
class UABASE_EXPORT UaSessionSecurityDiagnosticsDataType
{
    UA_DECLARE_PRIVATE(UaSessionSecurityDiagnosticsDataType)
public:
    UaSessionSecurityDiagnosticsDataType();
    UaSessionSecurityDiagnosticsDataType(const UaSessionSecurityDiagnosticsDataType &other);
    UaSessionSecurityDiagnosticsDataType(const OpcUa_SessionSecurityDiagnosticsDataType &other);
    UaSessionSecurityDiagnosticsDataType(
        const UaNodeId& sessionId,
        const UaString& clientUserIdOfSession,
        const UaStringArray &clientUserIdHistory,
        const UaString& authenticationMechanism,
        const UaString& encoding,
        const UaString& transportProtocol,
        OpcUa_MessageSecurityMode securityMode,
        const UaString& securityPolicyUri,
        const UaByteString& clientCertificate
        );
    UaSessionSecurityDiagnosticsDataType(const UaExtensionObject &extensionObject);
    UaSessionSecurityDiagnosticsDataType(const OpcUa_ExtensionObject &extensionObject);
    UaSessionSecurityDiagnosticsDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaSessionSecurityDiagnosticsDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaSessionSecurityDiagnosticsDataType();

    void clear();

    bool operator==(const UaSessionSecurityDiagnosticsDataType &other) const;
    bool operator!=(const UaSessionSecurityDiagnosticsDataType &other) const;

    UaSessionSecurityDiagnosticsDataType& operator=(const UaSessionSecurityDiagnosticsDataType &other);

    OpcUa_SessionSecurityDiagnosticsDataType* copy() const;
    void copyTo(OpcUa_SessionSecurityDiagnosticsDataType *pDst) const;

    static OpcUa_SessionSecurityDiagnosticsDataType* clone(const OpcUa_SessionSecurityDiagnosticsDataType& source);
    static void cloneTo(const OpcUa_SessionSecurityDiagnosticsDataType& source, OpcUa_SessionSecurityDiagnosticsDataType& copy);

    void attach(OpcUa_SessionSecurityDiagnosticsDataType *pValue);
    OpcUa_SessionSecurityDiagnosticsDataType* detach(OpcUa_SessionSecurityDiagnosticsDataType* pDst);

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

    OpcUa_StatusCode setSessionSecurityDiagnosticsDataType(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setSessionSecurityDiagnosticsDataType(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setSessionSecurityDiagnosticsDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSessionSecurityDiagnosticsDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setSessionSecurityDiagnosticsDataType(
        const UaNodeId& sessionId,
        const UaString& clientUserIdOfSession,
        const UaStringArray &clientUserIdHistory,
        const UaString& authenticationMechanism,
        const UaString& encoding,
        const UaString& transportProtocol,
        OpcUa_MessageSecurityMode securityMode,
        const UaString& securityPolicyUri,
        const UaByteString& clientCertificate
        );

    UaNodeId getSessionId() const;
    UaString getClientUserIdOfSession() const;
    void getClientUserIdHistory(UaStringArray& clientUserIdHistory) const;
    UaString getAuthenticationMechanism() const;
    UaString getEncoding() const;
    UaString getTransportProtocol() const;
    OpcUa_MessageSecurityMode getSecurityMode() const;
    UaString getSecurityPolicyUri() const;
    UaByteString getClientCertificate() const;

    void setSessionId(const UaNodeId& sessionId);
    void setClientUserIdOfSession(const UaString& clientUserIdOfSession);
    void setClientUserIdHistory(const UaStringArray &clientUserIdHistory);
    void setAuthenticationMechanism(const UaString& authenticationMechanism);
    void setEncoding(const UaString& encoding);
    void setTransportProtocol(const UaString& transportProtocol);
    void setSecurityMode(OpcUa_MessageSecurityMode securityMode);
    void setSecurityPolicyUri(const UaString& securityPolicyUri);
    void setClientCertificate(const UaByteString& clientCertificate);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_SessionSecurityDiagnosticsDataType.
 *
 *  This class encapsulates an array of the native OpcUa_SessionSecurityDiagnosticsDataType structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaSessionSecurityDiagnosticsDataType for information about the encapsulated structure.
 */
class UABASE_EXPORT UaSessionSecurityDiagnosticsDataTypes
{
public:
    UaSessionSecurityDiagnosticsDataTypes();
    UaSessionSecurityDiagnosticsDataTypes(const UaSessionSecurityDiagnosticsDataTypes &other);
    UaSessionSecurityDiagnosticsDataTypes(OpcUa_Int32 length, OpcUa_SessionSecurityDiagnosticsDataType* data);
    virtual ~UaSessionSecurityDiagnosticsDataTypes();

    UaSessionSecurityDiagnosticsDataTypes& operator=(const UaSessionSecurityDiagnosticsDataTypes &other);
    const OpcUa_SessionSecurityDiagnosticsDataType& operator[](OpcUa_UInt32 index) const;
    OpcUa_SessionSecurityDiagnosticsDataType& operator[](OpcUa_UInt32 index);

    bool operator==(const UaSessionSecurityDiagnosticsDataTypes &other) const;
    bool operator!=(const UaSessionSecurityDiagnosticsDataTypes &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_SessionSecurityDiagnosticsDataType* data);
    void attach(OpcUa_Int32 length, OpcUa_SessionSecurityDiagnosticsDataType* data);
    OpcUa_SessionSecurityDiagnosticsDataType* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_SessionSecurityDiagnosticsDataType* rawData() const {return m_data;}
    inline OpcUa_SessionSecurityDiagnosticsDataType* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setSessionSecurityDiagnosticsDataTypes(const UaVariant &variant);
    OpcUa_StatusCode setSessionSecurityDiagnosticsDataTypes(const OpcUa_Variant &variant);
    OpcUa_StatusCode setSessionSecurityDiagnosticsDataTypes(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSessionSecurityDiagnosticsDataTypes(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setSessionSecurityDiagnosticsDataTypes(OpcUa_Int32 length, OpcUa_SessionSecurityDiagnosticsDataType* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_SessionSecurityDiagnosticsDataType* m_data;
};

#endif // UASESSIONSECURITYDIAGNOSTICSDATATYPE_H

