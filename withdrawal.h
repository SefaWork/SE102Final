#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include "transaction.h"

class Keypad; // Forward declaration.
class CashDispenser; // Forward declaration.

class Withdrawal : public Transaction {
    public:
        Withdrawal(int, Screen&, BankDatabase&, Keypad&, CashDispenser&);
        virtual void execute();
    private:
        Keypad& keypad;
        CashDispenser& dispenser;

        int withdrawAmount;
        int displayMenuOfAmounts();
};

#endif // WITHDRAWAL_H