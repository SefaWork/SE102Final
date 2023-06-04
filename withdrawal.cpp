#include "withdrawal.h"

#include "Screen.h"
#include "BankDatabase.h"
#include "CashDispenser.h"
#include "Keypad.h"

// 1- 20, 2- 40, 3- 60, 4- 100, 5- 200, 6- CANCEL
static const int CANCEL_ID = 6;

Withdrawal::Withdrawal(int accountID, Screen& screen, BankDatabase& database, Keypad& keypad, CashDispenser& dispenser)
:Transaction(accountID, screen, database), keypad(keypad), dispenser(dispenser)
{
    // Empty body.
}

void Withdrawal::execute()
{
    Screen& screen = getScreen();
    BankDatabase& database = getBankDatabase();
    int accountID = getAccountID();

    while (true) {
        int input = displayMenuOfAmounts();
        if(input == CANCEL_ID) 
        {
            screen.nextLine();
            screen.displayMessageLine("Cancelled transaction.");
            break;
        }

        withdrawAmount = input;
        int currentBalance = database.getAvailableBalance(accountID);

        if( currentBalance >= withdrawAmount )
        {
            if(dispenser.isSufficientCashAvailable(withdrawAmount)) {
                database.debit(accountID, withdrawAmount);
                dispenser.dispenseCash(withdrawAmount);

                screen.nextLine();
                screen.displayMessageLine("Please take your cash from the cash dispenser.");

                break;
            } else {
                screen.nextLine();
                screen.displayMessageLine("Insufficient cash available in the ATM. Please choose a smaller amount or cancel transaction.");
            }
        } else {
            screen.nextLine();
            screen.displayMessageLine("Insufficient funds on account. Please choose a smaller amount or cancel transaction.");
        }
    }
}

int Withdrawal::displayMenuOfAmounts()
{
    int amounts[5] = {20, 40, 60, 100, 200};
    Screen& screen = getScreen();
    
    while (true)
    {
        screen.displayMessageLine("");
        screen.displayMessageLine("Withdraw options:");
        screen.displayMessage("\t1- 20$");
        screen.displayMessageLine("\t\t2- 40$");
        screen.displayMessage("\t3- 60$");
        screen.displayMessageLine("\t\t4- 100$");
        screen.displayMessage("\t5- 200$");
        screen.displayMessageLine("\t\t6- Cancel");
        screen.displayMessage("Select a withdraw option (1-6): ");

        int input = keypad.getInput();

        switch (input)
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                return amounts[input - 1];

            case CANCEL_ID:
                return CANCEL_ID;
            
            default:
                screen.displayMessageLine("");
                screen.displayMessageLine("Invalid input. Please try again.");
                break;
        }
    }
}
