#include "BA.h"
#include <iostream>

using namespace std;

// Constructor definition
BA::BA(int id, string firstName, string lastName, int numCourses, int* grades, int gradesSize)
    : Student(id, firstName, lastName, numCourses), gradesSize(gradesSize) {
    // DMA for grades array and copy values from grades parameter
    this->grades = new int[gradesSize];
    for (int i = 0; i < gradesSize; i++) {
        this->grades[i] = grades[i];
    }
}

// Destructor definition
BA::~BA() {
    //DMA for grades array
    delete[] grades;
}

// Override function milga() definition
bool BA::milga() const {
    // Check if the student has taken at least 10 courses
    if (numCourses < 10) {
      return false;
    }
    // Calculate the sum of grades
    int sum = 0;
    for (int i = 0; i < gradesSize; i++) {
        sum += grades[i];
    }

    // Calculate the average grade using static_cast to ensure floating point division is done properly and looked it up
    //and is indded needed 
    double avg = sum / static_cast<double>(gradesSize);

    // Determine if the student qualifies for milga (average grade > 95)
    return avg > 95;
}

// Override function print() definition
//remainging const and print like it did in students
void BA::print() const {
    cout << "ID: " << id << endl;
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Number of Courses: " << numCourses << endl;
    cout << "Grades: ";
    for (int i = 0; i < gradesSize; i++) {
        cout << grades[i] << " ";
    }
    cout << endl;
}

