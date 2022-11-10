//
// Created by karee on 31/10/2022.
//
#include "classes.h"

client::client(string name , string address , string  phone,BankAccount* BA){
this->name = name;
this->address = address;
this->phone = phone;
this->bankAcc = BA;
//this->accountID = BA->get_AccountID();
}
//client::client(string name , string address , string  phone,SavingsBankAccount* BA){
//    this->name = name;
//    this->address = address;
//    this->phone = phone;
//    this->bankAcc = BA;
//    this->accountID = BA->get_AccountID();
//}
void client::set_name(string name){
    this->name = name;
}
void client::set_address(string address){
    this->address = address;
}
void client::set_phone(string phone){
    this->phone = phone;
}
string client::get_name(){
    return name;
}
string client::get_address(){
    return address;
}
string client::get_phone(){
    return phone;
}
void client::set_account_pointer(BankAccount* BA){
    this->bankAcc = BA;
}
client::~client(){
    delete bankAcc;
}