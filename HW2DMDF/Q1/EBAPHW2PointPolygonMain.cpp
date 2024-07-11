//Eitan Brown 
//346816549
#include <iostream>
#include <cmath>
#include "Point.h"
#include "Polygon.h"
using namespace std;
/*
Implement a main program that inputs data pertaining to two polygons and prints their
perimeters, rounded to the closest integer (you may make use of the function round in
the library cmath), as follows:
a. If the polygons are identical the program must print “equal” and on the next
line print the perimeter (shared by both).
b. If the polygons are not identical the program must print “not equal” and on the
next lines the perimeters – each in a separate line.
The input of the polygons will consist of the output “enter number of sides:” followed
by the input of the number of points. Then the output “enter the point values:”
followed by the input of the coordinates.
The coordinate input will be of the format: (x1,y1) (x2,y2) … (xN,yN)
Where N is the number of points in the polygon and (xi,yi) are the point coordinates.
After the input of each Point it must be saved in its place in the polygon using the
method setPoint.
For any invalid input the program will print “ERROR”.
*/
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

    bool equal = Poly1.isIdentical(Poly2);
    
    if (equal) {
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
