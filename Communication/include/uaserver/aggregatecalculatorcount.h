/******************************************************************************
** aggregatecalculatorcount.h
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
#ifndef AGGREGATECALCULATORCOUNT_H
#define AGGREGATECALCULATORCOUNT_H

#include "aggregatecalculator.h"

/** Calculates the value of the aggregates Count, DurationInStateNonZero, DurationInStateZero, NumberOfTransitions and AnnotationCount.
*/
class AggregateCalculatorCount : AggregateCalculator
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
    AggregateCalculatorCount(
        UaNodeId aggregateId,
        UaDateTime startTime,
        UaDateTime endTime,
        double processingInterval,
        bool stepped,
        OpcUa_AggregateConfiguration& configuration);

    virtual ~AggregateCalculatorCount(){}

public:
    /* Indicates whether this aggregate uses Interpolated Bounding Values.
        @returns True if this aggregate uses Interpolated Bounding Values and false if it uses Simple Bounding Values.
    */
    bool UsesInterpolatedBounds();

protected:
    /* Computes the value for the timeslice. */
    UaDataValue ComputeValue(TimeSlice& slice);

protected:
    /* Calculates the Count aggregate for the timeslice. */
    UaDataValue ComputeCount(TimeSlice& slice);

    /* Calculates the AnnotationCount aggregate for the timeslice. */
    UaDataValue ComputeAnnotationCount(TimeSlice& slice);

    /* Calculates the DurationInStateZero and DurationInStateNonZero aggregates for the timeslice. */
    UaDataValue ComputeDurationInState(TimeSlice& slice, bool isNonZero);

    /* Calculates the Count aggregate for the timeslice. */
    UaDataValue ComputeNumberOfTransitions(TimeSlice& slice);
};

#endif //AGGREGATECALCULATORCOUNT_H
