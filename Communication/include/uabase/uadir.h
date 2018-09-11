/******************************************************************************
** uadir.h
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
** Class for providing access to directory structures and their contents
**
******************************************************************************/
#ifndef __UADIR_H__
#define __UADIR_H__

#include <opcua_proxystub.h>
#include "uaunistring.h"
#include "uaplatformdefs.h"

/** UaDir
 *  @brief The UaDir class provides access to directory structures and their contents.
 *  A UaDir is used to manipulate path names, access information
 *  regarding paths and files, and manipulate the underlying file
 *  system. UA uses "/" as a universal directory separator in the same way
 *  that "/" is used as a path separator in URLs. If you always use
 *  "/" as a directory separator, UA will translate your paths to
 *  conform to the underlying operating system.
 *  A UaDir can point to a file using either a relative or an absolute
 *  path. Absolute paths begin with the directory separator
 *  (optionally preceded by a drive specification under Windows).
 *  Relative file names begin with a directory name or a file name and
 *  specify a path relative to the current directory.
 *  Examples of absolute paths:
 *  \code
 *      UaDir("/home/user/Documents")
 *      UaDir("C:/Documents and Settings")
 *  \endcode
 *  On Windows, the second of the examples above will be translated to
 *  {C:\\My Documents} when used to access files.
 *  Examples of relative paths:
 *  \code
 *      UaDir("images/landscape.png")
 *  \endcode
 */
class UABASE_EXPORT UaDir
{
public:

    /** This enum describes the filtering options available to UaDir; e.g.
     *  for entryList(). The filter value is specified
     *  by combining values from the following list using the bitwise OR operator:
     */
    enum Filters
    {
        NoFilter        = 0,    /*!< no filter */
        Dirs            = 1,    /*!< List directories that match the filters. */
        Files           = 2,    /*!< List files only. */
        Drives          = 4,    /*!< List disk drives (ignored under Unix). */
        NoSymLinks      = 8,    /*!< Do not list symbolic links (ignored by operating systems that don't support symbolic links). */
        NoDotAndDotDot  = 16,   /*!< Do not list the special entries "." and "..". */
        Readable        = 32,   /*!< List files for which the application has read
                                     access. The Readable value needs to be combined with Dirs or Files. */
        Writeable       = 64,   /*!< List files for which the application has write
                                     access. The Writable value needs to be combined with Dirs or Files. */
        Executable      = 128   /*!< List files for which the application has
                                     execute access. The Executable value needs to be combined with Dirs or Files. */
    };

    /** This enum describes the sort options available to UaDir, e.g. for
     *  entryList(). The sort value is specified by OR-ing together values from the following list:
     */
    enum SortFlags
    {
        NoSort  = 0,        /*!< Do not sort. */
        Name    = 1,        /*!< Sort by name. */
        Time    = 2,        /*!< Sort by time (modification time). */
        Size    = 4         /*!< Sort by file size. */
    };

    UaDir(const UaUniString &sPath);
    ~UaDir();

    /** Get the path.
     *  @return the path.
     */
    inline UaUniString getPath() const { return m_sPath; }

    UaUniString canonicalPath() const;
    UaUniString filePath(const UaUniString &sFileName) const;

    UaUniStringList entryList(const UaUniString &sPath, int filters = UaDir::NoFilter, int sort = UaDir::NoSort) const;

    bool cd(const UaUniString &sDirName);
    bool copy(const UaUniString &fileName, const UaUniString &newName);
    bool createFile(const UaUniString &sPath, const UaUniString &sFileName);
    bool isRelativePath(const UaUniString &sPath) const;
    bool link(const UaUniString &fileName, const UaUniString &newName);
    bool mkdir(const UaUniString &sDirName) const;
    bool mkpath(const UaUniString &sDirName) const;
    bool remove(const UaUniString &sFileName);
    bool rename(const UaUniString &sOldName, const UaUniString &sNewName);
    bool rmdir(const UaUniString &sDirName) const;
    bool rmpath(const UaUniString &sDirPath) const;
    bool exists(const UaUniString &sPath) const;

    OpcUa_UInt16 count(const UaUniString &sPath) const;
    OpcUa_UInt16 recursiveFileCount(const UaUniString &sPath) const;

    static UaUniString applicationDataPath();
    static UaUniString homePath();
    static UaUniString systemApplicationDataPath();
    static UaUniString fromNativeSeparators(const UaUniString &sPathName);
    static UaUniString toNativeSeparators(const UaUniString &sPathName);

    static UaChar   separator();

private:
    // default construction
    UaDir();
    // the path
    UaUniString m_sPath;    // store the current path with '/' separators
};

#endif // #ifndef __UADIR_H__
