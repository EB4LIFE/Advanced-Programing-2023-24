#pragma once
#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
using namespace std;

class Clock {
private:
    int hour;
    int minute;
    int second;

public:
    Clock(int h = 0, int m = 0, int s = 0);

    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    void setHour(int h);
    void setMinute(int m);
    void setSecond(int s);

    bool equals(const Clock& other) const;
    bool before(const Clock& other) const;
    bool after(const Clock& other) const;

    Clock& operator+=(int seconds);

    friend ostream& operator<<(ostream& os, const Clock &time);
    friend istream& operator>>(istream& is, Clock &time);
};

#endif // CLOCK_H

