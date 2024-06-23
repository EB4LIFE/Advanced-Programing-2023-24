#include "AddStudent.h"
#include "BA.h"
#include "MA.h"
#include "PHD.h"
#include <stdexcept> 
#include <iostream>
using namespace std;

int main () {
   int numstudents;
   
   cout << "Enter the number of students: ";
   cin >> numstudents;
   
   
   // Pointer to an array of Student pointers for the array with size of chosen students
    Student** students = new Student*[numstudents];
    
    //Make a for loop with 'n' with the numstudents size
    for(int i = 0; i < numstudents; ++i) {
       //we will include a flag for invalid input for exceptions
       bool Valid = false;
       while(!Valid) {
          try {
              // Call addStudent to create and input student
             students[i] = addStudent();
              Valid = true;
          } catch (...) { 
                cout << "Error: Invalid input. Please try again." << endl;
            }
       }
    }
   //now we print who of choses students are eligible
   cout << "Students entitled for milga are:" << endl;
   //counter condition for students
   int goodstudents = 0;
   //for loop to itterrate through students array to check condtions 
   for (int i = 0; i < numstudents; ++i) {
      if (students[i]->milga()) {
            students[i]->print();
            ++goodstudents;
        }
        
   }
   if(goodstudents == 0) {
      cout << "No student was good enough." << endl;
   }
   
   // Free dynamically allocated memory first index then ptr
    for (int i = 0; i < numstudents; ++i) {
        delete students[i];
    }
    delete[] students;

    return 0;
}
