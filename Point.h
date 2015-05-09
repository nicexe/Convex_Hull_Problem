//
// Created by Nicolas Tsagarides on 4/20/15.
//

#ifndef CONVEX_HULL_PROBLEM_POINT_H
#define CONVEX_HULL_PROBLEM_POINT_H

#endif //CONVEX_HULL_PROBLEM_POINT_H

class Point
{
    double x, y;

public:
    Point(double x, double y);
    Point();

    double getX() const;
    void setX(double x);

    double getY() const;
    void setY(double y);
    void setXY(double x, double y);
};