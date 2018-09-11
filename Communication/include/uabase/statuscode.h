/******************************************************************************
** statuscode.h
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
** OPC server status code class.
**
******************************************************************************/
#ifndef STATUSCODE_H
#define STATUSCODE_H

#include "uaplatformdefs.h"
#include "opcua_proxystub.h"
#include "ualocalizedtext.h"
#include "uaqualifiedname.h"
#include "uaarraytemplates.h"
#include "uadiagnosticinfos.h"
#include <map>
#include "uastring.h"

class UABASE_EXPORT UaDiagnosticInfo;
class UABASE_EXPORT UaVariant;
class UABASE_EXPORT UaDataValue;

/*! \addtogroup CppBaseLibraryClass
*  @{
*/

/** @brief The class encapsulates the OPC UA data type StatusCodes and
    conversions from and to Classic OPC codes.

A StatusCode in OPC UA is a numerical value that is used to report the outcome of an operation
performed by an OPC UA Server. This code may have associated diagnostic information that
describes the status in more detail; however, the code by itself is intended to provide Client
applications with enough information to make decisions on how to process the results of an OPC
UA Service.

The derived class \ref UaStatus is used to combine the StatusCode with associated diagnostic information
in one object.

The StatusCode is a 32-bit unsigned integer. The top 16 bits represent the numeric value of the
code that shall be used for detecting specific errors or conditions. The bottom 16 bits are bit flags
that contain additional information but do not affect the meaning of the StatusCode.
All OPC UA Clients shall always check the StatusCode associated with a result before using it.
Results that have an uncertain/warning status associated with them shall be used with care since
these results might not be valid in all situations. Results with a bad/failed status shall never be
used.

OPC UA Servers should return good/success StatusCodes if the operation completed normally and
the result is always valid. Different StatusCode values can provide additional information to the
Client.

OPC UA Servers should use uncertain/warning StatusCodes if they could not complete the
operation in the manner requested by the Client, however, the operation did not fail entirely.

The codes for the top 16 bits of the StatusCode are defined by the OPC UA specification and it is not
allowed to extend these codes with application specific codes. Application specific codes must be
provided in the diagnostic information.

All OPC UA defined codes have a symbolic name and a numeric value. The SDK provides defines with the
symbolic name for the defined codes. The general defines are OpcUa_Good and OpcUa_Bad. All defines for
the other more specific good codes start with OpcUa_Good like OpcUa_GoodMoreData. All defines for
the other more specific bad codes start with OpcUa_Bad like OpcUa_BadInvalidArgument.

The method UaStatusCode::toString() returns the symbolic name for a status code value.

The following table contains the StatusCode bit assignments.

Field            | Bit Range | Description
-----------------|-----------|------------------------------------------------------------
Severity         | 30:31     | Indicates whether the StatusCode represents a good (00), bad (10), or uncertain (01) condition.
Reserved         | 29:28     | Reserved for future use. Shall always be zero.
SubCode          | 16:27     | The code is a numeric value assigned to represent different conditions. Each code has a symbolic name and a numeric value.
StructureChanged | 15:15     | Indicates that the structure of the associated data value has changed since the last Notification. Clients should not process the data value unless they reread the metadata. See detailed description after the table.
SemanticsChanged | 14:14     | Indicates that the semantics of the associated data value have changed. Clients should not process the data value until they reread the metadata associated with the Variable. See detailed description after the table.
Reserved         | 12:13     | Reserved for future use. Shall always be zero.
InfoType         | 10:11     | The type of information contained in the info bits. The valid options are NotUsed (00) and DataValue (01). All other options are reserved for future use.
InfoBits         | 0:9       | Additional information bits that qualify the StatusCode. The structure of these bits depends on the Info Type field.

The StructureChanged flag indicates that the structure of the associated data value has changed since the last
Notification. Clients should not process the data value unless they reread the metadata.
Servers shall set this bit if the structure data type used for a Variable changes.
The bit is also set if the data type Attribute of the Variable changes. A Variable with data type
BaseDataType does not require the bit to be set when the data type changes.
Servers shall also set this bit if the ArrayDimensions or the ValueRank Attribute or the
EnumStrings Property of the DataType of the Variable changes.
This bit is provided to warn Clients that parse structure data type values that their parsing routines
could fail because the serialized form of the data value has changed.
This bit has meaning only for StatusCodes returned as part of a data change Notification or
the HistoryRead. StatusCodes used in other contexts shall always set this bit to zero.

The SemanticsChanged flag indicates that the semantics of the associated data value have changed. Clients should not
process the data value until they reread the metadata associated with the Variable. Servers should set this bit
if the metadata has changed in way that could cause application errors if the Client does not reread the metadata.
For example, a change to the engineering units could create problems if the Client uses the value to perform calculations.
Data Access variable type defines the conditions where a Server shall set this bit for a DA Variable. Other
specifications may define additional conditions. A Server may define other conditions that cause this bit to be set.
This bit has meaning only for StatusCodes returned as part of a data change Notification or
the HistoryRead. StatusCodes used in other contexts shall always set this bit to zero.

The following table contains the DataValue InfoBits

<table>
  <tr>
    <th>Info Type</th>
    <th>Bit Range</th>
    <th>Description</th>
  </tr>
  <tr>
    <td>LimitBits</td>
    <td>8:9</td>
    <td>The limit bits associated with the data value. The limits bits
    have the meanings
      <dl>
        <dt>None (00)</dt><dd>The value is free to change,</dd>
        <dt>Low (01)</dt><dd>The value is at the lower limit for the
        data source,</dd>
        <dt>High (02)</dt><dd>The value is at the higher limit for the
        data source,</dd>
        <dt>Constant (11)</dt><dd>The value is constant and cannot
        change.</dd>
      </dl>
  </tr>
  <tr>
    <td>Overflow</td>
    <td>7:7</td>
    <td>If this bit is set, not every detected change has been
    returned since the Server’s queue buffer for the MonitoredItem
    reached its limit and had to purge out data.</td>
  </tr>
  <tr>
    <td>Reserved</td>
    <td>5:6</td>
    <td>Reserved for future use. Shall always be zero.</td>
  </tr>
  <tr>
    <td>HistorianBits</td>
    <td>0:4</td>
    <td>These bits are set only when reading historical data. They
    indicate where the data value came from and provide information
    that affects how the Client uses the data value. The historian
    bits have the meaning
    <dl>
      <dt>Raw (XXX00)</dt><dd>A raw data value,</dd>
      <dt>Calculated (XXX01)</dt><dd>A data value which was
      calculated,</dd>
      <dt>Interpolated (XXX10)</dt><dd>A data value which was
      interpolated,</dd>
      <dt> Reserved (XXX11),</dt><dd></dd>
      <dt>Partial (XX1XX)</dt><dd>A data value which was calculated
      with an incomplete interval,</dd>
      <dt>Extra Data (X1XXX)</dt><dd>A raw data value that hides other
      data at the same timestamp,</dd>
      <dt>Multi Value (1XXXX)</dt><dd>Multiple values match the
      aggregate criteria (i.e. multiple minimum values at different
      timestamps within the same interval)</dd>
    </dl>
  </tr>
</table>
*/
class UABASE_EXPORT UaStatusCode
{
public:
    /* construction. */
    UaStatusCode();
    UaStatusCode(const OpcUa_StatusCode &other);
    /* destruction */
    ~UaStatusCode();

    /* Implements the operator = for OpcUa_StatusCode */
    UaStatusCode& operator=(const OpcUa_StatusCode &other);
    /* Implements the operator = for UaStatusCode */
    UaStatusCode& operator=(const UaStatusCode &other);
    /* Implements the operator == for OpcUa_StatusCode */
    bool operator==(const OpcUa_StatusCode &other);
    /* Implements the operator == for UaStatusCode */
    bool operator==(const UaStatusCode &other);
    /* Implements the operator != for OpcUa_StatusCode */
    bool operator!=(const OpcUa_StatusCode &other);
    /* Implements the operator != for UaStatusCode */
    bool operator!=(const UaStatusCode &other);


    /** Checks if the status code is GOOD */
    inline OpcUa_Boolean isGood() const   { return OpcUa_IsGood(m_StatusCode); };
    /** Checks if the status code is not GOOD */
    inline OpcUa_Boolean isNotGood() const { return OpcUa_IsNotGood(m_StatusCode); };
    /** Checks if the status code is UNCERTAIN */
    inline OpcUa_Boolean isUncertain() const { return OpcUa_IsUncertain(m_StatusCode); };
    /** Checks if the status code is not UNCERTAIN */
    inline OpcUa_Boolean isNotUncertain() const { return OpcUa_IsNotUncertain(m_StatusCode); };
    /** Checks if the status code is BAD */
    inline OpcUa_Boolean isBad() const { return OpcUa_IsBad(m_StatusCode); };
    /** Checks if the status code is not BAD */
    inline OpcUa_Boolean isNotBad() const { return OpcUa_IsNotBad(m_StatusCode); };

    /** Gets the full status code value */
    inline OpcUa_StatusCode statusCode() const { return m_StatusCode; };
    /** Gets the code part (Severity + SubCode) of the status code value */
    inline OpcUa_StatusCode code() const { return OpcUa_GetCode(m_StatusCode); };
    /** Gets the InfoType part of the status code value */
    inline OpcUa_StatusCode infoType() const { return OpcUa_GetInfoType(m_StatusCode); };
    /** Gets the InfoBits part of the status code value */
    inline OpcUa_StatusCode infoBits() const { return OpcUa_GetInfoBits(m_StatusCode); };

    /** Sets the DataValue bit in the InfoType and the Overflow bit in the InfoBits. */
    inline void setOverflowBits() { m_StatusCode = ((m_StatusCode | OpcUa_StatusCode_InfoType_DataValue | OpcUa_StatusCode_InfoBit_Overflow)); }

    /** Sets the StructureChanged bit in the status code value. */
    inline void setStructureChangedBit() { m_StatusCode = ((m_StatusCode | OpcUa_StatusCode_StructureChanged)); }
    /** Checks if the StructureChanged bit is set in the status code value. */
    inline bool isStructureChanged() const { return (m_StatusCode & OpcUa_StatusCode_StructureChanged) == OpcUa_StatusCode_StructureChanged; };

    /** Sets the SemanticsChanged bit in the status code value. */
    inline void setSemanticsChangedBit() { m_StatusCode = ((m_StatusCode | OpcUa_StatusCode_SemanticsChanged)); }
    /** Checks if the SemanticsChanged bit is set in the status code value. */
    inline bool isSemanticsChanged() const { return (m_StatusCode & OpcUa_StatusCode_SemanticsChanged) == OpcUa_StatusCode_SemanticsChanged; };

    /* Creates a response header for OPC UA service calls */
    void getResponseHeader(OpcUa_RequestHeader*  requestHeader, OpcUa_ResponseHeader* responseHeader);

    /* Return string representation of an OPC UA Status Code*/
    UaString toString() const;

    /* Returns string representation of a known OpcUa_StatusCode*/
    static UaString toString(OpcUa_StatusCode statusCode);
    /* Gets the status code from a COM DA error code */
    static OpcUa_StatusCode setComDaError(long comDaError);
    /* Gets the status code from a COM DA quality */
    static OpcUa_StatusCode setComDaQuality(unsigned short comDaQuality);
    /* Gets the status code from a COM HDA quality */
    static OpcUa_StatusCode setComHdaQuality(unsigned long comHdaQuality);
    /* Gets the status code from COM DA error and quality */
    static OpcUa_StatusCode setComDaStatus(long comDaError, unsigned short comDaQuality);
    /* Gets COM DA error and quality from a status code */
    static void getComDaStatus(const OpcUa_StatusCode statusCode, long& comDaError, unsigned short& comDaQuality, bool isValueRelated = false);

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;

protected:
    OpcUa_StatusCode m_StatusCode;
    static std::map<OpcUa_StatusCode, const char*> s_mapStatusToString;
};


/** @brief This class handles status codes, conversions of the status code and diagnostic information.

The class is derived from \ref UaStatusCode and is used to combine the StatusCode with associated diagnostic information
in one object. The class \ref UaStatusCode encapsulated OPC UA data type StatusCodes and conversions from and to Classic OPC codes

See \ref UaStatusCode for StatusCode related documentation and functions.

 */
class UABASE_EXPORT UaStatus: public UaStatusCode
{
public:
    /* construction. */
    UaStatus();
    UaStatus(const OpcUa_StatusCode &other);
    UaStatus(const UaStatusCode &other);
    UaStatus(const UaStatus &other);
    /* destruction */
    ~UaStatus();

    /* Implements the operator = for OpcUa_StatusCode */
    UaStatus& operator=(const OpcUa_StatusCode &other);
    /* Implements the operator = for UaStatusCode */
    UaStatus& operator=(const UaStatusCode &other);
    /* Implements the operator = for UaStatus */
    UaStatus& operator=(const UaStatus &other);

    /* Set a status code and a diagnostic info string */
    void setStatus(OpcUa_StatusCode statusCode, const UaString& sDiagnosticInfo);
    /* Set diagnostic info */
    void setDiagnosticInfo(const UaString& namespaceUri, const UaString& symbolicId, const UaLocalizedText& localizedText);
    void setDiagnosticInfo(const UaString& namespaceUri, OpcUa_UInt32 numericReturnCode, const UaLocalizedText& localizedText);
    void setDiagnosticInfo(UaDiagnosticInfo* pDiagnosticInfo);
    /* Set the string for additional diagnostic information */
    void setAdditionalInfo(const UaString& sAdditionalInfo);
    /* Set the nested inner status containing a StatusCode and optional inner DiagnosticInformation */
    void setInnerStatus(const UaStatus& innerStatus);

    /** Provides access to the optional DiagnosticInformation.
     * The returned pointer is NULL if there is no DiagnosticInformation available.
     */
    inline UaDiagnosticInfo* pDiagnosticInfo() const {return m_pDiagnosticInfo;}
protected:
    UaDiagnosticInfo* m_pDiagnosticInfo;
};

/** @brief This class contains the diagnostic information in full format.
 *  It is not possible to create plain copies of this Class.
 */
class UABASE_EXPORT UaDiagnosticInfo
{
    UA_DISABLE_COPY(UaDiagnosticInfo);
protected:
    /** destruction */
    ~UaDiagnosticInfo(){}
public:
    /* construction. */
    UaDiagnosticInfo();

    int addRef();
    int release();

    UaString        m_namespaceUri;
    UaString        m_symbolicId;
    UaLocalizedText m_localizedText;
    UaString        m_sAdditionalInfo;
    UaStatus        m_innerStatus;
private:
    int             m_iRefCnt;
};

/*! @} */

/** An array of UaDiagnosticInfo */
typedef UaPointerArray<UaDiagnosticInfo> UaDiagnosticInfoRawArray;

// Creates a diagnostic info array for OPC UA service calls
UABASE_EXPORT void createDiagnosticInfoArray(
    OpcUa_UInt32                    returnDiagnostics,
    const UaDiagnosticInfoRawArray& pDiagnosticInfoArray,
    UaDiagnosticInfos&              diagnosticInfos,
    OpcUa_Boolean&                  isDiagAvailable,
    OpcUa_ResponseHeader*           responseHeader);

// Creates a diagnostic info array for OPC UA service calls
// appends the string from pDiagnosticInfoArray to existingTable and creates diagnosticInfos
UABASE_EXPORT void createDiagnosticInfoArray(
    OpcUa_UInt32                    returnDiagnostics,
    std::map<UaString, OpcUa_Int32> existingTable,
    const UaDiagnosticInfoRawArray& pDiagnosticInfoArray,
    UaDiagnosticInfos&              diagnosticInfos,
    OpcUa_Boolean&                  isDiagAvailable,
    OpcUa_ResponseHeader*           responseHeader);

// Create diagnostic info - for service fault
UABASE_EXPORT void createDiagnosticInfo(
    OpcUa_UInt32            returnDiagnostics,
    UaDiagnosticInfo*       pDiagnostics,
    OpcUa_DiagnosticInfo**  ppServiceDiagnostics,
    OpcUa_Int32&            noOfStringTable,
    OpcUa_String**          ppStringTable);

// Extract a UaDiagnosticInfo from OpcUa_DiagnosticInfo and a string table
UABASE_EXPORT UaDiagnosticInfo* extractUaDiagnosticInfo(
    const OpcUa_DiagnosticInfo& diagnosticInfo,
    OpcUa_Int32                 noOfStringTable,
    OpcUa_String*               pStringTable);

#endif // STATUSCODE_H
