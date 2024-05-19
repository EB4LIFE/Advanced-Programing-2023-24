//eitan brown
//346816549
#pragma once
#ifndef ROUNDVECTOR_H
#define ROUNDVECTOR_H
#include <iostream>
using namespace std;

class RoundVector() {
  
private:
  int capacity;
  //the maximum number of elements that can be stored in the array.
  //The actual number of elements will be less than or equal to capacity.
  int* Vec;
  //a pointer containing the address of an integer array size capacity+1. As
 //explained above: the extra space is to determine if the array is full (with
//capacity elements) or empty (with no elements).
  int head;
  //– the index of the next element to be removed from the array.
  int tail;
  // – the index of the next available space in the array. The next element to be added to the array will be put here.
public:
  //constructor 
  RoundVector(int cap) : capacity(cap), head(0), tail (0) {
  vec = new int[capacity + 1];
  cout << "in constructor" << endl;
    }
  //copy ctor
  RoundVector(const RoundVector& other) : capacity(other.capacity), head(0), tail (0) {
  vec = new int[capacity + 1];
  for (int i = 0; i < capacity; ++i) {
  addNext(other.vec[(other.head + i) % (capacity + 1)]);
  }
  cout << "in copy constructor" << endl;
  }
  //move ctor
  RoundVector(RoundVector&& other) noexcept : capacity(other.capacity), vec(other.vec), head(other.head), tail(other.tail) {
  other.vec = nullptr;
  cout << "in move constructor" << endl;
  }
  //destructor
  ~RoundVector() {
  delete[] vec;
  cout << "in destructor" << endl;
  }
  //methods 
   //an insertion method as described above. The method receives a 
  //number and inserts it at the tail of the array if the array is not full. If the array is
  //full the following output will be printed: “Vector is full”.
  addNext(int value) {
    //meaning full
    if ((tail + 1) % (capacity + 1) == head) {
    cout << "Vector is full" << endl;
    return;
    }
    //otherwise...
    vec[tail] = value;
    tail = (tail + 1) % (capacity + 1);
  }

//a removal method that removes the head element as described 
//above. The method is to return the removed element. 
removeFirst() {
  int value = vec[head];
  head = (head + 1) % (capacity + 1);
  return value;
}

//returns the head element without removing it
 firstValue() const {
  return vec[head];
 }
 //a boolean method the returns true if the array contains no elements.
 bool isEmpty() {
   //if head == tail it means it is empty so true
   return head == tail;
   }
  //a method that empties the array. It is not required to modify in any way
  //the contents of the array – just zero the head and tail.
 void clear() {
   head = 0;
   tail = 0;
 }

 //a method that prints the elements contained in the array from the head
  //to the tail. Each two elements are to be separated by a space and the printing is
  //to be terminated by an end line.
 void print () const {
   int i = head;
   //as long as the index is not the tail we continue to add  number into vec array
   while (i != tail) {
            cout << vec[i] << "  ";
            i = (i + 1) % (capacity + 1);
        }
        cout << endl;
    } 
 };
#endif
