#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <vector>
#include "Account.h"
using namespace std; 


class Accounts{
private:
       vector<Account*>accounts;

public:

     Accounts();
    ~Accounts();

    void add(Account* acct);
    Account* find (int accountId);
    Account* at(const int i)const;

    bool empty()const{return accounts.empty();}
    int size()const{return static_cast<int>(accounts.size());}



};
#endif 
