#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Clock.h"
#include <string>
#include <iostream>
using namespace std;



class Account {
//private by default
private:

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

static int sumDeposit;
static int sumWithdraw;

public:
//ctor - set all to zero and string to empty
Account () {
    accountNumber = 0;
    code = 0;
    balance = 0.0;
    mail = "";
}
//assignment ctor w/ parametrs 
Account (int AccNum, int codeword, float money, string mailb) : accountNumber(AccNum), code(codeword), balance(money), mail(mailb) {
   
}

//setters and getters
void setBal(float money) {
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

int getAccNum() const {
   return accountNumber;
}
int getCode() const {
   return code;
}
float getBal() const {
   return balance;
}
string getMail() const {
   return mail;
}
//static methods voids are essentials setters and static int are getters (return etc)
//method to withdraw a given amount of money from an account
void withdraw(int shek, Clock clocker) {
   //This will check withdrawl
   //If he withdraws and he gets below -6000 which oversteps overdraft limits throw 6000
   if ((balance - shek) < -6000) throw 6000; 
   //if he tries to withdraw more than limit of 2500 throw 2500
	if (shek > 2500) throw 2500; 
	//at this point everything was smooth and was inbounds so edit account accordingly
	balance -= shek; 
	sumWithdraw += shek; 
}
//method to deposit
void deposit(int shek, Clock clocker) {
   //tries to deposit more than 1000 shek at a time..
   if (shek > 10000) throw string("ERROR: cannot deposit more than 10000 NIS!"); 
	//at this point everything was smooth and was inbounds so edit account accordingly
	balance += shek; 
	sumDeposit += shek; 
}
//as static const is not needed
static int getSumWithdraw() {
   return sumWithdraw; 
}
static int getSumDeposit() {
   return sumDeposit;
} 
//friend input cin operator
friend istream& operator>>(istream& is, Account& bank) {
   //setting a code and email to bank account 
   int codeword;
	string mailb;
	is >> bank.accountNumber >> codeword >> mailb;
	
	//now we check if code is 4 digits - valdiity check on input 
	int tester = codeword / 1000;
	//Meaning if lesss than zero it is less than 4 digits 
	//greater than 10 it is more than 4 digits 
	//both bad so we throw that shiii
	if ((tester <= 0) || (tester >= 10)) { 
		throw string("ERROR: code must be of 4 digits!");
	}
	//if we gutchi then we set the code like normal
	else 
	{
		bank.code = codeword;
	}
	//now we check if email is correct like we did earlier 
	//if find returns -1 the char not found 
	//no comments as we did this same process above
	int e = mailb.find('@');    
	
	if (e == -1) throw string("ERROR: email must contain @"); 
	//now the com and il error checks 
	int com = mailb.find(".com");
	int il = mailb.find(".co.il"); 
	if ((com == -1) && (il == -1)) { 
		throw string("ERROR: email must end at .com or .co.il!");
	}
	//meaning if a positioin was returned in find() and not -1 we set as normal
	else {
		bank.mail = mailb;
	}
   //since new account balance gets set to 0 default 
	bank.balance = 0;
	return is;
	
	}

};
// Definition of static member variables
int Account::sumDeposit = 0;
int Account::sumWithdraw = 0;

#endif //ACCOUNT_H
