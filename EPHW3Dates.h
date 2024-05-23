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
//From Year zero CE (basically zero and up)
public:

//Assingment ctor
Date (int dday = 1, int dmonth = 1, int dyear = 1582) : day(dday), month(dmonth), year(dyear) {
  //check the validity of the date according to the rules described here
}
//copy since we are dealing with date will cal it fruit cuz i'm funny
Date (const Date &fruit) {

}

};
#end if //DATE_H
