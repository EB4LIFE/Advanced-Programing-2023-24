#include "MyDate.h"

// Helper function to check if a date is valid
bool MyDate::isValidDate(int d, int m, int y) {
    if (y < 1920 || y > 9999 || m < 1 || m > 12 || d < 1 || d > 31) {
        return false;
    }
    if (m == 2) {
        bool leapYear = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        if (d > (leapYear ? 29 : 28)) {
            return false;
        }
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        if (d > 30) {
            return false;
        }
    }
    return true;
}

// Set default date
void MyDate::setDefault() {
    day = 1;
    month = 1;
    year = 1920;
}

// Constructor with validity check
MyDate::MyDate(int d, int m, int y) {
    if (isValidDate(d, m, y)) {
        day = d;
        month = m;
        year = y;
    } else {
        cout << "Error date" << endl;
        setDefault();
    }
}

// Copy constructor
MyDate::MyDate(const MyDate& other) : day(other.day), month(other.month), year(other.year) {
}

// Set date method
void MyDate::setDate(int d, int m, int y) {
    if (isValidDate(d, m, y)) {
        day = d;
        month = m;
        year = y;
    }
}

// Print the date
void MyDate::print() const {
    cout << day << "/" << month << "/" << year;
}

// Assignment operator
MyDate& MyDate::operator=(const MyDate& other) {
    if (this != &other) {
        day = other.day;
        month = other.month;
        year = other.year;
    }
    return *this;
}

// Prefix increment
MyDate& MyDate::operator++() {
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    bool leapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (leapYear && month == 2) {
        daysInMonth[1] = 29;
    }
    day++;
    if (day > daysInMonth[month - 1]) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    return *this;
}

// Postfix increment
MyDate MyDate::operator++(int) {
    MyDate temp(*this);
    ++(*this);
    return temp;
}

// Comparison operators
bool MyDate::operator>(const MyDate& other) const {
    if (year != other.year) return year > other.year;
    if (month != other.month) return month > other.month;
    return day > other.day;
}

bool MyDate::operator<(const MyDate& other) const {
    return !(*this >= other);
}

bool MyDate::operator==(const MyDate& other) const {
    return day == other.day && month == other.month && year == other.year;
}

bool MyDate::operator>=(const MyDate& other) const {
    return *this > other || *this == other;
}

bool MyDate::operator<=(const MyDate& other) const {
    return *this < other || *this == other;
}
