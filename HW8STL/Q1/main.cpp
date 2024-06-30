#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <exception>
#include <algorithm>
#include "BA.h"
#include "MA.h"
#include "PHD.h"
#include <iostream>
using namespace std;

// Function to input students of all types and add them to a list
void addStudent(list<Student*>& students) {
    int type;
    while (true) {
        cout << "Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish" << endl;
        cin >> type;
        if (type == 0) break;
        
        Student* newStudent = nullptr;
        // Logic to create new instances of BA, MA, or PHD based on user input
        try {
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
                    throw string("Exception: no such degree");
            }
            newStudent->input();  // Input student details
            students.push_back(newStudent);
        } catch (const string& e) {
            cout << e << endl;
            delete newStudent; // Clean up allocated memory
        }
    }
}

int main() {
    list<Student*> studentList;
    addStudent(studentList); // Input students and add them to the list

    // Declare vectors for each type of student
    vector<BA> baStudents;
    vector<MA> maStudents;
    vector<PHD> phdStudents;

    // Iterate through the list and copy elements to the correct vectors based on studType
    for (auto it = studentList.begin(); it != studentList.end(); ++it) {
        if ((*it)->studType() == "BA student") {
            baStudents.push_back(dynamic_cast<BA&>(**it)); 
        } 
        else if ((*it)->studType() == "MA student") {
            maStudents.push_back(dynamic_cast<MA&>(**it)); 
        } 
        else if ((*it)->studType() == "PhD student") {
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
        baQueue.push(*it);
    }
    for (auto it = maStudents.rbegin(); it != maStudents.rend(); ++it) {
        maQueue.push(*it);
    }

    // Push PHD instances onto stack
    for (auto& phd : phdStudents) {
        phdStack.push(phd);
    }
   cout << "------------------------------------------------------------" << endl;
    while (!baQueue.empty()) {
        BA student = baQueue.front();
        student.print(); 
        baQueue.pop();
    }
      
      
    while (!maQueue.empty()) {
        MA student = maQueue.front();
        student.print(); 
        maQueue.pop();
    }
      
      
    while (!phdStack.empty()) {
        PHD student = phdStack.top();
        student.print(); 
        phdStack.pop();
    }

    return 0;
}
