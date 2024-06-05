#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <cstring>
using namespace std;

class Employee {
	//private	
private:
	int workerId;
	char workername[21];
	float Hourwages;
	int hoursworked;
	float collectedmoney;
public:
	//constructor
	Employee() {
		cout << "print: in constructor" << endl;
		workerId = 00000;
		workername[0] = '\0';
		Hourwages = 0.0;
		hoursworked = 0;
		collectedmoney = 0.0;
	}
    //THE SETTERS AND GETTERS
	
	//setID
	void setWorkerId(int id) {
		workerId = id;
	}
	//getID
	int getWorkerId() const {
		return workerId;
	}
	//setName - look at this again
	void setName(const char* empName) {
		strncpy(workername, empName, 20);
		workername[20] = '\0';
	}
	//getName
	const char* getName() const {
		return workername;
	}
	//setWages
	void sethourlywages(float wages) {
		Hourwages = wages;
	}
	//getwages
	float gethourlywages() const {
		return Hourwages;
	}
	//sethourworked
	void setHoursWorked(int hours) {
		hoursworked = hours;
	}
	//gethoursworked
	int getHoursWorked() const {
		return hoursworked;
	}
	//set totalcollected funds
	void setdonationscollected(float donate) {
		collectedmoney = donate;
	}
	//get totalcollected funds
	float getdonationscollected() const {
		return collectedmoney;
	}
	float calcsalary() const {
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
};
#endif
