/******************************************************************************
** uaabstractfileengine.h
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
** Abstract base class for file handling.
**
******************************************************************************/
#ifndef __UAABSTRACTFILEENGINE_H__
#define __UAABSTRACTFILEENGINE_H__

#include <opcua_proxystub.h>
#include "uaunistring.h"
#include "uadir.h"

class UABASE_EXPORT UaAbstractFileEngine
{
public:
    UaAbstractFileEngine() {}
    virtual ~UaAbstractFileEngine() {}

    virtual bool remove(const UaUniString &sFileName) const = 0;
    virtual bool copy(const UaUniString &fileName, const UaUniString &newName) const = 0;
    virtual bool rename(const UaUniString &fileName, const UaUniString &newName) const = 0;
    virtual bool link(const UaUniString &fileName, const UaUniString &newName) const = 0;
    virtual bool mkdir(const UaUniString &dirName) const = 0;
    virtual bool rmdir(const UaUniString &dirName) const = 0;
    virtual bool caseSensitive() const = 0;
    virtual bool isRelativePath(const UaUniString &sPath) const = 0;
    virtual bool cd(const UaUniString &sDirName) const = 0;
    virtual bool createFile(const UaUniString &sPath, const UaUniString &sFileName) const = 0;
    virtual bool exists(const UaUniString &sPath) const = 0;

    virtual FILE* openFile(const UaUniString &fileName, const UaUniString &mode) const = 0;
    virtual OpcUa_Int64 writeFile(const void *pData, OpcUa_Int64 size, OpcUa_Int64 count, FILE *pFile) const = 0;
    virtual OpcUa_Int64 readFile(void *ptr, OpcUa_Int64 size, OpcUa_Int64 count, FILE *pFile) const = 0;
    virtual OpcUa_Int64 readLine(char* pData, OpcUa_Int64 maxSize, FILE *pFile) const = 0;
    virtual OpcUa_Int64 pos(FILE* pFile) const = 0;
    virtual bool seek(OpcUa_Int64 pos, FILE* pFile, int origin = SEEK_SET) const = 0;
    virtual bool flush(FILE* pFile) const = 0;
    virtual bool closeFile(FILE* pFile) const = 0;
    virtual OpcUa_Int64 getFileSize(const UaUniString &fileName) const = 0;

    virtual UaUniString canonicalPath(const UaUniString &sPath) const = 0;

    virtual UaUniStringList entryList(const UaUniString &sPath, int filters = UaDir::NoFilter, int sort = UaDir::NoSort) const = 0;

    virtual OpcUa_UInt16 count(const UaUniString &sPath) const = 0;

    virtual UaUniString homePath() const = 0;
    virtual UaUniString applicationDataPath() const = 0;
    virtual UaUniString systemApplicationDataPath() const = 0;

    // Factory method
    static UaAbstractFileEngine* create();
    static void clear();

private:
    static UaAbstractFileEngine *s_pInstance;
};

#endif /* __UAABSTRACTFILEENGINE_H__ */
