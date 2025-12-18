#include "Accounts.h"
using namespace std;

Accounts::Accounts() {}

Accounts::~Accounts() {
    for (Account* acct : accounts) {
        delete acct;
    }
    accounts.clear();
}

void Accounts::add(Account* acct) {
    if (acct != nullptr) {
        accounts.push_back(acct);
    }
}

Account* Accounts::find(int accountId) {
    for (Account* acct : accounts) {
        if (acct->GetAccountID() == accountId) {
            return acct;
        }
    }
    return nullptr;
}

Account* Accounts::at(const int i) const {
    if (i < 0 || i >= static_cast<int>(accounts.size())) {
        return nullptr;
    }
    return accounts[i];
}

