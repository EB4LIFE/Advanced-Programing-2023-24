#include "MA.h"

// Input method
void MA::input() {
    BA::input();
    cout << "enter 1 if the student does research and 0 if not" << endl;
    cin >> writingThesis;
}

// Print method
void MA::print() const {
    if (milga()) {
        cout << studType() << " *** Scholarship ***\n";
    }
    else {
       cout << studType() << endl;
    }
    cout << "ID:\t" << studentId << endl;
    cout << "Name:\t" << firstName << " " << lastName << endl;
    cout << "Grades: ";
    for (int grade : grades) {
        cout << grade << " ";
    }
    cout << endl;
    cout << "Average: " << calculateAverage() << endl;
    cout << "research:\t" << (writingThesis ? "YES" : "NO") << endl;
    cout << endl;
}

// Grant eligibility method
bool MA::milga() const {
    if (numCourses < 7 || !writingThesis) {
        return false;
    }
    double average = 0;
    for (int grade : getGrades()) {
        average += grade;
    }
    average /= numCourses;
    return average > 90;
}

string MA::studType() const  {
        return "MA student";
    }
