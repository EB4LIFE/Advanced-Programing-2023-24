#include "PartTime.h"

PartTime::PartTime() : default_hoursWorked(0), default_rateHour(0) {
    Employee(); // calling ctor to set default values
}

PartTime::PartTime(string name, int id, int seni, int hours, float rate) : default_hoursWorked(hours), default_rateHour(rate) {
    Employee(name, id, seni); // calling ctor to set values to fields that overlap
}

void PartTime::setHoursWorked(int hours) {
    default_hoursWorked = hours;
}

void PartTime::setRate(float rate) {
    default_rateHour = rate;
}

int PartTime::getHoursWorked() const {
    return default_hoursWorked;
}

float PartTime::getRate() const {
    return default_rateHour;
}

float PartTime::salary() {
    return (default_hoursWorked * default_rateHour); // returning hourly wage * amount of hours worked that month
}

float PartTime::salaryAfterBonus() {
    float monthSal = salary(); // getting monthly salary since no field for it

    setPay(monthSal); // employee method uses m_pay field, so setting it so can call employee method
    return Employee::salaryAfterBonus(); // returning whatever the employee method returns
}

istream& operator>>(istream& is, PartTime& worker) {
    cout << "Enter employee details:\n";

    is >> worker.default_name >> worker.default_id >> worker.default_seniority >> worker.default_hoursWorked >> worker.default_rateHour;

    if (worker.default_id <= 0) { // if user enters negative value for id
        throw "ERROR";
    }
    if (worker.default_seniority < 0) { // if user enters negative value for number of years
        throw "ERROR";
    }
    if (worker.default_rateHour < 0) {
        throw "ERROR";
    }
    if (worker.default_hoursWorked < 0) { // if user enters negative value for salary
        throw "ERROR";
    }

    return is;
}

ostream& operator<<(ostream& os, PartTime& worker) {
    os << "Employee: " << worker.default_name << endl;
    os << "Employee ID: " << worker.default_id << endl;
    os << "Years Seniority: " << worker.default_seniority << endl;
    os << "Hours: " << worker.default_hoursWorked << endl;
    os << "Salary per Month: " << worker.salary() << endl;

    return os;
}

