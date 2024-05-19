//Eitan Brown 
//346816549
#pragma once
#ifndef POINT_H
#define POINT_H
#include<cmath>
#include <iostream>
using namespace std;

class Point {

private:
        float OGx;
        float OGy;

public:
  //Constructor
  Point() {
   OGx = 0; 
   OGy = 0;
}
 //assignment ctor
 Point(float x, float y ): OGx(x), OGy(y) {
}
//copy ctor
Point (const Point& P) : OGx(P.OGx), OGy(P.OGy) {

}
 //setter methods
 void setX(int x)
{
  OGx = x;
}

void setY(int y)
{
 OGy = y;
}

//getter methods
float getX() const
{
return OGx;
}
float getY() const
{
return OGy;
}

float distance(const Point& P)
//method to calculate distance between 
//2 points (1 called and 1 passed)
{
    float distance;
    float x1 = OGx;
 .  float y1 = OGy;
    float x2 = P.OGx;
    float y2 = P.OGy;
    distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return distance;
}


};
#endif POINT_H
