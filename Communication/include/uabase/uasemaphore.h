/******************************************************************************
** uasemaphore.h
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
** Semaphore class allows threads to synchronize access to a resource.
**
******************************************************************************/
#ifndef UASEMAPHORE_H
#define UASEMAPHORE_H

#include <uabase.h>

class UaSemaphorePrivate;


/** @ingroup CppBaseLibraryClass
 *  @brief Semaphore class is used to allow threads to synchronize access to a resource.
 *  The UaSemaphore class provides a general counting semaphore.
 *  A semaphore is a generalization of a mutex.
 *  While a mutex can only be locked once, it's possible to acquire a semaphore multiple times.
 *  Semaphores are typically used to protect a certain number of identical resources.
 *  A typical application of semaphores is for controlling access to a circular buffer shared by a producer thread and a consumer thread.
 *  It is not possible to create shallow copies of this Class.
 *  It is not possible to use the default constructor.
 */
class UABASE_EXPORT UaSemaphore
{
    UA_DISABLE_COPY(UaSemaphore);
    UaSemaphore(){}
public:

    UaSemaphore( OpcUa_UInt32 initalValue, OpcUa_UInt32 maxRange);

    ~UaSemaphore();

    OpcUa_StatusCode wait();

    OpcUa_StatusCode timedWait(OpcUa_UInt32 msecTimeout);

    OpcUa_StatusCode post(OpcUa_UInt32 releaseCount);

private:
    UaSemaphorePrivate* d;
};

#endif // UASEMAPHORE_H
