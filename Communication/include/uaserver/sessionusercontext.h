/******************************************************************************
** sessionusercontext.h
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
** Description: OPC server core module session user context class.
**
******************************************************************************/
#ifndef SESSIONUSERCONTEXT_H
#define SESSIONUSERCONTEXT_H

#include "referencecounter.h"
#include "opcuatypes.h"
#include <set>

class NodeAccessInfo;

/** @brief Class for user context of a Session.

 OPC UA defines different information model elements like Objects, Variables, Method and Events
 and different services to access the information. This access can be restricted based on the user
 that tries to access the information. The user authentication is done during the Session
 creation and the user information is stored in the Session using this class.

 The SessionUserContext stores information about the authenticated user that activated the session
 and the groups the user is a member in.

 The SessionUserContext is used to verify the rights of the user when accessing information in the
 server address space. The access masks and the authorized user and group are stored in the UaNode
 with the class NodeAccessInfo. The information from both classes is used to determine if the requested
 operation like Read, Write or Browse can be executed.
 */
class SERVER_CORE_EXPORT SessionUserContext : public ReferenceCounter
{
public:
    /// @brief Definition of the PermissionType Enumeration defining the model of the user authorization check
    enum AccessInfoMode
    {
        OwnerGroupOther = 0,    /*!< Check userId with owner and groupIds with group in NodeAccessInfo. */
        RoleRoleOther,          /*!< OwerId in NodeAccessInfo is used as second role. */
        UserDefined             /*!< Node NodeAccessInfo was overwritten by user for application specific user authorization */
    };

    SessionUserContext();
    SessionUserContext(OpcUa_UInt16 userId);

    virtual AccessInfoMode accessInfoMode() const;
    virtual void setAccessInfoMode(AccessInfoMode mode);

    virtual OpcUa_UInt16 userId() const;
    virtual void setUserId(OpcUa_UInt16 userId);
    virtual void setGroups(std::set<OpcUa_UInt16> groupIds);
    virtual void addMembership(OpcUa_UInt16 groupId);
    virtual bool isMemberOf(OpcUa_UInt16 groupId) const;
    virtual bool isRoot() const;

    virtual bool isAttributeReadable(const NodeAccessInfo* pNodeAccess) const;
    virtual bool isReadable(const NodeAccessInfo* pNodeAccess) const;
    virtual bool isWritable(const NodeAccessInfo* pNodeAccess) const;
    virtual bool isBrowseable(const NodeAccessInfo* pNodeAccess) const;
    virtual bool isHistoryReadable(const NodeAccessInfo* pNodeAccess) const;
    virtual bool isHistoryInsertable(const NodeAccessInfo* pNodeAccess) const;
    virtual bool isHistoryModifiable(const NodeAccessInfo* pNodeAccess) const;
    virtual bool isHistoryDeletable(const NodeAccessInfo* pNodeAccess) const;
    virtual bool isEventReadable(const NodeAccessInfo* pNodeAccess) const;
    virtual bool isExecutable(const NodeAccessInfo* pNodeAccess) const;
    virtual bool isAttributeWritable(const NodeAccessInfo* pNodeAccess) const;

    virtual OpcUa_UInt16 defaultPermissions() const;
    virtual void setDefaultPermissions(OpcUa_UInt16 defaultPermissions);

    virtual OpcUa_UInt16 rootId() const;
    virtual void setRootId(OpcUa_UInt16 rootId);

protected:
    virtual ~SessionUserContext(){}
    virtual bool permissionCheck(const NodeAccessInfo* pNodeAccess, OpcUa_UInt16 permission) const;

private:
    OpcUa_UInt16            m_userId;               // root is 0 by default - others start with 1
    std::set<OpcUa_UInt16>  m_setGroupIds;          // all groupIds this user is member of
    OpcUa_UInt16            m_defaultPermissions;   // if a node has no permissions configured we use these
    OpcUa_UInt16            m_rootId;               // the userId of the root user. That user has all rights.
    AccessInfoMode          m_mode;                 // how to check for user and group
};

#endif // SESSIONUSERCONTEXT_H