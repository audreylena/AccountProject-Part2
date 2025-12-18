#ifndef ACCOUNTCHECKING_H
#define ACCOUNTCHECKING_H

#include <string>
#include "Account.h"
using namespace std;

class AccountChecking : public Account {
private:
    float transactionFee;   // fee charged on every transaction

public:
    // Default constructor
    AccountChecking();

    // Convenience constructor
    AccountChecking(int id,
                    const string& name,
                    float initialBalance,
                    float fee);

    // Copy constructor
    AccountChecking(const AccountChecking& other);

    // Copy assignment
    AccountChecking& operator=(const AccountChecking& other);

    // Destructor
    virtual ~AccountChecking();

    // Mutator / accessor for fee
    void SetTransactionFee(float fee);
    float GetTransactionFee() const;

    // Override base class operations
    virtual void deposit(float amount) override;
    virtual bool withdraw(float amount) override;
};

#endif
