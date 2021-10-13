//
// Created by aviya and shahar on 13/10/2021.
//

#include <cmath>
#include "anomaly_detection_util.h"

// returns the avg of the values in the array
float average(float *x, int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += x[i];
    }
    float average = sum / ((float) size);
    return average;
}

// returns the variance of X and Y
float var(float *x, int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += pow(x[i], x[i]);
    }
    float num = sum / (float(size));
    float avg = average(x, size);
    float var = num - pow(avg, avg);
    return var;
}

// returns the covariance of X and Y
float cov(float *x, float *y, int size) {
    float multiply[size];
    for (int i = 0; i < size; i++) {
        multiply[i] = x[i] * y[i];
    }
    float multAverage = average(multiply, size);
    float numAverage = average(x, size) * average(y, size);
    float cov = multAverage - numAverage;
    return cov;
}

// returns the Pearson correlation coefficient of X and Y
float pearson(float *x, float *y, int size) {
    float sqrtX = sqrtf(var(x, size));
    float sqrtY = sqrtf(var(y, size));
    float mul = sqrtX * sqrtY;
    float pearson = cov(x, y, size) / mul;
    return pearson;
}

// calculate the slope of the line
float slope(float *x, float *y, int size) {
    float a = cov(x, y, size) / var(x, size);
    return a;
}

// performs a linear regression and return s the line equation
Line linear_reg(Point **points, int size) {
    float arrayX[size];
    float arrayY[size];
    for (int i = 0; i < size; ++i) {
        arrayX[i] = points[i]->x;
        arrayY[i] = points[i]->y;
    }
    float avgX = average(arrayX, size);
    float avgY = average(arrayY, size);
    float a = slope(arrayX, arrayY, size);
    float b = avgY - a * avgX;

    return {a, b};
}

// returns the deviation between point p and the line equation of the points
float dev(Point p, Point **points, int size) {
    Line line = linear_reg(points, size);
    return dev(p, line);
}

// returns the deviation between point p and the line
float dev(Point p, Line l) {
    float y = p.y;
    float valOfLine = l.a * p.x + l.b;
    return abs(valOfLine - y);
}



