#include "Polygon.h"

// Default constructor
Polygon::Polygon() : points(nullptr), numPoints(0) {
    cout << "in default constructor" << endl;
}

// Assignment constructor
Polygon::Polygon(int numPoints) : numPoints(numPoints) {
    cout << "in one parameter constructor" << endl;
    points = new Point[numPoints];
}

// Copy constructor
Polygon::Polygon(const Polygon& poly) : numPoints(poly.numPoints) {
    cout << "in copy constructor" << endl;
    points = new Point[numPoints];
    for (int i = 0; i < numPoints; ++i) {
        points[i] = poly.points[i];
    }
}

// Destructor
Polygon::~Polygon() {
    cout << "in destructor" << endl;
    delete[] points;
}

// Getter for points array
Point* Polygon::getPoints() const {
    Point* newPoints = new Point[numPoints];
    for (int i = 0; i < numPoints; ++i) {
        newPoints[i] = points[i];
    }
    return newPoints;
}

// Getter for number of points
int Polygon::getNumPoints() const {
    return numPoints;
}

// Method to set a point at a specific index in the polygon
void Polygon::setPoint(const Point& p, int ind) {
    if (ind >= 0 && ind < numPoints) {
        points[ind] = p;
    } else {
        cout << "ERROR" << endl;
    }
}

// Method to compute the perimeter of the polygon
float Polygon::perimeter() const {
    float perim = 0.0;
    for (int i = 0; i < numPoints; ++i) {
        perim += points[i].distance(points[(i + 1) % numPoints]);
    }
    return perim;
}

// Method to check if two polygons are identical
bool Polygon::isIdentical(Polygon poly) {
    if (numPoints != poly.numPoints) {
        return false;
    }

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
