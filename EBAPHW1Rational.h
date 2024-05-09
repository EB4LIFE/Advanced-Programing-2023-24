#pragma once
#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
using namespace std;


class Rational {

private: //by default
    int numerator;
    int denominator;

public:
    // The required constructors
    //An assignment constructor (ctor) with parameters that default to 0 for
    // the numerator and 1 for the denominator.The implementation must 
    // contain the following output : print: in constructor
    Rational(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        cout << "print: in constructor" << endl;
    }
    //copy constructor
    Rational(const Rational& other): numerator(other.numerator), denominator(other.denominator)  {
        cout << "print: in copy-constructor" << endl;
    }
    //set numerator
    void setNumerator(int num) {
        numerator = num;
    }
    //get numerator
    int getNumerator() const {
        return numerator;
    }
     //set denominator
    void setDenominator(int denom) {
        if (denom == 0) {
            denominator = 1;
        }
        else {
            denominator = denom;
            if (denominator < 0) {
                numerator *= -1;
                denominator *= -1;
            }
        }
    }
    //get denominaotr
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
    bool equal(const Rational& other) const {
        return (numerator == other.numerator && denominator == other.denominator);
    }
    //make equals
    // Method to make two rationals equal
    void makeEquals(const Rational& other) {
        numerator = other.numerator;
        denominator = other.denominator;
    }
    //reduction
    // Helper "stepping stone" function method for reducing the fraction
    void reduce() {
        int gcd = 1;
        int smaller = (numerator < denominator) ? numerator : denominator;
        for (int i = 2; i <= smaller; ++i) {
            if (numerator % i == 0 && denominator % i == 0) {
                gcd = i;
            }
        }
        numerator /= gcd;
        denominator /= gcd;
        if (numerator == 0)
        {
            denominator = 1;
        }
    }
    //add rational
    Rational add(const Rational& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        Rational result(num, denom);
        result.reduce();
        return result;
    }
    //addone
    // Method to add one to the rational
    Rational addOne() const {
        return add(Rational(1, 1));
    }
};
#endif
