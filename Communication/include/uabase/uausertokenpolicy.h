/******************************************************************************
** uausertokenpolicy.h
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
** Portable UaUserTokenPolicy class.
**
******************************************************************************/
#ifndef UAUSERTOKENPOLICY_H
#define UAUSERTOKENPOLICY_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uastring.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaUserTokenPolicyPrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_UserTokenPolicy.
 *
 *  This class encapsulates the native OpcUa_UserTokenPolicy structure
 *  and handles memory allocation and cleanup for you.
 *  UaUserTokenPolicy uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared UserTokenPolicy it creates a copy for that (copy-on-write).
 *  So assigning another UaUserTokenPolicy or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  Specifies a UserIdentityToken that a Server will accept.
 */
class UABASE_EXPORT UaUserTokenPolicy
{
    UA_DECLARE_PRIVATE(UaUserTokenPolicy)
public:
    UaUserTokenPolicy();
    UaUserTokenPolicy(const UaUserTokenPolicy &other);
    UaUserTokenPolicy(const OpcUa_UserTokenPolicy &other);
    UaUserTokenPolicy(
        const UaString& policyId,
        OpcUa_UserTokenType tokenType,
        const UaString& issuedTokenType,
        const UaString& issuerEndpointUrl,
        const UaString& securityPolicyUri
        );
    UaUserTokenPolicy(const UaExtensionObject &extensionObject);
    UaUserTokenPolicy(const OpcUa_ExtensionObject &extensionObject);
    UaUserTokenPolicy(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaUserTokenPolicy(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaUserTokenPolicy();

    void clear();

    bool operator==(const UaUserTokenPolicy &other) const;
    bool operator!=(const UaUserTokenPolicy &other) const;

    UaUserTokenPolicy& operator=(const UaUserTokenPolicy &other);

    OpcUa_UserTokenPolicy* copy() const;
    void copyTo(OpcUa_UserTokenPolicy *pDst) const;

    static OpcUa_UserTokenPolicy* clone(const OpcUa_UserTokenPolicy& source);
    static void cloneTo(const OpcUa_UserTokenPolicy& source, OpcUa_UserTokenPolicy& copy);

    void attach(OpcUa_UserTokenPolicy *pValue);
    OpcUa_UserTokenPolicy* detach(OpcUa_UserTokenPolicy* pDst);

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

    OpcUa_StatusCode setUserTokenPolicy(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setUserTokenPolicy(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setUserTokenPolicy(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setUserTokenPolicy(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setUserTokenPolicy(
        const UaString& policyId,
        OpcUa_UserTokenType tokenType,
        const UaString& issuedTokenType,
        const UaString& issuerEndpointUrl,
        const UaString& securityPolicyUri
        );

    UaString getPolicyId() const;
    OpcUa_UserTokenType getTokenType() const;
    UaString getIssuedTokenType() const;
    UaString getIssuerEndpointUrl() const;
    UaString getSecurityPolicyUri() const;

    void setPolicyId(const UaString& policyId);
    void setTokenType(OpcUa_UserTokenType tokenType);
    void setIssuedTokenType(const UaString& issuedTokenType);
    void setIssuerEndpointUrl(const UaString& issuerEndpointUrl);
    void setSecurityPolicyUri(const UaString& securityPolicyUri);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_UserTokenPolicy.
 *
 *  This class encapsulates an array of the native OpcUa_UserTokenPolicy structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaUserTokenPolicy for information about the encapsulated structure.
 */
class UABASE_EXPORT UaUserTokenPolicys
{
public:
    UaUserTokenPolicys();
    UaUserTokenPolicys(const UaUserTokenPolicys &other);
    UaUserTokenPolicys(OpcUa_Int32 length, OpcUa_UserTokenPolicy* data);
    virtual ~UaUserTokenPolicys();

    UaUserTokenPolicys& operator=(const UaUserTokenPolicys &other);
    const OpcUa_UserTokenPolicy& operator[](OpcUa_UInt32 index) const;
    OpcUa_UserTokenPolicy& operator[](OpcUa_UInt32 index);

    bool operator==(const UaUserTokenPolicys &other) const;
    bool operator!=(const UaUserTokenPolicys &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_UserTokenPolicy* data);
    void attach(OpcUa_Int32 length, OpcUa_UserTokenPolicy* data);
    OpcUa_UserTokenPolicy* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_UserTokenPolicy* rawData() const {return m_data;}
    inline OpcUa_UserTokenPolicy* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setUserTokenPolicys(const UaVariant &variant);
    OpcUa_StatusCode setUserTokenPolicys(const OpcUa_Variant &variant);
    OpcUa_StatusCode setUserTokenPolicys(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setUserTokenPolicys(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setUserTokenPolicys(OpcUa_Int32 length, OpcUa_UserTokenPolicy* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_UserTokenPolicy* m_data;
};

#endif // UAUSERTOKENPOLICY_H

