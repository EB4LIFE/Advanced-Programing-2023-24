
#ifndef COMMANDER_H
#define COMMANDER_H

#include "PrivateSoldier.h"
//inherits from private which inherits from soldier
//Additional attribute 
//Boolean indicating if the commander is a combat soldier.
class Commander : public PrivateSoldier {

private:
    bool isCombat;

public:
    
    Commander(int id, string firstName, string lastName, int numOperations, const vector<int>& grades, bool isCombat);
    
    //virtual overrides
    bool medal() const override;
    void print() const override;
    string soldierType() const override;

    //getters and setters
    bool getCombat() const;
    void setCombat(bool iscombat);
};

#endif // COMMANDER_H
