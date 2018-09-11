/******************************************************************************
** uaextensionobject.h
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
** Portable Ua ExtensionObject class.
**
******************************************************************************/
#ifndef UAEXTENSIONOBJECT_H
#define UAEXTENSIONOBJECT_H

#include "opcua_proxystub.h"
#include "uaplatformdefs.h"
#include "uanodeid.h"
#include "uagenericstructurevalue.h"
#include "statuscode.h"

class UaStringArray;

/**
 *  Derived from OpcUa_ExtensionObject.
 */
class UABASE_EXPORT UaExtensionObject: private OpcUa_ExtensionObject
{
public:
    /// @brief Definition of the ExtensionObjectEncoding Enumeration
    enum ExtensionObjectEncoding
    {
        None             = OpcUa_ExtensionObjectEncoding_None,              /*!< None: The ExtensionObject does not contain an data.*/
        Binary           = OpcUa_ExtensionObjectEncoding_Binary,            /*!< Binary: The data of the ExtensionObject is encoded as a binary string. Call binary() const to receive the raw data. If there is structure information available, you can call value(UaStructureDefinition structureDefinition) const.*/
        Xml              = OpcUa_ExtensionObjectEncoding_Xml,               /*!< Xml: The data of the ExtensionObject is encoded as an XML string. Call xml() const to receive the raw data.*/
        EncodeableObject = OpcUa_ExtensionObjectEncoding_EncodeableObject   /*!< EncodableObject: The ExtensionObject is encoded as object. Call object() const to receive the decoded structure. Use the constructors of the DataType classes for deserializing the ExtensionObject.*/
    };

    UaExtensionObject();
    UaExtensionObject(const UaExtensionObject &other);
    UaExtensionObject(const OpcUa_ExtensionObject &other);
    ~UaExtensionObject();
    void clear();

    UaExtensionObject& operator=(const UaExtensionObject &other);

    operator const OpcUa_ExtensionObject*() const;

    OpcUa_ExtensionObject* copy() const;
    void copyTo(OpcUa_ExtensionObject *pDst) const;

    static OpcUa_ExtensionObject* clone(const OpcUa_ExtensionObject& source);
    static void cloneTo(const OpcUa_ExtensionObject& source, OpcUa_ExtensionObject& copy);

    void detach();
    UaExtensionObject& attach(const OpcUa_ExtensionObject *pSrc);

    ExtensionObjectEncoding encoding() const;
    UaStatus changeEncoding(ExtensionObjectEncoding newEncoding);
    UaNodeId encodingTypeId() const;
    UaNodeId dataTypeId() const;
    UaNodeId dataTypeId(const UaStringArray &namespaceTable) const;
    const OpcUa_Void* object() const;
    OPCUA_P_DEPRECATED(UaGenericStructureValue value(UaStructureDefinition structureDefinition) const);
    OPCUA_P_DEPRECATED(void setValue(const UaGenericStructureValue &genericStructure, UaAbstractGenericValue::Encoding valueEncoding));
    const OpcUa_ByteString*     binary() const;
    const OpcUa_XmlElement*     xml() const;

    /* DEPRECATED functions */
    OPCUA_P_DEPRECATED(const OpcUa_EncodeableType* objectType() const);
};

#endif // UAEXTENSIONOBJECT_H
