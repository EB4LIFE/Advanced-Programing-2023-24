//Eitan Brown 346816549

#include "Clock.h"
#include "Account.h"
#include <iostream>
using namespace std;

enum ACTION {
STOP,
BALANCE,
DEPOSIT,
WITHDRAW,
SUM_DEPOSIT,
SUM_WITHDRAW
};

ACTION menu() {
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all deposits" << endl;
	cout << "enter 5 to see the sum of all withdrawals" << endl;
	cout << "enter 0 to stop" << endl << endl;

	int x;
	try {  
        //need to check if user entered valid menu option
		cin >> x;
		if (x < 0 || x > 5) {
			throw string("ERROR: choose an option between 0 and 5");
		}
		return (ACTION)x;
	}
	catch (string s) {
		cout << s << endl;
		return (ACTION)x;
	}
}

int findAccount(Account* bank, int size) {
	int number, code;
	cout << "please enter account number: \n";
	cin >> number;
	int i = 0;

	 //put loop in try in case tries to access invalid account (acc # not found because it doesn't exist)
	while (i < size && bank[i].getAccountNumber() != number) {
		i++;
	}
	if (bank[i].getAccountNumber() != number)
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

void printTransaction(Account a, ACTION ac, Clock& c) {

switch (ac) {
case BALANCE: cout << c << "\t" << "account #: " << a.getAccountNumber() << "\t";
cout << "balance: " << a.getBalance() << endl;
break;
case DEPOSIT:
case WITHDRAW: cout << c << "\t" << "account #: " << a.getAccountNumber() << "\t";
cout << "new balance: " << a.getBalance() << endl;
break;
case SUM_DEPOSIT:
cout << c << "\t" << "sum of all deposits: " << Account::getSumDeposit() << endl;
break;
case SUM_WITHDRAW:
cout << c << "\t" << "sum of all withdrawals: " << Account::getSumWithdraw() << endl;
break;
}
} 


void getBalance(Account* bank, int size, Clock& c) {
	int i = findAccount(bank, size);
	c += 20;
	printTransaction(bank[i], BALANCE, c);
}

void cashDeposit(Account* bank, int size, Clock& c) {
	int i;
	try {
		i = findAccount(bank, size);
	}
	catch (const char* msg) { 
	    //catching error from find account, problem with acc number or code
		throw msg; 
		//sending to function call in main
	}

	float amount;
	cout << "enter the amount of the deposit:\n";
	cin >> amount;
	try {
		bank[i].deposit(amount);
	}
	catch (string s) { //above deposit limit
		cout << c << '\t' << s << endl;
		return;
	}
	c += 30;
	printTransaction(bank[i], DEPOSIT, c);
}

void cashWithdraw(Account* bank, int size, Clock& c) {
	int i;
	try {
		i = findAccount(bank, size);
	}
	catch (const char* msg) { 
	    //catching error from find account, problem with acc number or code
		throw msg; 
		//sending to function call in main
	}

	float amount;
	cout << "enter the amount of money to withdraw:\n";
	cin >> amount;
	try {
		bank[i].withdraw(amount);
	}
	catch (int x) { 
	    //above overdraft limit or user wants to withdraw more than 2500
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
	printTransaction(bank[i], WITHDRAW, c);
}

void checkAccount(Account bank[], int i) {
for (int j = 0; j < i; j++)
if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
throw "ERROR: account number must be unique!\n";
}

int main() {
    const int SIZE = 10;
   Clock c(8, 0, 0);
   Account bank[SIZE];
   cout << " enter account number, code and email for " << SIZE << " accounts:" << endl;
   cout << endl;
   //I thought about ntro a flag to control the loop for entering account details, ensuring it only exits upon receiving valid input. 
   //Error handling via using--> catching exceptions and promp the user to re-enter data until correct, without incrementing the i or j to early
   //This prevents infinite loops caused by invalid inputs, such as incorrect account codes.
   //but moodle messed around to much so i left it out but tested it on Visual studio and it worked
   for (int i = 0; i < SIZE; i++) {
		try {
			try {
				cin >> bank[i];
			}
			catch (string s) { 
			    //catching any errors when reading in details: code not 4 digits, no @ in email, end of email invalid
				cout << c << '\t' << s << endl;;
				i--;
				continue;
			}

			for (int j = 0; j < i; j++)
				if (bank[i].getAccountNumber() == bank[j].getAccountNumber())                   
					throw "ERROR: account number must be unique!\n";

		}
		catch (const char* msg) { //catching wrong account number
			cout << c << '\t' << msg;
			i--;
			continue;
		}
	}
    ACTION ac = menu();

	while (ac != 0) {

		switch (ac) {
		case BALANCE:
			getBalance(bank, 10, c);
			break;
		case WITHDRAW:
			try {
				cashWithdraw(bank, 10, c);
			}
			catch (const char* msg) { 
                //catching error from cashWithdraw function which caught from findAccount
				cout << c << "\t" << msg;
			}
			break;
		case DEPOSIT:
			try {
				cashDeposit(bank, 10, c);
			}
			catch (const char* msg) { 
                //catching error from cashDeposit function which caught from findAccount
				cout << c << "\t" << msg;
			}

			break;
		case SUM_WITHDRAW:
			c += 60;
			printTransaction(bank[0], SUM_WITHDRAW, c);
			break;
		case SUM_DEPOSIT:
			c += 60;
			printTransaction(bank[0], SUM_DEPOSIT, c);
			break;
		}
		ac = menu();
	}

	return 0;
}

