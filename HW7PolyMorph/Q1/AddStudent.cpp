#include "AddStudent.h"
#include "BA.h"
#include "MA.h"
#include "PHD.h"
#include <stdexcept> 
#include <iostream>
using namespace std;

// Function to add a student
//The object of the function is to allow the user to choose the type of student to
//input (1 for BA, 2 for MA and 3 for PHD) and to return the address of a new
//dynamic allocation of the correct type.
//After the dynamic allocation the method must call the input method so that the
//program will input student data the matches the student type.
//If the user chooses an invalid choice the function must throw an exception.

Student* addStudent() {
    int choice;
    cout << "Enter degree: 1 for BA, 2 for MA, or 3 for PhD" << endl;
    cin >> choice;

    // Create a pointer to Student
    Student* student = nullptr;

    // Determine the type of student to create
    switch (choice) {
        case 1:
            student = new BA();
            break;
        case 2:
            student = new MA();
            break;
        case 3:
            student = new PHD();
            break;
        default:
            throw string("Exception: no such degree"); 
    }
    // Call input method to input student data either PHD, MA, BA
    student->input();
      
    //returns DMA adress of students   
    return student; 
}
