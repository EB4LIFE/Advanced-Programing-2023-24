//Eitan Brown 346816549
//Operator overload
#pragma once
#ifndef MYDate_H
#define MYDate_H
#include <iostream>
#include <string>
using namespace std;


class MyDate {

private: //by default
//of month (basically 1 - 31)
int day; 
//of year (basically 1 -12)
int month;
// from defualt year to 9999
int year;

//CHECK IF Date IS VALID (puttting function here 
//so we don't have to keep writing it over and over in public)
//What this does is if year is invalid, or month is invalid  return false
//And Date is seperate for the switch cases above or Date is invalid = false 
//Otherwise true
//We also include the leap year as well instead of 2 seperate ones
bool isValidDate(int d, int m, int y) {
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
//Choice to make a set default 
void setDefault() {
    day = 1;
    month = 1;
    year = 1920;
}
//end of private


public:
    //assignment ctor with validity check
    MyDate(int d = 1, int m = 1, int y = 1920) {
        if (isValidDate(d, m, y)) {
            day = d;
            month = m;
            year = y;
        } 
        else {
            //if date is not valid prints error and sets value to default date 
            cout << "Error date" << endl;
            setDefault();
        }
    }
    //copy ctor
    MyDate(const MyDate &other) : day(other.day), month(other.month), year(other.year) {
        
    }
    
    //setDate method
        //no error check as stated per question
        void setDate(int d, int m, int y) {
        if (isValidDate(d, m, y)) {
            day = d;
            month = m;
            year = y;
        }
     }
    //printing
    void print () const {
        cout << day << "/" << month << "/" << year << endl;
}
    //NOW OPERATORS
    
        //first: = 0p just copy shallow
        MyDate& operator=(const MyDate &other) {
        if (this != &other) {
            day = other.day;
            month = other.month;
            year = other.year;
        }
        return *this;
    }
    
    // Prefix increment
    MyDate& operator++() {
        
        //basically if incremented day is more than that of days of particular month
        //set MyDate to 1 and increment the month by 1 unless dec(12) then make it 1 and add to year
        //as we used an array of the months the leap year is included once again
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
    MyDate operator++(int) {
        //will print the changed date 
        MyDate temp(*this);
        ++(*this);
        return temp;
    }


    bool operator>(const MyDate &other) const {
        if (year != other.year) return year > other.year;
        if (month != other.month) return month > other.month;
        return day > other.day;
    }

    bool operator<(const MyDate &other) const {
        return !(*this >= other);
    }

    bool operator==(const MyDate &other) const {
        return day == other.day && month == other.month && year == other.year;
    }

    bool operator>=(const MyDate &other) const {
        return *this > other || *this == other;
    }

    bool operator<=(const MyDate &other) const {
        return *this < other || *this == other;
    }




};
#endif
