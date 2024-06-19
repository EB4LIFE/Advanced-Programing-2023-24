#include "Rational.h"

// GCD Helper function
int Rational::getgcd(int a, int b) const {
    if (b == 0) {
        return a;
    }
    return getgcd(b, a % b);
}

// Default constructor
Rational::Rational() : numerator(1), denominator(1) {
}

// Assignment constructor
Rational::Rational(int num, int denom) {
    numerator = num;
    if (denom == 0) {
        denominator = 1;
    } else if (denom < 0) {
        numerator = -numerator;
        denominator = -denom;
    } else {
        denominator = denom;
    }
}

// Copy constructor
Rational::Rational(const Rational &other) : numerator(other.numerator), denominator(other.denominator) {
}

// Set the numerator
void Rational::setNumerator(int num) {
    numerator = num;
}

// Set the denominator
void Rational::setDenominator(int denom) {
    if (denom == 0) {
        denominator = 1;
    } else if (denom < 0) {
        numerator = -numerator;
        denominator = -denom;
    } else {
        denominator = denom;
    }
}

// Get the numerator
int Rational::getNumerator() const {
    return numerator;
}

// Get the denominator
int Rational::getDenominator() const {
    return denominator;
}

// Reduce the fraction
void Rational::reduce() {
    int gcd = getgcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    if (numerator == 0) {
        denominator = 1;
    }
}

// Print the rational number
void Rational::print() const {
    if (denominator == 1) {
        cout << numerator;
    } else {
        cout << numerator << "/" << denominator;
    }
}

// Operator overloading
Rational Rational::operator+(Rational other) {
    Rational result(numerator * other.denominator + other.numerator * denominator,
                    denominator * other.denominator);
    result.reduce();
    return result;
}

Rational Rational::operator-(Rational other) {
    Rational result(numerator * other.denominator - other.numerator * denominator,
                    denominator * other.denominator);
    result.reduce();
    return result;
}

Rational Rational::operator*(Rational other) {
    Rational result(numerator * other.numerator, denominator * other.denominator);
    result.reduce();
    return result;
}

Rational Rational::operator/(Rational other) {
    Rational result(numerator * other.denominator, denominator * other.numerator);
    result.reduce();
    return result;
}

// Increment and decrement operators
Rational& Rational::operator++() {
    numerator += denominator;
    return *this;
}

Rational Rational::operator++(int) {
    Rational temp(*this);
    numerator += denominator;
    return temp;
}

Rational& Rational::operator--() {
    numerator -= denominator;
    return *this;
}

Rational Rational::operator--(int) {
    Rational temp(*this);
    numerator -= denominator;
    return temp;
}

// Comparison operators
bool Rational::operator==(const Rational &other) const {
    Rational temp1(*this);
    Rational temp2(other);
    temp1.reduce();
    temp2.reduce();
    return (temp1.numerator == temp2.numerator) && (temp1.denominator == temp2.denominator);
}

bool Rational::operator!=(const Rational &other) const {
    return !(*this == other);
}

bool Rational::operator<(Rational other) {
    return (numerator * other.denominator) < (other.numerator * denominator);
}

bool Rational::operator<=(Rational other) {
    return (numerator * other.denominator) <= (other.numerator * denominator);
}

bool Rational::operator>(Rational other) {
    return (numerator * other.denominator) > (other.numerator * denominator);
}

bool Rational::operator>=(Rational &other) {
    return (numerator * other.denominator) >= (other.numerator * denominator);
}
