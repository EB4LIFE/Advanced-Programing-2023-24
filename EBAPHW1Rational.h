#pragma once
#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
using namespace std;

class Rational {
private:
    //by default
    int numerator;
    int denominator;

public:
    // The required constructors
    //An assignment constructor (ctor) with parameters that default to 0 for
    // the numerator and 1 for the denominator.The implementation must 
    // contain the following output : print: in constructor
    Rational(int num = 0, int den = 1) : numerator(num), denominator(den) {
        cout << "print: in constructor" << endl;
          if (den == 0) {
            denominator = 1;
        }
        else {
            denominator = den;
        }
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
    //copy constructor
    Rational(const Rational& other) : numerator(other.numerator), denominator(other.denominator) {
        cout << "print: in copy-constructor" << endl;
    }
    //set numerator
    void setNumerator(int num) {
        numerator = num;
    }
    //set numerator
    void setDenominator(int den) {
        if (den == 0) {
            denominator = 1;
        }
        else {
            denominator = den;
        }
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
    //get num
    int getNumerator() const {
        return numerator;
    }
    //get denom
    int getDenominator() const {
        return denominator;
    }
    //print rational
    // Method to print the rational number
    void print() const {
        cout << numerator << "/" << denominator;
    }
    //equal
    // Method to check equality
    bool equal(const Rational other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }
    //make equals
    // Method to make two rationals equal
    void makeEquals(Rational& other) {
        other.numerator = numerator;
        other.denominator = denominator;
    }
    //reduction
    // Helper "stepping stone" function method for reducing the fraction
    void reduce() {
        int gcd = getGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        if (numerator == 0) {
            denominator = 1;
        }
    }
    //add rational
    Rational add(const Rational other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        Rational sum(num, den);
        sum.reduce();
        return sum;
    }
    //addone
    // Method to add one to the rational
    Rational addOne() const {
        int num = numerator * 1 + 1 * denominator;
        int den = denominator * 1;
        Rational sum(num, den);
        return sum;
    }
    //personal thing to make it work
private:
    int getGCD(int a, int b) const {
        if (b == 0) {
            return a;
        }
        return getGCD(b, a % b);
    }
};
#endif
