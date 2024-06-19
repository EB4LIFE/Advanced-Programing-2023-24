#ifndef BA_H
#define BA_H

#include "Student.h"

// Child class BA from Student
class BA : public Student {
private:
    int* grades;
    int gradesSize;

public:
    // Constructor
    BA(int id, string firstName, string lastName, int numCourses, int* grades, int gradesSize);

    // Destructor
    ~BA();

    // Override functions
    //a member function that overrides a virtual function and is itself declared as const, meaning it does not modify the object's state.
    //Essentialy keeps themm const throughout all 'child' files (no perfectly needed but helps with bugs) 
    bool milga() const override; // Checks if student is eligible for milga
    void print() const override; // Prints student details
};

#endif // BA_H
