/******************************************************************************
** uafileobject.h
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
** Project: C++ OPC Client SDK
**
** Description: Proxy class for OPC UA ObjectType FileType.
**
******************************************************************************/
#ifndef UACLIENTSDK_UAFILEOBJECT_H
#define UACLIENTSDK_UAFILEOBJECT_H

#include "uaclientsdk.h"

namespace UaClientSdk {

class UaFileObjectPrivate;
class UaSession;

/*! \addtogroup UaClientLibrary
*  @{
*/

/** This class is a proxy class for access to a FileType Object in the server
*
*/
class UACLIENT_EXPORT UaFileObject
{
    UA_DISABLE_COPY(UaFileObject);
    UaFileObject();
public:
    UaFileObject(UaSession* pSession);
    virtual ~UaFileObject();

    void attachToOpenFile(
        const UaNodeId&     fileObjectNodeId,
        OpcUa_UInt32        fileHandle);

    // FileType methods
    UaStatus open(
        ServiceSettings&    serviceSettings,
        const UaNodeId&     fileObjectNodeId,
        OpcUa_Byte          mode);
    UaStatus close(
        ServiceSettings&    serviceSettings);
    UaStatus read(
        ServiceSettings&    serviceSettings,
        OpcUa_Int32         length,
        UaByteString&       data);
    UaStatus write(
        ServiceSettings&    serviceSettings,
        const UaByteString& data);
    UaStatus getPosition(
        ServiceSettings&    serviceSettings,
        OpcUa_UInt64&       position);
    UaStatus setPosition(
        ServiceSettings&    serviceSettings,
        OpcUa_UInt64        position);

    OpcUa_UInt32 fileHandle() const;
    UaNodeId     fileObjectNodeId() const;
private:
    /** UaFileObject data */
    UaFileObjectPrivate* d;
};
/*! @} */
}

#endif // UACLIENTSDK_UAFILEOBJECT_H
