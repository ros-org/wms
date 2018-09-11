/******************************************************************************
** opcua_filetype.h
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
** Project: C++ OPC Server SDK information model for namespace http://opcfoundation.org/UA/
**
** Description: OPC Unified Architecture Software Development Kit.
**
******************************************************************************/

#ifndef __OPCUA_FILETYPE_H__
#define __OPCUA_FILETYPE_H__

#include "opcua_filetypebase.h"
#include "uafile.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

/** @brief Class implementing the UaObject interface for the FileType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Variable members of the FileType:**
 *
 *  Browse Name  | DataType | TypeDefinition | Modelling Rule | See Also
 *  -------------|----------|----------------|----------------|-----------------------------------------------------------------------------------------------------------
 *  MimeType     | String   | PropertyType   | Optional       | \ref FileTypeBase::getMimeType "getMimeType", \ref FileTypeBase::setMimeType "setMimeType"
 *  OpenCount    | UInt16   | PropertyType   | Mandatory      | \ref FileTypeBase::getOpenCount "getOpenCount", \ref FileTypeBase::setOpenCount "setOpenCount"
 *  Size         | UInt64   | PropertyType   | Mandatory      | \ref FileTypeBase::getSize "getSize", \ref FileTypeBase::setSize "setSize"
 *  UserWritable | Boolean  | PropertyType   | Mandatory      | \ref FileTypeBase::getUserWritable "getUserWritable", \ref FileTypeBase::setUserWritable "setUserWritable"
 *  Writable     | Boolean  | PropertyType   | Mandatory      | \ref FileTypeBase::getWritable "getWritable", \ref FileTypeBase::setWritable "setWritable"
 *
 *  **Method members of the FileType:**
 *
 *  Browse Name      | Modelling Rule
 *  -----------------|---------------
 *  \ref Close       | Mandatory
 *  \ref GetPosition | Mandatory
 *  \ref Open        | Mandatory
 *  \ref Read        | Mandatory
 *  \ref SetPosition | Mandatory
 *  \ref Write       | Mandatory
 *
 *  This ObjectType defines a type for files.
 *
 * The FileType is used to give an OPC UA client access to a file managed by the OPC UA server.
 * After creating a FileType object in the server, the path to the file can be set with FileType::setFilePath
 *
 * By default the FileType uses the class UaFile for all file access operations. The default behaviour of UaFile
 * can be changed by overwriting FileType::createFileAccessObject. This allows to create a own implementation of
 * UaFile with the application specific behaviour.
 *
 * The maximum size of the file a client can write to can be limited with FileType::setMaxFileSize. The write access
 * can be set with FileTypeBase::setWritable.
 *
 *  Note that all Methods on a file require a FileHandle, which is returned in the
 *  \ref OpcUa::FileType::Open "Open" Method.
 *
 *  See also \ref Doc_OpcUa_FileType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT FileType:
    public FileTypeBase
{
    UA_DISABLE_COPY(FileType);
protected:
    virtual ~FileType();
public:
    FileType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    FileType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    FileType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();
    void decrementOpenCount(bool isWriteModeIncluded);

    // File name access
    UaString filePath() const;
    bool setFilePath(const UaString& sFilePath);

    // File size limitation
    OpcUa_UInt64 maxFileSize() const;
    void setMaxFileSize(OpcUa_UInt64 maxFileSize);

    // UaFileType method Close
    virtual UaStatus Close(
        const ServiceContext& serviceContext,
        OpcUa_UInt32 FileHandle);
    // UaFileType method GetPosition
    virtual UaStatus GetPosition(
        const ServiceContext& serviceContext,
        OpcUa_UInt32 FileHandle,
        OpcUa_UInt64& Position);
    // UaFileType method Open
    virtual UaStatus Open(
        const ServiceContext& serviceContext,
        OpcUa_Byte Mode,
        OpcUa_UInt32& FileHandle);
    // UaFileType method Read
    virtual UaStatus Read(
        const ServiceContext& serviceContext,
        OpcUa_UInt32 FileHandle,
        OpcUa_Int32 Length,
        UaByteString& Data);
    // UaFileType method SetPosition
    virtual UaStatus SetPosition(
        const ServiceContext& serviceContext,
        OpcUa_UInt32 FileHandle,
        OpcUa_UInt64 Position);
    // UaFileType method Write
    virtual UaStatus Write(
        const ServiceContext& serviceContext,
        OpcUa_UInt32 FileHandle,
        UaByteString& Data);

protected:
    // Allows overwriting of default behaviour
    virtual UaFile* createFileAccessObject(Session* pSession, const UaString& sFileName);
    virtual OpcUa_Boolean checkUserAccess(Session* pSession, UaIODevice::OpenMode openMode);
    virtual UaFile* getFileAccessObject(OpcUa_UInt32 fileHandle);

protected:
    UaString      m_sFilePath;
    OpcUa_UInt64  m_maxFileSize;
    OpcUa_UInt16  m_readCount;
    OpcUa_UInt16  m_writeCount;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUAFILETYPE_H__


