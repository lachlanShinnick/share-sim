#ifndef MENU_H
#define MENU_H

#include "Investor.h"
#include "Broker.h"
#include "DataHandler.h"

class Menu {
public:
    Menu();  // Default constructor
    void displayBrokerMenu(Investor& investor, Broker& broker,DataHandler& dataHandler);
};

#endif



