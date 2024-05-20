#include "Exchange.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

// Constructor
Exchange::Exchange(const DataHandler& dataHandler) : Market<Crypto>(0.01) {
    std::cout << "Exchange initialized.\n";
    load_quantities(dataHandler.crypto_prices_2014);
}

// Method to load crypto quantities
void Exchange::load_quantities(const std::unordered_map<std::string, Crypto>& cryptos) {
    std::srand(std::time(nullptr)); // Seed for random number generator

    // Clear the existing inventory
    inventory.clear();

    // Initialize exchange inventory with random crypto quantities between 5000 and 10000
    for (const auto& entry : cryptos) {
        const Crypto& crypto = entry.second;
        double quantity = 5000 + std::rand() % 5001;

        inventory[crypto.name] = std::make_pair(std::make_shared<Crypto>(crypto), quantity);
        std::cout << "Loaded " << quantity << " units of " << crypto.name << " into exchange inventory.\n";
    }
}

// Method to buy crypto for the investor
bool Exchange::buyAsset(Portfolio& portfolio, const std::string& name, int quantity, const DataHandler& dataHandler) {
    int currentYear = portfolio.getCurrentYear();
    try {
        Crypto crypto = dataHandler.getCryptoByCurrencyAndYear(name, currentYear);
        double price = crypto.price;
        double totalCost = price * quantity;

        if (inventory[name].second >= quantity && portfolio.getCash() >= totalCost) {
            inventory[name].second -= quantity;
            portfolio.buyAsset(std::make_shared<Crypto>(crypto), quantity, price);
            std::cout << "Bought " << quantity << " of " << crypto.name << " at " << price << " each." << std::endl;
            return true;
        } else {
            std::cout << "Not enough crypto in inventory or not enough balance to buy the crypto.\n";
            return false;
        }
    } catch (const std::out_of_range& e) {
        std::cerr << "Crypto not found: " << name << std::endl;
        return false;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        return false;
    } catch (const std::length_error& e) {
        std::cerr << "Length error: " << e.what() << std::endl;
        return false;
    }
}

// Method to sell crypto for the investor
bool Exchange::sellAsset(Portfolio& portfolio, const std::string& name, int quantity, const DataHandler& dataHandler) {
    int currentYear = portfolio.getCurrentYear();
    try {
        Crypto crypto = dataHandler.getCryptoByCurrencyAndYear(name, currentYear);
        double price = crypto.price;
        double totalRevenue = price * quantity;
        double commission = totalRevenue * commission_rate;
        totalRevenue -= commission;

        if (portfolio.sellAsset(name, quantity, price)) {
            inventory[name].second += quantity;
            std::cout << "Sold " << quantity << " of " << name << " at " << price << " each with a commission of " << commission << "." << std::endl;
            return true;
        } else {
            std::cout << "Not enough crypto in portfolio to sell.\n";
            return false;
        }
    } catch (const std::out_of_range& e) {
        std::cerr << "Crypto not found: " << name << std::endl;
        return false;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        return false;
    } catch (const std::length_error& e) {
        std::cerr << "Length error: " << e.what() << std::endl;
        return false;
    }
}
