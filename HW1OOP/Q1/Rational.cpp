#include "Rational.h"

// The required constructors
// An assignment constructor (ctor) with parameters that default to 0 for
// the numerator and 1 for the denominator. The implementation must 
// contain the following output : print: in constructor
Rational::Rational(int num, int den) : numerator(num), denominator(den) {
    cout << "print: in constructor" << endl;
    if (den == 0) {
        denominator = 1;
    } else {
        denominator = den;
    }
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

// Copy constructor
Rational::Rational(const Rational& other) : numerator(other.numerator), denominator(other.denominator) {
    cout << "print: in copy-constructor" << endl;
}

// Set numerator
void Rational::setNumerator(int num) {
    numerator = num;
}

// Set denominator
void Rational::setDenominator(int den) {
    if (den == 0) {
        denominator = 1;
    } else {
        denominator = den;
    }
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

// Get numerator
int Rational::getNumerator() const {
    return numerator;
}

// Get denominator
int Rational::getDenominator() const {
    return denominator;
}

// Method to print the rational number
void Rational::print() const {
    cout << numerator << "/" << denominator;
}

// Method to check equality
//if top a and bottom a = top b and bottom b
bool Rational::equal(const Rational other) const {
    return numerator == other.numerator && denominator == other.denominator;
}

// Method to make two rationals equal
//setting other to value of earlier function calling object num/denom
void Rational::makeEquals(Rational& other) {
    other.numerator = numerator;
    other.denominator = denominator;
}

// Helper "stepping stone" function method for reducing the fraction
void Rational::reduce() {
    int gcd = getGCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    if (numerator == 0) {
        denominator = 1;
    }
}

// Method to add another rational
Rational Rational::add(const Rational other) const {
    //cross multiply
    int num = numerator * other.denominator + other.numerator * denominator;
    //reg mul
    int den = denominator * other.denominator;

    //new object with numbers with changed num/den
    Rational sum(num, den);

    //reduce it 
    sum.reduce();

    //return it
    return sum;
}

// Method to add one to the rational
//same as add except instead of other vlaues just use 1 instead
Rational Rational::addOne() const {
    int num = numerator * 1 + 1 * denominator;
    int den = denominator * 1;
    Rational sum(num, den);
    return sum;
}

// Private method to get the GCD of two numbers
int Rational::getGCD(int a, int b) const {
    if (b == 0) {
        return a;
    }
    return getGCD(b, a % b);
}
