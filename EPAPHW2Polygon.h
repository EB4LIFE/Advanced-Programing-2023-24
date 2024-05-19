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
//private by default 
//points a pointer of type point
//an int of number of pointss in the polygon
    Point* points;
    int numPoints;

public:
    // Default constructor
    //setting the ptr to null and num of poonts to zero by default
    Polygon() : points(nullptr), numPoints(0) {
        cout << "in default constructor" << endl;
    }

    // Assignment constructor 
    //same as in point, making a num points (user) and setting our og numpoint to value of whatever user waas
    Polygon(int numPoints) : numPoints(numPoints) {
        cout << "in one parameter constructor" << endl;
        points = new Point[numPoints];
    }

    // Copy constructor  - same as the assignment just copy thru cbr (call by refrence &)
    Polygon(const Polygon& poly) : numPoints(poly.numPoints) {
        cout << "in copy constructor" << endl;
        //using dynamic allocation to 'copy over the points'
        points = new Point[numPoints];
        for (int i = 0; i < numPoints; ++i) {
            points[i] = poly.points[i];
        }
    }

    // Destructor - to delete any copied info thru dynamic allocation
    ~Polygon() {
        cout << "in destructor" << endl;
        delete[] points;
    }

    // Getter for points array
    //this function gets point thru normal DMA and for loopp tp copy values
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

    // Method to set a point at a specific index in the poly
    void setPoint(const Point& p, int ind) {
        if (ind >= 0 && ind < numPoints) {
            points[ind] = p;
        } else {
            //error check
            cout << "ERROR" << endl;
        }
    }
    
    // Method to compute the perimeter of the polygon
    float perimeter() const {
        float perim = 0.0;
        for (int i = 0; i < numPoints; ++i) {
            perim += points[i].distance(points[(i + 1) % numPoints]);
            //This accesses the next point in the points array. The expression (i + 1) % numPoints uses the modulo operation to ensure that 
            //if i is the last index (i equals numPoints - 1), it wraps around to the first index to get a full shape
        }
        return perim;
    }

    // Method to check if two polygons are identical
    bool isIdentical(Polygon poly) {
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
