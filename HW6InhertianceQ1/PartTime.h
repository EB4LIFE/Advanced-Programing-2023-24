
#ifndef PARTTIME_H
#define PARTTIME_H

#include "Employee.h"

class PartTime : public Employee {
    int default_hoursWorked;
    float default_rateHour;

public:
    // constructors
    PartTime(); // default ctor
    PartTime(string name, int id, int seni, int hours, float rate); // ctor with parameters

    // setters and getters
    void setHoursWorked(int hours);
    void setRate(float rate);
    int getHoursWorked() const;
    float getRate() const;

    float salary(); // method to calculate monthly salary 
    float salaryAfterBonus(); // method to update a salary according to bonus guidelines

    // friend functions
    friend istream& operator>>(istream& is, PartTime& worker); // friend overloading function for cin for PartTime
    friend ostream& operator<<(ostream& os, PartTime& worker); // friend overloading function for cout for PartTime
};

#endif // PARTTIME_H

