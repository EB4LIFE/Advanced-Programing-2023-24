#pragma once
#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
using namespace std;

class Rational {
private:
    int numerator;
    int denominator;

public:
    Rational(int num = 0, int den = 1);
    Rational(const Rational& other);
    void setNumerator(int num);
    void setDenominator(int den);
    int getNumerator() const;
    int getDenominator() const;
    void print() const;
    bool equal(const Rational other) const;
    void makeEquals(Rational& other);
    void reduce();
    Rational add(const Rational other) const;
    Rational addOne() const;

private:
    int getGCD(int a, int b) const;
};

#endif // RATIONAL_H
