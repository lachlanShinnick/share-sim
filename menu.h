#ifndef MENU_H
#define MENU_H

#include "Investor.h"
#include "Broker.h"
#include "DataHandler.h"

class Game;  // Forward declaration

class Menu {
public:
    // Default constructor
    Menu();

    void displayMainMenu(Investor& investor, Broker& broker, DataHandler& dataHandler, Game& game);
    void displayBrokerMenu(Investor& investor, Broker& broker, DataHandler& dataHandler);
    void displayCryptoExchangeMenu(Investor& investor, Broker& broker, DataHandler& dataHandler);
};

#endif