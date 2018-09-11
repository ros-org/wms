/******************************************************************************
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
** Project: C++ OPC Client SDK
**
** Description: Class implements trace functionality.
**
******************************************************************************/
#ifndef LIBTRACE_H
#define LIBTRACE_H

#include "uatrace.h"
#include "uaclientsdk.h"

class UACLIENT_EXPORT LibT : public UaTrace
{
public:
    /**
    * construction / destruction
    */
    LibT(void);
    ~LibT(void);

    static void setTraceActive(bool isActive);
    static bool isTraceActive();

    static void setStackTraceActive(bool isActive);

    static void lError( const char * fmt, ...);
    static void lWarning( const char * fmt, ...);
    static void lInfo( const char * fmt, ...);
    static void lIfCall(const char * fmt, ...);
    static void lCtor(const char * fmt, ...);
    static void lInOut(const char * fmt, ...);
    static void lData(const char * fmt, ...);

    static void traceInternalString(TraceLevel traceLevel, const char * sContent);

private:
    static bool s_isTraceActive;
};

#ifdef __cplusplus
extern "C"
{
#endif
OPCUA_IMPORT extern OpcUa_P_TraceHook g_OpcUa_P_TraceHook;
#ifdef __cplusplus
}
#endif

OpcUa_Void OPCUA_DLLCALL OpcUaStackTrace(const OpcUa_CharA* a_sMessage);

#endif // LIBTRACE_H
