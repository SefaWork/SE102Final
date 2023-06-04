#ifndef BALANCE_INQUIRY_H
#define BALANCE_INQUIRY_H

#include "transaction.h"

class BalanceInquiry : public Transaction {
    public:
        BalanceInquiry(int, Screen&, BankDatabase&);
        virtual void execute();
};

#endif //BALANCE_INQUIRY_H