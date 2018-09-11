/******************************************************************************
** uaargument.h
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
** Portable UaArgument class.
**
******************************************************************************/
#ifndef UAARGUMENT_H
#define UAARGUMENT_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "ualocalizedtext.h"
#include "uanodeid.h"
#include "uastring.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaArgumentPrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_Argument.
 *
 *  This class encapsulates the native OpcUa_Argument structure
 *  and handles memory allocation and cleanup for you.
 *  UaArgument uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared Argument it creates a copy for that (copy-on-write).
 *  So assigning another UaArgument or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  Defines a Method input or output argument specification.
 *
 *  It is for example used in the input and output argum ent Properties for
 *  Methods.
 */
class UABASE_EXPORT UaArgument
{
    UA_DECLARE_PRIVATE(UaArgument)
public:
    UaArgument();
    UaArgument(const UaArgument &other);
    UaArgument(const OpcUa_Argument &other);
    UaArgument(
        const UaString& name,
        const UaNodeId& dataType,
        OpcUa_Int32 valueRank,
        const UaUInt32Array &arrayDimensions,
        const UaLocalizedText& description
        );
    UaArgument(const UaExtensionObject &extensionObject);
    UaArgument(const OpcUa_ExtensionObject &extensionObject);
    UaArgument(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaArgument(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaArgument();

    void clear();

    bool operator==(const UaArgument &other) const;
    bool operator!=(const UaArgument &other) const;

    UaArgument& operator=(const UaArgument &other);

    OpcUa_Argument* copy() const;
    void copyTo(OpcUa_Argument *pDst) const;

    static OpcUa_Argument* clone(const OpcUa_Argument& source);
    static void cloneTo(const OpcUa_Argument& source, OpcUa_Argument& copy);

    void attach(OpcUa_Argument *pValue);
    OpcUa_Argument* detach(OpcUa_Argument* pDst);

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

    OpcUa_StatusCode setArgument(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setArgument(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setArgument(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setArgument(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setArgument(
        const UaString& name,
        const UaNodeId& dataType,
        OpcUa_Int32 valueRank,
        const UaUInt32Array &arrayDimensions,
        const UaLocalizedText& description
        );

    UaString getName() const;
    UaNodeId getDataType() const;
    OpcUa_Int32 getValueRank() const;
    void getArrayDimensions(UaUInt32Array& arrayDimensions) const;
    UaLocalizedText getDescription() const;

    void setName(const UaString& name);
    void setDataType(const UaNodeId& dataType);
    void setValueRank(OpcUa_Int32 valueRank);
    void setArrayDimensions(const UaUInt32Array &arrayDimensions);
    void setDescription(const UaLocalizedText& description);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_Argument.
 *
 *  This class encapsulates an array of the native OpcUa_Argument structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaArgument for information about the encapsulated structure.
 */
class UABASE_EXPORT UaArguments
{
public:
    UaArguments();
    UaArguments(const UaArguments &other);
    UaArguments(OpcUa_Int32 length, OpcUa_Argument* data);
    virtual ~UaArguments();

    UaArguments& operator=(const UaArguments &other);
    const OpcUa_Argument& operator[](OpcUa_UInt32 index) const;
    OpcUa_Argument& operator[](OpcUa_UInt32 index);

    bool operator==(const UaArguments &other) const;
    bool operator!=(const UaArguments &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_Argument* data);
    void attach(OpcUa_Int32 length, OpcUa_Argument* data);
    OpcUa_Argument* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_Argument* rawData() const {return m_data;}
    inline OpcUa_Argument* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setArguments(const UaVariant &variant);
    OpcUa_StatusCode setArguments(const OpcUa_Variant &variant);
    OpcUa_StatusCode setArguments(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setArguments(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setArguments(OpcUa_Int32 length, OpcUa_Argument* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_Argument* m_data;
};

#endif // UAARGUMENT_H

