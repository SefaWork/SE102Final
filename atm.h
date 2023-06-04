#ifndef ATM_H
#define ATM_H

#include "Screen.h"
#include "Keypad.h"
#include "CashDispenser.h"
#include "DepositSlot.h"
#include "BankDatabase.h"

class Transaction; // Forward declaration of transaction class to avoid conflicts.

enum MenuOption {
    // Fowards to balance inquiry "transaction".
    BALANCE_INQUIRY = 1,

    // Fowards to withdrawal transaction.
    WITHDRAWAL,

    // Forwards to deposit transaction.
    DEPOSIT,

    // Exits the account.
    EXIT
};

class ATM
{
    public:
        ATM();
        void run();
    private:
        bool userAuthenticated = false;
        int currentAccountNumber;

        void authenticateUser();
        void performTransactions();
        void logoff();

        MenuOption displayMainMenu();

        Screen screen;
        Keypad keypad;
        CashDispenser dispenser;
        DepositSlot depositSlot;
        BankDatabase database;

        Transaction* createTransaction( MenuOption );

        // We need: screen, keypad, cashDispenser, depositSlot, bankDatabase, Transaction
};

#endif // ATM_H
