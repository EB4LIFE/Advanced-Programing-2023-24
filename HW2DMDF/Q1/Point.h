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
    float x;
    float y;

public:
    Point();
    Point(float x, float y);
    Point(const Point& p);
    float getX() const;
    float getY() const;
    void setX(float x);
    void setY(float y);
    float distance(const Point& p) const;
};

#endif // POINT_H
