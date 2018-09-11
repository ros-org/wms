/******************************************************************************
** uastructurefielddata.h
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
******************************************************************************/
#ifndef UASTRUCTUREFIELDDATA_H
#define UASTRUCTUREFIELDDATA_H

#include <opcua_proxystub.h>

#include "uabase.h"

class UaStructureFieldDataPrivate;
class UaVariant;
class UaGenericStructureValue;
class UaGenericStructureArray;
class UaGenericUnionValue;
class UaGenericUnionArray;
class UaGenericOptionSetValue;
class UaGenericOptionSetArray;

enum UaStructureFieldDataType
{
    DataVariant,
    DataGenericStructure,
    DataGenericStructureArray,
    DataGenericUnion,
    DataGenericUnionArray,
    DataGenericOptionSet,
    DataGenericOptionSetArray,
    DataEmpty
};

/******************************************************************************
** Class UaStructureFieldData
******************************************************************************/

class UaStructureFieldData
{
    UA_DECLARE_PRIVATE(UaStructureFieldData)
public:
    UaStructureFieldData();
    UaStructureFieldData(const UaVariant &variant);
    UaStructureFieldData(const UaGenericStructureValue &value);
    UaStructureFieldData(const UaGenericStructureArray &valueArray);
    UaStructureFieldData(const UaGenericUnionValue &genericUnion);
    UaStructureFieldData(const UaGenericUnionArray &genericUnionArray);
    UaStructureFieldData(const UaGenericOptionSetValue &genericOptionSet);
    UaStructureFieldData(const UaGenericOptionSetArray &genericOptionSetArray);
    UaStructureFieldData(const UaStructureFieldData &other);

    ~UaStructureFieldData();

    UaStructureFieldData& operator=(const UaStructureFieldData &other);

    bool operator==(const UaStructureFieldData &other) const;
    bool operator!=(const UaStructureFieldData &other) const;

    UaStructureFieldDataType type() const;

    void setVariant(UaVariant &variant);
    void setValue(const UaGenericStructureValue &value);
    void setValueArray(const UaGenericStructureArray &valueArray);
    void setUnion(const UaGenericUnionValue &genericUnion);
    void setUnionArray(const UaGenericUnionArray &genericUnionArray);
    void setOptionSet(const UaGenericOptionSetValue &genericOptionSet);
    void setOptionSetArray(const UaGenericOptionSetArray &genericOptionSetArray);
    void clear();

    const UaVariant& variant() const;
    UaGenericStructureValue value() const;
    const UaGenericStructureArray& valueArray() const;
    UaGenericUnionValue genericUnion() const;
    UaGenericUnionArray genericUnionArray() const;
    UaGenericOptionSetValue genericOptionSet() const;
    UaGenericOptionSetArray genericOptionSetArray() const;
    bool isEmpty() const;

private:
    static UaVariant ms_emptyVariant;
    static UaGenericStructureArray ms_emptyGenericValueArray;
};

/******************************************************************************
** Class UaStructureFieldDataArray
******************************************************************************/

class UaStructureFieldDataArray
{
    UA_DISABLE_COPY(UaStructureFieldDataArray);
public:
    UaStructureFieldDataArray();
    UaStructureFieldDataArray(unsigned int noOfMembers);
    ~UaStructureFieldDataArray();
    void create(unsigned int noOfMembers);
    void clear();
    unsigned int length() const;

    const UaStructureFieldData& operator[](unsigned int index) const;
    UaStructureFieldData& operator[](unsigned int index);

private:
    unsigned int m_noOfMembers;
    UaStructureFieldData *m_data;
};

#endif
