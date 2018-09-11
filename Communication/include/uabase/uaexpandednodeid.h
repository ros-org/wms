/******************************************************************************
** uaexpandednodeid.h
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
** Portable Ua ExpandedNodeId class.
**
******************************************************************************/
#ifndef UAEXPANDEDNODEID_H
#define UAEXPANDEDNODEID_H

#include "opcua_proxystub.h"
#include "uanodeid.h"
#include "uastring.h"

class UABASE_EXPORT UaVariant;
class UABASE_EXPORT UaDataValue;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_ExpandedNodeId.
 */
class UABASE_EXPORT UaExpandedNodeId : private OpcUa_ExpandedNodeId
{
public:
    UaExpandedNodeId();
    UaExpandedNodeId(const UaExpandedNodeId &other);
    UaExpandedNodeId(const OpcUa_ExpandedNodeId &other);
    UaExpandedNodeId(const UaNodeId &id, const UaString &sNsUri, OpcUa_UInt32 serverIndex);
    ~UaExpandedNodeId();

    void clear();
    void attach(const OpcUa_ExpandedNodeId *pSrc);
    void detach();

    UaExpandedNodeId& operator=(const UaExpandedNodeId &other);

    bool operator==(const UaExpandedNodeId &other) const;
    bool operator!=(const UaExpandedNodeId &other) const;
    bool ExpandednodeIdCompare(OpcUa_ExpandedNodeId* pExpandedNodeId);
    static bool compare(const OpcUa_ExpandedNodeId&, const OpcUa_ExpandedNodeId&);//be

    void setExpandedNodeId(const UaNodeId &id, const UaString &sNsUri, OpcUa_UInt32 serverIndex);

    operator const OpcUa_ExpandedNodeId*() const;

    OpcUa_ExpandedNodeId* copy() const;
    void copyTo(OpcUa_ExpandedNodeId *pDst) const;
    static OpcUa_ExpandedNodeId* clone(const OpcUa_ExpandedNodeId& source);
    static void cloneTo(const OpcUa_ExpandedNodeId& source, OpcUa_ExpandedNodeId& copy);

    UaString toString() const;
    UaString toFullString() const;

    /** Get the actual node id.
     *  @return the actual node id.
     */
    inline OpcUa_NodeId nodeId() const { return this->NodeId; };

    /** Get the namespace URI.
     *  @return the namespace URI.
     */
    inline const OpcUa_String* namespaceUri() const { return &this->NamespaceUri; };

    /** Get the server index.
     *  @return the server index.
     */
    inline OpcUa_UInt32 serverIndex() const { return this->ServerIndex; };

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
};

#endif // UANODEID_H
