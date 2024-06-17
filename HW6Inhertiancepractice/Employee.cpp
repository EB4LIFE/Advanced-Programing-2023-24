#include "Employee.h"
#include "FullTime.h"
#include "PartTime.h"

Employee::Employee(string name, int id, int seni, float pay) : default_name(name), default_id(id), default_seniority(seni), default_pay(pay) {}

void Employee::setName(string name) {
    default_name = name;
}

void Employee::setId(int id) {
    default_id = id;
}

void Employee::setSeniority(int seni) {
    default_seniority = seni;
}

void Employee::setPay(float pay) {
    default_pay = pay;
}

string Employee::getName() const {
    return default_name;
}

int Employee::getId() const {
    return default_id;
}

int Employee::getSeniority() const {
    return default_seniority;
}

float Employee::getPay() const {
    return default_pay;
}

float Employee::salaryAfterBonus() {
    if (default_seniority <= 5) {
        return (default_pay + 500);
    }
    if (default_seniority > 5) {
        return (default_pay + (0.25 * default_pay));
    }
    return default_pay;
}

istream& operator>>(istream& is, Employee& worker) {
    cout << "Enter employee details:\n";
    is >> worker.default_name >> worker.default_id >> worker.default_seniority >> worker.default_pay;

    if (worker.default_id <= 0) {
        throw "ERROR";
    }
    if (worker.default_seniority < 0) {
        throw "ERROR";
    }
    if (worker.default_pay < 0) {
        throw "ERROR";
    }

    return is;
}

ostream& operator<<(ostream& os, const Employee& worker) {
    os << "Employee: " << worker.default_name << endl;
    os << "Employee ID: " << worker.default_id << endl;
    os << "Years Seniority: " << worker.default_seniority << endl;

    return os;
}

