/******************************************************************************
** uanodeattributes.h
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
** Portable UA NodeAttributes classes.
**
******************************************************************************/
#ifndef UANODEATTRIBUTES_H
#define UANODEATTRIBUTES_H

#include "opcua_proxystub.h"
#include "uaplatformdefs.h"

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_ObjectAttributes.
 */
class UABASE_EXPORT UaObjectAttributes: private OpcUa_ObjectAttributes
{
public:
    UaObjectAttributes();
    UaObjectAttributes(const UaObjectAttributes &other);
    UaObjectAttributes(const OpcUa_ObjectAttributes &other);
    ~UaObjectAttributes();
    void clear();

    UaObjectAttributes& operator=(const UaObjectAttributes &other);

    operator const OpcUa_ObjectAttributes*() const;

    OpcUa_ObjectAttributes* copy() const;
    void copyTo(OpcUa_ObjectAttributes *pDst) const;

    static OpcUa_ObjectAttributes* clone(const OpcUa_ObjectAttributes& source);
    static void cloneTo(const OpcUa_ObjectAttributes& source, OpcUa_ObjectAttributes& copy);

    void detach();
};

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_VariableAttributes.
 */
class UABASE_EXPORT UaVariableAttributes: private OpcUa_VariableAttributes
{
public:
    UaVariableAttributes();
    UaVariableAttributes(const UaVariableAttributes &other);
    UaVariableAttributes(const OpcUa_VariableAttributes &other);
    ~UaVariableAttributes();
    void clear();

    UaVariableAttributes& operator=(const UaVariableAttributes &other);

    operator const OpcUa_VariableAttributes*() const;

    OpcUa_VariableAttributes* copy() const;
    void copyTo(OpcUa_VariableAttributes *pDst) const;

    static OpcUa_VariableAttributes* clone(const OpcUa_VariableAttributes& source);
    static void cloneTo(const OpcUa_VariableAttributes& source, OpcUa_VariableAttributes& copy);

    void detach();
};

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_MethodAttributes.
 */
class UABASE_EXPORT UaMethodAttributes: private OpcUa_MethodAttributes
{
public:
    UaMethodAttributes();
    UaMethodAttributes(const UaMethodAttributes &other);
    UaMethodAttributes(const OpcUa_MethodAttributes &other);
    ~UaMethodAttributes();
    void clear();

    UaMethodAttributes& operator=(const UaMethodAttributes &other);

    operator const OpcUa_MethodAttributes*() const;

    OpcUa_MethodAttributes* copy() const;
    void copyTo(OpcUa_MethodAttributes *pDst) const;

    static OpcUa_MethodAttributes* clone(const OpcUa_MethodAttributes& source);
    static void cloneTo(const OpcUa_MethodAttributes& source, OpcUa_MethodAttributes& copy);

    void detach();
};

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_ObjectTypeAttributes.
 */
class UABASE_EXPORT UaObjectTypeAttributes: private OpcUa_ObjectTypeAttributes
{
public:
    UaObjectTypeAttributes();
    UaObjectTypeAttributes(const UaObjectTypeAttributes &other);
    UaObjectTypeAttributes(const OpcUa_ObjectTypeAttributes &other);
    ~UaObjectTypeAttributes();
    void clear();

    UaObjectTypeAttributes& operator=(const UaObjectTypeAttributes &other);

    operator const OpcUa_ObjectTypeAttributes*() const;

    OpcUa_ObjectTypeAttributes* copy() const;
    void copyTo(OpcUa_ObjectTypeAttributes *pDst) const;

    static OpcUa_ObjectTypeAttributes* clone(const OpcUa_ObjectTypeAttributes& source);
    static void cloneTo(const OpcUa_ObjectTypeAttributes& source, OpcUa_ObjectTypeAttributes& copy);

    void detach();
};

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_VariableTypeAttributes.
 */
class UABASE_EXPORT UaVariableTypeAttributes: private OpcUa_VariableTypeAttributes
{
public:
    UaVariableTypeAttributes();
    UaVariableTypeAttributes(const UaVariableTypeAttributes &other);
    UaVariableTypeAttributes(const OpcUa_VariableTypeAttributes &other);
    ~UaVariableTypeAttributes();
    void clear();

    UaVariableTypeAttributes& operator=(const UaVariableTypeAttributes &other);

    operator const OpcUa_VariableTypeAttributes*() const;

    OpcUa_VariableTypeAttributes* copy() const;
    void copyTo(OpcUa_VariableTypeAttributes *pDst) const;

    static OpcUa_VariableTypeAttributes* clone(const OpcUa_VariableTypeAttributes& source);
    static void cloneTo(const OpcUa_VariableTypeAttributes& source, OpcUa_VariableTypeAttributes& copy);

    void detach();
};

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_ReferenceTypeAttributes.
 */
class UABASE_EXPORT UaReferenceTypeAttributes: private OpcUa_ReferenceTypeAttributes
{
public:
    UaReferenceTypeAttributes();
    UaReferenceTypeAttributes(const UaReferenceTypeAttributes &other);
    UaReferenceTypeAttributes(const OpcUa_ReferenceTypeAttributes &other);
    ~UaReferenceTypeAttributes();
    void clear();

    UaReferenceTypeAttributes& operator=(const UaReferenceTypeAttributes &other);

    operator const OpcUa_ReferenceTypeAttributes*() const;

    OpcUa_ReferenceTypeAttributes* copy() const;
    void copyTo(OpcUa_ReferenceTypeAttributes *pDst) const;

    static OpcUa_ReferenceTypeAttributes* clone(const OpcUa_ReferenceTypeAttributes& source);
    static void cloneTo(const OpcUa_ReferenceTypeAttributes& source, OpcUa_ReferenceTypeAttributes& copy);

    void detach();
};

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_DataTypeAttributes.
 */
class UABASE_EXPORT UaDataTypeAttributes: private OpcUa_DataTypeAttributes
{
public:
    UaDataTypeAttributes();
    UaDataTypeAttributes(const UaDataTypeAttributes &other);
    UaDataTypeAttributes(const OpcUa_DataTypeAttributes &other);
    ~UaDataTypeAttributes();
    void clear();

    UaDataTypeAttributes& operator=(const UaDataTypeAttributes &other);

    operator const OpcUa_DataTypeAttributes*() const;

    OpcUa_DataTypeAttributes* copy() const;
    void copyTo(OpcUa_DataTypeAttributes *pDst) const;

    static OpcUa_DataTypeAttributes* clone(const OpcUa_DataTypeAttributes& source);
    static void cloneTo(const OpcUa_DataTypeAttributes& source, OpcUa_DataTypeAttributes& copy);

    void detach();
};

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_ViewAttributes.
 */
class UABASE_EXPORT UaViewAttributes: private OpcUa_ViewAttributes
{
public:
    UaViewAttributes();
    UaViewAttributes(const UaViewAttributes &other);
    UaViewAttributes(const OpcUa_ViewAttributes &other);
    ~UaViewAttributes();
    void clear();

    UaViewAttributes& operator=(const UaViewAttributes &other);

    operator const OpcUa_ViewAttributes*() const;

    OpcUa_ViewAttributes* copy() const;
    void copyTo(OpcUa_ViewAttributes *pDst) const;

    static OpcUa_ViewAttributes* clone(const OpcUa_ViewAttributes& source);
    static void cloneTo(const OpcUa_ViewAttributes& source, OpcUa_ViewAttributes& copy);

    void detach();
};

#endif // UANODEATTRIBUTES_H
