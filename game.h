#ifndef GAME_H
#define GAME_H

#include "Investor.h"
#include "Broker.h"
#include "Exchange.h"
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
    Exchange exchange;
    Investor investor;
    int currentYear;
};

#endif // GAME_H
