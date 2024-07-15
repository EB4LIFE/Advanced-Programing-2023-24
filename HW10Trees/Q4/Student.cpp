#include "Student.h"

// Default constructor
Student::Student() : id(0), lastName(""), firstName("") {}

// Assignment constructor
Student::Student(int id, string lastName, string firstName)
    : id(id), lastName(lastName), firstName(firstName) {}

// Copy constructor
Student::Student(const Student& other) : id(other.id), lastName(other.lastName), firstName(other.firstName) {}

// Move constructor
Student::Student(Student&& other) noexcept
    : id(other.id), lastName(std::move(other.lastName)), firstName(std::move(other.firstName)) {
    other.id = 0;
}

// Destructor
Student::~Student() {}

// Copy assignment operator
Student& Student::operator=(const Student& other) {
    if (this == &other) return *this;
    id = other.id;
    lastName = other.lastName;
    firstName = other.firstName;
    return *this;
}

// Move assignment operator
Student& Student::operator=(Student&& other) noexcept {
    if (this != &other) {
        id = other.id;
        lastName = std::move(other.lastName);
        firstName = std::move(other.firstName);
        other.id = 0;
    }
    return *this;
}

// Operator<=
bool Student::operator<=(const Student& other) const {
    return id <= other.id;
}

// Operator==
bool Student::operator==(const Student& other) const {
    return id == other.id;
}

// Operator<<
ostream& operator<<(ostream& os, const Student& student) {
    os << student.id << " " << student.lastName << " " << student.firstName;
    return os;
}

// Operator>>
istream& operator>>(istream& is, Student& student) {
    is >> student.id >> student.lastName >> student.firstName;
    return is;
}
