#include "FullTime.h"
#include "PartTime.h"
#include <iostream>
using namespace std;
int main() {
	
	FullTime arrF[3];
	for (int i = 0; i < 3; i++) {
		try {
			cin >> arrF[i];
		}
		catch (const char* str) {
			cout << str << endl;
			i--;
		}
	}


	PartTime arrP[3];
	for (int i = 0; i < 3; i++) {
		try
		{
			cin >> arrP[i];
		}
		catch (const char* str) {
			cout << str << endl;
			i--;
		}
	}

	cout << endl;
	for (int i = 0; i < 3; i++) {
		cout << arrF[i];
		cout << "After Bonus: " << arrF[i].salaryAfterBonus() << endl << endl;
	}


	for (int i = 0; i < 3; i++) {
		cout << arrP[i];
		cout << "After Bonus: " << arrP[i].salaryAfterBonus() << endl << endl;
	}
	return 0;
}
