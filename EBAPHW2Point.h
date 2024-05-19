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
//private by default
//x and y values for the coord in polygon 
    float x;
    float y;

public:
    // Default constructor
    // set x and y to default 0
    Point() : x(0), y(0) {
    }

    // Assignment constructor 
    //setting x and y to user x and y will be 
    //better implemented via setter and getter
    Point(float x, float y) : x(x), y(y) {
    }
    // Copy constructor - copy of assignment so it can help for 
    //a second object of same value
    Point(const Point& p) : x(p.x), y(p.y) {
    }

    // Getter for x
    float getX() const {
        return x;
    }

    // Getter for y
    float getY() const {
        return y;
    }

    // Setter for x
    void setX(float x) {
        //this is used to define the og x variable to the one brough in the assignment ctor
        this->x = x;
    }

    // Setter for y
    void setY(float y) {
         //this is used to define the og y variable to the one brough in the assignment ctor
        this->y = y;
    }
    // Method to calculate distance between two points aka simple distance formula
    float distance(const Point& p) const {
        //sqaure root of x2 - x1 squared + y2 - y1 sqaured
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }
};

#endif
