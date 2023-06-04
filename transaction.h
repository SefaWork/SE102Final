#ifndef TRANSACTION_H
#define TRANSACTION_H

class Screen; // Forward declaration.
class BankDatabase; // Forward declaration.

// This class is an abstract class, thus it uses virtual data members and cannot be initiated on its own.

class Transaction
{
    public:
        Transaction(int, Screen&, BankDatabase&);
        virtual ~Transaction() {};

        int getAccountID();
        Screen& getScreen();
        BankDatabase& getBankDatabase();

        virtual void execute() = 0; // This must be overriden in derived classes since it is a PURE VIRTUAL CLASS!
    private:
        int accountID;
        Screen& screen;
        BankDatabase& database;
};

#endif // TRANSACTION_H
