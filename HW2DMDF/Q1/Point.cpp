#include "Point.h"

// Default constructor
Point::Point() : x(0), y(0) {}

// Assignment constructor
Point::Point(float x, float y) : x(x), y(y) {}

// Copy constructor
Point::Point(const Point& p) : x(p.x), y(p.y) {}

// Getter for x
float Point::getX() const {
    return x;
}

// Getter for y
float Point::getY() const {
    return y;
}

// Setter for x
void Point::setX(float x) {
    this->x = x;
}

// Setter for y
void Point::setY(float y) {
    this->y = y;
}

// Method to calculate distance between two points
float Point::distance(const Point& p) const {
    return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}
