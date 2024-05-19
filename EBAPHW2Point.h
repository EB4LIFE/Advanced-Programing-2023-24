#pragma once
#ifndef POINT_H
#define POINT_H
#<cmath>

class Point {

private:
        int OGx;
        int OGy;

public:
  //Constructor
  Point() {

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
int getX()
{
return OGx;
}
int getY()
{
return OGy;
}

float distance(Point point)
//method to calculate distance between 
//2 points (1 called and 1 passed)
{

}

};
#endif POINT_H