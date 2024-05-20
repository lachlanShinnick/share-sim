#include "Broker.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

// Constructor
Broker::Broker(const DataHandler& dataHandler) : Market<Stock>(0.01) {
    std::cout << "Broker initialized.\n";
    load_quantities(dataHandler.stock_prices_2014);
}

// Method to load stock quantities
void Broker::load_quantities(const std::unordered_map<std::string, Stock>& stocks) {
    std::srand(std::time(nullptr)); // Seed for random number generator

    // Clear the existing inventory
    inventory.clear();

    // Initialize broker inventory with random stock quantities between 5000 and 10000
    for (const auto& entry : stocks) {
        const Stock& stock = entry.second;
        double quantity = 5000 + std::rand() % 5001;

        if (stock.ticker.empty()) {
            std::cerr << "Error: Stock ticker is empty for stock: " << stock.name << std::endl;
            continue;
        }

        inventory[stock.ticker] = std::make_pair(std::make_shared<Stock>(stock), quantity);
        std::cout << "Loaded " << quantity << " shares of " << stock.ticker << " into broker inventory.\n";
    }
}

// Method to buy stock for the investor
bool Broker::buyAsset(Portfolio& portfolio, const std::string& ticker, int quantity, const DataHandler& dataHandler) {
    int currentYear = portfolio.getCurrentYear();
    try {
        Stock stock = dataHandler.getStockByTickerAndYear(ticker, currentYear);
        double price = stock.price;
        double totalCost = price * quantity;

        if (inventory[ticker].second >= quantity && portfolio.getCash() >= totalCost) {
            inventory[ticker].second -= quantity;
            portfolio.buyAsset(std::make_shared<Stock>(stock), quantity, price);
            std::cout << "Bought " << quantity << " of " << stock.ticker << " at " << price << " each." << std::endl;
            return true;
        } else {
            std::cout << "Not enough stock in inventory or not enough balance to buy the stock.\n";
            return false;
        }
    } catch (const std::out_of_range& e) {
        std::cerr << "Ticker not found: " << ticker << std::endl;
        return false;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        return false;
    } catch (const std::length_error& e) {
        std::cerr << "Length error: " << e.what() << std::endl;
        return false;
    }
}

// Method to sell stock for the investor
bool Broker::sellAsset(Portfolio& portfolio, const std::string& ticker, int quantity, const DataHandler& dataHandler) {
    int currentYear = portfolio.getCurrentYear();
    try {
        Stock stock = dataHandler.getStockByTickerAndYear(ticker, currentYear);
        double price = stock.price;
        double totalRevenue = price * quantity;
        double commission = totalRevenue * commission_rate;
        totalRevenue -= commission;

        if (portfolio.sellAsset(ticker, quantity, price)) {
            inventory[ticker].second += quantity;
            std::cout << "Sold " << quantity << " of " << ticker << " at " << price << " each with a commission of " << commission << "." << std::endl;
            return true;
        } else {
            std::cout << "Not enough stock in portfolio to sell.\n";
            return false;
        }
    } catch (const std::out_of_range& e) {
        std::cerr << "Ticker not found: " << ticker << std::endl;
        return false;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        return false;
    } catch (const std::length_error& e) {
        std::cerr << "Length error: " << e.what() << std::endl;
        return false;
    }
}
