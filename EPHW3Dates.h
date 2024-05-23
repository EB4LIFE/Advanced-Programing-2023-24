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

//Assungment ctor
Date () {
}
//copy since we are dealing with date will cal it fruit cuz i'm funny
Date (const Date &fruit) {

}

};
#end if //DATE_H
