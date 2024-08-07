#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <cstring>
using namespace std;

class Employee {
//private vars 
private:
    int workerId;
    char workername[21];
    float Hourwages;
    int hoursworked;
    float collectedmoney;

public:
    //ctor
    Employee();

    //setters and getters
    void setWorkerId(int id);
    int getWorkerId() const;
    void setName(const char* empName);
    const char* getName() const;
    void sethourlywages(float wages);
    float gethourlywages() const;
    void setHoursWorked(int hours);
    int getHoursWorked() const;
    void setdonationscollected(float donate);
    float getdonationscollected() const;

    //helper method
    float calcsalary() const;
};

#endif // EMPLOYEE_H
