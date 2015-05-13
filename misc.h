//
// Created by Nicolas Tsagarides on 4/19/15.
//

#include <string>
#include "Point.h"

#ifndef CONVEX_HULL_PROBLEM_MISC_H
#define CONVEX_HULL_PROBLEM_MISC_H

std::string userInput();
bool is_number(const std::string& s);
bool is_double(const std::string& s);
bool compareXOfPoints(Point, Point);

#endif //CONVEX_HULL_PROBLEM_MISC_H