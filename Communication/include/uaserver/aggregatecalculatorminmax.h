/******************************************************************************
** aggregatecalculatorminmax.h
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
** Project: C++ OPC Server SDK core module
**
** Description: Aggregate calculation engine.
**
******************************************************************************/
#ifndef AGGREGATECALCULATORMINMAX_H
#define AGGREGATECALCULATORMINMAX_H

#include "aggregatecalculator.h"

/** Calculates the value of minumim and maximum aggregates.
*
* This class covers the aggregates Minimum, Maximum, MinimumActualTime, MaximumActualTime, Range,
* Minimum2, Maximum2, MinimumActualTime2, MaximumActualTime2 and Range2.
*/
class AggregateCalculatorMinMax : AggregateCalculator
{
public:
    /* Used by the Aggregators factory to create a new instance of the aggregate calculator.
        @param aggregateId The aggregate function to apply.
        @param startTime The start time.
        @param endTime The end time.
        @param processingInterval The processing interval.
        @param stepped Whether to use stepped interpolation.
        @param configuration The aggregate configuration.
    */
    static AggregateCalculatorInterface* CreateCalculator(
        UaNodeId aggregateId,
        UaDateTime startTime,
        UaDateTime endTime,
        double processingInterval,
        bool stepped,
        OpcUa_AggregateConfiguration& configuration);

    /* Initializes the aggregate calculator.
        @param aggregateId The aggregate function to apply.
        @param startTime The start time.
        @param endTime The end time.
        @param processingInterval The processing interval.
        @param stepped Whether to use stepped interpolation.
        @param configuration The aggregate configuration.
    */
    AggregateCalculatorMinMax(
        UaNodeId aggregateId,
        UaDateTime startTime,
        UaDateTime endTime,
        double processingInterval,
        bool stepped,
        OpcUa_AggregateConfiguration& configuration);

    virtual ~AggregateCalculatorMinMax(){}

public:
    /* Indicates whether this aggregate uses Interpolated Bounding Values.
        @returns True if this aggregate uses Interpolated bounding values and false if it uses Simple Bounding Values.
    */
    bool UsesInterpolatedBounds();

protected:
    /* Computes the value for the timeslice. */
    UaDataValue ComputeValue(TimeSlice& slice);

protected:
    /* Calculate the Minimum, Maximum, MinimumActualTime and MaximumActualTime aggregates for the timeslice. */
    UaDataValue ComputeMinMax(TimeSlice& slice, int valueType, bool returnActualTime);

    /* Calculate the Minimum2, Maximum2, MinimumActualTime2, MaximumActualTime2 and Range2 aggregates for the timeslice. */
    UaDataValue ComputeMinMax2(TimeSlice& slice, int valueType, bool returnActualTime);
};

#endif //AGGREGATECALCULATORMINMAX_H
