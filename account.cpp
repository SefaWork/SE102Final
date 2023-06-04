#include "account.h"

Account::Account(int accountNumber, int pin, double availableBalance, double totalBalance)
:accountNumber(accountNumber), pin(pin), availableBalance(availableBalance), totalBalance(totalBalance)
{
    // Empty body.
}

bool Account::validatePin(int givenPin)
{
    return givenPin == pin;
}

double Account::getAvailableBalance()
{
    return availableBalance;
}

double Account::getTotalBalance()
{
    return totalBalance;
}

int Account::getAccountNumber()
{
    return accountNumber;
}

void Account::credit(double amount)
{
    totalBalance += amount;
}

void Account::debit(double amount)
{
    availableBalance -= amount;
    totalBalance -= amount;
};
