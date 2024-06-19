// Eitan Brown 346816549
// Operator overload
#pragma once
#ifndef MYDATE_H
#define MYDATE_H

#include <iostream>
#include <string>
using namespace std;

class MyDate {
private:
    int day;
    int month;
    int year;

    bool isValidDate(int d, int m, int y);
    void setDefault();

public:
    MyDate(int d = 1, int m = 1, int y = 1920);
    MyDate(const MyDate& other);

    void setDate(int d, int m, int y);
    void print() const;

    MyDate& operator=(const MyDate& other);
    MyDate& operator++();
    MyDate operator++(int);

    bool operator>(const MyDate& other) const;
    bool operator<(const MyDate& other) const;
    bool operator==(const MyDate& other) const;
    bool operator>=(const MyDate& other) const;
    bool operator<=(const MyDate& other) const;
};

#endif // MYDATE_H
