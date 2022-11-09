//
// Created by karee on 31/10/2022.
//

#include "classes.h"

BankAccount::BankAccount(){
    balance = 0;
    for(int i=0;i<10;i++){
        int x = rand()%10;
        accountID+= to_string(x);
    }
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
void BankAccount::set_accountID(){
        for(int i=0;i<10;i++){
            int x = rand()%10;
            accountID+= to_string(x);
        }
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