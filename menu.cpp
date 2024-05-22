#include "Menu.h"
#include "Individual.h"
#include "Partnership.h"
#include "Company.h"
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
    Sleep(1000);  // Sleep for 1000 milliseconds (1 seconds)
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
        std::cout << "\nChoose an option: ";
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
                std::cout << "\nGoing to next financial year.\n";
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
        std::cout << "3. Display All Stocks\n";  
        std::cout << "4. Return to Main Menu\n";
        std::cout << "\nChoose an option: ";
        int choice = getMenuChoice();

        switch (choice) {
            case 1:
                std::cout << "Buying stock...\n\n";
                investor.Buy(broker, dataHandler);
                break;
            case 2:
                std::cout << "Selling stock...\n\n";
                investor.Sell(broker, dataHandler);
                break;
            case 3:
                std::cout << "Displaying all stocks...\n\n";
                broker.displayAllAssets(dataHandler, investor.getCurrentYear());  
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
        std::cout << "3. Display All Cryptos\n"; 
        std::cout << "4. Return to Main Menu\n";
        std::cout << "\nChoose an option: ";
        int choice = getMenuChoice();

        switch (choice) {
            case 1:
                std::cout << "Buying crypto...\n\n";
                investor.BuyCrypto(exchange, dataHandler);
                break;
            case 2:
                std::cout << "Selling crypto...\n\n";
                investor.SellCrypto(exchange, dataHandler);
                break;
            case 3:
                std::cout << "Displaying all cryptos...\n\n";
                exchange.displayAllAssets(dataHandler, investor.getCurrentYear()); 
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

Investor* Menu::chooseInvestorType() {
    std::cout << "Choose Investor Type:\n";
    std::cout << "1. Individual\n";
    std::cout << "2. Partnership\n";
    std::cout << "3. Company\n";
    std::cout << "\nChoose an option: ";
    int choice = getMenuChoice();

    double initial_balance;
    std::cout << "Enter initial balance: ";
    std::cin >> initial_balance;

    switch (choice) {
        case 1: {
            std::string investor_name;
            std::cout << "Enter investor name: ";
            std::cin.ignore(); // To ignore any leftover newline character from previous input
            std::getline(std::cin, investor_name);
            return new Individual(initial_balance, investor_name);
        }
        case 2: {
            std::vector<std::string> partner_names(2);
            std::cout << "Enter name of first partner: ";
            std::cin.ignore();
            std::getline(std::cin, partner_names[0]);
            std::cout << "Enter name of second partner: ";
            std::getline(std::cin, partner_names[1]);
            return new Partnership(initial_balance, partner_names);
        }
        case 3: {
            std::string company_name;
            std::vector<std::string> board_of_directors;
            std::cout << "Enter company name: ";
            std::cin.ignore(); // To ignore any leftover newline character from previous input
            std::getline(std::cin, company_name);
            std::string director;
            std::cout << "Enter names of board of directors (enter 'done' to finish): \n";
            while (true) {
                std::getline(std::cin, director);
                if (director == "done") break;
                board_of_directors.push_back(director);
            }
            return new Company(initial_balance, company_name, board_of_directors);
        }
        default:
            std::cout << "Invalid option, defaulting to Individual.\n";
            std::string investor_name;
            std::cout << "Enter investor name: ";
            std::cin.ignore(); // To ignore any leftover newline character from previous input
            std::getline(std::cin, investor_name);
            return new Individual(initial_balance, investor_name);
    }
}
