/******************************************************************************
** uaabstractgenericvalue.h
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
#ifndef UAABSTRACTGENERICSTRUCTUREVALUE_H
#define UAABSTRACTGENERICSTRUCTUREVALUE_H

#include "uaabstractgenericvalue.h"

class UaExtensionObject;
class UaDataValue;
class UaAbstractDecoder;
class UaAbstractEncoder;
class UaStructureField;
class UaStructureFieldData;

/******************************************************************************
** Class UaAbstractGenericStructureValue
******************************************************************************/

/** Base class for handling values of structured DataTypes that are not known at compile time.*/
class UABASE_EXPORT UaAbstractGenericStructureValue : public UaAbstractGenericValue
{
public:
    UaAbstractGenericStructureValue();
    virtual ~UaAbstractGenericStructureValue();

    /** Returns the UaStructureDefinition of the instance. */
    virtual UaStructureDefinition definition() const = 0;

protected:
    virtual UaNodeId binaryEncodingId() const;
#ifdef HAVE_XML_ENCODER
    virtual UaNodeId xmlEncodingId() const;
#endif

    bool checkValue(const UaStructureField &field, const UaVariant &value) const;
    UaVariant defaultValue(const UaStructureField &field) const;

    void setVariantToFieldData(
        const UaStructureField &field,
        UaVariant &value,
        UaStructureFieldData &fieldData) const;

    UaString fieldToString(const UaStructureField &field, const UaStructureFieldData &fieldData) const;
};

#endif // UAABSTRACTGENERICSTRUCTUREVALUE_H
