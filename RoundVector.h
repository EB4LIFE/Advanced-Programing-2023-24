//eitan brown
//346816549
#pragma once
#ifndef ROUNDVECTOR_H
#define ROUNDVECTOR_H
#include <iostream>
using namespace std;

class RoundVector () {
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
  cout << "in constructor” << endl;
  //copy ctor
  cout << "in copy constructor” << endl;
  //move ctor
  cout << "in move constructor” << endl;
  //destructor
  cout << "in destructor" << endl;


  //methods 
  addNext 
  //an insertion method as described above. The method receives a 
  //number and inserts it at the tail of the array if the array is not full. If the array is
  //full the following output will be printed: “Vector is full”.
removeFirst 
  //a removal method that removes the head element as described 
  //above. The method is to return the removed element. Note: Assume the array is 
  //not empty. At this stage no test will be done to check if the array is empty –
  //such a test will be added after we study exceptions.
 firstValue 
  //returns the head element without removing it. Note: Assume the
  //array is not empty. At this stage no test will be done to check if the array is
  //empty – such a test will be added after we study exceptions.
 isEmpty 
  //a boolean method the returns true if the array contains no elements.
 clear 
  //a method that empties the array. It is not required to modify in any way
  //the contents of the array – just zero the head and tail.
 print 
  //a method that prints the elements contained in the array from the head
  //to the tail. Each two elements are to be separated by a space and the printing is
  //to be terminated by an end line.

};

#endif
