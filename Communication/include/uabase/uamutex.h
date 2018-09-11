/******************************************************************************
** uamutex.h
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
** Mutex class.
**
******************************************************************************/
#ifndef UAMUTEX_H
#define UAMUTEX_H

#include <uabase.h>

class UaMutexPrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief The UaMutex class provides access serialization between threads.
 *  The purpose of a UaMutex is to protect an object, data structure or section of code so that only one thread
 *  can access it at a time (this is similar to the Java synchronized keyword).
 *  It is usually best to use a mutex with a UaMutexLocker since this makes it easy to ensure that
 *  locking and unlocking are performed consistently.
 *  It is not possible to create shallow copies of this Class.
 */
class UABASE_EXPORT UaMutex
{
    UA_DISABLE_COPY(UaMutex);
public:
    /* Construction
       Constructs a UaMutex object that allows threads to lock()
       the mutex to block access to a resource.
    */
    UaMutex();

    /* Destruction
       Destroys the UaMutex object.
       \warning If you destroy a mutex that has accesses in use
       the resultant behavior is undefined.
    */
    virtual ~UaMutex();

    /* Attempts to lock the mutex.
       This function will block the current thread if the mutex is already locked.
       \sa unlock()
    */
    void lock();

    /* Unlocks the mutex.
       \sa lock()
    */
    void unlock();

    static int s_instanceCount;
private:
    UaMutexPrivate* d;
};

/** UaMutexLocker
 *  @brief Auto lock and unlock class for Mutex class.
 *  The UaMutexLocker class is a convenience class that simplifies locking and unlocking of a mutex.
 *  Locking and unlocking an UaMutex in complex functions and statements or in exception handling code is error-prone
 *  and difficult to debug. UaMutexLocker can be used in such situations to ensure that the state of the mutex is always well-defined.
 *  UaMutexLocker should be created within a function where an UaMutex needs to be locked.
 *  The mutex is locked when UaMutexLocker is created.
 *  You can unlock the mutex with unlock().
 *  If locked, the mutex will be unlocked when the UaMutexLocker is destroyed.
 *  It is not possible to create shallow copies of this Class.
 */
class UABASE_EXPORT UaMutexLocker
{
    UA_DISABLE_COPY(UaMutexLocker);
    void* operator new(size_t size);
public:
    /* Construction
       Constructs a UaMutexLocker object and locks passed pMutex
       to block access to a resource. The mutex will be unlocked when
       the UaMutexLocker is destroyed. */
    UaMutexLocker(UaMutex *pMutex);

    /* Destruction
       Destroys the UaMutexLocker object and unlocks the mutex object
       that was locked in the constructor. */
    ~UaMutexLocker();

    /* Unlocks the mutex. */
    void unlock();

    /* Locks the mutex. */
    void lock(UaMutex *pMutex);

private:
    UaMutex * m_pMutex;
};

/** UaMutexRefCounted
 *  @brief Reference counted mutex implementation.
 *  A derived class of UaMutex which provides the possibility to control the lifetime of the mutex object based on its reference counter.
 */
class UABASE_EXPORT UaMutexRefCounted : public UaMutex
{
protected:
    /* destruction */
    virtual ~UaMutexRefCounted();
public:
    /* construction */
    UaMutexRefCounted();

    // Increment the reference counter of the object.
    int addReference();

    // Decrement the reference counter of the object.
    int releaseReference();

    //  Returns the reference counter of the object.
    int referenceCount();
private:
    int m_refCount;
};

#endif // UAMUTEX_H
