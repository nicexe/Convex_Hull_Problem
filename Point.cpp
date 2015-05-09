//
// Created by Nicolas Tsagarides on 4/20/15.
//

#include "Point.h"

Point::Point(double newX, double newY)
{
    x = newX;
    y = newY;
}

Point::Point()
{
    x = 0.0;
    y = 0.0;
}

double Point::getX() const
{
    return x;
}

void Point::setX(double newX)
{
    x = newX;
}

double Point::getY() const
{
    return y;
}

void Point::setY(double newY)
{
    y = newY;
}

void Point::setXY(double newX, double newY)
{
    x=newX;
    y=newY;
}