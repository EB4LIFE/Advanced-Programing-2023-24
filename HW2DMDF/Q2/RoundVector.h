// Eitan Brown
// 346816549
#pragma once
#ifndef ROUNDVECTOR_H
#define ROUNDVECTOR_H

#include <iostream>
using namespace std;

class RoundVector {
private:
    int capacity;
    int* Vec;
    int head;
    int tail;

public:
    RoundVector(int cap);
    RoundVector(const RoundVector& other);
    RoundVector(RoundVector&& other) noexcept;
    ~RoundVector();

    void addNext(int value);
    int removeFirst();
    int firstValue() const;
    bool isEmpty();
    void clear();
    void print() const;
};

#endif // ROUNDVECTOR_H
