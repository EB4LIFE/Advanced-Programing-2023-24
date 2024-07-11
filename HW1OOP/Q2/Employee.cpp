#include "Employee.h"

//Constructor - set to default
Employee::Employee() {
    cout << "print: in constructor" << endl;
    workerId = 00000;
    workername[0] = '\0';
    Hourwages = 0.0;
    hoursworked = 0;
    collectedmoney = 0.0;
}

// Set worker ID
void Employee::setWorkerId(int id) {
    workerId = id;
}

// Get worker ID
int Employee::getWorkerId() const {
    return workerId;
}

// Set worker name
void Employee::setName(const char* empName) {
    strncpy(workername, empName, 20);
    workername[20] = '\0';
}

// Get worker name
const char* Employee::getName() const {
    return workername;
}

// Set hourly wages
void Employee::sethourlywages(float wages) {
    Hourwages = wages;
}

// Get hourly wages
float Employee::gethourlywages() const {
    return Hourwages;
}

// Set hours worked
void Employee::setHoursWorked(int hours) {
    hoursworked = hours;
}

// Get hours worked
int Employee::getHoursWorked() const {
    return hoursworked;
}

// Set collected money
void Employee::setdonationscollected(float donate) {
    collectedmoney = donate;
}

// Get collected money
float Employee::getdonationscollected() const {
    return collectedmoney;
}

// Calculate salary based on example given: Number of hours * Hourly wages + Percent of donations collected
/*Donations Collected Percent Added to Salary
Up to 1000 Shekels (inclusive) 10%
Between 1000 Shekels and 2000 Shekels (inclusive) 15%
Between 2000 Shekels and 4000 Shekels (inclusive) 20%
Between 4000 Shekels and 5000 Shekels (inclusive) 30%
More than 5000 Shekels. 40%
*/
float Employee::calcsalary() const {
    float bonus = 0.0;

    if (collectedmoney <= 1000) {
        bonus = 0.1 * collectedmoney;
    } else if (collectedmoney <= 2000) {
        bonus = 0.1 * 1000 + 0.15 * (collectedmoney - 1000);
    } else if (collectedmoney <= 4000) {
        bonus = 0.1 * 1000 + 0.15 * 1000 + 0.2 * (collectedmoney - 2000);
    } else if (collectedmoney <= 5000) {
        bonus = 0.1 * 1000 + 0.15 * 1000 + 0.2 * 2000 + 0.3 * (collectedmoney - 4000);
    } else {
        bonus = 0.1 * 1000 + 0.15 * 1000 + 0.2 * 2000 + 0.3 * 1000 + 0.4 * (collectedmoney - 5000);
    }

    return hoursworked * Hourwages + bonus;
}
