//
// Created by aviya - 209251891 and shahar - 209129618 on 2/11/2021.
//

#include <utility> // std::pair
#include <vector>
#include <string>

#ifndef ANOMALY_DETECTION_UTIL_CPP_TIMESERIES_H
#define ANOMALY_DETECTION_UTIL_CPP_TIMESERIES_H

using namespace std;

class TimeSeries {
public:
    vector<pair<string, vector<float>>> featuresTable;

    TimeSeries(string filename);

    void printTimeSeries();

    float findValueInTimeStep(string feature, int time) const;
};

#endif //ANOMALY_DETECTION_UTIL_CPP_TIMESERIES_H


