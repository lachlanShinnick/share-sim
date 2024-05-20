#include "Game.h"
#include <iostream>

// Constructor
Game::Game(double initial_balance)
    : dataHandler(), broker(dataHandler), exchange(dataHandler), investor(initial_balance), currentYear(2014) {
    std::cout << "Game initialized.\n";  // Debug statement
}

void Game::start() {
    Menu menu;
    menu.displayMainMenu(investor, broker, exchange, dataHandler, *this);
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
