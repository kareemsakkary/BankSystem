//
// Created by karee on 31/10/2022.
//

#include "classes.h"

BankAccount::BankAccount(){
    balance = 0;
}
BankAccount::BankAccount( double b){
    balance = b;
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