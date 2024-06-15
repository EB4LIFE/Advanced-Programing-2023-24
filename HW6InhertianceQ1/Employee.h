#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
using namespace std;

class Employee {

protected:
    string default_name;
    int default_id;
    int default_seniority;
    float default_pay;

public:
    // constructor
    Employee(string name = "", int id = 0, int seniority = 0, float pay = 0);

    // setters and getters (to be used by the inheriting classes)
    void setName(string name);
    void setId(int id);
    void setSeniority(int seniority);
    void setPay(float pay);
    string getName() const;
    int getId() const;
    int getSeniority() const;
    float getPay() const;

    float salaryAfterBonus(); 

    // friend functions
    friend istream& operator>>(istream& is, Employee& worker); 
    friend ostream& operator<<(ostream& os, const Employee& worker); 
};

#endif //EMPLOYEE_H

