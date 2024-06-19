#include"MA.h"
#include"PHD.h"

int main()
{
BA ba[2];
cout << "Enter details for 2 BA students\n";
for (int i = 0; i < 2; i++)
ba[i].input();
cout << "BA students entitled for milga are: \n";
for (int i = 0; i < 2; i++)
{
  if (ba[i].milga())
  ba[i].print();
//else cout << " Student not entitled for milga\n";
}

  cout << "Enter details for 2 MA students\n";
MA ma[2];
for (int i = 0; i < 2; i++)
ma[i].input();

cout << "MA students entitled for milga are: \n";
for (int i = 0; i < 2; i++)
{
if (ma[i].milga())
ma[i].print();
}
  
cout << "Enter details for 3 PHD students\n";
PHD phd[3];
for (int i = 0; i < 3; i++)
phd[i].input();
  
cout << "12PHD students entitled for milga are: \n";
for (int i = 0; i < 3; i++)
{
if (phd[i].milga())
phd[i].print();
}
return 0;
}
/* 
#include "BA.h"
#include "MA.h"
#include "PHD.h"

int main() {
    BA ba[2] = {
        BA(123, "Avraham", "Abe", 3, new int[3]{90, 100, 90}, 3),
        BA(234, "Yitzhak", "Avrahamson", 10, new int[10]{100, 100, 90, 100, 90, 100, 90, 100, 90, 100}, 10)
    };

    cout << "BA students entitled for milga are: \n";
    for (int i = 0; i < 2; i++) {
        if (ba[i].milga())
            ba[i].print();
    }

    MA ma[2] = {
        MA(345, "Yaacov", "Jacobson", 7, new int[7]{90, 100, 90, 100, 90, 100, 90}, 7, false),
        MA(456, "Sara", "Emanu", 7, new int[7]{90, 100, 90, 100, 90, 100, 90}, 7, true)
    };

    cout << "MA students entitled for milga are: \n";
    for (int i = 0; i < 2; i++) {
        if (ma[i].milga())
            ma[i].print();
    }

    PHD phd[3] = {
        PHD(567, "Rivka", "Imanu", 1, 30),
        PHD(678, "Rachel", "Jacobs", 2, 20),
        PHD(789, "Leah", "Jacobs", 2, 30)
    };

    cout << "PHD students entitled for milga are: \n";
    for (int i = 0; i < 3; i++) {
        if (phd[i].milga())
            phd[i].print();
    }

    return 0;
}
*/


