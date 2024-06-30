#include "BA.h"
#include <iostream>
#include <typeinfo> // For typeid

// Default constructor
BA::BA() : Student(), grades() {}

BA::~BA() {}

// Parameterized constructor
BA::BA(int id, const string& first, const string& last, int courses, const vector<int>& grades)
    : Student(id, first, last, courses), grades(grades) {}

// Destructor
//BA::~BA() {}

// Copy constructor
BA::BA(const BA& other) : Student(other), grades(other.grades) {}

// Copy assignment operator
BA& BA::operator=(const BA& other) {
    if (this != &other) {
        Student::operator=(other);
        grades = other.grades;
    }
    return *this;
}

// Move constructor
BA::BA(BA&& other) noexcept : Student(move(other)), grades(move(other.grades)) {
    other.grades.clear(); // Clear the other object's data
}

// Move assignment operator
BA& BA::operator=(BA&& other) noexcept {
    if (this != &other) {
        Student::operator=(move(other));
        grades = move(other.grades);
        other.grades.clear(); // Clear the other object's data
    }
    return *this;
}

// Input method
void BA::input() {
    cout << "Enter id, first name, last name, number of courses: ";
    cin >> studentId >> firstName >> lastName >> numCourses;
    grades.resize(numCourses);
    cout << "\nand enter a list of student grades:" << endl;
    for (int i = 0; i < numCourses; ++i) {
        cin >> grades[i];
    }
}

// Print method
void BA::print() const {
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
    cout << endl;
   }

// Calculate average grade
double BA::calculateAverage() const {
    if (numCourses < 1) {
        return 0; // Handle edge case where there are no grades
    }

    double total = 0;
    for (int grade : grades) {
        total += grade;
    }
    return total / numCourses;
}

// Grant eligibility
bool BA::milga() const {
    double average = calculateAverage();
    return (numCourses >= 10 && average > 95);
}

// Student type
string BA::studType() const {
    return "BA student";
}

// Comparison operator
bool BA::operator<(const Student& rhs) const {
    // Check if comparing students of different types
    if (typeid(*this) != typeid(rhs)) {
        throw string("Cannot compare students of different types");
    }

    // Downcast rhs to BA
    const BA& other = dynamic_cast<const BA&>(rhs);

    // Compare grant eligibility
    if (!milga() && other.milga()) {
        return true;  // *this is ineligible, rhs is eligible
    } else if (milga() && !other.milga()) {
        return false; // *this is eligible, rhs is ineligible
    } else {
        // Both eligible or both ineligible, compare grade averages
        return (calculateAverage() < other.calculateAverage());
    }
}

// Protected accessor for grades
const vector<int>& BA::getGrades() const {
    return grades;
}
