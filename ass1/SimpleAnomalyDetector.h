//
// Created by aviya - 209251891 and shahar - 209129618 on 2/11/2021.
//

#ifndef SIMPLEANOMALYDETECTOR_H_
#define SIMPLEANOMALYDETECTOR_H_

#include "anomaly_detection_util.h"
#include "AnomalyDetector.h"
#include "timeseries.h"
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#include "minCircle.h"

struct correlatedFeatures {
    string feature1, feature2;  // names of the correlated features
    float corrlation;
    Line lin_reg;
    Circle mec;
    float threshold; // maxDistanceFromReg
};


class SimpleAnomalyDetector : public TimeSeriesAnomalyDetector {
protected:
    vector<correlatedFeatures> cf;
    float threshold = 0.9; // max correlation allowed

public:
    SimpleAnomalyDetector();

    virtual ~SimpleAnomalyDetector();

    virtual void learnNormal(const TimeSeries &ts);

    virtual vector<AnomalyReport> detect(const TimeSeries &ts);

    virtual Line featuresRegLine(vector<float> f1, vector<float> f2);

    virtual float maxDistanceFromReg(vector<float> f1, vector<float> f2, Line reg);

    virtual Point **vectorToArrayPoints(float *x, float *y, int size);

    vector<correlatedFeatures> getNormalModel() {
        return cf;
    }

    virtual bool isAnomalous(correlatedFeatures cf, Point point);

    virtual void deletePoints(Point **p, int size);

    virtual void setCf(Point **points, float max, const TimeSeries &ts, string feature1,
                                      string feature2, vector<float> firstFeatureVals, vector<float> secondFeatureVals);
};

#endif /* SIMPLEANOMALYDETECTOR_H_ */
