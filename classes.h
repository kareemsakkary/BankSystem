//
// Created by karee on 31/10/2022.
//

#ifndef BANKSYSTEM_CLASSES_H
#define BANKSYSTEM_CLASSES_H
#include "bits/stdc++.h"
#include "sqlite3.h"

using namespace std;
class client;

class BankAccount{
protected:
    string accountID;
    double balance;
    double minimumBalance=0;
    string type = "regular";
public:
    client* client;
    BankAccount(string id);
    BankAccount(string id, double b);
    void set_balance(double b);
    void set_accountID(string id);
    double get_balance();
    string get_AccountID();
    void set_client(class client* c);
    virtual void deposit(double amount);
    virtual void withdraw(double amount);
    double get_MinimumBalance() const;
    void set_MinimumBalance(double minimumBalance);
    const string& getType() const;
//    void setType(const string &type);
};

class  SavingsBankAccount: public BankAccount{
public:
//    SavingsBankAccount(string id);
    SavingsBankAccount(string id,double balance) ;
    SavingsBankAccount(string id,double init_balance,double minimumBalance) ;
    void withdraw(double amount);
    void deposit(double amount);
};


class client{
private:
    string   name;
    string address;
    string  phone;
public:
    BankAccount* bankAcc;
    ~client();
    client(string name , string address , string  phone ,BankAccount* BA);
    void set_name(string name);
    void set_address(string address);
    void set_phone(string phone);
    string get_name();
    string get_address();
    string get_phone();
//    void set_account_pointer(BankAccount* BA);
};



class dataManger{
private:
    sqlite3 *db;
     sqlite3_stmt *stmt;
public:
    int size;
    dataManger();
    void add_client(client& cl);
    client get_client(string id);
    vector<client*> get_all_clients();
    void update_balance(client& id, double balance);

};

class BankApplication{
    private:
    dataManger dm;
    public:
    void mainMenu();
    void addClient();
    void deposit();
    void withdraw();
    void list_clients();
};

#endif //BANKSYSTEM_CLASSES_H
