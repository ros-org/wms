/******************************************************************************
** opcua_filedirectorytype.h
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

#ifndef __OPCUA_FILEDIRECTORYTYPE_H__
#define __OPCUA_FILEDIRECTORYTYPE_H__

#include "opcua_filedirectorytypebase.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class SERVER_CORE_EXPORT FileDirectoryType;

/** Callback interface for handling incoming FileDirectory Method calls
 */
class SERVER_CORE_EXPORT FileDirectoryTypeCallback
{
public:
    FileDirectoryTypeCallback(){}
    virtual ~FileDirectoryTypeCallback(){}

    /**
     *  Creates a new FileDirectoryType object organized by this object.
     *
     *  <b>Method Result Codes</b>
     *
     *  Result Code               | Description
     *  --------------------------|-----------------------------------------------------------------------
     *  Bad_BrowseNameDuplicated  | A directory with the name already exists.
     *  Bad_UserAccessDenied      | The user does not have permission to perform the requested operation.
     */
    virtual UaStatus CreateDirectory(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        const UaString& DirectoryName /**<[in] The name of the directory to create.
            <br>
            The name is used for the BrowseName and DisplayName of the directory object and
            also for the directory in the file system.
            <br>
            For the BrowseName, the directoryName is used for the name part of the
            QualifiedName. The namespace index is Server specific.
            <br>
            For the DisplayName, the directoryName is used for the text part of the
            LocalizedText. The locale part is Server specific. */,
        UaNodeId& DirectoryNodeId, /**<[out] The NodeId of the created directory object. */
        FileDirectoryType* pFileDirectory /**< Affected Object Node.*/
        ) = 0;

    /**
     *  Creates a new \ref OpcUa::FileType "FileType" object organized by this object.
     *
     *  The created file can be written using the \ref OpcUa::FileType::Write "Write"
     *  method of the \ref OpcUa::FileType "FileType".
     *
     *  <b>Method Result Codes</b>
     *
     *  Result Code               | Description
     *  --------------------------|-----------------------------------------------------------------------
     *  Bad_BrowseNameDuplicated  | A file with the name already exists.
     *  Bad_UserAccessDenied      | The user does not have permission to perform the requested operation.
     */
    virtual UaStatus CreateFile(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        const UaString& FileName /**<[in] The name of the file to create.
            <br>
            The name is used for the BrowseName and DisplayName of the file object and also
            for the file in the file system.
            <br>
            For the BrowseName, the FileName is used for the name part of the
            QualifiedName. The namespace index is Server specific.
            <br>
            For the DisplayName, the FileName is used for the text part of the
            LocalizedText. The locale part is Server specific. */,
        OpcUa_Boolean RequestFileOpen /**<[in] Flag indicating whether the new file should be opened with the Write and Read
            bits set in the open mode after the creation of the file.
            <br>
            If the flag is set to True, the file is created and opened for writing. If the
            flag is set to False, the file is just created. */,
        UaNodeId& FileNodeId /**<[out] The NodeId of the created file object. */,
        OpcUa_UInt32& FileHandle, /**<[out] The FileHandle is returned if RequestFileOpen is set to True.
            <br>
            The FileNodeId and the FileHandle can be used to access the new file through
            the \ref OpcUa::FileType "FileType" object representing the new file.
            <br>
            If RequestFileOpen is set to False, the returned value shall be 0 and shall be
            ignored by the caller. */
        FileDirectoryType* pFileDirectory /**< Affected Object Node.*/
        ) = 0;

    /**
     *  Deletes a file or directory organized by this object.
     *
     *  <b>Method Result Codes</b>
     *
     *  Result Code           | Description
     *  ----------------------|-------------------------------------------------------------------------------
     *  Bad_NotFound          | A file or directory with the provided NodeId is not organized by this object.
     *  Bad_InvalidState      | The file or directory is locked and thus cannot be deleted.
     *  Bad_UserAccessDenied  | The user does not have permission to perform the requested operation.
     */
    virtual UaStatus Delete(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        const UaNodeId& ObjectToDelete, /**<[in] The NodeId of the file or directory to delete.
            <br>
            In the case of a directory, all file and directory objects below the directory
            to delete are deleted recursively. */
        FileDirectoryType* pFileDirectory /**< Affected Object Node.*/
        ) = 0;

    /**
     *  Moves or copies a file or directory organized by this object to another
     *  directory or renames a file or directory.
     *
     *  <b>Method Result Codes</b>
     *
     *  Result Code               | Description
     *  --------------------------|-------------------------------------------------------------------------------
     *  Bad_BrowseNameDuplicated  | A file or directory with the name already exists.
     *  Bad_NotFound              | A file or directory with the provided NodeId is not organized by this object.
     *  Bad_InvalidState          | The file or directory is locked and thus cannot be moved or copied.
     *  Bad_UserAccessDenied      | The user does not have permission to perform the requested operation.
     */
    virtual UaStatus MoveOrCopy(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        const UaNodeId& ObjectToMoveOrCopy /**<[in] The NodeId of the file or directory to move or copy. */,
        const UaNodeId& TargetDirectory /**<[in] The NodeId of the target directory of the move or copy command.
            <br>
            If the file or directory is just renamed, the targetDirectory matches the
            ObjectId passed to the method call. */,
        OpcUa_Boolean CreateCopy /**<[in] A flag indicating whether a copy of the file or directory should be created at
            the target directory. */,
        const UaString& NewName /**<[in] The new name of the file or directory in the new location.
            <br>
            If the string is empty, the name is unchanged. */,
        UaNodeId& NewNodeId, /**<[out] The NodeId of the moved or copied object.
            <br>
            Even if the object is moved, the Server may return a new NodeId. */
        FileDirectoryType* pFileDirectory /**< Affected Object Node.*/
        ) = 0;
};

/** @brief Class implementing the UaObject interface for the FileDirectoryType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Object members of the FileDirectoryType:**
 *
 *  Browse Name           | Modelling Rule      | See Also
 *  ----------------------|---------------------|---------
 *  \<FileDirectoryName\> | OptionalPlaceholder | &nbsp;
 *  \<FileName\>          | OptionalPlaceholder | &nbsp;
 *
 *  **Method members of the FileDirectoryType:**
 *
 *  Browse Name          | Modelling Rule
 *  ---------------------|---------------
 *  \ref CreateDirectory | Mandatory
 *  \ref CreateFile      | Mandatory
 *  \ref Delete          | Mandatory
 *  \ref MoveOrCopy      | Mandatory
 *
 *  Defines a type for the representation of file directories.
 *
 *  It is expected that OPC UA Servers will create vendor specific subtypes of the
 *  \ref OpcUa::FileDirectoryType "FileDirectoryType" with additional
 *  functionalities like methods for creating symbolic links or setting access
 *  permissions. OPC UA Clients providing specialized file transfer user interfaces
 *  should be prepared to expose such additional methods to the user.
 *
 *  Instances of the ObjectType contain a list of \ref OpcUa::FileDirectoryType
 *  "FileDirectoryType" Objects representing the subdirectories of the file
 *  directory represented by the instance of this ObjectType.
 *
 *  Instances of the ObjectType contain a list of \ref OpcUa::FileType "FileType"
 *  Objects representing the files in the file directory represented by the
 *  instance of this ObjectType.
 *
 *  See also \ref Doc_OpcUa_FileDirectoryType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT FileDirectoryType:
    public FileDirectoryTypeBase
{
    UA_DISABLE_COPY(FileDirectoryType);
protected:
    // destruction
    virtual ~FileDirectoryType();
public:
    // construction
    FileDirectoryType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    FileDirectoryType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    FileDirectoryType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    void setCallback(FileDirectoryTypeCallback* pCallback);

    // UaFileDirectoryType method CreateDirectory
    virtual UaStatus CreateDirectory(
        const ServiceContext& serviceContext,
        const UaString& DirectoryName,
        UaNodeId& DirectoryNodeId);
    // UaFileDirectoryType method CreateFile
    virtual UaStatus CreateFile(
        const ServiceContext& serviceContext,
        const UaString& FileName,
        OpcUa_Boolean RequestFileOpen,
        UaNodeId& FileNodeId,
        OpcUa_UInt32& FileHandle);
    // UaFileDirectoryType method Delete
    virtual UaStatus Delete(
        const ServiceContext& serviceContext,
        const UaNodeId& ObjectToDelete);
    // UaFileDirectoryType method MoveOrCopy
    virtual UaStatus MoveOrCopy(
        const ServiceContext& serviceContext,
        const UaNodeId& ObjectToMoveOrCopy,
        const UaNodeId& TargetDirectory,
        OpcUa_Boolean CreateCopy,
        const UaString& NewName,
        UaNodeId& NewNodeId);

protected:

private:
    FileDirectoryTypeCallback* m_pCallback;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUAFILEDIRECTORYTYPE_H__

