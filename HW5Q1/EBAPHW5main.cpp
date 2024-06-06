#include "Clock.h"
#include "Account.h"
#include <iostream>
using namespace std;

enum action { stop, balance, deposit, withdraw, sumDeposit, sumWithdraw };

action menu() {
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all withdraws" << endl;
	cout << "enter 5 to see the sum of all Deposits" << endl;
	cout << "enter 0 to stop" << endl << endl;

	int x;
	try {  //need to check if user entered valid menu option
		cin >> x;
		if (x < 0 || x > 5) {
			throw string("ERROR: choose an option between 0 and 5");
		}
		return (action)x;
	}
	catch (string s) {
		cout << s << endl;
		return (action)x;
	}
}

int findAccount(Account* bank, int size) {
	int number, code;
	cout << "please enter account number: \n";
	cin >> number;
	int i = 0;

	 //put loop in try in case tries to access invalid account (acc # not found because it doesn't exist)
	while (i < size && bank[i].getAccNum() != number) {
		i++;
	}
	if (bank[i].getAccNum() != number)
		throw "ERROR: no such account number!\n";

	cout << "please enter the code: \n";
	cin >> code;
	if (bank[i].getCode() == code) {
		return i;
	}
	else { //in cases when account number doesn't match code
		throw "ERROR: wrong code!\n";
	}
}

void printTransaction(Account a, action ac, Clock& c) {
	cout << c << "\t";
	switch (ac)
	{
	case balance: cout << "account #: " << a.getAccNum() << "\t";
		cout << "balance: " << a.getBal() << endl;
		break;
	case deposit:
	case withdraw: cout << "account #: " << a.getAccNum() << "\t";
		cout << "new balance: " << a.getBal() << endl;
		break;
	case sumWithdraw:
		cout << "sum of all withdraws: " << Account::getSumWithdraw() << endl;
		break;
	case sumDeposit:
		cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
		break;
	}
}

void getBalance(Account* bank, int size, Clock& c) {
	int i = findAccount(bank, size);
	c += 20;
	printTransaction(bank[i], balance, c);
}

void cashDeposit(Account* bank, int size, Clock& c) {
	int i;
	try {
		i = findAccount(bank, size);
	}
	catch (const char* msg) { //catching error from find account, problem with acc number or code
		throw msg; //sending to function call in main
	}

	float amount;
	cout << "enter the amount of the check: \n";
	cin >> amount;
	try {
		bank[i].deposit(amount, c);
	}
	catch (string s) { //above deposit limit
		cout << c << '\t' << s << endl;
		return;
	}
	c += 30;
	printTransaction(bank[i], deposit, c);
}

void cashWithdraw(Account* bank, int size, Clock& c) {
	int i;
	try {
		i = findAccount(bank, size);
	}
	catch (const char* msg) { //catching error from find account, problem with acc number or code
		throw msg; //sending to function call in main
	}

	float amount;
	cout << "enter the amount of money to withdraw: \n";
	cin >> amount;
	try {
		bank[i].withdraw(amount, c);
	}
	catch (int x) { //above overdraft limit or user wants to withdraw more than 2500
		if (x == 2500) {
			cout << c << '\t' << "ERROR: cannot withdraw more than 2500 NIS!" << endl;
			return;
		}
		if (x == 6000) {
			cout << c << '\t' << "ERROR: cannot have less than - 6000 NIS!" << endl;
			return;
		}
	}
	c += 50;
	printTransaction(bank[i], withdraw, c);
}


int main() {
	Clock c(8,0,0);
	Account bank[10];
	cout << "enter account number, code and email for 10 accounts:\n";
	for (int i = 0; i < 10; i++) {
		try {
			try {
				cin >> bank[i];
			}
			catch (string s) { //catching any errors when reading in details: code not 4 digits, no @ in email, end of email invalid
				cout << c << '\t' << s << endl;;
				i--;
				continue;
			}

			for (int j = 0; j < i; j++)
				if (bank[i].getAccNum() == bank[j].getAccNum())                   
					throw "ERROR: account number must be unique!\n";

		}
		catch (const char* msg) { //catching wrong account number
			cout << c << '\t' << msg;
			i--;
			continue;
		}
	}
	action ac = menu();

	while (ac != 0) {

		switch (ac) {
		case balance:
			getBalance(bank, 10, c);
			break;
		case withdraw:
			try {
				cashWithdraw(bank, 10, c);
			}
			catch (const char* msg) { //catching error from cashWithdraw function which caught from findAccount
				cout << c << "\t" << msg;
			}
			break;
		case deposit:
			try {
				cashDeposit(bank, 10, c);
			}
			catch (const char* msg) { //catching error from cashDeposit function which caught from findAccount
				cout << c << "\t" << msg;
			}

			break;
		case sumWithdraw:
			c += 60;
			printTransaction(bank[0], sumWithdraw, c);
			break;
		case sumDeposit:
			c += 60;
			printTransaction(bank[0], sumDeposit, c);
			break;
		}
		ac = menu();
	}

	return 0;
}

