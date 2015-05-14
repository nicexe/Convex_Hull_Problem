//
// Created by Nicolas Tsagarides on 4/12/15.
//

#include "grahamScan.h"

std::vector<Point> upperHull;
std::vector<Point> lowerHull;

double slope(Point point1, Point point2)
{
    // slope = (y2-y1) / (x2-x1)
    return ( (point2.getY()-point1.getY()) / (point2.getX()-point1.getX()) );
}


bool rightTurn(Point point1, Point point2, Point point3)
{
    double slope12 = slope(point1, point2);
    double slope23 = slope(point2, point3);

    return (slope12>slope23);
}

void fillUpperHull()
{
    upperHull.clear();

    upperHull.push_back(grahamScanPointSet.at(0));
    upperHull.push_back(grahamScanPointSet.at(1));

    for (unsigned long long int i = 2; i < grahamScanPointSet.size(); ++i)
    {
        upperHull.push_back(grahamScanPointSet.at(i));

        while ( (upperHull.size()>2) && (!rightTurn(upperHull.at(upperHull.size()-3), upperHull.at(upperHull.size()-2), upperHull.at(upperHull.size()-1))) )
        {
            Point temp = upperHull.back();  // saving the last element
            upperHull.pop_back();           // popping the last element
            upperHull.pop_back();           // popping the element before the last
            upperHull.push_back(temp);      // putting the last element back
        }
    }
}

void fillLowerHull()
{
    lowerHull.clear();

    lowerHull.push_back(grahamScanPointSet.at(grahamScanPointSet.size()-1));
    lowerHull.push_back(grahamScanPointSet.at(grahamScanPointSet.size()-2));

//    for (unsigned long long int i = grahamScanPointSet.size()-3; i >= 0; --i)
    for (std::vector<Point>::reverse_iterator rit = grahamScanPointSet.rbegin()-2; rit!=grahamScanPointSet.rend(); ++rit)
    {
        lowerHull.push_back(*rit);

        while ( (lowerHull.size()>2) && (!rightTurn(lowerHull.at(lowerHull.size()-3), lowerHull.at(lowerHull.size()-2), lowerHull.at(lowerHull.size()-1))) )
        {
            Point temp = lowerHull.back();
            lowerHull.pop_back();
            lowerHull.pop_back();
            lowerHull.push_back(temp);
        }
    }

}

std::vector<Point> grahamScanConvexHull()
{
    fillUpperHull();
    fillLowerHull();

    if (lowerHull.size()>2)
    {
        for (unsigned long long int i = 1; i < lowerHull.size()-1; ++i)
        {
            upperHull.push_back(lowerHull.at(i));
        }
    }

    return upperHull;
}
