#ifndef ACCOUNTSYSTEMS_H
#define ACCOUNTSYSTEMS_H
#include "Accounts.h"


class AccountSystems{
private:
       Accounts accts;

public:
      AccountSystems();

     void addAccount();
     void deposit();
     void withdraw();
     void transfer();
     void printAll()const;

};
#endif
