//eitan brown 346816549
#pragma once
#ifndef WORKER_H
#define WORKER_H
#include <iostream>
#include <string>
using namespace std;

class Worker {
//by default 
private:
    long id;       
    // Positive id number, greater than 0, doesn’t begin with 0
    string name;   
    // The worker’s name, no spaces
    float wages;   
    // Monthly wages, greater than 0

public:

    // Default ctor and setting everything to 0 
    Worker() : id(0), name(""), wages(0.0) {
     
    }
    
    //operator+=
    //Receives a float argument that represents a bonus 
    //Updates the Worker instance so that the bonus is added to the wages.
    //Returns a reference to the updated worker.
    Worker& operator+=(float bonus) {
        wages += bonus;
        //new value
        return *this;
    }
      
    //operator<
    //Receives another Worker as a right operand (const and &).
    //Returns true if the left operand wages are less than the right operand
    //wages. Otherwise returns false.
    bool operator<(const Worker& other) const {
        //this worker wages < other worker
        return this->wages < other.wages;
    }

    // Friend functions - new stuff 
    //eqality to left operand type long
    //Receives a Worker as a right operand (const and &).
    //Returns true if the id numbers of both operands are equal. Otherwise
    //returns false.
    friend bool operator==(long left, const Worker& right) {
        return left == right.id;
    }
    //eqality to left operand type string
    //Receives a Worker as a right operand (const and &).
    //Returns true if the nanmeof both operands are equal. Otherwise
    //returns false.
    friend bool operator==(const string& left, const Worker& right) {
        return left == right.name;
    }
    //input from itream& aka cin
    // Receives a Worker as a right operand (const and &).
    //Inputs the values of the three fields (consecutively, separated by spaces)
    //into the Worker instance.
    //Returns a reference to the input object (istream&).
    friend istream& operator>>(istream& input, Worker& worker) {
        input >> worker.id >> worker.name >> worker.wages;
        return input;
    }
    //output from ostream& aka cout
    //Receives a Worker as a right operand (const and &).
    //Outputs the values of the three fields (consecutively, separated by
    //spaces) from the Worker instance.
    //Returns a reference to the output object (ostream&).
    friend ostream& operator<<(ostream& output, const Worker& worker) {
        output << worker.id << " " << worker.name << " " << worker.wages;
        return output;
    }
};
#endif
