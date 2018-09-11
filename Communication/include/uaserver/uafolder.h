/******************************************************************************
** uafolder.h
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
** Description: OPC UA server folder node class.
**
******************************************************************************/
#ifndef __UAFOLDER_H__
#define __UAFOLDER_H__

#include "uabasenodes.h"
#include "uaobjecttypes.h"


/** @ingroup ServerCoreAddressModel
 *  OPC UA Folder Object handling class.
 *  This class implements a UA node of the type Folder object based on the abstract base classes UaNode
 *  and UaObject. The class UaFolder can be used to instantiate a simple folder that uses one name
 *  and a default localeId to compose the BrowseName (name + namespace index of NodeId) and
 *  DisplayName (name + default localeId). The description is not supported in this class.
 *  Enhanced features like multiple DisplayNames with different localeIds, description or BrowseName
 *  with different namespace than NodeId can be implemented in a derived class.
 *  Derived from UaObjectBase.
 *  It is not possible to create shallow copies of this Class.
 */
class SERVER_CORE_EXPORT UaFolder : public UaObjectBase
{
    UA_DISABLE_COPY(UaFolder);
protected:
    /** destruction */
    virtual ~UaFolder();
public:
    /** construction */
    UaFolder(const UaString& name, const UaNodeId& nodeId, const UaString& defaultLocaleId);

    /** Get the object type NodeId for the server object.
     *  @return the object type NodeId for the server object.
     */
    UaNodeId                typeDefinitionId() const;

    /** Provides the information if the object can be used to subscribe for events.
     *  @return the EventNotifier attribute value for the Folder.
     */
    virtual OpcUa_Byte      eventNotifier() const;

    /** Get the Node.
     *  @return the current searched Node.
     */
    UaNode* getUaNode() const {return (UaNode*)this;};

private:
};

/** @ingroup ServerCoreAddressModel
 *  OPC UA Folder Object handling class used as Alarm Area object.
 *  This class implements a UA node of the type Folder object with the eventNotifier set to SubscribeToEvents.
 *  It is used to build an Alarm Area tree. The class is based on the abstract base classes UaNode
 *  and UaObject. The class UaAreaFolder can be used to instantiate a simple folder that uses one name
 *  and a default localeId to compose the BrowseName (name + namespace index of NodeId) and
 *  DisplayName (name + default localeId). The description is not supported in this class.
 *  Enhanced features like multiple DisplayNames with different localeIds, description or BrowseName
 *  with different namespace than NodeId can be implemented in a derived class.
 *  Derived from UaObjectBase.
 *  It is not possible to create shallow copies of this Class.
 */
class SERVER_CORE_EXPORT UaAreaFolder : public UaFolder
{
    UA_DISABLE_COPY(UaAreaFolder);
public:
    /** construction */
    UaAreaFolder(const UaString& name, const UaNodeId& nodeId, const UaString& defaultLocaleId);
    /** destruction */
    virtual ~UaAreaFolder();

    /** Provides the information if the object can be used to subscribe for events.
     *  @return the EventNotifier attribute value for the Object.
     */
    virtual OpcUa_Byte      eventNotifier() const;
private:
};

#endif // __UAFOLDER_H__
