#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    int id;
    string firstName;
    string lastName;
    int numCourses;
public:
    Student(int id, string firstName, string lastName, int numCourses) 
        : id(id), firstName(firstName), lastName(lastName), numCourses(numCourses) {}
    
    virtual void print() const = 0; // pure virtual function
    virtual bool milga() const = 0; // pure virtual function
};

