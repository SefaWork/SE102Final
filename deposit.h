#ifndef DEPOSIT_H
#define DEPOSIT_H

#include "transaction.h"

class Keypad; // Forward declaration.
class DepositSlot; // Forward declaration.

class Deposit : public Transaction {
    public:
        Deposit(int, Screen&, BankDatabase&, Keypad&, DepositSlot&);
        
        virtual void execute();
    private:
        int depositAmount;

        Keypad& keypad;
        DepositSlot& depositSlot;

        double promptDepositMenu();
};

#endif