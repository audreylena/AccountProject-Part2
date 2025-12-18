#ifndef ACCOUNTSAVING_H
#define ACCOUNTSAVING_H

#include <string>
#include "Account.h"
using namespace std;

class AccountSaving : public Account {
private:
    float minimumBalance;   // must always keep at least this much in the account

public:
    // Constructors / destructor
    AccountSaving();
    AccountSaving(int id,
                  const string& name,
                  float initialBalance,
                  float minBal);
    AccountSaving(const AccountSaving& other);
    AccountSaving& operator=(const AccountSaving& other);
    virtual ~AccountSaving();

    // Mutator / accessor
    void SetMinimumBalance(float minBal);
    float GetMinimumBalance() const;

    // Override withdraw to enforce minimum balance rule
    virtual bool withdraw(float amount) override;
};

#endif
