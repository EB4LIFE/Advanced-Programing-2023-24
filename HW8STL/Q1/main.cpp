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

// Function to input students of all types and add them to a list
void addStudent(list<Student*>& students) {
    int type; // variable to store degree type
    while (true) {
        cout << "Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish" << endl;
        cin >> type; // take input from user
        if (type == 0) break; // exit loop if input is 0
        
        Student* newStudent = nullptr; // pointer to hold new student object
        try {
            // Logic to create new instances of BA, MA, or PHD based on user input
            switch (type) {
                case 1:
                    // Create new BA student
                    newStudent = new BA();
                    break;
                case 2:
                    // Create new MA student
                    newStudent = new MA();
                    break;
                case 3:
                    // Create new PHD student
                    newStudent = new PHD();
                    break;
                default:
                    // Throw exception for invalid degree type
                    throw string("Exception: no such degree");
            }
            newStudent->input();  // Input student details
            students.push_back(newStudent); // Add student to list
        } catch (const string& e) {
            // Catch and print exception message
            cout << e << endl;
            delete newStudent; // Clean up allocated memory if exception is thrown
        }
    }
}

int main() {
    list<Student*> studentList; // List to store all students
    addStudent(studentList); // Input students and add them to the list

    // Declare vectors for each type of student
    vector<BA> baStudents;
    vector<MA> maStudents;
    vector<PHD> phdStudents;

    // Iterate through the list and copy elements to the correct vectors based on studType
    for (auto it = studentList.begin(); it != studentList.end(); ++it) {
        if ((*it)->studType() == "BA student") {
            // Add BA student to baStudents vector
            baStudents.push_back(dynamic_cast<BA&>(**it));
        } else if ((*it)->studType() == "MA student") {
            // Add MA student to maStudents vector
            maStudents.push_back(dynamic_cast<MA&>(**it));
        } else if ((*it)->studType() == "PhD student") {
            // Add PHD student to phdStudents vector
            phdStudents.push_back(dynamic_cast<PHD&>(**it));
        }
        delete *it; // Free memory of the element in the list
    }

    // Sort each vector in non-descending order
    sort(baStudents.begin(), baStudents.end());
    sort(maStudents.begin(), maStudents.end());
    sort(phdStudents.begin(), phdStudents.end());

    // Declare queues and stack for BA, MA, PHD instances
    queue<BA> baQueue;
    queue<MA> maQueue;
    stack<PHD> phdStack;

    // Enqueue BA and MA instances
    for (auto it = baStudents.rbegin(); it != baStudents.rend(); ++it) {
        baQueue.push(*it); // Add BA student to queue
    }
    for (auto it = maStudents.rbegin(); it != maStudents.rend(); ++it) {
        maQueue.push(*it); // Add MA student to queue
    }

    // Push PHD instances onto stack
    for (auto& phd : phdStudents) {
        phdStack.push(phd); // Add PHD student to stack
    }
    
    cout << "------------------------------------------------------------" << endl;
    
    // Print and remove BA students from queue
    while (!baQueue.empty()) {
        BA student = baQueue.front(); // Get the front student
        student.print(); // Print student details
        baQueue.pop(); // Remove the student from the queue
    }
      
    // Print and remove MA students from queue
    while (!maQueue.empty()) {
        MA student = maQueue.front(); // Get the front student
        student.print(); // Print student details
        maQueue.pop(); // Remove the student from the queue
    }
      
    // Print and remove PHD students from stack
    while (!phdStack.empty()) {
        PHD student = phdStack.top(); // Get the top student
        student.print(); // Print student details
        phdStack.pop(); // Remove the student from the stack
    }

    return 0; // End of the program
}
```
