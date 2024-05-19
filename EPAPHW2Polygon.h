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
    // Default constructor
    Polygon() : points(nullptr), numPoints(0) {
        cout << "in default constructor" << endl;
    }

    // Assignment constructor
    Polygon(int numPoints) : numPoints(numPoints) {
        cout << "in one parameter constructor" << endl;
        points = new Point[numPoints];
    }

    // Copy constructor
    Polygon(const Polygon& poly) : numPoints(poly.numPoints) {
        cout << "in copy constructor" << endl;
        points = new Point[numPoints];
        for (int i = 0; i < numPoints; ++i) {
            points[i] = poly.points[i];
        }
    }

    // Destructor
    ~Polygon() {
        cout << "in destructor" << endl;
        delete[] points;
    }

    // Getter for points array
    Point* getPoints() const {
        Point* newPoints = new Point[numPoints];
        for (int i = 0; i < numPoints; ++i) {
            newPoints[i] = points[i];
        }
        return newPoints;
    }

    // Getter for number of points
    int getNumPoints() const {
        return numPoints;
    }

    // Method to set a point at a specific index
    void setPoint(const Point& p, int index) {
        if (index >= 0 && index < numPoints) {
            points[index] = p;
        } else {
            cout << "ERROR" << endl;
        }
    }

    // Method to compute the perimeter of the polygon
    float perimeter() const {
        float perim = 0.0;
        for (int i = 0; i < numPoints; ++i) {
            perim += points[i].distance(points[(i + 1) % numPoints]);
        }
        return perim;
    }

    // Method to check if two polygons are identical
    bool isIdentical(const Polygon& poly) const {
        if (numPoints != poly.numPoints) {
            return false;
        }
        // Checking if points are the same regardless of order
        bool* matched = new bool[numPoints]();
        for (int i = 0; i < numPoints; ++i) {
            bool found = false;
            for (int j = 0; j < numPoints; ++j) {
                if (!matched[j] && points[i].getX() == poly.points[j].getX() && points[i].getY() == poly.points[j].getY()) {
                    matched[j] = true;
                    found = true;
                    break;
                }
            }
            if (!found) {
                delete[] matched;
                return false;
            }
        }
        delete[] matched;
        return true;
    }
};

#endif
