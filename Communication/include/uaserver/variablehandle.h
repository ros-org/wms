/******************************************************************************
** variablehandle.h
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
** Description: OPC server core module variable handle class.
**
******************************************************************************/
#ifndef VARIABLEHANDLE_H
#define VARIABLEHANDLE_H

#include "opcuatypes.h"
#include "referencecounter.h"
#include "uaarraytemplates.h"

class SERVER_CORE_EXPORT IOManager;
class SERVER_CORE_EXPORT HistoryManager;

/** @ingroup ServerCoreInterfaces
  Base class for the variable handle used in data access methods.
  The content of this class is used by the server SDK to multiplex access to node attributes to <b>1 to N</b> IOManagers per
  NodeManager. Therefore this class contains the interface pointer of the responsible IOManager for the node and the
  attribute id. NodeManagers can use derived classes to add more information for the responsible IOManager.
  The class is derived from ReferenceCounter to control the life time of the object through reference counting.
 */
class SERVER_CORE_EXPORT VariableHandle: public ReferenceCounter
{
    UA_DISABLE_COPY(VariableHandle);
public:
    /** This enumeration indicates the type of action this variable handle is used for.
      If Register is set the variable handle is only created for optimizing later service calls and this Variable Handle
      may be used in all possible other actions like reading data, writing data and monitoring of data changes.
    */
    enum ServiceType
    {
        ServiceRead,        /*!< Service Read */
        ServiceWrite,       /*!< Service Write */
        ServiceMonitoring,  /*!< Service CreateMonitoredItems */
        ServiceRegister     /*!< Service RegisterNodes */
    };

    /** construction */
    VariableHandle();

    /// @brief Interface pointer of the responsible IOManager for the node.
    IOManager*    m_pIOManager;
    /// @brief Requested attribute for the action.
    OpcUa_Int32   m_AttributeID;

protected:
    /** destruction */
    virtual ~VariableHandle();
};

/** A pointer array of VariableHandles. */
typedef UaPointerArray<VariableHandle> PVariableHandleArray;

/** HistoryVariableHandle
 *  @brief Base class for the History Variable Handle used in history access methods.
 *  Derived from ReferenceCounter.
 *  It is not possible to create shallow copies of this Class.
 */
class SERVER_CORE_EXPORT HistoryVariableHandle: public ReferenceCounter
{
    UA_DISABLE_COPY(HistoryVariableHandle);
public:
    /** Enumeration  for the different history service options */
    enum ServiceType
    {
        ServiceReadEvents,    /*!< Service HistoryRead with ReadEventDetails for read events */
        ServiceReadRaw,       /*!< Service HistoryRead with ReadRawModifiedDetails for read raw data */
        ServiceReadModified,  /*!< Service HistoryRead with ReadRawModifiedDetails for read modified data */
        ServiceReadProcessed, /*!< Service HistoryRead with ReadProcessedDetails for read processed data */
        ServiceReadAtTime,    /*!< Service HistoryRead with ReadAtTimeDetails for read data at a list of timestamps */
        ServiceUpdateData,    /*!< Service HistoryUpdate with UpdateDataDetails for update of data */
        ServiceUpdateStructureData, /*!< Service HistoryUpdate with UpdateStructureDataDetails for update of structure data like Anotations */
        ServiceUpdateEvent,   /*!< Service HistoryUpdate with UpdateEventDetails for update of events */
        ServiceDeleteRaw,     /*!< Service HistoryUpdate with DeleteRawModifiedDetails for deletion of raw or modified data */
        ServiceDeleteAtTime,  /*!< Service HistoryUpdate with DeleteAtTimeDetails for deletion of data at a list of timestamps */
        ServiceDeleteEvent    /*!< Service HistoryUpdate with DeleteEventDetails for deletion of events */
    };
    /** Enumeration for the different HistoryVariableHandle implementations */
    enum HandleImplementation
    {
        CUSTOM,   /*!< A product specific handle implementation is used */
        NODE_ID,  /*!< The class HistoryVariableHandleNodeId is used */
        UA_NODE   /*!< The class HistoryVariableHandleUaNode is used */
    };
    /** construction */
    HistoryVariableHandle();

    /** Returns the type of handle implementation */
    virtual HandleImplementation getHandleImplementation() const { return CUSTOM; }

    /// @brief Interface of the history manager responsible for this variable.
    HistoryManager* m_pHistoryManager;
protected:
    /** destruction */
    virtual ~HistoryVariableHandle();
};

/** Class for the History Variable Handle containing the NodeId for the processing in the HistoryManager
 *
 *  This class can be used if no other information idenfying the node can be used in the HistoryVariableHandle and the
 *  HistoryManager has all node related information to process the history request for the node.
 */
class SERVER_CORE_EXPORT HistoryVariableHandleNodeId : public HistoryVariableHandle
{
public:
    /* construction */
    HistoryVariableHandleNodeId();

    virtual HandleImplementation getHandleImplementation() const { return HistoryVariableHandle::NODE_ID; }

    /// @brief NodeId of the node used for history access.
    UaNodeId m_nodeId;

protected:
    /* destruction */
    virtual ~HistoryVariableHandleNodeId();
};

/** RegisteredNode
 *  @brief Base class for the Variable Handle used in data access methods.
 *  It is not possible to create shallow copies of this Class.
 */
class SERVER_CORE_EXPORT RegisteredNode
{
    UA_DISABLE_COPY(RegisteredNode);
public:
    /** construction */
    RegisteredNode();
    /** destruction */
    ~RegisteredNode();

    /// @brief Original NodeId of the registered node.
    UaNodeId                m_originalNodeId;
    /// @brief VariableHandle for the value attribute access.
    VariableHandle*         m_pValueAttributeVariableHandle;
    /// @brief HistoryVariableHandle for the history access.
    HistoryVariableHandle*  m_pHistoryVariableHandle;
};


#endif // VARIABLEHANDLE_H
