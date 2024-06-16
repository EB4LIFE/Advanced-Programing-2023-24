#pragma once
#ifndef DOCTOR_H
#define DOCTOR_H
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

class Doctor {
private:
    // No more than 24 patients plus the null
    char name[25];
    // Number of waiting patients
    int numPatients;
    // An array of patient numbers waiting in order of arrival
    int* patientNumbers;

public:
    // Assignment constructor
    // (the name, the number of patients waiting, the array of
    // waiting patients) and initializes the object accordingly
    Doctor(const char* doctorName, int numPatientsWaiting, int* patientsArray) {
        cout << "In constructor" << endl;
        // Set variable to private vars
        // Copy doctor name
        strncpy(name, doctorName, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0'; // Ensure null-terminated string
        // Set number of patients waiting
        numPatients = numPatientsWaiting;
        // Allocate memory for patient numbers
        patientNumbers = new int[numPatients];
        // Copy patient numbers
        for (int i = 0; i < numPatients; ++i) {
            patientNumbers[i] = patientsArray[i];
        }
    }

    ~Doctor() {
        cout << "In destructor" << endl;
        // Deallocate memory for patient numbers
        delete[] patientNumbers;
    }

    void print() {
        cout << name << " patients waiting:";
        for (int i = 0; i < numPatients; ++i) {
            cout << " " << patientNumbers[i];
        }
        cout << endl;
    }

    int next() {
        if (numPatients == 0) {
            cout << "No patients waiting." << endl;
            return -1; // Indicate no patients are waiting
        }

        int nextPatient = patientNumbers[0];
        // Shift patient numbers to the left
        for (int i = 0; i < numPatients - 1; ++i) {
            patientNumbers[i] = patientNumbers[i + 1];
        }
        // Decrement number of patients
        --numPatients;
        return nextPatient;
    }
};
#endif // DOCTOR_H
