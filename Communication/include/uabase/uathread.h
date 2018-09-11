/******************************************************************************
** uathread.h
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
** Base class for a class that has its own thread.
**
******************************************************************************/
#ifndef UATHREAD_H
#define UATHREAD_H

#include "uabase.h"

class UABASE_EXPORT UaThreadPrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Platform independent class for a worker thread.
 *
 *  A UaThreads represents a separate thread of control within the program;
 *  it shares data with all the other threads within the process but executes independently
 *  in the way that a separate program does on a multitasking operating system.
 *  Instead of starting in main(), UaThreads begin executing in run().
 *
 *  A class representing a worker thread or a class that needs a background processing thread
 *  must be derived from UaThread and the method
 *  run() must be implemented as main function for the thread in this class. See the following
 *  sample code for the definition of such a class and the use of the class.
 *
 * @code
 * class MyWorkerThread : public UaThread
 * {
 * public:
 *     MyWorkerThread(){}
 *     virtual ~MyWorkerThread(){}
 *
 *     void run()
 *     {
 *         // Do something here
 *     }
 * };
 *
 * // Use worker thread
 * MyWorkerThread myThread;
 * // Start worker thread
 * myThread.start();
 *
 * // Wait for completion
 * myThread.wait();
 * @endcode
 *
 *  The class is also used by the UaThreadPool. If you have recurring task you want to execute
 *  in worker threads it is more efficient to use UaThread
 *
 *  It is not possible to create shallow copies of this Class.
 */
class UABASE_EXPORT UaThread
{
    UA_DISABLE_COPY(UaThread);
public:
    UaThread();
    virtual ~UaThread();

    /* Start Thread */
    virtual void start();
    /* Waits for shutdown-ready event */
    OpcUa_Boolean wait(OpcUa_UInt32 time = OpcUa_UInt32_Max);
    /* Get Run State of Thread. */
    OpcUa_Boolean running() const;
    /* Get Run State of Thread. */
    OpcUa_Boolean finished() const;

    static OpcUa_UInt32 currentThread();

    static void sleep ( OpcUa_UInt32 secs);
    static void msleep( OpcUa_UInt32 msecs);
    static void usleep( OpcUa_UInt32 usecs);

protected:
    /** Main function of the thread
    *
    * Must be implemented by the derived class to execute the functionality
    */
    virtual void run() = 0;

private:
    void ThreadMain();
    static void startT( OpcUa_Void* pData );

private:
    UaThreadPrivate* d;
};

#endif // UATHREAD_H

