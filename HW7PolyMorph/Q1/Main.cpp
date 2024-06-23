#include "AddStudent.h"
#include "BA.h"
#include "MA.h"
#include "PHD.h"
#include <exception>
#include <iostream>
using namespace std;

int main () {
   int numstudents;
   
   cout << "Enter the number of students: " << endl;
   cin >> numstudents;
   
   
   // Pointer to an array of Student pointers for the array with size of chosen students
    Student** students = new Student*[numstudents];
    
    //Make a for loop with 'n' with the numstudents size
    for(int i = 0; i < numstudents; ++i) {
        cout<< "\nStudent " << (i+1) << " of " << numstudents << endl;
       //we will include a flag for invalid input for exceptions
       bool Valid = false;
       while(!Valid) {
          try {
              // Call addStudent to create and input student
             students[i] = addStudent();
              Valid = true;
          } catch (const string& e) {
                cout << e << endl;
                cout<< "\nStudent " << (i+1) << " of " << numstudents << endl;
            }
       }
    }
    
   //now we print who of choses students are eligible
   cout << "\nStudents entitled for milga are:" << endl;
   cout << endl;
   //counter condition for students
  // int goodstudents = 0;
   //for loop to itterrate through students array to check condtions 
   for (int i = 0; i < numstudents; ++i) {
      if (students[i]->milga()) {
            
            cout << students[i]->studType();
            students[i]->print();
            cout << endl;
        }
        
   }
   /*
   if(goodstudents == 0) {
      cout << "No student was good enough." << endl;
   }
   */
   
   // Free dynamically allocated memory first index then ptr
    for (int i = 0; i < numstudents; ++i) {
        delete students[i];
    }
    delete[] students;

    return 0;
}
