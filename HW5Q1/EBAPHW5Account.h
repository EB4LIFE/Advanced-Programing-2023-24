#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Clock.h"
#include <string>
#include <iostream>
using namespace std;


Class Account {
//private by default
Private:

//bank account numbers
int accountNumber;
//code for account - 4 dgits (leftmost not zero)
int code;
//balance of account
float balance;
//a correct email address consists of
//@ with preceding characters with no space, and after the @ sign, characters
//with no space, ending with one of the following: .com or .co.il.
string mail;
//add static variable for methods
static int sumDeposit = 0;
static int sumWithdraw = 0;


Public:
//ctor - set all to zero and string to empty
Account () {
    accountNumber = 0;
    code = 0;
    balance = 0.0;
    mail = "";
}
//assignment ctor w/ parametrs 
Account (int AccNum, int codeword, float money, string mailb) : accountNumber(Accnum), code(codeword), balance(money), mail(mailb) {
   
}

//setters and getters
void setBalance(float money) {
   balance = money;
}
void setMail(string mailb) {
//as stated next to variable above we need to check if email is valid 
//@ with preceding characters with no space, and after the @ sign, characters
//with no space, ending with one of the following: .com or .co.il.
try {
   int index;
   //checking if the email contains an @ symbol
	index = mailb.find('@'); 
	   //We will exit code from find function if char not found
		if (index == -1) throw string("wrong email!"); 
		//...ending with one of the following: .com or .co.il.
		if ((mailb.find(".com", index) == -1) || (mailb.find(".co.il", index) == -1)) { 
		   //if not there then ...
			throw string("wrong email!");
		}
		//no issues so set as normal
		mail = mailb;
   
}
//catches error message from try and prints it
catch (string s) {
   cout << s << endl;
	return;
}

}

int getAccountNumber() const {
   return accountNumber;
}
int getCode() const {
   return code;
}
float getBalance() const {
   return balance;
}
string getMail() const {
   return mail;
}
//static methods voids are essentials setters and static int are getters (return etc)
//method to withdraw a given amount of money from an account
void withdraw(int shek, Clock clocker) {
   
}
//method to deposit
void deposit(int shek, Clock clocker) {
   
}
//as static const is not needed
static int getSumWithdraw() {
   return sumWithdraw; 
}
static int getSumDeposit() {
   return sumDeposit;
} 
//friend input cin operator
friend istream& operator>>(istream& is, Account &bank) {
   
}

};
#endif //ACCOUNT_H
