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
    Point* points;
    int numPoints;

public:
    Polygon();
    Polygon(int numPoints);
    Polygon(const Polygon& poly);
    ~Polygon();
    Point* getPoints() const;
    int getNumPoints() const;
    void setPoint(const Point& p, int ind);
    float perimeter() const;
    bool isIdentical(Polygon poly);
};

#endif // POLYGON_H
