//
// Created by karee on 31/10/2022.
//

#include "classes.h"

SavingsBankAccount::SavingsBankAccount(string id):BankAccount(id) {
    type = "saving";

}

SavingsBankAccount::SavingsBankAccount(string id,double balance):BankAccount(id) {
    this->minimumBalance=1000;
    if (balance>=minimumBalance){
        this->balance = balance;
    }
    type = "saving";
}
SavingsBankAccount::SavingsBankAccount(string id,double init_balance,double minimumBalance):BankAccount(id) {
    if (init_balance < minimumBalance) {
        cout << "Initial balance is less than minimum balance" << endl;
    }
    else {
        balance = init_balance;
    }
    this->minimumBalance = minimumBalance;
    type = "saving";

}



void SavingsBankAccount::withdraw(double amount){
    if( amount<=balance){
        balance -= amount;
        if (balance < minimumBalance){
            balance += amount;
            cout << "Your balance is insufficient" << endl;
        }
    }
    else{
        cout << "Your balance is insufficient" << endl;
    }
}

void SavingsBankAccount::deposit(double amount){
    if(amount >= 100){
        BankAccount::deposit(amount);
    }
}