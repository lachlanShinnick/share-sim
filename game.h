#ifndef GAME_H
#define GAME_H

#include "Broker.h"
#include "Investor.h"
#include "DataHandler.h"
#include "Menu.h"

class Game {
public:
    Game(double initial_balance);
    void start();
    void goToNextFinancialYear();

private:

    DataHandler dataHandler;
    Broker broker;
    Investor investor;
    Menu menu;
    int currentYear;
};

#endif
