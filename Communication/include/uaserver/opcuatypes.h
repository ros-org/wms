/******************************************************************************
** opcuatypes.h
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
** Description: OPC server core module base types.
**
******************************************************************************/
#ifndef OPCUATYPES_H
#define OPCUATYPES_H

#ifdef _WIN32
# ifdef _SERVER_CORE_BUILD_DLL
#  define SERVER_CORE_EXPORT __declspec(dllexport)
# elif defined _SERVER_CORE_USE_DLL
#  define SERVER_CORE_EXPORT __declspec(dllimport)
# else
#  define SERVER_CORE_EXPORT
# endif
#else
# define SERVER_CORE_EXPORT
#endif

#include "opcua_proxystub.h"
#include "statuscode.h"
#include "uastring.h"
#include "uavariant.h"
#include "uamutex.h"
#include "uadatetime.h"
#include <map>

class SERVER_CORE_EXPORT Session;
class SERVER_CORE_EXPORT SessionUserContext;
class SERVER_CORE_EXPORT NodeAccessInfo;

/** @brief This class provides the context for a Service invocation.

* This context contains the Session object used for the Service call and the general client side settings like the timeout hint and
* the level of requested diagnostic information.
*/
class SERVER_CORE_EXPORT ServiceContext
{
public:
    // construction / destruction
    ServiceContext();
    virtual ~ServiceContext();
    ServiceContext(const ServiceContext &);
    ServiceContext& operator=(const ServiceContext&);

    /**  Returns the Session object.
    *
    * The Session object is reference counted. The Session is valid until the client has closed the Session or it timed out.
    * If the Session pointer is stored in user objects, these objects must add their own reference.
    */
    inline Session*     pSession() const {return m_pSession;}

    // Returns the SessionUserContext object.
    const SessionUserContext* pSessionUserContext() const;

    /**  Returns the timeout hint in milliseconds set by the client for this service invocation.
    * A client side stack returns an timeout error to the caller after the timeout expired.
    */
    inline OpcUa_UInt32 timeoutHint() const {return m_timeoutHint;}

    /** Returns the timestamp the server received this service invocation. */
    inline UaDateTime   receiveTime() const {return m_receiveTime;}

    /**  Returns the timestamp set by the client for this service invocation.*/
    inline UaDateTime   clientTime() const {return m_clientTime;}

    /**  Returns the client requested diagnostic level for this service invocation.
    * Bit mask that defines the diagnostic information to be returned from the server.<br>
    * Bit Value --- Diagnostics to return -------------- Define<br>
    * 0x0000 0001 - ServiceLevel / SymbolicId ---------- OpcUa_DiagnosticsMasks_ServiceSymbolicId<br>
    * 0x0000 0002 - ServiceLevel / LocalizedText ------- OpcUa_DiagnosticsMasks_ServiceLocalizedText<br>
    * 0x0000 0004 - ServiceLevel / AdditionalInfo ------ OpcUa_DiagnosticsMasks_ServiceAdditionalInfo<br>
    * 0x0000 0008 - ServiceLevel / Inner StatusCode ---- OpcUa_DiagnosticsMasks_ServiceInnerStatusCode<br>
    * 0x0000 0010 - ServiceLevel / Inner Diagnostics --- OpcUa_DiagnosticsMasks_ServiceInnerDiagnostics<br>
    * 0x0000 0020 - OperationLevel / SymbolicId -------- OpcUa_DiagnosticsMasks_OperationSymbolicId<br>
    * 0x0000 0040 - OperationLevel / LocalizedText ----- OpcUa_DiagnosticsMasks_OperationLocalizedText<br>
    * 0x0000 0080 - OperationLevel / AdditionalInfo ---- OpcUa_DiagnosticsMasks_OperationAdditionalInfo<br>
    * 0x0000 0100 - OperationLevel / Inner StatusCode -- OpcUa_DiagnosticsMasks_OperationInnerStatusCode<br>
    * 0x0000 0200 - OperationLevel / Inner Diagnostics - OpcUa_DiagnosticsMasks_OperationInnerDiagnostics<br>
    */
    inline OpcUa_UInt32 returnDiagnostics() const {return m_returnDiagnostics;}

    /**  Returns the request handle set by the client for this service invocation.
    */
    inline OpcUa_UInt32 requestHandle() const {return m_requestHandle;}

    /**  Returns the AuditEntryId set by the client for this service invocation.
    */
    inline UaString clientAuditEntryId() const {return m_sClientAuditEntryId;}

    // Sets the Service context with information provided by the client in the request header and with the session object related to the request
    void setContext(
        Session*                   pSession,
        const OpcUa_RequestHeader& header);
    // Sets the Session object.
    void setSession(Session* pSession);
    // Set the client requested diagnostic level for this service invocation.
    void setReturnDiagnostics(OpcUa_UInt32 returnDiagnostics);
    void setTimeoutHint(OpcUa_UInt32 timeoutHint);

    OpcUa_Boolean checkSecurityMode(const NodeAccessInfo* pAccessInfo) const;

    // Set or get the mutex for the node list in a NodeManager
    void setNodeManagementMutex(UaMutex* pMutex);
    UaMutex* getNodeManagementMutex() const;
private:
    Session*      m_pSession;
    OpcUa_UInt32  m_timeoutHint;
    UaDateTime    m_receiveTime;
    UaDateTime    m_clientTime;
    OpcUa_UInt32  m_returnDiagnostics;
    OpcUa_UInt32  m_requestHandle;
    UaString      m_sClientAuditEntryId;
    UaMutex*      m_pNodeManagementMutex;
};

/** @brief This class manages a relative path used for TranslatBrowsePathsToNodeIds.

 *  The relative path contains a list of path elements where each path element contains the reference type
 *  to follow and the browse name of the target node. This path is used to find a target node by starting at a
 *  starting node and by following the path. This class manages the relative path and the current position in the
 *  path. To process the path a pointer to the current path element can be requested by using the function getCurrentElement().
 *  If the current position contained a valid reference and browse path and a matching node was found at this level, the position
 *  must be incremented by calling incrementPosition() and the next level must be processed until the end of the list is reached.
 *  It is not possible to create shallow copies of this Class.
 */
class SERVER_CORE_EXPORT UaRelativePath
{
    UA_DISABLE_COPY(UaRelativePath);
    UaRelativePath();
public:
    /* construction */
    UaRelativePath(const OpcUa_RelativePath& relativePath);
    /* destruction */
    virtual ~UaRelativePath();

    /** Get the current position in the list of browse elements.
     *  @return The current position in the list of browse elements as zero based index.
     */
    inline OpcUa_UInt32 currentPosition() {return m_currentPosition;};

    /** Increments the position in the list of relative path element to the next element to process.
     *  This function must be called after successfully processing the current position.
     *  @see getCurrentElement
     */
    inline void incrementPosition() {m_currentPosition++;};

    /** Get the total number of relative path elements in the list.
     *  @return The number of elements.
     */
    inline OpcUa_UInt32 pathElementCount() const { return (OpcUa_UInt32)m_noOfElements;};

    /**  Get a pointer to the list of relative path elements.
     *  @return The list of relative path elements.
     */
    inline const OpcUa_RelativePathElement* pathElements() const { return m_Elements;};

    const OpcUa_RelativePathElement* getCurrentElement();

    // SDK internal use
    inline bool isRootProcessed() const {return m_isRootProcessed;};
    void setIsRootProcessed();

private:
    OpcUa_UInt32               m_currentPosition;
    OpcUa_Int32                m_noOfElements;
    OpcUa_RelativePathElement* m_Elements;
    bool                       m_isRootProcessed;
};

#endif // OPCUATYPES_H
