//Eitan Brown 
//346816549
#ifndef POLYGON_H
#define POLYGON_H

#include "Point.h"
#include <iostream>
#include <cmath>
using namespace std;

class Polygon {
private:
/*
A pointer to the address of a Point array of unspecified size.
The number of points in the polygon (the size of the array).
*/
    Point* points;
    int numPoints;

public:
    //ctor
    Polygon();

    //param ctor
    Polygon(int numPoints);

    //copy ctor
    Polygon(const Polygon& poly);

    //destructor for pointer
    ~Polygon();

    //getters and setters
    //type is Point* becuase of type in private
    Point* getPoints() const;
    int getNumPoints() const;
    void setPoint(const Point& p, int ind);

    //Helper methods
    float perimeter() const;
    bool isIdentical(Polygon poly);
};

#endif // POLYGON_H
