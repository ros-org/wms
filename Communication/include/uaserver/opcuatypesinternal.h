/******************************************************************************
** opcuatypesinternal.h
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
** Description: OPC server core module base types.
**
******************************************************************************/
#ifndef OPCUATYPESINTERNAL_H
#define OPCUATYPESINTERNAL_H

#include "opcua_proxystub.h"

#include <list>

/** HandleManager
 */
template<class T>
class HandleManager
{
    UA_DISABLE_COPY(HandleManager);
public:
    /** construction with Variable initialization. */
    HandleManager()
    {
        m_nMaxID    = 0;
        m_itemCount = 0;
        m_arraySize = 0;
        m_pItems    = NULL;
    };
    /** destruction */
    virtual ~HandleManager()
    {
        clearList();
    };

    /** Clears the formally created list. */
    void clearList()
    {
        if (m_pItems)
        {
            OpcUa_UInt32 i;

            for ( i=0; i<m_nMaxID; i++ )
            {
                if ( m_pItems[i] != NULL )
                {
                    delete m_pItems[i];
                    m_pItems[i] = NULL;
                }
            }
            delete [] m_pItems;
        }
        m_pItems    = NULL;
        m_arraySize = 0;
        m_nMaxID    = 0;
        m_itemCount = 0;
        m_listIndex.clear();
    }

    /** Prepares an array to add more items.
     *  First of all the actual size will be calculated and after that the existing array will be expanded.
     *  @param addCount the size for expanding the array.
     */
    void prepareAdd(OpcUa_UInt32 addCount)
    {
        // Calculate size
        OpcUa_Int32  newCount  = (OpcUa_Int32)addCount - ((OpcUa_Int32)m_arraySize - (OpcUa_Int32)m_itemCount);

        // Expand array
        if ( newCount > 0 )
        {
            resize(m_arraySize + newCount);
        }
    };

    /** Adds a new item to the array. Returns invalid index 0 if the passed item is NULL
     *  @param pItem the item to add.
     *  @return the index where the new item is stored.
     */
    OpcUa_UInt32  add(T* pItem)
    {
        if ( pItem == NULL )
        {
            return 0;
        }

        unsigned int index = 0;

        if ( m_listIndex.size() == 0 )
        {
            if ( m_arraySize == m_nMaxID )
            {
                prepareAdd(100);
            }
            m_pItems[m_nMaxID] = pItem;
            m_nMaxID++;
            index = m_nMaxID;
            m_itemCount++;
        }
        else
        {
            // Unused handles available, set item to unused vector element
            std::list<OpcUa_UInt32>::iterator TempI = m_listIndex.end();
            TempI--;
            index = *TempI;
            m_listIndex.pop_back();
            m_pItems[index-1] = pItem;
            m_itemCount++;
        }
        return index;
    };

    /** Adds a new item at a specific index to the array.
     *  @param index The index where the new item should be stored.
     *  @param pItem The item to add.
     *  @return Success code.
     */
    OpcUa_StatusCode addAt(OpcUa_UInt32 index, T* pItem)
    {
        // Check if we have a valid index
        if ( index == 0 )
        {
            return OpcUa_BadInvalidArgument;
        }

        // Check if the index is outside the current array size
        if ( m_arraySize < index )
        {
            resize(index+100);
        }

        if ( index == m_nMaxID+1 )
        {
            // Index matches the next available handle
            m_pItems[m_nMaxID] = pItem;
            m_nMaxID++;
            m_itemCount++;
        }
        else if ( index > m_nMaxID+1 )
        {
            // Index is larger than the next available handle
            m_pItems[index-1] = pItem;
            m_itemCount++;
            m_nMaxID++;
            // Push gaps to list of unused indexes
            while ( index > m_nMaxID )
            {
                m_listIndex.push_back(m_nMaxID);
                m_nMaxID++;
            }
        }
        else
        {
            // Index is in the used handle range
            if ( m_pItems[index-1] == NULL )
            {
                m_pItems[index-1] = pItem;
                m_itemCount++;
                // Remove index from list of unused indexes
                m_listIndex.remove(index);
            }
            else
            {
                return OpcUa_BadInvalidArgument;
            }
        }
        return OpcUa_Good;
    }

    /** Removes and deletes the item with the passed handle and returns a boolean value indicating success.
     *  @param index The handle of the item to remove.
     *  @return A flag indicating if the item was removed (true) or not found (false).
     */
    OpcUa_Boolean remove(OpcUa_UInt32 index)
    {
        bool bFound = OpcUa_False;
        if ( (index != 0) && (index <= m_nMaxID) )
        {
            if ( m_pItems[index-1] != NULL )
            {
                delete m_pItems[index-1];
                m_pItems[index-1] = NULL;
                m_listIndex.push_back(index);
                bFound = OpcUa_True;
                m_itemCount--;
            }
        }
        return bFound;
    };

    /** Removes the item with the passed handle but does not delete the item. Returns a boolean value indicating success.
     *  @param index The handle of the item to remove.
     *  @return A flag indicating if the item was removed (true) or not found (false).
     */
    OpcUa_Boolean detach(OpcUa_UInt32 index)
    {
        bool bFound = OpcUa_False;
        if ( (index != 0) && (index <= m_nMaxID) )
        {
            if ( m_pItems[index-1] != NULL )
            {
                m_pItems[index-1] = NULL;
                m_listIndex.push_back(index);
                bFound = OpcUa_True;
                m_itemCount--;
            }
        }
        return bFound;
    };

    /** Get the specified item with the given index.
     *  @param index the specified index where to get the item.
     *  @return the specified item.
     */
    T* get(OpcUa_UInt32 index)
    {
        if ( (index != 0) && (index <= m_nMaxID) )
        {
            return m_pItems[index-1];
        }
        else
        {
            return NULL;
        }
    };

    /** Counts all available items.
     *  @return the counted number of items.
     */
    OpcUa_UInt32  itemCount(){ return m_itemCount; };

    /** Get the maximum Index.
     *  @return the maximum index number.
     */
    OpcUa_UInt32  maxIndex(){ return m_nMaxID; };

protected:
    /** Resizes the length of the array.
     *  @param length the value of length for the resize.
     */
    void resize(OpcUa_UInt32 length)
    {
        if ( length < m_nMaxID )
        {
            for ( OpcUa_UInt32 i=length; i<m_nMaxID; i++ )
            {
                if ( NULL != m_pItems[i] )
                {
                    delete m_pItems[i];
                }
            }
            m_nMaxID = length;
        }
        else if ( length > m_arraySize )
        {
            T** newData = new T*[length];
            OpcUa_MemSet(newData, 0, length * sizeof(T*));
            if ( m_pItems )
            {
                for ( OpcUa_UInt32 i=0; i<m_nMaxID; i++ )
                {
                    newData[i] = m_pItems[i];
                }
                delete [] m_pItems;
            }
            m_pItems = newData;
            m_arraySize = length;
        }
      }

private:
    OpcUa_UInt32              m_nMaxID;
    std::list<OpcUa_UInt32>   m_listIndex;
    T**                       m_pItems;
    OpcUa_UInt32              m_arraySize;
    OpcUa_UInt32              m_itemCount;
};

#endif // OPCUATYPESINTERNAL_H
