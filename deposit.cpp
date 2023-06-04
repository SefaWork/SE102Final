#include "deposit.h"

#include "Screen.h"
#include "BankDatabase.h"
#include "Keypad.h"
#include "DepositSlot.h"

static const int CANCEL_ID = 0;

Deposit::Deposit(int accountID, Screen& screen, BankDatabase& database, Keypad& keypad, DepositSlot& slot)
:Transaction(accountID, screen, database), keypad(keypad), depositSlot(slot)
{
    // Empty body.
}

void Deposit::execute()
{
    Screen& screen = getScreen();

    double amount = promptDepositMenu();
    if(amount == CANCEL_ID) 
    {
        screen.nextLine();
        screen.displayMessageLine("Cancelled transaction.");
        return;
    }

    screen.nextLine();
    screen.displayMessage("Please insert a deposit envelope containing ");
    screen.displayDollarAmount(amount);
    screen.displayMessageLine(" dollars into the deposit slot.");

    if(depositSlot.isEnvelopeReceived())
    {
        screen.nextLine();
        screen.displayMessageLine("Your envelope has been received.");
        screen.nextLine();
        screen.displayMessageLine("NOTE: The money deposited will not be available until we verify the amount of the enclosed cash.");

        getBankDatabase().credit(getAccountID(), amount);
    }
    else
    {
        screen.nextLine();
        screen.displayMessageLine("ERROR: You have not inserted an envelope into the deposit slot within 2 minutes, the transaction has been canceled.");
    }
}

double Deposit::promptDepositMenu()
{
    Screen& screen = getScreen();

    screen.nextLine();
    screen.displayMessageLine("Input the amount of CENTS to deposit (or 0 to cancel transaction): ");

    int input = keypad.getInput();
    
    if(input == CANCEL_ID) 
        return CANCEL_ID;
    else 
        return static_cast<double>(input / 100);
}
