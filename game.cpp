#include "Game.h"
#include <iostream>
#include <iomanip>  // Ensure this is included for std::setprecision

// Constructor
Game::Game(double initial_balance)
    : dataHandler(), broker(dataHandler), exchange(dataHandler), investor(initial_balance), currentYear(2014), initialBalance(initial_balance) {
    std::cout << "Game initialized.\n";  // Debug statement
}

void Game::start() {
    Menu menu;
    while (shouldContinueGame) {
        menu.displayMainMenu(investor, broker, exchange, dataHandler, *this);
    }
}

// Function to go to the next financial year
void Game::goToNextFinancialYear() {
    if (currentYear >= 2021) {  // Check if the year is 2021 or beyond
        displayFinalResults();  // Display the final results
        shouldContinueGame = false; // Ensure the game stops
        return;
    }

    currentYear++;
    investor.GoToNextFinancialYear();

    std::cout << "Loading quantities for year: " << currentYear << std::endl;  // Debug statement

    switch (currentYear) {
        case 2014:
            broker.load_quantities(dataHandler.stock_prices_2014);
            exchange.load_quantities(dataHandler.crypto_prices_2014);
            break;
        case 2015:
            broker.load_quantities(dataHandler.stock_prices_2015);
            exchange.load_quantities(dataHandler.crypto_prices_2015);
            break;
        case 2016:
            broker.load_quantities(dataHandler.stock_prices_2016);
            exchange.load_quantities(dataHandler.crypto_prices_2016);
            break;
        case 2017:
            broker.load_quantities(dataHandler.stock_prices_2017);
            exchange.load_quantities(dataHandler.crypto_prices_2017);
            break;
        case 2018:
            broker.load_quantities(dataHandler.stock_prices_2018);
            exchange.load_quantities(dataHandler.crypto_prices_2018);
            break;
        case 2019:
            broker.load_quantities(dataHandler.stock_prices_2019);
            exchange.load_quantities(dataHandler.crypto_prices_2019);
            break;
        case 2020:
            broker.load_quantities(dataHandler.stock_prices_2020);
            exchange.load_quantities(dataHandler.crypto_prices_2020);
            break;
        case 2021:
            broker.load_quantities(dataHandler.stock_prices_2021);
            exchange.load_quantities(dataHandler.crypto_prices_2021);
            break;
        default:
            // This case should never be reached due to the initial check
            throw std::invalid_argument("Year not supported");
    }

    std::cout << "Current year is now: " << currentYear << std::endl;  // Debug statement
}

// Function to display the final results
void Game::displayFinalResults() {
    double finalCash = investor.GetBalance();
    double totalAssetsValue = investor.getPortfolio().calculateTotalAssetsValue(dataHandler);
    double finalBalance = finalCash + totalAssetsValue;
    double profit = finalBalance - initialBalance;

    std::cout << "\nGame Over\n";
    std::cout << "Initial Balance: $" << std::fixed << std::setprecision(2) << initialBalance << "\n";
    std::cout << "Final Cash: $" << std::fixed << std::setprecision(2) << finalCash << "\n";
    std::cout << "Total Value of Assets: $" << std::fixed << std::setprecision(2) << totalAssetsValue << "\n";
    std::cout << "Final Balance (Cash + Assets): $" << std::fixed << std::setprecision(2) << finalBalance << "\n";
    std::cout << "Total Profit: $" << std::fixed << std::setprecision(2) << profit << "\n";
}
