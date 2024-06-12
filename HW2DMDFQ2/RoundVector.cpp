#include "RoundVector.h"

// Constructor
RoundVector::RoundVector(int cap) : capacity(cap), head(0), tail(0) {
    Vec = new int[capacity + 1];
    cout << "in constructor" << endl;
}

// Copy constructor
RoundVector::RoundVector(const RoundVector& other) : capacity(other.capacity), head(0), tail(0) {
    Vec = new int[capacity + 1];
    for (int i = 0; i < capacity; ++i) {
        addNext(other.Vec[(other.head + i) % (capacity + 1)]);
    }
    cout << "in copy constructor" << endl;
}

// Move constructor
RoundVector::RoundVector(RoundVector&& other) noexcept : capacity(other.capacity), Vec(other.Vec), head(other.head), tail(other.tail) {
    other.Vec = nullptr;
    cout << "in move constructor" << endl;
}

// Destructor
RoundVector::~RoundVector() {
    delete[] Vec;
    cout << "in destructor" << endl;
}

// Add next element
void RoundVector::addNext(int value) {
    if ((tail + 1) % (capacity + 1) == head) {
        cout << "Vector is full" << endl;
        return;
    }
    Vec[tail] = value;
    tail = (tail + 1) % (capacity + 1);
}

// Remove first element
int RoundVector::removeFirst() {
    int value = Vec[head];
    head = (head + 1) % (capacity + 1);
    return value;
}

// Get first value
int RoundVector::firstValue() const {
    return Vec[head];
}

// Check if empty
bool RoundVector::isEmpty() {
    return head == tail;
}

// Clear the vector
void RoundVector::clear() {
    head = 0;
    tail = 0;
}

// Print the vector
void RoundVector::print() const {
    int i = head;
    while (i != tail) {
        cout << Vec[i] << "  ";
        i = (i + 1) % (capacity + 1);
    }
    cout << endl;
}
