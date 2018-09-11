/******************************************************************************
** uapkiconfig.h
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
** Project: C++ OPC SDK PKI module
**
******************************************************************************/
#ifndef __UAPKICONFIG_H__
#define __UAPKICONFIG_H__

#include "uaplatformdefs.h"

// wincrypt.h has to be included BEFORE x509.h, otherwise X509_NAME gets defined by some
// Windows header, overwriting the OpenSSL definition.
#if defined(_WIN32)
# if OPCUA_SUPPORT_PKI_WIN32
#  include "wincrypt.h"
# endif // OPCUA_SUPPORT_PKI_WIN32
#endif // defined(_WIN32)

#ifdef _WIN32

#ifdef _UA_PKI_BUILD_DLL
# define UAPKI_EXPORT __declspec(dllexport)
#elif defined _UA_PKI_USE_DLL
# define UAPKI_EXPORT __declspec(dllimport)
#else
# define UAPKI_EXPORT
#endif

#if OPCUA_SUPPORT_PKI_WIN32
/** WindowsStoreLocation Enumeration */
enum WindowsStoreLocation
{
    Location_CurrentUser       = CERT_SYSTEM_STORE_CURRENT_USER,        //!< The current user of the system
    Location_LocalMachine      = CERT_SYSTEM_STORE_LOCAL_MACHINE,       //!< The local machine (usually root or administrator)
    Location_CurrentService    = CERT_SYSTEM_STORE_CURRENT_SERVICE,     //!< The current running services
    Location_Services          = CERT_SYSTEM_STORE_SERVICES,            //!< The current running services (usually root or administrator)
    Location_Users             = CERT_SYSTEM_STORE_USERS                //!< The location of all known users
};
#endif // OPCUA_SUPPORT_PKI_WIN32

#else // _WIN32
# define UAPKI_EXPORT
#endif // _WIN32

#endif // __UAPKICONFIG_H__

