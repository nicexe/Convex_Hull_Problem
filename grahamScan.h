//
// Created by Nicolas Tsagarides on 4/12/15.
//

#include <vector>
#include "Point.h"

#ifndef CONVEX_HULL_PROBLEM_GRAHAMSCAN_H
#define CONVEX_HULL_PROBLEM_GRAHAMSCAN_H

extern std::vector <Point> grahamScanPointSet;
double slope(Point, Point);
bool rightTurn(Point, Point, Point);
void fillUpperHull();
void fillLowerHull();
std::vector <Point> grahamScanConvexHull();

#endif //CONVEX_HULL_PROBLEM_GRAHAMSCAN_H
