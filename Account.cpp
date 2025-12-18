#include "Account.h"
#include <iostream>
#include <limits>
using namespace std;

Account::Account() : accountID(nullptr), customerName(""), balance(0.0f), accountType(0) {}


Account::~Account() {
    delete accountID;
    accountID = nullptr;
}

Account::Account(const Account& other)
    : accountID(nullptr), customerName(other.customerName), balance(other.balance), accountType(other.accountType) {
    if (other.accountID) accountID = new int(*other.accountID);
}

Account& Account::operator=(const Account& other) {
    if (this == &other) return *this;
    int* newId = nullptr;
    if (other.accountID) newId = new int(*other.accountID);
    delete accountID;
    accountID = newId;
    customerName = other.customerName;
    balance = other.balance;
    return *this;
}

void Account::SetAccountID(int id) {
    if (!accountID) accountID = new int;
    *accountID = id;
}

void Account::SetCustomerName(const string& name) {
    customerName = name;
}

void Account::SetBalance(float amount) {
    balance = amount;
}
void Account::SetAccountType(int type){
     accountType = type;
}

int Account::GetAccountID() const {
    return accountID ? *accountID : -1;
}

string Account::GetCustomerName() const {
    return customerName;
}

float Account::GetBalance() const {
    return balance;
}
int Account::GetAccountType()const{
    return accountType;
}

void Account::deposit(float amount) {
    if (amount > 0.0f) balance += amount;
}

bool Account::withdraw(float amount) {
    if (amount <= 0.0f) return false;
    if (balance < amount) return false;
    balance -= amount;
    return true;
}

Account& Account::operator+=(Account& src) {
    cout << "Enter amount to transfer: ";
    float amount = 0.0f;
    if (!(cin >> amount)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return *this;
    }
    if (amount > 0.0f && src.balance >= amount) {
        src.balance -= amount;
        balance += amount;
    }
    return *this;
}


