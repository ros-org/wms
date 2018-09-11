/******************************************************************************
** opcuagds_identifiers.h
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
** Project: C++ OPC Server SDK information model for namespace http://opcfoundation.org/UA/GDS/
**
** Description: OPC Unified Architecture Software Development Kit.
**
******************************************************************************/

#ifndef __OPCUAGDS_IDENTIFIERS_H__
#define __OPCUAGDS_IDENTIFIERS_H__

#define OpcUaGds_NameSpaceUri "http://opcfoundation.org/UA/GDS/"

/*============================================================================
* ObjectType Identifiers
 *===========================================================================*/
#define OpcUaGdsId_ApplicationRegistrationChangedAuditEventType 26
#define OpcUaGdsId_CertificateDeliveredAuditEventType 109
#define OpcUaGdsId_CertificateRequestedAuditEventType 91
#define OpcUaGdsId_DirectoryType 13
#define OpcUaGdsId_CertificateDirectoryType 63

/*============================================================================
* VariableType Identifiers
 *===========================================================================*/

/*============================================================================
* DataType Identifiers
 *===========================================================================*/
#define OpcUaGdsId_ApplicationRecordDataType 1
#define OpcUaGdsId_ApplicationRecordDataType_Encoding_DefaultBinary 134
#define OpcUaGdsId_ApplicationRecordDataType_Encoding_DefaultXml 127
#define OpcUaGdsId_BinarySchema 135
#define OpcUaGdsId_BinarySchema_ApplicationRecordDataType 138
#define OpcUaGdsId_BinarySchema_NamespaceUri 137
#define OpcUaGdsId_XmlSchema 128
#define OpcUaGdsId_XmlSchema_ApplicationRecordDataType 131
#define OpcUaGdsId_XmlSchema_NamespaceUri 130

/*============================================================================
* ReferenceType Identifiers
 *===========================================================================*/

/*============================================================================
* Object Identifiers
 *===========================================================================*/
#define OpcUaGdsId_DirectoryType_Applications 14
#define OpcUaGdsId_CertificateDirectoryType_CertificateGroups 511
#define OpcUaGdsId_CertificateDirectoryType_CertificateGroups_DefaultApplicationGroup 512
#define OpcUaGdsId_CertificateDirectoryType_CertificateGroups_DefaultApplicationGroup_TrustList 513
#define OpcUaGdsId_Directory 141
#define OpcUaGdsId_Directory_Applications 142
#define OpcUaGdsId_Directory_CertificateGroups 614
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup 615
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList 616
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup 649
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList 650
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup 683
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList 684

/*============================================================================
* Variable Identifiers
 *===========================================================================*/
#define OpcUaGdsId_CertificateDeliveredAuditEventType_CertificateGroup 719
#define OpcUaGdsId_CertificateDeliveredAuditEventType_CertificateType 720
#define OpcUaGdsId_CertificateRequestedAuditEventType_CertificateGroup 717
#define OpcUaGdsId_CertificateRequestedAuditEventType_CertificateType 718
#define OpcUaGdsId_DirectoryType_FindApplications_InputArguments 16
#define OpcUaGdsId_DirectoryType_FindApplications_OutputArguments 17
#define OpcUaGdsId_DirectoryType_GetApplication_InputArguments 211
#define OpcUaGdsId_DirectoryType_GetApplication_OutputArguments 212
#define OpcUaGdsId_DirectoryType_QueryServers_InputArguments 24
#define OpcUaGdsId_DirectoryType_QueryServers_OutputArguments 25
#define OpcUaGdsId_DirectoryType_RegisterApplication_InputArguments 19
#define OpcUaGdsId_DirectoryType_RegisterApplication_OutputArguments 20
#define OpcUaGdsId_DirectoryType_UnregisterApplication_InputArguments 22
#define OpcUaGdsId_DirectoryType_UpdateApplication_InputArguments 189
#define OpcUaGdsId_CertificateDirectoryType_CertificateGroups_DefaultApplicationGroup_CertificateTypes 545
#define OpcUaGdsId_CertificateDirectoryType_CertificateGroups_DefaultApplicationGroup_TrustList_Close_InputArguments 523
#define OpcUaGdsId_CertificateDirectoryType_CertificateGroups_DefaultApplicationGroup_TrustList_GetPosition_InputArguments 530
#define OpcUaGdsId_CertificateDirectoryType_CertificateGroups_DefaultApplicationGroup_TrustList_GetPosition_OutputArguments 531
#define OpcUaGdsId_CertificateDirectoryType_CertificateGroups_DefaultApplicationGroup_TrustList_LastUpdateTime 534
#define OpcUaGdsId_CertificateDirectoryType_CertificateGroups_DefaultApplicationGroup_TrustList_Open_InputArguments 520
#define OpcUaGdsId_CertificateDirectoryType_CertificateGroups_DefaultApplicationGroup_TrustList_Open_OutputArguments 521
#define OpcUaGdsId_CertificateDirectoryType_CertificateGroups_DefaultApplicationGroup_TrustList_OpenCount 517
#define OpcUaGdsId_CertificateDirectoryType_CertificateGroups_DefaultApplicationGroup_TrustList_OpenWithMasks_InputArguments 536
#define OpcUaGdsId_CertificateDirectoryType_CertificateGroups_DefaultApplicationGroup_TrustList_OpenWithMasks_OutputArguments 537
#define OpcUaGdsId_CertificateDirectoryType_CertificateGroups_DefaultApplicationGroup_TrustList_Read_InputArguments 525
#define OpcUaGdsId_CertificateDirectoryType_CertificateGroups_DefaultApplicationGroup_TrustList_Read_OutputArguments 526
#define OpcUaGdsId_CertificateDirectoryType_CertificateGroups_DefaultApplicationGroup_TrustList_SetPosition_InputArguments 533
#define OpcUaGdsId_CertificateDirectoryType_CertificateGroups_DefaultApplicationGroup_TrustList_Size 514
#define OpcUaGdsId_CertificateDirectoryType_CertificateGroups_DefaultApplicationGroup_TrustList_UserWritable 516
#define OpcUaGdsId_CertificateDirectoryType_CertificateGroups_DefaultApplicationGroup_TrustList_Writable 515
#define OpcUaGdsId_CertificateDirectoryType_CertificateGroups_DefaultApplicationGroup_TrustList_Write_InputArguments 528
#define OpcUaGdsId_CertificateDirectoryType_FinishRequest_InputArguments 86
#define OpcUaGdsId_CertificateDirectoryType_FinishRequest_OutputArguments 87
#define OpcUaGdsId_CertificateDirectoryType_GetCertificateGroups_InputArguments 370
#define OpcUaGdsId_CertificateDirectoryType_GetCertificateGroups_OutputArguments 371
#define OpcUaGdsId_CertificateDirectoryType_GetCertificateStatus_InputArguments 223
#define OpcUaGdsId_CertificateDirectoryType_GetCertificateStatus_OutputArguments 224
#define OpcUaGdsId_CertificateDirectoryType_GetTrustList_InputArguments 198
#define OpcUaGdsId_CertificateDirectoryType_GetTrustList_OutputArguments 199
#define OpcUaGdsId_CertificateDirectoryType_StartNewKeyPairRequest_InputArguments 77
#define OpcUaGdsId_CertificateDirectoryType_StartNewKeyPairRequest_OutputArguments 78
#define OpcUaGdsId_CertificateDirectoryType_StartSigningRequest_InputArguments 80
#define OpcUaGdsId_CertificateDirectoryType_StartSigningRequest_OutputArguments 81
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_CertificateTypes 648
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_AddCertificate_InputArguments 645
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_Close_InputArguments 626
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_CloseAndUpdate_InputArguments 642
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_CloseAndUpdate_OutputArguments 643
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_GetPosition_InputArguments 633
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_GetPosition_OutputArguments 634
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_LastUpdateTime 637
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_Open_InputArguments 623
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_Open_OutputArguments 624
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_OpenCount 620
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_OpenWithMasks_InputArguments 639
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_OpenWithMasks_OutputArguments 640
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_Read_InputArguments 628
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_Read_OutputArguments 629
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_RemoveCertificate_InputArguments 647
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_SetPosition_InputArguments 636
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_Size 617
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_UserWritable 619
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_Writable 618
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_Write_InputArguments 631
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_CertificateTypes 682
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_AddCertificate_InputArguments 679
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_Close_InputArguments 660
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_CloseAndUpdate_InputArguments 676
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_CloseAndUpdate_OutputArguments 677
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_GetPosition_InputArguments 667
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_GetPosition_OutputArguments 668
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_LastUpdateTime 671
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_Open_InputArguments 657
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_Open_OutputArguments 658
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_OpenCount 654
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_OpenWithMasks_InputArguments 673
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_OpenWithMasks_OutputArguments 674
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_Read_InputArguments 662
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_Read_OutputArguments 663
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_RemoveCertificate_InputArguments 681
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_SetPosition_InputArguments 670
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_Size 651
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_UserWritable 653
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_Writable 652
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_Write_InputArguments 665
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_CertificateTypes 716
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_AddCertificate_InputArguments 713
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_Close_InputArguments 694
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_CloseAndUpdate_InputArguments 710
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_CloseAndUpdate_OutputArguments 711
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_GetPosition_InputArguments 701
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_GetPosition_OutputArguments 702
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_LastUpdateTime 705
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_Open_InputArguments 691
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_Open_OutputArguments 692
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_OpenCount 688
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_OpenWithMasks_InputArguments 707
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_OpenWithMasks_OutputArguments 708
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_Read_InputArguments 696
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_Read_OutputArguments 697
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_RemoveCertificate_InputArguments 715
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_SetPosition_InputArguments 704
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_Size 685
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_UserWritable 687
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_Writable 686
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_Write_InputArguments 699
#define OpcUaGdsId_Directory_FindApplications_InputArguments 144
#define OpcUaGdsId_Directory_FindApplications_OutputArguments 145
#define OpcUaGdsId_Directory_FinishRequest_InputArguments 164
#define OpcUaGdsId_Directory_FinishRequest_OutputArguments 165
#define OpcUaGdsId_Directory_GetApplication_InputArguments 217
#define OpcUaGdsId_Directory_GetApplication_OutputArguments 218
#define OpcUaGdsId_Directory_GetCertificateGroups_InputArguments 509
#define OpcUaGdsId_Directory_GetCertificateGroups_OutputArguments 510
#define OpcUaGdsId_Directory_GetCertificateStatus_InputArguments 226
#define OpcUaGdsId_Directory_GetCertificateStatus_OutputArguments 227
#define OpcUaGdsId_Directory_GetTrustList_InputArguments 205
#define OpcUaGdsId_Directory_GetTrustList_OutputArguments 206
#define OpcUaGdsId_Directory_QueryServers_InputArguments 152
#define OpcUaGdsId_Directory_QueryServers_OutputArguments 153
#define OpcUaGdsId_Directory_RegisterApplication_InputArguments 147
#define OpcUaGdsId_Directory_RegisterApplication_OutputArguments 148
#define OpcUaGdsId_Directory_StartNewKeyPairRequest_InputArguments 155
#define OpcUaGdsId_Directory_StartNewKeyPairRequest_OutputArguments 156
#define OpcUaGdsId_Directory_StartSigningRequest_InputArguments 158
#define OpcUaGdsId_Directory_StartSigningRequest_OutputArguments 159
#define OpcUaGdsId_Directory_UnregisterApplication_InputArguments 150
#define OpcUaGdsId_Directory_UpdateApplication_InputArguments 201

/*============================================================================
* Method Identifiers
 *===========================================================================*/
#define OpcUaGdsId_DirectoryType_FindApplications 15
#define OpcUaGdsId_DirectoryType_GetApplication 210
#define OpcUaGdsId_DirectoryType_QueryServers 23
#define OpcUaGdsId_DirectoryType_RegisterApplication 18
#define OpcUaGdsId_DirectoryType_UnregisterApplication 21
#define OpcUaGdsId_DirectoryType_UpdateApplication 188
#define OpcUaGdsId_CertificateDirectoryType_FinishRequest 85
#define OpcUaGdsId_CertificateDirectoryType_GetCertificateGroups 369
#define OpcUaGdsId_CertificateDirectoryType_GetCertificateStatus 222
#define OpcUaGdsId_CertificateDirectoryType_GetTrustList 197
#define OpcUaGdsId_CertificateDirectoryType_StartNewKeyPairRequest 76
#define OpcUaGdsId_CertificateDirectoryType_StartSigningRequest 79
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_AddCertificate 644
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_Close 625
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_CloseAndUpdate 641
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_GetPosition 632
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_Open 622
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_OpenWithMasks 638
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_Read 627
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_RemoveCertificate 646
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_SetPosition 635
#define OpcUaGdsId_Directory_CertificateGroups_DefaultApplicationGroup_TrustList_Write 630
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_AddCertificate 678
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_Close 659
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_CloseAndUpdate 675
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_GetPosition 666
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_Open 656
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_OpenWithMasks 672
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_Read 661
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_RemoveCertificate 680
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_SetPosition 669
#define OpcUaGdsId_Directory_CertificateGroups_DefaultHttpsGroup_TrustList_Write 664
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_AddCertificate 712
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_Close 693
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_CloseAndUpdate 709
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_GetPosition 700
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_Open 690
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_OpenWithMasks 706
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_Read 695
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_RemoveCertificate 714
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_SetPosition 703
#define OpcUaGdsId_Directory_CertificateGroups_DefaultUserTokenGroup_TrustList_Write 698
#define OpcUaGdsId_Directory_FindApplications 143
#define OpcUaGdsId_Directory_FinishRequest 163
#define OpcUaGdsId_Directory_GetApplication 216
#define OpcUaGdsId_Directory_GetCertificateGroups 508
#define OpcUaGdsId_Directory_GetCertificateStatus 225
#define OpcUaGdsId_Directory_GetTrustList 204
#define OpcUaGdsId_Directory_QueryServers 151
#define OpcUaGdsId_Directory_RegisterApplication 146
#define OpcUaGdsId_Directory_StartNewKeyPairRequest 154
#define OpcUaGdsId_Directory_StartSigningRequest 157
#define OpcUaGdsId_Directory_UnregisterApplication 149
#define OpcUaGdsId_Directory_UpdateApplication 200


#ifdef _WIN32
#ifdef _UAMODELS_GDS_BUILD_DLL
# define UAMODELS_GDS_EXPORT __declspec(dllexport)
#elif defined _UAMODELS_GDS_USE_DLL
# define UAMODELS_GDS_EXPORT __declspec(dllimport)
#else
# define UAMODELS_GDS_EXPORT
#endif
#else
# define UAMODELS_GDS_EXPORT
#endif

///////////////////////////////////////////////
// Private Class Hiding Macros
#define OPCUAGDS_DECLARE_PRIVATE(Class) \
    inline Class##Private* d_func() { return reinterpret_cast<Class##Private *>(d_ptr); } \
    inline const Class##Private* d_func() const { return reinterpret_cast<const Class##Private *>(d_ptr); } \
    friend class Class##Private; \
    Class##Private *d_ptr;

#define OPCUAGDS_DECLARE_PUBLIC(Class) \
    inline Class* q_func() { return static_cast<Class *>(q_ptr); } \
    inline const Class* q_func() const { return static_cast<const Class *>(q_ptr); } \
    friend class Class;

#define OPCUAGDS_D(Class) Class##Private * const d = d_func()
#define OPCUAGDS_CD(Class) const Class##Private * const d = d_func()
#define OPCUAGDS_Q(Class) Class * const q = q_func()

#endif // __OPCUAGDS_IDENTIFIERS_H__

