#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

// Base abstract class representing a student
class Student {
protected:
    int id;
    string firstName;
    string lastName;
    int numCourses;

public:
    // Constructor
    Student(int id, string firstName, string lastName, int numCourses);

    // Pure virtual functions only to be derived in child classes
     // Prints student details
    virtual void print() const = 0;
    // Checks if student is eligible for milga
    virtual bool milga() const = 0; 

    // Virtual destructor 
    virtual ~Student() {}
};

#endif // STUDENT_H


