#include "PHD.h"
#include <iostream>

using namespace std;

// Constructor definition
PHD::PHD(int id, string firstName, string lastName, int numCourses, int researchHours)
    : Student(id, firstName, lastName, numCourses), researchHours(researchHours) {
    //empty 
}

// Override function milga() definition
bool PHD::milga() const {
    // Check if the student has taken at least 2 courses and has more than 25 research hours with is nessary for PHD 
    return numCourses >= 2 && researchHours > 25;
  //for pHD no need to cheg avg
}

// Override function print() 
void PHD::print() const {
    
    cout << "ID: " << id << endl;
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Number of Courses: " << numCourses << endl;
    cout << "Research Hours: " << researchHours << endl;
}

