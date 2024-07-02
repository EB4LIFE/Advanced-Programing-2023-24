#include <list>      // for list
#include <vector>    // for vector
#include <queue>     // for queue
#include <stack>     // for stack
#include <exception> // for exception handling
#include <algorithm> // for sort
#include "BA.h"      // include BA header
#include "MA.h"      // include MA header
#include "PHD.h"     // include PHD header
#include <iostream>  // for input and output
using namespace std;

//Function to input students of all types and add them to a list
void addStudent(list<Student*>& students) {
    // variable to store degree type
    int type; 
    while (true) {
        cout << "Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish" << endl;
        cin >> type;
        if (type == 0) break; // exit loop if input is 0
        // pointer to hold new student object
        Student* newStudent = nullptr; 
        try {
            //Logic to create new instances of BA, MA, or PHD based on user input
            switch (type) {
                case 1:
                    //Create new BA student
                    newStudent = new BA();
                    break;
                case 2:
                    //Create new MA student
                    newStudent = new MA();
                    break;
                case 3:
                    //Create new PHD student
                    newStudent = new PHD();
                    break;
                default:
                    //Throw exception for invalid degree type (not 0,1,2,3)
                    throw string("Exception: no such degree");
            }
            //Input student details(based on type)
            newStudent->input();
            //Add student to list
            students.push_back(newStudent); 
        } catch (const string& e) {
            // Catch and print exception message
            cout << e << endl;
            // Clean up allocated memory if exception is thrown
            delete newStudent;
        }
    }
}
int main() {
    // List to store all students
    list<Student*> studentList; 
    // Input students and add them to the list
    addStudent(studentList); 

    // Declare vectors for each type of student
    // Vector to hold BA students
    vector<BA> baStudents; 
    // Vector to hold MA students
    vector<MA> maStudents; 
    // Vector to hold PHD students
    vector<PHD> phdStudents; 

     // Iterate through the list and copy elements to the correct vectors based on studType
    // Using auto here automatically deduces the type of the iterator (list<Student*>::iterator)
    for (auto it = studentList.begin(); it != studentList.end(); ++it) {
        // Check if the student is a BA student
        if ((*it)->studType() == "BA student") {
            // Add BA student to baStudents vector
            baStudents.push_back(dynamic_cast<BA&>(**it));
        // Check if the student is an MA student
        } else if ((*it)->studType() == "MA student") {
            // Add MA student to maStudents vector
            maStudents.push_back(dynamic_cast<MA&>(**it));
        // Check if the student is a PhD student
        } else if ((*it)->studType() == "PhD student") {
            // Add PHD student to phdStudents vector
            phdStudents.push_back(dynamic_cast<PHD&>(**it));
        }
        // Free memory of the element in the list
        delete *it; 
    }

    // Sort each vector in non-descending order 
    //the built method sorts this wau by default
    // Sort BA students
    sort(baStudents.begin(), baStudents.end()); 
    // Sort MA students
    sort(maStudents.begin(), maStudents.end()); 
    // Sort PHD students
    sort(phdStudents.begin(), phdStudents.end()); 

    // Declare queues and stack for BA, MA, PHD instances
    
    // Queue to hold BA students
    queue<BA> baQueue; 
    // Queue to hold MA students
    queue<MA> maQueue; 
    // Stack to hold PHD students
    stack<PHD> phdStack; 

    // Enqueue BA and MA instances
    // Iterate in reverse through the baStudents vector and add each student to the queue
    for (auto it = baStudents.rbegin(); it != baStudents.rend(); ++it) {
        // Add BA student to queue
        baQueue.push(*it); 
    }
    // Iterate in reverse through the maStudents vector and add each student to the queue
    for (auto it = maStudents.rbegin(); it != maStudents.rend(); ++it) {
        // Add MA student to queue
        maQueue.push(*it); 
    }

    // Push PHD instances onto stack
    // Iterate through the phdStudents vector and add each student to the stack
    for (auto& phd : phdStudents) {
        // Add PHD student to stack
        phdStack.push(phd); 
    }
    
    cout << "------------------------------------------------------------" << endl;
    
    // Print and remove BA students from queue
    while (!baQueue.empty()) {
        // Get the front student
        BA student = baQueue.front(); 
        // Print student details
        student.print(); 
        // Remove the student from the queue
        baQueue.pop(); 
    }
      
    // Print and remove MA students from queue
    while (!maQueue.empty()) {
        // Get the front student
        MA student = maQueue.front(); 
        // Print student details
        student.print(); 
        // Remove the student from the queue
        maQueue.pop(); 
    }
      
    // Print and remove PHD students from stack
    while (!phdStack.empty()) {
        // Get the top student
        PHD student = phdStack.top(); 
        // Print student details
        student.print(); 
        // Remove the student from the stack
        phdStack.pop(); 
    }

    return 0; // End of the program
}
