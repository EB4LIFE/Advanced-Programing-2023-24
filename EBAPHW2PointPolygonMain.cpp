//Eitan Brown 
//346816549
#include<iostream>
#include<cmath>
#include "Point.h"
#include "Polygon.h"
using namespace std;

//will be intliazied below but basically will get the point for the shape of said polygon 
void fillPoints(Polygon& shape, int size);

int main () { 
//sides of said polygon
int sides;

cout << "enter number of sides:" << endl;
cin >> sides;
//putting it in the assignment ctor
Polygon Poly1(sides);
//now getting the points for polygon 1
cout << "enter the point values:" << endl;
fillPoints(Poly1, sides);

//now for the second shape
cout << "enter number of sides:" << endl;
cin >> sides;
//putting it in the assignment ctor
Polygon Poly2(sides);
//get the point for polygon 2
cout << "enter the point values:" << endl;
fillPoints(Poly2, sides);
   
// Compare polygons and print results
if (Poly1.isIdentical(Poly2)) 
{
cout << "equal" << endl;
cout << "perimeter: " << round(Poly1.perimeter()) << endl;
} 
else 
{
cout << "not equal" << endl;
cout << "perimeter: "<< round(Poly1.perimeter()) << endl;
cout << "perimeter: "<< round(Poly2.perimeter()) << endl;
}
return 0;
}

void fillPoints(Polygon& shape, int size) {
   int x;
   int y;
   char par;
for(int i = 0; i < size; ++i)
{
   //put the x and y and coordinate format
   cin >> par >> x >> par >> y >> par;
   shape.getPoints()->setX(x);
   shape.getPoints()->setY(y);
}
}
