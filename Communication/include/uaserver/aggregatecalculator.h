/******************************************************************************
** aggregatecalculator.h
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
#ifndef UAAGGREGATECALCULATOR_H
#define UAAGGREGATECALCULATOR_H

#include "aggregatecalculatorinterface.h"
#include "uadatetime.h"
#include "statuscode.h"
#include <list>

/** Calculates the value of an interpolative aggregate.
*/
class AggregateCalculator : public AggregateCalculatorInterface
{
public:
    static AggregateCalculatorInterface* CreateCalculator(
        UaNodeId aggregateId,
        UaDateTime startTime,
        UaDateTime endTime,
        double processingInterval,
        bool stepped,
        OpcUa_AggregateConfiguration& configuration);

    AggregateCalculator(
        UaNodeId aggregateId,
        UaDateTime startTime,
        UaDateTime endTime,
        double processingInterval,
        bool stepped,
        OpcUa_AggregateConfiguration& configuration);

    virtual ~AggregateCalculator(){}

protected:
    AggregateCalculator(UaNodeId aggregateId);

    void Initialize(
        UaNodeId aggregateId,
        UaDateTime startTime,
        UaDateTime endTime,
        double processingInterval,
        bool stepped,
        OpcUa_AggregateConfiguration& configuration);

public:
    /** The aggregate function applied by the calculator. */
    UaNodeId GetAggregateId() { return mAggregateId; }
    bool QueueRawValue(UaDataValue value);

    UaDataValue GetProcessedValue(bool returnPartial);

    /*  Returns true if the specified time is later than the end of the current interval.
       @remarks Return true if time flows forward and the time is later than the end time.
    */
    bool HasEndTimePassed(UaDateTime currentTime);

    /*  Indicates that this aggregate uses Interpolated Bounding Values.
        @returns True if this aggregate uses Interpolated bounding values and false if it uses Simple Bounding Values.
    */
    bool UsesInterpolatedBounds();


protected:
    /** Stores information about a slice of data to be processed. */
    struct TimeSlice
    {
        void Clear(std::list<UaDataValue>::iterator iterEnd)
        {
            StartTime = EndTime = UaDateTime();
            Partial = false;
            Complete = false;
            OutOfDataRange = false;
            EarlyBound = SecondEarlyBound = Begin = End = LateBound = LastProcessedValue = iterEnd;
        }

        /** The start time for the slice. */
        UaDateTime StartTime;

        /** The end time for the slice. */
        UaDateTime EndTime;

        /** True if the slice is a partial interval. */
        bool Partial;

        /** True if all of the data required to process the slice has been collected. */
        bool Complete;

        /** True if the slice includes times that are outside of the available dataset. */
        bool OutOfDataRange;

        /** The first early bound for the slice. */
        std::list<UaDataValue>::iterator EarlyBound;

        /** The second early bound for the slice (always earlier than the first). */
        std::list<UaDataValue>::iterator SecondEarlyBound;

        /** The beginning of the slice. */
        std::list<UaDataValue>::iterator Begin;

        /** The end of the slice. */
        std::list<UaDataValue>::iterator End;

        /** The late bound for the slice. */
        std::list<UaDataValue>::iterator LateBound;

        /** The last value which was processed. */
        std::list<UaDataValue>::iterator LastProcessedValue;
    };

    /** The start time for the request. */
    UaDateTime GetStartTime() { return mStartTime; }

    /** The end time for the request. */
    UaDateTime GetEndTime() { return mEndTime; }

    /** The processing interval for the request. */
    double GetProcessingInterval() { return mProcessingInterval; }

    /** True if the data series requires stepped interpolation. */
    bool GetStepped() { return mStepped; }

    /** The configuration to use when processing. */
    void GetConfiguration(OpcUa_AggregateConfiguration& returnValue) { returnValue = mConfiguration; }

    /** Whether to use the server timestamp for all processing. */
    bool GetUseServerTimestamp() { return mUseServerTimestamp; }

    /** True if data is being processed in reverse order. */
    bool GetTimeFlowsBackward() { return mTimeFlowsBackward; }

    /** */
    void GetCurrentSlice(TimeSlice& returnValue);

    /** True if all values required for the request have been received and processed */
    bool GetComplete() { return mComplete; }

    /** True if data is extrapolated after the end of data. */
    bool GetUsingExtrapolation() { return mUsingExtrapolation; }

    /** True if the GetProcessedValue method should set the Partial bit when appropriate. */
    bool GetSetPartialBit() { return mSetPartialBit; }
    void SetSetPartialBit(bool value) { mSetPartialBit = value; }


    /* Compares timestamps for two DataValues according to the current UseServerTimestamp setting.
        @param value1 The first value to compare.
        @param value2 The second value to compare.
        @returns Less than 0 if value1 is earlier than value2; 0 if they are equal; Greater than zero otherwise.
    */
    int CompareTimestamps(const UaDataValue value1, const UaDataValue value2);

    /* Compares timestamps for a timestamp to a DataValue according to the current UseServerTimestamp setting.
        @param value1 The timestamp to compare.
        @param value2 The data value to compare.
        @returns Less than 0 if value1 is earlier than value2; 0 if they are equal; Greater than zero otherwise.
    */
    int CompareTimestamps(UaDateTime value1, UaDataValue value2);

    /* Checks if the value is good according to the configuration rules.
        @param value The value to test.
        @returns True if the value is good.
    */
    bool IsGood(UaDataValue value);

    /** Returns a status code with the bits pertaining to the code set.
        @param statusCode The original code to modify.
        @param bits The bits to change.
        @returns The modified status code.
    */
    OpcUa_StatusCode SetCodeBits(OpcUa_StatusCode statusCode, unsigned int bits)
    {
        statusCode &= 0x0000FFFF;
        statusCode |= (bits & 0xFFFF0000);
        return statusCode;
    }

    /** Returns the code bits of the specified status code.
        @param statusCode The original code.
        @returns The code bits of the status code.
    */
    OpcUa_StatusCode GetCodeBits(OpcUa_StatusCode statusCode)
    {
        return statusCode & 0xFFFF0000;
    }

    /** Returns a status code with the bits pertaining to aggregates set.
        @param statusCode The original code to modify.
        @param bits The bits to change.
        @returns The modified status code.
    */
    OpcUa_StatusCode SetAggregateBits(OpcUa_StatusCode statusCode, unsigned int bits)
    {
        statusCode |= 0x0400; // Set data info bit
        statusCode &= ~0x001F; // Clear info bits
        statusCode |= (bits & 0x001F);
        return statusCode;
    }

    /** Returns the aggregate bits of the specified status code.
        @param statusCode The original code.
        @returns The aggregate bits of the status code.
    */
    OpcUa_StatusCode GetAggregateBits(OpcUa_StatusCode statusCode)
    {
        return statusCode & 0x001F;
    }

    /** AggregateBits enumeration */
    enum AggregateBits
    {
        Raw = 0x00,            /*!< A raw data value */
        Calculated = 0x01,     /*!< A calculated data value */
        Interpolated = 0x02,   /*!< A data value which was interpolated */
        DataSourceMask = 0x03, /*!< A mask that selects the bit which identify the source of the value (raw, calculated, interpolated) */
        Partial = 0x04,        /*!< A data value which was calculated with an incomplete interval */
        ExtraData = 0x08,      /*!< A raw data value that hides other data at the same timestamp */
        MultipleValues = 0x10  /*!< Multiple values match the aggregate criteria (i.e. multiple minimum values at different timestamps within the same interval) */
    };


private:
    void SetAggregateId(UaNodeId aggregateId) { mAggregateId = aggregateId; }
    void SetStartTime(UaDateTime value) { mStartTime = value; }
    void SetEndTime(UaDateTime value) { mEndTime = value; }
    void SetProcessingInterval(double value) { mProcessingInterval = value; }
    void SetStepped(bool value) { mStepped = value; }
    void SetConfiguration(OpcUa_AggregateConfiguration& value) { mConfiguration = value; }
    void SetUseServerTimestamp(bool value) { mUseServerTimestamp = value; }
    void SetTimeFlowsBackward(bool value) { mTimeFlowsBackward = value; }
    void SetCurrentSlice(TimeSlice& value);
    void SetComplete(bool value) { mComplete = value; }
    void SetUsingExtrapolation(bool value) { mUsingExtrapolation = value; }

protected:

    void CreateSlice(TimeSlice& newSlice, UaDateTime previousStart, UaDateTime previousEnd);

    /* Creates a new timeslice to process.
        @param slice The slice to update.
        @returns True if the slice is complete.
    */
    bool UpdateSlice(TimeSlice& slice);

    /* Calculates the value for the timeslice.
        @param slice The slice to process.
        @returns The processed value.
    */
    virtual UaDataValue ComputeValue(TimeSlice& slice);

    /* Calculate the interpolate aggregate for the timeslice. */
    UaDataValue Interpolate(TimeSlice& slice);

    /* Return a value indicating there is no data in the timeslice. */
    UaDataValue GetNoDataValue(TimeSlice slice);

    /* Returns the timestamp to use for the slice value. */
    UaDateTime GetTimestamp(TimeSlice slice);

    /* Return a value indicating there is no data in the timeslice. */
    UaDataValue GetNoDataValue(UaDateTime timestamp);

    /* Interpolates a value at the timestamp.
        @param timestamp The timestamp.
        @returns The interpolated value.
    */
    UaDataValue Interpolate(UaDateTime timestamp);

    /* Calculate the value at the timestamp using stepped interpolation. */
    UaDataValue SteppedInterpolate(UaDateTime timestamp, UaDataValue earlyBound);

    /* Calculate the value at the timestamp using sloped interpolation. */
    UaDataValue SlopedInterpolate(UaDateTime timestamp, UaDataValue earlyBound, UaDataValue lateBound);

    /* Converts the value to a double for use in calculations (throws exceptions if conversion fails). */
    double CastToDouble(UaDataValue value);

    /* Returns the simple bound for the timestamp. */
    UaDataValue GetSimpleBound(UaDateTime timestamp, TimeSlice& slice);

    /* Returns the values in the list with simple bounds. */
    void GetValuesWithSimpleBounds(TimeSlice& slice, std::list<UaDataValue>& returnList);

    /* Returns the values between the start time and the end time for the slice. */
    bool GetValues(TimeSlice& slice, std::list<UaDataValue>& returnList);

    /* Returns the values in the list with interpolated bounds. */
    void GetValuesWithInterpolatedBounds(TimeSlice& slice, std::list<UaDataValue>& returnList);

    /** A subset of a slice bounded by two raw data points. */
    struct SubRegion
    {
        /** The value at the start of the region. */
        double StartValue;

        /** The value at the end of the region. */
        double EndValue;

        /** The timestamp at the start of the region. */
        UaDateTime StartTime;

        /** The length of the region. */
        double Duration;

        /** The status for the region. */
        UaStatusCode StatusCode;

        /** The data point at the start of the region. */
        UaDataValue DataPoint;

        bool IsNull() { return (StartTime.isNull() != OpcUa_False); }
    };

    /** Returns the values in the list with simple bounds. */
    void GetRegionsInValueSet(std::list<UaDataValue>& values, bool ignoreBadData, bool useSteppedCalculations, std::list<SubRegion>& returnList);

    /* Calculates the value based status code for the slice */
    UaStatusCode GetValueBasedStatusCode(TimeSlice& slice, std::list<UaDataValue>& values, UaStatusCode statusCode);

    /* Calculates the status code for the slice */
    UaStatusCode GetTimeBasedStatusCode(TimeSlice& slice, std::list<UaDataValue>& values, UaStatusCode defaultCode);

    /* Calculates the status code for the slice */
    UaStatusCode GetTimeBasedStatusCode(std::list<SubRegion>& regions, UaStatusCode statusCode);

    std::list<UaDataValue> mValues;


private:
    UaDateTime mStartOfData;
    UaDateTime mEndOfData;
    UaDateTime mStartTime;
    UaDateTime mEndTime;
    double mProcessingInterval;
    bool mStepped;
    UaNodeId mAggregateId;
    OpcUa_AggregateConfiguration mConfiguration;
    bool mUseServerTimestamp;
    bool mTimeFlowsBackward;
    bool mComplete;
    bool mSetPartialBit;
    bool mUsingExtrapolation;
    TimeSlice mCurrentSlice;
};

#endif
