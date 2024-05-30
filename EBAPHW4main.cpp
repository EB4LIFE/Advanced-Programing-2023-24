//eitan brown 346816549
#include "WorkersFile.h"
#include <iostream>
using namespace std;

//declarations of help functions
void Test1();
void Test2();
void Test3();
void Test4();
void Test5();

enum OPTIONS { STOP, TEST1, TEST2, TEST3, TEST4, TEST5 };

int main()
{
int choice;
do
{
cout << "Enter your choice 0-5:" << endl;
cin >> choice;
switch (choice)
{
case TEST1:
Test1();
break;
  
case TEST2:
Test2();
break;

case TEST3:
Test3();
break;

case TEST4:
Test4();
break;

case TEST5:
Test5();
break;
default:
break;
}
} while (choice);
}
//test case 1
void Test1()
{
cout << "--- Test 1 --- one Worker operators --" << endl;
Worker w1;
cout << "Empty Worker: " << w1;
cout << "Input first worker details, id name salary:" << endl;
cin >> w1;
cout << "First Worker: " << w1;
w1 += 350.4;
cout << "Worker after bonus: " << w1;
Worker w2;
cout << "Input second worker details, id name salary:" << endl;
cin >> w2;
cout << "Second Worker: " << w2;
if (w1 < w2)
cout << "First worker is smaller than second worker" << endl;
if (w2 < w1)
cout << "Second worker is smaller than second worker" << endl;
int id;
cout << "Input worker id: " << endl;
cin >> id;
if (id == w2)
cout << "Id of second worker is " << id << endl;
else
cout << "Id of second worker is not " << id << endl;
string name;
cout << "Input worker name: " << endl;
cin >> name;
if (name == w1)
cout << "Name of first worker is " << name << endl;
else
cout << "Name of first worker is not " << name << endl;
cout << "--- End Test 1 -------------" << endl;
}
//test case 2
void Test2()
{
cout << "--- Test 2 --- cout -- cin --" << endl;
string name = "Test2.txt";
WorkersFile wf2(name);
cout << "Input worker details, id name salary. Into file: " << name << ". press 0 0 0 to end:" << endl;
cin >> wf2;
cout << "Output worker list (id name salary). From file: " << name << "" << endl;
cout << wf2;
cout << "Input worker details, id name salary. Into file: " << name << ". press 0 0 0 to end:" << endl;
cin >> wf2;
cout << "Output worker list (id name salary). From file: " << name << "" << endl;
cout << wf2;
cout << "--- End Test 2 -------------" << endl;
}
//test case 3
void Test3()
{
cout << "--- Test 3 --- sort -- operator[] --" << endl;
string name = "Test3.txt";
WorkersFile wf3(name);
cout << "Input worker details, id name salary. Into file: " <<
name << ". press 0 0 0 to end:" << endl;
cin >> wf3;
cout << "Output worker list (id name salary), before sorting. From file: " << name << "" << endl;
cout << wf3;
wf3.sort(); //sort ascending
cout << "Output worker list (id name salary), after sort ascending. From file: " << name << "" << endl;
cout << wf3;
cout << "The worker with the minimum salary: " << wf3[0];
wf3.sort(false); //sort descending
cout << "Output worker list (id name salary), after sort descending. From file: " << name << "" << endl;
cout << wf3;
cout << "The worker with the maximum salary: " << wf3[0];
cout << "--- End Test 3 -------------" << endl;
}
//test case 4
void Test4()
{
cout << "--- Test 4 --- operator+= --" << endl;
string name = "Test4.txt";
WorkersFile wf4(name);
cout << "Input worker details, id name salary. Into file: " << name << ". press 0 0 0 to end:" << endl;
cin >> wf4;
cout << "Output worker list (id name salary), before bonus. From file: " << name << "" << endl;
cout << wf4;
wf4 += 1000;
cout << "Output worker list (id name salary), after bonus. From file: " << name << "" << endl;
cout << wf4;
cout << "--- End Test 4 -------------" << endl;
}
//test case 5
void Test5()
{
cout << "--- Test 5 --- merge 2 files -- sort -" << endl;
string name5a = "Test5A.txt";
WorkersFile wf5_a(name5a);
cout << "Input worker details, id name salary. Into file: " << name5a << ". press 0 0 0 to end:" << endl;
cin >> wf5_a;
string name5b = "Test5B.txt";
WorkersFile wf5_b(name5b);
cout << "Input worker details, id name salary. Into file: " << name5b << ". press 0 0 0 to end:" << endl;
cin >> wf5_b;
WorkersFile wf5 = wf5_a + wf5_b; //the compiler optimized by not
calling to copy ctor
cout << "Merged file:" << endl;
cout << wf5;
wf5.sort(false);
cout << "Output worker list (id name salary), merged file sort descending:" << endl;
cout << wf5;
cout << "--- End Test 5 -------------" << endl;
}

