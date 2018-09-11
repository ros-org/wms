/******************************************************************************
** uaunistringlist.h
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
** OPC UA string list handling class.
**
******************************************************************************/
#ifndef __UAUNISTRINGLISTLIST_H__
#define __UAUNISTRINGLISTLIST_H__

/* check if UA types are included correctly */
#ifndef _OpcUa_P_Types_H_
    #ifdef _UA_WIN32
        #pragma message("ATTENTION: Please include <opcua_proxystub.h> before including <UaUniStringList.h>")
    #else
        #warning "ATTENTION: Please include <opcua_proxystub.h> before including <UaUniStringList.h>"
    #endif
#endif

#include "uaplatformdefs.h"
#include "uabytearray.h"

class UaUniString;

class UABASE_EXPORT UaUniStringPrivate;

/** If the list needs to allocated more memory it will allocate chunks of this size
 * The default constructor will allocate memory for that much strings
 */
#define DEFAULT_ALLOC_CHUNK_SIZE 10

/** OPC UA string list class.
 * This class encapsulates a list of UaUniStringPrivate
 * This list behaves like a vector and allows fast index lookup.
 * Inserting and deleting elements can be very slow.
 */
class UABASE_EXPORT UaUniStringList
{
public:
    UaUniStringList(unsigned int capacity = DEFAULT_ALLOC_CHUNK_SIZE);
    UaUniStringList(const UaUniStringList &other);
    ~UaUniStringList();

    UaUniStringList& operator=(const UaUniStringList &other);

    unsigned int size() const;
    unsigned int capacity() const;
    void resize(unsigned int size);  // change size only
    void reserve(unsigned int capacity); // change capacity only
    void squeeze(); // release all unused memory
    bool isEmpty() const;

    void setAllocChunkSize(unsigned int newSize){m_nAllocChunkSize = newSize;};
    unsigned int allocChunkSize() const {return m_nAllocChunkSize;};

    void append(const UaUniString &newString);
    void append(const UaUniStringList &lstStrings);
    void prepend(const UaUniString &newString);
    void insert(unsigned int index, const UaUniString &newString);

    void swap(unsigned int indexA, unsigned int indexB);

    void removeAt(unsigned int index);
    void clear();

    void sort(bool bAscending = true, bool bCaseSensitive = false);

    UaUniString join(const UaUniString &sSeparator) const;

    bool operator==(const UaUniStringList &other) const;
    bool operator!=(const UaUniStringList &other) const;

    const UaUniString& operator[](unsigned int index) const;
    UaUniString& operator[](unsigned int index);

private:
    void combSort(bool bAscending, bool bCaseSensitive, unsigned int length);
    int createGap(int gap);

private:
    UaUniString **m_pData;
    unsigned int m_nSize;
    unsigned int m_nCapacity;
    unsigned int m_nAllocChunkSize;    // default is DEFAULT_ALLOC_CHUNK_SIZE
};

#endif // #ifndef __UAUNISTRINGLISTLIST_H__
