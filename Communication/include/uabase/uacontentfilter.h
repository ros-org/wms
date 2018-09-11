/******************************************************************************
** uacontentfilter.h
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
** Description: UaContentFilter class provides helper classes for UA filter handling.
**
******************************************************************************/
#ifndef UACONTENTFILTER_H
#define UACONTENTFILTER_H

#include "uabase.h"
#include "uavariant.h"
#include "statuscode.h"

class UaContentFilterElement;
typedef UaPointerArray<UaContentFilterElement> UaContentFilterElements;

/** OPC UA ContentFilter used in event filters and the Query service.
 *
 *  This class is used to build and hold an OPC UA ContentFilter used in the event filter of event
 *  monitored items and as filter parameter for the Query service.
 */
class UABASE_EXPORT UaContentFilter
{
public:
    UaContentFilter();
    UaContentFilter(const UaContentFilter &other);
    UaContentFilter(const OpcUa_ContentFilter &other);
    ~UaContentFilter();
    void clear();

    UaContentFilter& operator=(const UaContentFilter &other);

    UaStatus setContentFilter(const OpcUa_ContentFilter* pContentFilter, OpcUa_EventFilterResult* pEventFilterResult, OpcUa_Boolean& hasFilterError);

    void setContentFilterElement(OpcUa_UInt32 index, UaContentFilterElement* pElement, OpcUa_UInt32 arraySize);
    OpcUa_UInt32 getContentFilterElementArraySize() const;
    const UaContentFilterElement* getContentFilterElement(OpcUa_UInt32 index) const;

    void copyTo(OpcUa_ContentFilter& contentFilter) const;
protected:
    UaContentFilterElements m_contentFilterElements;
    OpcUa_Boolean           m_isServer;
};

/** OPC UA FilterOperand used in ContentFilterElement.
 *
 *  This class is used to build and hold an OPC UA FilterOperand used in the UaContentFilterElement. This abstract
 *  class can not be used directly. The three concrete classes UaElementOperand, UaLiteralOperand and UaSimpleAttributeOperand
 *  can be used. The content filter elements and the element filter operands (UaElementOperand)
 *  can be used to build a filter hierarchy.
 */
class UABASE_EXPORT UaFilterOperand
{
public:
    /** FilterOperandType enumeration */
    enum FilterOperandType
    {
        Element,         /*!< Contains a content filter element. This type is use to build a logic tree of subelements
                              by linking the operand of one element to a sub-element */
        Literal,         /*!< Specifies a literal value */
        SimpleAttribute  /*!< Specifies any attribute of an object or variable node using a TypeDefinition and a relative path
                              constructed from BrowseNames. */
    };

    UaFilterOperand();
    virtual ~UaFilterOperand();

    /** Returns the filter operand type.<br>
     *  Possible values are:<br>
     *  - Element
     *  - Literal
     *  - SimpleAttribute
     *  @return The filter operand type
     */
    virtual FilterOperandType getFilterOperandType() const = 0;
};

typedef UaObjectPointerArray<UaFilterOperand> UaFilterOperands;

/** OPC UA ContentFilterElement used in ContentFilter.
 *
 *  This class is used to build and hold an OPC UA ContentFilterElement used in the UaContentFilter.
 *  The content filter elements and the element filter operands (UaElementOperand derived from UaFilterOperand)
 *  can be used to build a filter hierarchy.
 */
class UABASE_EXPORT UaContentFilterElement
{
public:
    UaContentFilterElement();
    UaContentFilterElement(const UaContentFilterElement &other);
    UaContentFilterElement(const OpcUa_ContentFilterElement &other);
    virtual ~UaContentFilterElement();

    UaContentFilterElement& operator=(const UaContentFilterElement &other);

    void setElementIndex(OpcUa_Int32 elementIndex);
    OpcUa_Int32 elementIndex() const;

    void setFilterOperator(OpcUa_FilterOperator filterOperator);
    OpcUa_FilterOperator filterOperator() const;

    void setFilterOperand(OpcUa_UInt32 index, UaFilterOperand* pOperand, OpcUa_UInt32 arraySize);
    OpcUa_UInt32 getFilterOperandArraySize() const;
    const UaFilterOperand* getFilterOperand(OpcUa_UInt32 index) const;

    UaString toString() const;

protected:
    OpcUa_FilterOperator m_filterOperator;
    UaFilterOperands     m_filterOperands;
    OpcUa_Int32          m_elementIndex;
};

/** OPC UA ElementOperand used in ContentFilterElement.
 *
 *  This class is used to build and hold an OPC UA ElementOperand used in the UaContentFilterElement. This class is
 *  concrete implementation of the abstract UaFilterOperand. It contains a content filter element. This type is used
 *  to build a logic tree of sub elements by linking the operand of one element to a sub-element
 */
class UABASE_EXPORT UaElementOperand: public UaFilterOperand
{
    UA_DISABLE_COPY(UaElementOperand);
public:
    UaElementOperand();
    virtual ~UaElementOperand();

    UaFilterOperand::FilterOperandType getFilterOperandType() const;

    // Used in client
    void setIndex(OpcUa_UInt32 index);
    OpcUa_UInt32 index() const;

    // Used in server only
    void setContentFilterElement(UaContentFilterElement* pElement);
    UaContentFilterElement* pContentFilterElement() const;
    UaStatus setContentFilterElement(
        UaContentFilter*                  pUaContentFilter,
        OpcUa_UInt32                      noOfElements,
        const OpcUa_ContentFilterElement* pElements,
        OpcUa_UInt32                      elementIndex,
        OpcUa_EventFilterResult*          pEventFilterResult,
        OpcUa_Boolean&                    hasFilterError);
protected:
    UaContentFilterElement* m_pContentFilterElement;
    OpcUa_UInt32            m_index;
};

/** OPC UA LiteralOperand used in ContentFilterElement.
 *
 *  This class is used to build and hold an OPC UA LiteralOperand used in the UaContentFilterElement. This class is
 *  concrete implementation of the abstract UaFilterOperand. It contains a literal value used in a filter.
 */
class UABASE_EXPORT UaLiteralOperand: public UaFilterOperand
{
    UA_DISABLE_COPY(UaLiteralOperand);
public:
    UaLiteralOperand();
    virtual ~UaLiteralOperand();

    UaFilterOperand::FilterOperandType getFilterOperandType() const;

    void setLiteralValue(const UaVariant& value);
    UaVariant literalValue() const;

protected:
    UaVariant m_literalValue;
};

/** OPC UA SimpleAttributeOperand used in ContentFilterElement or UaEventFilter.
 *
 * This class is used to build and hold an OPC UA SimpleAttributeOperand used in the UaContentFilterElement or in the UaEventFilter.
 * The selectClause and whereClause parameters of an EventFilter are specified with the SimpleAttributeOperand structure. The structure is
 * composed of
 * - typeId (NodeId) NodeId of the type definition node. This is an event type node for event filters.
 *                   In some cases the same BrowsePath will apply to multiple EventTypes. If the Client specifies the BaseEventType in the
 *                   SimpleAttributeOperand then the Server shall evaluate the BrowsePath without considering the Type. The default value for the
 *                   typeId set by the class is the BaseEventType.
 * - browsePath[] (QualifiedName) This parameter specifies a relative path using a list of BrowseNames. The list of BrowseNames in an event filter
 *                                represents the nodes from an EventType to the event field of interest following hierarchical forward references.
 *                                All Nodes followed by the browsePath shall be of the NodeClass Object or Variable.
 *                                If this list is empty the Node is the instance of the TypeDefinition e.g. the instance of a Condition object.
 * - attributeId (IntegerId) The SimpleAttributeOperand structure allows the Client to specify any Attribute, however, the
 *                           Server is only required to support the Value Attribute (OpcUa_Attributes_Value) for Variable Nodes
 *                           and the NodeId Attribute (OpcUa_Attributes_NodeId)for Object Nodes.
 *                           The default value set by this class is the Value attribute.
 * - indexRange (NumericRange) This parameter is used to identify a single element of an array, or a single range of indexes for an array.
 *
 * This class is concrete implementation of the abstract UaFilterOperand. It specifies any attribute of an object or variable node using
 * a TypeDefinition and a relative path constructed from BrowseNames.
 */
class UABASE_EXPORT UaSimpleAttributeOperand: public UaFilterOperand
{
public:
    UaSimpleAttributeOperand();
    UaSimpleAttributeOperand(const UaSimpleAttributeOperand &other);
    UaSimpleAttributeOperand(const OpcUa_SimpleAttributeOperand &other);
    virtual ~UaSimpleAttributeOperand();

    UaSimpleAttributeOperand& operator=(const UaSimpleAttributeOperand &other);

    UaFilterOperand::FilterOperandType getFilterOperandType() const;

    void getSimpleAttributeOperand(OpcUa_SimpleAttributeOperand& operand, OpcUa_Boolean createDeepCopy) const;

    void setTypeId(const UaNodeId& typeId);
    UaNodeId typeId() const;

    void setBrowsePathElement(OpcUa_UInt32 index, const UaQualifiedName& name, OpcUa_UInt32 arraySize);
    void clearBrowsePath();
    OpcUa_UInt32 noOfBrowsePath()const;
    const OpcUa_QualifiedName* browsePath() const;

    void setAttributeId(OpcUa_UInt32 attributeId);
    OpcUa_UInt32 attributeId() const;

    void setIndexRange(const UaString& indexRange);
    UaString indexRange() const;

    UaString toString() const;

    void copyTo(OpcUa_SimpleAttributeOperand* pDst) const;

protected:
    UaNodeId             m_typeId;
    UaQualifiedNameArray m_browsePath;
    OpcUa_UInt32         m_attributeId;
    UaString             m_indexRange;
};

#endif // UACONTENTFILTER_H
