/******************************************************************************
** opcuadi_identifiers.h
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
** Project: C++ OPC Server SDK information model for namespace http://opcfoundation.org/UA/DI/
**
** Description: OPC Unified Architecture Software Development Kit.
**
******************************************************************************/

#ifndef __OPCUADI_IDENTIFIERS_H__
#define __OPCUADI_IDENTIFIERS_H__

#define OpcUaDi_NameSpaceUri "http://opcfoundation.org/UA/DI/"

#include "version_coremodule.h"
#if (PROD_MAJOR != 1 || (PROD_MAJOR == 1 && PROD_MINOR < 5) || (PROD_MAJOR == 1 && PROD_MINOR == 5 && PROD_MINOR2 < 0))
#if ! (PROD_MAJOR == 1 && PROD_MINOR == 3 && PROD_MINOR2 == 0 && CPP_SDK_BUILD == 193)
#error The code is generated for SDK version 1.5.0
#endif
#endif

/*============================================================================
* ObjectType Identifiers
 *===========================================================================*/
#define OpcUaDiId_ConfigurableObjectType 1004
#define OpcUaDiId_FunctionalGroupType 1005
#define OpcUaDiId_LockingServicesType 6388
#define OpcUaDiId_NetworkType 6247
#define OpcUaDiId_ProtocolType 1006
#define OpcUaDiId_TopologyElementType 1001
#define OpcUaDiId_BlockType 1003
#define OpcUaDiId_ConnectionPointType 6308
#define OpcUaDiId_DeviceType 1002
#define OpcUaDiId_TransferServicesType 6526

/*============================================================================
* VariableType Identifiers
 *===========================================================================*/
#define OpcUaDiId_UIElementType 6246

/*============================================================================
* DataType Identifiers
 *===========================================================================*/
#define OpcUaDiId_DeviceHealthEnumeration 6244
#define OpcUaDiId_DeviceHealthEnumeration_EnumStrings 6450
#define OpcUaDiId_FetchResultDataType 6522
#define OpcUaDiId_FetchResultDataType_Encoding_DefaultBinary 6551
#define OpcUaDiId_FetchResultDataType_Encoding_DefaultXml 6535
#define OpcUaDiId_FetchResultDataDataType 6524
#define OpcUaDiId_FetchResultDataDataType_Encoding_DefaultBinary 6553
#define OpcUaDiId_FetchResultDataDataType_Encoding_DefaultXml 6537
#define OpcUaDiId_FetchResultErrorDataType 6523
#define OpcUaDiId_FetchResultErrorDataType_Encoding_DefaultBinary 6552
#define OpcUaDiId_FetchResultErrorDataType_Encoding_DefaultXml 6536
#define OpcUaDiId_ParameterResultDataType 6525
#define OpcUaDiId_ParameterResultDataType_Encoding_DefaultBinary 6554
#define OpcUaDiId_ParameterResultDataType_Encoding_DefaultXml 6538
#define OpcUaDiId_BinarySchema 6435
#define OpcUaDiId_BinarySchema_FetchResultDataDataType 6561
#define OpcUaDiId_BinarySchema_FetchResultDataType 6555
#define OpcUaDiId_BinarySchema_FetchResultErrorDataType 6558
#define OpcUaDiId_BinarySchema_ParameterResultDataType 6564
#define OpcUaDiId_BinarySchema_NamespaceUri 6437
#define OpcUaDiId_XmlSchema 6423
#define OpcUaDiId_XmlSchema_FetchResultDataDataType 6545
#define OpcUaDiId_XmlSchema_FetchResultDataType 6539
#define OpcUaDiId_XmlSchema_FetchResultErrorDataType 6542
#define OpcUaDiId_XmlSchema_ParameterResultDataType 6548
#define OpcUaDiId_XmlSchema_NamespaceUri 6425

/*============================================================================
* ReferenceType Identifiers
 *===========================================================================*/
#define OpcUaDiId_ConnectsTo 6030
#define OpcUaDiId_ConnectsToParent 6467
#define OpcUaDiId_IsOnline 6031

/*============================================================================
* Object Identifiers
 *===========================================================================*/
#define OpcUaDiId_ConfigurableObjectType_ObjectIdentifier 6026
#define OpcUaDiId_ConfigurableObjectType_SupportedTypes 5004
#define OpcUaDiId_FunctionalGroupType_GroupIdentifier 6027
#define OpcUaDiId_NetworkType_CPIdentifier 6248
#define OpcUaDiId_NetworkType_CPIdentifier_NetworkAddress 6292
#define OpcUaDiId_NetworkType_ProfileIdentifier 6596
#define OpcUaDiId_NetworkType_Lock 6294
#define OpcUaDiId_TopologyElementType_GroupIdentifier 6567
#define OpcUaDiId_TopologyElementType_Identification 6014
#define OpcUaDiId_TopologyElementType_Lock 6161
#define OpcUaDiId_TopologyElementType_MethodSet 5003
#define OpcUaDiId_TopologyElementType_ParameterSet 5002
#define OpcUaDiId_ConnectionPointType_NetworkIdentifier 6599
#define OpcUaDiId_ConnectionPointType_ProfileId 6499
#define OpcUaDiId_ConnectionPointType_NetworkAddress 6354
#define OpcUaDiId_DeviceType_CPIdentifier 6571
#define OpcUaDiId_DeviceType_CPIdentifier_NetworkAddress 6592
#define OpcUaDiId_DeviceType_DeviceTypeImage 6209
#define OpcUaDiId_DeviceType_Documentation 6211
#define OpcUaDiId_DeviceType_ImageSet 6215
#define OpcUaDiId_DeviceType_ProtocolSupport 6213
#define OpcUaDiId_DeviceSet 5001
#define OpcUaDiId_DeviceTopology 6094
#define OpcUaDiId_NetworkSet 6078

/*============================================================================
* Variable Identifiers
 *===========================================================================*/
#define OpcUaDiId_FunctionalGroupType_GroupIdentifier_UIElement 6242
#define OpcUaDiId_FunctionalGroupType_ParameterIdentifier 6028
#define OpcUaDiId_FunctionalGroupType_UIElement 6243
#define OpcUaDiId_LockingServicesType_BreakLock_OutputArguments 6401
#define OpcUaDiId_LockingServicesType_ExitLock_OutputArguments 6399
#define OpcUaDiId_LockingServicesType_InitLock_InputArguments 6394
#define OpcUaDiId_LockingServicesType_InitLock_OutputArguments 6395
#define OpcUaDiId_LockingServicesType_Locked 6534
#define OpcUaDiId_LockingServicesType_LockingClient 6390
#define OpcUaDiId_LockingServicesType_LockingUser 6391
#define OpcUaDiId_LockingServicesType_RemainingLockTime 6392
#define OpcUaDiId_LockingServicesType_RenewLock_OutputArguments 6397
#define OpcUaDiId_NetworkType_Lock_BreakLock_OutputArguments 6307
#define OpcUaDiId_NetworkType_Lock_ExitLock_OutputArguments 6305
#define OpcUaDiId_NetworkType_Lock_InitLock_InputArguments 6300
#define OpcUaDiId_NetworkType_Lock_InitLock_OutputArguments 6301
#define OpcUaDiId_NetworkType_Lock_Locked 6497
#define OpcUaDiId_NetworkType_Lock_LockingClient 6296
#define OpcUaDiId_NetworkType_Lock_LockingUser 6297
#define OpcUaDiId_NetworkType_Lock_RemainingLockTime 6298
#define OpcUaDiId_NetworkType_Lock_RenewLock_OutputArguments 6303
#define OpcUaDiId_TopologyElementType_Lock_BreakLock_OutputArguments 6174
#define OpcUaDiId_TopologyElementType_Lock_ExitLock_OutputArguments 6172
#define OpcUaDiId_TopologyElementType_Lock_InitLock_InputArguments 6167
#define OpcUaDiId_TopologyElementType_Lock_InitLock_OutputArguments 6168
#define OpcUaDiId_TopologyElementType_Lock_Locked 6468
#define OpcUaDiId_TopologyElementType_Lock_LockingClient 6163
#define OpcUaDiId_TopologyElementType_Lock_LockingUser 6164
#define OpcUaDiId_TopologyElementType_Lock_RemainingLockTime 6165
#define OpcUaDiId_TopologyElementType_Lock_RenewLock_OutputArguments 6170
#define OpcUaDiId_TopologyElementType_ParameterSet_ParameterIdentifier 6017
#define OpcUaDiId_BlockType_ActualMode 6010
#define OpcUaDiId_BlockType_NormalMode 6012
#define OpcUaDiId_BlockType_PermittedMode 6011
#define OpcUaDiId_BlockType_RevisionCounter 6009
#define OpcUaDiId_BlockType_TargetMode 6013
#define OpcUaDiId_DeviceType_DeviceClass 6470
#define OpcUaDiId_DeviceType_DeviceHealth 6208
#define OpcUaDiId_DeviceType_DeviceManual 6005
#define OpcUaDiId_DeviceType_DeviceRevision 6006
#define OpcUaDiId_DeviceType_DeviceTypeImage_ImageIdentifier 6210
#define OpcUaDiId_DeviceType_Documentation_DocumentIdentifier 6212
#define OpcUaDiId_DeviceType_HardwareRevision 6008
#define OpcUaDiId_DeviceType_ImageSet_ImageIdentifier 6216
#define OpcUaDiId_DeviceType_Manufacturer 6003
#define OpcUaDiId_DeviceType_Model 6004
#define OpcUaDiId_DeviceType_ProtocolSupport_ProtocolSupportIdentifier 6214
#define OpcUaDiId_DeviceType_RevisionCounter 6002
#define OpcUaDiId_DeviceType_SerialNumber 6001
#define OpcUaDiId_DeviceType_SoftwareRevision 6007
#define OpcUaDiId_TransferServicesType_FetchTransferResultData_InputArguments 6532
#define OpcUaDiId_TransferServicesType_FetchTransferResultData_OutputArguments 6533
#define OpcUaDiId_TransferServicesType_TransferFromDevice_OutputArguments 6530
#define OpcUaDiId_TransferServicesType_TransferToDevice_OutputArguments 6528
#define OpcUaDiId_DeviceTopology_OnlineAccess 6095
#define OpcUaDiId_Server_ServerCapabilities_MaxInactiveLockTime 6387

/*============================================================================
* Method Identifiers
 *===========================================================================*/
#define OpcUaDiId_FunctionalGroupType_MethodIdentifier 6029
#define OpcUaDiId_LockingServicesType_BreakLock 6400
#define OpcUaDiId_LockingServicesType_ExitLock 6398
#define OpcUaDiId_LockingServicesType_InitLock 6393
#define OpcUaDiId_LockingServicesType_RenewLock 6396
#define OpcUaDiId_NetworkType_Lock_BreakLock 6306
#define OpcUaDiId_NetworkType_Lock_ExitLock 6304
#define OpcUaDiId_NetworkType_Lock_InitLock 6299
#define OpcUaDiId_NetworkType_Lock_RenewLock 6302
#define OpcUaDiId_TopologyElementType_Lock_BreakLock 6173
#define OpcUaDiId_TopologyElementType_Lock_ExitLock 6171
#define OpcUaDiId_TopologyElementType_Lock_InitLock 6166
#define OpcUaDiId_TopologyElementType_Lock_RenewLock 6169
#define OpcUaDiId_TopologyElementType_MethodSet_MethodIdentifier 6018
#define OpcUaDiId_TransferServicesType_FetchTransferResultData 6531
#define OpcUaDiId_TransferServicesType_TransferFromDevice 6529
#define OpcUaDiId_TransferServicesType_TransferToDevice 6527


#ifdef _WIN32
#ifdef _UAMODELS_BUILD_DLL
# define UAMODELS_EXPORT __declspec(dllexport)
#elif defined _UAMODELS_USE_DLL
# define UAMODELS_EXPORT __declspec(dllimport)
#else
# define UAMODELS_EXPORT
#endif
#else
# define UAMODELS_EXPORT
#endif

///////////////////////////////////////////////
// Private Class Hiding Macros
#define OPCUADI_DECLARE_PRIVATE(Class) \
    inline Class##Private* d_func() { return reinterpret_cast<Class##Private *>(d_ptr); } \
    inline const Class##Private* d_func() const { return reinterpret_cast<const Class##Private *>(d_ptr); } \
    friend class Class##Private; \
    Class##Private *d_ptr;

#define OPCUADI_DECLARE_PUBLIC(Class) \
    inline Class* q_func() { return static_cast<Class *>(q_ptr); } \
    inline const Class* q_func() const { return static_cast<const Class *>(q_ptr); } \
    friend class Class;

#define OPCUADI_D(Class) Class##Private * const d = d_func()
#define OPCUADI_CD(Class) const Class##Private * const d = d_func()
#define OPCUADI_Q(Class) Class * const q = q_func()

#endif // __OPCUADI_IDENTIFIERS_H__

