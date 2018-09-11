/******************************************************************************
** uaoptionset.h
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
** Portable UaOptionSet class.
**
******************************************************************************/
#ifndef UAOPTIONSET_H
#define UAOPTIONSET_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uabytestring.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaOptionSetPrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_OptionSet.
 *
 *  This class encapsulates the native OpcUa_OptionSet structure
 *  and handles memory allocation and cleanup for you.
 *  UaOptionSet uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared OptionSet it creates a copy for that (copy-on-write).
 *  So assigning another UaOptionSet or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  This abstract DataType is the base DataType for all DataTypes representing a
 *  bit mask.
 *
 *  All OptionSet DataTypes representing bit masks shall inherit from this
 *  DataType.
 *
 *  The DataType Nodes representing concrete subtypes of the OptionSet shall have
 *  an OptionSetValues Property.
 */
class UABASE_EXPORT UaOptionSet
{
    UA_DECLARE_PRIVATE(UaOptionSet)
public:
    UaOptionSet();
    UaOptionSet(const UaOptionSet &other);
    UaOptionSet(const OpcUa_OptionSet &other);
    UaOptionSet(
        const UaByteString& value,
        const UaByteString& validBits
        );
    UaOptionSet(const UaExtensionObject &extensionObject);
    UaOptionSet(const OpcUa_ExtensionObject &extensionObject);
    UaOptionSet(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaOptionSet(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaOptionSet();

    void clear();

    bool operator==(const UaOptionSet &other) const;
    bool operator!=(const UaOptionSet &other) const;

    UaOptionSet& operator=(const UaOptionSet &other);

    OpcUa_OptionSet* copy() const;
    void copyTo(OpcUa_OptionSet *pDst) const;

    static OpcUa_OptionSet* clone(const OpcUa_OptionSet& source);
    static void cloneTo(const OpcUa_OptionSet& source, OpcUa_OptionSet& copy);

    void attach(OpcUa_OptionSet *pValue);
    OpcUa_OptionSet* detach(OpcUa_OptionSet* pDst);

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    void toExtensionObject(UaExtensionObject &extensionObject) const;
    void toExtensionObject(OpcUa_ExtensionObject &extensionObject) const;
    void toExtensionObject(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    void toExtensionObject(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    OpcUa_StatusCode setOptionSet(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setOptionSet(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setOptionSet(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setOptionSet(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setOptionSet(
        const UaByteString& value,
        const UaByteString& validBits
        );

    UaByteString getValue() const;
    UaByteString getValidBits() const;

    void setValue(const UaByteString& value);
    void setValidBits(const UaByteString& validBits);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_OptionSet.
 *
 *  This class encapsulates an array of the native OpcUa_OptionSet structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaOptionSet for information about the encapsulated structure.
 */
class UABASE_EXPORT UaOptionSets
{
public:
    UaOptionSets();
    UaOptionSets(const UaOptionSets &other);
    UaOptionSets(OpcUa_Int32 length, OpcUa_OptionSet* data);
    virtual ~UaOptionSets();

    UaOptionSets& operator=(const UaOptionSets &other);
    const OpcUa_OptionSet& operator[](OpcUa_UInt32 index) const;
    OpcUa_OptionSet& operator[](OpcUa_UInt32 index);

    bool operator==(const UaOptionSets &other) const;
    bool operator!=(const UaOptionSets &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_OptionSet* data);
    void attach(OpcUa_Int32 length, OpcUa_OptionSet* data);
    OpcUa_OptionSet* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_OptionSet* rawData() const {return m_data;}
    inline OpcUa_OptionSet* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setOptionSets(const UaVariant &variant);
    OpcUa_StatusCode setOptionSets(const OpcUa_Variant &variant);
    OpcUa_StatusCode setOptionSets(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setOptionSets(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setOptionSets(OpcUa_Int32 length, OpcUa_OptionSet* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_OptionSet* m_data;
};

#endif // UAOPTIONSET_H

