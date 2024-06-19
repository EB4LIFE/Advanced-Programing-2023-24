#include "MA.h"
#include <iostream>

using namespace std;

// Constructor definition
MA::MA(int id, string firstName, string lastName, int numCourses, int* grades, int gradesSize, bool research)
    : BA(id, firstName, lastName, numCourses, grades, gradesSize), research(research) {
      //empty
   }

// Override function milga() definition
//emains const and adds more since its a step above Bachlors degree but logic is the same
bool MA::milga() const {
    // Check if the student has taken at least 7 courses
    if (numCourses < 7) {
      return false;
    }
    // Check if the student has done research
    if (!research) {
      return false;
    }
    // Calculate the sum of grades
    int sum = 0;
    for (int i = 0; i < gradesSize; i++) {
        sum += grades[i];
    }

    // Calculate the average grade using floating-point division
    double avg = sum / static_cast<double>(gradesSize);

    // Determine if the student qualifies for milga (average grade > 90)
    return avg > 90;
}

// Override function print() definition
//remain const and with added for masters specfic
void MA::print() const {
    // regular print() to print basic student details like usual
    BA::print();
    // Print research status
    cout << "Research: " << (research ? "Yes" : "No") << endl;
}

