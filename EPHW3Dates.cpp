//Eitan Brown 346816549
//Operator overload
#include <iostream>
#include "MyDate.h"  
using namespace std;

int main () {
    MyDate d1;
    char ch;
    int d, m, y;

    cout << "Enter a date" << endl;
    cin >> d >> ch >> m >> ch >> y;
    d1.setDate(d, m, y);
    d1.print();
    
    //will use switch such as previous example
    while (true) {
        int code;
        cout << "Enter a code" << endl;
        cin >> code;
        
        if (code == 0) break;

        switch (code) {
            case 1:
                cout << "Enter a date" << endl;
                cin >> d >> ch >> m >> ch >> y;
                d1.setDate(d, m, y);
                d1.print();
                break;
            case 2:
                {
                    MyDate result = ++d1;
                    result.print();
                    d1.print();
                }
                break;
            case 3:
                {
                    MyDate result = d1++;
                    result.print();
                    d1.print();
                }
                break;
            case 4:
                {
                    cout << "Enter a date" << endl;
                    cin >> d >> ch >> m >> ch >> y;
                    MyDate d2(d, m, y);
                    d1 = d2;
                    d1.print();
                }
                break;
            case 5:
                {
                    cout << "Enter a date" << endl;
                    cin >> d >> ch >> m >> ch >> y;
                    MyDate d2(d, m, y);
                    cout << (d1 < d2 ? "true" : "false") << endl;
                }
                break;
            case 6:
                {
                    cout << "Enter a date" << endl;
                    cin >> d >> ch >> m >> ch >> y;
                    MyDate d2(d, m, y);
                    cout << (d1 > d2 ? "true" : "false") << endl;
                }
                break;
            case 7:
                {
                    cout << "Enter a date" << endl;
                    cin >> d >> ch >> m >> ch >> y;
                    MyDate d2(d, m, y);
                    cout << (d1 == d2 ? "true" : "false") << endl;
                }
                break;
            default:
                cout << "Invalid code" << endl;
                break;
        }
    }

    return 0;
}
    
    
    
    
    
