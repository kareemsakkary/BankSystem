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
    cout<<"What Type of Account Do You Like? (1) Basic (2) Saving - Type 1 or 2"<<endl;
    int type;
    cin>>type;
    cout<<"Please enter your balance"<<endl;
    double b;
    cin>>b;

    string counter = to_string(dm.size+1);
    string id = string(4-counter.size() , '0');
    id += counter;

    if(type == 1) {
        BankAccount *BA =new BankAccount(id,b);
        client cl = client(n,addr,p,BA);
        dm.add_client(cl);
    }
    else if(type == 2){
        BankAccount *BA = new SavingsBankAccount(id,b);
        client cl = client(n,addr,p,BA);
        dm.add_client(cl);
    }
    else{
        cout<<"Invalid Input"<<endl;
    }

}

void BankApplication::deposit() {
    cout<<"Please Enter Your Account ID"<<endl;
    string id;
    cin>>id;
    client cl = dm.get_client(id);
    if(id==cl.bankAcc->get_AccountID()) {
        cout << "Please enter The amount you want to deposit" << endl;
        double amount;
        cin >> amount;
        cl.bankAcc->deposit(amount);
        dm.update_balance(cl, cl.bankAcc->get_balance());
        cout << "Your New Balance is: " << cl.bankAcc->get_balance() << endl;
    }
    else
        cout<<"Invalid Account ID"<<endl;

}
void BankApplication::withdraw() {
    cout<<"Please Enter Your Account ID"<<endl;
    string id;
    cin>>id;
    client cl = dm.get_client(id);
    if(id==cl.bankAcc->get_AccountID()) {
        cout << "Please enter The amount you want to withdraw" << endl;
        double amount;
        cin >> amount;
        cl.bankAcc->withdraw(amount);
        dm.update_balance(cl, cl.bankAcc->get_balance());
        cout << "Your New Balance is: " << cl.bankAcc->get_balance() << endl;
    }
    else
        cout<<"Invalid Account ID"<<endl;
}
void BankApplication::list_clients(){
    vector<client>listing;
    dm.get_all_clients(listing);
    for(int i=0;i<listing.size();i++){
        cout<<i+1<<" - "<<listing[i].get_name()<<", ";
        cout<<listing[i].get_phone()<<", ";
        cout<<listing[i].get_address()<<"."<<endl;
    }
}
void BankApplication::mainMenu(){
    int choice;
    cout<<"Welcome to FCAI Banking Application\n"<<
          "1. Create a New Account\n"<<
          "2. List Clients and Accounts\n"<<
          "3. Withdraw Money\n"<<
          "4. Deposit Money \n"<<
          "Input your choice: ";
    cin>>choice;
    switch(choice){
        case 1:
             addClient();
            break;
        case 2:
            list_clients();
            break;
        case 3:
             withdraw();
            break;
        case 4:
             deposit();
            break;
    }


}