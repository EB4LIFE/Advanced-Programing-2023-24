#include "Clock.h"

Clock::Clock(int h, int m, int s) : hour(0), minute(0), second(0) {
    if (s < 0) throw "Invalid time - negative number of seconds.";
    if (s >= 60) throw "Invalid time - more than 60 seconds.";
    if (m < 0) throw "Invalid time - negative number of minutes.";
    if (m >= 60) throw "Invalid time - more than 60 minutes.";
    if (h < 0) throw "Invalid time - negative number of hours.";
    if (h >= 24) throw "Invalid time - more than 24 hours.";
    hour = h;
    minute = m;
    second = s;
}

int Clock::getHour() const {
    return hour;
}

int Clock::getMinute() const {
    return minute;
}

int Clock::getSecond() const {
    return second;
}

void Clock::setHour(int h) {
    try {   
        if ((h > 23) || (h < 0)) throw h; 
        hour = h;
    } catch (int x) { 
        if (x > 23) {
            cout << "Invalid time – more than 24 hours" << endl;
        }
        if (x < 0) {
            cout << "Invalid time – negative number of hours" << endl;
        }
        hour = 0;
        minute = 0;
        second = 0; 
    }   
}

void Clock::setMinute(int m) {
    try {
        if ((m > 59) || (m < 0)) throw m; 
        minute = m;
    } catch (int x) { 
        if (x > 60) {
            cout << "Invalid time – more than 60 minutes" << endl;
        }
        if (x < 0) {
            cout << "Invalid time – negative number of minutes" << endl;
        }
        hour = 0;
        minute = 0;
        second = 0;
    }
}

void Clock::setSecond(int s) {
    try {
        if ((s > 59) || (s < 0)) throw s; 
        second = s;
    } catch (int x) { 
        if (x > 60) {
            cout << "Invalid time – more than 60 seconds" << endl;
        }
        if (x < 0) {
            cout << "Invalid time – negative number of seconds" << endl;
        }
        hour = 0;
        minute = 0;
        second = 0; 
    }
}

bool Clock::equals(const Clock& other) const {
    return hour == other.hour && minute == other.minute && second == other.second;
}

bool Clock::before(const Clock& other) const {
    if (hour < other.hour) return true;
    if (hour > other.hour) return false;
    if (minute < other.minute) return true;
    if (minute > other.minute) return false;
    return second < other.second;
}

bool Clock::after(const Clock& other) const {
    return !before(other) && !equals(other);
}

Clock& Clock::operator+=(int seconds) {
    if (seconds < 0) throw "Invalid time - negative number of seconds.";
    second += seconds;
    while (second >= 60) {
        second -= 60;
        minute++;
    }
    while (minute >= 60) {
        minute -= 60;
        hour++;
    }
    while (hour >= 24) {
        hour -= 24;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Clock &time) {
    os << (time.hour < 10 ? "0" : "") << time.hour << ":"
       << (time.minute < 10 ? "0" : "") << time.minute << ":"
       << (time.second < 10 ? "0" : "") << time.second;
    return os;
}

istream& operator>>(istream& is, Clock &time) {
    char c;
    try {
        is >> time.hour >> c;
        if (c != ':') throw string("Wrong time format\n");
        is >> time.minute >> c;
        if (c != ':') throw string("Wrong time format\n");
        is >> time.second;
    } catch (string s) {
        cout << s;
        time.hour = 0;
        time.minute = 0;
        time.second = 0;
    }
    return is;
}
