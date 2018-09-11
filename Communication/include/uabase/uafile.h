/******************************************************************************
** uafile.h
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
******************************************************************************/
#ifndef UAFILE_H
#define UAFILE_H

#include "uaiodevice.h"
#include "uastring.h"

/** The UaFile class provides an interface for reading from and writing to files.
 *
 * UaFile is an I/O device for reading and writing text and binary files.
 *
 * The file name is passed in the constructor.
 */
class UABASE_EXPORT UaFile : public UaIODevice
{
    UA_DISABLE_COPY(UaFile);
    UaFile();
public:
    UaFile(const UaString& sFileName);
    virtual ~UaFile();

    virtual OpcUa_Boolean open(UaIODevice::OpenMode mode);
    virtual void close();

    virtual OpcUa_Int64 pos() const;
    virtual OpcUa_Boolean seek(OpcUa_Int64 pos, UaIODevice::SeekMode origin = UaIODevice::SeekModeBeginning);
    virtual OpcUa_Int64 size() const;
    virtual OpcUa_Int64 read(char* data, OpcUa_Int64 maxSize);
    virtual OpcUa_Int64 readLine(char* data, OpcUa_Int64 maxSize);
    virtual OpcUa_Int64 write(const char* data, OpcUa_Int64 size);
    virtual OpcUa_Boolean flush();

private:
    enum LastOperation
    {
        LastOperationNone = 0x00,
        LastOperationRead = 0x01,
        LastOperationWrite = 0x02
    };
    UaString m_sFileName;
    FILE*    m_pFileHandle;
    OpcUa_Boolean m_bFileUpdateMode;
    OpcUa_Boolean m_bAllowRead;
    LastOperation m_lastOperation;
};

#endif
