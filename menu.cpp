#include "Menu.h"
#include "Game.h"
#include <iostream>
#include <limits>
#include <windows.h>  // Include the Windows header for Sleep

// Remove or rename any max macro definitions
#ifdef max
#undef max
#endif

// Default constructor
Menu::Menu() {
    // Any initialization if needed
}

int Menu::getMenuChoice() const {
    int choice;
    while (true) {
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore invalid input
            std::cout << "Invalid input, please enter a number: ";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard remaining input
            return choice;
        }
    }
}

void Menu::pauseForReadability() const {
    Sleep(2000);  // Sleep for 2000 milliseconds (2 seconds)
}

void Menu::displayMainMenu(Investor& investor, Broker& broker, Exchange& exchange, DataHandler& dataHandler, Game& game) {
    bool running = true;

    std::cout << "Game started.\n";

    while (running && shouldContinueGame) {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Display Portfolio\n";
        std::cout << "2. Go to Stock Broker\n";
        std::cout << "3. Go to Crypto Exchange\n";
        std::cout << "4. Go To Next Financial Year\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose an option: ";
        int choice = getMenuChoice();

        switch (choice) {
            case 1:
                std::cout << "Displaying portfolio.\n";
                investor.DisplayPortfolio(dataHandler);
                break;
            case 2:
                std::cout << "Going to stock broker.\n";
                displayBrokerMenu(investor, broker, dataHandler);
                break;
            case 3:
                std::cout << "Going to crypto exchange.\n";
                displayCryptoExchangeMenu(investor, exchange, dataHandler);
                break;
            case 4:
                std::cout << "Going to next financial year.\n";
                game.goToNextFinancialYear();
                if (!game.shouldContinueGame) {
                    running = false;
                }
                break;
            case 5:
                std::cout << "Exiting game.\n";
                running = false;
                game.shouldContinueGame = false;
                break;
            default:
                std::cout << "Invalid option, please try again.\n";
        }
        pauseForReadability();
    }
}

void Menu::displayBrokerMenu(Investor& investor, Broker& broker, DataHandler& dataHandler) {
    bool brokerMenuRunning = true;
    while (brokerMenuRunning && shouldContinueGame) {
        std::cout << "\nBroker Menu:\n";
        std::cout << "1. Buy Stock\n";
        std::cout << "2. Sell Stock\n";
        std::cout << "3. Display All Stocks\n";  // Add this option
        std::cout << "4. Return to Main Menu\n";
        std::cout << "Choose an option: ";
        int choice = getMenuChoice();

        switch (choice) {
            case 1:
                std::cout << "Buying stock...\n";
                investor.Buy(broker, dataHandler);
                break;
            case 2:
                std::cout << "Selling stock...\n";
                investor.Sell(broker, dataHandler);
                break;
            case 3:
                std::cout << "Displaying all stocks...\n";
                broker.displayAllAssets(dataHandler, investor.getCurrentYear());  // Call the new method
                break;
            case 4:
                brokerMenuRunning = false;
                break;
            default:
                std::cout << "Invalid option, please try again.\n";
        }
        pauseForReadability();
    }
}

void Menu::displayCryptoExchangeMenu(Investor& investor, Exchange& exchange, DataHandler& dataHandler) {
    bool cryptoMenuRunning = true;
    while (cryptoMenuRunning && shouldContinueGame) {
        std::cout << "\nCrypto Exchange Menu:\n";
        std::cout << "1. Buy Crypto\n";
        std::cout << "2. Sell Crypto\n";
        std::cout << "3. Display All Cryptos\n";  // Add this option
        std::cout << "4. Return to Main Menu\n";
        std::cout << "Choose an option: ";
        int choice = getMenuChoice();

        switch (choice) {
            case 1:
                std::cout << "Buying crypto...\n";
                investor.BuyCrypto(exchange, dataHandler);
                break;
            case 2:
                std::cout << "Selling crypto...\n";
                investor.SellCrypto(exchange, dataHandler);
                break;
            case 3:
                std::cout << "Displaying all cryptos...\n";
                exchange.displayAllAssets(dataHandler, investor.getCurrentYear());  // Call the new method
                break;
            case 4:
                cryptoMenuRunning = false;
                break;
            default:
                std::cout << "Invalid option, please try again.\n";
        }
        pauseForReadability();
    }
}
