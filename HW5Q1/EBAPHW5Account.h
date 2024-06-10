#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Clock.h"
#include <string>
#include <iostream>
using namespace std;

//eitanbrown346816549
class Account {
private:
//bank account numbers
int accountNumber;
//code for account - 4 dgits (leftmost not zero)
int code;
//balance of account
int balance;
//a correct eemailaddress consists of
//@ with preceding characters with no space, and after the @ sign, characters
//with no space, ending with one of the following: .com or .co.il.
string email;
//add static variable for methods
static int sumWithdraw;
static int sumDeposit;

public:
    // Constructors
    Account() : accountNumber(0), code(0), balance(0), email("") {
        //nothing to see here :0
    }
    //assignment constructor – receives a value for each field and assigns them
    //accordingly. If any of the values is invalid:

    Account(int accNum, int c, int bal, const string &em) {
        if (c < 1000 || c > 9999) {
            throw "ERROR: code must be of 4 digits!\n";
        }
        //-1 is not found via askiiiiiiiiiiiiiiiiiiiiiii
        if (em.find('@') == -1) {
            throw "ERROR: email must contain @!\n";
        }
        //meaning not found
        if (!(em.find(".com") != -1 || em.find(".co.il") != -1)) {
            throw "ERROR: email must end at .com or .co.il!\n";
        }
        accountNumber = accNum;
        code = c;
        balance = bal;
        email = em;
    }

    // Getters
    int getAccountNumber() const { 
        return accountNumber; 
    }
    int getCode() const { 
        return code; 
    }
    int getBalance() const { 
        return balance; 
    }
    string getEmail() const { 
        return email; 
    }

    static int getSumWithdraw() { 
            return sumWithdraw; 
    }
    static int getSumDeposit() { 
        return sumDeposit; 
    }

    // Input operator
    friend istream& operator>>(istream &in, Account &acc) {
        int accNum;
        int c;
        string em;
        //cout << "Enter account number: ";
        in >> accNum;
        //cout << "Enter code: ";
        in >> c;
        //cout << "Enter email: ";
        in >> em;
        //same as in assignment ctor
        if (c < 1000 || c > 9999) {
            throw "ERROR: code must be of 4 digits!\n";
        }
        //-1 is not found via askiiiiiiiiiiiiiiiiiiiiiii
        if (em.find('@') == -1) {
            throw "ERROR: email must contain @!\n";
        }
        //meaning not found
        if (!(em.find(".com") != -1 || em.find(".co.il") != -1)) {
            throw "ERROR: email must end at .com or .co.il!\n";
        }
        //otherwise add values and return the full input to data
        acc.accountNumber = accNum;
        acc.code = c;
        acc.email = em;
        return in;
    }

    // Methods
    void withdraw(int nis) {
        //bad overflow limit
        if (balance - nis < -6000) {
           throw 6000;
        //can't take out too much
        } else if (nis > 2500) {
            throw 2500;
        } else {
            balance -= nis;
            sumWithdraw+=nis;
        }
    }
    //an't put in more than 1000shek 
    void deposit(int nis) {
        if (nis > 10000) {
            throw string("ERROR: cannot deposit more than 10000 NIS!\n");
        } else {
            balance += nis;
            sumDeposit+=nis;
        }
    }
};

// Initialize static fields
int Account::sumWithdraw = 0;
int Account::sumDeposit = 0;
#endif //ACCOUNT_H
