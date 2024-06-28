#include "Pack.h"

//Default ctor
//amount of cans =  0
//string pointer array to null 
Pack::Pack() : size(0), cans(nullptr) {}

//Parameterized ctor
//a constructor that receives one arguments (the
//number of cans in the crate) and initializes the
//object accordingly. If the provided argument is
//greater than 100 the size of the crate is to be
//initialized to 100.
Pack::Pack(int numberOfCans) {
    //i love this format its ELITE
    size = (numberOfCans > 100) ? 100 : numberOfCans;
    cans = new string[size];
}

//Copy ctor --> of the param ctor above
Pack::Pack(const Pack& other) : size(other.size), cans(new string[other.size]) {
    //copying info of cans to the copy other object 
    for (int i = 0; i < size; ++i) {
        cans[i] = other.cans[i];
    }
}

//Move constructor
//move that data from copy to reg object
//then sets eveyrthin back to def like in def ctor
Pack::Pack(Pack&& other) noexcept : size(other.size), cans(other.cans) {
    other.size = 0;
    other.cans = nullptr;
}

//Destructor
//delete the Dynaimic mem allocated + in destructor line 
Pack::~Pack() {
    delete[] cans;
    cout << "In destructor" << endl;
}

//Copy assignment operator 
//added purely for rule of 5
Pack& Pack::operator=(const Pack& other) {
    if (this == &other) {
        return *this;
    }

    delete[] cans;

    size = other.size;
    cans = new string[size];
    for (int i = 0; i < size; ++i) {
        cans[i] = other.cans[i];
    }

    return *this;
}

//Move assignment operator
//added purely for rule of 5
Pack& Pack::operator=(Pack&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    delete[] cans;

    size = other.size;
    cans = other.cans;

    other.size = 0;
    other.cans = nullptr;

    return *this;
}

//Overloaded input-op
//input names of cans in crate (size we did from param ctor)
istream& operator>>(istream& in, Pack& pack) {
    //user input names so if size 5: coke, coke, pepsi, sprite, Dr. brown
    for (int i = 0; i < pack.size; ++i) {
        in >> pack.cans[i];
    }
    return in;
}

//Overloaded output-op
//the number of cans followed by their names
//example:
/*
* Amount : 3 --> Cans : Coke Zero Sprite
*/
ostream& operator<<(ostream& out, const Pack& pack) {
    out << "Amount : " << pack.size << endl;
    out << "Cans :";
    for (int i = 0; i < pack.size; ++i) {
        out << " " << pack.cans[i];
    }
    //why no commas? or at lest endl it so output is cleaner
    out << endl;
    return out;
}

//Overloaded add-op
/*copies the content of two crates into a third crate.
The order is important: First the cans from the
calling object (left operand) are copied and only
after that the cans from the argument object (right
operand) are copied.
In the case that the combined sizes of the two
crates exceeds 100 the exception “ERROR” is to
be thrown and the third crate is not created.
*/
Pack Pack::operator+(const Pack& other) {
    if (this->size + other.size > 100) {
        throw "ERROR";
    }

    Pack result(this->size + other.size);
    for (int i = 0; i < this->size; ++i) {
        result.cans[i] = this->cans[i];
    }
    for (int i = 0; i < other.size; ++i) {
        result.cans[this->size + i] = other.cans[i];
    }

    return result;
}
