/*****************************************************************************
 *                                                                           *
 * Copyright (c) 2006-2016 Unified Automation GmbH. All rights reserved.     *
 *                                                                           *
 * Software License Agreement ("SLA") Version 2.5                            *
 *                                                                           *
 * Unless explicitly acquired and licensed from Licensor under another       *
 * license, the contents of this file are subject to the Software License    *
 * Agreement ("SLA") Version 2.5, or subsequent versions as allowed by the   *
 * SLA, and You may not copy or use this file in either source code or       *
 * executable form, except in compliance with the terms and conditions of    *
 * the SLA.                                                                  *
 *                                                                           *
 * All software distributed under the SLA is provided strictly on an "AS     *
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,       *
 * AND LICENSOR HEREBY DISCLAIMS ALL SUCH WARRANTIES, INCLUDING WITHOUT      *
 * LIMITATION, ANY WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR   *
 * PURPOSE, QUIET ENJOYMENT, OR NON-INFRINGEMENT. See the SLA for specific   *
 * language governing rights and limitations under the SLA.                  *
 *                                                                           *
 * The complete license agreement can be found here:                         *
 * http://unifiedautomation.com/License/SLA/2.5/                             *
 *                                                                           *
 * Project: Unified Automation OPC UA ANSI C Communication Stack             *
 *                                                                           *
 * This software is based in part on the ANSI C Stack of the OPC Foundation. *
 * Initial version of the ANSI C Stack was founded and copyrighted by OPC    *
 * Foundation, Inc.                                                          *
 * Copyright (C) 2008, 2014 OPC Foundation, Inc., All Rights Reserved.       *
 *****************************************************************************/

#ifndef _OpcUa_Attributes_H_
#define _OpcUa_Attributes_H_ 1

OPCUA_BEGIN_EXTERN_C

/*============================================================================
 * The canonical identifier for the node.
 *===========================================================================*/
#define OpcUa_Attributes_NodeId 1

/*============================================================================
 * The class of the node.
 *===========================================================================*/
#define OpcUa_Attributes_NodeClass 2

/*============================================================================
 * A non-localized, human readable name for the node.
 *===========================================================================*/
#define OpcUa_Attributes_BrowseName 3

/*============================================================================
 * A localized, human readable name for the node.
 *===========================================================================*/
#define OpcUa_Attributes_DisplayName 4

/*============================================================================
 * A localized description for the node.
 *===========================================================================*/
#define OpcUa_Attributes_Description 5

/*============================================================================
 * Indicates which attributes are writable.
 *===========================================================================*/
#define OpcUa_Attributes_WriteMask 6

/*============================================================================
 * Indicates which attributes are writable by the current user.
 *===========================================================================*/
#define OpcUa_Attributes_UserWriteMask 7

/*============================================================================
 * Indicates that a type node may not be instantiated.
 *===========================================================================*/
#define OpcUa_Attributes_IsAbstract 8

/*============================================================================
 * Indicates that forward and inverse references have the same meaning.
 *===========================================================================*/
#define OpcUa_Attributes_Symmetric 9

/*============================================================================
 * The browse name for an inverse reference.
 *===========================================================================*/
#define OpcUa_Attributes_InverseName 10

/*============================================================================
 * Indicates that following forward references within a view will not cause a loop.
 *===========================================================================*/
#define OpcUa_Attributes_ContainsNoLoops 11

/*============================================================================
 * Indicates that the node can be used to subscribe to events.
 *===========================================================================*/
#define OpcUa_Attributes_EventNotifier 12

/*============================================================================
 * The value of a variable.
 *===========================================================================*/
#define OpcUa_Attributes_Value 13

/*============================================================================
 * The node id of the data type for the variable value.
 *===========================================================================*/
#define OpcUa_Attributes_DataType 14

/*============================================================================
 * The number of dimensions in the value.
 *===========================================================================*/
#define OpcUa_Attributes_ValueRank 15

/*============================================================================
 * The length for each dimension of an array value.
 *===========================================================================*/
#define OpcUa_Attributes_ArrayDimensions 16

/*============================================================================
 * How a variable may be accessed.
 *===========================================================================*/
#define OpcUa_Attributes_AccessLevel 17

/*============================================================================
 * How a variable may be accessed after taking the user's access rights into account.
 *===========================================================================*/
#define OpcUa_Attributes_UserAccessLevel 18

/*============================================================================
 * Specifies (in milliseconds) how fast the server can reasonably sample the value for changes.
 *===========================================================================*/
#define OpcUa_Attributes_MinimumSamplingInterval 19

/*============================================================================
 * Specifies whether the server is actively collecting historical data for the variable.
 *===========================================================================*/
#define OpcUa_Attributes_Historizing 20

/*============================================================================
 * Whether the method can be called.
 *===========================================================================*/
#define OpcUa_Attributes_Executable 21

/*============================================================================
 * Whether the method can be called by the current user.
 *===========================================================================*/
#define OpcUa_Attributes_UserExecutable 22

OPCUA_END_EXTERN_C

#endif /* _OpcUa_Attributes_H_ */
/* This is the last line of an autogenerated file. */
