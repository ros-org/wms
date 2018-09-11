/******************************************************************************
** opcua_filetypebase.h
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

#ifndef __OPCUA_FILETYPEBASE_H__
#define __OPCUA_FILETYPEBASE_H__

#include "opcua_baseobjecttype.h"
#include "basenodes.h"
#include "opcua_identifiers.h"
#include "opcua_propertytype.h"
#include "uaargument.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;

/** Generated base class for a FileType.
 *
 *  This class contains the generated base code for the object type FileType
 *  representing an OPC UA ObjectType. This class is used to create the object type and to
 *  create and represent instances of the object type in the server address space.
 *
 *  **Variable members of the FileType:**
 *
 *  Browse Name  | DataType | TypeDefinition | Modelling Rule | See Also
 *  -------------|----------|----------------|----------------|-------------------------------------------
 *  MimeType     | String   | PropertyType   | Optional       | \ref getMimeType, \ref setMimeType
 *  OpenCount    | UInt16   | PropertyType   | Mandatory      | \ref getOpenCount, \ref setOpenCount
 *  Size         | UInt64   | PropertyType   | Mandatory      | \ref getSize, \ref setSize
 *  UserWritable | Boolean  | PropertyType   | Mandatory      | \ref getUserWritable, \ref setUserWritable
 *  Writable     | Boolean  | PropertyType   | Mandatory      | \ref getWritable, \ref setWritable
 *
 *  This ObjectType defines a type for files.
 *
 *  Note that all methods on a file require a FileHandle, which is returned in the
 *  \ref OpcUa::FileType::Open "Open" method.
 *
 *  See also \ref Doc_OpcUa_FileType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT FileTypeBase:
    public OpcUa::BaseObjectType
{
    UA_DISABLE_COPY(FileTypeBase);
protected:
    virtual ~FileTypeBase();
public:
    // construction / destruction
    FileTypeBase(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    FileTypeBase(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    FileTypeBase(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;


    //- Interface MethodManager -----------------------------------------------------------
    /** Call method of an UA object. */
    virtual UaStatus beginCall(
        MethodManagerCallback* pCallback,
        const ServiceContext&  serviceContext,
        OpcUa_UInt32           callbackHandle,
        MethodHandle*          pMethodHandle,
        const UaVariantArray&  inputArguments);
    virtual UaStatus call(
        const ServiceContext&  serviceContext,
        MethodHandle*          pMethodHandle,
        const UaVariantArray&  inputArguments,
        UaVariantArray&        outputArguments,
        UaStatusCodeArray&     inputArgumentResults,
        UaDiagnosticInfos&     inputArgumentDiag);
    //- Interface MethodManager -----------------------------------------------------------


    /**
     *  Closes a file represented by a \ref OpcUa::FileType "FileType".
     *
     *  When a client closes a file, the handle becomes invalid.
     */
    virtual UaStatus Close(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        OpcUa_UInt32 FileHandle /**<[in] A handle returned by the \ref OpcUa::FileType::Open "Open" method, indicating
            the access request and thus indirectly the position inside the file. */) = 0;

    /**
     *  Provides the current position of the FileHandle.
     */
    virtual UaStatus GetPosition(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        OpcUa_UInt32 FileHandle /**<[in] A handle returned by the \ref OpcUa::FileType::Open "Open" method, indicating
            the access request and thus indirectly the position inside the file. */,
        OpcUa_UInt64& Position /**<[out] The position of the FileHandle in the file.
            <br>
            If \ref OpcUa::FileType::Read "Read" or \ref OpcUa::FileType::Write "Write" is
            called, it starts at that position. */) = 0;

    /**
     *  Opens a file represented by an object of \ref OpcUa::FileType "FileType".
     *
     *  When a client opens a file, it gets a FileHandle that is valid while the
     *  session is open. Clients shall use the \ref OpcUa::FileType::Close "Close"
     *  method to release the handle when they do not need access to the file anymore.
     *  Clients can open the same file several times for reading. A request to open for
     *  writing shall return Bad_NotWritable when the file is already opened.
     */
    virtual UaStatus Open(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        OpcUa_Byte Mode /**<[in] Indicates whether the file should be opened only for read operations or for
            read and write operations and where the initial position is set.
            <br>
            The mode is an 8-bit unsigned integer used as bit mask with the structure
            defined in the following table:
            <br>
            Field          | Bit | Description
            ---------------|-----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            Read           | 0   | The file is opened for reading. If this bit is not set the \ref OpcUa::FileType::Read "Read" method cannot be executed.
            Write          | 1   | The file is opened for writing. If this bit is not set the \ref OpcUa::FileType::Write "Write" method cannot be executed.
            EraseExisting  | 2   | This bit can only be set if the file is opened for writing (Write bit is set). The existing content of the file is erased and an empty file is provided.
            Append         | 3   | When the Append bit is set the file is opened at end of the file, otherwise at begin of the file. The \ref OpcUa::FileType::SetPosition "SetPosition" Method can be used to change the position. */,
        OpcUa_UInt32& FileHandle /**<[out] A handle for the file used in other method calls indicating not the file (this
            is done by the object of the method call) but the access request and thus the
            position in the file.
            <br>
            The FileHandle is generated by the server and is unique for the Session.
            Clients cannot transfer the FileHandle to another Session but need to get a new
            FileHandle by calling the \ref OpcUa::FileType::Open "Open" method. */) = 0;

    /**
     *  Reads a part of the file starting from the current file position.
     *
     *  The file position is advanced by the number of bytes read.
     */
    virtual UaStatus Read(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        OpcUa_UInt32 FileHandle /**<[in] A handle returned by the \ref OpcUa::FileType::Open "Open" method, indicating
            the access request and thus indirectly the position inside the file. */,
        OpcUa_Int32 Length /**<[in] Defines the length in bytes that should be returned in data, starting from the
            current position of the file handle.
            <br>
            If the end of file is reached, all data until the end of the file is returned.
            The Server is allowed to return less data than the specified length. Only
            positive values are allowed. */,
        UaByteString& Data /**<[out] Contains the returned data of the file.
            <br>
            If the ByteString is empty, it indicates that the end of the file is reached. */) = 0;

    /**
     *  Sets the current position of the FileHandle.
     */
    virtual UaStatus SetPosition(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        OpcUa_UInt32 FileHandle /**<[in] A handle indicating the access request and thus indirectly the position inside
            the file. */,
        OpcUa_UInt64 Position /**<[in] The position to be set for the FileHandle in the file.
            <br>
            If \ref OpcUa::FileType::Read "Read" or \ref OpcUa::FileType::Write "Write" is
            called, it starts at that position. If the position is higher than the file
            size, the position is set to the end of the file. */) = 0;

    /**
     *  Writes a part of the file starting from the current file position.
     *
     *  The file position is advanced by the number of bytes written
     */
    virtual UaStatus Write(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        OpcUa_UInt32 FileHandle /**<[in] A handle returned by the \ref OpcUa::FileType::Open "Open" method, indicating
            the access request and thus indirectly the position inside the file. */,
        UaByteString& Data /**<[in] Contains the data to be written at the position of the file.
            <br>
            It is server-dependent whether the written data are persistently stored if the
            session is ended without calling the \ref OpcUa::FileType::Close "Close" method
            with the FileHandle.
            <br>
            Writing an empty or null ByteString returns a Good result code without any
            effect on the file. */) = 0;

    virtual void setMimeType(const UaString& MimeType);
    virtual UaString getMimeType() const;

    virtual void setOpenCount(OpcUa_UInt16 OpenCount);
    virtual OpcUa_UInt16 getOpenCount() const;

    virtual void setSize(OpcUa_UInt64 Size);
    virtual OpcUa_UInt64 getSize() const;

    virtual void setUserWritable(OpcUa_Boolean UserWritable);
    virtual OpcUa_Boolean getUserWritable() const;

    virtual void setWritable(OpcUa_Boolean Writable);
    virtual OpcUa_Boolean getWritable() const;

    virtual OpcUa::PropertyType* getMimeTypeNode();
    virtual OpcUa::PropertyType* getOpenCountNode();
    virtual OpcUa::PropertyType* getSizeNode();
    virtual OpcUa::PropertyType* getUserWritableNode();
    virtual OpcUa::PropertyType* getWritableNode();
    virtual OpcUa::BaseMethod* getClose();
    virtual OpcUa::BaseMethod* getGetPosition();
    virtual OpcUa::BaseMethod* getOpen();
    virtual OpcUa::BaseMethod* getRead();
    virtual OpcUa::BaseMethod* getSetPosition();
    virtual OpcUa::BaseMethod* getWrite();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(FileTypeBase *pInstance);

protected:
    // Variable nodes
    // Variable MimeType
    static OpcUa::PropertyType*  s_pMimeType;
    OpcUa::PropertyType*  m_pMimeType;
    // Variable OpenCount
    static OpcUa::PropertyType*  s_pOpenCount;
    OpcUa::PropertyType*  m_pOpenCount;
    // Variable Size
    static OpcUa::PropertyType*  s_pSize;
    OpcUa::PropertyType*  m_pSize;
    // Variable UserWritable
    static OpcUa::PropertyType*  s_pUserWritable;
    OpcUa::PropertyType*  m_pUserWritable;
    // Variable Writable
    static OpcUa::PropertyType*  s_pWritable;
    OpcUa::PropertyType*  m_pWritable;


    // Method nodes
    static OpcUa::BaseMethod* s_pCloseMethod;
    OpcUa::BaseMethod*  m_pCloseMethod;
    static OpcUa::BaseMethod* s_pGetPositionMethod;
    OpcUa::BaseMethod*  m_pGetPositionMethod;
    static OpcUa::BaseMethod* s_pOpenMethod;
    OpcUa::BaseMethod*  m_pOpenMethod;
    static OpcUa::BaseMethod* s_pReadMethod;
    OpcUa::BaseMethod*  m_pReadMethod;
    static OpcUa::BaseMethod* s_pSetPositionMethod;
    OpcUa::BaseMethod*  m_pSetPositionMethod;
    static OpcUa::BaseMethod* s_pWriteMethod;
    OpcUa::BaseMethod*  m_pWriteMethod;


private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUAFILETYPEBASE_H__


