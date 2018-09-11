/******************************************************************************
** uatrace.h
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
** Class provides trace functionality.
**
******************************************************************************/
#ifndef UATRACE_H
#define UATRACE_H

#include "uadatetime.h"
#include "uamutex.h"
#include "uavariant.h"
#include "uastring.h"
#include "uaplatformdefs.h"
#include <list>

class UABASE_EXPORT UaTraceHook;

/** @ingroup CppBaseLibraryClass
 *  A class used for trace outputs (error, information,...).
 */
class UABASE_EXPORT UaTrace
{
public:
    /// @brief Definition of the TraceLevel Enumeration
    enum TraceLevel {
        NoTrace = 0,    /*!< Trace_Level: No Trace */
        Errors,         /*!< Trace_Level: Unexpected errors */
        Warning,        /*!< Trace_Level: Unexpected behaviour that is not an error */
        Info,           /*!< Trace_Level: Information about important activities like connection establishment */
        InterfaceCall,  /*!< Trace_Level: Calls to module interfaces */
        CtorDtor,       /*!< Trace_Level: Creation and destruction of objects */
        ProgramFlow,    /*!< Trace_Level: Internal program flow */
        Data            /*!< Trace_Level: Data */
    };

    UaTrace();
    virtual ~UaTrace();

    static long initTrace(
        TraceLevel      traceLevel,
        unsigned int    maxTraceEntries,
        unsigned int    NumBackupFiles,
        const UaString& traceFile,
        const UaString& appName);
    static long changeTrace(
        TraceLevel      traceLevel,
        unsigned int    maxTraceEntries,
        unsigned int    NumBackupFiles,
        const UaString& traceFile);
    static long initErrorTrace(
        const UaString& traceFile,
        const UaString& appName);
    static void setPreFileTrace(
        bool            isActive,
        TraceLevel      traceLevel);
    static long setProductVersion(const UaString& appVersion);
    static void addTraceHeaderEntry(const UaString& traceHeaderEntry);
    static TraceLevel getTraceLevel();
    static void setLocalTimeOutput(bool isLocal);
    static void setPrintDateInTrace(bool printDateInTrace);
    static void setTraceHook(UaTraceHook* pTraceHook);
    static void setErrorTraceHook(UaTraceHook* pErrorTraceHook);

    static bool getFlushDisabled();
    static void setFlushDisabled(bool bFlushDisabled);

    static bool getSkipTraceAfterHook();
    static void setSkipTraceAfterHook(bool bSkipTraceAfterHook);

    static void tError(const char * fmt,...);
    static void tWarning(const char * fmt,...);
    static void tInfo(const char * fmt,...);
    static void tIfCall(const char * fmt,...);
    static void tCtor(const char * fmt,...);
    static void tInOut(const char * fmt,...);
    static void tData(const char * fmt,...);

    static void flushTrace();
    static void closeTrace();

    static bool isInitialized();
    static std::list<UaString> getPreFileTraces();
    static void clearPreFileTraces();
    static void setMaxPreFileTraceEntries(unsigned int nMaxPreFileTraceEntries);

protected:
    static void trace( TraceLevel   traceLevel,
                       const char * fmt,
                       va_list      arg_ptr);
    static void traceOutput(TraceLevel traceLevel, const char * sContent, int nModule = 0, bool bFromUaStack = false);

protected:
    static UaMutex    * s_pLock;
    static TraceLevel   s_traceLevel;

private:
    static void copyFile(const UaString& oldName, const UaString& newName);
    static void buildBackupFileName( const UaString& originalName, unsigned int index, UaString& backupFileName);
    static void backupError();
    static void backupTrace();
    static void printHeader(FILE * pFile);

    static UaString*    s_pAppName;
    static UaString*    s_pAppVersion;
    static UaString*    s_pTraceFile;
    static FILE       * s_pfTrace;
    static UaString*    s_pErrorFile;
    static FILE       * s_pfError;
    static unsigned int s_nMaxTraceEntries;
    static unsigned int s_nNumBackupFiles;
    static unsigned int s_nCountTraceEntries;
    static unsigned int s_nCountErrorEntries;
    static bool         s_IsLocalTimeTrace;
    static bool         s_PrintDateInTrace;
    static bool         s_IsFlushDisabled;
    static bool         s_SkipTraceAfterHook;
    static UaTraceHook* s_pTraceHook;
    static UaTraceHook* s_pErrorTraceHook;
    static bool         s_IsPreFileTrace;
    static unsigned int s_nMaxPreFileTraceEntries;
    static std::list<UaString> s_preFileTraces;
    static std::list<UaString> s_fileHeaderEntries;
};


/** @ingroup CppBaseLibraryClass
 *  Interface used to register a trace hook
 */
class UABASE_EXPORT UaTraceHook
{
public:
    UaTraceHook(){}
    virtual ~UaTraceHook(){}

    virtual void traceOutput(UaTrace::TraceLevel traceLevel, const char * sContent, int nModule) = 0;
};

#endif // UATRACE_H
