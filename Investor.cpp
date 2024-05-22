#include "Investor.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

Investor::Investor(double initial_balance) : investors_portfolio(initial_balance), initial_balance(initial_balance) {
    std::cout << "Investor initialized.\n"; 
}

Investor::~Investor() {}

// Method to check if the investor has enough balance for a transaction
bool Investor::CheckBalance(double transaction) {
    return investors_portfolio.getCash() >= transaction;
}

// Method to display the investor's portfolio
void Investor::DisplayPortfolio(const DataHandler& dataHandler) {
    investors_portfolio.getSummaryOfAssets(dataHandler);
}

// Method for buying stocks
void Investor::Buy(Broker& broker, const DataHandler& dataHandler) {
    std::string ticker;
    int quantity;

    // Display the current cash balance
    std::cout << "Your current cash balance: $" << investors_portfolio.getCash() << "\n";
    std::cout << "Enter ticker: ";
    std::cin >> ticker;

    try {
        Stock stock = dataHandler.getStockByTickerAndYear(ticker, investors_portfolio.getCurrentYear());
        std::cout << "Current price of " << stock.name << " (" << ticker << ") is " << stock.price << "\n";
        double availableQuantity = broker.getAvailableQuantity(ticker);
        std::cout << "Broker has " << availableQuantity << " shares of " << ticker << " available.\n";
    } catch (const std::exception& e) {
        std::cout << "Invalid input or ticker not found.\n";
        return;
    }

    std::cout << "Enter quantity: ";
    std::cin >> quantity;

    broker.buyAsset(investors_portfolio, ticker, quantity, dataHandler);
}

// Method for selling stocks
void Investor::Sell(Broker& broker, const DataHandler& dataHandler) {
    std::string ticker;
    int quantity;

    // Display the current cash balance
    std::cout << "Your current cash balance: $" << investors_portfolio.getCash() << "\n";
    std::cout << "Enter stock TICKER (all uppercase letters): ";
    std::cin >> ticker;

    try {
        Stock stock = dataHandler.getStockByTickerAndYear(ticker, investors_portfolio.getCurrentYear());
        std::cout << "Current price of " << stock.name << " (" << ticker << ") is " << stock.price << "\n";
        double availableQuantity = broker.getAvailableQuantity(ticker);
        double ownedQuantity = investors_portfolio.getAssetAmount(stock.name);  // Use the name from the retrieved stock
        std::cout << "Broker has " << availableQuantity << " shares of " << ticker << " available.\n";
        std::cout << "You own " << ownedQuantity << " shares of " << ticker << ".\n";
    } catch (const std::exception& e) {
        std::cout << "Invalid input or ticker not found: " << e.what() << "\n";
        return;
    }

    std::cout << "Enter quantity: ";
    std::cin >> quantity;

    bool success = broker.sellAsset(investors_portfolio, ticker, quantity, dataHandler);
    if (success) {
        std::cout << "Successfully sold " << quantity << " shares of " << ticker << ".\n";
    } else {
        std::cout << "Failed to sell shares of " << ticker << ".\n";
    }
}

// Method for buying cryptocurrencies
void Investor::BuyCrypto(Exchange& exchange, const DataHandler& dataHandler) {
    std::string name;
    int quantity;

    std::cout << "Your current cash balance: $" << investors_portfolio.getCash() << "\n";
    std::cout << "Enter crypto Name (capitalise first letter): ";
    std::cin >> name;

    try {
        Crypto crypto = dataHandler.getCryptoByCurrencyAndYear(name, investors_portfolio.getCurrentYear());
        std::cout << "Current price of " << crypto.name << " is " << crypto.price << "\n";
        double availableQuantity = exchange.getAvailableQuantity(name);
        std::cout << "Exchange has " << availableQuantity << " units of " << name << " available.\n";
    } catch (const std::exception& e) {
        std::cout << "Invalid input or crypto not found.\n";
        return;
    }

    std::cout << "Enter quantity: ";
    std::cin >> quantity;

    exchange.buyAsset(investors_portfolio, name, quantity, dataHandler);
}

// Method for seling cryptocurrencies
void Investor::SellCrypto(Exchange& exchange, const DataHandler& dataHandler) {
    std::string name;
    int quantity;

    // Display the current cash balance
    std::cout << "Your current cash balance: $" << investors_portfolio.getCash() << "\n";
    std::cout << "Enter crypto name: ";
    std::cin >> name;

    try {
        Crypto crypto = dataHandler.getCryptoByCurrencyAndYear(name, investors_portfolio.getCurrentYear());
        std::cout << "Current price of " << crypto.name << " is " << crypto.price << "\n";
        double availableQuantity = exchange.getAvailableQuantity(name);
        double ownedQuantity = investors_portfolio.getAssetAmount(name);  // Get the amount of crypto the person owns
        std::cout << "Exchange has " << availableQuantity << " units of " << name << " available.\n";
        std::cout << "You own " << ownedQuantity << " units of " << name << ".\n";  // Display the amount owned
    } catch (const std::exception& e) {
        std::cout << "Invalid input or crypto not found.\n";
        return;
    }

    std::cout << "Enter quantity: ";
    std::cin >> quantity;

    exchange.sellAsset(investors_portfolio, name, quantity, dataHandler);
}

// Go to the next financial year
void Investor::GoToNextFinancialYear() {
    investors_portfolio.incrementYear();
}


double Investor::GetBalance() {
    return investors_portfolio.getCash();
}

int Investor::getCurrentYear() const {
    return investors_portfolio.getCurrentYear();
}

const Portfolio& Investor::getPortfolio() const {
    return investors_portfolio;
}

// Get percentage gain, so high score can be updated
double Investor::calculatePercentageGain(double initial_balance, const DataHandler& dataHandler) const {
    double final_balance = investors_portfolio.getCash() + investors_portfolio.calculateTotalAssetsValue(dataHandler);
    return ((final_balance - initial_balance) / initial_balance) * 100.0;
}


void Investor::saveHighScore(const std::string& filename, double initial_balance, const DataHandler& dataHandler) const {
    double percentage_gain = calculatePercentageGain(initial_balance, dataHandler);
    std::ofstream file(filename);
    if (file.is_open()) {
        file << percentage_gain << "\n";
        // Capture the investor names in a string stream
        std::ostringstream oss;
        getInvestorNameOrNames();
        oss << "\n";  // Ensure there's a newline after the name
        file << oss.str();
        file.close();
    } else {
        std::cerr << "Unable to open file for writing.\n";
    }
}


bool Investor::loadHighScore(const std::string& filename, double& highScore, std::string& name) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        if (std::getline(file, line)) {
            highScore = std::stod(line);
        }
        if (std::getline(file, line)) {
            name = line;
        }
        file.close();
        return true;
    } else {
        std::cerr << "Unable to open file for reading.\n";
        return false;
    }
}

void Investor::updateHallOfFame(const std::string& filename, double initial_balance, const DataHandler& dataHandler) const {
    double current_score = calculatePercentageGain(initial_balance, dataHandler);
    double high_score = 0.0;
    std::string high_score_name;

    bool high_score_exists = loadHighScore(filename, high_score, high_score_name);

    if (!high_score_exists || current_score > high_score) {
        std::cout << "Congratulations! You achieved a new high score and entered the Simulation Hall of Fame.\n";
        saveHighScore(filename, initial_balance, dataHandler);
    } else {
        std::cout << "You did not beat the high score.\n";
    }
}
