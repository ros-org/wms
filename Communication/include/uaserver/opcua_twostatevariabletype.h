/******************************************************************************
** opcua_twostatevariabletype.h
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

#ifndef __OPCUA_TWOSTATEVARIABLETYPE_H__
#define __OPCUA_TWOSTATEVARIABLETYPE_H__

#include "opcua_statevariabletype.h"
#include "opcua_identifiers.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class PropertyType;
// Addition to generated code begin
class TwoStateDisplayNames;
// Addition to generated code end

/** Implements OPC UA Variables of the type TwoStateVariableType
 *
 *  **Variable members of the TwoStateVariableType:**
 *
 *  Browse Name             | DataType      | TypeDefinition | Modelling Rule | See Also
 *  ------------------------|---------------|----------------|----------------|-----------------------------------------------------------------
 *  EffectiveTransitionTime | UtcTime       | PropertyType   | Optional       | \ref getEffectiveTransitionTime, \ref setEffectiveTransitionTime
 *  FalseState              | LocalizedText | PropertyType   | Optional       | \ref getFalseState, \ref setFalseState
 *  TransitionTime          | UtcTime       | PropertyType   | Optional       | \ref getTransitionTime, \ref setTransitionTime
 *  TrueState               | LocalizedText | PropertyType   | Optional       | \ref getTrueState, \ref setTrueState
 *
 *  Most states defined in the OPC UA Specification are simple – i.e. they are
 *  either TRUE or FALSE. The TwoStateVariableType is introduced specifically for
 *  this use case. More complex states are modelled by using a StateMachineType.
 *  The TwoStateVariableType is derived from the StateVariableType. The Value
 *  Attribute of a TwoStateVariable contains the current state as a human readable
 *  name. The EnabledState for example, might contain the name “Enabled” when TRUE
 *  and “Disabled” when FALSE.
 *
 *  The optional Property EffectiveDisplayName from the StateVariableType is used
 *  if a state has substates. It contains a human readable name for the current
 *  state after taking the state of any SubStateMachines in account. As an example,
 *  the EffectiveDisplayName of the EnabledState could contain “Active/HighHigh” to
 *  specify that the Condition is active and has exceeded the HighHigh limit.
 *
 *  A HasTrueSubState Reference is used to indicate that the TRUE state has
 *  substates.
 *
 *  A HasFalseSubState Reference is used to indicate that the FALSE state has
 *  substates.
 *
 *  See also \ref Doc_OpcUa_TwoStateVariableType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT TwoStateVariableType:
    public OpcUa::StateVariableType
{
    UA_DISABLE_COPY(TwoStateVariableType);
protected:
    virtual ~TwoStateVariableType();
public:
    TwoStateVariableType(
        UaNode*            pParentNode,
        UaVariable*        pInstanceDeclarationVariable,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    TwoStateVariableType(
        const UaNodeId&    nodeId,
        const UaString&    name,
        OpcUa_UInt16       browseNameNameSpaceIndex,
        const UaVariant&   initialValue,
        OpcUa_Byte         accessLevel,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);
    TwoStateVariableType(
        UaBase::Variable*  pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    static void createTypes();
    static void clearStaticMembers();

    virtual UaNodeId       typeDefinitionId() const;

    virtual void setEffectiveTransitionTime(const UaDateTime& EffectiveTransitionTime);
    virtual UaDateTime getEffectiveTransitionTime() const;

    virtual void setFalseState(const UaLocalizedText& FalseState);
    virtual UaLocalizedText getFalseState(Session* pSession) const;

    virtual void setId(const UaVariant&Id);
    virtual UaVariant getId() const;
    virtual void setIdBoolean(OpcUa_Boolean Id);
    virtual OpcUa_Boolean getIdBoolean() const;
    // Id defined by base type

    virtual void setTransitionTime(const UaDateTime& TransitionTime);
    virtual UaDateTime getTransitionTime() const;

    virtual void setTrueState(const UaLocalizedText& TrueState);
    virtual UaLocalizedText getTrueState(Session* pSession) const;

    virtual OpcUa::PropertyType* getEffectiveTransitionTimeNode();
    virtual OpcUa::PropertyType* getFalseStateNode();
    virtual OpcUa::PropertyType* getIdNode();
    virtual OpcUa::PropertyType* getTransitionTimeNode();
    virtual OpcUa::PropertyType* getTrueStateNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(TwoStateVariableType *pInstance);

// Addition to generated code begin
    void setTwoStateDisplayNames(TwoStateDisplayNames* m_pTwoStateDisplayNames);
    void setState(OpcUa_Boolean state);
    OpcUa_Boolean getState();

    // Overwrites the value getter of the base class
    UaDataValue value(Session* pSession);

    UaLocalizedText getStateName(Session* pSession);
    UaLocalizedText getStateName(Session* pSession, OpcUa_Boolean state);
// Addition to generated code end

protected:
    // Variable nodes
    // Variable EffectiveTransitionTime
    static OpcUa::PropertyType*  s_pEffectiveTransitionTime;
    OpcUa::PropertyType*  m_pEffectiveTransitionTime;
    // Variable FalseState
    static OpcUa::PropertyType*  s_pFalseState;
    OpcUa::PropertyType*  m_pFalseState;
    // Variable Id
    static OpcUa::PropertyType*  s_pId;
    // Id defined by base type
    // Variable TransitionTime
    static OpcUa::PropertyType*  s_pTransitionTime;
    OpcUa::PropertyType*  m_pTransitionTime;
    // Variable TrueState
    static OpcUa::PropertyType*  s_pTrueState;
    OpcUa::PropertyType*  m_pTrueState;


private:
    void initialize(NodeManagerConfig* pNodeConfig);

private:
    static bool s_typeNodesCreated;
// Addition to generated code begin
    TwoStateDisplayNames* m_pTwoStateDisplayNames;
// Addition to generated code end
};

// Addition to generated code begin
/** @brief Contains the display names for the two states of a wo state statemachine
*/
class SERVER_CORE_EXPORT TwoStateDisplayNames:
    public ReferenceCounter
{
    UA_DISABLE_COPY(TwoStateDisplayNames);
    ~TwoStateDisplayNames();
public:

    // construction / destruction
    TwoStateDisplayNames(const UaLocalizedText& falseName, const UaLocalizedText& trueName);

    void addLocale(const UaLocalizedText& falseName, const UaLocalizedText& trueName);

    UaLocalizedText getFalseName(Session* pSession) const;
    UaLocalizedText getTrueName(Session* pSession) const;

private:
    UaLocalizedTextArray m_falseNames;
    UaLocalizedTextArray m_trueNames;
// Addition to generated code end
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUA_TWOSTATEVARIABLETYPE_H__

