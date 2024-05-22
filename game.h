#ifndef GAME_H
#define GAME_H

#include "Investor.h"
#include "Broker.h"
#include "Exchange.h"
#include "DataHandler.h"
#include "Menu.h"
#include <iomanip>

class Game {
public:
    Game(Investor* investor);
    void start();
    void goToNextFinancialYear();
    void displayFinalResults();
    int getCurrentYear() const { return currentYear; }

    bool shouldContinueGame = true;

private:
    DataHandler dataHandler;
    Broker broker;
    Exchange exchange;
    Investor* investor;
    int currentYear;
    double initialBalance;
    Menu menu;  
};

#endif 
