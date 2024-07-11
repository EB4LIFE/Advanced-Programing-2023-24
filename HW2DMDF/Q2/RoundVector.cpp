#include "RoundVector.h"

// Constructor: receives the maximum possible number of elements to be stored
//in the array. Initializes capacity and dynamically allocates vec to be
//capacity+1.
RoundVector::RoundVector(int cap) : capacity(cap), head(0), tail(0) {
    Vec = new int[capacity + 1];
    cout << "in constructor" << endl;
}

// Copy constructor:
/*receives an existing RoundVector (a cbr & const) and
initializes the RoundVector being constructed with the same values:
o The capacity must be the same and the allocation must be capacity+1.
o The values are copied sequentially so that the first is put in index 0. The
values of head and tail are to be set accordingly (not necessarily the
same as the source).*/
RoundVector::RoundVector(const RoundVector& other) : capacity(other.capacity), head(0), tail(0) {
    Vec = new int[capacity + 1];
    for (int i = 0; i < capacity; ++i) {
        addNext(other.Vec[(other.head + i) % (capacity + 1)]);
    }
    cout << "in copy constructor" << endl;
}

// Move constructor: 
/*receives an existing RoundVector (a cbr &&) and
initializes the RoundVector being constructed with the same values: all values
are to be identical including the address stored in vec. The source vec should be
set to nullptr.*/
RoundVector::RoundVector(RoundVector&& other) noexcept : capacity(other.capacity), Vec(other.Vec), head(other.head), tail(other.tail) {
    other.Vec = nullptr;
    cout << "in move constructor" << endl;
}

// Destructor: Delete DMA
RoundVector::~RoundVector() {
    delete[] Vec;
    cout << "in destructor" << endl;
}

// Add next element: an insertion method as described above. The method receives a
//number and inserts it at the tail of the array if the array is not full. If the array is
//full the following output will be printed: “Vector is full”.
void RoundVector::addNext(int value) {
    if ((tail + 1) % (capacity + 1) == head) {
        cout << "Vector is full" << endl;
        return;
    }
    Vec[tail] = value;
    tail = (tail + 1) % (capacity + 1);
}

// Remove first element: a removal method that removes the head element as described
//above. The method is to return the removed element. Note: Assume the array is
//not empty. At this stage no test will be done to check if the array is empty –
//such a test will be added after we study exceptions
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
