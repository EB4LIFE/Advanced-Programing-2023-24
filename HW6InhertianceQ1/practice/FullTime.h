#ifndef FULLTIME_H
#define FULLTIME_H

#include "Employee.h"

class FullTime : public Employee {

    float default_annualSalary;

public:
    // constructors
    FullTime(string name, int id, int seni, float annualSal); // ctor with parameters
    FullTime(); // default ctor

    // setter and getter
    void setAnnualSalary(float sal);
    float getAnnualSalary() const;

    float salary(); // method to calculate monthly salary 
    float salaryAfterBonus(); // method to update a salary according to bonus guidelines

    // friend functions
    friend istream& operator>>(istream& is, FullTime& worker); 
    friend ostream& operator<<(ostream& os, FullTime& worker);
};

#endif // FULLTIME_H

