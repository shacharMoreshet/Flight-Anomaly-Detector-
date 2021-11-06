//
// Created by shach on 02/11/2021.
//

#include <vector>
#include <utility> // std::pair

#ifndef ANOMALY_DETECTION_UTIL_CPP_TIMESERIES_H
#define ANOMALY_DETECTION_UTIL_CPP_TIMESERIES_H

class TimeSeries {
public:
    std::vector<std::pair<std::string, std::vector<float>>> featuresTable;
    //TimeSeries(const char* fileName);
    TimeSeries(std::string filename);
    void printTimeSeries();
};

#endif //ANOMALY_DETECTION_UTIL_CPP_TIMESERIES_H


