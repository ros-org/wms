/******************************************************************************
** srvtrace.h
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
** Project: C++ OPC Server SDK core module
**
** Description: Class implements trace functionality.
**
******************************************************************************/
#ifndef SRVTRACE_H
#define SRVTRACE_H

#include "uatrace.h"

#define SERVER_UI     1
#define SERVER_CORE   2
#define UA_MODULE     3
#define COM_DA_MODULE 4
#define UA_STACK_T    5
#define UA_REDUNDANCY 6
#define COM_AE_MODULE 7

/** SrvT
 *  @brief Class definition of SrvT. Derived from UaTrace.
 *  Provides a set of methods and properties that help you trace the execution of your code.
 *  You can use the properties and methods in the Trace class to instrument release builds.
 *  Instrumentation allows you to monitor the health of your application running in real-life settings.
 *  Tracing helps you isolate problems and fix them without disturbing a running system.
 */
class UABASE_EXPORT SrvT : public UaTrace
{
public:
    /* construction */
    SrvT();
    /* destruction */
    ~SrvT();

    /*  Sets Trace to active.
     *  @param isActive true sets the Trace to active false to inactive.
     */
    static void setTraceActive(bool isActive);

    /*  Sets the stack Trace to active. Uses the same trace level like the server trace.
     *  @param isActive true sets the Trace to active false to inactive.
     */
    static void setStackTraceActive(bool isActive, OpcUa_UInt32 uTraceLevel);

    /*  Check whether Trace is active or not.
     *  @return TRUE if active FALSE if not.
     */
    static bool isTraceActive();

    /*  An Error trace for the output.
     *  @param fmt the message to be printed out.
     *  @param nModule name of the module.
     */
    static void sError(   int nModule, const char * fmt,...);

    /*  A Warning trace for the output.
     *  @param fmt the message to be printed out.
     *  @param nModule name of the module.
     */
    static void sWarning( int nModule, const char * fmt,...);

    /*  A Info trace for the output.
     *  @param fmt the message to be printed out.
     *  @param nModule name of the module.
     */
    static void sInfo(    int nModule, const char * fmt,...);

    /*  A Trace for Interface calls incoming or outgoing.
     *  @param fmt the message to be printed out.
     *  @param nModule name of the module.
     */
    static void sIfCall(  int nModule, const char * fmt,...);

    /*  A Trace for creating and deleting objects.
     *  @param fmt the message to be printed out.
     *  @param nModule name of the module.
     */
    static void sCtor(    int nModule, const char * fmt,...);

    /*  A Trace for Method incoming or outgoing.
     *  @param fmt the message to be printed out.
     *  @param nModule name of the module.
     */
    static void sInOut(   int nModule, const char * fmt,...);

    /*  A Data trace for the output.
     *  @param fmt the message to be printed out.
     *  @param nModule name of the module.
     */
    static void sData(    int nModule, const char * fmt,...);

    static void traceInternalString(TraceLevel traceLevel, const char * sContent, int nModule);

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

OpcUa_Void OPCUA_DLLCALL OpcUaStackTraceServer(const OpcUa_CharA* a_sMessage);

// This define is used to switch static trace text to unicode
#define UA_T

// trace macros for errors
#define TLEVEL_ERROR SrvT::Errors
#define TRACE0_ERROR(m,t)                    { if (SrvT::getTraceLevel() >= SrvT::Errors) SrvT::sError(m,t); }
#define TRACE1_ERROR(m,t,p1)                 { if (SrvT::getTraceLevel() >= SrvT::Errors) SrvT::sError(m,t,p1); }
#define TRACE2_ERROR(m,t,p1,p2)              { if (SrvT::getTraceLevel() >= SrvT::Errors) SrvT::sError(m,t,p1,p2); }
#define TRACE3_ERROR(m,t,p1,p2,p3)           { if (SrvT::getTraceLevel() >= SrvT::Errors) SrvT::sError(m,t,p1,p2,p3); }
#define TRACE4_ERROR(m,t,p1,p2,p3,p4)        { if (SrvT::getTraceLevel() >= SrvT::Errors) SrvT::sError(m,t,p1,p2,p3,p4); }
#define TRACE5_ERROR(m,t,p1,p2,p3,p4,p5)     { if (SrvT::getTraceLevel() >= SrvT::Errors) SrvT::sError(m,t,p1,p2,p3,p4,p5); }
#define TRACE6_ERROR(m,t,p1,p2,p3,p4,p5,p6)  { if (SrvT::getTraceLevel() >= SrvT::Errors) SrvT::sError(m,t,p1,p2,p3,p4,p5,p6); }

// trace macros for warnings
#define TLEVEL_WARNING SrvT::Warning
#define TRACE0_WARNING(m,t)                  { if (SrvT::getTraceLevel() >= SrvT::Warning) SrvT::sWarning(m,t); }
#define TRACE1_WARNING(m,t,p1)               { if (SrvT::getTraceLevel() >= SrvT::Warning) SrvT::sWarning(m,t,p1); }
#define TRACE2_WARNING(m,t,p1,p2)            { if (SrvT::getTraceLevel() >= SrvT::Warning) SrvT::sWarning(m,t,p1,p2); }
#define TRACE3_WARNING(m,t,p1,p2,p3)         { if (SrvT::getTraceLevel() >= SrvT::Warning) SrvT::sWarning(m,t,p1,p2,p3); }
#define TRACE4_WARNING(m,t,p1,p2,p3,p4)      { if (SrvT::getTraceLevel() >= SrvT::Warning) SrvT::sWarning(m,t,p1,p2,p3,p4); }
#define TRACE5_WARNING(m,t,p1,p2,p3,p4,p5)   { if (SrvT::getTraceLevel() >= SrvT::Warning) SrvT::sWarning(m,t,p1,p2,p3,p4,p5); }
#define TRACE6_WARNING(m,t,p1,p2,p3,p4,p5,p6){ if (SrvT::getTraceLevel() >= SrvT::Warning) SrvT::sWarning(m,t,p1,p2,p3,p4,p5,p6); }

// trace macros for information
#define TLEVEL_INFO SrvT::Info
#define TRACE0_INFO(m,t)                     { if (SrvT::getTraceLevel() >= SrvT::Info) SrvT::sInfo(m,t); }
#define TRACE1_INFO(m,t,p1)                  { if (SrvT::getTraceLevel() >= SrvT::Info) SrvT::sInfo(m,t,p1); }
#define TRACE2_INFO(m,t,p1,p2)               { if (SrvT::getTraceLevel() >= SrvT::Info) SrvT::sInfo(m,t,p1,p2); }
#define TRACE3_INFO(m,t,p1,p2,p3)            { if (SrvT::getTraceLevel() >= SrvT::Info) SrvT::sInfo(m,t,p1,p2,p3); }
#define TRACE4_INFO(m,t,p1,p2,p3,p4)         { if (SrvT::getTraceLevel() >= SrvT::Info) SrvT::sInfo(m,t,p1,p2,p3,p4); }
#define TRACE5_INFO(m,t,p1,p2,p3,p4,p5)      { if (SrvT::getTraceLevel() >= SrvT::Info) SrvT::sInfo(m,t,p1,p2,p3,p4,p5); }
#define TRACE6_INFO(m,t,p1,p2,p3,p4,p5,p6)   { if (SrvT::getTraceLevel() >= SrvT::Info) SrvT::sInfo(m,t,p1,p2,p3,p4,p5,p6); }

// trace macros for interface calls
#define TLEVEL_IFCALL SrvT::InterfaceCall
#define TRACE0_IFCALL(m,t)                   { if (SrvT::getTraceLevel() >= SrvT::InterfaceCall) SrvT::sIfCall(m,t); }
#define TRACE1_IFCALL(m,t,p1)                { if (SrvT::getTraceLevel() >= SrvT::InterfaceCall) SrvT::sIfCall(m,t,p1); }
#define TRACE2_IFCALL(m,t,p1,p2)             { if (SrvT::getTraceLevel() >= SrvT::InterfaceCall) SrvT::sIfCall(m,t,p1,p2); }
#define TRACE3_IFCALL(m,t,p1,p2,p3)          { if (SrvT::getTraceLevel() >= SrvT::InterfaceCall) SrvT::sIfCall(m,t,p1,p2,p3); }
#define TRACE4_IFCALL(m,t,p1,p2,p3,p4)       { if (SrvT::getTraceLevel() >= SrvT::InterfaceCall) SrvT::sIfCall(m,t,p1,p2,p3,p4); }
#define TRACE5_IFCALL(m,t,p1,p2,p3,p4,p5)    { if (SrvT::getTraceLevel() >= SrvT::InterfaceCall) SrvT::sIfCall(m,t,p1,p2,p3,p4,p5); }
#define TRACE6_IFCALL(m,t,p1,p2,p3,p4,p5,p6) { if (SrvT::getTraceLevel() >= SrvT::InterfaceCall) SrvT::sIfCall(m,t,p1,p2,p3,p4,p5,p6); }

// trace macros for construction / destruction of objects
#define TLEVEL_CTOR SrvT::CtorDtor
#define TRACE0_CTOR(m,t)                     { if (SrvT::getTraceLevel() >= SrvT::CtorDtor) SrvT::sCtor(m,t); }
#define TRACE1_CTOR(m,t,p1)                  { if (SrvT::getTraceLevel() >= SrvT::CtorDtor) SrvT::sCtor(m,t,p1); }
#define TRACE2_CTOR(m,t,p1,p2)               { if (SrvT::getTraceLevel() >= SrvT::CtorDtor) SrvT::sCtor(m,t,p1,p2); }
#define TRACE3_CTOR(m,t,p1,p2,p3)            { if (SrvT::getTraceLevel() >= SrvT::CtorDtor) SrvT::sCtor(m,t,p1,p2,p3); }
#define TRACE4_CTOR(m,t,p1,p2,p3,p4)         { if (SrvT::getTraceLevel() >= SrvT::CtorDtor) SrvT::sCtor(m,t,p1,p2,p3,p4); }
#define TRACE5_CTOR(m,t,p1,p2,p3,p4,p5)      { if (SrvT::getTraceLevel() >= SrvT::CtorDtor) SrvT::sCtor(m,t,p1,p2,p3,p4,p5); }
#define TRACE6_CTOR(m,t,p1,p2,p3,p4,p5,p6)   { if (SrvT::getTraceLevel() >= SrvT::CtorDtor) SrvT::sCtor(m,t,p1,p2,p3,p4,p5,p6); }

// trace macros for internal programm flow
#define TLEVEL_INOUT SrvT::ProgramFlow
#define TRACE0_INOUT(m,t)                    { if (SrvT::getTraceLevel() >= SrvT::ProgramFlow) SrvT::sInOut(m,t); }
#define TRACE1_INOUT(m,t,p1)                 { if (SrvT::getTraceLevel() >= SrvT::ProgramFlow) SrvT::sInOut(m,t,p1); }
#define TRACE2_INOUT(m,t,p1,p2)              { if (SrvT::getTraceLevel() >= SrvT::ProgramFlow) SrvT::sInOut(m,t,p1,p2); }
#define TRACE3_INOUT(m,t,p1,p2,p3)           { if (SrvT::getTraceLevel() >= SrvT::ProgramFlow) SrvT::sInOut(m,t,p1,p2,p3); }
#define TRACE4_INOUT(m,t,p1,p2,p3,p4)        { if (SrvT::getTraceLevel() >= SrvT::ProgramFlow) SrvT::sInOut(m,t,p1,p2,p3,p4); }
#define TRACE5_INOUT(m,t,p1,p2,p3,p4,p5)     { if (SrvT::getTraceLevel() >= SrvT::ProgramFlow) SrvT::sInOut(m,t,p1,p2,p3,p4,p5); }
#define TRACE6_INOUT(m,t,p1,p2,p3,p4,p5,p6)  { if (SrvT::getTraceLevel() >= SrvT::ProgramFlow) SrvT::sInOut(m,t,p1,p2,p3,p4,p5,p6); }

// trace macros for data
#define TLEVEL_DATA SrvT::Data
#define TRACE0_DATA(m,t)             { if (SrvT::getTraceLevel() >= SrvT::Data) SrvT::sData(m,t); }
#define TRACE1_DATA(m,t,p1)          { if (SrvT::getTraceLevel() >= SrvT::Data) SrvT::sData(m,t,p1); }
#define TRACE2_DATA(m,t,p1,p2)       { if (SrvT::getTraceLevel() >= SrvT::Data) SrvT::sData(m,t,p1,p2); }
#define TRACE3_DATA(m,t,p1,p2,p3)    { if (SrvT::getTraceLevel() >= SrvT::Data) SrvT::sData(m,t,p1,p2,p3); }
#define TRACE4_DATA(m,t,p1,p2,p3,p4) { if (SrvT::getTraceLevel() >= SrvT::Data) SrvT::sData(m,t,p1,p2,p3,p4); }
#define TRACE5_DATA(m,t,p1,p2,p3,p4,p5)    { if (SrvT::getTraceLevel() >= SrvT::Data) SrvT::sData(m,t,p1,p2,p3,p4,p5); }
#define TRACE6_DATA(m,t,p1,p2,p3,p4,p5,p6) { if (SrvT::getTraceLevel() >= SrvT::Data) SrvT::sData(m,t,p1,p2,p3,p4,p5,p6); }

/** Validates the trace level.
 *  @param traceLevel the level of the trace to validate.
 *  @return true if trace level is set, false if not.
 */
bool UABASE_EXPORT validateTraceLevel(int traceLevel);

#endif // SRVTRACE_H
