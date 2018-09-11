/******************************************************************************
** userdatareferencecounted.h
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
#ifndef USERDATAREFERENCECOUNTED_H
#define USERDATAREFERENCECOUNTED_H

#include "uabase.h"
#include "referencecounter.h"

/** @brief Base class for reference counted user data stored in reference counted objects like UaStructureDefinition.

 Reference counted user data classes need to be derived from this class if the user data should be added to SDK
 managed objects like a UaStructureDefinition to allow the SDK managed object to clean the memory of the user
 data when the SDK managed object is deleted.
 */
class UABASE_EXPORT UserDataReferenceCounted : public ReferenceCounter
{
public:
    UserDataReferenceCounted(){}
    virtual ~UserDataReferenceCounted(){}
};

#endif // USERDATAREFERENCECOUNTED_H
