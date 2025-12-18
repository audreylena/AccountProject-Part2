#include "AccountSystems.h"
#include "AccountChecking.h"
#include "AccountSaving.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;

static inline void money() {
    cout << fixed << setprecision(2);
}

static inline void clearBad() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

static inline void printLine() {
    cout << "+----------------------------------------------------------------------------+\n";
}

AccountSystems::AccountSystems() {}

// ---------------------- ADD ACCOUNT ----------------------
void AccountSystems::addAccount() {
    int type;
    while (true){
    cout << "Enter account type (1 = Checking, 2 = Saving): ";
    if (!(cin >> type)) { clearBad(); cout << "\n"; return; }
    if (type == 1 ||type ==2){break;}
    cout<<"Error: invalid account type. Account type(1:checking, 2:saving)"<<endl;
    }

    int id;
    string name;
    float initial;

    cout << "Enter account id: ";
    if (!(cin >> id)) { clearBad(); cout << "\n"; return; }

    // Check if exists
    if (accts.find(id) != nullptr) {
        cout << "Error: account with id " << id << " already exists.\n\n";
        return;
    }

    clearBad();
    cout << "Enter customer account name: ";
    getline(cin, name);

    cout << "Enter initial deposit amount: $ ";
    if (!(cin >> initial)) { clearBad(); cout << "\n"; return; }

    Account* a = nullptr;

    if (type == 1) {
        float fee;
        cout << "Enter transaction fee: $ ";
        if (!(cin >> fee)) { clearBad(); cout << "\n"; return; }

        a = new AccountChecking(id, name, initial, fee);
    }
    else {
        float minBal;
        cout << "Enter minimum balance: $ ";
        if (!(cin >> minBal)) { clearBad(); cout << "\n"; return; }

        a = new AccountSaving(id, name, initial, minBal);
    }

    accts.add(a);

    money();
    cout << "Added new account id " << a->GetAccountID()
         << " with initial balance $" << a->GetBalance() << "\n\n";
}

// ---------------------- DEPOSIT ----------------------
void AccountSystems::deposit() {
    if (accts.empty()) {
        cout << "Empty account list.\n\n";
        return;
    }

    int id;
    float amount;

    cout << "Enter account id: ";
    if (!(cin >> id)) { clearBad(); cout << "\n"; return; }

    Account* acc = accts.find(id);
    if (!acc) {
        cout << "Error: account with id " << id << " not found.\n\n";
        return;
    }

    cout << "Enter the deposit amount: $ ";
    if (!(cin >> amount)) { clearBad(); cout << "\n"; return; }

    acc->deposit(amount);

    money();
    cout << "Deposited $" << amount
         << " into account id " << acc->GetAccountID()
         << ". New balance: $" << acc->GetBalance() << "\n\n";
}

// ---------------------- WITHDRAW ----------------------
void AccountSystems::withdraw() {
    if (accts.empty()) {
        cout << "Empty account list.\n\n";
        return;
    }

    int id;
    float amount;

    cout << "Enter account id: ";
    if (!(cin >> id)) { clearBad(); cout << "\n"; return; }

    Account* acc = accts.find(id);
    if (!acc) {
        cout << "Error: account with id " << id << " not found.\n\n";
        return;
    }

    cout << "Enter the withdraw amount: $ ";
    if (!(cin >> amount)) { clearBad(); cout << "\n"; return; }

    bool ok = acc->withdraw(amount);

    money();
    if (!ok) {
        cout << "Error: failed to withdraw $" << amount
             << " from account id " << acc->GetAccountID() << ".\n\n";
        return;
    }

    cout << "Withdrawn $" << amount
         << " from account id " << acc->GetAccountID()
         << ". New balance: $" << acc->GetBalance() << "\n\n";
}

// ---------------------- TRANSFER ----------------------
void AccountSystems::transfer() {
    if (accts.empty()) {
        cout << "Empty account list.\n\n";
        return;
    }

    int srcId, dstId;
    float amount;

    cout << "Enter source account id: ";
    if (!(cin >> srcId)) { clearBad(); cout << "\n"; return; }

    cout << "Enter destination account id: ";
    if (!(cin >> dstId)) { clearBad(); cout << "\n"; return; }

    Account* src = accts.find(srcId);
    Account* dst = accts.find(dstId);

    if (!src || !dst) {
        cout << "Error: Source or destination account number not found. Operation failed.\n\n";
        return;
    }

    cout << "Enter the transfer amount: $ ";
    if (!(cin >> amount)) { clearBad(); cout << "\n"; return; }

    // Checking source: withdraw handles fee
    // Saving source: withdraw handles minBalance rule
    if (!src->withdraw(amount)) {
        cout << "Error: Transfer failed.\n\n";
        return;
    }

    dst->deposit(amount);

    money();
    cout << "Successfully transferred $" << amount
         << " from account id " << src->GetAccountID()
         << " to account id " << dst->GetAccountID() << ".\n\n";
}

// ---------------------- PRINT ALL ----------------------
void AccountSystems::printAll() const {
    if (accts.empty()) {
        cout << "Empty account list.\n\n";
        return;
    }

    printLine();
    cout << "| Acct | Type     | Customer Account Name              | Balance        |\n";
    printLine();

    money();
    for (int i = 0; i < accts.size(); i++) {
        Account* acc = accts.at(i);
        if (!acc) continue;

        string typeStr =
            (acc->GetAccountType() == 1 ? "Checking" :
             acc->GetAccountType() == 2 ? "Saving" : "Unknown");

        cout << "| " << setw(4) << acc->GetAccountID()
             << " | " << left << setw(8) << typeStr
             << " | " << left << setw(30) << acc->GetCustomerName().substr(0,30)
             << " | $ " << right << setw(12) << acc->GetBalance() << " |\n";

        printLine();
    }
    cout << "\n";
}
