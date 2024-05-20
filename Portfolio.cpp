#include "Portfolio.h"
#include <iostream>

// Constructor
Portfolio::Portfolio(double initial_cash) : cash(initial_cash), current_year(2014) {}

// Method to buy an asset
bool Portfolio::buyAsset(const Stock& stock, double amount, double price) {
    double totalCost = amount * price;
    if (cash >= totalCost) {
        assets[stock.ticker].first = stock;
        assets[stock.ticker].second += amount;
        cash -= totalCost;
        return true;
    } else {
        std::cout << "Not enough balance to buy " << amount << " of " << stock.ticker << std::endl;
        return false;
    }
}

// Method to sell an asset
bool Portfolio::sellAsset(const std::string& ticker, double amount, double price) {
    if (assets.find(ticker) != assets.end() && assets[ticker].second >= amount) {
        double totalRevenue = amount * price;
        assets[ticker].second -= amount;
        cash += totalRevenue;
        if (assets[ticker].second == 0) {
            assets.erase(ticker);
        }
        return true;
    } else {
        std::cout << "Not enough " << ticker << " to sell." << std::endl;
        return false;
    }
}

// Method to get the amount of a specific asset
double Portfolio::getAssetAmount(const std::string& ticker) const {
    if (assets.find(ticker) != assets.end()) {
        return assets.at(ticker).second;
    } else {
        return 0.0;
    }
}

// Method to print a summary of all assets
void Portfolio::getSummaryOfAssets(const DataHandler& dataHandler) const {
    std::cout << "Summary of Assets:" << std::endl;
    for (const auto& asset : assets) {
        const Stock& stock = asset.second.first;
        double amount = asset.second.second;
        try {
            Stock currentStock = dataHandler.getStockByTickerAndYear(stock.ticker, current_year);
            std::cout << "Ticker: " << currentStock.ticker << ", Name: " << currentStock.name << ", Current Price: " << currentStock.price << ", Amount: " << amount << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Ticker not found: " << stock.ticker << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "Cash available: $" << cash << std::endl;
}

// Method to get the current cash balance
double Portfolio::getCash() const {
    return cash;
}

// Method to increment the current year
void Portfolio::incrementYear() {
    if (current_year < 2022) {
        current_year++;
        std::cout << "Year incremented to: " << current_year << std::endl;  // Debug statement
    } else {
        std::cout << "You have reached the maximum year limit!" << std::endl;
    }
}

// Method to get the current year
int Portfolio::getCurrentYear() const {
    return current_year;
}
