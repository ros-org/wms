/******************************************************************************
** uaclientsdk.h
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
** Project: C++ OPC Client SDK
**
** Description: Namespace and defines for OPC UA client library.
**
******************************************************************************/
#ifndef UACLIENTSDK_H
#define UACLIENTSDK_H

// OPC UA stack includes
#include "opcua_proxystub.h"
#include "opcua_builtintypes.h"
#include "opcua_attributes.h"
#include "opcua_encodeableobject.h"

#include "uaplatformdefs.h"
#include "uaarraytemplates.h"
#include "statuscode.h"
#include "uanodeid.h"
#include "uavariant.h"
#include "uauseridentitytoken.h"
#include "uaeventfilter.h"
#include "uaendpointdescription.h"
#include "uahistoryeventfieldlist.h"
#include "uadatetime.h"

#if OPCUA_SUPPORT_PKI_WIN32
  #include "uapkiconfig.h"
#endif

#ifdef _WIN32
# ifdef _UA_CLIENT_BUILD_DLL
#  define UACLIENT_EXPORT __declspec(dllexport)
# elif defined _UA_CLIENT_USE_DLL
#  define UACLIENT_EXPORT __declspec(dllimport)
# else
#  define UACLIENT_EXPORT
# endif
#else
# define UACLIENT_EXPORT
#endif

/** \brief Namespace for the C++ OPC UA Client Library.
 *
 *  @ingroup UaClientLibraryHelper
*/
namespace UaClientSdk {

class UaSessionCallback;
class SessionSecurityInfo;

/*! \addtogroup UaClientLibraryHelper
*  @{
*/

/** \brief Namespace class for OPC UA Client Library.*/
class UACLIENT_EXPORT UaClient
{
public:
    /// OPC UA server status enumeration used to indicate the connection status in the client API
    enum ServerStatus
    {
        Disconnected, /*!< The connection to the server is deactivated by the user of the client API. */
        Connected, /*!< The connection to the server is established and is working in normal mode. */
        ConnectionWarningWatchdogTimeout,  /*!< The monitoring of the connection to the server indicated a potential connection problem. */
        ConnectionErrorApiReconnect, /*!< The monitoring of the connection to the server detected an error and is trying to reconnect to the server. */
        ServerShutdown, /*!< The server sent a shut-down event and the client API tries a reconnect. */
        NewSessionCreated /*!< The client was not able to reuse the old session and created a new session during reconnect. This requires to redo register nodes for the new session or to read the namespace array. */
    };

    /// Service type enumeration used to indicate a connection establishment step in the client API
    enum ConnectServiceType
    {
        CertificateValidation, /*!< Certificate validation steps. */
        OpenSecureChannel, /*!< Processing of Service OpenSecureChannel. */
        CreateSession, /*!< Processing of Service CreateSession. */
        ActivateSession /*!< Processing of Service ActivateSession. */
    };

    static UaString serviceTypeString(ConnectServiceType serviceType);

    /// Enumeration used to define the access to the data type dictionary
    enum ReadTypeDictionaries
    {
        ReadTypeDictionaries_FirstUse = 0, /*!< The data type dictionary is read when used the first time by the client application. */
        ReadTypeDictionaries_Manual, /*!< Reading the data type dictionary must be triggered manually through UaSession::loadDataTypeDictionaries(). */
        ReadTypeDictionaries_Connect, /*!< The data type dictionary is read during connection establishment to the server. */
        ReadTypeDictionaries_Reconnect /*!< The data type dictionary is read during connection establishment and reconnect. */
    };
};

/** \brief The SessionConnectInfo class contains the session settings for connect.*/
class UACLIENT_EXPORT SessionConnectInfo
{
public:
    /** \brief Creates a SessionConnectInfo object with default settings
     *
     * \todo include list of default settings?
     */
    SessionConnectInfo()
    {
        clientConnectionId = 0;
        // Default is 20 minutes
        nSessionTimeout        = 1200000;
        nConnectTimeout        = 5000;
        nPublishTimeout        = 60000;
        // Default is 60 minutes
        nSecureChannelLifetime = 3600000;
        nWatchdogTime          = 5000;
        bAutomaticReconnect    = OpcUa_True;
        bRetryInitialConnect   = OpcUa_False;
        sLocaleId              = "en";
        applicationType        = OpcUa_ApplicationType_Client;
        nWatchdogTimeout       = 5000;
        nMaxOperationsPerServiceCall = 0;
        typeDictionaryMode     = UaClient::ReadTypeDictionaries_FirstUse;
        internalServiceCallTimeout = 5000;

    };
    /** Destructor */
    ~SessionConnectInfo(){};

    /** @brief The Client Application Uri.
    */
    UaString       sApplicationUri;

    /** @brief The Client Application Name.
    */
    UaString       sApplicationName;

    /** @brief The Client Product Uri.
    */
    UaString       sProductUri;

    /** @brief The Session Name. This name should be unique for the instance of the client.
    */
    UaString       sSessionName;

    /// The Client Application Type.

    /// Possible values are:
    /// - OpcUa_ApplicationType_Client
    /// - OpcUa_ApplicationType_ClientAndServer
    ///
    OpcUa_ApplicationType applicationType;

    /** @brief The client defined connection Id.
    *
    * The connection Id is returned in all session callbacks to distinguish between callbacks
    * for different connections if the same callback interface is used for more than one connection.
    * Can be 0 if not needed.
    */
    OpcUa_UInt32   clientConnectionId;

    /** @brief The time-out for the application session in milliseconds.
    *
    * The client library ensures that the session does not time out as long as the client application
    * does not call disconnect. The session can time out if the network connection is broken for longer
    * than the defined session time-out. A long time-out ensures that the established application session
    * can be reused after the longer network interruption. Default value is 20 minutes, the minimum
    * value enforced by the client library is 30 seconds. This time-out has no effect for the individual
    * time-out for a service call (can be defined per call). This time-out is only used to ensure
    * that the server is able to release resources if a client is disconnected for a long time.
    */
    OpcUa_Double    nSessionTimeout;

    /** @brief The locale ID uses for the session.
    *
    * Examples are
    * - "en" for English
    * - "en-US" for English (US)
    * - "de" for German
    * - "de-DE" for German (Germany)
    * - "de-AT" for German (Austria)
    */
    UaString       sLocaleId;

    /** @brief Additional locale IDs to be used for the session.
    * See @ref sLocaleId for examples.
    */
    UaStringArray  arAdditionalLocaleIds;

    /** @brief The lifetime of the SecureChannel in milliseconds before it gets renewed.
    *
    * This is the time the key pair exchanged during secure channel establishment are valid. The stack starts
    * the renew process that exchanges new key pairs after 75% of the lifetime. The default lifetime is one hour.
    */
    OpcUa_UInt32   nSecureChannelLifetime;

    /** @brief The time-out for the connect call in milliseconds.
     *
     * The default value for the connect time-out is 5000 milliseconds.
     */
    OpcUa_UInt32   nConnectTimeout;

    /** @brief The time-out for Publish request calls in milliseconds.
     *
     * The default value for the publish time-out is 60 seconds (60000ms).
     *
     * It is strongly recommended to keep the default timeout. A shorter timeout should only
     * be configured if the timeout of the underlying transport protocol like HTTP is shorter
     * than 60 seconds.
     *
     * In OPC UA Publish handling, the server queues the Publish requests until new data is available
     * or a KeepAlive message is sent. In addition the client SDK sends more than one Publish request into
     * this queue. Therefore it may take a while until the server sends a Publish response to the client.
     * If the timeout happens before, a Publish response may get lost if already timed out in the client.
     *
     * The maximum time between Publish responses depends on the KeepAlive setting for the Subscriptions in
     * a Session.
     *
     * The client application is informed about lost Notification messages contained in Publish responses through
     * SubscriptionCallback::notificationsMissing. Lost notifications can be requested with the Republish service.
     */
    OpcUa_UInt32   nPublishTimeout;

    /** @brief The time between watchdog checks in milliseconds.
     *
     * The default value for the watchdog time is 5000 milliseconds. The minimum value accepted by the SDK is 1000 milliseconds.
     */
    OpcUa_UInt32   nWatchdogTime;

    /** @brief A flag indicating if the client SDK should try to reconnect in the case of a connection error.
     *
     * The default value is OpcUa_True.
     */
    OpcUa_Boolean  bAutomaticReconnect;

    /** @brief A flag indicating if the client SDK should continue to try a connect establishment in the background if the initial connect fails.
     *
     * The default value is OpcUa_False.
     */
    OpcUa_Boolean  bRetryInitialConnect;

    /** @brief A list of alternative Endpoint URLs to connect to for network redundancy.
    *
    * This configuration option allows to specify endpoints for the same server connected to with the URL parameter passed to UaSession::connect().
    * It can be used for redundant networks used to connect to a server with the same ServerUri and Server certificate.
    * Specifying URLs of different servers with different certificates will cause a connection error when using a security policy other than NONE.
    * @code
    * SessionConnectInfo sessionConnectInfo;
    * SessionSecurityInfo sessionSecurityInfo;
    * UaString sFirstUrl("opc.tcp://192.168.0.55:48010");
    * UaString sSecondUrl("opc.tcp://192.168.10.55:48010");
    * // Do other initialization
    *
    * // Set URL of the alternative endpoint
    * sessionConnectInfo.alternativeEndpointUrls.create(1);
    * sSecondUrl.copyTo(&sessionConnectInfo.alternativeEndpointUrls[0]);
    *
    * status = pUaSession->connect(
    * sFirstUrl,           // URL of the regular Endpoint
    * sessionConnectInfo,  // General settings for connection
    * sessionSecurityInfo, // Security settings
    * pCallback);          // Callback interface
    * @endcode
    */
    UaStringArray  alternativeEndpointUrls;

    /** @brief The Server Uri of the server to connect through a gateway server.
    *
    * This value is only specified if the EndpointDescription has a gatewayServerUri.
    * This value is the applicationUri from the EndpointDescription which is the
    * applicationUri for the underlying Server.
    */
    UaString       sServerUri;

    /** @brief The endpoint descriptions returned from the server during session creation.
    *
    * The list must be verified with the list returned during discovery at the first
    * connect to make sure the discovery server provided the right list and the client
    * was able to choose the most secure setting.
    */
    UaEndpointDescriptions endpointDescriptions;

    /** @brief The time-out for watchdog calls in milliseconds. After one unsuccessful call
     *
     * The time-out will be two times this value for the next call.
     *
     * The default value for the watchdog time is 5000 milliseconds.
     */
    OpcUa_UInt32   nWatchdogTimeout;

    /** @brief The maximum number of operations used in a Service call.
     *
     * The OPC UA server may restrict the message size and array sizes. This parameter provides a way
     * to reduce the number of operations, like nodes to read in a Read call, to a number that works.
     * The caller of the API does not need to care about the limitations. The SDK will send several
     * Service calls if the number of operations provided by the caller exceeds the maximum number the server
     * accepts. The value 0 indicates no limitation.
     *
     * The default value is 0.
     */
    OpcUa_UInt32   nMaxOperationsPerServiceCall;

    /** @brief The mode for updating the data type dictionaries from the server
     * Possible options are
     * <dl>
     *   <dt>FirstUse</dt><dd>The data type dictionary is read when used the first time by the client application</dd>
     *   <dt>Manual</dt><dd>Read of dictionaries from server is only triggered through UaSession::loadDataTypeDictionaries()</dd>
     *   <dt>Connect</dt><dd>Initial read of dictionaries from server is done at connect</dd>
     *   <dt>Reconnect</dt><dd>Initial read of dictionaries from server is done at connect and they are updated at reconnect</dd>
     * </dl>
     *
     * The default value is FirstUse.
     * For this functionality, SUPPORT_XML_PARSER needs to be enabled. If SUPPORT_XML_PARSER is disabled, only the known
     * type dictionary of namespace 0 will be loaded.
     */
    UaClient::ReadTypeDictionaries typeDictionaryMode;

    /** @brief The time-out for all internal UA service calls in milliseconds.
    *
    * The default value is 5000 milliseconds.
    */
    OpcUa_UInt32  internalServiceCallTimeout;

    /** @brief An identifier that identifies the Client's security audit log entry associated with the connection related requests. */
    UaString      auditEntryId;
};

class ClientSecurityInfoPrivate;

/// The ClientSecurityInfo class contains the security related settings to create a secure channel.
class UACLIENT_EXPORT ClientSecurityInfo
{
    UA_DISABLE_COPY(ClientSecurityInfo);
public:
    ClientSecurityInfo();
    ~ClientSecurityInfo();

#if OPCUA_SUPPORT_PKI
#if OPCUA_SUPPORT_PKI_OPENSSL
    UaStatusCode initializePkiProviderOpenSSL(
        const UaString& sCertificateRevocationListLocation,
        const UaString& sCertificateTrustListLocation);

    UaStatusCode initializePkiProviderOpenSSL(
        const UaString& sCertificateRevocationListLocation,
        const UaString& sCertificateTrustListLocation,
        const UaString& sIssuersRevocationListLocation,
        const UaString& sIssuersCertificatesLocation);

    UaStatusCode loadClientCertificateOpenSSL(
        const UaString& sClientCertificateFile,
        const UaString& sClientPrivateKeyFile);
#endif // OPCUA_SUPPORT_PKI_OPENSSL
#if OPCUA_SUPPORT_PKI_WIN32
    UaStatusCode initializePkiProviderWindows(
        WindowsStoreLocation certificateStoreLocation,
        const UaString& sCertificateStoreName);

    UaStatusCode initializePkiProviderWindows(
        WindowsStoreLocation certificateStoreLocation,
        const UaString& sCertificateStoreName,
        const UaString& sIssuersCertificateStoreName);

    UaStatusCode loadClientCertificateWindows(const UaString& sCertificateThumbprint);
#endif // OPCUA_SUPPORT_PKI_WIN32
#endif // OPCUA_SUPPORT_PKI

    OpcUa_Void* pkiCfg();

    UaStatusCode initializePkiProviderHttps(
        const UaString& sHttpsIssuersRevocationListLocation,
        const UaString& sHttpsIssuersCertificatesLocation);

    OpcUa_Void* pkiCfgHttps();

    /** \brief The name of the security policy used for the connection.
    *
    * Value                              | String Representation
    * -----------------------------------|--------------------------
    * OpcUa_SecurityPolicy_None          | "http://opcfoundation.org/UA/SecurityPolicy#None" for security disabled
    * OpcUa_SecurityPolicy_Basic128Rsa15 | "http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15"
    * OpcUa_SecurityPolicy_Basic256      | "http://opcfoundation.org/UA/SecurityPolicy#Basic256"
    * OpcUa_SecurityPolicy_Basic256Sha256| "http://opcfoundation.org/UA/SecurityPolicy#Basic256Sha256"
    */
    UaString                  sSecurityPolicy;

    /**  \brief The message security mode used for the connection.
    *
    * Possible values are:
    *- OpcUa_MessageSecurityMode_None
    *- OpcUa_MessageSecurityMode_Sign
    *- OpcUa_MessageSecurityMode_SignAndEncrypt
    */
    OpcUa_MessageSecurityMode messageSecurityMode;

    /** \brief Client certificate (public key). This parameter can contain the leaf certificate only or a certificate chain. */
    UaByteString              clientCertificate;

    /** \brief Client private key */
    UaByteString              clientPrivateKey;

protected:
    ClientSecurityInfoPrivate* d;
};

/** \brief The CertificateValidationCallback is an interface for retrieving information about certificate validation errors.
* If detailed information about certificate validation is needed, the SessionSecurityInfo::verifyServerCertificate() method
* can be called by passing this interface. For each single error during certificate validation, the verificationError()
* callback will be invoked containing detailed information about the error. */
class UACLIENT_EXPORT CertificateValidationCallback
{
public:
    virtual ~CertificateValidationCallback() {}

    /** \brief Callback method to inform about errors during certificate validation.
    * @return true if a certificate validation error should be ignored, false otherwise. If an error is ignored,
    *         validation continues, otherwise verification will be stopped. */
    virtual bool verificationError(SessionSecurityInfo *pInfo,                  //!< [out] The SessionSecurityInfo where SessionSecurityInfo::verifyServerCertificate()
                                                                                //!<       was called.
                                   OpcUa_Void*          pvVerifyContext,        //!< [out] The verification context. Use SessionSecurityInfo::getCurrentErrorInformationOpenSSL
                                                                                //!<       to get detailed error information when using an OpenSSL PKI provider.
                                   const UaByteString  &certificateChain,       //!< [out] The certificate chain that was constructed during verification.
                                   OpcUa_StatusCode     uVerificationResult,    //!< [out] The verification error.
                                   OpcUa_UInt32         uDepth                  //!< [out] The index of the certificate in the certificateChain the error occured on.
                                   ) = 0;
};

/** \brief The SessionSecurityInfo class contains the security related session settings for connect.
*
* The \ref L2ClientSdkSecurity section of the client SDK introduction contains a detailed description
* on how the certificate store is set up, on how application instance certificates are created and
* how an secure connection to a server is initiated.
*/
class UACLIENT_EXPORT SessionSecurityInfo: public ClientSecurityInfo
{
public:
    // Construction
    SessionSecurityInfo();
    ~SessionSecurityInfo();
    SessionSecurityInfo(const SessionSecurityInfo&);
    SessionSecurityInfo& operator=(const SessionSecurityInfo&);

    // Loading existing certificate from store
    UaStatusCode loadServerCertificateOpenSSL(const UaString& sServerCertificateFile);
#if OPCUA_SUPPORT_PKI_WIN32
    UaStatusCode loadServerCertificateWindows(const UaString& sCertificateThumbprint);
#endif // OPCUA_SUPPORT_PKI_WIN32

    // Split a certificate chain
    UaStatusCode splitCertificateChain(const UaByteString &certificateChain,
                                       UaByteStringArray &chainEntries);

    // Save or verify server certificate in store
    UaStatusCode saveServerCertificate(UaString& sCertificateName);
    UaStatus     verifyServerCertificate(CertificateValidationCallback *pCallback = OpcUa_Null);

    UaStatusCode getCurrentErrorInformationOpenSSL(OpcUa_Void*  pvVerifyContext,
                                                   OpcUa_Int32 &iNativeError,
                                                   UaString    &sErrorMessage);

    // Handle user identity
    void setAnonymousUserIdentity();
    void setUserPasswordUserIdentity(const UaString& userName, const UaString& password);
    void setCertificateUserIdentity(const UaByteString& userCertificate, const UaByteString& userPrivateKey);

    const UaUserIdentityToken* pUserIdentityToken() const;

    /** \brief Server certificate (public key). */
    UaByteString              serverCertificate;

    /** \brief Indicates if the client SDK must verify the server certificate or if this was done already by the application.
    *
    * The default value is True to force the client SDK to verify the server certificate before establishing the connection.
    */
    OpcUa_Boolean             doServerCertificateVerify;

    /** \brief Flag used to disable the server certificate validation error BadCertificateTimeInvalid, default is false. */
    OpcUa_Boolean             disableErrorCertificateTimeInvalid;

    /** \brief Flag used to disable the client certificate validation error BadCertificateIssuerTimeInvalid, default is false. */
    OpcUa_Boolean             disableErrorCertificateIssuerTimeInvalid;

    /** \brief Flag used to disable the client certificate validation error BadCertificateRevocationUnknown, default is false. */
    OpcUa_Boolean             disableErrorCertificateRevocationUnknown;

    /** \brief Flag used to disable the client certificate validation error BadCertificateIssuerRevocationUnknown, default is false. */
    OpcUa_Boolean             disableErrorCertificateIssuerRevocationUnknown;

    /** \brief Flag used to disable the check if the hostname the client connected to matches one of the hostnames or IP addresses in the server certificate. */
    OpcUa_Boolean             disableErrorCertificateHostNameInvalid;

    /** \brief Flag used to disable the check if the password of a UserPassword identity token is encrypted properly.
    The check will fail if either the ServerNonce is not set or the PasswordEncryptionMode is None. The default is true. */
    OpcUa_Boolean             disableEncryptedPasswordCheck;

    /** \brief Flag used to disable the check if the ApplicationUri in the ServerCertificate matches the ApplicationUri the Server returns in the EndpointDescription. */
    OpcUa_Boolean             disableApplicationUriCheck;

    /** \brief Flag used to disable the check if the ServerNonce has the correct length of minimum 32 bytes. */
    OpcUa_Boolean             disableNonceLengthCheck;
};

/** \brief The ServiceSettings class contains the general settings for a call.*/
class UACLIENT_EXPORT ServiceSettings
{
public:
    /** \brief Creates a ServiceSettings object with callTimeout set to 10 seconds.*/
    ServiceSettings()
    {
        // Default 10 seconds
        callTimeout       = 10000;
        // Default no diagnostic information
        returnDiagnostics = 0;
        // Default -> Request handle is assigned by SDK
        requestHandle = 0;
    };
    /** \brief Destroys the service settings object.*/
    ~ServiceSettings(){};

    /** @brief The time-out for the service call in milliseconds. The default setting is 10 seconds.*/
    OpcUa_Int32   callTimeout;

    /** @brief Bit mask that defines the diagnostic information to be returned from the server. The default setting is 0.
    *
    * Bit Value | Diagnostics to return | Define
    * ----------|-----------------------|-------
    * 0x0000 0001 | ServiceLevel / SymbolicId | OpcUa_DiagnosticsMasks_ServiceSymbolicId
    * 0x0000 0002 | ServiceLevel / LocalizedText | OpcUa_DiagnosticsMasks_ServiceLocalizedText
    * 0x0000 0004 | ServiceLevel / AdditionalInfo | OpcUa_DiagnosticsMasks_ServiceAdditionalInfo
    * 0x0000 0008 | ServiceLevel / Inner StatusCode | OpcUa_DiagnosticsMasks_ServiceInnerStatusCode
    * 0x0000 0010 | ServiceLevel / Inner Diagnostics | OpcUa_DiagnosticsMasks_ServiceInnerDiagnostics
    * 0x0000 0020 | OperationLevel / SymbolicId | OpcUa_DiagnosticsMasks_OperationSymbolicId
    * 0x0000 0040 | OperationLevel / LocalizedText | OpcUa_DiagnosticsMasks_OperationLocalizedText
    * 0x0000 0080 | OperationLevel / AdditionalInfo | OpcUa_DiagnosticsMasks_OperationAdditionalInfo
    * 0x0000 0100 | OperationLevel / Inner StatusCode | OpcUa_DiagnosticsMasks_OperationInnerStatusCode
    * 0x0000 0200 | OperationLevel / Inner Diagnostics | OpcUa_DiagnosticsMasks_OperationInnerDiagnostics
    *
    * Additional defines for combinations:
    *
    *
    * Description  | Define
    * -------------|--------------
    * All service level diagnostic information | OpcUa_DiagnosticsMasks_ServiceAll
    * All operation level diagnostic information | OpcUa_DiagnosticsMasks_OperationAll
    * All diagnostic information without inner status | OpcUa_DiagnosticsMasks_NoInnerStatus
    * All diagnostic information | OpcUa_DiagnosticsMasks_All
    * SymbolicId for service and operation level | OpcUa_DiagnosticsMasks_SymbolicId
    * LocalizedText for service and operation level | OpcUa_DiagnosticsMasks_LocalizedText
    * AdditionalInfo for service and operation level | OpcUa_DiagnosticsMasks_AdditionalInfo
    */
    OpcUa_UInt32  returnDiagnostics;

    /** @brief An identifier that identifies the Client's security audit log entry associated with this request. */
    UaString      auditEntryId;

    /** @brief UaString table for returned diagnostic information. */
    UaStringArray stringTable;

    /** @brief Request handle used for the service call.
     *
     * The request handle is sent to the server in the RequestHeader and is used to cancel service invocations.
     * If the request handle is not set (initial value is 0), a unique number is set by the SDK.
     *
     * The SDK is using numbers above 1.000.000 for creating unique numbers. An application must make sure to only
     * use numbers below 1.000.000 to avoid conflicts when cancel is called.
     */
    OpcUa_UInt32 requestHandle;

    /** @brief Timestamp of the response as returned by the server. */
    UaDateTime   responseTimestamp;
};

/** \brief The BrowseContext class contains the settings for a browse request.*/
class UACLIENT_EXPORT BrowseContext
{
public:
    /** Creates a BrowseContext object with settings to browse hierarchical references in forward direction and
     * other default settings described for the parameters.
     */
    BrowseContext()
    {
        OpcUa_ViewDescription_Initialize(&view);
        referenceTypeId       = OpcUaId_HierarchicalReferences;
        maxReferencesToReturn = 0;
        browseDirection       = OpcUa_BrowseDirection_Forward;
        includeSubtype        = OpcUa_True;
        nodeClassMask         = 0;
        resultMask            = OpcUa_BrowseResultMask_All;
    };
    /** Destroys the browse context object.*/
    ~BrowseContext(){};

    /** @brief Optional view parameter allows browsing in a view context.
     *
     * The view context includes a view NodeId and an optional view version or view timestamp.
     * The default setting is a null ViewDescription. */
    OpcUa_ViewDescription view;

    /** @brief Parameter to limit the number of results per node.
     *
     * A server can further limit the number it returns. If the the number of
     * available results exceeds the client or server limit, a continuation
     * point is returned in the browse response.
     * The default value is 0.
     */
    OpcUa_UInt32          maxReferencesToReturn;

    /** @brief The direction of the browse with option forward, inverse or both.
     *
     * The default value is forward. Possible options are
     * - OpcUa_BrowseDirection_Forward
     * - OpcUa_BrowseDirection_Inverse
     * - OpcUa_BrowseDirection_Both
     */
    OpcUa_BrowseDirection browseDirection;

    /** @brief The type of reference to follow.
     *
     * The NodeId of the reference type to follow in the browse request. This parameter is
     * used in combination with \ref includeSubtype. If abstract base reference types are specified,
     * the parameter ref includeSubtype must be set to true.
     * The default value is OpcUaId_HierarchicalReferences.
     */
    UaNodeId              referenceTypeId;

    /** @brief Indicates if the \ref referenceTypeId to follow should include subtypes.
     *
     * The default value is true.
     */
    OpcUa_Boolean         includeSubtype;

    /** @brief NodeClass filter mask.
     *
     * The default value is 0 to return all NodeClasses.
     *
     * Possible masks to set are
     * - OpcUa_NodeClass_Object        = 1,
     * - OpcUa_NodeClass_Variable      = 2,
     * - OpcUa_NodeClass_Method        = 4,
     * - OpcUa_NodeClass_ObjectType    = 8,
     * - OpcUa_NodeClass_VariableType  = 16,
     * - OpcUa_NodeClass_ReferenceType = 32,
     * - OpcUa_NodeClass_DataType      = 64,
     * - OpcUa_NodeClass_View          = 128
     */
    OpcUa_UInt32          nodeClassMask;

    /** @brief Result mask to define results to be returned with the browse response.
     *
     * The default value is OpcUa_BrowseResultMask_All to return all results. The NodeIds of the target nodes are
     * always returned. It is recommended to request only the information that is used by the client application.
     * Possible result masks to set are
     * - OpcUa_BrowseResultMask_None              = 0,
     * - OpcUa_BrowseResultMask_ReferenceTypeId   = 1,
     * - OpcUa_BrowseResultMask_IsForward         = 2,
     * - OpcUa_BrowseResultMask_NodeClass         = 4,
     * - OpcUa_BrowseResultMask_BrowseName        = 8,
     * - OpcUa_BrowseResultMask_DisplayName       = 16,
     * - OpcUa_BrowseResultMask_TypeDefinition    = 32,
     * - OpcUa_BrowseResultMask_All               = 63,
     * - OpcUa_BrowseResultMask_ReferenceTypeInfo = 3,
     * - OpcUa_BrowseResultMask_TargetInfo        = 60
     */
    OpcUa_UInt32          resultMask;
};

/** \brief The HistoryReadRawModifiedContext class contains the settings for a HistoryReadRawModified call.*/
class UACLIENT_EXPORT HistoryReadRawModifiedContext
{
public:
    /** Creates a HistoryReadRawModifiedContext object with default settings described with the parameters.*/
    HistoryReadRawModifiedContext()
    {
        isReadModified             = OpcUa_False;
        timeStamps                 = OpcUa_TimestampsToReturn_Source;
        bReleaseContinuationPoints = OpcUa_False;
        returnBounds               = OpcUa_False;
        numValuesPerNode           = 0;
    };
    /** Destroys the HistoryReadRawModifiedContext object.*/
    ~HistoryReadRawModifiedContext(){};

    /** @brief Indicates if modified data should be read instead of the raw data.
     *
     * The default value is false.
     */
    OpcUa_Boolean              isReadModified;

    /** @brief Enumeration for the timestamps to return with the values.
     *
     * The default value is Source.
     *
     * Possible options are
     * - OpcUa_TimestampsToReturn_Source  = 0,
     * - OpcUa_TimestampsToReturn_Server  = 1,
     * - OpcUa_TimestampsToReturn_Both    = 2,
     *
     * The option OpcUa_TimestampsToReturn_Neither = 3 is invalid for history read.
     */
    OpcUa_TimestampsToReturn   timeStamps;

    /** @brief This parameter must be set to true to release a continuation point without requesting more data.
     *
     * The default value is false.
     */
    OpcUa_Boolean              bReleaseContinuationPoints;

    /** @brief Parameter to limit the number of results per node.
     *
     * A server can further limit the number he returns. If the client or server limit exceeds
     * the number of results available, a continuation point is returned in the history read response.
     * The default value is 0.
     */
    OpcUa_UInt32               numValuesPerNode;

    /** @brief The start time of the requested time domain.
     *
     * The values can be read in inverse order if the end time is before the start time.
     * The default value is null.
     */
    UaDateTime                 startTime;

    /** @brief The end time of the requested time domain.
     *
     * The values can be read in inverse order if the end time is before the start time.
     * The default value is null.
     */
    UaDateTime                 endTime;

    /** @brief Indicates if bounding values should be returned.
     *
     * Bounding values are delivered if this flag is set to true and no value is available for the requested start or end time.
     * The default value is false.
     */
    OpcUa_Boolean              returnBounds;
};

/** \brief The HistoryReadProcessedContext class contains the settings for a HistoryReadProcessed call.*/
class UACLIENT_EXPORT HistoryReadProcessedContext
{
public:
    /** Creates a HistoryReadProcessedContext object with default settings described with the parameters.*/
    HistoryReadProcessedContext()
    {
        timeStamps                    = OpcUa_TimestampsToReturn_Source;
        bReleaseContinuationPoints    = OpcUa_False;
        processingInterval            = 0;
        OpcUa_AggregateConfiguration_Initialize(&aggregateConfiguration);
        aggregateConfiguration.PercentDataBad = 100;
        aggregateConfiguration.PercentDataGood = 100;
        aggregateConfiguration.UseServerCapabilitiesDefaults = OpcUa_True;
    };
    /** Destructor */
    ~HistoryReadProcessedContext(){};

    /** @brief Indicates if the source timestamp, the server timestamp, or both should be returned.
     *
     * The default value is Source.
     *
     * Possible options are
     * - OpcUa_TimestampsToReturn_Source  = 0,
     * - OpcUa_TimestampsToReturn_Server  = 1,
     * - OpcUa_TimestampsToReturn_Both    = 2,
     *
     * The option OpcUa_TimestampsToReturn_Neither = 3 is invalid for history read.
     *
     * The selected timestamp is also used for the selection of the values in the time domain to read. If both are selected, the source timestamp is used.
     */
    OpcUa_TimestampsToReturn     timeStamps;

    /** @brief The flag indicates if the Service call is used to release ContinuationPoints returned from previous calls without returning additional data.
     *
     * This allows clients to free resources in the server if the client does not continue the read.
     * The default value is false.
     */
    OpcUa_Boolean                bReleaseContinuationPoints;

    /** @brief The NodeIds of the aggregates used for the calculation of the values. The length of this array must match the nodesToRead array. */
    UaNodeIdArray                aggregateTypes;

    /** @brief The start time of the requested time domain.
     *
     * The values can be read in inverse order if the end time is before the start time.
     * The default value is null.
     */
    UaDateTime                   startTime;

    /** @brief The end time of the requested time domain.
     *
     * The values can be read in inverse order if the end time is before the start time.
     * The default value is null.
     */
    UaDateTime                   endTime;

    /** @brief Time interval in milliseconds that is used to calculate one aggregated value from the raw values in the history database.
     *
     * The time domain is divided into subintervals with the length of the ResampleInterval beginning with the start
     * time. If the ResampleInterval is 0, one aggregated value is calculated for the time domain.
     * The default value is 0.
     */
    OpcUa_Double                 processingInterval;

    /** @brief The aggregateConfiguration parameter allows clients to override the Aggregate configuration
    * settings supplied by the AggregateConfiguration object in the server on a per call basis.
    *
    * The default values are
    * - UseServerCapabilitiesDefaults = true
    * - TreatUncertainAsBad = false
    * - PercentDataBad = 100
    * - PercentDataGood = 0
    * - UseSlopedExtrapolation = false
    */
    OpcUa_AggregateConfiguration aggregateConfiguration;
};

/** \brief The HistoryReadAtTimeContext class contains the settings for a HistoryReadAtTime call.*/
class UACLIENT_EXPORT HistoryReadAtTimeContext
{
public:
    /** Creates a HistoryReadAtTimeContext object with default settings described with the parameters.*/
    HistoryReadAtTimeContext()
    {
        timeStamps                 = OpcUa_TimestampsToReturn_Source;
        bReleaseContinuationPoints = OpcUa_False;
        useSimpleBounds            = OpcUa_False;
    };
    /** Destroys the HistoryReadAtTimeContext object.*/
    ~HistoryReadAtTimeContext(){};

    /** @brief Enumeration for the timestamps to return with the values.
     *
     * The default value is Source.
     *
     * Possible options are
     * - OpcUa_TimestampsToReturn_Source  = 0,
     * - OpcUa_TimestampsToReturn_Server  = 1,
     * - OpcUa_TimestampsToReturn_Both    = 2,
     *
     * The option OpcUa_TimestampsToReturn_Neither = 3 is invalid for history read.
     */
    OpcUa_TimestampsToReturn   timeStamps;

    /** @brief This parameter must be set to true to release a continuation point without requesting more data.
     *
     * The default value is false.
     */
    OpcUa_Boolean              bReleaseContinuationPoints;

    /** @brief The entries in the array define the specific timestamps for which values are to be read.
     *
     * The default value is an empty array.
     */
    UaDateTimeArray            requestedTimes;

    /** @brief Flag indicating if simple bound calculation should be applied.
     *
     * The default value is false.
     */
    OpcUa_Boolean              useSimpleBounds;
};

/** \brief The HistoryReadDataResult class contains the result for one item in a HistoryRead call for data.*/
class UACLIENT_EXPORT HistoryReadDataResult
{
public:
    /** Constructor */
    HistoryReadDataResult(){};
    /** Destructor */
    ~HistoryReadDataResult(){};

    /** @brief Result code for the operation */
    UaStatus           m_status;
    /** @brief Continuation point if the server was not able to return all available data */
    UaByteString       m_continuationPoint;
    /** @brief The data for the requested time frame */
    UaDataValues       m_dataValues;
    /** @brief Modification information for the provided modified data if the isReadModified flag was set. */
    UaModificationInfo m_modificationInformation;
};
typedef UaObjectArray<UaClientSdk::HistoryReadDataResult> HistoryReadDataResults;

/** \brief The HistoryReadEventContext class contains the settings for a HistoryReadEvent call.*/
class UACLIENT_EXPORT HistoryReadEventContext
{
public:
    /** Creates a HistoryReadEventContext object with default settings described with the parameters.*/
    HistoryReadEventContext()
    {
        timeStamps                 = OpcUa_TimestampsToReturn_Source;
        bReleaseContinuationPoints = OpcUa_False;
        numValuesPerNode           = 0;
    };
    /** Destroys the HistoryReadEventContext object.*/
    ~HistoryReadEventContext(){};


    /** @brief Enumeration for the timestamps to return with the events.
     *
     * The default value is Source.
     *
     * Possible options are
     * - OpcUa_TimestampsToReturn_Source  = 0,
     * - OpcUa_TimestampsToReturn_Server  = 1,
     * - OpcUa_TimestampsToReturn_Both    = 2,
     *
     * The option OpcUa_TimestampsToReturn_Neither = 3 is invalid for history read.
     */
    OpcUa_TimestampsToReturn   timeStamps;

    /** @brief This parameter must be set to true to release a continuation point without requesting more data.
     *
     * The default value is false.
     */
    OpcUa_Boolean              bReleaseContinuationPoints;

    /** @brief Parameter to limit the number of results per node.
     *
     * A server can further limit the number it returns. If the client or server limit exceeds
     * the number of results available, a continuation point is returned in the history read response.
     * The default value is 0.
     */
    OpcUa_UInt32               numValuesPerNode;

    /** @brief The start time of the requested time domain.
     *
     * The values can be read in inverse order if the end time is before the start time.
     * The default value is null.
     */
    UaDateTime                 startTime;

    /** @brief The end time of the requested time domain.
     *
     * The values can be read in inverse order if the end time is before the start time.
     * The default value is null.
     */
    UaDateTime                 endTime;

    /** @brief The event filter for the history read.
     *
     * This is the same event filter used for getting new events through an event monitored item.
     * The default value is null.
     */
    UaEventFilter              eventFilter;
};

/** \brief The HistoryReadDataResult class contains the result for one item in a HistoryRead call for data.*/
class UACLIENT_EXPORT HistoryReadEventResult
{
public:
    /** Constructor */
    HistoryReadEventResult(){};
    /** Destructor */
    ~HistoryReadEventResult(){};

    /** @brief Result code for the operation */
    UaStatus                 m_status;
    /** @brief Continuation point if the server was not able to return all available data */
    UaByteString             m_continuationPoint;
    /** @brief The events for the requested time frame and event filter */
    UaHistoryEventFieldLists m_events;
};
typedef UaObjectArray<UaClientSdk::HistoryReadEventResult> HistoryReadEventResults;

/** \brief The UpdateDataDetail class contains the data for one item in a HistoryUpdate call for data.*/
class UACLIENT_EXPORT UpdateDataDetail
{
public:
    /** Creates a UpdateDataDetail object with default settings described with the parameters.*/
    UpdateDataDetail()
    {
        m_PerformInsertReplace  = OpcUa_PerformUpdateType_Update;
        m_isStructureUpdate     = OpcUa_False;
    };
    /** Destructor */
    ~UpdateDataDetail(){};

    /** @brief The NodeId of the variable node to update.
     *
     * The default value is null.
     */
    UaNodeId                m_nodeId;

    /** @brief The type of update.
     *
     * Possible values are
     * - OpcUa_PerformUpdateType_Insert  = 1
     * - OpcUa_PerformUpdateType_Replace = 2
     * - OpcUa_PerformUpdateType_Update  = 3
     *
     * The default value is OpcUa_PerformUpdateType_Update.
     */
    OpcUa_PerformUpdateType m_PerformInsertReplace;

    /** @brief The data values to update history with.
     *
     * The default value is an empty array.
     */
    UaDataValues            m_dataValues;

    /** @brief Flag indicating if a structure update should be applied.
     *
     * The default value is false.
     */
    OpcUa_Boolean           m_isStructureUpdate;
};
typedef UaObjectArray<UpdateDataDetail> UpdateDataDetails;

/** \brief The DeleteRawModifiedDetail class contains the data for one item in a HistoryUpdate call for data.*/
class UACLIENT_EXPORT DeleteRawModifiedDetail
{
public:
    /** Constructor */
    DeleteRawModifiedDetail()
    {
        m_IsDeleteModified = OpcUa_False;
    };
    /** Destructor */
    ~DeleteRawModifiedDetail(){};

    UaNodeId       m_nodeId;
    OpcUa_Boolean  m_IsDeleteModified;
    UaDateTime     m_startTime;
    UaDateTime     m_endTime;
};
typedef UaObjectArray<DeleteRawModifiedDetail> DeleteRawModifiedDetails;

/** \brief The DeleteRawModifiedDetail class contains the data for one item in a HistoryUpdate call for data.*/
class UACLIENT_EXPORT DeleteAtTimeDetail
{
public:
    /** Constructor */
    DeleteAtTimeDetail(){};
    /** Destructor */
    ~DeleteAtTimeDetail(){};

    UaNodeId        m_nodeId;
    UaDateTimeArray m_requestedTimes;
};
typedef UaObjectArray<DeleteAtTimeDetail> DeleteAtTimeDetails;

/** \brief The UpdateEventsDetail class contains the data for one item in a HistoryUpdate call for events.*/
class UACLIENT_EXPORT UpdateEventDetail
{
public:
    /** Constructor */
    UpdateEventDetail()
    {
        m_PerformInsertReplace  = OpcUa_PerformUpdateType_Update;
    };
    /** Destructor */
    ~UpdateEventDetail(){};

    UaNodeId                 m_nodeId;
    OpcUa_PerformUpdateType  m_PerformInsertReplace;
    UaEventFilter            m_eventFilter;
    UaHistoryEventFieldLists m_eventData;
};
typedef UaObjectArray<UpdateEventDetail> UpdateEventDetails;

/** \brief The DeleteRawModifiedDetail class contains the data for one item in a HistoryUpdate call for data.*/
class UACLIENT_EXPORT DeleteEventDetail
{
public:
    /** Constructor */
    DeleteEventDetail(){};
    /** Destructor */
    ~DeleteEventDetail(){};

    UaNodeId          m_nodeId;
    UaByteStringArray m_eventIds;
};
typedef UaObjectArray<DeleteEventDetail> DeleteEventDetails;

/** \brief The CallIn class contains the settings for a call request.*/
class UACLIENT_EXPORT CallIn
{
public:
    /** Constructor */
    CallIn()
    {
    };
    /** Destructor */
    ~CallIn(){};

    UaNodeId         objectId;
    UaNodeId         methodId;
    UaVariantArray   inputArguments;
};

/** \brief The CallOut class contains the settings for a call request.*/
class UACLIENT_EXPORT CallOut
{
public:
    /** Constructor */
    CallOut()
    {
    };
    /** Destructor */
    ~CallOut(){};

    UaStatus          callResult;
    UaStatusCodeArray inputArgumentResults;
    UaDiagnosticInfos inputArgumentDiagnosticInfos;
    UaVariantArray    outputArguments;
};

/** \brief The SubscriptionSettings class contains the settings for a Subscription. */
class UACLIENT_EXPORT SubscriptionSettings
{
public:
    /** Constructor */
    SubscriptionSettings()
    {
        publishingInterval         = 1000;
        lifetimeCount              = 1200;
        maxKeepAliveCount          = 5;
        maxNotificationsPerPublish = 0;
        priority                   = 0;
    };
    /** Destructor */
    ~SubscriptionSettings(){};

    /** \brief The publishingInterval defines the cyclic rate in milliseconds at which the subscription is being requested to return notifications to the client. */
    OpcUa_Double   publishingInterval;

    /** \brief The subscription has a lifetime that is defined by multiples of the publishingInterval.
    *
    * In other words if the client can't communicate with the server for a period of time shorter than
    * (lifetimeCount * publishingInterval), then the subscription is still available in the server. After
    * that, the server will delete the subscription. With a publishingInterval of 1000 ms, the default is
    * 20 minutes like the default lifetime of the session. Please make sure you are adjusting the lifetimeCount
    * if you change the publishingInterval.
    */
    OpcUa_UInt32   lifetimeCount;

    /** \brief If the server has no notifications pending for the period of time defined by
    * (MaxKeepAliveCount * PublishingInterval), the server will send a keep alive message to the client.
    *
    * Like that, client and server know that the other side is still alive even if no data is exchanged for some time.
    */
    OpcUa_UInt32   maxKeepAliveCount;

    /** \brief The maximum number of notifications that the client wishes to receive in a single publish response.
    *
    * This is one way for the client to limit the
    * memory consumption if that resources is very rare.
    */
    OpcUa_UInt32   maxNotificationsPerPublish;

    /** \brief Defines the relative priority of this subscription within the session.
    *
    * If multiple subscriptions need to send notifications to the client, the server will send notifications to the subscription with the highest priority first.
    */
    OpcUa_Byte     priority;
};
/*! @} */

class UaSession;
class UaSessionPrivate;
class UaSubscription;
class UaSubscriptionCallback;
class UaSubscriptionPrivate;
class UaDiscoveryPrivate;

/** @ingroup UaClientLibrary

 \brief UaSessionCallback defines the callback interface for the UaSession class.

 This callback interface needs to be implemented by the user of the UaSession class to receive
 connection status change callbacks from the Client SDK. The interface provides also the callback
 functions for the asynchronous service calls. Only the callbacks for used asynchronous calls need
 to be implemented by the user of the SDK.

 Callbacks from the SDK APIs are coming from worker threads and not from the thread that was used to
 connect to the server. It is in the responsibility of the user of the client API to synchronize the
 data provided by the callbacks with a GUI main thread if this is necessary. You should never execute
 any long lasting operations in the callback. Calling UaSession::disconnect() from within callback is explicitly
 not allowed and leads to a deadlock in the client application.

 After UaSession::disconnect() is called, no more callbacks will be sent for this UaSession object.
 The disconnect blocks until all outstanding service calls are finished and results are returned.
 This includes any asynchronous service calls and outstanding callbacks to the client application.

 It is not allowed to block the execution of callbacks when UaSession::disconnect() is called. This
 will also lead to a deadlock in the client application.
*/
class UACLIENT_EXPORT UaSessionCallback
{
public:
    UaSessionCallback();
    virtual ~UaSessionCallback();

    /** \brief Send changed status.
     *
     * This callback function is called by the SDK whenever the connection status changes. This is typically
     * the case if UaSession::connect() or UaSession::disconnect() are called or if the connection monitoring
     * detects a connection interruption or was able to re-establish the connection.
     *
     * There is normally no action necessary by the application using the UaSession object other than not calling
     * services if the status is not connected. The only case that may require special actions is the status
     * NewSessionCreated. In these cases the SDK was not able to reuse the old session and created a new session
     * during reconnect. This requires to redo register nodes for the new session or to read the namespace array.
     */
    virtual void connectionStatusChanged(
        OpcUa_UInt32             clientConnectionId,     //!< [in] Client defined handle of the affected session
        UaClient::ServerStatus   serverStatus            //!< [in] New connection status. See UaClient::ServerStatus for more details.
        ) = 0;

    /** \brief Callback for reporting errors during connection establishment to the application.
     *
     * The callback UaSessionCallback::connectionStatusChanged indicates the overall status of the connection but does not report
     * detailed error information. The connectError callback can be used to get more information about the error scenario. This includes
     * errors during reconnect attempts after a connection interruption.
     *
     * Most of the errors are returned from the communication stack or the OPC UA server but some of the errors like server certificate
     * validation errors are reported by the client SDK. If clientSideError is true, the error was created inside the Client SDK,
     * these errors can be overridden by returning true. The default implementation always returns false.
     *
     * @return true if a Client SDK error should be skipped, false otherwise. The return code is ignored by the SDK if the error was
     *         not created by the Client SDK
     */
    virtual bool connectError(
        OpcUa_UInt32                    clientConnectionId, //!< [in] Client defined handle of the affected session
        UaClient::ConnectServiceType    serviceType, //!< [in] The failing connect step
        const UaStatus&                 error,       //!< [in] Status code for the error situation
        bool                            clientSideError //!< [in] Flag indicating if the bad status was created in the Client SDK
        );

    /** \brief Callback for verifying the server's SSL certificate.
     * The application must return true if the certificate is trusted. The application must return false if the certificate is not trusted.
     */
    virtual bool sslCertificateValidationFailed(
        OpcUa_UInt32        clientConnectionId, //!< [in] Client defined handle of the affected session
        const UaStatusCode &uaStatus,          //!< [in] Status code for the error situation
        const UaByteString &bsSSLCertificate //!< [in] The SSL certificate that failed verification
        );

    /** \brief Send read results.
     * This is the callback function for calls to UaSession::beginRead.
     */
    virtual void readComplete(
        OpcUa_UInt32             transactionId,     //!< [in] Client defined transaction id for the read
        const UaStatus&          result,            //!< [in] Overall read service result
        const UaDataValues&      values,            //!< [in] List of read operation results contained in OpcUa_DataValue structures
        const UaDiagnosticInfos& diagnosticInfos    //!< [in] List of diagnostic information
        );

    /** \brief Send write results.
     * This is the callback function for calls to UaSession::beginWrite.
     */
    virtual void writeComplete(
        OpcUa_UInt32             transactionId,     //!< [in] Client defined transaction id for the write
        const UaStatus&          result,            //!< [in] Overall write service result
        const UaStatusCodeArray& results,           //!< [in] List of write operation results
        const UaDiagnosticInfos& diagnosticInfos    //!< [in] List of diagnostic information
        );

    /** \brief Send call result.
     * This is the callback function for calls to UaSession::beginCall.
     */
    virtual void callComplete(
        OpcUa_UInt32             transactionId,     //!< [in] Client defined transaction id for the call
        const UaStatus&          result,            //!< [in] Overall call result
        const CallOut&           callResponse       //!< [in] Output arguments and input argument results. See CallOut for more details
        );

    /** \brief Send addNodes result.
     * This is the callback function for calls to UaSession::beginAddNodes.
     */
    virtual void addNodesComplete(
        OpcUa_UInt32             transactionId,     //!< [in] Client defined transaction id for the addNodes
        const UaStatus&          result,            //!< [in] Overall addNodes service result
        const UaAddNodesResults& results,           //!< [in] List of add nodes operation results
        const UaDiagnosticInfos& diagnosticInfos    //!< [in] List of diagnostic information
        );

    /** \brief Send addReferences result.
     * This is the callback function for calls to UaSession::beginAddReferences.
     */
    virtual void addReferencesComplete(
        OpcUa_UInt32             transactionId,     //!< [in] Client defined transaction id for the addReferences
        const UaStatus&          result,            //!< [in] Overall addReferences service result
        const UaStatusCodeArray& results,           //!< [in] List of add references operation results
        const UaDiagnosticInfos& diagnosticInfos    //!< [in] List of diagnostic information
        );

    /** \brief Send deleteNodes result.
     * This is the callback function for calls to UaSession::beginDeleteNodes.
     */
    virtual void deleteNodesComplete(
        OpcUa_UInt32             transactionId,     //!< [in] Client defined transaction id for the deleteNodes
        const UaStatus&          result,            //!< [in] Overall deleteNodes service result
        const UaStatusCodeArray& results,           //!< [in] List of delete nodes operation results
        const UaDiagnosticInfos& diagnosticInfos    //!< [in] List of diagnostic information
        );

    /** \brief Send deleteReferences result.
     * This is the callback function for calls to UaSession::beginDeleteReferences.
     */
    virtual void deleteReferencesComplete(
        OpcUa_UInt32             transactionId,     //!< [in] Client defined transaction id for the deleteReferences
        const UaStatus&          result,            //!< [in] Overall deleteReferences service result
        const UaStatusCodeArray& results,           //!< [in] List of delete references operation results
        const UaDiagnosticInfos& diagnosticInfos    //!< [in] List of diagnostic information
        );
    /** \brief Send historyReadRawModified result.
     * This is the callback function for calls to UaSession::beginHistoryReadRawModified.
     */
    virtual void historyReadRawModifiedComplete(
        OpcUa_UInt32                    transactionId,     //!< [in] Client defined transaction id for the historyReadRawModified
        const UaStatus&                 result,            //!< [in] Overall historyReadRawModified service result
        const HistoryReadDataResults&   results,           //!< [in] Result data for the requested nodes and time interval. A continuation point is included for a node if not all results could be returned.
        const UaDiagnosticInfos&        diagnosticInfos    //!< [in] List of diagnostic information
        );
    /** \brief Send historyReadProcessed result.
     * This is the callback function for calls to UaSession::beginHistoryReadProcessed.
     */
    virtual void historyReadProcessedComplete(
        OpcUa_UInt32                    transactionId,     //!< [in] Client defined transaction id for the historyReadProcessed
        const UaStatus&                 result,            //!< [in] Overall historyReadProcessed service result
        const HistoryReadDataResults&   results,           //!< [in] Result data for the requested nodes, time domain and aggregates. A continuation point is included for a node if not all results could be returned or processed before the timeout expired.
        const UaDiagnosticInfos&        diagnosticInfos    //!< [in] List of diagnostic information
        );
    /** \brief Send historyReadAtTime result.
     * This is the callback function for calls to UaSession::beginHistoryReadAtTime.
     */
    virtual void historyReadAtTimeComplete(
        OpcUa_UInt32                    transactionId,     //!< [in] Client defined transaction id for the historyReadAtTime
        const UaStatus&                 result,            //!< [in] Overall historyReadAtTime service result
        const HistoryReadDataResults&   results,           //!< [in] Result data for the requested nodes and timestamps
        const UaDiagnosticInfos&        diagnosticInfos    //!< [in] List of diagnostic information
        );
    /** \brief Send historyReadEvent result.
     * This is the callback function for calls to UaSession::beginHistoryReadEvent.
     */
    virtual void historyReadEventComplete(
        OpcUa_UInt32                    transactionId,     //!< [in] Client defined transaction id for the historyReadEvent
        const UaStatus&                 result,            //!< [in] Overall historyReadEvent service result
        const HistoryReadEventResults&  results,           //!< [in] The event history for each notifier
        const UaDiagnosticInfos&        diagnosticInfos    //!< [in] List of diagnostic information
        );
    /** \brief Send historyUpdateData result.
     * This is the callback function for calls to UaSession::beginHistoryUpdateData.
     */
    virtual void historyUpdateDataComplete(
        OpcUa_UInt32                    transactionId,     //!< [in] Client defined transaction id for the historyUpdateData
        const UaStatus&                 result,            //!< [in] Overall historyUpdateData service result
        const UaHistoryUpdateResults&   results,           //!< [in] The list of update operation results
        const UaDiagnosticInfos&        diagnosticInfos    //!< [in] List of diagnostic information
        );
    /** \brief Send historyDeleteRawModified result.
     * This is the callback function for calls to UaSession::beginHistoryDeleteRawModified.
     */
    virtual void historyDeleteRawModifiedComplete(
        OpcUa_UInt32                    transactionId,     //!< [in] Client defined transaction id for the historyDeleteRawModified
        const UaStatus&                 result,            //!< [in] Overall historyDeleteRawModified service result
        const UaHistoryUpdateResults&   results,           //!< [in] The list of delete operation results
        const UaDiagnosticInfos&        diagnosticInfos    //!< [in] List of diagnostic information
        );
    /** \brief Send historyDeleteAtTime result.
     * This is the callback function for calls to UaSession::beginHistoryDeleteAtTime.
     */
    virtual void historyDeleteAtTimeComplete(
        OpcUa_UInt32                    transactionId,     //!< [in] Client defined transaction id for the historyDeleteAtTime
        const UaStatus&                 result,            //!< [in] Overall historyDeleteAtTime service result
        const UaHistoryUpdateResults&   results,           //!< [in] The list of delete operation results
        const UaDiagnosticInfos&        diagnosticInfos    //!< [in] List of diagnostic information
        );
    /** \brief Send historyUpdateEvents result.
     * This is the callback function for calls to UaSession::beginHistoryUpdateEvents.
     */
    virtual void historyUpdateEventsComplete(
        OpcUa_UInt32                    transactionId,     //!< [in] Client defined transaction id for the historyUpdateEvents
        const UaStatus&                 result,            //!< [in] Overall historyUpdateEvents service result
        const UaHistoryUpdateResults&   results,           //!< [in] The list of update operation results
        const UaDiagnosticInfos&        diagnosticInfos    //!< [in] List of diagnostic information
        );
    /** \brief Send historyDeleteEvents result.
     * This is the callback function for calls to UaSession::beginHistoryDeleteEvents.
     */
    virtual void historyDeleteEventsComplete(
        OpcUa_UInt32                    transactionId,     //!< [in] Client defined transaction id for the historyDeleteEvents
        const UaStatus&                 result,            //!< [in] Overall historyDeleteEvents service result
        const UaHistoryUpdateResults&   results,           //!< [in] The list of delete operation results
        const UaDiagnosticInfos&        diagnosticInfos    //!< [in] List of diagnostic information
        );
};

/** @ingroup UaClientLibrary
 \brief UaSubscriptionCallback defines the callback interface for the UaSubscription class.

 This callback interface needs to be implemented by the user of the UaSubscription class to receive
 data change, event and subscription status change callbacks from the Client SDK. The interface
 provides also a callback function for keep alive calls from the server. This function needs
 to be implemented only by users of the SDK interested in the keep alive callbacks. The status of the
 subscription is normally monitored by the SDK and changes are indicated by sending subscription status
 changed callbacks.

 In cases of Subscription errors the user of the SDK is responsible for creating a new subscription since
 the SDK does not keep the information to recreate the Subscription to not increase memory consumption.
 The necessary information needs to be kept also by the client application anyway. To duplicate this information
 in the SDK consumes too much memory.

 Callbacks from the SDK APIs are coming from different worker threads and not from the thread that was used to
 connect to the server. It is in the responsibility of the user of the client API to synchronize the
 data provided by the callbacks with a GUI main thread if this is necessary.

 Publish responses are processed in worker threads from a thread pool. A Publish response may trigger one or more
 callbacks including dataChange newEvents, notificationsMissing and keepAlive. The Publish responses are processed
 in the order they are received by the stack. For the UA TCP protocol this normally ensures that the sequence numbers
 are processed in order. The processing of a Publish response will not start if another Publish response for the same
 UaSubscription object is still processed and callbacks are not returned by the client application.
*/
class UACLIENT_EXPORT UaSubscriptionCallback
{
public:
    UaSubscriptionCallback();
    virtual ~UaSubscriptionCallback();

    /** \brief Send subscription state change.

      This callback function informs the client if the status of a subscription changes. This can happen after a connection error that
      lasted longer than the lifetime of the subscription. The lifetime is calculated from PublishingInterval x LifetimeCount.
      A client must create a new subscription to continue data or event monitoring if this callback indicates a bad status for the subscription.
      UaSession::deleteSubscription should be called even if the subscription is no longer valid in the server to clear
      the client side subscription object.
    */
    virtual void subscriptionStatusChanged(
        OpcUa_UInt32      clientSubscriptionHandle,     //!< [in] Client defined handle of the affected subscription. The handle can be ignored if the callback object is only used by one subscription.
        const UaStatus&   status                        //!< [in] Status code indicating the error status of the subcription
        ) = 0;

    /** \brief Send subscription keep alive.
    *
    * This callback function provides the keep alive messages sent by the server if no changed data or events are available.
    *
    * The frequency of calls to this callback function depends on the settings in SubscriptionSettings::maxKeepAliveCount and
    * the availability of data and events.
    */
    virtual void keepAlive(
        OpcUa_UInt32 clientSubscriptionHandle   //!< [in] Client defined handle of the affected subscription. The handle can be ignored if the callback object is only used by one subscription.
        );

    /** \brief Informs the client about missing notification messages.
    *
    *  The client SDK monitors the sequence numbers of the received data and event notifications and reports
    *  gaps in the sequence numbers using this callback method. The client can use the UaSubscription::republish
    *  method to request the missing notifications.
    *
    * The notificationsMissing is called from a worker thread but it should not be blocked by the application since this will block other callbacks like dataChange
    * contained in the same Publish response and also blocks more Publish responses received for the same UaSubscription object. See the general description of
    * the callback class for more details on Publish response processing.
    */
    virtual void notificationsMissing(
        OpcUa_UInt32 clientSubscriptionHandle,  //!< [in] Client defined handle of the affected subscription. The handle can be ignored if the callback object is only used by one subscription.
        OpcUa_UInt32 previousSequenceNumber,    //!< [in] Sequence number of the previously received notification
        OpcUa_UInt32 newSequenceNumber          //!< [in] Sequence number of the new notification
        );

    /** \brief Send changed data.
    *
    * This callback function provides the data notification for a subscription.
    *
    * Data changes may arrive for monitored items before the creation of the monitored item is completed and the createMonitoredItems call
    * returns. The client application must be prepared for that and ClientHandles passed in to createMonitoredItems must be valid and usable
    * before createMonitoredItems returns.
    *
    * Data changes may also arrive after monitored items are deleted, sampling is turned off, or after the publishing is disabled.
    *
    * This callback is normally not called faster than configured in SubscriptionSettings::publishingInterval but this is controlled by the
    * OPC UA Server and not by the client SDK. If the number of notifications in one publishing interval exceeds the setting
    * SubscriptionSettings::maxNotificationsPerPublish, the OPC UA Server will send more than one Publish response and this dataChange may be
    * called more than one time in the publishingInterval.
    *
    * If no new data is available in a publishingInterval, no dataChange is called and a UaSubscriptionCallback::keepAlive callback may be called
    * depending on the settings in SubscriptionSettings::maxKeepAliveCount.
    *
    * The dataChange is called from a worker thread but it should not be blocked by the application since this will block other callbacks like newEvents
    * contained in the same Publish response and also blocks more Publish responses received for the same UaSubscription object. See the general description of
    * the callback class for more details on Publish response processing.
    */
    virtual void dataChange(
        OpcUa_UInt32               clientSubscriptionHandle,    //!< [in] Client defined handle of the affected subscription. The handle can be ignored if the callback object is only used by one subscription.
        const UaDataNotifications& dataNotifications,           //!< [in] List of data notifications sent by the server
        const UaDiagnosticInfos&   diagnosticInfos              //!< [in] List of diagnostic info related to the data notifications. This list can be empty.
        ) = 0;

    /** \brief Send new events.
    *
    * This callback function provides the event notification for a subscription.
    *
    * New events may arrive for monitored items before the creation of the monitored item is completed and the createMonitoredItems call
    * returns. The client application must be prepared for that and ClientHandles passed in to createMonitoredItems must be valid and usable
    * before createMonitoredItems returns.
    *
    * New events may also arrive after monitored items are deleted, sampling is turned off, or after the publishing is disabled.
    *
    * This callback is normally not called faster than configured in SubscriptionSettings::publishingInterval but this is controlled by the
    * OPC UA Server and not by the client SDK. If the number of notifications in one publishing interval exceeds the setting
    * SubscriptionSettings::maxNotificationsPerPublish, the OPC UA Server will send more than one Publish response and this newEvents may be
    * called more than one time in the publishingInterval.
    *
    * If no new events are available in a publishingInterval, no newEvents is called and a UaSubscriptionCallback::keepAlive callback may be called
    * depending on the settings in SubscriptionSettings::maxKeepAliveCount.
    *
    * The newEvents is called from a worker thread but it should not be blocked by the application since this will block other callbacks like dataChange
    * contained in the same Publish response and also blocks more Publish responses received for the same UaSubscription object. See the general description of
    * the callback class for more details on Publish response processing.
    */
    virtual void newEvents(
        OpcUa_UInt32                clientSubscriptionHandle,   //!< [in] Client defined handle of the affected subscription. The handle can be ignored if the callback object is only used by one subscription.
        UaEventFieldLists&          eventFieldList              //!< [in] List of event notifications sent by the server
        ) = 0;

    /** \brief Send createMonitoredItems results.
     * This is the callback function for calls to UaSubscription::beginCreateMonitoredItems.
     */
    virtual void createMonitoredItemsComplete(
        OpcUa_UInt32                        transactionId,      //!< [in] Client defined transaction id for the createMonitoredItems
        const UaStatus&                     result,             //!< [in] Overall createMonitoredItems service result
        const UaMonitoredItemCreateResults& createResults,      //!< [in] List of createMonitoredItems operation results
        const UaDiagnosticInfos&            diagnosticInfos     //!< [in] List of diagnostic information
        );

    /** \brief Send modifyMonitoredItems results.
     * This is the callback function for calls to UaSubscription::beginModifyMonitoredItems.
     */
    virtual void modifyMonitoredItemsComplete(
        OpcUa_UInt32                        transactionId,      //!< [in] Client defined transaction id for the modifyMonitoredItems
        const UaStatus&                     result,             //!< [in] Overall modifyMonitoredItems service result
        const UaMonitoredItemModifyResults& modifyResults,      //!< [in] List of modifyMonitoredItems operation results
        const UaDiagnosticInfos&            diagnosticInfos     //!< [in] List of diagnostic information
        );

    /** \brief Send setMonitoringMode results.
     * This is the callback function for calls to UaSubscription::beginSetMonitoringMode.
     */
    virtual void setMonitoringModeComplete(
        OpcUa_UInt32             transactionId,     //!< [in] Client defined transaction id for the setMonitoringMode
        const UaStatus&          result,            //!< [in] Overall setMonitoringMode service result
        const UaStatusCodeArray& setModeResults,    //!< [in] List of setMonitoringMode operation results
        const UaDiagnosticInfos& diagnosticInfos    //!< [in] List of diagnostic information
        );

    /** \brief Send deleteMonitoredItems results.
     * This is the callback function for calls to UaSubscription::beginDeleteMonitoredItems.
     */
    virtual void deleteMonitoredItemsComplete(
        OpcUa_UInt32             transactionId,     //!< [in] Client defined transaction id for the deleteMonitoredItems
        const UaStatus&          result,            //!< [in] Overall deleteMonitoredItems service result
        const UaStatusCodeArray& deleteResults,     //!< [in] List of deleteMonitoredItems operation results
        const UaDiagnosticInfos& diagnosticInfos    //!< [in] List of diagnostic information
        );
};
}

#if defined(_MSC_VER)
#  if (defined(WIN32) && _MSC_VER < 1400)
#    define UACLIENTSDK_USE_TYPEDEF
#  endif
#elif (defined(__linux__) && defined(__arm__)) || defined(ANDROID)
#  define UACLIENTSDK_USE_TYPEDEF
#endif

#if defined(UACLIENTSDK_USE_TYPEDEF)
typedef UACLIENT_EXPORT UaObjectArray<UaClientSdk::UpdateDataDetail> UaUpdateDataDetailArray;
typedef UACLIENT_EXPORT UaObjectArray<UaClientSdk::HistoryReadDataResult> UaHistoryReadDataResultArray;
typedef UACLIENT_EXPORT UaObjectArray<UaClientSdk::DeleteRawModifiedDetail> UaDeleteRawModifiedDetailArray;
typedef UACLIENT_EXPORT UaObjectArray<UaClientSdk::DeleteAtTimeDetail> UaDeleteAtTimeDetailArray;
#else // defined(UACLIENTSDK_USE_TYPEDEF)
template class UACLIENT_EXPORT UaObjectArray<UaClientSdk::UpdateDataDetail>;
template class UACLIENT_EXPORT UaObjectArray<UaClientSdk::HistoryReadDataResult>;
template class UACLIENT_EXPORT UaObjectArray<UaClientSdk::DeleteRawModifiedDetail>;
template class UACLIENT_EXPORT UaObjectArray<UaClientSdk::DeleteAtTimeDetail>;
#endif // defined(UACLIENTSDK_USE_TYPEDEF)

#endif // UACLIENTSDK_H

