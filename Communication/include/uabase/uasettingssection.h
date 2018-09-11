/******************************************************************************
** uasettingssection.h
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
** platform independent implementation for ini file handling.
**
******************************************************************************/
#ifndef __UASETTINGSSECTION_H__
#define __UASETTINGSSECTION_H__

#include <opcua_proxystub.h>
#include "uaunistring.h"
#include "uaunistringlist.h"
#include "uavariant.h"
#include <map>
#include "uaplatformdefs.h"

/** @ingroup CppBaseLibraryClass
 *  The UaSettingsSection class provides persistent platform-independent application settings.
 *  UaSettingsSection is a classical helper class to create the information needed for the
 *  class UaSettings.
 *  This class looks after the correct handling of the (sub) sections, keys and values needed to create
 *  an INI file. All information which will be written to the file is kept in the memory during
 *  runtime and will be written into a file when the object will be destroyed.
 */
class UABASE_EXPORT UaSettingsSection
{
    UA_DISABLE_COPY(UaSettingsSection);
public:
    UaSettingsSection(const UaUniString &sGroup);
    ~UaSettingsSection();

    bool removeKey(const UaUniString &sKey);
    void setValue(const UaUniString &sKey, const UaUniString &sValue);
    UaUniString getValue(const UaUniString &sKey, const UaUniString &sDefaultValue);
    bool contains(const UaUniString &sKey);

    UaSettingsSection *findSettingsSection(const UaUniString &sGroup);
    void addSettingsSubSection(UaSettingsSection *pSubSection);

    void setParentSection(UaSettingsSection *pParent);
    UaSettingsSection *getParentSection();

    void getAllSubSections(UaUniStringList *sList, int *index, const UaUniString &sPrefix);
    void getAllSubKeys(UaUniStringList *sList, int *index, const UaUniString &sPrefix);

    void getAllKeyValueStrings(UaUniStringList *sList, int *index, const UaUniString &sPrefix);
    void getKeyValuePairs(UaUniStringList *sList , int *index, const UaUniString &sPrefix);

    UaUniString getGroup();

private:
    // forbid the default construction
    UaSettingsSection();

    // the map for the key-value pair which will be the "key=value" in the INI file.
    std::map<UaUniString, UaUniString> m_mapValues;
    // this map holds all sub sections of the current section
    std::map<UaUniString, UaSettingsSection*> m_mapSubSection;

    // member for the actual section.
    UaUniString m_sGroup;
    // this member points to the parent section of the actual child.
    UaSettingsSection *m_pParentSection;
};

#endif // #ifndef __UASETTINGSSECTION_H__

