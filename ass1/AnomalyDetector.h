//
// Created by aviya - 209251891 and shahar - 209129618 on 2/11/2021.
//

#include <vector>
#include <map>
#include <string>
#include "timeseries.h"

#ifndef ANOMALY_DETECTION_UTIL_CPP_ANOMALYDETECTOR_H
#define ANOMALY_DETECTION_UTIL_CPP_ANOMALYDETECTOR_H

using namespace std;

// for each report we have description and timeStep
class AnomalyReport {
public:
    const string description;
    const long timeStep;

    AnomalyReport(string description, long timeStep) :
            description(description), timeStep(timeStep) {}
};

class TimeSeriesAnomalyDetector {
public:
    virtual void learnNormal(const TimeSeries &ts) = 0;

    virtual vector<AnomalyReport> detect(const TimeSeries &ts) = 0;

    virtual ~TimeSeriesAnomalyDetector() {}
};

#endif //ANOMALY_DETECTION_UTIL_CPP_ANOMALYDETECTOR_H

