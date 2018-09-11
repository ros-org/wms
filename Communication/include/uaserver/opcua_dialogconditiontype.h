/******************************************************************************
** opcua_dialogconditiontype.h
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
** Project: C++ OPC Server SDK information model for namespace http://opcfoundation.org/UA/
**
** Description: OPC Unified Architecture Software Development Kit.
**
******************************************************************************/

#ifndef __OPCUA_DIALOGCONDITIONTYPE_H__
#define __OPCUA_DIALOGCONDITIONTYPE_H__

#include "opcua_dialogconditiontypebase.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {


/** @brief Class implementing the UaObject interface for the DialogConditionType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Variable members of the DialogConditionType:**
 *
 *  Browse Name       | DataType      | TypeDefinition       | Modelling Rule | See Also
 *  ------------------|---------------|----------------------|----------------|-----------------------------------------------------------------------------------------------------------------------------------------------------
 *  CancelResponse    | Int32         | PropertyType         | Mandatory      | \ref DialogConditionTypeBase::getCancelResponse "getCancelResponse", \ref DialogConditionTypeBase::setCancelResponse "setCancelResponse"
 *  DefaultResponse   | Int32         | PropertyType         | Mandatory      | \ref DialogConditionTypeBase::getDefaultResponse "getDefaultResponse", \ref DialogConditionTypeBase::setDefaultResponse "setDefaultResponse"
 *  DialogState       | LocalizedText | TwoStateVariableType | Mandatory      | \ref DialogConditionTypeBase::getDialogState "getDialogState", \ref DialogConditionTypeBase::setDialogState "setDialogState"
 *  EnabledState      | LocalizedText | TwoStateVariableType | Mandatory      | \ref DialogConditionTypeBase::getEnabledState "getEnabledState", \ref DialogConditionTypeBase::setEnabledState "setEnabledState"
 *  LastResponse      | Int32         | PropertyType         | Mandatory      | \ref DialogConditionTypeBase::getLastResponse "getLastResponse", \ref DialogConditionTypeBase::setLastResponse "setLastResponse"
 *  OkResponse        | Int32         | PropertyType         | Mandatory      | \ref DialogConditionTypeBase::getOkResponse "getOkResponse", \ref DialogConditionTypeBase::setOkResponse "setOkResponse"
 *  Prompt            | LocalizedText | PropertyType         | Mandatory      | \ref DialogConditionTypeBase::getPrompt "getPrompt", \ref DialogConditionTypeBase::setPrompt "setPrompt"
 *  ResponseOptionSet | LocalizedText | PropertyType         | Mandatory      | \ref DialogConditionTypeBase::getResponseOptionSet "getResponseOptionSet", \ref DialogConditionTypeBase::setResponseOptionSet "setResponseOptionSet"
 *
 *  **Method members of the DialogConditionType:**
 *
 *  Browse Name  | Modelling Rule
 *  -------------|---------------
 *  \ref Respond | Mandatory
 *
 *  Used to represent Conditions as dialogs.
 *
 *  The DialogConditionType inherits all Properties of the ConditionType.
 *
 *  See also \ref Doc_OpcUa_DialogConditionType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT DialogConditionType:
    public DialogConditionTypeBase
{
    UA_DISABLE_COPY(DialogConditionType);
protected:
    // destruction
    virtual ~DialogConditionType();
public:
    // construction
    DialogConditionType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    DialogConditionType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    DialogConditionType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    // UaDialogConditionType method Respond
    virtual UaStatus Respond(
        const ServiceContext& serviceContext,
        OpcUa_Int32 SelectedResponse);

    static void addDialogStateLocale(const UaLocalizedText& falseName, const UaLocalizedText& trueName);

private:
    void initialize();

private:
    static bool                  s_typeNodesCreated;
    static TwoStateDisplayNames* s_pDialogStateDisplayNames;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUADIALOGCONDITIONTYPE_H__

