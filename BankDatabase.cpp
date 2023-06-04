#include "BankDatabase.h"
#include <iostream>

BankDatabase::BankDatabase()
{
    //Test accounts;

    Account account1(11111, 12345, 500.0, 1000.0);
    Account account2(22222, 67890, 3233.0, 82550.0);

    accountList.push_back(account1);
    accountList.push_back(account2);
}

bool BankDatabase::authenticateUser(int accountID, int pin)
{
    Account* accountFound = getAccount(accountID);
    
    if(accountFound != nullptr)
        return accountFound->validatePin(pin); // We have to use -> here since accountFound is a pointer.
    else
        return false;
}

double BankDatabase::getAvailableBalance(int accountID)
{
    Account* accountFound = getAccount(accountID);

    if(accountFound != nullptr)
        return accountFound->getAvailableBalance();
    else
        return 0.0;
}

double BankDatabase::getTotalBalance(int accountID)
{
    Account* accountFound = getAccount(accountID);

    if(accountFound != nullptr)
        return accountFound->getTotalBalance();
    else
        return 0.0;
}

void BankDatabase::credit(int accountID, double amount)
{
    Account* accountFound = getAccount(accountID);

    if(accountFound != nullptr)
        accountFound->credit(amount);
}

void BankDatabase::debit(int accountID, double amount)
{
    Account* accountFound = getAccount(accountID);

    if(accountFound != nullptr)
        accountFound->debit(amount);
}

Account* BankDatabase::getAccount(int accountID)
{
    for ( std::size_t i = 0; i < accountList.size(); i++ )
    {
        if ( accountList[i].getAccountNumber() == accountID )
        return &accountList[i];
    } // end for

    return nullptr; // if no matching account was found, return NULL
}
