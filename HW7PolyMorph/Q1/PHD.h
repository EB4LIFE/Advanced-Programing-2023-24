#ifndef PHD_H
#define PHD_H

#include "Student.h"

class PHD : public Student {
private:
    int hoursInResearch;

public:
    // Default constructor
    PHD() : Student(), hoursInResearch(0) {}

    // Parameterized constructor
    PHD(int id, const string& first, const string& last, int courses, int hours)
        : Student(id, first, last, courses), hoursInResearch(hours) {}

    // Input method
    void input() override;

    // Print method
    void print() const override;

    // Grant eligibility method
    bool milga() const override;
    
    string studType() const override;
};

#endif // PHD_H
