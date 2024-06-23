#ifndef MA_H
#define MA_H

#include "BA.h"

class MA : public BA {
private:
    bool writingThesis;

public:
    // Default constructor
    MA() : BA(), writingThesis(false) {}

    // Parameterized constructor
    MA(int id, const string& first, const string& last, int courses, const vector<int>& grades, bool thesis)
        : BA(id, first, last, courses, grades), writingThesis(thesis) {}

    // Input method
    void input() override;

    // Print method
    void print() const override;

    // Grant eligibility method
    bool milga() const override;
    
    string studType() const override;
    
};

#endif // MA_H
