#include <iostream>
#include <limits>
#include "AccountSystems.h"
using namespace std;

static void printBanner() {

    cout << "+---------------------------------------------------------------------+\n";
    cout << "|                                                                     |\n";
    cout << "|                 Computer Science and Engineering                    |\n";
    cout << "|                                                                     |\n";
    cout << "|                 CSCE 1040 - Computer Science II                     |\n";
    cout << "|                                                                     |\n";
    cout << "|    Audrey Asu             ala0371             AudreyAsu@my.unt.edu  |\n";
    cout << "|                                                                     |\n";
    cout << "+---------------------------------------------------------------------+\n\n";
}


static void printMenu() {
    cout << "1. Add new account\n";
    cout << "2. Deposit into account\n";
    cout << "3. Withdraw from account\n";
    cout << "4. Transfer into account\n";
    cout << "5. Print a list of all accounts\n";
    cout << "6. End transaction (Exit)\n";
    cout << "Choose an option: ";
}

static void clearBadInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {


    printBanner();

    AccountSystems system;
    bool running = true;

    while (running) {
        printMenu();
        int choice;
        if (!(cin >> choice)) {
            clearBadInput();
            cout << "Invalid input. Please enter a number between 1 and 6.\n\n";
            continue;
        }

        switch (choice) {
            case 1:
                system.addAccount();
                cout << "\n";
                break;
            case 2:
                system.deposit();
                cout << "\n";
                break;
            case 3:
                system.withdraw();
                cout << "\n";
                break;
            case 4:
                system.transfer();
                cout << "\n";
                break;
            case 5:
                system.printAll();
                cout << "\n";
                break;
            case 6:
                cout << "Ending transaction. Goodbye.\n";
                running = false;
                break;
            default:
                cout << "Invalid option. Please enter a number between 1 and 6.\n\n";
                break;
        }
    }

    return 0;
}
