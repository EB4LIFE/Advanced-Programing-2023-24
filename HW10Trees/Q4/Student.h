

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int id;
    string lastName;
    string firstName;

public:
    Student();
    Student(int id, string lastName, string firstName);
    Student(const Student& other);
    Student(Student&& other) noexcept;
    ~Student();

    Student& operator=(const Student& other);
    Student& operator=(Student&& other) noexcept;

   bool operator<(const Student& other) const;
   bool operator>(const Student& other) const;

    bool operator<=(const Student& other) const;
    bool operator==(const Student& other) const;

    friend ostream& operator<<(ostream& os, const Student& student);
    friend istream& operator>>(istream& is, Student& student);
};

#endif // STUDENT_H
