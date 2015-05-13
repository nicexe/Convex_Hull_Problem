//
// Created by Nicolas Tsagarides on 4/20/15.
//

#include "heapSort.h"
#include "grahamScan.h"
#include <algorithm>
#include <limits>

double maxDouble = std::numeric_limits<double>::max();

void heapSort()
{

}

unsigned long long leftChildIndex(unsigned long long int i)
{
    return 2 * i;
}

unsigned long long rightChildIndex(unsigned long long int i)
{
    return (2 * i + 1);
}

unsigned long long parentIndex(unsigned long long int i)
{
    return i / 2;
}

Point leftChild(unsigned long long int i)
{
    return grahamScanPointSet.at(leftChildIndex(i));
}

Point rightChild(unsigned long long int i)
{
    return grahamScanPointSet.at(rightChildIndex(i));
}

Point parent(unsigned long long int i)
{
    return grahamScanPointSet.at(parentIndex(i));
}

void insert(Point point)
{
    grahamScanPointSet.push_back(point);

//    unsigned long long int newIndex = grahamScanPointSet.size()-1;
//
//    while (!inPlace(newIndex, true))    // while the newly added element is not in place
//    {
//        newIndex /= 2;
//    }

    for (unsigned long long int newIndex = grahamScanPointSet.size(); !inPlace(newIndex, true); newIndex /= 2);
}

void deleteMin()
{
    std::swap(grahamScanPointSet.at(0), grahamScanPointSet.at(grahamScanPointSet.size()-1));    // swap the last with the first element
    grahamScanPointSet.pop_back();  // delete the last element

    unsigned long long int newRoot = 1;

    while (!inPlace(newRoot, false))    // while the new root element is not in place
    {
        // TODO figure out which child to swap with
    }
}

bool inPlace(unsigned long long int i, bool inserting)  // returns true if the element is in place
{
    if (inserting)
    {
        if (i == 1) // if the element is the root
        {
            return true;
        }

        double currentX = grahamScanPointSet.at(i).getX();
        double parentX = grahamScanPointSet.at(parentIndex(i)).getX();

        if (currentX > parentX) // if element at place is bigger than it's parent
        {
            std::swap(grahamScanPointSet.at(i), grahamScanPointSet.at(parentIndex(i))); // swap element with it's parent
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        if ( (leftChildIndex(i) > grahamScanPointSet.size()) && (rightChildIndex(i) > grahamScanPointSet.size()) )  // if the element doesn't have any children (is a leaf)
        {
            return true;
        }

        double currentX = grahamScanPointSet.at(i).getX();
        double leftChildX = leftChild(i).getX();
        double rightChildX;
        if (rightChildIndex(i) > grahamScanPointSet.size()) // if the element doesn't have a right child
        {
            rightChildX = maxDouble;
        }
        else
        {
            rightChildX = rightChild(i).getX();
        }

        if ( (leftChildX < rightChildX) && (leftChildX < currentX) )   // left child is the smallest child and is also smaller than current element
        {
            std::swap(grahamScanPointSet.at(i), grahamScanPointSet.at(leftChildIndex(i)));  // swap element with it's left child
            return false;
        }
        else if ( (leftChildX > rightChildX) && (rightChildX < currentX) ) // right child is the smallest child and is also smaller than current element
        {
            std::swap(grahamScanPointSet.at(i), grahamScanPointSet.at(rightChildIndex(i))); // swap element with it's right child
            return false;
        }
        else if ( ( (currentX > leftChildX) && (currentX > rightChildX) ) || ( (leftChild==rightChild) && (leftChildX==maxDouble) ) || ( (currentX == leftChildX) && (currentX == rightChildX) ) )
        // if its children are smaller or if it doesn't have children or if the element is equal to it's left and right child
        {
            return true;
        }

        return false;
    }
}
