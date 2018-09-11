/* ========================================================================
 * Copyright (c) 2005-2016 The OPC Foundation, Inc. All rights reserved.
 *
 * OPC Foundation MIT License 1.00
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * The complete license agreement can be found here:
 * http://opcfoundation.org/License/MIT/1.00/
 * ======================================================================*/

#ifndef _OPCUA_CONFIG_H_
#define _OPCUA_CONFIG_H_ 1

/*============================================================================
 * build information
 *===========================================================================*/
/** @brief The version number of the official OPC Foundation SDK this build is based on. */
#ifndef OPCUA_BUILDINFO_VERSION_BASE
# define OPCUA_BUILDINFO_VERSION_MAJOR              1
# define OPCUA_BUILDINFO_VERSION_MINOR              3
# define OPCUA_BUILDINFO_VERSION_PATCH              15
# define OPCUA_BUILDINFO_VERSION_BASE               OPCUA_TOSTRING(OPCUA_BUILDINFO_VERSION_MAJOR) "." OPCUA_TOSTRING(OPCUA_BUILDINFO_VERSION_MINOR) "." OPCUA_TOSTRING(OPCUA_BUILDINFO_VERSION_PATCH)
#endif /* OPCUA_BUILDINFO_VERSION_BASE */

/** @brief The build number appended to OPCUA_BUILDINFO_VERSION_BASE. */
#ifndef OPCUA_BUILDINFO_VERSION_BUILD
# define OPCUA_BUILDINFO_VERSION_BUILD              180
#endif /* OPCUA_BUILDINFO_VERSION_BUILD */

/** @brief An optional suffix appended to OPCUA_BUILDINFO_VERSION_BASE. */
#ifndef OPCUA_BUILDINFO_VERSION_SUFFIX
# define OPCUA_BUILDINFO_VERSION_SUFFIX             " / 8814c77e7def993d110141c197623689e15ba579"
#endif /* OPCUA_BUILDINFO_VERSION_SUFFIX */

/** @brief The date and time when the source was last modified. */
#ifndef OPCUA_BUILDINFO_SOURCE_TIMESTAMP
# define OPCUA_BUILDINFO_SOURCE_TIMESTAMP           "2017-11-15 13:31:51"
#endif /* OPCUA_BUILDINFO_SOURCE_TIMESTAMP */

/** @brief The date and time when the binary is build. */
#ifndef OPCUA_BUILDINFO_BUILD_TIMESTAMP
# ifdef OPCUA_P_TIMESTAMP
#  define OPCUA_BUILDINFO_BUILD_TIMESTAMP            OPCUA_P_TIMESTAMP
# else /* OPCUA_P_TIMESTAMP */
#  define OPCUA_BUILDINFO_BUILD_TIMESTAMP            "OPCUA_BUILDINFO_BUILD_TIMESTAMP not set"
# endif /* OPCUA_P_TIMESTAMP */
#endif /* OPCUA_BUILDINFO_BUILD_TIMESTAMP */

/** @brief The name of the company which build the binary. */
#ifndef OPCUA_BUILDINFO_VENDOR_NAME
# define OPCUA_BUILDINFO_VENDOR_NAME                "Unified Automation GmbH"
#endif /* OPCUA_BUILDINFO_VENDOR_NAME */

/** @brief Additional information from the company, ie. internal revision number. */
#ifndef OPCUA_BUILDINFO_VENDOR_INFO
# define OPCUA_BUILDINFO_VENDOR_INFO                ""
#endif /* OPCUA_BUILDINFO_VENDOR_INFO */

/** @brief Information about the used compiler. */
#ifndef OPCUA_BUILDINFO_COMPILER
# ifdef OPCUA_P_COMPILERINFO
#  define OPCUA_BUILDINFO_COMPILER                  OPCUA_P_COMPILERINFO
# else /* OPCUA_P_COMPILERINFO */
#  define OPCUA_BUILDINFO_COMPILER                  "OPCUA_BUILDINFO_COMPILER not set"
# endif /* OPCUA_P_COMPILERINFO */
#endif /* OPCUA_BUILDINFO_COMPILER */

#ifndef OPCUA_BUILD_SHARED_STACK
#  define OPCUA_BUILD_SHARED_STACK                  OPCUA_CONFIG_ON
#endif

/** @brief The versionstring returned by OpcUa_ProxyStub_GetVersion. */
#define OPCUA_PROXYSTUB_VERSIONSTRING   OPCUA_BUILDINFO_VERSION_BASE                        \
                                        " "                                                 \
                                        OPCUA_TOSTRING(OPCUA_BUILDINFO_VERSION_BUILD)       \
                                        OPCUA_BUILDINFO_VERSION_SUFFIX                "\\"  \
                                        OPCUA_BUILDINFO_SOURCE_TIMESTAMP              "\\"  \
                                        OPCUA_BUILDINFO_BUILD_TIMESTAMP               "\\"  \
                                        OPCUA_BUILDINFO_VENDOR_NAME                   "\\"  \
                                        OPCUA_BUILDINFO_VENDOR_INFO                   "\\"  \
                                        OPCUA_BUILDINFO_COMPILER

/*============================================================================
 * configure platform layer interface type
 *===========================================================================*/
#ifndef OPCUA_USE_STATIC_PLATFORM_INTERFACE
# define OPCUA_USE_STATIC_PLATFORM_INTERFACE        OPCUA_CONFIG_ON
#endif /* OPCUA_USE_STATIC_PLATFORM_INTERFACE */

/*============================================================================
 * modules (removing unneeded modules reduces codesize)
 *===========================================================================*/
/** @brief Enable or disable client functionality */
#ifndef OPCUA_HAVE_CLIENTAPI
# define OPCUA_HAVE_CLIENTAPI                       OPCUA_CONFIG_ON
#endif /* OPCUA_HAVE_CLIENTAPI */
/** @brief Enable or disable server functionality */
#ifndef OPCUA_HAVE_SERVERAPI
# define OPCUA_HAVE_SERVERAPI                       OPCUA_CONFIG_ON
#endif /* OPCUA_HAVE_SERVERAPI */
/** @brief Enable or disable threadpool support. Required if secure listener shall use it. */
#ifndef OPCUA_HAVE_THREADPOOL
# define OPCUA_HAVE_THREADPOOL                      OPCUA_CONFIG_YES
#endif /* OPCUA_HAVE_THREADPOOL */
/** @brief Enable or disable the memory stream module. */
#ifndef OPCUA_HAVE_MEMORYSTREAM
# define OPCUA_HAVE_MEMORYSTREAM                    OPCUA_CONFIG_YES
#endif /* OPCUA_HAVE_MEMORYSTREAM */
/** @brief Enable or disable the soap and http support. */
#ifndef OPCUA_HAVE_SOAPHTTP
# define OPCUA_HAVE_SOAPHTTP                        OPCUA_CONFIG_NO
#endif /* OPCUA_HAVE_SOAPHTTP */
/** @brief Enable or disable the https support. */
#ifndef OPCUA_HAVE_HTTPS
# define OPCUA_HAVE_HTTPS                           OPCUA_CONFIG_ON
#endif /* OPCUA_HAVE_HTTPS */

/* * @brief AUTOMATIC; activate additional modules required by soap/http */
#if OPCUA_HAVE_SOAPHTTP
# ifndef OPCUA_HAVE_HTTPAPI
#  define OPCUA_HAVE_HTTPAPI                        OPCUA_CONFIG_YES
# endif /* OPCUA_HAVE_HTTPAPI */
# ifndef OPCUA_HAVE_XMLAPI
#  define OPCUA_HAVE_XMLAPI                         OPCUA_CONFIG_YES
# endif /* OPCUA_HAVE_XMLAPI */
# ifndef OPCUA_HAVE_BASE64
#  define OPCUA_HAVE_BASE64                         OPCUA_CONFIG_YES
# endif /* OPCUA_HAVE_BASE64 */
# if OPCUA_HAVE_MEMORYSTREAM == OPCUA_CONFIG_NO
#  error SOAP/HTTP UA-SC transport profile requires memory stream!
# endif /* OPCUA_HAVE_MEMORYSTREAM */
#endif /* OPCUA_HAVE_SOAPHTTP */

/* * @brief AUTOMATIC; activate additional modules required by https */
#if OPCUA_HAVE_HTTPS
# ifndef OPCUA_HAVE_HTTPSAPI
#  define OPCUA_HAVE_HTTPSAPI                        OPCUA_CONFIG_YES
# endif /* OPCUA_HAVE_HTTPSAPI */
# ifndef OPCUA_HAVE_BASE64
#  define OPCUA_HAVE_BASE64                          OPCUA_CONFIG_YES
# endif /* OPCUA_HAVE_BASE64 */
#endif /* OPCUA_HAVE_HTTPS */

/** @brief AUTOMATIC; set defaults. */
#ifndef OPCUA_HAVE_BASE64
# define OPCUA_HAVE_BASE64                          OPCUA_CONFIG_NO
#endif /* OPCUA_HAVE_BASE64 */
#ifndef OPCUA_HAVE_HTTPSAPI
# define OPCUA_HAVE_HTTPSAPI                        OPCUA_CONFIG_NO
#endif /* OPCUA_HAVE_HTTPSAPI */
#ifndef OPCUA_HAVE_HTTPAPI
# define OPCUA_HAVE_HTTPAPI                         OPCUA_CONFIG_NO
#endif /* OPCUA_HAVE_HTTPAPI */
#ifndef OPCUA_HAVE_XMLAPI
# define OPCUA_HAVE_XMLAPI                          OPCUA_CONFIG_NO
#endif /* OPCUA_HAVE_XMLAPI */

/*============================================================================
 * dotnet native stack wrapper requires this extension
 *===========================================================================*/
#ifndef OPCUA_SUPPORT_PREENCODED_MESSAGES
# define OPCUA_SUPPORT_PREENCODED_MESSAGES          OPCUA_CONFIG_YES
#endif /* OPCUA_SUPPORT_PREENCODED_MESSAGES */

/*============================================================================
 * general
 *===========================================================================*/
/** @brief Prefer the use of inline functions instead of function calls (see opcua_string) */
#ifndef OPCUA_PREFERINLINE
# define OPCUA_PREFERINLINE                         OPCUA_CONFIG_NO
#endif /* OPCUA_PREFERINLINE */

/** @brief Enable the use of safe functions like defined with VS2005 and higher. */
#ifndef OPCUA_USE_SAFE_FUNCTIONS
# define OPCUA_USE_SAFE_FUNCTIONS                   OPCUA_CONFIG_NO
#endif /* OPCUA_USE_SAFE_FUNCTIONS */

/** @brief Some temporary optimizations, to test their impact on performance. */
#ifndef OPCUA_PERFORMANCE_OPTIMIZATION_TESTING
# define OPCUA_PERFORMANCE_OPTIMIZATION_TESTING     OPCUA_CONFIG_NO
#endif /* OPCUA_PERFORMANCE_OPTIMIZATION_TESTING */

/** @brief Adds a value into enums to ensure their size is 32-bits (required for some compilers). */
#ifndef OPCUA_FORCE_INT32_ENUMS
# define OPCUA_FORCE_INT32_ENUMS                    OPCUA_CONFIG_YES
#endif /* OPCUA_FORCE_INT32_ENUMS */

/** @brief Removes picoseconds from data value. Received data is ignored. */
#ifndef OPCUA_DATAVALUE_OMIT_PICOSECONDS
# define OPCUA_DATAVALUE_OMIT_PICOSECONDS           OPCUA_CONFIG_OFF
#endif /* OPCUA_DATAVALUE_OMIT_PICOSECONDS */

/** @brief Removes matrix value union from variant. */
#ifndef OPCUA_VARIANT_OMIT_MATRIX
# define OPCUA_VARIANT_OMIT_MATRIX                  OPCUA_CONFIG_OFF
#endif /* OPCUA_VARIANT_OMIT_MATRIX */

/** @brief Limit string length to 64kB and reduce size of the OpcUa_String structure. */
#ifndef OPCUA_STRING_SHORT
# define OPCUA_STRING_SHORT                         OPCUA_CONFIG_OFF
#endif /* OPCUA_STRING_SHORT */

#ifndef OPCUA_GUID_STRING_USE_CURLYBRACE
# define OPCUA_GUID_STRING_USE_CURLYBRACE           OPCUA_CONFIG_ON
#endif /* OPCUA_GUID_STRING_USE_CURLYBRACE */

/*============================================================================
 * threading
 *===========================================================================*/
/** @brief Run in multi thread mode. Each listen socket gets its own thread. */
#ifndef OPCUA_MULTITHREADED
# define OPCUA_MULTITHREADED                        OPCUA_CONFIG_ON
#endif /* OPCUA_MULTITHREADED */

/** @brief Use access synchronization. Required for OPCUA_MULTITHREADED */
#ifndef OPCUA_USE_SYNCHRONISATION
# define OPCUA_USE_SYNCHRONISATION                  OPCUA_CONFIG_ON
#endif /* OPCUA_USE_SYNCHRONISATION */

#if OPCUA_MULTITHREADED
# if !OPCUA_USE_SYNCHRONISATION
#  error MT needs SYNCHRO!
# endif
#endif

/** @brief Using a special mutex struct with debug information. */
#ifndef OPCUA_MUTEX_ERROR_CHECKING
# define OPCUA_MUTEX_ERROR_CHECKING                 OPCUA_CONFIG_NO
#endif /* OPCUA_MUTEX_ERROR_CHECKING */

/*============================================================================
 * timer
 *===========================================================================*/
/** @brief Maximum amount of milliseconds to stay inactive in the timer. */
#ifndef OPCUA_TIMER_MAX_WAIT
# define OPCUA_TIMER_MAX_WAIT                       200
#endif /* OPCUA_TIMER_MAX_WAIT */

/*============================================================================
 * encodeable object
 *===========================================================================*/
/** @brief Support encoding requests at encodeable object type. */
#ifndef OPCUA_ENCODEABLE_OBJECT_ENCODE_REQUESTS
#define OPCUA_ENCODEABLE_OBJECT_ENCODE_REQUESTS   OPCUA_CONFIG_YES
#endif /* OPCUA_ENCODEABLE_OBJECT_ENCODE_REQUESTS */

/** @brief Support decoding requests at encodeable object type. */
#ifndef OPCUA_ENCODEABLE_OBJECT_DECODE_REQUESTS
#define OPCUA_ENCODEABLE_OBJECT_DECODE_REQUESTS   OPCUA_CONFIG_YES
#endif /* OPCUA_ENCODEABLE_OBJECT_DECODE_REQUESTS */

/** @brief Support encoding responses at encodeable object type. */
#ifndef OPCUA_ENCODEABLE_OBJECT_ENCODE_RESPONSES
#define OPCUA_ENCODEABLE_OBJECT_ENCODE_RESPONSES   OPCUA_CONFIG_YES
#endif /* OPCUA_ENCODEABLE_OBJECT_ENCODE_RESPONSES */

/** @brief Support decoding responses at encodeable object type. */
#ifndef OPCUA_ENCODEABLE_OBJECT_DECODE_RESPONSES
#define OPCUA_ENCODEABLE_OBJECT_DECODE_RESPONSES   OPCUA_CONFIG_YES
#endif /* OPCUA_ENCODEABLE_OBJECT_DECODE_RESPONSES */

/** @brief Support compare method at encodeable object type. */
#ifndef OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED
#define OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED   OPCUA_CONFIG_ON
#endif /* OPCUA_ENCODEABLE_OBJECT_COMPARE_SUPPORTED */

/** @brief Support copy and copyto methods at encodeable object type. */
#ifndef OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED
#define OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED      OPCUA_CONFIG_ON
#endif /* OPCUA_ENCODEABLE_OBJECT_COPY_SUPPORTED */

/** @brief Removes type name from encodeable type structure. */
#ifndef OPCUA_ENCODEABLE_OBJECT_OMIT_TYPE_NAME
# define OPCUA_ENCODEABLE_OBJECT_OMIT_TYPE_NAME     OPCUA_CONFIG_OFF
#endif /* OPCUA_ENCODEABLE_OBJECT_OMIT_TYPE_NAME */

/*============================================================================
 * binary serializer constraints
 *===========================================================================*/
/** @brief The maximum size of memory allocated by a serializer */
#ifndef OPCUA_SERIALIZER_MAXALLOC
# define OPCUA_SERIALIZER_MAXALLOC                  16777216
#endif /* OPCUA_SERIALIZER_MAXALLOC */

/** @brief Maximum String Length accepted */
#ifndef OPCUA_ENCODER_MAXSTRINGLENGTH
# define OPCUA_ENCODER_MAXSTRINGLENGTH              ((OpcUa_UInt32)16777216)
#endif /* OPCUA_ENCODER_MAXSTRINGLENGTH */

/** @brief Maximum Array Length accepted */
#ifndef OPCUA_ENCODER_MAXARRAYLENGTH
# define OPCUA_ENCODER_MAXARRAYLENGTH               ((OpcUa_UInt32)65536)
#endif /* OPCUA_ENCODER_MAXARRAYLENGTH */

/** @brief Maximum ByteString Length accepted */
#ifndef OPCUA_ENCODER_MAXBYTESTRINGLENGTH
# define OPCUA_ENCODER_MAXBYTESTRINGLENGTH          ((OpcUa_UInt32)16777216)
#endif /* OPCUA_ENCODER_MAXBYTESTRINGLENGTH */

/** @brief Maximum Message Length accepted */
#ifndef OPCUA_ENCODER_MAXMESSAGELENGTH
# define OPCUA_ENCODER_MAXMESSAGELENGTH             ((OpcUa_UInt32)16777216)
#endif /* OPCUA_ENCODER_MAXMESSAGELENGTH */

/*============================================================================
 * serializer checks
 *===========================================================================*/
/** @brief OpcUa_True or OpcUa_False; switches checks on or off; dont use with chunking enabled. */
#ifndef OPCUA_SERIALIZER_CHECKLENGTHS
# define OPCUA_SERIALIZER_CHECKLENGTHS              OpcUa_False
#endif /* OPCUA_SERIALIZER_CHECKLENGTHS */

#ifndef OPCUA_SERIALIZER_CHECKNESTINGDEPTH
# define OPCUA_SERIALIZER_CHECKNESTINGDEPTH         OPCUA_CONFIG_YES
#endif /* OPCUA_SERIALIZER_CHECKNESTINGDEPTH */

#ifndef OPCUA_SERIALIZER_MAXNESTINGDEPTH
# define OPCUA_SERIALIZER_MAXNESTINGDEPTH           50
#endif /* OPCUA_SERIALIZER_MAXNESTINGDEPTH */

/** @brief Enable check for additional data after encoded messages. */
#ifndef OPCUA_SERIALIZER_CHECKFORADDITIONALDATA
# define OPCUA_SERIALIZER_CHECKFORADDITIONALDATA    OPCUA_CONFIG_YES
#endif /* OPCUA_SERIALIZER_CHECKFORADDITIONALDATA */

/** @brief Reject message if additional data was found after encoded message body. */
#ifndef OPCUA_SERIALIZER_REJECTADDITIONALDATA
# define OPCUA_SERIALIZER_REJECTADDITIONALDATA      OPCUA_CONFIG_NO
#endif /* OPCUA_SERIALIZER_REJECTADDITIONALDATA */

/*============================================================================
 * thread pool
 *===========================================================================*/
/** @brief Allow to dynamically create threads to prevent delay in queue if no static thread is free. Not recommended! */
#ifndef OPCUA_THREADPOOL_EXPANSION
# define OPCUA_THREADPOOL_EXPANSION                 OPCUA_CONFIG_NO
#endif /* OPCUA_THREADPOOL_EXPANSION */

/** @brief Time in milliseconds after which a worker thread looks for further orders. Affects shutdown time. */
#ifndef OPCUA_THREADPOOL_RELOOPTIME
# define OPCUA_THREADPOOL_RELOOPTIME                500
#endif /* OPCUA_THREADPOOL_RELOOPTIME */

/*============================================================================
 * server call dispatching
 *===========================================================================*/
/** @brief Put fully received requests into the servers thread job queue. (Be careful with the blocking setting!) */
#ifndef OPCUA_SECURELISTENER_SUPPORT_THREADPOOL
# if OPCUA_MULTITHREADED
#  define OPCUA_SECURELISTENER_SUPPORT_THREADPOOL    OPCUA_CONFIG_YES
# else
#  define OPCUA_SECURELISTENER_SUPPORT_THREADPOOL    OPCUA_CONFIG_NO
# endif /* OPCUA_MULTITHREADED */
#endif /* OPCUA_SECURELISTENER_SUPPORT_THREADPOOL */

/** @brief Minimum number of threads (static) in the secure listeners job queue. */
#ifndef OPCUA_SECURELISTENER_THREADPOOL_MINTHREADS
# define OPCUA_SECURELISTENER_THREADPOOL_MINTHREADS 5
#endif /* OPCUA_SECURELISTENER_THREADPOOL_MINTHREADS */

/** @brief Maximum number of threads (static) in the secure listeners job queue. */
#ifndef OPCUA_SECURELISTENER_THREADPOOL_MAXTHREADS
# define OPCUA_SECURELISTENER_THREADPOOL_MAXTHREADS 5
#endif /* OPCUA_SECURELISTENER_THREADPOOL_MAXTHREADS */

/** @brief Maximum total number of jobs being processed by the thread pool. */
#ifndef OPCUA_SECURELISTENER_THREADPOOL_MAXJOBS
# define OPCUA_SECURELISTENER_THREADPOOL_MAXJOBS    20
#endif /* OPCUA_SECURELISTENER_THREADPOOL_MAXJOBS */

/*============================================================================
 * tracer
 *===========================================================================*/
/** @brief Enable output to trace device. */
#ifndef OPCUA_TRACE_ENABLE
# define OPCUA_TRACE_ENABLE                         !OPCUA_CONFIG_OFF
#endif /* OPCUA_TRACE_ENABLE */

/** @brief Unfiltered trace to platform layer. (needs to be supported by platform layer!) */
#ifndef OPCUA_TRACE_RAW
# define OPCUA_TRACE_RAW                            OPCUA_CONFIG_OFF
#endif /* OPCUA_TRACE_ENABLE */

/** @brief Enable output to trace device. */
#ifndef OPCUA_TRACE_MAXLENGTH
# define OPCUA_TRACE_MAXLENGTH                      200
#endif /* OPCUA_TRACE_MAXLENGTH */

/** @brief output the messages in errorhandling macros; requires OPCUA_ERRORHANDLING_OMIT_METHODNAME set to OPCUA_CONFIG_NO */
#ifndef OPCUA_TRACE_ERROR_MACROS
# define OPCUA_TRACE_ERROR_MACROS                   OPCUA_CONFIG_NO
#endif /* OPCUA_TRACE_ERROR_MACROS */

/** @brief Omit the methodname in initialize status macro. */
#ifndef OPCUA_ERRORHANDLING_OMIT_METHODNAME
# define OPCUA_ERRORHANDLING_OMIT_METHODNAME        OPCUA_CONFIG_YES
#endif /* OPCUA_ERRORHANDLING_OMIT_METHODNAME */

/** @brief Add __LINE__ and __FILE__ information to the trace line. */
#ifndef OPCUA_TRACE_FILE_LINE_INFO
# define OPCUA_TRACE_FILE_LINE_INFO                 OPCUA_CONFIG_NO
#endif /* OPCUA_TRACE_FILE_LINE_INFO */

/** @brief Set to YES if the file name comes first in the format string below. */
#ifndef OPCUA_TRACE_FILE_LINE_ORDER
# define OPCUA_TRACE_FILE_LINE_ORDER                OPCUA_CONFIG_YES
#endif /* OPCUA_TRACE_FILE_LINE_ORDER */

/** @brief Set to YES if the file and line information should be printed before the trace content. */
#ifndef OPCUA_TRACE_PREPEND_FILE_LINE
# define OPCUA_TRACE_PREPEND_FILE_LINE              OPCUA_CONFIG_YES
#endif /* OPCUA_TRACE_PREPEND_FILE_LINE */

/** @brief Formatting of the __LINE__ and __FILE__ information. */
#ifndef OPCUA_TRACE_FILE_LINE_INFO_FORMAT
# define OPCUA_TRACE_FILE_LINE_INFO_FORMAT          "In file %s at line %u: "
#endif /* OPCUA_TRACE_FILE_LINE_INFO_FORMAT */

/*============================================================================
 * UASC
 *===========================================================================*/
/** @brief The maximum lifetime of a secure channel security token in milliseconds. */
#ifndef OPCUA_SECURITYTOKEN_LIFETIME_MAX
# define OPCUA_SECURITYTOKEN_LIFETIME_MAX           3600000
#endif /* OPCUA_SECURITYTOKEN_LIFETIME_MAX */

/** @brief The minimum lifetime of a secure channel security token in milliseconds. */
#ifndef OPCUA_SECURITYTOKEN_LIFETIME_MIN
# define OPCUA_SECURITYTOKEN_LIFETIME_MIN           300000
#endif /* OPCUA_SECURITYTOKEN_LIFETIME_MIN */

/** @brief The minimum revised lifetime of a secure channel security token in milliseconds (for clients). */
#ifndef OPCUA_SECURITYTOKEN_REVISED_LIFETIME_MIN
# define OPCUA_SECURITYTOKEN_REVISED_LIFETIME_MIN   OPCUA_SECURITYTOKEN_LIFETIME_MIN
#endif /* OPCUA_SECURITYTOKEN_REVISED_LIFETIME_MIN */

/** @brief The maximum revised lifetime of a secure channel security token in milliseconds (for clients). */
#ifndef OPCUA_SECURITYTOKEN_REVISED_LIFETIME_MAX
# define OPCUA_SECURITYTOKEN_REVISED_LIFETIME_MAX   OPCUA_SECURITYTOKEN_LIFETIME_MAX
#endif /* OPCUA_SECURITYTOKEN_REVISED_LIFETIME_MAX */

/** @brief The interval in which securechannels get checked for lifetime timeout in milliseconds. */
#ifndef OPCUA_SECURELISTENER_WATCHDOG_INTERVAL
# define OPCUA_SECURELISTENER_WATCHDOG_INTERVAL     10000
#endif /* OPCUA_SECURELISTENER_WATCHDOG_INTERVAL */

/** @brief How many OPCUA_SECURELISTENER_WATCHDOG_INTERVAL an inactive secure channel may wait for its activation. */
#ifndef OPCUA_SECURELISTENER_INACTIVECHANNELTIMEOUT
# define OPCUA_SECURELISTENER_INACTIVECHANNELTIMEOUT 1
#endif /* OPCUA_SECURELISTENER_INACTIVECHANNELTIMEOUT */

/** @brief Maximum number of milliseconds allowed between the receive timestamps of the first chunk and the final chunk.
    The actual detection may take up to OPCUA_SECURELISTENER_WATCHDOG_INTERVAL milliseconds.
 */
#ifndef OPCUA_SECURELISTENER_MESSAGE_TIMEOUT
# define OPCUA_SECURELISTENER_MESSAGE_TIMEOUT       5000
#endif /* OPCUA_SECURELISTENER_MESSAGE_TIMEOUT */

/** @brief Close channel if pending input message is older than OPCUA_SECURELISTENER_MESSAGE_TIMEOUT. */
#ifndef OPCUA_SECURELISTENER_MESSAGE_TIMEOUT_CLOSE_CHANNEL
# define OPCUA_SECURELISTENER_MESSAGE_TIMEOUT_CLOSE_CHANNEL OPCUA_CONFIG_YES
#endif /* OPCUA_SECURELISTENER_MESSAGE_TIMEOUT_CLOSE_CHANNEL */

/** @brief Shall the secureconnection validate the server certificate given by the client application? */
#ifndef OPCUA_SECURECONNECTION_VALIDATE_SERVERCERT
# define OPCUA_SECURECONNECTION_VALIDATE_SERVERCERT OPCUA_CONFIG_NO
#endif /* OPCUA_SECURECONNECTION_VALIDATE_SERVERCERT */

/** @brief the time interval in msec at which the secureconnection checks for timeouts. */
#ifndef OPCUA_SECURECONNECTION_TIMEOUTINTERVAL
# define OPCUA_SECURECONNECTION_TIMEOUTINTERVAL     1000
#endif /* OPCUA_SECURECONNECTION_TIMEOUTINTERVAL */

/** @brief Verify the content of all padding bytes. */
#ifndef OPCUA_SECURESTREAM_VERIFY_FULL_PADDING
# define OPCUA_SECURESTREAM_VERIFY_FULL_PADDING     OPCUA_CONFIG_YES
#endif /* OPCUA_SECURESTREAM_VERIFY_FULL_PADDING */

/** @brief Verify received nonce against stored previous nonce to detect duplicates. */
#ifndef OPCUA_SECURECHANNEL_COMPARE_NONCES
# define OPCUA_SECURECHANNEL_COMPARE_NONCES         OPCUA_CONFIG_YES
#endif /* OPCUA_SECURECHANNEL_COMPARE_NONCES */

/** @brief Maximum length for an security policy uri. */
#define OPCUA_SECURECONVERSATION_MAX_SECURITYPOLICY_LENGTH 256

/** @brief Maximum length for an certificate chain. (8192 is the max size of an encoded certificate) */
#define OPCUA_SECURECONVERSATION_MAX_CERTIFICATECHAIN_LENGTH 24576

/** @brief Maximum length of an encoded certificate thumbprint. */
#define OPCUA_SECURECONVERSATION_MAX_THUMBPRINT_LENGTH 20

/*============================================================================
 * HTTPS protocol
 *===========================================================================*/
/** @brief Maximum number of receive buffers per message. */
#ifndef OPCUA_HTTPS_MAX_RECV_BUFFER_COUNT
# define OPCUA_HTTPS_MAX_RECV_BUFFER_COUNT          100
#endif /* OPCUA_HTTPS_MAX_RECV_BUFFER_COUNT */

/** @brief Maximum size of a receive buffer. */
#ifndef OPCUA_HTTPS_MAX_RECV_BUFFER_LENGTH
# define OPCUA_HTTPS_MAX_RECV_BUFFER_LENGTH         65536
#endif /* OPCUA_HTTPS_MAX_RECV_BUFFER_LENGTH */

/** @brief Calculated accepted (total) size limit of a received message. */
#ifndef OPCUA_HTTPS_MAX_RECV_MESSAGE_LENGTH
# define OPCUA_HTTPS_MAX_RECV_MESSAGE_LENGTH         OPCUA_HTTPS_MAX_RECV_BUFFER_COUNT*OPCUA_HTTPS_MAX_RECV_BUFFER_LENGTH
#endif /* OPCUA_HTTPS_MAX_RECV_MESSAGE_LENGTH */

/** @brief Maximum length of a single HTTP header line. If a message exceeds this limit, 414 is returned. */
#ifndef OPCUA_HTTPS_MAX_RECV_HEADER_LINE_LENGTH
# define OPCUA_HTTPS_MAX_RECV_HEADER_LINE_LENGTH    1024
#endif /* OPCUA_HTTPS_MAX_RECV_HEADER_LENGTH */

/** @brief Maximum accepted size of an HTTP header. If a message exceeds this limit, 414 is returned. */
#ifndef OPCUA_HTTPS_MAX_RECV_HEADER_LENGTH
# define OPCUA_HTTPS_MAX_RECV_HEADER_LENGTH         1024
#endif /* OPCUA_HTTPS_MAX_RECV_HEADER_LENGTH */

/** @brief Maximum accepted number of HTTP headers in a received message. If a message exceeds this limit, 414 is returned. */
#ifndef OPCUA_HTTPS_MAX_RECV_HEADER_COUNT
# define OPCUA_HTTPS_MAX_RECV_HEADER_COUNT          20
#endif /* OPCUA_HTTPS_MAX_RECV_HEADER_COUNT */


/** @brief Maximum number of send buffers (result in HTTP chunks) per message. */
#ifndef OPCUA_HTTPS_MAX_SEND_CHUNK_COUNT
# define OPCUA_HTTPS_MAX_SEND_CHUNK_COUNT           200
#endif /* OPCUA_HTTPS_MAX_SEND_CHUNK_COUNT */

/** @brief Maximum size of a send chunk (equals HTTP chunk size). */
#ifndef OPCUA_HTTPS_MAX_SEND_CHUNK_LENGTH
# define OPCUA_HTTPS_MAX_SEND_CHUNK_LENGTH          262144
#endif /* OPCUA_HTTPS_MAX_SEND_CHUNK_LENGTH */

/** @brief Maximum size of outgoing HTTP header. (also includes chunk header) */
#ifndef OPCUA_HTTPS_MAX_SEND_HEADER_LENGTH
# define OPCUA_HTTPS_MAX_SEND_HEADER_LENGTH         350
#endif /* OPCUA_HTTPS_MAX_SEND_HEADER_LENGTH */

/** @brief Maximum size of outgoing HTTP footer. */
#ifndef OPCUA_HTTPS_MAX_SEND_FOOTER_LENGTH
# define OPCUA_HTTPS_MAX_SEND_FOOTER_LENGTH         3
#endif /* OPCUA_HTTPS_MAX_SEND_FOOTER_LENGTH */

/** @brief Calculated size of a send buffer. */
#ifndef OPCUA_HTTPS_MAX_SEND_BUFFER_LENGTH
# define OPCUA_HTTPS_MAX_SEND_BUFFER_LENGTH         OPCUA_HTTPS_MAX_SEND_HEADER_LENGTH + OPCUA_HTTPS_MAX_SEND_CHUNK_LENGTH + OPCUA_HTTPS_MAX_SEND_FOOTER_LENGTH
#endif /* OPCUA_HTTPS_MAX_SEND_BUFFER_LENGTH */

/** @brief Calculated size of outgoing message. */
#ifndef OPCUA_HTTPS_MAX_SEND_MESSAGE_LENGTH
# define OPCUA_HTTPS_MAX_SEND_MESSAGE_LENGTH        OPCUA_HTTPS_MAX_SEND_CHUNK_COUNT*OPCUA_HTTPS_MAX_SEND_BUFFER_LENGTH
#endif /* OPCUA_HTTPS_MAX_SEND_MESSAGE_LENGTH */


/** @brief the time interval in msec at which the https connection checks for timeouts. */
#ifndef OPCUA_HTTPSCONNECTION_TIMEOUTINTERVAL
# define OPCUA_HTTPSCONNECTION_TIMEOUTINTERVAL      1000
#endif /* OPCUA_HTTPSCONNECTION_TIMEOUTINTERVAL */

/** @brief Defines the number of maximum pending requests/connection to a server. */
#ifndef OPCUA_HTTPS_CONNECTION_MAXPENDINGREQUESTS
# define OPCUA_HTTPS_CONNECTION_MAXPENDINGREQUESTS  10
#endif /* OPCUA_HTTPS_CONNECTION_MAXPENDINGREQUESTS */


/** @brief Defines max number of sockets. (a single client needs one socket per parallel request!) */
#ifndef OPCUA_HTTPSLISTENER_MAXCONNECTIONS
# define OPCUA_HTTPSLISTENER_MAXCONNECTIONS         50
#endif /* OPCUA_HTTPSLISTENER_MAXCONNECTIONS */


/** @brief The standard port for the https protocol. */
#ifndef OPCUA_HTTPS_DEFAULT_PORT
# define OPCUA_HTTPS_DEFAULT_PORT                   443
#endif /* OPCUA_HTTP_DEFAULT_PORT */

/** @brief if defined, the httpsstream expects the write call to block until all data is sent */
#ifndef OPCUA_HTTPSSTREAM_BLOCKINGWRITE
# define OPCUA_HTTPSSTREAM_BLOCKINGWRITE            OPCUA_CONFIG_NO
#endif /* OPCUA_HTTPSSTREAM_BLOCKINGWRITE */

/** @brief Enable HTTP GET method - experimental feature */
#ifndef OPCUA_HTTPS_ALLOW_GET
# define OPCUA_HTTPS_ALLOW_GET                      OPCUA_CONFIG_OFF
#endif /* OPCUA_HTTPS_ALLOW_GET */

/*============================================================================
 * UATCP protocol
 *===========================================================================*/
/** @brief default buffer(chunk sizes) (also max value) */
#ifndef OPCUA_TCPLISTENER_DEFAULTCHUNKSIZE
# define OPCUA_TCPLISTENER_DEFAULTCHUNKSIZE         ((OpcUa_UInt32)65536)
#endif /* OPCUA_TCPLISTENER_DEFAULTCHUNKSIZE */

/** @brief The maximum number of client connections supported by a tcp listener. (maybe one reserved, see below) */
#ifndef OPCUA_TCPLISTENER_MAXCONNECTIONS
# define OPCUA_TCPLISTENER_MAXCONNECTIONS           101
#endif /* OPCUA_TCPLISTENER_MAXCONNECTIONS */

/** @brief Reserve one of the OPCUA_TCPLISTENER_MAXCONNECTIONS for an "MaxConnectionsReached" error channel?. */
#ifndef OPCUA_TCPLISTENER_USEEXTRAMAXCONNSOCKET
# define OPCUA_TCPLISTENER_USEEXTRAMAXCONNSOCKET    OPCUA_CONFIG_YES
#endif /* OPCUA_TCPLISTENER_USEEXTRAMAXCONNSOCKET */


#ifndef OPCUA_TCPCONNECTION_DEFAULTCHUNKSIZE
# define OPCUA_TCPCONNECTION_DEFAULTCHUNKSIZE       ((OpcUa_UInt32)65536)
#endif /* OPCUA_TCPCONNECTION_DEFAULTCHUNKSIZE */


/** @brief if defined, the tcpstream expects the write call to block until all data is sent */
#ifndef OPCUA_TCPSTREAM_BLOCKINGWRITE
# define OPCUA_TCPSTREAM_BLOCKINGWRITE              OPCUA_CONFIG_NO
#endif /* OPCUA_TCPSTREAM_BLOCKINGWRITE */


/** @brief The default and maximum number of chunks a tcp message may consist of. */
#ifndef OPCUA_TCPSTREAM_MAXCHUNKCOUNT
# define OPCUA_TCPSTREAM_MAXCHUNKCOUNT              256
#endif /* OPCUA_TCPSTREAM_MAXCHUNKCOUNT */


/** @brief The standard port for the opc.tcp protocol, defined in part 6. */
#ifndef OPCUA_TCP_DEFAULT_PORT
# define OPCUA_TCP_DEFAULT_PORT                     4840
#endif /* OPCUA_TCP_DEFAULT_PORT */

/*============================================================================
 * networking
 *===========================================================================*/
/** @brief The standard port for the http protocol. */
#ifndef OPCUA_HTTP_DEFAULT_PORT
# define OPCUA_HTTP_DEFAULT_PORT                    80
#endif /* OPCUA_HTTP_DEFAULT_PORT */

/** @brief Request this buffersize for the sockets sendbuffer. */
#ifndef OPCUA_P_SOCKET_SETTCPRCVBUFFERSIZE
# define OPCUA_P_SOCKET_SETTCPRCVBUFFERSIZE         OPCUA_CONFIG_NO
#endif /* OPCUA_P_SOCKET_SETTCPRCVBUFFERSIZE */
#ifndef OPCUA_P_TCPRCVBUFFERSIZE
# define OPCUA_P_TCPRCVBUFFERSIZE                   65536
#endif /* OPCUA_P_TCPRCVBUFFERSIZE */
#ifndef OPCUA_P_SOCKET_SETTCPSNDBUFFERSIZE
# define OPCUA_P_SOCKET_SETTCPSNDBUFFERSIZE         OPCUA_CONFIG_NO
#endif /* OPCUA_P_SOCKET_SETTCPSNDBUFFERSIZE */
#ifndef OPCUA_P_TCPSNDBUFFERSIZE
# define OPCUA_P_TCPSNDBUFFERSIZE                   65536
#endif /* OPCUA_P_TCPSNDBUFFERSIZE */

/** @brief the time interval in msec at which the secureconnection checks for timeouts. */
#ifndef OPCUA_SECURECONNECTION_TIMEOUTINTERVAL
# define OPCUA_SECURECONNECTION_TIMEOUTINTERVAL     1000
#endif /* OPCUA_SECURECONNECTION_TIMEOUTINTERVAL */

/*============================================================================
 * type support
 *===========================================================================*/
/** @brief type exclusion configuration */
#include "opcua_exclusions.h"

/*============================================================================
 * build configuration string
 *===========================================================================*/
#ifndef RC_INVOKED
#define OPCUA_PROXYSTUB_STATICCONFIGSTRING          "UseSafeFunction:" OPCUA_TOSTRING(OPCUA_USE_SAFE_FUNCTIONS) "\\"\
                                                    "Force32BitEnums:" OPCUA_TOSTRING(OPCUA_FORCE_INT32_ENUMS) "\\"\
                                                    "Multithreaded:" OPCUA_TOSTRING(OPCUA_MULTITHREADED) "\\"\
                                                    "Synchronized:" OPCUA_TOSTRING(OPCUA_USE_SYNCHRONISATION) "\\"\
                                                    "ThreadPoolSupported:" OPCUA_TOSTRING(OPCUA_SECURELISTENER_SUPPORT_THREADPOOL) "\\"\
                                                    "ThreadPoolDynamicSize:" OPCUA_TOSTRING(OPCUA_THREADPOOL_EXPANSION) "\\"\
                                                    "ThreadPoolReloopTime:" OPCUA_TOSTRING(OPCUA_THREADPOOL_RELOOPTIME) "\\"\
                                                    "TraceLength:" OPCUA_TOSTRING(OPCUA_TRACE_MAXLENGTH) "\\"\
                                                    "SecurityTokenLifeTimeMin:" OPCUA_TOSTRING(OPCUA_SECURITYTOKEN_LIFETIME_MIN) "\\"\
                                                    "SecurityTokenLifeTimeMax:" OPCUA_TOSTRING(OPCUA_SECURITYTOKEN_LIFETIME_MAX) "\\"\
                                                    "SecurityTokenRevisedLifeTimeMin:" OPCUA_TOSTRING(OPCUA_SECURITYTOKEN_REVISED_LIFETIME_MIN) "\\"\
                                                    "SecurityTokenRevisedLifeTimeMax:" OPCUA_TOSTRING(OPCUA_SECURITYTOKEN_REVISED_LIFETIME_MAX) "\\"\
                                                    "SecureListenerWatchdogInterval:" OPCUA_TOSTRING(OPCUA_SECURELISTENER_WATCHDOG_INTERVAL) "\\"\
                                                    "SecureListenerInactiveChannelLifetime:" OPCUA_TOSTRING(OPCUA_SECURELISTENER_INACTIVECHANNELTIMEOUT) "\\"\
                                                    "SecureConnectionTimeoutInterval:" OPCUA_TOSTRING(OPCUA_SECURECONNECTION_TIMEOUTINTERVAL) "\\"\
                                                    "MaxCertificateChainLength:" OPCUA_TOSTRING(OPCUA_SECURECONVERSATION_MAX_CERTIFICATECHAIN_LENGTH) "\\"\
                                                    "SocketBlockingWrite:" OPCUA_TOSTRING(OPCUA_TCPSTREAM_BLOCKINGWRITE) "\\"\
                                                    "TcpListenerMaxConnections:" OPCUA_TOSTRING(OPCUA_TCPLISTENER_MAXCONNECTIONS) "\\"\
                                                    "TcpListenerUseExtraSocket:" OPCUA_TOSTRING(OPCUA_TCPLISTENER_USEEXTRAMAXCONNSOCKET) "\\"\
                                                    "HttpsMaxReceiveMessageLength:" OPCUA_TOSTRING(OPCUA_HTTPS_MAX_RECV_MESSAGE_LENGTH) "\\"\
                                                    "HttpsMaxReceiveHeaderLength:" OPCUA_TOSTRING(OPCUA_HTTPS_MAX_RECV_HEADER_LENGTH) "\\"\
                                                    "HttpsMaxReceiveHeaderCount:" OPCUA_TOSTRING(OPCUA_HTTPS_MAX_RECV_HEADER_COUNT) "\\"\
                                                    "HttpsMaxSendHeaderLength:" OPCUA_TOSTRING(OPCUA_HTTPS_MAX_SEND_HEADER_LENGTH) "\\"\
                                                    "HttpsMaxSendMessageLength:" OPCUA_TOSTRING(OPCUA_HTTPS_MAX_SEND_MESSAGE_LENGTH) "\\"\
                                                    "HttpsConnectionTimeoutInterval:" OPCUA_TOSTRING(OPCUA_HTTPSCONNECTION_TIMEOUTINTERVAL) "\\"\
                                                    "HttpsConnectionMaxPendingRequests:" OPCUA_TOSTRING(OPCUA_HTTPS_CONNECTION_MAXPENDINGREQUESTS) "\\"\
                                                    "HttpsListenerMaxConnections:" OPCUA_TOSTRING(OPCUA_HTTPSLISTENER_MAXCONNECTIONS)
#endif

#endif /* _OPCUA_CONFIG_H_ */
