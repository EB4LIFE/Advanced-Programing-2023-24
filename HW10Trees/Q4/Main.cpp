#include <iostream>
using namespace std;
#include "SearchTree.h"
#include "Student.h"

int main() {
    SearchTree<Student> sList;
    Student tmp;
    char choice = 'i';

    while (choice != 'e') {
        cout << "enter a-e\n";
        cin >> choice;
        switch (choice) {
        case 'a':
            cout << "enter a student\n";
            cin >> tmp;
            sList.add(tmp);
            break;
        case 'b':
            cout << "enter a student\n";
            cin >> tmp;
            sList.remove(tmp);
            break;
        case 'c':
            cout << "enter a student\n";
            cin >> tmp;
            if (sList.search(tmp))
                cout << "exist\n";
            else
                cout << "not exist\n";
            break;
        case 'd':
            sList.inOrder();
            break;
        case 'e':
            break;
        default:
            cout << "error\n";
            break;
        }
    }
    return 0;
}

