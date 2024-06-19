#include "MA.h"

// Input method
void MA::input() {
    BA::input();
    cout << "enter 1 if the student does research and 0 if not" << endl;
    cin >> writingThesis;
}

// Print method
void MA::print() const {
    BA::print();
    cout << "research:\t" << (writingThesis ? "1" : "0") << endl;
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
