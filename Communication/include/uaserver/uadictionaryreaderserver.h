/******************************************************************************
** uadictionaryreaderserver.h
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
** Project: C++ OPC UA Server SDK core module
**
******************************************************************************/
#ifndef UASERVER_UADICTIONARYREADERSERVER_H
#define UASERVER_UADICTIONARYREADERSERVER_H

#include <uaabstractdictionaryreader.h>
#include "servermanager.h"

class SERVER_CORE_EXPORT UaDictionaryReaderServer : public UaAbstractDictionaryReader
{
    UA_DISABLE_COPY(UaDictionaryReaderServer);
public:
    UaDictionaryReaderServer(ServerManager *pServerManager);
    ~UaDictionaryReaderServer();
protected:
    //helpers
    virtual UaStatus browse(
        const UaNodeId &startingNodeId,
        const UaNodeId &referenceTypeId,
        UaReferenceDescriptions &rResults) const;
    virtual UaStatus browseInverse(
        const UaNodeId &startingNodeId,
        const UaNodeId &referenceTypeId,
        /*out*/ UaReferenceDescriptions &rResults) const;
    virtual UaStatus readValue(
        const UaNodeId &nodeId,
        UaVariant &rValue) const;
    virtual UaStatus readValues(
        const UaNodeIdArray &nodeIds,
        UaDataValues &rValues) const;
    virtual UaStatus readDescriptionAttributes(
        const UaNodeIdArray &nodeIds,
        UaLocalizedTextArray &rValues) const;

private:
    ServerManager *m_pServerManager;
    Session *m_pSession;
};

#endif // UASERVER_UADICTIONARYREADERSERVER_H