/******************************************************************************
** userdatabase.h
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
** Description: the base class to store user data.
**
******************************************************************************/
#ifndef USERDATABASE_H
#define USERDATABASE_H

#include "uaplatformdefs.h"
#include "uavariant.h"
#include "uadatavalue.h"

/** @brief Base class for user data stored in SDK managed objects like UaNode.

 User data classes need to be derived from this class if the user data should be added to SDK managed objects like a UaNode to
 allow the SDK managed object to clean the memory of the user data when the SDK managed object is deleted.
 */
class UABASE_EXPORT UserDataBase
{
public:
    /// @brief Enumeration used to detect the type of user data for further processing
    enum UserDataType
    {
        UserDataType_Custom,   /*!< Default type for custom user data */
        UserDataType_GetValue  /*!< User data class derived from UserDataVariableGetValue. This option can be used for
                                    data in memory where the update of the data is not reported through internal events
                                    and the data needs to be polled */
    };

    UserDataBase();
    virtual ~UserDataBase();

    virtual UserDataType getUserDataType() const;
    virtual void setInvalid();
};


/** Specialized UserData class for UaVariable where the UserData class provides a capability to get the current value.
 *
 * This class and the derived classes are used for instances of the UaVariable where polling access through
 * NodeManagerUaNode::readValues is used for variables. This is usefull where the data of the underlying
 * system is available in memory but data changes are not reported through events. In this case the functionality of
 * UaDataVariableCache can not be used but the current value can be provided for generic polling through this user data class.
 */
class UABASE_EXPORT UserDataVariableGetValue : public UserDataBase
{
    UA_DISABLE_COPY(UserDataVariableGetValue);
public:
    UserDataVariableGetValue();
    virtual ~UserDataVariableGetValue();

    UserDataType getUserDataType() const;
    virtual OpcUa_StatusCode getValue(UaVariant& value) const = 0;
    virtual void getDataValue(UaDataValue& dataValue) const;
    virtual OpcUa_StatusCode setDataValue(const UaDataValue& dataValue);
};


#endif
