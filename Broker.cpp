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
    }
}

// Method to buy stock for the investor
bool Broker::buyAsset(Portfolio& portfolio, const std::string& ticker, int quantity, const DataHandler& dataHandler) {
    int currentYear = portfolio.getCurrentYear();
    try {
        Stock stock = dataHandler.getStockByTickerAndYear(ticker, currentYear);
        double price = stock.price;
        double totalCost = price * quantity;

        // If buy is valid
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

        std::cout << "Attempting to sell " << quantity << " of " << ticker << " at " << price << " each.\n";
        double ownedQuantity = portfolio.getAssetAmount(stock.name);  // Use the name from the retrieved stock
        std::cout << "Portfolio before sale: " << ownedQuantity << " shares of " << ticker << "\n";

        if (portfolio.sellAsset(stock.name, quantity, price)) {  // Use the name from the retrieved stock
            inventory[ticker].second += quantity;
            std::cout << "Sold " << quantity << " of " << ticker << " at " << price << " each with a commission of " << commission << ".\n";
            std::cout << "Portfolio after sale: " << portfolio.getAssetAmount(stock.name) << " shares of " << ticker << "\n";
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



// Method to get the available quantity of a stock
double Broker::getAvailableQuantity(const std::string& ticker) const {
    auto it = inventory.find(ticker);
    if (it != inventory.end()) {
        return it->second.second;
    }
    return 0.0;
}

void Broker::displayAllAssets(const DataHandler& dataHandler, int currentYear) const {
    std::cout << "All stocks in broker inventory:\n";
    for (const auto& entry : inventory) {
        const auto& stock = entry.second.first;
        double quantity = entry.second.second;

        try {
            Stock currentStock = dataHandler.getStockByTickerAndYear(stock->ticker, currentYear);
            std::cout << "Ticker: " << currentStock.ticker << ", Name: " << currentStock.name << ", Price: " << currentStock.price << ", Quantity: " << quantity << "\n";
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }
}