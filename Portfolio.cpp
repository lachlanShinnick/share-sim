#include "Portfolio.h"
#include <iostream>

// Constructor
Portfolio::Portfolio(double initial_cash) : cash(initial_cash), current_year(2014) {}

// Method to buy an asset
bool Portfolio::buyAsset(const std::shared_ptr<Asset>& asset, double amount, double price) {
    double totalCost = amount * price;
    if (cash >= totalCost) {
        if (assets.find(asset->name) == assets.end()) {
            assets[asset->name] = std::make_pair(asset, 0);
        }
        assets[asset->name].second += amount;
        cash -= totalCost;
        return true;
    } else {
        std::cerr << "Not enough balance to buy " << amount << " of " << asset->name << std::endl;
        return false;
    }
}

// Method to sell an asset
bool Portfolio::sellAsset(const std::string& name, double amount, double price) {
    auto it = assets.find(name);
    if (it != assets.end() && it->second.second >= amount) {
        double totalRevenue = amount * price;
        it->second.second -= amount;
        cash += totalRevenue;
        if (it->second.second == 0) {
            assets.erase(it);
        }
        return true;
    } else {
        std::cerr << "Not enough " << name << " to sell." << std::endl;
        return false;
    }
}

// Method to get the amount of a specific asset
double Portfolio::getAssetAmount(const std::string& name) const {
    auto it = assets.find(name);
    if (it != assets.end()) {
        return it->second.second;
    } else {
        return 0.0;
    }
}

// Method to print a summary of all assets
void Portfolio::getSummaryOfAssets(const DataHandler& dataHandler) const {
    std::cout << "Summary of Assets:" << std::endl;
    for (const auto& asset : assets) {
        const std::shared_ptr<Asset>& asset_ptr = asset.second.first;
        double amount = asset.second.second;
        try {
            if (auto stock = std::dynamic_pointer_cast<Stock>(asset_ptr)) {
                Stock currentStock = dataHandler.getStockByTickerAndYear(stock->ticker, current_year);
                std::cout << "Ticker: " << currentStock.ticker << ", Name: " << currentStock.name 
                          << ", Current Price: " << currentStock.price << ", Amount: " << amount << std::endl;
            } else if (auto crypto = std::dynamic_pointer_cast<Crypto>(asset_ptr)) {
                Crypto currentCrypto = dataHandler.getCryptoByCurrencyAndYear(crypto->name, current_year);
                std::cout << "Crypto: " << currentCrypto.name << ", Current Price: " << currentCrypto.price 
                          << ", Amount: " << amount << std::endl;
            }
        } catch (const std::out_of_range& e) {
            std::cerr << "Asset not found: " << asset_ptr->name << std::endl;
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
        std::cout << "Year incremented to: " << current_year << std::endl;
    } else {
        std::cout << "You have reached the maximum year limit!" << std::endl;
    }
}

// Method to get the current year
int Portfolio::getCurrentYear() const {
    return current_year;
}

// Method to calculate the total value of all assets
double Portfolio::calculateTotalAssetsValue(const DataHandler& dataHandler) const {
    double totalValue = 0.0;
    for (const auto& asset : assets) {
        const std::shared_ptr<Asset>& asset_ptr = asset.second.first;
        double amount = asset.second.second;
        try {
            if (auto stock = std::dynamic_pointer_cast<Stock>(asset_ptr)) {
                Stock currentStock = dataHandler.getStockByTickerAndYear(stock->ticker, current_year);
                totalValue += currentStock.price * amount;
            } else if (auto crypto = std::dynamic_pointer_cast<Crypto>(asset_ptr)) {
                Crypto currentCrypto = dataHandler.getCryptoByCurrencyAndYear(crypto->name, current_year);
                totalValue += currentCrypto.price * amount;
            }
        } catch (const std::out_of_range& e) {
            std::cerr << "Asset not found: " << asset_ptr->name << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    return totalValue;
}
