//Eitan Brown 
//346816549
#include <iostream>
#include <cmath>
#include "Point.h"
#include "Polygon.h"
using namespace std;

void fillPoints(Polygon& shape, int size);

int main() {
    int sides;

    cout << "enter number of sides:" << endl;
    cin >> sides;
    Polygon Poly1(sides);
    cout << "enter the point values:" << endl;
    fillPoints(Poly1, sides);

    cout << "enter number of sides:" << endl;
    cin >> sides;
    Polygon Poly2(sides);
    cout << "enter the point values:" << endl;
    fillPoints(Poly2, sides);

    // Get a shallow copy of points for Poly1
    Point* pointsCopy = Poly1.getPoints();
    // Delete the shallow copy to trigger the destructor
    delete[] pointsCopy;

    if (Poly1.isIdentical(Poly2)) {
        cout << "equal" << endl;
        cout << "perimeter: " << round(Poly1.perimeter()) << endl;
    } else {
        cout << "not equal" << endl;
        cout << "perimeter: " << round(Poly1.perimeter()) << endl;
        cout << "perimeter: " << round(Poly2.perimeter()) << endl;
    }
    return 0;
}

void fillPoints(Polygon& shape, int size) {
    int x, y;
    char par;
    for (int i = 0; i < size; ++i) {
        cin >> par >> x >> par >> y >> par;
        Point p(x, y);
        shape.setPoint(p, i);
    }
}
