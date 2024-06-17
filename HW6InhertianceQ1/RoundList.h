#ifndef ROUNDLIST_H
#define ROUNDLIST_H

#include "List.h"

class RoundList : public List {
public:
    // Default constructor
    RoundList() : List() {}

    // Methods specific to RoundList
    void addToEnd(int val);
    int search(int n) const;

    // Overriding List methods
    void add(int value) override;
    void removeFirst() override;
};

#endif // ROUNDLIST_H
