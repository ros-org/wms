/******************************************************************************
** continuationpoint.h
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
** Project: C++ OPC Server SDK core module
**
** Description: OPC server core continuation point handling class.
**
******************************************************************************/
#ifndef CONTINUATIONPOINT_H
#define CONTINUATIONPOINT_H

#include "uabase.h"
#include "opcuatypes.h"
#include "historymanager.h"

/** Base class for continuation point user data.
 *
 *  This is the base class for handling of user data stored in a continuation point.
 *  It is not possible to create shallow copies of this class.
 */
class SERVER_CORE_EXPORT ContinuationPointUserDataBase
{
    UA_DISABLE_COPY(ContinuationPointUserDataBase);
public:
    /** construction */
    ContinuationPointUserDataBase(){}
    /** destruction */
    virtual ~ContinuationPointUserDataBase(){}
};

/** Base class for History Read continuation point user data.
 *
 *  This is the base class for handling of user data stored in a History Read continuation point.
 *  It is not possible to create shallow copies of this class.
 */
class SERVER_CORE_EXPORT HistoryReadCPUserDataBase
{
    UA_DISABLE_COPY(HistoryReadCPUserDataBase);
    HistoryReadCPUserDataBase(){}
public:
    HistoryReadCPUserDataBase(
        const UaNodeId& affectedNode,
        HistoryManager::TransactionType historyTransactionType);
    virtual ~HistoryReadCPUserDataBase();

    /** Returns the NodeId for the node the continuation point was created for. */
    inline UaNodeId affectedNode() const {return m_affectedNode;}
    /** Returns the TransactionType the continuation point was created for. */
    inline HistoryManager::TransactionType historyTransactionType() const {return m_historyTransactionType;}

    // SDK internal use
    inline OpcUa_UInt16 cpCounter() const {return m_CPCounter;}
    inline void setCPCounter(OpcUa_UInt16 CPCounter){m_CPCounter = CPCounter;}
private:
    OpcUa_UInt16                     m_CPCounter;
    UaNodeId                         m_affectedNode;
    HistoryManager::TransactionType  m_historyTransactionType;
};

class SERVER_CORE_EXPORT BrowseCallback
{
public:
    BrowseCallback(){}
    virtual ~BrowseCallback(){}
};

/** This class provides all browse settings and the continuation point handling.

 The class provides all settings for a browse call, like node to browse and
 the browse filter settings. It also keeps the settings and the continuation
 point user data if not all results can be returned in a single browse
 result. The same object is provided in a second browse call triggered through
 a BrowseNext service call. In this case, the continuation point is provided in
 addition to the browse settings.

 If the number of browse results exeeds the #uMaxResultsToReturn or a server internal limit, a continuation point is necessary and
 #setUserData is used to store the implementation specific continuation point user data.

 The following code provides an example for the functions #setUserData and #uMaxResultsToReturn

 @code
    // Check whether we need to create a continuation point and stop browsing
    if ( browseCount >= browseContext.uMaxResultsToReturn() )
    {
        // Create continuation point object for browse context
        CPNodeManagerTree* pCP = new CPNodeManagerTree;
        // Set continuation point data for next browse
        pCP->m_nextChild = i+1;
        // Assign continuation point to browse context
        browseContext.setUserData(pCP);
        break;
    }
 @endcode

 The following code provides an example for a continuation point user data class

 @code
 class CPNodeManagerTree : public ContinuationPointUserDataBase
 {
    UA_DISABLE_COPY(CPNodeManagerTree);
 public:
    CPNodeManagerTree() : m_nextChild(0){}
    virtual ~CPNodeManagerTree(){}

    OpcUa_UInt32 m_nextChild;
 };
 @endcode

 #isFirstBrowse is used to check whether it is a first browse or a browse next.

 #detachUserData is used to get the stored continuation point data.

 The following code provides an example for the functions #isFirstBrowse and #detachUserData

 @code
     // Check whether we have a continuation point from OPC UA browse
    if ( browseContext.isFirstBrowse() == OpcUa_False )
    {
        CPNodeManagerTree* pCP = (CPNodeManagerTree*)browseContext.detachUserData();
        if ( pCP )
        {
            startingChild = pCP->m_nextChild;
            delete pCP;
        }
    }
 @endcode

 The SDK handles the release of continuation point data if BrowseNext is not called or just called to release the continuation point.
*/
class SERVER_CORE_EXPORT BrowseContext
{
    UA_DISABLE_COPY(BrowseContext);
    BrowseContext();
public:
    BrowseContext(
        OpcUa_ViewDescription*  pView,
        OpcUa_NodeId*           pNodeToBrowse,
        OpcUa_UInt32            uMaxResultsToReturn,
        OpcUa_BrowseDirection   BrowseDirection,
        OpcUa_NodeId*           pReferenceTypeId,
        OpcUa_Boolean           bIncludeSubtype,
        OpcUa_UInt32            uNodeClassMask,
        OpcUa_UInt32            uResultMask);
    virtual ~BrowseContext();

    // Set and get user data for continuation point handling
    void setUserData( ContinuationPointUserDataBase* pContinuationPointUserDataBase );
    ContinuationPointUserDataBase* detachUserData();
    OpcUa_Boolean isUserDataSet();

    /** Returns the OPC UA View context for the browse. If the view is not set, the whole address space is browsed.
     */
    inline OpcUa_ViewDescription* pView() const {return m_pView;}

    /** Returns the node id of the node to browse.
     */
    inline OpcUa_NodeId*          pNodeToBrowse() const {return m_pNodeToBrowse;}

    /** Returns the maximum number of browse results to return. If the maximum is exceeded, a continuation point needs to be created.
    * @see setUserData
     */
    inline OpcUa_UInt32           uMaxResultsToReturn() const {return m_uMaxResultsToReturn;}

    /** Allows setting of the maximum number of results to return.
     */
    inline void                   setMaxResultsToReturn(OpcUa_UInt32 uMaxResultsToReturn) {m_uMaxResultsToReturn = uMaxResultsToReturn;}

    /** Returns the browse direction for the browse call.
    *
    * Options are:
    * - OpcUa_BrowseDirection_Forward
    * - OpcUa_BrowseDirection_Inverse
    * - OpcUa_BrowseDirection_Both
    */
    inline OpcUa_BrowseDirection  BrowseDirection() const {return m_BrowseDirection;}

    /** Returns the node id of the requested reference type or its subtypes if bIncludeSubtype is set.
    * @see bIncludeSubtype
    */
    inline OpcUa_NodeId*          pReferenceTypeId() const {return m_pReferenceTypeId;}

    /** Returns the flag indicating whether subtypes of the requested reference type should be included in the browse result.
    * @see pReferenceTypeId
     */
    inline OpcUa_Boolean          bIncludeSubtype() const {return m_bIncludeSubtype;}

    /** Returns the node class filter mask identifying the node classes to include in the browse result.
    *
    * Bit mask containing the following options:
    * Define                        | Value
    * ------------------------------|------
    * OpcUa_NodeClass_Object        | 1
    * OpcUa_NodeClass_Variable      | 2
    * OpcUa_NodeClass_Method        | 4
    * OpcUa_NodeClass_ObjectType    | 8
    * OpcUa_NodeClass_VariableType  | 16
    * OpcUa_NodeClass_ReferenceType | 32
    * OpcUa_NodeClass_DataType      | 64
    * OpcUa_NodeClass_View          | 128
    *
    * If set to zero, all node classes are returned.
    */
    inline OpcUa_UInt32           uNodeClassMask() const {return m_uNodeClassMask;}

    /** Returns the result filter mask identifing the information returned for each node in the browse result.
    *
    * Bit mask containing the following options:
    * Define                                   | Value
    * -----------------------------------------|------
    * OpcUa_BrowseResultMask_None              | 0
    * OpcUa_BrowseResultMask_ReferenceTypeId   | 1
    * OpcUa_BrowseResultMask_IsForward         | 2
    * OpcUa_BrowseResultMask_NodeClass         | 4
    * OpcUa_BrowseResultMask_BrowseName        | 8
    * OpcUa_BrowseResultMask_DisplayName       | 16
    * OpcUa_BrowseResultMask_TypeDefinition    | 32
    */
    inline OpcUa_UInt32           uResultMask() const {return m_uResultMask;}

    /** Allows setting of the result mask.
     */
    inline void setResultMask(OpcUa_UInt32 uResultMask){m_uResultMask = uResultMask;}

    /** Can be used to check whether it is the first browse with this context
     *
     *  In the case of OpcUa_True, it is the first browse call with this browse context.
     *  In the case of OpcUa_False, it is a browse next call with a continuation point.
     *  @return a Boolean value to check whether this was the first browse with the current context.
     */
    inline OpcUa_Boolean isFirstBrowse() const {return m_isFirstBrowse;}

    /** Flag that tells the SDK whether it was the last browse call and all references are returned.
     *
     *  The flag is set by #setUserData (OpcUa_False) since this indicates that a
     *  continuation point is necessary, or by #detachUserData (OpcUa_True) since the continuation
     *  point is handled in a next browse. The default value is OpcUa_True.
     *  @return a value used to recognize whether this was the last browse call or not.
     */
    inline OpcUa_Boolean isLastBrowse() const {return m_isLastBrowse;}

    /** Returns the total number of nodes to browse in the Browse service
     *
     * This BrowseContext represents only one of the nodes to browse in the Browse request.
     * This information can be used together with the nodeToBrowseIndex() and the receiveTime
     * and timeoutHint in the ServiceContext to decide whether the current node can still be processed
     * or the browse for the node should be skipped and BadNoContinuationPoints returned for
     * the remaining nodes. It would also be possible to return continuation points and an empty result list
     * for the remaining nodes if the number is below the number of continuation points supported
     * per session.
     */
    inline OpcUa_UInt32 nodeToBrowseCount() const {return m_nodeToBrowseCount;}

    /** Returns the index of this node in the nodes to browse array in the Browse service call
     *
     * This BrowseContext represents only one of the nodes to browse in the Browse request.
     * This information can be used together with the nodeToBrowseCount() and the receiveTime
     * and timeoutHint in the ServiceContext to decide whether the current node can still be processed
     * or the browse for the node should be skipped and BadNoContinuationPoints returned for
     * the remaining nodes. It would also be possible to return continuation points and an empty result list
     * for the remaining nodes if the number is below the number of continuation points supported
     * per session.
     */
    inline OpcUa_UInt32 nodeToBrowseIndex() const {return m_nodeToBrowseIndex;}

    // SDK internal use
    inline OpcUa_Byte            CPCounter() const {return m_CPCounter;}
    inline void                  setCPCounter(OpcUa_Byte CPCounter){m_CPCounter = CPCounter;}
    inline bool isRootProcessed() const {return m_isRootProcessed;};
    void setIsRootProcessed();
    void setBrowseRequestInformation(OpcUa_UInt32 nodeToBrowseCount, OpcUa_UInt32 nodeToBrowseIndex);
    void setBrowseCallback(BrowseCallback* pBrowseCallback) {m_pBrowseCallback = pBrowseCallback;}
    inline BrowseCallback* pBrowseCallback() const {return m_pBrowseCallback;}

    bool isTypeDefinitionProcessed() { return m_bTypeDefinitionProcessed; }
    void setTypeDefinitionProcessed() { m_bTypeDefinitionProcessed = true; }
    bool isModellingRuleProcessed() { return m_bModellingRuleProcessed; }
    void setModellingRuleProcessed() { m_bModellingRuleProcessed = true; }

private:
    /** Browse data */
    OpcUa_ViewDescription* m_pView;
    OpcUa_NodeId*          m_pNodeToBrowse;
    OpcUa_UInt32           m_uMaxResultsToReturn;
    OpcUa_BrowseDirection  m_BrowseDirection;
    OpcUa_NodeId*          m_pReferenceTypeId;
    OpcUa_Boolean          m_bIncludeSubtype;
    OpcUa_UInt32           m_uNodeClassMask;
    OpcUa_UInt32           m_uResultMask;

    /** Internal data */
    OpcUa_Boolean                  m_isFirstBrowse;
    ContinuationPointUserDataBase* m_pContinuationPointUserDataBase;
    OpcUa_Boolean                  m_isLastBrowse;
    OpcUa_Byte                     m_CPCounter;
    BrowseCallback*                m_pBrowseCallback;
    bool                           m_isRootProcessed;
    OpcUa_UInt32                   m_nodeToBrowseCount;
    OpcUa_UInt32                   m_nodeToBrowseIndex;
    bool                           m_bTypeDefinitionProcessed;
    bool                           m_bModellingRuleProcessed;
};

/** This class provides all query settings and the continuation point handling.

 The class provides all settings for a query call, like node types and filter settings. It also keeps the settings and the continuation
 point if not all results can be returned in a single query result. The same object is provided in a second query call triggered through a QueryNext
 service call. In this case, the continuation point is provided in addition to the query settings.

 If the number of query results exeeds the #uMaxDataSetsToReturn, #uMaxReferencesToReturn or a server internal limit, a continuation
 point is necessary and #setUserData is used to store the implementation specific continuation point user data.
 You must derive your data handling class from ContinuationPointUserDataBase.

 #isFirstQuery is used to check if it is a first query or a query next.

 #detachUserData is used to get the stored continuation point data.

 The SDK handles the release of continuation point data if QueryNext is not called or just called to release the continuation point.
*/
class SERVER_CORE_EXPORT QueryContext
{
    UA_DISABLE_COPY(QueryContext);
    QueryContext();
public:
    QueryContext(
        OpcUa_ViewDescription*     pView,
        OpcUa_Int32                noOfNodeTypes,
        OpcUa_NodeTypeDescription* pNodeTypes,
        OpcUa_ContentFilter*       pFilter,
        OpcUa_UInt32               uMaxDataSetsToReturn,
        OpcUa_UInt32               uMaxReferencesToReturn);
    virtual ~QueryContext();

    /** Returns the OPC UA View context for the query. If the view is not set, the whole address space is queried.
     */
    inline OpcUa_ViewDescription* pView() const {return (OpcUa_ViewDescription*)&m_view;}

    /** Returns the number of NodeType entries.
    * @see setUserData
     */
    inline OpcUa_Int32           noOfNodeTypes() const {return m_noOfNodeTypes;}

    /** Returns the list of NodeTypes.
     */
    inline OpcUa_NodeTypeDescription* pNodeTypes() const {return m_pNodeTypes;}

    /** Returns the filter for the query results.
     */
    inline OpcUa_ContentFilter*   pFilter() const {return (OpcUa_ContentFilter*)&m_filter;}

    /** Returns the maximum number of data sets to return. If the maximum is exceeded, a continuation point needs to be created.
    * @see setUserData
     */
    inline OpcUa_UInt32           uMaxDataSetsToReturn() const {return m_uMaxDataSetsToReturn;}

    /** Returns the maximum number of references to return. If the maximum is exceeded, a continuation point needs to be created.
    * @see setUserData
     */
    inline OpcUa_UInt32           uMaxReferencesToReturn() const {return m_uMaxReferencesToReturn;}

    /** Can be used to check whether it is the first query with this context.
     *
     *  In the case of OpcUa_True, it is the first query call with this query context.
     *  In the case of OpcUa_False, it is a query next call with a continuation point.
     *  @return a Boolean value to check whether this was the first query with the current context.
     */
    inline OpcUa_Boolean          isFirstQuery() const {return m_isFirstQuery;}

    // Set user data if not all nodes can be returned to prepare Continuation Point for next query.
    void setUserData( ContinuationPointUserDataBase* pContinuationPointUserDataBase );

    // Detach user data to continue query.
    ContinuationPointUserDataBase* detachUserData();

    inline OpcUa_Byte            CPCounter() const {return m_CPCounter;}
    inline void                  setCPCounter(OpcUa_Byte CPCounter){m_CPCounter = CPCounter;}

    /** Flag telling the SDK whether it was the last query call and all references are returned.
     *
     *  The flag is set by the method #setUserData (OpcUa_False) since this indicates that a
     *  continuation point is necessary, or by #detachUserData (OpcUa_True) since the continuation
     *  point is handled in a next query. The default value is OpcUa_True.
     *  @return a value used to recognize whether this was the last query call or not.
     */
    inline OpcUa_Boolean isLastQuery() const {return m_isLastQuery;}

private:
    /** Browse data */
    OpcUa_ViewDescription      m_view;
    OpcUa_Int32                m_noOfNodeTypes;
    OpcUa_NodeTypeDescription* m_pNodeTypes;
    OpcUa_ContentFilter        m_filter;
    OpcUa_UInt32               m_uMaxDataSetsToReturn;
    OpcUa_UInt32               m_uMaxReferencesToReturn;

    /** Internal data */
    OpcUa_Boolean                  m_isFirstQuery;
    ContinuationPointUserDataBase* m_pContinuationPointUserDataBase;
    OpcUa_Boolean                  m_isLastQuery;
    OpcUa_Byte                     m_CPCounter;
};


/** Continuation point wrapper class for internal browse calls.
 */
class SERVER_CORE_EXPORT ContinuationPointWrapper
{
    UA_DISABLE_COPY(ContinuationPointWrapper);
public:
    ContinuationPointWrapper();
    virtual ~ContinuationPointWrapper();

    // Internal method used to set and get the browse context if a continuation point is needed
    void setBrowseContext(BrowseContext* pBrowseContext);
    BrowseContext* pBrowseContext();

    // Check if there are more results and the continuation point can be used to get more results
    OpcUa_Boolean isContinuationPointSet();

private:
    BrowseContext* m_pBrowseContext;
};

#endif // CONTINUATIONPOINT_H

