//
// Created by abdel on 11/6/2022.
//
#include "classes.h"

void BankApplication::addClient() {
    string n;
    string p;
    string addr;
    cout<<"Please Enter Client Name"<<endl;
    cin>>n;
    cout<<"PLease enter your phone number"<<endl;
    cin>>p;
    cout<<"Please enter your address"<<endl;
    cin>>addr;
    cout<<"What Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2"<<endl;
    int type;
    cin>>type;
    if(type == 1) {
        BankAccount **BA = reinterpret_cast<BankAccount **>(new BankAccount());
        Clist.push_back(client(n,addr,p,*BA));
    }
    else if(type == 2){
        BankAccount **BA = reinterpret_cast<BankAccount **>(new SavingsBankAccount());
        Clist.push_back(client(n,addr,p,*BA));
    }
    else{
        cout<<"Invalid Input"<<endl;
    }
    cout<<"Please enter your balance"<<endl;
    double b;
    cin>>b;
    Clist[Clist.size()-1].bankAcc->set_balance(b);
    cout<<"Client Balance: "<<Clist[Clist.size()-1].bankAcc->get_balance()<<endl;
    cout<<"An account created with ID"<<Clist[Clist.size()-1].bankAcc->get_AccountID()<<"and starting balance"<<Clist[Clist.size()-1].bankAcc->get_balance()<<endl;
}

void BankApplication::deposit() {
    cout<<"Please Enter Your Account ID"<<endl;
    string id;
    cin>>id;
    for(int i = 0 ; i < Clist.size() ; i++){
        if(Clist[i].bankAcc->get_AccountID() == id){
            cout<<"Please Enter The Amount You Want To Deposit"<<endl;
            double amount;
            cin>>amount;
            Clist[i].bankAcc->deposit(amount);
            cout<<"Your New Balance is: "<<Clist[i].bankAcc->get_balance()<<endl;
            return;
        }
    }
    cout<<"Invalid Account ID"<<endl;
}
void BankApplication::withdraw() {
    cout<<"Please Enter Your Account ID"<<endl;
    string id;
    cin>>id;
    for(int i = 0 ; i < Clist.size() ; i++){
        if(Clist[i].bankAcc->get_AccountID() == id){
            cout<<"Please Enter The Amount You Want To Withdraw"<<endl;
            double amount;
            cin>>amount;
            Clist[i].bankAcc->withdraw(amount);
            cout<<"Your New Balance is: "<<Clist[i].bankAcc->get_balance()<<endl;
            return;
        }
    }
    cout<<"Invalid Account ID"<<endl;
}
void BankApplication::list_clients(){
    cout<<"Please Enter Your Account ID"<<endl;
    string id;
    cin>>id;
    for(int i = 0 ; i < Clist.size() ; i++){
        if(Clist[i].bankAcc->get_AccountID() == id){
            cout<<"Your Name: "<<Clist[i].get_name()<<endl;
            cout<<"Your Address: "<<Clist[i].get_address()<<endl;
            cout<<"Your Phone: "<<Clist[i].get_phone()<<endl;
            cout<<"Your Balance: "<<Clist[i].bankAcc->get_balance()<<endl;
            return;
        }
    }
    cout<<"Invalid Account ID"<<endl;
}