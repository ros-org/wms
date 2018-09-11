/******************************************************************************
**
** This software is licensed under the proprietary Software License Agreement
** (SLA) of Unified Automation GmbH
** You are not allowed to publish, distribute, sublicense, and/or sell the
** Source Code of this Software
** Get full License Agreement at: license@www.unified-automation.com
**
** Copyright (C) 2005-2016 Unified Automation GmbH. All Rights Reserved.
** Web: http://www.unified-automation.com
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** This code is derived work and it was substantially changed!
** The original MIT License can be found here:
** http://opcfoundation.org/License/MIT/1.00/
**
** Project: OPC UA Ansi C Communication Stack Windows Platform Layer
**
******************************************************************************/

#ifndef _OpcUa_P_Config_H_
#define _OpcUa_P_Config_H_ 1

/*============================================================================
 * platform layer version information
 *===========================================================================*/
/* helper to get build time through buildsystem */
#ifndef OPCUA_P_BUILDINFO_BUILD_TIMESTAMP
#if (defined(__DATE__) && defined(__TIME__))
#define OPCUA_P_TIMESTAMP __DATE__ " " __TIME__
#define OPCUA_P_BUILDINFO_BUILD_TIMESTAMP OPCUA_P_TIMESTAMP
#endif /* __DATE__ && __TIME__ */
#endif /* OPCUA_P_BUILDINFO_BUILD_TIMESTAMP */

/** @brief Name of the platform or operating system this platform layer was created for. */
#ifndef OPCUA_P_BUILDINFO_PLATFORMNAME
# define OPCUA_P_BUILDINFO_PLATFORMNAME             "Linux"
#endif /* OPCUA_P_BUILDINFO_PLATFORMNAME */

/** @brief The date and time when the source was last modified. */
#ifndef OPCUA_P_BUILDINFO_SOURCE_TIMESTAMP
# define OPCUA_P_BUILDINFO_SOURCE_TIMESTAMP         "2017-11-15 13:31:51"
#endif /* OPCUA_P_BUILDINFO_SOURCE_TIMESTAMP */

/** @brief The date and time when the binary is build. */
#ifndef OPCUA_P_BUILDINFO_BUILD_TIMESTAMP
# define OPCUA_P_BUILDINFO_BUILD_TIMESTAMP          "OPCUA_P_BUILDINFO_BUILD_TIMESTAMP not set"
#endif /* OPCUA_P_BUILDINFO_BUILD_TIMESTAMP */

/** @brief The name of the company which build the binary. */
#ifndef OPCUA_P_BUILDINFO_VENDOR_NAME
# define OPCUA_P_BUILDINFO_VENDOR_NAME              "Unified Automation GmbH"
#endif /* OPCUA_P_BUILDINFO_VENDOR_NAME */

/** @brief Additional information from the company, ie. internal revision number. */
#ifndef OPCUA_P_BUILDINFO_VENDOR_INFO
# define OPCUA_P_BUILDINFO_VENDOR_INFO              ""
#endif /* OPCUA_P_BUILDINFO_VENDOR_INFO */

/**********************************************************************************/
/*/  Security Configuration section.                                             /*/
/**********************************************************************************/
#ifndef OPCUA_SUPPORT_SECURITYPOLICY_NONE
# define OPCUA_SUPPORT_SECURITYPOLICY_NONE              OPCUA_CONFIG_ON
#endif  /* OPCUA_SUPPORT_SECURITYPOLICY_NONE */

#ifndef OPCUA_SUPPORT_SECURITYPOLICY_BASIC128RSA15
# define OPCUA_SUPPORT_SECURITYPOLICY_BASIC128RSA15     OPCUA_CONFIG_ON
#endif  /* OPCUA_SUPPORT_SECURITYPOLICY_BASIC128RSA15 */

#ifndef OPCUA_SUPPORT_SECURITYPOLICY_BASIC256
# define OPCUA_SUPPORT_SECURITYPOLICY_BASIC256          OPCUA_CONFIG_ON
#endif /* OPCUA_SUPPORT_SECURITYPOLICY_BASIC256 */

#ifndef OPCUA_SUPPORT_SECURITYPOLICY_BASIC256SHA256
# define OPCUA_SUPPORT_SECURITYPOLICY_BASIC256SHA256    OPCUA_CONFIG_ON
#endif  /* OPCUA_SUPPORT_SECURITYPOLICY_BASIC256SHA256 */

#ifndef OPCUA_SUPPORT_PKI
# define OPCUA_SUPPORT_PKI                              OPCUA_CONFIG_ON
#endif  /* OPCUA_SUPPORT_PKI */

#ifndef OPCUA_HAVE_OPENSSL
# define OPCUA_HAVE_OPENSSL                             OPCUA_CONFIG_ON
#endif  /* OPCUA_HAVE_OPENSSL */

#if OPCUA_SUPPORT_PKI
# ifndef OPCUA_SUPPORT_PKI_OVERRIDE
#  define OPCUA_SUPPORT_PKI_OVERRIDE                    OPCUA_CONFIG_OFF
# endif /* OPCUA_SUPPORT_PKI_OVERRIDE */
# ifndef OPCUA_SUPPORT_PKI_OPENSSL
#  define OPCUA_SUPPORT_PKI_OPENSSL                     OPCUA_CONFIG_ON
# endif /* OPCUA_SUPPORT_PKI_OPENSSL */
#endif /* OPCUA_SUPPORT_PKI */
/** Not supported on this platform. */
#define OPCUA_SUPPORT_PKI_WIN32                         OPCUA_CONFIG_OFF

/**********************************************************************************/
/*/  General section.                                                            /*/
/**********************************************************************************/

/** @brief The maximum number of sockets supported by a socket manager. */
#ifndef OPCUA_P_SOCKETMANAGER_NUMBEROFSOCKETS
# define OPCUA_P_SOCKETMANAGER_NUMBEROFSOCKETS                  104
#endif /* OPCUA_P_SOCKETMANAGER_NUMBEROFSOCKETS */

/** @brief Toggle SSL support in the socket manager class. */
#ifndef OPCUA_P_SOCKETMANAGER_SUPPORT_SSL
# define OPCUA_P_SOCKETMANAGER_SUPPORT_SSL                      OPCUA_CONFIG_ON
#endif /* OPCUA_P_SOCKETMANAGER_SUPPORT_SSL */

/** @brief The number of timers available to the system. */
#ifndef OPCUA_P_TIMER_NO_OF_TIMERS
# define OPCUA_P_TIMER_NO_OF_TIMERS                             200
#endif

#define HAVE_TIMEGM 1

#endif /* _OpcUa_P_Config_H_ */
