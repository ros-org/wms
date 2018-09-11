/******************************************************************************
** opcuadi_devicetype.h
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

#ifndef __OPCUADI_DEVICETYPE_H__
#define __OPCUADI_DEVICETYPE_H__

#include "opcuadi_devicetypebase.h"

// Namespace for the UA information model http://opcfoundation.org/UA/DI/
namespace OpcUaDi {


/** @brief Class implementing the UaObject interface for the DeviceType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Object members of the DeviceType:**
 *
 *  Browse Name      | TypeDefinition      | Modelling Rule      | See Also
 *  -----------------|---------------------|---------------------|-------------------------------------------------------------
 *  \<CPIdentifier\> | ConnectionPointType | OptionalPlaceholder | &nbsp;
 *  DeviceTypeImage  | FolderType          | Optional            | \ref DeviceTypeBase::getDeviceTypeImage "getDeviceTypeImage"
 *  Documentation    | FolderType          | Optional            | \ref DeviceTypeBase::getDocumentation "getDocumentation"
 *  ImageSet         | FolderType          | Optional            | \ref DeviceTypeBase::getImageSet "getImageSet"
 *  ProtocolSupport  | FolderType          | Optional            | \ref DeviceTypeBase::getProtocolSupport "getProtocolSupport"
 *
 *  **Variable members of the DeviceType:**
 *
 *  Browse Name      | DataType                | TypeDefinition | Modelling Rule | See Also
 *  -----------------|-------------------------|----------------|----------------|-------------------------------------------------------------------------------------------------------------------------------
 *  DeviceClass      | String                  | PropertyType   | Optional       | \ref DeviceTypeBase::getDeviceClass "getDeviceClass", \ref DeviceTypeBase::setDeviceClass "setDeviceClass"
 *  DeviceHealth     | DeviceHealthEnumeration | PropertyType   | Optional       | \ref DeviceTypeBase::getDeviceHealth "getDeviceHealth", \ref DeviceTypeBase::setDeviceHealth "setDeviceHealth"
 *  DeviceManual     | String                  | PropertyType   | Mandatory      | \ref DeviceTypeBase::getDeviceManual "getDeviceManual", \ref DeviceTypeBase::setDeviceManual "setDeviceManual"
 *  DeviceRevision   | String                  | PropertyType   | Mandatory      | \ref DeviceTypeBase::getDeviceRevision "getDeviceRevision", \ref DeviceTypeBase::setDeviceRevision "setDeviceRevision"
 *  HardwareRevision | String                  | PropertyType   | Mandatory      | \ref DeviceTypeBase::getHardwareRevision "getHardwareRevision", \ref DeviceTypeBase::setHardwareRevision "setHardwareRevision"
 *  Manufacturer     | LocalizedText           | PropertyType   | Mandatory      | \ref DeviceTypeBase::getManufacturer "getManufacturer", \ref DeviceTypeBase::setManufacturer "setManufacturer"
 *  Model            | LocalizedText           | PropertyType   | Mandatory      | \ref DeviceTypeBase::getModel "getModel", \ref DeviceTypeBase::setModel "setModel"
 *  RevisionCounter  | Int32                   | PropertyType   | Mandatory      | \ref DeviceTypeBase::getRevisionCounter "getRevisionCounter", \ref DeviceTypeBase::setRevisionCounter "setRevisionCounter"
 *  SerialNumber     | String                  | PropertyType   | Mandatory      | \ref DeviceTypeBase::getSerialNumber "getSerialNumber", \ref DeviceTypeBase::setSerialNumber "setSerialNumber"
 *  SoftwareRevision | String                  | PropertyType   | Mandatory      | \ref DeviceTypeBase::getSoftwareRevision "getSoftwareRevision", \ref DeviceTypeBase::setSoftwareRevision "setSoftwareRevision"
 *
 */
class UAMODELS_EXPORT DeviceType:
    public DeviceTypeBase
{
    UA_DISABLE_COPY(DeviceType);
protected:
    // destruction
    virtual ~DeviceType();
public:
    // construction
    DeviceType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    DeviceType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    DeviceType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();


protected:

private:
};

} // End namespace for the UA information model http://opcfoundation.org/UA/DI/

#endif // #ifndef __OPCUADIDEVICETYPE_H__

