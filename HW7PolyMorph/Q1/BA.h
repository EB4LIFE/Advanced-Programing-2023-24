#ifndef BA_H
#define BA_H
#include "Student.h"
#include <vector>

class BA : public Student {
protected:
    vector<int> grades;

public:
    // Default constructor
    BA() : Student(), grades() {}

    // Parameterized constructor
    BA(int id, const string& first, const string& last, int courses, const vector<int>& grades)
        : Student(id, first, last, courses), grades(grades) {}

    // Input method
    void input() override;

    // Print method
    void print() const override;

    // Grant eligibility method
    bool milga() const override;
    
    string studType() const override;
    
protected:
    // Protected accessor for grades
    const vector<int>& getGrades() const { 
       return grades; 
           }
};

#endif // BA_H
