

#ifndef HYBRIDANOMALYDETECTOR_H_
#define HYBRIDANOMALYDETECTOR_H_

#include "SimpleAnomalyDetector.h"
#include "minCircle.h"

class HybridAnomalyDetector:public SimpleAnomalyDetector {
//    vector<correlatedFeatures> cf;
//    float threshold = 0.9; // max correlation allowed
public:
	HybridAnomalyDetector();
	virtual ~HybridAnomalyDetector();
//    virtual bool HybridAnomalyDetector::isAnomalous(correlatedFeatures cf,Point point);
    virtual bool isAnomalous(correlatedFeatures cf,Point point);
    virtual void setCf(Point **points, float max, const TimeSeries &ts, string feature1,
                                      string feature2, vector<float> firstFeatureVals, vector<float> secondFeatureVals);
    float HybridAnomalyDetector::getThreshold();
    void HybridAnomalyDetector::setThreshold(float threshold);
};


#endif /* HYBRIDANOMALYDETECTOR_H_ */
