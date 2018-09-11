/******************************************************************************
** opcua_dialogconditiontypebase.h
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

#ifndef __OPCUA_DIALOGCONDITIONTYPEBASE_H__
#define __OPCUA_DIALOGCONDITIONTYPEBASE_H__

#include "opcua_conditiontype.h"
#include "basenodes.h"
#include "opcua_identifiers.h"
#include "opcua_propertytype.h"
#include "opcua_twostatevariabletype.h"
#include "uaargument.h"

// Namespace for the UA information model http://opcfoundation.org/UA/
namespace OpcUa {

class DialogConditionTypeBase;
class PropertyType;
class TwoStateVariableType;

/** Generated event data class for a DialogConditionType.
 *
 *  This class contains the auto generated code for the object type DialogConditionType
 *  providing UaEventData interface for the access to event data containing the current state of the
 *  condition for events sent to the client. The class is used for condition events if the condition has
 *  no nodes in the address space or for condition branches created as snapshot of the main branch.
 *
 *  **Event Fields of the DialogConditionType:**
 *
 *  Browse Name       | DataType      | TypeDefinition       | Modelling Rule | See Also
 *  ------------------|---------------|----------------------|----------------|-----------------------------------------------------
 *  CancelResponse    | Int32         | PropertyType         | Mandatory      | \ref getCancelResponse, \ref setCancelResponse
 *  DefaultResponse   | Int32         | PropertyType         | Mandatory      | \ref getDefaultResponse, \ref setDefaultResponse
 *  DialogState       | LocalizedText | TwoStateVariableType | Mandatory      | \ref getDialogState, \ref setDialogState
 *  LastResponse      | Int32         | PropertyType         | Mandatory      | \ref getLastResponse, \ref setLastResponse
 *  OkResponse        | Int32         | PropertyType         | Mandatory      | \ref getOkResponse, \ref setOkResponse
 *  Prompt            | LocalizedText | PropertyType         | Mandatory      | \ref getPrompt, \ref setPrompt
 *  ResponseOptionSet | LocalizedText | PropertyType         | Mandatory      | \ref getResponseOptionSet, \ref setResponseOptionSet

 *  Used to represent Conditions as dialogs.
 *
 *  The DialogConditionType inherits all Properties of the ConditionType.
 *
 *  See also \ref Doc_OpcUa_DialogConditionType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT DialogConditionTypeData:
    public OpcUa::ConditionTypeData
{
    UA_DISABLE_COPY(DialogConditionTypeData);
protected:
    virtual ~DialogConditionTypeData();
public:
    DialogConditionTypeData();
    void initializeAsBranch(DialogConditionTypeBase* pCondition);
    void initializeAsBranch(DialogConditionTypeData* pConditionData);
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    // CancelResponse
    void setCancelResponse(OpcUa_Int32 CancelResponse);
    void setCancelResponseStatus(OpcUa_StatusCode status);
    OpcUa_Int32 getCancelResponse();
    virtual void getCancelResponseValue(Session* pSession, OpcUa_Variant& value);
    // DefaultResponse
    void setDefaultResponse(OpcUa_Int32 DefaultResponse);
    void setDefaultResponseStatus(OpcUa_StatusCode status);
    OpcUa_Int32 getDefaultResponse();
    virtual void getDefaultResponseValue(Session* pSession, OpcUa_Variant& value);
    // DialogState
    virtual void getDialogStateValue(Session* pSession, OpcUa_Variant& value);
    void setDialogState(OpcUa_Boolean dialogState);
    void setDialogStateStatus(OpcUa_StatusCode status);
    OpcUa_Boolean getDialogState();
    virtual void getDialogState_IdValue(Session* pSession, OpcUa_Variant& value);
    void setDialogState_TransitionTime(const UaDateTime& TransitionTime);
    void setDialogState_TransitionTimeStatus(OpcUa_StatusCode status);
    UaDateTime getDialogState_TransitionTime();
    virtual void getDialogState_TransitionTimeValue(Session* pSession, OpcUa_Variant& value);
    // EnabledState already defined by base class
    // LastResponse
    void setLastResponse(OpcUa_Int32 LastResponse);
    void setLastResponseStatus(OpcUa_StatusCode status);
    OpcUa_Int32 getLastResponse();
    virtual void getLastResponseValue(Session* pSession, OpcUa_Variant& value);
    // OkResponse
    void setOkResponse(OpcUa_Int32 OkResponse);
    void setOkResponseStatus(OpcUa_StatusCode status);
    OpcUa_Int32 getOkResponse();
    virtual void getOkResponseValue(Session* pSession, OpcUa_Variant& value);
    // Prompt
    void setPrompt(const UaLocalizedText& Prompt);
    void setPromptStatus(OpcUa_StatusCode status);
    UaLocalizedText getPrompt();
    virtual void getPromptValue(Session* pSession, OpcUa_Variant& value);
    // ResponseOptionSet
    void setResponseOptionSet(const UaLocalizedTextArray& ResponseOptionSet);
    void setResponseOptionSetStatus(OpcUa_StatusCode status);
    void getResponseOptionSet(UaLocalizedTextArray& ResponseOptionSet);
    virtual void getResponseOptionSetValue(Session* pSession, OpcUa_Variant& value);


private:
    void initialize();

private:
    UaObjectPointerArray<UaVariant> m_FieldValues;
};


/** Generated base class for a DialogConditionType.
 *
 *  This class contains the auto generated code for the object type DialogConditionType
 *  representing an OPC UA condition type. This class is used to create the condition type and to
 *  create and represent the condition object in the server address space. It provides also the UaEventData
 *  interface for the access to event data containing the current state of the condition for events sent to
 *  the client.
 *
 *  **Variable members of the DialogConditionType:**
 *
 *  Browse Name       | DataType      | TypeDefinition       | Modelling Rule | See Also
 *  ------------------|---------------|----------------------|----------------|-----------------------------------------------------
 *  CancelResponse    | Int32         | PropertyType         | Mandatory      | \ref getCancelResponse, \ref setCancelResponse
 *  DefaultResponse   | Int32         | PropertyType         | Mandatory      | \ref getDefaultResponse, \ref setDefaultResponse
 *  DialogState       | LocalizedText | TwoStateVariableType | Mandatory      | \ref getDialogState, \ref setDialogState
 *  LastResponse      | Int32         | PropertyType         | Mandatory      | \ref getLastResponse, \ref setLastResponse
 *  OkResponse        | Int32         | PropertyType         | Mandatory      | \ref getOkResponse, \ref setOkResponse
 *  Prompt            | LocalizedText | PropertyType         | Mandatory      | \ref getPrompt, \ref setPrompt
 *  ResponseOptionSet | LocalizedText | PropertyType         | Mandatory      | \ref getResponseOptionSet, \ref setResponseOptionSet
 *
 *
 *  Used to represent Conditions as dialogs.
 *
 *  The DialogConditionType inherits all Properties of the ConditionType.
 *
 *  See also \ref Doc_OpcUa_DialogConditionType for a documentation of the complete Information Model.
 */
class SERVER_CORE_EXPORT DialogConditionTypeBase:
    public OpcUa::ConditionType
{
    friend class DialogConditionTypeData;
    UA_DISABLE_COPY(DialogConditionTypeBase);
protected:
    // destruction
    virtual ~DialogConditionTypeBase();
public:
    // construction
    DialogConditionTypeBase(const UaNodeId& nodeId, UaObject* pInstanceDeclarationObject, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    DialogConditionTypeBase(const UaNodeId& nodeId, const UaString& name, OpcUa_UInt16 browseNameNameSpaceIndex, NodeManagerConfig* pNodeConfig, const UaNodeId& sourceNode, const UaString& sourceName, UaMutexRefCounted* pSharedMutex = NULL);
    DialogConditionTypeBase(
        UaBase::Object*    pBaseNode,
        XmlUaNodeFactoryManager*   pFactory,
        NodeManagerConfig* pNodeConfig,
        UaMutexRefCounted* pSharedMutex = NULL);

    static void createTypes();
    static void clearStaticMembers();
    virtual UaNodeId typeDefinitionId() const;
    static void registerEventFields();
    static OpcUa_UInt32 registerOptionalEventFields(const UaString& fieldName);
    virtual void getFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);
    void clearFieldData();
    UaNodeId createBranch();


    //- Interface MethodManager -----------------------------------------------------------
    /** Call method of an UA object. */
    virtual UaStatus beginCall(
        MethodManagerCallback* pCallback,
        const ServiceContext&  serviceContext,
        OpcUa_UInt32           callbackHandle,
        MethodHandle*          pMethodHandle,
        const UaVariantArray&  inputArguments);
    virtual UaStatus call(
        const ServiceContext&  serviceContext,
        MethodHandle*          pMethodHandle,
        const UaVariantArray&  inputArguments,
        UaVariantArray&        outputArguments,
        UaStatusCodeArray&     inputArgumentResults,
        UaDiagnosticInfos&     inputArgumentDiag);
    //- Interface MethodManager -----------------------------------------------------------


    /**
     *  Respond is used to pass the selected response option and end the dialog.
     *
     *  DialogState will return to FALSE.
     *
     *  <b>Method Result Codes</b>
     *
     *  ResultCode                 | Description
     *  ---------------------------|--------------------------------------------------------------------------
     *  Bad_DialogNotActive        | The DialogConditionType instance is not in Active state.
     *  Bad_DialogResponseInvalid  | The selected option is not a valid index in the ResponseOptionSet array.
     */
    virtual UaStatus Respond(
        const ServiceContext& serviceContext /**<General context for the service calls containing
                                                 information like the session object,
                                                 return diagnostic mask and timeout hint.*/,
        OpcUa_Int32 SelectedResponse /**<[in] The response to the dialog condition.. Selected index of the ResponseOptionSet array. */) = 0;

    // CancelResponse
    virtual void setCancelResponse(OpcUa_Int32 CancelResponse);
    virtual OpcUa_Int32 getCancelResponse() const;
    virtual void setCancelResponseStatus(OpcUa_StatusCode status);
    virtual void getCancelResponseValue(Session* pSession, UaVariant& value);
    // DefaultResponse
    virtual void setDefaultResponse(OpcUa_Int32 DefaultResponse);
    virtual OpcUa_Int32 getDefaultResponse() const;
    virtual void setDefaultResponseStatus(OpcUa_StatusCode status);
    virtual void getDefaultResponseValue(Session* pSession, UaVariant& value);
    // DialogState
    virtual void setDialogState(OpcUa_Boolean dialogState);
    virtual OpcUa_Boolean getDialogStateBool();
    virtual UaLocalizedText getDialogState();
    virtual void setDialogStateStatus(OpcUa_StatusCode status);
    virtual void getDialogStateValue(Session* pSession, UaVariant& value);
    // EnabledState
    // Already defined by base class
    // LastResponse
    virtual void setLastResponse(OpcUa_Int32 LastResponse);
    virtual OpcUa_Int32 getLastResponse() const;
    virtual void setLastResponseStatus(OpcUa_StatusCode status);
    virtual void getLastResponseValue(Session* pSession, UaVariant& value);
    // OkResponse
    virtual void setOkResponse(OpcUa_Int32 OkResponse);
    virtual OpcUa_Int32 getOkResponse() const;
    virtual void setOkResponseStatus(OpcUa_StatusCode status);
    virtual void getOkResponseValue(Session* pSession, UaVariant& value);
    // Prompt
    virtual void setPrompt(const UaLocalizedText& Prompt);
    virtual UaLocalizedText getPrompt(Session* pSession) const;
    virtual void setPromptStatus(OpcUa_StatusCode status);
    virtual void getPromptValue(Session* pSession, UaVariant& value);
    // ResponseOptionSet
    virtual void setResponseOptionSet(const UaLocalizedTextArray& ResponseOptionSet);
    virtual void getResponseOptionSet(UaLocalizedTextArray& ResponseOptionSet) const ;
    virtual void setResponseOptionSetStatus(OpcUa_StatusCode status);
    virtual void getResponseOptionSetValue(Session* pSession, UaVariant& value);

    virtual OpcUa::PropertyType* getCancelResponseNode();
    virtual OpcUa::PropertyType* getDefaultResponseNode();
    virtual OpcUa::TwoStateVariableType* getDialogStateNode();
    virtual OpcUa::PropertyType* getLastResponseNode();
    virtual OpcUa::PropertyType* getOkResponseNode();
    virtual OpcUa::PropertyType* getPromptNode();
    virtual OpcUa::PropertyType* getResponseOptionSetNode();

    // NodeAccessInfo management
    virtual void useAccessInfoFromType();
    void useAccessInfoFromInstance(DialogConditionTypeBase *pInstance);

    virtual UaStatus triggerEvent(
        const UaDateTime&   time,
        const UaDateTime&   receiveTime,
        const UaByteString& eventId);

    virtual void getDialogConditionTypeOptionalFieldData(OpcUa_UInt32 index, Session* pSession, OpcUa_Variant& data);

protected:
    // Variable nodes
    // Variable CancelResponse
    static OpcUa::PropertyType*  s_pCancelResponse;
    OpcUa::PropertyType*  m_pCancelResponse;
    // Variable DefaultResponse
    static OpcUa::PropertyType*  s_pDefaultResponse;
    OpcUa::PropertyType*  m_pDefaultResponse;
    // Variable DialogState
    static OpcUa::TwoStateVariableType*  s_pDialogState;
    OpcUa::TwoStateVariableType*  m_pDialogState;
    // Variable EnabledState
    static OpcUa::TwoStateVariableType*  s_pEnabledState;
    // EnabledState defined by base type
    // Variable LastResponse
    static OpcUa::PropertyType*  s_pLastResponse;
    OpcUa::PropertyType*  m_pLastResponse;
    // Variable OkResponse
    static OpcUa::PropertyType*  s_pOkResponse;
    OpcUa::PropertyType*  m_pOkResponse;
    // Variable Prompt
    static OpcUa::PropertyType*  s_pPrompt;
    OpcUa::PropertyType*  m_pPrompt;
    // Variable ResponseOptionSet
    static OpcUa::PropertyType*  s_pResponseOptionSet;
    OpcUa::PropertyType*  m_pResponseOptionSet;


    // Method Respond
    static OpcUa::BaseMethod* s_pRespondMethod;

private:
    void initialize();
    void createChildren();

private:
    static bool                                 s_typeNodesCreated;
    static std::map<OpcUa_UInt32, OpcUa_UInt32> s_DialogConditionTypeDataFields;
    UaObjectPointerArray<UaVariant>             m_FieldValues;
};

} // End namespace for the UA information model http://opcfoundation.org/UA/

#endif // #ifndef __OPCUADIALOGCONDITIONTYPEBASE_H__

