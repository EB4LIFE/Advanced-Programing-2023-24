#include "Officer.h"

//same as before child : parent with added attribute
Officer::Officer(int id, string firstName, string lastName, int numOperations, int sociometricScore)
    : Soldier(id, firstName, lastName, numOperations), sociometricScore(sociometricScore) {}


bool Officer::medal() const {
    if ((sociometricScore >= 92) && (numOperations > 2)) {
        return true;
    }
    return false;
}

void Officer::print() const {
    cout << soldierType() << endl;
    Soldier::print();
    cout << "Sociometric Score: " << sociometricScore << endl;
}

string Officer::soldierType() const {
    return "officer";
}

int Officer::getSociometricScore() const {
    return sociometricScore;
}
