//
// Created by Nicolas Tsagarides on 4/20/15.
//

#include <vector>
#include "Point.h"

#ifndef CONVEX_HULL_PROBLEM_HEAPSORT_H
#define CONVEX_HULL_PROBLEM_HEAPSORT_H

void heapSort();
unsigned long long int leftChildIndex(unsigned long long int);
unsigned long long int rightChildIndex(unsigned long long int);
unsigned long long int parentIndex(unsigned long long int);
Point leftChild(unsigned long long int);
Point rightChild(unsigned long long int);
Point parent(unsigned long long int);
void insert(Point);
void deleteMin();
bool inPlace(unsigned long long int, bool);

#endif //CONVEX_HULL_PROBLEM_HEAPSORT_H