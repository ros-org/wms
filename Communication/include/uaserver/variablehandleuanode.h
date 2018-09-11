/******************************************************************************
** variablehandleuanode.h
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
** Description: OPC server core module variable handle class.
**
******************************************************************************/
#ifndef VARIABLEHANDLEUANODE_H
#define VARIABLEHANDLEUANODE_H

#include "variablehandle.h"

class SERVER_CORE_EXPORT UaNode;

/** VariableHandleUaNode
 *  @brief Class for the Variable Handle of an internal node tree element based on the BaseNode.
 *  Derived from VariableHandle.
 */
class SERVER_CORE_EXPORT VariableHandleUaNode : public VariableHandle
{
    UA_DISABLE_COPY(VariableHandleUaNode);
protected:
    virtual ~VariableHandleUaNode();
public:
    VariableHandleUaNode();

    inline UaNode* pUaNode() const { return m_pUaNode;}
    void setUaNode(UaNode* pUaNode);
private:
    UaNode*    m_pUaNode;
};

/** HistoryVariableHandleUaNode
 *  @brief Class for the History Variable Handle of an internal node tree element based on the BaseNode.
 *  Derived from HistoryVariableHandle.
 */
class SERVER_CORE_EXPORT HistoryVariableHandleUaNode : public HistoryVariableHandle
{
    UA_DISABLE_COPY(HistoryVariableHandleUaNode);
public:
    /* construction */
    HistoryVariableHandleUaNode();

    virtual HandleImplementation getHandleImplementation() const { return HistoryVariableHandle::UA_NODE; }

    inline UaNode* pUaNode() const { return m_pUaNode;}
    void setUaNode(UaNode* pUaNode);

protected:
    /* destruction */
    virtual ~HistoryVariableHandleUaNode();

private:
    UaNode*    m_pUaNode;
};

#endif // VARIABLEHANDLEUANODE_H
