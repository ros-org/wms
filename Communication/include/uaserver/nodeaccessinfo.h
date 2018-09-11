/******************************************************************************
** nodeaccessinfo.h
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
** Description: OPC server core module access info for user authorisation
**
******************************************************************************/
#ifndef NODEACCESSINFO_H
#define NODEACCESSINFO_H

#include "opcuatypes.h"

/** @brief Class for the user access flags of a node in the address space.

 OPC UA defines different information model elements like Objects, Variables, Method and Events
 and different services to access the information. This access can be restricted based on the user
 that tries to access the information. The user authentication is done during the Session
 creation and the user information is stored in the Session using the class SessionUserContext.

 The access masks and the authorized user and group are stored in the UaNode with the class
 NodeAccessInfo. The information from SessionUserContext and NodeAccessInfo is used to determine
 if the requested operation like Read, Write or Browse can be executed.

 The different permissions are defined by the PermissionType.

 The different masks are defined by AccessMask.

 The class is reference counted. After creation, the reference counter is 1. If the NodeAccessInfo is
 set on a node with UaNode::attachAccessInfo(), the reference counter is not incremented and the node
 takes ownership of the one reference. If you want to set NodeAccessInfo on additional nodes, the
 method UaNode::setAccessInfo() is used. It increments the reference counter of NodeAccessInfo.
 */
class SERVER_CORE_EXPORT NodeAccessInfo : public ReferenceCounter
{
public:
    /// @brief Definition of the PermissionType Enumeration defining the permissions of the NodeAccessInfo
    enum PermissionType
    {
        UA_ATTRREADABLE     = 0x0001,       /*!< Read access to all non-value attributes */
        UA_READABLE         = 0x0002,       /*!< Read access to value attribute */
        UA_WRITABLE         = 0x0004,       /*!< Write access to value attribute */
        UA_BROWSEABLE       = 0x0008,       /*!< Browse access to node */
        UA_HISTORYREADABLE  = 0x0010,       /*!< Read history access for node */
        UA_HISTORYINSERT    = 0x0020,       /*!< Insert history access for node */
        UA_HISTORYMODIFY    = 0x0040,       /*!< Modify history access for node */
        UA_HISTORYDELETE    = 0x0080,       /*!< Delete history access for node */
        UA_EVENTREADABLE    = 0x0100,       /*!< Receive events rights */
        UA_EXECUTABLE       = UA_WRITABLE,  /*!< Execute method call rights */
        UA_ATTRWRITABLE     = 0x0200,       /*!< Write access to non-value attributes dependent on write mask */
        UA_PERMISSION_ALL   = 0x03FF        /*!< Full access */
    };
    static const OpcUa_UInt16 UA_NUM_PERMISSION_BITS = 10;

    /// @brief Definition of the AccessMask Enumeration defining the user masks of the NodeAccessInfo
    enum AccessMask
    {
        // access for others
        UA_OTHER_ATTRREADABLE    = UA_ATTRREADABLE,    /*!< OTHER: Read access to all non-value attributes */
        UA_OTHER_READABLE        = UA_READABLE,        /*!< OTHER: Read access to value attribute */
        UA_OTHER_WRITABLE        = UA_WRITABLE,        /*!< OTHER: Write access to value attribute */
        UA_OTHER_BROWSEABLE      = UA_BROWSEABLE,      /*!< OTHER: Browse access to node */
        UA_OTHER_HISTORYREADABLE = UA_HISTORYREADABLE, /*!< OTHER: Read history access for node */
        UA_OTHER_HISTORYINSERT   = UA_HISTORYINSERT,   /*!< OTHER: Insert history access for node */
        UA_OTHER_HISTORYMODIFY   = UA_HISTORYMODIFY,   /*!< OTHER: Modify history access for node */
        UA_OTHER_HISTORYDELETE   = UA_HISTORYDELETE,   /*!< OTHER: Delete history access for node */
        UA_OTHER_EVENTREADABLE   = UA_EVENTREADABLE,   /*!< OTHER: Receive events rights */
        UA_OTHER_EXECUTABLE      = UA_EXECUTABLE,      /*!< OTHER: Execute method call rights */
        UA_OTHER_ATTRWRITABLE    = UA_ATTRWRITABLE,    /*!< OTHER: Write access to non-value attributes dependent on write mask */
        UA_OTHER_OBSERVATION     = UA_OTHER_ATTRREADABLE | UA_OTHER_READABLE | UA_OTHER_BROWSEABLE | UA_OTHER_HISTORYREADABLE | UA_OTHER_EVENTREADABLE,
        UA_OTHER_OPERATION       = UA_OTHER_OBSERVATION | UA_OTHER_WRITABLE | UA_OTHER_EXECUTABLE,
        UA_OTHER_ALL             = UA_PERMISSION_ALL,  /*!< OTHER: Full access */

        // access for group members
        UA_GROUP_ATTRREADABLE    = UA_ATTRREADABLE      << UA_NUM_PERMISSION_BITS, /*!< GROUP: Read access to all non-value attributes */
        UA_GROUP_READABLE        = UA_READABLE          << UA_NUM_PERMISSION_BITS, /*!< GROUP: Read access to value attribute */
        UA_GROUP_WRITABLE        = UA_WRITABLE          << UA_NUM_PERMISSION_BITS, /*!< GROUP: Write access to value attribute */
        UA_GROUP_BROWSEABLE      = UA_BROWSEABLE        << UA_NUM_PERMISSION_BITS, /*!< GROUP: Browse access to node */
        UA_GROUP_HISTORYREADABLE = UA_HISTORYREADABLE   << UA_NUM_PERMISSION_BITS, /*!< GROUP: Read history access for node */
        UA_GROUP_HISTORYINSERT   = UA_HISTORYINSERT     << UA_NUM_PERMISSION_BITS, /*!< GROUP: Insert history access for node */
        UA_GROUP_HISTORYMODIFY   = UA_HISTORYMODIFY     << UA_NUM_PERMISSION_BITS, /*!< GROUP: Modify history access for node */
        UA_GROUP_HISTORYDELETE   = UA_HISTORYDELETE     << UA_NUM_PERMISSION_BITS, /*!< GROUP: Delete history access for node */
        UA_GROUP_EVENTREADABLE   = UA_EVENTREADABLE     << UA_NUM_PERMISSION_BITS, /*!< GROUP: Receive events rights */
        UA_GROUP_EXECUTABLE      = UA_EXECUTABLE        << UA_NUM_PERMISSION_BITS, /*!< GROUP: Execute method call rights */
        UA_GROUP_ATTRWRITABLE    = UA_ATTRWRITABLE      << UA_NUM_PERMISSION_BITS, /*!< GROUP: Write access to non-value attributes dependent on write mask */
        UA_GROUP_OBSERVATION     = UA_GROUP_ATTRREADABLE | UA_GROUP_READABLE | UA_GROUP_BROWSEABLE | UA_GROUP_HISTORYREADABLE | UA_GROUP_EVENTREADABLE,
        UA_GROUP_OPERATION       = UA_GROUP_OBSERVATION | UA_GROUP_WRITABLE | UA_GROUP_EXECUTABLE,
        UA_GROUP_ALL             = UA_PERMISSION_ALL    << UA_NUM_PERMISSION_BITS, /*!< GROUP: Full access */

        // access for owner
        UA_OWNER_ATTRREADABLE    = UA_GROUP_ATTRREADABLE    << UA_NUM_PERMISSION_BITS, /*!< OWNER: Read access to all non-value attributes */
        UA_OWNER_READABLE        = UA_GROUP_READABLE        << UA_NUM_PERMISSION_BITS, /*!< OWNER: Read access to value attribute */
        UA_OWNER_WRITABLE        = UA_GROUP_WRITABLE        << UA_NUM_PERMISSION_BITS, /*!< OWNER: Write access to value attribute */
        UA_OWNER_BROWSEABLE      = UA_GROUP_BROWSEABLE      << UA_NUM_PERMISSION_BITS, /*!< OWNER: Browse access to node */
        UA_OWNER_HISTORYREADABLE = UA_GROUP_HISTORYREADABLE << UA_NUM_PERMISSION_BITS, /*!< OWNER: Read history access for node */
        UA_OWNER_HISTORYINSERT   = UA_GROUP_HISTORYINSERT   << UA_NUM_PERMISSION_BITS, /*!< OWNER: Insert history access for node */
        UA_OWNER_HISTORYMODIFY   = UA_GROUP_HISTORYMODIFY   << UA_NUM_PERMISSION_BITS, /*!< OWNER: Modify history access for node */
        UA_OWNER_HISTORYDELETE   = UA_GROUP_HISTORYDELETE   << UA_NUM_PERMISSION_BITS, /*!< OWNER: Delete history access for node */
        UA_OWNER_EVENTREADABLE   = UA_GROUP_EVENTREADABLE   << UA_NUM_PERMISSION_BITS, /*!< OWNER: Receive events rights */
        UA_OWNER_EXECUTABLE      = UA_GROUP_EXECUTABLE      << UA_NUM_PERMISSION_BITS, /*!< OWNER: Execute method call rights */
        UA_OWNER_ATTRWRITABLE    = UA_GROUP_ATTRWRITABLE    << UA_NUM_PERMISSION_BITS, /*!< OWNER: Write access to non-value attributes dependent on write mask */
        UA_OWNER_OBSERVATION     = UA_OWNER_ATTRREADABLE | UA_OWNER_READABLE | UA_OWNER_BROWSEABLE | UA_OWNER_HISTORYREADABLE | UA_OWNER_EVENTREADABLE,
        UA_OWNER_OPERATION       = UA_OWNER_OBSERVATION | UA_OWNER_WRITABLE | UA_OWNER_EXECUTABLE,
        UA_OWNER_ALL             = UA_GROUP_ALL             << UA_NUM_PERMISSION_BITS, /*!< OWNER: Full access */

        // additional flags
        UA_ALL_SIGNING_REQUIRED     = (0x1 << (3*UA_NUM_PERMISSION_BITS)), /*!< Access requires message signing */
        UA_ALL_ENCRYPTION_REQUIRED  = (0x2 << (3*UA_NUM_PERMISSION_BITS))  /*!< Access requires message encryption */
    };

    /** Creates a NodeAccessInfo object with the access mask, the owner and the group information
    */
    NodeAccessInfo(
        OpcUa_UInt32 mode,    /*!< Mask setting based on the flags defined in the AccessMask. */
        OpcUa_UInt16 ownerId, /*!< The ID of the owner of the node. Depending on the settings
                                   in the SessionUserContext, this ID may be used as second group/role ID. */
        OpcUa_UInt16 groupId) /*!< The ID of the owner of the group. */
        : m_mode(mode), m_ownerId(ownerId), m_groupId(groupId)
    {}

    /** Creates a NodeAccessInfo object with the settings from another NodeAccessInfo
    */
    NodeAccessInfo(
        const NodeAccessInfo* pOther) /*!< Other NodeAccessInfo to copy from. */
        : m_mode(pOther->m_mode), m_ownerId(pOther->m_ownerId), m_groupId(pOther->m_groupId)
    {}

    virtual bool isDefaultAttributeReadable() const
    {
        return (m_mode & UA_ATTRREADABLE) != 0;
    }
    virtual bool isDefaultReadable() const
    {
        return (m_mode & UA_READABLE) != 0;
    }
    virtual bool isDefaultWritable() const
    {
        return (m_mode & UA_WRITABLE) != 0;
    }
    virtual bool isDefaultBrowseable() const
    {
        return (m_mode & UA_BROWSEABLE) != 0;
    }
    virtual bool isDefaultHistoryReadable() const
    {
        return (m_mode & UA_HISTORYREADABLE) != 0;
    }
    virtual bool isDefaultHistoryInsertable() const
    {
        return (m_mode & UA_HISTORYINSERT) != 0;
    }
    virtual bool isDefaultHistoryModifiable() const
    {
        return (m_mode & UA_HISTORYMODIFY) != 0;
    }
    virtual bool isDefaultHistoryDeletable() const
    {
        return (m_mode & UA_HISTORYDELETE) != 0;
    }
    virtual bool isDefaultEventReadable() const
    {
        return (m_mode & UA_EVENTREADABLE) != 0;
    }
    virtual bool isDefaultExecutable() const
    {
        return (m_mode & UA_EXECUTABLE) != 0;
    }
    virtual bool isDefaultAttributeWritable() const
    {
        return (m_mode & UA_ATTRWRITABLE) != 0;
    }

    virtual bool checkSecurityMode(OpcUa_MessageSecurityMode securityMode) const
    {
        if (m_mode & UA_ALL_ENCRYPTION_REQUIRED)
        {
            return securityMode == OpcUa_MessageSecurityMode_SignAndEncrypt ? OpcUa_True : OpcUa_False;
        }
        else if (m_mode & UA_ALL_SIGNING_REQUIRED)
        {
            if (securityMode == OpcUa_MessageSecurityMode_Sign || securityMode == OpcUa_MessageSecurityMode_SignAndEncrypt)
            {
                return true;
            }
            return false;
        }

        return true;
    }

    OpcUa_UInt32 m_mode;
    OpcUa_UInt16 m_ownerId;
    OpcUa_UInt16 m_groupId;

protected:
    virtual ~NodeAccessInfo(){};

private:
    NodeAccessInfo(const NodeAccessInfo&);
    NodeAccessInfo& operator=(const NodeAccessInfo&);
};

#endif // NODEACCESSINFO_H
