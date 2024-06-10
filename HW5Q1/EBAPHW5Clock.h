#pragma once
#ifndef CLOCK_H
#define CLOCK_H
#include <iostream>
using namespace std;
//eitanbrown346816549
class Clock {
private:
//by default
    int hour;
    int minute;
    int second;

public:
    // Assignment Constructor - don't need try and catch since it is in the assignctor itself
    Clock(int h = 0, int m = 0, int s = 0) : hour(0), minute(0), second(0) {
        //Throws for errors
        //second exceptions
        if (s < 0) throw "Invalid time - negative number of seconds.";
        if (s >= 60) throw "Invalid time - more than 60 seconds.";
        //minutes excepttions
        if (m < 0) throw "Invalid time - negative number of minutes.";
        if (m >= 60) throw "Invalid time - more than 60 minutes.";
        //hour exceptions
        if (h < 0) throw "Invalid time - negative number of hours.";
        if (h >= 24) throw "Invalid time - more than 24 hours.";
        //default time set to if just 1 of inputed values was invalid
        hour = h;
        minute = m;
        second = s;
    }

    // Getters
    int getHour() const { 
        return hour; 
    }
    int getMinute() const {
      return minute; 
      }
    int getSecond() const { 
        return second; 
    }

    // Setters

    void setHour(int h) {
        //check if hour is valid before set 
        //if (h < 0 || h >= 24) throw "Invalid time - hour out of range.";
        //hour = h;
         //similiar to assignment ctor
        try {   
        //if user entered invalid hour input, throw the value to catch
		if ((h > 23) || (h < 0)) throw h; 
        //otherwise set as normal
		hour = h;
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

    void setMinute(int m) {
        //if (m < 0 || m >= 60) throw "Invalid time - minute out of range.";
        //minute = m;
        //similiar to assignment ctor
        try {
         //if user entered invalid hour input, throw the value to catch
		if ((m > 59) || (m < 0)) throw m; 
        //otherwise
		minute = m;
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

    void setSecond(int s) {
        //if (s < 0 || s >= 60) throw "Invalid time - second out of range.";
        //second = s;
            //similiar to assignment ctor
        try {
    //if user entered invalid hour input, throw the value to catch
		if ((s > 59) || (s < 0)) throw s; 
		second = s;
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

    // equals method using a copy object instance 
    bool equals(const Clock& other) const {
        return hour == other.hour && minute == other.minute && second == other.second;
    }

    // before method
    //– A boolean method that receives a Clock instance and returns true if the
    //time in it is later than the time in the calling instance
    bool before(const Clock& other) const {
        if (hour < other.hour) return true;
        if (hour > other.hour) return false;
        if (minute < other.minute) return true;
        if (minute > other.minute) return false;
        //finally if time the calling instance
        return second < other.second;
    }

    // after method the literal oppisite of before method
    //lazy so wrote this way and still efecttive
    bool after(const Clock& other) const {
        return !before(other) && !equals(other);
    }

    // operator+=
    //receives an int that represents a number of seconds and updates the time accordingly.
    Clock& operator+=(int seconds) {
        if (seconds < 0) throw "Invalid time - negative number of seconds.";
        second += seconds;
        //60 second in am minute
        while (second >= 60) {
            second -= 60;
            minute++;
        }
        //60 minutes in 1 hour
        while (minute >= 60) {
            minute -= 60;
            hour++;
        }
        //latest is 24 but after 2359 we go to 00:00
        while (hour >= 24) {
            hour -= 24;
        }
        //return the instance
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
#endif 

