#include "PHD.h"

// Input method
void PHD::input() {
    cout << "enter id, first name, last name, number of courses\n";
    cin >> studentId >> firstName >> lastName >> numCourses;
    cout << "enter number of research hours" << endl;
    cin >> hoursInResearch;
}

// Print method
void PHD::print() const {
    cout << "ID:\t" << studentId << endl;
    cout << "Name:\t" << firstName << " " << lastName << endl;
    //cout << "num courses: " << numCourses << endl;
    cout << "number of research Hours:\t" << hoursInResearch << endl;
}

// Grant eligibility method
bool PHD::milga() const {
    return numCourses >= 2 && hoursInResearch > 25;
}

string PHD::studType() const  {
        return "PhD student\n";
    }
