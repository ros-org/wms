/******************************************************************************
** uareferencetypesns0.h
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
** Description: OPC UA server core module namespace 0 reference type classe.
**
******************************************************************************/
#ifndef __UAREFERENCETYPENS0_H__
#define __UAREFERENCETYPENS0_H__

#include "uabasenodes.h"

/*! \addtogroup ServerCoreAddressModel
*  @{
*/

/** @brief Derived from UaReferenceType and UaReferenceLists.
 */
class SERVER_CORE_EXPORT UaReferenceTypeNS0: public UaReferenceType, public UaReferenceLists
{
protected:
    /** destruction */
    virtual ~UaReferenceTypeNS0(){};
public:
    /** construction */
    UaReferenceTypeNS0(
        OpcUa_UInt32  identifier,
        UaString      name,
        OpcUa_Boolean isAbstract,
        OpcUa_Boolean symmetric,
        UaString      inverseName);

    /**  Get a ReferenceList where all the Nodes are in.
     *  @return a ReferenceList where all the Nodes are in.
     */
    UaReferenceLists* getUaReferenceLists() const {return (UaReferenceLists*)this;};

    /** Discover the references of a specified node of a view.
     *  This method is used to return a list of references and target nodes for the passed node to browse for the
     *  services Browse and BrowseNext.
     *  @param serviceContext   General context for the service calls containing information like the session object,
     *                          return diagnostic mask and timeout hint.
     *  @param browseContext    Browse context for the first browse or the following browse with continuation point.
     *  @param References       Array of ReferenceDescription results for the browsed node.
     *  @return                 Error code
     */
    UaStatus browse(
        const ServiceContext&    serviceContext,
        BrowseContext&           browseContext,
        UaReferenceDescriptions& References) {return browseReferences(serviceContext, browseContext, References);};

    /** Get the NodeId of the current Node.
     *  @return the NodeId of the current Node.
     */
    UaNodeId        nodeId() const {return UaNodeId(m_identifier, 0);};

    /** Get the browseName of the current Node.
     *  @return the browseName of the current Node.
     */
    UaQualifiedName browseName() const {return UaQualifiedName(m_name, 0);};

    /** Get the displayName as LocalizedText of the current Node.
     *  @return the LocalizedText of the current Node.
     */
    UaLocalizedText displayName(Session*) const {return UaLocalizedText("en", m_name);};

    /** Check if Node is DescriptionSupported.
     *  @return FALSE if not supported.
     */
    OpcUa_Boolean   isDescriptionSupported() const {return OpcUa_False;};

    /** Get the description as LocalizedText of the current Node.
     *  @return the LocalizedText of the current Node.
     */
    UaLocalizedText description(Session*) const { return UaLocalizedText();};

    /** Check if Node is WriteMaskSupported.
     *  @return TRUE if Node is WriteMaskSupported.
     */
    OpcUa_Boolean   isWriteMaskSupported() const {return OpcUa_True;};

    /** Get the writeMask of the current Node.
     *  @return the writeMask.
     */
    OpcUa_UInt32    writeMask() const {return 0;};

    /** Check if Node is UserWriteMaskSupported.
     *  @return TRUE if Node is UserWriteMaskSupported.
     */
    OpcUa_Boolean   isUserWriteMaskSupported() const {return OpcUa_True;};

    /** Check if Node has a userWriteMask.
     *  @return the userWriteMask.
     */
    OpcUa_UInt32    userWriteMask(Session* /*pSession*/) const {return 0;};

    /** Check if Node is Abstract.
     *  @return TRUE if is Abstract FALSE if not.
     */
    OpcUa_Boolean   isAbstract() const {return m_isAbstract;};

    /** Check if Node is symmetric.
     *  @return TRUE if is symmetric FALSE if not.
     */
    OpcUa_Boolean   symmetric() const {return m_symmetric;};

    /** Check if Node is InverseNameSupported.
     *  @return TRUE if is InverseNameSupported FALSE if not.
     */
    OpcUa_Boolean   isInverseNameSupported() const { if (m_inverseName.length()==0) return OpcUa_False; else return OpcUa_True;};

    /** Get the inverseName as LocalizedText of the current Node.
     *  @return the inverseName as LocalizedText.
     */
    UaLocalizedText inverseName(Session*) const {return UaLocalizedText("en", m_inverseName);};

    /** Check whether the current Node is a Subtype of another.
     *  @param pNodeId NodeId of the requested Node.
     *  @return TRUE if the Node is a Subtype of another FALSE if not.
     */
    OpcUa_Boolean isSubtypeOf(const OpcUa_NodeId * pNodeId) const;

    /** Get the Node.
     *  @return the current searched Node.
     */
    UaNode* getUaNode() const {return (UaNode*)this;};

private:
    OpcUa_UInt32  m_identifier;
    UaString      m_name;
    OpcUa_Boolean m_isAbstract;
    OpcUa_Boolean m_symmetric;
    UaString      m_inverseName;
};
/*! @} */

#endif // __UAREFERENCETYPENS0_H__
