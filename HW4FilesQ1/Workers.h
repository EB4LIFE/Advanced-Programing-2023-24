// Eitan Brown 346816549
#pragma once
#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <string>
using namespace std;

class Worker {
private:
    long id;
    string name;
    float wages;

public:
    Worker();
    Worker& operator+=(float bonus);
    bool operator<(const Worker& other) const;

    friend bool operator==(long left, const Worker& right);
    friend bool operator==(const string& left, const Worker& right);
    friend istream& operator>>(istream& input, Worker& worker);
    friend ostream& operator<<(ostream& output, const Worker& worker);

    bool compare(const Worker& other) const;
};

#endif // WORKER_H
