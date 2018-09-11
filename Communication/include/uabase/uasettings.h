/******************************************************************************
** uasettings.h
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
** Class for loading and storing application settings.
**
******************************************************************************/
#ifndef __UASETTINGS_H__
#define __UASETTINGS_H__

#include "uavariant.h"
#include "uaunistringlist.h"
#include "uaunistring.h"
#include <map>
#include "uaplatformdefs.h"

// forward declaration
class UaSettingsSection;

/// the maximum of buffer to read in data
#define BUFFERSIZE 4096

/** @ingroup CppBaseLibraryClass
 *  The UaSettings class provides persistent platform-independent application settings.
 *  Users normally expect an application to remember its settings
 *  (window sizes and positions, options, etc.) across sessions.
 *  This information is often stored in the system registry on Windows.
 *  On Unix systems, many applications (including the KDE applications) use INI text files.
 *  UaSettings is an abstraction around these technologies, enabling you to save and restore application settings in a portable manner.
 *  UaSettings's API is based on UaVariant, allowing you to save most value-based types, such as UaString with the minimum of effort.
 */
class UABASE_EXPORT UaSettings
{
    UA_DISABLE_COPY(UaSettings);
public:
    /** @brief Scope enumeration. */
    enum Scope
    {
        UserScope   = 0,    /*!< Store settings in a location specific to the current user (e.g., in the user's home directory). */
        SystemScope = 1     /*!< Store settings in a global location, so that all users on the same machine access the same set of settings. */
    };

    UaSettings(const UaUniString &sOrganization, const UaUniString &sApplication, Scope scope = UserScope);
    UaSettings(const UaUniString &sPath);
    ~UaSettings();

    void sync();

    /** Get the name of the organization.
     *  @return the name of the organization.
     */
    inline UaUniString organizationName() const { return m_sOrganization; }

    /** Get the name of the application.
     *  @return the name of the application.
     */
    inline UaUniString applicationName() const { return m_sApplication; }

    /** Get the actual used scope.
     *  @return the actual used scope.
     */
    inline Scope scope() const { return m_scope; }

    void beginGroup(const UaUniString &sGroup);
    void removeKey (const UaUniString &sKey);
    void setValue  (const UaUniString &sKey, const UaVariant &value);

    UaUniString endGroup();
    UaUniString group();

    UaUniStringList childGroups() const;
    UaUniStringList childKeys() const;

    UaVariant value(const UaUniString &sKey, const UaVariant &defaultValue = UaVariant());
    bool      contains(const UaUniString &sKey);

private:
    // forbid default construction
    UaSettings();
    // method to create the INI path
    void createIniPath();
    // method to create the INI file if all data is set.
    void writeIniFile();
    // method to read out an existing INI file and set values to the map
    void readOutIniFile();
    // method to parse the file
    int parseLine(char* a_pchLine);
    // method to find the current section
    UaSettingsSection *findSection(const UaUniString &sGroup);

    // the name of the organization
    UaUniString m_sOrganization;
    // the name of the application
    UaUniString m_sApplication;
    // the path to the INI file
    UaUniString m_sPath;
    // the group in the INI file
    UaSettingsSection *m_pCurrentSection;
    // the actual group.
    UaUniString m_sGroup;
    // scope you use to write into the INI file
    Scope m_scope;
    // Change flag
    bool m_isChanged;

    // this map holds the complete sections and its values.
    std::map<UaUniString, UaSettingsSection*> m_mapSection;
};

#endif // #ifndef __UASETTINGS_H__
