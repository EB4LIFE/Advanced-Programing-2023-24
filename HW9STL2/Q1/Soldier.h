#pragma once
#ifndef SOLDIER_H
#define SOLDIER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Soldier {
    //Attributes: ID, first name, last name, 
    //number of operations participated.
protected:
    int id;
    string firstName;
    string lastName;
    int numOperations;

public:
    /*
    * 
    Constructor to initialize attributes.
    Virtual destructor.
    bool medal() to check if the soldier deserves a medal.
    void print() to print soldier details.
    string soldierType() to return the soldier type ("private", "commander", "officer").
    */
    Soldier(int id, string firstName, string lastName, int numOperations);
    //will be overrided so keep empty 
    virtual ~Soldier();
    //pure virtual
    virtual bool medal() const = 0;
    virtual void print() const;
    virtual string soldierType() const = 0;
    //getters and setters bitches

    int getId() const;
    void setId(int id);
    string getFirstName() const;
    void setFirstName(const string& firstName);
    string getLastName() const;
    void setLastName(const string& lastName);
    int getNumOperations() const;
    void setNumOperations(int numOperations);

};

#endif // SOLDIER_H
