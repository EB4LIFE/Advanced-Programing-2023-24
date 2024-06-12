// Eitan Brown 346816549
// Operator overloading
#pragma once
#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;

class Rational {
private:
    int numerator;
    int denominator;

    int getgcd(int a, int b) const;

public:
    Rational();
    Rational(int num, int denom);
    Rational(const Rational &other);

    void setNumerator(int num);
    void setDenominator(int denom);
    int getNumerator() const;
    int getDenominator() const;

    void reduce();
    void print() const;

    Rational operator+(Rational other);
    Rational operator-(Rational other);
    Rational operator*(Rational other);
    Rational operator/(Rational other);

    Rational& operator++();
    Rational operator++(int);
    Rational& operator--();
    Rational operator--(int);

    bool operator==(const Rational &other) const;
    bool operator!=(const Rational &other) const;
    bool operator<(Rational other);
    bool operator<=(Rational other);
    bool operator>(Rational other);
    bool operator>=(Rational &other);
};

#endif // RATIONAL_H
