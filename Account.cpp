#include "Account.h"

int Account::sumWithdraw = 0;
int Account::sumDeposit = 0;

Account::Account() : accountNumber(0), code(0), balance(0), email("") {}

Account::Account(int accNum, int c, int bal, const string &em) {
    if (c < 1000 || c > 9999) {
        throw "ERROR: code must be of 4 digits!\n";
    }
    if (em.find('@') == string::npos) {
        throw "ERROR: email must contain @!\n";
    }
    if (!(em.find(".com") != string::npos || em.find(".co.il") != string::npos)) {
        throw "ERROR: email must end at .com or .co.il!\n";
    }
    accountNumber = accNum;
    code = c;
    balance = bal;
    email = em;
}

int Account::getAccountNumber() const {
    return accountNumber;
}

int Account::getCode() const {
    return code;
}

int Account::getBalance() const {
    return balance;
}

string Account::getEmail() const {
    return email;
}

int Account::getSumWithdraw() {
    return sumWithdraw;
}

int Account::getSumDeposit() {
    return sumDeposit;
}

istream& operator>>(istream &in, Account &acc) {
    int accNum;
    int c;
    string em;
    in >> accNum;
    in >> c;
    in >> em;

    if (c < 1000 || c > 9999) {
        throw "ERROR: code must be of 4 digits!\n";
    }
    if (em.find('@') == string::npos) {
        throw "ERROR: email must contain @!\n";
    }
    if (!(em.find(".com") != string::npos || em.find(".co.il") != string::npos)) {
        throw "ERROR: email must end at .com or .co.il!\n";
    }
    
    acc.accountNumber = accNum;
    acc.code = c;
    acc.email = em;
    return in;
}

void Account::withdraw(int nis) {
    if (balance - nis < -6000) {
        throw 6000;
    } else if (nis > 2500) {
        throw 2500;
    } else {
        balance -= nis;
        sumWithdraw += nis;
    }
}

void Account::deposit(int nis) {
    if (nis > 10000) {
        throw string("ERROR: cannot deposit more than 10000 NIS!\n");
    } else {
        balance += nis;
        sumDeposit += nis;
    }
}
