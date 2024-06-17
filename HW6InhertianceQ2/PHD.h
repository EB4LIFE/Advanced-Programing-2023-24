#ifndef PHD_H
#define PHD_H

#include "Student.h"

//child of students
class PHD : public Student {
private:
    //private and spefic to pHD students
    int researchHours;

public:
    // Constructor
    PHD(int id, string firstName, string lastName, int numCourses, int researchHours);

    // Override functions
    // Checks if student is eligible for milga
    bool milga() const override; 
    // Prints student details including research hours
    void print() const override; 
};

#endif // PHD_H
