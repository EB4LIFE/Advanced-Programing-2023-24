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
    // Default constructor
    Point() : x(0), y(0) {}

    // Assignment constructor
    Point(float x, float y) : x(x), y(y) {}

    // Copy constructor
    Point(const Point& p) : x(p.x), y(p.y) {}

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
        this->x = x;
    }

    // Setter for y
    void setY(float y) {
        this->y = y;
    }

    // Method to calculate distance between two points
    float distance(const Point& p) const {
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }
};
#endif
