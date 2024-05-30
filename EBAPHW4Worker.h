//eitan brown 346816549
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

    // Friend functions - new
    friend bool operator==(long left, const Worker& right) {
        return left == right.id;
    }

    friend bool operator==(const string& left, const Worker& right) {
        return left == right.name;
    }

    friend istream& operator>>(istream& input, Worker& worker) {
        input >> worker.id >> worker.name >> worker.wages;
        return input;
    }

    friend ostream& operator<<(ostream& output, const Worker& worker) {
        output << worker.id << " " << worker.name << " " << worker.wages;
        return output;
    }
};
#endif
