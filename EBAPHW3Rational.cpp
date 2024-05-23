//Eitan Brown 346816549
//operator overloading
//Main function given via moodle
#include"Rational.h"
#include <iostream>
using namespace std;

enum OPERATOR {
	EXIT, ADD_PRE, ADD_POST, SUB_PRE, SUB_POST, ADD, SUB, MULT, DIV,
	GREATER, LESS_THAN, GREATER_OR_EQUAL, LESS_OR_EQUAL, EQUAL, NOT_EQUAL
};
int main()
{
	int numerator, denominator;
	char junk;
	int op;
	cout << "enter your choice:" << endl;
	cin >> op;
	Rational r2, r3;
	while (op != EXIT) {
		cout << "enter a rational number:" << endl;
		cin >> numerator >> junk >> denominator;
		Rational r1(numerator, denominator);
		if (op >= 5) {
			cout << "enter a rational number:" << endl;
			cin >> numerator >> junk >> denominator;
			r2.setNumerator(numerator);
			r2.setDenominator(denominator);
		}
		switch (op) {
		case ADD_PRE:
			cout << "x = ++y;" << endl;
			cout << "before operation y is: ";
			r1.print();
			r3 = ++r1;
			cout << endl;
			cout << "after operation x is: ";
			r3.print();
			cout << endl << "y is: ";
			r1.print();
			break;
		case ADD_POST:
			cout << "x = " << " y++;" << endl;
			cout << "before operation y is: ";
			r1.print();
			r3 = r1++;
			cout << endl;
			cout << "after operation x is: ";
			r3.print();
			cout << endl << "y is: ";
			r1.print();
			break;
		case SUB_PRE:
			cout << "x = --y;" << endl;
			cout << "before operation y is: ";
			r1.print();
			r3 = --r1;
			cout << endl;
			cout << "after operation x is: ";
			r3.print();
			cout << endl << "y is: ";
			r1.print();
			break;
		case SUB_POST:
			cout << "x = " << " y--;" << endl;
			cout << "before operation y is: ";
			r1.print();
			r3 = r1--;
			cout << endl;
			cout << "after operation x is: ";
			r3.print();
			cout << endl << "y is: ";
			r1.print();
			break;
		case ADD:
			r3 = r1 + r2;
			r1.print();
			cout << " + ";
			r2.print();
			cout << " = ";
			r3.print();
			break;
		case SUB:
			r3 = r1 - r2;
			r1.print();
			cout << " - ";
			r2.print();
			cout << " = ";
			r3.print();
			break;
		case MULT:
			r3 = r1 * r2;
			r1.print();
			cout << " * ";
			r2.print();
			cout << " = ";
			r3.print();
			break;
		case DIV:
			r3 = r1 / r2;
			r1.print();
			cout << " / ";
			r2.print();
			cout << " = ";
			r3.print();
			break;
		case GREATER:
			r1.print();
			cout << " > ";
			r2.print();
			cout << " ? ";
			if (r1 > r2)
				cout << "yes\n";
			else cout << "no\n";
			break;
		case LESS_THAN:
			r1.print();
			cout << " < ";
			r2.print();
			cout << " ? ";
			if (r1 < r2)
				cout << "yes\n";
			else cout << "no\n";
			break;
		case GREATER_OR_EQUAL:
			r1.print();
			cout << " >= ";
			r2.print();
			cout << " ? ";
			if (r1 >= r2)
				cout << "yes\n";
			else cout << "no\n";
			break;
		case LESS_OR_EQUAL:
			r1.print();
			cout << " <= ";
			r2.print();
			cout << " ? ";
			if (r1 <= r2)
				cout << "yes\n";
			else cout << "no\n";
			break;
		case EQUAL:
			r1.print();
			cout << " == ";
			r2.print();
			cout << " ? ";
			if (r1 == r2)
				cout << "yes\n";
			else cout << "no\n";
			break;
		case NOT_EQUAL:
			r1.print();
			cout << " != ";
			r2.print();
			cout << " ? ";
			if (r1 != r2)
				cout << "yes\n";
			else cout << "no\n";
			break;
		}
		cout << endl;
		cout << " enter your choice : " << endl;
		cin >> op;
	}
	return 0;
}
