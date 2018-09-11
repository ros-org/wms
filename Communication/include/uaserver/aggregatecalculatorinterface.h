/******************************************************************************
** aggregatecalculatorinterface.h
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
#ifndef AGGREGATECALCULATORINTERFACE_H
#define AGGREGATECALCULATORINTERFACE_H

#include "uanodeid.h"
#include "uadatavalue.h"

/** An interface that captures the original active API of the AggregateCalculator class
 * required to integrate with the subscription code.
 */
class AggregateCalculatorInterface
{
public:
    AggregateCalculatorInterface(){}
    virtual ~AggregateCalculatorInterface(){}

    /** The aggregate function applied by the calculator.*/
    virtual UaNodeId GetAggregateId() = 0;

    /** Pushes the next raw value into the stream.
     * @param value The data value to append to the stream.
     * @return True if successful, false if the source timestamp has been superseded by values already in the stream.
     */
    virtual bool QueueRawValue(UaDataValue value) = 0;

    /** Returns the next processed value.
     * @param returnPartial If true, a partial interval should be processed.
     * @return The processed value. Returns an empty UaDataValue if nothing available and returnPartial is false.
     */
    virtual UaDataValue GetProcessedValue(bool returnPartial) = 0;

    /** Indicates whether this aggregate uses Interpolated Bounding Values.
     * @return True is this aggregate uses Interpolated Bounding Values and false if it uses Simple Bounding Values.
     */
    virtual bool UsesInterpolatedBounds() = 0;

    /** Returns true if the specified time is later than the end time of the current interval.
     * @return true if time flows forward and the time is later than the end time.
     */
    virtual bool HasEndTimePassed(UaDateTime currentTime) = 0;
};

#endif // AGGREGATECALCULATORINTERFACE_H
