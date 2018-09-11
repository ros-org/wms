/******************************************************************************
** opcuadi_functionalgrouptype.h
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
** Project: C++ OPC Server SDK information model for namespace http://opcfoundation.org/UA/DI/
**
** Description: OPC Unified Architecture Software Development Kit.
**
******************************************************************************/

#ifndef __OPCUADI_FUNCTIONALGROUPTYPE_H__
#define __OPCUADI_FUNCTIONALGROUPTYPE_H__

#include "opcuadi_functionalgrouptypebase.h"

// Namespace for the UA information model http://opcfoundation.org/UA/DI/
namespace OpcUaDi {


/** @brief Class implementing the UaObject interface for the FunctionalGroupType.
 *
 * OPC UA Objects are used to represent systems, system components, real-world objects and software
 * objects. They have the NodeClass @ref L3UaNodeClassObject. The detailed description of Objects and their attributes
 * can be found in the general description of the @ref L3UaNodeClassObject node class.
 *
 *  **Object members of the FunctionalGroupType:**
 *
 *  Browse Name         | TypeDefinition      | Modelling Rule      | See Also
 *  --------------------|---------------------|---------------------|---------
 *  \<GroupIdentifier\> | FunctionalGroupType | OptionalPlaceholder | &nbsp;
 *
 *  **Variable members of the FunctionalGroupType:**
 *
 *  Browse Name             | DataType     | TypeDefinition       | Modelling Rule      | See Also
 *  ------------------------|--------------|----------------------|---------------------|---------------------------------------------------------------------------------------------------------------------
 *  \<ParameterIdentifier\> | BaseDataType | BaseDataVariableType | OptionalPlaceholder | &nbsp;
 *  UIElement               | BaseDataType | UIElementType        | Optional            | \ref FunctionalGroupTypeBase::getUIElement "getUIElement", \ref FunctionalGroupTypeBase::setUIElement "setUIElement"
 *
 *  **Method members of the FunctionalGroupType:**
 *
 *  Browse Name          | Modelling Rule
 *  ---------------------|--------------------
 *  \<MethodIdentifier\> | OptionalPlaceholder
 *
 */
class UAMODELS_EXPORT FunctionalGroupType:
    public FunctionalGroupTypeBase
{
    UA_DISABLE_COPY(FunctionalGroupType);
protected:
    // destruction
    virtual ~FunctionalGroupType();
public:
    // construction
    FunctionalGroupType(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    FunctionalGroupType(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    FunctionalGroupType(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();


protected:

private:
};

} // End namespace for the UA information model http://opcfoundation.org/UA/DI/

#endif // #ifndef __OPCUADIFUNCTIONALGROUPTYPE_H__

