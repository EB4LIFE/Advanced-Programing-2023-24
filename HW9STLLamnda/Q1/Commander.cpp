#include "Commander.h"

//same as before child : parent with added attribute
Commander::Commander(int id, string firstName, string lastName, int numOperations, const vector<int>& grades, bool isCombat)
    : PrivateSoldier(id, firstName, lastName, numOperations, grades), isCombat(isCombat) {}

//will return true if they have the medal that was described 
bool Commander::medal() const {
    double C_avg = PrivateSoldier::CalcAvg();
    if ((C_avg > 90) && numOperations >= 7 && (isCombat)) {
        return true;
    }
    return false;
}
bool Commander::getCombat() const {
    return isCombat;
}
void Commander::setCombat(bool isCombat) {
    this->isCombat = isCombat;
}

void Commander::print() const {
    PrivateSoldier::print();
    cout << "Combat: " << (isCombat ? "Yes" : "No") << endl;
}

string Commander::soldierType() const {
    return "commander";
}
