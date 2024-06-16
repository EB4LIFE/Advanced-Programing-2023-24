#include <iostream>
#include "Doctor.h"
using namespace std;


int main() {
    int size;
    cin >> size;
    int* patients = new int[size];
    for (int i = 0; i < size; i++)
        patients[i] = i + 100;
    char drName[25];
    cin >> drName;
    Doctor doctor(drName, size, patients);
    doctor.print();
    cout << "next patient:" << doctor.next();
    cout << endl;
    doctor.print();
    return 0;
}
