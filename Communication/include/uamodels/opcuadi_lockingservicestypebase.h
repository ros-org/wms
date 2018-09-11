/******************************************************************************
** opcuadi_lockingservicestypebase.h
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
** Project: C++ OPC Server SDK information model for namespace http://opcfoundation.org/UA/DI/
**
** Description: OPC Unified Architecture Software Development Kit.
**
******************************************************************************/

#ifndef __OPCUADI_LOCKINGSERVICESTYPEBASE_H__
#define __OPCUADI_LOCKINGSERVICESTYPEBASE_H__

#include "opcua_baseobjecttype.h"
#include "opcuadi_datatypes.h"
#include "basenodes.h"
#include "opcua_propertytype.h"
#include "opcuadi_identifiers.h"
#include "opcuadi_instancefactory_devices.h"
#include "uaargument.h"

// Namespace for the UA information model http://opcfoundation.org/UA/DI/
namespace OpcUaDi {


/** Generated base class for a LockingServicesType.
 *
 *  This class contains the generated base code for the object type LockingServicesType
 *  representing an OPC UA ObjectType. This class is used to create the object type and to
 *  create and represent instances of the object type in the server address space.
 *
 *  **Variable members of the LockingServicesType:**
 *
 *  Browse Name       | DataType | TypeDefinition | Modelling Rule | See Also
 *  ------------------|----------|----------------|----------------|-----------------------------------------------------
 *  Locked            | Boolean  | PropertyType   | Mandatory      | \ref getLocked, \ref setLocked
 *  LockingClient     | String   | PropertyType   | Mandatory      | \ref getLockingClient, \ref setLockingClient
 *  LockingUser       | Boolean  | PropertyType   | Mandatory      | \ref getLockingUser, \ref setLockingUser
 *  RemainingLockTime | Duration | PropertyType   | Mandatory      | \ref getRemainingLockTime, \ref setRemainingLockTime
 *
 */
class UAMODELS_EXPORT LockingServicesTypeBase:
    public OpcUa::BaseObjectType
{
    UA_DISABLE_COPY(LockingServicesTypeBase);
protected:
    virtual ~LockingServicesTypeBase();
public:
    // construction / destruction
    LockingServicesTypeBase(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    LockingServicesTypeBase(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    LockingServicesTypeBase(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;


    //- Interface MethodManager -----------------------------------------------------------
    /** Call method of an UA object. */
    virtual UaStatus beginCall(
        MethodManagerCallback* pCallback,
        const ServiceContext&  serviceContext,
        OpcUa_UInt32           callbackHandle,
        MethodHandle*          pMethodHandle,
        const UaVariantArray&  inputArguments);
    virtual UaStatus call(
        const ServiceContext&  serviceContext,
        MethodHandle*          pMethodHandle,
        const UaVariantArray&  inputArguments,
        UaVariantArray&        outputArguments,
        UaStatusCodeArray&     inputArgumentResults,
        UaDiagnosticInfos&     inputArgumentDiag);
    //- Interface MethodManager -----------------------------------------------------------

    virtual UaStatus BreakLock(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        OpcUa_Int32& BreakLockStatus /**<[out] The DI specific result of the call. 0 - OK, -1 - E_NotLocked - the object is not locked*/) = 0;
    virtual UaStatus ExitLock(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        OpcUa_Int32& ExitLockStatus /**<[out] The DI specific result of the call. 0 - OK, -1 - E_NotLocked - the object is not locked*/) = 0;
    virtual UaStatus InitLock(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        const UaString& CurrentContext,  /**<[in] A string used to provide context information about the current activity going on in the Client.*/
        OpcUa_Int32& InitLockStatus      /**<[out] The DI specific result of the call. 0 - OK, -1 - E_AlreadyLocked – the element is already locked, -2 – E_Invalid – the element cannot be locked*/) = 0;
    virtual UaStatus RenewLock(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        OpcUa_Int32& RenewLockStatus /**<[out] The DI specific result of the call. 0 - OK, -1 - E_NotLocked - the object is not locked*/) = 0;

    virtual void setLocked(OpcUa_Boolean Locked);
    virtual OpcUa_Boolean getLocked() const;

    virtual void setLockingClient(const UaString& LockingClient);
    virtual UaString getLockingClient() const;

    virtual void setLockingUser(OpcUa_Boolean LockingUser);
    virtual OpcUa_Boolean getLockingUser() const;

    virtual void setRemainingLockTime(OpcUa_Double RemainingLockTime);
    virtual OpcUa_Double getRemainingLockTime() const;

    virtual OpcUa::PropertyType* getLockedNode();
    virtual OpcUa::PropertyType* getLockingClientNode();
    virtual OpcUa::PropertyType* getLockingUserNode();
    virtual OpcUa::PropertyType* getRemainingLockTimeNode();
    virtual OpcUa::BaseMethod* getBreakLock();
    virtual OpcUa::BaseMethod* getExitLock();
    virtual OpcUa::BaseMethod* getInitLock();
    virtual OpcUa::BaseMethod* getRenewLock();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(LockingServicesTypeBase *pInstance);

protected:
    // Variable nodes
    // Variable Locked
    static OpcUa::PropertyType*  s_pLocked;
    OpcUa::PropertyType*  m_pLocked;
    // Variable LockingClient
    static OpcUa::PropertyType*  s_pLockingClient;
    OpcUa::PropertyType*  m_pLockingClient;
    // Variable LockingUser
    static OpcUa::PropertyType*  s_pLockingUser;
    OpcUa::PropertyType*  m_pLockingUser;
    // Variable RemainingLockTime
    static OpcUa::PropertyType*  s_pRemainingLockTime;
    OpcUa::PropertyType*  m_pRemainingLockTime;


    // Method nodes
    static OpcUa::BaseMethod* s_pBreakLockMethod;
    OpcUa::BaseMethod*  m_pBreakLockMethod;
    static OpcUa::BaseMethod* s_pExitLockMethod;
    OpcUa::BaseMethod*  m_pExitLockMethod;
    static OpcUa::BaseMethod* s_pInitLockMethod;
    OpcUa::BaseMethod*  m_pInitLockMethod;
    static OpcUa::BaseMethod* s_pRenewLockMethod;
    OpcUa::BaseMethod*  m_pRenewLockMethod;


private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/DI/

#endif // #ifndef __OPCUADILOCKINGSERVICESTYPEBASE_H__


