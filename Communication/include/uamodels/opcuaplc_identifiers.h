/******************************************************************************
** opcuaplc_identifiers.h
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
** Project: C++ OPC Server SDK information model for namespace http://PLCopen.org/OpcUa/IEC61131-3/
**
** Description: OPC Unified Architecture Software Development Kit.
**
******************************************************************************/

#ifndef __OPCUAPLC_IDENTIFIERS_H__
#define __OPCUAPLC_IDENTIFIERS_H__

#define OpcUaPlc_NameSpaceUri "http://PLCopen.org/OpcUa/IEC61131-3/"

#include "version_coremodule.h"
#if (PROD_MAJOR != 1 || (PROD_MAJOR == 1 && PROD_MINOR < 5) || (PROD_MAJOR == 1 && PROD_MINOR == 5 && PROD_MINOR2 < 0))
#if ! (PROD_MAJOR == 1 && PROD_MINOR == 3 && PROD_MINOR2 == 0 && CPP_SDK_BUILD == 193)
#error The code is generated for SDK version 1.5.0
#endif
#endif

/*============================================================================
* ObjectType Identifiers
 *===========================================================================*/
#define OpcUaPlcId_CtrlTaskType 1006
#define OpcUaPlcId_SFCType 1007
#define OpcUaPlcId_CtrlProgramOrganizationUnitType 1003
#define OpcUaPlcId_CtrlFunctionBlockType 1005
#define OpcUaPlcId_CtrlProgramType 1004
#define OpcUaPlcId_CtrlConfigurationType 1001
#define OpcUaPlcId_CtrlResourceType 1002

/*============================================================================
* VariableType Identifiers
 *===========================================================================*/

/*============================================================================
* DataType Identifiers
 *===========================================================================*/

/*============================================================================
* ReferenceType Identifiers
 *===========================================================================*/
#define OpcUaPlcId_HasInOutVars 4003
#define OpcUaPlcId_HasInputVars 4001
#define OpcUaPlcId_HasLocalVars 4004
#define OpcUaPlcId_HasOutputVars 4002
#define OpcUaPlcId_HasExternalVars 4005
#define OpcUaPlcId_With 4006

/*============================================================================
* Object Identifiers
 *===========================================================================*/
#define OpcUaPlcId_CtrlConfigurationType_AccessVars 5007
#define OpcUaPlcId_CtrlConfigurationType_Configuration 5009
#define OpcUaPlcId_CtrlConfigurationType_ConfigVars 5008
#define OpcUaPlcId_CtrlConfigurationType_Diagnostic 5010
#define OpcUaPlcId_CtrlConfigurationType_GlobalVars 5006
#define OpcUaPlcId_CtrlConfigurationType_MethodSet 5002
#define OpcUaPlcId_CtrlConfigurationType_Resources 5004
#define OpcUaPlcId_CtrlConfigurationType_Resources_SupportedTypes 5005
#define OpcUaPlcId_CtrlResourceType_Configuration 5019
#define OpcUaPlcId_CtrlResourceType_Diagnostic 5020
#define OpcUaPlcId_CtrlResourceType_GlobalVars 5018
#define OpcUaPlcId_CtrlResourceType_MethodSet 5012
#define OpcUaPlcId_CtrlResourceType_Programs 5016
#define OpcUaPlcId_CtrlResourceType_Programs_SupportedTypes 5017
#define OpcUaPlcId_CtrlResourceType_Tasks 5014
#define OpcUaPlcId_CtrlResourceType_Tasks_SupportedTypes 5015
#define OpcUaPlcId_CtrlTypes 5030

/*============================================================================
* Variable Identifiers
 *===========================================================================*/
#define OpcUaPlcId_CtrlTaskType_Interval 6005
#define OpcUaPlcId_CtrlTaskType_Priority 6004
#define OpcUaPlcId_CtrlTaskType_Single 6006
#define OpcUaPlcId_CtrlProgramOrganizationUnitType_Body 6001
#define OpcUaPlcId_CtrlFunctionBlockType_FunctionBlock 6003
#define OpcUaPlcId_CtrlProgramType_Program 6002

/*============================================================================
* Method Identifiers
 *===========================================================================*/
#define OpcUaPlcId_CtrlConfigurationType_MethodSet_Start 7001
#define OpcUaPlcId_CtrlConfigurationType_MethodSet_Stop 7002
#define OpcUaPlcId_CtrlResourceType_MethodSet_Start 7003
#define OpcUaPlcId_CtrlResourceType_MethodSet_Stop 7004


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
#define OPCUAPLC_DECLARE_PRIVATE(Class) \
    inline Class##Private* d_func() { return reinterpret_cast<Class##Private *>(d_ptr); } \
    inline const Class##Private* d_func() const { return reinterpret_cast<const Class##Private *>(d_ptr); } \
    friend class Class##Private; \
    Class##Private *d_ptr;

#define OPCUAPLC_DECLARE_PUBLIC(Class) \
    inline Class* q_func() { return static_cast<Class *>(q_ptr); } \
    inline const Class* q_func() const { return static_cast<const Class *>(q_ptr); } \
    friend class Class;

#define OPCUAPLC_D(Class) Class##Private * const d = d_func()
#define OPCUAPLC_CD(Class) const Class##Private * const d = d_func()
#define OPCUAPLC_Q(Class) Class * const q = q_func()

#endif // __OPCUAPLC_IDENTIFIERS_H__

