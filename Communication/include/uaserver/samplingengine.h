/******************************************************************************
** samplingengine.h
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
** Description: OPC server core module SamplingEngine interface.
**
******************************************************************************/
#ifndef SAMPLINGENGINE_H
#define SAMPLINGENGINE_H

#include "opcuatypes.h"
#include "uathread.h"
#include "uamutex.h"
#include "opcua_list.h"

// Fallback configuration if no configuration is provided through ServerConfig::getAvailableSamplingRates
#define NUM_SAMPLINGRATES 7
extern OpcUa_UInt32 g_SamplingRates[];

/** SamplingExecution
 *  @brief Provides the functionality to sample items at the defined sampling rate.
 */
class SERVER_CORE_EXPORT SamplingExecution
{
public:
    /** construction */
    SamplingExecution(){};
    /** destruction */
    virtual ~SamplingExecution(){};

    /** Sample item. */
    virtual void sample() = 0;
};

 /** SamplingEngine
  *  @brief  Provides the functionality to sample items at the defined sampling rate.
  *  Derived from UaThread.
  *  It is not possible to create shallow copies of this Class.
  */
class SERVER_CORE_EXPORT SamplingEngine: private UaThread
{
    UA_DISABLE_COPY(SamplingEngine);
public:
    SamplingEngine();
    SamplingEngine(const UaUInt32Array& availableSamplingRates);
    ~SamplingEngine();

    void addItemToSampling(SamplingExecution *pItem, OpcUa_Int32& samplingRate);
    void removeItemFromSampling(SamplingExecution *pItem, OpcUa_Int32 samplingRate);

    /** Returns the smallest sampling rate available in the SamplingEngine */
    inline OpcUa_Int32 minSamplingRate() const { return m_MinSamplingRate;}

private:
    /** Main thread method. */
    void run();

    /** Main thread method. */
    OpcUa_Boolean m_isStopped;
    /** @brief Number of configured sampling classes */
    OpcUa_UInt32  m_SamplingClassCount;
    /** @brief Tickcount of last sampling */
    OpcUa_UInt32* m_SamplingTickCounts;
    /** @brief The configured sampling rates */
    OpcUa_UInt32* m_SamplingRates;
    /** @brief Minimum Sampling Rate */
    OpcUa_UInt32  m_MinSamplingRate;
    /** @brief List of Monitored Items for each sampling rate */
    OpcUa_List*   m_SamplingLists;

    /** Mutex to control access to the SamplingEngine object */
    UaMutex      m_mutex;
};

#endif // SAMPLINGENGINE_H
