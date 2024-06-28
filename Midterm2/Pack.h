#pragma once
#ifndef PACK_H
#define PACK_H

#include <iostream>
#include <string>
using namespace std;

class Pack {
private:
    //Number of cans in the crate
    int size;       
    //Array of cannames like coke, pepsi, MUG!!!! so must be string
    string* cans;         

public:
    //Default ctor
    Pack();

    //Parameterized ctor
    Pack(int numberOfCans);

    //Copy ctor
    Pack(const Pack& other);

    //Move ctor
    Pack(Pack&& other) noexcept;

    //Destructor
    ~Pack();

    //Copy assignment operator
    //added purely for rule of 5
    Pack& operator=(const Pack& other);

    // Move assignment operator
    //added purely for rule of 5
    Pack& operator=(Pack&& other) noexcept;

    //Overloaded input-op
    friend istream& operator>>(istream& in, Pack& pack);

    //Overloaded output-op
    friend ostream& operator<<(ostream& out, const Pack& pack);

    //Overloaded add-op
    Pack operator+(const Pack& other);
};

#endif // PACK_H



