#pragma once
#ifndef CLOCK_H
#define CLOCK_H
#include <iostream>
using namespace std;


Class Clock {

Private:
//by default
int hour;
int minute; 
int second;

Public:

//ctor
Clock() {
   hour = 00;
   minute = 00;
   second = 00;
}
//assignment ctor 
Clock(int hours, int min, int sec) : hour(hours), minute(min), sec(second) {
    //set parameters for max and error check for variables
    try {
		if ((hour > 23) || (hour < 0)) {
			throw 'h'; //throwing error for invalid hour input
		}
		if ((minute > 59) || (minute < 0)) {
			throw 'm'; //throwing error for invalid minute input
		}
		if ((second > 59) || (second < 0)) {
			throw 's'; //throwing error for invalid second input
		}
	}
		catch (char c) { //catching errors for invalid time input
		//will go through all possible error types and provide the correct error message
		if (c == 'h') {
			if (hour > 23) { 
				cout << "Invalid time – more than 24 hours" << endl;
			}
			if (hour < 0) {
				cout << "Invalid time – negative number of hours" << endl;
			}
		}
		if (c == 'm') {
			if (minute > 60) {
				cout << "Invalid time – more than 60 minutes" << endl;
			}
			if (minute < 0) {
				cout << "Invalid time – negative number of minutes" << endl;
			}
		}
		if (c == 's') {
			if (second > 60) {
				cout << "Invalid time – more than 60 seconds" << endl;
			}
			if (second < 0) {
				cout << "Invalid time – negative number of seconds" << endl;
			}
		}
		hour = 00;
		minute = 00;
		second = 00; 
		//default time set to if just 1 of inputed values was invalid
	}
}
//copy
Clock(Clock& time) {
    hour = time.hour;
    minute = time.minute;
    second = time.second;
}

//setters and getters
void setHour(int hours) 
{
    //similiar to assignment ctor
try {   
        //if user entered invalid hour input, throw the value to catch
		if ((hours > 23) || (hours < 0)) throw hours; 
		hour = hours;
	}
	//now check: which error message to execute
	catch (int x) { 
		if (x > 23) {
			cout << "Invalid time – more than 24 hours" << endl;
		}
		if (x < 0) {
			cout << "Invalid time – negative number of hours" << endl;
		}
		//defualt set if  1 invalid input was put in
		hour = 00;
		minute = 00;
		second = 00; 
	}
}
void setMin(int min)
{
    //similiar to assignment ctor
    try {
         //if user entered invalid hour input, throw the value to catch
		if ((min > 59) || (min < 0)) throw min; 
		minute = min;
	}
	//now check: which error message to execute
	catch (int x) { 
		if (x > 60) {
			cout << "Invalid time – more than 60 minutes" << endl;
		}
		if (x < 0) {
			cout << "Invalid time – negative number of minutes" << endl;
		}
		//defualt set if  1 invalid input was put in
		hour = 00;
		minute = 00;
		second = 00;
	}

}
void setSec(int sec)
{   
    //similiar to assignment ctor
    try {
    //if user entered invalid hour input, throw the value to catch
		if ((sec > 59) || (sec < 0)) throw sec; 
		second = sec;
	}
	//now check: which error message to execute
	catch (int x) { 
		if (x > 60) {
			cout << "Invalid time – more than 60 seconds" << endl;
		}
		if (x < 0) {
			cout << "Invalid time – negative number of seconds" << endl;
		}
		//defualt set if  1 invalid input was put in
		hour = 00;
		minute = 00;
		second = 00; 
	}
}
int getHour() const
{
    return hour;
}
int getMin() const
{
    return minute;
}
int getSec() const
{
    return second;
}
//add immediate operation overload method
//add another sec variable 
Clock operator+=(int sec2) {
    second += se2s; 
    //if new value for seconds is too big
    //We put them into minute so can get rid of them in seconds
	if (second > 59) { 
		++minute; 
		second -= 60; 
        //same process from minute to hours
		if (minute > 59) { 
			++hour;
			minute -= 60;
            //same process as above except nothing to add to so we just move hour back to 0
			if (hour > 23) { 
				hour = 00; 
			}
		}
	}
	return *this;
}
    //cout friend operator
	friend ostream& operator<<(ostream& os, const Clock &time) {
    os << (time.hour < 10 ? "0" : "") << time.hour << ":" << (time.minute < 10 ? "0" : "") << time.minute << ":" << (time.second < 10 ? "0" : "") << time.second;
    
	return os;
	}
	
	//cin friend operator
	friend istream& operator>>(istream& is, Clock &time) {
	//basic var names
	char c;
	int x;
	
	try {
	    
		is >> time.hour;
		is >> c;
		//user didn't enter colon so sending message that it's wrong format as instructed
		if (c != ':') { 
			throw string("Wrong time format\n");
		}

		is >> time.minute;
		is >> c;
		//same as above
		if (c != ':') { 
			throw string("Wrong time format\n");
		}

		is >> time.second;
	}
	//printing exception message and setting to default time
	catch (string s) { 
		cout << s;
		
		time.hour = 00;
		time.minute = 00; 
		time.second = 00;
	}
	return is;
	}

};
#endif //CLOCK_H
