#include "Soldier.h"

//param ctor setting the values of def in the ctor
Soldier::Soldier(int id, string firstName, string lastName, int numOperations)
    : id(id), firstName(firstName), lastName(lastName), numOperations(numOperations) {}
//blank dtor
Soldier::~Soldier() {
}

//print function for variables
void Soldier::print() const {
    cout << "ID: " << id << endl;
    cout << "first Name: " << firstName << endl;
    cout << "last Name: " << lastName << endl; 
    cout << "Num operations: " << numOperations << endl;
}

//getters and setter

int Soldier::getId() const {
    return id;
}


void Soldier::setId(int id) {
    this->id = id;
}


string Soldier::getFirstName() const {
    return firstName;
}

void Soldier::setFirstName(const string& firstName) {
    this->firstName = firstName;
}


string Soldier::getLastName() const {
    return lastName;
}


void Soldier::setLastName(const string& lastName) {
    this->lastName = lastName;
}


int Soldier::getNumOperations() const {
    return numOperations;
}


void Soldier::setNumOperations(int numOperations) {
    this->numOperations = numOperations;
}
