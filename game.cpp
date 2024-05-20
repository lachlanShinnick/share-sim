#include "Game.h"
#include <iostream>

// Constructor
Game::Game(double initial_balance)
    : dataHandler(), broker(dataHandler), investor(initial_balance), currentYear(2014) {
    std::cout << "Game initialized.\n";  // Debug statement
}

// Function to start the game
void Game::start() {
    bool running = true;

    std::cout << "Game started.\n";  // Debug statement

    while (running) {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Display Portfolio\n";
        std::cout << "2. Go to Stock Broker\n";
        std::cout << "3. Go To Next Financial Year\n";
        std::cout << "4. Exit\n";
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
                menu.displayBrokerMenu(investor, broker, dataHandler);
                break;
            case 3:
                std::cout << "Going to next financial year.\n";  // Debug statement
                goToNextFinancialYear();
                break;
            case 4:
                std::cout << "Exiting game.\n";  // Debug statement
                running = false;
                break;
            default:
                std::cout << "Invalid option, please try again.\n";
        }
    }
}

// Function to go to the next financial year
void Game::goToNextFinancialYear() {
    currentYear++;
    if (currentYear > 2022) {
        std::cout << "You have reached the maximum year limit!" << std::endl;
        return;
    }

    investor.GoToNextFinancialYear();

    std::cout << "Loading quantities for year: " << currentYear << std::endl;  // Debug statement

    switch (currentYear) {
        case 2014:
            broker.load_quantities(dataHandler.stock_prices_2014);
            break;
        case 2015:
            broker.load_quantities(dataHandler.stock_prices_2015);
            break;
        case 2016:
            broker.load_quantities(dataHandler.stock_prices_2016);
            break;
        case 2017:
            broker.load_quantities(dataHandler.stock_prices_2017);
            break;
        case 2018:
            broker.load_quantities(dataHandler.stock_prices_2018);
            break;
        case 2019:
            broker.load_quantities(dataHandler.stock_prices_2019);
            break;
        case 2020:
            broker.load_quantities(dataHandler.stock_prices_2020);
            break;
        case 2021:
            broker.load_quantities(dataHandler.stock_prices_2021);
            break;
        case 2022:
            broker.load_quantities(dataHandler.stock_prices_2022);
            break;
        default:
            throw std::invalid_argument("Year not supported");
    }

    std::cout << "Current year is now: " << currentYear << std::endl;  // Debug statement
}
