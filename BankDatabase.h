#ifndef BANKDATABASE_H
#define BANKDATABASE_H

#include <vector>
#include "account.h"

class BankDatabase
{
    public:
        BankDatabase();

        // Will be used to determine if a user can be authenticated with the given account number & pin.
        bool authenticateUser( int, int );

        // Gets available balance of an account with the specified ID.
        double getAvailableBalance( int );

        // Gets total balance of an account with the specified ID.
        double getTotalBalance( int );

        // Credit cash to account ID.
        void credit ( int, double );

        // Debit cash from account ID.
        void debit ( int, double );

    private:
        // This vector holds all our accounts.
        std::vector<Account> accountList;

        // Returns a pointer to the account with the specified account ID.
        Account* getAccount( int );

};

#endif // BANKDATABASE_H
