/******************************************************************************
** aggregators.h
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
#ifndef AGGREGATORS_H
#define AGGREGATORS_H

#include "aggregatecalculatorinterface.h"
#include <vector>

/** The set of built-in aggregate factories. */
class Aggregators
{
private:
    typedef AggregateCalculatorInterface* (*CreateCalculatorFunc)(
        UaNodeId aggregateId,
        UaDateTime startTime,
        UaDateTime endTime,
        double processingInterval,
        bool stepped,
        OpcUa_AggregateConfiguration& configuration);

    /** Stores the mapping for a aggregate id to the calculator. */
    class FactoryMapping
    {
        public:
        FactoryMapping(UaNodeId aggregateId, UaString aggregateName, UaString aggregateDescription, CreateCalculatorFunc createCalculator)
        {
            AggregateId = aggregateId;
            AggregateName = aggregateName;
            AggregateDescription = aggregateDescription;
            CreateCalculator = createCalculator;
        }

        UaNodeId AggregateId;
        UaString AggregateName;
        UaString AggregateDescription;
        CreateCalculatorFunc CreateCalculator;
    };

    /** Mapping for all of the standard aggregates. */
    static std::vector<FactoryMapping> m_sMappings;
    static void PopulateMap();

public:

    class Aggregates
    {
        friend class Aggregators;

        public:
        UaNodeId AggregateId;
        UaString AggregateName;
        UaString AggregateDescription;

        private:
        Aggregates() {}
        Aggregates(const FactoryMapping& mapping)
        {
            AggregateId = mapping.AggregateId;
            AggregateName = mapping.AggregateName;
            AggregateDescription = mapping.AggregateDescription;
        }
    };

    /* Returns the name for a standard aggregates. */
    static UaString GetNameForStandardAggregate(UaNodeId aggregateId);

    /* Returns the id for a standard aggregates. */
    static UaNodeId GetIdForStandardAggregate(UaString aggregateName);

    /* Returns a list of the supported aggregates. */
    static std::vector<Aggregators::Aggregates> GetSupportedAggregates();

    /* Creates a calculator for one of the standard aggregates. */
    static AggregateCalculatorInterface* CreateStandardCalculator(
        UaNodeId aggregateId,
        UaDateTime startTime,
        UaDateTime endTime,
        double processingInterval,
        bool stepped,
        OpcUa_AggregateConfiguration& configuration);

    /** Clears the static Aggregators class data. Must be called before the UA SDK shutdown. */
    static void clearStaticMembers();

    /*  Determines if the UaDataValue has been assigned to or is empty.
        @param name value The value to compare.
        @returns true if value is empty or false if value has been assigned to */
    static bool IsDataValueEmpty(UaDataValue value);
};

#endif // AGGREGATORS_H
