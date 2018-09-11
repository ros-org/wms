/******************************************************************************
** uanumericrange.h
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
** Portable UA NumericRange class.
**
******************************************************************************/
#ifndef __UANUMERICRANGE_H__
#define __UANUMERICRANGE_H__

#include "uaplatformdefs.h"
#include "uastring.h"

class UABASE_EXPORT UaNumericRangeDimension
{
    friend class UaNumericRange;
public:
    /** NumericRange type enumeration */
    enum NumericRangeType
    {
        NOTSET, /*!< The numeric range is not set */
        INDEX,  /*!< The numeric range represents an individual integer used as index into an array */
        RANGE   /*!< A range represented by two integers */
    };

    UaNumericRangeDimension()
    {
        m_firstIndex = 0;
        m_secondIndex = 0;
        m_numericRangeType = NOTSET;
    };

    inline NumericRangeType numericRangeType() const {return m_numericRangeType;}
    inline OpcUa_UInt32 firstIndex() const {return m_firstIndex;}
    inline OpcUa_UInt32 secondIndex() const {return m_secondIndex;}

protected:
    OpcUa_UInt32        m_firstIndex;
    OpcUa_UInt32        m_secondIndex;
    NumericRangeType    m_numericRangeType;
};

/** @ingroup CppBaseLibraryClass
 *  Helper class for NumericRange handling
 *
 * The numeric range provides a way to identify a subset of a single or multidimensional array of data.
 * The numeric range is provided as a string with a defined syntax for different constructs like single index
 * into an array, a range of the array or a subset of a multidimensional array.<br>
 *
 * BNF for NumericRange:<br>
 * <numeric-range> ::= dimension [',' dimension]<br>
 * dimension ::= index [':' index]<br>
 * index ::= digit [digit]<br>
 * digit ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'<br>
 */
class UABASE_EXPORT UaNumericRange
{
public:
    UaNumericRange();
    UaNumericRange(const UaNumericRange& other);
    UaNumericRange(const UaString& sNumericRange);
    ~UaNumericRange();

    UaNumericRange& operator=(const UaNumericRange &other);

    bool isValid() const;
    void clear();

    OpcUa_StatusCode setNumericRange(const UaString& sNumericRange);

    inline int dimensions() const {return m_Dimensions;}
    UaNumericRangeDimension dimension(OpcUa_UInt32 index) const;

private:
    OpcUa_UInt32             m_Dimensions;
    UaNumericRangeDimension *m_pNumericRanges;
};

#endif /* __UANUMERICRANGE_H__ */

