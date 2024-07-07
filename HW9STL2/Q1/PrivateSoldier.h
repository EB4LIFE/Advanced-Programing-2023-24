#pragma once
#ifndef PRIVATESOLDIER_H
#define PRIVATESOLDIER_H

#include "Soldier.h"
//inherits directly from soldier
class PrivateSoldier : public Soldier {
 //Additional attribute : Array of grades for military operations.
//Note: Deep copy is required for dynamic memory.

private:
    vector<int> grades;

public:
    
    PrivateSoldier(int id, string firstName, string lastName, int numOperations, const vector<int>& grades);
    
    PrivateSoldier(const PrivateSoldier& other);
    
    PrivateSoldier& operator=(const PrivateSoldier& other);
    
    ~PrivateSoldier();

    //helper 
    double CalcAvg() const;
    //override functions from pure
    bool medal() const override;
    void print() const override;
    string soldierType() const override;


};

#endif // PRIVATESOLDIER_H
