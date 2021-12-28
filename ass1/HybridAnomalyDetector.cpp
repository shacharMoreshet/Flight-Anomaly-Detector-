
#include "HybridAnomalyDetector.h"

bool HybridAnomalyDetector::isAnomalous( correlatedFeatures cf,Point point) {
    if (cf.corrlation >= threshold) {
        return SimpleAnomalyDetector::isAnomalous(cf, point);
    } else if ((cf.corrlation > 0.5) && (cf.corrlation < threshold)) {
        cf.mec.radius = cf.threshold;
        return !isInside(cf.mec, point);
    } else {
        return false;
    }
}

void HybridAnomalyDetector::setCf(Point **points, float max, const TimeSeries &ts, string feature1,
                                  string feature2, vector<float> firstFeatureVals, vector<float> secondFeatureVals) {
    if (max >= threshold) {
        SimpleAnomalyDetector::setCf(points, max, ts, feature1, feature2, firstFeatureVals, secondFeatureVals);
    }
    else if ((max > 0.5) && (max < threshold)) {
        correlatedFeatures currentCf = {};//creat instance
        currentCf.corrlation = max;
        currentCf.feature1 = feature1;
        currentCf.feature2 = feature2;
        currentCf.mec = findMinCircle(points, firstFeatureVals.size());
        currentCf.threshold = currentCf.mec.radius * 1.1f;
        cf.push_back(currentCf);
    }
}

float HybridAnomalyDetector::getThreshold(){
    return this->threshold;
}

void HybridAnomalyDetector::setThreshold(float threshold){
    this->threshold = threshold;
}

HybridAnomalyDetector::HybridAnomalyDetector() {
    // TODO Auto-generated constructor stub
}

HybridAnomalyDetector::~HybridAnomalyDetector() {
    // TODO Auto-generated destructor stub
}

