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
    Doctor(const char* doctorName, int numPatientsWaiting, int* patientsArray);

    // Destructor
    ~Doctor();

    // Function to print doctor details
    void print();

    // Function to get the next patient number
    int next();
};

#endif // DOCTOR_H
