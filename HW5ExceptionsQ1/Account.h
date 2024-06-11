#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>
using namespace std;

class Account {
private:
    int accountNumber;
    int code;
    int balance;
    string email;

    static int sumWithdraw;
    static int sumDeposit;

public:
    Account();
    Account(int accNum, int c, int bal, const string &em);

    int getAccountNumber() const;
    int getCode() const;
    int getBalance() const;
    string getEmail() const;

    static int getSumWithdraw();
    static int getSumDeposit();

    friend istream& operator>>(istream &in, Account &acc);

    void withdraw(int nis);
    void deposit(int nis);
};

#endif //ACCOUNT_H
