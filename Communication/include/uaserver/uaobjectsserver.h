/******************************************************************************
** uaobjectsserver.h
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
** Project: C++ OPC Server SDK core module
**
** Description: OPC UA server server object class.
**
******************************************************************************/
#ifndef __UAOBJECTSSERVER_H__
#define __UAOBJECTSSERVER_H__

#include "uabasenodes.h"
#include "uaobjecttypes.h"
#include "opcua_basedatavariabletype.h"
#if SUPPORT_Historical_Access
#include "opcua_historyservercapabilitiestype.h"
#endif // SUPPORT_Historical_Access
#include "userdatabase.h"
#if SUPPORT_Method_Server_Facet && OPCUA_SUPPORT_PKI
#include "opcua_serverconfigurationtype.h"
#endif // SUPPORT_Method_Server_Facet && OPCUA_SUPPORT_PKI

class SERVER_CORE_EXPORT NodeManagerConfig;
class SERVER_CORE_EXPORT UaPropertyCache;
class SERVER_CORE_EXPORT ServerConfig;
class SERVER_CORE_EXPORT UaDataVariableCache;
class SERVER_CORE_EXPORT UaObjectServerCapabilities;

class UaServerStatusDataType;

/** Management class for the Server object node and its children
 *
 * This class represents the Server object with the children for namespace array, server status
 * server diagnostics and server capability nodes.
 */
class SERVER_CORE_EXPORT UaObjectServer :
    public UaObjectBase
{
    UA_DISABLE_COPY(UaObjectServer);
protected:
    /** destruction */
    virtual ~UaObjectServer();
public:
    /** construction */
    UaObjectServer(const UaString& name, const UaNodeId& nodeId, const UaString& defaultLocaleId);
    static void createTypes();
    static void clearStaticMembers();

    UaStatus startUp(ServerConfig* pServerConfig, NodeManagerConfig* pNodeManagerConfig);
    UaStatus shutDown();

    //- Interface UaObject -----------------------------------------------------------------
    UaNodeId                typeDefinitionId() const;
    OpcUa_Byte              eventNotifier() const;
    //- Interface UaObject -----------------------------------------------------------------
    void setEventNotifier(OpcUa_Byte eventNotifier);

    //- Interface UaReferenceLists ---------------------------------------------------------
    /** Get the UaNode.
     *  @return the node owning the reference list.
     */
    UaNode* getUaNode() const {return (UaNode*)this;};
    //- Interface UaReferenceLists ---------------------------------------------------------

    // Namespace handling
    UaStatus setNamespaces(UaStringArray& sNamespaces);
    UaStatus getNamespaces(UaStringArray& sNamespaces);

    // Inform the server object about the shutdown of the server
    void startServerShutDown(
        OpcUa_Int32            secondsTillShutdown,
        const UaLocalizedText& shutdownReason);
    void startServerShutDown(
        OpcUa_Int32            secondsTillShutdown,
        const UaLocalizedTextArray& shutdownReason);

    // Change state information
    void changeServerState(OpcUa_ServerState newState);

    // Get and set service level
    void changeServiceLevel(OpcUa_Byte serviceLevel, OpcUa_Byte changeMask);
    OpcUa_Byte serviceLevel() const;

    void setEstimatedReturnTime(const UaDateTime& time);

#if SUPPORT_Historical_Access
    OpcUa::HistoryServerCapabilitiesType* getHistoryServerCapabilities();
#endif // SUPPORT_Historical_Access
#if SUPPORT_Method_Server_Facet && OPCUA_SUPPORT_PKI
    void createServerConfiguration(ServerConfig* pServerConfig);
#endif // SUPPORT_Method_Server_Facet && OPCUA_SUPPORT_PKI

private:
    static bool          s_typeNodesCreated;
    UaMutex              m_mutex;
    OpcUa_Byte           m_eventNotifier;

    UaPropertyCache*     m_pServerArray;
    UaPropertyCache*     m_pNamespaceArray;
    UaPropertyCache*     m_pServiceLevel;
    UaPropertyCache*     m_pEstimatedReturnTime;
    OpcUa::BaseDataVariableType* m_pServerState;
    OpcUa::BaseVariableTypeGeneric* m_pServerStatus;
    UaDataVariableCache* m_pSecondsTillShutdown;
    OpcUa::BaseVariableTypeLocalizedTextValue* m_pShutdownReason;
#if SUPPORT_Historical_Access
    OpcUa::HistoryServerCapabilitiesType* m_pHistoryServerCapabilities;
#endif // SUPPORT_Historical_Access
#if SUPPORT_Method_Server_Facet && OPCUA_SUPPORT_PKI
    OpcUa::ServerConfigurationType* m_pServerConfiguration;
#endif // SUPPORT_Method_Server_Facet && OPCUA_SUPPORT_PKI
    UaObjectServerCapabilities* m_pServerCapabilities;
    NodeManagerConfig*          m_pNodeManagerConfig;
};

/** Management class for the Server capability node and its children
 *
 * This class represents the Server capabilities with the children like aggregate functions
 * history capabilies, modeling rules, operation limitits and other resource information
 */
class SERVER_CORE_EXPORT UaObjectServerCapabilities : public UaObjectBase
{
    UA_DISABLE_COPY(UaObjectServerCapabilities);
protected:
    /** destruction */
    virtual ~UaObjectServerCapabilities();
public:
    /** construction */
    UaObjectServerCapabilities(const UaString& name, const UaNodeId& newNodeId, const UaString& defaultLocaleId, NodeManagerConfig* pNodeConfig, ServerConfig* pServerConfig);
    static void createTypes();
    static void clearStaticMembers();

    //- Interface UaObject ----------------------------------------------------------------
    /** Get the object type NodeId for the server object.
     *  @return the object type NodeId for the server object.
     */
    UaNodeId        typeDefinitionId() const;

    /** Provides the information if the object can be used to subscribe for events.
     *  @return the EventNotifier attribute value for the Object.
     */
    OpcUa_Byte      eventNotifier() const;

    /** Get the MethodManager interface of an Object.
     *  @param pMethod a pointer to the Method of the actual Object.
     *  @return the MethodManager interface of an Object.
     */
    MethodManager*  getMethodManager(UaMethod* pMethod) const;
    //- Interface UaObject ----------------------------------------------------------------

private:
    static bool  s_typeNodesCreated;
    UaMutex      m_mutex;
};

/** UaModelingRule
 *  @brief Derived from UaObjectBase.
 *  It is not possible to create shallow copies of this Class.
 */
class SERVER_CORE_EXPORT UaModelingRule : public UaObjectBase
{
    UA_DISABLE_COPY(UaModelingRule);
protected:
    /** destruction */
    virtual ~UaModelingRule();
public:
    /** construction */
    UaModelingRule(const UaString& name, const UaNodeId& newNodeId, const UaString& defaultLocaleId, NodeManagerConfig* pNodeConfig, ServerConfig* pServerConfig);

    //- Interface UaObject ----------------------------------------------------------------
    /** Get the object type NodeId for the server object.
     *  @return the object type NodeId for the server object.
     */
    UaNodeId        typeDefinitionId() const;

    /** Provides the information if the object can be used to subscribe for events.
     *  @return the EventNotifier attribute value for the Object.
     */
    OpcUa_Byte      eventNotifier() const;

    /** Get the MethodManager interface of an Object.
     *  @param pMethod a pointer to the Method of the actual Object.
     *  @return the MethodManager interface of an Object.
     */
    MethodManager*  getMethodManager(UaMethod* pMethod) const;
    //- Interface UaObject ----------------------------------------------------------------

private:
    UaMutex                m_mutex;
};

/** Management class for the Server diagnostic node and its children
 *
 * This class represents the Server diagnostics with the children like server diagnostics
 * session diagnostics and subscription diagnostics
 */
class SERVER_CORE_EXPORT UaObjectServerDiagnostic : public UaObjectBase
{
    UA_DISABLE_COPY(UaObjectServerDiagnostic);
protected:
    /** destruction */
    virtual ~UaObjectServerDiagnostic();
public:
    /** construction */
    UaObjectServerDiagnostic(const UaString& name, const UaNodeId& newNodeId, const UaString& defaultLocaleId, NodeManagerConfig* pNodeConfig, ServerConfig* pServerConfig);
    static void createTypes();
    static void clearStaticMembers();

    //- Interface UaObject ----------------------------------------------------------------
    /** Get the object type NodeId for the server object.
     *  @return the object type NodeId for the server object.
     */
    UaNodeId        typeDefinitionId() const;

    /** Provides the information if the object can be used to subscribe for events.
     *  @return the EventNotifier attribute value for the Object.
     */
    OpcUa_Byte      eventNotifier() const;

    /** Get the MethodManager interface of an Object.
     *  @param pMethod a pointer to the Method of the actual Object.
     *  @return the MethodManager interface of an Object.
     */
    MethodManager*  getMethodManager(UaMethod* pMethod) const;
    //- Interface UaObject ----------------------------------------------------------------

private:
    static bool  s_typeNodesCreated;
    UaMutex      m_mutex;
};

/** Management class for the SessionsDiagnosticsSummary node and its children
*
* This class represents the SessionsDiagnosticsSummary with the children like SessionDiagnosticsArray
* SessionSecurityDiagnosticsArray and the SessionDiagnosticsObjects
*/
class SERVER_CORE_EXPORT UaObjectSessionsDiagnosticsSummary : public UaObjectBase
{
    UA_DISABLE_COPY(UaObjectSessionsDiagnosticsSummary);
protected:
    /** destruction */
    virtual ~UaObjectSessionsDiagnosticsSummary();
public:
    /** construction */
    UaObjectSessionsDiagnosticsSummary(const UaString& name, const UaNodeId& newNodeId, const UaString& defaultLocaleId, NodeManagerConfig* pNodeConfig, ServerConfig* pServerConfig);
    static void createTypes();
    static void clearStaticMembers();

    //- Interface UaObject ----------------------------------------------------------------
    /** Get the object type NodeId for the SessionsDiagnosticsSummaryType.
    *  @return the object type NodeId for the SessionsDiagnosticsSummaryType.
    */
    UaNodeId        typeDefinitionId() const;

    /** Provides the information if the object can be used to subscribe for events.
    *  @return the EventNotifier attribute value for the Object.
    */
    OpcUa_Byte      eventNotifier() const;

    /** Get the MethodManager interface of an Object.
    *  @param pMethod a pointer to the Method of the actual Object.
    *  @return the MethodManager interface of an Object.
    */
    MethodManager*  getMethodManager(UaMethod* pMethod) const;
    //- Interface UaObject ----------------------------------------------------------------

private:
    static bool  s_typeNodesCreated;
};

/** UaObjectVendorServerInfo
 *  @brief Derived from UaObjectBase.
 *  It is not possible to create shallow copies of this Class.
 */
class SERVER_CORE_EXPORT UaObjectVendorServerInfo : public UaObjectBase
{
    UA_DISABLE_COPY(UaObjectVendorServerInfo);
protected:
    /** destruction */
    virtual ~UaObjectVendorServerInfo();
public:
    /** construction */
    UaObjectVendorServerInfo(const UaString& name, const UaNodeId& newNodeId, const UaString& defaultLocaleId, NodeManagerConfig* pNodeConfig, ServerConfig* pServerConfig);

    //- Interface UaObject ----------------------------------------------------------------
    /** Get the object type NodeId for the server object.
     *  @return the object type NodeId for the server object.
     */
    UaNodeId        typeDefinitionId() const;

    /** Provides the information if the object can be used to subscribe for events.
     *  @return the EventNotifier attribute value for the Object.
     */
    OpcUa_Byte      eventNotifier() const;

    /** Get the MethodManager interface of an Object.
     *  @param pMethod a pointer to the Method of the actual Object.
     *  @return the MethodManager interface of an Object.
     */
    MethodManager*  getMethodManager(UaMethod* pMethod) const;
    //- Interface UaObject ----------------------------------------------------------------

private:
    UaMutex                m_mutex;
};

class SERVER_CORE_EXPORT UserDataServerStatus : public UserDataVariableGetValue
{
    UA_DISABLE_COPY(UserDataServerStatus);
    UserDataServerStatus();
public:
    UserDataServerStatus(UaServerStatusDataType& serverStatus);
    virtual ~UserDataServerStatus();

    void setShutDown(OpcUa_Int32 secondsTillShutdown, const UaLocalizedText& shutdownReason);
    void setServerState(OpcUa_ServerState newState);

    virtual OpcUa_StatusCode getValue(UaVariant& value) const;
private:
    mutable UaMutex m_mutex;
    UaVariant       m_uvServerStatus;
};

#endif // __UAOBJECTSSERVER_H__


