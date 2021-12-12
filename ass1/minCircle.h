//
// Created by aviya - 209251891 and shahar - 209129618.
//

#ifndef MINCIRCLE_H_
#define MINCIRCLE_H_

#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "anomaly_detection_util.h"

using namespace std;


// ------------ DO NOT CHANGE -----------

class Circle {
public:
    Point center;
    float radius;

    Circle(Point c, float r) : center(c), radius(r) {}
    Circle(): center(Point()), radius(0){}
};
// --------------------------------------

Circle findMinCircle(Point **points, size_t size);

//float findDistance(const Point &a, const Point &b);

bool isInside(const Circle &c, const Point &p);

//Point getCircleCenter(float bx, float by, float cx, float cy);

Circle circleFrom3(const Point &A, const Point &B, const Point &C);

Circle circleFrom2(const Point &A, const Point &B);

bool isValidCircle(const Circle& c, const vector<Point>& P);

//Circle welzl_helper(Point **P, vector<Point> R, size_t size);

Circle welzl(Point **P, size_t size);


// you can add here additional methods

#endif /* MINCIRCLE_H_ */
