//
// Created by aviya - 209251891 and shahar - 209129618.
//

#include "minCircle.h"
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
// Defining infinity
const double INF = 1e18;

Circle findMinCircle(Point **points, size_t size){
    return welzl(points, size);
}


Circle minCircleTrivial(vector<Point> &P, size_t size) {
    assert(P.size() <= 3);
    // if there is no points
    if (P.empty()) {
        return { { 0, 0 }, 0 };
    }
     else if (size == 1) {
        return { P[0], 0 };
    } else if (size == 2) {
        return circleFrom2(P[0], P[1]);
    }

    // To check if MEC can be determined
    // by 2 points only
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {

            Circle c = circleFrom2(P[i], P[j]);
            if (isValidCircle(c, P))
                return c;

        }
    }
    return circleFrom3(P[0], P[1], P[2]);
}

// Function to return the euclidean distance
// between two points
float findDistance(const Point &a, const Point &b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Function to check whether a point lies inside
// or on the boundaries of the circle
bool isInside(const Circle &c, const Point &p) {
    return findDistance(c.center, p) <= c.radius;
}

// The following two functions are used
// To find the equation of the circle when
// three points are given.

// Helper method to get a circle defined by 3 points
Point getCircleCenter(float bx, float by, float cx, float cy) {
    float B = bx * bx + by * by;
    float C = cx * cx + cy * cy;
    float D = bx * cy - by * cx;
    return {(cy * B - by * C) / (2 * D), (bx * C - cx * B) / (2 * D)};
}

// Function to return a unique circle that
// intersects three points
Circle circleFrom3(const Point &A, const Point &B, const Point &C) {
    Point I = getCircleCenter(B.x - A.x, B.y - A.y,
                              C.x - A.x, C.y - A.y);
    I.x += A.x;
    I.y += A.y;
    return {I, findDistance(I, A)};
}

// Function to return the smallest circle
// that intersects 2 points
Circle circleFrom2(const Point &A, const Point &B) {
    // Set the center to be the midpoint of A and B
    Point C = {(A.x + B.x) / (float)2.0, (A.y + B.y) / (float)2.0};

    // Set the radius to be half the distance AB
    return {C, findDistance(A, B) / (float)2.0};
}

// Function to check whether a circle
// encloses the given points
bool isValidCircle(const Circle& c, const vector<Point>& P)
{

    // Iterating through all the points
    // to check  whether the points
    // lie inside the circle or not
    for (const Point& p : P)
        if (!isInside(c, p))
            return false;
    return true;
}


// Returns the MEC using Welzl's algorithm
// Takes a set of input points P and a set R
// points on the circle boundary.
// n represents the number of points in P
// that are not yet processed.
Circle welzl_helper(Point **P, vector<Point> R, size_t size) {
    // Base case when all points processed or |R| = 3
    if (size == 0 || R.size() == 3) {
        //min_circle_trivial
        return minCircleTrivial(R, R.size());
    }

    // Pick a random point randomly
    int idx = rand() % size;
    Point p = *P[idx];

    // Put the picked point at the end of P
    // since it's more efficient than
    // deleting from the middle of the vector
    swap(P[idx], P[size - 1]);

    // Get the MEC circle d from the
    // set of points P - {p}
    Circle d = welzl_helper(P, R, size - 1);

    // If d contains p, return d
    if (isInside(d, p)) {
        return d;
    }

    // Otherwise, must be on the boundary of the MEC
    R.push_back(p);

    // Return the MEC for P - {p} and R U {p}
    return welzl_helper(P, R, size - 1);
}

Circle welzl(Point **P, size_t size) {
    Point **P_copy = P;
    return welzl_helper(P_copy, {}, size);
}