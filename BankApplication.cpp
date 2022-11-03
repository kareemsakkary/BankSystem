#include <iostream>
using namespace std;
class BankAccount{
public:
    int accountID;
    double balance;
    //client* CLIENT;

    BankAccount(){
        balance = 0;
    }
    BankAccount( double b){
        balance = b;
    }

    BankAccount(int id, double b){
        accountID = id;
        balance = b;
    }

    void set_balance(double b){
        balance = b;
    }
    void set_accountID(int id){
        accountID = id;
    }
    double get_balance(){
        return balance;
    }
    int get_AccountID(){
        return accountID;
    }

    virtual void deposit(double amount){
        balance += amount;
    }

    virtual void withdraw(double amount){
        if( amount<=balance){
            balance -= amount;
        }
        else{
            cout << "Your balance is insufficient" << endl;
        }
    }

};



class  SavingsBankAccount: public BankAccount{
private:
    double minimumBalance;
public:
    SavingsBankAccount() {
        minimumBalance = 1000;
    }
    SavingsBankAccount(double balance) {
        this->balance = balance;
    }
    SavingsBankAccount(double init_balance,double minimumBalance) {
        if (init_balance < minimumBalance) {
            cout << "Initial balance is less than minimum balance" << endl;
        }
        else {
            balance = init_balance;
        }
        this->minimumBalance = minimumBalance;
    }



    void withdraw(double amount){
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

    void deposit(double amount){
        if(amount >= 100){
            BankAccount::deposit(amount);
        }
    }
};


class client{
private:
    string   name;
    string address;
    string  phone;
    BankAccount* bankAcc;
public:
    client(string name , string address , string  phone){
        this->name = name;
        this->address = address;
        this->phone = phone;
    }
    void set_name(string name){
        this->name = name;
    }
    void set_address(string address){
        this->address = address;
    }
    void set_phone(string phone){
        this->phone = phone;
    }
    string get_name(){
        return name;
    }
    string get_address(){
        return address;
    }
    string get_phone(){
        return phone;
    }

};

int main() {


}