/******************************************************************************
** opcuaplc_datatypes.h
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
** Project: C++ OPC Server SDK information model for namespace http://PLCopen.org/OpcUa/IEC61131-3/
**
** Description: OPC Unified Architecture Software Development Kit.
**
******************************************************************************/

#ifndef __OPCUAPLC_DATATYPES_H__
#define __OPCUAPLC_DATATYPES_H__

#include <opcua_proxystub.h>
#include <opcua_builtintypes.h>
#include <opcua_exclusions.h>
#include <opcua_types.h>

#include "opcuaplc_identifiers.h"

#define OPCUAPLC_EXTENSIONOBJECT_GET_ENCODEABLE(xExpectedType, xExtensionObject) \
    (OpcUaPlc_##xExpectedType*)((((xExtensionObject)->Encoding == OpcUa_ExtensionObjectEncoding_EncodeableObject && \
    (xExtensionObject)->Body.EncodeableObject.Type != OpcUa_Null && \
    (xExtensionObject)->Body.EncodeableObject.Type->TypeId == OpcUaPlcId_##xExpectedType && \
    OpcUa_StrCmpA((xExtensionObject)->Body.EncodeableObject.Type->NamespaceUri, "http://PLCopen.org/OpcUa/IEC61131-3/") == 0 && \
    (xExtensionObject)->Body.EncodeableObject.Object != OpcUa_Null))?((xExtensionObject)->Body.EncodeableObject.Object):OpcUa_Null)


// Namespace for the UA information model http://PLCopen.org/OpcUa/IEC61131-3/
namespace OpcUaPlc {

}


/*============================================================================
 * Register known types.
 *===========================================================================*/
namespace OpcUaPlc
{
    /** Class used to handle data type registration
    */
    class DataTypes
    {
    public:
        static void registerStructuredTypes();
    private:
        static bool s_dataTypesAdded;
    };
}

#endif // __OPCUAPLC_DATATYPES_H__

