/******************************************************************************
** uaprogramdiagnosticdatatype.h
**
** Copyright (c) 2006-2016 Unified Automation GmbH All rights reserved.
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
** Portable UaProgramDiagnosticDataType class.
**
******************************************************************************/
#ifndef UAPROGRAMDIAGNOSTICDATATYPE_H
#define UAPROGRAMDIAGNOSTICDATATYPE_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "uaargument.h"
#include "uadatetime.h"
#include "uanodeid.h"
#include "statuscode.h"
#include "uastring.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaProgramDiagnosticDataTypePrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_ProgramDiagnosticDataType.
 *
 *  This class encapsulates the native OpcUa_ProgramDiagnosticDataType structure
 *  and handles memory allocation and cleanup for you.
 *  UaProgramDiagnosticDataType uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared ProgramDiagnosticDataType it creates a copy for that (copy-on-write).
 *  So assigning another UaProgramDiagnosticDataType or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 */
class UABASE_EXPORT UaProgramDiagnosticDataType
{
    UA_DECLARE_PRIVATE(UaProgramDiagnosticDataType)
public:
    UaProgramDiagnosticDataType();
    UaProgramDiagnosticDataType(const UaProgramDiagnosticDataType &other);
    UaProgramDiagnosticDataType(const OpcUa_ProgramDiagnosticDataType &other);
    UaProgramDiagnosticDataType(
        const UaNodeId& createSessionId,
        const UaString& createClientName,
        const UaDateTime& invocationCreationTime,
        const UaDateTime& lastTransitionTime,
        const UaString& lastMethodCall,
        const UaNodeId& lastMethodSessionId,
        const UaArguments &lastMethodInputArguments,
        const UaArguments &lastMethodOutputArguments,
        const UaDateTime& lastMethodCallTime,
        const UaStatus& lastMethodReturnStatus
        );
    UaProgramDiagnosticDataType(const UaExtensionObject &extensionObject);
    UaProgramDiagnosticDataType(const OpcUa_ExtensionObject &extensionObject);
    UaProgramDiagnosticDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaProgramDiagnosticDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    ~UaProgramDiagnosticDataType();

    void clear();

    bool operator==(const UaProgramDiagnosticDataType &other) const;
    bool operator!=(const UaProgramDiagnosticDataType &other) const;

    UaProgramDiagnosticDataType& operator=(const UaProgramDiagnosticDataType &other);

    OpcUa_ProgramDiagnosticDataType* copy() const;
    void copyTo(OpcUa_ProgramDiagnosticDataType *pDst) const;

    static OpcUa_ProgramDiagnosticDataType* clone(const OpcUa_ProgramDiagnosticDataType& source);
    static void cloneTo(const OpcUa_ProgramDiagnosticDataType& source, OpcUa_ProgramDiagnosticDataType& copy);

    void attach(OpcUa_ProgramDiagnosticDataType *pValue);
    OpcUa_ProgramDiagnosticDataType* detach(OpcUa_ProgramDiagnosticDataType* pDst);

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

    OpcUa_StatusCode setProgramDiagnosticDataType(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setProgramDiagnosticDataType(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setProgramDiagnosticDataType(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setProgramDiagnosticDataType(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setProgramDiagnosticDataType(
        const UaNodeId& createSessionId,
        const UaString& createClientName,
        const UaDateTime& invocationCreationTime,
        const UaDateTime& lastTransitionTime,
        const UaString& lastMethodCall,
        const UaNodeId& lastMethodSessionId,
        const UaArguments &lastMethodInputArguments,
        const UaArguments &lastMethodOutputArguments,
        const UaDateTime& lastMethodCallTime,
        const UaStatus& lastMethodReturnStatus
        );

    UaNodeId getCreateSessionId() const;
    UaString getCreateClientName() const;
    UaDateTime getInvocationCreationTime() const;
    UaDateTime getLastTransitionTime() const;
    UaString getLastMethodCall() const;
    UaNodeId getLastMethodSessionId() const;
    void getLastMethodInputArguments(UaArguments& lastMethodInputArguments) const;
    void getLastMethodOutputArguments(UaArguments& lastMethodOutputArguments) const;
    UaDateTime getLastMethodCallTime() const;
    UaStatus getLastMethodReturnStatus() const;

    void setCreateSessionId(const UaNodeId& createSessionId);
    void setCreateClientName(const UaString& createClientName);
    void setInvocationCreationTime(const UaDateTime& invocationCreationTime);
    void setLastTransitionTime(const UaDateTime& lastTransitionTime);
    void setLastMethodCall(const UaString& lastMethodCall);
    void setLastMethodSessionId(const UaNodeId& lastMethodSessionId);
    void setLastMethodInputArguments(const UaArguments &lastMethodInputArguments);
    void setLastMethodOutputArguments(const UaArguments &lastMethodOutputArguments);
    void setLastMethodCallTime(const UaDateTime& lastMethodCallTime);
    void setLastMethodReturnStatus(const UaStatus& lastMethodReturnStatus);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_ProgramDiagnosticDataType.
 *
 *  This class encapsulates an array of the native OpcUa_ProgramDiagnosticDataType structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaProgramDiagnosticDataType for information about the encapsulated structure.
 */
class UABASE_EXPORT UaProgramDiagnosticDataTypes
{
public:
    UaProgramDiagnosticDataTypes();
    UaProgramDiagnosticDataTypes(const UaProgramDiagnosticDataTypes &other);
    UaProgramDiagnosticDataTypes(OpcUa_Int32 length, OpcUa_ProgramDiagnosticDataType* data);
    virtual ~UaProgramDiagnosticDataTypes();

    UaProgramDiagnosticDataTypes& operator=(const UaProgramDiagnosticDataTypes &other);
    const OpcUa_ProgramDiagnosticDataType& operator[](OpcUa_UInt32 index) const;
    OpcUa_ProgramDiagnosticDataType& operator[](OpcUa_UInt32 index);

    bool operator==(const UaProgramDiagnosticDataTypes &other) const;
    bool operator!=(const UaProgramDiagnosticDataTypes &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_ProgramDiagnosticDataType* data);
    void attach(OpcUa_Int32 length, OpcUa_ProgramDiagnosticDataType* data);
    OpcUa_ProgramDiagnosticDataType* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_ProgramDiagnosticDataType* rawData() const {return m_data;}
    inline OpcUa_ProgramDiagnosticDataType* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setProgramDiagnosticDataTypes(const UaVariant &variant);
    OpcUa_StatusCode setProgramDiagnosticDataTypes(const OpcUa_Variant &variant);
    OpcUa_StatusCode setProgramDiagnosticDataTypes(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setProgramDiagnosticDataTypes(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setProgramDiagnosticDataTypes(OpcUa_Int32 length, OpcUa_ProgramDiagnosticDataType* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_ProgramDiagnosticDataType* m_data;
};

#endif // UAPROGRAMDIAGNOSTICDATATYPE_H

