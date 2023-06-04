#include "Screen.h"

#include <string>
#include <iomanip>
#include <iostream>

void Screen::displayMessage( std::string msg ) {
    std::cout << msg;
}

void Screen::nextLine() {
    std::cout << std::endl;
}

void Screen::displayMessageLine( std::string msg ) {
    std::cout << msg << std::endl;
}

void Screen::displayDollarAmount( int amount ) {
    std::cout << std::fixed << std::setprecision( 2 ) << "$" << amount;
}
