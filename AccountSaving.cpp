#include "AccountSaving.h"
#include <iostream>
using namespace std;

// Default constructor
AccountSaving::AccountSaving()
    : Account(), minimumBalance(0.0f) {
    SetBalance(0.0f);
    SetAccountType(2);   // 2 = saving
}

// Convenience constructor
AccountSaving::AccountSaving(int id,
                             const string& name,
                             float initialBalance,
                             float minBal)
    : Account(), minimumBalance(minBal) {
    SetAccountID(id);
    SetCustomerName(name);
    SetBalance(initialBalance);
    SetAccountType(2);   // saving
}

// Copy constructor
AccountSaving::AccountSaving(const AccountSaving& other)
    : Account(other) {
    minimumBalance = other.minimumBalance;
}

// Copy assignment
AccountSaving& AccountSaving::operator=(const AccountSaving& other) {
    if (this != &other) {
        Account::operator=(other);      // copy base stuff
        minimumBalance = other.minimumBalance;
    }
    return *this;
}

// Destructor
AccountSaving::~AccountSaving() {
    // nothing special here
}

// Mutator / accessor
void AccountSaving::SetMinimumBalance(float minBal) {
    minimumBalance = minBal;
}

float AccountSaving::GetMinimumBalance() const {
    return minimumBalance;
}

// Override withdraw:
// Only succeed if (currentBalance - amount) >= minimumBalance.
// If not, print an error and return false.
bool AccountSaving::withdraw(float amount) {
    float currentBalance = GetBalance();

    // Check minimum balance rule
    if (currentBalance - amount < minimumBalance) {
        cout << "Error: withdrawal would drop balance below minimum balance." << endl;
        return false;
    }

    // Otherwise, use base class logic to actually subtract
    return Account::withdraw(amount);
}
