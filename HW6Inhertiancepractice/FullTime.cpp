#include "FullTime.h"

FullTime::FullTime(string name, int id, int seni, float annualSal) : default_annualSalary(annualSal) {
    Employee(name, id, seni); // calling ctor for employee to set all the values besides for new one for fulltime
}

FullTime::FullTime() {
    Employee(); // calling ctor to set values to default
    default_annualSalary = 0;
}

void FullTime::setAnnualSalary(float sal) {
    default_annualSalary = sal;
}

float FullTime::getAnnualSalary() const {
    return default_annualSalary;
}

float FullTime::salary() {
    return (default_annualSalary / 12); // returning monthly salary based on annual salary
}

float FullTime::salaryAfterBonus() {
    float monthSal = salary(); // getting monthly salary since no field for it
    setPay(monthSal); // employee method uses m_pay field, so setting it so can call employee method
    return Employee::salaryAfterBonus(); // returning whatever the employee method returns
}

istream& operator>>(istream& is, FullTime& worker) {
    cout << "Enter employee details:\n";
    is >> worker.default_name >> worker.default_id >> worker.default_seniority >> worker.default_annualSalary;

    if (worker.default_id <= 0) { // if user enters negative value for id
        throw "ERROR";
    }
    if (worker.default_seniority < 0) { // if user enters negative value for number of years
        throw "ERROR";
    }
    if (worker.default_annualSalary < 0) { // if user enters negative value for salary
        throw "ERROR";
    }

    return is;
}

ostream& operator<<(ostream& os, FullTime& worker) {
    os << "Employee: " << worker.default_name << endl;
    os << "Employee ID: " << worker.default_id << endl;
    os << "Years Seniority: " << worker.default_seniority << endl;
    os << "Salary p

