#include "CashDispenser.h"

CashDispenser::CashDispenser()
{
    count = INITIAL_COUNT;
}

void CashDispenser::dispenseCash( int amount ) {
    int billsRequired = amount / 20;
    count -= billsRequired;
}

bool CashDispenser::isSufficientCashAvailable ( int amount )
{
    int billsRequired = amount / 20;
    return count >= billsRequired; // cast to boolean
}
