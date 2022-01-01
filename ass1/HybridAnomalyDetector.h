

#ifndef HYBRIDANOMALYDETECTOR_H_
#define HYBRIDANOMALYDETECTOR_H_

#include "SimpleAnomalyDetector.h"
#include "minCircle.h"

class HybridAnomalyDetector:public SimpleAnomalyDetector {
public:
	HybridAnomalyDetector();
	virtual ~HybridAnomalyDetector();
    virtual bool isAnomalous(correlatedFeatures cf,Point point);
    virtual void setCf(Point **points, float max, const TimeSeries &ts, string feature1,
                                      string feature2, vector<float> firstFeatureVals, vector<float> secondFeatureVals);
    float getThreshold();
    void setThreshold(float threshold);
};


#endif /* HYBRIDANOMALYDETECTOR_H_ */
