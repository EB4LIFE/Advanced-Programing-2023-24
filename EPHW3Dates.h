//Eitan Brown 346816549
//Operator overload
#pragma once
#ifndef DATE_H
#define DATE_H
#include <iostream>

using namespace std;
class Date {

private: 
//by default
int day; 
//of month (basically 1 - 31)

int month;
//of year (basically 1 -12)

int year;
//From Year zero CE (basically from defualt year to 9999

//For Feb which has 28 days reg but 29 in leap 
bool isLeapYear(int year) const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
//if date inputed is valid
bool isValid(int day, int month, int year) const {
  
}


public:

//Assingment ctor
Date (int dday, int dmonth, int dyear) : day(dday), month(dmonth), year(dyear) {
  if ((dday < 1) || (dday > 31)) {
		cout << "Error day" << end;
    //assigning default value
		day = 1; 
	}
	if ((dmonth < 1) || (dmonth > 12)) { 
		cout << "Error month" << endl;
    //assigning default value
		month = 1; 
	}
	if ((year < 1582) || (year > 9999)) { 
		cout << "Error year" << endl;
    //assigning default value
		year = 1582; 
	}


//copy since we are dealing with date will cal it fruit cuz i'm funny
Date (const Date &fruit) : day(fruit.dday), month(fruit.dmonth), year(fruit.dyear) {

}

void setDate(int d, int m, int y) {
  //if values inputed are truly valid 
  //we are good to say them as value
       
        }
    }

void print () const {
cout << day << "/" << month << "/" << year << endl;
}


};
#end if //DATE_H
