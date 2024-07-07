#pragma once
#ifndef OFFICER_H
#define OFFICER_H

#include "Soldier.h"
//inherits dierctly from soldier
class Officer : public Soldier {
private:
    int sociometricScore;

public:
    
    Officer(int id, string firstName, string lastName, int numOperations, int sociometricScore);
    
    //vrituals
    bool medal() const override;
    void print() const override;
    string soldierType() const override;

    //specficaly for this class
    int getSociometricScore() const;
};

#endif // OFFICER_H

