#ifndef SCREEN_H
#define SCREEN_H

#include <string>

class Screen
{
    public:
        void displayMessage( std::string );
        void displayMessageLine( std::string );
        void displayDollarAmount( int );
        void nextLine();
};

#endif // SCREEN_H
