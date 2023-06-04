#include "transaction.h"
#include "Screen.h"
#include "BankDatabase.h"

Transaction::Transaction(int accountID, Screen& screen, BankDatabase& database)
    :accountID(accountID), screen(screen), database(database)
{
    // Empty body.  
}

int Transaction::getAccountID()
{
    return accountID;
}

Screen &Transaction::getScreen()
{
    return screen;
}

BankDatabase &Transaction::getBankDatabase()
{
    return database;
}
