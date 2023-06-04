#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
    public:
        Account( int, int, double, double );

        bool validatePin( int );

        // Getters for private data members. //
        double getAvailableBalance();
        double getTotalBalance();

        int getAccountNumber();
        //////////////////////////////////////

        void credit( double );
        void debit( double );

    private:
        int accountNumber;
        int pin;
        double availableBalance;
        double totalBalance;
};

#endif // ACCOUNT_H
