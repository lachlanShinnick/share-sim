#ifndef MENU_H
#define MENU_H

#include "Investor.h"
#include "Broker.h"
#include "Exchange.h"
#include "DataHandler.h"
#include <windows.h>  // Include the Windows header for Sleep

class Game;  // Forward declaration of the Game class

class Menu {
public:
    // Default constructor
    Menu();

    void displayMainMenu(Investor& investor, Broker& broker, Exchange& exchange, DataHandler& dataHandler, Game& game);
    void displayBrokerMenu(Investor& investor, Broker& broker, DataHandler& dataHandler);
    void displayCryptoExchangeMenu(Investor& investor, Exchange& exchange, DataHandler& dataHandler);
    Investor* chooseInvestorType();  // New function to choose the investor type
    void pauseForReadability() const;

private:
    int getMenuChoice() const;  // Method to pause for readability

public:
    bool shouldContinueGame = true;  // Add this member variable to track if the game should continue
};

#endif // MENU_H
