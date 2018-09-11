/******************************************************************************
** uanetworkbrowser.h
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
** Platform independent network browser handling class.
**
******************************************************************************/
#ifndef UANETWORKBROWSER_H
#define UANETWORKBROWSER_H

#include "opcua_proxystub.h"
#include "uastring.h"
#include "uaarraytemplates.h"
#include "statuscode.h"

class UaNetworkBrowserPrivate;

/** @ingroup CppBaseLibraryClass
Browse result class for navigating through the network.
 */
class UABASE_EXPORT UaNetworkBrowseResult
{
    UA_DISABLE_COPY(UaNetworkBrowseResult);
public:
    /** NetworkNodeType enumeration  */
    enum NetworkNodeType
    {
        NODE_TYPE_NETWORK, /*!< A network node */
        NODE_TYPE_DOMAIN,  /*!< A domain node */
        NODE_TYPE_HOST,    /*!< A host node */
        NODE_TYPE_INVALID  /*!< An invalid node */
    };

    UaNetworkBrowseResult()
    {
        nodeType = NODE_TYPE_INVALID;
    }
    ~UaNetworkBrowseResult(){}

    /** Network node name  */
    UaString        sNodeName;
    /** Network node type  */
    NetworkNodeType nodeType;
};

typedef UaObjectPointerArray<UaNetworkBrowseResult> UaNetworkBrowseResults;


/** @ingroup CppBaseLibraryClass
Platform independent class for navigating through the network.
 */
class UABASE_EXPORT UaNetworkBrowser
{
    UA_DISABLE_COPY(UaNetworkBrowser);
public:
    /** Constructs a network browser object. */
    UaNetworkBrowser();

    /** Destroys the network browser object */
    ~UaNetworkBrowser();

    /** Operating system independent browse method used to navigate through the network nodes. The hirarchy and the number of nodes returned depends
     on the operating system capabilities and the network setup.
    */
    UaStatus browse(
        const UaString&         startingNode,   //!< [in] Starting node for the network browsing. This is the node name returned from a previous browse call or an empty string for root.
        UaNetworkBrowseResults& browseResults  //!< [out] Returns a list of browse results containing the result data in a list of UaNetworkBrowseResult objects.
        );

private:
    UaNetworkBrowserPrivate* d;
};

#endif // UANETWORKBROWSER_H

