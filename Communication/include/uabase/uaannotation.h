/******************************************************************************
** uaannotation.h
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
** Portable UaAnnotation class.
**
******************************************************************************/
#ifndef UAANNOTATION_H
#define UAANNOTATION_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uadatetime.h"
#include "uastring.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaAnnotationPrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_Annotation.
 *
 *  This class encapsulates the native OpcUa_Annotation structure
 *  and handles memory allocation and cleanup for you.
 *  UaAnnotation uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared Annotation it creates a copy for that (copy-on-write).
 *  So assigning another UaAnnotation or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  Describes Annotation information for the history data items.
 */
class UABASE_EXPORT UaAnnotation
{
    UA_DECLARE_PRIVATE(UaAnnotation)
public:
    UaAnnotation();
    UaAnnotation(const UaAnnotation &other);
    UaAnnotation(const OpcUa_Annotation &other);
    UaAnnotation(
        const UaString& message,
        const UaString& userName,
        const UaDateTime& annotationTime
        );
    UaAnnotation(const UaExtensionObject &extensionObject);
    UaAnnotation(const OpcUa_ExtensionObject &extensionObject);
    UaAnnotation(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaAnnotation(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaAnnotation();

    void clear();

    bool operator==(const UaAnnotation &other) const;
    bool operator!=(const UaAnnotation &other) const;

    UaAnnotation& operator=(const UaAnnotation &other);

    OpcUa_Annotation* copy() const;
    void copyTo(OpcUa_Annotation *pDst) const;

    static OpcUa_Annotation* clone(const OpcUa_Annotation& source);
    static void cloneTo(const OpcUa_Annotation& source, OpcUa_Annotation& copy);

    void attach(OpcUa_Annotation *pValue);
    OpcUa_Annotation* detach(OpcUa_Annotation* pDst);

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

    OpcUa_StatusCode setAnnotation(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setAnnotation(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setAnnotation(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setAnnotation(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setAnnotation(
        const UaString& message,
        const UaString& userName,
        const UaDateTime& annotationTime
        );

    UaString getMessage() const;
    UaString getUserName() const;
    UaDateTime getAnnotationTime() const;

    void setMessage(const UaString& message);
    void setUserName(const UaString& userName);
    void setAnnotationTime(const UaDateTime& annotationTime);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_Annotation.
 *
 *  This class encapsulates an array of the native OpcUa_Annotation structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaAnnotation for information about the encapsulated structure.
 */
class UABASE_EXPORT UaAnnotations
{
public:
    UaAnnotations();
    UaAnnotations(const UaAnnotations &other);
    UaAnnotations(OpcUa_Int32 length, OpcUa_Annotation* data);
    virtual ~UaAnnotations();

    UaAnnotations& operator=(const UaAnnotations &other);
    const OpcUa_Annotation& operator[](OpcUa_UInt32 index) const;
    OpcUa_Annotation& operator[](OpcUa_UInt32 index);

    bool operator==(const UaAnnotations &other) const;
    bool operator!=(const UaAnnotations &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_Annotation* data);
    void attach(OpcUa_Int32 length, OpcUa_Annotation* data);
    OpcUa_Annotation* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_Annotation* rawData() const {return m_data;}
    inline OpcUa_Annotation* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setAnnotations(const UaVariant &variant);
    OpcUa_StatusCode setAnnotations(const OpcUa_Variant &variant);
    OpcUa_StatusCode setAnnotations(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setAnnotations(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setAnnotations(OpcUa_Int32 length, OpcUa_Annotation* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_Annotation* m_data;
};

#endif // UAANNOTATION_H

