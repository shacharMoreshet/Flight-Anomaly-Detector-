//
// Created by shach on 03/11/2021.
//

#include "SimpleAnomalyDetector.h"

void SimpleAnomalyDetector::learnNormal(const TimeSeries &ts) {
    int featureNumber = ts.featuresTable.size();
    for (int i = 0; i < featureNumber; i++) {
        correlatedFeatures currentCf = {}; //creat instance
        float max = 0;
        float c = -1;
        // checking the correlation between feature i to the next features.
        for (int j = i + 1; j < featureNumber; j++) {
            float *ptr1 = (float *) &(ts.featuresTable[i].second[0]);
            float *ptr2 = (float *) &(ts.featuresTable[j].second[0]);
            float p = pearson(ptr1, ptr2, featureNumber);
            if (p > max) { // saving the max correlation.
                max = p;
                c = j;
            }
        }
        // if c value changed and the correlation is bigger than threshold
        // this means we can add new correlated features.
        if (c != -1) {
            currentCf.feature1 = ts.featuresTable[i].first;
            currentCf.feature2 = ts.featuresTable[c].first;
            currentCf.corrlation = max;
            vector<float> firstFeatureVals = ts.featuresTable[i].second;
            vector<float> secondFeatureVals = ts.featuresTable[c].second;
            Line reg = featuresRegLine(firstFeatureVals, secondFeatureVals);
            currentCf.lin_reg = reg;
            currentCf.threshold = maxDistanceFromReg(firstFeatureVals, secondFeatureVals, reg) * 1.2;
            if (max >= currentCf.threshold) {
                cf.push_back(currentCf);
            }
        }
    }
}

Line SimpleAnomalyDetector::featuresRegLine(vector<float> f1, vector<float> f2) {
    vector<Point *> v;
    for (int i = 0; i < f1.size(); i++) {
        Point *p = new Point(f1[i], f2[i]); //saving ptr to the point from f1,f2
        v.push_back(p); // insert the pointer to the vector
    }
    Point **featuresP = &v[0]; // creating pointer to the vector
    return linear_reg(featuresP, v.size());
}

float SimpleAnomalyDetector::maxDistanceFromReg(vector<float> f1, vector<float> f2, Line reg) {
    float max = 0;
    for (int i = 0; i < f1.size(); i++) {
        Point *p = new Point(f1[i], f2[i]); //saving ptr to the point from f1,f2
        float distance = dev(*p, reg); // calculating the distance between the point ahd the regression line.
        if (distance > max) {
            max = distance;
        }
    }
    return max;
}

SimpleAnomalyDetector::SimpleAnomalyDetector() {
    // TODO Auto-generated constructor stub

}

SimpleAnomalyDetector::~SimpleAnomalyDetector() {
    // TODO Auto-generated destructor stub
}

vector<AnomalyReport> SimpleAnomalyDetector::detect(const TimeSeries &ts) {
    return {};
}
