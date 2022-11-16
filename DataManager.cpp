//
// Created by karee on 31/10/2022.
//

#include "classes.h"

dataManger::dataManger() {
    fstream data;
    data.open("data.txt",ios::in);
    string line;
    this->size=0;
    while (getline(data,line)){
        this->size++;
    }
    data.close();
}

void dataManger::add_client(client& cl) {
    fstream data;
    data.open("data.txt",ios::app);
    data << cl.get_name() << " " << cl.get_address() << " " << cl.get_phone() << " " << cl.bankAcc->get_AccountID() << " " << cl.bankAcc->get_balance() << " " << cl.bankAcc->get_MinimumBalance() << " " << cl.bankAcc->getType() << endl;
    data.close();
}

client dataManger::get_client(string id) {
    fstream data;
    data.open("data.txt",ios::in);
    string line;
    while (getline(data,line)){
        stringstream ss(line);
        string name,address,phone,accountID,type;
        double balance,minimumBalance;
        ss >> name >> address >> phone >> accountID >> balance >> minimumBalance >> type;
        if(accountID == id){
            BankAccount* BA;
            if(type == "regular"){
                BA = new BankAccount(accountID,balance);
            }
            else{
                BA = new SavingsBankAccount(accountID,balance,minimumBalance);
            }
            client cl(name,address,phone,BA);
            return cl;
        }
    }
    BankAccount *Ba= new BankAccount(id, 132);
    client *ca = new client("error" , "err" , "0000" ,Ba);
    return *ca;
}


vector<client*> dataManger::get_all_clients( ) {
    fstream data;
    data.open("data.txt",ios::in);
    string line;
    vector<client*> clients;
    while (getline(data,line)){
        stringstream ss(line);
        string name,address,phone,accountID,type;
        double balance,minimumBalance;
        ss >> name >> address >> phone >> accountID >> balance >> minimumBalance >> type;
        BankAccount* BA;
        if(type == "regular"){
            BA = new BankAccount(accountID,balance);
        }
        else{
            BA = new SavingsBankAccount(accountID,balance,minimumBalance);
        }
        client* cl = new client(name,address,phone,BA);
        clients.push_back(cl);
    }
    return clients;
}

void dataManger::update_balance(client& client, double bal) {
    fstream data;
    data.open("data.txt",ios::in);
    string line;
    vector<string> lines;
    while (getline(data,line)){
        stringstream ss(line);
        string name,address,phone,accountID,type;
        double balance,minimumBalance;
        ss >> name >> address >> phone >> accountID >> balance >> minimumBalance >> type;
        if(accountID == client.bankAcc->get_AccountID()){
            line = name + " " + address + " " + phone + " " + accountID + " " + to_string(bal) + " " + to_string(minimumBalance) + " " + type;
        }
        lines.push_back(line);
    }
    data.close();
    data.open("data.txt",ios::out);
    for (int i = 0; i < lines.size(); ++i) {
        data << lines[i] << endl;
    }
    data.close();
}