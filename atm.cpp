#include "atm.h"
#include "transaction.h"

#include "BalanceInquiry.h"
#include "withdrawal.h"
#include "deposit.h"

ATM::ATM()
:userAuthenticated(false), currentAccountNumber(0)
{
    //empty body
}

void ATM::run()
{
    while (true)
    {
        // authentication step.
        while (!userAuthenticated)
        {
            screen.displayMessageLine("Welcome!");
            authenticateUser();
        }
        
        performTransactions();
        logoff();
    }
}

void ATM::performTransactions()
{
    Transaction* currentTransaction = nullptr;

    while(true)
    {
        MenuOption selection = displayMainMenu();

        if (selection == EXIT) {
            screen.nextLine();
            screen.displayMessageLine("Exiting account...");
            break;
        }


        Transaction* transactionPTR = createTransaction(selection);
        transactionPTR->execute();

        delete transactionPTR; // This allows us to delete dynamically allocated objects!
    }
}

void ATM::logoff()
{
    userAuthenticated = false;
    currentAccountNumber = 0;

    screen.nextLine();
    screen.displayMessageLine("Thank you! Goodbye.");
    screen.nextLine();
}

MenuOption ATM::displayMainMenu()
{
    while (true) {
        screen.nextLine();
        screen.displayMessageLine( "Main menu:" );
        screen.displayMessageLine( "\t1 - View my balance" );
        screen.displayMessageLine( "\t2 - Withdraw cash" );
        screen.displayMessageLine( "\t3 - Deposit funds" );
        screen.displayMessageLine( "\t4 - Exit" );
        screen.nextLine();
        screen.displayMessageLine("Enter a choice (1-4): ");

        int input = keypad.getInput();

        switch (input)
        {
            case BALANCE_INQUIRY:
                return BALANCE_INQUIRY;
            case WITHDRAWAL:
                return WITHDRAWAL;
            case DEPOSIT:
                return DEPOSIT;
            case EXIT:
                return EXIT;
            default:
                screen.nextLine();
                screen.displayMessageLine("That is not a valid selection. Please try again.");
            break;
        }
    }
}

Transaction* ATM::createTransaction(MenuOption option)
{
    Transaction* ptr = nullptr;

    switch (option)
    {
        case BALANCE_INQUIRY:
            ptr = new BalanceInquiry(currentAccountNumber, screen, database);
            break;
        
        case WITHDRAWAL:
            ptr = new Withdrawal(currentAccountNumber, screen, database, keypad, dispenser);
            break;
        
        case DEPOSIT:
            ptr = new Deposit(currentAccountNumber, screen, database, keypad, depositSlot);
            break;

        default:
            break;
    }

    return ptr;
}

void ATM::authenticateUser()
{
    screen.nextLine();
    screen.displayMessageLine("Enter your 5-digit account number: ");

    int accountNumber = keypad.getInput();

    screen.nextLine();
    screen.displayMessageLine("Enter your 5-digit PIN: ");

    int pin = keypad.getInput();

    userAuthenticated = database.authenticateUser(accountNumber, pin);
    if(userAuthenticated) 
    {
        currentAccountNumber = accountNumber;
    }
    else
    {
        screen.nextLine();
        screen.displayMessageLine("Authentication failed. Either the given account number or PIN is wrong. Please try again.");
        screen.nextLine();
    }
}
