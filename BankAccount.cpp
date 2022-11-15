//
// Created by karee on 31/10/2022.
//

#include "classes.h"

BankAccount::BankAccount(string id){
    balance = 0;
    accountID = id;
}
BankAccount::BankAccount(string id, double b){
    accountID = id;
    balance = b;
}

void BankAccount::set_client(class client *c) {
    this->client = c;
}
void BankAccount::set_balance(double b){
    balance = b;
}
void BankAccount::set_accountID(string id){
        accountID = id;
}
double BankAccount::get_balance(){
    return balance;
}
string BankAccount::get_AccountID(){
    return accountID;
}

void BankAccount::deposit(double amount){
    balance += amount;
}

void BankAccount::withdraw(double amount){
    if( amount<=balance){
        balance -= amount;
    }
    else{
        cout << "Your balance is insufficient" << endl;
    }
}

double BankAccount::get_MinimumBalance() const {
    return minimumBalance;
}

void BankAccount::set_MinimumBalance(double minimumBalance) {
    BankAccount::minimumBalance = minimumBalance;
}

const string &BankAccount::getType() const {
    return type;
}



