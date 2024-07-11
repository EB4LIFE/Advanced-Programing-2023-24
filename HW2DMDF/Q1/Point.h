//Eitan Brown 
//346816549
#pragma once
#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
/* x – a floating point number for the x coordinate
y – a floating point number for the y coordinate */
    float x;
    float y;

public:
    //ctor
    Point();

    //param ctor
    Point(float x, float y);

    //copy ctor
    Point(const Point& p);

    //getters and setters
    float getX() const;
    float getY() const;
    void setX(float x);
    void setY(float y);

    //helper method
    float distance(const Point& p) const;
};

#endif // POINT_H
