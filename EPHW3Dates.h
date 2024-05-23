//Eitan Brown 346816549
//Operator overload
#pragma once
#ifndef MYMyDate_H
#define MYMyDate_H
#include <iostream>
using namespace std;


class MyDate {

  private: //by default

//of month (basically 1 - 31)
int day; 

//of year (basically 1 -12)
int month;

// from defualt year to 9999
int year;

//personal help function for leap year based of question:
//A year is a leap year if it divides by 4 
//but not by 100, or if it divides by 400
//true=leap false = loop
 bool isLeapYear(int year) const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
//Now we can also make another helper using switch
//so for months __> 1,3,5,7,8,10,12 have 31 days 
//4,6,9,11 __> 30 
//feb(2) we use the leap year function above 
int daysInMonth(int month, int year) const {
        switch(month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
            case 4: case 6: case 9: case 11: return 30;
            case 2: return isLeapYear(year) ? 29 : 28;
            default: return 0;
        }
    }
//CHECK IF Date IS VALID (puttting function here 
//so we don't have to keep writing it over and over in public)
//What this does is if year is invalid, or month is invalid  return false
//And Date is seperate for the switch cases above or Date is invalid = false 
//Otherwise true
bool isValid(int day, int month, int year) const {
      if (year < 1582 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31) {
            return false;
        }
        return day <= daysInMonth(month, year);
    }



public:
   //Assignment ctor
   MyDate (int dday=1, int dmonth=1, int dyear=1582) {
    //Check Validity here as well before setting values
    //which it should be true
    if(isValid(dday, dmonth, dyear)) {
            day = dday;
            month = dmonth;
            year = dyear;
        } 
    else {
            cout << "Error MyDate" << endl;
            day = 1;
            month = 1;
            year = 1582;
        }
   }
   //copy tor
    //copy since we are dealing with MyDate will cal it fruit cuz i'm funny
    MyDate (const MyDate &fruit) : day(fruit.day), month(fruit.month), year(fruit.year) {

    }
    //Date set
   void setDate(int dday, int dmonth, int dyear) {
       
    if(isValid(dday, dmonth, dyear)) {
            day = dday;
            month = dmonth;
            year = dyear;
    }
    //as specfied no error MyDate is printed here 
   }
   
//print the full Date dd/mm/yyyy
void print () const {
cout << day << "/" << month << "/" << year << endl;
}
//copy assignemtn (= op)
    MyDate& operator=(const MyDate &fruit) {
        if (this != &fruit) {
            day = fruit.day;
            month = fruit.month;
            year = fruit.year;
        }
        return *this;
    }
    
//prefix op++
MyDate& operator++() {
//basically if incremented day is more than that of days of particular month
//set MyDate to 1 and increment the month by 1 unless dec(12) then make it 1 and add to year
        if (++day > daysInMonth(month, year)) {
            day = 1;
            if (++month > 12) {
                month = 1;
                ++year;
            }
        }
        return *this;
    }

//postfix ++op
 MyDate operator++(int) {
        MyDate temp(*this);
        ++(*this);
        return temp;
    }

//postfix >
bool operator>(const MyDate &fruit) const {
    
        if (year != fruit.year) {
            return year > fruit.year;
        }
        else if (month != fruit.month) {
            return month > fruit.month;
        }
        else { 
            return day > fruit.day;
        }
    }
//postfix < 
bool operator<(const MyDate &fruit) const {
        return fruit > *this;
    }
//postfix == (wants true or false) - if the MyDate are equal
 bool operator==(const MyDate &fruit) const {
        return day == fruit.day && month == fruit.month && year == fruit.year;
    }
};
#endif //MyDate_H



   
