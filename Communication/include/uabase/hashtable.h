/******************************************************************************
** hashtable.h
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
** Description: OPC server hash table class.
**
******************************************************************************/
#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include "uabase.h"
#include "uanodeid.h"
#include "referencecounter.h"

class HashTable;

/** ChainEntry
 *  @brief This class implements the collision resolution of the hashtable.
 *  It uses the simple chaining strategy.
 *  It's just a simple list of entries which having the same hash.
 *  If there are multiple entries they are searched by linear probing.
 */
class UABASE_EXPORT ChainEntry: public ReferenceCounter
{
    UA_DISABLE_COPY(ChainEntry);
protected:
    /** destruction */
    virtual ~ChainEntry();
public:
    /** construction */
    ChainEntry();

    /** finds the right entry in the chain.
     *  @param key The key identifying the entry.
     *  @param ppPrevious Returns the pointer to the previous entry. Needed to change the linked list.
     *  @return the pointer to the found object or NULL if not found.
     */
    ChainEntry* find(const UaNodeId &key, ChainEntry **ppPrevious);

    /** adds a new entry to the list.
     *  @param pNewEntry Pointer to the new entry.
     */
    void add(ChainEntry *pNewEntry);

    /** prepends a new entry to the list.
     *  @param pNewEntry Pointer to the new entry.
     */
    void prepend(ChainEntry *pNewEntry);

    /** removes an entry from the list.
     *  @param key The key identifying the entry.
     *  @param ppNext Returns pointer to the next element. The returned object will not contain a next element because it gets unchained.
     *  @return the pointer to the found (removed) object or NULL if not found.
     */
    ChainEntry* remove(const UaNodeId &key, ChainEntry** ppNext);

    /** this returns the key of this entry.
     *  This method can be overwritten to optimize redundant information.
     *  The key doesn't need to be saved for every entry.
     */
    virtual UaNodeId getKey() const = 0;

    /** Check if there is a chain. That`s a faster way than a string compare for each lookup.
     *  @return the next Value of the chain if exists.
     */
    inline ChainEntry* getNext() const {return m_pNext;}

    /** Set the entry to invalid.
     *  This method can be overwritten by a derived class to set the internal state to invalid until the object gets deleted when the
     *  reference count goes to zero. This method is used if the object should be invalidated but can not be deleted since the lifetime
     *  is controlled by the reference count.
     */
    virtual void setInvalid(){}

    /** Clear the chain when the hashtable is cleared.
    */
    void clearChain();

protected:
    ChainEntry *m_pNext;
};

class UABASE_EXPORT HashIterator
{
public:
    HashIterator(const HashIterator &other);
    ~HashIterator();
    HashIterator& operator=(const HashIterator& other);
    bool operator==(const HashIterator& other);
    bool operator!=(const HashIterator& other);

    HashIterator& operator++(); // prefix
    HashIterator operator++(int); // postfix

    ChainEntry* value();

private:
    friend class HashTable;
    HashIterator(HashTable* pTable);

    HashTable* m_pTable;
    ChainEntry* m_pCurrent;
    int m_nIndex;
};

/** HashTable
 *  @brief This class implements a fast hash table.
 *  primes for special tables sizes:
 *  size  1.000, 10.000, 100.000, 1.000.000, 10.000.000
 *  prime 1.009, 10.007, 100.003, 1.000.003, 10.000.019
 */
class UABASE_EXPORT HashTable
{
    UA_DISABLE_COPY(HashTable);
public:
    /** Description of the Enumeration HashType */
    enum HashType
    {
        Rotating = 0 /*!< value 1*/
#if 0
        SDBM,
        FNV,
        OneAtATime,
        MyHash
#endif
    };

    /** Constructor of the hash table.
     *  You can initialize the max size of the table.
     *  You can fill in even more the max elements, but then there must be collision
     *  and performance is decreasing.
     *  @param iSize max number of entries. You should choose a prime here to reduce collisions.
     */
    HashTable(int iSize = 1000003);

    /** The destructor cleans up its resources.
     *  It does not delete the referenced objects.
     */
    ~HashTable();

    /** Adds a new ChainEntry object with a corresponding key.
     *  You can use this key to lookup the object.
     *  @param key a unicode string
     *  @param pValue the value to store
     */
    void add(const UaNodeId &key, ChainEntry *pValue);

    /** Looks up the value object identified by the passed string.
     *  @param key the key to search for
     *  @return the found object or NULL if not found
     */
    ChainEntry* lookup(const UaNodeId &key);

    /** Removes an object from the hash table identified by the passed string.
     *  @param key the key to search for
     *  @return the removed object or NULL if not found
     */
    ChainEntry* remove(const UaNodeId &key);

    /** Sets the HashType.
     *  @param type a Variable filled with the HashType (e.g. rotating_hash).
     */
    void setHashType(HashType type);

    /** Clears the hash table.
     *  @param bDelete true if everything is cleared false if not.
     */
    void clear(bool bDelete = true);

    /** Get the number of elements in the hash table.
     *  @return the number of elements currently filled ein the hash table.
     */
    int count();

    /** Get the size the table was initialized with.
     *  @return the internal size of the hashtable.
     */
    int tableSize() const;

    HashIterator begin();

    HashIterator end();

#ifdef _DEBUG
    unsigned long collisions()
    {
        unsigned long lCollisions = 0;

        for (unsigned int i=0; i<m_iSize; i++)
        {
            if (m_pTable[i] != NULL)
            {
                ChainEntry *pEntry = m_pTable[i];
                while ((pEntry = pEntry->getNext()) != NULL)
                {
                    lCollisions++;
                }
            }
        }
        return lCollisions;
    }
#endif

protected:
    friend class HashIterator;

    /** Create a new Hash with specified length and data.
    *  @param pData the data to put into the hash.
    *  @param iLen the length of the Hash.
    *  @return the created Hash.
    */
    int hash(const unsigned char *pData, unsigned int iLen);

    /** Rotating hash
     *  @param pData the data to put into the hash.
     *  @param iLen the length of the Hash.
     *  @return the created rotating_hash.
     */
    int rotating_hash(const unsigned char *pData, unsigned int iLen);

    /** Get next element from table starting at iterator
    */
    HashIterator next(const HashIterator* pCurrent);

private:
    const unsigned int m_iSize; // should be a prime
    int       m_iCount;
    ChainEntry** m_pTable;
    int (HashTable::*m_fctHash)(const unsigned char *pData, unsigned int iLen);
};

#endif
