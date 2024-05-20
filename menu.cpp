#include "Menu.h"
#include <iostream>

// Default constructor
Menu::Menu() {
    // Any initialization if needed
}

void Menu::displayBrokerMenu(Investor& investor, Broker& broker, DataHandler& dataHandler) {
    bool brokerMenuRunning = true;
    while (brokerMenuRunning) {
        std::cout << "\nBroker Menu:\n";
        std::cout << "1. Buy Stock\n";
        std::cout << "2. Sell Stock\n";
        std::cout << "3. Return to Main Menu\n";
        std::cout << "Choose an option: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Buying stock...\n";  // Debug statement
                investor.Buy(broker, dataHandler);
                break;
            case 2:
                std::cout << "Selling stock...\n";  // Debug statement
                investor.Sell(broker, dataHandler);
                break;
            case 3:
                brokerMenuRunning = false;
                break;
            default:
                std::cout << "Invalid option, please try again.\n";
        }
    }
}

