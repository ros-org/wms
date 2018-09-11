/******************************************************************************
** methodhandleuanode.h
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
** Description: OPC server core module method handle class.
**
******************************************************************************/
#ifndef METHODHANDLEUANODE_H
#define METHODHANDLEUANODE_H

#include "opcuatypes.h"
#include "methodmanager.h"

class SERVER_CORE_EXPORT UaObject;
class SERVER_CORE_EXPORT UaMethod;

/** @brief MethodHandle containing the information necessary to execute a method represented as UaNode.

 *  The instance of the MethodHandleUaNode class is created in the function NodeManager::getMethodHandle and contains all
 *  information necessary for the SDK to call the MethodManager and for the MethodManager implementation to execute the method.
 *  The information for a MethodManager implementation are the UaObject and UaMethod node pointers contained as members in this class.
 *  The class is reference counted by deriving from ReferenceCounter. The class can not be deleted directly.
 */
class SERVER_CORE_EXPORT MethodHandleUaNode: public MethodHandle
{
    UA_DISABLE_COPY(MethodHandleUaNode);
public:
    MethodHandleUaNode();
    void setUaNodes(UaObject* pUaObject, UaMethod* pUaMethod);

    /** Returns the type of handle implementation */
    virtual HandleImplementation getHandleImplementation() const { return MethodHandle::UA_NODE; }

    /** UaObject node representing the object the method should be called on. */
    inline UaObject* pUaObject() const { return m_pUaObject; }

    /** UaMethod node representing the method that should be called. */
    inline UaMethod* pUaMethod() const { return m_pUaMethod; }

protected:
    virtual ~MethodHandleUaNode();

    UaObject* m_pUaObject;
    UaMethod* m_pUaMethod;
};

#endif // METHODHANDLEUANODE_H
