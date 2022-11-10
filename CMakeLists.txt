cmake_minimum_required(VERSION 3.21)
project(BankSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(BankSystem main.cpp classes.h Client.cpp BankApplication.cpp BankAccount.cpp SavingBankAccount.cpp DataManager.cpp sqlite3.h sqlite3.c)
