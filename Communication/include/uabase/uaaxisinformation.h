/******************************************************************************
** uaaxisinformation.h
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
** Portable UaAxisInformation class.
**
******************************************************************************/
#ifndef UAAXISINFORMATION_H
#define UAAXISINFORMATION_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uaeuinformation.h"
#include "ualocalizedtext.h"
#include "uarange.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaAxisInformationPrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_AxisInformation.
 *
 *  This class encapsulates the native OpcUa_AxisInformation structure
 *  and handles memory allocation and cleanup for you.
 *  UaAxisInformation uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared AxisInformation it creates a copy for that (copy-on-write).
 *  So assigning another UaAxisInformation or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  Defines the information for auxiliary axis for ArrayItemType Variables.
 *
 *  There are three typical uses of this structure:
 *
 *  1. The step between points is constant and can be predicted using the range
 *  information and the number of points. In this case, axisSteps can be set to
 *  NULL.
 *
 *  2. The step between points is not constant, but remains the same for a long
 *  period of time (from acquisition to acquisition for example). In this case,
 *  axisSteps contains the value of each step on the axis.
 *
 *  3. The step between points is not constant and changes at every update. In this
 *  case, a type like XYArrayType shall be used and axisSteps is set to NULL.
 *
 *  When the steps in the axis are constant, axisSteps may be set to “Null” and in
 *  this case, the Range limits are used to compute the steps. The number of steps
 *  in the axis comes from the parent ArrayItem.ArrayDimensions.
 */
class UABASE_EXPORT UaAxisInformation
{
    UA_DECLARE_PRIVATE(UaAxisInformation)
public:
    UaAxisInformation();
    UaAxisInformation(const UaAxisInformation &other);
    UaAxisInformation(const OpcUa_AxisInformation &other);
    UaAxisInformation(
        const UaEUInformation& engineeringUnits,
        const UaRange& eURange,
        const UaLocalizedText& title,
        OpcUa_AxisScaleEnumeration axisScaleType,
        const UaDoubleArray &axisSteps
        );
    UaAxisInformation(const UaExtensionObject &extensionObject);
    UaAxisInformation(const OpcUa_ExtensionObject &extensionObject);
    UaAxisInformation(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaAxisInformation(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaAxisInformation();

    void clear();

    bool operator==(const UaAxisInformation &other) const;
    bool operator!=(const UaAxisInformation &other) const;

    UaAxisInformation& operator=(const UaAxisInformation &other);

    OpcUa_AxisInformation* copy() const;
    void copyTo(OpcUa_AxisInformation *pDst) const;

    static OpcUa_AxisInformation* clone(const OpcUa_AxisInformation& source);
    static void cloneTo(const OpcUa_AxisInformation& source, OpcUa_AxisInformation& copy);

    void attach(OpcUa_AxisInformation *pValue);
    OpcUa_AxisInformation* detach(OpcUa_AxisInformation* pDst);

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

    OpcUa_StatusCode setAxisInformation(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setAxisInformation(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setAxisInformation(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setAxisInformation(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setAxisInformation(
        const UaEUInformation& engineeringUnits,
        const UaRange& eURange,
        const UaLocalizedText& title,
        OpcUa_AxisScaleEnumeration axisScaleType,
        const UaDoubleArray &axisSteps
        );

    UaEUInformation getEngineeringUnits() const;
    UaRange getEURange() const;
    UaLocalizedText getTitle() const;
    OpcUa_AxisScaleEnumeration getAxisScaleType() const;
    void getAxisSteps(UaDoubleArray& axisSteps) const;

    void setEngineeringUnits(const UaEUInformation& engineeringUnits);
    void setEURange(const UaRange& eURange);
    void setTitle(const UaLocalizedText& title);
    void setAxisScaleType(OpcUa_AxisScaleEnumeration axisScaleType);
    void setAxisSteps(const UaDoubleArray &axisSteps);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_AxisInformation.
 *
 *  This class encapsulates an array of the native OpcUa_AxisInformation structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaAxisInformation for information about the encapsulated structure.
 */
class UABASE_EXPORT UaAxisInformations
{
public:
    UaAxisInformations();
    UaAxisInformations(const UaAxisInformations &other);
    UaAxisInformations(OpcUa_Int32 length, OpcUa_AxisInformation* data);
    virtual ~UaAxisInformations();

    UaAxisInformations& operator=(const UaAxisInformations &other);
    const OpcUa_AxisInformation& operator[](OpcUa_UInt32 index) const;
    OpcUa_AxisInformation& operator[](OpcUa_UInt32 index);

    bool operator==(const UaAxisInformations &other) const;
    bool operator!=(const UaAxisInformations &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_AxisInformation* data);
    void attach(OpcUa_Int32 length, OpcUa_AxisInformation* data);
    OpcUa_AxisInformation* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_AxisInformation* rawData() const {return m_data;}
    inline OpcUa_AxisInformation* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setAxisInformations(const UaVariant &variant);
    OpcUa_StatusCode setAxisInformations(const OpcUa_Variant &variant);
    OpcUa_StatusCode setAxisInformations(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setAxisInformations(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setAxisInformations(OpcUa_Int32 length, OpcUa_AxisInformation* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_AxisInformation* m_data;
};

#endif // UAAXISINFORMATION_H

