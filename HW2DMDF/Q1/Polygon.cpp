#include "Polygon.h"

// Default constructor: A default constructor that receives no arguments and initializes the
//number of points to 0 and the array to nullptr.
Polygon::Polygon() : points(nullptr), numPoints(0) {
    cout << "in default constructor" << endl;
}

// Assignment constructor: An assignment constructor that receives the number of points as an
//argument and uses dynamic allocation to initialize the fields
//accordingly. The points in the polygon are to all be initialized to zeros
//using the automatic call to their default constructor.
Polygon::Polygon(int numPoints) : numPoints(numPoints) {
    cout << "in one parameter constructor" << endl;
    points = new Point[numPoints];
}

// Copy constructor: A copy constructor that receives a Polygon instance and deep-copies its
//points into the instance being constructed. This means a new dynamic
//allocation of the same size is required.
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

// Method to set a point at a specific index in the polygon:
/*The method sets the
Point at the given index in the array to the coordinates of the Point received.
This occurs even if the Point at the given index is already set to other
coordinates.*/
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

// Method to check if two polygons are identical:
/*that receives a Polygon and returns true if it is the same
as the calling Polygon. Sameness is defined as having the same Points and the
same edges. Notice that the order of the Points is not necessariy the same, for
instance: (0,0) (1,1) (2,0) is the same as (1,1) (2,0) (0,0) even though the order is
different.
*/
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
