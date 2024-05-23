//Eitan Brown 346816549
//operator overloading
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
//for functions reduce later 
 int getGCD(int a, int b) const {
        if (b == 0) {
            return a;
        }
        return getGCD(b, a % b);
    }
public:

    // Empty constructor
    Rational() : numerator(1), denominator(1) {
      //Nothing to implement 
    }

    // Assignment constructor
    Rational(int num, int denom) {
        numerator = num;
        if (denom == 0) {
            denominator = 1;
        } 
        else if (denom < 0) {
            numerator = -numerator;
            denominator = -denom;
        } 
        else {
            denominator = denom;
        }
    }

// Copy constructor
    Rational(const Rational &other) : numerator(other.numerator), denominator(other.denominator) {
      //nothing to implement 
    }

    //Set the Numerator
    void setNumerator(int num) {
        numerator = num;
    }

   //Set the Denomanator
    void setDenominator(int denom) {
        if (denom == 0) {
            denominator = 1;
        } else if (denom < 0) {
            numerator = -numerator;
            denominator = -denom;
        } else {
            denominator = denom;
        }
    }

    //getter num
    int getNumerator() const {
        return numerator;
    }

    // Getter denom
    int getDenominator() const {
        return denominator;
    }
    // Helper method to reduce the fraction
    void reduce() {
        if (numerator == 0) {
            denominator = 1;
        } 
        else {
            int gcd = gcd(numerator, denominator);
            numerator /= gcd;
            denominator /= gcd;
        }
    }

    // Method to print the rational number
    void print() const {
        if (denominator == 1) {
            cout << numerator;
        } else {
            cout << numerator << "/" << denominator;
        }
    }

// Operator overloading
//This operator adds two rational numbers. It creates a new Rational object where the numerator is the cross sum of the numerators and denominators of the two //operands. The denominator is the product of the denominators. The result is then reduced.
    Rational operator+(const Rational &other) const {
        Rational result(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
        result.reduce();
        return result;
    }
//This operator subtracts one rational number from another. It follows a similar approach to addition, but subtracts the cross products of the numerators.
    Rational operator-(const Rational &other) const {
        Rational result(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
        result.reduce();
        return result;
    }
//This operator multiplies two rational numbers. It multiplies the numerators and denominators directly and then reduces the result.
    Rational operator*(const Rational &other) const {
        Rational result(numerator * other.numerator, denominator * other.denominator);
        result.reduce();
        return result;
    }
//This operator divides one rational number by another. It multiplies the numerator of the first by the denominator of the second, 
//and vice versa, to perform the division. The result is then reduced.
    Rational operator/(const Rational &other) const {
        Rational result(numerator * other.denominator, denominator * other.numerator);
        result.reduce();
        return result;
    }
//increment and decremnt opps

//General:
//This operator increments the rational number by adding the denominator to the numerator (equivalent to adding 1). 
//It returns the incremented object.
    Rational& operator++() {
        numerator += denominator;
        return *this;
    }
//increment value by one but return pre-incremented value
    Rational operator++(int) {
        Rational temp(*this);
        numerator += denominator;
        return temp;
    }
//This operator decrements the rational number by subtracting the denominator from the numerator (equivalent to subtracting 1). 
//It returns the decremented object.
    Rational& operator--() {
        numerator -= denominator;
        return *this;
    }
//decrement value by one but return pre-deccremented value
    Rational operator--(int) {
        Rational temp(*this);
        numerator -= denominator;
        return temp;
    }
//This operator checks if two rational numbers are equal by reducing both and then comparing their numerators and denominators.
    bool operator==(const Rational &other) const {
        Rational lhs(*this);
        Rational rhs(other);
        lhs.reduce();
        rhs.reduce();
        return (lhs.numerator == rhs.numerator) && (lhs.denominator == rhs.denominator);
    }
//This operator checks if two rational numbers are not equal by using the equality operator 
    bool operator!=(const Rational &other) const {
        return !(*this == other);
    }
//provifg less than by cross mult
    bool operator<(const Rational &other) const {
        return (numerator * other.denominator) < (other.numerator * denominator);
    }
//same methed here for less than or equal to
    bool operator<=(const Rational &other) const {
        return (numerator * other.denominator) <= (other.numerator * denominator);
    }
//same methed here for greater than to
    bool operator>(const Rational &other) const {
        return (numerator * other.denominator) > (other.numerator * denominator);
    }
//same methed here for greather than or equal to
    bool operator>=(const Rational &other) const {
        return (numerator * other.denominator) >= (other.numerator * denominator);
    }
};

#endif 

