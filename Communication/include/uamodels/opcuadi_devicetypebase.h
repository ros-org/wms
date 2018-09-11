/******************************************************************************
** opcuadi_devicetypebase.h
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

#ifndef __OPCUADI_DEVICETYPEBASE_H__
#define __OPCUADI_DEVICETYPEBASE_H__

#include "opcuadi_topologyelementtype.h"
#include "opcuadi_datatypes.h"
#include "basenodes.h"
#include "opcua_basedatavariabletype.h"
#include "opcua_foldertype.h"
#include "opcua_propertytype.h"
#include "opcuadi_identifiers.h"
#include "opcuadi_instancefactory_devices.h"

// Namespace for the UA information model http://opcfoundation.org/UA/DI/
namespace OpcUaDi {

class ConnectionPointType;
class FunctionalGroupType;

/** Generated base class for a DeviceType.
 *
 *  This class contains the generated base code for the object type DeviceType
 *  representing an OPC UA ObjectType. This class is used to create the object type and to
 *  create and represent instances of the object type in the server address space.
 *
 *  **Object members of the DeviceType:**
 *
 *  Browse Name      | TypeDefinition      | Modelling Rule      | See Also
 *  -----------------|---------------------|---------------------|------------------------
 *  \<CPIdentifier\> | ConnectionPointType | OptionalPlaceholder | &nbsp;
 *  DeviceTypeImage  | FolderType          | Optional            | \ref getDeviceTypeImage
 *  Documentation    | FolderType          | Optional            | \ref getDocumentation
 *  ImageSet         | FolderType          | Optional            | \ref getImageSet
 *  ProtocolSupport  | FolderType          | Optional            | \ref getProtocolSupport
 *
 *  **Variable members of the DeviceType:**
 *
 *  Browse Name      | DataType                | TypeDefinition | Modelling Rule | See Also
 *  -----------------|-------------------------|----------------|----------------|---------------------------------------------------
 *  DeviceClass      | String                  | PropertyType   | Optional       | \ref getDeviceClass, \ref setDeviceClass
 *  DeviceHealth     | DeviceHealthEnumeration | PropertyType   | Optional       | \ref getDeviceHealth, \ref setDeviceHealth
 *  DeviceManual     | String                  | PropertyType   | Mandatory      | \ref getDeviceManual, \ref setDeviceManual
 *  DeviceRevision   | String                  | PropertyType   | Mandatory      | \ref getDeviceRevision, \ref setDeviceRevision
 *  HardwareRevision | String                  | PropertyType   | Mandatory      | \ref getHardwareRevision, \ref setHardwareRevision
 *  Manufacturer     | LocalizedText           | PropertyType   | Mandatory      | \ref getManufacturer, \ref setManufacturer
 *  Model            | LocalizedText           | PropertyType   | Mandatory      | \ref getModel, \ref setModel
 *  RevisionCounter  | Int32                   | PropertyType   | Mandatory      | \ref getRevisionCounter, \ref setRevisionCounter
 *  SerialNumber     | String                  | PropertyType   | Mandatory      | \ref getSerialNumber, \ref setSerialNumber
 *  SoftwareRevision | String                  | PropertyType   | Mandatory      | \ref getSoftwareRevision, \ref setSoftwareRevision
 *
 */
class UAMODELS_EXPORT DeviceTypeBase:
    public OpcUaDi::TopologyElementType
{
    UA_DISABLE_COPY(DeviceTypeBase);
protected:
    virtual ~DeviceTypeBase();
public:
    // construction / destruction
    DeviceTypeBase(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    DeviceTypeBase(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    DeviceTypeBase(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;


    virtual void setDeviceClass(const UaString& DeviceClass);
    virtual UaString getDeviceClass() const;

    virtual void setDeviceHealth(OpcUaDi::DeviceHealthEnumeration DeviceHealth);
    virtual OpcUaDi::DeviceHealthEnumeration getDeviceHealth() const;

    virtual void setDeviceManual(const UaString& DeviceManual);
    virtual UaString getDeviceManual() const;

    virtual void setDeviceRevision(const UaString& DeviceRevision);
    virtual UaString getDeviceRevision() const;

    virtual void setHardwareRevision(const UaString& HardwareRevision);
    virtual UaString getHardwareRevision() const;

    virtual void setManufacturer(const UaLocalizedText& Manufacturer);
    virtual UaLocalizedText getManufacturer(Session* pSession) const;

    virtual void setModel(const UaLocalizedText& Model);
    virtual UaLocalizedText getModel(Session* pSession) const;

    virtual void setRevisionCounter(OpcUa_Int32 RevisionCounter);
    virtual OpcUa_Int32 getRevisionCounter() const;

    virtual void setSerialNumber(const UaString& SerialNumber);
    virtual UaString getSerialNumber() const;

    virtual void setSoftwareRevision(const UaString& SoftwareRevision);
    virtual UaString getSoftwareRevision() const;

    // <ImageIdentifier> defined at DeviceTypeImage

    // <DocumentIdentifier> defined at Documentation

    // <ImageIdentifier> defined at ImageSet

    // <ProtocolSupportIdentifier> defined at ProtocolSupport

    virtual OpcUa::PropertyType* getDeviceClassNode();
    virtual OpcUa::PropertyType* getDeviceHealthNode();
    virtual OpcUa::PropertyType* getDeviceManualNode();
    virtual OpcUa::PropertyType* getDeviceRevisionNode();
    virtual OpcUa::FolderType* getDeviceTypeImage();
    virtual OpcUa::FolderType* getDocumentation();
    virtual OpcUa::PropertyType* getHardwareRevisionNode();
    virtual OpcUa::FolderType* getImageSet();
    virtual OpcUa::PropertyType* getManufacturerNode();
    virtual OpcUa::PropertyType* getModelNode();
    virtual OpcUa::FolderType* getProtocolSupport();
    virtual OpcUa::PropertyType* getRevisionCounterNode();
    virtual OpcUa::PropertyType* getSerialNumberNode();
    virtual OpcUa::PropertyType* getSoftwareRevisionNode();

// Add placeholders
    virtual UaStatus addCP(OpcUaDi::ConnectionPointType *pCP);
    virtual UaStatus addDeviceTypeImage_Image(OpcUa::BaseDataVariableType *pImage);
    virtual UaStatus addDocumentation_Document(OpcUa::BaseDataVariableType *pDocument);
    virtual UaStatus addImageSet_Image(OpcUa::BaseDataVariableType *pImage);
    virtual UaStatus addProtocolSupport_ProtocolSupport(OpcUa::BaseDataVariableType *pProtocolSupport);

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(DeviceTypeBase *pInstance);

protected:
    // Object nodes
    // Object CPIdentifier
    static OpcUaDi::ConnectionPointType*  s_pCPIdentifier;
    // Object DeviceTypeImage
    static OpcUa::FolderType*  s_pDeviceTypeImage;
    OpcUa::FolderType*  m_pDeviceTypeImage;
    // Object Documentation
    static OpcUa::FolderType*  s_pDocumentation;
    OpcUa::FolderType*  m_pDocumentation;
    // Object ImageSet
    static OpcUa::FolderType*  s_pImageSet;
    OpcUa::FolderType*  m_pImageSet;
    // Object ProtocolSupport
    static OpcUa::FolderType*  s_pProtocolSupport;
    OpcUa::FolderType*  m_pProtocolSupport;

    // Variable nodes
    // Variable DeviceClass
    static OpcUa::PropertyType*  s_pDeviceClass;
    OpcUa::PropertyType*  m_pDeviceClass;
    // Variable DeviceHealth
    static OpcUa::PropertyType*  s_pDeviceHealth;
    OpcUa::PropertyType*  m_pDeviceHealth;
    // Variable DeviceManual
    static OpcUa::PropertyType*  s_pDeviceManual;
    OpcUa::PropertyType*  m_pDeviceManual;
    // Variable DeviceRevision
    static OpcUa::PropertyType*  s_pDeviceRevision;
    OpcUa::PropertyType*  m_pDeviceRevision;
    // Variable HardwareRevision
    static OpcUa::PropertyType*  s_pHardwareRevision;
    OpcUa::PropertyType*  m_pHardwareRevision;
    // Variable Manufacturer
    static OpcUa::PropertyType*  s_pManufacturer;
    OpcUa::PropertyType*  m_pManufacturer;
    // Variable Model
    static OpcUa::PropertyType*  s_pModel;
    OpcUa::PropertyType*  m_pModel;
    // Variable RevisionCounter
    static OpcUa::PropertyType*  s_pRevisionCounter;
    OpcUa::PropertyType*  m_pRevisionCounter;
    // Variable SerialNumber
    static OpcUa::PropertyType*  s_pSerialNumber;
    OpcUa::PropertyType*  m_pSerialNumber;
    // Variable SoftwareRevision
    static OpcUa::PropertyType*  s_pSoftwareRevision;
    OpcUa::PropertyType*  m_pSoftwareRevision;

    // Variable DeviceTypeImage ImageIdentifier
    static OpcUa::BaseDataVariableType* s_pDeviceTypeImage_ImageIdentifier;
    // Variable Documentation DocumentIdentifier
    static OpcUa::BaseDataVariableType* s_pDocumentation_DocumentIdentifier;
    // Variable ImageSet ImageIdentifier
    static OpcUa::BaseDataVariableType* s_pImageSet_ImageIdentifier;
    // Variable ProtocolSupport ProtocolSupportIdentifier
    static OpcUa::BaseDataVariableType* s_pProtocolSupport_ProtocolSupportIdentifier;


private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/DI/

#endif // #ifndef __OPCUADIDEVICETYPEBASE_H__


