#ifndef MA_H
#define MA_H

#include "BA.h"

// Derived class MA from BA
class MA : public BA {
private:
    bool research;

public:
    // Constructor
    MA(int id, string firstName, string lastName, int numCourses, int* grades, int gradesSize, bool research);

    // Override functions
    // Checks if student is eligible for milga
    bool milga() const override; 
    // Prints student details including research status from private so specfic to masters
    void print() const override; 
};

#endif // MA_H
