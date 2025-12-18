#include "AccountChecking.h"
#include <iostream>
using namespace std;

// Default constructor
AccountChecking::AccountChecking()
    : Account(), transactionFee(0.0f) {
    SetBalance(0.0f);
    SetAccountType(1);  // 1 = checking
}

// Convenience constructor
AccountChecking::AccountChecking(int id,
                                 const string& name,
                                 float initialBalance,
                                 float fee)
    : Account(), transactionFee(fee) {
    SetAccountID(id);
    SetCustomerName(name);
    SetBalance(initialBalance);
    SetAccountType(1);  // checking
}

// Copy constructor
AccountChecking::AccountChecking(const AccountChecking& other)
    : Account(other) {  // let base copy its data
    transactionFee = other.transactionFee;
}

// Copy assignment
AccountChecking& AccountChecking::operator=(const AccountChecking& other) {
    if (this != &other) {
        Account::operator=(other);      // copy base part
        transactionFee = other.transactionFee;
    }
    return *this;
}

// Destructor
AccountChecking::~AccountChecking() {
    // nothing special, base destructor handles its stuff
}

// Mutator / accessor
void AccountChecking::SetTransactionFee(float fee) {
    transactionFee = fee;
}

float AccountChecking::GetTransactionFee() const {
    return transactionFee;
}

// Override deposit:
// If fee = 2 and user deposits 500,
// only 498 is actually added to the balance.
void AccountChecking::deposit(float amount) {
    float netAmount = amount - transactionFee;

    if (netAmount <= 0.0f) {
        cout << "Error: deposit amount too small to cover transaction fee." << endl;
        return;
    }

    // Use base class logic to actually modify balance
    Account::deposit(netAmount);
}

// Override withdraw:
// Charge the fee on every withdrawal.
// If base withdraw checks balance and returns bool,
// just pass (amount + fee) to it.
bool AccountChecking::withdraw(float amount) {
    float total = amount + transactionFee;
    return Account::withdraw(total);
}
