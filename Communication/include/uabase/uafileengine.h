/******************************************************************************
** uafileengine.h
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
** Project: C++ OPC SDK base module
**
** Unix implementation for file handling.
**
******************************************************************************/

#include "uaabstractfileengine.h"
#include "uavariant.h"
#include "uaunistringlist.h"
#include "uadir.h"


/** @ingroup CppBaseLibraryClass
 *  \todo Add documentation
 */
class UaFileEngine : public UaAbstractFileEngine
{
public:
    UaFileEngine();
    virtual ~UaFileEngine();

    virtual bool remove(const UaUniString &sFileName) const;
    virtual bool copy(const UaUniString &fileName, const UaUniString &newName) const;
    virtual bool rename(const UaUniString &fileName, const UaUniString &newName) const;
    virtual bool link(const UaUniString &fileName, const UaUniString &newName) const;
    virtual bool mkdir(const UaUniString &dirName) const;
    virtual bool rmdir(const UaUniString &dirName) const;
    virtual bool caseSensitive() const;
    virtual bool isRelativePath(const UaUniString &sPath) const;
    virtual bool cd(const UaUniString &sDirName) const;
    virtual bool createFile(const UaUniString &sPath, const UaUniString &sFileName) const;
    virtual bool exists(const UaUniString &sPath) const;

    virtual FILE* openFile(const UaUniString &fileName, const UaUniString &mode) const;
    virtual OpcUa_Int64 writeFile(const void *pData, OpcUa_Int64 size, OpcUa_Int64 count, FILE *pFile) const;
    virtual OpcUa_Int64 readFile(void *ptr, OpcUa_Int64 size, OpcUa_Int64 count, FILE *pFile) const;
    virtual OpcUa_Int64 readLine(char* pData, OpcUa_Int64 maxSize, FILE *pFile) const;
    virtual OpcUa_Int64 pos(FILE *pFile) const;
    virtual bool seek(OpcUa_Int64 pos, FILE* pFile, int origin) const;
    virtual bool flush(FILE* pFile) const;
    virtual bool closeFile(FILE *pFile) const;
    virtual OpcUa_Int64 getFileSize(const UaUniString &fileName) const;

    virtual UaUniStringList entryList(const UaUniString &sPath, int filters = UaDir::NoFilter, int sort = UaDir::NoSort) const;

    virtual UaUniString canonicalPath(const UaUniString &sPath) const;

    virtual UaUniString homePath() const;
    virtual UaUniString applicationDataPath() const;
    virtual UaUniString systemApplicationDataPath() const;

    virtual OpcUa_UInt16 count(const UaUniString &sPath) const;

private:

};
