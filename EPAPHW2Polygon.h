#pragma once
#ifndef POLYGON_H
#define POLYGON_H
#include "Point.h"
#include <iostream>
using namespace std;

class Polygon {

private: 
Point *pts;
int size;

public:
//Default - set to zero
Polygon () {
 size = 0;
 pts = Nullptr;
 cout << “in default constructor” << endl;
}

//Assignment 
Polygon (int size) : size(size) {
pts = new Point[size];
cout << "in one parameter constructor" << endl;
}

//Copy ctor 
Polygon(const Polygon &other) : size(other.size) {

Point pts = new Point[size];
//using for loop to copy
for(int i = 0; i < size; ++i)
{
 pts[i] = other.pts[i];
}
 cout << "in copy constructor" << endl;
}

//destructor ctor for tracking out the trash after the main
~Polygon () {
   delete[] pts;
 cout << "in destructor" << endl;
}

// Setter for a specific point
void setPoint(const Point &p, int index) {
        if (index >= 0 && index < size) {
            pts[index] = p;
        }
    }

// Getters
//for points array aka the deep copy using dynamic allocation 
    Point* getPoints() const {
        Point *deepcopy = new Point[size];
        for (int i = 0; i < size; ++i) {
            deepcopy[i] = points[i];
        }
        return deepcopy;
    }

// Perimeter method
float perimeter() const {
if (size < 2) {
return 0; 
//don't have 2 consec pts
}
//in a case where we do we must evaluate method is to sum up the distances 
//between every two consecutive Points, assuming that the Points in the array 
//are ordered according to the edges of the polygon
float per = 0;
for (int i = 0; i < size; ++i) 
{
perim += pts[i].distance(pts[(i + 1) % size]);
}
return perim;
} //end of method

//isIdentical method
bool isIdentical(const Polygon &other) const {
if (size != other.size) 
{
return false; 
//obviously because they are not the same 
//if not the same size
}
//for loop to traverse polygon and copy poly to see if the points are the same
//since orde of points don't matter this way, at place 1: it will check all point 
//in j to see if they match and so on 
for (int i = 0; i < size; ++i) 
{
bool found = false;
for (int j = 0; j < size; ++j) 
{
if (pts[i].getX() == other.pts[j].getX() && points[i].getY() == other.pts[j].getY()) {
found = true;
break;
}
}
if (!found) return false;
}
return true;
}

}; 
#endif POLYGON_H
