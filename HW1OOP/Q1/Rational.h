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
//Param ctor with private variable    
Rational(int num = 0, int den = 1);

//copy ctor of param
Rational(const Rational& other);

//setters and getters 
void setNumerator(int num);
void setDenominator(int den);
int getNumerator() const;
int getDenominator() const;

//Methods will describe in .cpp

//A method print for printing the rational number. The printing is to be in the
//format: numerator/denominator (For example: 1/2, 3/4, 54/56 etc.) according to
//the original values and not the values after reduction.
void print() const;

/*A boolean method called equal that compares two Rational numbers and tests if
they are the same. Note: In this context the same means that the numerators are
equal and the denominators are equal (1/2 and 3/6 are not considered equal).*/
bool equal(const Rational other) const;

/*A method called makeEquals that receives a Rational object and modifies it to
equal the calling object.
Note: The method is of return type void. The argument is cbr so that there is no
call to the copy-ctor. */
void makeEquals(Rational& other);

//The function is to reduce the calling object.
/*The resulting numerator for rat will be 1 and its denominator will be 2.
After reduction, if the numerator is 0, the method is to make the
denominator 1. */
void reduce();

/*A method called add that receives a Rational object and sums the two objects.
The method is to return a new Rational object that contains the reduced sum of
the original objects. */
Rational add(const Rational other) const;

//generates and returns a new Rational object
//whose value is 1 greater than the value of the calling object.
Rational addOne() const;

//private helper function
private:
    int getGCD(int a, int b) const;
};

#endif // RATIONAL_H
