/******************************************************************************
** uaendpoint.h
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
** Project: C++ OPC Server SDK UA communication module
**
** Description: Container class for optimized handling of OPC UA Endpoint description data.
**
******************************************************************************/
#ifndef UAENDPOINT_H
#define UAENDPOINT_H

#include "opcuatypes.h"
#include "opcua_proxystub.h"
#include "opcua_endpoint.h"
#include "statuscode.h"
#include "uastring.h"
#include "uabytestring.h"
#include "uaarraytemplates.h"
#include "uapkiprovider.h"

class SERVER_CORE_EXPORT UaEndpointSecuritySetting;
class SERVER_CORE_EXPORT CertificateConfiguration;
class SERVER_CORE_EXPORT CertificateStoreConfiguration;
typedef UaObjectPointerArray<UaEndpointSecuritySetting> UaEndpointSecuritySettingArray;

/** UaEndpoint
 *  @brief Container class for optimized handling of OPC UA Endpoint description data.
 *  The list of endpoints is used by the SDK to open the endpoints in the UA ANSI C Stack when the
 *  UA Module is started with UaModule::startUp. For each endpoint in the list the method
 *  OpcUa_Endpoint_Open is called in the UA ANSI C Stack.
 *  The list is also used to return the list of endpoint descriptions in the UA Service implementation
 *  for GetEndpoints. In this case the Service returns multiple endpoint description for each endpoint
 *  if more than one security policy or more than one security mode is set.
 */
class SERVER_CORE_EXPORT UaEndpoint : public UaPkiProviderCertificateValidationCallback
{
public:
    /* construction */
    UaEndpoint();
    UaEndpoint(const UaEndpoint &other);
    /* destruction */
    virtual ~UaEndpoint();

    UaEndpoint& operator=(const UaEndpoint &other);

    /* Set the serializer type used for the endpoint.
     * @param eSerializerType  Serializer type enumeration value.
     *                         Possible enumeration values are
     *                         OpcUa_Endpoint_SerializerType_Binary
     *                         OpcUa_Endpoint_SerializerType_Xml
     */
    UaStatus setSerializerType(OpcUa_Endpoint_SerializerType  eSerializerType);

    /** Get the serializer type used for the endpoint.
     * @return Serializer type.
     * @see setSerializerType
     */
    inline OpcUa_Endpoint_SerializerType eSerializerType() const { return m_eSerializerType; };

    /* Set the URL used for the endpoint. */
    void setEndpointUrl ( UaString sEndpointUrl, OpcUa_Boolean useAlsoAsStackUrl );
    /** Get the URL used for the endpoint. */
    inline UaString sEndpointUrl() const { return m_sEndpointUrl;}

    /** Set the URL for the Endpoint used for the stack.
     * This URL allows to define a specific address the stack should use to bind to.
     */
    void setStackEndpointUrl ( UaString sStackEndpointUrl );
    /* Get the URL used for the endpoint. */
    inline UaString sStackEndpointUrl() const { return m_sStackEndpointUrl;};

    /* Add a security setting to the endpoint. */
    UaStatus addSecuritySetting(const UaEndpointSecuritySetting& endpointSecuritySetting);

    /** Get the list of security settings.
     * @return List of security settings.
     * @see addSecuritySetting
     */
    inline const UaEndpointSecuritySettingArray& securitySettings() const { return m_securitySettings;};

    /* Get the handle to the PKI configuration. */
    OpcUa_Handle hPKIConfig() const;
    /* Get the PKI provider. */
    UaPkiProvider* pkiProvider() const;

    /* Set the Endpoint handle for the Endpoint opened with the stack. */
    void setEndpointHandle ( OpcUa_Endpoint endpoint );
    /** Get the URL used for the endpoint. */
    inline OpcUa_Endpoint endpointHandle() const { return m_endpoint;}

    void setIsVisible(OpcUa_Boolean isVisible);
    OpcUa_Boolean isVisible() const;

    void setIsDiscoveryUrl(OpcUa_Boolean isDiscoveryUrl);
    OpcUa_Boolean isDiscoveryUrl() const;

    void setAutomaticallyTrustAllClientCertificates(OpcUa_Boolean automaticTrust);
    OpcUa_Boolean automaticallyTrustAllClientCertificates() const;

    void setCreateSignatureWithChain(OpcUa_Boolean createSignatureWithChain);
    OpcUa_Boolean createSignatureWithChain() const;

    void setDisableApplicationUriCheck(OpcUa_Boolean disableApplicationUriCheck);
    OpcUa_Boolean disableApplicationUriCheck() const;

    void setDisableUserTokenPolicyIdCheck(OpcUa_Boolean disableUserTokenPolicyIdCheck);
    OpcUa_Boolean disableUserTokenPolicyIdCheck() const;

    void setDisableNonceLengthCheck(OpcUa_Boolean disableNonceLengthCheck);
    OpcUa_Boolean disableNonceLengthCheck() const;

    void setDisableErrorCertificateTimeInvalid(OpcUa_Boolean disableErrorCertificateTimeInvalid);
    void setDisableErrorCertificateIssuerTimeInvalid(OpcUa_Boolean disableErrorCertificateIssuerTimeInvalid);
    void setDisableErrorCertificateRevocationUnknown(OpcUa_Boolean disableErrorCertificateRevocationUnknown);
    void setDisableErrorCertificateIssuerRevocationUnknown(OpcUa_Boolean disableErrorCertificateIssuerRevocationUnknown);

    void setIsTransparentRedundant(OpcUa_Boolean isTransparentRedundant);
    OpcUa_Boolean isTransparentRedundant() const;

    inline void setEndpointIndex(OpcUa_UInt32 index) {m_index = index;}
    inline OpcUa_UInt32 endpointIndex() const {return m_index;}

    inline void setOpened(bool isOpened) {m_isOpened = isOpened;}
    inline bool isOpened() const {return m_isOpened;}

    /** Returns the index of the CertificateSore used for the endpoint*/
    inline OpcUa_UInt32 endpointCertificateStoreIndex() const {return m_endpointCertificateStoreIndex;}
    /** Returns the CertificateStoreConfiguration object for the endpoint*/
    inline CertificateStoreConfiguration* pEndpointCertificateStore() const {return m_pEndpointCertificateStore;}
    /** Returns the CertificateConfiguration object for the endpoint*/
    inline CertificateConfiguration* pEndpointCertificateSettings() const {return m_pEndpointCertificateSettings;}

    void setupPkiProvider();
    UaStatus loadCertificate();

    virtual bool certificateVerificationError(
        OpcUa_Void*          pvVerifyContext,
        const UaByteString  &certificateChain,
        OpcUa_StatusCode     uVerificationResult,
        OpcUa_UInt32         uDepth);

    static UaStatus setupCertificateStore(
        CertificateStoreConfiguration*   pEndpointCertificateStore,
        CertificateConfiguration* pEndpointCertificateSettings);

    static UaStatus createCertificate(
        const UaString& sServerUri,
        CertificateConfiguration* pEndpointCertificateSettings);

protected:
    /* Serializer type used for the endpoint. */
    OpcUa_Endpoint_SerializerType  m_eSerializerType;
    /* URL used for the endpoint. */
    UaString                       m_sEndpointUrl;
    /* URL for the Endpoint used for the stack that allows to define a specific address the stack should use to bind to. */
    UaString                       m_sStackEndpointUrl;
    /* List of security settings for the Endpoint. */
    UaEndpointSecuritySettingArray m_securitySettings;

    /* Endpoint handle */
    OpcUa_Endpoint                 m_endpoint;
    OpcUa_UInt32                   m_endpointCertificateStoreIndex;
    CertificateStoreConfiguration* m_pEndpointCertificateStore;
    CertificateConfiguration*      m_pEndpointCertificateSettings;

    /* PKI provider. */
    UaPkiProvider*                 m_pPkiProvider;
    /* Flag indicating if the endpoint is provided in GetEndpoints */
    OpcUa_Boolean                  m_isVisible;
    /* Flag indicating if the endpoint URL is provided as discovery URL */
    OpcUa_Boolean                  m_isDiscoveryUrl;
    /* Flag that indicates if the endpoint automatically trusts all client certificates */
    OpcUa_Boolean                  m_automaticallyTrustAllClientCertificates;
    OpcUa_Boolean                  m_createSignatureWithChain;
    OpcUa_Boolean                  m_disableApplicationUriCheck;
    OpcUa_Boolean                  m_disableUserTokenPolicyIdCheck;
    OpcUa_Boolean                  m_disableNonceLengthCheck;
    OpcUa_Boolean                  m_disableErrorCertificateTimeInvalid;
    OpcUa_Boolean                  m_disableErrorCertificateIssuerTimeInvalid;
    OpcUa_Boolean                  m_disableErrorCertificateRevocationUnknown;
    OpcUa_Boolean                  m_disableErrorCertificateIssuerRevocationUnknown;
    /* Flag indicating if the endpoint support transparent redundancy */
    OpcUa_Boolean                  m_isTransparentRedundant;
    /* The index of the endpoint assigned by the server */
    OpcUa_UInt32                   m_index;
    bool                           m_isOpened;
};

/** UaEndpointSecuritySetting
 *  @brief UaEndpointSecuritySetting Class.
 */
class SERVER_CORE_EXPORT UaEndpointSecuritySetting
{
public:
    /* construction */
    UaEndpointSecuritySetting();
    UaEndpointSecuritySetting(const UaEndpointSecuritySetting &other);
    /* destruction */
    virtual ~UaEndpointSecuritySetting();

    UaEndpointSecuritySetting& operator=(const UaEndpointSecuritySetting &other);

    /* Set the security policy to support in the security setting. */
    void setSecurityPolicy(UaString sSecurityPolicy);
    /* Get the the security policy to support in the security setting. */
    inline UaString sSecurityPolicy() const { return m_sSecurityPolicy;};

    /* Add a message security mode to support.
     * @param uMessageSecurityMode    Message security mode to add.
     *                                Possible values are
     *                                OPCUA_ENDPOINT_MESSAGESECURITYMODE_NONE            0x01
     *                                OPCUA_ENDPOINT_MESSAGESECURITYMODE_SIGN            0x02
     *                                OPCUA_ENDPOINT_MESSAGESECURITYMODE_SIGNANDENCRYPT  0x04
     */
    UaStatus addMessageSecurityMode(OpcUa_UInt16 uMessageSecurityMode);

    /* Get message security modes supported by the endpoint.
     * @return Message security modes.
     * @see addMessageSecurityMode
     */
    inline OpcUa_UInt16 uMessageSecurityModes() const { return m_uMessageSecurityModes;};

    /* Get number of message security modes supported by the endpoint.
     * @return Number of message security modes.
     * @see addMessageSecurityMode
     */
    OpcUa_UInt16 numberOfMessageSecurityModes() const;

protected:
    /** List of security policies to support in the endpoint. */
    UaString                       m_sSecurityPolicy;
    /** Security modes supported by the endpoint. */
    OpcUa_UInt16                   m_uMessageSecurityModes;
};

/** An array of UaEndpoints */
typedef SERVER_CORE_EXPORT UaObjectPointerArray<UaEndpoint> UaEndpointArray;

#endif // UAENDPOINT_H
