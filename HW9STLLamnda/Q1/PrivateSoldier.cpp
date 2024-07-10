#include "PrivateSoldier.h"

//param ctor with added for soldier since it is inherit like for class
//we go child:parent in ctor we also do child : parent
PrivateSoldier::PrivateSoldier(int id, string firstName, string lastName, int numOperations, const vector<int>& grades)
    : Soldier(id, firstName, lastName, numOperations), grades(grades) {}

//copy -> only needs to copy this classes param which is
//grades
PrivateSoldier::PrivateSoldier(const PrivateSoldier& other) : Soldier(other) {
    grades = other.grades;
}

//assignment op
//we first confirm not the same object
//call base class
PrivateSoldier& PrivateSoldier::operator=(const PrivateSoldier& other) {
    if (this != &other) {
        Soldier::operator=(other);
        grades = other.grades;
    }
    return *this;
}
//destructor
PrivateSoldier::~PrivateSoldier() {}

//overrided function
//has medal:Participated in at least 10 military 
//operations with an average score above 95.
//otherwise false
bool PrivateSoldier::medal() const {
    if (numOperations >= 10) {
        return(CalcAvg() >= 95);
    }
    return false;
}
//helper average function
double PrivateSoldier::CalcAvg() const {
    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    return static_cast<double>(sum) / grades.size();
}
//4 basic attributes + grades
void PrivateSoldier::print() const {
    cout << soldierType() << endl;
    Soldier::print();
    if (grades.size() > 0) {
        cout << "grades: ";
        for (int grade : grades) {
            cout << grade << " ";
        }
        cout << endl;
    }
}
//return soldier type - private
string PrivateSoldier::soldierType() const {
    return "private";
}
