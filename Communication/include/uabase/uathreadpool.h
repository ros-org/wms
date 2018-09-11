/******************************************************************************
** uathreadpool.h
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
** Provides a configurable thread pool.
**
******************************************************************************/
#ifndef UATHREADPOOL_H
#define UATHREADPOOL_H

#include "uaplatformdefs.h"
#include "uabase.h"

/*! \addtogroup CppBaseLibraryClass
*  @{
*/

/** This class represents a job to be executed by a worker thread
 *
 * The job is executed and deleted by the UaThreadPool.
 *
 * A derived class must be imlemented that implements the execute() method used
 * as main function for the job. The following code gives an example on how to use
 * a job with the UaThreadPool.
 *
 * @code
 * class MyWorkerJob : public UaThreadPoolJob
 * {
 * public:
 *     MyWorkerJob(){}
 *     virtual ~MyWorkerJob(){}
 *
 *     void execute()
 *     {
 *         // Do something here
 *     }
 * };
 *
 * // Use thread pool
 * UaThreadPool myThreadPool(4,8);
 *
 * MyWorkerJob* pMyJob = new MyWorkerJob;
 * // Add job to thread pool, job is deleted by thread pool after execution
 * myThreadPool.addJob(pMyJob);
 * @endcode
 *
 * It is not possible to create shallow copies of this class.
 */
class UABASE_EXPORT UaThreadPoolJob
{
    UA_DISABLE_COPY(UaThreadPoolJob);
public:
    UaThreadPoolJob(){}
    virtual ~UaThreadPoolJob(){}

    /** Main function of the job to be executed
    *
    * Must be implemented by the derived class to execute the functionality
    */
    virtual void execute() = 0;
};

class UABASE_EXPORT UaThreadPoolPrivate;

/** This class is used to manager a pool of threads
 *
 *  This class manages and recycles individual UaThread objects to help reduce thread
 *  creation costs in programs that use threads. It also ensures that a maximum number
 *  of threads is used to execute worker thread jobs. Jobs are passed in as UaThreadPoolJob.
 *
 *  If all threads of the thread pool are busy, the jobs are added to a job pool. Jobs from the
 *  job pool will be processed by the next available threads. The job pool size is four times the
 *  maximum numbers of threads in the thread pool.
 *
 *  During the creation of the thread pool a minimum and maximum number of threads is defined.
 *  The thread pool creates the minimum number of threads when it is created. It creates more threads
 *  if needed but not more than defined as maximum.
 *
 *  See UaThreadPoolJob for an example.
 *
 *  The default and copy constructor and the copy operator are private and not supported.
 */
class UABASE_EXPORT UaThreadPool
{
    UA_DISABLE_COPY(UaThreadPool);
    UaThreadPool();
public:
    UaThreadPool(
        OpcUa_UInt32 minThreads,
        OpcUa_UInt32 maxThreads);
    virtual ~UaThreadPool();

    OpcUa_StatusCode addJob(UaThreadPoolJob* job, OpcUa_Boolean blockAtAdd = OpcUa_True, OpcUa_Boolean addToPool = OpcUa_False);

    void getCapacity(OpcUa_UInt32& maxThreads, OpcUa_UInt32& usedThreads);
    void getCapacity(OpcUa_UInt32& maxThreads, OpcUa_UInt32& usedThreads, OpcUa_UInt32& maxPoolSize, OpcUa_UInt32& numberOfJobsInPool);

private:
    UaThreadPoolPrivate* d;
};
/*! @} */

#endif // UATHREADPOOL_H

