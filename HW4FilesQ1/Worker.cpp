#include "Worker.h"

// Default constructor
Worker::Worker() : id(0), name(""), wages(0.0) {
}

// Operator+= to add bonus to wages
Worker& Worker::operator+=(float bonus) {
    wages += bonus;
    return *this;
}

// Operator< to compare wages
bool Worker::operator<(const Worker& other) const {
    return this->wages < other.wages;
}

// Operator== to compare id with a long
bool operator==(long left, const Worker& right) {
    return left == right.id;
}

// Operator== to compare name with a string
bool operator==(const string& left, const Worker& right) {
    return left == right.name;
}

// Input operator>> to read Worker data
istream& operator>>(istream& input, Worker& worker) {
    input >> worker.id >> worker.name >> worker.wages;
    return input;
}

// Output operator<< to write Worker data
ostream& operator<<(ostream& output, const Worker& worker) {
    output << worker.id << " " << worker.name << " " << worker.wages;
    return output;
}

// Compare function to assist sorting in WorkersFile
bool Worker::compare(const Worker& other) const {
    if (wages != other.wages) {
        return wages < other.wages;
    }
    return name > other.name;
}
