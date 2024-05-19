#include<iostream>
#include<cmath>
#include "Point.h"
#include "Polygon.h"
using namespace std;

int main () { 
   Polygon Poly1, Poly2;



// Compare polygons and print results
if (poly1.isIdentical(poly2)) 
{
cout << "equal" << endl;
cout << round(poly1.perimeter()) << endl;
} 
else 
{
cout << "not equal" << endl;
cout << round(poly1.perimeter()) << endl;
cout << round(poly2.perimeter()) << endl;
}
return 0;
}