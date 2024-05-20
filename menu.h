#ifndef MENU_H
#define MENU_H

#include "Investor.h"
#include "Broker.h"
#include "Exchange.h"
#include "DataHandler.h"

class Game;  // Forward declaration

class Menu {
public:
    // Default constructor
    Menu();

    void displayMainMenu(Investor& investor, Broker& broker, Exchange& exchange, DataHandler& dataHandler, Game& game);
    void displayBrokerMenu(Investor& investor, Broker& broker, DataHandler& dataHandler);
    void displayCryptoExchangeMenu(Investor& investor, Exchange& exchange, DataHandler& dataHandler);
};

#endif
