/******************************************************************************
** opcuadi_nodemanagerdevicesbase.h
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

#ifndef _OPCUADI_NODEMANAGERDEVICESBASE_H__
#define _OPCUADI_NODEMANAGERDEVICESBASE_H__

#include "uamutex.h"
#include "uabasenodes.h"
#include "nodemanagerbase.h"
#include "uaobjecttypes.h"
#include "opcuadi_identifiers.h"

/** Namespace for the UA information model http://opcfoundation.org/UA/DI/
*/
namespace OpcUaDi {

/** Generated base class for NodeManager for Devices information model.
 *
 *  This abstract class contains the auto generated code for the NodeManagerDevices.
 *  This class is used to create the nodes defined for the namespace http://opcfoundation.org/UA/DI/.
 *
 */
class UAMODELS_EXPORT NodeManagerDevicesBase : public NodeManagerBase
{
    UA_DISABLE_COPY(NodeManagerDevicesBase);
public:
    /* construction / destruction */
    NodeManagerDevicesBase(
        OpcUa_Boolean supportDeviceCommunicationModel = OpcUa_False,
        OpcUa_Boolean supportDeviceIntegrationHostModel = OpcUa_False,
        OpcUa_Boolean firesEvents = OpcUa_False,
        OpcUa_Int32 nHashTableSize = 10007);
    virtual ~NodeManagerDevicesBase(){};

    //- Interface NodeManagerUaNode -------------------------------------------------------
    virtual UaStatus   afterStartUp();
    //- Interface NodeManagerUaNode -------------------------------------------------------

    static OpcUa_UInt16 getTypeNamespace();

private:
    UaStatus createDataTypeNodes();
    UaStatus createReferenceTypeNodes();
    UaStatus addObjectsFolderDeviceSet(const XmlUaNodeFactoryManager &factory);
    UaStatus addObjectsFolderDeviceTopology(const XmlUaNodeFactoryManager &factory);
    UaStatus addObjectsFolderNetworkSet(const XmlUaNodeFactoryManager &factory);
    UaStatus addObjectsFolderServerServerCapabilitiesMaxInactiveLockTime(const XmlUaNodeFactoryManager &factory);


protected:
    UaMutex             m_mutex;
    static OpcUa_UInt16 s_namespaceIndex;
    OpcUa_Boolean m_supportDeviceCommunicationModel;
    OpcUa_Boolean m_supportDeviceIntegrationHostModel;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/DI/

#endif // #ifndef __NODEMANAGERDEVICESBASE_H__

