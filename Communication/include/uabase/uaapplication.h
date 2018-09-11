/******************************************************************************
** uaapplication.h
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
#ifndef __UAAPPLICATION_H__
#define __UAAPPLICATION_H__

//#define USE_EVENTLOG

#ifdef _WIN32
#  if defined(_WIN32_WCE)
#    define SHUTDOWN_SEQUENCE "Escape"
#  else //defined(_WIN32_WCE)
// Uncomment the following line to use CTRL-C on Windows to shutdown
//#define UAAPPLICATION_USE_CTRLC_ON_WINDOWS
#    if defined(UAAPPLICATION_USE_CTRLC_ON_WINDOWS)
#      define SHUTDOWN_SEQUENCE "CTRL-C"
#    else //defined(UAAPPLICATION_USE_CTRLC_ON_WINDOWS)
#      define SHUTDOWN_SEQUENCE "x"
#    endif //defined(UAAPPLICATION_USE_CTRLC_ON_WINDOWS)
#  endif //defined(_WIN32_WCE)
#else
#  define SHUTDOWN_SEQUENCE "CTRL-C"
#endif

#if defined(WIN32)
#  ifndef WIN32_LEAN_AND_MEAN
/* Always define WIN32_LEAN_AND_MEAN to prevent windows.h from including
 * winsock.h which leads to conflicts with winsock2.h */
#    define WIN32_LEAN_AND_MEAN
#  endif
#include <windows.h>
extern "C"
{
    void WINAPI UaApplication_SvcMain(DWORD, LPTSTR*);
    void WINAPI UaApplication_SvcCtrlHandler(DWORD);
#if defined(UAAPPLICATION_USE_CTRLC_ON_WINDOWS)
    BOOL WINAPI UaApplication_CtrlHandler(DWORD);
#endif //defined(UAAPPLICATION_USE_CTRLC_ON_WINDOWS)
}
#endif //defined(WIN32)
#if defined(__linux__)
    void UaApplication_CbSigIntTerm(int);
#endif //defined(__linux__)

#include <uabase.h>
#include <uastring.h>

class UABASE_EXPORT UaApplication
{
    UA_DISABLE_COPY(UaApplication);
public:
    UaApplication();
    UaApplication(int argc, char* argv[], bool bRunAsService, const UaString &sApplicationName);
    virtual ~UaApplication();

    static int initEnvironment();
    static void cleanupEnvironment();

    // Main routine, calls main() of subclass
    int run();

    /** System message level enumeration defining the trace level for system event log. */
    enum SystemMessageLevel
    {
        SystemMessageLevel_Error, /*!< Error level for system event log. */
        SystemMessageLevel_Warning, /*!< Warning level for system event log. */
        SystemMessageLevel_Info /*!< Info level for system event log. */
    };
    void logSystemMessage(SystemMessageLevel traceLevel, const char *szMessage, ...);

    static UaString getApplicationPath();

protected:
    virtual int main() = 0;
    bool shutdownFlag() const;

    int         m_argc;
    char      **m_argv;
    bool        m_bRunAsService;
    UaString    m_sApplicationName;

private:
    // Utility
    int registerService();
    int unregisterService();

    int registerSyslog();
    int unregisterSyslog();

    int initSyslog();
    int clearSyslog();

    void registerSignalHandlers();

    bool m_bShutdown;

#if defined(WIN32)
    TCHAR* getApplicationFilePath() const;
    TCHAR* getApplicationName() const;

    HANDLE m_hEventLog;

    friend void WINAPI UaApplication_SvcMain(DWORD, LPTSTR*);
    friend void WINAPI UaApplication_SvcCtrlHandler(DWORD);
#if defined(UAAPPLICATION_USE_CTRLC_ON_WINDOWS)
    friend BOOL WINAPI UaApplication_CtrlHandler(DWORD);
#endif //defined(UAAPPLICATION_USE_CTRLC_ON_WINDOWS)
#endif //defined(WIN32)
#if defined(__linux__)
    int daemonize(bool &bContinue);
    char* pidFileName() const;

    friend void UaApplication_CbSigIntTerm(int);
#endif //defined(__linux__)
};

#endif /* __UAAPPLICATION_H__ */
