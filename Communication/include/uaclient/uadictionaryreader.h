/******************************************************************************
** uadictionaryreader.h
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
#ifndef UADICTIONARYREADER_H
#define UADICTIONARYREADER_H

#include <map>

#include "uasession.h"
#include <uaabstractdictionaryreader.h>

namespace UaClientSdk {

class UaDictionaryReader : public UaAbstractDictionaryReader
{
    UA_DISABLE_COPY(UaDictionaryReader);
public:
    UaDictionaryReader(UaSession *pSession, unsigned int blockSize = OPCUA_ENCODER_MAXBYTESTRINGLENGTH);
    ~UaDictionaryReader();

    void setCallTimeout(OpcUa_Int32 milliseconds);
    OpcUa_Int32 callTimeout() const;

protected:
    //helpers
    virtual UaStatus browse(
        const UaNodeId &startingNodeId,
        const UaNodeId &referenceTypeId,
        /*out*/ UaReferenceDescriptions &rResults) const;
    virtual UaStatus browseInverse(
        const UaNodeId &startingNodeId,
        const UaNodeId &referenceTypeId,
        /*out*/ UaReferenceDescriptions &rResults) const;
    virtual UaStatus browseList(
        const UaBrowseDescriptions &browseDescriptions,
        /* out */ UaBrowseResults &rDescriptions) const;
    virtual UaStatus browseList(
        const UaNodeIdArray &startingNodeIds,
        const UaNodeId &referenceTypeId,
        UaReferenceDescriptions &rResults) const;
    virtual UaStatus browseList(
        const UaNodeIdArray &startingNodeIds,
        const UaNodeId &referenceTypeId,
        UaBrowseResults &rResults) const;
    virtual UaStatus browseListInverse(
        const UaNodeIdArray &startingNodeIds,
        const UaNodeId &referenceTypeId,
        UaReferenceDescriptions &rResults) const;
    virtual UaStatus browseListInverse(
        const UaNodeIdArray &startingNodeIds,
        const UaNodeId &referenceTypeId,
        UaBrowseResults &rResults) const;
    virtual UaStatus browseListWithLimits(
        ServiceSettings&             serviceSettings,
        const OpcUa_ViewDescription& viewDescription,
        OpcUa_UInt32                 maxReferencesToReturn,
        const UaBrowseDescriptions&  browseDescription,
        UaBrowseResults&             browseResults,
        UaDiagnosticInfos&           diagnosticInfos) const;
    virtual UaStatus browseCompleteWithContinuationPoint(ServiceSettings &serviceSettings,
        const OpcUa_ViewDescription &viewDescription,
        OpcUa_UInt32 maxReferencesToReturn,
        const UaBrowseDescriptions &browseDescription,
        UaBrowseResults &browseResults) const;
    virtual UaStatus translate(
        const UaNodeId &startingNodeId,
        const UaQualifiedName &browseName,
        const UaNodeId &referenceTypeId,
        /*out*/ UaNodeId &targetNodeId) const;
    virtual UaStatus translateBrowsePaths(
        const UaNodeIdArray &startingNodeIds,
        const UaNodeId &referenceTypeId,
        const UaQualifiedName &browseName,
        /*out*/ UaBrowsePathResults &targetNodes) const;
    virtual UaStatus translateBrowsePathsInverse(
        const UaNodeIdArray &startingNodeIds,
        const UaNodeId &referenceTypeId,
        const UaQualifiedName &browseName,
        /*out*/ UaNodeIdArray &targetNodes) const;
    virtual UaStatus translateBrowsePaths(
        const UaReferenceDescriptions &startingNodes,
        const UaNodeId &referenceTypeId,
        const UaQualifiedName &browseName,
        /*out*/ UaBrowsePathResults &targetNodes) const;
    virtual UaStatus readValue(
        const UaNodeId &nodeId,
        /*out*/ UaVariant &rValue) const;
    virtual UaStatus readValues(
        const UaNodeIdArray &nodeIds,
        /*out*/ UaDataValues &rValues) const;
    virtual UaStatus readDictionaryValues(
        const UaNodeIdArray &nodeIds,
        /*out*/ UaByteStringArray &rValues) const;
    virtual UaStatus readDescriptionAttributes(
        const UaNodeIdArray &nodeIds,
        UaLocalizedTextArray &rValues) const;

private:
    bool continuationPointsFromBrowseResults(
        const UaBrowseResults &results,
        UaBoolArray &rResultsWithContinuationPoints,
        UaByteStringArray &rContinuationPoints) const;
    void moveBrowseResults(
        UaBrowseResults &target,
        UaBrowseResults &source,
        const UaBoolArray &usedBrowseResults) const;
    UaStatus browseNext(
        UaBrowseResults &rResults,
        ServiceSettings &serviceSettings) const;
    UaStatus browseNext(
        UaReferenceDescriptions &rResults,
        UaByteString &rContinuationPoint,
        ServiceSettings &serviceSettings) const;
    void resultsToDescriptions(
        UaBrowseResults &rResults,
        UaReferenceDescriptions &rDescriptions) const;

    UaSession *m_pSession;
    unsigned int m_blockSize;
    OpcUa_Int32 m_callTimeout;
};

};
#endif // UADICTIONARYREADER_H
