#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account{
private:
       int*accountID;
       string customerName;
       float balance;
       int accountType;
public:
      Account();
    virtual ~Account();
      Account(const Account& other);
      Account& operator=(const Account& other);

      //muttators
      void SetAccountID(int id);
      void SetCustomerName(const string& name);
      void SetBalance(float amount);
      void SetAccountType(int type);

      //accessors
     int GetAccountID()const;
     string GetCustomerName()const;
     float GetBalance()const;
     int GetAccountType()const;

     //Operations
     virtual void deposit(float amount);
    virtual bool withdraw(float amount);
     virtual Account& operator+=(Account& src);


};

#endif
