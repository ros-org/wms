/******************************************************************************
** uaiodevice.h
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
#ifndef UAIODEVICE_H
#define UAIODEVICE_H

#include <opcua_platformdefs.h>
#include "uaplatformdefs.h"
#include "uabase.h"

/** The UaIODevice class is the base interface class of all I/O devices.*/
class UABASE_EXPORT UaIODevice
{
public:
    /** OpenMode enumeration  */
    enum OpenModeFlag
    {
        OpenModeNone = 0x00,
        OpenModeRead = 0x01,            /*!<  Open the file for reading.*/
        OpenModeWrite = 0x02,           /*!<  Open the file for writing. This creates a new file if the file does not exist.*/
        OpenModeEraseExisiting = 0x04,  /*!<  @deprecated Use OpenModeEraseExisting instead.*/
        OpenModeEraseExisting = 0x04,   /*!<  If the file is opened for writing the existing content of the file is erased and an empty file is provided.*/
        OpenModeAppend = 0x08,          /*!<  The file is opened at the end of the file.*/
        OpenModeText = 0x10             /*!<  Open the file in text mode - default is binary.*/
    };
    UA_DECLARE_FLAGS(OpenMode, OpenModeFlag)

    /** SeekMode enumeration  */
    enum SeekMode
    {
        SeekModeBeginning   = SEEK_SET, /*!<  Seek from beginning of the file.*/
        SeekModeCurrent     = SEEK_CUR, /*!<  Seek from current position.*/
        SeekModeEnd         = SEEK_END  /*!<  Seek the end of file.*/
    };

    UaIODevice();
    virtual ~UaIODevice();

    /** Open a file in the \a mode specified.
     *  Returns true on success; otherwise returns false.
     *  @param mode Indicates whether the file should be opened only for read operations or for read and write operations and where the initial position is set.
     *  @return         true if successful false if not.
     *  \sa close()
     */
    virtual OpcUa_Boolean open(OpenMode mode) = 0;

    /** Close a file the was opened before with \sa open()
    */
    virtual void close() = 0;

    /** Return the current position to read or write.
     *  Returns true on success; otherwise returns false.
     *  @return         true if successful false if not.
     */
    virtual OpcUa_Int64 pos() const = 0;
    /** Set the current position to the position specified.
     *  Returns true on success; otherwise returns false.
     *  @param pos      the position to set. If pos is bigger than the end of the file \a seek() sets the position to the end of the file.
     *  @param origin   the origin from where to start seeking. See \sa SeekMode. .
     *  @return         true if successful false if not.
     *  \sa pos()
     */
    virtual OpcUa_Boolean seek(OpcUa_Int64 pos, SeekMode origin) = 0;
    /** Returns the size of the file.
     *  @return     The number of bytes of the file size. Or -1 if the operation fails.
     */
    virtual OpcUa_Int64 size() const = 0;
    /** Reads data from a file opened with open().
     *  @param data     A buffer to store the read data.
     *  @param maxSize  The number of elements to read. One element has the size of one char.
     *  @return         The number of elements read. If this number differs from \a maxSize, either an error occured or the end of the file has been reached.
     *  \sa write()
     */
    virtual OpcUa_Int64 read(char* data, OpcUa_Int64 maxSize) = 0;
    /** Reads a line of characters from a file opened with open().
    *  @param data     A buffer to store the read data.
    *  @param maxSize  The number of elements to read. One element has the size of one char.
    *  @return         The length of what could be read or -1 if nothing was read.
    *  \sa read()
    */
    virtual OpcUa_Int64 readLine(char* data, OpcUa_Int64 maxSize) = 0;
    /** Write data to a file opened with open().
     *  @param data     A buffer to store the read data.
     *  @param size     The number of elements to write. One element has the size of one char.
     *  @return         The number of elements successfully written. If this number differs from \a size an error occured.
     *  \sa read()
     */
    virtual OpcUa_Int64 write(const char* data, OpcUa_Int64 size) = 0;

private:
};

#endif
