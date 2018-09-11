/******************************************************************************
** opcuadi_functionalgrouptypebase.h
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

#ifndef __OPCUADI_FUNCTIONALGROUPTYPEBASE_H__
#define __OPCUADI_FUNCTIONALGROUPTYPEBASE_H__

#include "opcua_foldertype.h"
#include "opcuadi_datatypes.h"
#include "basenodes.h"
#include "opcua_basedatavariabletype.h"
#include "opcuadi_identifiers.h"
#include "opcuadi_instancefactory_devices.h"

// Namespace for the UA information model http://opcfoundation.org/UA/DI/
namespace OpcUaDi {

class FunctionalGroupType;
class UIElementType;

/** Generated base class for a FunctionalGroupType.
 *
 *  This class contains the generated base code for the object type FunctionalGroupType
 *  representing an OPC UA ObjectType. This class is used to create the object type and to
 *  create and represent instances of the object type in the server address space.
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
 *  ------------------------|--------------|----------------------|---------------------|-------------------------------------
 *  \<ParameterIdentifier\> | BaseDataType | BaseDataVariableType | OptionalPlaceholder | &nbsp;
 *  UIElement               | BaseDataType | UIElementType        | Optional            | \ref getUIElement, \ref setUIElement
 *
 */
class UAMODELS_EXPORT FunctionalGroupTypeBase:
    public OpcUa::FolderType
{
    UA_DISABLE_COPY(FunctionalGroupTypeBase);
protected:
    virtual ~FunctionalGroupTypeBase();
public:
    // construction / destruction
    FunctionalGroupTypeBase(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    FunctionalGroupTypeBase(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, UaMutexRefCounted* pSharedMutex = NULL);
    FunctionalGroupTypeBase(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;



    virtual void setUIElement(const UaVariant&UIElement);
    virtual UaVariant getUIElement() const;

    virtual OpcUaDi::UIElementType* getUIElementNode();

// Add placeholders
    virtual UaStatus addGroup(OpcUaDi::FunctionalGroupType *pGroup);
    virtual UaStatus addParameter(OpcUa::BaseDataVariableType *pParameter);
    virtual UaStatus addMethod(OpcUa::BaseMethod *pMethod);

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(FunctionalGroupTypeBase *pInstance);

protected:
    // Object nodes
    // Object GroupIdentifier
    static OpcUaDi::FunctionalGroupType*  s_pGroupIdentifier;

    // Variable nodes
    // Variable ParameterIdentifier
    static OpcUa::BaseDataVariableType*  s_pParameterIdentifier;
    // ParameterIdentifier defined by base type
    // Variable UIElement
    static OpcUaDi::UIElementType*  s_pUIElement;
    OpcUaDi::UIElementType*  m_pUIElement;


    // Method nodes
    static OpcUa::BaseMethod* s_pMethodIdentifierMethod;


private:
    void initialize();

private:
    static bool s_typeNodesCreated;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/DI/

#endif // #ifndef __OPCUADIFUNCTIONALGROUPTYPEBASE_H__


