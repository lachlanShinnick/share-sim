#ifndef GAME_H
#define GAME_H

#include "Investor.h"
#include "Broker.h"
#include "Exchange.h"
#include "DataHandler.h"
#include "Menu.h"
#include <iomanip>  // Ensure this is included for std::setprecision

class Game {
public:
    Game(Investor* investor);
    void start();
    void goToNextFinancialYear();
    void displayFinalResults();  // Add this method declaration
    int getCurrentYear() const { return currentYear; }  // Add a method to get the current year

    bool shouldContinueGame = true;

private:
    DataHandler dataHandler;
    Broker broker;
    Exchange exchange;
    Investor* investor;  // Use a pointer to Investor
    int currentYear;
    double initialBalance;  // Store the initial balance
};

#endif // GAME_H
