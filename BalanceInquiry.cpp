#include "BalanceInquiry.h"
#include "Screen.h"
#include "BankDatabase.h"

BalanceInquiry::BalanceInquiry(int accountID, Screen & screen, BankDatabase & database)
:Transaction(accountID, screen, database)
{}

void BalanceInquiry::execute()
{
    BankDatabase& database = getBankDatabase();
    Screen& screen = getScreen();
    int accountID = getAccountID();

    double availableBalance = database.getAvailableBalance(accountID);
    double totalBalance = database.getTotalBalance(accountID);

    screen.displayMessageLine("");
    screen.displayMessageLine("Balance Information:");

    screen.displayMessage(" - Available Balance: ");
    screen.displayDollarAmount(availableBalance);

    screen.displayMessageLine("");
    screen.displayMessage(" - Total Balance: ");
    screen.displayDollarAmount(totalBalance);

    screen.displayMessageLine("");
}
