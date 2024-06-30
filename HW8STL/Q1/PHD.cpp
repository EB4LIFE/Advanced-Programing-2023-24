#include "PHD.h"
#include <string>
#include <typeinfo> 

// Input method
void PHD::input() {
    cout << "enter id, first name, last name, number of courses\n";
    cin >> studentId >> firstName >> lastName >> numCourses;
    cout << "enter number of research hours" << endl;
    cin >> hoursInResearch;
}

// Print method
void PHD::print() const {
     if (milga()) {
      cout << studType() << " *** Scholarship ***\n";
     }
     else {
        cout << studType() << endl;
     }
      cout << "ID:\t" << studentId << endl;
      cout << "Name:\t" << firstName << " " << lastName << endl;
      //cout << "num courses: " << numCourses << endl;
      cout << "number of research Hours:\t" << hoursInResearch << endl;
      cout << endl;
}

// Grant eligibility method
bool PHD::milga() const {
    return numCourses >= 2 && hoursInResearch > 25;
}

string PHD::studType() const  {
        return "PhD student";
    }
bool PHD::operator<(const Student& rhs) const {
    // Check if comparing students of different types
    if (typeid(*this) != typeid(rhs)) {
        throw string("cannot compare students of different types");
    }

    // Downcast rhs to PHD
    const PHD& other = dynamic_cast<const PHD&>(rhs);

    // Compare grant eligibility
    if (!milga() && other.milga()) {
        return true;  // *this is ineligible, rhs is eligible
    } else if (milga() && !other.milga()) {
        return false; // *this is eligible, rhs is ineligible
    } else {
        // Both eligible or both ineligible, compare research hours
        return (hoursInResearch < other.hoursInResearch);
    }
}