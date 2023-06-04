#ifndef CASHDISPENSER_H
#define CASHDISPENSER_H


class CashDispenser
{
    public:
        CashDispenser();

        void dispenseCash( int );
        bool isSufficientCashAvailable( int );
    private:

        // The amount of $20 bills.
        static const int INITIAL_COUNT = 500;
        int count;
};

#endif // CASHDISPENSER_H
