/******************************************************************************
** opcuadi_lockingservicestype.h
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

#ifndef __OPCUADI_LOCKINGSERVICESTYPE_H__
#define __OPCUADI_LOCKINGSERVICESTYPE_H__

#include "opcuadi_lockingservicestypebase.h"

// Namespace for the UA information model http://opcfoundation.org/UA/DI/
namespace OpcUaDi {


/** Callback interface used to implement the LockingServices interface in the user application
 *
 * Locking is the means to avoid concurrent modifications to a Device or Network and their components. Clients shall
 * use the locking services if they need to make a set of changes (for example, several write operations and Method
 * invocations) and where a consistent state is available only after all of these changes have been performed. The main
 * purpose of locking a Device is avoiding concurrent modifications. The main purpose of locking a Network is avoiding
 * concurrent topology changes.
 *
 * A Lock from one Client usually allows other Clients to view (navigate / read) the locked element. Servers may choose
 * to implement an exclusive locking where other Clients have no access at all (e.g. in cases where even read operations
 * require certain settings in a Device).
 *
 * When locking a Device, the lock applies to the complete device (including all components like blocks or modules).
 *
 * When locking a Modular Device, the lock applies to the complete Device (including all modules). Equally, when locking
 * a block-oriented Device (see 9.2), the lock applies to the complete Device (including all Blocks). Servers may allow
 * independent locking of Sub-Devices or Blocks, respectively, if no lock is applied to the top-level Device
 * (for Modular Device or for Block Device).
 *
 * If the Online / Offline model is supported, the lock always applies to both the online and the offline version.
 *
 * When locking a Network, the lock applies to the Network and all connected Devices. If any of the connected Devices
 * provides access to a sub-ordinate Network (like a gateway), the sub-ordinate Network and its connected Devices are
 * locked as well.
 */
class UAMODELS_EXPORT LockingServicesCallback
{
    UA_DISABLE_COPY(LockingServicesCallback);
public:
    LockingServicesCallback(){}
    virtual ~LockingServicesCallback(){}

    /** InitLock restricts access to the Device for other Clients.
     *
     * A call of this Method for an element that is already locked will be rejected. This may also be due to an implicit
     * lock created by the Server. If InitLock is requested for a Network, it will be rejected if any of the Devices
     * connected to this Network or any sub-ordinate Network including their connected Devices is already locked.
     *
     * While locked, requests from other Clients to modify the locked element (e.g., writing to Parameters, modifying
     * the topology, or invoking Methods) will be rejected. However, requests to read or navigate will typically work.
     * Servers may choose to implement an exclusive locking where other Clients have no access at all (e.g. in cases
     * where even read operations require certain settings in a Device).
     *
     * The lock is removed when ExitLock is called. It is automatically removed when the Session ends. This is typically
     * the case when the connection to the Client breaks and the Session times out. Servers shall also maintain an
     * automatic unlock if Clients do not access the locked element for a certain time.
     */
    virtual UaStatus InitLock(
        const ServiceContext& serviceContext, //!< [in] The session and client call context
        const UaString& CurrentContext, //!< [in] A string used to provide context information about the current activity going on in the Client.
        OpcUa_Int32& InitLockStatus) //!< [out] 0 - OK, -1 - E_AlreadyLocked, -2 - E_Invalid
        = 0;

    /** ExitLock removes the lock from the Device.
     *
     * This Method may only be called from the same Session from which InitLock had been called.
     */
    virtual UaStatus ExitLock(
        const ServiceContext& serviceContext, //!< [in] The session and client call context
        OpcUa_Int32& ExitLockStatus) //!< [out] 0 - OK, -1 - E_NotLocked
        = 0;

    /** Renew the lock of a device
     *
     * The lock timer is automatically renewed whenever the Client initiates a request for the locked element or while
     * Nodes of the locked element are subscribed to. RenewLock is used to reset the lock timer to the value of the
     * MaxInactiveLockTime Property and prevent the Server from automatically aborting the lock. This Method may only
     * be called from the same Session from which InitLock had been called.
     */
    virtual UaStatus RenewLock(
        const ServiceContext& serviceContext, //!< [in] The session and client call context
        OpcUa_Int32& RenewLockStatus) //!< [out] 0 - OK, -1 - E_NotLocked
        = 0;

    /** Break the lock of a device
     *
     * BreakLock allows a Client (with sufficiently high user rights) to break the lock held by another Client.
     * This Method will typically be available only to users with administrator privileges. BreakLock should be
     * used with care as the locked element may be in an inconsistent state.
     */
    virtual UaStatus BreakLock(
        const ServiceContext& serviceContext, //!< [in] The session and client call context
        OpcUa_Int32& BreakLockStatus) //!< [out] 0 - OK, -1 - E_NotLocked
        = 0;
};

/** @brief Class implementing the UaObject interface for the LockingServicesType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.<br>
 *
 *  **Variable members of the LockingServicesType:**
 *
 *  Browse Name       | DataType | TypeDefinition | Modelling Rule | See Also
 *  ------------------|----------|----------------|----------------|-----------------------------------------------------------------------------------------------------------------------------------------------------
 *  Locked            | Boolean  | PropertyType   | Mandatory      | \ref LockingServicesTypeBase::getLocked "getLocked", \ref LockingServicesTypeBase::setLocked "setLocked"
 *  LockingClient     | String   | PropertyType   | Mandatory      | \ref LockingServicesTypeBase::getLockingClient "getLockingClient", \ref LockingServicesTypeBase::setLockingClient "setLockingClient"
 *  LockingUser       | Boolean  | PropertyType   | Mandatory      | \ref LockingServicesTypeBase::getLockingUser "getLockingUser", \ref LockingServicesTypeBase::setLockingUser "setLockingUser"
 *  RemainingLockTime | Duration | PropertyType   | Mandatory      | \ref LockingServicesTypeBase::getRemainingLockTime "getRemainingLockTime", \ref LockingServicesTypeBase::setRemainingLockTime "setRemainingLockTime"
 *
 *  **Method members of the LockingServicesType:**
 *
 *  Browse Name    | Modelling Rule
 *  ---------------|---------------
 *  \ref BreakLock | Mandatory
 *  \ref ExitLock  | Mandatory
 *  \ref InitLock  | Mandatory
 *  \ref RenewLock | Mandatory
 *
 * Locking is the means to avoid concurrent modifications to a Device or Network and their components. Clients shall
 * use the locking services if they need to make a set of changes (for example, several write operations and Method
 * invocations) and where a consistent state is available only after all of these changes have been performed. The main
 * purpose of locking a Device is avoiding concurrent modifications. The main purpose of locking a Network is avoiding
 * concurrent topology changes.
 *
 * A Lock from one Client usually allows other Clients to view (navigate / read) the locked element. Servers may choose
 * to implement an exclusive locking where other Clients have no access at all (e.g. in cases where even read operations
 * require certain settings in a Device).
 *
 * When locking a Device, the lock applies to the complete device (including all components like blocks or modules).
 *
 * When locking a Modular Device, the lock applies to the complete Device (including all modules). Equally, when locking
 * a block-oriented Device (see 9.2), the lock applies to the complete Device (including all Blocks). Servers may allow
 * independent locking of Sub-Devices or Blocks, respectively, if no lock is applied to the top-level Device
 * (for Modular Device or for Block Device).
 *
 * If the Online / Offline model is supported, the lock always applies to both the online and the offline version.
 *
 * When locking a Network, the lock applies to the Network and all connected Devices. If any of the connected Devices
 * provides access to a sub-ordinate Network (like a gateway), the sub-ordinate Network and its connected Devices are
 * locked as well.
 */
class UAMODELS_EXPORT LockingServicesType:
    public LockingServicesTypeBase
{
    UA_DISABLE_COPY(LockingServicesType);
protected:
    // destruction
    virtual ~LockingServicesType();
public:
    // construction
    LockingServicesType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    LockingServicesType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    LockingServicesType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    // UaLockingServicesType method BreakLock
    virtual UaStatus BreakLock(
        const ServiceContext& serviceContext,
        OpcUa_Int32& BreakLockStatus);
    // UaLockingServicesType method ExitLock
    virtual UaStatus ExitLock(
        const ServiceContext& serviceContext,
        OpcUa_Int32& ExitLockStatus);
    // UaLockingServicesType method InitLock
    virtual UaStatus InitLock(
        const ServiceContext& serviceContext,
        const UaString& CurrentContext,
        OpcUa_Int32& InitLockStatus);
    // UaLockingServicesType method RenewLock
    virtual UaStatus RenewLock(
        const ServiceContext& serviceContext,
        OpcUa_Int32& RenewLockStatus);

    void setLockingServices(LockingServicesCallback* pCallback);

protected:
    LockingServicesCallback* m_pCallback;
private:
};

} // End namespace for the UA information model http://opcfoundation.org/UA/DI/

#endif // #ifndef __OPCUADILOCKINGSERVICESTYPE_H__

