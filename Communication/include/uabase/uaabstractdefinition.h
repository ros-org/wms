/******************************************************************************
** uaabstractdefinition.h
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
******************************************************************************/
#ifndef UAABSTRACTDEFINITION_H
#define UAABSTRACTDEFINITION_H

#include "uadatatypedefinition.h"
#include "ualocalizedtext.h"

class UABASE_EXPORT UaAbstractDefinitionPrivate;

/** The class is the base class for Definitions
 */
class UABASE_EXPORT UaAbstractDefinition
{
    UA_DISABLE_COPY(UaAbstractDefinition);
protected:
    UA_DECLARE_PRIVATE(UaAbstractDefinition)
    UaAbstractDefinition(UaAbstractDefinitionPrivate* pBody);
public:
    UaAbstractDefinition();
    virtual ~UaAbstractDefinition();

    virtual void clear() = 0;
    virtual bool isNull() const;

    virtual void setDataTypeId(const UaNodeId &nodeId) = 0;
    UaNodeId dataTypeId() const;

    virtual void setName(const UaString &sName) = 0;
    UaString name() const;

    virtual void setDocumentation(const UaLocalizedText &documentation) = 0;
    UaLocalizedText documentation() const;

    virtual void setNamespace(const UaString &sNamespace) = 0;
    UaString getNamespace() const;

    virtual int childrenCount() const = 0;
};

#endif // UAABSTRACTDEFINITION_H
