#include "BA.h"

// Input method
void BA::input() {
    cout << "enter id, first name, Last name, number of courses\n";
    cin >> studentId >> firstName >> lastName >> numCourses;
    grades.resize(numCourses);
    cout << "and enter a list of student grades" << endl;
    for (int i = 0; i < numCourses; ++i) {
        cin >> grades[i];
    }
}

// Print method
void BA::print() const {
    cout << "ID:\t" << studentId << endl;
    cout << "Name:\t" << firstName << " " << lastName << endl;
    //cout << "num courses: " << numCourses << endl;
    cout << "grades: ";
    for (int grade : grades) {
        cout << grade << " ";
    }
    cout << endl;
}

// Grant 
bool BA::milga() const {
    if (numCourses < 10) {
        return false;
    }
    double average = 0;
    for (int grade : grades) {
        average += grade;
    }
    average /= numCourses;
    return average > 95;
}

string BA::studType() const  {
        return "BA";
    }