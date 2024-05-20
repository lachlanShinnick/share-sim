#include "Menu.h"
#include "Game.h"
#include <iostream>

// Default constructor
Menu::Menu() {
    // Any initialization if needed
}

void Menu::displayMainMenu(Investor& investor, Broker& broker, DataHandler& dataHandler, Game& game) {
    bool running = true;

    std::cout << "Game started.\n";  // Debug statement

    while (running) {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Display Portfolio\n";
        std::cout << "2. Go to Stock Broker\n";
        std::cout << "3. Go to Crypto Exchange\n";
        std::cout << "4. Go To Next Financial Year\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose an option: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Displaying portfolio.\n";  // Debug statement
                investor.DisplayPortfolio(dataHandler);
                break;
            case 2:
                std::cout << "Going to stock broker.\n";  // Debug statement
                displayBrokerMenu(investor, broker, dataHandler);
                break;
            case 3:
                std::cout << "Going to crypto exchange.\n";  // Debug statement
                displayCryptoExchangeMenu(investor, broker, dataHandler);
                break;
            case 4:
                std::cout << "Going to next financial year.\n";  // Debug statement
                game.goToNextFinancialYear();
                break;
            case 5:
                std::cout << "Exiting game.\n";  // Debug statement
                running = false;
                break;
            default:
                std::cout << "Invalid option, please try again.\n";
        }
    }
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

void Menu::displayCryptoExchangeMenu(Investor& investor, Broker& broker, DataHandler& dataHandler) {
    bool cryptoMenuRunning = true;
    while (cryptoMenuRunning) {
        std::cout << "\nCrypto Exchange Menu:\n";
        std::cout << "1. Buy Crypto\n";
        std::cout << "2. Sell Crypto\n";
        std::cout << "3. Return to Main Menu\n";
        std::cout << "Choose an option: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Buying crypto...\n";  // Debug statement
                // Add crypto buying functionality here
                break;
            case 2:
                std::cout << "Selling crypto...\n";  // Debug statement
                // Add crypto selling functionality here
                break;
            case 3:
                cryptoMenuRunning = false;
                break;
            default:
                std::cout << "Invalid option, please try again.\n";
        }
    }
}
