//
// Created by karee on 31/10/2022.
//

#include "classes.h"

dataManger::dataManger() {
    if(sqlite3_open("data.db",&db)==SQLITE_OK){
        int res =sqlite3_prepare_v2(db,"CREATE TABLE IF NOT EXISTS client (name TEXT , address TEXT , phone TEXT , accountID TEXT , balance REAL , minimumBalance REAL , accountType TEXT , PRIMARY KEY (accountID));"
                                    ,1000,&stmt,0);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);

        if(res != SQLITE_OK){
            cout << "can`t connect to database error" << sqlite3_errmsg(db) << endl;
        }else{
            cout << "connected"  << endl;
            vector<client> cls;
            this->get_all_clients(cls);
            this->size = cls.size();
        }
    }
}

void dataManger::add_client(client& cl) {
    BankAccount ba = *cl.bankAcc;
    cout << ba.get_AccountID() << endl;
    string sql = "INSERT into client (name,address,phone,accountID,balance,minimumBalance,accountType) VALUES('"+
            cl.get_name()+"','"+cl.get_address()+"','"+cl.get_phone()+"','"+ba.get_AccountID()+"','"
            +to_string(ba.get_balance())+"','"+ to_string(ba.get_MinimumBalance())+"','"+ba.getType()+"');";
    int res = sqlite3_prepare_v2(db,sql.c_str(),1000,&stmt,0);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    if(res == SQLITE_OK){
        cout << "added" << endl;
        dataManger::size++;
    }else{
        cout << "can`t connect to database error" << sqlite3_errmsg(db) << endl;
    }
}

client dataManger::get_client(string id) {
    string sql = "SELECT name,address,phone,accountID,balance,minimumBalance,accountType FROM client where accountID = '" + id + "';";
    int res;
    try {
        res = sqlite3_prepare_v2(db,sql.c_str(),-1,&stmt,NULL);
        if(res == SQLITE_OK) {
            sqlite3_step(stmt);
            string name((char *) sqlite3_column_text(stmt, 0));
            string address((char *) sqlite3_column_text(stmt, 1));
            string phone((char *) sqlite3_column_text(stmt, 2));
            string accountID((char *) sqlite3_column_text(stmt, 3));
            double balance = sqlite3_column_double(stmt, 4);
            double balanceMin = sqlite3_column_double(stmt, 5);
            string type((char *) sqlite3_column_text(stmt, 6));
            BankAccount *Ba;
            if (type == "regular") {
                Ba = new BankAccount(id, balance);
            } else {
                Ba = new SavingsBankAccount(id, balance, balanceMin);
            }
            client *ca = new client(name, address, phone, Ba);
            sqlite3_finalize(stmt);
            return *ca;
        }else{
            BankAccount *Ba= new BankAccount(id, 132);
            client *ca = new client("error" , "err" , "0000" ,Ba);
            return *ca;
        }
    } catch (exception e) {
        BankAccount *Ba= new BankAccount("***", 132);
        client *ca = new client("error" , "err" , "0000" ,Ba);
        return *ca;
    }
}


void dataManger::get_all_clients(vector<client>& clients) {
   clients = {};
    string sql = "SELECT name,address,phone,accountID,balance,minimumBalance,accountType FROM client;";
    int res = sqlite3_prepare_v2(db,sql.c_str(),-1,&stmt,NULL);
    while( (res = sqlite3_step(stmt) == SQLITE_ROW)) {
        string name((char *) sqlite3_column_text(stmt, 0));
        string address((char *) sqlite3_column_text(stmt, 1));
        string phone((char *) sqlite3_column_text(stmt, 2));
        string accountID((char *) sqlite3_column_text(stmt, 3));
        double balance = sqlite3_column_double(stmt, 4);
        double balanceMin = sqlite3_column_double(stmt, 5);
        string type((char *) sqlite3_column_text(stmt, 6));
//        cout << name << address << phone << accountID << balance << endl;
        BankAccount *Ba;

        if (type == "regular") {
            Ba = new BankAccount(accountID, balance);
        } else {
            Ba = new SavingsBankAccount(accountID,balance, balanceMin);

        }
        client* ca = new client(name, address, phone, Ba);
        clients.emplace_back(*ca);
    }
 }

void dataManger::update_balance(client& client, double balance) {
    string sql = "UPDATE client set balance = " + to_string(balance) + " Where accountID = " + client.bankAcc->get_AccountID() + ";";
    int res = sqlite3_prepare_v2(db,sql.c_str(),1000,&stmt,0);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    client.bankAcc->set_balance(balance);
}