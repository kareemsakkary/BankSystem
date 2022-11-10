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
    BankAccount();
    BankAccount( double b);
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

    const string &getType() const;

    void setType(const string &type);
};

class  SavingsBankAccount: public BankAccount{
public:
    SavingsBankAccount();
    SavingsBankAccount(double balance) ;
    SavingsBankAccount(double init_balance,double minimumBalance) ;
    void withdraw(double amount);
    void deposit(double amount);
};


class client{
private:
    string   name;
    string address;
    string  phone;
    string accountID;
public:
    BankAccount* bankAcc;
    ~client();
    client(string name, string address, string phone, SavingsBankAccount *BA);
    client(string name , string address , string  phone ,BankAccount* BA);
    void set_name(string name);
    void set_address(string address);
    void set_phone(string phone);
    string get_name();
    string get_address();
    string get_phone();
    void set_account_pointer(BankAccount* BA);
};

class BankApplication{
    private:
    vector<client> Clist;
    vector<BankAccount> Bankaccs;
    public:
    void mainMenu();
    void addClient();
    void deposit();
    void withdraw();
    void list_clients();
};


class dataManger{
private:
    sqlite3 *db;
    sqlite3_stmt *stmt;
public:

    dataManger();
    void add_client(client& cl);
    client get_client(string id);
    void get_all_client(vector<client> & clients);
    void update_balance(client& id, double balance);

};
#endif //BANKSYSTEM_CLASSES_H
