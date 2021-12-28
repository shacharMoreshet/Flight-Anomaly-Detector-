//
// Created by aviya - 209251891 and shahar - 209129618 on 2/11/2021.
//

#include "SimpleAnomalyDetector.h"

void SimpleAnomalyDetector::learnNormal(const TimeSeries &ts) {
    int rowsNumber = ts.featuresTable[0].second.size(); // rows number
    int columnNumber = ts.featuresTable.size(); // column Number
    for (int i = 0; i < columnNumber; i++) {
        float max = 0;
        int c = -1;
        // checking the correlation between feature i to the next features.
        for (int j = i + 1; j < columnNumber; j++) {
            float *ptr1 = (float *) &(ts.featuresTable[i].second[0]);
            float *ptr2 = (float *) &(ts.featuresTable[j].second[0]);
            float p = pearson(ptr1, ptr2, rowsNumber);
            if (p > max) { // saving the max correlation.
                max = p;
                c = j;
            }
        }
        // if c value changed and the correlation is bigger than threshold
        // this means we can add new correlated features.
        if (c != -1) {
            vector<float> firstFeatureVals = ts.featuresTable[i].second;
            vector<float> secondFeatureVals = ts.featuresTable[c].second;
            string feature1 = ts.featuresTable[i].first;
            string feature2 = ts.featuresTable[c].first;
            Point **points = vectorToArrayPoints(firstFeatureVals.data(), secondFeatureVals.data(), firstFeatureVals.size());
            setCf(points, max, ts, feature1, feature2, firstFeatureVals, secondFeatureVals);
            deletePoints(points, firstFeatureVals.size());
        }
    }
}

Point **SimpleAnomalyDetector::vectorToArrayPoints(float *x, float *y, int size) {
    // create a array of pointers that every one is a pointer to point.
    Point **p = new Point *[size];
    // create all the points.
    for (int i = 0; i < size; i++) {
        p[i] = new Point(x[i], y[i]);
    }
    return p;
}

void SimpleAnomalyDetector::setCf(Point **points, float max, const TimeSeries &ts, string feature1,
                                  string feature2, vector<float> firstFeatureVals, vector<float> secondFeatureVals) {
    if (max >= threshold) {
        correlatedFeatures currentCf = {};//creat instance
        currentCf.corrlation = max;
        currentCf.feature1 = feature1;
        currentCf.feature2 = feature2;
        Line reg = featuresRegLine(firstFeatureVals, secondFeatureVals);
        currentCf.lin_reg = reg;
        currentCf.threshold = maxDistanceFromReg(firstFeatureVals, secondFeatureVals, reg) * 1.1f;
        cf.push_back(currentCf);
    }

}

void SimpleAnomalyDetector::deletePoints(Point **p, int size) {
    for (int i = 0; i < size; i++) {
        delete p[i];
    }
    delete[] p;
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
    // the vector of the reports
    vector<AnomalyReport> reportAnomaly;
    //the size of the features table
    int rowsNumber = ts.featuresTable[0].second.size(); // rows number

    // go on the vector of correlated features
    for (correlatedFeatures c: cf) {
        // j is the time step of the anomaly report
        for (int time = 0; time < rowsNumber; time++) {
            // the two correlated features
            string feature1 = c.feature1;
            string feature2 = c.feature2;
            //find the value in time step
            float x = ts.findValueInTimeStep(feature1, time);
            float y = ts.findValueInTimeStep(feature2, time);

            Point point = Point(x, y);
            if (isAnomalous(c, point)) {
                string description = feature1 + "-" + feature2;
                reportAnomaly.push_back(AnomalyReport(description, time + 1));
            }
        }
    }

    return reportAnomaly;
}

/**
 * @param cf - the correlated features.
 * @param point - the point that we want to check if its anomaly.
 * @return - true / false.
 */
bool SimpleAnomalyDetector::isAnomalous(correlatedFeatures cf, Point point) {
    if ((dev(point, cf.lin_reg)) > cf.threshold) {
        return true;
    }
    return false;
}


