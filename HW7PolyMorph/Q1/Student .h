#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    int studentId;
    string firstName;
    string lastName;
    int numCourses;
   
  public:
    // Constructor
    Student(int id = 0, const string& first = "", const string& last = "", int courses = 0)
        : studentId(id), firstName(first), lastName(last), numCourses(courses) {}

    // Pure virtual function for input
    virtual void input() = 0;

    // Virtual function for print
    virtual void print() const = 0;

    // Virtual function for grant eligibility
    virtual bool milga() const = 0;
    
     virtual string studType() const = 0;
  

    // Virtual destructor
    virtual ~Student() {}
};

#endif // STUDENT_H
